class Solution {
public:
    int maxPalindromes(string s, int k) {
        int cnt = 0;
        int n = s.size();
        if(k==1) return n;
        
        int i = 0;
        while(i <= n - k) 
        {
            int j = i+k-1;
            bool found = false; 
            
            // FIX: Only check for palindromes of length k and k+1. 
            // This prevents grabbing massive palindromes that swallow up smaller ones.
            int limit = min(n - 1, i + k); 
            
            while(j <= limit) // Changed from j < n
            {
                int left = i;
                int right = j;
                
                while(left<=right)
                {
                    if(s[left]!=s[right]) break;
                    left++;
                    right--;
                }
                
                if(left>right) 
                {
                    cnt++; 
                    i = j + 1; 
                    found = true; 
                    break; 
                }
                else
                {
                    j++;
                }
            }
            
            if(!found) 
            {
                i++;
            }
        }
        return cnt;
    }
};