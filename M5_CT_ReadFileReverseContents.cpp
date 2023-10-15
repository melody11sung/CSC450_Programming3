#include <iostream>
#include <fstream>
using namespace std;

// a reversal method that will reverse all the characters in the input file,
// and save it as another file as specified 'outFileName'.
void reverseFileContents(const string& inFileName, const string& outFileName){

    ifstream inFile(inFileName); // input file with original contents
    ofstream outFile(outFileName); // output file with reversed contents

    if (!inFile.is_open()){ // if input file is unable to open,
        cout << "Error: Unable to open the input file." << endl;
        return;
    } if (!outFile.is_open()){ // if output file is unable to open,
        cout << "Error: Unable to open the output file." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)){ // for each and every lines of the file,
        reverse(line.begin(), line.end()); // reverse it all
        outFile << line << endl; // and write it to the output file.
    }

    // Let the user know the process was successful.
    cout << "File contents successfully reversed and saved to: " << outFileName << endl;
    inFile.close();
    outFile.close();
}


int main(){

    // 1. Getting the User Input
    string user_input;
    cout << endl << "========= Welcome to File System! =========" << endl;
    cout << "Type in the contents you want to add to the file." << endl;
    getline(cin, user_input);

    // 2. Open the file, and write the User Input
    fstream myFile;

    try { // try to open the file, and write
        myFile.open("CSC450_CT5_mod5.txt", ios::app);
        
        if (myFile.is_open()){ // if file opens, write
            myFile << user_input << endl;
            cout << endl;
            cout << "You entered: " << user_input << endl;
            cout << "Writing to the file... " << endl;
            myFile.close();
        } else { // if failed to write, throw an error
            cout << "Failed to write in the file." << endl;
            throw ("Error");
        }
    } catch (...) { // catch error and send the message
        cout << "!! Failed to open the file !!" << endl;
    }

    // 3. Open the file, reverse characters, and save it as another file
    cout << endl << "Reversing the contents... " << endl;
    reverseFileContents("CSC450_CT5_mod5.txt", "CSC450_mod5_reverse.txt");

    return 0;
}

