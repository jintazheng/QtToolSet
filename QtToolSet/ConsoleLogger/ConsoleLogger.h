#ifndef CONSOLELOGGER_H_
#define CONSOLELOGGER_H_

#include <QtWidgets/QMainWindow>
#include "ui_ConsoleLogger.h"

class ConsoleLogger : public QMainWindow
{
	Q_OBJECT

public:
	ConsoleLogger(QWidget *parent = Q_NULLPTR);

	void writeConsole(const char * msg, ...);
	void writeConsole(QString msg);
	void writeConsole(QColor c, QString msg);
	void showError(const char * msg, ...);
	bool showWarning(const char * msg, ...);

public slots:
	void on_actionclear_console_logger_triggered();
	void on_actionZoom_in_triggered();
	void on_actionZoom_out_triggered();


private:
	Ui::ConsoleLoggerClass  ui;
	uint m_row_num;
};

#endif