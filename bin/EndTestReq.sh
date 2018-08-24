#!/bin/sh
##############################################################
# EndTestReq.sh V1.0.0                                  #
#------------------------------------------------------------#
# History:                                                   #
#  1.2017/11/21 create                                       #
#------------------------------------------------------------#
# Author: jennachen  Date:2017/11/21                         #
# CopyRight (C) 2017 by Tencent                              #
##############################################################
readonly APP_PATHNAME=./EndTestReq
usage()
{
    echo "usage:$0 start|daemon|stop|status|clean|rmlog"
    echo "      $0 start        #start app in foreground mode."
    echo "      $0 daemon       #start app in daemon mode."
    echo "      $0 stop         #stop app."
    echo "      $0 status       #query app run status."
    echo "      $0 rmlog        #remove all log."
	echo "      $0 rmdata       #remove all data."
    echo "      $0 clean        #clean all test enviroment(output files and log)."
    echo "app_version:"`$APP_PATHNAME -v`" (md5:"`md5sum $APP_PATHNAME`")"
    exit -1
}

#Clean all enviroment before tapp is running.
clean()
{
    #TODO: add your code here.
    rm ./data/*
    rm ./log//*
    echo "[INFO]$APP_PATHNAME clean enviroment is succ."
}

#Remove all log before tapp is running.
rmlog()
{
    #TODO: add your code here.
    rm ./log/*
    echo "[INFO]$APP_PATHNAME remove log is succ."
}

#Remove all log before tapp is running.
rmdata()
{
    #TODO: add your code here.
    rm ./data/*
    echo "[INFO]$APP_PATHNAME remove data is succ."
}

case $1 in
start)
    PROC_ID=`ps -ef|grep "$APP_PATHNAME $2 $3 $4 $5 $6 $7 $8 $9"|grep -v grep|awk '{print $2}'`
    if [ X"$PROC_ID" != X ]
    then
        echo "$APP_PATHNAME is running,not advise more than one instance"
        ps -ef | grep $APP_PATHNAME | grep -v grep | awk '{printf("kill -9 %s\n",$2)}' | sh
        if [ -e $APP_PATHNAME ] ; then
            $APP_PATHNAME -n $2 $3 $4 $5 $6 $7 $8 $9
        else
            echo "$APP_PATHNAME is not in current directory,Please change to correct directory"
            exit 2
        fi
    else
        if [ -e $APP_PATHNAME ] ; then
            $APP_PATHNAME -n $2 $3 $4 $5 $6 $7 $8 $9
        else
            echo "$APP_PATHNAME is not in current directory,Please change to correct directory"
            exit 2
        fi
    fi
    ;;	
daemon)
    PROC_ID=`ps -ef|grep "$APP_PATHNAME $2 $3 $4 $5 $6 $7 $8 $9"|grep -v grep|awk '{print $2}'`
    if [ X"$PROC_ID" != X ]
    then
        echo "$APP_PATHNAME is running,not advise more than one instance"
        #ps -ef | grep $APP_PATHNAME | grep -v grep | awk '{printf("kill -9 %s\n",$2)}' | sh
        #if [ -e $APP_PATHNAME ] ; then
        #    $APP_PATHNAME $2 $3
        #else
        #    echo "$APP_PATHNAME is not in current directory,Please change to correct directory"
        #    exit 2
        #fi
    else
        if [ -e $APP_PATHNAME ] ; then
            $APP_PATHNAME $2 $3 $4 $5 $6 $7 $8 $9 > ./log/runtimelog.log 2>&1 &
        else
            echo "$APP_PATHNAME is not in current directory,Please change to correct directory"
            exit 2
        fi
    fi
    ;;    
stop)
    PROC_ID=`ps -ef|grep "$APP_PATHNAME $2 $3 $4 $5 $6 $7 $8 $9"|grep -v grep|awk '{print $2}'`
    if [ X"$PROC_ID" != X ]
    then
        kill -9 $PROC_ID
    fi
    exit 0
    ;;    
status)
    RET=`ps -ef|grep "$APP_PATHNAME $2 $3 $4 $5 $6 $7 $8 $9"|grep -v grep`
    if [ X"$RET" = X ]
    then
        exit -1
    fi
    echo $RET   
    exit 0
    ;;    
clean)
    clean
    exit 0
    ;;
rmlog)
    rmlog
    exit 0
    ;;	
rmdata)
    rmlog
    exit 0
    ;;	
help|*)
    usage
    ;;
esac


