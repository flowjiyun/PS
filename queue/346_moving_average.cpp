class MovingAverage {
public:
    queue<int> m_list;
    double m_curSum;
    int m_size;

    MovingAverage(int size) {
        m_size = size;
        m_curSum = 0;
    }
    
    double next(int val) {
        double ans;
        m_list.push(val);
        m_curSum += val;
        if (m_list.size() <= m_size) {
            ans = m_curSum / m_list.size();
        } else {
            m_curSum -= m_list.front();
            m_list.pop();
            ans = m_curSum / m_size;
        }
        return ans;
    }
};