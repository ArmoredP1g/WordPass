#include "missionpage.h"
#include "ui_missionpage.h"
#include "Word_Sentenceexercisetool.h"
MissionPage::MissionPage(QWidget *parent, unsigned int mode) :
    QWidget(parent),
    ui(new Ui::MissionPage)
{
	this->mode = mode;
	LoadContent((Word_Sentenceexercisetool*)(parent));
    ui->setupUi(this);
}

void MissionPage::LoadContent(Word_Sentenceexercisetool *parent)
{
	if (mode == WORD_MODE)
	{
		words = parent->fileLoader->getAllWords(parent->batchSize_Word, parent->master_Word);
	}

	if (mode == SENTENCE_MODE)
	{
		sentences = parent->fileLoader->getAllSentences(parent->batchSize_Sentence, parent->master_Sentence);
	}
}

MissionPage::~MissionPage()
{
	delete words;
	delete sentences;
    delete ui;
}
