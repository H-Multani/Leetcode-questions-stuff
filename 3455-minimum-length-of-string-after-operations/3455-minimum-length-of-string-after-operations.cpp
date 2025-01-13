class Solution {
public:
    int minimumLength(string s) {
        // simple soln hai, har char ko pakad kar right and left wala instance
        // alag karna hai

        // toh end me kitne bhi bande ho current char ke, end me 2 hi
        // bachenge(unless already 1 ho)

        // so for eg if freq of 'a' is 5, then beech wala 'a' pakad kar aaju
        // baaju alag karenge, toh 5 se 3 instances bache 'a' ke, again beech
        // wala leke alag kiye toh, 1 instance bacha 'a' ka, isse kam nai kar
        // sakte, toh 1 instance bachega 'a' ka which cant be removed, toh aise
        // karke saare char ke instances alag karunga such that aur freq kam na
        // kar paaye, phir end me saare freq ttl karke ans bhj dunga

        unordered_map<char,int> freq;

        for(auto it:s){
            freq[it]++;
        }

        // ab har char ka freq kam karte jao 2 se until reach under 3
        int ans=0;
        for(auto it:freq){
            int curr=it.second;
            while(curr>=3){
                curr-=2;
            }
            ans+=curr;
        }

        return ans;
    }
};