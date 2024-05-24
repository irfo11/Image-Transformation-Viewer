QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imgtools.cpp \
    main.cpp \
    mainwindow.cpp \
    negativetransformationdialog.cpp

HEADERS += \
    imgtools.h \
    mainwindow.h \
    negativetransformationdialog.h

FORMS += \
    mainwindow.ui \
    negativetransformationdialog.ui

# Adding Qt libraries
INCLUDEPATH += C:\opencv\build\include

LIBS += C:\opencv-build\bin\libopencv_core490.dll
LIBS += C:\opencv-build\bin\libopencv_highgui490.dll
LIBS += C:\opencv-build\bin\libopencv_imgcodecs490.dll
LIBS += C:\opencv-build\bin\libopencv_imgproc490.dll
LIBS += C:\opencv-build\bin\libopencv_features2d490.dll
LIBS += C:\opencv-build\bin\libopencv_calib3d490.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
