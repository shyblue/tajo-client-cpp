#pragma once

#include <boost/noncopyable.hpp>

#include <string>
#include <list>

// A reference to a byte or char array
class TajoSlice {
	const BYTE *data_;
	size_t size_;
};

class TajoBuffer
{
public:
    inline TajoBuffer();
    inline TajoBuffer(const char *ptr, size_t dataSize);
    inline TajoBuffer(const char *s);
    inline TajoBuffer(const std::string &s);
    inline TajoBuffer(const std::vector<char> &buf);

    inline size_t size() const;
    inline const char *data() const;

private:
    const char *ptr_;
    size_t size_;
};


TajoBuffer::TajoBuffer()
    : ptr_(NULL), size_(0)
{
}

TajoBuffer::TajoBuffer(const char *ptr, size_t dataSize)
    : ptr_(ptr), size_(dataSize)
{
}

TajoBuffer::TajoBuffer(const char *s)
    : ptr_(s), size_(s == NULL ? 0 : strlen(s))
{
}

TajoBuffer::TajoBuffer(const std::string &s)
    : ptr_(s.c_str()), size_(s.length())
{
}

TajoBuffer::TajoBuffer(const std::vector<char> &buf)
    : ptr_(buf.empty() ? NULL : &buf[0]), size_(buf.size())
{
}

size_t TajoBuffer::size() const
{
    return size_;
}

const char *TajoBuffer::data() const
{
    return ptr_;
}

