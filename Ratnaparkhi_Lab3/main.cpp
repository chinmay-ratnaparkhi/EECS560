#include <iostream>
#include <fstream>
#include "hashtable.cpp"
using namespace std;

int main()
{
	
	ifstream data_input;
	data_input.open("data.txt");
	if(!data_input)
	{
		cout << "Unable to open 'data.txt'. Check the file location and try again."<< endl;
		return(-1);
	}

	int file_data;
	data_input >> file_data;
	hashtable* values= new hashtable(file_data);
	while(data_input >> file_data)
	{
		values->insert(file_data);
	}
	

	int choice= 0;
	while (choice != 4)
	{
		cout << "\n	.......................................................... " << endl;
		cout << "Please choose one of the following commands:" << endl;
		cout << "1- insert \n2- delete \n3- print \n4- exit \n" << endl;
		cin >> choice;
		
		if(choice == 1)
		{
			cout << "Choose a number to be inserted to the list:" << endl;
			int user_in;
			cin >> user_in;
			cout << "	.......................................................... " << endl;
			values->insert(user_in);
		}
		else if(choice == 2)
		{
			cout << "Choose a number to be deleted from the list:" << endl;
			int user_in;
			cin >> user_in;
			cout << "	.......................................................... " << endl;
			values->remove(user_in);
		}		
		else if(choice == 3)
		{
			cout << "	.......................................................... " << endl;
			cout << "Hashtable : \n" << endl;
			values->print();
			cout << "	.......................................................... " << endl;
		}
		else if(choice == 4)
		{
			// exit!
		}
		else
			{
				cout << "	.......................................................... " << endl;
			 	cout << "Invalid Entry. Try again. " << endl;
			}		
	}
return 0;
}
