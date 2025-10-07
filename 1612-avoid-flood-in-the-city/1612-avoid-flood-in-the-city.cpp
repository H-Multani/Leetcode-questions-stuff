class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        vector<int> ans(n, -1);

        // full lakes set me store nai kar sakte apan ab since we need most
        // recent fill idx of current lake as well
        unordered_map<int, int> full;

        // ek set store karlo which will
        // store ki konse days me dry spell hai apne paas, which can be used
        set<int> dry;
        // ek boolean array use karlo which will store ki current wala idx used
        // up already

        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                // we here means yaha baarish hogi, rains[i] wali lake me

                // 2 cases,

                // case 1, first time raining here,
                if (full.find(rains[i]) == full.end()) {
                    // means dry hai, laga do rain
                    full[rains[i]] = i;
                    // this basically means ki rains[i] wali lake filled at idx
                    // i(filled at day i )

                } else {
                    // case 2
                    // means yaha flooding hori hai, agar koi dry lake bana
                    // sakte hai toh use karlo

                    // dry spell ke liye bhai current lake ka last time full
                    // karne wala idx nikalo
                    int prev = full[rains[i]];

                    // ab we need to find dry spell ka index which came right
                    // after this prev idx, so that jab dry spell aaye, tab ye
                    // prev wala lake actually full bhi ho, nai toh WA testcase
                    // wala dikkat ho jayega which is already dry lake par dry
                    // spell laga rahe

                    auto idx = dry.lower_bound(prev);

                    if (idx == dry.end()) {
                        // we here means nai mila dry spell such that the spell
                        // came after we filled the lake last time

                        // in such case current wali lake me flooding hogi
                        // pakka, in such case return empty arr
                        return {};
                    }

                    // we here means ki mil gaya spell such that the spell came
                    // after pond was filled last time
                    int val = *idx;

                    // ab iss spell ka use karke ye lake ko pehle dry karenge
                    // then new fill karenge

                    // dry kardo, basically use dry spell on lake rains[i]
                    ans[val] = rains[i];

                    // ab lake is dry, fill lake again at current idx/day i
                    full[rains[i]] = i;

                    // ye purana spell is now used up, remove from set
                    // or we can mark the value as -1 to indicate ki ye wala spell now used 
                    // dry[idx-dry.begin()]=-1;
                    dry.erase(val);
                    // removal takes time alag kardo
                }
            } else if (rains[i] == 0) {
                // we here means apan current wali lake ka dry spell dusri lake
                // me use kar sakte hai, store in set index
                dry.insert(i);
            }
        }

        // ab agar dry spells bache hai toh rains[0] wali lake ko dry kardo aur
        // kya

        // okay nai kar sakte ye, toh apan ko first actual lake dhundna padega
        // usko empty kar sakte hai apan

        // since its possible ki rains[0] is a dry spell and not a lake loll
        int dryidx = 0;
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0) {
                dryidx = i;
                break;
            }
        }
        for (auto it : dry) {
            if(it==-1) continue;
            ans[it] = rains[dryidx];
        }

        return ans;
    }
};