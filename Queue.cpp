#include "Queue.h"


///////
//template <class T>
void Queue::pushBack(const T itemToPush) 
{
    // if item == null ?
    if (m_lastItemIndex >= m_maxSize) {
        expand();
    }
    m_data[m_lastItemIndex] = itemToPush;
    m_lastItemIndex++;
}

//<template class T>
void Queue::expand() 
{
    int newSize = m_maxSize * EXPAND_RATE;
    T *tempData = new T[newSize];
    try {
        for (int i = 0; i < m_maxSize; ++i) {
            tempData[i] = m_data[i];
        }
    }
    catch (...) {
        delete[] tempData;
        throw;
    }
    delete[] m_data;
    m_data = tempData;
    m_maxSize = newSize;
}

//<template class T>
int Queue::size() const 
{
    return m_maxSize;
}

//<template class T>
T Queue::front() const 
{
    return m_data[m_lastItemIndex - 1];
}


//<template class T>
void Queue::popFront() {
    if (m_lastItemIndex == 0) 
    {
        throw EmptyQueue();
    }
    moveOneLeft();
    if (m_lastItemIndex - 1 <= 0.5 * m_maxSize) 
    {
        minimize();
    }
}

void Queue::moveOneLeft() 
{
    for (int i = 0; i < m_lastItemIndex - 1; ++i) 
    {
        m_data[i] = m_data[i + 1];
    }
    m_lastItemIndex--;
}

void Queue::minimize() {
    // when we use less than half of data space we minimize by 25%
    // given size: 100, when used spaces gets to 49 we minimize size to 75
    delete[] (m_data+(int)(m_maxSize * 0.75));
    m_maxSize = m_maxSize * 0.75;
}


//template <class T>
//Queue<T>::Queue(int size) {
Queue::Queue() {
    m_data = new T[INITIAL_SIZE];
    m_maxSize = INITIAL_SIZE;
    m_lastItemIndex = 0;
}

//template <class T>
//Queue<T>::Queue(const Queue& queue){
Queue::Queue(const Queue &queue) 
{
    m_data = new int[queue.m_maxSize];
    m_maxSize = queue.m_maxSize;
    m_lastItemIndex = queue.m_lastItemIndex;
    try 
    {
        for (int i = 0; i < m_maxSize; i++) 
        {
            m_data[i] = queue.m_data[i];
            //need check with michal
        }
    }
    catch (...) 
    {
        delete[] m_data;
        throw;
    }
}


//template <class T>
Queue& Queue::operator=(const Queue &queue) {
    if (this == &queue) {
        return *this;
    }
    T *tempData = new T[queue.m_maxSize];
    try {
        m_maxSize = queue.m_maxSize;
        m_lastItemIndex = queue.m_lastItemIndex;
        for (int i = 0; i < m_maxSize; ++i) {
            m_data[i] = queue.m_data[i];
        }
    } catch (...) {
        delete[] tempData;
        throw;
    }
    delete[] m_data;
    m_data = tempData;
    return *this;
}
    Queue::Const_Iterator::Const_Iterator(const Queue* queue, int index) : 
        m_queue(queue), m_index(index){}

    const T& Queue::Const_Iterator::operator*()
    {
        if (m_index>=m_queue->m_lastItemIndex)
        {
            throw InvalidOperation();
        }
        return m_queue->m_data[m_index];
    }
    Queue::Const_Iterator& Queue::Const_Iterator::operator++()
    {
        ++m_index;
        if (m_index>=m_queue->m_lastItemIndex)
        {
            throw InvalidOperation();
        }
        return *this;
    }
    bool Queue::Const_Iterator::operator!=(const Const_Iterator it) const
    {
        if(m_queue!=it.m_queue)
        {
            throw InvalidOperation();
        }
        return m_index!=it.m_index;
    }

    Queue::Iterator::Iterator(const Queue* queue, int index) : 
        m_queue(queue), m_index(index){}

    T& Queue::Iterator::operator*()
    {
        if (m_index>=m_queue->m_lastItemIndex)
        {
            throw InvalidOperation();
        }
        return m_queue->m_data[m_index];
    }
    Queue::Iterator& Queue::Iterator::operator++()
    {
        ++m_index;
        if (m_index>=m_queue->m_lastItemIndex)
        {
            throw InvalidOperation();
        }
        return *this;
    }
    bool Queue::Iterator::operator!=(const Iterator it) const
    {
        if(m_queue!=it.m_queue)
        {
            throw InvalidOperation();
        }
        return m_index!=it.m_index;
    }
    

    

Queue Queue::filter(Queue &queue, FilterFunc filterFunc) {
    // what if given queue smaller
    Queue newQueue;
    for (int i = 0; i < queue.m_lastItemIndex; ++i) {
        if (filterFunc(queue.m_data[i])) {
            newQueue.pushBack(queue.m_data[i]);
        }
    }
    return newQueue;
}

void Queue::transform(Queue &queue, Transform transformOperator) {
    // what if given queue smaller
    for (int i = 0; i < queue.m_lastItemIndex; ++i) {
        queue.m_data[i] = transformOperator(queue.m_data[i]);
    }
}

Queue::~Queue() {
    delete[] m_data;
};


