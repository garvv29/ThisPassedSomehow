class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int> idk;
    for(int i=0;i<nums.size();i++)
    {
        int comp= target-nums[i];
        if(idk.count(comp))
        return {i,idk[comp]};
    idk[nums[i]]=i;
    }
    return {};
    }
};
