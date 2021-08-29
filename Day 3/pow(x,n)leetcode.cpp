class Solution {
public:
    double myPow(double x, int n) {
      double ans = 1.0;
      long long ref = n;
      if(ref<0)
      {
          ref = -1*ref;
      }
      while(ref)
      {
          if(ref%2!=0)
          {
              ans = ans*x;
              ref=ref-1;
          }
          else
          {
              x=x*x;
              ref=ref/2;
          }
      }
      if(n<0)
      {
          ans = (double)(1.0)/(double)(ans);
      }
     return ans;
    }
};
