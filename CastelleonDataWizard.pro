QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++1z

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    castellionobject.cpp \
    configline.cpp \
    configlineparse.cpp \
    configlineparsetester.cpp \
    configlinewrite.cpp \
    configlinewritetester.cpp \
    debugprinthelper.cpp \
    fileiorunner.cpp \
    filereadwrite.cpp \
    main.cpp \
    mainwindow.cpp \
    modifyfiletester.cpp

HEADERS += \
    castellionobject.h \
    configline.h \
    configlineparse.h \
    configlineparsetester.h \
    configlinewrite.h \
    configlinewritetester.h \
    debugprinthelper.h \
    fileiorunner.h \
    filereadwrite.h \
    mainwindow.h \
    modifyfiletester.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/gtest/release/ -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/gtest/debug/ -lgtest
else:unix: LIBS += -L$$PWD/../../lib/gtest/ -lgtest

INCLUDEPATH += $$PWD/../../lib/gtest/include
DEPENDPATH += $$PWD/../../lib/gtest/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/gtest/release/libgtest.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/gtest/debug/libgtest.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/gtest/release/gtest.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../lib/gtest/debug/gtest.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../lib/gtest/libgtest.a

DISTFILES += \
    test_file.dat
