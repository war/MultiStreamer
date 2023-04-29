
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qaudiooutput.h"
#include "qmediaplayer.h"
#include "qpushbutton.h"
#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openBtn_released();
    void on_playPauseBtn_released();
    void on_stopBtn_released();

    void on_volumeSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    bool playing = false;

    void playVideo();
    void stopVideo();
    void pauseVideo();

    float getSliderVal(float maxSlider, float value);

    void updateBtnText(std::string text, QPushButton* btn);

    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audio = new QAudioOutput;
};

#endif // MAINWINDOW_H
