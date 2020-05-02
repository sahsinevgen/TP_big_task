#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QTimer>
#include <QMouseEvent>
#include "./fabrics/EvilFabric.h"
#include "./fabrics/GoodFabric.h"
#include "./objects/units/EconomicArmy.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);


private:
    bool correct_armi_ID(int ID);
    Ui::MainWindow *ui;
    QTimer* timer;
    QVector<Unit*> q;
    QVector<QLabel*> label;
    QVector<UnitFabric*> fabs;
    QVector<Army*> army;
    Army *choosedArmy;
    Point mousePressPosition;

private slots:
    void add_army();
    void update();
    void choose();
};

#endif // MAINWINDOW_H
