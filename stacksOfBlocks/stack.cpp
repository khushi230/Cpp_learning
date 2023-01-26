#include <bits/stdc++.h>
using namespace std;
int len[20];
int bd[20];
int vis[20];
int n;
int ans = 0;

bool safe(int a, int b, int p, int q)
{
    if ((a >= p && b >= q) || (a >= q && b >= p))
        return true;
    return false;
}

void solve(int i, int h)
{
    if (h > ans)
    {
        ans = h;
    }

    int a = len[i];
    int b = bd[i];
    for (int k = 0; k < n; k++)
    {
        int p = len[k];
        int q = bd[k];
        if (!vis[k] && safe(a, b, p, q))
        {
            vis[k] = 1;
            solve(k, h + 1);
            vis[k] = 0;
        }
    }
    return;
}

int main(int argc, int **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> len[i];
            cin >> bd[i];
            vis[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                solve(i, 1);
                vis[i] = 0;
            }
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}