#pragma once
#include <QtWidgets/QWidget>
#include "ui_Word_Sentenceexercisetool.h"
#include "FileLoader.h"
#include "missionpage.h"
#include "settingpage.h"
#include "addingpage.h"

#define WORD_MODE 0
#define SENTENCE_MODE 1

class Word_Sentenceexercisetool : public QWidget
{
    Q_OBJECT

public:
    Word_Sentenceexercisetool(QWidget *parent = Q_NULLPTR);
	~Word_Sentenceexercisetool();
	void Back2Home();
	void goWordMission();
	void goSentenceMission();
	void goSettingPage();

    Ui::Word_SentenceexercisetoolClass ui;
	void LoadConfig(string path);
	vector<string> split(const string& str, const string& delim);
	AddingPage * addingPage;
	FileLoader * fileLoader;
	unsigned int batchSize_Word;
	unsigned int batchSize_Sentence;
	unsigned int master_Word;
	unsigned int master_Sentence;
private slots:
	void goAddingPage();
};
