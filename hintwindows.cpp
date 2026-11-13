#include "hintwindows.h"
#include "ui_hintwindows.h"

HintWindows::HintWindows(QWidget *parent)
    : QDialog(parent), ui(new Ui::HintWindows) {
  ui->setupUi(this);
  ui->label->setStyleSheet("QLabel {  color : green; }");
}

HintWindows::~HintWindows() { delete ui; }
