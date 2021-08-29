vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        int x = -1;
        while(!s.empty() && s.top()>=A[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            x = s.top();
        }
      v[i]=x;
      s.push(A[i]);
    }
return v;
}
