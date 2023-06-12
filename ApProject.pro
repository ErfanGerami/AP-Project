QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    errors.cpp \
    filehandeling.cpp \
    forgotmypassword.cpp \
    game.cpp \
    main.cpp \
    login.cpp \
    player.cpp \
    signup.cpp

HEADERS += \
    errors.h \
    filehandeling.h \
    forgotmypassword.h \
    game.h \
    login.h \
    player.h \
    signup.h

FORMS += \
    forgotmypassword.ui \
    login.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
