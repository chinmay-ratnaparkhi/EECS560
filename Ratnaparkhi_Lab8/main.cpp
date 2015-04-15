#include <iostream>
#include <math.h>
#include "./Leftist/leftistHeap.h"
#include "./Skew/skewHeap.h"
#include "Timer.cpp"
#include "./Leftist/leftistQ.h"
#include "./Skew/skewQ.h"

using namespace std;

int main(int argc, char* argv[])
{
	Timer timer; 

	leftistHeap* left = new leftistHeap();
	skewHeap* skew = new skewHeap();

	int n = 50000;

	double leftistHeap_time_records[4][5];
	double skewHeap_time_records[4][5];

	for(int i = 0; i < 4; i++)
	{
		cout << "Insertion : " << n << ".\n";
		for(int j = 0; j < 5; j++) {
			
			srand(j);
			int rand_values[n];

			for(int k = 0; k < n; k++)
			{
				rand_values[k] = rand();
			}

			delete left;
			left = new leftistHeap();
			
			//**************** TIMER STARTS ***********************************
			timer.start();
			
			for(int k = 0; k< n; k++)
			{
				left->insert(rand_values[k]);
			}
		
			leftistHeap_time_records[i][j] = timer.stop();
			
			//**************** TIMER STOPS ***********************************

			cout << "Leftist : Insertion complete. Time taken = " << leftistHeap_time_records[i][j] << endl;



			delete skew;
			skew = new skewHeap();
			
			//**************** TIMER STARTS ***********************************
			timer.start();
			for(int k = 0; k < n; k++)
			{
				skew->insert(rand_values[k]);
			}

			skewHeap_time_records[i][j] = timer.stop();

			//**************** TIMER STOPS ***********************************


			cout << "Skew : Insertion complete. Time taken = " << skewHeap_time_records[i][j] << endl;

		}
		n = 2*n;
	}



	cout << "\n\n***************************************\n";
	int tmp = 50000;
	
	for(int i = 0; i < 4; i++)
	{
		double leftistHeap_avergae_time = 0;
		double skewHeap_average_time = 0;
		
		for (int j = 0; j < 5; j++)
		{
			leftistHeap_avergae_time += leftistHeap_time_records[i][j];
			skewHeap_average_time += skewHeap_time_records[i][j];
		}

		cout << "Number of records : " << tmp << endl;
		cout << "Average time (Leftist) : " << leftistHeap_avergae_time/5 << endl;
		cout << "Average time (Skew Hp) : " << skewHeap_average_time/5 << endl;
		tmp = tmp * 2;
	}

	
	cout << "\n\n***************************************\n";
	
	
	n = 50000;
	srand(1);
	float test = 0.8;
	float values[n/10];
	double left_total_time = 0;
	double skew_total_time = 0;

	for(int i = 0; i < 5; i++)
	{

		int rand_values[n];
		for(int k = 0; k < n; k++)
		{
			rand_values[k] = rand();
		}

		delete left;
		left = new leftistHeap();
		for(int k = 0; k < n; k++)
		{
			left->insert(rand_values[k]);
		}

		delete skew;
		skew = new skewHeap();
		for(int k = 0; k < n; k++)
		{
			skew->insert(rand_values[k]);
		}

		for(int k = 0; k < n/10; k++)
		{
			values[k] = rand() % 2;
		}

		//**************** TIMER STARTS ***********************************
		timer.start();
		for (int j = 0; j < n/10; j++)
		{
			if (values[j] == 1) 
			{
				left->deletemin();
			}
			else 
			{
				left->insert(rand());
			}
		}
		//**************** TIMER STOPS ***********************************
		double cur_time = timer.stop();
		left_total_time += cur_time;
		cout << "Leftist completed at : " << cur_time << endl;




		//**************** TIMER STARTS ***********************************
		timer.start();
		for (int j = 0; j < n/10; j++) 
		{
			if (values[j] == 1) 
			{
				skew->deletemin();
			} 
			else 
			{
				skew->insert(rand());
			}
		}
		//**************** TIMER STOPS ***********************************
		cur_time = timer.stop();
		skew_total_time += cur_time;
		cout << "Skew completed at: " << cur_time << endl;
	}

	cout << "Leftist heap : Average operation time : " << left_total_time/5 << endl;
	cout << "Skew heap : Average operation time : " << skew_total_time/5 << endl;
}