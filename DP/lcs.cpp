#include <bits/stdc++.h>
using namespace std;

void lcs(char *
             a,
         char *b, int m, int n)
{
    vector<char> visited = {0};
    int k = 0;
    int l[m + 1][n + 1] = {0};
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                l[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                l[i][j] = l[i - 1][j - 1] + 1;
            }
            else
            {
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
    }
    int index = l[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (l[i - 1][j] > l[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << lcs;
}

int main()
{
    char a[] = "bandar";
    char b[] = "panda";
    int m = strlen(a);
    int n = strlen(b);
    lcs(a, b, m, n);
    return 0;
}