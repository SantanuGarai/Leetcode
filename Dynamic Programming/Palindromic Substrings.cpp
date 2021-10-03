/*
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.

Example 1:
Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: s = "aaa"
Output: 6

Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int t[n][n];
        int ans = 0;
        for(int i=0;i<n;i++){
            t[i][i] = 1;
            ans += 1;
            if(i+1<n && s[i]==s[i+1]){
                t[i][i+1] = 1;
                ans += 1;
            }else if(i+1<n) 
                t[i][i+1] = 0;
        }
        for(int diff=2;diff<n;diff++){
            int i = 0;
            for(int j=i+diff;j<n;j++){
                if(s[i]==s[j] && t[i+1][j-1]){
                    t[i][j] = 1;
                    ans += 1;
                }else{
                    t[i][j] = 0;
                }
                i++;
            }
        }
        return ans;
    }
};

//another method

int count =1;
public int countSubstrings(String s) {
    if(s.length()==0) 
        return 0;
    for(int i=0; i<s.length()-1; i++){
        checkPalindrome(s,i,i);     //To check the palindrome of odd length palindromic sub-string
        checkPalindrome(s,i,i+1);   //To check the palindrome of even length palindromic sub-string
    }
    return count;
}    
private void checkPalindrome(String s, int i, int j) {
    while(i>=0 && j<s.length() && s[i]==s[j]){    //Check for the palindrome string 
        count++;    //Increment the count if palindromin substring found
        i--;    //To trace string in left direction
        j++;    //To trace string in right direction
    }
}
