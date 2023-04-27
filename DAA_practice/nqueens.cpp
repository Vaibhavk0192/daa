#include <bits/stdc++.h>
using namespace std;

void printBoard(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j]<<" ";
        }
        cout << endl;
    }
}

bool canPlace(int n, int board[][20], int row, int col)
{
    //checking row on left side
    for (int i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }

    // checking upper diagonal on left side
    for (int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
            return false;
    }

    //cheking lower diagonal on left side
    for (int i=row,j=col;j>=0 && i<n;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}

bool solveQueens(int n, int board[][20], int col)
{
    if (col == n)
    {
        printBoard(n, board);
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (canPlace(n, board, i, col))
        {
            board[i][col] = 1;
            if(solveQueens(n, board, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
int main()
{
    int board[20][20] = {0};
    int n;
    cout << "enter number of queens";
    cin >> n;
    solveQueens(n, board, 0);
    return 0;
}