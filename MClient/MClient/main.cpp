#include <QtGui>
#include "MainApp.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	theApp::instance().InitAppInstance();
	return a.exec();
}
