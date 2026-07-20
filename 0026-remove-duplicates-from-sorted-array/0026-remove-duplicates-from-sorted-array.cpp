class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        if(n==1) return cnt;
        int i=1,j=1;
        while(j<n)
        {
            while(j<n && nums[j] == nums[i-1]) j++;
            if(j<n)
            {
                swap(nums[i],nums[j]);
                i++;
                j++;
            } 
        }
        return i;
    }
};