#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    onStart();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStart() {
    setImage();
    ui->date_edit->setDate(QDate::currentDate());
    ui->stackedWidget->setCurrentWidget(ui->login);
    ui->invalid_time_label->setVisible(false);
    ui->success_label->setVisible(false);
    ui->invalid_login_label->setVisible(false);
    this->fill_test_information();
}

void MainWindow::setImage() {
    QPixmap pm(":/images/csusm_logo.png");

    ui->csusm_logo->setPixmap(pm);
    ui->csusm_logo->setScaledContents(true);
}

void MainWindow::tempList() { // adds temporary data to the table
    QStandardItemModel *model = new QStandardItemModel(current_parking.size(), 3, this);
    for (int i = 0; i < users.size(); i++) {
        ui->reservations_table->setModel(model);
    }

    model->setHorizontalHeaderLabels(QStringList() << "Lot" << "Space Number" << "End Time");

    for (int i = 0; i < current_parking.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(current_parking[i].getLot())));
        model->setItem(i, 1, new QStandardItem(QString::number(current_parking[i].getSpaceNumber())));
        model->setItem(i, 2, new QStandardItem(QString::number(current_parking[i].getReservationEndTime())));
    }
}

void MainWindow::fill_test_information() {
    vector<string> first_names = {"John", "Steve", "Bob", "Alice", "Sally"};
    vector<string> last_names = {"Doe", "Smith", "Johnson", "Williams", "Brown"};
    vector<int> uIDs = {0, 1, 2, 3, 4};
    vector<int> user_types = {1, 1, 0, 2, 3};
    vector<bool> registered = {true, true, true, true, true};

    for (int i = 0; i < 5; i++) {
        User* temp = new User(first_names[i], last_names[i], uIDs[i], registered[i], user_types[i]);
        this->add_user(temp);
    }

    ParkingLot A = factory->createParkingLot("A", 10);
    ParkingLot B = factory->createParkingLot("B", 20);
    lots.push_back(A);
    lots.push_back(B);

    lots[0].reserveSpace(users[0]->get_uID(), 1, 1, 4);
    lots[1].reserveSpace(users[0]->get_uID(), 1, 2, 5);
    lots[0].reserveSpace(users[0]->get_uID(), 2, 3, 6);
    lots[1].reserveSpace(users[0]->get_uID(), 2, 4, 7);
}

void MainWindow::set_user_information(User* user) {
    //Get the user information from login and set it

    this->current_user = user;

    string s = user->get_first_name() + " " + user->get_last_name();
    QString name = QString::fromStdString(s);
    QString uID = QString::number(user->get_uID());
    QString type = QString::number(user->get_user_type());
    QString rating = QString::number(user->get_rating());

    ui->user_label->setText(name);
    ui->uID_label->setText(uID);
    ui->type_label->setText(type);
    ui->rating_label->setText(rating);

    for (int i = 0; i < lots.size(); i++) {
        for (int j = 0; j < lots[i].getSpaces().size(); j++) {
            if (lots[i].getSpaces()[j].getUserID() == user->get_uID()) {
                this->current_parking.push_back(lots[i].getSpaces()[j]);
            }
        }
    }
    //Set user information
}

void MainWindow::add_user(User* user) {
    this->users.push_back(user);
}

User* MainWindow::get_user(int uID) {
    for (int i = 0; i < this->users.size(); i++) {
        if (this->users[i]->get_uID() == uID) {
            return this->users[i];
        }
    }
    return nullptr;
}

// void MainWindow::add_parking(ParkingSpace* parking) {
//     this->current_parking.push_back(parking);
// }

void MainWindow::fill_user_table() {
    tempList();
}


void MainWindow::update_reservation_table() {

}

void MainWindow::update_available_table() {

}



//Slots




void MainWindow::on_login_button_clicked() {
    int u = this->ui->text_box_username->toPlainText().toInt();
    User* user = this->get_user(u);

    cout << "User: " << u << endl;

    if (user) {
        this->set_user_information(user);
        fill_user_table();
        ui->stackedWidget->setCurrentWidget(ui->home);
    } else {
        ui->invalid_login_label->setVisible(true);
    }

}

void MainWindow::on_new_reservation_button_clicked() {
    //update parking lot information
    //fill_reservation_table();
    this->update_available_table(1);
    ui->stackedWidget->setCurrentWidget(ui->search);
}

void MainWindow::on_back_home_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->home);
}

void MainWindow::on_logout_button_clicked() {
    //Delete all information
    current_user = nullptr;
    current_parking.clear();
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
    ui->end_time_input->setMinimumTime(time);
    //Check if date is valid
    //Check if time is valid
    //Check if spot is available
    //Update table with available spots
}

void MainWindow::on_end_time_input_userTimeChanged(const QTime &time) {
    compare_time(ui->start_time_input->time(), time);
    ui->start_time_input->setMaximumTime(time);
}

void MainWindow::compare_time(const QTime &time1, const QTime &time2) {
    if (time1 >= time2) {
        ui->invalid_time_label->setVisible(true);
    } else {
        ui->invalid_time_label->setVisible(false);
    }
}

void MainWindow::on_new_user_button_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->create_user);
}


void MainWindow::on_back_login_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->login);
}


void MainWindow::on_create_user_button_clicked() {
    string first = ui->create_first_name->toPlainText().toStdString();
    string last = ui->create_last_name->toPlainText().toStdString();
    int uID = ui->create_user_id->toPlainText().toInt();
    int type = ui->create_user_type->value();

    cout << "Button clicked" << endl;

    User* u = new User(first, last, uID, false, type);
    this->users.push_back(u);

    this->set_user_information(u);
    fill_user_table();

    ui->stackedWidget->setCurrentWidget(ui->home);
}


void MainWindow::on_lot_box_input_currentIndexChanged(int index) {
    this->update_available_table(index);
}

