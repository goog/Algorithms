/*
 * client.c
 * 
 * Copyright 2013 drill <drill@cheng>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <rpc/rpc.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include "trans.h"

 

#define WSVERS MAKEWORD(0, 2)

#define RMACHINE "localhost"

CLIENT *handle;

 

#define MAXNAME 20

#define MAXLENGTH 1024

 

char * readfile(char *);

 

int main()

{

    char name[MAXNAME];

    char * buf;

    printf("Enter File Name:");
    scanf("%s", name);

    handle = clnt_create(RMACHINE, FILETRANSPROG, FILETRANSVERS,"tcp"); // portmap is needed.

   if (handle == 0) {
         printf("Could Not Connect To Remote Server.\n");
         exit(1);
   }

    buf = readfile(name);
    printf("%s", buf);
    return 0;

}

