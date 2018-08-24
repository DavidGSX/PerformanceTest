#!/bin/bash
#!/bin/bash
##############################################################
# SprRobotRun.sh V1.0.1                                      #
#------------------------------------------------------------#
# History:                                                   #
#  1.2018/05/21 create                                       #
#------------------------------------------------------------#
# Author: jennachen Date:2018/05/21                          #
# CopyRight (C) 2017 by Tencent                              #
##############################################################

# begin_offline.sh脚本执行示例：
# ./begin_offline.sh robotNum=1 startIndex=0 robotPerSec=30 tranTotal=1000 robotScene=battleScene

chmod  a+x *

#加载lib库路径
LIBHOMEDIR=`pwd | xargs dirname`
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$LIBHOMEDIR/lib

#拉起SprAgent
./StartSprAgent.sh

#获取参数
ROBOT_ARGS=""
ARGS_INDEX=1
for i in $@
do
	if [ ${ARGS_INDEX} -ge 1 ]
	then
		ROBOT_ARGS=${ROBOT_ARGS}${i}" "
		#echo ${ROBOT_ARGS}
	fi
	let ARGS_INDEX++
done
#启动spr机器人
./SprRobotRunHelper.sh start Robot $ROBOT_ARGS

#停止SprAgent
./EndSprAgent.sh
