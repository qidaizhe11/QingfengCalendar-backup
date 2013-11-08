#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QDate>

class CalendarHeader;
class QStackedWidget;
class MonthWidget;

class MainWindow : public QWidget
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);

signals:
  void selectedDateChanged(const QDate& date);

public slots:
  void setSelectedDate(const QDate& date);

private:
  void createWidgets();
  void createLayout();
  void createConnections();

  CalendarHeader *calendar_header;
  QStackedWidget *calendar_internal;

  MonthWidget *month_widget;

  QDate selected_date_;
};

#endif // MAINWINDOW_H
