#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MVGigE.h"
#include "MVImageC.h"
#include "MVCamProptySheet.h"
#include "detect.h"
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *pEvent);
    int showStreamOnLabel(MV_IMAGE_INFO* pInfo);
    void shapeChange(Shape shape);
    void changeCurrentDefectThreshold(int v);
    void changeCurrentFBDetachThreshold(int v);
private slots:
    void on_Attribute_clicked();

    void on_Start_clicked();

    void on_Stop_clicked();

    void on_SingleGrab_clicked();

    void on_saveImage_clicked();

    void on_HEART_SMALL_clicked();

    void on_HEART_BIG_clicked();

    void on_COIN_clicked();

    void on_WINTERSWEET_SMALL_clicked();

    void on_WINTERSWEET_BIG_clicked();

    void on_RAY_clicked();

    void on_STAR_clicked();

    void on_CIRCLE_clicked();

    void on_PEACH_clicked();

    void on_defect_threshold_slider_valueChanged(int value);

    void on_defect_threshold_input_valueChanged(int arg1);

    void on_FN_detach_threshold_slider_valueChanged(int value);

    void on_FN_detach_threshold_input_valueChanged(int arg1);

    void on_shapeParmsReset_clicked();

    void on_resize_filter_img_slider_valueChanged(int value);

    void on_double_camera_config_btn_clicked();

private:
    Ui::MainWindow *ui;
    volatile Shape currentShape = Shape::UNKNOWN;
    volatile int currentDefectThreshold = 1000;
    volatile int currentFBDetachThreshold = 185;
    volatile int resizeImg = 800;
    QSettings *settings = new QSettings("./config/conf.ini", QSettings::IniFormat);
    void mockImg();
    void initialCamera();
    void drawImage();
    bool m_bRun;
    HANDLE m_hCam;
    HANDLE m_hPropDlg;
    HANDLE m_hImg;
};
#endif // MAINWINDOW_H
