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
    int maxPathSol(TreeNode*root,int &maxx){
        if(root==NULL){
            return 0;
        }
        int lh=max(0,maxPathSol(root->left,maxx));  //VVVIMP (corner case)//if we got pathsum negative we rather pick 0 beacuse we want max sum and so negative path will gonna make sum lesser
        int rh=max(0,maxPathSol(root->right,maxx)); //if we got pathsum negative we rather pick 0 beacuse we want max sum and so negative path will gonna make sum lesser
        maxx=max(maxx,lh+rh+root->val);
        return root->val+max(lh,rh); 
    }
    int maxPathSum(TreeNode* root) {
        int maxx=INT_MIN;
        maxPathSol(root,maxx);
        return maxx;
    }
};