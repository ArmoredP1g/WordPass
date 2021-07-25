#ifndef INDEX_MENU_H
#define INDEX_MENU_H
#include "Word_Sentenceexercisetool.h"
#include <QWidget>

namespace Ui {
class Index_Menu;
}

class Index_Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Index_Menu(Word_Sentenceexercisetool *parent = nullptr);
    ~Index_Menu();

private:
    Ui::Index_Menu *ui;
};

#endif // INDEX_MENU_H
