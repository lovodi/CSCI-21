/*
 * PROGRAM pc1
 * Basic construction of main and strings, returning strings.
 *
 * Lovodi
 * Date created: 1/29/14
 * Last date modified: 1/29/14
 *
 * SOURCES USED
 *
 */
#include <cassert>
#include <iostream>
using namespace std;

string greet (string name);
string checkExperience (char hasExperience);

/* for unit testing -- do not alter */
template <typename X, typename A>
void btassert(A assertion);
void unittest (string s, char c);

int main (int argc, char* argv[])
{
	// CODE HERE
	string userName;
	char programmedBefore = 'z';
	cout << "Welcome to pc.1!" << endl;
	cout << "What is your name?" << endl;
	cin >> userName;
	cout << "Have you programmed in C++ before?" << endl;
	cin >> programmedBefore;
	
	unittest(userName, programmedBefore);
	
	return 0;
}

string greet (string name)
{
	string output = "Nice to meet you, " + name;
	return output;
}

string checkExperience (char hasExperience)
{
    string output;
	if(toupper(hasExperience) == 'Y')
	    output = "Welcome back";
	else
	    output = "Get ready to have some fun!";
	    
	return output;
}

/*
 * Unit test. Do not alter this function.
 */
void unittest (string s, char c)
{
	if (s == "fez")
	{
		cout << "\nSTARTING UNIT TEST\n\n";
		
		try {
			btassert<bool>(greet(s) == "Nice to meet you, fez");
			cout << "Passed TEST 1: greet\n";
		} catch (bool b) {
			cout << "# FAILED TEST 1 greet #\n";
		}
		
		if (toupper(c) == 'Y')
		{
			try {
				btassert<bool>(checkExperience(c) == "Welcome back");
				cout << "Passed TEST 2: checkExperience\n";
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
		else if (toupper(c) == 'N')
		{
			try {
				btassert<bool>(checkExperience(c) == "Get ready to have some fun");
				cout << "Passed TEST 2: checkExperience\n";
			} catch (bool b) {
				cout << "# FAILED TEST 2 checkExperience #\n";
			}
		}
		
		cout << "\nUNIT TEST COMPLETE\n\n";
	}
	else
	{
		cout << "\nRun program and enter the name \"fez\" to see unit test output.\n";
	}
}

template <typename X, typename A>
void btassert (A assertion)
{
    if (!assertion)
		throw X();
}

