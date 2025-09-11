class Solution {
public:
    string sortVowels(string s) {

        // lage haath saare vowels bhi nikal lo
        string vow="";

        for(auto it:s){
            if(it=='a' || it=='e' ||it=='i' ||it=='o' ||it=='u' ||it=='A' ||it=='E' ||it=='I' ||it=='O' ||it=='U') vow+=it;
         
        }

        // vowel ko sort kardo
        sort(vow.begin(),vow.end());

        // ek iterator j leke chalo which will iterate over the vowels
        int j=0;

        // ab dono par iterate karo at the same time, make ans
        for(int i=0;i<s.size();i++){
            auto it=s[i];
            if(it=='a' || it=='e' ||it=='i' ||it=='o' ||it=='u' ||it=='A' ||it=='E' ||it=='I' ||it=='O' ||it=='U'){
                // matlab vowel hai ye, yaha jo char hai replace with vowel frm sorted vowel string
                s[i]=vow[j];
                j++;
            }
        }

        return s;
    }
};