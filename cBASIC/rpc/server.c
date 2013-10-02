/*
 * server.c
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

#include "trans.h"

 

#define MAXNAME 20

#define MAXLENGTH 1024

 

char * readfile(char *name)

{

    FILE *file = fopen(name, "r");

    char * buf = (char *) malloc(sizeof(char) * MAXLENGTH);

    if (file == NULL)

    {

        printf("File Cann't Be Open!");

        return 0;

    }

    printf("The File Content is :");

    while (fgets(buf, MAXLENGTH-1, file) != NULL)

    {
	printf("the current buffer is: %s \n",buf);
        return buf;

    }

    return NULL;

}
