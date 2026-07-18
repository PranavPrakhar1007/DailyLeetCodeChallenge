class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        int sum=0;
        for(auto const&[key,value] : mpp)
        {
            if(value==1)
            {
                sum+=key;
            }
        }
        return sum;
    }
};