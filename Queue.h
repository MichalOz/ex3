#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;

//template <class T>
class Queue {
private:
    T *m_data;
    int m_lastItemIndex;
    int m_maxSize;


public:
//    void pushBack(<T> itemToPush);
    void pushBack(T itemToPush);

//helper  to push back- our func
    void expand();

    int size() const;

    void popFront();

    T front();

    explicit Queue(int maxSize = 100);

    Queue(const Queue &q);

    ~Queue();

    Queue& operator=(const Queue &q);

    class Full {};
    class Empty {};
    class InvalidSize {};

};

#endif //EX3_QUEUE_H
