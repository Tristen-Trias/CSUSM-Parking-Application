#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpixmap.h>
#include <QStandardItemModel>

#include "headers/users/User.h"
#include "headers/parking/ParkingSpace.h"

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
    void setImage();
    void onStart();
    void tempList(); //delete later
    void fill_user_table();
    void fill_reservation_table();
    vector<User*> users;
    vector<ParkingSpace*> current_parking;

    void set_user_information(/*User* user*/);
    void add_user(User* user);
    void add_parking(ParkingSpace* parking);

    void compare_time(const QTime &time1, const QTime &time2);

    //This is a placeholder for an already filled database
    void fill_test_information();

private slots:

    void on_login_button_clicked();
    void on_new_reservation_button_clicked();
    void on_back_home_clicked();
    void on_logout_button_clicked();

    void on_confirmation_back_button_clicked();
    void on_reserve_button_clicked();
    void on_confirmation_confirm_button_clicked();
    void on_date_edit_userDateChanged(const QDate &date);
    void on_start_time_input_userTimeChanged(const QTime &time);
    void on_end_time_input_userTimeChanged(const QTime &time);
};
#endif // MAINWINDOW_H
