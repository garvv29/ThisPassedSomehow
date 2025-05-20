class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n=nums.size();
    vector<int> diffarr(n+1,0);
    for(int i=0;i<queries.size();i++)
    {
        int left=queries[i][0],right=queries[i][1];
        diffarr[left]++;diffarr[right+1]--;

    }
    vector<int> maxop;
    int sum=0;
    for(int i:diffarr)
    {
        sum+=i;
        maxop.push_back(sum);
    }
    for(int i=0;i<n;i++)
    {
        if(nums[i]>maxop[i])return false;
    }
    return true;

    }
};
