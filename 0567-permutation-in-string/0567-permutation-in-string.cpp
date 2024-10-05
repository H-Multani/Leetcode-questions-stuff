
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        // permutation me char ke freq doesnt change, use this
        unordered_map<char, int> s1_mpp;
        for (auto it : s1) {
            s1_mpp[it]++;
        }

        int n = s1.size();

        // since fixed window me search kar rhe the, hence can apply sliding
        // window same approach use karenge ki n size ka window banaenge pehle
        // toh, then check karenge

        // ek map bana lenge jo char ka freq store karega, and if we get n size
        // ka window + freq map all keys(and values) same as s1 ka map, means
        // apan ko mil gaya hai n size ka permutation s1 ka inside s2, in such
        // case return true
        unordered_map<char, int> s2_map;

        int left = 0, right = 0;
        while (right < s2.size()) {
            // current wale character ko map me daal do s2 ke
            s2_map[s2[right]]++;

            // if size of window is greater than n, means window not of correct
            // size, shrink karo window ko
            // size of window is right-left+1
            while (right - left + 1 > n) {
                // means window too big, shrink it
                s2_map[s2[left]]--;
                if (s2_map[s2[left]] == 0) {
                    // means curr char ka freq 0 ho gaya, alag kar do map se
                    s2_map.erase(s2[left]);
                }

                // left ptr ko aage badhao
                left++;
            }

            // now we have window of n size, and the corresponding updated map
            // s2 wala, if this s2 wala map same as s1 wala map, means current
            // window is the permutation of s1 that we needed, in such case
            // return true, else move on to the next window
            if(s1_mpp==s2_map) return true;

            // window aage badhao
            right++;
        }

        // we here means koi bhi window me nai mila permutation s1 ka, hence return false

        return false;
    }
};