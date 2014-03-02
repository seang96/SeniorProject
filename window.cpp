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

#include <QtDebug>
#include <QSettings>


//Move window by dragging at the top (modify 20 to increase/decrease)
//isDragging allows it to move only if the left mouse button is pressed
void SeniorProject::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->pos() << pos();
    if (isDragging) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void SeniorProject::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (event->y() < 25) {
            isDragging = true;
            m_dragPosition = event->globalPos() - frameGeometry().topLeft();
            qDebug() << "topleft" << frameGeometry().topLeft();
            event->accept();
        }
    }
}

void SeniorProject::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        isDragging = false;
    }
}

//Button to exit window/program
void SeniorProject::on_exit_clicked()
{
    qApp->quit();
}
