class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> re;
        if(!root) return {};
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            // 记录每层节点数目！！！
            for(int i=q.size();i>0;i--){
                auto f=q.front();q.pop();
                temp.push_back(f->val);
                if(f->children.empty()) continue;
                for(auto node:f->children) 
                    q.push(node);
            }
            re.push_back(temp);
        }
        return re;
    }
};