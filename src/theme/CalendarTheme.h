//-------------------------------------------------------------------------
//
// TODO：
// CalendarTheme类后期是要清除的，qss固定一个默认的灰色主题即可。
//
// 此处为了方便颜色的测试与修改，暂且照原样留它。
//
//-------------------------------------------------------------------------

#ifndef CALENDARTHEME_H
#define CALENDARTHEME_H

#include <QColor>

class CalendarTheme
{
public:
  CalendarTheme() {}
  ~CalendarTheme() {}

  static QColor color() { return color_; }
  static QColor pre_month_color() { return pre_month_color_; }
  static QColor next_month_color() { return next_month_color_; }
  static QColor pre_month_font() { return pre_month_font_; }
  static QColor next_month_font() { return next_month_font_; }
  static QColor pressed_color() { return pressed_color_; }
  static QColor border_color() { return border_color_; }
  static QColor line_color() { return line_color_; }

  void setCalendarTheme(const QColor& color);

private:
  static QColor color_;
  static QColor pre_month_color_;
  static QColor next_month_color_;
  static QColor pre_month_font_;
  static QColor next_month_font_;
  static QColor pressed_color_;
  static QColor border_color_;
  static QColor line_color_;
};

#endif // CALENDARTHEME_H
