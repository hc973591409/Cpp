
#include <cctype>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void main1()
{
	string s1;			// Ĭ�ϳ�ʼ��
	string s2 = s1;     // ������ʼ��
	string s3("hiya");	//s3�Ǹ��ַ���������ֵ����
	string s4(10, 'c');		// s4��������ccccccccccccccc   10��c

	// ��ʼ����Ϊ���֣�������ʼ����ֱ�ӳ�ʼ�����Ե�����ʼֵ�����ԣ������ʼֵһ��
	// һ��ֻ����ֱ�ӳ�ʼ��
	string s5 = "hiya";		// ������ʼ��
	string s6("huchao");	// ֱ�ӳ�ʼ��
	string s7(10, 'c');		// ֱ�ӳ�ʼ��   cccccccc
	string s8 = string(10, 'c');	// ������ʼ�����½���ʱ����Ȼ�󿽱�
	
	cout << s8 << endl;
	string s9;

	//cin >> s9;							// �����ܴ��ո�����
	//cout << s9 << endl;

	//getline(cin, s9);						// �����ж�ȡһ�У�������
	//cout << s9 << endl;

	cout << s8.size() << endl;					// ��ȡ����
	cout << s8.empty() << endl;					// 0 �ж��ǲ��ǿգ��Ǿͷ���1
	cout << s9.empty() << endl;					// 1

	cout << s3[1] << endl;				// �����ַ�

	s3 = s3 + s4;					// �ַ������
	cout << s3 << endl;

	s1 == s2;							//.�ж����
	s1 != s2;							// �жϲ���
	//< <= > >=							�����жϷ��϶�������
	cin.get();
}

void main2()
{
	string s1;				// ���Զ��������뿪ͷ�Ŀո�
	string s2;	
	cin >> s1 >> s2;		// ���������ͬʱ���ƶ��,�ո���߻��зָ�
	cout << s1 << " " << s2 << endl;

	cin.get();
	system("pause");
}

void main3()
{
	//����getline��ȡһ��
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
	// ��һ���ͱȽϿ�ͷ�ַ���һ�Ƚ�
	//"hello" + "world"; // ����ı��ʽ ������һ����string

	cin.get();
}

void main4()
{
	//string s = "12";
	cout << isalnum('2') << endl;		// �������ַ���0
	cout << isalpha('3') << endl;		// ������ĸ����0
	cout << iscntrl('\n') << endl;			// �ǿ����ַ�Ϊ��
	isdigit('1');
	isgraph('x');    // ���ǿո񣬵��ǿ��Դ�ӡ
	islower('x');
	isupper('x');
	isprint('s');	// �ɴ�ӡ�ַ�
	ispunct('c');	// �Ǳ�����
	isspace(' ');    //�հ׷�
	isxdigit(' ');    //16��������
	tolower(' ');      // ���Сд�ַ�
	toupper(' ');


	cin.get();
}

// תΪ���������
void main()
{
	


	cin.get();
}