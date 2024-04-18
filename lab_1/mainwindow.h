#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "actions.h"

#define SCENE_HEIGHT 548
#define SCENE_WIDTH 1258

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
    errors_t draw();

    void on_move_btn_clicked();

    void on_rotate_btn_clicked();

    void on_scale_btn_clicked();

    void on_open_file_triggered();

    void on_save_file_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
