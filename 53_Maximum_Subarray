class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int target = 0; // store the max sum of a contiguous subarray
        int tmp=0, k=0; // tmp is to store the sum of a contiguous subarray, k is to store the start index of this subarray.
        // continuously add numbers of a subarray to tmp.
        for(int j = 0; j<nums.size(); j++){
            tmp += nums[j]; 
            // if tmp becomes minus, subtract the start number of subarray until tmp > 0.
            // Thus, we can possibly gain the bigger sums by adding the sum of the remaining numbers in tmp(subarray) to the following numbers. 
            while(tmp<0){
                tmp -= nums[k];
                k++;
            }
            // if the sum of tmp subarray is bigger than the biggest sum of the previous subarrays, then update the target's value.
            if(tmp > target){
                target = tmp;
            }
        }
        // In case that all numbers in nums are not bigger than 0, return the biggest number in nums.
        if(target == 0){
            target = nums[0];
            for(int i = 1; i< nums.size(); i++){
                if(nums[i] > target)
                    target = nums[i];
            }
        }
        return target;
    }
};
