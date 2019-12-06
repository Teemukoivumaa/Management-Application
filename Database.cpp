#include "Database.h"
#include "Loginpage.h"
#include <string>

#include <QtSql>
#include <QMessageBox>
#include <QTableView>

Database::Database(QWidget *parent)
    : QWidget(parent)
{

}

bool Database::connectDatabase() {
    db = QSqlDatabase::addDatabase("QMYSQL");		    // Here we define what database is used. For me its MySQL running on rasberry pi
    db.setHostName("85.23.24.117");                     // Define the database ip. If running on localhost set it "localhost"
    db.setPort(3306);                                   // Also running on localhost you don't need to set the port
    db.setDatabaseName("managementDatabase");
    db.setUserName("management");
    db.setPassword("managementAdmin");
    dbOpen = db.open();                                 // Open database and check if it did open
    if (dbOpen != true) { qWarning() << __FUNCTION__ <<":"<<__LINE__<<db.lastError().text(); }
    return dbOpen;
}

void Database::closeDatabase() {
    db.close();     // Close database connection
}

bool Database::checkLoginInfo(QString *usernameIn, QString *passwordIn) {

    QSqlQuery query(db);				    // Create a query to database and prepare it
    query.prepare("SELECT employeeUsername, employeePassword from employees");

    if(!query.exec()) {					    // Check if query executes and give a warning
    qWarning() << __FUNCTION__ <<":"<<__LINE__<<db.lastError().text();
    QMessageBox::warning(this,"Error", db.lastError().text());
    }

    while (query.next() && logged != true) {		    // Scan through query
        QString user = query.value(0).toString();	    // Set query walues to string
        QString pass = query.value(1).toString();
        qWarning()<< __FUNCTION__<<":"<<__LINE__<<user; // These are not needed and are used only for debug
        qWarning()<< __FUNCTION__<<":"<<__LINE__<<pass;
        if(*usernameIn ==  user && *passwordIn == pass) {
            logged = true;				    // Given information is right so login is true
        }
    }
    return logged;
}

bool Database::insertInfo(int table, QString *dataFirstInput, QString *dataSecondInput, QString *dataThirdInput) {
    if (table == 1) {
        QSqlQuery query(db);
        QString insertQuery = "INSERT INTO employees (employeeId, employeeName, employeeUsername, employeePassword) VALUES (NULL, '";
        insertQuery.append(*dataFirstInput); insertQuery.append("', '"); insertQuery.append(*dataSecondInput); insertQuery.append("', '"); insertQuery.append(dataThirdInput); insertQuery.append("');");
        query.exec(insertQuery);
    } else if (table == 2) {
        QSqlQuery query(db);
        QString insertQuery = "INSERT INTO computers (computersId, computersName,computersStatus) VALUES (NULL, '";
        insertQuery.append(*dataFirstInput); insertQuery.append("', '"); insertQuery.append(*dataSecondInput); insertQuery.append("');");
        query.exec(insertQuery);
    } else if (table == 3) {
        QSqlQuery query(db);
        QString insertQuery = "INSERT INTO customers (customerId, customerName, customerAddress, customerEmail) VALUES (NULL, '";
        insertQuery.append(*dataFirstInput); insertQuery.append("', '"); insertQuery.append(*dataSecondInput); insertQuery.append("', '"); insertQuery.append(dataThirdInput); insertQuery.append("');");
        query.exec(insertQuery);
    } else if (table == 4) {
        QSqlQuery query(db);
        QString insertQuery = "INSERT INTO items (itemId, itemName, itemQuantity, itemPrice) VALUES (NULL, '";
        insertQuery.append(*dataFirstInput); insertQuery.append("', '"); insertQuery.append(*dataSecondInput); insertQuery.append("', '"); insertQuery.append(dataThirdInput); insertQuery.append("');");
        query.exec(insertQuery);
    }
    return true;
}
