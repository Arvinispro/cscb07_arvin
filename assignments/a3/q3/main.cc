#include <iostream>
#include <fstream>
#include <string>
#include "DigitalMedia.h"
#include "Song.h"
#include "Video.h"
#include "Library.h"
#include "Queue.h"
int main() {
    // Initial dummy values to facilitate reading in information over top of an existing object.
    Song s1{ "S01", "Great beat and you can dance to it", 183, "Too cool", 
        "I'd give it a 10!", "Eclectic" };
    Video v1{ "V01", "How to cook pasta", 612, "Chef Ana", 1080 };

    Queue queue;
    Library media;
    DigitalMedia *mptr;
    char command, dmtype, arg;
    std::string line, key, filename;

    while ( true ) {
        std::cin >> command;

        // Terminate the program if enter 'q' or reach EOF.
        if ( std::cin.fail() || command == 'q' ) break;

        switch( command ) {
            case 'p':
                // "p m" prints the contents of the media library.
                // "p q" prints the contents of the queue.
                std::cin >> arg;
                if ( arg == 'm' ) { 
                    std::cout << media;
                } else if ( arg == 'q' ) {
                    std::cout << "Queue:\n" << queue;
                } // if 
                break;

            case 'r':
                // "r <key>" removes the item with the specified key from the media library, and
                // from the queue. Silently does nothing if such an item doesn't exist.
                std::cin >> key;
                mptr = media.find( key );
                if ( mptr ) { 
                    queue.remove( mptr );
                    media.remove( key );   // also deletes the item
                } // if
                break;

            case '>':
                // If the queue isn't empty, "play" the item at the front of the queue: it is
                // removed from the queue and its information is printed, followed by the total
                // number of seconds played so far (including this item).
                mptr = queue.play();
                if ( mptr != nullptr ) {
                    mptr->print( std::cout );
                    std::cout << " " << queue.getSecondsPlayed() << std::endl;
                } // if
                break;

            case 'z':
                // Resets the number of seconds played so far to 0.
                queue.reset();
                break;

            case 'f':
                // "f m <key>" looks for the item with the specified key in the media library.
                std::cin >> arg;
                if ( arg == 'm' ) {
                    std::cin >> key;
                    mptr = media.find( key );
                    if ( mptr ) {
                        std::cout << "Found: ";
                        mptr->print( std::cout );
                        std::cout << std::endl;
                    } else {
                        std::cout << "Library doesn't contain any item with key " 
                            << key << std::endl;
                    } // if
                } // if
                break;

            case 'i':
                // "i <filename>" inserts the contents of file <filename> into the media library.
                // <filename> consists of a sequence of items as described for "a m" below, each
                // preceded by its type character.
                std::cin >> filename;
                getline( std::cin, line ); // throw away rest of line.
                {
                    std::ifstream infile{ filename };
                    infile >> media;
                }
                break;

            case 'a':
                // "a m s\n" and "a m v\n" add a song or a video to the media library. The information that follows must follow the format as specified for
                // the operator>> of that type. If the information can't be read, nothing is added.
                // "a n <key>" adds the media item with key <key> to the front of the queue (play next).
                // "a l <key>" adds the media item with key <key> to the back of the queue (play last).
                // Both silently fail if the media library doesn't contain an item with key <key>.
                std::cin >> arg;
                if ( arg == 'm' ) {
                    std::cin >> dmtype;
                    getline( std::cin, line ); // throw away rest of line
                    if ( dmtype == 's' ) {
                        std::cin >> s1;
                        if ( std::cin.fail() ) std::cin.clear();   // error already reported
                        else media.add( new Song{s1} );
                    } else if ( dmtype == 'v' ) {
                        std::cin >> v1;
                        if ( std::cin.fail() ) std::cin.clear();
                        else media.add( new Video{v1} );
                    } // if
                } else if ( arg == 'n' || arg == 'l' ) {
                    std::cin >> key;
                    mptr = media.find( key );
                    if ( mptr ) {
                        if ( arg == 'n' ) queue.playNext( mptr ); else queue.playLast( mptr );
                    } // if
                } // if
                break;
        } // switch
    } // while
} // main
