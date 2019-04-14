class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> re;
        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (asteroids[i] > 0)
                re.push_back(asteroids[i]);
            else if (re.empty() || re.back() < 0)
                re.push_back(asteroids[i]);
            else if (re.back() <= -asteroids[i])
            {
                if (re.back() < -asteroids[i])
                    --i;
                re.pop_back();
            }
        }
        return re;
    }
};
