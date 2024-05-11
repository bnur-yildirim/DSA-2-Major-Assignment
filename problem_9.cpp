#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfs(vector<vector<char>> &board, string &s, int i, int j, int n, int m, int idx)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }

    if (s[idx] != board[i][j])
    {
        return false;
    }
    if (idx == s.size() - 1)
    {
        return true;
    }

    char temp = board[i][j];
    board[i][j] = '*';

    bool a = dfs(board, s, i, j + 1, n, m, idx + 1);
    bool b = dfs(board, s, i, j - 1, n, m, idx + 1);
    bool c = dfs(board, s, i + 1, j, n, m, idx + 1);
    bool d = dfs(board, s, i - 1, j, n, m, idx + 1);
    bool e = dfs(board, s, i + 1, j + 1, n, m, idx + 1);
    bool f = dfs(board, s, i - 1, j + 1, n, m, idx + 1);
    bool g = dfs(board, s, i + 1, j - 1, n, m, idx + 1);
    bool h = dfs(board, s, i - 1, j - 1, n, m, idx + 1);

    board[i][j] = temp;
    return a || b || c || e || f || g || h || d;
}

void wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{
    int n = board.size();
    int m = board[0].size();
    set<string> store;
    for (int i = 0; i < dictionary.size(); i++)
    {
        string s = dictionary[i];
        int l = s.size();
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dfs(board, s, j, k, n, m, 0))
                {
                    store.insert(s);
                }
            }
        }
    }

    for (auto i : store)
    {
        cout << i << "\n";
    }

    return;
}

int main()
{
    vector<vector<char>> boggle{{'G', 'I', 'Z'},
                                {'U', 'E', 'K'},
                                {'Q', 'S', 'E'}};
    vector<string> dictionary{"GEEKS", "FOR", "QUIZ", "GO"};

    cout << "Following words of dictionary are present\n";
    wordBoggle(boggle, dictionary);
    return 0;
}
