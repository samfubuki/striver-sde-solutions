class Solution {
public:
    string intToRoman(int num) {
       string roman;
       if(num>=4000 || num<=0)
       {
           return roman;
       }
       string fives[3] = {"V","L","D"};
       string ones[4] = {"I","X","C","M"};
       int unitplace = 0;
       while(num>0)
       {
           int i = num%10;
           num/=10;
           if(i==1)
           {
               roman = ones[unitplace]+roman;
           }
           else if(i==2)
           {
               roman = ones[unitplace]+ones[unitplace]+roman;
           }
           else if(i==3)
           {
               roman = ones[unitplace]+ones[unitplace]+ones[unitplace]+roman;
           }
           else if(i==4)
           {
               roman = ones[unitplace]+fives[unitplace]+roman;
           }
           else if(i==5)
           {
               roman = fives[unitplace]+roman;
           }
           else if(i==6)
           {
               roman = fives[unitplace]+ones[unitplace]+roman;
           }
           else if(i==7)
           {
               roman = fives[unitplace]+ones[unitplace]+ones[unitplace]+roman;
           }
           else if(i==8)
           {
               roman = fives[unitplace]+ones[unitplace]+ones[unitplace]+ones[unitplace]+roman;
           }
           else if(i==9)
           {
               roman = ones[unitplace]+ones[unitplace+1]+roman;
           }
         unitplace++;
       }
      return roman;
    }
};
