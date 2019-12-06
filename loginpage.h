#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

#include "Mainpage.h"
#include "Database.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QSqlRelationalTableModel;
QT_END_NAMESPACE

class Loginpage : public QWidget
{
    Q_OBJECT

public:
    explicit Loginpage(QWidget *parent = nullptr);

private slots:
   void on_pushButton_Login_clicked();
   void closeEvent(QCloseEvent *event);

public:
    bool login = false;

    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QString *usernameInput;
    QString *passwordInput;

    Database *database;

private:
    bool first = true;
    bool isDbOpen = false;
    bool connError;
    void checkData();
    MainPage *mainPage;
    QPushButton *send_button;
};

#endif // LOGINPAGE_H
