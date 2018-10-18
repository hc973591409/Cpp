#pragma  once
//以下是宏定义要求的最低平台
// 是具有运行程序所需要功能的Windows Internet Explorer 等产品的最早产品
// 必须在最低平台以上才能正常工作

// 如果必须要低于指定平等 修改下列定义
// MSDN查询即可
#ifndef _WIN32_WINNT               //指定最低平台是 Windows Vista
#define _WIN32_WINNT 0x0600         //修改这个值就可以更改位相应版本
#endif // !_WIN32_WINNT               //指定最低平台是 Windows Vista
