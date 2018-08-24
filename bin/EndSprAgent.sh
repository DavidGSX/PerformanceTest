#!/bin/sh
GAPSHOMEDIR=`pwd | xargs dirname`
echo -e "\033[35m "send stop req" \033[0m"
${GAPSHOMEDIR}/bin/PlatformAgent -n -c stop
killall -9 ${GAPSHOMEDIR}/bin/gapsdatacollect
