
//-------------------------------------------------------------------------

#include "QfDateEdit.h"
#include <QtWidgets>

//-------------------------------------------------------------------------

QfDateEdit::QfDateEdit(const QDate &date, QWidget *parent) :
  QWidget(parent), date_(date)
{
  year_combo = new QComboBox();
  month_combo = new QComboBox();
  day_combo = new QComboBox();

  for (int year = date_.year() - 50; year < 100; ++year) {
    year_combo->addItem(i);
  }
  for (int month = 1; month <= 12; ++month) {
    month_combo->addItem(QDate::longMonthName(month));
  }
  for (int day = 1; day <= date_.daysInMonth(); ++day) {
    day_combo->addItem(QDate::longDayName(day));
  }

  QGridLayout *layout = new QGridLayout;
  layout->addWidget(year_combo, 0, 0);
  layout->addWidget(month_combo, 0, 1);
  layout->addWidget(day_combo, 0, 2);
  layout->setColumnStretch(0, 3);
  layout->setColumnStretch(1, 4);
  layout->setColumnStretch(2, 5);
  setLayout(layout);

  connect(year_combo, SIGNAL(currentIndexChanged(QString)),
          this, SLOT(yearChanged(QString)));
  connect(month_combo, SIGNAL(currentIndexChanged(int)),
          this, SLOT(monthChanged(int)));
  connect(day_combo, SIGNAL(currentIndexChanged(int)),
          this, SLOT(dayChanged(int)));
}

//-------------------------------------------------------------------------

void QfDateEdit::updateDate(const QDate &date)
{
  date_ = date;
  // TODO : yearCombo的begin, end是否随着新的date一并更新？ 有待求证
  year_combo->setCurrentText(QString::number(date_.year()));
  month_combo->setCurrentIndex(date_.month() - 1);

  day_combo->clear();
  for (int day = 1; day <= date_.daysInMonth(); ++day) {
    day_combo->addItem(QDate::longDayName(day));
  }
  day_combo->setCurrentIndex(date_.day() - 1);
}

void QfDateEdit::yearChanged(const QString &year)
{
  // TODO : Seems it's not safe. Should be improved.
  date_.year() = year.toInt();
}

void QfDateEdit::monthChanged(int index)
{
  date_.month() = index + 1;

  day_combo->clear();
  for (int day = 1; day <= date_.daysInMonth(); ++day) {
    day_combo->addItem(QDate::longDayName(day));
  }
  day_combo->setCurrentIndex(date_.day() - 1);
}

void QfDateEdit::dayChanged(int index)
{
  date_.day() = index + 1;
}

//-------------------------------------------------------------------------

QfTimeEdit::QfTimeEdit(const QTime &time, QWidget *parent)
  : QWidget(parent), time_(time)
{
  hour_combo = new QComboBox();
  minute_combo = new QComboBox();

  for (int hour = 0; hour < 24; ++hour) {
    hour_combo->addItem(hour);
  }
  for (int minute = 0; minute < 60; minute += 5) {
    minute_combo->addItem(minute);
  }

  QHBoxLayout *layout = new QHBoxLayout;
  layout->addWidget(hour_combo, 1);
  layout->addSpacing(5);
  layout->addWidget(minute_combo, 1);
  setLayout(layout);

  connect(hour_combo, SIGNAL(currentIndexChanged(int)),
          this, SLOT(timeChanged()));
  connect(minute_combo, SIGNAL(currentIndexChanged(QString)),
          this, SLOT(timeChanged()));
}

//-------------------------------------------------------------------------

void QfTimeEdit::upadteTime(const QTime &time)
{
  time_ = time;
  hour_combo->setCurrentText(time_.hour());
  minute_combo->setCurrentText(time_.minute());
}

void QfTimeEdit::timeChanged()
{
  time_.hour() = hour_combo->currentText().toInt();
  time_.minute() = minute_combo->currentText().toInt();
}

//-------------------------------------------------------------------------
