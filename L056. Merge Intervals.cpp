class Solution
{
  public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
            return intervals;
        // lambda函数
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) { return a.start < b.start; });
        vector<Interval> re;
        re.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (re.back().end < intervals[i].start)
                re.push_back(intervals[i]);
            else
                re.back().end = max(re.back().end, intervals[i].end);
        }
        return re;
    }
};