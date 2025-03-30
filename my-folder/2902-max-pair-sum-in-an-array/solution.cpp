class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> mp; 
        int maxi = -1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int maxDigit = 0;
            
            while (num > 0) {
                maxDigit = max(maxDigit, num % 10);
                num /= 10;
            }
            
            if (mp.find(maxDigit) != mp.end()) {
                maxi = max(maxi, mp[maxDigit] + nums[i]);
            }
            
            mp[maxDigit] = max(mp[maxDigit], nums[i]);
        }
        return maxi;
    }
};
