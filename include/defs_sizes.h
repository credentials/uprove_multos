/**
 * defs_sizes.h
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
 * Copyright (C) Pim Vullers, Radboud University Nijmegen, July 2011.
 */
 
#ifndef __sizes_H
#define __sizes_H

// Attribute definitions
#define MAX_ATTR      9

// System parameter lengths
#define LENGTH_N      1024
#define LENGTH_M       256
#define LENGTH_STATZK   80
#define LENGTH_H       160 // SHA-1
#define LENGTH_E       501 // > L_STATZK(80) + L_H(160) + L_M(256) + 4

// Variable byte size definitions
#define SIZE_L      MAX_ATTR + 1
#define SIZE_N      128 // 1024 bits
#define SIZE_M       32 //  256 bits
#define SIZE_STATZK  10 //   80 bits
#define SIZE_H       20 //  160 bits
#define SIZE_V      201 // 1604 bits
#define SIZE_E       63 //  504 bits

#define SIZE_VPRIME  (SIZE_N + SIZE_STATZK) // 138 bytes
#define SIZE_VPRIME_ (SIZE_N + 2*SIZE_STATZK + SIZE_H) // 168 bytes
#define SIZE_M_      (SIZE_M + SIZE_STATZK + SIZE_H + 1) // 63 bytes

#define SIZE_BUFFER_C1 ((SIZE_H+2) + 2*(SIZE_N+3) + (SIZE_STATZK+2) + 3 + 4)
#define SIZE_BUFFER_C2 ((SIZE_H+2) + 3*(SIZE_N+3) + (SIZE_STATZK+2) + 3 + 4)

// Auxiliary sizes
#define SIZE_S_EXPONENT 96

#endif // __sizes_H
