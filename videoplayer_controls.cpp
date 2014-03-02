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

void SeniorProject::on_playButton_clicked()
{
    switch(mediaPlayer->state())
    {
    case QMediaPlayer::PlayingState:
        mediaPlayer->pause();
        ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    default:
        mediaPlayer->play();
        ui->playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    }
}

void SeniorProject::on_Information_currentChanged(int index)
{
    switch(index)
    {
    case 0:
        ui->Information->resize(ui->Information->width(), 311);
        ui->controlLayout->hide();
        if (mediaPlayer->state() == QMediaPlayer::PlayingState)
        {
            on_playButton_clicked();
        }
        break;
    case 1:
        ui->Information->resize(ui->Information->width(), 291);
        if (prev_prog == prog)
            changevid = false;
        if (prog == 1 && changevid)
            mediaPlayer->setMedia(QUrl("http://db.tt/Av4ohw4e"));
        if (prog == 2 && changevid)
            mediaPlayer->setMedia(QUrl("https://db.tt/nAhsdOvQ"));
        if (prog == 3 && changevid)
            mediaPlayer->setMedia(QUrl("https://db.tt/h7e1bTLS"));
        if (prog == 4 && changevid)
            mediaPlayer->setMedia(QUrl("http://db.tt/K1kwfdnZ"));
        ui->controlLayout->show();
        on_playButton_clicked();
        break;
    }
}

void SeniorProject::durationChanged(qint64 duration)
{
    ui->positionSlider->setRange(0, duration);
    qDebug() << "Duration changed to " + QString::number(duration);
}

void SeniorProject::positionChanged(qint64 position)
{
    ui->positionSlider->setValue(position);
}

void SeniorProject::setPosition(int position)
{
    mediaPlayer->setPosition(position);
}


void SeniorProject::on_volumeButton_clicked()
{
    switch(mediaPlayer->isMuted())
    {
    case false:
        mediaPlayer->setMuted(true);
        ui->volumeButton->setIcon
                (style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        break;
    default:
        mediaPlayer->setMuted(false);
        ui->volumeButton->setIcon
                (style()->standardIcon(QStyle::SP_MediaVolume));
        break;
    }
}

void SeniorProject::on_volumeSlider_valueChanged(int position)
{
    mediaPlayer->setVolume(position);
    ui->volume_label->setText(QString::number(position));
}

void SeniorProject::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    switch(status)
    {
    case QMediaPlayer::LoadingMedia:
        changevid= false;
        ui->Back->setEnabled(false);
        ui->Information->setTabText(1, tr("Video (Loading...)"));
        break;
    case QMediaPlayer::InvalidMedia:
        qDebug() << "true!";
        changevid= false;
        ui->Back->setEnabled(true);
        ui->Information->setTabText
                (1, tr("Error. Could not load video: No Internet Connection?"));
        break;
    default:
        changevid= false;
        ui->Back->setEnabled(true);
        ui->Information->setTabText(1, tr("Video"));
        break;
    }
    qDebug() << status;
}
