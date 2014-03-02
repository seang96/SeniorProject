#ifndef SELECT_LANGUAGE_H
#define SELECT_LANGUAGE_H

#include "seniorproject.h"
#include <QMainWindow>

namespace Ui {
class select_language;
}

class select_language : public QMainWindow
{
    Q_OBJECT

public:
    explicit select_language(QWidget *parent = 0);
    ~select_language();
protected:
    void translate(QString lang);
    void changeEvent(QEvent *event);
private slots:
    void on_English_clicked();

    void on_French_clicked();

    void on_Spanish_clicked();

    void on_OK_clicked();

private:
    Ui::select_language *ui;
    SeniorProject *SeniorProj;

};

#endif // SELECT_LANGUAGE_H
