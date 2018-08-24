/**
*
* @file     Sampler.h
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

#ifndef __SAMPLER_H__
#define __SAMPLER_H__

#include <string>
#include <iostream>
#include "core/AbstractRobot.h"
#include "core/CommonFunction.h"
#include "core/TpsControler.h"

using namespace std;

/**
 * 
 * Description ��������
 * Details     ���Ի�����ִ������Ľ�����в���
 * @author     ��  moosedong
 * @Aug 17, 2015
 */
class Sampler{
	private:
		
		string m_key;
		//bool m_result;             // ���ؽ�� ���ɹ���1��+ʧ�ܣ�0��
		unsigned char m_detailRes;  // ��ϸ���ؽ�� ���ɹ���1��+ʧ�ܣ�0��+�쳣��2��+��ʱ��3��
		UInt64 m_startTimeInMsec;
		UInt64 m_endTimeInMsec;

		unsigned int m_curTimeInSec;
		unsigned int m_curTimeInUsec;

	public:
		AbstractRobot * m_pRobot;
		Sampler(string key, AbstractRobot *robot);
		static Sampler newSampleStart(string key, AbstractRobot *robot);
		void sampleStart();
		void sampleEnd(unsigned char result);
		//void sampleEnd(bool result);
		string getKey();
		void setKey(string key);
		UInt64 getStartTime();
		void setStartTime(UInt64 startTime);
		UInt64 getEndTime();
		void setEndTime(UInt64 endTime);
		
		unsigned int getCurTimeInSec();
		unsigned int getCurTimeInUsec();

		//bool isResult();
		//void setResult(bool result);
		unsigned char getResult();
		void setResult(unsigned char result);
};

#endif

