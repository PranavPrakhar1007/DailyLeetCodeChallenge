class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j,n;
        n = nums.size();
        i=0;
        j=0;
        while(i<n && j<n)
        {
            while( i<n && nums[i]!= 0)i++;
            j=i;
            while(j<n && nums[j]==0)j++;
            if(i<n && j<n)
            swap(nums[i],nums[j]);
        }
    }
};