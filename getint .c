#include <stdio.h>

int getch(void);
void ungetch(int);

/*	getline函数：将输入中的下一个整形数赋值给*pn	*/
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))			/*	跳过空白符	*/
		;			/*	新值覆盖旧值	*/
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);			/*	输入的不是一个整数，退回去	*/
		return 0;
	}
	sign = (c == '-' ? -1 : 1);
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
