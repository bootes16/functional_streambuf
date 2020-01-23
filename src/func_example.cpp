//
// Simple main function illustrating use of the simple PRNG.
//
// Author: Greg Johnson
// Github: bootes16
//
#include <iostream>
#include <sstream>

#include "middle_sq_weyl.h"
#include "random_streambuf.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (1 == argc) {
        cout << "Usage: " << argv[0] << " <count>" << endl;
        return -1;
    }

    auto count = atoi(argv[1]);

    MiddleSqWeyl<char> msw {};
    random_streambuf rsb {static_cast<size_t>(count), msw};
    istream is {&rsb};
    char c;
    cout << hex;
    while (is.get(c)) {
        cout << (int)c;
    }
    cout << endl;
}
