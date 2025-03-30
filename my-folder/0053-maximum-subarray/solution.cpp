class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0,msum=INT_MIN;
        for(int i: nums)
        {
            csum+=i;
            msum=max(csum,msum);
            if(csum<0)csum=0;
        }
        return msum;
    }
};
