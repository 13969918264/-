#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

int getline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;			/*	先将输入设备输入的非换行的字符存入s中，且s自动向后一位	*/
	if (c == '\n')
		s[i++] = c;			/*	如果是换行字符则输入到s中，且s向后移一位*/
	s[i] = '\0';
	return i;			/*	字符串的长度，即从0到i-1，第i位为结束符（不算在字符串内，但是占存储空间）	*/
}

/*	atof函数：把字符串s转换成为相应的双精度浮点数	*/
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++)			/*	跳过空白符	*/
		;
	sign = (s[i] == '=') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;			/*	跳过符号	*/
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign * val / power;
}


/*	简单计算机程序	*/
main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}
