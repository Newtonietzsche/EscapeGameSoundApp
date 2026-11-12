#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "audiopuzzlewindow.h"
#include <QAudioOutput>
#include <QFile>
#include <QFileInfo>
#include <QListWidget>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QUrl>
#include <QVector>
#include <unistd.h>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);

  ~MainWindow() override;

public:
  void playNextSound();
public slots:
  void whenButtonIsClicked();
  void on_pushButton_2_clicked();
  void openNewWindow();

private:
  Ui::MainWindow *ui;
  double _smallCounter;
  double test;
  int sequence = 0;
  QMediaPlayer player;
  QAudioOutput audioOutput;
  QVector<QUrl> soundList;
  QString motDePasse ="mdp";
  QWidget *wdg = new audioPuzzleWindow;
  QString path;
};
#endif // MAINWINDOW_H
