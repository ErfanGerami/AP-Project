QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    card.cpp \
    changeinfo.cpp \
    errors.cpp \
    filehandeling.cpp \
    forgotmypassword.cpp \
    game.cpp \
    gamehandeler.cpp \
    getserversinformation.cpp \
    main.cpp \
    login.cpp \
    maingamewindow.cpp \
    mainmenu.cpp \
    player.cpp \
    signup.cpp \
    test.cpp\
    mainmenu.cpp \
    waitmenu.cpp \
    PlayerInGame.cpp \
    DataPacket.cpp \
    serverselection.cpp

HEADERS += \
    card.h \
    changeinfo.h \
    errors.h \
    filehandeling.h \
    forgotmypassword.h \
    game.h \
    gamehandeler.h \
    getserversinformation.h \
    login.h \
    maingamewindow.h \
    mainmenu.h \
    player.h \
    signup.h \
    test.h\
    mainmenu.h \
    waitmenu.h \
    PlayerInGame.h \
    DataPacket.h \
    serverselection.h

FORMS += \
    changeinfo.ui \
    forgotmypassword.ui \
    getserversinformation.ui \
    login.ui \
    maingamewindow.ui \
    mainmenu.ui \
    signup.ui \
    test.ui\
    mainmenu.ui \
    waitmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
