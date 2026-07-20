class Solution {
public:
    int maxPower(string s) {
        char ch = s[0];
        int cnt=1;
        int maxcnt = 1;
        if(s.size()==1) return 1;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]!=ch)
            {
                ch = s[i];
                cnt=1;
            }
            else
            {
                cnt++;
                maxcnt = max(maxcnt,cnt);
            }
        }
        return maxcnt;
    }
};