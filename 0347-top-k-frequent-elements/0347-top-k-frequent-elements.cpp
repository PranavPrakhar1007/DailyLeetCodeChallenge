class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int num:nums)
        {
            mpp[num]++;
        }
        vector<vector<int>> bucket(n+1);
        for(auto it:mpp)
        {
            int value = it.first;
            int freq = it.second;
            bucket[freq].push_back(value);
        }
        vector<int> result;
        for(int i=n;i>=0;i--)
        {
            while(bucket[i].size()==0) continue;
            while(bucket[i].size()>0 && k>0)
            {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};