#include "doublecameraconfig.h"
#include "ui_doublecameraconfig.h"

DoubleCameraConfig::DoubleCameraConfig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoubleCameraConfig)
{
    ui->setupUi(this);
}

DoubleCameraConfig::~DoubleCameraConfig()
{
    delete ui;
}
