class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int flag = 0;
        for(int x:nums)
        {
            if(x%2==0) 
            {
                mpp[x]++;
                flag=1;
            }
        }  
        int maxi = 0;
        int ans = -1;
        if(flag==0) return ans;
        for(auto const &[key,value] : mpp)
        {
            if(value>maxi)
            {
                maxi = value;
                ans = key;
            }
            else if(value==maxi) ans = min(ans,key);
        }
        return ans;
    }
};