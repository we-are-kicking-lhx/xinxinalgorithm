class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> re;
        stack<TreeNode *> s;
        while (root != NULL || !s.empty())
        {
            if (root)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                root = s.top();
                re.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return re;
    }
};