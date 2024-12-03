#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qpixmap.h>
#include <QStandardItemModel>
#include <QAbstractItemView>

#include "headers/users/User.h"
#include "src/parking/ParkingLotFactory.hpp"

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
    vector<User*> users;
    User* current_user;
    ParkingLotFactory* factory;
    vector<ParkingLot> lots;
    vector<ParkingSpace> current_parking;
    vector<ParkingSpace> empty_parking;
    int selected_lot = 0, selected_row = -1;

    void ui_checks();
    void setImage();
    void onStart();
    void fill_user_table();
    void fill_reservation_table();

    void set_user_information(User* user);
    void add_user(User* user);
    User* get_user(int uID);
    void get_user(string first_name, string last_name);
    void get_user_parking();
    bool search_uID(int n);
    //void add_parking(ParkingSpace* parking);
    void update_reservation_table();
    void update_available_table(int index);
    void update_available_table(int index, int time1, int time2);
    void update_user_table();

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
    void on_new_user_button_clicked();
    void on_back_login_clicked();
    void on_create_user_button_clicked();

    void on_lot_box_input_currentIndexChanged(int index);
    void on_available_list_clicked(const QModelIndex &index);
    void on_delete_reservation_button_clicked();
    void on_reservations_table_clicked(const QModelIndex &index);
    void on_done_button_clicked();
    void on_create_parking_button_clicked();
};
#endif // MAINWINDOW_H
