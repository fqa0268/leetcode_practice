class Solution {
public:
    int trap(vector<int>& height) {
        // only two bars cannot trap any water.
        if(height.size() < 3) return 0;
        int water = 0;
        int i = 0, j = (int) height.size()-1;
        int barL = 0, barR = (int) height.size()-1;
        // The following concept is:
        // 1. i & j will move from the outer to the inner
        // 2. assume bar "barL" is no higher than bar "barR". move "i" to inner from "barL" for checking
        //    (1) if bar "i" is shorter than bar "barL", the location can contain (height[barL] - height[i]) units of water since bar "barR" is no shorter than bar "barL".
        //    (2) if bar "i" is higher than bar "barL", update the "barL" with "i".
        // 3. "j" & "barR" work in the same way.
        while(i < j){ // 刪掉了&& j > 0 && i< (int) height.size()，因為如果i<j，後面這兩件事就不可能發生
            while(height[barL] <= height[barR]){
                i++;
                if(height[i] > height[barL] || i == j){
                    barL = i;
                }else{
                    water += (height[barL] - height[i]);
                }
                if(j-i < 2) break;
            }
            if(j-i < 2) break;
            while(height[barL] > height[barR]){
                j--;
                if(height[j] > height[barR] || i == j){
                    barR = j;
                }else{
                    water += (height[barR] - height[j]);
                }
            }
        }
        return water;
    }
};
