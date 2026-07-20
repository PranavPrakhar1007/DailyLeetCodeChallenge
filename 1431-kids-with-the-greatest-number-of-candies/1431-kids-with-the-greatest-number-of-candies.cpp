class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi = *max_element(candies.begin(),candies.end());
        for(int num:candies)
        {
            if((num+extraCandies)>=maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};