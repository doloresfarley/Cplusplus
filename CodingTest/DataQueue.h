#ifndef _DATAQUEUE_H
#define _DATAQUEUE_H
#include <pthread.h>
#include <queue>

class DataQueue
{
	private:
		pthread_mutex_t mutex;
    		pthread_cond_t condRead;
    		pthread_cond_t condWrite;
    		std::queue<std::string> queue;
    		int dataCount;
    		bool end;
		int size;

	public:
		DataQueue(int maxCount) : dataCount(0),end(false),size(maxCount)
		{
			pthread_mutex_init(&mutex, NULL);        
        		pthread_cond_init(&condRead, NULL);               
        		pthread_cond_init(&condWrite, NULL);       

		}
		~DataQueue()
		{
			pthread_mutex_destroy(&mutex);
  			pthread_cond_destroy(&condRead);
  			pthread_cond_destroy(&condWrite);
			
		}

		pthread_mutex_t& getMutex()
		{
			return mutex;
		}

		pthread_cond_t& getConditionalRead()
		{
			return condRead;
		}
		pthread_cond_t& getConditionalWrite()
		{
			return condWrite;
		}
		void push(std::string& str);
		std::string pop();
		bool isEmpty();
		bool isFull();
		bool isEnd()
		{
			return end;
		}
		void setEnd(bool b)
		{
			end=b;
		}

};
#endif
