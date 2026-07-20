class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int x:nums)
        {
            mpp[x]++;
        }
        for(auto const &[key,value] : mpp)
        {
            if(value==1) ans.push_back(key);
        }
        return ans;
    }
};