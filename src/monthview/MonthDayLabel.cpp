
//-------------------------------------------------------------------------

#include "MonthDayLabel.h"
#include <QtWidgets>
#include "src/theme/CalendarTheme.h"
#include "src/QfGlobal.h"

//-------------------------------------------------------------------------

MonthDayLabel::MonthDayLabel(const QDate& date, int month_flag,
                 bool is_selected, QWidget *parent)
  : QFrame(parent),
    date_(date),
    month_flag_(month_flag),
    is_selected_(is_selected)
{
//  is_mouse_pressed_ = false;

  createWidgets();
  createLayout();
  createColorStyleSheet();
}

//-------------------------------------------------------------------------

void MonthDayLabel::createWidgets()
{
  day_label = new QLabel;
  day_label->setObjectName("day_label");
  day_label->setText(date_.toString("dd"));
}

void MonthDayLabel::createLayout()
{
  QGridLayout* main_layout = new QGridLayout;
  main_layout->setMargin(0);
  main_layout->setSpacing(0);
  main_layout->addWidget(day_label, 0, 1);
  main_layout->setRowStretch(0, 5);
  main_layout->setRowStretch(1, 5);
  main_layout->setRowStretch(2, 10);
  setLayout(main_layout);
}

void MonthDayLabel::createColorStyleSheet()
{
  QString str = "";

  if (is_selected_)
  {
    str += QString("MonthDayLabel {background-color:%1;}")
           .arg(CalendarTheme::pressed_color().name());
    str += QString("#day_label {color:white;}");
  }
  else
  {
    switch (month_flag_)
    {
    case Qc::kLastMonth:
      str += QString("MonthDayLabel {background-color:%1;}")
             .arg(CalendarTheme::pre_month_color().name());
      str += QString("#day_label {color:%1;}")
             .arg(CalendarTheme::pre_month_font().name());
      break;
    case Qc::kCurrentMonth:
      str += "MonthDayLabel {background-color:transparent;}";
      break;
    case Qc::kNextMonth:
      str += QString("MonthDayLabel {background-color:%1;}")
             .arg(CalendarTheme::next_month_color().name());
      str += QString("#day_label {color:%1;}")
             .arg(CalendarTheme::next_month_font().name());
      break;
    default:
      break;
    }
  } // end else

  this->setStyleSheet(str);
}

//-------------------------------------------------------------------------
