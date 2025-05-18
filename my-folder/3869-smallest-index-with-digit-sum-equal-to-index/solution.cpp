class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini=99999;
        bool flag=false;
        for(int i=0;i<nums.size();i++)
        {
            int sum=0;
            int num=nums[i];
            while(num)
            {
                int digit= num%10;
                sum+=digit;
                num=num/10;
            }
            if(i==sum)
            {
            flag=true;;
            mini=min(mini,sum);
            }
        }
        if(flag)
        return mini;
        else
        return -1;
    }
};
