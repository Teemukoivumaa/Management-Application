#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QtSql>
#include <QTableWidget>

//#include <Loginpage.h>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPlainTextEdit;
class QMenu;
class QVBoxLayout;
class QTableView;
QT_END_NAMESPACE

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage();

signals:

public slots:
    void closeEvent(QCloseEvent *event);
    void sendInfo();
    void employees();
    void computers();
    void customers();
    void items();

public:
    int sendTable;
    int currentWindow;

    bool textBox = false;
    bool deleteTextBox = false;
    bool deleteTableBox = false;
    bool deleteFillers = false;
    bool deleteButtons = false;

    bool shortcutTextBox = false;
    bool deleteShortcutTextBox = false;

    QString *databaseFirstInput;
    QString *databaseSecondInput;
    QString *databaseThirdInput;
    QWidget *widget;

private:

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

    void createMenus();
    void createActions();
    void index();

    void info();
    void shortcuts();
    void closeProgram();
    void logout();
    void deleteWidgets();
    void showTextBox(bool);
    void showShortcutBox(bool);
    void showTable(bool, int);

    QPushButton *sendDbInfo;
    QPushButton *employeesButton;
    QPushButton *computersButton;
    QPushButton *customersButton;
    QPushButton *itemsButton;
    QVBoxLayout *layout;
    QWidget *topFiller;
    QWidget *bottomFiller;
    QTableView *table;

    QMenu *infoMenu;
    QAction *indexAct;
    QAction *employeesAct;
    QAction *computersAct;
    QAction *customersAct;
    QAction *itemsAct;
    QAction *infoAct;
    QAction *shortcutsAct;
    QAction *closeAct;
    QAction *logoutAct;

    QPlainTextEdit *infoTextEdit;
    QPlainTextEdit *shortcutTextEdit;
    QLineEdit *databaseFirstLine;
    QLineEdit *databaseSecondLine;
    QLineEdit *databaseThirdLine;
    QLineEdit *databaseFourthLine;
    QLabel *headerLabel;
    QLabel *dataInputLabel;

};

#endif // MAINPAGE_H
