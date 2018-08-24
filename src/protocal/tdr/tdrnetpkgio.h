/*! 
@addtogroup common	
@{

@details  通过socket[TCP]方式来收发TDR数据包

@section _ 使用说明
		    -#，如果使用SendPacket来发送网络包，那么另一端必须用RecvPacket来接收这个包，
			SendPacket与RecvPacket要成对使用

@version 	2011年08月31日 scottpei 创建
*/
#ifndef __TDRNETPKGIO_H__
#define __TDRNETPKGIO_H__

#ifdef __cplusplus
extern "C"{
#endif

#include "tdr/tdr.h"

#define MAX_TDR_PKG_LENGTH 262144

/*!
@brief    	网络原生发包函数, 在发送TDR包前先发送一个long型的长度信息，然后再发送TDR包体
@param[in]	socket -- socket file descriptor
@param[in]  pstPkg --要发送的包体
@param[in]	nLen -- 要发送的消息长度
@param[in]  pstMeta --  要发送网络包的tdr meta
@parma[in]	nTimeout --发包超时时间
@return 	无
*/
int SendRawPacket(int socket, char* pstPkg, int nLen, LPTDRMETA pstMeta, int nTimeout = 500);

/*!
	@brief    	网络发包函数,在发送TDR包前先发送一个long型的长度信息，然后再发送TDR包体
	@param[in]	socket -- socket file descriptor
	@param[in]  pstPkg --要发送的包体
	@param[in]	nLen -- 要发送的消息长度
	@param[in]  pstMeta --  要发送网络包的tdr meta
	@parma[in]	nTimeout --发包超时时间
	@return 	无
*/
int SendPacket(int socket, char* pstPkg, int nLen, LPTDRMETA pstMeta, int nTimeout=500);

/*!
	@brief    	网络收包函数，先接受一个long型长度，再按长度接收一个TDR包体
	@param[in]	socket -- socket file descriptor
	@param[in]  pstPkg --要接收消息的包体
	@param[in]	nLen -- 要接收的消息长度
	@param[in]  pstMeta --  要接收网络包的tdr meta
	@parma[in]	nTimeout --收包超时时间
	@return 	无
*/
int RecvPacket(int socket, char* pstPkg, int nLen, LPTDRMETA pstMeta, int nTimeout=500);

/*! @} */

#ifdef __cplusplus
}
#endif

#endif