#include <QtWidgets>
#include <QPushButton>
#include <QCoreApplication>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

#include "Loginpage.h"
#include "Database.h"

Loginpage::Loginpage(QWidget *parent)
: QWidget(parent)
{
    setFixedSize(500, 300);			    // Set fixed size for the window

    send_button = new QPushButton("Login", this);   // Create new push button
    //send_button->setStyleSheet("* {}");
    QGroupBox *usernameGroup = new QGroupBox();	    // Create a new group

    QLabel *usernameLabel = new QLabel(tr("Username:"));
    usernameLineEdit = new QLineEdit;		    // Create username input field
    usernameLineEdit->setPlaceholderText("Username");
    usernameLineEdit->setFocus();

    QLabel *userPasswordLabel = new QLabel(tr("Password:"));
    passwordLineEdit = new QLineEdit;		    // Create password input field
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);	// Set field to password so nobody can see it
    passwordLineEdit->setFocus();

    QGridLayout *usernameLayout = new QGridLayout;  // Create a new layout and assign buttons and fields to it
    usernameLayout->addWidget(usernameLabel, 0, 0);
    usernameLayout->addWidget(usernameLineEdit, 1, 0);
    usernameLayout->addWidget(userPasswordLabel, 2, 0);
    usernameLayout->addWidget(passwordLineEdit, 3, 0);
    usernameLayout->addWidget(send_button, 4, 0);
    usernameGroup->setLayout(usernameLayout);	    // Set layout to username group

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(usernameGroup, 0, 0);
    setLayout(layout);				    // Set layout visible

    setWindowTitle(tr("User login"));		    // Set window title

    connect(usernameLineEdit, SIGNAL(returnPressed()),
            this, SLOT (on_pushButton_Login_clicked())); // Connect input fields to login void so you
    connect(passwordLineEdit, SIGNAL(returnPressed()),	 // can enter information with the enter key
            this, SLOT (on_pushButton_Login_clicked()));
    connect(send_button, SIGNAL (released()),
            this, SLOT (on_pushButton_Login_clicked())); // Connect button to login void
}

void Loginpage::on_pushButton_Login_clicked() {
    checkData();		// Check the given login information

    if (connError != true) {	// Check if there were connection errors, so it wont pop up wrong information window
	if(login == true) {	// If login info is correct the show popup and go to main page
	    QMessageBox::information(this, "Login", "Username and password is correct");
	    hide();		// Hide current window
	    MainPage *mainPage = new MainPage;
	    mainPage->show();
	} else {		// Else show pop up that login information was wrong
	    QMessageBox::warning(this,"Login", "Username and password is not correct");
	}
    }
}

void Loginpage::closeEvent (QCloseEvent *event) {
    Database *database = new Database;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to exit?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
	if (isDbOpen == true) { database->closeDatabase(); }
	QApplication::quit();
    } else { Loginpage *loginpage = new Loginpage; loginpage->show(); }
}

void Loginpage::checkData() {
    Database *database = new Database;			    // Intialise database so we can call voids and other stuff
    connError = false;					    // from Database.cpp. For example connectDatabase()

    usernameInput = new QString (usernameLineEdit->text()); // Get written login info from line edit
    passwordInput = new QString (passwordLineEdit->text()); // on plain text

    if (first == true) {				    // Set database connection if this is the first time
	isDbOpen = database->connectDatabase();
	first = false;					    // Set false so we dont try to set db every time we try to login
    }

    if (isDbOpen == false) {				    // Show error if client can't connect to database
	QMessageBox::warning(this,"Error","Unable to connect to the database. Check if you have internet connection.");
	connError = true;
	database->closeDatabase();			    // Close db connection for new connection try
	first = true;
    }

    if (isDbOpen == true) {				    // If connected to db send login info to be checked
	login = database->checkLoginInfo(usernameInput, passwordInput);
    }							    // Returns true || false
}
