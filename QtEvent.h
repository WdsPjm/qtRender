#ifndef _QT_EVENT_H_
#define _QT_EVENT_H_

#include<QEvent>
class QtEvent :public QEvent
{
public:
	enum QtEventType
	{
		GL_Render = QEvent::User + 1,
	};
	QtEvent(QtEventType type):QEvent(QEvent::Type(type)) {};
};

#endif // !_QT_EVENT_H_

