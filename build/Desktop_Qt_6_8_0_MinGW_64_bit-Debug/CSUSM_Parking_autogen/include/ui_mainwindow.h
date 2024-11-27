/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *user;
    QWidget *login;
    QLabel *csusm_logo;
    QTextEdit *text_box_username;
    QTextEdit *text_box_password;
    QPushButton *login_button;
    QWidget *search;
    QLabel *start_time_label;
    QPushButton *back_home;
    QTimeEdit *start_time_input;
    QLabel *end_time_label;
    QTimeEdit *timeEdit;
    QDateEdit *dateEdit;
    QLabel *date_label;
    QTableView *available_list;
    QPushButton *reserveButton;
    QLabel *label;
    QWidget *confirmation;
    QPushButton *confirmation_confirm_button;
    QPushButton *confirmation_back_button;
    QLabel *label_2;
    QWidget *home;
    QPushButton *logout_button;
    QListView *reservations;
    QPushButton *new_reservation_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 9, 801, 561));
        user = new QWidget();
        user->setObjectName("user");
        stackedWidget->addWidget(user);
        login = new QWidget();
        login->setObjectName("login");
        csusm_logo = new QLabel(login);
        csusm_logo->setObjectName("csusm_logo");
        csusm_logo->setGeometry(QRect(30, 30, 171, 81));
        text_box_username = new QTextEdit(login);
        text_box_username->setObjectName("text_box_username");
        text_box_username->setGeometry(QRect(290, 290, 141, 31));
        text_box_password = new QTextEdit(login);
        text_box_password->setObjectName("text_box_password");
        text_box_password->setGeometry(QRect(290, 330, 141, 31));
        login_button = new QPushButton(login);
        login_button->setObjectName("login_button");
        login_button->setGeometry(QRect(320, 370, 83, 29));
        stackedWidget->addWidget(login);
        search = new QWidget();
        search->setObjectName("search");
        start_time_label = new QLabel(search);
        start_time_label->setObjectName("start_time_label");
        start_time_label->setGeometry(QRect(270, 90, 121, 20));
        back_home = new QPushButton(search);
        back_home->setObjectName("back_home");
        back_home->setGeometry(QRect(10, 10, 83, 29));
        start_time_input = new QTimeEdit(search);
        start_time_input->setObjectName("start_time_input");
        start_time_input->setGeometry(QRect(270, 110, 118, 29));
        end_time_label = new QLabel(search);
        end_time_label->setObjectName("end_time_label");
        end_time_label->setGeometry(QRect(420, 90, 71, 20));
        timeEdit = new QTimeEdit(search);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(420, 110, 118, 29));
        dateEdit = new QDateEdit(search);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(270, 30, 111, 31));
        date_label = new QLabel(search);
        date_label->setObjectName("date_label");
        date_label->setGeometry(QRect(270, 10, 63, 20));
        available_list = new QTableView(search);
        available_list->setObjectName("available_list");
        available_list->setGeometry(QRect(170, 200, 481, 241));
        reserveButton = new QPushButton(search);
        reserveButton->setObjectName("reserveButton");
        reserveButton->setGeometry(QRect(360, 500, 83, 29));
        label = new QLabel(search);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 170, 131, 20));
        stackedWidget->addWidget(search);
        confirmation = new QWidget();
        confirmation->setObjectName("confirmation");
        confirmation_confirm_button = new QPushButton(confirmation);
        confirmation_confirm_button->setObjectName("confirmation_confirm_button");
        confirmation_confirm_button->setGeometry(QRect(400, 350, 83, 29));
        confirmation_back_button = new QPushButton(confirmation);
        confirmation_back_button->setObjectName("confirmation_back_button");
        confirmation_back_button->setGeometry(QRect(270, 350, 83, 29));
        label_2 = new QLabel(confirmation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(250, 230, 311, 41));
        stackedWidget->addWidget(confirmation);
        home = new QWidget();
        home->setObjectName("home");
        logout_button = new QPushButton(home);
        logout_button->setObjectName("logout_button");
        logout_button->setGeometry(QRect(10, 10, 83, 29));
        reservations = new QListView(home);
        reservations->setObjectName("reservations");
        reservations->setGeometry(QRect(380, 110, 256, 192));
        new_reservation_button = new QPushButton(home);
        new_reservation_button->setObjectName("new_reservation_button");
        new_reservation_button->setGeometry(QRect(622, 500, 161, 29));
        stackedWidget->addWidget(home);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        csusm_logo->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        text_box_username->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        text_box_password->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        login_button->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        start_time_label->setText(QCoreApplication::translate("MainWindow", "Start Time", nullptr));
        back_home->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        end_time_label->setText(QCoreApplication::translate("MainWindow", "End Time", nullptr));
        date_label->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        reserveButton->setText(QCoreApplication::translate("MainWindow", "Reserve", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Available Spots", nullptr));
        confirmation_confirm_button->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        confirmation_back_button->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Confirm parking spot for x time at x?", nullptr));
        logout_button->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        new_reservation_button->setText(QCoreApplication::translate("MainWindow", "New Reservation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
