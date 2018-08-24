#!/bin/sh
GAPSHOMEDIR=`pwd | xargs dirname`
chmod a+x *

ERR_Previous_Process_Exist=1
ERR_WRITE_PID_FILE_ERR=2
ERR_UpdateVersion_err=3
ERR_SendStartTestReq_err=4
ERR_SendEndTestReq_err=5
ERR_SaveCfg_err=6
ERR_LoadConfig_err=7 
ERR_RestartProcess_err=8
ERR_RUN_ERR=9

declare -A errorInfodic
errorInfodic=([$ERR_Previous_Process_Exist]="process already exist!!" \
		 [$ERR_SendStartTestReq_err]="send StartTestReq Faild!" \
         [$ERR_WRITE_PID_FILE_ERR]="ERR_WRITE_PID_FILE_ERR" \
         [$ERR_UpdateVersion_err]="ERR_UpdateVersion_err" \
         [$ERR_SendEndTestReq_err]="Send EndTestReq_err" \
         [$ERR_SaveCfg_err]="ERR_SaveCfg_err" \
         [$ERR_LoadConfig_err]="ERR_LoadConfig_err" \
         [$ERR_RestartProcess_err]="ERR_RestartProcess_err" \
         [$ERR_RestartProcess_err]="ERR_RestartProcess_err" \
         ) 


logger()
{
	logLevel=$1
	logStr=$2
	if [ "$logLevel" == 'ERROR' ]
	then
	     echo -e "\033[31m $logStr \033[0m"
	elif [ "$logLevel" == 'WARN' ]
	then
	     echo -e "\033[35m $logStr \033[0m"
	elif [ "$logLevel" == 'INFO' ]
	then
	     echo -e "\033[37m $logStr \033[0m"	
	else
	     echo -e "\033[31m unkown logLevel \033[0m"

	fi


}
#logger "INFO" "start PlatFormAgent process"
logger "WARN" "-----step1:start PlatFormAgent process "
logger "INFO" "check the newest version.."
logger "INFO" "send StartTest Req to server."
logger "INFO" "connecting.."
${GAPSHOMEDIR}/bin/PlatformAgent

errcode=$?
for key in $(echo ${!errorInfodic[*]})
do
        #echo "$key : ${errorInfodic[$key]}"
	if [ $errcode == $key ]
	then 
        logger "ERROR" "start failed , errstr : ${errorInfodic[$key]}"
        logger "ERROR" "ensure the IDCFlag value in ../config/platformagent_conf.xml is right (1:IDCnet , 0 :非IDCnet)"
	fi
done

if [ $errcode == 0 ]
then
      ProjectID=`cat ../config/platformagent_conf.xml|grep ProjectID|awk -F "[<>]" '{print $3}'`
      TestID=`cat ../config/platformagent_conf.xml|grep TestID|awk -F "[<>]" '{print $3}'`
      host=`cat ../config/platformagent_conf.xml|grep IntranetServer|grep "qq.com"|awk -F "[<>]" '{print $3}'`
      logger "ERROR" "start success,report url is http://${host}/gaps/ConfigRunning?projectid=${ProjectID}&i_testid=${TestID}"
fi

#start datacollect
chmod a+x start_datacollect.sh
./start_datacollect.sh daemon

