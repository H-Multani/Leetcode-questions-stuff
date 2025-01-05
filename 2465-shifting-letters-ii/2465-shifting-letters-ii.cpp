class Solution {
public:
    void update(char& ch, int val) {
        // possible hai ki val>26 ho, in such case agar "v" se chalu karke aage
        // ya peeche 26 baar jaaye toh vapas "v" par hi aake rukenge, in such
        // case, 26 ke upar ka koi value kaam ka nai hai, kaam ka value hai
        // remainder, which determine overall kitna age peehce jana hai

        // toh val ko update kardo such that its now under the 26 range of
        // alphabet
        val=val%26;
        if (val > 0) {
            // aage badhana hai curr character

            // curr char se end(z) tak ka range kitna hai
            int range = 'z' - ch;

            // agar val>range, means 'z' ke baad phir se "a" se chalu karna
            // padega
            if (val > range) {
                // "a" se chalu karke val-range characters aage badhao bass,
                // since ttl val jitne char aage badhane hai, and range jitne
                // char lag jaenge ch se "z" laane me, bacha val-change, "a" se
                // aage badhenge
                ch = (char)('a' + (val - range - 1));
            } else {
                // means val<=range, ie atmost 'z' tak jayega, lee jao yahi se
                ch += val;
            }
        } else {
            // peeche bhejna hai curr character

            // curr se "a" tak range kitna hai
            int range = ch - 'a';

            // agar abs(val)>range, means 'a' ke baad phir se "z" se chalu karna
            // padega, backward aake
            if (abs(val) > range) {
                // abs(val)-range jitna peeche jao 'z' se , jaise upar 'a' se
                // itna hi aage badh rhe hai, reason same hai but instead of "z"
                // ye baad "a", here we go "a" ke baad "z"
                ch = (char)('z' - (abs(val) - range - 1));
            } else {
                // means val<=range, ie atmost 'a' tak jayega, lee jao yahi se
                // no need to circle anything back
                ch -= abs(val);
            }
        }
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // toh dekho har shift ko separate separate implement karne me tle de
        // dega pakka pakka, toh better hai ki apan ek array me store kar lete
        // hai jo bhi indexes me changes karne hai, phir ek baar me string me vo
        // change kar denge, for forward we do +1, for backward we do -1

        // so for eg1, the change array would look like following, initially
        // change={0,0,0}, ie koi bhi idx par koi change nai karna hai
        // shift 1-> change={-1,-1,0}
        // shift 2-> change={-1,0,1}
        // shift 3-> change={0,1,2}, ye changes karne hai
        // so s[0], me no change
        // so s[1], me change to next char(since changes[1]=1)
        // so s[2], me change to next char 2 times(since changes[2]=2)

        // ab ye change array banane ke 2 methods,
        // method 1, start with empty array, har shift par jao, uss shift ke
        // hisaab se changes array update kardo, do with each shift, like
        // {0,0,2,2,2,0} and {0,-1,-1,-1,0,0} 2 shifts ko join karenge toh we
        // get {0,-1,1,1,2,0}, ab ye karte jao, phir end me changes apply kar
        // dena s me, however this may give tle, since har shift ka length can
        // span the length of whole array, toh tle de dega, instead we do method
        // 2

        // method 2: start with empty array, of size n+1, ab har shift me bas
        // following karo foe g shift is {2,4,1}, which will change like
        // {0,0,1,1,1,0}, toh ye karne se accha apa, sirf 2 idx par change
        // karenge, idx 2 and idx 4+1=5
        // at idx 2 we do +1, and at idx 5 we put -1, so change looks like
        // {0,0,1,0,0,-1}, toh isse kya hoga 1 operation lga bass, ab isme
        // prefix sum laga do we get {0,0,1,1,1,0} which is what we required

        // essentially for shift {i,j,1} we do changes[i]+=1, changes[j+1]-=1
        // and for shift {i,j,0} we do changes[i]-=1, changes[j+1]+=1
        // this j+1 is the reason why apan n+1 size ka array le rhe hai prefix
        // ke liye

        // applying this on shfts={2,4,1} and {1,3,0}, normal answer should be
        // {0,0,1,1,1,0} and {0,-1,-1,-1,0,0}=> {0,-1,0,0,1,0}
        // by method 2, changes={0,0,0,0,0,0,0}(n+1 size)
        // shift 1-{2,4,1}->changes={0,0,1,0,0,-1,0}
        // shift 2-{1,3,0}->changes={0,-1,1,0,+1,-1,0}
        // end me changes array be like {0,-1,1,0,+1,-1,0}, iss par prefix sum
        // lagao, we get {0,-1,0,0,1,0,0}, and n elements dekho bas we get
        // {0,-1,0,0,1,0}, which is same as the answer we should have gotten,
        // matlab kaam karega ye, laga lo

        // by this method, shifts ko process karne me time kam lagega, each
        // shift will take O(1) time, which was earlier O(n)

        int n = s.size();
        vector<int> prefix(n + 1, 0);
        for (auto it : shifts) {
            int start = it[0];
            int end = it[1] + 1;
            bool addn;
            if (it[2]) {
                // +1 karna hai
                prefix[start] += 1;
                prefix[end] -= 1;
            } else {
                // -1 karna hai
                prefix[start] -= 1;
                prefix[end] += 1;
            }
        }
        // ab prefix sum chala do
        for (int i = 1; i < n + 1; i++) {
            prefix[i] += prefix[i - 1];
        }

        // ab prefix array ke first n elements me apne paas changes ka frequency
        // hai, laga do changes
        for (int i = 0; i < n; i++) {
            // char is
            char ch = s[i];
            // change to be done
            int changes = prefix[i];

            // agar koi changes nai hai aage badho
            if (changes == 0)
                continue;

            // apply change to character
            update(ch, changes);

            // updated character ko s[i] me daal do, apan saare changes original
            // s me hi kar rhe hai
            s[i] = ch;
        }
        return s;
    }
};