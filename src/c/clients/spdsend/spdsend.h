/* Declarations for spdsend
   Author: Milan Zamazal <pdm@brailcom.org>
*/

/* Copyright (C) 2004 Brailcom, o.p.s.

   COPYRIGHT NOTICE

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation, version 2 of the License.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
*/


#ifndef __SPDSEND_H

#define __SPDSEND_H


#define _GNU_SOURCE

#include <stddef.h>


/* Configuration */

#ifndef LISTEN_QUEUE_LENGTH
#define LISTEN_QUEUE_LENGTH 100
#endif

/* Types */

typedef enum { FALSE, TRUE } bool;
typedef int Stream;
typedef int Connection_Id;

typedef enum { OK, ERROR } Success;
#define NONE -1

/* common.c */

extern Success write_data (Stream s, const void *buffer, size_t size);
extern int read_data (Stream s, void *buffer, size_t max_size);
extern Success forward_data (Stream from, Stream to, bool closep);

typedef enum { A_OPEN, A_CLOSE, A_DATA } Action;

typedef enum { OK_CODE, ER_CODE } Result;

extern const long CONNECTION_ID_MIN;
extern const long CONNECTION_ID_MAX;

extern const int EXIT_OK;
extern const int EXIT_ERROR;

/* server.c */

extern Stream open_server ();

/* client.c */

extern Success open_connection (Stream server, const char *host, int port);
extern Success close_connection (Stream server, Connection_Id id);
extern Success send_command (Stream server, Connection_Id id);


#endif