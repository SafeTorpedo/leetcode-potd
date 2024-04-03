#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (backtrack(board, word, i, j, m, n, 0))
                        return true;
                }
            }
        }

        return false;
    }

private:
    bool backtrack(vector<vector<char>> &board, string &word, int i, int j, int m, int n, int index)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
            return false;

        if (index == word.size() - 1)
            return true;

        board[i][j] = '#';

        if (backtrack(board, word, i - 1, j, m, n, index + 1) || backtrack(board, word, i + 1, j, m, n, index + 1) || backtrack(board, word, i, j - 1, m, n, index + 1) || backtrack(board, word, i, j + 1, m, n, index + 1))
            return true;

        board[i][j] = word[index];

        return false;
    }
};