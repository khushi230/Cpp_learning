#include <iostream>
using namespace std;

void printTable(int start, int end, int step)
{

    for (int i = start; i <= end; i = i + step)
    {
        int celcius = (i - 32) * 5 / 9;

        cout << i << "  " << celcius << endl;
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;

    printTable(start, end, step);
}
