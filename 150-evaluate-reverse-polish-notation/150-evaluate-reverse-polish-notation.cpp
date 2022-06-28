class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int)>> operation = {
            { "+", [](int a, int b) { return a + b; } },
            { "-", [](int a, int b) { return a - b; } },
            { "/", [](int a, int b) { return a / b; } },
            { "*", [](int a, int b) { return a * b; } },
        };
        stack<int> s;
        for(string token : tokens){
            if(operation.count(token)){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                s.push(operation[token](num2, num1));
            }
            else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};