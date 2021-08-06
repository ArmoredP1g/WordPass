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
	Word_And_Sentence content;
	FileLoader * fileLoader;
private:
    Ui::VocabListItem *ui;

	void ShowMeaning();//�����ʾ���尴ť
	void Forget();//������Ǻ������¼���ɲ���


};

#endif // VOCABLISTITEM_H
