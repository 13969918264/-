#include <string.h>

/*	reverse函数：倒置字符串s中个个字符的位置	*/
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/*	itoa函数；将数字n转换成字符串并保存到s中	*/
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)			/*	记录符号	*/
		n = -n;			/*	使n成为正数	*/
	i = 0;
	do {			/*	以反序生成数字	*/
		s[i++] = n % 10 + '0';			/*为什么用这句话？	*//*	去下一个数字	*/
	} while ((n /= 10) > 0);			/*为什么用这句话？	*//*	删除该数字	*/
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
