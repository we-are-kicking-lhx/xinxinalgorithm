class Solution
{
public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int sum = 0;
        stack<TreeNode *> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            if (s.top()->val <= L && s.top()->val >= R)
                sum += s.top()->val;
            root = s.top()->right;
            s.pop();
        }
        return sum;
    }
};