//============================================================================
// Name        : Thread-Condition-variable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<thread>
#include<condition_variable>
#include<chrono>
using namespace std;









int main() {


	condition_variable condition;

	mutex mtx;

	bool ready = false;


	thread t1([&](){
		this_thread::sleep_for(chrono::milliseconds(2000));
		unique_lock<mutex>lock(mtx);
		ready=true;
		lock.unlock();
		condition.notify_one();

	});



unique_lock<mutex>lock(mtx);//both unique_lock with same mutex
while(!ready)
	{

condition.wait(lock);


	}

cout<<"ready"<<ready<<endl;

t1.join();

	return 0;
}




/*
 *
 *
 * Here when the control comes to the main thread at line#45, it will get the lock and get it locked for the
 * first time.
 *
 * when it calls the wiat(), it releases the lock so that local is available for the thread function.
 *
 * when the thread function returns, then we have to check the condition what we were waiting for.
 *
 * In this case when ready boolean is set, it will come out of the while loop.
 *
 * when the wait returns, the waiting thread re-acquires the lock
 *
 *
 *
 *
 *
 *
 */


