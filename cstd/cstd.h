// Copyright (C) 2016-2017 Elias Kosunen
// This file is distributed under the 3-Clause BSD License
// See LICENSE for details

#pragma once

#include <cstdbool>
#include <cstdint>
#include <cstdlib>

using va_i8 = int8_t;
using va_i16 = int16_t;
using va_i32 = int32_t;
using va_i64 = int64_t;
using va_size = std::size_t;

using va_f32 = float;
using va_f64 = double;

using va_bool = bool;
using va_byte = uint8_t;

using va_char = char32_t;
using va_bchar = char;

struct va_string
{
    va_size len;
    va_bchar* ptr;
};
using va_cstring = va_bchar*;

va_string cstr_to_str(va_cstring str);
va_cstring str_to_cstr(va_string str);

va_string stralloc(va_size size);
va_cstring cstralloc(va_size size);

void strfree(va_string str);
void cstrfree(va_cstring str);

va_bool getstr(va_string buf, va_i32 max_size);

va_char putstr(va_string str);

void perrorstr(va_string str);

va_char eof();
