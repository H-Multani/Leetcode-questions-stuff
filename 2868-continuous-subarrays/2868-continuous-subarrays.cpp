class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        // sliding window hint 1,2 se
        int n = nums.size();
        int l = 0, r = 0;

        long long ans = 0;
        // int maxm=-1,minm=INT_MAX;

        // ye maxm and minm rakhna hint 2 ne bola
        // set that stores minm value of current subarray
        set<int> mx;
        // incase multiple instances of element exists
        unordered_map<int, int> mxfreq;

        // set that stores maxm value of current subarray
        set<int, greater<int>> mn;
        // incase multiple instances of element exists
        unordered_map<int, int> mnfreq;

        while (r < n) {
            // current bande ko include karo
            // maxm and minm update karo
            mx.insert(nums[r]);
            mxfreq[nums[r]]++;
            mn.insert(nums[r]);
            mnfreq[nums[r]]++;

            // now shrink window
            // shrink ka condn(what i can think of at least)
            // agar abs(maxm-minm)>2, toh shrink window(accd to condn given)
            // since saare pairs ka diff agar [0,2] hai toh maxm-minm ka bhi
            // inrange([0,2]) hona chahiye, for a valid subarray

            // and since maxm and minm are 2 different corners of the subarray,
            // toh agar ye range me hai means beech ke elements bhi range me
            // honge

            // hence agar range se bahar jaa rha hai, ie maxm-minm>2, means
            // subarray correct nai hai(window ke andar wala), in such case
            // shrink window
            // maxm=mx[0] OR mx.begin()
            // minm=mn[0] OR mn.begin()
            while (l <= r && abs(*mx.begin() - *mn.begin()) > 2) {
                // means window valid nai hai
                // shrink window

                // left wala element map se alag karo pehle(since possible hai
                // ki multiple instances ho window me)

                // maxm wale map se alag karo
                mxfreq[nums[l]]--;
                if (mxfreq[nums[l]] == 0) {
                    // freq of left wala element reached 0, means ki ye left
                    // wala iklota tha window me, lekin ab apan ne isko alag
                    // kardiya window se, so do 2 things here

                    // remove the element frm the map
                    mxfreq.erase(nums[l]);
                    // remove the element frm the set,(to make way for the maxm
                    // element of new window/subarray)
                    mx.erase(nums[l]);
                }

                // same thing as above, but this time for the minm wala map

                mnfreq[nums[l]]--;
                if (mnfreq[nums[l]] == 0) {
                    mnfreq.erase(nums[l]);
                    mn.erase(nums[l]);
                }

                // move left ptr ahead
                l++;
            }

            // ab apne paas valid window hai, toh ans me update karo
            // eg if window was like {2,3,4,3,3},l=0,r=4,ttl elemetents=r-l+1=5
            // then iss window se following subarrays ban sakte hai
            // {2},{3},{4},{3},{3},
            // {2,3},{3,4},{4,3},{3,3},
            // {2,3,4},{3,4,3},{4,3,3},
            // {2,3,4,3},{3,4,3,3}
            // {2,3,4,3,3}
            // overall 15 subarrays that are valid ie 5*(5+1)/2, the 5 is the
            // no. of elements in the window

            // this logic isnt working, ho kya rha hai ki apan same subarrays ko
            // multiple times count krre hai(dry run krke dekho samaj me aa
            // jaega),which is wrong, so better approach is (aisa ek baar
            // pehele koi questn me bhi kiya tha), ki for current window(which
            // starts with element 2), se bas vo subarrays count karo jo iss 2
            // se start hore hai ie count only
            // {2},{2,3},{2,3,4},{2,3,4,3},{2,3,4,3,3}, ie 5 subarrays= no of
            // elements in the window, ye logic works and also gave me the AC so
            // noixe ig

            // exact reason as to why this works???, mai note me likh dunga the
            // quesn number jiss me ye approach last use kiya tha(ie adding only
            // those subarrays jo 'L' wale element se start hore)/ or agar
            // editorial me kuch milega reasoning to bhi note me likh dunga

            // all that matters is it works

            // yehi add kardo ans me
            int no_of_elements = r - l + 1;
            ans += no_of_elements;
            cout << l << " to " << r << endl;

            // window aage badhao,
            r++;
        }

        return ans;
    }
};