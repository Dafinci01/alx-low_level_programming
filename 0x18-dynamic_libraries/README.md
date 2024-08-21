DYNAMIC LIBRARY Project

a dynamic library known as shared library is a collection of Data and code that can be used by multiple programs 

difference between static and Dynamic lib
unlike static libraries that limnked into an excutable at compile time, dynamic libraries are loaded into memory at runtime , this allow efficiency 


HOW it works 

creating a dynamic library in c 

create a source file 

#include <stdio.h>

void hello(){
	printf("Hello, World!\n");

}

COMPILE THE CODE 	
use the gcc compiler with the -fPIC (position independt code) and -shared flags 

gcc -fPIC -shared -o licmylib.so mylib.c


USE THE LIB; in thr main progrsm include the heasder and link against the library 

#include <stdio.h>

void hello(); //declarion of the function

int main() {
     hello();
     return 0;

}

COMPILE THE MAIN PROGRAM 
gcc -0 main main.c -L. -lmylib 

RUN THE PROGRAM 
export ID_LIBRARY_PATH=:#LD_LIBRARY_PATH


ENVIRONMENT VARIABLE $LD_LIBRARY_PATH 

$LD_LIBRARY_PATH is an environment variable used in unix - like operating sysytems to specify 
a list of directories where the dynamuc linker should look for dynamix libraries 
before searching the standard library paths 

export ID_LIBRARY_PATH=/path/to your/library:$LD_LIBRARY_PATH./your_program

Basic Usage of nm, ldd and Idconfig 

nm: Lists symbols from object files. It can show functions are defined in a library 
nm libmylib.so

ldd ./your_program 


