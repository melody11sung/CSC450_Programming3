/* Module 3 Pointers and Exception Control
Examples for Discussion Board */

#include <iostream>

using namespace std;

int main(){

    int x = 10;
    int *ptr = &x;
    cout << "*ptr is " << *ptr << endl;
    cout << "ptr is " << ptr << endl;

    int y = *ptr;
    cout << "y is " << y << endl;

    // dynamic memory allocation with user input size
    int size;
    cout << "Enter the size of the array ";
    cin >> size;

    // size does not have to be allocated during compile
    int *dynamicArr = new (nothrow) int[size]; // exception control
    if (dynamicArr == nullptr){
        cout << "Error: memory not allocated" << endl;
    }else{ // user inputs for the array contents
        for (int i=0; i<size; i++){
            cout << "Enter number: ";
            cin >> dynamicArr[i];
        }
        cout << "You have entered: "; // display contents
        for (int i=0; i<size; i++){
            cout << *(dynamicArr+i) << " ";
        }
    }
    
    // delete the pointer for memory management
    delete dynamicArr;
    
    return 0;
}