#ifndef QUEUE_ITERATOR_H
#define QUEUE_ITERATOR_H
#include "Queue.h"

class QueueIterator {
    friend class Queue;
    // *** fill in

    explicit QueueIterator( /*** fill in ***/ );  // Private constructor

public:
    // Time that will pass before the current item starts playing (0 at the front).
    int getElapsedTime() const;   

    DigitalMedia * operator*() const;

    // Adds the duration of the current item to the elapsed time before moving the iterator
    // to the next item. Any change to the queue invalidates the iterator.
    QueueIterator operator++();

    bool operator==( const QueueIterator & other ) const;
    bool operator!=( const QueueIterator & other ) const; 
};

#endif
