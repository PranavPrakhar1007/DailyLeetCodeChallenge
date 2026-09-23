class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int,int> mpp;
        mpp[0] = -1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mpp[sum] = i;
        }
        int value = sum-x;
        if (value < 0) return -1;
        int length = INT_MIN;
        sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int findSum = sum-value;
            if(mpp.find(findSum)!=mpp.end())
            {
                int idx = mpp[findSum];
                length = max(length,i-idx);
            }
        }
        return length == INT_MIN ? -1 : (n-length);
    }
};