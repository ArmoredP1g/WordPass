#ifndef VOCABLISTITEM_H
#define VOCABLISTITEM_H

#include <QWidget>
#include "FileLoader.h"

namespace Ui {
class VocabListItem;
}

//存储要删除记录的必要信息，这些信息最终会发送给父窗口的删除列表
typedef struct
{
	unsigned int startLine;
	unsigned int lineCount;
}DeleteInfo;

class VocabListItem : public QWidget
{
    Q_OBJECT
public:
    explicit VocabListItem(QWidget *parent,FileLoader *fileLoader,string content1,string content2);
    ~VocabListItem();

private:
    Ui::VocabListItem *ui;

	void ShowMeaning();//点击显示含义按钮
	void Forget();//点击忘记后该条记录不可操作

	string content1;//单词或句子意思
	string content2;//解释
};

#endif // VOCABLISTITEM_H
