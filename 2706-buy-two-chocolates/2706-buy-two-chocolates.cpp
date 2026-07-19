class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini = *min_element(prices.begin(),prices.end());
        int flag=0;
        int mini2 = INT_MAX;
        for(int x:prices)
        {
            if(x==mini)
            {
                if(flag==1) mini2 = mini;
                else flag=1;
            }
            else if(x<mini2)
            {
                mini2 = x;
            }

        }
        return ((money-(mini+mini2)<0)) ? money : (money-(mini+mini2));
    }
};