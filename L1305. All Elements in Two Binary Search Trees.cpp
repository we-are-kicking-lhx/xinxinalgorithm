/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1,t2;
        traverse(root1,t1);
        traverse(root2,t2);
        vector<int> ans;
        int i=0,j=0;
        while(ans.size()!=t1.size()+t2.size()){
            if(i==t1.size()) ans.emplace_back(t2[j++]);
            else if(j==t2.size()) ans.emplace_back(t1[i++]);
            else{
                if(t1[i]<t2[j]) ans.emplace_back(t1[i++]);
                else ans.emplace_back(t2[j++]);
            }
        }
        return ans;
    }
    void traverse(TreeNode* root,vector<int>& re){
        if(!root) return;
        traverse(root->left,re);
        re.emplace_back(root->val);
        traverse(root->right,re);
    }
};