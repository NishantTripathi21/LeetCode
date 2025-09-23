class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1= version1.size();
        int n2= version2.size();
        int i= 0;int j =  0;
        while (i < n1 || j < n2) {
            string s1, s2;
            while (i < n1 && version1[i] != '.') {
                s1 += version1[i];
                i++;
            }
            i++;
            while (j < n2 && version2[j] != '.') {
                s2 += version2[j];
                j++;
            }
            j++;
            int t1 = s1.empty() ? 0 : stoi(s1);
            int t2 = s2.empty() ? 0 : stoi(s2);
            if (t1 < t2) return -1;
            if (t1 > t2) return 1;
        }

        return 0;
    }
};
