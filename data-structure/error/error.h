#ifndef _ERROR_HEAD_FILE_
#define _ERROR_HEAD_FILE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Error handle function */
#define Error(a)  do{printf("Error. %-10s: %s\n", __func__, a);}while(0)
#define Exit(a)   do{printf("Error. %-10s: %s\n", __func__, a);exit(1);}while(0)

#endif
