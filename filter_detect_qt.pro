QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    detect.cpp \
    doublecameraconfig.cpp \
    main.cpp \
    mainwindow.cpp \
    utils.cpp

HEADERS += \
    detect.h \
    doublecameraconfig.h \
    mainwindow.h \
    utils.h

FORMS += \
    doublecameraconfig.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# 摄像机依赖
LIBS += -L$$PWD/lib/ -lMVGigE
LIBS += -L$$PWD/lib/ -lMVCamProptySheet
LIBS += -L$$PWD/lib/ -lMVTickDlg
INCLUDEPATH += $$PWD/include


# opencv依赖
INCLUDEPATH += C:\Users\HuntZou\Documents\Personal\Projects\opencv-4.6.0\build\install\include

LIBS += -LC:\Users\HuntZou\Documents\Personal\Projects\opencv-4.6.0\build\install\x64\vc17\lib  \
        -lopencv_calib3d460 \
        -lopencv_core460    \
        -lopencv_dnn460 \
        -lopencv_features2d460  \
        -lopencv_flann460   \
        -lopencv_gapi460    \
        -lopencv_highgui460 \
        -lopencv_imgcodecs460   \
        -lopencv_imgproc460 \
        -lopencv_ml460  \
        -lopencv_objdetect460   \
        -lopencv_photo460   \
        -lopencv_stitching460   \
        -lopencv_video460   \
        -lopencv_videoio460

# debug release版本
QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO
