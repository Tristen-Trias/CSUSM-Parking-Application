#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    onStart();
}

void MainWindow::onStart() {
    ui->date_edit->setDate(QDate::currentDate());
    ui->stackedWidget->setCurrentWidget(ui->login);
    ui->invalid_time_label->setVisible(false);
    ui->success_label->setVisible(false);
    this->fill_test_information();
    setImage();
}

void MainWindow::setImage() {
    QPixmap pm("assets/csusm_logo.png");

    ui->csusm_logo->setPixmap(pm);
    ui->csusm_logo->setScaledContents(true);
}

void MainWindow::tempList() { // will delete later
    QStandardItemModel *model = new QStandardItemModel(users.size(), 2, this);
    for (int i = 0; i < users.size(); i++) {
        ui->reservations_table->setModel(model);
    }

    //populate the table
    for (int i = 0; i < current_parking.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(current_parking[i]->get_section())));
        model->setItem(i, 1, new QStandardItem(QString::number(current_parking[i]->get_id())));
    }
}

void MainWindow::fill_test_information() {
    vector<string> first_names = {"John", "Steve", "Bob", "Alice", "Sally"};
    vector<string> last_names = {"Doe", "Smith", "Johnson", "Williams", "Brown"};
    vector<int> uIDs = {0, 1, 2, 3, 4};
    vector<int> user_types = {1, 1, 0, 2, 3};
    vector<bool> registered = {true, true, true, true, true};
    vector<double> ratings = {5.0, 4.0, 3.0, 2.0, 1.0};

    for (int i = 0; i < 5; i++) {
        User* temp = new User(first_names[i], last_names[i], uIDs[i], user_types[i], registered[i], ratings[i]);
        this->add_user(temp);
    }

    for (int i = 0; i < 20; i++) {
        ParkingSpace* temp = new ParkingSpace("F", i);
        this->add_parking(temp);
    }
}

void MainWindow::set_user_information(/*User* user*/) {
    //Get the user information from login and set it
    QString user = "Jane Doe";
    QString uID = "0";
    QString type = "1";
    QString rating = "5.0";

    ui->user_label->setText(user);
    ui->uID_label->setText(uID);
    ui->type_label->setText(type);
    ui->rating_label->setText(rating);
    //Set user information
}

void MainWindow::add_user(User* user) {
    this->users.push_back(user);
}

void MainWindow::add_parking(ParkingSpace* parking) {
    this->current_parking.push_back(parking);
}

void MainWindow::fill_user_table() {
    tempList();
}

MainWindow::~MainWindow() {
    delete ui;
}





//Slots




void MainWindow::on_login_button_clicked() {
    //Check to see if valid user
    //then login using line below
    //Get all parking lot information
    set_user_information(/*User* user*/);
    fill_user_table();
    ui->stackedWidget->setCurrentWidget(ui->home);
}

void MainWindow::on_new_reservation_button_clicked() {
    //get all parking lot information
    //fill_reservation_table();
    ui->stackedWidget->setCurrentWidget(ui->search);
}

void MainWindow::on_back_home_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->home);
}

void MainWindow::on_logout_button_clicked() {
    //Delete all information
    ui->stackedWidget->setCurrentWidget(ui->login);
}

void MainWindow::on_confirmation_back_button_clicked() {
    //Reload information from previous page
    ui->stackedWidget->setCurrentWidget(ui->search);
}

void MainWindow::on_reserve_button_clicked() {
    //Check if reservation times are valid
    //Check if spot is still available
    ui->stackedWidget->setCurrentWidget(ui->confirmation);
}

void MainWindow::on_confirmation_confirm_button_clicked() {
    //Add information to vectors or database
    ui->stackedWidget->setCurrentWidget(ui->home);

    ui->success_label->setVisible(true);
    //Tell user if reservation was successful or not
}

void MainWindow::on_date_edit_userDateChanged(const QDate &date){
    if (date < QDate::currentDate()) {
        ui->date_edit->setDate(QDate::currentDate());
    }
}


void MainWindow::on_start_time_input_userTimeChanged(const QTime &time) {
    compare_time(time, ui->end_time_input->time());
    //Check if date is valid
    //Check if time is valid
    //Check if spot is available
    //Update table with available spots
}

void MainWindow::on_end_time_input_userTimeChanged(const QTime &time) {
    compare_time(ui->start_time_input->time(), time);
}

void MainWindow::compare_time(const QTime &time1, const QTime &time2) {
    if (time1 >= time2) {
        ui->invalid_time_label->setVisible(true);
    } else {
        ui->invalid_time_label->setVisible(false);
    }
}
