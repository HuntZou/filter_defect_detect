#ifndef DOUBLECAMERACONFIG_H
#define DOUBLECAMERACONFIG_H

#include <QDialog>

namespace Ui {
class DoubleCameraConfig;
}

class DoubleCameraConfig : public QDialog
{
    Q_OBJECT

public:
    explicit DoubleCameraConfig(QWidget *parent = nullptr);
    ~DoubleCameraConfig();

private:
    Ui::DoubleCameraConfig *ui;
};

#endif // DOUBLECAMERACONFIG_H
