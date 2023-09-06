class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int a;
        istringstream is(s);
        char op ='+';
        while(is>>a){
            if(op=='+' || op=='-') 
              st.push(op=='+' ? a: -a);
            else{
                int last= st.top();
                st.pop();
                if(op=='*') last*=a;
                else last/=a;
                st.push(last);
            }
            is>>op;
        }
        int sum=0;
        while(!st.empty()){
            sum+= st.top();
            st.pop();
        }
        return sum;
    }
};