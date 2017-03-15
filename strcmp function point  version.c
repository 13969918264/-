/*	strcmp函数：根据s按照字典顺序小于等于或大于t的结果分别返回负整数，0和正整数	*/
int strcmp(char *s, char *t)
{
	for ( ; *s == *t;s++,t++)
		if (*s = '\0')
			return 0;
	return *s - *t;
}
