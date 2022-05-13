class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return 1;
        int j = nums.size()-1;
        // location "j" is used to store repeated data.
        // In the end of for loop, any data before j (including data "j") is unique. 
        for(int i = nums.size()-1; i>=0;i--){
            while(i != 0 && nums[i]==nums[i-1]){
                swap(nums[i], nums[j]);
                i--;
                j--;
            }
        }
        sort(nums.begin(), nums.begin()+j+1); // sort the unique data.
        return j+1;
    }
};
