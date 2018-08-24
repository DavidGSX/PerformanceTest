/**
*
* @file     AbstractThread.h
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


#ifndef __ABSTRACTTHREAD_H__
#define __ABSTRACTTHREAD_H__

#include <string>
#include <vector>

using namespace std;

/**
 * 
 * Description ：线程基类
 * Details     ：基类只要实现在runThread实现线程逻辑，调用createThread启动线程即可
 */
class AbstractThread
{
private :
	void *m_pThreadHandle;//win下为指向 HANDLE类型的指针 linux下为指向 pthread_t的指针
	void *m_pThreadAttr;  //win下此指针不使用  linux下为指向pthread_attr_t的指针	
	public:
	  AbstractThread();
	  int createThread();//启动线程
	  virtual  void runThread()=0;//启动线程后运行的函数
	  virtual ~AbstractThread();

};

#endif
