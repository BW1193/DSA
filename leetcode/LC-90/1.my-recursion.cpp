/*
 * THIS SOLUTION PASSED ALL TEST CASES BUT TIME AND COMPLEXITY SCORE IS VERY LOW
 * Runtime - Beats 6.09%
 * Memory - Beats 5.31%
 * TODO - Need to check Submissions tab for better approaches
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> temp;
        subRec(results, nums, temp, 0);
        return results;
    }

    void subRec(vector<vector<int>> &results, vector<int> &nums, vector<int> &temp, int index)
    {
        if (index == nums.size())
        {
            pushUniqueVector(results, temp); 
            return;
        }
        temp.push_back(nums[index]);
        subRec(results, nums, temp, index + 1);
        temp.pop_back();
        subRec(results, nums, temp, index + 1);
    }

    void pushUniqueVector(vector<vector<int>> &results, vector<int> &temp)
    {
        bool vectorFound = false;
        for (auto it : results)
        {
            if (it == temp)
            {
                vectorFound = true;
                break;
            }
        }
        if (!vectorFound)
        {
            vector<int> copy(temp);
            results.push_back(copy);
        }
    }
};

int main()
{
    vector<int> nums = {2, 1, 2};
    Solution sln;
    vector<vector<int>> results = sln.subsetsWithDup(nums);
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
}