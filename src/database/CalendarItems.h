#ifndef CALENDARITEMS_H
#define CALENDARITEMS_H

#include <QDateTime>
#include <QString>
//#include <QSqlRecord>
#include <QList>

class EventItems
{
public:
  int calendar_id;
  QString organizer;
  QString title;
  QString description;
  QString event_location;
  QDateTime start_datetime;
  QDateTime end_datetime;
  bool all_day;
  QString duration;
  int availablity;
  int access_level;

  QList<ReminderItems*> reminders;
};

class CalendarItems
{
public:
  QString name;
  QString calendar_display_name;
  bool visible;
  QColor calendar_color;
};

class ReminderItems
{
  int event_id;
  int minutes;
  int method;
};

class InstanceItems
{
  int event_id;
  QDateTime begin;
  QDateTime end;
  QDate start_day;
  QDate start_minute;
  QDate end_day;
  QDate end_minute;
};

#endif // CALENDARITEMS_H
