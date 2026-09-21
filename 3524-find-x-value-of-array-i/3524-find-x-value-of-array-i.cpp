class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k);
        vector<long long> prev(k);
        for(int i=0;i<n;i++)
        {
            vector<long long> curr(k);
            int currRem = nums[i]%k;
            curr[currRem]++;
            for(int oldrem = 0; oldrem<k; oldrem++)
            {
                int newrem = ((long long)oldrem*nums[i]%k)%k;
                curr[newrem]+=prev[oldrem];
            }
            prev = curr;
            for(int x=0;x<k;x++)
            {
                result[x]+=curr[x];
            }
        }
        return result;
    }
};