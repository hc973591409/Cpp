int x = 199;
static int y = 20;                // ��static�޶���ֻ�ܱ��ļ�ʹ�ã������ļ��޷�ʹ��

namespace{
	int y = 90;
}

int show(){
	return ::y;                   // ::���Է���ȫ�� static �����ṹ�壬���ȼ� static��ߣ������ռ����
}