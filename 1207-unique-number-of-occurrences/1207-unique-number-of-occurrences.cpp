class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int x:arr)
        {
            mpp[x]++;
        }
        unordered_set<int> st;
        for(auto const&[key,value] : mpp)
        {
            if(st.count(value)) return false;
            st.insert(value);
        }
        return true;
    }
};