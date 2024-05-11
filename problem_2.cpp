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
    return first.profit > second.profit;
}

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].dead);
    }

    vector<bool> slot(maxDeadline, false);
    int count = 0, maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(maxDeadline - 1, arr[i].dead - 1); j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                count++;
                maxProfit += arr[i].profit;
                break;
            }
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
