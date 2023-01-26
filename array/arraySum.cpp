#include <iostream>
// #define abc <bits/stdc++.h>
// #include abc
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int sum = 0;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        sum = array[i] + sum;
    }
    cout << sum;
    return 0;
}
