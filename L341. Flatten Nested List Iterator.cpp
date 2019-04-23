class NestedIterator
{
  public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        make_queue(nestedList);
    }

    int next()
    {
        int temp = q.front();
        q.pop();
        return temp;
    }

    bool hasNext()
    {
        return !q.empty();
    }

  private:
    queue<int> q;
    void make_queue(vector<NestedInteger> &list)
    {
        for (auto a : list)
        {
            if (a.isInteger())
                q.push(a.getInteger());
            else
                make_queue(a.getList());
        }
    }
};
