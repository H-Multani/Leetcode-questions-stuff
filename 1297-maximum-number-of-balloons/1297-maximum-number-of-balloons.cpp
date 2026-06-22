class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // b,a,l,o,n ke freq nikal lo

        // b jitne baar aayega utne baar word bana sakte
        // a jitne baar aayega utne baar word bana sakte
        // n jitne baar aayega utne baar word bana sakte
        // l jitne baar aayega utne/2 baar word bana sakte(since l comes 2 times
        // in each word )
        // o jitne baar aayega utne/2 baar word bana sakte(since l comes 2 times
        // in each word )

        unordered_map<char, int> mpp;
        for (auto it : text) {
            mpp[it]++;
        }

        // ans nikal lo, minm lete chalna, since the word creation heavily
        // depends on how many characters will remain after each word

        // all in all character ka frequency batayega ki bottleneck kaha hogi,
        // if b is less, then jitne words banenge will depend on kitne b honge
        // text me

        // similarly with b,a,n-> each b,a,n means 1 word ban payega
        // similarly with l,o-> 2 l,o means 1 word ban payega, since each word
        // me 2 L lagege and 2 O lagenge
        int ans=text.size();

        // b ka check karo
        ans=min(ans,mpp['b']);
        // a ka check karo
        ans=min(ans,mpp['a']);
        // n ka check karo
        ans=min(ans,mpp['n']);

        // l ka check karo, we need 2 for each word toh freq/2 words check karna
        ans=min(ans,mpp['l']/2);
        // o ka check karo, we need 2 for each word toh freq/2 words check karna
        ans=min(ans,mpp['o']/2);

        return ans;
    }
};