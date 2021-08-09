#ifndef VOCABLISTITEM_H
#define VOCABLISTITEM_H

#include <QWidget>
#include "FileLoader.h"

namespace Ui {
class VocabListItem;
}

class VocabListItem : public QWidget
{
    Q_OBJECT
public:
    explicit VocabListItem(QWidget *parent,FileLoader *fileLoader,Word_And_Sentence * content);
    ~VocabListItem();
	Ui::VocabListItem *ui;
	Word_And_Sentence content;
	FileLoader * fileLoader;
	bool readyToDel = false;
private:
	void ShowMeaning();//�����ʾ���尴ť
	void Forget();//������Ǻ������¼���ɲ���
	void SetDelFlag();
};

#endif // VOCABLISTITEM_H
