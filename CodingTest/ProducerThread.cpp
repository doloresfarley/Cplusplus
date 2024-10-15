#include "ProducerThread.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
	Create And Start Thread with a Data Queue

*/
int ProducerThread::startThread(void* d)
{
	int iret1 = pthread_create( &thread, NULL, &ProducerThread::process, (void*)d);
        return iret1;
}

/*
		Thread processing method
		Read from the file as a block of 1024 bytes and push to the queue
		if the file end is reached,flag the queue to end processing

*/

void* ProducerThread::process(void* arg)
{
	ThreadArg* threadArg = static_cast<ThreadArg*>(arg);
	ifstream file(threadArg->fileName,ios::in|ios::binary);
        DataQueue* d = (DataQueue*)threadArg->queue;
        char buff[blockSize];
	
	if(file.is_open())
	{

        	file.seekg(0,ios::beg);
        	while( file.read(buff,blockSize))
        	{
        		produce(buff,d,false);
        	}
        	file.close();
	}
        strcpy(buff,"END");
        produce(buff,d,true);
	pthread_exit(0);
}

/*
	Produce method
	If the queue is full, wait for it to be emptied

*/


void ProducerThread::produce(char* data,DataQueue* d,bool end)
{
       	pthread_mutex_lock(&d->getMutex());
       	while(d->isFull())
		pthread_cond_wait(&d->getConditionalRead(),&d->getMutex());
	std::string str(data);
	d->push(str);
	d->setEnd(end);
	pthread_cond_signal(&d->getConditionalWrite());
        pthread_mutex_unlock(&d->getMutex());

}
