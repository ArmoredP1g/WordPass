#include "settingpage.h"
#include "ui_settingpage.h"
#include "Word_Sentenceexercisetool.h"


settingPage::settingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingPage)
{
	this->parent = (Word_Sentenceexercisetool*)(parent);
    ui->setupUi(this);
	LoadConfig();
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
	connect(ui->pb_confirm, &QPushButton::clicked, this, &settingPage::ConfirmSettigs);
}

settingPage::~settingPage()
{
    delete ui;
}


void settingPage::LoadConfig()
{
	ui->le_wordBatchSize->setText(QString::number(parent->batchSize_Word));
	ui->le_sentenceBatchSize->setText(QString::number(parent->batchSize_Sentence));
	ui->le_masterLimit->setText(QString::number(parent->master_Word));
	//ui->le_masterLimit->setText(QString::number(parent->master_Sentence));
}

void settingPage::ConfirmSettigs()
{
	Setting set;
	set.BatchSize_word = ui->le_wordBatchSize->text().toInt();
	set.BatchSize_sentence = ui->le_sentenceBatchSize->text().toInt();
	set.Master_word = ui->le_masterLimit->text().toInt();
	parent->fileLoader->ConfirmSettings(set);
	parent->LoadConfig(".\\userdata\\config.txt");
}

//设置语种的radiobutton的槽
void settingPage::setLanguage_en()
{
	parent->fileLoader->language = EN;
}

void settingPage::setLanguage_jp()
{
	parent->fileLoader->language = JP;
}

