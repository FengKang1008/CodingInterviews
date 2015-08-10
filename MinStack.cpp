#include <iostream>
using namespace std;

#include <stack>
#include <assert.h>

template<typename T>
class  StackWithMin
{
public:
    void push(const T &value);
    void pop();
    const T &min() const; // 返回不可修改的引用类型，同时在函数中不能修改元素

private:
    stack<T> m_min;
    stack<T> m_data;
};


template <typename T>
void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);

    if(m_min.size() == 0 || value < m_min.top())
    {
        m_min.push(value); // 最小栈中的元素为空或者value为最小元素
    }
    else
    {
        m_min.push(m_min.top()); // 将最小元素再次压入栈中
    }
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() >  0 && m_min.size() > 0); // data栈与min栈中的元素个数相同

    // data栈与min栈同时出栈
    m_data.pop();
    m_min.pop();
}

template <typename T>
const T &StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

int main(int argc, char const *argv[])
{
    /**
     * 测试用例
     * 1.新入栈元素比最小值大
     * 2.新入栈元素比最小值小
     * 3.弹出非最小元素
     * 4.弹出最小元素
     */
    StackWithMin<int> minStack;
    minStack.push(2);
    minStack.push(3);
    cout << minStack.min() << endl;
    minStack.push(1);
    cout << minStack.min() << endl;
    minStack.push(2);
    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.min() << endl;
    minStack.pop();
    cout << minStack.min() << endl;

    return 0;
}
