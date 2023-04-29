
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qpushbutton.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    bool playPause = true;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openBtn_released();
    void on_playPauseBtn_released();
    void on_stopBtn_released();

private:
    Ui::MainWindow *ui;
    void playVideo();
    void stopVideo();
    void pauseVideo();
    void updateBtnText(std::string text, QPushButton* btn);
};

#endif // MAINWINDOW_H
