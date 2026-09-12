class Solution {
public:
    int n;
    struct Node
    {
        long long score = -1;
        vector<int> indxs;
    };
    vector<vector<Node>> t;
    vector<int> nextIndx;
    int findNext(vector<vector<int>> &intervals, int end)
    {
        int lo=0; int hi = n-1;
        int result = n;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(intervals[mid][0]>end)
            {
                result = mid;
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        return result;
    }
    Node solve(vector<vector<int>> &intervals, int i, int k)
    {
        if(k==0 || i>=n)
        {
            return Node();
        }
        if(t[i][k].score!=-1)
        {
            return t[i][k];
        }
        Node skip = solve(intervals,i+1,k);
        int wt = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIndx[i];
        Node temp = solve(intervals, j, k-1);
        Node take;
        take.score = temp.score + wt;
        take.indxs = temp.indxs;
        take.indxs.push_back(idx);
        sort(begin(take.indxs),end(take.indxs));
        Node result;
        if(skip.score > take.score) result = skip;
        else if(skip.score<take.score) result = take;
        else
        {
            result = (skip.indxs<take.indxs)?skip:take;
        }
        return t[i][k] = result;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        for(int i=0;i<n;i++)
        {
            intervals[i].push_back(i);
        }
        sort(begin(intervals),end(intervals));
        nextIndx.resize(n);
        for(int i=0;i<n;i++)
        {
            int end = intervals[i][1];
            nextIndx[i] = findNext(intervals,end);
        }
        
        int K = 4;
        t.assign(n+1,vector<Node>(K+1));
        return solve(intervals,0,K).indxs;
    }
};