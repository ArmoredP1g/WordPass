#ifndef ADDINGPAGE_H
#define ADDINGPAGE_H

#include <QWidget>
#include "FileLoader.h"

namespace Ui {
class AddingPage;
}

class AddingPage : public QWidget
{
    Q_OBJECT

public:
    explicit AddingPage(QWidget *parent = nullptr);
	void setFileLoader(FileLoader * loader);
    ~AddingPage();

private:
    Ui::AddingPage *ui;
	FileLoader * fileLoader;
	Qt::WindowFlags windowAttrFlag;//窗口状态标志位
	void addItem();
};

#endif // ADDINGPAGE_H
