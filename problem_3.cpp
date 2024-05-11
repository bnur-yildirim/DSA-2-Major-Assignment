#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

static bool comparison(Job first, Job second)
{
    return first.dead < second.dead;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<vector<int>> dp(n + 1, vector<int>(maxDeadline + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxDeadline; j++)
        {
            if (arr[i - 1].dead > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i - 1].dead] + arr[i - 1].profit);
            }
        }
    }

    int count = 0, maxProfit = dp[n][maxDeadline];
    vector<bool> selected(n + 1, false);
    for (int i = n; i > 0; i--)
    {
        if (dp[i][maxDeadline] != dp[i - 1][maxDeadline])
        {
            count++;
            selected[i] = true;
            maxDeadline -= arr[i - 1].dead;
        }
    }

    return {count, maxProfit};
}

int main()
{
    Job jobs[] = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    vector<int> result = JobScheduling(jobs, n);
    cout << "Maximum profit: " << result[1] << ", Number of jobs done: " << result[0] << endl;
    return 0;
}