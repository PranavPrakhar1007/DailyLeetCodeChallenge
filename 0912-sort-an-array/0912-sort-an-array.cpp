class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high,vector<int>&temp)
    {
        int left = low;
        int right = mid+1;
        int index = low;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right]) temp[index++] = nums[left++]; 
            else 
            {
                temp[index++] = nums[right++];
            }
        }
        while(left<=mid) temp[index++] = nums[left++];
        while(right<=high) temp[index++] = nums[right++];
        for(int i=low;i<=high;i++)
        {
            nums[i] = temp[i];
        }
    }
    void mergesort(vector<int> &nums, int low, int high,vector<int> & temp)
    {
        if(low>=high) return;
        int mid = (low+high)/2;
        mergesort(nums,low,mid,temp);
        mergesort(nums,mid+1,high,temp);
        merge(nums,low,mid,high,temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergesort(nums,0,nums.size()-1,temp);
        return nums;
    }
};