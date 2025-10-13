class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // stack me lete chalo and compare karate chalna mast
        stack<string> s;

        for (auto it : words) {
            // agar current stack empty hai means kuch nai hai previous, add
            // kardo current wala
            if (s.empty()) {
                // current banda daal do aage badho
                s.push(it);
                continue;
            }

            // we here means empty nai hai, toh most recent wala banda adjacent
            // hi hoga, nums[i-1] wala hi hoga, compare with current wala
            // element if theyre anagrams

            // pichla banda nikalo and sort
            string prev = s.top();
            sort(prev.begin(), prev.end());
            // current banda nikalo and sort
            string curr = it;
            sort(curr.begin(), curr.end());

            if (prev == curr) {
                // means anagram hai, skip current banda and move to the next
                // banda
                continue;
            } else {
                // we here means ki anagram nai hai, normal neighbours hai, toh
                // stack me push kardo like normal
                s.push(it);
            }
        }

        // ab jitne bhi elements alag hone the sab alag ho chuke hai(as in stack
        // me daale hi nai) toh stack me pade elements hi bachenge ab, nikal kar
        // ans me daal do

        vector<string> ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        // ab stack se elements reverse order me nikalte hai toh ans ko ek final time reverse krdo
        reverse(ans.begin(),ans.end());
        return ans;
    }
};