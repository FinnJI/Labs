#include <QApplication>
#include "field.h"

using namespace std;

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Field field;
    field.showMaximized();
    return a.exec();
}
