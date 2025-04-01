class Solution {
public:
    int countPrimes(int n) {
    long long count=0;
    vector<bool>v(n+1,true);
    v[0]=v[1]=false;
    for(long long i=2;i<n;i++){
        if(v[i]==true){
             count++;
    for(long long j=i*i;j<=n;j+=i){
                v[j]=false;
            }
            }
        }
         return count;
    }
};
