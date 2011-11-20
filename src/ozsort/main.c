/*
 * main.c
 *
 *  Created on: 2011-11-11
 *      Author: liheyuan
 */

#include "ozsort.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

void test_ozsort_work()
{
    OZSort param;
    strcpy(param._src, "/tmp/test_db/key.dat");
    printf("%d\n", ozsort_work(&param));
	printf("%ld\n", param._mlines);
}

int main(int argc, char** argv)
{
	/* Argumengs */
	OZSort param;
	FILE* fp;
	char c;
	size_t len;
	if(argc!=2)
	{
		printf("Usage:\n");
		printf("%s  keyfile(key.dat)\n", argv[0]);
		return -1;
	}
	
	/* merge sort */
	strncpy(param._src,  argv[1], OZ_BUF_SIZE);
	if(!ozsort_work(&param))
	{
		/* print lines */
		printf("%lld\n", param._mlines);
		fp = fopen(param._merge, "rb");
		if(!fp)
		{
			return -1;
		}

		while( (c=fgetc(fp))!=EOF )
		{
			putchar(c);
		}
		
		fclose(fp);

		/* unlink */
		unlink(param._merge);

		return 0;
	}
	else
	{
		/* error */
		printf("0\n");
		return 2;
	}
	

}
