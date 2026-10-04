class Solution {
public:
    bool checkValidString(string_view s) {
        auto o = 1ul;
        for (char c : s) {
            bool b0 = c == '*';
            bool b1 = b0 | (c == '(');
            bool b2 = b0 | (c == ')');
            o = (o & -b0) | ((o << 1) & -b1) | ((o >> 1) & -b2);
        }
        return o & 1;
    }
};