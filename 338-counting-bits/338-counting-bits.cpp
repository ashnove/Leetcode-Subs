class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; i++){
            int n = i;
            int cnt = 0;
            while(n){
                n &= n - 1;
                cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};