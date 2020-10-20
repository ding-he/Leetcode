#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);

        for (int i = int(sum.size()) - 2; i >= 0; --i) {
            sum[i] += sum[i + 1];
        }

        int pos = 0;
        dfs(root, pos);
        return root;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        sum.push_back(root->val);
        dfs(root->right);
    }

    void dfs(TreeNode* root, int& pos) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, pos);
        root->val = sum[pos++];
        dfs(root->right, pos);
    }

    vector<int> sum;
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(13);

    Solution().convertBST(root); 
    cout << root->left->val << " " << root->val << " " << root->right->val << endl;
}