#-------------------------------------------------
#
# Project created by QtCreator 2013-08-26T21:56:10
#
#-------------------------------------------------

#define FILEVER 1.0.0
QT += multimedia multimediawidgets webkitwidgets

TARGET = SeniorProject

CONFIG += mobility c++11

VERSION_MAJOR = 1
VERSION_MINOR = 0
VERSION_BUILD = 0

DEFINES += "VERSION_MAJOR=$$VERSION_MAJOR"\
       "VERSION_MINOR=$$VERSION_MINOR"\
       "VERSION_BUILD=$$VERSION_BUILD"
VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_BUILD}

TARGET = spl

DEFINES += "VERSION=$$VERSION"

# Fervor autoupdater
!include("fervor/Fervor.pri") {
    error("Unable to include Fervor autoupdater.")
}

RC_FILE = SPL.rc

TRANSLATIONS += Translations/spl_en-us.ts \
		Translations/spl_es.ts \
		Translations/spl_fr.ts

SOURCES += main.cpp \
	   seniorproject.cpp \
    options.cpp \
    run_programs.cpp \
    program_buttons.cpp \
    select_language.cpp \
    window.cpp \
    webbrowser.cpp \
    about.cpp \
    animation.cpp \
    videoplayer_controls.cpp \
    theming.cpp

HEADERS  += seniorproject.h \
    select_language.h \
    about.h

FORMS    += seniorproject.ui \
    select_language.ui \
    about.ui

RESOURCES += \
    Pictures.qrc \
    translations.qrc \
    html.qrc
