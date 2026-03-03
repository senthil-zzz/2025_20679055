#include "mainwindow.h"
#include "optiondialog.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connections
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::handleTreeClicked);

    // Model Setup
    this->partList = new ModelPartList("PartsList");
    ui->treeView->setModel(this->partList);

    // Multi-level Tree Generation
    ModelPart* rootItem = this->partList->getRootItem();
    for (int i = 0; i < 3; i++) {
        QString name = QString("TopLevel %1").arg(i);
        ModelPart* childItem = new ModelPart({ name, "true" });
        rootItem->appendChild(childItem); // Add to root

        // ADDING A SECOND LEVEL:
        // Create a sub-child and attach it to the item we just created
        ModelPart* subChild = new ModelPart({ QString("Child of %1").arg(i), "true" });
        childItem->appendChild(subChild); // This creates the hierarchy!

        // OPTIONAL: Add a third level
        if (i == 0) {
            ModelPart* grandChild = new ModelPart({ "Grandchild of 0", "true" });
            subChild->appendChild(grandChild);
        }
    }

    // Context Menu Setup
    ui->treeView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->treeView->addAction(ui->actionItem_Options);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleButton() {
    QMessageBox msgBox;
    msgBox.setText("Add button was clicked");
    msgBox.exec();
    emit statusUpdateMessage(QString("Add button was clicked"), 0);
}

void MainWindow::handleTreeClicked() {
    // 1. Get the index of the item you clicked
    QModelIndex index = ui->treeView->currentIndex();

    // 2. Get a pointer to the actual ModelPart object
    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());

    // 3. Extract the name (stored at index 0 of the data array)
    QString text = selectedPart->data(0).toString();

    // 4. Show it on the status bar!
    emit statusUpdateMessage(QString("The selected item is: ") + text, 0);
}



void MainWindow::on_actionOpen_File_triggered()
{
    // This opens the standard Windows "Open File" window
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "C:\\",
        tr("STL Files (*.stl);;Text Files (*.txt)")
        );

    // If the user didn't click cancel, show the name in the status bar
    if (!fileName.isEmpty()) {
        emit statusUpdateMessage(QString("Selected File: ") + fileName, 0);
    }
}


void MainWindow::on_actionItem_Options_triggered()
{
    QModelIndex index = ui->treeView->currentIndex();

    // 1. Safety check FIRST: If nothing is selected, warn the user and stop.
    if (!index.isValid()) {
        QMessageBox::warning(this, "Selection", "Please select an item first.");
        return;
    }

    // 2. Now that we know index is valid, get the pointer once.
    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());
    OptionDialog dialog(this);

    // 3. Pre-fill the dialog with ALL current data (Name and RGB).
    dialog.setName(selectedPart->data(0).toString());
    dialog.setColors(selectedPart->getColourR(),
                     selectedPart->getColourG(),
                     selectedPart->getColourB());

    // 4. Run the dialog ONCE.
    if (dialog.exec() == QDialog::Accepted) {
        // 5. Save EVERYTHING back to the model.
        selectedPart->set(0, dialog.getName());
        selectedPart->setColour(dialog.getR(), dialog.getG(), dialog.getB());

        // 6. Refresh the view and give status feedback.
        ui->treeView->viewport()->update();
        emit statusUpdateMessage(QString("Updated: ") + dialog.getName(), 0);
    } else {
        emit statusUpdateMessage(QString("Update Cancelled"), 0);
    }
}

