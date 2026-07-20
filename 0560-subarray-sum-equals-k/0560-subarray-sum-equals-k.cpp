class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int sum=0;
        int cnt=0;
        for(int x:nums)
        {
            sum+=x;
            if(sum==k) cnt++;
            int rem = sum-k;
            if(mpp.find(rem)!= mpp.end()) cnt+=mpp[rem];
            mpp[sum]++;
        }
        return cnt;
    }
};