#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> re;
        queue<TreeNode*> q{{root}};
        while(!q.empty()){
            int n=q.size();
            double temp=0;
            for(int i=n;i>0;i--){
                auto t=q.front();q.pop();
                temp+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            re.push_back(temp/n);
        }
        return re;
    }
};
// 参考429
