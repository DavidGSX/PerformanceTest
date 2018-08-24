#!/bin/bash
##############################################################
# begin.sh           V1.0.1                                  #
#------------------------------------------------------------#
# History:                                                   #
#  1.2018/05/21 create                                       #
#------------------------------------------------------------#
# Author: jennachen Date:2018/05/21                          #
# CopyRight (C) 2017 by Tencent                              #
##############################################################

# begin.sh脚本执行示例：
# ./begin.sh robotNum=10 startIndex=1 robotPerSec=30 tranTotal=1 robotScene=battleScene

chmod  a+x *

#加载lib库路径
LIBHOMEDIR=`pwd | xargs dirname`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LIBHOMEDIR/lib

#获取参数
ROBOT_ARGS=""
ARGS_INDEX=1
for i in $@
do
	if [ ${ARGS_INDEX} -ge 1 ]
	then
		ROBOT_ARGS=${ROBOT_ARGS}${i}" "
	fi
	let ARGS_INDEX++
done

./SprRobotRunHelper.sh  daemon Robot $ROBOT_ARGS


