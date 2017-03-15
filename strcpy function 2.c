/*	strcpy函数：将指针t指向的字符串复制到指针s所指向的字符串；使用指针方式实现的版本1	*/
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		/*	指针向后移动一位（根据指针类型决定，逻辑上的移动一位，非物理一位）	*/
		s++;
		t++;
	}
}