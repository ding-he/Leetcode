#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums[nums.size() - 1] != 1) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] == 1) {
                    swap(nums[i], nums[nums.size() - 1]);
                    break;
                }
                if (nums[i] == 2 && nums[nums.size() - 1] != 2) {
                    swap(nums[i], nums[nums.size() - 1]);
                }
            }
        }

        int left = 0, right = nums.size() - 1;
        int key = nums[right];
        while (left < right) {
            while (left < right && nums[left] <= key) {
                ++left;
            }
            nums[right] = nums[left];
            while (left < right && nums[right] >= key) {
                --right;
            }
            nums[left] = nums[right];
        }
        nums[left] = key;
    }
};

int main()
{
    vector<int> nums = {1, 0, 1};
    Solution().sortColors(nums);
    for (auto& n : nums) {
        cout << n << " ";
    }
    cout << endl;
}