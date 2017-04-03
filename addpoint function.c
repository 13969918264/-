/*	addpoint函数：将两个点相加	*/
struct point addpoint(struct point p1, struct point p2)
{
	p1.x += p2.x;
	p2.y += p2.y;
	return p1;
}
