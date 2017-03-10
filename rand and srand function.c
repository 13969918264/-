unsigned long int next = 1;

/*	rand函数：返回取值在0~32767之间的伪随机函数	*/
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next/65536) % 32768;
}

/*	srand函数：为rand()函数设置种子数	*/
void srand(unsigned int seed)
{
	next = seed;
}
