#include<stdio.h>

/*将文件复制到输出：版本*/
main()
{
	int c;

	c = getchar();
	while(c != EOF){
		putchar(c);
		c = getchar();
	}
}
