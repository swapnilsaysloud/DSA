#include <bits/stdc++.h>
using namespace std;
bool checkRepeat(vector<char> a)
{
    unordered_map<char, int> mp;
    for (auto x : a)
    {
        if (x > 57 || x < 49)
            return false;
        if (x != '.')
            mp[x]++;
        if (mp[x] > 1)
            return false;
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    // Rows checked
    for (int i = 0; i < 9; i++)
    {
        bool t = checkRepeat(board[i]);
        if (t == false)
            return false;
    }
    // Column checked
    for (int i = 0; i < 9; i++)
    {
        vector<char> test;
        for (int j = 0; j < 9; j++)
        {

            test.push_back(board[j][i]);
        }
        bool t = checkRepeat(test);
        if (t == false)
            return false;
    }
    // 3*3 check
    map<pair<int, int>, set<int>> mp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                if (board[i][j] > 57 || board[i][j] < 49)
                    return false;
                if (mp[{i / 3, j / 3}].count(board[i][j]) > 0)
                    return false;
                else
                    mp[{i / 3, j / 3}].insert(board[i][j]);
            }
        }
    }
    return true;
}
bool isValidSudokuShort(vector<vector<char>> &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

    for (int i = 0; i < board.size(); ++i)
    // i -> Row number
        for (int j = 0; j < board[i].size(); ++j)
        // j -> Column number
            if (board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if (used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }

    return true;
}
int main()
{

    return 0;
}