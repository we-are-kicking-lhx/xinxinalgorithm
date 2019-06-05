class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        if (!root)
            return {};
        vector<int> re;
        stack<Node *> s{{root}};
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            re.insert(re.begin(), temp->val);
            for (Node *node : temp->children)
            {
                if (node)
                    s.push(node);
            }
        }
        return re;
    }
};