// Module 2 discussion board examples of Buffer Overflow

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // buffer overflow

    char firstname[10] = ""; // it only allows 10 letters.
    cout << "Hi! What is your first name? ";
    cin >> firstname;
    
    char lastname[10] ; // last name allows 10 letters.
    cout << "What is your last name? ";
    cin >> lastname;

    // Print out the saved inputs
    cout << "First name: " << firstname << ", Last name: " << lastname << endl;

    // format string vulnerability
    int age = 30;
    printf("%s%s%d");

    return 0;

}
