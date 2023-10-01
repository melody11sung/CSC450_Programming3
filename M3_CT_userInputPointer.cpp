/* A program that asks the user to enter 3 Integer values as input.
Store the values as 3 different variables.
For each variable, create an integer pointer to dynamic memory.
Display the contents of variables and pointers.*/

#include <iostream>
#include <string>

using namespace std;

// a method that tells if the user input is integer or not
bool is_int(string input){
    
    for (char c: input){
        if (!isdigit(c)){
            return false;
        }
    } return true;
}

int main(){

    string num1, num2, num3;

    // ask the user to enter three integer values
    cout << "<<< Enter 3 Integer alues >>>" << endl;
    do{ // ask the user to input num1
        cout << "num1: ";
        cin >> num1;
    } while (!is_int(num1)); // until it is a valid integer
    do{ // user input num2
        cout << "num2: ";
        cin >> num2;
    } while (!is_int(num2));
    do{ // user input num3
        cout << "num3: ";
        cin >> num3;
    } while (!is_int(num3));
    
    // create integer pointers to dynamic memory
    int* ptr1 = new int(stoi(num1)); // convert string to int
    int* ptr2 = new int(stoi(num2));
    int* ptr3 = new int(stoi(num3));

    // display the contents and addresses of variables and pointers
    cout << endl;
    cout << "<<< Display Variables >>>" << endl;
    cout << "num1: " << num1 << ", &num1: " << &num1 << endl;
    cout << "num2: " << num2 << ", &num2: " << &num2 << endl;
    cout << "num3: " << num3 << ", &num3: " << &num3 << endl;
    cout << "<<< Display Pointers >>>" << endl;
    cout << "*ptr1: " << *ptr1 << ", ptr1: " << ptr1 << endl;
    cout << "*ptr2: " << *ptr2 << ", ptr2: " << ptr2 << endl;
    cout << "*ptr3: " << *ptr3 << ", ptr3: " << ptr3 << endl;

    delete ptr1, ptr2, ptr3;

    return 0;
}