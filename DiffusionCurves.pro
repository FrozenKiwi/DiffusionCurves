#-------------------------------------------------
#
# Project created by QtCreator 2014-12-19T12:06:07
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DiffusionCurves
TEMPLATE = app


SOURCES += main.cpp\
        DCMainWindow.cpp \
    GLContainer.cpp \
    GLWidget.cpp \
    stdafx.cpp \
    CurveStorage.cpp \
    CurveRDP.cpp

HEADERS  += DCMainWindow.h \
    GLContainer.h \
    GLWidget.h \
    stdafx.h \
    CurveStorage.h \
    DCPoint.h \
    CurveRDP.h

FORMS    += DCMainWindow.ui

INCLUDEPATH += /usr/local/include/opencv2
INCLUDEPATH += /home/azer/Qt5.3.2/5.3/gcc_64/include/QtOpenGL
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_imgcodecs
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_flann

LIBS += -lglut
LIBS += -lGL
LIBS += -lGLU
#LIBS += -lGLEW

CONFIG += console
CONFIG += opengl
CONFIG += thread

CONFIG += precompile_header
PRECOMPILED_HEADER = stdafx.h
HEADERS += stdafx.h

#QMAKE_CFLAGS = -fpermissive
#QMAKE_CXXFLAGS = -fpermissive
#QMAKE_LFLAGS = -fpermissive

#QT       += core gui
#QT       += opengl
