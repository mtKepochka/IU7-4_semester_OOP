#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onCabinBtnClicked(int btn_number);
    void onFloorBtnClicked(int btn_number);

    void on_lift_btn_1_clicked();

    void on_lift_btn_2_clicked();

    void on_lift_btn_3_clicked();

    void on_lift_btn_4_clicked();

    void on_lift_btn_5_clicked();

    void on_floor_btn_5_clicked();

    void on_floor_btn_4_clicked();

    void on_floor_btn_3_clicked();

    void on_floor_btn_2_clicked();

    void on_floor_btn_1_clicked();

private:
    Ui::MainWindow *ui;

    Elevator elevator;
};
#endif // MAINWINDOW_H
