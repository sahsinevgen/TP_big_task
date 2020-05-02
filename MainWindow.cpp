#include "MainWindow.h"
#include "ui_MainWindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(600, 600);
    connect(ui->chooseButton, SIGNAL(clicked(bool)), this, SLOT(choose()));
    connect(ui->createButton, SIGNAL(clicked(bool)), this, SLOT(add_army()));
    this->choosedArmy = 0;
    ui->textLabel->setText("No army chosen");

//    QPushButton* spawner = new QPushButton(parent);
//    connect(spawner, SIGNAL(clicked(bool)), this, SLOT(spawn()));
    fabs.push_back(new GoodFabric(this));
    fabs.push_back(new EvilFabric(this));
    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start();
//    for (int j = 0; j < 2; j++) {
//        army.push_back(new EconomicArmy(fabs[j]));
//        for (int i = 0; i < 1; i++) {

//            Unit* unit = fabs[j]->create_unit(Warrior_ID);
//            army[j]->add_Unit(unit);
//            unit->set_position(Point(200, 200));
//            //label[q.size()-1]->show();
//        }
//        for (int i = 0; i < 1; i++) {
//            Unit* unit = fabs[j]->create_unit(Archer_ID);
//            army[j]->add_Unit(unit);
//            unit->set_position(Point(200, 200));
//            //label[q.size()-1]->show();
//        }
//    }
}

void MainWindow::add_army()
{
    Army* new_army;
    int side = (ui->isEvil->isChecked() ? 1 : 0);
    if (ui->isCommon->isChecked())
    {
        new_army = new Army();
    }
    else
    {
        new_army = new EconomicArmy(fabs[side]);
    }
    Point start_pos(rand() % 400 + 100, rand() % 400 + 100);
    new_army->set_position(start_pos);
    for (int i = 0; i < ui->numberOfWarriors->value(); i++)
    {
        Unit* new_unit = fabs[side]->create_unit(Warrior_ID);
        new_unit->set_position(start_pos);
        new_army->add_Unit(new_unit);
    }
    for (int i = 0; i < ui->numberOfWarriors->value(); i++)
    {
        Unit* new_unit = fabs[side]->create_unit(Archer_ID);
        new_unit->set_position(start_pos);
        new_army->add_Unit(new_unit);
    }
    army.push_back(new_army);
}

void MainWindow::update()
{
    for (int i = 0; i < army.size(); i++)
    {
        army[i]->do_action();
        army[i]->draw();
    }
    for (int i = 0; i < q.size(); i++)
    {
        //q[i]->do_action();
//        if (q[i]->is_dead())
//        {
//            label[i]->hide();
//        }
//        Point pos = q[i]->get_position();
//        //std::cout << pos.x << " " << pos.y << " -> ";
//        label[i]->setGeometry(pos.x, pos.y, 64, 64);
    }
}

void MainWindow::choose()
{
    int id = ui->chooseSpinBox->value();
    if (id == -1)
    {
        choosedArmy = 0;
        ui->textLabel->setText("No army chosen");
        return;
    }
    if (id >= army.size())
    {
        ui->textLabel->setText("Incorrect army number");
        return;
    }
    if (choosedArmy == 0)
    {
        choosedArmy = army[id];
        ui->textLabel->setText(QStringLiteral("You choose army number %1.\nNow chose it's target: another army number or point").arg(id));
    }
    else
    {
        if (choosedArmy == army[id]) {
            return;
        }
        choosedArmy->change_target(army[id]);
        choosedArmy = 0;
        ui->textLabel->setText("No army chosen");
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    mousePressPosition = Point(e->x(), e->y());
    if (choosedArmy != 0)
    {
        choosedArmy->change_target(mousePressPosition);
        choosedArmy = 0;
        ui->textLabel->setText("No army chosen");
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{

}

MainWindow::~MainWindow()
{
    delete ui;
}
