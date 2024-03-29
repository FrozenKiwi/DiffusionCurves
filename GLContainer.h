

#ifndef GLCONTAINER_H
#define GLCONTAINER_H

#include "stdafx.h"
#include "GLWidget.h"

class GLContainer : public QAbstractScrollArea
{
    Q_OBJECT

public:
    // constructor
    GLContainer(QWidget *parent = 0);

    // for Qt internal use
    void setWidget(QWidget *widget);
    QWidget *widget() const;

    // get renderer
    GLWidget* GetGLWidget();
    QSize GetCanvasSize();
    void SetCanvas(int canvas_witdh, int canvas_height);

    // set up scrolls (vertical and horizontal)
    void SetScrolls();


protected:
    // global event
    bool event( QEvent * event );

    // draw
    void paintEvent(QPaintEvent *event);

    // mouse events
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    // mouse wheel
    void wheelEvent(QWheelEvent* event);

    // keyboard
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    GLWidget* glWidget;
    QPoint prevScrollPos;
    QPoint prevMousePos;
    bool ctrlPressed;
    bool mousePressed;

    int sWidth;
    int sHeight;
    QPoint mousePos;

    // for updating opengl when scrolling display
    float xPrevF;
    float yPrevF;
    float prevZoomFactor;

    // previous number of strokes (not used)
    int prevNum;

    // timer for double click
    QTimer* doubleClickTimer;

    // timing for double click
    int     doubleClickTimeout;

private:
    // update opengl viewport
    void UpdateViewport(bool putInMiddle = false);

signals:
    // send message to UI (bottom left)
    //void SendMessage(QString msg);

    // drawing stroke is released (not used)
    //void StrokeRelease();

    // tell system to update
    //void UpdateThings();

private slots:
    // vertical scroll
    void VScrollChanged(int val);

    // horizontal scroll
    void HScrollChanged(int val);

    // for double click effect
    void DummyFunction();
};

#endif // GLCONTAINER_H
