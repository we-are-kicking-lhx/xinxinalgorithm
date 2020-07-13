class MonotonicQueue {
public:
    void push(int e)
    {
        while (!data_.empty() && e > data_.back())
            data_.pop_back();
        data_.push_back(e);
    }
    void pop()
    {
        data_.pop_front();
    }
    int max()
    {
        return data_.front();
    }

private:
    deque<int> data_;
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        MonotonicQueue q;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                ans.push_back(q.max());
                if (nums[i - k + 1] == q.max())
                    q.pop();
            }
        }
        return ans;
    }
};
