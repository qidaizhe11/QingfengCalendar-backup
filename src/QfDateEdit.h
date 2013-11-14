#ifndef QFDATEEDIT_H
#define QFDATEEDIT_H

//-------------------------------------------------------------------------

#include <QWidget>
#include <QDateTime>

class QComboBox;

//-------------------------------------------------------------------------

class QfDateEdit : public QWidget
{
  Q_OBJECT
public:
  QfDateEdit(const QDate &date, QWidget *parent = 0);
  ~QfDateEdit() {}

  QDate date() const { return date_; }

signals:
  void dateChanged(const QDate &date);

public slots:
  void updateDate(const QDate &date);

private slots:
  void yearChanged(const QString &year);
  void monthChanged(int index);
  void dayChanged(int index);

private:
  QComboBox *year_combo;
  QComboBox *month_combo;
  QComboBox *day_combo;

  QDate date_;
};

//-------------------------------------------------------------------------

class QfTimeEdit : public QWidget
{
  Q_OBJECT
public:
  QfTimeEdit(const QTime &time, QWidget *parent = 0);
  ~QfTimeEdit() {}

  QTime time() const { return time_; }

public slots:
  void upadteTime(const QTime& time);

private slots:
  void timeChanged();

private:
  QComboBox *hour_combo;
  QComboBox *minute_combo;

  QTime time_;
};

//-------------------------------------------------------------------------

#endif // QFDATEEDIT_H
