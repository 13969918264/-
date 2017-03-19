#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char *line, int max);

/*	find 函数：打印与第一个参数指定的模式匹配的行	*/
main(int argc, int argv[])
{
	char line[MAXLINE];
	int found = 0;			/*	对匹配成功的行计数	*/

	if (argc != 2)
		printf("Usage: find pattern\n");
	else
		while (getline(line, MAXLINE) > 0)
		/*	将输入的文本放到line中，且保证长度不超过MAXLINE	*/
			if (strstr(line, argv[1]) != NULL) {
			/*	返回line中有argv[1]的行，否则否则为空不执行	*/
				printf("%s",line);			/*	打印找到的第一行	*/
				found++;
			}
	return found;
}

#define MAXLEN 1000			/*	每个输入文本行的最大长度	*/
int geline(char *, int);
char *alloc(int);

/*	getline函数：将行保存到s中，并返回该行的长度	*/

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

