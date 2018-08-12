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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto compare = [](const Interval& interval1, const Interval& interval2){
            return interval1.end < interval2.start;
        };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, compare);
        auto iter1 = range.first;
        auto iter2 = range.second;
        if (iter1 == iter2){
            intervals.insert(iter1, newInterval);
        }else{
            iter2--;
            iter2->start = min(iter1->start, newInterval.start);
            iter2->end = max(iter2->end, newInterval.end);
            intervals.erase(iter1, iter2);
        }
        return intervals;
    }
};
