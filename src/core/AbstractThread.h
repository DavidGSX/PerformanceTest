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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
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
 * Description ���̻߳���
 * Details     ������ֻҪʵ����runThreadʵ���߳��߼�������createThread�����̼߳���
 */
class AbstractThread
{
private :
	void *m_pThreadHandle;//win��Ϊָ�� HANDLE���͵�ָ�� linux��Ϊָ�� pthread_t��ָ��
	void *m_pThreadAttr;  //win�´�ָ�벻ʹ��  linux��Ϊָ��pthread_attr_t��ָ��	
	public:
	  AbstractThread();
	  int createThread();//�����߳�
	  virtual  void runThread()=0;//�����̺߳����еĺ���
	  virtual ~AbstractThread();

};

#endif
