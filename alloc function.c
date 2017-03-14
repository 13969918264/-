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
