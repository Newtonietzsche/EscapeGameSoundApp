#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  _smallCounter = 0.0f;
  ui->setupUi(this);
  QList<QComboBox *> list = ui->widget->findChildren<QComboBox *>();
  foreach (auto obj, list) {
    obj->addItem(QString("0"));
    obj->addItem(QString("1"));
    obj->addItem(QString("2"));
    obj->addItem(QString("3"));
    obj->addItem(QString("4"));
    obj->addItem(QString("5"));
    obj->addItem(QString("6"));
    obj->addItem(QString("7"));
    obj->addItem(QString("8"));
    obj->addItem(QString("9"));
  }
  connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(openNewWindow()));
  // wdg->show();
}

void MainWindow::openNewWindow() {

  if (isCodeValid()) {
    wdg->show();
    hide();
  } else {
    ui->label_2->setText("Mauvais code réessayez");
    ui->label_2->setStyleSheet("QLabel {  color : red; }");
  }
}

bool MainWindow::isCodeValid() {
  QList<QComboBox *> list = ui->widget->findChildren<QComboBox *>();
  for (int i = 0; i < list.size(); ++i) {
    if (qint32(list[i]->currentIndex()) != CodeDePasse[i]) {
      return false;
    }
  }
  return true;
}

void MainWindow::whenButtonIsClicked() {
  ui->label->setText("the button has been clicked " +
                     QVariant(_smallCounter).toString() + " times !");
}

MainWindow::~MainWindow() { delete ui; }
