/***********************************************************************************
**    This file is part of Senior Project Launcher.
**
**    Senior Project Launcher is free software: you can redistribute it and/or modify
**    it under the terms of the GNU Lesser General Public License as published by
**    the Free Software Foundation, either version 2.1 of the License, or
**    (at your option) any later version.
**
**    Senior Project Launcher is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU Lesser General Public License for more details.
**
**    You should have received a copy of the GNU Lesser General Public License
**    along with Senior Project Launcher.  If not, see <http://www.gnu.org/licenses/>.
**************************************************************************************/

#include "fvupdater.h"
#include "seniorproject.h"
#include "ui_seniorproject.h"
#include "animation.cpp"
#include "window.cpp"
#include "options.cpp"
#include "run_programs.cpp"
#include "program_buttons.cpp"
#include "webbrowser.cpp"
#include "videoplayer_controls.cpp"
#include "theming.cpp"
#include <QtDebug>
#include <QSettings>
#include <qmediaplayer.h>
#include <qvideowidget.h>

SeniorProject::SeniorProject(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeniorProject)
{
    ui->setupUi(this);
    ui->Run->hide();
    ui->controlLayout->hide();
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);

    //Create Media Player
    mediaPlayer = new QMediaPlayer(this,QMediaPlayer::VideoSurface);
    QVideoWidget *videoWidget = new QVideoWidget;
    videoWidget->setUpdatesEnabled(false);
    videoWidget->showMinimized(); //show
    videoWidget->hide();

    ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->volumeButton->setIcon
            (style()->standardIcon(QStyle::SP_MediaVolume));
    ui->positionSlider->setRange(0, 0);

    mediaPlayer->setVideoOutput(videoWidget);
    ui->Information->addTab(videoWidget, tr("Video")); //hide
    videoWidget->setAspectRatioMode(Qt::IgnoreAspectRatio);
    connect(mediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),
            this, SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));
    connect(ui->positionSlider, SIGNAL(sliderMoved(int)),
            this, SLOT(setPosition(int)));
    connect(mediaPlayer, SIGNAL(positionChanged(qint64)),
            this, SLOT(positionChanged(qint64)));
    connect(mediaPlayer, SIGNAL(durationChanged(qint64)),
            this, SLOT(durationChanged(qint64)));
    qDebug() << mediaPlayer->error();
    changevid = true;

    //Setup moving window
    isDragging = false;

    //Give installed_themes a number before loading
    installed_themes = 0;

    //Give Main Windows Values
    winw = 775;
    winh = 500;
    winx = 0;
    winy = 20;

    //Set Settings
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());

    //Load/Set the current language setting
    language = settings.value("Language").toString();
    qDebug() << "lang =" << language;
    ui->Language_box->setCurrentText(language); //Set language to selected language
    qDebug() << settings.value("Language").toString();

    //Set to current theme and receive themes from themese folder
    loadthemes();
    ui->Theme_box->setCurrentText(settings.value("CurrentTheme").toString());
    if (ui->Theme_box->currentText() == "< default theme >")
        themer("default");
    //Enable/Disable UpdateOnStart
    if (settings.value("UpdateOnStart").toBool())
        ui->checkForUpdatesOnStart->setCheckState(Qt::Checked);
    //If the program window has been moved, move it to that position
    if (settings.contains("WinPos"))
        move(settings.value("WinPos").toPoint());
    qDebug() << "Current Pos:";
    qDebug() << pos();
    qDebug() << "Saved Pos= " + settings.value("WinPos").toString();
    update();
    qDebug() << winw << winh;
}

SeniorProject::~SeniorProject()
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    if (settings.value("WinPos").toPoint() != pos())
    {
        settings.setValue("WinPos", pos());
        settings.sync();
        qDebug() << "settings" << settings.value("WinPos").toPoint();
    }
        delete ui;
}
