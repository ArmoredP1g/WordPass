#include "index_menu.h"
#include "ui_index_menu.h"

Index_Menu::Index_Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Index_Menu)
{
    ui->setupUi(this);
}

Index_Menu::~Index_Menu()
{
    delete ui;
}
