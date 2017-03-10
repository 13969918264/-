/*	getbits函数：返回x中从p位开始的的n位	*/
unsigned getbits(unsigned x,int p,int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
