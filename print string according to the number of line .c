#include <stdio.h>
#include <string.h>

#define MAXLINES 5000			/*	进行排序的最大文本行数	*/

char *lineptr[MAXLINES];			/*	指向文本的指针数组	*/

/*	各种函数声明	*/
int readlines(char *lineptr[], int nlines);
void writeline(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);



/*	对输入的文本行进行排序	*/
main()
{
	int nlines;			/*	读取的输入行数目	*/

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
			qsort(lineptr, 0, nlines-1);
			writelines(lineptr,nlines);
			return 0;
	} else {
		printf("error: input too big to sort\n");
	}
}



#define	ALLOCSIZE	10000			/*	可用空间大小	*/

static char allocbuf[ALLOCSIZE];			/*	alloc使用的存储区（操作系统分配的）	*/
/*	allocbuf是默认的缓冲区大小	*/
static char *allocp = allocbuf;			/*	下一个空闲位置	*/

char *alloc(int n)			/*	返回指向n个字符的指针	*/
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {			/*	有足够的空闲空间	*/
		allocp += n;			/*	新的缓冲块的地址，将allocp指针移动到下一个缓存块	*/
		return allocp - n;
		/*
		分配前的指针，因为上面只是检测了有没有足够的大小存储
		可以将要存储的数据，并且将指针已经移动到新的缓存块的地址，
		但我们存储东西是还需要在原来的地址开始存储
		*/
	} else			/*	空闲空间不够，及系统缓存区剩余的空间不足以存储即将输入的数据	*/
		return 0;
}
void afree(char *p)			/*	释放p指向的存储区	*/
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
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

/*	writelines函数：写输出行	*/
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n",lineptr[i]);
}

/*	改写writelines函数：写输出行	*/
/*
void wtitelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}
*/


/*	qsort函数：按递增顺序对v[left]*...v[right]进行排序	*/
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)			/*	如果数组元素的个数小于2，则返回	*/
		return;
	swap(v,left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i],v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v,last+1, right);
}

/*	swap函数：交换v[i]和v[j]	*/
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
