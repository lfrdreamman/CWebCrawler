/*
 * DocQueue.h
 *
 *  Created on: 2014年12月28日
 *      Author: lfr
 */

#ifndef DOCQUEUE_H_
#define DOCQUEUE_H_

#include <string>
#include <iostream>
#include <queue>
#include "MessageComponent.h"
#include "ace/Synch.h"
#include "ace/Recursive_Thread_Mutex.h"

using namespace std;
class Document;
class DocQueue : public MessageComponent{
public:
	DocQueue(string n);
	virtual ~DocQueue();
private:
	ACE_Recursive_Thread_Mutex mutex_;
	queue<Document*> _dq;

	Document *pop_queue();
	void insert_queue(Document *s);
	bool isEmpty();
	string name;

public:
	virtual void call(string/*插件方法名*/,void *,void*,void *,void*,void *,void *,void**/*函数返回值*/);
};

#endif /* DOCQUEUE_H_ */
