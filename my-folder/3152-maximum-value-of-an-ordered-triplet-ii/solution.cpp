class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxtrip=0,maxele=0,maxdiff=0;
        for(long num:nums)
        {
            maxtrip=max(maxtrip,maxdiff*num);
            maxdiff=max(maxdiff,maxele-num);
            maxele=max(maxele,num);
        }
        return maxtrip;
    }
};
