class Solution {
public:
    int singleNumber(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       // Since nums is sorted, each two repeated data is adjacent to each other.
       // return nums[i] that isn't equal to nums[i+1]
        for(int i = 0; i<nums.size()-1; i+=2){
            if(nums[i] != nums[i+1]) return nums[i];
        }
        return nums[nums.size()-1];
    }
};

// Also, keep the XOR method in mind!
// refer to https://leetcode.com/problems/single-number/discuss/1771720/C%2B%2B-EASY-SOLUTIONS-(SORTING-XOR-MAPS-(OR-FREQUENCY-ARRAY))
