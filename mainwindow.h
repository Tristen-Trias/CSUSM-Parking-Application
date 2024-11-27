#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpixmap.h>
#include "headers/parking/Parking.h"

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

private:
    Ui::MainWindow *ui;
    vector<Parking*> lots;
    void setImage();
    void onStart();
    void tempList();

private slots:

    void on_login_button_clicked();
    void on_new_reservation_button_clicked();
    void on_back_home_clicked();
    void on_logout_button_clicked();

    void on_confirmation_back_button_clicked();
    void on_reserveButton_clicked();
    void on_confirmation_confirm_button_clicked();
    // void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
