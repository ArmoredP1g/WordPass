#include "addingpage.h"
#include "ui_addingpage.h"

AddingPage::AddingPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddingPage)
{
    ui->setupUi(this);
	windowAttrFlag = 0x00000000;//初始化窗口属性

	//设置无边框
	//windowAttrFlag |= Qt::FramelessWindowHint;
	windowAttrFlag |= Qt::WindowStaysOnTopHint;
	setWindowFlags(windowAttrFlag);
	ui->rb_addWord->setChecked(true);
	ui->rb_jp->setChecked(true);

	connect(ui->pb_back, &QPushButton::clicked, this, &AddingPage::close);
	connect(ui->pb_confirm, &QPushButton::clicked, this, &AddingPage::addItem);
}

AddingPage::~AddingPage()
{
    delete ui;
}

void AddingPage::setFileLoader(FileLoader * loader)
{
	fileLoader = loader;
}

//slots
void AddingPage::addItem()
{	
	//判空
	if (ui->le_wordOrSenten->text().toLocal8Bit().toStdString() == "" || ui->pt_paraphrase->toPlainText().toLocal8Bit().toStdString() == "")
	{
		return;
	}
	//确定语种
	unsigned int type;
	if (ui->rb_en->isChecked())
	{
		type = 0;
	}	
	if (ui->rb_jp->isChecked())
	{
		type = 1;
	}
	
	if (ui->rb_addWord->isChecked())
	{
		//添加单词
		Word_And_Sentence word;
		word.type = type;
		word.mastered = 0;
		word.origin = ui->le_wordOrSenten->text().toLocal8Bit().toStdString();
		word.paraphrase.push_back(ui->pt_paraphrase->toPlainText().toLocal8Bit().toStdString());
		fileLoader->addWord(word);
	}
	else
	{
		//添加句子
		Word_And_Sentence senten;
		senten.type = type;
		senten.mastered = 0;
		senten.origin = ui->le_wordOrSenten->text().toLocal8Bit().toStdString();
		senten.paraphrase.push_back(ui->pt_paraphrase->toPlainText().toLocal8Bit().toStdString());
		fileLoader->addSentence(senten);
	}

	//添加后清空内容
	ui->le_wordOrSenten->clear();
	ui->pt_paraphrase->clear();
}