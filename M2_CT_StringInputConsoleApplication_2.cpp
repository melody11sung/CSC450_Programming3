// practice 2 to try string, instead of char[]

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