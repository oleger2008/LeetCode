class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return {};
        }
        int size = std::gcd(str1.size(), str2.size());
        return str1.substr(0, size);
    }
    // string gcdOfStrings(string str1, string str2) {
    //     if (str1 < str2) {
    //         return gcdOfStrings(std::move(str2), std::move(str1));
    //     }
    //     int i = str2.size();
    //     while (i > 0) {
    //         if ((str1.size() % i == 0) && (str2.size() % i == 0)) {
    //             if (help(str1, std::string_view{str2.begin(), str2.begin() + i}) &&
    //                 help(str2, std::string_view{str2.begin(), str2.begin() + i})
    //                 ) {
    //                 return str2.substr(0, i);
    //             }
    //         }
    //         --i;
    //     }
    //     return {};
    // }

    // bool help(std::string_view s1, std::string_view s2) {
    //     if (s1.size() == s2.size()) {
    //         return s1 == s2;
    //     }
    //     return s1.starts_with(s2) && help(std::string_view{s1.begin() + s2.size(), s1.end()}, s2);
    // }
};