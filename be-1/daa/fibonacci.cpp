#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if(n == 0 || n == 1)
    return 1;

    return fibonacciRecursive(n-1)+fibonacciRecursive(n-2);
}

int fibonacciIterative(int n) {
    int x = 1, y = 1, z = 0;
    for(int i = 0; i < n; i++) {
        cout << x << " ";
        z = x + y;
        x = y;
        y = z;
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    cout << fibonacciRecursive(i) << " ";
    cout << endl;
    fibonacciIterative(n);
    return 0;
}
