class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int indx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>max1)
            {
                max2 = max1;
                max1 =nums[i];
                indx = i;

            }
            else if(nums[i]>max2 && nums[i] != max1)
            {
                max2 = nums[i];
            }
        }
        if(max1 >= 2*max2) return indx;
        return -1;
    }
};