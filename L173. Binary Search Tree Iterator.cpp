class BSTIterator
{
  private:
    stack<TreeNode *> st;

  public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        int re = node->val;
        if (node->right)
        {
            node = node->right;
            while (node)
            {
                st.push(node);
                node = node->left;
            }
        }
        return re;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !st.empty();
    }
};