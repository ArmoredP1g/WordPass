#ifndef MISSIONPAGE_H
#define MISSIONPAGE_H

#include <QWidget>
#include <vector>
#include "FileLoader.h"

#define WORD_MODE 0
#define SENTENCE_MODE 1
#define	HIDE_MODE 0
#define DISPLAY_MODE 1
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
	FileLoader * fileLoader;
	vector<Word> * words = NULL;
	vector<Sentence> * sentences = NULL;
	vector<Word>::iterator iterW;
	vector<Sentence>::iterator iterS;
	unsigned int batchSize;//һ����ٸ����ʡ�����
	unsigned int doneNum = 0;//��¼�����Ѿ������ĸ���

	void display(unsigned int mode, string origin, vector<string> * paraphrase);
	void blankDisplay();
	void next();//����ָ��
	void show();
	void showMeaning();
	void notYet();
	void iRememberedThis();
	void iGotIt();
	void slot_changeLable(unsigned int fig);
signals:
	void changeLableFig(unsigned int fig);
};

#endif // MISSIONPAGE_H
