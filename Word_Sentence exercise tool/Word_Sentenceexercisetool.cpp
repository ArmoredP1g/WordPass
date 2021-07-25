#include "Word_Sentenceexercisetool.h"
#include "index_menu.h"

Word_Sentenceexercisetool::Word_Sentenceexercisetool(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
	addingPage = new AddingPage;
	
	fileLoader = new FileLoader(".\\userdata\\单词例句库.txt");
	addingPage->setFileLoader(fileLoader);
	LoadConfig(".\\userdata\\config.txt");

	connect(ui.pb_home, &QPushButton::clicked, this, &Word_Sentenceexercisetool::Back2Home);
	connect(ui.pb_add, &QPushButton::clicked, this, &Word_Sentenceexercisetool::goAddingPage);
	
	//fileLoader->getAllWords(100, 10);
	//fileLoader->getAllSentences(100,10);

	//fileLoader->delete_(122,15);

}

Word_Sentenceexercisetool::~Word_Sentenceexercisetool()
{
	delete addingPage;
	delete fileLoader;
}

void Word_Sentenceexercisetool::LoadConfig(string path)
{
	ifstream ifs(path);
	string buffer;
	while (getline(ifs,buffer))
	{
		vector<string> keyPair = split(buffer, ":");
		if (keyPair[0] == "BatchSize(word)")
		{
			batchSize_Word = atoi(keyPair[1].c_str());
		}
		if (keyPair[0] == "BatchSize(sentence)")
		{
			batchSize_Sentence = atoi(keyPair[1].c_str());
		}
		if (keyPair[0] == "Master(word)")
		{
			master_Word = atoi(keyPair[1].c_str());
		}
		if (keyPair[0] == "Master(sentence)")
		{
			master_Sentence = atoi(keyPair[1].c_str());
		}
	}
	ifs.close();
}

vector<string> Word_Sentenceexercisetool::split(const string& str, const string& delim) 
{
	vector<string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型
		char * strs = new char[str.length() + 1]; //不要忘了
	strcpy(strs, str.c_str());

	char * d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char *p = strtok(strs, d);
	while (p) {
		string s = p; //分割得到的字符串转换为string类型
		res.push_back(s); //存入结果数组
		p = strtok(NULL, d);
	}
	delete strs;
	delete d;
	delete p;
	return res;
}

//slots:
void Word_Sentenceexercisetool::Back2Home()
{
	delete ui.mainWidget;
	ui.mainWidget = new Index_Menu(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
}

void Word_Sentenceexercisetool::goWordMission()
{
	delete ui.mainWidget;
	ui.mainWidget = new MissionPage(this, WORD_MODE);
	ui.verticalLayout->addWidget(ui.mainWidget);
}

void Word_Sentenceexercisetool::goSentenceMission()
{
	delete ui.mainWidget;
	ui.mainWidget = new MissionPage(this, SENTENCE_MODE);
	ui.verticalLayout->addWidget(ui.mainWidget);
}

void Word_Sentenceexercisetool::goSettingPage()
{
	delete ui.mainWidget;
	ui.mainWidget = new settingPage(this);
	ui.verticalLayout->addWidget(ui.mainWidget);
}

void Word_Sentenceexercisetool::goAddingPage()
{
	addingPage->show();
}

