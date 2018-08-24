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
* Copyright (c)  2016-2017, ��Ѷ�Ƽ����޹�˾���������з���
* All rights reserved.
*
*/

#ifndef __SPR_ERROR_H__
#define __SPR_ERROR_H__

/*
*  û�д���
*/
#define   SPR_ERR_NONE                       0
/*
*  �߳̿���ʧ�ܣ����ܵ�ԭ�����ڴ治��������ջ�ռ䲻��
*/
#define   SPR_ERR_THREAD_CTREATE_FAIL        -1
/*
*  log�ļ�����ʧ�ܣ�����ԭ����·������ȷ�����ߴ�������
*/
#define   SPR_ERR_LOGFILE_OPEN_FAIL          -2
/*
*  �߳�����ʼ��ʧ�ܣ�����ԭ����ʹ���˹�����߳���
*/
#define   SPR_ERR_THREADLCON_INIT_FAIL       -3


#define SPR_ERR_SOCKET_INIT_FAIL             -100
/*
*  socket ����ʧ��
*/
#define SPR_ERR_SOCKET_CONNECT_FAIL          -101
/*
*  socket ��������ʧ��
*/
#define SPR_ERR_SOCKET_SEND_FAIL             -102
/*
* socket  ��������ʧ��
*/
#define SPR_ERR_SOCKET_RECIEVE_FAIL          -103
/*
* socket �ر�ʧ��
*/
#define SPR_ERR_SOCKET_CLOSE_FAIL            -104



/*
���������������:
 0��SPR_ERR_NONE��
	û�д���
-1��SPR_ERR_THREAD_CTREATE_FAIL
	�������飺ջ�ռ䲻�㣬�޷������趨�����Ļ����ˣ��˴��������Ϊ�����˿����̵߳Ĺ�����
	���������
		1.linuxƽ̨��
			ulinit -a�鿴stack sizeֵ�� ulimit -s (size)��stack sizeֵ�޸ĵ�Сһ��
		2.windowsƽ̨��
			�����ṩʹ��vsʱ�Ľ��������
			2.1 x86ƽ̨�� vs--��Ŀ--����--������--ϵͳ--��ջ������С ��������Ϊ65536
			2.2 x64ƽ̨�� vs--���ù�����--�½�x64ƽ̨������ʱʹ��x64ƽ̨����
			�����windows��ʹ��vs֮���IDE���������в�������޸Ķ�ջ�ռ�Ĵ�С��Ȼ���޸�֮����
-2��SPR_ERR_LOGFILE_OPEN_FAIL
	�������飺��־�ļ���ʧ�ܣ������Խϴ��ԭ����������һ�Ƕ�Ӧ��Ŀ¼�����ڣ����Ǵ��̿ռ䲻��
	���������
		1. ��Ӧ��Ŀ¼�����ڣ��ڿ�ִ���ļ���Ŀ¼�´��������ļ��У�ȡ��Ϊdata��log
		2. ������־�ļ����ڵĴ���

-3: SPR_ERR_THREADLCON_INIT_FAIL
    �������飺 �߳�����ʼ��ʧ�ܣ������ǳ�ʼ���߳���������̫��
	���������
	    �����߳�������


*/
#endif

