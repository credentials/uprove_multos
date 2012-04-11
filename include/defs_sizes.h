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
 * Copyright (C) Pim Vullers, Radboud University Nijmegen, April 2012.
 */
 
#ifndef __sizes_H
#define __sizes_H


// Attribute definitions
#define MAX_ATTR         0x01
#define MAX_ATTR_SIZE    0xFF

// System parameter lengths
#define PSIZE_BITS       1024
#define PSIZE_BYTES      (PSIZE_BITS / 8)
#define QSIZE_BITS       160
#define QSIZE_BYTES      (QSIZE_BITS / 8)


// Variable byte size definitions
#define TI_length 29
#define PI_length 30
#define UID_H_length 5
#define S_length 31

#define TEMP_SIZE 2048

// Auxiliary sizes

#endif // __sizes_H
