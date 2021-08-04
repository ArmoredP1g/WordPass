#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QWidget>
class Word_Sentenceexercisetool;

namespace Ui {
class settingPage;
}

typedef struct {


}Configs;

class settingPage : public QWidget
{
    Q_OBJECT

public:
    explicit settingPage(QWidget *parent = nullptr);
    ~settingPage();

private:
    Ui::settingPage *ui;
	Word_Sentenceexercisetool * parent;
	void setLanguage_en();
	void setLanguage_jp();

	void LoadConfig();
	void ConfirmSettigs();
};

#endif // SETTINGPAGE_H
