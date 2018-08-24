#!/bin/bash
##############################################################
# getScene.sh V1.0.0                                  #
#------------------------------------------------------------#
# History:                                                   #
#  1.2017/11/23 create                                       #
#------------------------------------------------------------#
# Author:  jennachen  Date:2017/11/23                        #
# CopyRight (C) 2017 by Tencent                              #
##############################################################
rm -f SceneList.txt
chmod a+x ./getSceneHelper.sh
chmod a+x ./Robot
#./getSceneHelper.sh $1 Robot nodeModel=2 
./getSceneHelper.sh daemon Robot nodeModel=2 
