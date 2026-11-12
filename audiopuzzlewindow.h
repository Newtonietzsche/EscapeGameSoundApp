#ifndef AUDIOPUZZLEWINDOW_H
#define AUDIOPUZZLEWINDOW_H

#include "hintwindows.h"
#include <QAudioOutput>
#include <QDialog>
#include <QListWidget>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QUrl>
#include <QVector>

namespace Ui {
class audioPuzzleWindow;
}

class audioPuzzleWindow : public QDialog {
  Q_OBJECT

public:
  explicit audioPuzzleWindow(QWidget *parent = nullptr);
  ~audioPuzzleWindow();

public:
  void playNextSound();
public slots:
  void on_pushButton_clicked();
  void followSequence();
  void openNewWindow();

  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();

private:
  Ui::audioPuzzleWindow *ui;
  int sequence = 0;
  QMediaPlayer player;
  QAudioOutput audioOutput;
  QVector<QUrl> soundList;
  QVector<QString> soundNames;
  QWidget *wdg = new HintWindows;
};

#endif // AUDIOPUZZLEWINDOW_H
