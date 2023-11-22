// 8.6 Example -- Listing Directories
#define NAME_MAX 1024			/* longest filename component; */
								/* system - dependent */
typedef struct					/* portalble directory entry: */
{
	long ino;					/* inode number */
	char name[NAME_MAX + 1];	/* name + '\0' terminator */
}Dirent;

typedef struct					/* minimal DIR: no buffering, etc. */
{
	int fd;						/* file descriptor for directory */
	Dirent d;					/* the directory entry */
}DirNode;

DirNode *open_dir(char *dirname);
Dirent *read_dir(DirNode *dfd);
void close_dir(DirNode *dfd);

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

void fsize(char *);

/* print file sizes */
int main(int argc, char *argv[])
{
	if (argc == 1)				/* default: current directory */
		fsize(".");
	else
		while (--argc > 0)
			fsize(*++argv);
	return 0;
}

void dir_walk(char *, void (fcn)(char *));

/* fsize: print size of file "name" */
void fsize(char *name)
{
	struct stat stbuf;

	if (stat(name, &stbuf) == -1)
	{
		fprintf(stderr, "fsize: can't access %s\n", name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dir_walk(name, fsize);
	printf("%8ld %s\n", stbuf.st_size, name);
}

#define MAX_PATH	1024
/* dir_walk: apply fcn to all files in dir */
void dir_walk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	Dirent *dp;
	DirNode *dfd;

	if ((dfd = open_dir(dir)) == NULL)
	{
		fprintf(stderr, "dir_walk: can't open %s\n", dir);
		return;
	}
	while ((dp = read_dir(dfd)) != NULL)
	{
		if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
			continue;					/* skip self and parent */
		if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
			fprintf(stderr, "dir_walk: name %s/%s too long \n", dir, dp->name);
		else
		{
			sprintf(name, "%s/%s", dir, dp->name);
			(*fcn)(name);
		}
	}
	close_dir(dfd);
}

#ifndef DIR_SIZ
#define DIR_SIZ 	14
#endif
struct direct				/* directory entry */
{
	ino_t d_ino;			/* inode number */
	char d_name[DIR_SIZ];	/* long name does not have '\0' */
};

/* open_dir: open a directory for read_dir calls */
DirNode *open_dir(char *dirname)
{
	int fd;
	struct stat stbuf;
	DirNode *dp;

	if ((fd = open(dirname, O_RDONLY, 0)) == -1 
		|| fstat(fd, &stbuf) == -1
		|| (stbuf.st_mode &S_IFMT) != S_IFDIR
		|| (dp = (DirNode *) malloc(sizeof(DirNode))) == NULL)
			return NULL;
	dp->fd = fd;
	return dp;
}


/* close_dir: close directory opend by opendir */
void close_dir(DirNode *dp)
{
	if (dp)
	{
		close(dp->fd);
		free(dp);
	}
}

#include <sys/dir.h>
#include <sys/stat.h>

/* read_dir: read directory entries in sequence */
Dirent *read_dir(DirNode *dp)
{
	struct direct dirbuf;
	static Dirent d;

	while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf))
	{
		if (dirbuf.d_ino == 0)
			continue;
		d.ino = dirbuf.d_ino;
		strncpy(d.name, dirbuf.d_name, DIR_SIZ);
		d.name[DIR_SIZ] = '\0';
		return &d;
	}
	return NULL;
}




