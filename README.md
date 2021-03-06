# functional_streambuf

Stream buffer class which emits characters acquired from a nullary function object.

## Synopsis
```cpp
    functional_streambuf fsbuf(size_t sz, nullary_function fn);
```

## Parameters
__sz__ - length of stream (number of characters) emitted.

__fn__ - nullary function object with the following signature:
```cpp
int fn(void);
```
Function object shall return the required number of values (__sz__).

## Example Usage
Create a functional_streambuf to emit 32 alternating 'AB' characters and print the stream.
```cpp
  functional_streambuf fsbuf {count, [](){static int a {1}; a = !a; return 'A'+ a;}};
  std::istream is {&fsbuf};
  std::cout << is.rdbuf() << std::endl;
```
