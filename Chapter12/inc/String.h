#include "../../Chapter11/inc/Vec.h"

class String {
public:
    typedef Vec<char>::size_type size_type;

    // Default constructor, create empty string
    String();

    // Create a string containing |n| copies of |c|
    String(size_type n, char c): data(n, c) {}

    // Create a string from a null-terminated array of char
    String(const char *str) {
        std::copy(str, str + std::strlen(str), std::back_inserter(data_));
    }

    // Create a string from the range denoted by iterators |b| and |e|
    template<class T>
    String(T b, T e) {
        std::copy(b, e, std::back_inserter(data_));
    }

    // index operator
    char & operator[](size_type index) {
        return data_[index];
    }

    const char & operator[](size_type index) const {
        return data_[index];
    }
private:
    Vec<char> data_;
};