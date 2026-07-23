class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int gap = arr.size()/4;
        for(int i=0;i<arr.size()-gap;i++)
        {
            if(arr[i]==arr[i+gap])return arr[i];
        }
        return -1;
    }
};