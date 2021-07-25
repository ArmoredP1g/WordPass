#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QWidget>

namespace Ui {
class settingPage;
}

class settingPage : public QWidget
{
    Q_OBJECT

public:
    explicit settingPage(QWidget *parent = nullptr);
    ~settingPage();

private:
    Ui::settingPage *ui;
};

#endif // SETTINGPAGE_H
