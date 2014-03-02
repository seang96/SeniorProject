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

#include <QDesktopServices>
#include <QApplication>
//Running Programs
void SeniorProject::on_Run_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    qDebug() << path;
    if (prog == 2)
    {
        QDesktopServices::openUrl(path + "/mcuhelper_setup.exe");
    }
    else if (prog == 4)
    {
        QDesktopServices::openUrl(path + "/FizzBuzz.exe");

    }
}
