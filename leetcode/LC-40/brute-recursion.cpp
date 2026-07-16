#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        combSum(result, candidates, candidates.size(), 0, target, temp);
        return result;
    }

private:
    void addUniqueSequenceToResultVector(vector<vector<int>> &result, vector<int> &temp)
    {
        vector<int> copyTemp(temp);
        bool vectorAlreadyAvailable = false;
        for (vector<int> it : result)
        {
            if (it == copyTemp)
            {
                vectorAlreadyAvailable = true;
                break;
            }
        }
        if (!vectorAlreadyAvailable)
            result.push_back(copyTemp);
    }

    void combSum(vector<vector<int>> &result, vector<int> &candidates, int n, int index, int target, vector<int> &temp)
    {
        if (target == 0)
        {
            addUniqueSequenceToResultVector(result, temp);
        }
        else if (target < 0)
        {
            return;
        }
        else if (index == n)
        {
            return;
        }
        else
        {
            temp.push_back(candidates[index]);
            combSum(result, candidates, n, index + 1, target - candidates[index], temp);
            temp.pop_back();
            combSum(result, candidates, n, index + 1, target, temp);
        }
    }

    void printVector(vector<int> temp)
    {
        cout << "Printing vector" << endl;
        for (auto it2 : temp)
        {
            cout << it2 << " ";
        }
        cout << "Print complete" << endl;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution sln;
    vector<vector<int>> result = sln.combinationSum2(candidates, target);
    for (auto it : result)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}
