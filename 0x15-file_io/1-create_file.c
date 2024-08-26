#include "main.h"

/**
 * 
 * function to create a file name where
 * @filename: name of the file to create 
 * @text_content: a NULL terminated string to write to the file
 * 
 * Returns: 1 on success and -1 on failure 
 * 
 * 
 *
 */
int create_file(const char *filename, char *text_content){
    int fd;
    int nletters;
    int rwr

    if (filename == NULL){
        return (-1); //Return -1 if filename is NULL

    }
    //open file with O_CREATE | 0_WRONLY | 0_TRUNC flags
    int fd = open(filename, O_CREAT |  O_WRONLY | O_TRUNC, 0600);
    
    if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters++)
		;

	rwr = write(fd, text_content, nletters);

	if (rwr == -1)
		return (-1);

	close(fd);

	return (1);
}
}