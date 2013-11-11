
#include "MainWindow.h"
#include <QtWidgets>
#include "CalendarHeader.h"
#include "src/monthview/MonthWidget.h"

//-------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
  setMinimumSize(600, 400);
  resize(960, 600);

  createWidgets();
  createLayout();
  createConnections();
}

//-------------------------------------------------------------------------
// public slots

void MainWindow::setSelectedDate(const QDate &date)
{

}


//-------------------------------------------------------------------------
// private

void MainWindow::createWidgets()
{
  calendar_header = new CalendarHeaderView(this);
  calendar_internal = new QStackedWidget(this);

//  MonthWidget *month_widget = new MonthWidget();
  month_widget = new MonthWidget(this);
//  calendar_internal->addWidget(month_widget);
//  calendar_internal->setCurrentIndex(0);
}

void MainWindow::createLayout()
{
  QGridLayout *main_layout = new QGridLayout;
  main_layout->addWidget(calendar_header, 0, 0);
//  main_layout->addWidget(calendar_internal);
  main_layout->addWidget(month_widget, 1, 0);
  main_layout->setRowStretch(0, 2);
  main_layout->setRowStretch(1, 8);
  setLayout(main_layout);
}

void MainWindow::createConnections()
{
  connect(calendar_header, SIGNAL(selectedDateChanged(QDate)),
          this, SLOT(setSelectedDate(QDate)));
}
