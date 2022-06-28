class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> nextLarger;
        vector<int> result;
        result.push_back(0);
        nextLarger.push(temperatures.size() - 1);
        for(int i = temperatures.size() - 2; i >= 0; i--){
            while(!nextLarger.empty() && temperatures[i] >= temperatures[nextLarger.top()]){
                nextLarger.pop();
            }
            if(nextLarger.empty()){
                result.push_back(0);
            }
            else {
                result.push_back(nextLarger.top() - i);
            }
            nextLarger.push(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};