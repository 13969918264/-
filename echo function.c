#include <stdio.h>

/*	回显程序命令行参数：版本1	*/
main(int argc, int argv[])
{
	/*
	argc用于参数计数，表示参数的数目
	argv用于参数向量，指向字符串数组的指针，每个字符串对应一个指针
	*/

	int i;

	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc-1) ? " " : "");
	printf("\n");
	return 0;
}
