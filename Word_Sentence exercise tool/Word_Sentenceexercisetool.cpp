#include "Word_Sentenceexercisetool.h"
#include "index_menu.h"

Word_Sentenceexercisetool::Word_Sentenceexercisetool(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
	FileLoader fileLoader = FileLoader("C:\\Users\\29147\\Desktop\\����õ�����\\content.txt");


	connect(ui.pb_home, &QPushButton::clicked, this, &Word_Sentenceexercisetool::Back2Home);
	//fileLoader.getAllWords(100);
	//fileLoader.getAllSentences(100,10);

	//Word wd;
	//wd.origin = "�g��";
	//wd.paraphrase.push_back("����");
	//wd.type = 1;
	//fileLoader.addWord(wd);
	//fileLoader.test();

	//Sentence stc;
	//stc.origin = "sdfasdfasdfa";
	//stc.paraphrase = "��ʵ��ʵ���մ�ʵ��ʵ";
	//stc.type = 1;
	//stc.remarks.push_back("һ����ע�����\n��Σ��㻹��ע�����");
	//fileLoader.addSentence(stc);
}

void Word_Sentenceexercisetool::Back2Home()
{
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
}
