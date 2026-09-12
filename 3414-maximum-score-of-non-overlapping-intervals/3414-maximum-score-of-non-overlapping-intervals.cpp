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
        for(int i=n-1;i>=0;i--)
        {
            int wt = intervals[i][2];
            int idx = intervals[i][3];
            int j = nextIndx[i];
            for(int k=1;k<=K;k++)
            {
                Node skip = t[i+1][k];
                Node temp = t[j][k-1];
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
                    t[i][k] = result;
                }
        }
        return t[0][K].indxs;
    }
};