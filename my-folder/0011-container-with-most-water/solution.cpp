class Solution {
public:
    int maxArea(vector<int>& height) {
    int left=0,right=height.size()-1;
    long long area,maxarea=0,h,l;
    while(left<=right)
    {
        h=min(height[left],height[right]);
        l=right-left;
        area=h*l;
        maxarea=max(area,maxarea);

        if(right==left)break;
        if(height[left]>height[right])
        {
            right--;
        }
        else if(height[right]>height[left])
        {
            left++;
        }
        else left++;
    }
    return maxarea;
    }
};
