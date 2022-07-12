class Solution {
public:
    int minDeletions(string s) {
        vector<int> hash(26, 0);
        for(char ch : s){
            hash[ch - 'a']++;
        }
        vector<int> store;
        for(int i = 0; i < 26; i++){
            if(hash[i]) store.push_back(hash[i]);
        }
        sort(store.rbegin(), store.rend());
        int ans = 0;
        for(int i = 1; i < store.size(); i++){
            if(store[i] >= store[i - 1]){
                int was = store[i];
                store[i] = max(0, store[i - 1] - 1);
                ans += was - store[i];
            }
        }
        return ans;
    }
};