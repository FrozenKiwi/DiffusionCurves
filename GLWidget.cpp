

#include "stdafx.h"
#include "GLWidget.h"


GLWidget::GLWidget(QGLFormat format, QWidget *parent) :
    QGLWidget(format, parent),
    _isMouseDown(false),
    _zoomFactor(1.0),
    _canvas_width(0),
    _canvas_height(0)
{
}

GLWidget::~GLWidget()
{
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

bool GLWidget::event( QEvent * event ) { return QGLWidget::event(event); }

// This is an override function from Qt but I can't find its purpose
void GLWidget::resizeGL(int width, int height)  { QGLWidget::resizeGL(width, height); }

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

    std::cout << x << " " << y << std::endl;

//    // mesh deform fix
//    //if(this->_drawMode == DRAW_DEFORMATION && _meshDeformer)  { _meshDeformer->mousePressEvent(x, y); }
//    if(this->_drawMode == DRAW_DEFORMATION && _deformManager)  { _deformManager->mousePressEvent(x, y); }
//    else if(this->_drawMode == DRAW_PART_EXTRACTION && _partExtractor)  { _partExtractor->mousePressEvent(x, y); }
//    else if(this->_drawMode == DRAW_LIGHTING_EFFECT && _lightingEffect) {_lightingEffect->mousePressEvent(x, y);}

//    if(x < 0 || y < 0 || x >= _img_width || y >= _img_height) { return; }

//    if(_uStrokeLines.size() == 0)
//    {
//        std::vector<CVSystem::MyLine> newSegment;
//        _uStrokeLines.push_back(newSegment);
//        _uStrokeColors.push_back(qRgb(rand() % 255, rand() % 255, rand() % 255));
//    }
//    _uPrevPoint =  CVSystem::MyPoint(x, y);
}

// Mouse is moved
void GLWidget::mouseMoveEvent(int x, int y)
{
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;

//    // mesh deform fix
//    //if(this->_drawMode == DRAW_DEFORMATION && _meshDeformer) { _meshDeformer->mouseMoveEvent(x, y); }
//    if(this->_drawMode == DRAW_DEFORMATION && _deformManager) { _deformManager->mouseMoveEvent(x, y); }
//    if(this->_drawMode == DRAW_PART_EXTRACTION && _partExtractor)  { _partExtractor->mouseMoveEvent(x, y); }
//    else if(this->_drawMode == DRAW_LIGHTING_EFFECT && _lightingEffect) {_lightingEffect->mouseMoveEvent(x, y);}

//    if(x < 0 || y < 0 || x >= _img_width|| y >= _img_height|| !_isMouseDown) { return; }

//    if(_drawMode != DRAW_RASTER) { return; }

//    int idx = _uStrokeLines.size() - 1;
//    if(idx >= 0)
//    {
//        _uStrokeLines[idx].push_back(CVSystem::MyLine(_uPrevPoint.x, _uPrevPoint.y, x, y));
//        _uPrevPoint = CVSystem::MyPoint(x,y);
//    }
}

// Mouse is released
void GLWidget::mouseReleaseEvent(int x, int y)
{
    _isMouseDown = false;
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;

//    // mesh deform fix
//    //if(this->_drawMode == DRAW_DEFORMATION && _meshDeformer)  { _meshDeformer->mouseReleaseEvent(x, y); }
//    if(this->_drawMode == DRAW_DEFORMATION && _deformManager)  { _deformManager->mouseReleaseEvent(x, y); }
//    else if(this->_drawMode == DRAW_PART_EXTRACTION && _partExtractor) { _partExtractor->mouseReleaseEvent(x, y); }
//    else if(this->_drawMode == DRAW_LIGHTING_EFFECT && _lightingEffect) {_lightingEffect->mouseReleaseEvent(x, y);}

//    //if(x < 0 || y < 0 || x >= imgOriginal.width()|| y >= imgOriginal.height()|| !isMouseDown)
//    //{ return; }
}

void GLWidget::mouseDoubleClick(int x, int y)
{
    x += _scrollOffset.x();	y += _scrollOffset.y();
    x /= _zoomFactor;		y /= _zoomFactor;
}

// Set function
//void GLWidget::SetImage(QString img)
//{
//    this->Reset();
//    _imgOriginal.load(img);

//    // size
//    this->_img_width = _imgOriginal.width();
//    this->_img_height = _imgOriginal.height();

//    // calculating power-of-two (pow) size
//    int xpow = (int) std::pow(2.0, std::ceil( std::log10((double)_img_width )/std::log10(2.0) ) );
//    int ypow = (int) std::pow(2.0, std::ceil( std::log10((double)_img_height )/std::log10(2.0) ) );

//    xpow = my_max(xpow, ypow);	// the texture should be square too
//    xpow = my_min(xpow, 1024);	// shrink if the size is too big
//    ypow = xpow;

//    // transform the image to square pow size
//    _imgGL = _imgOriginal.scaled(xpow, ypow, Qt::IgnoreAspectRatio);
//    _imgGL = QGLWidget::convertToGLFormat(_imgGL);

//    glGenTextures(1, &_imgID);
//    glBindTexture( GL_TEXTURE_2D, _imgID );
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _imgGL.width(), _imgGL.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _imgGL.bits());

//    this->updateGL(); // Update !
//}

// Save image to file
void GLWidget::SaveImage(QString filename)
{
    // Save onscreen
    paintGL();
    glFlush();
    QImage image = this->grabFrameBuffer();
    if( !image.save( filename) ) std::cout << "Error saving image\n";

    // Save triangle only (OpenCV)
    /*
    double maxZoom = 1.0;
    int w = img_width * maxZoom;
    int h = img_height * maxZoom;
    cv::Mat imgMat(h, w, CV_8UC1);
    imgMat = 255;

    for(size_t a = 0; a < lsTriangles.size(); a++)
    {
        CVSystem::MyTriangle t = lsTriangles[a];
        std::vector<cv::Point> tri(3);
        tri[0] = cv::Point(t.p1.x * maxZoom, t.p1.y * maxZoom);
        tri[1] = cv::Point(t.p2.x * maxZoom, t.p2.y * maxZoom);
        tri[2] = cv::Point(t.p3.x * maxZoom, t.p3.y * maxZoom);

        const cv::Point* elementPoints[1] = { &tri[0] };
        int numberOfPoints = (int)tri.size();

        cv::fillPoly (imgMat, elementPoints, &numberOfPoints, 1, cv::Scalar(0), 8);
    }
    cv::imwrite(filename.toStdString(), imgMat);
    */
}

//void GLWidget::SetDrawMode(DrawMode mode) { _drawMode = mode; }
void GLWidget::HorizontalScroll(int val) { _scrollOffset.setX(val); }
void GLWidget::VerticalScroll(int val) { _scrollOffset.setY(val); }
void GLWidget::ZoomIn() { this->_zoomFactor += 0.05f; }
void GLWidget::ZoomOut() { this->_zoomFactor -= 0.05f; if(this->_zoomFactor < 0.1f) _zoomFactor = 0.1f; }

void GLWidget::Reset()
{
    //if(_img_width != 0 && _img_height != 0) { glDeleteTextures( 1, &_imgID ); }
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

