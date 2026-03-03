#include "mainwindow.h"
#include "optiondialog.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connections
    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::handleButton);
    connect(this, &MainWindow::statusUpdateMessage, ui->statusbar, &QStatusBar::showMessage);
    connect(ui->treeView, &QTreeView::clicked, this, &MainWindow::handleTreeClicked);
    ui->treeView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->treeView->addAction(ui->actionItem_Options);
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
//third level
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
    QModelIndex index = ui->treeView->currentIndex();

    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());

    QString text = selectedPart->data(0).toString();

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

    if (!fileName.isEmpty()) {
        emit statusUpdateMessage(QString("Selected File: ") + fileName, 0);

        QModelIndex index = ui->treeView->currentIndex();

        if (!index.isValid()) {
            // Warn user if part not selected
            QMessageBox::warning(this, "Selection", "Please select a part in the tree first to assign this file to.");
            return;
        }
        ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());

        QFileInfo fileInfo(fileName);
        QString shortFileName = fileInfo.fileName();

        selectedPart->set(0, shortFileName);

        partList->forceItemUpdate(index);

    }
}


void MainWindow::on_actionItem_Options_triggered()
{
    emit statusUpdateMessage(QString("ACTION TRIGGERED!"), 0);
    QModelIndex index = ui->treeView->currentIndex();

    if (!index.isValid()) {
        QMessageBox::warning(this, "Selection", "Please select an item first.");

        return;
    }

    ModelPart *selectedPart = static_cast<ModelPart*>(index.internalPointer());
    OptionDialog dialog(this);


    dialog.setName(selectedPart->data(0).toString());

    dialog.setColors(selectedPart->getColourR(),
                     selectedPart->getColourG(),
                     selectedPart->getColourB());

    dialog.setPartVisibility(selectedPart->visible());

    if (dialog.exec() == QDialog::Accepted) {
        selectedPart->set(0, dialog.getName());
        selectedPart->setColour(dialog.getR(), dialog.getG(), dialog.getB());
        selectedPart->setVisible(dialog.isPartVisible());
        partList->forceItemUpdate(index);
        emit statusUpdateMessage(QString("Updated: ") + dialog.getName(), 0);
    } else {
        emit statusUpdateMessage(QString("Update Cancelled"), 0);
    }
}

