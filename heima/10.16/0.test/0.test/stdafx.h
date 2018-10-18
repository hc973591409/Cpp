#pragma once
// stdafx.h : 标准系统常使用，但是不常更改的包含文件
// 特定与项目的包含文件

# include <stdio.h>
# include <tchar.h>
# include "targetver.h"
// 因为VS里的很多字符编码都是采用unicode来编码的，为了兼容字符集。微软开发了tchar包，tchar 在unicode下是wchar（双字符），
//而普通是char。 因为C++支持两种字符串，即常规的ANSI编码和Unicode编码，这样对应的就有了两套字符串字符串处理函数，比如：
//strlen和wcslen，分别用于处理两种字符串 。微软将这两套字符集及其操作进行了统一，通过条件编译（通过_UNICODE和UNICODE宏）
//控制实际使用的字符集，这样就有了_T("")这样的字符串，对应的就有了_tcslen这样的函数 。　　
//为了存储这样的通用字符，就有了TCHAR： 当没有定义_UNICODE宏时，TCHAR = char，_tcslen = strlen；
//当定义了_UNICODE宏时，TCHAR = wchar_t ， _tcslen = wcslen 。当我们定义了UNICODE宏，就相当于告诉了编译器：
//我准备采用UNICODE版本。这个时候，TCHAR就会变成了wchar_t。而未定义UNICODE宏时，TCHAR变成了unsigned char 。
//这样就可以很好的切换宽窄字符集。tchar可用于双字节字符串，使程序可以用于中日韩等国 语言文字处理、显示。使编程方法简化。

// TODO: 在此处引用程序所需要的其他头文件