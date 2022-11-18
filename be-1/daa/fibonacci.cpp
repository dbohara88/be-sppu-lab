#include <iostream>
using namespace std;

int fib_recursive(int n) {
    if(n == 1 || n == 0) 
    return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}  

int fib_iterative(int n) {
    int x = 0, y = 1, z = 0;
    for(int i=0; i<n; i++) {
        cout << x <<" ";
        z = x + y;
        x = y;
        y = z;
    }
}

int main()
{
    int n;
    cin >> n;

    //fibonacci using recursion 
    // Time Complexity O(2^N)
    for(int i=0; i<n; i++) 
    cout << fib_recursive(i) << " ";
    cout << endl;

    //fibonacci using iterative
    // Time Complexity O(N)
    fib_iterative(n);

    return 0;
}