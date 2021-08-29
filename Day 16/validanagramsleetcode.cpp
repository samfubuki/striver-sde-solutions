class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss = s.length();
        int tt = t.length();
        if(ss!=tt)
        {
            return false;
        }
        int freqS[26]={0};
        int freqT[26]={0};
        for(int i=0;i<ss;i++)
        {
            freqS[s[i]-'a']+=1;
            freqT[t[i]-'a']+=1;
        }
        for(int i=0;i<26;i++)
        {
            if(freqS[i]!=freqT[i])
            {
                return false;
            }
        }
      return true;
    }
};
