#include <stdio.h>
#include <stdlib.h> 
  
long int findsize(char file_name[]) 
{
    FILE* fp = fopen(file_name, "r"); 
  
    if (fp == NULL) { 
        printf("File Not Found!\n"); 
        return -1; 
    } 
  
    fseek(fp, 0L, SEEK_END); 
  
    long int res = ftell(fp); 
  
    fclose(fp); 
  
    return res; 
} 

int main ()
{
	FILE *fptr;
	char path[256];
	char* data;

	printf("Enter the path of file : ");
	scanf("%s",path);
	long int file_size = findsize(path);
	
	data = malloc(file_size);

	fptr = fopen(path,"rb");

	int i = 0;
	while (!feof(fptr))
		data[i++] = fgetc(fptr);
	fclose(fptr);

	fptr = fopen(path, "wb");

	for (int j=0; j<i-1; j++)
		fputc((data[j] ^ 0x60), fptr);
	fclose(fptr);
	free(data);

	return 0;
}
