#include "TitleBar.h"

TitleBar::TitleBar(QWidget *parent) :
	QWidget(parent),
	m_isPressed(false)
{

}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
	m_isPressed = true;
	m_startMovePos = event->globalPos();

	return QWidget::mousePressEvent(event);
}

void TitleBar::mouseMoveEvent(QMouseEvent* event)
{
	if (m_isPressed)
	{
		QPoint movePoint = event->globalPos() - m_startMovePos;

		if (parentWidget())
		{
			QPoint widgetPos = this->parentWidget()->pos();
			m_startMovePos = event->globalPos();
			parentWidget()->move(widgetPos.x() + movePoint.x(), widgetPos.y() + movePoint.y());
		}
	}

	return QWidget::mouseMoveEvent(event);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
	m_isPressed = false;

	return QWidget::mouseReleaseEvent(event);
}