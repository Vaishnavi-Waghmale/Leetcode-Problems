class Solution {
public:
    int calculate(string s)
{
    stack<int> stk;
    stack<char> op;
    int n = s.length(), ans = 0;
    
    for( int i = n-1 ; i >= 0 ; i-- ){
        //neglect spaces
        if( s[i] == 32 ){
            continue;
        }
        //operate bracket
        else if( s[i] == '(' ){
            int v = 0;
            while( op.top() == 'd' ){
                v += stk.top();
                stk.pop();
                op.pop();
            }
            
            if( op.top() == ')' ){
                op.pop();
            }
            stk.push(v);
            op.push('d');
        }
        
        else if( isdigit(s[i]) ){
            int j = i;
            stack<int> num;
            
            while( j >= 0 && isdigit(s[j]) ){
                num.push((s[j]-'0'));
                j--;
            }
            
            int v = 0;
            while( !num.empty() ){
                v *= 10;
                v += num.top();
                num.pop();
            }

            stk.push(v);
            op.push('d');
            i = j+1;
        }
        else if( s[i] == ')' ){
            op.push(s[i]);
        }
        //multiply top of stl with -1;
        else if( s[i] == '-' ){
            int a = stk.top() * ( -1 );
            stk.pop();
            stk.push(a);
        }
        
    }
    
    while( !stk.empty() ){
        ans += stk.top();
        stk.pop();
    }
    return ans;
}
};
