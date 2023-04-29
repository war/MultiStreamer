
#include "mainwindow.h"
#include "qmediaplayer.h"
#include "qurl.h"
#include "qvideowidget.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FISHTANK");

    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;

    QVBoxLayout* layout = new QVBoxLayout();

    QString path = "C:\\Users\\oui\\Videos";
    QString file = "2023-04-27 01-06-26.mp4";
    QUrl url = QUrl::fromLocalFile(path + "\\" + file);

    player->setVideoOutput(vw);
    player->setSource(url);
    layout->addWidget(vw);

    player->play();

    qDebug() << player->playbackState();

    ui->vidWidget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openBtn_released()
{
    qDebug() << "open";
    ui->playPauseBtn->setDisabled(false);
    ui->stopBtn->setDisabled(false);
}

void MainWindow::on_playPauseBtn_released()
{
    if (playPause){
        playVideo();
    } else {
        pauseVideo();
    }

    playPause = !playPause;
}

void MainWindow::on_stopBtn_released()
{
    stopVideo();
}

void MainWindow::playVideo()
{
    // Play video
    qDebug() << "play";

    // After video is played
    playPause = true;
    updateBtnText("Pause", ui->playPauseBtn);
    ui->stopBtn->setDisabled(false);
}

void MainWindow::pauseVideo()
{
    // Pause video
    qDebug() << "pause";

    // After video is paused
    playPause = false;
    updateBtnText("Play", ui->playPauseBtn);
}

void MainWindow::stopVideo()
{
    // Stop video
    qDebug() << "stop";

    // After video is stopped
    ui->playPauseBtn->setDisabled(false);
    ui->stopBtn->setDisabled(true);

    playPause = true;

    updateBtnText("Play", ui->playPauseBtn);
}

void MainWindow::updateBtnText(std::string text, QPushButton* btn)
{
    QString str = QString::fromStdString(text);
    btn->setText(str);
}
