#include "QtToolSet.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtToolSet w;
	w.show();
	return a.exec();
}
