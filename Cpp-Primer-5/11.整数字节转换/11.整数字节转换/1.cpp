#include <iostream>

using namespace std;

// ��������   
class RanderManager
{
public:
	RanderManager()
	{
		// ������������
	}
	~RanderManager()
	{
		// ������������
	}
};

static RanderManager myManager;		// ������ƣ���main֮ǰ�ͻ���ã��޷�֪������˳��

// ���Կ��Ƶĵ��õ���
class RanderManager
{
public:
	RanderManager()
	{
		// ������������
		VideoManager::get();		//��Ҫ��ʱ��ֱ��getһ��ʵ��
		TextureManager::get();		
	}
	~RanderManager()
	{
		// ������������
	}

	static RanderManager & get()
	{
		static RanderManager myManager;	// ������static �ھ�̬�������Բ�������
		return myManager;
	}
};
