class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>umap;
        vector<pair<int, int>>vpair; 
        vector<int>res;

        for(auto x: nums){
            ++umap[x];
        }

        for(auto x: umap){
            pair<int, int>p = {x.second, x.first};
            vpair.emplace_back(p);
        }

        sort(vpair.begin(), vpair.end());
        reverse(vpair.begin(), vpair.end());

        for(int i = 0 ; i < k ; ++i)
            res.emplace_back(vpair[i].second);

        return res;
    }
};
