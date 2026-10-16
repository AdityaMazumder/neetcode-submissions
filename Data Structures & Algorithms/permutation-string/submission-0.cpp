class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> count1(26, 0), count2(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        for (int right = s1.length(); right < s2.length(); right++) {
            count2[s2[right] - 'a']++;
            count2[s2[right - s1.length()] - 'a']--;

            if (count1 == count2) return true;
        }

        return false;
    }
};