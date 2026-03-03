#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ModelPartList.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void statusUpdateMessage(const QString & message, int timeout);

public slots:
    void handleButton();
    void handleTreeClicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();

    void on_actionItem_Options_triggered();

private:
    Ui::MainWindow *ui;
    ModelPartList *partList;
};


#endif // MAINWINDOW_H
