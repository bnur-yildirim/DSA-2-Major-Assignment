#include <iostream>
#include <vector>

using namespace std;

bool isValidPart(string s, int start, int end)
{
    if (start > end || end - start + 1 > 3)
        return false;
    if (s[start] == '0' && start != end)
        return false;
    int num = 0;
    for (int i = start; i <= end; i++)
    {
        if (!isdigit(s[i]))
            return false;
        num = num * 10 + (s[i] - '0');
        if (num > 255)
            return false;
    }
    return true;
}

void generateIP(string s, int start, int parts, string current, vector<string> &result)
{
    if (start == s.length() && parts == 4)
    {
        result.push_back(current);
        return;
    }
    if (start == s.length() || parts == 4)
        return;

    for (int i = 1; i <= 3; i++)
    {
        if (isValidPart(s, start, start + i - 1))
        {
            string part = s.substr(start, i);
            if (parts < 3)
                part += ".";
            generateIP(s, start + i, parts + 1, current + part, result);
        }
    }
}

vector<string> genIp(string &s)
{
    vector<string> result;
    generateIP(s, 0, 0, "", result);
    return result;
}

int main()
{
    string s = "25525511135";
    vector<string> ips = genIp(s);
    for (const auto &ip : ips)
    {
        cout << ip << endl;
    }
    return 0;
}
