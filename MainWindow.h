#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "./objects/units/DemonWarrior.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    QVector<Unit*> q;
    QVector<QLabel*> label;
private slots:
    void spawn();
};

#endif // MAINWINDOW_H
