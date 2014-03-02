#ifndef SENIORPROJECT_H
#define SENIORPROJECT_H

#include "about.h"
#include <QMainWindow>
#include <QMouseEvent>
#include <QFrame>
#include <qmediaplayer.h>

namespace Ui {
class SeniorProject;
}

class SeniorProject : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeniorProject(QWidget *parent = 0);
    ~SeniorProject();
private:
    QPoint m_dragPosition;
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void changeEvent(QEvent *event);
    void animation(QFrame *a, int a_start_x, int a_start_y, int a_move_x, int a_move_y,
                   QFrame *b, int b_start_x, int b_start_y, int b_move_x, int b_move_y,
                   int timelen);
    void mainanimation();
    void translate(QString lang);
    void themer(QString theme_name);
    void loadthemes();
    void cpDir(QString src, QString dst);
    bool rmDir(const QString &dirPath);
private slots:
    void on_exit_clicked();
    void on_program_TradingPost_clicked();

    void on_Back_clicked();

    void on_program_MCUHelper_clicked();

    void on_program_AccessFlashDrive_clicked();

    void on_program_FizzBuzz_clicked();

    void on_Run_clicked();

    void on_Language_box_currentTextChanged(const QString &arg1);

    void on_program_TradingPost_picture_clicked();

    void on_program_MCUHelper_picture_clicked();

    void on_program_AccessFlashDrive_picture_clicked();

    void on_program_FizzBuzz_picture_clicked();

    void on_program_SPL_picture_clicked();

    void on_Options_3_clicked();

    void on_closeoptions_clicked();

    void on_back_clicked();

    void on_forward_clicked();

    void on_About_clicked();

    //MediaPlayer Slots
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);

    void on_playButton_clicked();

    void on_Information_currentChanged(int index);

    void positionChanged(qint64 position);

    void durationChanged(qint64 duration);

    void setPosition(int position);

    void on_volumeButton_clicked();

    void on_volumeSlider_valueChanged(int position);

    //End of MediaPlayer slots

    void on_Theme_box_currentTextChanged(const QString &arg1);


    void on_browseButton_clicked();

    void on_installDir_returnPressed();

    void on_ThemeButton_clicked();

    void on_Updater_button_clicked();

    void on_checkForUpdatesOnStart_clicked();

    void on_Updater_Reset_clicked();

    void on_program_SPL_clicked();

    void on_source_urlChanged(const QUrl &arg1);

private:
    Ui::SeniorProject *ui;
    About *about;
    QMediaPlayer *mediaPlayer;
    bool isDragging;
    bool changevid;
    bool closeoptions;
    bool wasplaying;
    int winw;
    int winh;
    int winx;
    int winy;
    int prog;
    int prev_prog;
    int installed_themes;
    QString url;
    QString language;
    QString vid_link;
};


#endif // SENIORPROJECT_H
