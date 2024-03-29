
//-------------------------------------------------------------------------

#include "CalendarHeaderView.h"
#include <QtWidgets>

//-------------------------------------------------------------------------

CalendarHeaderView::CalendarHeaderView(QWidget* parent /* = 0 */)
  : QFrame(parent)
{
  selected_date_ = QDate::currentDate();

  createWidgets();
  createLayout();
  createConnections();

  //setColorStyleSheet();

  setSelectedDate(QDate::currentDate());
}

//-------------------------------------------------------------------------
// slots

void CalendarHeaderView::setSelectedDate(const QDate& date)
{
  QString date_string =
      QLocale::system().toString(date, "yyyy  MMM");
  date_label->setText(date_string);

  selected_date_ = date;
  emit selectedDateChanged(date);
}

void CalendarHeaderView::previousMonth()
{
  setSelectedDate(selected_date_.addMonths(-1));
}

void CalendarHeaderView::nextMonth()
{
  setSelectedDate(selected_date_.addMonths(1));
}

//-------------------------------------------------------------------------
// private

void CalendarHeaderView::createWidgets()
{
  previous_month_button = new QPushButton("Pre");
  previous_month_button->setObjectName("previous_month_button");
  next_month_button = new QPushButton("Next");
  next_month_button->setObjectName("next_month_button");
  QString date__string =
      QLocale::system().toString(selected_date_, "yyyy  MMM");
  date_label = new QLabel(date__string);
  date_label->setObjectName("date_label");
}

void CalendarHeaderView::createLayout()
{
  QHBoxLayout* header_layout = new QHBoxLayout;
  header_layout->setMargin(0);
  header_layout->setSpacing(3);
  header_layout->addWidget(previous_month_button);
  header_layout->addSpacing(6);
  header_layout->addWidget(date_label);
  header_layout->addStretch(1);
  header_layout->addWidget(next_month_button);

  //    QVBoxLayout* main_layout = new QVBoxLayout;
  //    main_layout->setMargin(0);
  //    main_layout->setSpacing(0);
  //    main_layout->addLayout(title_layout);
  //    main_layout->addSpacing(3);
  //    main_layout->addLayout(header_layout);
  //    main_layout->addSpacing(6);
  //    setLayout(main_layout);

  setLayout(header_layout);
}

void CalendarHeaderView::createConnections()
{
  connect(previous_month_button, SIGNAL(clicked()),this, SLOT(previousMonth()));
  connect(next_month_button, SIGNAL(clicked()), this, SLOT(nextMonth()));
}

//void CalendarHeader::setColorStyleSheet()
//{
//}

//-------------------------------------------------------------------------
