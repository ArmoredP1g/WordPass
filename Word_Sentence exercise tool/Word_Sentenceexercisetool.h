#pragma once

#include <QtWidgets/QWidget>
#include "ui_Word_Sentenceexercisetool.h"
#include "FileLoader.h"

class Word_Sentenceexercisetool : public QWidget
{
    Q_OBJECT

public:
    Word_Sentenceexercisetool(QWidget *parent = Q_NULLPTR);

private:
    Ui::Word_SentenceexercisetoolClass ui;
private slots:
	void Back2Home();
};
