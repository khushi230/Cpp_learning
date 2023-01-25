#include <iostream>
#define abc <bits/stdc++.h>
#include abc
using namespace std;
int n, m;
int ans = INT_MAX;
int countpaths = 0;
int xarr[] = {0 - 1, 0, 1};
int yarr[] = {-1, 0, 1, 0};

bool isValid(vector<vector<int>> &mat, vector<vector<int>> &visited, int i, int j)
{
    if (i > 0 && j > 0 && i < n && j < n && visited[i][j] == 0 && mat[i][j] != 9)
        return true;
    return false;
}

void solve(vector<vector<int>> &mat, vector<vector<int>> &visited, vector<int> &count, int currval, int nextval, int i, int j, int len)
{
    if (nextval == mat[i][j])
    {
        if (len < ans)
        {
            ans = len;
            countpaths = 1;
        }
        else if (len == ans)
        {
            countpaths++;
        }
        count[currval] = countpaths;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int nexti = i + xarr[k];
        int nextj = j + yarr[k];
        if (isValid(mat, visited, nexti, nextj))
        {
            visited[nexti][nextj] = 1;
            len++;
            solve(mat, visited, count, currval, nextval, nexti, nextj, len);
            len--;
            visited[nexti][nextj] = 0;
        }
    }
    return;
}

void func(vector<vector<int>> &mat, vector<int> &count, int m)
{
    int currval = 1;
    while (currval != m + 1)
    {
        ans = INT_MAX;
        countpaths = 0;
        int l = 0;
        int v = 0;
        int nextval = currval + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (currval == mat[i][j])
                {
                    l = i;
                    v = j;
                    break;
                }
            }
        }
        vector<vector<int>> visited(n, vector<int>(n, 0));
        solve(mat, visited, count, currval, nextval, l, v, 0);
        currval = nextval;
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
        n = 0, m = 0;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        vector<int> count(m + 1, 0);
        func(mat, count, m);
        int output = 1;
        for (int k = 1; k < m; k++)
        {
            output = output * count[k];
        }
        cout << output << endl;
    }
    return 0;
}
