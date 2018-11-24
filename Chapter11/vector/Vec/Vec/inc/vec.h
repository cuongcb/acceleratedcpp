//
//  vec.h
//  Vec
//
//  Created by CAO BA CUONG on 6/25/18.
//  Copyright © 2018 CAO BA CUONG. All rights reserved.
//

#pragma once

#include <cstdlib>
#include <memory>

template <class T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }
    Vec(const Vec &v) { create(v.begin(), v.end()); }
    Vec & operator=(const Vec &v);
    ~Vec() { uncreate(); }
    T & operator[](size_type i) { return data[i]; }
    const T & operator[](size_type i) const { return data[i]; }

    void push_back(const T &t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

    void clear();

    size_type size() const { return avail - data; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    iterator data; // first element
    iterator avail; // one past initialized element
    iterator limit; // one past uninitialized element

    std::allocator<T> alloc; // object to handle memory

    // initializer of array
    void create();
    void create(size_type n, const T &t);
    void create(const_iterator begin, const_iterator end);

    // destroy the element and deallocate memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T &t);
};

template <class T>
Vec<T> & Vec<T>::operator=(const Vec &v) {
    if (*this != v)
    {
        this->uncreate();
        this->create(v.begin(), v.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = nullptr;
}

template <class T>
void Vec<T>::create(size_type n, const T &t)
{
    data = alloc.allocate(n);
    avail = limit = data + n;
    std::uninitialized_fill(data, limit, t);
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    avail = limit = std::uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);

        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = nullptr;
}

template <class T>
void Vec<T>::grow()
{
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    // construct new data, avail
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    // deallocate old data
    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T &t)
{
    alloc.construct(avail++, t);
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator position)
{
    if (position >= data && position < avail)
    {
        // destroy current pointer's data
        alloc.destroy(position);
        // copy the next data to previous position
        --avail;
        iterator new_position = position;
        while (new_position != avail)
        {
            alloc.construct(new_position, *(new_position + 1));
            ++new_position;
        }
        alloc.destroy(new_position);
        return position;
    }

    return avail;
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator first, Vec<T>::iterator last)
{
    // not implement yet
    return first;
}

template <class T>
void Vec<T>::clear()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
        {
            alloc.destroy(--it);
        }
    }

    // keep capacity = limit, reset size
    data = avail = nullptr;
}
