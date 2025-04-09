class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // agar koi bhi element k se chota hua toh usko k nai bana sakte apan,
        // in such case return -1
        if (*min_element(nums.begin(), nums.end()) < k)
            return -1;

        // we here means smallest element ko bhi k bana sakte hai apan

        // map me store karlo nums and freq ko
        map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;

        // ab map me agar 3 distinct element hai toh sabko k tak laane me 3
        // operations lagenge

        // for eg if map is like {3:2,4:2,5:2} and k=2, toh iss case me first
        // operation me h=4 lenge, toh saare 5 apne 4 ban jaenge, now we have
        // map as {3:2,4:4}, ab apan h=3 lenge, toh saare 4 apne 3 ban jaenge,
        // now we have map as {3:6}, ab since inn sabko k tak pahuchana hai toh
        // 1 operation aur lagega, here h=k=2 le lenge, toh saare 3 apne 2 ban
        // jaenge, so we have map like {2:6}, ttl operations=3(map ka size)

        // edge case, agar minm element==k hoga toh, map.size()-1 operations
        // lagenge

        // for eg , in eg 1 map is like {2:1,4:2,5:2}, 1st operation me h=4
        // lenge, toh saare 5 becomes 4, map is {2:1,4:4}, ab 2nd operation me
        // h=k=2 le lenge, toh saare 4 becomes 2, map is {2:6}, ttl no of
        // operations=mpp.size()-1

        // yehi logic laga do
        if(*min_element(nums.begin(),nums.end())==k) return mpp.size()-1;

        return mpp.size();
    }
};