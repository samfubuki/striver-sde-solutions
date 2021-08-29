int Solution::divide(int A, int B) {
         long long int a = A;
         long long int b = B;
         int sign=0;
         if((a>0 && b<0) || (a<0 && b>0))
         {
             sign=1;
         }
         if(a<0)
         {
             a=-a;
         }
         if(b<0)
         {
             b=-b;
         }
         long long int ans=0,temp=0;
         for(int i=31;i>=0;i--)
         {
             if(temp+(b<<i)<=a)
             {
                 temp=temp+(b<<i);
                 ans+=((1ll)<<i);
             }

         }
         if(sign==1)
         {
             ans=-ans;
         }
         if(ans>INT_MAX || ans<INT_MIN)
         {
             return INT_MAX;
         }
        //  if (ans == 2147483648)
        //  {
        //      ans--;
        //  }
         return ans;
        }
