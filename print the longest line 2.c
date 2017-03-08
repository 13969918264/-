#include <stdio.h>

#define	MAXLINE	1000			/*	允许输入行的最大长度	*/

int max;			/*	到目前为止发现的最长行的长度	*/
char line[MAXLINE];			/*	当前的输入行	*/
char longest[MAXLINE]; 			/*	用于保存最长的行	*/

int getline(void);
void copy(void);




/*	打印最长的输入行：特别版本	*/
main()
{
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getline()) > 0)
		if (len > max)	{
			copy();
		}
	if (max > 0)			/*	存在这样的行	*/
		printf("%s",longest);
	return 0;
}



/*	getline函数:特别版本	*/
int getline(void)
{
	int c, i;
	extern char line[];

	for	(i = 0; i < MAXLINE-1 &&  (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
/*	copy函数：特别版本	*/
void copy(void)
{
	int i;
	extern char line[],longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
