class StockSpanner
{
  private:
    stack<pair<int, int>> st;
    int index = 0;

  public:
    StockSpanner()
    {
        st.push(make_pair(INT_MAX, 0));
    }

    int next(int price)
    {
        index++;
        while (!st.empty() && price >= st.top().first)
            st.pop();
        int start = st.top().second;
        st.push(make_pair(price, index));
        return index - start;
    }
};