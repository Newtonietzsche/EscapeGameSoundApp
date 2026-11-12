#include "audiopuzzlewindow.h"
#include "ui_audiopuzzlewindow.h"

audioPuzzleWindow::audioPuzzleWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::audioPuzzleWindow) {
  ui->setupUi(this);

    soundNames={
      "Sonnette",
      "RoueLibre",
      "Chaine",
      "Frein"
  };
  soundList = {
      QUrl("qrc:/Sons/Ressources/Sonnette.mp3"),
      QUrl("qrc:/Sons/Ressources/RoueLibre.mp3"),
      QUrl("qrc:/Sons/Ressources/Chaine.mp3"),
      QUrl("qrc:/Sons/Ressources/Frein.mp3"),
  };

    for (int k=0;k<soundNumber;k++)
  {
        QComboBox * combo = new QComboBox;
        foreach (QString q, soundNames)
        {
            combo->addItem(q);
        }
      ui->horizontalLayout_2->addWidget(combo);

   }

    listRandomizer();
  player.setAudioOutput(&audioOutput);
  audioOutput.setVolume(0.5);
  connect(ui->pushButton, SIGNAL(clicked(bool)), this,
          SLOT(whenPlayIsClicked()));
  connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(openNewWindow()));
  connect(&player, &QMediaPlayer::mediaStatusChanged, this,
          &audioPuzzleWindow::followSequence);




}

audioPuzzleWindow::~audioPuzzleWindow() { delete ui; }

void audioPuzzleWindow::on_pushButton_clicked() {
    if (runSequence)
    {
        qDebug()<<"stop sequence";
        player.stop();
           // sequence = RandomizedSoundList.size()+1;
        sequence=0;
        runSequence=0;
        ui->progressBar->setValue(0);
        return;



    }
  if (sequence >= soundList.size()) {
    sequence = 0;
  }
  runSequence=1;
  player.setSource(soundList[RandomizedSoundList[sequence]]);
   ui->progressBar->setValue(qfloat16(sequence+1)/qfloat16(RandomizedSoundList.size())*100 );
  player.play();

}

void audioPuzzleWindow::followSequence() {
  if (player.mediaStatus() == QMediaPlayer::EndOfMedia && runSequence) {
    playNextSound();
  }
}

void audioPuzzleWindow::playNextSound() {
  sequence += 1;
  if (sequence >= RandomizedSoundList.size()) {
      qDebug()<<"seqence stopped";
      runSequence=0;
      sequence=0;
      ui->progressBar->setValue(0);
    return;
  }
  player.setSource(soundList[RandomizedSoundList[sequence]]);
    ui->progressBar->setValue(qfloat16(sequence+1)/qfloat16(RandomizedSoundList.size())*100 );
  player.play();


}

void audioPuzzleWindow::on_pushButton_2_clicked() {
    if (!runSequence)
    {
  player.setSource(soundList[0]);
  player.play();
    }
}
void audioPuzzleWindow::on_pushButton_3_clicked() {
    if (!runSequence)
    {
        player.setSource(soundList[1]);
        player.play();
    }
}
void audioPuzzleWindow::on_pushButton_4_clicked() {
    if (!runSequence)
    {
        player.setSource(soundList[2]);
        player.play();
    }
}
void audioPuzzleWindow::on_pushButton_5_clicked() {
    if (!runSequence)
    {
        player.setSource(soundList[3]);
        player.play();
    }
}
void audioPuzzleWindow::on_pushButton_6_clicked() {
  return;
    if (!runSequence)
    {
        player.setSource(soundList[4]);
        player.play();
    }
}

void audioPuzzleWindow::openNewWindow() {

  QList temp = ui->horizontalLayout->children();

  if(isComboValid()){
    ui->label_3->setText("Code bon");
    ui->label_3->setStyleSheet("QLabel {  color : green; }");
    wdg->show();
    hide();
  } else {
    ui->label_3->setText("Mauvais code réessayez");
    ui->label_3->setStyleSheet("QLabel {  color : red; }");
  }
}

void audioPuzzleWindow::listRandomizer()
{
    for (int i=0;i<this->soundNumber;i++)
    {
        RandomizedSoundList.append(QRandomGenerator::global()->bounded(this->soundList.size()));
    }
}

bool audioPuzzleWindow::isComboValid()
{
    QList<QComboBox *> list = ui->widget->findChildren<QComboBox *>();
    for (int i = 0; i < list.size(); ++i)
    {
        if (list[i]->currentIndex()!=RandomizedSoundList[i])
        {
            return false;
        }
    }
    return true;
}