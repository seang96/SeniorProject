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
#include "select_language.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("spgrn");
    QApplication::setOrganizationDomain("spgrn.com");
    SeniorProject w;
    select_language sl;
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    QString language = settings.value("Language").toString();
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
    if (language != "English" and language != "Español" and
            language != "Français")
        sl.show();
    else {
        if (settings.value("UpdateOnStart").toBool())
            FvUpdater::sharedUpdater()->CheckForUpdatesSilent();
        w.show();
    }

    return a.exec();
}
