#include "index_menu.h"
#include "ui_index_menu.h"

//实现子窗口直接给父窗口传信号，只需把构造函数的参数类型改成父类，继承依旧继承QWidget即可
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
