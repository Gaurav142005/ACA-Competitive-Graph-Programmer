
class Solution {
public:
    bool isValid(string s) {
        stack <int> state;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '(')
                state.push(1);
            
            else if(ch == '{')
                state.push(2);
            
            else if(ch == '[')
                state.push(3);
            
            if(!state.empty()){
                if(ch == ')'){
                    if(state.top() == 1)
                        state.pop();
                    else
                        return false;
                }

                else if(ch == '}'){
                    if(state.top() == 2)
                        state.pop();
                    else
                        return false;
                }

                else if(ch == ']'){
                    if(state.top() == 3)
                        state.pop();
                    else
                        return false;
                }
            }
            else
                return false;
        }
        if(!state.empty())
            return false;
        return true;
    }
};
