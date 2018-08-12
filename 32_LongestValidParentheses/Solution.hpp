class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int currSum = 0;
        int sum = 0;
        for(int i = 0; i < s.length(); i++){
            if (s[i] == '(')
                stack.push_back(i);
            else{
                if (!stack.empty() && s[stack.back()] == '('){
                    stack.pop_back();
                    int lastOfStack = -1;
                    if (!stack.empty())
                        lastOfStack = stack.back();
                    currSum = i - lastOfStack;
                    if (currSum > sum)
                        sum = currSum;
                }
                else
                    stack.push_back(i);
            }
        }
        return sum;
    }
};
