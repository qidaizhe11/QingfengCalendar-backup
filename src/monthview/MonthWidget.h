#ifndef MONTHWIDGET_H
#define MONTHWIDGET_H

#include <QWidget>
#include <QDate>

class QLabel;
class MonthDayLabel;
class QHBoxLayout;
class QGridLayout;

class MonthWidget : public QWidget
{
  Q_OBJECT
public:
  explicit MonthWidget(QWidget *parent = 0);

signals:
  void selectedDateChanged(const QDate& date);

public slots:
  void setSelectedDate(const QDate& date);

private:
  void createWidgets();
  void createLayout();
  void createConnections();
//  void updateEvents();

  void computeMonthBoundaries();
  void computeMonthRows();

  QHBoxLayout* header_layout;
  QGridLayout* day_layout;
  QGridLayout* main_layout;

  QList<QLabel*> header_cells_;
  QList<MonthDayLabel*> day_cells_;
  QDate selected_date_;

  int month_start_at_, month_end_at_;
  int month_rows_;
  int header_height_;
  int cell_height_, cell_width_;
  int days_in_last_month, days_in_month;

};

#endif // MONTHWIDGET_H
