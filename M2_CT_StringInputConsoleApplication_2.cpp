/* A simple console application that will take 2 string inputs from an user.
Concatenate the two string inputs and print the resulting output to the screen.
Take the two string inputs from the user 3 times for varying lengths. */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){

    string str1="", str2=""; // dynamic size

    for (int i=1; i<4; i++){

        cout << endl;
        printf("<<< Round %d >>>\n", i);
        
        cout << "What's your 1st item? ";
        getline(cin, str1); // getline enables to take blank inputs

        cout << "What's your 2nd item? ";
        getline(cin, str2);

        string res = str1 + " " + str2;
        // str1.append(str2);
        
        cout << "Concatenated Output: " << res << endl;
    
    }

    return 0;
}
