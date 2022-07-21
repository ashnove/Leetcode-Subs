class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        for(int i = 1; i < numRows; i++){
            ans.push_back({1});
            for(int j = 0; j < ans[i - 1].size() - 1; j++){
                ans.back().push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            ans.back().push_back(1);
        }
        return ans;
    }
};