#include <iostream>
using namespace std;

bool checkMember(int n)
{
    int prev = 0;
    int next = 1;
    int temp;
    if (n == 0 || n == 1)
        return true;
    while (next < n)
    {
        temp = prev + next;
        prev = next;
        next = temp;
        if (n == next)
            return true;
    }
    return false;
}

int main()
{

    int n;
    cin >> n;
    if (checkMember(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
