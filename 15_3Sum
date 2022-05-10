class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans; // Set is to store unique elements following a specific order.
        if(nums.size() < 3) return vector<vector<int>>{}; // if the size of nums is less than 3, the answer is empty set.
        sort(nums.begin(), nums.end());
        
        // set the first number is non-positive number
        // using "findAns" function to check whether the sum of this number and any two numbers after it is 0;
        // do the for loop until nums[i] < 1 because if nums[i] >= 1, any two numbers after it will be positive, which means their sum will never be 0.
        for(int i = 0; i < (int) nums.size()-1 && nums[i] < 1; i++){
            //if the value nums[i] and nums[i-1] is the same, skip nums[i] to avoid repeating to check the same number.
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            findAns(nums, i+1, nums.size()-1, ans);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
    void findAns(vector<int>& nums, int low , int high, set<vector<int>>& ans){
        if(low<high){
            int target = -nums[low-1];
            while(low < high){
                int subSum = nums[low]+nums[high];
                // subSum - target = 0
                // if subSum is bigger than target, move the right index to its left 
                // if subSum is smaller than target, move the left index to its right 
                if(subSum>target){
                    while(high-1 > low && nums[high]==nums[high-1]) high--;  //avoid repeating to check the same number.
                    high--;
                }else if(subSum<target){
                    while(low+1 < high && nums[low]==nums[low+1]) low++; //avoid repeating to check the same number.
                    low++;
                }else{
                    ans.insert(vector<int>{-target, nums[low], nums[high]});
                    while(high-1 > low && nums[high]==nums[high-1]) high--;
                    while(low+1 < high && nums[low]==nums[low+1]) low++;
                    high--;
                    low++;
                }
            }
        }
    }
};
