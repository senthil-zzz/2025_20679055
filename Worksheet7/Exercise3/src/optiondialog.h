#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include "ui_optiondialog.h"
#include <QDialog>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT


public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();
    void setName(const QString& name) { ui->nameEdit->setText(name); }
    QString getName() const { return ui->nameEdit->text(); }

    int getR() const;
    int getG() const;
    int getB() const;

    // Also add this to pre-fill the colors when the dialog opens
    void setColors(int r, int g, int b);
    void setPartVisibility(bool visible) { ui->visibleCheck->setChecked(visible); }
    bool isPartVisible() const { return ui->visibleCheck->isChecked(); }

private:
    Ui::OptionDialog *ui;

};

#endif // OPTIONDIALOG_H
