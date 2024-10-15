#ifndef _THREAD_H
#define _THREAD_H

#include <pthread.h>

class Thread
{
	protected:
		pthread_t thread;
	public:
		virtual int startThread(void* d) = 0;
		pthread_t& getThreadReference()
                {
                        return thread;
                }
};

#endif
