#pragma once
#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QMouseEvent>

class TitleBar : public QWidget
{
public:
     TitleBar(QWidget *parent = 0);

protected:
     virtual void mousePressEvent(QMouseEvent* event);
     virtual void mouseMoveEvent(QMouseEvent* event);
     virtual void mouseReleaseEvent(QMouseEvent* event);

 private:
     bool            m_isPressed;
     QPoint          m_startMovePos;
};

#endif // FRAMETITLEBAR_H