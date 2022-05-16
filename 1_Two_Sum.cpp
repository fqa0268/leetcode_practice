vector<int> twoSum(vector<int>& nums, int target) {
    for(int i=0; i<nums.size(); i++){ // nums[i] is the 1st element to be checked
        for(int j=i+1; j<nums.size(); j++){ // nums[j] is the 2nd element to be checked, and j starts from i+1 to avoid ckecking the same pairs.
            if(nums[i]+nums[j]==target){ // if the sum of the pair is equal to target, return the indexes.
                return vector<int> {i,j};
            }
        }
    }
    return vector<int> {};
}
