#include "vocablistitem.h"
#include "ui_vocablistitem.h"

VocabListItem::VocabListItem(QWidget *parent, FileLoader *fileLoader, string content1, string content2) :
    QWidget(parent),
    ui(new Ui::VocabListItem)
{
	this->content1 = content1;
	this->content2 = content2;
    ui->setupUi(this);
	connect(ui->tb_meaning,&QToolButton::clicked,this,&VocabListItem::ShowMeaning);
	connect(ui->tb_forget, &QToolButton::clicked, this, &VocabListItem::Forget);
	ui->l->setText(QString::fromLocal8Bit(content1.c_str()));
	ui->l->setStyleSheet("color:#ff6600;font-size:15px;font-family:\"Arial\";");

}

VocabListItem::~VocabListItem()
{
	//disconnect(ui->tb_meaning, &QToolButton::clicked, this, &VocabListItem::ShowMeaning);
	//disconnect(ui->tb_forget, &QToolButton::clicked, this, &VocabListItem::Forget);
    delete ui;
}

//slots
void VocabListItem::ShowMeaning()
{
	ui->l->setText(QString::fromLocal8Bit(content2.c_str()));
	ui->l->setStyleSheet("color:#585eaa;font-size:15px;font-family:\"Arial\";");
}

void VocabListItem::Forget()
{
	//将对应记录master值归零

	//对应条目不可操作
	ui->cb->setDisabled(true);
	ui->tb_forget->setDisabled(true);
	ui->l->setStyleSheet("color:#72777b;font-size:15px;font-family:\"Arial\";");
}