class Solution {
public: 
    string getPermutation(int n, int k) {
        vector<int>v;  
        for(int i = 1; i <= n; i++) v.push_back(i);
        for(int i = 1; i < k; i++) next_permutation(v.begin(), v.end());
        string s = "";
        for(int num : v) s += to_string(num);
        return s;
    }
};
