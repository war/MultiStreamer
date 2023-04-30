
#include "mainwindow.h"
#include "qmediaplayer.h"
#include "qurl.h"
#include "qvideowidget.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QAudioFormat>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FISHTANK");

    QVideoWidget* vw = new QVideoWidget;
    QVBoxLayout* layout = new QVBoxLayout();

    player->setVideoOutput(vw);

    layout->addWidget(vw);

    ui->vidWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openBtn_released()
{
    qDebug() << "open";

    pauseVideo();

    QString openVideo = tr("Open Video");
    QString initialDir = "./";
    QString fileTypes = tr("Video Files (*.mp4 *.mov *.mka)");

    QString dialog = QFileDialog::getOpenFileName(this, openVideo, initialDir, fileTypes);

    player->setSource(dialog);
    //player->setVolume(50);

    audio->setMuted(false);
    audio->setVolume(0.5);

    player->setAudioOutput(audio);

    playVideo();
}

void MainWindow::on_playPauseBtn_released()
{
    if (playing){
        pauseVideo();
    } else {
        playVideo();
    }
}

void MainWindow::on_stopBtn_released()
{
    stopVideo();
}

void MainWindow::playVideo()
{
    // Play video
    qDebug() << "play";
    player->play();

    // After video is played
    playing = true;
    updateBtnText("Pause", ui->playPauseBtn);

    ui->playPauseBtn->setDisabled(false);
    ui->stopBtn->setDisabled(false);
}

void MainWindow::pauseVideo()
{
    // Pause video
    qDebug() << "pause";
    player->pause();

    // After video is paused
    playing = false;
    updateBtnText("Play", ui->playPauseBtn);
}

void MainWindow::stopVideo()
{
    // Stop video
    qDebug() << "stop";
    player->stop();

    // After video is stopped
    ui->playPauseBtn->setDisabled(false);
    ui->stopBtn->setDisabled(true);

    playing = false;

    updateBtnText("Play", ui->playPauseBtn);
}

void MainWindow::updateBtnText(std::string text, QPushButton* btn)
{
    QString str = QString::fromStdString(text);
    btn->setText(str);
}

void MainWindow::on_volumeSlider_sliderMoved(int position)
{
    float volume = getSliderVal(100, position);
    audio->setVolume(volume);
}

float MainWindow::getSliderVal(float maxSlider, float value)
{
    return (value / maxSlider);
}

void MainWindow::on_muteBtn_released()
{
    if (muted)
    {
        ui->muteBtn->setText("Mute");
    }
    else
    {
        ui->muteBtn->setText("Un-Mute");
    }

    audio->setMuted(!muted);
    muted = !muted;
}

