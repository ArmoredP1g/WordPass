#include "settingpage.h"
#include "ui_settingpage.h"
#include "Word_Sentenceexercisetool.h"


settingPage::settingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingPage)
{
	this->parent = (Word_Sentenceexercisetool*)(parent);
    ui->setupUi(this);
	if (this->parent->fileLoader->language == JP)
	{
		ui->rb_jp->setChecked(true);
	}
	if (this->parent->fileLoader->language == EN)
	{
		ui->rb_en->setChecked(true);
	}
	connect(ui->rb_en, &QRadioButton::clicked, this, &settingPage::setLanguage_en);
	connect(ui->rb_jp, &QRadioButton::clicked, this, &settingPage::setLanguage_jp);
}

settingPage::~settingPage()
{
    delete ui;
}

void settingPage::setLanguage_en()
{
	parent->fileLoader->language = EN;
}

void settingPage::setLanguage_jp()
{
	parent->fileLoader->language = JP;
}