#ifndef ICALENDARHELPER_H
#define ICALENDARHELPER_H

#include <QDateTime>
#include <libical/ical.h>

class ICalendarHelper
{
public:
  struct icaltimetype icaltimetypeFromQDateTime(const QDateTime& time);
//  QString
};

#endif // ICALENDARHELPER_H
