class Solution
{
  public:
    string shiftingLetters(string S, vector<int> &shifts)
    {
        long long total=0;
        for (int i = S.length() - 1; i >= 0; i--)
        {
            total += shifts[i];
            S[i] = (S[i] - 'a' + total) % 26 + 'a';
        }
        return S;
    }
};