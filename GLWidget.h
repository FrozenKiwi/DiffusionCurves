#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "stdafx.h"

class CurveStorage;

class GLWidget : public QGLWidget
{
    Q_OBJECT

private:
    // image size (do not depend on QImage)
    int _canvas_width;
    int _canvas_height;

    bool    _isMouseDown;
    float   _zoomFactor;
    QPoint  _scrollOffset;

    CurveStorage* _curveStorage;

public:

    // constructor
    GLWidget( QGLFormat format, QWidget *parent = 0);
    // destructor
    ~GLWidget();

    // set bitmap image
    //void SetImage(QString img);

    void SetCanvas(int canvas_witdh, int canvas_height)
    {
        this->_canvas_width = canvas_witdh;
        this->_canvas_height = canvas_height;
    }

    // save current buffer to image
    void SaveImage(QString filename);
    //  obtain image size
    QSize GetCanvasSize() { return QSize(_canvas_width, _canvas_height); }

    // zoom in handle
    void ZoomIn();
    // zoom out handle
    void ZoomOut();
    // set zoom value
    void SetZoom(int val){this->_zoomFactor = val;}
    // get zoom value
    float GetZoomFactor() { return this->_zoomFactor; }

    // set horizontal scroll position
    void HorizontalScroll(int val);
    // set vertical scroll position
    void VerticalScroll(int val);
    // get scroll position (horizontal and vertical)
    QPoint GetScrollOffset() {return this->_scrollOffset;}

    // mouse press
    void mousePressEvent(int x, int y);
    // mouse move
    void mouseMoveEvent(int x, int y);
    // mouse release
    void mouseReleaseEvent(int x, int y);
    // mouse double click
    void mouseDoubleClick(int x, int y);

    // reset everything
    void Reset();

    // set image width and height
    void SetWidthHeight(int canvas_width, int canvas_height);

protected:
    // qt event
    bool event( QEvent * event );
    // init opengl
    void initializeGL();
    // draw
    void paintGL();

    void resizeGL(int width, int height);

private:
    void DrawCanvas();

public:
};


#endif // GLWIDGET_H
