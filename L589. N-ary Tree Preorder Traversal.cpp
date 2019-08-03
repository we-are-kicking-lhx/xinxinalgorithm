class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (!root)
            return {};
        vector<int> res;
        stack<Node *> st{{root}};
        while (!st.empty())
        {
            Node *t = st.top();
            st.pop();
            res.push_back(t->val);
            for (int i = (int)t->children.size() - 1; i >= 0; --i)
            {
                st.push(t->children[i]);
            }
        }
        return res;
    }
};