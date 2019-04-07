#!/bin/bash
if [[ -d $2 ]]
then
	if [[ -d $1 ]]
	then    
		for FILE in $1/*
		do
			if [[ -f "$FILE" ]]
			then
				./check_brackets < $FILE
				echo "The result should be: "
				cat $2/$(basename $FILE).a
				echo "tested file $FILE with exit code $?"
				echo				
			fi
		done
	else
		echo "No such directory $1"
		exit 1
	fi
fi
