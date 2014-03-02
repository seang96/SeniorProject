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

#include <QSettings>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QFileDialog>

void SeniorProject::themer(QString theme_name)
{
    qDebug() << theme_name;
    QString file = QCoreApplication::applicationDirPath()
            + "/themes/" + theme_name + "/theme.style";
    qDebug() << "file = " + file;
    QFile themeFile(file);
    QString themeStyle;
    if (themeFile.open(QIODevice::ReadOnly))
    {
        QTextStream in (&themeFile);
        themeStyle = in.readAll();
        themeFile.close();
    }
    else
    {
        qDebug() << "error";
    }
    qDebug() << themeStyle;
    qApp->setStyleSheet(themeStyle);
    update();
}

void SeniorProject::on_Theme_box_currentTextChanged(const QString &arg1)
{
    if(arg1 == "< default theme >") {
        themer("default");
    }
    else {
        themer(arg1);
        qDebug() << "Setting theme to: " + arg1;
    }
    QSettings settings(QSettings::NativeFormat,
                       QSettings::UserScope,
                       QApplication::organizationName(),
                       QApplication::applicationName());
    settings.setValue("CurrentTheme", arg1);
}

void SeniorProject::on_browseButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "/", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug() << "directory = " + dir;
    ui->installDir->setText(dir);
}

void SeniorProject::on_installDir_returnPressed()
{
    QString path = ui->installDir->text();
    QDir src(path);
    if(!src.exists()) {
        QMessageBox::critical(this, tr("Folder Not Found"), tr("The folder specified cannot be found. Please recheck the folder's path."), QMessageBox::Ok);
        return;
    }
    QFile style(path + "/theme.style");
    if (!style.exists()){
        QMessageBox::critical(this, tr("File Not Found"),
                              tr("The folder specified does not contain the ") +
                              tr("core theme file \"theme.style\". ") +
                              tr("Please recheck the folder's path."),
                              QMessageBox::Ok);
        return;
    }
    QStringList folder;
    while (path.endsWith("/") or path.endsWith("\\"))
        path.chop(1);
    if (path.contains("/"))
        folder = path.split("/");
    if (path.contains("\\"))
        folder = path.split("\\");
    QString foldername = folder.last();
    while (foldername.contains("/") or foldername.contains("\\"))
        foldername.remove(0, 1);
    QString destination = QCoreApplication::applicationDirPath() + "/themes/" + foldername;
    QDir dir(destination);
    if (dir.exists())
        rmDir(destination);
    dir.mkpath(destination);
    cpDir(path, destination);
    qDebug() << "folder= " + foldername;
    loadthemes();
    ui->Theme_box->setCurrentText(foldername);
}

void SeniorProject::cpDir(QString src, QString dst)
{
    QDir dir(src);
    if (! dir.exists())
        return;

    foreach (QString d, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot)) {
        QString dst_path = dst + QDir::separator() + d;
        dir.mkpath(dst_path);
        cpDir(src+ QDir::separator() + d, dst_path);
    }

    foreach (QString f, dir.entryList(QDir::Files)) {
        QFile::copy(src + QDir::separator() + f, dst + QDir::separator() + f);
    }
}

bool SeniorProject::rmDir(const QString &dirPath)
{
    QDir dir(dirPath);
    if (!dir.exists())
        return true;
    foreach(const QFileInfo &info, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        if (info.isDir()) {
            if (!rmDir(info.filePath()))
                return false;
        } else {
            if (!dir.remove(info.fileName()))
                return false;
        }
    }
    QDir parentDir(QFileInfo(dirPath).path());
    return parentDir.rmdir(QFileInfo(dirPath).fileName());
}


void SeniorProject::loadthemes()
{
    if (installed_themes > 0) {
        for (int i=installed_themes; i > 0; i--)
        {
            ui->Theme_box->removeItem(i);
            installed_themes--;
            qDebug() << "i= " << i << "installed_themes= " + installed_themes;
        }
    }
    QDir path(QCoreApplication::applicationDirPath() + "/themes");
    QStringList folders = path.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for(QStringList::ConstIterator folder=folders.begin(); folder!=folders.end(); folder++ ) {
        QString dirname= *folder;
        qDebug() << dirname;
        if (dirname != "default")
        {
            ui->Theme_box->addItem(dirname);
            qDebug() << "passed " + dirname;
            installed_themes++;
        }
        qDebug() << "loop";
    }
}

void SeniorProject::on_ThemeButton_clicked()
{
    on_installDir_returnPressed();
}

