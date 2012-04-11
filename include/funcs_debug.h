/**
 * funcs_debug.h
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
 
#ifndef __funcs_debug_H
#define __funcs_debug_H

#ifdef SIMULATOR

#include "defs_types.h"

void debugMessage(String message);
void debugWarning(String warning);
void debugError(String error);

void debugInteger(String label, int value);
void debugPointer(String label, ByteArray value);

void debugValue(String label, ByteArray value, int length);

#else // SIMULATOR

#define debugMessage(P1)
#define debugWarning(P1)
#define debugError(P1)

#define debugInteger(P1,P2)
#define debugPointer(P1,P2)

#define debugValue(P1,P2,P3)

#endif // SIMULATOR

#endif // __funcs_debug_H
