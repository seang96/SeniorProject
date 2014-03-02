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

//Back
void SeniorProject::on_Back_clicked()
{
    prev_prog = prog;
    prog = 0;
    if (mediaPlayer->state() == QMediaPlayer::PlayingState)
    {
        on_playButton_clicked();
    }
    animation(ui->programs_window,  winx, winy, +winw, 0,
              ui->mainbox,          -winw, winy, +winw, 0,
              999);
    if (!ui->Run->isHidden())
        ui->Run->hide();
    changevid = true;
    ui->Options_3->show();
    ui->Information->setTabEnabled(1, true);
}

void SeniorProject::on_program_TradingPost_clicked()
{
    url = "qrc:/html/html/TradingPost.html";
    ui->source->setUrl(url);
    if (prog != 1)
    {
        mainanimation();
        prog = 1;
        if (prev_prog != prog)
            ui->Information->setCurrentIndex(0);
        else
            on_playButton_clicked();
    }
}
void SeniorProject::on_program_MCUHelper_clicked()
{
    ui->Run->setText(tr("Install MCUHelper"));
    ui->Run->show();
    url = "qrc:/html/html/MCUHelper.html";
    ui->source->setUrl(url);
    if (prog != 2)
    {
        mainanimation();
        prog = 2;
        if (prev_prog != prog)
            ui->Information->setCurrentIndex(0);
        else
            on_playButton_clicked();
    }
}
void SeniorProject::on_program_AccessFlashDrive_clicked()
{
    url = "qrc:/html/html/AccessFlashDrive.html";
    qDebug() << url;
    ui->source->setUrl(url);
    if (prog != 3)
    {
        mainanimation();
        prog = 3;
        if (prev_prog != prog)
            ui->Information->setCurrentIndex(0);
        else
            on_playButton_clicked();
    }
}
void SeniorProject::on_program_FizzBuzz_clicked()
{
    ui->Run->setText(tr("Run FizzBuzz Test"));
    ui->Run->show();
    url = "qrc:/html/html/FizzBuzz.html";
    qDebug() << url;
    ui->source->setUrl(url);
    if (prog != 4)
    {
        mainanimation();
        prog = 4;
        if (prev_prog != prog)
            ui->Information->setCurrentIndex(0);
        else
            on_playButton_clicked();
    }
}

void SeniorProject::on_program_SPL_clicked()
{
    url = "https://github.com/seang96/SeniorProject#js-repo-pjax-container";
    qDebug() << url;
    ui->Information->setTabEnabled(1, false);
    ui->source->setUrl(url);
    if (prog != 5)
    {
        mainanimation();
        prog = 5;
    }
}

//Picture Click
void SeniorProject::on_program_TradingPost_picture_clicked()
{
    on_program_TradingPost_clicked();
}
void SeniorProject::on_program_MCUHelper_picture_clicked()
{
    on_program_MCUHelper_clicked();
}
void SeniorProject::on_program_AccessFlashDrive_picture_clicked()
{
    on_program_AccessFlashDrive_clicked();
}
void SeniorProject::on_program_FizzBuzz_picture_clicked()
{
    on_program_FizzBuzz_clicked();
}
void SeniorProject::on_program_SPL_picture_clicked()
{
    on_program_SPL_clicked();
}
