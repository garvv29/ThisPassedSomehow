class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++)
        {
            int sum1=0,sum2=0;
            string num=to_string(i);
            for(int j=0;j<num.length();j++)
            {
                if(j<num.length()/2)sum1+=num[j];
                else if(j>=num.length()/2)sum2+=num[j];
            }
            if(sum1==sum2)count++;
        }
        return count;
    }
};
