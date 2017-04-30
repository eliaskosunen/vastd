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

using va_f32 = float;
using va_f64 = double;

using va_bool = bool;
using va_byte = uint8_t;

using va_char = char32_t;
using va_bchar = char;

struct string
{
    va_i64 len;
    va_bchar* ptr;
};
using string2 = string;
using cstring = va_bchar*;
using cstring2 = cstring;

cstring cstrcpy(cstring dest, cstring2 src);
va_i64 cstrlen(cstring str);
va_i32 cstrcmp(cstring lhs, cstring2 rhs);

string strcpy(string dest, string2 src);
va_i64 strlen(string str);
va_i32 strcmp(string lsh, string2 rhs);

string cstr_to_str(cstring str);
cstring str_to_cstr(string str);

string stralloc(va_i64 size);
cstring cstralloc(va_i64 size);

void strfree(string str);
void cstrfree(cstring str);

va_bool getstr(string buf, va_i32 max_size);

va_char putstr(string str);

void perrorstr(string str);

va_char eof();
