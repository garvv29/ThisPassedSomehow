class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10,0);
        vector<int> result;
        for(int digit:digits)
        {
            count[digit]++;
        }
        for(int i=1;i<=9;i++)
        {
            if(count[i]==0)continue;
            count[i]--;
            for(int j=0;j<=9;j++)
            {
                if(count[j]==0)continue;
                count[j]--;
                for(int k=0;k<=8;k+=2)
                {
                    if(count[k]==0)continue;
                    count[k]--;
                    int num=(i*100)+(j*10)+k;
                    result.push_back(num);
                    count[k]++;
                }
                count[j]++;
            }
            count[i]++;
        }
        return result;
    }
};
