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
            const auto &op = operation.find(token);
            if(op != operation.end()){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                s.push((*op).second(num2, num1));
            }
            else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};