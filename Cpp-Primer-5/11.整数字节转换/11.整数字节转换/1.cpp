#include <iostream>

using namespace std;

// 管理器类   
class RanderManager
{
public:
	RanderManager()
	{
		// 启动管理器类
	}
	~RanderManager()
	{
		// 析构管理器类
	}
};

static RanderManager myManager;		// 单例设计，在main之前就会调用，无法知道调用顺序

// 可以控制的调用单例
class RanderManager
{
public:
	RanderManager()
	{
		// 启动管理器类
		VideoManager::get();		//需要的时候直接get一个实例
		TextureManager::get();		
	}
	~RanderManager()
	{
		// 析构管理器类
	}

	static RanderManager & get()
	{
		static RanderManager myManager;	// 由于是static 在静态区，所以不会消亡
		return myManager;
	}
};
