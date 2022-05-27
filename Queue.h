#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;
const EXPAND_RATE = 2;

//template <class T>
class Queue {
private:
    T *m_data;
    int m_lastItemIndex;
    int m_maxSize;


public:

//template <class T>
    bool pushBack(const T item);

//<template class T>
    void expand();

    int size() const;

    T front() const;

    void popFront();

    void moveOneLeft();

    void minimize();

    explicit Queue(int size = EXPAND_RATE);

    Queue(const Queue &queue);

    Queue &operator=(const Queue &queue);

    Queue filter(Queue &queue, FilterFunc filterFunc);

    void transform(Queue &queue, Transform transformOperator);

    ~Queue(); //need to be done

    Queue &operator=(const Queue &q);

    class EmptyQueue {
    };
};

#endif //EX3_QUEUE_H

