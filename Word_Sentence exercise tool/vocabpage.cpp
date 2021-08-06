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
			for(Word_And_Sentence iter: *words)
			{ 
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
			}
		}
		else
		{
			//����-������
			this->words = fileLoader->getAllMasteredWords(parent->master_Word);
			for (Word_And_Sentence iter : *words)
			{
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
			}
		}
	}
	else
	{
		if (ui->rb_all->isChecked())
		{
			//����-ȫ��
			this->sentents = fileLoader->getAllSentences(65535, 65535);
			for (Word_And_Sentence iter : *sentents)
			{
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
			}
		}
		else
		{
			//����-������
			this->sentents = fileLoader->getAllMasteredSentences(parent->master_Sentence);
			for (Word_And_Sentence iter : *sentents)
			{
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
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

}

//����б��ͷ��ڴ�
void VocabPage::resetList()
{
	//�����ʾ�б�
	ui->listWidget->clear();


	//�ͷ��Զ����б��ڴ�
	for (VocabListItem * iter : listContainer)
	{
		delete iter;
	}

	//����б���������
	listContainer.clear();
}

//ɾ��ѡ������
void VocabPage::del()
{
	vector<Word_And_Sentence *>* deleteList = new vector<Word_And_Sentence *>();
	//TODO
}