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
    this->setWindowTitle(QString::fromStdString("CSUSM Parking Application"));
    ui_checks();

    this->fill_test_information();
}

void MainWindow::ui_checks() {
    ui->date_edit->setDate(QDate::currentDate());
    ui->stackedWidget->setCurrentWidget(ui->login);
    ui->invalid_time_label->setVisible(false);
    ui->success_label->setVisible(false);
    ui->invalid_login_label->setVisible(false);
    ui->invalid1->setVisible(false);
    ui->invalid2->setVisible(false);
    ui->invalid3->setVisible(false);
    ui->reservations_table->verticalHeader()->hide();

    QTime* minTime = new QTime(7, 0, 0);
    QTime* maxTime = new QTime(23, 0, 0);

    ui->start_time_input->setMinimumTime(*minTime);
    ui->end_time_input->setMinimumTime(*maxTime);

    ui->available_list->verticalHeader()->hide();
    ui->available_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->available_list->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->reservations_table->verticalHeader()->hide();
    ui->reservations_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->reservations_table->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->text_box_username->clear();
    ui->create_first_name->clear();
    ui->create_last_name->clear();
    ui->create_user_id->clear();

    ui->delete_reservation_button->hide();
    ui->create_parking_button->hide();

}

void MainWindow::setImage() {
    QPixmap pm(":/images/csusm_logo.png");

    ui->csusm_logo->setPixmap(pm);
    ui->csusm_logo->setScaledContents(true);
}

void MainWindow::update_user_table() {
    QStandardItemModel *model = new QStandardItemModel(current_parking.size(), 4, this);
    for (int i = 0; i < users.size(); i++) {
        ui->reservations_table->setModel(model);
    }

    model->setHorizontalHeaderLabels(QStringList() << "Lot" << "Space Number" << "Start Time" << "End Time");

    for (int i = 0; i < current_parking.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(current_parking[i].getLot())));
        model->setItem(i, 1, new QStandardItem(QString::number(current_parking[i].getSpaceNumber())));

        QTime start = QTime(current_parking[i].getReservationStartTime(), 0, 0);
        QTime end = QTime(current_parking[i].getReservationEndTime(), 0, 0);

        model->setItem(i, 2, new QStandardItem(start.toString()));
        model->setItem(i, 3, new QStandardItem(end.toString()));
    }

    QStandardItemModel* list = new QStandardItemModel(lots.size(), 2, this);
    ui->lot_box_input->setModel(list);

    for (int i = 0; i < lots.size(); i++) {
        list->setItem(i, 0, new QStandardItem(QString::fromStdString(lots[i].getLotName())));
        list->setItem(i, 1, new QStandardItem(QString::number(lots[i].countEmptySpaces())));
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
    ParkingLot C = factory->createParkingLot("C", 15);

    lots.push_back(A);
    lots.push_back(B);
    lots.push_back(C);

    lots[1].reserveSpace(users[0]->get_uID(), 4, 2, 5);
    lots[1].reserveSpace(users[0]->get_uID(), 6, 4, 7);
    lots[1].reserveSpace(users[0]->get_uID(), 7, 4, 7);
    lots[1].reserveSpace(users[0]->get_uID(), 8, 4, 7);
}

void MainWindow::set_user_information(User* user) {
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

    get_user_parking();

    if (uID.toInt() == 3) {
        ui->create_parking_button->show();
    }


}

void MainWindow::get_user_parking() {
    current_parking.clear();
    for (int i = 0; i < lots.size(); i++) {
        for (int j = 0; j < lots[i].getSpaces().size(); j++) {
            if (lots[i].getSpaces()[j].getUserID() == current_user->get_uID()) {
                this->current_parking.push_back(lots[i].getSpaces()[j]);
            }
        }
    }
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

void MainWindow::update_reservation_table() {
    QStandardItemModel* model = new QStandardItemModel(current_parking.size(), 4, this);
    ui->reservations_table->setModel(model);

    model->setHorizontalHeaderLabels(QStringList() << "Lot" << "Space Number" << "Start Time" << "End Time");

    QStandardItemModel* list = new QStandardItemModel(lots.size(), 2, this);
    ui->lot_box_input->setModel(list);

    for (int i = 0; i < current_parking.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(current_parking[i].getLot())));
        model->setItem(i, 1, new QStandardItem(QString::number(current_parking[i].getSpaceNumber())));

        QTime start = QTime(current_parking[i].getReservationStartTime(), 0, 0);
        QTime end = QTime(current_parking[i].getReservationEndTime(), 0, 0);

        model->setItem(i, 2, new QStandardItem(start.toString()));
        model->setItem(i, 3, new QStandardItem(end.toString()));
    }
}

void MainWindow::update_available_table(int index) {
    vector<ParkingSpace> empty = lots[index].getEmptySpaces();
    QStandardItemModel* model = new QStandardItemModel(empty.size(), 2, this);

    ui->available_list->setModel(model);

    model->setHorizontalHeaderLabels(QStringList() << "Lot" << "Space Number");

    for (int i = 0; i < empty.size(); i++) {
        model->setItem(i, 0, new QStandardItem(QString::fromStdString(empty[i].getLot())));
        model->setItem(i, 1, new QStandardItem(QString::number(empty[i].getSpaceNumber())));
    }

    this->empty_parking = empty;
}

bool MainWindow::search_uID(int n) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i]->get_uID() == n) {
            return true;
        }
    }
    return false;
}


//Slots




void MainWindow::on_login_button_clicked() {
    int u = this->ui->text_box_username->toPlainText().toInt();
    User* user = this->get_user(u);

    cout << "User: " << u << endl;

    if (user) {
        this->set_user_information(user);
        update_user_table();
        ui->stackedWidget->setCurrentWidget(ui->home);
    } else {
        ui->invalid_login_label->setVisible(true);
    }

}

void MainWindow::on_new_reservation_button_clicked() {
    //update parking lot information
    //fill_reservation_table();
    this->update_available_table(0);
    ui->stackedWidget->setCurrentWidget(ui->search);
}

void MainWindow::on_back_home_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->home);
}

void MainWindow::on_logout_button_clicked() {
    current_user = nullptr;
    current_parking.clear();

    ui_checks();
    ui->stackedWidget->setCurrentWidget(ui->login);
}

void MainWindow::on_confirmation_back_button_clicked() {
    //Reload information from previous page
    ui->stackedWidget->setCurrentWidget(ui->search);
}

void MainWindow::on_reserve_button_clicked() {
    //Check if reservation times are valid
    //Check if spot is still available
    string temp = lots[selected_lot].getLotName() + to_string(empty_parking[selected_row].getSpaceNumber());
    QString s = QString::fromStdString(temp);

    QString start = ui->start_time_input->time().toString();
    start += " - " + ui->end_time_input->time().toString();

    ui->confirmation_time_label->setText(start);

    ui->selected_parking_label->setText(s);
    ui->stackedWidget->setCurrentWidget(ui->confirmation);
}

void MainWindow::on_confirmation_confirm_button_clicked() {
    //Add information to vectors or database
    lots[selected_lot].reserveSpace(current_user->get_uID(), empty_parking[selected_row].getSpaceNumber(), ui->start_time_input->time().hour() - 7, ui->end_time_input->time().hour() - 7);

    ui->stackedWidget->setCurrentWidget(ui->home);
    ui->success_label->setVisible(true);
    this->set_user_information(current_user);
    update_user_table();
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

    if (first.empty()) {
        ui->invalid1->setVisible(true);
    } else {
        ui->invalid1->setVisible(false);
    }

    if (last.empty()) {
        ui->invalid2->setVisible(true);
    } else {
        ui->invalid2->setVisible(false);
    }

    if (search_uID(uID)) {
        ui->invalid3->setVisible(true);
    } else {
        ui->invalid3->setVisible(false);
    }

    bool invalid = first.empty() || last.empty() || search_uID(uID);

    if (!invalid) {
        ui->stackedWidget->setCurrentWidget(ui->home);

        User* u = new User(first, last, uID, false, type);
        this->users.push_back(u);

        this->set_user_information(u);
        update_user_table();
    }
}


void MainWindow::on_lot_box_input_currentIndexChanged(int index) {
    this->update_available_table(index);
    this->selected_lot = index;
}

void MainWindow::on_reservations_table_clicked(const QModelIndex &index) {
    auto rowList = ui->reservations_table->selectionModel()->selectedRows();

    if (rowList.count() > 0) {
        this->selected_row = rowList.constFirst().row();
    }

    if (this->selected_row >= 0) {
        cout << "Row: " << this->selected_row << endl;
    }

    cout << "click" << endl;
}

void MainWindow::on_available_list_clicked(const QModelIndex &index){
    auto rowList = ui->available_list->selectionModel()->selectedRows();

    if (rowList.count() > 0) {
        this->selected_row = rowList.constFirst().row();
    }

    if (this->selected_row >= 0) {
        cout << "Row: " << this->selected_row << endl;
    }
}


void MainWindow::on_delete_reservation_button_clicked() {
    lots[selected_lot].clearSpace(current_parking[selected_row].getSpaceNumber());

    this->set_user_information(current_user);
    update_reservation_table();
}


void MainWindow::on_done_button_clicked() {
    string s = ui->create_parking_box->toPlainText().toStdString();
    int num = ui->num_spaces_box->toPlainText().toInt();

    ParkingLot newLot = factory->createParkingLot(s, num);
    lots.push_back(newLot);

    ui->stackedWidget->setCurrentWidget(ui->home);
}


void MainWindow::on_create_parking_button_clicked(){
    ui->stackedWidget->setCurrentWidget(ui->admin);
}

