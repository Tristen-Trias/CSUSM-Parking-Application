#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "headers/parking/ParkingLot.h"
#include "headers/parking/ParkingSpace.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    onStart();
}

void MainWindow::onStart() {
    ui->stackedWidget->setCurrentWidget(ui->login);
    setImage();
}

void MainWindow::setImage() {
    QPixmap pm("C:/Users/Tristen/Documents/CSUSM_Parking_Application/assets/csusm_logo.jpg");

    ui->csusm_logo->setPixmap(pm);
    ui->csusm_logo->setScaledContents(true);
}

void MainWindow::tempList() {
    ParkingLot* a, b, c;
    this->lots.push_back(a);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_login_button_clicked() {
    //Check to see if valid user
    //then login using line below
    //Get all parking lot information
    ui->stackedWidget->setCurrentWidget(ui->home);
}


void MainWindow::on_new_reservation_button_clicked() {
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

void MainWindow::on_reserveButton_clicked() {
    //Check if reservation times are valid
    //Check if spot is still available
    ui->stackedWidget->setCurrentWidget(ui->confirmation);
}

void MainWindow::on_confirmation_confirm_button_clicked() {
    //Send information to database
    ui->stackedWidget->setCurrentWidget(ui->home);
    //Tell user if reservation was successful or not
}


