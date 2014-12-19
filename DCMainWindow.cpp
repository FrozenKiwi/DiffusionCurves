#include "DCMainWindow.h"
#include "ui_DCMainWindow.h"

DCMainWindow::DCMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DCMainWindow)
{
    ui->setupUi(this);

    ui->frame->SetCanvas(800, 600);
}

DCMainWindow::~DCMainWindow()
{
    delete ui;
}
