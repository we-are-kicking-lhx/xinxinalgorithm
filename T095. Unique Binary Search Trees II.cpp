class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        
        if (!n)return vector<TreeNode*>{};
        return generate(1, n);
    }
    
    //以n个结点分别做根节点，进行生成
    vector<TreeNode*>generate(int s,int e){
        vector<TreeNode*>res;
        //当s>e时，说明是个叶子结点，
        if (s > e) {
            res.push_back(NULL);
            return res;
        }
        
        for(int i = s;i <= e ; i++){
            //生成左右子树的所有可能性
            vector<TreeNode*>left_nodes = generate(s, i - 1);
            vector<TreeNode*>right_nodes = generate(i + 1, e);
            for(auto left : left_nodes){
                for(auto right : right_nodes){
                    TreeNode * t = new TreeNode(i);
                    t->left = left;
                    t->right = right;
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};