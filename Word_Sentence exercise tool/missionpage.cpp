#include "missionpage.h"
#include "ui_missionpage.h"
#include "Word_Sentenceexercisetool.h"
MissionPage::MissionPage(QWidget *parent, unsigned int mode) :
    QWidget(parent),
    ui(new Ui::MissionPage)
{
	this->mode = mode;
	Word_Sentenceexercisetool* p = (Word_Sentenceexercisetool*)(parent);
	this->fileLoader = p->fileLoader;
	LoadContent((Word_Sentenceexercisetool*)(parent));
	
    ui->setupUi(this);

	connect(ui->pb_notMastered, &QPushButton::clicked, this, &MissionPage::notYet);
	connect(ui->pb_check, &QPushButton::clicked, this, &MissionPage::showMeaning);
	connect(ui->pb_mastered, &QPushButton::clicked, this, &MissionPage::iRememberedThis);
	connect(ui->pb_pass, &QPushButton::clicked, this, &MissionPage::iGotIt);
	connect(this, &MissionPage::changeLableFig, this, &MissionPage::slot_changeLable);

	ui->label->setText("0/0");

	ui->pb_check->setDisabled(true);
	ui->pb_mastered->setDisabled(true);
	ui->pb_notMastered->setDisabled(true);
	ui->pb_pass->setDisabled(true);

	show();
}

void MissionPage::LoadContent(Word_Sentenceexercisetool *parent)
{
	if (mode == WORD_MODE)
	{
		words = parent->fileLoader->getAllWords(parent->batchSize_Word, parent->master_Word);
		batchSize = parent->batchSize_Word;
		if (batchSize > words->size())
		{
			batchSize = words->size();
		}
		iterW = words->begin();
	}

	if (mode == SENTENCE_MODE)
	{
		sentences = parent->fileLoader->getAllSentences(parent->batchSize_Sentence, parent->master_Sentence);
		for (Sentence iter : *sentences)
		{
			iter.mastered = 0;
		}
		batchSize = parent->batchSize_Sentence;
		if (batchSize > sentences->size())
		{
			batchSize = sentences->size();
		}
		iterS = sentences->begin();
	}
}

MissionPage::~MissionPage()
{
	if(words != NULL)
		delete words;

	if(sentences != NULL)
		delete sentences;
    delete ui;
}

void MissionPage::display(unsigned int mode, string origin, vector<string> * paraphrase)
{
	ui->pb_check->setDisabled(false);
	ui->pb_mastered->setDisabled(false);
	ui->pb_notMastered->setDisabled(false);
	ui->pb_pass->setDisabled(false);
	//清空已有内容
	ui->textEdit->clear();
	if (mode == HIDE_MODE)
	{
		ui->textEdit->append(QString::fromLocal8Bit("<font style=\"font-family:arial;color:rgb(29, 108, 255); font-size:20px; \"><b>")+
			QString::fromLocal8Bit(origin.data())+
			QString::fromLocal8Bit("</b></font><br>解释:<br><font style=\"font-family:arial; color:rgb(255, 85, 0); font-size:20px; \">")+
			QString::fromLocal8Bit("---隐藏状态---")+
			"</font>");
	}

	if (mode == DISPLAY_MODE)
	{
		QString html;
		html += QString::fromLocal8Bit("<font style=\"font-family:arial; color:rgb(29, 108, 255); font-size:20px; \"><b>");
		html += QString::fromLocal8Bit(origin.data());
		html += QString::fromLocal8Bit("</b></font><br>解释:<br><font style=\"font-family:arial; color:rgb(255, 85, 0); font-size:20px; \">");

		for (string iter : (*paraphrase))
		{
			html += QString::fromLocal8Bit(iter.data());
			html += QString::fromLocal8Bit("<br>");
		}
		html += QString::fromLocal8Bit("</font>");
		ui->textEdit->append(html);
	}
}

void MissionPage::blankDisplay()
{
	//清空已有内容
	ui->textEdit->clear();
	ui->textEdit->append(QString::fromLocal8Bit("<font style=\"font-family:arial; color:rgb(29, 108, 255); font-size:60px; \">无内容或已完成<//font>"));
}

void MissionPage::next()
{
	if (mode == WORD_MODE)
	{
		if (iterW == words->end() - 1)
		{
			iterW = words->begin();
		}
		else
		{
			iterW++;
		}
	}
	if (mode == SENTENCE_MODE)
	{
		if (iterS == sentences->end() - 1)
		{
			iterS = sentences->begin();
		}
		else
		{
			iterS++;
		}
	}
}

void MissionPage::show()
{
	if (batchSize == 0)
	{
		ui->pb_check->setDisabled(true);
		ui->pb_mastered->setDisabled(true);
		ui->pb_notMastered->setDisabled(true);
		ui->pb_pass->setDisabled(true);
		blankDisplay();
		return;
	}

	if (mode == WORD_MODE)
	{
		//显示内容		
		display(HIDE_MODE, iterW->origin, &iterW->paraphrase);
	}
	if (mode == SENTENCE_MODE)
	{
		//显示内容
		display(HIDE_MODE, iterS->origin, &iterS->paraphrase);	
	}
}

//slots

void MissionPage::showMeaning()
{
	if (mode == SENTENCE_MODE)
	{
		display(DISPLAY_MODE, iterS->origin, &iterS->paraphrase);
	}
	if (mode == WORD_MODE)
	{
		display(DISPLAY_MODE, iterW->origin, &iterW->paraphrase);
	}
}

void MissionPage::notYet()
{
	if (mode == SENTENCE_MODE)
	{
		if (sentences->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterS->masteredThisBatch >= 2);
		display(HIDE_MODE, iterS->origin, &iterS->paraphrase);
	}
	if (mode == WORD_MODE)
	{
		if (words->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterW->masteredThisBatch >= 2);
		display(HIDE_MODE, iterW->origin, &iterW->paraphrase);
	}
}

void MissionPage::iRememberedThis()
{
	if (mode == SENTENCE_MODE)
	{
		iterS->mastered++;
		iterS->masteredThisBatch++;
		fileLoader->ModifyLineData(iterS->mastered_tag_line, to_string(iterS->mastered));
		if (iterS->masteredThisBatch >= 2)
		{
			doneNum++;
			emit changeLableFig(doneNum);
		}
		
		if (sentences->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterS->masteredThisBatch >= 2);
		display(HIDE_MODE, iterS->origin, &iterS->paraphrase);
	}
	if (mode == WORD_MODE)
	{
		iterW->mastered++;
		iterW->masteredThisBatch++;
		fileLoader->ModifyLineData(iterW->mastered_tag_line, to_string(iterW->mastered));
		if (iterW->masteredThisBatch >= 2)
		{
			doneNum++;
			emit changeLableFig(doneNum);
		}

		if (words->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterW->masteredThisBatch >= 2);
		display(HIDE_MODE, iterW->origin, &iterW->paraphrase);
	}
}

void MissionPage::iGotIt()
{
	if (mode == SENTENCE_MODE)
	{
		iterS->mastered = 100;
		iterS->masteredThisBatch = 100;
		fileLoader->ModifyLineData(iterS->mastered_tag_line, to_string(iterS->mastered));
		if (iterS->masteredThisBatch >= 2)
		{
			doneNum++;
			emit changeLableFig(doneNum);
		}

		if (sentences->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterS->masteredThisBatch >= 2);
		display(HIDE_MODE, iterS->origin, &iterS->paraphrase);
	}
	if (mode == WORD_MODE)
	{
		iterW->mastered = 100;
		iterW->masteredThisBatch = 100;
		fileLoader->ModifyLineData(iterW->mastered_tag_line, to_string(iterW->mastered));
		if (iterW->masteredThisBatch >= 2)
		{
			doneNum++;
			emit changeLableFig(doneNum);
		}

		if (words->size() == 0 || doneNum >= batchSize)
		{
			//显示完成界面
			blankDisplay();

			ui->pb_check->setDisabled(true);
			ui->pb_mastered->setDisabled(true);
			ui->pb_notMastered->setDisabled(true);
			ui->pb_pass->setDisabled(true);
			return;
		}
		do {
			next();
		} while (iterW->masteredThisBatch >= 2);
		display(HIDE_MODE, iterW->origin, &iterW->paraphrase);
	}
}

void MissionPage::slot_changeLable(unsigned int fig)
{	
	ui->label->setText(QString::number(fig) + "/" + QString::number(batchSize));
}


