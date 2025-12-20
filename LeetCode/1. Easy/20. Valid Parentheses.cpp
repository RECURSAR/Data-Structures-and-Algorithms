class Solution {
public:
    bool isValid(string s) {
    stack<char> stack;
    int i=0, n = s.size(), flag = 0; 
    char c;

    while(i<n)
    {
        c = s[i];
        switch (c)
        {
        case '(':
                    stack.push(c);
                    break;
        
        case ')':
                    if(stack.empty()==1)
                    {
                        flag = 1;
                        break;
                    }
                        
                    if(stack.top()=='(')
                        {
                            stack.pop();
                            break;
                        }
                    else 
                        stack.push(c);
                    break;

        case '{':
                    stack.push(c);
                    break;
        
        case '}':
                    if(stack.empty()==1)
                    {
                        flag = 1;
                        break;
                    }
                        
                    if(stack.top()=='{')
                        {
                            stack.pop();
                            break;
                        }
                    else 
                        stack.push(c);
                    break;

        case '[':
                    stack.push(c);
                    break;
        
        case ']':
                    if(stack.empty()==1)
                    {
                        flag = 1;
                        break;
                    }
                        

                    if(stack.top()=='[')
                        {
                            stack.pop();
                            break;
                        }
                    else 
                        stack.push(c);
                        
                    break;
        default:
                    break;
        }

        i++;
    }
   
   if(stack.empty()==1 && flag==0)
    return true;
   
   else 
    return false;
    }
};