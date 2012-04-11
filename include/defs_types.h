/**
 * defs_types.h
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Copyright (C) Pim Vullers, Radboud University Nijmegen, April 2012.
 */
 
#ifndef __defs_types_H
#define __defs_types_H

#include "defs_sizes.h"

typedef const char *String;

typedef unsigned char Byte;
typedef Byte *ByteArray;

typedef struct {
  unsigned char number_w[1];
  unsigned char number[PSIZE_BYTES];
} NUMBER_PSIZE;

typedef struct {
  unsigned char number_w[1];
  unsigned char number[QSIZE_BYTES];
} NUMBER_QSIZE;

typedef struct {
  int attr_size;
  unsigned char attr_val[MAX_ATTR_SIZE];
} ATTRIBUTE;

#endif // __defs_types_H
