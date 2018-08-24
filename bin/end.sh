#!/bin/sh	
##############################################################
# end.sh V1.0.0                                              #
#------------------------------------------------------------#
# History:                                                   #
#  1.2017/11/23 create                                       #
#------------------------------------------------------------#
# Author: jennachen Date:2017/11/23                          #
# CopyRight (C) 2017 by TencentIERD                          #
##############################################################
chmod  a+x  *
#执行spr前调用脚本通知Agent平台创建一个spr任务
# ps -ef : 查询所有进程 
# grep -w "${GREP_KEY}" : 从所有进程中查出名称为APP_NAME的进程,-w为精确查找 
# grep -v "grep" : 排除名称为grep的进程 
#强制停止机器人进程
GAPSHOMEDIR=`pwd | xargs dirname` 
killall -9 ${GAPSHOMEDIR}/bin/gapsdatacollect
killall -9 ${GAPSHOMEDIR}/bin/Robot
#发送结束测试消息
chmod  a+x  ./EndTestReq.sh
#./EndTestReq.sh $1
./EndTestReq.sh daemon

