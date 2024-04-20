/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root, string number = "") {
        if (!root)
           return 0;

        number += std::to_string(root->val);

        if (!root->left && !root->right)
            return stoi(number);

        int res1 = sumNumbers(root->left, number);
        int res2 = sumNumbers(root->right, number);

        return res1 + res2;
    }
}
    ;