class Solution {
public:
    int strStr(string haystack, string needle) {
      int n = haystack.length();
      int m = needle.length();
      if(m==0)
      {
        return 0;
      }
    if(n==0)
    {
     return -1;
    }
    if( m > n)
    {
      return -1;
    }
      for(int i=0;i<=(n-m);i++)
      {
          bool flag=true;
          for(int j=0;j<m;j++)
          {
              if(needle[j]!=haystack[i+j])
              {
                  flag=false;
                  break;
              }
          }
         if(flag==true)
         {
             return i;
         }
      }
      return -1;

    }
};
