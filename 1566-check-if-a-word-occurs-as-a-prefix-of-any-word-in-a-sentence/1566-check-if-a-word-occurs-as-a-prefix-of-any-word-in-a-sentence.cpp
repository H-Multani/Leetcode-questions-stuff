class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // searchword ka size rakh lo let this be reqdn
        // phir sentence har word me check karo if start se reqdn size ka
        // substring same as searchword, agar kahi yes milta hai toh uss word ka
        // index return kardo
        // agar kahi nai milta hai toh end me -1 return krdo
        int reqdn = searchWord.size();

        // first sentence se word array banao, so that word ka index easily mil
        // jaaye
        vector<string> vec;
        string curr = "";
        for (auto it : sentence) {
            if (it != ' ') {
                curr += it;
            } else {
                vec.push_back(curr);

                curr = "";
            }
        }
        if(curr.size()>0) vec.push_back(curr);
        for(auto it:vec){
            cout<<it<<" ";
        }
        cout<<endl;

        for (int i = 0; i < vec.size(); i++) {
            // reqdn size ka subarray nikalo current word se

            // agar current word ka size<reqdn means searchword iss word se bada
            // hai toh reqfix kaise banega searchword, iss word me ans nai ho
            // sakta hence continue to next word
            if(vec[i].size()<reqdn) continue;

            if(vec[i].substr(0,reqdn)==searchWord) return i+1;
        }

        return -1;
    }
};