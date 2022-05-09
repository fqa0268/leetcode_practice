class Solution {
public:
    string longestPalindrome(string s) {
        string target = "";
        // start from the first character
        for(int i = 0; i <s.length();i++){
            string tmp = "";
            // find the longest continuous repeated character
            // e.g. each of the longest continuous repeated character in "babad" is 'b', 'a', 'b', 'a', 'd'
            // e.g. each of the longest continuous repeated character in "cbbvvvd" is 'c', 'bb', 'vvv', 'd'
            int j = i+1;
            while(s[i]==s[j]){
                j++;
            }
            int k = i-1;
            // check whether the pair of characters on both sides of the longest continuous repeated character is the same.
            while(k>=0 && j< s.length() && s[k]==s[j]){
                k--;
                j++;
            }
            // after while loop, we found a palindromic substring and then examine whether its length is longer than the longest palindromic substring found before.
            // if yes, update the target string.
            if(j-k-1 > target.length()){
                target.assign(s, k+1, j-k-1);
            }
        }
        return target;
    }
};
