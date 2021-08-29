#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n = x.size();
        stack<char> st;
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(x[i]=='{' || x[i]=='(' || x[i]=='[')
            {
                st.push(x[i]);
            }
            else if(x[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                }
            }
            else if(x[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                }
            }
            else if(x[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                }
            }

        }
        if(!st.empty())
            {
                return false;
            }
            else
            {
                return ans;
            }
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
