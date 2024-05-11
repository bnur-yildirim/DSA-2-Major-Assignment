#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Pair
{
    int first;
    int second;
};

bool comparePairs(const Pair &x, const Pair &y)
{
    return (x.second != y.second) ? (x.second < y.second) : (x.first < y.first);
}

int maxChainLen(vector<Pair> &pairs)
{
    sort(pairs.begin(), pairs.end(), comparePairs);
    int chainLength = 0;
    int lastEnd = INT_MIN;
    for (const auto &pair : pairs)
    {
        if (pair.first > lastEnd)
        {
            lastEnd = pair.second;
            chainLength++;
        }
    }
    return chainLength;
}

int main()
{
    vector<Pair> pairs1 = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(pairs1) << endl;
    vector<Pair> pairs2 = {{5, 10}, {1, 11}};
    cout << maxChainLen(pairs2) << endl;
    return 0;
}
