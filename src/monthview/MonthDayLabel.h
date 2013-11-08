#ifndef MONTHDAYLABEL_H
#define MONTHDAYLABEL_H

#include <QFrame>
#include <QDate>

class QLabel;
class EventWindow;

class MonthDayLabel : public QFrame
{
  Q_OBJECT

public:
  MonthDayLabel(const QDate& date, int month_flag,
          bool is_selected = false, QWidget *parent = 0);
  ~MonthDayLabel() {}

//signals:
//  void pressedDateChanged(const QDate& date);

//protected:
//  void mousePressEvent(QMouseEvent *e);
//  void mouseReleaseEvent(QMouseEvent *e);

private:
  void createWidgets();
  void createLayout();
  void createConnections();
  void createColorStyleSheet();
  void showEventWindow();

  QLabel* day_label;
  QLabel* total_events_label;
//  EventWindow* event_window;

  QDate date_;
  bool is_selected_;
  int month_flag_;
//  bool is_mouse_pressed_;
};

#endif // MONTHDAYLABEL_H
