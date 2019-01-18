#!/bin/bash

# check for whether we're clang or gcc
# setup the right options depending on the environment variables
# run the build

echo $CC
#CC=clang #force it for testing. having trouble with travis
if [ "${CC}" == "clang" ]
then
	make config T=x86_64-native-linuxapp-clang
elif [ "${CC}" == "gcc" ]
then
	make config T=x86_64-native-linuxapp-gcc
else
	echo "compiler env variable not set"
	exit 1
fi

make all
