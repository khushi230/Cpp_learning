#include <iostream>
#define abc <bits/stdc++.h>
#include abc
using namespace std;
int n, m;
int ans = INT_MAX;
int countpaths = 0;
int xarr[] = {0, -1, 0, 1};
int yarr[] = {-1, 0, 1, 0};

bool isValid(vector<vector<int>> &mat, vector<vector<int>> &visited, int nexti, int nextj)
{
    if (nexti > 0 && nextj > 0 && nexti < n && nextj < n && mat[nexti][nextj] != 9 && visited[nexti][nextj] == 0)
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
        int nexti = i + xarr;
        int nextj = j + yarr;
        if (isValid(mat, visited, nexti, nextj))
        {
            visited[nexti][nexti] = 1;
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
    int T;
    cin >> T;
    for (int test_case = 0; test_case < T; test_case++)
    {
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
            output = output * mat[k];
        }
    }
    return 0;
}
