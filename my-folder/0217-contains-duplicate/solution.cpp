class Solution {
public:
    bool containsDuplicate(vector<int>& nums) { 

    sort(nums.begin(),nums.end()) ;

     for (int i=0;i<nums.size()-1;i++) {

          if (nums[i]==nums[i+1]) 

           {  return true;
           }   
           
         }
             return false ;
     
    }
};







 /*Using unordered set (HashSet)
    std::unordered_set<int> myset ;

    for (int i=0; i<nums.size(); i++)

    {
              if (myset.count(nums[i]) == true)
              {
                return true ;
              }
               
             else myset.insert(nums[i]);  

    }     
      

    return false;
    */
