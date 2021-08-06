#ifndef VOCABLISTITEM_H
#define VOCABLISTITEM_H

#include <QWidget>
#include "FileLoader.h"

namespace Ui {
class VocabListItem;
}

//�洢Ҫɾ����¼�ı�Ҫ��Ϣ����Щ��Ϣ���ջᷢ�͸������ڵ�ɾ���б�
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

	void ShowMeaning();//�����ʾ���尴ť
	void Forget();//������Ǻ������¼���ɲ���

	string content1;//���ʻ������˼
	string content2;//����
};

#endif // VOCABLISTITEM_H
