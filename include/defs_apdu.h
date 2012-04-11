/**
 * defs_apdu.h
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
 
#ifndef __defs_apdu_H
#define __defs_apdu_H

// Command APDU definitions
#define UPROVE_CLA       0x00

#define CMD_INIT_SET_NOT           0x00
#define CMD_INIT_GET_NOT           0x30
#define CMD_INIT_SET_UIDP          0x01
#define CMD_INIT_GET_UIDP          0x31
#define CMD_INIT_SET_PQG           0x02
#define CMD_INIT_GET_PQG           0x32
#define CMD_INIT_SET_UIDH          0x03
#define CMD_INIT_GET_UIDH          0x33
#define CMD_INIT_SET_PUBKEY        0x04
#define CMD_INIT_GET_PUBKEY        0x34
#define CMD_INIT_SET_EI            0x05
#define CMD_INIT_GET_EI            0x35
#define CMD_INIT_SET_ISSUEVAL      0x06
#define CMD_INIT_GET_ISSUEVAL      0x36
#define CMD_INIT_SET_SPEC          0x07
#define CMD_INIT_GET_SPEC          0x37
#define CMD_INIT_SET_RAWATTRVAL    0x08
#define CMD_INIT_GET_RAWATTRVAL    0x38
#define CMD_INIT_SET_TI            0x09
#define CMD_INIT_GET_TI            0x39
#define CMD_INIT_SET_PI            0x0A
#define CMD_INIT_GET_PI            0x3A
#define CMD_INIT_SET_ATTRVAL       0x0B
#define CMD_INIT_GET_ATTRVAL       0x3B
#define CMD_INIT_GET_ATTRCOUNT     0x3C
#define CMD_INIT_PRECOMPUTE_INPUTS 0x0D

#define CMD_ISSUE_PRECOMPUTE    0x11
#define CMD_ISSUE_SIGMA_A       0x12
#define CMD_ISSUE_SIGMA_B       0x13
#define CMD_ISSUE_SIGMA_R       0x14

#define CMD_PRESENT_SELECT_D         0x20
#define CMD_PRESENT_CHALLENGE_M      0x21
#define CMD_PRESENT_DISCLOSE_AI      0x22
#define CMD_PRESENT_RETURN_RI        0x23
#define CMD_PRESENT_RETURN_SIGMAS    0x24

#define CMD_TEST                     0xFF

// Status words
#define ERR_OK                  0x9000
#define ERR_WRONGCLASS          0x6402
#define ERR_INS_NOT_SUPPORTED   0x6D00
#define ERR_WRONGDATA           0x6A80
#define ERR_WRONGLENGTH         0x6700
#define ERR_WRONGP1P2           0x6B00
#define ERR_WRONGSIGNATURE      0x6982

#endif // __defs_apdu_H
