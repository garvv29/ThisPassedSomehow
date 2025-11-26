class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp=INT_MAX,mpro=0;
        for(int price:prices)
        {
            if(price<mp)mp=price;
            else
            {
                mpro=max(mpro,price-mp);
            }
        }
        return mpro;
    }
};
