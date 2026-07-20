class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;
        int insertIndex = 2;
        for(int i=2;i<n;i++)
        {
            if(nums[i]!=nums[insertIndex-2])
            {
                nums[insertIndex] = nums[i];
                insertIndex++;
            }
        }
        return insertIndex;
    }
};