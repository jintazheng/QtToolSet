#include "QtToolSet.h"
#include "ConsoleLogger/ConsoleLogger.h"

ConsoleLogger* g_console_logger;
QtToolSet::QtToolSet(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	g_console_logger = new ConsoleLogger();
	g_console_logger->show();
}
