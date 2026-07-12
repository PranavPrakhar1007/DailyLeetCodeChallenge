class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int even_no = 0;
        for(int x:nums)
        {
            int cnt = 0;
            while(x>0)
            {
                cnt++;
                x/=10;
            }
            if(cnt%2==0) even_no++;
        }
        return even_no;
    }
};