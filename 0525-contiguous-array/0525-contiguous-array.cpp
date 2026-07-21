class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int sum=0;
        int maxlength = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i] ? 1 : -1;
            if(sum==0) maxlength = i+1;
            if(mpp.find(sum)!=mpp.end())
            {
                maxlength = max(maxlength,i-mpp[sum]);
            }
            else mpp[sum] = i;
        }
        return maxlength;
    }
};