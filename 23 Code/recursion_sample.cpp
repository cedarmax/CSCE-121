#include <iostream>
using namespace std;

void myFunction( int counter) {
    if(counter == 0)
        return;
    else {
        cout << counter << endl;
        myFunction(--counter);
        return;
    }
}

int main() {
    myFunction(10);
}