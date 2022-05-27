#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H
typedef int T;

//template <class T>
class Queue 
{
    public:

        class Const_Iterator;
        class Iterator;

        Iterator begin() const;
        Iterator end() const;
        Const_Iterator const_begin() const;
        Const_Iterator const_end() const;
        void pushBack(T itemToPush);

        void expand();

        int size() const;

        void popFront();

        T front();

        explicit Queue(int maxSize = 100);

        Queue(const Queue &q);

        ~Queue();

        Queue& operator=(const Queue &q);

        class InvalidSize {};
        class InvalidOperation{};

    private:

        T *m_data;
        int m_lastItemIndex;
        int m_maxSize;
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
