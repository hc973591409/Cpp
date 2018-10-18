int x = 199;
static int y = 20;                // 用static限定，只能本文件使用，其他文件无法使用

namespace{
	int y = 90;
}

int show(){
	return ::y;                   // ::可以访问全局 static 匿名结构体，优先级 static最高，命名空间最低
}