#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 32767

typedef char *HuffmanCode; 
typedef struct
{
int Weight; //字母的权
int Parent, Leftchild, Rightchild; 
}HuffmanTree; 

void Select(HuffmanTree *HT, int n, int *s1, int *s2)
{
	int min1 = MAX; 
	int min2 = MAX; 
	int pos1,  pos2; 
	int i; 

	for(i = 0; i < n; i++)
	{
		if(HT[i].Parent == -1)//选择还没有父亲的节点
		{
			if(HT[i].Weight <= min1)
			{
				pos2 = pos1;  
				min2 = min1; 
				pos1 = i;  
				min1 = HT[i].Weight; 
			}
			else if(HT[i].Weight <= min2)
			{
				pos2 = i;  
				min2 = HT[i].Weight; 
			}
		}
	}
	*s1 = pos1; 
	*s2 = pos2; 
}

void CreateTree(HuffmanTree *HT, int n, int *w)

{

int m=2*n-1; //总的节点数

int s1, s2; 

int i; 

for(i=0; i<m; i++)

{

if(i<n)

HT[i].Weight=w[i]; 

else

HT[i].Weight=-1; 

HT[i].Parent=-1; 

HT[i].Leftchild=-1; 

HT[i].Rightchild=-1; 

}

for(i=n; i<m; i++)

{

Select(HT, i, &s1, &s2); //这个函数是从0到n-1中选两个权最小的节点

HT[i].Weight=HT[s1].Weight+HT[s2].Weight; 

HT[i].Leftchild=s1; 

HT[i].Rightchild=s2; 

HT[s1].Parent=i; 

HT[s2].Parent=i; 

}

}

void Print(HuffmanTree *HT, int m)

{

if(m!=-1)

{

printf("%d ", HT[m].Weight); 

Print(HT, HT[m].Leftchild); 

Print(HT, HT[m].Rightchild); 

}

}

void Huffmancoding(HuffmanTree *HT, int n, HuffmanCode *hc, char *letters)

{

char *cd; 

int start; 

int Current, parent; 

int i; 

cd=(char*)malloc(sizeof(char)*n); //用来临时存放一个字母的编码结果

cd[n-1]='\0'; 

for(i=0; i<n; i++)

{

start=n-1; 

for(Current=i, parent=HT[Current].Parent;  parent!=-1;  Current=parent, parent=HT[parent].Parent)

if(Current==HT[parent].Leftchild)//判断该节点是父节点的左孩子还是右孩子

cd[--start]='0'; 

else

cd[--start]='1'; 

hc[i]=(char*)malloc(sizeof(char)*(n-start)); 

strcpy(hc[i], &cd[start]); 

}

free(cd); 

for(i=0; i<n; i++)

{

printf("letters：%c, weight：%d, 编码为 %s\n", letters[i], HT[i].Weight, hc[i]); 

printf("\n"); 

}

}

void Encode(HuffmanCode *hc, char *letters, char *test, char *code)

{

int len=0; 

int i, j; 

for(i=0; test[i]!='\0'; i++)

{

for(j=0; letters[j]!=test[i]; j++){}

strcpy(code+len, hc[j]); 

len=len+strlen(hc[j]); 

}

printf("The Test ： %s \nEncode to be ：", test); 

printf("%s", code); 

printf("\n"); 

}

void Decode(HuffmanTree *HT, int m, char *code, char *letters)

{

int position=0, i; 

printf("The Code： %s \nDecode to be ：", code); 

while(code[position]!='\0')

{

for(i=m-1; HT[i].Leftchild!=-1&&HT[i].Rightchild!=-1; position++)

{

if(code[position]=='0')

i=HT[i].Leftchild; 

else

i=HT[i].Rightchild; 

}

printf("%c", letters[i]); 

}

}

int main()

{

int n=27; 

int m=2*n-1; 

char letters[28]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 

'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '}; 

int w[28]={64, 13, 22, 32, 103, 21, 15, 47, 57, 1, 5, 32, 20, 

57, 63, 15, 1, 48, 51, 80, 23, 8, 18, 1, 16, 1, 168}; 

char code[200]; 

char test[50]={"this is about build my life"}; 

HuffmanTree *HT; 

HuffmanCode *hc; 

HT=(HuffmanTree *)malloc(m*sizeof(HuffmanTree)); 

hc=(HuffmanCode *)malloc(n*sizeof(char*)); 

CreateTree(HT, n, w); 

Print(HT, m-1); 

printf("\n"); 

Huffmancoding(HT, n, hc, letters); 

Encode(hc, letters, test, code); 

Decode(HT, m, code, letters); 

printf("\n"); 

return 0; 

}

