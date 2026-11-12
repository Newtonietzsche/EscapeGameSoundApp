#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  _smallCounter = 0.0f;
  ui->setupUi(this);

  connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(openNewWindow()));
}

void MainWindow::openNewWindow() {

  qDebug() << ui->lineEdit->text();
  if (motDePasse == ui->lineEdit->text()) {
    wdg->show();
    hide();
  } else {
    ui->label_2->setText("Mauvais code réessayez");
    ui->label_2->setStyleSheet("QLabel {  color : red; }");
  }
}

void MainWindow::on_pushButton_2_clicked() {
  player.setAudioOutput(&audioOutput);
  audioOutput.setVolume(0.5);

  player.setSource(QUrl("qrc:/Sons/Ressources/Sonnette.mp3"));

  player.play();
}

void MainWindow::whenButtonIsClicked() {
  ui->label->setText("the button has been clicked " +
                     QVariant(_smallCounter).toString() + " times !");
}

MainWindow::~MainWindow() { delete ui; }
