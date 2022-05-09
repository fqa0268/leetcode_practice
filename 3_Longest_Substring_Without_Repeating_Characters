class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int target = 0;
        string tmp = ""; // temporarily store the substring with no repeating characters
        for(int i=0; i < s.length(); i++){
            tmp += s[i];
            // check whether the current last character is the same as any other one in tmp.
            for(int j = 0; j < tmp.length()-1; j++){
                // if finding a character before the last poistion is the same as the last one,
                // then check whether the current length of tmp (exclusive of the last character) is bigger than the target (the longest length of substrings found before)
                // after checking, deleting the previous repeated character and the ones before it. Then, continue to check other substrings.
                if(tmp[j] == s[i]){
                    if(tmp.length()-1 > target)
                        target = (int) tmp.length()-1;
                    tmp.erase (tmp.begin(), tmp.begin()+j+1);
                    break;
                }
            }
        }
        // check the final substring with no repeated character.
        if(tmp.length() > target) 
            target = (int) tmp.length();
        return target;
    }
};
