/*	ptinrect函数：如果点p在矩形rect中，则返回1，否则返回0	*/
int ptinrect(struct point p, strct rect r)
{
	return p.x >= r.pt1.x && p.x <= r.pt2.x && p.y >= r.pt1.y && p.y <= r.pt2.y;
}
