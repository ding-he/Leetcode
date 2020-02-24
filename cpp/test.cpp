#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) / 2, cnt = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (cnt < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};


int main()
{
	vector<vector<int>> matrix{{1, 2}, {1, 3}};
	int res;

	Solution solu = Solution();
	res = solu.kthSmallest(matrix, 3);

	cout << res << endl;

    cout << "我爱你" << endl;

	return 0;
}
