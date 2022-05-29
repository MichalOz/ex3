#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;
const int EXPAND_RATE = 2;
const int INITIAL_SIZE = 10;
const double MINIMIZE_RATE = 0.75;
//template <class T>
class Queue
{
public:

    Queue();
    Queue(const Queue &queue);
    Queue &operator=(const Queue &queue);
    ~Queue();

    void pushBack(const T item);
    int size() const;
    T front() const;
    void popFront();
    typedef bool (*FilterFunc)(T);
    typedef void (*Transform)(T&);
    Queue filter(Queue &queue, FilterFunc filterFunc);
    void transform(Queue &queue, Transform transformOperator);
    class EmptyQueue {};
    class InvalidOperation{};

    class Const_Iterator;
    class Iterator;
    Iterator begin();
    Iterator end();
    Const_Iterator const_begin() const;
    Const_Iterator const_end() const;

private:
    T *m_data;
    int m_lastItemIndex;
    int m_maxSize;
    //expand the queue when there's no space left
    void expand();
    void moveOneLeft();
    //free 25% of the space allocated when only half is used
    void minimize();

};

class Queue::Const_Iterator
{
public:
    const T& operator*();
    Const_Iterator& operator++();
    bool operator!=(const Const_Iterator it) const;
    Const_Iterator(const Const_Iterator& it) = default;
    Const_Iterator& operator=(const Const_Iterator&) = default;
    ~Const_Iterator() = default;

private:
    const Queue* m_queue;
    int m_index;
    Const_Iterator (const Queue* queue, int index);
    friend class Queue;
};

class Queue::Iterator
{
public:
    T& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator() = default;

private:
    Queue* m_queue;
    int m_index;
    Iterator (Queue* queue, int index);
    friend class Queue;

};
#endif //EX3_QUEUE_H
