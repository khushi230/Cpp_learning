#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
    int temp = 0;
    int temp2 = 1;

    for (int i = 0; i < n; i++)
    {
        arr[i] = 2 * i + 1;

        if (arr[i] > n)
        {
            if (n % 2 == 0)
            {
                arr[i] = n - temp;
                temp += 2;
            }
            else
            {
                arr[i] = n - temp2;
                temp2 += 2;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        arrange(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
}