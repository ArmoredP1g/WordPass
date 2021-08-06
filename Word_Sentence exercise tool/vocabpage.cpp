#include "vocabpage.h"
#include "ui_vocabpage.h"
#include "Word_Sentenceexercisetool.h"
#include <QListWidgetItem>

VocabPage::VocabPage(QWidget *parent, FileLoader * fileLoader):
    QWidget(NULL),
    ui(new Ui::VocabPage)
{
	this->parent = (Word_Sentenceexercisetool*)parent;
	this->fileLoader = fileLoader;

    ui->setupUi(this);
	connect(ui->rb_all, &QRadioButton::clicked, this, &VocabPage::refreshAll);
	connect(ui->rb_masteredOnly, &QRadioButton::clicked, this, &VocabPage::refreshAll);
	connect(ui->rb_sentences, &QRadioButton::clicked, this, &VocabPage::refreshAll);
	connect(ui->rb_word, &QRadioButton::clicked, this, &VocabPage::refreshAll);
	ui->rb_masteredOnly->setChecked(true);
	ui->rb_sentences->setChecked(true);

	refreshAll();
}

VocabPage::~VocabPage()
{
	delete sentents;
	delete words;
    delete ui;
}

//���ݴʿ����¼����б�����
void VocabPage::refreshAll()
{
	//������б�
	resetList();

	if (ui->rb_word->isChecked())
	{
		if (ui->rb_all->isChecked())
		{
			//����-ȫ��
			this->words = fileLoader->getAllWords(65535, 65535);
			for(Word iter: *words)
			{ 
				//�������ɵ���
				string paraphrase = "";
				for (string iter_:iter.paraphrase)
				{
					paraphrase += iter_;
				}
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, iter.origin, paraphrase));
			}
		}
		else
		{
			//����-������
			this->words = fileLoader->getAllMasteredWords(parent->master_Word);
			for (Word iter : *words)
			{
				//�������ɵ���
				string paraphrase = "";
				for (string iter_ : iter.paraphrase)
				{
					paraphrase += iter_;
				}
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, iter.origin, paraphrase));
			}
		}
	}
	else
	{
		if (ui->rb_all->isChecked())
		{
			//����-ȫ��
			this->sentents = fileLoader->getAllSentences(65535, 65535);
			for (Sentence iter : *sentents)
			{
				//�������ɵ���
				string paraphrase = "";
				for (string iter_ : iter.paraphrase)
				{
					paraphrase += iter_;
				}
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, iter.origin, paraphrase));
			}
		}
		else
		{
			//����-������
			this->sentents = fileLoader->getAllMasteredSentences(parent->master_Sentence);
			for (Sentence iter : *sentents)
			{
				//�������ɵ���
				string paraphrase = "";
				for (string iter_ : iter.paraphrase)
				{
					paraphrase += iter_;
				}
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, iter.origin, paraphrase));
			}
		}
	}

	for (VocabListItem * iter:listContainer)
	{
		QListWidgetItem *listItem1 = new QListWidgetItem();
		listItem1->setSizeHint(QSize(0, 50));
		ui->listWidget->addItem(listItem1);
		ui->listWidget->setItemWidget(listItem1, iter);
	}

	//for (int i = 0; i < 15; i++)
	//{
	//	VocabListItem * vocabListItem = new VocabListItem(nullptr, fileLoader, "apple", "ƻ��");
	//	QListWidgetItem *listItem1 = new QListWidgetItem();
	//	listItem1->setSizeHint(QSize(0, 50));
	//	ui->listWidget->addItem(listItem1);
	//	ui->listWidget->setItemWidget(listItem1, vocabListItem);
	//}
}

//����б��ͷ��ڴ�
void VocabPage::resetList()
{
	//�����ʾ�б�
	ui->listWidget->clear();
	for (int i = 0; i < ui->listWidget->count(); i++)


	//�ͷ��Զ����б��ڴ�
	for (VocabListItem * iter : listContainer)
	{
		delete iter;
	}

	//����б���������
	listContainer.clear();
}