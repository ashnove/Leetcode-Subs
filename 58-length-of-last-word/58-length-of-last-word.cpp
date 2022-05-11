class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int j = s.size() - 1;
        while(j >=0 && s[j] == ' ')j--;
        for(int i = j; i >= 0; i--){
            if(s[i] == ' ')break;
            len++;
        }
        return len;
    }
};