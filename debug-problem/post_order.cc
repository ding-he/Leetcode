#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        stk.push(root);
        vector<int> ans;
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            while (node->left != nullptr) {
                stk.push(node->left);
                node = node->left;
            }

            if (node->right != nullptr) {
                stk.push(node->right);
                continue;
            }

            node = stk.top();
            stk.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};