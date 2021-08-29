class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>> s;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            if(s.empty())
            {
                s.push({intervals[i][0],intervals[i][1]});
            }
            else if(s.top().second>=intervals[i][0] && intervals[i][1]>s.top().second)
            {
                s.top().second = intervals[i][1];
            }
            else if(intervals[i][1]>s.top().second)
            {
                s.push({intervals[i][0],intervals[i][1]});
            }
        }
        vector<vector<int>> v;
        while(!s.empty())
        {
            vector<int> b;
            b.push_back(s.top().first);
            b.push_back(s.top().second);
            v.push_back(b);
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
