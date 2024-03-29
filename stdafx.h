#pragma once

// Qt OpenGL
#include <QtOpenGL/QGLWidget>
#include <QGLShader>
#include <QGLFormat>
#include <QGLFramebufferObject>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtGui/QMouseEvent>


// Scrollbar
#include <QAbstractScrollArea>
#include <QScrollArea>
#include <QScrollBar>

#include <QColor>
#include <QFileDialog>
#include <QImage>
#include <QImageReader>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>

#include <QStyle>
#include <QTimer>
#include <QWidget>

#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <sstream>
#include <cfloat>
#include <ctime>
#include <cmath>
#include <iostream>
#include <fstream>

//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <malloc.h>

#include <GL/glu.h>
#include <GL/glut.h>

#define my_min(a,b) ((a)<(b) ? (a) : (b))
#define my_max(a,b) ((a)>(b) ? (a) : (b))

#ifndef M_EPS
#define M_EPS		1e-8
#endif


