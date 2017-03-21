#include <stdio.h>
#include <string.h>

#define MAXLINES 5000			/*	待排序的最大行数	*/
char *lineptr[MAXLINES];			/*	指向文本行的指针	*/

void qsort(void *lineptr[], int left, int right,int (*comp)(void *, void *));
int geline(char *, int);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines)；

/*	对输入的文本行进行排序	*/
main(int argc, char argv[])
{
	int nlines;			/*	读入的输入行数	*/
	int numeric = 0;			/*	若进行数值排序，则numeric的值为1	*/

	if (argc > 1 && strcmp(argv[1], "-n") == 0)
		numeric = 1;
	if ((nlines = readlines(lineptr,MAXLINES)) >= 0) {
		qsort((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr,nlines);
		return 0;
	} else {
		printf("input too big to sort\n");
		return 1;
	}
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

/*	readlines函数：读取输入行	*/
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	/*
		当行的长度大于零时，判断输入的行数是否大于最大的规定的行数
		或者已经分配的内存空间剩余的空间是否可以存储这些数据，若行
		数超过或者没有可分配空间则返回—1；否则则将行数组最后一位放
		入结束符，并将行数组复制到p，再将p的地址赋值给行指针数组，
		并将行指针数组向后移动一位。
	*/
	while ((len = getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len -1] = '\0';			/*	赋值结束符	*/
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}



/*	qsort函数：以递增顺序对v[left]...v[right]进行排序	*/
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)			/*	如果数组元素个数小于2，则不执行任何操作	*/
		return;
	swap(v, left, (right + left)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last,i);
	swap(v, left, last);
	qsort(v, left, last-1, comp);
	qsort(v, last-1, right, comp);
}



#include <stdio.h>

/*	numcmp函数：按树枝顺序比较字符串s1和s2	*/
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}



void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
