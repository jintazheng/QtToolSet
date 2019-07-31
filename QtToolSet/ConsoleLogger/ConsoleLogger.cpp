#include "ConsoleLogger.h"
#include "windows.h"
#include "QMessageBox"

#define CHARNUM 1024
ConsoleLogger::ConsoleLogger(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->move(0, 0);
	m_row_num = 0;
}

void ConsoleLogger::on_actionclear_console_logger_triggered() {

	QString status("Are you sure to remove all the console information?");
	int ret = QMessageBox::warning(this, tr("Warning"), status,
		QMessageBox::Ok | QMessageBox::Cancel);

	if (ret == QMessageBox::Cancel)
		return;

	ui.textEdit_console_logger->clear();
	m_row_num = 0;
}
void ConsoleLogger::on_actionZoom_in_triggered() {

	ui.textEdit_console_logger->zoomIn();
}
void ConsoleLogger::on_actionZoom_out_triggered() {

	ui.textEdit_console_logger->zoomOut();
}


void ConsoleLogger::writeConsole(const char * msg, ...)
{
	char text[CHARNUM];
	va_list args;
	va_start(args, msg);
	_vsnprintf(text, sizeof(text) / sizeof(TCHAR), msg, args);
	text[CHARNUM-1] = '\0';
	va_end(args);
	//Ui_MainWindow::writeConsole(text);
	ui.textEdit_console_logger->append(QString::number(m_row_num) + " : " + text);

	ui.textEdit_console_logger->update();
	m_row_num++;
}
void ConsoleLogger::writeConsole(QString msg)
{
	//Ui_MainWindow::writeConsole(text);
	ui.textEdit_console_logger->append(QString::number(m_row_num) + " : " + msg);

	ui.textEdit_console_logger->update();
	m_row_num++;
}
void ConsoleLogger::writeConsole(QColor c, QString msg)
{
	ui.textEdit_console_logger->setTextColor(c);
	ui.textEdit_console_logger->append(QString::number(m_row_num) + " : " + msg);
	ui.textEdit_console_logger->update();
	m_row_num++;
	ui.textEdit_console_logger->setTextColor(QColor("black"));
}

void ConsoleLogger::showError(const char * msg, ...) {

	char text[CHARNUM];
	va_list args;
	va_start(args, msg);
	_vsnprintf(text, sizeof(text) / sizeof(TCHAR), msg, args);
	va_end(args);
	text[CHARNUM-1] = '\0';
	QString status = QString(text);

	ui.textEdit_console_logger->setTextColor(QColor("red"));
	QString ErrorMsg = "\n[ERROR]:";
	ErrorMsg += text;
	ErrorMsg += "\n";

	ui.textEdit_console_logger->append(QString::number(m_row_num) + " : " + ErrorMsg);
	ui.textEdit_console_logger->update();
	m_row_num++;
	ui.textEdit_console_logger->setTextColor(QColor("black"));
}

bool ConsoleLogger::showWarning(const char * msg, ...) {

	char text[CHARNUM];
	va_list args;
	va_start(args, msg);
	_vsnprintf(text, sizeof(text) / sizeof(TCHAR), msg, args);
	va_end(args);
	QString status = QString(text);

	int ret = QMessageBox::warning(this, tr("Warning"), status,
		QMessageBox::Ok | QMessageBox::Cancel);

	if (ret == QMessageBox::Cancel)
		return false;
	else
		return true;
}