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

#include <QDebug>
#include <QSettings>
#include <QTranslator>

//Options Button
void SeniorProject::on_Options_3_clicked()
{
    if (mediaPlayer->state() == QMediaPlayer::PlayingState)
    {
        on_playButton_clicked();
        wasplaying = true;
    }
    else {
        wasplaying = false;
    }
    if (ui->closeoptions->pos() != QPoint(0, 20))
    {
        ui->closeoptions->move(0, 20);
    }
    ui->closeoptions_frame->show();
    animation(ui->closeoptions_frame,  0, 20, 0, 20,
              ui->Options,  winx + winw, winy,
              -ui->Options->frameGeometry().width(), 0, 999);
}
void SeniorProject::on_closeoptions_clicked()
{
    if (wasplaying)
        on_playButton_clicked();
    ui->closeoptions_frame->hide();
    animation(ui->closeoptions_frame,  0, 20, 0, 20,
              ui->Options,  winw - ui->Options->frameGeometry().width(), winy,
              ui->Options->frameGeometry().width(), 0, 999);
}

void SeniorProject::on_About_clicked()
{
    about = new About;
    about->show();
}

//---=Change Language=---
//Translate Function
void SeniorProject::translate(QString lang)
{
    static QTranslator* translator=0;
    if (translator)
    {
        qApp->removeTranslator(translator);
        delete translator;
    }
    translator = new QTranslator(0);
    translator->load(":/translations/Translations/spl_" + lang + ".qm");
    qApp->installTranslator(translator);
}

//Retranslate Event
void SeniorProject::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
        qDebug() << "Translating?";
        switch (prog)
        {
        case 1: on_program_TradingPost_clicked(); break;
        case 2: on_program_MCUHelper_clicked(); break;
        case 3: on_program_AccessFlashDrive_clicked(); break;
        case 4: on_program_FizzBuzz_clicked(); break;
        }
//        ui->reload_source->setGeometry(100,110,40,16);
//        ui->reload_source->setGeometry(105,110,55,16);
    }
    QMainWindow::changeEvent(event);
}
//Language ComboBox
void SeniorProject::on_Language_box_currentTextChanged(const QString &arg1)
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    if (arg1 == "Español")
    {
        translate("es");
        qDebug() << "spanish repeating?";
    }
    else if (arg1 == "Français")
    {
        translate("fr");
        qDebug() << "french repeating?";
    }
    else if (arg1 == "English")
    {
        translate("en-us");
        qDebug() << "english repeating?";
    }
    qDebug() << arg1;
    ui->Language_box->setCurrentText(arg1);
    settings.setValue("Language", arg1);
    qDebug() << prog;
}

//Updating
void SeniorProject::on_Updater_button_clicked()
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    language = settings.value("Language").toString();
    if (settings.value("CurrentTheme").toString() == NULL) {
        settings.setValue("CurrentTheme", "< default theme >");
    }
    if (language == "English")
        FvUpdater::sharedUpdater()->SetFeedURL(
                    "http://dl.dropboxusercontent.com/u/8526567/SPL/Appcast.xml"
                    );
    if (language == "Español")
        FvUpdater::sharedUpdater()->SetFeedURL(
                    "http://dl.dropboxusercontent.com/u/8526567/SPL/Appcast_es.xml"
                    );
    if (language == "Français")
        FvUpdater::sharedUpdater()->SetFeedURL(
                    "http://dl.dropboxusercontent.com/u/8526567/SPL/Appcast_fr.xml"
                    );
    FvUpdater::sharedUpdater()->CheckForUpdatesNotSilent();
}

void SeniorProject::on_checkForUpdatesOnStart_clicked()
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    if (ui->checkForUpdatesOnStart->isChecked())
        settings.setValue("UpdateOnStart", true);
    else
        settings.setValue("UpdateOnStart", false);
}

void SeniorProject::on_Updater_Reset_clicked()
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    settings.remove("FVLatestSkippedVersion");
}

