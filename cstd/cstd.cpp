// Copyright (C) 2016-2017 Elias Kosunen
// This file is distributed under the 3-Clause BSD License
// See LICENSE for details

#include "cstd.h"
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>

cstring str_to_cstr(string str)
{
    auto cstr = cstralloc(str.len + 1);
    std::memcpy(cstr, str.ptr, static_cast<size_t>(str.len));
    cstr[str.len] = '\0';
    return cstr;
}
string cstr_to_str(cstring cstr)
{
    const auto len = std::strlen(cstr);
    auto str = stralloc(static_cast<va_i64>(len));
    std::strncpy(str.ptr, cstr, len);
    return str;
}

string stralloc(va_i64 size)
{
    auto ptr = static_cast<va_bchar*>(
        std::malloc(static_cast<size_t>(size) * sizeof(va_bchar)));
    if(!ptr)
    {
        std::fputs("Heap allocation failed: ", stderr);
        std::fputs(std::strerror(errno), stderr);
        std::abort();
    }
    return {size, ptr};
}
cstring cstralloc(va_i64 size)
{
    auto ptr = static_cast<va_bchar*>(
        std::malloc(static_cast<size_t>(size) * sizeof(va_bchar)));
    if(!ptr)
    {
        std::fputs("Heap allocation failed: ", stderr);
        std::fputs(std::strerror(errno), stderr);
        std::abort();
    }
    return ptr;
}

void strfree(string str)
{
    std::free(str.ptr);
}
void cstrfree(cstring str)
{
    std::free(str);
}

cstring cstrcpy(cstring dest, cstring2 src)
{
    return std::strcpy(dest, src);
}
va_i64 cstrlen(cstring str)
{
    return static_cast<va_i64>(std::strlen(str));
}
va_i32 cstrcmp(cstring lhs, cstring2 rhs)
{
    return std::strcmp(lhs, rhs);
}

string strcpy(string dest, string2 src)
{
    return {dest.len, static_cast<va_bchar*>(std::memcpy(
                          dest.ptr, src.ptr, static_cast<size_t>(dest.len)))};
}
va_i64 strlen(string str)
{
    return str.len;
}
va_i32 strcmp(string lhs, string2 rhs)
{
    return std::memcmp(lhs.ptr, rhs.ptr, static_cast<size_t>(lhs.len));
}

va_bool getstr(string str, va_i32 max_size)
{
    auto ret = std::fgets(str.ptr, max_size, stdin) != nullptr;
    str.len = static_cast<va_i64>(std::strlen(str.ptr));
    return ret;
}

va_char putstr(string str)
{
    auto s = str_to_cstr(str);
    auto ret = std::puts(s);
    cstrfree(s);
    return static_cast<va_char>(ret);
}

void perrorstr(string str)
{
    auto s = str_to_cstr(str);
    std::perror(s);
    cstrfree(s);
}

va_char eof()
{
    return static_cast<va_char>(EOF);
}
