class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> nextLarger;
        vector<int> result(temperatures.size());
        for(int i = temperatures.size() - 1; i >= 0; i--){
            while(!nextLarger.empty() && temperatures[i] >= temperatures[nextLarger.top()]){
                nextLarger.pop();
            }
            if(nextLarger.empty()){
                result[i]=0;
            }
            else {
                result[i]=nextLarger.top() - i;
            }
            nextLarger.push(i);
        }
        return result;
    }
};