#ifndef INDEX_MENU_H
#define INDEX_MENU_H

#include <QWidget>

namespace Ui {
class Index_Menu;
}

class Index_Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Index_Menu(QWidget *parent = nullptr);
    ~Index_Menu();

private:
    Ui::Index_Menu *ui;
};

#endif // INDEX_MENU_H
