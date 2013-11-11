#ifndef CALENDARHEADER_H
#define CALENDARHEADER_H

//----------------------------------------------------------------------

#include <QFrame>
#include <QDate>

class QLabel;
class QPushButton;

//-------------------------------------------------------------------------

class CalendarHeaderView : public QFrame
{
  Q_OBJECT

public:
  CalendarHeaderView(QWidget* parent = 0);
  ~CalendarHeaderView() {}

signals:
  void selectedDateChanged(const QDate& date);
  //	void minButtonClicked();
  //	void maxButtonClicked();
  //	void closeButtonClicked();

public slots:
  void setSelectedDate(const QDate& date);

protected:
  //	void mousePressEvent(QMouseEvent *);

private slots:
  void nextMonth();
  void previousMonth();

private:
  void createWidgets();
  void createLayout();
  void createConnections();
  //void setColorStyleSheet();

  //QLabel* software_name_label;
  //QToolButton* min_button;
  //QToolButton* max_button;
  //QToolButton* close_button;
  QLabel* date_label;
  QPushButton* previous_month_button;
  QPushButton* next_month_button;

  QDate selected_date_;
};

//-------------------------------------------------------------------------

#endif // CALENDARHEADER_H
