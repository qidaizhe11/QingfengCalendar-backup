
#include "mainwindow.h"
#include <QtWidgets>
#include "calendarheader.h"
#include "src/monthview/monthwidget.h"

//-------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  setMinimumSize(600, 400);
  resize(960, 600);

  createWidgets();
  createLayout();
  createConnections();
}

//-------------------------------------------------------------------------



//-------------------------------------------------------------------------
// private

void MainWindow::createWidgets()
{
  calendar_header = new CalendarHeader(this);
  calendar_internal = new QStackedWidget(this);

  MonthWidget month_widget = new MonthWidget();
  calendar_internal->addWidget(month_widget);
  calendar_internal->setCurrentIndex(0);
}

void MainWindow::createLayout()
{
  QVBoxLayout *main_layout = new QVBoxLayout;
  main_layout->addWidget(calendar_header);
  main_layout->addWidget(calendar_internal);
  setLayout(main_layout);
}
