#include <iostream>
#include <fstream>
#include <pthread.h>
#include <queue>
#include "DataQueue.h"
#include "ProducerThread.h"
#include "ConsumerThread.h"

using namespace std;

void* consumer(void* arg);

void printUsage();

int main(int argc, char* argv[])
{

	if(argc < 2)
	{
		printUsage();
		return 0;
	}
	// Create a DataQueue
	// max size of queue - 3
	DataQueue* d = new DataQueue(3);

	ThreadArg arg;
	arg.queue = d;
	arg.fileName = argv[1];

	// Create Producer and Consumer Threads
	ProducerThread producer;
	ConsumerThread consumer;
	
	// create and start threads

	int iret1 = producer.startThread((void*)&arg);
	int iret2 = consumer.startThread((void*)d);
     	if(iret1)
     	{
		std::cout << "pthread producer thread creation failure" << std::endl;
     	}
     	if(iret2)
     	{
		std::cout << "pthread consumer thread creation failure" << std::endl;
     	}
	// join for threads to finish
	pthread_join( producer.getThreadReference(), NULL);
	pthread_join( consumer.getThreadReference(), NULL);

	delete d;
	std::cout << "done" << std::endl;
}

void printUsage()
{
	cout << "USAGE: " << endl;
	cout << "<ProgramName> <filename>" << endl;
}
