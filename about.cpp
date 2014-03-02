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

#include "about.h"
#include "ui_about.h"
#include <QSettings>

About::About(QWidget *parent) :
    QDialog(parent, Qt::WindowCloseButtonHint | Qt::WindowTitleHint),
    ui(new Ui::About)
{
    ui->setupUi(this);
    setFixedSize(size());
    QString version = QString("%1.%2.%3").arg(VERSION_MAJOR)
            .arg(VERSION_MINOR).arg(VERSION_BUILD);
    ui->spl_ver->setText("SPL (" + version + ")");
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    QString lang = settings.value("Language").toString();
    QString link;
    if (lang == "English")
        link = "qrc:/html/html/credits.html";
    if (lang == "Español")
        link = "qrc:/html/html/credits_es.html";
    if (lang == "Français")
        link = "qrc:/html/html/credits_fr.html";
    ui->CreditsText->setUrl(link);
}

void About::on_aboutqt_clicked()
{
    qApp->aboutQt();
}

void About::on_ok_clicked()
{
    close();
}

About::~About()
{
    delete ui;
}
