class Solution
{
    public:
    //Function to evaluate a postfix expression.
     int evaluatePostfix(string S)
   {
       // Your code here
       stack<int>st ;
       int res ;
       for( int i = 0 ; i < S.size() ; i++)
       {
           if(S[i] >='0' && S[i] <= '9')
           {
               st.push(S[i]-'0') ;
           }
           else {
               
               int num1 = st.top() ;
               st.pop() ;
               int num2 = st.top() ;
               st.pop() ;
               
               if(S[i]=='+')
               {
                   res = num2 + num1 ;
               }
               else if(S[i]=='-')
               {
                   res = num2 - num1 ;
               }
               else if(S[i]=='*')
               {
                   res = num2 * num1 ;
               }
               if(S[i]=='/')
               {
                   res = num2 / num1 ;
               }
               
               st.push(res) ;
           }
       }
       
       return   st.top()   ;
   }
};
