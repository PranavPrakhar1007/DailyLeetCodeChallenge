class Solution {
public:
    int n;
    int cntovrlps(vector<vector<int>>& img1, vector<vector<int>>& img2, int ro, int co)
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+ro <0 || j+co <0 || i+ro>=n||j+co>=n) continue;
                else if(img2[i+ro][j+co] == 0) continue;
                else if(img2[i+ro][j+co] == 1 && img1[i][j]==0) continue;
                else cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        n = img1.size();
        int count = 0;
        for(int i = -n+1;i<n;i++)
        {
            for(int j = -n+1;j<n;j++)
            {
                count = max(cntovrlps(img1,img2,i,j),count);
            }
        }
        return count;
    }
};