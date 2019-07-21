// Reed Posehn, 2017
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

// Print a debug line (to indicate whether a line is for testing purposes)
void debug(string testLine)
{
	cout << "Debug -- " + testLine << endl;
}

// Print a debug line (to indicate whether a line is for testing purposes)
void debug(int testInt)
{
        cout << "Debug -- " + to_string(testInt) << endl;
}
