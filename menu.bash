#!/usr/bin/bash

tput setaf 2
#while loop that repeats program until termination is triggered by the user
while true
do
    echo "
    Choose an option
    A) List files in directory supplied as an argument
    B) Display today's date
    C) Display whether a given argument is an ordinary file or a directory
    D) Compare two files given as argument and display if they are equal or not
    E) exit
    "
    #receives user input and stores into variable 'input'
    read input
    #validates as true if user input is lower or uppercase a
    if [[ $input = "A" || $input = "a" ]];
    then
        echo -n "Directory:"
        read dir
        #prints contents of user specified directory
        ls $dir
    elif [[ $input = "B" || $input = "b" ]];
    then
        #prints the date after setting the text color to red, then back to green
        tput setaf 1;date;tput setaf 2;
    elif [[ $input = "C" || $input = "c" ]];
    then
        echo -n "Enter path to file or directory:"
        read fidir
        #checks to see if user specified entity is a directory
        if test -d $fidir
        then
            tput setaf 1;echo "Directory";tput setaf 2;
        #checks to see if user input is a file
        elif test -f $fidir
        then
            tput setaf 1;echo "File"; tput setaf 2;
        fi
    elif [[ $input = "D" || $input = "d" ]];
    then
        echo -n "First File:"
        read f1
        echo -n "Second File:"
        read f2
        #Compares two files, both inputted by the user
        if cmp -s $f1 $f2
        then
            tput setaf 1;echo "Both files are the same";tput setaf 2;
        else
            tput setaf 1;echo "Both files are different";tput setaf 2;
        fi
    elif [[ $input = "E" || $input = "e" ]];
    then
        #ends the while loop, stops execution
        break
    fi
done
