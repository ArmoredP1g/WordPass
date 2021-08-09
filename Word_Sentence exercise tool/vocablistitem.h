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
	void ShowMeaning();//点击显示含义按钮
	void Forget();//点击忘记后该条记录不可操作
	void SetDelFlag();
};

#endif // VOCABLISTITEM_H
