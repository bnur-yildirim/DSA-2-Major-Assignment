#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair
{
    int start;
    int end;
};

bool comparePairs(const Pair &x, const Pair &y)
{
    return x.end < y.end;
}

int maxChainLen(vector<Pair> &pairs)
{
    sort(pairs.begin(), pairs.end(), comparePairs);

    vector<int> dp(pairs.size(), 1);

    for (int i = 1; i < pairs.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (pairs[i].start > pairs[j].end && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<Pair> pairs1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(pairs1) << endl;

    vector<Pair> pairs2 = {{5, 10}, {1, 11}};
    cout << maxChainLen(pairs2) << endl;

    return 0;
}
