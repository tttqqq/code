1、#pragma pack (n)与#pragma  pack (push,1)的区别

#pragma pack (n)            作用：C编译器将按照n个字节对齐。
#pragma pack ()               作用：取消自定义字节对齐方式，恢復編譯器默認。

#pragma  pack (push,1)     作用：是指把原来对齐方式设置压栈，并设新的对齐方式设置为一个字节对齐
#pragma pack(pop)           作用：恢复对齐状态

可见，加入push和pop可以使对齐恢复到原来状态，而不是编译器默认，因此后者更优。

扩展：
1. #pragma once
保证头文件只被include一次,等同于 
#ifndef _X_H 
#define _X_H
...
#endif //_X_H

2.#pragma comment
原形是#pragma comment( "comment-type" [, commentstring] )，把comment recode放入目标文件或可

执行文件。"comment-type"有五种,其中lib比较常用:#pragma comment(lib,"d3d9x") 在连接时就会把

d3d9x.lib报含到项目中来。其实在IDE中也可以手动的设置把lib文件包含进来。

3.#pragma warning
可以对编译的warning做一些处理.
比如当把float 转成 int时会有一个warning.看到warning总归不爽,而且有些warning心知肚明,肯定不

会引起什么问题,这时候:
#pragma warning(disable:4244)
可以把该警告屏蔽掉.#pragma warning的作用域是本文件,如果是头文件,则会影响到包含它的模块,确保

你的使用不会影响到别人.所以最好及时地恢复warning
#pragma warning( push )
#pragma warning( disable : 4705 )
#pragma warning( disable : 4706 )
// Some code
#pragma warning( pop )
也可以
#pragma warning( disable : 4705 )
#pragma warning( disable : 4706 )
// Some code
#pragma warning( default:  4705 )
#pragma warning( default:  4705 )




关于结构里包含结构体的计算参考blog:
https://blog.csdn.net/Eunice_fan1207/article/details/79696981