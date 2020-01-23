//
// Example illustrating use of the functional_streambuf class.
// Instantiate the functional_streambuf with a function returning random
// characters in the range A-Z.
//
// Github: bootes16
//
#include <iostream>
#include <random>

#include "functional_streambuf.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (1 == argc) {
        cout << "Usage: " << argv[0] << " <count>" << endl;
        return -1;
    }

    size_t count = atoi(argv[1]);

    // Create the RNG for ASCII 'A' - 'Z'.
    random_device rd;
    uniform_int_distribution<> d{'A','Z'};

    // Create functional_streambuf instance and istream of maximum length.
    functional_streambuf fsbuf {count, [&rd, &d](){ return d(rd); }};
    istream is {&fsbuf};
    cout << is.rdbuf() << endl;
}
