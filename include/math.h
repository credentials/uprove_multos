/**
 * math.h
 *
 * This file is part of IRMAcard.
 *
 * IRMAcard is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * IRMAcard is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with IRMAcard. If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) April 2013 - 2013.
 *   Pim Vullers <pim@cs.ru.nl>, Radboud University Nijmegen.
 */

#ifndef __MATH_H
#define __MATH_H

#include "MULTOS.h"

// x ^= y
#define XorAssign(bytes, x, y) \
  __push(BLOCKCAST(bytes)(y)); \
  __code(XORN, __typechk(unsigned char *, x), bytes); \
  __code(POPN, bytes)

#define Increment(bytes, x) \
  __code(INCN, x, bytes)

#define IncrementBytes(bytes, x) \
  __push((void *)(x)); \
  __push(BLOCKCAST(bytes)(x)); \
  __code(INCN, bytes); \
  __code(STOREI, bytes);

#define ModMul(ModulusLength, LHS, RHS, Modulus) \
do { \
  __push(__typechk(unsigned int, ModulusLength)); \
  __push(__typechk(unsigned char *, LHS)); \
  __push(__typechk(unsigned char *, RHS)); \
  __push(__typechk(unsigned char *, Modulus)); \
  __code(PRIM, PRIM_MODULAR_MULTIPLICATION); \
} while (0)

#ifdef SIMULATOR
#undef RSA_VERIFY
#endif

#ifdef RSA_VERIFY

#define ModExp(ExponentLength, ModulusLength, Exponent, Modulus, Base, Result) \
do { \
  __push(__typechk(unsigned int, ExponentLength)); \
  __push(__typechk(unsigned int, ModulusLength)); \
  __push(__typechk(const unsigned char *, Exponent)); \
  __push(__typechk(const unsigned char *, Modulus)); \
  __push(__typechk(const unsigned char *, Base)); \
  __push(__typechk(unsigned char *, Result)); \
  __code(PRIM, PRIM_RSA_VERIFY); \
} while (0)

#endif // RSA_VERIFY

#define ModExpSecure(ExponentLength, ModulusLength, Exponent, Modulus, Base, Result) \
do { \
  __push(__typechk(unsigned int, ExponentLength)); \
  __push(__typechk(unsigned int, ModulusLength)); \
  __push(__typechk(const unsigned char *, Exponent)); \
  __push(__typechk(const unsigned char *, Modulus)); \
  __push(__typechk(const unsigned char *, Base)); \
  __push(__typechk(unsigned char *, Result)); \
  __code(PRIM, PRIM_MODULAR_EXPONENTIATION); \
} while (0)

#ifndef ModExp
  #define ModExp ModExpSecure
#endif // !ModExp

extern unsigned char MATH_flag;

#define IfCarry(action) \
do { \
  __code(PRIM, PRIM_LOAD_CCR); \
  __code(PRIM, PRIM_BIT_MANIPULATE_BYTE, (1<<7 | 3), (1<<3)); \
  __code(PRIM, PRIM_SHIFT_RIGHT, 1, 3); \
  __code(STORE, &MATH_flag, 1); \
  if (MATH_flag != 0x00) { action; } \
} while (0)

#define IfZero(bytes, value, action) \
do { \
  __code(TESTN, value, bytes); \
  __code(PRIM, PRIM_LOAD_CCR); \
  __code(PRIM, PRIM_BIT_MANIPULATE_BYTE, (1<<7 | 3), 1); \
  __code(STORE, &MATH_flag, 1); \
  if (MATH_flag != 0x00) { action; } \
} while (0)

#define IfZeroBytes(bytes, value, action) \
do { \
  __push((void *)(value)); \
  __code(LOADI, bytes); \
  __code(TESTN, bytes); \
  __code(PRIM, PRIM_LOAD_CCR); \
  __code(PRIM, PRIM_BIT_MANIPULATE_BYTE, (1<<7 | 3), 1); \
  __code(STORE, &MATH_flag, 1); \
  __code(POPN, bytes + sizeof(void *)); \
  if (MATH_flag != 0x00) { action; } \
} while (0)

#endif // __MATH_H
