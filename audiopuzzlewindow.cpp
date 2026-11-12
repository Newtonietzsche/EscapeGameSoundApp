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
  if (sequence >= soundList.size()) {
    sequence = 0;
  }
  player.setSource(soundList[sequence]);
  player.play();
  ui->progressBar->setValue(qfloat16(sequence+1)/qfloat16(soundList.size())*100 );
}

void audioPuzzleWindow::followSequence() {
  if (player.mediaStatus() == QMediaPlayer::EndOfMedia) {
    playNextSound();
  }
}

void audioPuzzleWindow::playNextSound() {
  sequence += 1;
  if (sequence >= soundList.size()) {
    return;
  }
  player.setSource(soundList[sequence]);
  player.play();
  ui->progressBar->setValue(qfloat16(sequence+1)/qfloat16(soundList.size())*100 );

}

void audioPuzzleWindow::on_pushButton_2_clicked() {
  player.setSource(soundList[0]);
  player.play();
}
void audioPuzzleWindow::on_pushButton_3_clicked() {
  player.setSource(soundList[1]);
  player.play();
}
void audioPuzzleWindow::on_pushButton_4_clicked() {
  player.setSource(soundList[2]);
  player.play();
}
void audioPuzzleWindow::on_pushButton_5_clicked() {
  player.setSource(soundList[3]);
  player.play();
}
void audioPuzzleWindow::on_pushButton_6_clicked() {
  return;
  player.setSource(soundList[4]);
  player.play();
}

void audioPuzzleWindow::openNewWindow() {

  QList temp = ui->horizontalLayout->children();

/*  if (ui->comboBox->currentText() == "Sonnette" &&
      ui->comboBox_2->currentText() == "Frein")*/ if(0){
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
    bool valid;
    foreach(int i,RandomizedSoundList)
    {

    }
}