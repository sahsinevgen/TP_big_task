#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <iostream>
#include <random>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton* spawner = new QPushButton(this);
    spawner->setText("Spawn new demon");
    spawner->setGeometry(0, 0, 200, 20);
    connect(spawner, SIGNAL(clicked(bool)), this, SLOT(spawn()));
    spawner->show();
}

void MainWindow::spawn()
{
    q.push_back(new DemonWarrior());
    label.push_back(new QLabel(this));
    label[q.size()-1]->setPixmap(QPixmap(q[q.size()-1]->get_path_to_image()));
    label[q.size()-1]->setGeometry(rand()%200+50, rand()%200+50, 64, 64);
    label[q.size()-1]->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
