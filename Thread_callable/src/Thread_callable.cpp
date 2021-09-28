//============================================================================
// Name        : Thread_callable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<thread>
#include<mutex>
using namespace std;


class Application
{
private:
	mutex mtx;
	int count=0;
public:


	void operator()()
	{
		for(int i=0;i<20;i++)
		{
			lock_guard<mutex>guard(mtx);
			++count;
		}

	}


	int getcount()
	{

		return count;
	}
};

int main() {


	Application app;

	thread t1(ref(app));
		thread t2(ref(app));
		t1.join();
		t2.join();

		cout<<app.getcount()<<endl;


	return 0;
}
