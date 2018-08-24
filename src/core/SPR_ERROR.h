/**
*
* @file     SPR_ERROR.h
* @brief
*
* @author honyliu jennachen
* @version 1.0
* @date 2017-11-08
*
*
* Copyright (c)  2016-2017, 腾讯科技有限公司互动娱乐研发部
* All rights reserved.
*
*/

#ifndef __SPR_ERROR_H__
#define __SPR_ERROR_H__

/*
*  没有错误
*/
#define   SPR_ERR_NONE                       0
/*
*  线程开启失败，可能的原因是内存不够，或者栈空间不足
*/
#define   SPR_ERR_THREAD_CTREATE_FAIL        -1
/*
*  log文件开启失败，可能原因是路径不正确，或者磁盘已满
*/
#define   SPR_ERR_LOGFILE_OPEN_FAIL          -2
/*
*  线程锁初始化失败，可能原因是使用了过多的线程锁
*/
#define   SPR_ERR_THREADLCON_INIT_FAIL       -3


#define SPR_ERR_SOCKET_INIT_FAIL             -100
/*
*  socket 连接失败
*/
#define SPR_ERR_SOCKET_CONNECT_FAIL          -101
/*
*  socket 发送数据失败
*/
#define SPR_ERR_SOCKET_SEND_FAIL             -102
/*
* socket  接收数据失败
*/
#define SPR_ERR_SOCKET_RECIEVE_FAIL          -103
/*
* socket 关闭失败
*/
#define SPR_ERR_SOCKET_CLOSE_FAIL            -104



/*
错误分析与解决方案:
 0：SPR_ERR_NONE：
	没有错误
-1：SPR_ERR_THREAD_CTREATE_FAIL
	错误详情：栈空间不足，无法开启设定数量的机器人，此错误出现在为机器人开启线程的过程中
	解决方案：
		1.linux平台：
			ulinit -a查看stack size值， ulimit -s (size)将stack size值修改得小一点
		2.windows平台：
			这里提供使用vs时的解决方案：
			2.1 x86平台： vs--项目--属性--链接器--系统--堆栈保留大小 将其设置为65536
			2.2 x64平台： vs--配置管理器--新建x64平台，编译时使用x64平台即可
			如果在windows下使用vs之外的IDE，可以自行查找如何修改堆栈空间的大小，然后修改之即可
-2：SPR_ERR_LOGFILE_OPEN_FAIL
	错误详情：日志文件打开失败，可能性较大的原因有两个：一是对应的目录不存在，二是磁盘空间不足
	解决方案：
		1. 对应的目录不存在：在可执行文件的目录下创建两个文件夹，取名为data和log
		2. 清理日志文件所在的磁盘

-3: SPR_ERR_THREADLCON_INIT_FAIL
    错误详情： 线程锁初始化失败，可能是初始化线程锁的数量太大
	解决方案：
	    减少线程锁数量


*/
#endif

