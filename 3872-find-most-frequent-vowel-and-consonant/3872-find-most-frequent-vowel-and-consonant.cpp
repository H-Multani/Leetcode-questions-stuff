class Solution {
public:
    int maxFreqSum(string s) {
        if(s.size()==0) return 0;

        unordered_map<char,int> mpp1;// for vowel
        unordered_map<char,int> mpp2;// for consonant

        for(auto it:s){
            if(it=='a' || it=='e' || it=='i' || it=='o' || it=='u') mpp1[it]++;
            else mpp2[it]++;
        }

        int m1=0,m2=0;

        for(auto it:mpp1){
            if(it.second>m1) m1=it.second;
        }
        for(auto it:mpp2){
            if(it.second>m2) m2=it.second;
        }

        return m1+m2;
    }
};