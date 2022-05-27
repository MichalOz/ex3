#include "Queue.h"



///////
//template <class T>
bool Queue::pushBack(T item) {
    if (m_lastItemIndex >= m_maxSize) {
        expand();
    }
    data[size++] = item;
    return true;
}

//<template class T>
void Queue::expand() {
    int newSize = m_maxSize * EXPAND_RATE;
    T *newData = new T[newSize];
    for (int i = 0; i < m_maxSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    maxSize = newSize;
}

//<template class T>
int Queue::size() const {
    return m_maxSize;
}

//<template class T>
T Queue::front() const {
    return m_data[m_lastItemIndex - 1];
}


//<template class T>
void Queue::popFront() {
    delete m_data[0];
    if (m_lastItemIndex - 1 <= 0.5 * m_maxSize) {
        minimize();
    }
    // move all items one place left
}

void Queue::minimize() {
    // when we use less than half of data space we minimize by 25%
    // given size: 100, when used spaces gets to 49 we minimize size to 75
    int placeToStopMinimize = m_maxSize * 0.75;
    for (int i = m_maxSize - 1; i >= placeToStopMinimize; i--) {
        delete m_data[i];
    }
}


//template <class T>
Queue::Queue(int size) :
        data(new T[size]), m_maxSize(size),m_lastItemIndex(1){
    if (size <= 0) {
        // fit to default size
        delete[] data;
        throw InvalidSize();
    }
}

//template <class T>
Queue::Queue(const Queue T& q) :
        data(new T[q.m_maxSize]), m_maxSize(q.m_maxSize), m_lastItemIndex(q.m_nextIndex) {
    try {
        for (int i = 0; i < nextIndex; ++i) {
            data[i] = s.data[i];
        }
    } catch (...) {
        delete[] data;
        throw;
    }
}
