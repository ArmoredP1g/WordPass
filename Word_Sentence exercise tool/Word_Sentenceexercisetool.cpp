#include "Word_Sentenceexercisetool.h"

Word_Sentenceexercisetool::Word_Sentenceexercisetool(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	FileLoader fileLoader = FileLoader("C:\\Users\\29147\\Desktop\\最近用的破烂\\content.txt");
	//fileLoader.getAllWords(100);
	fileLoader.getAllSentences(100,10);

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
