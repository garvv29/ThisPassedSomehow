class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s=nums.size();
        vector <int> idk(s,0);
        for(int i=0;i<s;i++)
        { 
            if(idk[nums[i]]==1)
                return nums[i];
            else
            idk[nums[i]]++;
        }
        return -1;
    }
};
