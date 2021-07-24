#include "missionpage.h"
#include "ui_missionpage.h"

MissionPage::MissionPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MissionPage)
{
    ui->setupUi(this);
}

MissionPage::~MissionPage()
{
    delete ui;
}
