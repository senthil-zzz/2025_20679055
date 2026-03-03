#include "optiondialog.h"
#include "ui_optiondialog.h"

OptionDialog::OptionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

int OptionDialog::getR() const { return ui->redSpin->value(); }
int OptionDialog::getG() const { return ui->greenSpin->value(); }
int OptionDialog::getB() const { return ui->blueSpin->value(); }

void OptionDialog::setColors(int r, int g, int b) {
    ui->redSpin->setValue(r);
    ui->greenSpin->setValue(g);
    ui->blueSpin->setValue(b);
}
