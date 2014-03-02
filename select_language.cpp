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
#include "select_language.h"
#include "ui_select_language.h"
#include <QTranslator>
#include <QDebug>
#include <QApplication>
#include <QSettings>
#include <QIcon>

select_language::select_language(QWidget *parent) :
    QMainWindow(parent, Qt::CustomizeWindowHint |
    Qt::WindowTitleHint | Qt::WindowCloseButtonHint),
    ui(new Ui::select_language)
{
    ui->setupUi(this);
    setFixedSize(size());
}

//Retranslate Event
void select_language::changeEvent(QEvent *event)
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);
        qDebug() << "Translating?";
    }
    else
    {
        QMainWindow::changeEvent(event);
    }
}

//Function to translate on radio clicks
void select_language::translate(QString lang)
{
    static QTranslator* translator=0;
    if (translator)
    {
        qApp->removeTranslator(translator);
        delete translator;
    }
    translator = new QTranslator(0);
    translator->load(":/translations/Translations/spl_" + lang + ".qm");
    this->setWindowIcon(QIcon(":/pictures/" + lang + ".png"));
    qApp->installTranslator(translator);
}

void select_language::on_English_clicked()
{
    translate("en_us");
}

void select_language::on_French_clicked()
{
    translate("fr");
}

void select_language::on_Spanish_clicked()
{
    translate("es");
}

//End of First run
void select_language::on_OK_clicked()
{
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());

    if (ui->Spanish->isChecked())
    {
        settings.setValue("Language", "Espagnol");
    }
    else if (ui->French->isChecked())
    {
        settings.setValue("Language", "Français");
    }
    else
    {
        settings.setValue("Language", "English");
    }

    this->hide();
    FvUpdater::sharedUpdater()->CheckForUpdatesSilent();
    SeniorProj = new SeniorProject();//I FIGURED IT OUT!
    SeniorProj->show();
}

select_language::~select_language()
{
    delete ui;
}
