class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnta = 0, cntb = 0, cntc = 0; // to be deleted
        for (auto it : s) {
            if (it == 'a')
                cnta++;
            if (it == 'b')
                cntb++;
            if (it == 'c')
                cntc++;
        }

        // koi ka cnt k ke upar or = nai h pure string me, return -1, since ans
        // cant be formed
        // since k characters hi nai h , toh delete kaha se karoge
        if (cnta < k || cntb < k || cntc < k)
            return -1;

        int i = 0, j = 0;
        int ans = 0;

        // sliding window
        while (j < n) {
            if (s[j] == 'a') {
                // we dont want to delete current character frm s
                // freq me -1 krdo
                cnta--;
            }
            if (s[j] == 'b') {
                // we dont want to delete current character frm s
                // freq me -1 krdo
                cntb--;
            }
            if (s[j] == 'c') {
                // we dont want to delete current character frm s
                // freq me -1 krdo
                cntc--;
            }

            // shrink window if necessary
            // if deletion cnt of any char<k, then shrink window, and bring the character back
            while(i<=j && (cnta<k || cntb<k || cntc<k)){
                // shrink window 
                // ith char move to left
                if(s[i]=='a'){
                    // means i th char is 'a' and we dont want to delete it
                    // increase a cnt
                    cnta++;
                }
                if(s[i]=='b'){
                    // means i th char is 'b' and we dont want to delete it
                    // increase b cnt
                    cntb++;
                }
                if(s[i]=='c'){
                    // means i th char is 'c' and we dont want to delete it
                    // increase c cnt
                    cntc++;
                }

                // i ptr aage badhao
                i++;

            }

            // reuslt update krdo
            ans=max(ans,j-i+1);

            // window aage badhao
            j++;
        }
        // ans kitne characters are to be deleted

        // hence not deleted characters are n-ans
        return n-ans;
    }
};