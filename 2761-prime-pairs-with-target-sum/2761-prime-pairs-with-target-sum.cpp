class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n<4) return {};
        if(n%2!=0)
        {
            int p = n-2;
            for(int i=3;i*i<=p;i+=2)
            {
                if(p%i==0) return {};
            }
            return {{2,p}};
        }
        vector<bool> sieve(n,false);
        if(n==4) return{{2,2}};
        for(int i=3;i*i<=n;i+=2)
        {
            if(!sieve[i])
            {
                for(int j=i*i;j<n;j+=i*2)
                {
                    sieve[j] = true;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=3;i<=n/2;i+=2)
        {
            if(!sieve[i] && !sieve[n-i]) ans.push_back({i,n-i});
        }
        return ans;
    }
};