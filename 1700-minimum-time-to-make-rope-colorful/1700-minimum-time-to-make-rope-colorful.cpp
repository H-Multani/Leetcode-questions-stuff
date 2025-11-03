class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        // aisa kar sakte hai ki agar consecutive baloons milte jaaye toh agar 3
        // balloons hai consecutive toh minm wale 2 values nikal lenge usme se
        // since itna minm time lagega, toh yehi kar sakte hai

        // do variable lelo ek overall sum ke liye ek max in range ke liye

        // like agar 4 consecutive baloons hai toh ek variable will store ki all
        // 4 baloons ke time ka sum kya hai, ad 2nd variable will store ki 4 me
        // se sabse zyada time khane wala baloon konsa hai toh usko ttl se alag
        // kar denge agar toh bacha hua tme lagega minm 4 baloons ko 1 karne ke
        // liye ie leaving the most time taking baloon

        int ans = 0;

        int ttl = 0, maxm = 0;
        // initially dono 0 kardo
        int n = colors.size();
        for (int i = 1; i < n; i++) {
            // agar same hai aaju baaju waale baloons
            if (colors[i] == colors[i - 1]) {
                // we here means ttl aur max ke saath khelna hai ab

                // toh yaha 2 cases hai first is yaha se start hora hai counting
                // consecutive in such case dono ke times ttl me add karne
                // padenge
                if (ttl == 0 && maxm == 0) {
                    // we here means dono ko ttl me add karo
                    ttl += nt[i];
                    ttl += nt[i - 1];
                }
                // second case is ye kahi beech me hai like 5 consecutive ke
                // range me se abhi apan 3 rd bande tak pahuche hai bss aage
                // jana baaki hai in such case in ttl only consider the current
                // element
                else {
                    // we here means current element ko add karo bss
                    ttl += nt[i];
                }

                // maxm update karo
                maxm = max({maxm, nt[i], nt[i - 1]});
            } else {
                // we here means color[i]!=color[i-1] means different color hai

                // yaha 2 cases bante hai ek me i-1 ke peeche consecutive ka
                // line hai(like idx 1-4 same then 5 is different color) ek me
                // nai hai(like idx 3,4,5,6, all different color in such case
                // nothing to remove)

                // agar ttl already 0 hai means 2nd wala case hai
                if (ttl == 0) {
                    // means second wala case hai nothing to remove nothing to
                    // be added to ans
                } else {
                    // we here means case 1 hai ie pehle consecutive item the
                    // jisme se alag karna hai apan ko, if n items the
                    // consecutive toh usme se n-1 items ko alag karna hai sabse
                    // bade time taking waale ko chhor kar

                    // toh ans me add krdo

                    // ttl-maxm, since this is the value we get after adding
                    // smallest n-1 values
                    ans += (ttl - maxm);
                }

                // ab ttl and maxm ko reset kardo to count next range of
                // consecutive elements
                ttl = 0;
                maxm = 0;
            }
        }

        // ab yaha case bana ek edge case ki consecutive end me hai like 4
        // baloons same color ke end end me hai , in such case iss position par
        // ttl==0 nai rahega, if ttl not zero means consecutive baloons hai
        // remove karo one last time
        if(ttl!=0){
            ans+=(ttl-maxm);
        }

        return ans;
    }
};