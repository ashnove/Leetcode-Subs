class Solution {
public:
    bool isOperation(string token){
        return (token=="+"||token=="-"||token=="/"||token=="*");
    }
    int performOperation(int num1, int num2, string operand){
        switch(operand[0]){
            case '+':
                return num1 + num2;
            case '-':
                return num2 - num1;
            case '*':
                return num2 * num1;
            default:
                return num2 / num1;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens){
            if(isOperation(token)){
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                s.push(performOperation(num1, num2, token));
            }
            else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};