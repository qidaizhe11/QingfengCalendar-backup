
//-------------------------------------------------------------------------

#include "MonthWidget.h"
#include <QtWidgets>
#include "src/QfGlobal.h"
#include "src/monthview/MonthDayLabel.h"

//-------------------------------------------------------------------------

MonthWidget::MonthWidget(QWidget *parent) :
  QWidget(parent)
{
  month_start_at_ = month_end_at_ = 0;
  month_rows_ = 0;
  header_height_ = 0;
  cell_height_ = cell_width_ = 0;
  days_in_last_month = days_in_month = 0;

  selected_date_ = QDate();

  //selected_date_ = QDate::currentDate();

  setSelectedDate(QDate::currentDate());

//  createWidgets();
//  createLayout();
//  createConnections();
}

//-------------------------------------------------------------------------
// public slots

void MonthWidget::setSelectedDate(const QDate& date)
{
  if (date.isValid()) {
    if (date != selected_date_) {
      selected_date_ = date;

      header_cells_.clear();
      day_cells_.clear();
      qDeleteAll(this->children());
      computeMonthBoundaries();
      computeMonthRows();
      createWidgets();
      createLayout();
//      updateEvents();
    }
  }
}

//-------------------------------------------------------------------------
// private

void MonthWidget::createWidgets()
{
  // header_cell

  for (int i = 1; i <= 7; ++i) {
    QString day_name = QLocale::system().dayName(i);
    header_cells_.push_back(new QLabel(day_name));
  }

  //day_cell

  QDate date = QDate(selected_date_.year(), selected_date_.month(), 1);
  date = date.addDays(-month_start_at_ + 1);

  for (int row = 0; row < month_rows_; ++row)
  {
    for (int col = 0; col < 7; ++col)
    {
      int month_flag = 0;
      if (date.month() == selected_date_.month())
        month_flag = Qc::kCurrentMonth;
      else if (date.year() < selected_date_.year() ||
               date.month() == selected_date_.month() - 1)
        month_flag = Qc::kLastMonth;
      else if (date.year() > selected_date_.year() ||
               date.month() == selected_date_.month() + 1)
        month_flag = Qc::kNextMonth;

      if (date == QDate::currentDate())
        day_cells_.push_back(new MonthDayLabel(date, month_flag, true));
      else
        day_cells_.push_back(new MonthDayLabel(date, month_flag));

      date = date.addDays(1);
    } // end for
  } // end for
}

void MonthWidget::createLayout()
{
  // header_layout

  header_layout = new QHBoxLayout;
//  header_layout->setMargin(0);
//  header_layout->setSpacing(0);
  for (QList<QLabel*>::iterator it = header_cells_.begin();
      it != header_cells_.end(); ++it) {
    header_layout->addWidget(*it);
  }

  // day_layout

  day_layout = new QGridLayout;
//  day_layout->setMargin(0);
//  day_layout->setSpacing(0);

  int i = 0;
  for (QList<MonthDayLabel*>::iterator it = day_cells_.begin();
      it != day_cells_.end(); ++it, ++i) {
    day_layout->addWidget(*it, i/7 * 3, i % 7, 3, 1);
    day_layout->setRowStretch(i/7 * 3, 2);
    day_layout->setRowStretch(i/7 * 3 + 1, 1);
    day_layout->setRowStretch(i/7 * 3 + 2, 1);
    day_layout->setColumnStretch(i % 7, 1);
  }

  // main_layout

  main_layout = new QGridLayout;
//  main_layout->setMargin(0);
//  main_layout->setSpacing(0);
  main_layout->addLayout(header_layout, 0, 1);
  main_layout->addLayout(day_layout, 1, 1);
  main_layout->setRowStretch(0, 1);
  main_layout->setRowStretch(1, 25);
  this->setLayout(main_layout);
}

void MonthWidget::createConnections()
{

}

//void MonthWidget::updateEvents()
//{
//	QDate date = QDate(selected_date_.year(), selected_date_.month(), 1);
//	date = date.addDays(-month_start_at_ + 1);

//	for (int row = 0; row < month_rows_; ++row)
//	{
//		for (int col = 0; col < 7; ++col)
//		{
//			EventGateway event;
//			if (EventFinder::find(event, date)) {
//				EventLabel* event_label = new EventLabel(event, this);
//				day_layout->addWidget(event_label, row*3 + 1, col);
//			}
//			day_layout->setColumnStretch(col, 1);
//			date = date.addDays(1);
//		}
//	}

//	setLayout(main_layout);
//}

void MonthWidget::computeMonthBoundaries()
{
  int day_of_week =
    QDate(selected_date_.year(), selected_date_.month(), 1).dayOfWeek();
  month_start_at_ = day_of_week;
  month_end_at_ = month_start_at_ + selected_date_.daysInMonth() - 1;
}

void MonthWidget::computeMonthRows()
{
  days_in_last_month = selected_date_.addMonths(-1).daysInMonth();
  days_in_month = selected_date_.daysInMonth();

  int day_of_week =
    QDate(selected_date_.year(), selected_date_.month(), 1).dayOfWeek();

  if (days_in_month + day_of_week - 1 <= 35)
    month_rows_ = 5;
  else
    month_rows_ = 6;
}

//-------------------------------------------------------------------------
