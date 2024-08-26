#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * 
 * 
 *read_textfile -  reads a text file and prints to POSIX standard 
 * @filename: name of file to read 
 * @letters: number of letters to read and print 
 * 
 * 
 * Return: actua; numebr of leteters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters) {
	int fd;
	ssize_t lenr, lenw;
	char *buffer;

	if (filename == NULL) {
		return 0;// return 0 if filename is NULL
	}
	int fd = open(filename, O_RDONLY);//open file for readonly
	if (fd == -1){
		return 0; //return if file cannot be opened
	}
	
	buffer = malloc(sizeof(char)* letters); //allocate memroy for  buffer 
	if (buffer == NULL) 
	{
		close (fd);
		return (0); //return 0 if memory allocation fails 
	}
	lenr = read(fd, buffer, letters); // read from files 
	close(fd);
	if (lenr == -1)
	{
		free(buffer);
		return(0)//return 0 if reading fails 
	}
	lenw = write(STDOUT_FILENO, buffer, lenr); //write to standard output 
	free(buffer);
	if (lenr != lenw)
			return (0);
	return(lenw);

}