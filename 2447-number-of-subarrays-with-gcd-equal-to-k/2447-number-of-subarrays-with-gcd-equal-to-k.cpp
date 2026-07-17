class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int current_gcd = nums[i];
            for(int j=i;j<n;j++)
            {
                current_gcd = gcd(current_gcd,nums[j]);
                if(current_gcd==k) count++;
                else if(current_gcd%k!=0) break;
            }
        }
        return count;
    }
};