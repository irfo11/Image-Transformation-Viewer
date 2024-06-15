QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstracttransformationdialog.cpp \
    binaryintensityslicingdialog.cpp \
    gammatransformationdialog.cpp \
    gaussiannoisedialog.cpp \
    highlightingintensitylevelslicingdialog.cpp \
    highpassfilterdialog.cpp \
    histogramequalizationdialog.cpp \
    imgtools.cpp \
    logtransformationdialog.cpp \
    lowpassfilterdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    negativetransformationdialog.cpp \
    saltandpeppernoisedialog.cpp

HEADERS += \
    abstracttransformationdialog.h \
    binaryintensityslicingdialog.h \
    gammatransformationdialog.h \
    gaussiannoisedialog.h \
    highlightingintensitylevelslicingdialog.h \
    highpassfilterdialog.h \
    histogramequalizationdialog.h \
    imgtools.h \
    logtransformationdialog.h \
    lowpassfilterdialog.h \
    mainwindow.h \
    negativetransformationdialog.h \
    saltandpeppernoisedialog.h

FORMS += \
    abstracttransformationdialog.ui \
    mainwindow.ui

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
