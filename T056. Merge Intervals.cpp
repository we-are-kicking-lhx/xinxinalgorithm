/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> ans;
    vector<Interval> merge(vector<Interval>& intervals) {
        if(!intervals.size()) return ans;
        sort(intervals.begin(), intervals.end(),[](Interval &i1,Interval &i2){
            if (i1.start != i2.start) {
                return i1.start < i2.start;
            }
            return i1.end < i2.end;
        });
        Interval t = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if(t.end < intervals[i].start){
                ans.push_back(t);
                t = intervals[i];
            }
            else t.end = max(intervals[i].end,t.end);
        }
        ans.push_back(t);
        return ans;
    }
};
//区间连续，无法用-1 和 1 那种做