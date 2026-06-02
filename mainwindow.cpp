#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), elapsedTime(0.00), circleCount(0), lastLapTime(0.0)
{
    ui->setupUi(this);

    ui->start_stop->setText("START");
    ui->circle->setText("KRUG");
    ui->cleaner->setText("CLEAN");
    ui->demo_time->setText("0.000");
    ui->textBrowser->append("--");

    this->timer = new QTimer(this);
    connect(this->timer, &QTimer::timeout, this, &MainWindow::updateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_circle_clicked(){
    if(this->elapsedTime > 0){
        this->circleCount++;
        double currentCircleTime = (this->elapsedTime * 0.1) - this->lastLapTime;

        QString currentCircle = "Circle: " + QString::number(this->circleCount) + ", time: " + QString::number(currentCircleTime);
        ui->textBrowser->append(currentCircle);

        this->lastLapTime = (this->elapsedTime * 0.1);
    }
};

void::MainWindow::on_cleaner_clicked(){
    this->elapsedTime = 0;
    ui->demo_time->setText("0.00");

    this->lastLapTime = 0.0;

    this->circleCount = 0;
    ui->textBrowser->clear();
}

void::MainWindow::on_start_stop_clicked(){
    if(this->timer->isActive()){
        this->timer->stop();
        ui->start_stop->setText("START");
    }else{
        this->timer->start(100);
        ui->start_stop->setText("STOP");
    };
}

void MainWindow::updateTime()
{
    this->elapsedTime++;
    ui->demo_time->setText(QString::number(this->elapsedTime * 0.1));
}
