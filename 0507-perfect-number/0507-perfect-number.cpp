class Solution {
public:
    bool checkPerfectNumber(int num) {
        int count = 0;
        if(num==1) return false;
        for(int i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                count +=i;
                if(i*i != num)
                {
                    count+= num/i;
                }
            }
            
        }
        count++;
        return count == num;
    }
};