class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // swap hamesha (0,2) and (1,3) ka hi hoga, agar ye swap maarne se ho
        // jata hai same toh theek hi hai, otherwise return false

        string t1, t2, t;

        // s1 ke idx 0 and 2 ke char se t1 banao and t2 banao
        // t1= s1[0]+s1[2];
        // t2= s1[2]+s1[0];
        // s2 ke idx 0 and 2 ke char se t banao
        // t=s2[0]+s2[2];
        // agar t==s1 ya t==s2, means sahi hai bana sakte, aage idx 1,3 ke liye
        // chk kro, otherwise nai bana sakte return false
        t1 = string(1,s1[0]) + string(1,s1[2]);
        t2 = string(1,s1[2]) + string(1,s1[0]);
        t = string(1,s2[2]) + string(1,s2[0]);
        

        if (t == t1 || t == t2) {
            // cout << t1 << " " << t2 << " " << t << endl;
            // means string bana sakte hai aage badho
        } else {
            // means string kabhi nai banegi
            return false;
        }

        // same cheez check for idx 1,3
        t1 = string(1,s1[1]) + string(1,s1[3]);
        t2 = string(1,s1[3]) + string(1,s1[1]);
        t = string(1,s2[1]) + string(1,s2[3]);
        if (t == t1 || t == t2) {
            // cout << t1 << " " << t2 << " " << t << endl;
            // cout << "here2 " << endl;
            // means string bana sakte hai aage badho
        } else {
            // means string kabhi nai banegi
            return false;
        }

        // we here means string bana sakte hai, toh return true
        return true;
    }
};