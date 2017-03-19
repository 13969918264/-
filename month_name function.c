/*	month_name函数：返回第n个月份的名字	*/
char *month_name(int n)
{
	static char *name[] = {
		"illegal month",
		"january","february","march",
		"april","may","june",
		"july","august","september",
		"octomber","november","december"
	};

	return (n < 1 || n > 12) ? name[0] : name [n];
}
