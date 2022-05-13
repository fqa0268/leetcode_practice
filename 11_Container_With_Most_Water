class Solution {
public:
    int maxArea(vector<int>& height) {
        int target = 0;
        int i = 0, j = (int) height.size()-1; // the index of container edges
        int left = 0, right = 0; // the height of container edges that are used to check the amount of water 
        while(i < j){
            // only when the height of inner edges is higher than that of outer edges, we check the amount of water 
            while(i<j && height[i] < left) i++;
            left = height[i];
            while(i<j && height[j] < right) j--;
            right =  height[j];
            int tmp = min(left, right)*(j-i);
            if(tmp > target) target = tmp;
            // on the shorter-edge side, move the index to its next inner edges first, and continue to look for a higher edge.
            if(left > right){
                j--;
            }else{
                i++;
            }
        }
        return target;
    }
};
