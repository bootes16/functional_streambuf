//
// Simple main function illustrating use of the simple PRNG.
//
// Author: Greg Johnson
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

    auto count = atoi(argv[1]);

    random_device rd;
    uniform_int_distribution<> d{64,90};

    functional_streambuf sbuf {static_cast<size_t>(count), [&rd, &d](){ return d(rd); }};
    istream is {&sbuf};
    char c;
    cout << hex;
    while (is.get(c)) {
        cout << (int)c;
    }
    cout << endl;
}
