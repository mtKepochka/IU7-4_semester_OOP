#include <QFileDialog>
#include <QMessageBox>

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setSceneRect(-SCENE_WIDTH/2, -SCENE_HEIGHT/2,
                        SCENE_WIDTH, SCENE_HEIGHT);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    manager_actions(request);
    delete ui;
}

errors_t MainWindow::draw()
{
    ui->graphicsView->scene()->setSceneRect(-SCENE_WIDTH/2, -SCENE_HEIGHT/2,
                                            SCENE_WIDTH, SCENE_HEIGHT);
    request_t request;
    request.action = DRAW;
    request.view =
    {
        .scene = ui->graphicsView->scene(),
        .width =  ui->graphicsView->scene()->width(),
        .height =  ui->graphicsView->scene()->height()
    };

    return manager_actions(request);
}

void MainWindow::on_move_btn_clicked()
{
    request_t request;
    request.action = MOVE;
    request.move = {
        .dx = ui->dx->value(),
        .dy = ui->dy->value(),
        .dz = ui->dz->value()
    };

    errors_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_rotate_btn_clicked()
{
    request_t request;
    request.action = ROTATE;
    request.rotate = {
        .ax = ui->ax->value(),
        .ay = ui->ay->value(),
        .az = ui->az->value()
    };

    errors_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_scale_btn_clicked()
{
    request_t request;
    request.action = SCALE;
    request.scale = {
        .kx = ui->kx->value(),
        .ky = ui->ky->value(),
        .kz = ui->kz->value()
    };

    errors_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}


void MainWindow::on_open_file_triggered()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open skeleton model"),
                                                "/home/kepochka/Programming/OOP_data",
                                                tr("(*.txt)"));
    request_t request;
    request.action = OPEN;
    request.filename = path.toUtf8().data();

    errors_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}


void MainWindow::on_save_file_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save skeleton model"),
                                                "/home/kepochka/Programming/OOP_data",
                                                tr("(*.txt)"));
    request_t request;
    request.action = SAVE;
    request.filename = path.toUtf8().data();

    errors_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

