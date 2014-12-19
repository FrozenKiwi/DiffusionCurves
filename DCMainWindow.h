#ifndef DCMAINWINDOW_H
#define DCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class DCMainWindow;
}

class DCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DCMainWindow(QWidget *parent = 0);
    ~DCMainWindow();

private:
    Ui::DCMainWindow *ui;
};

#endif // DCMAINWINDOW_H
