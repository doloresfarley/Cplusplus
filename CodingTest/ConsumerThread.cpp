#include "ConsumerThread.h"
#include <iostream>

using namespace std;

/*
	Create and Start Threads

*/
int ConsumerThread::startThread(void* d)
{
        int iret1 = pthread_create( &thread, NULL, &ConsumerThread::process, (void*)d);
        return iret1;
}

/*
	Thread Processing method
	if queue is empty, wait for it to be full
	read from the queue and display standard output

*/

void* ConsumerThread::process(void* arg)
{
        bool end = false;
        DataQueue *d = static_cast<DataQueue*>(arg);
        while(!end)
        {
                pthread_mutex_lock(&d->getMutex());
                while(d->isEmpty())
                {
                        pthread_cond_wait(&d->getConditionalWrite(),&d->getMutex());


                }
                end = d->isEnd();
                std::string str = d->pop();
                cout << str.data() << endl;
                pthread_cond_signal(&d->getConditionalRead());
                pthread_mutex_unlock(&d->getMutex());

        }
        pthread_exit(0);
}
