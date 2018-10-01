#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Interval
{
    int start;
    int end;
    Interval(int s, int e): start(s), end(e) {};
};

class Solution
{
public:

    static bool comp(Interval& l, Interval& r)
    {
        return l.start < r.start;
    }

    int minMeetingsRooms2(vector<Interval>& intervals) 
    {
        if(intervals.size()==0) 
        {
            return 0;
        }
        vector<int> start;
        vector<int> end;
        for(auto i: intervals)
        {
            start.push_back(i.start);
            start.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms=0;
        int avaliable =0;
        int e=0;

        for(int s=0;s<start.size(); s++)
        {
            while(end[e] <=start[s])
            {
                ++e;
                ++available;
            }
            if(available)
                --available
            else
                ++rooms;

        }


        return rooms;
    }

    int minMeetingsRooms(vector<Interval>& intervals) 
    {
        if(intervals.size()==0) 
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        priority_queue<int, vector<int>, greater<int> > pq;
        pq.push(intervals[0].end);

        for(int i=1;i<intervals.size(); i++)
        {
            if (pq.top() <= intervals[i].start)
                pq.pop();
            pq.push(intervals[i].end);
            cnt = max(cnt, (int)pq.size());
        }


        return cnt;
    }

};




int main()
{
    vector<Interval> intervals;
    Interval i(0,30);
    intervals.push_back(i);
    i = Interval(5, 10);
    intervals.push_back(i);
    i = Interval(15, 20);
    intervals.push_back(i);

    Solution sol;
    int rooms = sol.minMeetingsRooms(intervals);
    cout << rooms << endl;

    return 0;
}
