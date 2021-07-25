#ifndef MISSIONPAGE_H
#define MISSIONPAGE_H

#include <QWidget>
#include <vector>
#include "FileLoader.h"

#define WORD_MODE 0
#define SENTENCE_MODE 1
using namespace std;
class Word_Sentenceexercisetool;
namespace Ui {
	class MissionPage;
}

class MissionPage : public QWidget
{
    Q_OBJECT

public:
    explicit MissionPage(QWidget *parent , unsigned int mode);
    ~MissionPage();

private:
    Ui::MissionPage *ui;
	void LoadContent(Word_Sentenceexercisetool *parent);//��������
	unsigned int mode;//0���� 1�Ự
	vector<Word> * words;
	vector<Sentence> * sentences;
};

#endif // MISSIONPAGE_H
