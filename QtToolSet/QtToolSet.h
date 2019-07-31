#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtToolSet.h"

class QtToolSet : public QMainWindow
{
	Q_OBJECT

public:
	QtToolSet(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtToolSetClass ui;
};
