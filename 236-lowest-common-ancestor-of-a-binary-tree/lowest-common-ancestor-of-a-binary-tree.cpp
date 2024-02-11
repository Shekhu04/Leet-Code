class Solution
{
public:
    bool visit(TreeNode *root, TreeNode *p, vector<TreeNode *> &v)
    {
        if (!root)
        {
            return false;
        }
        v.push_back(root);
        if (root == p)
        {
            return true;
        }
        if (visit(root->left, p, v) || visit(root->right, p, v))
        {
            return true;
        }

        v.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> vp;
        vector<TreeNode *> vq;
        visit(root, p, vp);
        visit(root, q, vq);
        for (int i = vq.size() - 1; i >= 0; i--)
        {
            if (find(vp.begin(), vp.end(), vq[i]) != vp.end())
            {
                return vq[i];
            }
        }
        return NULL;
    }
};