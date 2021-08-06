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

//根据词库重新加载列表内容
void VocabPage::refreshAll()
{
	//先清空列表
	resetList();

	if (ui->rb_word->isChecked())
	{
		if (ui->rb_all->isChecked())
		{
			//单词-全部
			this->words = fileLoader->getAllWords(65535, 65535);
			for(Word_And_Sentence iter: *words)
			{ 
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
			}
		}
		else
		{
			//单词-已掌握
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
			//句子-全部
			this->sentents = fileLoader->getAllSentences(65535, 65535);
			for (Word_And_Sentence iter : *sentents)
			{
				listContainer.push_back(new VocabListItem(nullptr, fileLoader, &iter));
			}
		}
		else
		{
			//句子-已掌握
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

//清空列表，释放内存
void VocabPage::resetList()
{
	//清空显示列表
	ui->listWidget->clear();


	//释放自定义列表内存
	for (VocabListItem * iter : listContainer)
	{
		delete iter;
	}

	//清空列表容器本身
	listContainer.clear();
}

//删除选中内容
void VocabPage::del()
{
	vector<Word_And_Sentence *>* deleteList = new vector<Word_And_Sentence *>();
	//TODO
}