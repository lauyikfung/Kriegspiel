#include "error_surrender.h"
#include "ui_error_surrender.h"

Error_surrender::Error_surrender(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error_surrender)
{
    ui->setupUi(this);
}

Error_surrender::~Error_surrender()
{
    delete ui;
}
