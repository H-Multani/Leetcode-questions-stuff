class Solution {
public:
    vector<int> minOperations(string boxes) {
        // optimal soln, prefix bana lena

        // sabse pehle 2 prefix banao, for left to right, and right to left, ie,
        // left se right current idx par kitne bande laane hai
        int n = boxes.size();
        vector<int> ltor(n, 0), rtol(n, 0);
        // lotr[i]=4 means, 0 se leke,i-1 tak me 4 bande hai, basically i idx
        // par apan ko left side se 4 bande laane hai(excluding i par already
        // baitha banda), similarly with rtol[i]=5 means right se i idx par apan
        // ko 5 bande laane hai (i th par already baitha banda not counted)
        for (int i = 1; i < n; i++) {
            ltor[i] = ltor[i - 1] + (boxes[i - 1] - '0');
        }
        for (int i = n - 2; i >= 0; i--) {
            rtol[i] = rtol[i + 1] + (boxes[i + 1] - '0');
        }
        // ab steps chahiye hai har bande ko laane me kitna staps lagega

        // ab lets take rtol of eg2 which is {3,3,2,2,1,0}, iske liye steps
        // nikalne ka logic likhunga

        // lets take for rt to left for idx 3 ie idx 3 par bande laane me kitne
        // steps lagenge, idx 3 ke liye apan ko 2 cheez needed firstly idx 3 par
        // kitne bande aane hai ie rtoi[3], and pichle idx(here, its idx 4 since
        // rt to left jaa rhe apan) par kitne steps lage the(more on this later)

        // for idx 3, rtoi[3]=2, ie idx 3 par 2 bande aane hai, maan lo ye 2
        // bande idx 4 par khade hai abhi, toh inn 2 bando ko idx 4 se idx 3 par
        // laane ke liye 2 steps lagenge total(1 for each banda), toh ye 2 added
        // to step cnt for current idx 3, abb unn 2 bando ko idx 4 par laane me
        // kitne steps lage, steps_rtol[4]=1 jitne steps lage, toh unko bhi
        // count karenge na current idx ke ttl steps ke liye

        // essentially steps[3]=(steps taken to get rtoi[3](ie 2) bande frm idx
        // 4 to idx 3)+(steps taken to get the 2 ppl frm their location whatever
        // it is to idx 4 in the first place),

        // this works prefix sum me, ie eg 2 ke liye dekh lo rt to left me hi,
        // idx 5 par right se koi nai aane wala toh uske liye steps 0 honge,
        // phir idx 4 ke liye idx 5 se jitne bande aayenge sbke liye +1, phir
        // idx 5 par laane me 0 steps lage, vo count karlo, aise karte karte
        // pura step array ban jayega

        // for general formula,
        // steps_rtol[i]=rtol[i]+steps_rtol[i+1];

        // ye ho gaya right to left ke step count karne ke liye, similarly left
        // to right step count ke liye formula hoga
        // steps_ltor[i]=ltor[i]+steps_ltor[i-1];
        
        // now for eg 2 we have steps_rtol[3]=3, and steps_ltor[3]=1, ie saare
        // bando ko right se i par laane me 3 steps lagenge, and saare bando ko
        // left se laane me 1 step lagega
        // total steps taken to get all ppl(frm left and rt side) to idx i will
        // be ans[i]=steps_rtol[3]+steps_ltor[3], which will be 3+1=4, which
        // also checks out in the required output array

        // yehi karna hai
        vector<int> steps_rtol(n,0),steps_ltor(n,0);
        for(int i=1;i<n;i++){
            steps_ltor[i]=steps_ltor[i-1]+ltor[i];
        }
        for(int i=n-2;i>=0;i--){
            steps_rtol[i]=steps_rtol[i+1]+rtol[i];
        }
        // ans bana do ab
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=steps_ltor[i]+steps_rtol[i];
        }

        return ans;
    }
};