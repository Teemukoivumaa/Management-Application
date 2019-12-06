#include <QtWidgets>
#include <QPushButton>
#include <QMessageBox>

#include "Mainpage.h"
#include "Database.h"
#include "loginpage.h"

MainPage::MainPage() {
    widget = new QWidget;
    setCentralWidget(widget);	// Create a new widget and but it in the center

    headerLabel = new QLabel(tr("Index"));   // Create label and assign it's position to the center
    headerLabel->setAlignment(Qt::AlignCenter);

    dataInputLabel = new QLabel(tr("Database input"));
    dataInputLabel->setAlignment(Qt::AlignCenter);

    databaseFirstLine = new QLineEdit;
    databaseSecondLine = new QLineEdit;
    databaseThirdLine = new QLineEdit;
    databaseFourthLine = new QLineEdit;

    layout = new QVBoxLayout;	// Create new BoxLayout and add widgets to it

    index();
    createActions();		// Create the actions
    createMenus();		// Create the menus

    setWindowTitle(tr("Management system V0.6")); // Set window title, window minimum size and resize size.
    setMinimumSize(600, 400);
    resize(1000, 720);
}

void MainPage::index() {
    deleteWidgets();
    currentWindow = 1;

    employeesButton = new QPushButton (tr("Employees"));
    computersButton = new QPushButton (tr("Computers"));
    customersButton = new QPushButton (tr("Customers"));
    itemsButton = new QPushButton (tr("Items"));

    /*
    m_pTableWidget = new QTableWidget(this);
    m_pTableWidget->setRowCount(10);
    m_pTableWidget->setColumnCount(3);
    m_TableHeader<<"#"<<"Name"<<"Text";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);
    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableWidget->setShowGrid(false);
    m_pTableWidget->setStyleSheet("QTableView {selection-background-color: black;}");
    m_pTableWidget->setGeometry(QApplication::desktop()->screenGeometry());

    //insert data
    m_pTableWidget->setItem(0, 1, new QTableWidgetItem("Hello"));
    */

    headerLabel->setText(tr("Index"));
    layout->addWidget(headerLabel);
    layout->addWidget(employeesButton); layout->addWidget(computersButton);
    layout->addWidget(customersButton); layout->addWidget(itemsButton);
    widget->setLayout(layout);

    deleteButtons = true;
    connect(employeesButton, SIGNAL (clicked()),this, SLOT (employees()));
    connect(computersButton, SIGNAL (clicked()),this, SLOT (computers()));
    connect(customersButton, SIGNAL (clicked()),this, SLOT (customers()));
    connect(itemsButton, SIGNAL (clicked()),this, SLOT (items()));
}
void MainPage::employees() {
    int table = 0;
    currentWindow = 2;
    deleteWidgets();

    table = 1;
    bool show = true;

    headerLabel->setText(tr("List of employees"));
    dataInputLabel->setText(tr("Add employee:"));

    databaseFirstLine->setPlaceholderText("Employee name");
    databaseSecondLine->setPlaceholderText("Employee username");
    databaseThirdLine->setPlaceholderText("Employee password");
    showTable(show, table);

    deleteTableBox = true;
}

void MainPage::computers() {
    int table = 0;
    currentWindow = 3;
    deleteWidgets();

    table = 2;
    bool show = true;

    headerLabel->setText(tr("List of computers"));
    dataInputLabel->setText(tr("Add computer:"));

    databaseFirstLine->setPlaceholderText("Computer name");
    databaseSecondLine->setPlaceholderText("Computer status");
    showTable(show, table);

    deleteTableBox = true;
}

void MainPage::customers() {
    int table = 0;
    currentWindow = 4;
    deleteWidgets();

    table = 3;
    bool show = true;

    headerLabel->setText(tr("List of customers"));
    dataInputLabel->setText(tr("Add customer:"));

    databaseFirstLine->setPlaceholderText("Customer name");
    databaseSecondLine->setPlaceholderText("Customer address");
    databaseThirdLine->setPlaceholderText("Customer email");
    showTable(show, table);

    deleteTableBox = true;
}

void MainPage::items() {
    int table = 0;
    currentWindow = 5;
    deleteWidgets();

    table = 4;
    bool show = true;

    headerLabel->setText(tr("List of items"));
    dataInputLabel->setText(tr("Add item:"));

    databaseFirstLine->setPlaceholderText("Item name");
    databaseSecondLine->setPlaceholderText("Item quantity");
    databaseThirdLine->setPlaceholderText("Item price");
    showTable(show, table);

    deleteTableBox = true;
}

void MainPage::info() {
    currentWindow = 6;
    deleteWidgets();

    bool show = true;

    showTextBox(show);
    deleteTextBox = true;
    deleteFillers = true;
}

void MainPage::shortcuts() {
    currentWindow = 7;
    deleteWidgets();

    bool show = true;

    showShortcutBox(show);
    deleteShortcutTextBox = true;
    deleteFillers = true;
}

void MainPage::showTextBox(bool textBox) {
    if (textBox == false) {
	layout->removeWidget(infoTextEdit);
	delete infoTextEdit;
    } else if (textBox == true) {
	headerLabel->setText(tr("Info:"));
	topFiller = new QWidget;	// Top filler widget
	topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	bottomFiller = new QWidget;	// Bottom filler widget
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	infoTextEdit = new QPlainTextEdit;
	infoTextEdit->QPlainTextEdit::setReadOnly(true);
	infoTextEdit->setPlainText("Program info: \n	-Abcd \nThis is a test \n   1. Line 1 \n    2. Line 2 \n    3. Line 3");

	layout->addWidget(topFiller);
	layout->addWidget(headerLabel);
	layout->addWidget(infoTextEdit);
	layout->addWidget(bottomFiller);
	widget->setLayout(layout);
    }
}

void MainPage::showShortcutBox(bool shortcutBox) {
    if (shortcutBox == false) {
	layout->removeWidget(shortcutTextEdit);
	delete shortcutTextEdit;
    } else if (shortcutBox == true) {
	headerLabel->setText(tr("Shortcuts:"));

	topFiller = new QWidget;	// Top filler widget
	topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	bottomFiller = new QWidget;	// Bottom filler widget
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	shortcutTextEdit = new QPlainTextEdit;
	shortcutTextEdit->QPlainTextEdit::setReadOnly(true);
	shortcutTextEdit->setPlainText("Shortcuts: \n  - Index: Ctrl+A \n  - Employees: Ctrl+Z \n  - Computers: Ctrl+X \n  "
	                               "- Customers: Ctrl+C \n  - Info: F1 \n  - Shortcuts: Shift+F1 \n  - Exit: Ctrl+W");

	layout->addWidget(topFiller);
	layout->addWidget(headerLabel);
	layout->addWidget(shortcutTextEdit);
	layout->addWidget(bottomFiller);
	widget->setLayout(layout);
    }
}

void MainPage::showTable(bool tableBox, int whatTable) {
    Database *dataBase = new Database;
    if (whatTable == 1) {
	dataBase->model = new QSqlTableModel(this);
	dataBase->model->setTable("employees");
	dataBase->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dataBase->model->select();
	dataBase->model->setHeaderData(0, Qt::Horizontal, tr(""));
	dataBase->model->setHeaderData(1, Qt::Horizontal, tr("Employee name"));
	dataBase->model->setHeaderData(2, Qt::Horizontal, tr("Username"));
	dataBase->model->setHeaderData(3, Qt::Horizontal, tr("Password"));
    } else if (whatTable == 2) {
	dataBase->model = new QSqlTableModel(this);
	dataBase->model->setTable("computers");
	dataBase->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dataBase->model->select();
	dataBase->model->setHeaderData(0, Qt::Horizontal, tr(""));
	dataBase->model->setHeaderData(1, Qt::Horizontal, tr("Computer name"));
	dataBase->model->setHeaderData(2, Qt::Horizontal, tr("Status"));
	dataBase->model->setHeaderData(3, Qt::Horizontal, tr(""));
    } else if (whatTable == 3) {
	dataBase->model = new QSqlTableModel(this);
	dataBase->model->setTable("customers");
	dataBase->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dataBase->model->select();
	dataBase->model->setHeaderData(0, Qt::Horizontal, tr(""));
	dataBase->model->setHeaderData(1, Qt::Horizontal, tr("Customer name"));
	dataBase->model->setHeaderData(2, Qt::Horizontal, tr("Customer address"));
	dataBase->model->setHeaderData(3, Qt::Horizontal, tr("Customer email"));
    } else if (whatTable == 4) {
	dataBase->model = new QSqlTableModel(this);
	dataBase->model->setTable("items");
	dataBase->model->setEditStrategy(QSqlTableModel::OnManualSubmit);
	dataBase->model->select();
	dataBase->model->setHeaderData(0, Qt::Horizontal, tr(""));
	dataBase->model->setHeaderData(1, Qt::Horizontal, tr("Item name"));
	dataBase->model->setHeaderData(2, Qt::Horizontal, tr("Item quantity"));
	dataBase->model->setHeaderData(3, Qt::Horizontal, tr("Item price"));
    }

    if (tableBox == false) {
	layout->removeWidget(table);
	dataInputLabel->setVisible(0);
	sendDbInfo->setVisible(0);
	databaseFirstLine->clear(); databaseSecondLine->clear(); databaseThirdLine->clear();
	delete table;

	databaseFirstLine->setVisible(0); databaseSecondLine->setVisible(0); databaseThirdLine->setVisible(0);
    } else if (tableBox == true) {
	table = new QTableView;
	table->setModel(dataBase->model);   // We set the model on the TableView
	table->setColumnHidden(0, true);    // Hide the column id Records

	// Allow the selection of lines
	table->setSelectionBehavior(QAbstractItemView::SelectRows);
	table->setSelectionMode(QAbstractItemView::SingleSelection);	// Set selection mode, only one row in table
	table->resizeColumnsToContents();   // Set the size of the columns by content
	table->setEditTriggers(QAbstractItemView::NoEditTriggers);
	table->horizontalHeader()->setStretchLastSection(true);

	sendDbInfo = new QPushButton("Insert database info", this);
	layout->addWidget(headerLabel);
	layout->addWidget(table);
	layout->addWidget(dataInputLabel);
	layout->addWidget(databaseFirstLine); layout->addWidget(databaseSecondLine);
	layout->addWidget(databaseThirdLine);
	layout->addWidget(sendDbInfo);

	dataInputLabel->setVisible(1);
	sendDbInfo->setVisible(1);
	if (whatTable == 1) {
	    databaseFirstLine->setVisible(1); databaseSecondLine->setVisible(1); databaseThirdLine->setVisible(1);
	} else if (whatTable == 2) {
	    databaseFirstLine->setVisible(1); databaseSecondLine->setVisible(1); databaseThirdLine->setVisible(0);
	} else if (whatTable == 3) {
	    databaseFirstLine->setVisible(1); databaseSecondLine->setVisible(1); databaseThirdLine->setVisible(1);
	} else if (whatTable == 4) {
	    databaseFirstLine->setVisible(1); databaseSecondLine->setVisible(1); databaseThirdLine->setVisible(1);
	}

	sendTable = whatTable;
	connect(databaseThirdLine, SIGNAL(returnPressed()), this, SLOT (sendInfo()));
	connect(sendDbInfo, SIGNAL (clicked()), this, SLOT (sendInfo()));
    }
}

void MainPage::deleteWidgets() {
    int table = 0;

    if (deleteButtons == true) {
	layout->removeWidget(employeesButton); layout->removeWidget(computersButton);
	layout->removeWidget(customersButton); layout->removeWidget(itemsButton);
	delete employeesButton; delete computersButton; delete customersButton; delete itemsButton;
	deleteButtons = false;
    }

    if (deleteTextBox == true) {
	bool show = false;
	showTextBox(show);
	deleteTextBox = false;
    }
    if (deleteShortcutTextBox == true) {
	bool show = false;
	showShortcutBox(show);
	deleteShortcutTextBox = false;
    }
    if (deleteTableBox == true) {
	bool show = false;
	showTable(show, table);
	deleteTableBox = false;
    }
    if (deleteFillers == true) {
	layout->removeWidget(topFiller);
	layout->removeWidget(bottomFiller);
	delete topFiller; delete bottomFiller;
	deleteFillers = false;
    }
}

void MainPage::closeProgram() {
    Database *database = new Database;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to exit?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
	database->closeDatabase();
	QApplication::quit();
    }
}

void MainPage::closeEvent (QCloseEvent *event) {
    closeProgram();
    event->ignore();
}

void MainPage::logout() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to logout?", QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
	hide();
	Loginpage *loginpage = new Loginpage;
	loginpage->show();
    }
}

void MainPage::sendInfo() {

    databaseFirstInput = new QString (databaseFirstLine->text());
    databaseSecondInput = new QString (databaseSecondLine->text());
    databaseThirdInput = new QString (databaseThirdLine->text());

    bool dataOk = false;
    if (databaseFirstInput->isEmpty() == false) {
	dataOk = true;
    } else { QMessageBox::warning(this,"SQL qyery", "Error in input line 1. Can't input empty values"); dataOk = false;}
    if (databaseSecondInput->isEmpty() == false) {
	dataOk = true;
    } else { QMessageBox::warning(this,"SQL qyery", "Error in input line 2. Can't input empty values"); dataOk = false;}
    if (databaseThirdInput->isEmpty() == false) {
	dataOk = true;
    } else { QMessageBox::warning(this,"SQL qyery", "Error in input line 3. Can't input empty values"); dataOk = false;}

    bool send = false;
    if (dataOk == true) {
	Database *dataBase = new Database;
	send = dataBase->insertInfo(sendTable, databaseFirstInput,
	                            databaseSecondInput, databaseThirdInput);
    }

    if (send == true) {
	databaseFirstLine->clear();
	databaseSecondLine->clear();
	databaseThirdLine->clear();
	switch (sendTable) {
	case 1:
	    employees();
	    break;
	case 2:
	    computers();
	    break;
	case 3:
	    customers();
	    break;
	case 4:
	    items();
	    break;
	default:
	    index();
	    break;
	}
    }
}

void MainPage::createActions() {
    indexAct = new QAction(tr("&Index"), this);
    indexAct->setShortcuts(QKeySequence::SelectAll); // ctrl a
    indexAct->setStatusTip(tr("Index page"));
    connect(indexAct, &QAction::triggered, this, &MainPage::index);

    employeesAct = new QAction(tr("&Employees"), this);
    employeesAct->setShortcuts(QKeySequence::Undo); //ctrl z
    employeesAct->setStatusTip(tr("See a list of all employees"));
    connect(employeesAct, &QAction::triggered, this, &MainPage::employees);

    computersAct = new QAction(tr("&Computers"), this);
    computersAct->setShortcuts(QKeySequence::Cut); // ctrl x
    computersAct->setStatusTip(tr("See a list of all computers"));
    connect(computersAct, &QAction::triggered, this, &MainPage::computers);

    customersAct = new QAction(tr("&Customers"), this);
    customersAct->setShortcuts(QKeySequence::Copy); //ctrl c
    customersAct->setStatusTip("See a list of all customers");
    connect(customersAct, &QAction::triggered, this, &MainPage::customers);

    itemsAct = new QAction(tr("&Items"), this);
    itemsAct->setShortcut(QKeySequence::Find); //ctrl f
    itemsAct->setStatusTip("See a list of all the items");
    connect(itemsAct, &QAction::triggered, this, &MainPage::items);

    infoAct = new QAction(tr("&Info"), this);
    infoAct->setShortcuts(QKeySequence::HelpContents); // f1
    infoAct->setStatusTip("Info page");
    connect(infoAct, &QAction::triggered, this, &MainPage::info);

    shortcutsAct = new QAction(tr("&Shortcuts"), this);
    shortcutsAct->setShortcuts(QKeySequence::WhatsThis); // shift f1
    shortcutsAct->setStatusTip("Shortcut info");
    connect(shortcutsAct, &QAction::triggered, this, &MainPage::shortcuts);

    closeAct = new QAction(tr("&Close"), this);
    closeAct->setShortcuts(QKeySequence::Close); // ctrl w
    closeAct->setStatusTip("Close the program");
    connect(closeAct, &QAction::triggered, this, &MainPage::closeProgram);

    logoutAct = new QAction(tr("&Logout"), this);
    logoutAct->setShortcut(QKeySequence::Paste); // ctrl v
    logoutAct->setStatusTip("Logout of the program");
    connect(logoutAct, &QAction::triggered, this, &MainPage::logout);
}

void MainPage::createMenus() {
    menuBar()->addAction(indexAct);
    menuBar()->addAction(employeesAct);
    menuBar()->addAction(computersAct);
    menuBar()->addAction(customersAct);
    menuBar()->addAction(itemsAct);

    infoMenu = menuBar()->addMenu(tr("&Info"));
    infoMenu->addAction(infoAct);
    infoMenu->addAction(shortcutsAct);

    menuBar()->addAction(logoutAct);
    menuBar()->addAction(closeAct);
}
