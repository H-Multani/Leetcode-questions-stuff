class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // toh basically make an array of size 26 and simulate on it t times

        // toh initially saare char ki freq add krdo, ab s ka kaam khatam

        // phir uss size 26 ke array par t baar iterate karenge updating stuff
        // as we go

        // isse kya hoga ki string manipulate nai karna padega, and since char+1
        // hi karna hai har iteration me toh usko simulate karte jayenge

        // like for eg, in eg1 s='abcyy' toh iska array banega
        // [a:1,b:1,c:1,y:2], ab apan ko 2 baar iss par iterate krke aadge
        // badhna hai

        // ek empty array lenge apan jo new values ka count rakhega

        // in iteration 1->
        // a:1, hai toh 1 A ko apan b kar denge, toh b++ kar
        // denge new array me apan toh new array is [b:1],
        // next original me b:1,hai toh 1 B ko apan c kar denge, toh c++ kar
        // denge new array me new array=[b:1,c:1]
        // next original me c:1,hai toh 1 c ko apan d kar denge, toh d++ kar
        // denge new array me new array=[b:1,c:1,d:1]
        // next original me y:2,hai toh 2 Y ko apan Z kar denge, toh z+=2 kar
        // denge new array me new array=[b:1,c:1,d:1,z:2]
        // ab apan ne 1 iteration me saare changes apply kar diye hai (eg1 me
        // dekho, first transformation ke baad wala string follows this new freq
        // array)

        // now replace original array with this new updated array
        // now original=[b:1,c:1,d:1,z:2], onto iteration 2

        // iteration 2->
        // b:1, hai toh 1 B ko apan c kar denge, toh c++ kar
        // denge new array me apan toh new array is [c:1],
        // next original me c:1,hai toh 1 c ko apan d kar denge, toh d++ kar
        // denge new array me new array=[c:1,d:1]
        // next original me d:1,hai toh 1 d ko apan e kar denge, toh e++ kar
        // denge new array me new array=[c:1,d:1,e:1]
        // next original me z:2,hai toh 2 Z ko apan 'ab' kar denge, toh
        // a+=2,b+=2 kar denge new array me new array=[c:1,d:1,e:1,a:2,b:2]

        // we did this since apan ko bola h questn me ki z is to be replaced by
        // 'ab', toh 1 z is replaced by 1 a and 1 b, hence for 2 z, we add 2 a
        // and 2 b

        // at end we have freq array as [c:1,d:1,e:1,a:2,b:2], which is the
        // exact freq of chars we get after 2nd transformation in eg1, ab bss in
        // saari freq ko add krna h and return as ans hence in this case
        // ans=1+1+1+2+2=7 which checks out

        vector<int> freq(26, 0);

        int mod=1e9+7;

        // initial freq s se insert karo
        for (auto it : s)
            freq[it - 'a']++;

        // ab t jitne iterations chalao
        while (t--) {
            // iss iteration me we iterate over the freq array and
            // simultaneously make a new freq array

            vector<int> newfreq(26, 0);

            for (auto i = 0; i < 26; i++) {
                int val = freq[i];
                if (i == 25) {
                    // means z hai current banda, toh new me a+=val hoga and
                    // b+=val hoga since 1 z is replaced by 1 a and 1 b, toh 3 z
                    // are to be replaced by 3 a and 3 b in nre freq

                    // toh newfreq me a ka freq+=val kardo
                    newfreq[0]=(newfreq[0]+val)%mod;
                    // and b ka freq bhi+=val kardo
                    newfreq[1]=(newfreq[1]+val)%mod;
                } else {
                    // we here means curr char is a,b,c,...y, in me +1 ka
                    // transformation hoga bas

                    // toh agar 1 a tha, it will become 1 b
                    // agar 1 c tha, it will become 1 d
                    // agar 1 l tha, it will become 1 m and so on

                    // toh agar 3 a the, it will become 3 b,
                    // agar 5 c tha, it will become 5 d

                    // vahi karna hai
                    // ie i+1 th char me +=val karna hai new freq me

                    // since a ka freq = freq[0], this will become b ka freq ie
                    // freq[1]

                    // essentially curr char(at idx i) ka jitna freq hai newfreq
                    // me idx i+1 ka freq banega
                    newfreq[i + 1]=(newfreq[i+1]+val)%mod;
                }
            }

            // ab 1 transformation ke baad freq array update ho chuka hai, this
            // new freq array will be used as original array for next iteration,
            // hence replace old freq array with new freq array
            freq = newfreq;
        }

        // ab saare transformations ho chuke hai, and freq updated hai, jitne
        // char hai sabka freq ka sum will be the size of final string, toh add krke return krdo
        int ans=0;
        for(auto it:freq) ans=(ans+it)%mod;

        return ans;
    }
};