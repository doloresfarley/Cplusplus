#ifndef _PRODUCER
#define _PRODUCER
#include <pthread.h>
#include "DataQueue.h"
#include "Thread.h"

struct ThreadArg
{
        char* fileName;
        DataQueue* queue;
};

class ProducerThread : public Thread
{
        public:
                ProducerThread(){}
		int startThread(void* d);
		static void* process(void* arg);
		static void produce(char* data,DataQueue* arg,bool end);

	private:
		static const int blockSize = 1024;
};

#endif
