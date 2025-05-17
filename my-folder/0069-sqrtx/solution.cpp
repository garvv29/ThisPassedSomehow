class Solution {
public:
    int mySqrt(int x) {
        if(x==0)    return 0;
        if(x==1)    return 1;
        int l=1, r= x;
        long long int mid = -1;
        long long int ans=1;
        while(l<=r){
            mid = l+(r-l)/2;
            long long int sq = mid*mid;
            
            if(sq>x)
                r=mid-1;
            else if(sq==x)
                return mid;
            else  {
                ans = mid;
                l=mid+1;
            }
            
        }
        return ans;
    }
};
