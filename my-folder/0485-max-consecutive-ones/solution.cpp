class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=1;
        int count=0,maxc=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                count++;
            }
            else
            {
                count=0;
            }
            maxc=max(maxc,count);
        }
        return maxc;
    }
};
