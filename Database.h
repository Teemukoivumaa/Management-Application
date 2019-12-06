#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>
#include <QtSql>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QSqlRelationalTableModel;
QT_END_NAMESPACE

class Database : public QWidget
{
    Q_OBJECT
public:
    explicit Database(QWidget *parent = nullptr);

signals:

public slots:

public:
    bool connectDatabase();
    bool checkLoginInfo(QString *usernameIn, QString *passwordIn);
    void closeDatabase();
    void getComputers(int);
    bool insertInfo(int table, QString *dataFirstInput, QString *dataSecondInput, QString *dataThirdInput);
    bool dbOpen = false;
    bool logged = false;

    int *table;
    QString *user;
    QString *pass;
    QString *usernameIn;
    QString *passwordIn;
    QString *dataFirstInput;
    QString *dataSecondInput;
    QString *dataThirdInput;
    QString *computerName;
    QString *computerStatus;

    QSqlDatabase db;
    QSqlTableModel *model;

private:

};

#endif // DATABASE_H
