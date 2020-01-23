//
// functional_streambuf
//
// Stream buffer which takes a nullary function object as a character data source.
// Will emit up to a fix size stream of chars from the function object.
//
// Github: bootes16
//
#ifndef FUNCTIONAL_STREAMBUF_H
#define FUNCTIONAL_STREAMBUF_H
#include <iostream>
#include <functional>

class functional_streambuf : public std::streambuf {
public:
    //
    // len      Maximum number of characters the stream buffer will emit.
    // fn       nullary function object which returns an int at a time.
    //
    functional_streambuf(size_t len, std::function<int()> fn) : len{len}, cap{len}, fn{fn} {
        ch = fn(); // Prime the holding buffer.
    }

private:
    //
    // Return the current character in the sequence. Do not advance the stream pointer.
    //
    int_type underflow() {
        if (len == 0) return traits_type::eof();
        return traits_type::to_int_type(ch);
    }

    //
    // Return the current character in the sequence, then advance the stream pointer.
    //
    int_type uflow() {
        if (len == 0) return traits_type::eof();
        len--;
        auto ret = ch;
        ch = fn();
        return traits_type::to_int_type(ret);
    }

    //
    // Consume and drop the character being pushed back. The nullary function
    // obj is not required to be able to wind back the stream. Just increment the length.
    //
    int_type pbackfail(int_type val) {
        if (len < cap) len++;
        return val;
    }

    //
    // Return number of characters available.
    //
    std::streamsize showmanyc() {
        return len;
    }

    char ch {};     // Holding buffer for the next character returned. Supports non-advancing underflow().
    size_t len {0};
    const size_t cap {0};
    std::function<char()> fn;
};
#endif // FUNCTIONAL_STREAMBUF_H