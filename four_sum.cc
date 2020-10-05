#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            dfs(nums, target, i);
        }
        return ans;
    }

    void dfs(vector<int>& nums, int target, int pos) {
        if (tuples.size() == 4 && target == sum) {
            ans.push_back(tuples);
            return;
        } else if (tuples.size() >= 4 || target < sum) {
            return;
        }

        sum += nums[pos];
        tuples.push_back(nums[pos]);

        for (int i = pos + 1; i < nums.size(); ++i) {
            dfs(nums, target, i);
        }

        tuples.pop_back();
        sum -= nums[pos];
    }

    vector<vector<int>> ans;
    vector<int> tuples;
    int sum = 0;
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    auto ans = Solution().fourSum(nums, target);

    for (auto& tuple : ans) {
        for (auto& ele : tuple) {
            cout << ele << " ";
        }
        cout << endl;
    }
}