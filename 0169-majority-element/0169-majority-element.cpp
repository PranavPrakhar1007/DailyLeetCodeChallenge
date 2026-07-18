class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0) major = nums[i];
            if(nums[i]==major) cnt++;
            else cnt--;
        }
        return major;
    }
};