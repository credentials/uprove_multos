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

#include "funcs_debug.h" 

#ifdef SIMULATOR

#include <stdio.h> // for printf()

/********************************************************************/
/* Debug functions                                                  */
/********************************************************************/

void debugMessage(String message) {
  printf("[MSG] %s\n", message);
}

void debugWarning(String warning) {
  printf("[WRN] %s\n", warning);
}

void debugError(String error) {
  printf("[ERR] %s\n", error);
}

void debugInteger(String label, int value) {
  printf("%s: %d\n", label, value);
}

void debugPointer(String label, ByteArray value) {
  printf("%s: %p\n", label, value);
}

void debugValue(String label, ByteArray value, int length) {
  int i;

  printf("%s: ", label);
  for (i = 0; i < length; i++) {
    printf("%02X", value[i]);
  }
  printf("\n");
}

#endif // SIMULATOR
