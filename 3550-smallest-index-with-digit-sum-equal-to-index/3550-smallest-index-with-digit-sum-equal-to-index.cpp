class Solution {
public:
    int sumOfDigits(int x)
    {
        int sum=0;
        while(x)
        {
            int digit = x%10;
            sum+=digit;
            x/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int x = sumOfDigits(nums[i]);
            if(x==i) return i;
        }
        return -1;
    }
};