#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> results;
        vector<int> temp;
        subRec(results, nums, temp, 0, nums.size());
        return results;
    }

    void subRec(vector<vector<int>> &results, vector<int> &nums, vector<int> &temp, int index, int n)
    {
        if (index == n)
        {
            vector<int> copyTemp(temp);
            results.push_back(copyTemp);
            return;
        }
        temp.push_back(nums[index]);
        subRec(results, nums, temp, index + 1, n);
        temp.pop_back();
        subRec(results, nums, temp, index + 1, n);
    }

    void printVector(vector<int> &temp)
    {
        cout << "Printing vector" << endl;
        for (auto it2 : temp)
        {
            cout << it2 << " ";
        }
        cout << endl;
        cout << "Print complete" << endl;
    }
};

int main()
{
    vector<int> nums = {9, 8, 7};
    Solution sln;
    vector<vector<int>> results = sln.subsets(nums);
    cout << '[';
    for (vector<int> v : results)
    {
        cout << '[';
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
                cout << ",";
        }
        cout << ']';
    }
    cout << ']' << endl;
    return 0;
}