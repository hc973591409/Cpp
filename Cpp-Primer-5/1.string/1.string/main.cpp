
#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void main1()
{
	string s1;			// 默认初始化
	string s2 = s1;     // 副本初始化
	string s3("hiya");	//s3是该字符串的字面值副本
	string s4(10, 'c');		// s4的内容是ccccccccccccccc   10个c

	// 初始化分为两种，拷贝初始化和直接初始化，对单个初始值都可以，多个初始值一般
	// 一般只能用直接初始化
	string s5 = "hiya";		// 拷贝初始化
	string s6("huchao");	// 直接初始化
	string s7(10, 'c');		// 直接初始化   cccccccc
	string s8 = string(10, 'c');	// 拷贝初始化，新建临时对象然后拷贝
	
	cout << s8 << endl;
	string s9;

	//cin >> s9;							// 不接受带空格输入
	//cout << s9 << endl;

	//getline(cin, s9);						// 送流中读取一行，返回流
	//cout << s9 << endl;

	cout << s8.size() << endl;					// 获取长度
	cout << s8.empty() << endl;					// 0 判断是不是空，是就返回1
	cout << s9.empty() << endl;					// 1

	cout << s3[1] << endl;				// 返回字符

	s3 = s3 + s4;					// 字符串相加
	cout << s3 << endl;

	s1 == s2;							//.判断相等
	s1 != s2;							// 判断不等
	//< <= > >=							各种判断符合都可以用
	cin.get();
}

void main2()
{
	string s1;				// 会自动忽略输入开头的空格
	string s2;	
	cin >> s1 >> s2;		// 流输入可以同时复制多个,空格或者换行分割
	cout << s1 << " " << s2 << endl;

	cin.get();
	system("pause");
}

void main3()
{
	//利用getline获取一行
	string line;
	while (getline(cin,line))
	{
		cout << line << endl;
	}

	cin.get();
}

void main4()
{
	string s = "agsa";
	decltype(s.size());

	"hello" < "hello world";
	// 不一样就比较开头字符逐一比较
	//"hello" + "world"; // 错误的表达式 必须有一个是string

	cin.get();
}

void main4()
{
	//string s = "12";
	cout << isalnum('2') << endl;		// 不是数字返回0
	cout << isalpha('3') << endl;		// 不是字母返回0
	cout << iscntrl('\n') << endl;			// 是控制字符为真
	isdigit('1');
	isgraph('x');    // 不是空格，但是可以打印
	islower('x');
	isupper('x');
	isprint('s');	// 可打印字符
	ispunct('c');	// 是标点符号
	isspace(' ');    //空白符
	isxdigit(' ');    //16进制数字
	tolower(' ');      // 输出小写字符
	toupper(' ');


	cin.get();
}

// 转为标题的做法
void main()
{
	


	cin.get();
}