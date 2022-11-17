#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QScreen>
#include <QPainter>
#include <QSettings>
#include <time.h>
#include "doublecameraconfig.h"

using namespace cv;

void MainWindow::mockImg()
{
//    Mat img = imread("C:\\Users\\HuntZou\\Documents\\Personal\\Projects\\filter_defect\\imgs\\real\\f.jpg", 0);
    Mat img = imread("C:\\Users\\HuntZou\\Documents\\Personal\\Projects\\filter_defect\\imgs\\real\\good\\1656552242_good.jpg", 0);

    ui->pic1->setPixmap(QPixmap::fromImage(mat2QImage(img, 0)));

    DetectResult res;
    DetectCfg cfg(Shape::STAR, currentFBDetachThreshold, resizeImg);
    filterDefectDetect(img, res, cfg);

    ui->cost->setText(QString::fromStdString(std::to_string(res.cost) + " ms"));
    ui->pic2->setPixmap(QPixmap::fromImage(mat2QImage(img, 0)));
    ui->p1->setText(QString::number(res.extraDoubleData[0]));
    ui->p2->setText(QString::number(res.extraDoubleData[1]));
    ui->p3->setText(QString::number(res.extraDoubleData[2]));
    ui->p4->setText(QString::number(res.extraDoubleData[3]));
    ui->p5->setText(QString::number(res.extraDoubleData[4]));
    ui->status->setStyleSheet(res.defectArea > ui->defect_threshold_input->value() ?
                                  "background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);" :
                                  "background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);");
    ui->status->setText(res.defectArea > ui->defect_threshold_input->value() ? "Bad" : "Good");
    ui->defect->setText(QString::number(res.defectArea));
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_bRun(false)
    , m_hCam(NULL)
    ,m_hPropDlg(NULL)
    , m_hImg(NULL)
{
    ui->setupUi(this);
    initialCamera();

//    mockImg();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (m_hCam != NULL)
    {
        //1 MVGigE.h
        MVCloseCam(m_hCam);
        m_hCam = NULL;
    }

    if (m_hPropDlg != NULL)
    {
        //销毁属性页对话框
        //2 MVCamProptySheet.h
        MVCamProptySheetDestroy(m_hPropDlg);
        m_hPropDlg = NULL;
    }
    //1 MVGigE.h
    MVTerminateLib();

}

// 窗口设置背景图片
void MainWindow::paintEvent(QPaintEvent *pEvent)
{
//    QPainter painter(this);
//    painter.setOpacity(0.3);
//    painter.drawPixmap(0, 0, this->width(), this->height(), QPixmap("C:\\Users\\HuntZou\\Pictures\\壁纸\\voyager2_interstellar_blue_poster.jpg"));
}

int __stdcall StreamCB(MV_IMAGE_INFO* pInfo, ULONG_PTR nUserVal)
{
    MainWindow* pWd = (MainWindow*)nUserVal;
    return (pWd->showStreamOnLabel(pInfo));
}

int count = 0;
int MainWindow::showStreamOnLabel(MV_IMAGE_INFO* pInfo)
{
    ++count;

    MVInfo2Image(m_hCam,pInfo,(MVImage*)m_hImg);

    drawImage();

    // 检测图形中的过滤嘴
    int w = MVImageGetWidth(m_hImg);
    int h = MVImageGetHeight(m_hImg);
    Mat img;
    img.create(h, w, CV_8UC1);
    memcpy(img.data, pInfo->pImageBuffer, pInfo->nImageSizeAcq);
//    img = imread("C:\\Users\\HuntZou\\Documents\\Personal\\Temporary\\pics2\\mat2QImage_"+std::to_string(count%300+1)+".png", 0);
//    img = imread("D:\\Tmp\\good\\13_org.jpg", 0);

    DetectResult res;
    DetectCfg cfg(currentShape, currentFBDetachThreshold, resizeImg);
    Mat imgCopy = img.clone();
    filterDefectDetect(img, res, cfg, count);

//    imwrite("D:\\Tmp\\pic\\img_" + std::to_string(count) + "_" + std::to_string(res.detected) + "_" +std::to_string(QDateTime::currentDateTime().toMSecsSinceEpoch()) + ".jpg", imgCopy);

//    if (!res.detected)
//    {
//        return 0;
//    }

    QPixmap qpm = QPixmap::fromImage(mat2QImage(img, count));
    QMetaObject::invokeMethod(qApp, [this, qpm = qpm]() {
        ui->pic2->setPixmap(qpm);
    });

    switch(cfg.getShape())
    {
    case Shape::COIN:
    {
        if (res.extraDoubleData.size() == 8)
        {
            ui->p1->setText(QString::number((res.extraDoubleData[0] + res.extraDoubleData[1]
                            + res.extraDoubleData[2] + res.extraDoubleData[3])/4));
            ui->p2->setText(QString::number((res.extraDoubleData[4] + res.extraDoubleData[5]
                            + res.extraDoubleData[6] + res.extraDoubleData[7])/4));
        }
        break;
    };
    case Shape::STAR:
    {
        if (res.extraDoubleData.size() == 5)
        {
            ui->p1->setText(QString::number(res.extraDoubleData[0]));
            ui->p2->setText(QString::number(res.extraDoubleData[1]));
            ui->p3->setText(QString::number(res.extraDoubleData[2]));
            ui->p4->setText(QString::number(res.extraDoubleData[3]));
            ui->p5->setText(QString::number(res.extraDoubleData[4]));
        }
        break;
    };
    case Shape::CIRCLE:
    {
        if (res.extraDoubleData.size() == 2)
        {
            ui->p1->setText(QString::number(res.extraDoubleData[0]));
            ui->p2->setText(QString::number(res.extraDoubleData[1]));
        }
        break;
    };
    default:
    {};
    }


    QString costInfo = QString::fromStdString(std::to_string(res.cost) + " ms");
    QString defectArea = QString::number(res.defectArea);
    QString status = res.defectArea > ui->defect_threshold_input->value() ? "Bad" : "Good";
    auto statusBg = res.defectArea > ui->defect_threshold_input->value() ?
                "background-color: rgb(170, 0, 0);color: rgb(255, 255, 255);" :
                "background-color: rgb(0, 170, 0);color: rgb(255, 255, 255);";
    QMetaObject::invokeMethod(qApp, [this, costInfo = costInfo, defectArea = defectArea, status = status, statusBg = statusBg]() {
        ui->cost->setText(costInfo);
        ui->defect->setText(defectArea);
        ui->status->setText(status);
        ui->status->setStyleSheet(statusBg);
    });

    return 0;
}
void MainWindow::initialCamera()
{
    // 设置鼠标等待效果
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
    // 初始化相机函数库
    MVInitLib();
    // 打开相机
    int nCams = 0;
    //MVGigE.h
    MVGetNumOfCameras(&nCams);
#ifdef __SINGLEGRAB__
    qDebug("found %d cameras\n",nCams);
#endif
    //无相机
    if (nCams == 0)
    {
        //恢复鼠标效果
        QApplication::restoreOverrideCursor();
        QMessageBox::StandardButton t_Re = QMessageBox::warning(this,"Warning","Can't find camera",QMessageBox::Yes);
        if(t_Re == QMessageBox::Yes)
        {
            return ;
        }
    }
    //打开连接到电脑上的第一个相机
    MVSTATUS_CODES r = MVOpenCamByIndex(0, &m_hCam);
    if (m_hCam == NULL)
    {
        if (r == MVST_ACCESS_DENIED)
        {
            QMessageBox::StandardButton t_Re = QMessageBox::warning(this,"Warning","Access camera failed",QMessageBox::Yes);
            if(t_Re == QMessageBox::Yes)
            {
                return ;
            }
        }
        else
        {
            QMessageBox::StandardButton t_Re = QMessageBox::warning(this,"Warning","Open camera failed",QMessageBox::Yes);
            if(t_Re == QMessageBox::Yes)
            {
                return ;
            }
        }
        return;
    }
    TriggerModeEnums enumMode;
    MVGetTriggerMode(m_hCam, &enumMode);
    if (enumMode != TriggerMode_Off)
    {
         //设置为连续非触发模式
         MVSetTriggerMode(m_hCam, TriggerMode_Off);
    }
    int w, h;
    //3 GigECamera_Types.h
    MV_PixelFormatEnums PixelFormat;
    MVGetWidth(m_hCam, &w);
    MVGetHeight(m_hCam, &h);
    MVGetPixelFormat(m_hCam, &PixelFormat);
    //根据相机的宽、高、像素格式创建图像
    if (PixelFormat == PixelFormat_Mono8)
    {
        m_hImg = MVImageCreate(w, h, 8);
        #ifdef __SINGLEGRAB__
                qDebug() << "图像创建：" << 8;
        #endif
    }
    else
    {
        m_hImg = MVImageCreate(w, h, 24);
        #ifdef __SINGLEGRAB__
                qDebug() << "图像创建：" << 24;
        #endif
    }
    //设置相机属性页
    if (m_hPropDlg == NULL)
    {
        //创建及初始化属性页对话框
        const char t_Title[] = "Camera Properties";
        LPCTSTR strCaption = (LPCTSTR)t_Title;
        //2 MVCamProptySheet.h
        MVCamProptySheetCreateEx(&m_hPropDlg, m_hCam,0,strCaption,0xffff);
        if (m_hPropDlg == NULL)
        {
            QMessageBox::StandardButton t_Re = QMessageBox::warning(this,"Waring","Create property dialog faileds",QMessageBox::Yes);
            if(t_Re == QMessageBox::Yes)
            {
                return ;
            }
        }
    }
    ui->Start->setEnabled(true);
    ui->SingleGrab->setEnabled(true);
    ui->Attribute->setEnabled(true);
    //恢复鼠标效果
    QApplication::restoreOverrideCursor();
}
QImage img2QImage(HANDLE hImg)
{
    int w = MVImageGetWidth(hImg);
    int h = MVImageGetHeight(hImg);
    int bpp = MVImageGetBPP(hImg);
    int pitch = MVImageGetPitch(hImg);
    unsigned char *pImgData = (unsigned char *)MVImageGetBits(hImg);

    if (bpp == 8)
    {
        uchar *pSrc = pImgData;
        QImage image(pSrc, w,h, pitch, QImage::Format_Indexed8);
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        return image;
    }
    else if (bpp == 24)
    {
        const uchar *pSrc = (const uchar*)pImgData;
        QImage image(pSrc, w,h, pitch, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else
    {
        return QImage();
    }
}

void MainWindow::drawImage()
{
    QImage t_Image = img2QImage(m_hImg);
    QPixmap pm = QPixmap::fromImage(t_Image);

    QMetaObject::invokeMethod(qApp, [this, pm = pm]() {
        ui->pic1->setPixmap(pm);
        ui->pic1->setScaledContents(true);
    });

#ifdef __SINGLEGRAB__
    qDebug() << "width " << w << " height " << h << " bpp " << b;
#endif
}

void MainWindow::on_Attribute_clicked()
{
    if (m_hPropDlg != NULL)
    {
        //2 MVCamProptySheet.h
        MVCamProptySheetShow(m_hPropDlg, SW_SHOW);
    }
}

void MainWindow::on_Start_clicked()
{
    qDebug() << "on_Start_clicked: " << GetCurrentThreadId();
    MVStartGrab(m_hCam, StreamCB, (ULONG_PTR)this);
    m_bRun = TRUE;
    if (m_hPropDlg != NULL)
    {
        //2 MVCamProptySheet.h
        MVCamProptySheetCameraRun(m_hPropDlg, MVCameraRun_ON);
    }
    ui->Start->setEnabled(false);
    ui->SingleGrab->setEnabled(false);
    ui->Stop->setEnabled(true);
    ui->saveImage->setEnabled(true);
}

void MainWindow::on_Stop_clicked()
{
    MVStopGrab(m_hCam);
    m_bRun = FALSE;
    if (m_hPropDlg != NULL)
    {
        //2 MVCamProptySheet.h
        MVCamProptySheetCameraRun(m_hPropDlg, MVCameraRun_OFF);
    }
    ui->Start->setEnabled(true);
    ui->SingleGrab->setEnabled(true);
    ui->Stop->setEnabled(false);
    ui->saveImage->setEnabled(false);
}

void MainWindow::on_SingleGrab_clicked()
{
    MVSTATUS_CODES r = MVSingleGrab(m_hCam, m_hImg, 500);
    if (r == MVST_SUCCESS)
    {
        drawImage();
    }
    else
    {
        QMessageBox::StandardButton t_Re = QMessageBox::warning(this,"警告","图像采集失败",QMessageBox::Yes);
        if(t_Re == QMessageBox::Yes)
        {
            return ;
        }
    }
    ui->Start->setEnabled(true);
    ui->SingleGrab->setEnabled(true);
    ui->Stop->setEnabled(false);
    ui->saveImage->setEnabled(true);
}

void MainWindow::on_saveImage_clicked()
{
    bool t_Run = false;
    if (m_bRun)
    {
        t_Run = true;
        on_Stop_clicked();
    }
    HANDLE t_Img = MVImageCreate(MVImageGetWidth(m_hImg), MVImageGetHeight(m_hImg), MVImageGetBPP(m_hImg));
    memcpy(MVImageGetBits(t_Img), MVImageGetBits(m_hImg), MVImageGetPitch(t_Img) * MVImageGetHeight(t_Img));
    QString t_FileName = QFileDialog::getSaveFileName(this, tr("保存图像"),
                               "untitled.bmp",
                               tr("Images (*.png *.xpm *.jpg *.bmp *.tif)"));
    char t_File[100];
    sprintf(t_File,"%s",t_FileName.toStdString().c_str());
    if (!t_FileName.isEmpty())
    {
        MVImageSave(t_Img,t_File);
    }
    MVImageDestroy(t_Img);
    if (t_Run)
    {
        on_Start_clicked();
    }
}

void MainWindow::shapeChange(Shape shape)
{
    for (int i = 0; i < ui->shapeGrid->count(); i++)
    {
        ui->shapeGrid->itemAt(i)->widget()->setEnabled(true);
    }

    auto shapeBtn = this->findChild<QPushButton*>(QString::fromStdString(shapeToString(shape)));
    shapeBtn->setEnabled(false);

    currentShape = shape;

    // 清空数据框
    ui->p1->clear();
    ui->p2->clear();
    ui->p3->clear();
    ui->p4->clear();
    ui->p5->clear();


    // 设置相应参数
    int defectThreshold = settings->value(QString::fromStdString(shapeToString(currentShape)) + "_defectThreshold", 1000).toInt();
    auto defectThresholdSpinBox = this->findChild<QSpinBox*>("defect_threshold_input");
    defectThresholdSpinBox->setValue(defectThreshold);


    int FBDetachThreshold = settings->value(QString::fromStdString(shapeToString(currentShape)) + "_FBDetachThreshold", 185).toInt();
    auto FNDetachThresholdSInput = this->findChild<QSpinBox*>("FN_detach_threshold_input");
    FNDetachThresholdSInput->setValue(FBDetachThreshold);
}

void MainWindow::on_HEART_SMALL_clicked()
{
    shapeChange(Shape::HEART_SMALL);
}

void MainWindow::on_HEART_BIG_clicked()
{
    shapeChange(Shape::HEART_BIG);
}

void MainWindow::on_COIN_clicked()
{
    shapeChange(Shape::COIN);
}

void MainWindow::on_WINTERSWEET_SMALL_clicked()
{
    shapeChange(Shape::WINTERSWEET_SMALL);
}

void MainWindow::on_WINTERSWEET_BIG_clicked()
{
    shapeChange(Shape::WINTERSWEET_BIG);
}

void MainWindow::on_RAY_clicked()
{
    shapeChange(Shape::RAY);
}

void MainWindow::on_STAR_clicked()
{
    shapeChange(Shape::STAR);
}

void MainWindow::on_CIRCLE_clicked()
{
    shapeChange(Shape::CIRCLE);
}

void MainWindow::on_PEACH_clicked()
{
    shapeChange(Shape::PEACH);
}

void MainWindow::changeCurrentDefectThreshold(int v)
{
    if (currentShape == NULL)
    {
        QMessageBox::critical(this, tr("Warning"),  tr("select shape first"));
        return;
    }

    auto defectThresholdSpinBox = this->findChild<QSpinBox*>("defect_threshold_input");
    if (defectThresholdSpinBox->value() != v)
        defectThresholdSpinBox->setValue(v);

    auto defectThresholdSlider = this->findChild<QSlider*>("defect_threshold_slider");
    if (defectThresholdSlider->value() != v)
        defectThresholdSlider->setValue(v);

    settings->setValue(QString::fromStdString(shapeToString(currentShape)) + "_defectThreshold", v);
    currentDefectThreshold = v;
}

void MainWindow::changeCurrentFBDetachThreshold(int v)
{
    if (currentShape == NULL)
    {
        QMessageBox::critical(this, tr("Warning"),  tr("select shape first"));
        return;
    }

    auto FNDetachThresholdSInput = this->findChild<QSpinBox*>("FN_detach_threshold_input");
    if (FNDetachThresholdSInput->value() != v)
        FNDetachThresholdSInput->setValue(v);

    auto FNDetachThresholdSlider = this->findChild<QSlider*>("FN_detach_threshold_slider");
    if (FNDetachThresholdSlider->value() != v)
        FNDetachThresholdSlider->setValue(v);

    settings->setValue(QString::fromStdString(shapeToString(currentShape)) + "_FBDetachThreshold", v);
    currentFBDetachThreshold = v;
}

void MainWindow::on_defect_threshold_slider_valueChanged(int value)
{
    changeCurrentDefectThreshold(value);
}

void MainWindow::on_defect_threshold_input_valueChanged(int v)
{
    changeCurrentDefectThreshold(v);
}


void MainWindow::on_FN_detach_threshold_slider_valueChanged(int v)
{
    changeCurrentFBDetachThreshold(v);
}


void MainWindow::on_FN_detach_threshold_input_valueChanged(int v)
{
    changeCurrentFBDetachThreshold(v);
}

void MainWindow::on_shapeParmsReset_clicked()
{
    changeCurrentDefectThreshold(1000);
    changeCurrentFBDetachThreshold(185);
}


void MainWindow::on_resize_filter_img_slider_valueChanged(int value)
{
    resizeImg = value;
}


void MainWindow::on_double_camera_config_btn_clicked()
{
    auto doubleCameraConfig = new DoubleCameraConfig();
    // 双相机设定框弹出后不允许其他操作
    doubleCameraConfig->setModal(true);
    doubleCameraConfig->show();
}

