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
#ִ��sprǰ���ýű�֪ͨAgentƽ̨����һ��spr����
# ps -ef : ��ѯ���н��� 
# grep -w "${GREP_KEY}" : �����н����в������ΪAPP_NAME�Ľ���,-wΪ��ȷ���� 
# grep -v "grep" : �ų�����Ϊgrep�Ľ��� 
#ǿ��ֹͣ�����˽���
GAPSHOMEDIR=`pwd | xargs dirname` 
killall -9 ${GAPSHOMEDIR}/bin/gapsdatacollect
killall -9 ${GAPSHOMEDIR}/bin/Robot
#���ͽ���������Ϣ
chmod  a+x  ./EndTestReq.sh
#./EndTestReq.sh $1
./EndTestReq.sh daemon

