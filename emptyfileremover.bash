#!/usr/bin/bash
echo "Enter directory:"
#stores user input into variable 'directory'
read directory
#changes current directory to user specified directory
cd $directory
#enumerates through all the files in the directory, using variable FILE as a placeholder for the file name
for FILE in *;
    do
        #for each file, display the length with wc -l, parse the integer with regex and store it in len
        len=`wc -l $FILE | grep -Eo '[0-9]{1,4}' ;`
        #if len is 0(empty file), then remove the file
        if [ $len -eq 0 ]
        then
            rm -rf $FILE
        fi
    done
