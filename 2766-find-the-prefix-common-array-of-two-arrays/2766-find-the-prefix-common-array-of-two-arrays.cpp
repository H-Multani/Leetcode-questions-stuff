class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        // brute force the way through

        // map me store karlo, ki current idx i tak kitne elements mile hai
        // common A and B se

        // instance store krna hai bss, unique needed bass
        unordered_set<int> stA, stB;

        vector<int> ans;
        int i = 0, j = 0, n = A.size();
        while (i < n && j < n) {
            // i th wala A se nikal kar set me store kardo
            stA.insert(A[i]);
            // j th wala B se nikal kar set me store kardo
            stB.insert(B[i]);

            // ab in dono ke beech me kitne elements common hai count kardo(yehi
            // bola hai question me)

            // since stA will have elements that have idx<=i, and stB will have
            // elements that have idx<=j

            // for ans[i], we need the number of elements that are present at
            // index<=i, in both A and B, toh essentially, dono me se common
            // elements count karne hai, ki abhi tak A and B me kitne elements
            // common hai, vahi hoga ans[i];

            int currans = 0;
            // initially maan lo 0 elements are common
            for (auto it : stA) {
                // kya yehi element B wale set me bhi hai??
                if (stB.find(it) != stB.end()) {
                    // means ye element A and B dono me hai, ie common hai, toh
                    // possible ans hai, currans me add kardo iss element vaaste
                    // 1
                    currans++;
                }
            }

            // ab jo bhi currans hai, utne elements common hai iss idx i tak,
            // such that both elements have idx<=i and the element is present in
            // both A and B, toh ye currans answer wale vector me update kardo
            ans.push_back(currans);

            // move to the next element
            i++;j++;
        }

        return ans;
    }
};