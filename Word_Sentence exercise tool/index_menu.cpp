#include "index_menu.h"
#include "ui_index_menu.h"

//ʵ���Ӵ���ֱ�Ӹ������ڴ��źţ�ֻ��ѹ��캯���Ĳ������͸ĳɸ��࣬�̳����ɼ̳�QWidget����
Index_Menu::Index_Menu(Word_Sentenceexercisetool *parent) :
	QWidget(parent),
    ui(new Ui::Index_Menu)
{
    ui->setupUi(this);
	connect(ui->tb_goWord, &QToolButton::clicked, parent, &Word_Sentenceexercisetool::goWordMission);
	connect(ui->tb_goSentence, &QToolButton::clicked, parent, &Word_Sentenceexercisetool::goSentenceMission);
	connect(ui->tb_Setting, &QToolButton::clicked, parent, &Word_Sentenceexercisetool::goSettingPage);
	connect(ui->tb_LibManage, &QToolButton::clicked, parent, &Word_Sentenceexercisetool::goVocabPage);
}

Index_Menu::~Index_Menu()
{
    delete ui;
}
