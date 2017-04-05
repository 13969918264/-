#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS 100
int getword(char *,int)
int binsearch(char *,struct key *, int);

struct key {
	char *word;
	int count;
}keytab[NKEYS] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	/* ... */
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while",0
};



int getword(char *word, int lim);



/*	统计输入中c语言关键字的出现次数	*/
main()
{
	int n;
	char word[MAXWORD];

	while (getword(word,MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((n = binsearch(word,keytab,NKEYS)) >= 0)
				keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	return 0;
}



/*	getword函数：从输入中读取下一个单词或者字符	*/
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim >0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}



/*	binsearch函数：在tab[0]到tab[n-1]中查找单词	*/
int binsearch(char *word, struct key tab[], int )
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n -1;
	while (low <= hign) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid -1;
		else if (cond >0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}
