#include <stdio.h>
// Chapter 6: Structures

// 6.1 Basics of Structures
struct point 
{
	int x;
	int y;
};

struct rect 
{
	struct point pt1;
	struct point pt2;
};

// 6.2 Structures and Functions

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}

/* addpint: add two points */
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
	struct rect temp;

	temp.pt1.x = MIN(r.pt1.x, r.pt2.x);
	temp.pt1.y = MIN(r.pt1.y, r.pt2.y);
	temp.pt2.x = MAX(r.pt1.x, r.pt2.x);
	temp.pt2.y = MAX(r.pt1.y, r.pt2.y);
	return temp;
}

// 6.3 Arrays of Structures
struct key
{
	char *word;
	int count;
} keytab[] = 
{
	"auto"			, 0,
	"break"			, 0,
	"case"			, 0,
	"char"			, 0,
	"const"			, 0,
	"continue"		, 0,
	"default"		, 0,
	"do"			, 0,
	"double"		, 0,
	"else"			, 0,
	"enum"			, 0,
	"extern"		, 0,
	"float"			, 0,
	"for"			, 0,
	"goto"			, 0,
	"if"			, 0,
	"int"			, 0,
	"long"			, 0,
	"register"		, 0,
	"return"		, 0,
	"short"			, 0,
	"signed"		, 0,
	"sizeof"		, 0,
	"static"		, 0,
	"struct"		, 0,
	"switch"		, 0,
	"typedef"		, 0,
	"union"			, 0,
	"unsigned"		, 0,
	"void"			, 0,
	"volatile"		, 0,
	"while"			, 0,
};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))
//Another way:
//#define NKEYS (sizeof keytab / sizeof(struct key))

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
int keyword()
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	
	return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) 
	{
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
	int getch(void);
	void ungetch(int);

	int c;
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

// 6.4 Pointers to Structures
int getword(char *, int);
struct key *p_binsearch(char *, struct key *, int);

/* count C keywords; pointer version */
int p_keyword(void)
{
	char word[MAXWORD];
	struct key *p;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = p_binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *p_binsearch(char *word, struct key *tab, int n)
{
	int cond;
	struct key *low = &tab[0];
	struct key *high = &tab[n];
	struct key *mid;

	while (low < high)
	{
		mid = low + (high - low) / 2;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
}

// 6.5 Self-referential Structures
#undef MAXWORD
#define MAXWORD 100
struct tnode 				/* the tree node : */
{
	char *word;				/* points to the text */
	int count;				/* number of occurrences */
	struct tnode *left;		/* left child */
	struct tnode *right;	/* right child */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

/* word frequency count */
int wordfreq(void)
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *str_dup( char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p == NULL)						/* a new word has arrived */
	{
		p = talloc();					/* make a new node */
		p->word = str_dup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;						/* repeated word */
	else if (cond < 0)					/* less than into left subtree */
		p->left = addtree(p->left, w);
	else								/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order pint of tree p */
void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

#include <stdlib.h>
/* talloc: make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *str_dup(char *s)		/* make a duplicate of s */
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);		/* +1 for '\0' */
	if (p != NULL)
		strcpy(p, s);
	return p;
}

// 6.6 Table Lookup
#undef IN
#define IN 1

struct nlist  					/* table entry: */
{
	struct nlist *next; 		/* next entry in charn */
	char *name;					/* defined name */
	char *defn;					/* replacement text */
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];	/* pointer table */

/* hash: form hash value for string s */
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;
	
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;					/* found */
	return NULL;						/* not found */
}

struct nlist *lookup(char *);
char *str_dup(char *);

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)		/* not found */
	{
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = str_dup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	else									/* already there */
		free((void *) np->defn);			/* free previous defn */
	if ((np->defn = str_dup(defn)) == NULL)
		return NULL;
	return np;
}

// 6.7 Typedef
typedef int Length;
Length len, maxlen;
typedef char *String;
typedef struct tnode *Treeptr;
typedef struct tnode Treenode;
typedef int (*PFI)(char *, char *);
PFI str_cmp, num_cmp;

// 6.8 Unions
union u_tag
{
	int ival;
	float fval;
	char *sval;
}u;

#define NSYM 100

struct 
{
	char *name;
	int flags;
	int utype;
	union
	{
		int ival;
		float fval;
		char *sval;
	}u;
} symtab[NSYM];

// 6.9 Bit-fields
#define KEYWORD 	01
#define EXTERNAL	02
#define STATIC 		03

void flags(void)
{
	int flags = 0;

	struct
	{
		unsigned int is_keyword : 1;
		unsigned int is_extern	: 1;
		unsigned int is_static 	: 1;
	} bitflag;

	flags |= EXTERNAL | STATIC;
	flags &= ~(EXTERNAL | STATIC);
	if ((flags & (EXTERNAL | STATIC)) == 0)
		printf("flags not EXTERNAL nor STATIC\n");
}
	
#define TEST(func) printf("Testing "#func" :\n");func()
int main()
{
	TEST(wordfreq);
	//TEST(p_keyword);
	//TEST(keyword);
	return 0;
}

