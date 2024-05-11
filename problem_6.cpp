#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> paths;
vector<vector<bool>> isVisited;

void findPath(vector<vector<int>> &matrix, int x, int y, string direction, int size)
{
    if (x == size - 1 and y == size - 1)
    {
        paths.push_back(direction);
        return;
    }

    if (matrix[x][y] == 0 or isVisited[x][y] == 1)
        return;

    isVisited[x][y] = 1;

    if (x > 0)
        findPath(matrix, x - 1, y, direction + 'U', size);
    if (y > 0)
        findPath(matrix, x, y - 1, direction + 'L', size);
    if (x < size - 1)
        findPath(matrix, x + 1, y, direction + 'D', size);
    if (y < size - 1)
        findPath(matrix, x, y + 1, direction + 'R', size);

    isVisited[x][y] = 0;
}

vector<string> explorePaths(vector<vector<int>> &matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        isVisited.push_back(vector<bool>(size, false));
    }

    paths.clear();

    if (matrix[0][0] == 0 || matrix[size - 1][size - 1] == 0)
        return paths;

    findPath(matrix, 0, 0, "", size);

    sort(paths.begin(), paths.end());

    return paths;
}

int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int size = maze.size();
    vector<string> paths = explorePaths(maze, size);
    for (const auto &path : paths)
    {
        cout << path << endl;
    }
    return 0;
}
