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

#include <QTime>
#include <math.h>
#include <QPainter>
#ifndef M_PI
#define M_PI           3.14159265358979323846
#endif

void SeniorProject::animation(QFrame *a, int a_start_x, int a_start_y,
                              int a_move_x, int a_move_y,
                              QFrame *b, int b_start_x, int b_start_y,
                              int b_move_x, int b_move_y,
                              int timelen)
{
    QTime timer;
    float dif;
    int now;

    timer.start();
    while (now = timer.elapsed(), now < timelen)
    {
        dif = float(now) / timelen;

        dif = cos(M_PI * dif) * (-0.5) + 0.5;
        dif = cos(M_PI * dif) * (-0.5) + 0.5;

        a->move (a_start_x + (a_move_x * dif),
                 a_start_y + (a_move_y * dif));

        b->move (b_start_x + (b_move_x * dif),
                 b_start_y + (b_move_y * dif));

        repaint();
    } //needs to be condensed
    a->move (a_start_x + a_move_x,
            a_start_y + a_move_y);

    b->move (b_start_x + b_move_x,
            b_start_y + b_move_y);

    repaint();
}

void SeniorProject::mainanimation()
{
    animation(ui->mainbox,         winx, winy, -winw, 0,
              ui->programs_window, winx + winw, winy, -winw, 0,
              999);
}

