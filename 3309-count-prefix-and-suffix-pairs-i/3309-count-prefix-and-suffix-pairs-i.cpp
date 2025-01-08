class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int length=words.size();
        int count=0;
        for(int i=0;i<length;i++){
            string current=words[i];
            for(int j=i+1;j<length;j++){
                // if j.length<i.length do  nothing, like tstcase 3,otherwise do the foll
                if(words[j].size()>=current.size()){
                    // check if word[i] is present in word[j], if yes increase count
                    // dont just check if it simply present, check if i is present at the end of string j also
                    // otherwise for cases like ["a","abb"], this returns true which is not needed since it is prefix but not suffix
                    // so check from index 0 and also from index j.length-i.length, 
                    // like for ["aba","ababa"] we check from index 5-3=2 in string j for suffix and from index 0 for prefix
                    // and for case like ["a","abb"], we check from index 3-1=2 in string j for suffix and from index 0 for prefix,we check if string i is present in string j
                    if(words[j].find(current,words[j].size()-current.size())!=string::npos && words[j].starts_with(current)){
                        // words[j].find(current,words[j].size()-current.size())!=string::npos checks if it is suffix
                        // cant use above to check prefix since will search frm index 0 but chek the whole string and return the same answer as it did for suffix
                        // words[j].starts_with(current) checks if it is prefix
                        // cout<<i<<" "<<j<<endl;
                        count++;
                    }
                        
                }
                
            }
        }
        // cout<<endl<<endl;
        return count;
    }
};