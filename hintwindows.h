#ifndef HINTWINDOWS_H
#define HINTWINDOWS_H

#include <QDialog>

namespace Ui {
class HintWindows;
}

class HintWindows : public QDialog
{
    Q_OBJECT

public:
    explicit HintWindows(QWidget *parent = nullptr);
    ~HintWindows();

private:
    Ui::HintWindows *ui;
};

#endif // HINTWINDOWS_H
