class Solution {
public:
    int countCollisions(string directions) {
        // right wale set me store karlo left wale collide karate jao

        // ek stack store karega ki abhi tak kitne right wale aaye hai
        stack<char> st;
        // ek bool store karega ki abhi tak kya koi stationary aaya hai?, bool
        // since stationary hai toh collide hoke stationary hi rahega thats all
        bool stat = false;
        int ans = 0;
        for (auto it : directions) {
            // agar right wala hai toh stack me daal kar khatam karo
            if (it == 'R') {
                st.push(it);

                // right se banda aa raha hai means pehle jitne stationary wale
                // the sab bhid chuke already and new banda aa raha yaha se jo
                // aage collide kar sakta toh aage walo ke liye stationary is
                // false for now since saare stationary peche hi reh jaenge
                // since ye right wala right jata rahega
                
                // toh stat ko false kardo
                stat=false;
                continue;
            }

            // agar current wala left hai
            if (it == 'L') {
                // iske right me koi hai kya, nai hai toh jaata rahega khatam
                // kaam
                if (st.size() == 0 && !stat)
                    continue;

                // agar right me stationary hai kuch toh collidde karega aur
                // point count hoga 1
                if (stat) {
                    ans += 1;
                    continue;
                }

                // we here means right me aa rahe hai log, toh pehle toh ye dono
                // collide karenge toh +2 points, then dono stationary ho jaenge
                ans += 2;
                // stack se alag kardo since collide hua hai
                st.pop();
                stat = true;

                // startionary honge toh right se jitne bande aa rahe the sab
                // collide kar jaenge har collision 1 point dega toh stack ka
                // size jitne points milenge basically
                ans += st.size();

                // and ab sab stationary hai toh stat=true here also, lekin
                // since pehle kar liya hai toh why bother again

                // plus stack wale saare ab stationary ho gaye hai toh stack
                // clear kardo
                st = stack<char>();
                continue;
            }

            // we here means stationary hai, toh yaha par saare right se aane
            // wale stationary ho jaenge ab +1 point for each element toh ans me
            // include karlo
            ans += st.size();

            // stack clear kardo ab since saare elements staionary ho gaye hai
            st = stack<char>();

            // ab ye saare stationary hai aage walo ke liye toh agar aage left
            // aayega toh ye stationary will make that left moving also
            // stationary and so onn

            // toh stationary is true since ab left me stationary wale elements hai
            stat=true;
        }

        return ans;
    }
};