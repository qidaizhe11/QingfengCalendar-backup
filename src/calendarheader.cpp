
//-------------------------------------------------------------------------

#include "calendarheader.h"
#include <QtWidgets>

//-------------------------------------------------------------------------

CalendarHeader::CalendarHeader(QWidget* parent /* = 0 */)
  : QFrame(parent)
{
  selected_date_ = QDate::currentDate();

  createWidgets();
  createLayout();
  createConnections();

  //setColorStyleSheet();
}

//-------------------------------------------------------------------------
// slots

void CalendarHeader::setSelectedDate(const QDate& date)
{
  QString date_string =
      QLocale::system().toString(date, "yyyy  MMM");
  date_label->setText(date_string);

  selected_date_ = date;
  emit selectedDateChanged(date);
}

void CalendarHeader::previousMonth()
{
  setSelectedDate(selected_date_.addMonths(-1));
}

void CalendarHeader::nextMonth()
{
  setSelectedDate(selected_date_.addMonths(1));
}

//-------------------------------------------------------------------------
// private

void CalendarHeader::createWidgets()
{
  previous_month_button = new QPushButton;
  previous_month_button->setObjectName("previous_month_button");
  next_month_button = new QPushButton;
  next_month_button->setObjectName("next_month_button");
  QString date__string =
      QLocale::system().toString(selected_date_, "yyyy  MMM");
  date_label = new QLabel(date__string);
  date_label->setObjectName("date_label");
}

void CalendarHeader::createLayout()
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

void CalendarHeader::createConnections()
{
  connect(previous_month_button, SIGNAL(clicked()),this, SLOT(previousMonth()));
  connect(next_month_button, SIGNAL(clicked()), this, SLOT(nextMonth()));
}

//void CalendarHeader::setColorStyleSheet()
//{
//}

//-------------------------------------------------------------------------
