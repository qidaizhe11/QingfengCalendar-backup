#-------------------------------------------------
#
# Project created by QtCreator 2013-11-08T09:39:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QingfengCalendar
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/CalendarHeader.cpp \
    src/monthview/MonthDayLabel.cpp \
    src/monthview/MonthWidget.cpp \
    src/theme/CalendarTheme.cpp

HEADERS  += \
    src/MainWindow.h \
    src/CalendarHeader.h \
    src/QcGlobal.h \
    src/monthview/MonthDayLabel.h \
    src/monthview/MonthWidget.h \
    src/theme/CalendarTheme.h

OTHER_FILES += \
    README.md
