#ifndef VOCABPAGE_H
#define VOCABPAGE_H
#include "FileLoader.h"
#include "vocablistitem.h"
#include <QWidget>

#define MODE_ALL 0
#define MODE_MASTERED_ONLY 1
#define MODE_WORD 0
#define MODE_SENTENCE 1

class Word_Sentenceexercisetool;

namespace Ui {
class VocabPage;
}

class VocabPage : public QWidget
{
    Q_OBJECT

public:
    explicit VocabPage(QWidget *parent,FileLoader * fileLoader);
    ~VocabPage();

private:
    Ui::VocabPage *ui;
	Word_Sentenceexercisetool * parent;
	FileLoader * fileLoader;
	vector<Word_And_Sentence> * words;//word list
	vector<Word_And_Sentence> * sentents;//sentence list
	vector<VocabListItem *> listContainer;//����б��е��Զ���ؼ�
	void refreshAll();//���¼�������
	void resetList();
	void del();

};

#endif // VOCABPAGE_H
