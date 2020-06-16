class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>res;
        if(!root)return res;
        stack<Node*>s;
        s.push(root);
        while(!s.empty()){
            Node* node = s.top();
            s.pop();
            res.emplace_back(node->val);
            for(auto child : node->children)
                s.push(child);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};