#include "DataQueue.h"

void DataQueue::push(std::string& str)
{
	queue.push(str);
	dataCount++;
}

std::string DataQueue::pop()
{
	std::string str = queue.front();
	queue.pop();
	dataCount--;
	return str;
}

bool DataQueue::isEmpty()
{
	return (queue.empty() && dataCount <= 0);
}
bool DataQueue::isFull()
{
	return ( (!queue.empty()) && dataCount >= size);
}
