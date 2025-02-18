class Solution {
public:
    bool valid(string temp, string pattern) {
        int n = temp.size();

        for (int i = 0; i < n - 1; i++) {
            if ((temp[i] < temp[i + 1] && pattern[i] == 'D') ||
                (temp[i] > temp[i + 1] && pattern[i] == 'I'))
                return false;
        }

        return true;
    }
    string smallestNumber(string pattern) {
        // isme vahi brute force chal jaega, shayad, since constraints even
        // smaller hai lc 1718 wala brute force

        string ans;

        string temp = "";

        for (int i = 1; i <= pattern.size() + 1; i++) {
            temp += (char)('0' + i);
        }
        // initially temp="123456789" if pattern.size==8

        do {
            if (valid(temp, pattern)) {
                // jo sbse pehle aayega vahi minm string hoga, aage permute krne
                // ka need hi nai h, return krdo yahi se
                return temp;
            }
        } while (next_permutation(temp.begin(), temp.end()));

        return ans;
    }
};