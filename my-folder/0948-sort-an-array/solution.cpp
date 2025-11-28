class Solution {
public:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int low = left;
        int high = mid+1;
        vector<int> temp;
        while(low <= mid && high <= right)
        {
            if(nums[low] <= nums[high])
            {
                temp.push_back(nums[low]);
                low++;
            }
            else
            {
                temp.push_back(nums[high]);
                high++;
            }
        }
        while(low <= mid)
        {
            temp.push_back(nums[low]);
            low++;
        }
        while(high <= right)
        {
            temp.push_back(nums[high]);
            high++;
        }
        for(int i=0; i<temp.size(); i++)
        {
            nums[i + left] = temp[i];
        }
    }   

    void mergeSort(vector<int> &nums, int left, int right)
    {
        if(left == right)
            return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        // atexit([](){ std::ofstream("display_runtime.txt") << "0"; });
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
