#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>

class CalendarHeader;
class QStackedWidget;
//class MonthWidget;

class MainWindow : public QMainWindow
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

  QDate selected_date_;
};

#endif // MAINWINDOW_H
