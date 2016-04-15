#include <string.h>
#include "tajo_value.h"

TajoValue::TajoValue()
    : value(NullTag()), error(false)
{
}

TajoValue::TajoValue(int i)
    : value(i), error(false)
{
}

TajoValue::TajoValue(const char *s)
    : value( std::vector<char>(s, s + strlen(s)) ), error(false)
{
}

TajoValue::TajoValue(const std::string &s)
    : value( std::vector<char>(s.begin(), s.end()) ), error(false)
{
}

TajoValue::TajoValue(const std::vector<char> &buf)
    : value(buf), error(false)
{
}

TajoValue::TajoValue(const std::vector<char> &buf, struct ErrorTag &)
    : value(buf), error(true)
{
}

TajoValue::TajoValue(const std::vector<TajoValue> &array)
    : value(array), error(false)
{
}

std::vector<TajoValue> TajoValue::toArray() const
{
    return castTo< std::vector<TajoValue> >();
}

std::string TajoValue::toString() const
{
    const std::vector<char> &buf = toByteArray();
    return std::string(buf.begin(), buf.end());
}

std::vector<char> TajoValue::toByteArray() const
{
    return castTo<std::vector<char> >();
}

int TajoValue::toInt() const
{
    return castTo<int>();
}

std::string TajoValue::inspect() const
{
    if( isError() )
    {
        static std::string err = "error: ";
        std::string result;

        result = err;
        result += toString();

        return result;
    }
    else if( isNull() )
    {
        static std::string null = "(null)";
        return null;
    }
    else if( isInt() )
    {
        return std::to_string(toInt());
    }
    else if( isString() )
    {
        return toString();
    }
    else
    {
        std::vector<TajoValue> values = toArray();
        std::string result = "[";

        if( values.empty() == false )
        {
            for(size_t i = 0; i < values.size(); ++i)
            {
                result += values[i].inspect();
                result += ", ";
            }

            result.resize(result.size() - 1);
            result[result.size() - 1] = ']';
        }
        else
        {
            result += ']';
        }

        return result;
    }
}

bool TajoValue::isOk() const
{
    return !isError();
}

bool TajoValue::isError() const
{
    return error;
}

bool TajoValue::isNull() const
{
    return typeEq<NullTag>();
}

bool TajoValue::isInt() const
{
    return typeEq<int>();
}

bool TajoValue::isString() const
{
    return typeEq<std::vector<char> >();
}

bool TajoValue::isByteArray() const
{
    return typeEq<std::vector<char> >();
}

bool TajoValue::isArray() const
{
    return typeEq< std::vector<TajoValue> >();
}

bool TajoValue::operator == (const TajoValue &rhs) const
{
    return value == rhs.value;
}

bool TajoValue::operator != (const TajoValue &rhs) const
{
    return !(value == rhs.value);
}