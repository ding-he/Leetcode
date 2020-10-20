#include <unistd.h>
#include <cmath>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* pre = nullptr;
        dfs(root, pre);
        return ans;
    }

    void dfs(TreeNode* root, TreeNode*& pre) {
        if (root == nullptr) {
            return;
        }

        dfs(root->left, pre);
        if (pre != nullptr) {
            ans = min(ans, abs(root->val - pre->val));
        }
        pre = root;
        dfs(root->right, pre);
    }

    int ans = INT_MAX;
};

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);

    int min_abs = Solution().getMinimumDifference(root);
    cout << "min_abs = " << min_abs << endl;
}