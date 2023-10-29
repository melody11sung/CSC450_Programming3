#include <iostream>
#include <thread>

using namespace std;

/* This Portfolio project for CSC450 Programming 3 is to create a C++ application
 * that exhibit concurrency concepts. Two threads will act as counters.
 * Once a thread counts up to 20, a second thread counts down to 0.
 */

int result = 0;
mutex count_mutex;

void counter_add(){ // a method that counts up to 20
    // lock the thread
    lock_guard <mutex> lock(count_mutex);
    // count up to 20
    for (int i=0; i<20; i++){
        result += 1;
        cout << "Count up: " << result << endl; // show the process
    }
    cout << "<< After counter_add >> Count: " << result << "\n\n"; // print result
}

void counter_sub(){ // a method that counts down to 0
    // until counter_add work ends and result becomes 20, yield
    while (result < 20){
        this_thread::yield();
    }
    // lock the thread
    lock_guard <mutex> lock(count_mutex);
    // count down to 0
    for (int i=0; i<20; i++){
        result -=1;
        cout << "Count down: " << result << endl; // show the process
    }
    cout << "<< After counter_sub >> Count: " << result << "\n\n"; // print result
}

int main(){

    cout << "<< Default Count >> " << result << "\n\n";

    thread t1(counter_add); // thread 1 counts up to 20
    thread t2(counter_sub); // thread 2 counts down to 0

    t1.join();
    t2.join();

    return 0;
}
