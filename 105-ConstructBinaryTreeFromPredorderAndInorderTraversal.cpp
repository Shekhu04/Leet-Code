class Solution {
    private:
    map<int,int> mp;
public:
    void mapping(vector<int>& inorder,int &size){
        for(int i=0;i<size;i++)
            mp[inorder[i]]=i;
        
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &size,int &preindex,int inorderstart,int inorderend){
        if((preindex>=size)||(inorderstart>inorderend))
            return NULL;

        int ele=preorder[preindex++];
        TreeNode* root=new TreeNode(ele);
        int pos=mp[ele];
        root->left=solve(preorder,inorder,size,preindex,inorderstart,pos-1);
        root->right=solve(preorder,inorder,size,preindex,pos+1,inorderend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size=preorder.size();
        int preindex=0,inorderstart=0,inorderend=size-1;
        mapping(inorder,size);
        return solve(preorder,inorder,size,preindex,inorderstart,inorderend);
    }
};
