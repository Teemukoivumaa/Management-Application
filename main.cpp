#include <QApplication>

#include "Loginpage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Loginpage loginpage;
    loginpage.show();
    return app.exec();
}
