

#include "stdafx.h"
#include "GLWidget.h"
#include "CurveStorage.h"

GLWidget::GLWidget(QGLFormat format, QWidget *parent) :
    QGLWidget(format, parent),
    _isMouseDown(false),
    _zoomFactor(1.0),
    _canvas_width(0),
    _canvas_height(0),
    _curveStorage(new CurveStorage())
{
}

GLWidget::~GLWidget()
{
    if(_curveStorage) { delete _curveStorage; }
}

void GLWidget::initializeGL()
{
}

/**
 * SET
 */
void GLWidget::SetWidthHeight(int canvas_width, int canvas_height)
{
    this->_canvas_width = canvas_width;
    this->_canvas_height = canvas_height;
}

bool GLWidget::event( QEvent * event )
{
    return QGLWidget::event(event);
}

// This is an override function from Qt but I can't find its purpose
void GLWidget::resizeGL(int width, int height)
{
    QGLWidget::resizeGL(width, height);
}

void GLWidget::paintGL()
{
    glClearColor(0.5, 0.5, 0.5, 1.0);
    //glClearColor(0.0, 0.0, 0.0, 1.0);

    glViewport(0, 0, this->width(),  this->height());
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // scrollOffset has the coordinates of horizontal and vertical scrollbars
    gluOrtho2D(0 + _scrollOffset.x(),
               this->width() + _scrollOffset.x(),
               this->height() + _scrollOffset.y(),
               0 + _scrollOffset.y());	// flip the y axis
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glScalef(_zoomFactor, _zoomFactor, _zoomFactor);
    glClear(GL_COLOR_BUFFER_BIT);

    DrawCanvas();
    _curveStorage->DrawCurve();
    //DrawTexture(_imgID, _img_width, _img_height);

    //glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}
// Mouse is pressed
void GLWidget::mousePressEvent(int x, int y)
{
    _isMouseDown = true;

    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;

    //std::cout << x << " " << y << std::endl;
    _curveStorage->StartCurve();
    _curveStorage->AddPoint(x, y);

    this->repaint();
}

// Mouse is moved
void GLWidget::mouseMoveEvent(int x, int y)
{
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;

    if(_isMouseDown)
    {
        _curveStorage->AddPoint(x, y);
        this->repaint();
    }
}

// Mouse is released
void GLWidget::mouseReleaseEvent(int x, int y)
{
    _isMouseDown = false;
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;

    _curveStorage->AddPoint(x, y);
    _curveStorage->EndCurve();

    this->repaint();
}

void GLWidget::mouseDoubleClick(int x, int y)
{
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;
}

// Save image to file
void GLWidget::SaveImage(QString filename)
{
    // Save onscreen
    paintGL();
    glFlush();
    QImage image = this->grabFrameBuffer();
    if( !image.save( filename) ) std::cout << "Error saving image\n";
}

//void GLWidget::SetDrawMode(DrawMode mode) { _drawMode = mode; }
void GLWidget::HorizontalScroll(int val) { _scrollOffset.setX(val); }
void GLWidget::VerticalScroll(int val) { _scrollOffset.setY(val); }
void GLWidget::ZoomIn() { this->_zoomFactor += 0.05f; }
void GLWidget::ZoomOut() { this->_zoomFactor -= 0.05f; if(this->_zoomFactor < 0.1f) _zoomFactor = 0.1f; }

void GLWidget::Reset()
{
}

void GLWidget::DrawCanvas()
{
    glEnable(GL_TEXTURE_2D);

    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glColor4f(1.0, 1.0, 1.0, 1.0);

    //glBindTexture( GL_TEXTURE_2D, texId );

    glBegin(GL_QUADS);

    // text coords are flipped in y axis
    glTexCoord2d(0,1); glVertex3d(0,	 0,          0);
    glTexCoord2d(1,1); glVertex3d(_canvas_width, 0,          0);
    glTexCoord2d(1,0); glVertex3d(_canvas_width, _canvas_height, 0);
    glTexCoord2d(0,0); glVertex3d(0,	 _canvas_height, 0);

    glEnd();

    glFlush();
    //glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

