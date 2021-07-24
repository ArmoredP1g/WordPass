#ifndef MISSIONPAGE_H
#define MISSIONPAGE_H

#include <QWidget>

namespace Ui {
class MissionPage;
}

class MissionPage : public QWidget
{
    Q_OBJECT

public:
    explicit MissionPage(QWidget *parent = nullptr);
    ~MissionPage();

private:
    Ui::MissionPage *ui;
};

#endif // MISSIONPAGE_H
