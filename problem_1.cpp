#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool pair_Compare(const pair<pair<int, int>, int> &a,
                         const pair<pair<int, int>, int> &b)
{
    if (a.first.second != b.first.second)
    {
        return a.first.second < b.first.second;
    }
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    vector<pair<pair<int, int>, int>> x;

    for (int i = 0; i < n; i++)
        x.push_back(make_pair(make_pair(start[i], end[i]), i + 1));

    sort(x.begin(), x.end(), pair_Compare);
    int last = -1;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (x[i].first.first > last)
        {
            res++;
            last = x[i].first.second;
        }
    }
    return res;
}

int main()
{
    int start_times[] = {1, 3, 0, 5, 8, 5};
    int end_times[] = {2, 4, 6, 7, 9, 9};
    int num_meetings = sizeof(start_times) / sizeof(start_times[0]);
    cout << "The maximum number of meetings that can be performed is: " << maxMeetings(start_times, end_times, num_meetings) << endl;
    return 0;
}
