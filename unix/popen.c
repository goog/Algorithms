#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void write_data(FILE *stream)
{
	int i;
	for(i =0;i < 50;i++)
	{
		fprintf(stream,"line %2d \n", i);  //发送信息(参数)到由stream(流)指定的文件. 
		if(ferror(stream))
			{exit(0);}
	}
	
}

int main(void)
{
	FILE *output;
	output = popen("more -10","w");
	if(!output)
	{exit(0);}
	write_data(output);// convert the data to standard input.
	pclose(output);
	return EXIT_SUCCESS;

}
