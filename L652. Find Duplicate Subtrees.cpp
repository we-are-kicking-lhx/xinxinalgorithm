class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<long, int> ids;
        unordered_map<int, int> cnt;
        vector<TreeNode*> ans;
        getId(root, ids, cnt, ans);
        return ans;
    }
    int getId(TreeNode* root, unordered_map<long, int>& ids, unordered_map<int, int>& cnt, vector<TreeNode*>& ans)
    {
        if (!root)
            return 0;
        long key = (static_cast<long>(static_cast<unsigned>(root->val)) << 32) | (getId(root->left, ids, cnt, ans) << 16) | (getId(root->right, ids, cnt, ans));
        int id;
        auto it = ids.find(key);
        if (it == ids.end())
            id = ids[key] = ids.size() + 1;
        else
            id = it->second;
        if (++cnt[id] == 2)
            ans.push_back(root);
        return id;
    }
};
