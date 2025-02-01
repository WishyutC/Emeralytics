QT += core gui widgets webenginewidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Source files
SOURCES += main.cpp mainwindow.cpp web_page.cpp

# Header files
HEADERS += color.h mainwindow.h web_page.h

# UI files for Qt Designer
FORMS += mainwindow.ui

# Add the icon for the application
ICON = app_icon.ico

# Deployment settings
DISTFILES += style.qml

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
