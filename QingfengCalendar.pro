#-------------------------------------------------
#
# Project created by QtCreator 2013-11-08T09:39:16
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QingfengCalendar
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/monthview/MonthDayLabel.cpp \
    src/monthview/MonthWidget.cpp \
    src/theme/CalendarTheme.cpp \
    src/database/CalendarContract.cpp \
    src/database/Database.cpp \
    src/database/ICalendarHelper.cpp \
    src/database/CalendarItems.cpp \
    src/EventSettingsView.cpp \
    src/CalendarHeaderView.cpp \
    src/QfDateEdit.cpp

HEADERS  += \
    src/MainWindow.h \
    src/monthview/MonthDayLabel.h \
    src/monthview/MonthWidget.h \
    src/theme/CalendarTheme.h \
    src/database/CalendarContract.h \
    src/database/Database.h \
    src/database/ICalendarHelper.h \
    src/database/CalendarItems.h \
    src/EventSettingsView.h \
    src/CalendarHeaderView.h \
    src/QfDateEdit.h \
    src/QfGlobal.h \
    src/theme/CalendarTheme.h \
    src/monthview/MonthWidget.h \
    src/monthview/MonthDayLabel.h

OTHER_FILES += \
    README.md

RESOURCES += \
    resources/QingfengCalendar.qrc
