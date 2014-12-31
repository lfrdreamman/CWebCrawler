/*
 * DocQueue.cpp
 *
 *  Created on: 2014年12月28日
 *      Author: lfr
 */

#include "DocQueue.h"

DocQueue::DocQueue() {
	// TODO Auto-generated constructor stub

}

DocQueue::~DocQueue() {
	// TODO Auto-generated destructor stub
}

void DocQueue::insert_queue(Document *s)
{
	mutex_.acquire();
	_dq.push(s);
	mutex_.release();
}
Document* DocQueue::pop_queue()
{
	Document* a = NULL;
	mutex_.acquire();
	if(isEmpty() == false)
	{
		a = _dq.front();
		_dq.pop();
	}
	mutex_.release();
	return a;
}

bool DocQueue::isEmpty()
{
	mutex_.acquire();
	bool a = _dq.empty();
	mutex_.release();
	return a;
}

void DocQueue::call(string/*插件方法名*/ a,void *b,void *c,void *d,void* e,void *f,unsigned long &retvaladdr/*函数返回值*/)
{
	if(a == string("insert_queue"))
	{
		insert_queue((Document*)b);
	}
	else if(a == string("pop_queue"))
	{
		retvaladdr = (unsigned long)pop_queue();
	}
	else if(a == string("isEmpty"))
	{
		bool bb = isEmpty();
		retvaladdr = (unsigned long)&bb;
	}
}