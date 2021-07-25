#include "settingpage.h"
#include "ui_settingpage.h"

settingPage::settingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingPage)
{
    ui->setupUi(this);
}

settingPage::~settingPage()
{
    delete ui;
}
