#!/bin/bash
#cd ../
#corename=`find . -name "corefile-*"|xargs ls -t|sed -n '1p'`
corenames=`find ./ -name "corefile-*" -mmin -0.1|xargs -i ls -t {} |sed -n '1p'`

if [ -n "$corenames" ];then
    for corename in $corenames
    do
        program=`echo $corename|cut -d '-' -f 2`
        gdb bin/$program $corename -ex=bt -ex=q  >check_core.log 2>&1
        nr=`grep -n 'Program terminated with signal' check_core.log |awk -F: '{print $1}'`
        if [ $? -eq 0 ]; then
            sed -n ''"${nr}"' , $p' check_core.log >core.log 
            pathnames=`grep '/data/home' core.log |awk -F ' ' '{print $NF}'`

            for pathname in $pathnames 
            do                          
                filename=${pathname##*/}
                sed -i  "s#${pathname}#${filename}#g" core.log

            done                       
            cat core.log
        fi
        rm -rf check_core.log core.log
    done
else
    echo "nocore"
fi
