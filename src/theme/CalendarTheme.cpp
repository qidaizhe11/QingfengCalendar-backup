
//-------------------------------------------------------------------------

#include "CalendarTheme.h"

QColor CalendarTheme::color_ = QColor(255, 255, 255);

QColor CalendarTheme::pre_month_color_ = QColor(255, 255, 255);
QColor CalendarTheme::next_month_color_ = QColor(255, 255, 255);
QColor CalendarTheme::pre_month_font_ = QColor(255, 255, 255);
QColor CalendarTheme::next_month_font_ = QColor(255, 255, 255);
QColor CalendarTheme::pressed_color_ = QColor(255, 255, 255);
QColor CalendarTheme::border_color_ = QColor(255, 255, 255);
QColor CalendarTheme::line_color_ = QColor(255, 255, 255);

//-------------------------------------------------------------------------

void CalendarTheme::setCalendarTheme(const QColor& color)
{
  color_ = color;
  pre_month_color_ = color.darker(108);
  next_month_color_ = color.darker(104);
  pre_month_font_ = color.darker(200);
  next_month_font_ = color.darker(180);
  pressed_color_ = color.darker(150);
  line_color_ = color.lighter(120);
  border_color_ = color.darker(130);
}

//-------------------------------------------------------------------------
