#include "template/head.h"

#include <fcntl.h>
#include <unistd.h>
#include <dirent.h> 		//struct dirent
#include <sys/dir.h>		//struct dirent ??
#include <sys/types.h>
#include <sys/stat.h>

int stat(const char *, struct stat *);
int fstat(int fd, struct stat *);

//#define NAME_MAX 1024
#define MAX_PATH 4096
typedef struct {
	long ino;
	char name[NAME_MAX + 1];
} Dirent;
typedef struct {
	int fd;
	Dirent d;
} Dir;

Dir *Opendir(const char *dirname);
Dirent *Readdir(Dir *d);
void Closedir(Dir *d);
void Fsize(const char *name);
void Dirwalk(const char *, void (*fcn)(const char *));


void Fsize(const char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1)
	{
		fprintf(stderr, "Fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
	{
		printf("Meet a dir: %s\n", name);
		Dirwalk(name, Fsize);
	}
	printf("%8ld %s\n", stbuf.st_size, name);
}
void Dirwalk(const char *dir, void (*fcn)(const char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	Dir *dfd;

	if ((dfd = Opendir(dir)) == NULL)
	{
		fprintf(stderr, "Dirwalk: can't open %s\n", dir);
		return;
	}
	while ((dp = Readdir(dfd)) != NULL)
	{
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "Dirwalk: name %s/%s too long\n", dir, dp->name);
		else
		{
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
}
Dir *Opendir(const char *dirname)
{
	int fd;
	struct stat stbuf;
	Dir *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1
		|| fstat(fd, &stbuf) == -1
		|| (stbuf.st_mode & S_IFMT) != S_IFDIR
		|| (dp = (Dir *) malloc(sizeof(Dir))) == NULL)
	{
		printf("Open dir error: %s\n", dirname);
		return NULL;
	}
	printf("Dir opened: %s\n", dirname);
	dp->fd = fd;
	return dp;
}
void Closedir(Dir *dp)
{
	if (dp) 
	{
		close(dp->fd);
		free(dp);
	}
}
#ifndef DIRSIZ 
#define DIRSIZ 256
#endif
Dirent *Readdir(Dir *dp)
{
	struct direct dirbuf;
	static Dirent d;
	//for debuf:
	size_t read_size;

	printf("Readdir, fd: %10d\n", dp->fd);
	while ((read_size = read(dp->fd, (char *) &dirbuf, sizeof(dirbuf))) == sizeof(dirbuf))
	{
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIRSIZ);
		d.name[DIRSIZ] = '\0';
		return &d;
	}
	printf("Readir() read: %ld, return NULL\n", read_size);
	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		Fsize(".");
	else
		while (--argc > 0)
			Fsize(*++argv);
	return 0;
}