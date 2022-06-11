class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        
        int revMap[100][100];
        memset(revMap, 0, sizeof revMap);
        for(auto e : mappings){
            revMap[e[1] - '0'][e[0] - '0'] = 1;
        }
        int n = s.size();
        int m = sub.size();
        // cout << n << " " << m << endl;
        bool ans = 0;
        for(int i = 0; i < n; i++){
            if(i + m - 1 >= n) break;
            int k = i;
            bool ok = 1;
            for(int j = 0; j < m; j++, k++){
                if(sub[j] != s[k]){
                    if(revMap[s[k] - '0'][sub[j] - '0']){
                        // temp[s[k]] = '#';
                    }
                    else {
                        ok = 0;
                    }
                }
            }
                // if(ok)
                // cout << i << " " << ok << endl;
            ans |= ok;
        }
        return ans;
        
    }
};