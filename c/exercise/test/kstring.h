/*
   head file of kstring.cpp
*/
#ifndef KSTRING_H
#define KSTRING_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>

void Strinfo(const char *dest, size_t len);
void Strxprn(const char *dest, size_t len);

size_t Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, size_t n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, size_t n);
int Strcmp(const char *s, const char *t);
int Strncmp(const char *s1, const char *s2, size_t n);
char *Strstr(const char *dest, const char *sub);
size_t Strindex(const char *dest, const char *sub);
char *Strchr(const char *dest, int c);
char *Strrchr(const char *dest, int c);
size_t Strspn(const char *dest, const char *pre);
size_t Strcspn(const char *dest, const char *pre);
char *Strpbrk(const char *dest, const char *npre);
char *Strsqz(char *dest, int chr);
char *Strtrim(char *dest);
char *Strrev(char *dest);
char *Strdup(const char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);
char *Strsqzs(char *dest, char *sq);


//size_t, char*
char *Strxcpy(char *dest, const char *src, size_t n);
//size_t, char*
char *Strxcat(char *dest, size_t ds, const char *src, size_t n);
//char*, size_t
char *Strxstr(const char *dest, size_t ds, const char *sub, size_t ss);
//size_t
size_t Strxindex(const char *dest, size_t ds, const char *sub, size_t ss);
int Strxcmp(const char *s, size_t ss, const char *t, size_t ts);
//char*, size_t
char *Strxchr(const char *dest, size_t ds, int c);
//char*, size_t
char *Strxrchr(const char *dest, size_t ds, int c);
//size_t
size_t Strxspn(const char *dest, size_t ds, const char *pre, size_t ps);
//size_t
size_t Strxcspn(const char *dest, size_t ds, const char *npre, size_t ns);
//char*, size_t
char *Strxpbrk(const char *dest, size_t ds, const char *npre, size_t ns);
//size_t
size_t Strxsqz(char *dest, size_t ds, int chr);
//size_t
size_t Strxtrim(char *dest, size_t ds);
//char*, size_t
char *Strxrev(char *dest, size_t ds);
//char*
char *Strxdup(const char *dest, size_t ds);
//char*, size_t
char *Strxtoup(char *dest, size_t ds);
//char*, size_t
char *Strxtolow(char *dest, size_t ds);
//size_t
char *Strxsqzs(char *dest, size_t ds, char *sq, size_t ss);

#endif
