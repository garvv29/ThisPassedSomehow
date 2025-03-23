class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector <int> ans(2);
        int n=grid.size();
        int t=n*n;
        vector <int> counts(t+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                counts[grid[i][j]]++;
            }
        }
        for(int i=1;i<=t;i++)
        {
            if(counts[i]==2)
            ans[0]=i;
            else if(counts[i]==0)
            ans[1]=i;
        }
return ans;
}
};
