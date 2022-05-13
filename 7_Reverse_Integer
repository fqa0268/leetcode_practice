class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        // assign the units digit of x to ans, and then drop the units digit of x.
        ans = x%10;
        x /= 10;
        int cnt = 1;
        // reverse the rest digits of x to ans, and do it until completing the 9th digits 
        while(x != 0 && cnt < 9){
            ans *= 10;
            ans = ans + x%10;
            x /= 10;
            cnt++;
        }
        // handle the limits
        if(x!=0 && abs(ans) > 214748364 || (abs(ans) == 214748364 && (x%10 > 7 || x%10 < -8))){
                return 0;
        }else if(x!=0){
            ans = ans*10 + x%10;
        }
        return ans;
    }
};
