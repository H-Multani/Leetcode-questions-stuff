class Solution {
public:
    int n;
    string ans;
    set<string> st;

    void solve(int idx, string& currans) {
        // void le rahe hai, lekin bool bhi le sakte hai since apan ko first
        // possible ans bhejna hai bass, questn says ki any possible ans bhej do
        // lekin mai bss first possible ans bhej rha

        // base case
        // minor optimization, agar ans mil chuka hai return frm here itself,
        // aage mt chk kro
        if (!ans.empty())
            return;
        if (idx >= n) {
            // means ek possible answer ready hai, 2 options hai yaha

            // option 1
            // the answer is already in the set, means its useless to us since
            // we already have it

            // option 2, currans string is not in set means new string hai that
            // does not appear in nums, this is our answer
            if (st.find(currans) == st.end()) {
                // means curr string nai hai set me, ie this string is not in
                // nums, its answer, bhar do

                // assign function since currans pass by reference hai, can be
                // changed, causing problems, toh copy karlo contents
                ans.assign(currans);
            }

            // we here means ya ans nums me tha ya nai tha, either way, aage nai
            // jaa skte ab aur, return
            return;
        }

        // now apne paas 2 options hai current bande ke liye, either current
        // banda becomes 0 or becomes 1, 2 cases hai dono dekho

        // simple backtracking, try, explore, undo

        // set current idx banda to '0'
        // TRY
        currans[idx] = '0';
        // EXPLORE
        solve(idx + 1, currans);
        // UNDO
        currans[idx] = 'a';
        // ab 0 bana kar dekh liya

        // ab 1 bana kar dekho curr bande ko
        currans[idx] = '1';
        // EXPLORE
        solve(idx + 1, currans);
        // UNDO
        currans[idx] = 'a';

        // bass bhai 2 options the current idx ke liye, dono explore krke dekh
        // liya nai chale toh kya hi kar sakte hai ab, return krdo aur kya

        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        // similar to lc 2375 and lc 1415, bas only difference is har n size ka
        // string banao, jo bhi ans strings banenge, the first one that isnt in
        // nums is our answer, return it
        n = nums.size();

        // nums size ka temporary string banao, which will store all possible
        // asnwers and will be manipulated to make all the possible answers
        string curr = "";
        // intially saare 'a' bhar do
        for (int i = 0; i < n; i++)
            curr += 'a';

        // ab ans string bana do empty
        ans = "";

        // nums ke saare elements set me daal do, so that checking krne me
        // problem na jaaye answer ko
        for (auto it : nums)
            st.insert(it);

        // funccn chla do, send in function,starting idx 0, curr string we have
        // made, thats all thats needed
        solve(0, curr);

        return ans;
    }
};