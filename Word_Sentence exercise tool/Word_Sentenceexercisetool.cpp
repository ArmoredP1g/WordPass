#include "Word_Sentenceexercisetool.h"
#include "index_menu.h"

Word_Sentenceexercisetool::Word_Sentenceexercisetool(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
	FileLoader fileLoader = FileLoader("C:\\Users\\29147\\Desktop\\最近用的破烂\\content.txt");


	connect(ui.pb_home, &QPushButton::clicked, this, &Word_Sentenceexercisetool::Back2Home);
	//fileLoader.getAllWords(100);
	//fileLoader.getAllSentences(100,10);

	//Word wd;
	//wd.origin = "単価";
	//wd.paraphrase.push_back("单价");
	//wd.type = 1;
	//fileLoader.addWord(wd);
	//fileLoader.test();

	//Sentence stc;
	//stc.origin = "sdfasdfasdfa";
	//stc.paraphrase = "啊实打实大苏打实打实";
	//stc.type = 1;
	//stc.remarks.push_back("一来，注意这个\n其次，你还得注意这个");
	//fileLoader.addSentence(stc);
}

void Word_Sentenceexercisetool::Back2Home()
{
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
}
