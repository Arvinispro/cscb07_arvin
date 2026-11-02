#ifndef QUEUE_H
#define QUEUE_H
#include <string>
#include <iostream>
class DigitalMedia;

class QueueIterator;   // defined in QueueIterator.h (it needs Queue::Node)

class Queue {
    friend class QueueIterator;

    // *** fill in

public:
    Queue();
    ~Queue();           // the media items themselves are owned by the Library

    void playNext( DigitalMedia * m );  // adds m to the front of the queue
    void playLast( DigitalMedia * m );  // adds m to the back of the queue

    // "Plays" the item at the front of the queue: removes it from the queue, adds its
    // duration to the number of seconds played, and returns it. Returns nullptr (and
    // changes nothing) if the queue is empty.
    DigitalMedia * play();

    // Removes every occurrence of m from the queue. Does nothing if m isn't in the queue.
    void remove( DigitalMedia * m );

    void reset();                       // resets the number of seconds played back to 0
    int getTotalSeconds() const;        // total duration of the items in the queue
    int getSecondsPlayed() const;       // total duration of the items played so far

    QueueIterator begin() const;        // Iterator set to the front of the queue.
    QueueIterator end() const;          // Iterator set past the back of the queue.
};

// Returns modified output stream. Outputs each item on its own line, in queue order, as
// a tab, the position of the item (width 3, padded with '0'), ": ", the item's information,
// and " starts in N seconds" where N is the iterator's elapsed time at that item. The last
// line is "Total: N seconds", N being the total duration of the items in the queue.
std::ostream & operator<<( std::ostream & out, const Queue & q );

#endif
