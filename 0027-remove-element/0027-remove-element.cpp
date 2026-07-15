class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        int n = nums.size();
        for(int num:nums)
        {
            if(num==val) cnt++;
        }
        int i=0,j=n-1;
        while(i<j)
        {
            while(i<j && nums[i]!=val) i++;
            while(j>i && nums[j]==val)j--;
            if(i<j)swap(nums[i],nums[j]);
        }
        return n-cnt;
    }
};