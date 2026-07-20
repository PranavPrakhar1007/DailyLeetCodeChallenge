class Solution {
public:
    bool check(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        int indx=-1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                indx = i;
                break;
            }
        } 
        if(indx==-1) return true;
        reverse(nums.begin(),nums.begin()+indx);
        reverse(nums.begin()+indx,nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
};