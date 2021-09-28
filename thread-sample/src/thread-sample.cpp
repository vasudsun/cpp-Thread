//============================================================================
// Name        : thread-sample.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<thread>
#include<chrono>
#include<mutex>
using namespace std;



int main() {

int count=0;
const int ITERATIONS=10;
mutex mtx;

auto func=[&](){

for(int i=0; i<ITERATIONS;i++)
{

mtx.lock();
++count;
cout<<count<<endl;
mtx.unlock();
}

};

	thread t1(func);
	thread t2(func);
	t1.join();
	t2.join();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
