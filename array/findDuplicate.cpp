#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count != 1)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << duplicateNumber(input, size) << endl;
    }

    return 0;
}