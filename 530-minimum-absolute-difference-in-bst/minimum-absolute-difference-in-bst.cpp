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

    int res=INT_MAX;
    vector<int> temp;
    void inorder(TreeNode* root){

        if(!root){
            return;
        }
        inorder(root->left);
        temp.push_back(root->val);
        inorder(root->right);

    }
    int getMinimumDifference(TreeNode* root) {
        
        inorder(root);

        for(int i=0;i<temp.size()-1;i++){
            res=min(res,temp[i+1]-temp[i]);
        }

        return res;
    }
};