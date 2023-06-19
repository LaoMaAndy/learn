/* heartbeat.cpp */
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

void heartbeat() 
{
	while (true) 
	{
		cout << steady_clock::now() << endl;
		this_thread::sleep_for(second{1});
	}
}

void run()
{
	thread t{heartbeat};
}

int main()
{
	run();

	return 0;
}


	
