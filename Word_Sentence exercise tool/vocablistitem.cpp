#include "vocablistitem.h"
#include "ui_vocablistitem.h"

VocabListItem::VocabListItem(QWidget *parent, FileLoader *fileLoader, Word_And_Sentence * content) :
    QWidget(parent),
    ui(new Ui::VocabListItem)
{
	this->fileLoader = fileLoader;
	this->content = *content;
    ui->setupUi(this);
	connect(ui->tb_meaning,&QToolButton::clicked,this,&VocabListItem::ShowMeaning);
	connect(ui->tb_forget, &QToolButton::clicked, this, &VocabListItem::Forget);
	ui->l->setText(QString::fromLocal8Bit(content->origin.c_str()));
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
	//�������ɵ���
	string paraphrase = "";
	for (string iter_ : content.paraphrase)
	{
		paraphrase += iter_;
	}
	ui->l->setText(QString::fromLocal8Bit(paraphrase.c_str()));
	ui->l->setStyleSheet("color:#585eaa;font-size:15px;font-family:\"Arial\";");
}

void VocabListItem::Forget()
{
	//����Ӧ��¼masterֵ����
	fileLoader->ModifyLineData(content.mastered_tag_line,"0",fileLoader->filepath);
	//��Ӧ��Ŀ���ɲ���
	ui->cb->setDisabled(true);
	ui->tb_forget->setDisabled(true);
	ui->l->setStyleSheet("color:#72777b;font-size:15px;font-family:\"Arial\";");
}