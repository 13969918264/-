/*	makepoint 函数：通过X.Y坐标构造一个点	*/

/*	构造一个结构体，struct是标识符，point的作用类似c++和java中的类class，
	makepoint是point的一个实例	,一个struct类型的函数	*/
/*	抽象和具体的关系	*/
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}
