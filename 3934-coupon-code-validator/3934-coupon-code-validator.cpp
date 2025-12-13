class Solution {
public:
    bool valid1(string s) {
        // khali hai toh false
        if(s=="") return false;
        for (auto it : s) {
            if ((it >= '0' && it <= '9') || (it >= 'a' && it <= 'z') ||
                (it >= 'A' && it <= 'Z') || it == '_') {
                // means alphanueric hai, agel char par jao
            }
            // we here means special characters hai toh its not valid return
            // false
            else
                return false;
        }

        return true;
    }
    bool valid2(string s) {
        // khali hai toh false
        if(s=="") return false;
        if (s == "electronics" || s == "grocery" || s == "pharmacy" ||
            s == "restaurant")
            return true;

        return false;
    }

    static bool comp(vector<string>& v1, vector<string>& v2) {
        if (v1[1] == v2[1]) {
            // means businessline same hai sort accd to lexicographical code

            // ascending order me rakhna hai toh agar v1 has lexicographical
            // smaller code than v2, toh its in correct position , otherwise its in wrong position
            return v1[0]<v2[0];
        }

        // we here means businessline order me nai hai sort kardo
        
        // electoronics ko sort kardo
        if(v1[1]=="electronics" && v2[1]=="grocery") return true;
        if(v1[1]=="electronics" && v2[1]=="pharmacy") return true;
        if(v1[1]=="electronics" && v2[1]=="restaurant") return true;

        // grocery ko sort karo
        if(v1[1]=="grocery" && v2[1]=="restaurant") return true;
        if(v1[1]=="grocery" && v2[1]=="pharmacy") return true;
        if(v1[1]=="grocery" && v2[1]=="electronics") return false;


        // pharmacy ko sort karo
        if(v1[1]=="pharmacy" && v2[1]=="restaurant") return true;
        if(v1[1]=="pharmacy" && v2[1]=="grocery") return false;
        if(v1[1]=="pharmacy" && v2[1]=="electronics") return false;


        // restaurant ko sort karo
        if(v1[1]=="restaurant" && v2[1]=="pharmacy") return false;
        if(v1[1]=="restaurant" && v2[1]=="grocery") return false;
        if(v1[1]=="restaurant" && v2[1]=="electronics") return false;

        return false;

    }
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        // pehle toh valid walo ka ek array bana lo string ka fir dekhenge kais
        // sort karna hai
        vector<vector<string>> overall;

        int n = code.size();
        for (int i = 0; i < n; i++) {
            // valid wale daal do
            if (valid1(code[i]) && valid2(businessLine[i]) && isActive[i]) {
                // means its valid, daal do overall array me
                overall.push_back({code[i], businessLine[i]});
            }
        }

        // ab inko sort kardo based on the required comparator
        sort(overall.begin(), overall.end(), comp);

        // ab bass ans banano and bhej do
        vector<string> ans;

        for (auto it : overall) {
            ans.push_back(it[0]);
        }

        return ans;
    }
};