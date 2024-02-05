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

    TreeNode* check(vector<int>& in,vector<int>& post,unordered_map<int,int>& mp,int i,int j,int k){
        // cout<<i<<"=="<<j<<"=="<<k<<"\n";
        if(i==j){
            return new TreeNode(in[i]);
        }
        for(int t=k;t>=0;t--){
            if(mp[post[t]]>=i && mp[post[t]]<=j){
                TreeNode* root=new TreeNode(post[t]);
                root->left=check(in,post,mp,i,mp[post[t]]-1,t-1);
                root->right=check(in,post,mp,mp[post[t]]+1,j,t-1);
                return root;
            }
        }
        return NULL;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return check(inorder,postorder,mp,0,inorder.size()-1,inorder.size()-1);
    }
};