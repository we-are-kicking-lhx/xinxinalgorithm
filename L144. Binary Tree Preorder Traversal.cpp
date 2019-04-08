class Solution
{
  public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> re;
        stack<TreeNode *> s;
        while (root != NULL || !s.empty())
        {
            if (root)
            {
                s.push(root);
                re.push_back(root->val);
                root = root->left;
            }
            else
            {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return re;
    }
};