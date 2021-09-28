//============================================================================
// Name        : Thread-Blocking-Queue.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



/****
 *
 * FIFO queue
 * here one thread add(producer) items to the Queue. Another thread(consumer) takes off
 * the items from the queue
 *
 *whenever we are trying to retrieve the items from the queue we should check the queue is empty.
 *whenever if it is empty, then we should wait till the items are added onto the queue.
 *
 *
 *Producer thread:: When Producer thread  adding items to the queue, they have to check the maximum size the queue can bear.
 *
 *
 *Thread safety for a function: That function is safe for using from multiple threads
 */



#include <iostream>
#include<thread>
using namespace std;


template<typename E>
class blocking_queue
{
public:

	void push(E e)
	{

		cout<<"Pusing the item"<<endl;
	}


void pop()
{


	cout<<"poping the item"<<endl;

}


};








int main() {

	blocking_queue<int>qu;

	thread t1(&blocking_queue<int>::push,&qu,7);

	thread t2(&blocking_queue<int>::pop,&qu);







	return 0;
}
