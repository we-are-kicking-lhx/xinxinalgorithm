class Solution
{
  public:
    int compareVersion(string version1, string version2)
    {
        int temp1 = 0, temp2 = 0, i = 0, j = 0;
        int len1 = version1.length(), len2 = version2.length();

        string val1, val2;
        while (i < len1 || j < len2)
        {
            while (i < len1 && version1[i] != '.')
                val1.push_back(version1[i++]);
            temp1 = atoi(val1.c_str());
            while (j < len2 && version2[j] != '.')
                val2.push_back(version2[j++]);
            temp2 = atoi(val2.c_str());
            if (temp1 > temp2)
                return 1;
            else if (temp1 < temp2)
                return -1;
            val1.clear();
            val2.clear();
            i++;
            j++;
        }
        return 0;
    }
};