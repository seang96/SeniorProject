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

void SeniorProject::on_back_clicked()
{
    if(ui->source->url() != url)
    {
        ui->source->back();
        if (prog == 5) {
            ui->source->back();
        }
        qDebug() << ui->source->url();
    }
}

void SeniorProject::on_forward_clicked()
{
    ui->source->forward();
}

void SeniorProject::on_source_urlChanged(const QUrl &arg1)
{
    if (prog == 5) {
        QString id = "#js-repo-pjax-container";
        QString url = arg1.toString() + id;
        if (! url.contains("#js-repo-pjax-container#js-repo-pjax-container"))
            ui->source->setUrl(url);
        qDebug() << url;
    }
}
