class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int n:nums)
        {
            sum+=n;
        }
        int asum=n*(n+1)/2;
        int mnum=asum-sum;
        return mnum;
    }
};
