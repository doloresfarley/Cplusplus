#ifndef _CONSUMER
#define _CONSUMER

#include <pthread.h>
#include "DataQueue.h"
#include "Thread.h"

class ConsumerThread : public Thread
{
	public:
		ConsumerThread() {}
		int startThread(void* d);
		static void* process(void* arg);
};

#endif
