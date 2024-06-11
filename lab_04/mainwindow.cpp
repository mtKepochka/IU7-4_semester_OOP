#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Этаж №1 | Движение кабины разблокировано | Двери закрыты";
}

void MainWindow::onCabinBtnClicked(const int btnNumber) {
    qDebug() << "Кабина | Нажата кнопка " << btnNumber;
    elevator.btnClick(btnNumber);
}

void MainWindow::onFloorBtnClicked(const int btnNumber) {
    qDebug() << "Этаж №" << btnNumber << "| Вызов лифта";
    elevator.btnClick(btnNumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lift_btn_1_clicked()
{
    onCabinBtnClicked(1);
}


void MainWindow::on_lift_btn_2_clicked()
{
    onCabinBtnClicked(2);
}


void MainWindow::on_lift_btn_3_clicked()
{
    onCabinBtnClicked(3);
}


void MainWindow::on_lift_btn_4_clicked()
{
    onCabinBtnClicked(4);
}


void MainWindow::on_lift_btn_5_clicked()
{
    onCabinBtnClicked(5);
}


void MainWindow::on_floor_btn_5_clicked()
{
    onFloorBtnClicked(5);
}


void MainWindow::on_floor_btn_4_clicked()
{
    onFloorBtnClicked(4);
}


void MainWindow::on_floor_btn_3_clicked()
{
    onFloorBtnClicked(3);
}


void MainWindow::on_floor_btn_2_clicked()
{
    onFloorBtnClicked(2);
}


void MainWindow::on_floor_btn_1_clicked()
{
    onFloorBtnClicked(1);
}

