/*
 * simplegame.cxx
 * 
 * Copyright 2013 googcheng <googcheng@gmail.com>
 * 
 * For SIT, it obeys "copyright reserved".
 * 
 * 
 */


using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

int main()
{
	/* initialize random seed: */
	srand (time(NULL));
	
	int v1 = rand() % 100 +1;
	int guess;
	cout << "please input a number" << endl;
	while(1)
	{

		if (!(cin >> guess))
		{
			cout << "Please enter only numbers" << endl;
		}
		
		else
		{ 
			if(guess > v1)
				cout << "The guessed number is bigger." << endl<<endl;
			else if(guess < v1 )
					cout << "guess is smaller " << endl<<endl;
				else
					{
						cout << "you are clever, congratulations." << endl;
						cout << "the random is " << v1 << endl;
						break;
					}
		}
	}

	return 0;
}

