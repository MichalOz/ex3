#include "Queue.h"

//template <class T>
//Queue<T>::Queue(int size) {
Queue::Queue() {
    m_data = new T[INITIAL_SIZE];
    m_maxSize = INITIAL_SIZE;
    m_lastItemIndex = 0;
}

//template <class T>
//Queue<T>::Queue(const Queue& queue){
Queue::Queue(const Queue &queue) {
    m_data = new int[queue.m_maxSize];
    m_maxSize = queue.m_maxSize;
    m_lastItemIndex = queue.m_lastItemIndex;
    try {
        for (int i = 0; i < m_maxSize; i++) {
            m_data[i] = queue.m_data[i];
            //need check with michal
        }
    }
    catch (...) {
        delete[] m_data;
        throw;
    }
}

//template <class T>
Queue &Queue::operator=(const Queue &queue) {
    if (this == &queue) {
        return *this;
    }
    T *tempData = new T[queue.m_maxSize];
    try {
        m_maxSize = queue.m_maxSize;
        m_lastItemIndex = queue.m_lastItemIndex;
        for (int i = 0; i < m_lastItemIndex; ++i) {
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

Queue::~Queue() {
    delete[] m_data;
}


///////
//template <class T>
void Queue::pushBack(const T item) {
    // if item == null ?
    if (m_lastItemIndex + 1 >= m_maxSize) {
        expand();
    }
    m_data[m_lastItemIndex] = item;
    m_lastItemIndex++;
}

//<template class T>
void Queue::expand() {
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
int Queue::size() const {
    //return m_lastItemIndex;
    return m_lastItemIndex;
}

//<template class T>
T Queue::front() const {
    return m_data[0];
}


//<template class T>
void Queue::popFront() {
    if (m_lastItemIndex == 0) {
        throw EmptyQueue();
    }
    moveOneLeft();
    if (m_lastItemIndex - 1 <= 0.5 * m_maxSize) {
        minimize();
    }
}

void Queue::moveOneLeft() {
    for (int i = 0; i < m_lastItemIndex - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    m_lastItemIndex--;
}

void Queue::minimize() {
    int newSize = m_maxSize * MINIMIZE_RATE;
    T *tempData = new T[newSize];
    try {
        for (int i = 0; i < m_lastItemIndex; ++i) {
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

Queue Queue::filter(Queue &queue, FilterFunc filterFunc) {
    // what if given queue smaller
    Queue newQueue;
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        if (filterFunc(*it)) {
            newQueue.pushBack(*it);
        }
    }
    return newQueue;
}

void Queue::transform(Queue &queue, Transform transformOperator) {
    // what if given queue smaller
    for (Queue::Iterator it = queue.begin(); it != queue.end(); ++it) {
        transformOperator(*it);
    }
}

Queue::Const_Iterator Queue::const_begin() const {
    return Const_Iterator(this, 0);
}

Queue::Const_Iterator Queue::const_end() const {
    return Const_Iterator(this, m_lastItemIndex);
}

Queue::Iterator Queue::begin() {
    return Iterator(this, 0);
}

Queue::Iterator Queue::end() {
    return Iterator(this, m_lastItemIndex);
}

Queue::Const_Iterator::Const_Iterator(const Queue *queue, int index) :
        m_queue(queue), m_index(index) {}

const T &Queue::Const_Iterator::operator*() {
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}

Queue::Const_Iterator &Queue::Const_Iterator::operator++() {
    ++m_index;
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return *this;
}

bool Queue::Const_Iterator::operator!=(const Const_Iterator it) const {
    if (m_queue != it.m_queue) {
        throw InvalidOperation();
    }
    return m_index != it.m_index;
}

Queue::Iterator::Iterator(Queue *queue, int index) :
        m_queue(queue), m_index(index) {}

T &Queue::Iterator::operator*() {
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}

Queue::Iterator &Queue::Iterator::operator++() {
    ++m_index;
    if (m_index >= m_queue->m_lastItemIndex) {
        throw InvalidOperation();
    }
    return *this;
}

bool Queue::Iterator::operator!=(const Iterator it) const {
    if (m_queue != it.m_queue) {
        throw InvalidOperation();
    }
    return m_index != it.m_index;
}
