class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> count;
        for(int i=0;i<nums.size();i++)
        {
            if(i>k)
            {
                count.erase(nums[i-k-1]);
            }
            if(count.find(nums[i])!=count.end())
            return true;

            count.insert(nums[i]);
        }
        return false;
    }
};
