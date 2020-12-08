#! /usr/bin/env zsh
########################COLORS########################
DEFAULT="\033[0m"
HIGHLIGHT="\033[1m"
UNDERLINE="\033[4m"
BLINK="\033[5m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
PURPLE="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
######################################################
var=0
echo "
${YELLOW}~~~~~~~~~~~~~~~~~~~~~ Script Diff ~~~~~~~~~~~~~~~~~~~~~~~~~~~
${GREEN}1 : NM
${BLUE}2 : OTOOL
${DEFAULT}
"
read var
if [ -n "$var" ]
then
	if [ ${var} == 1 ]
	then
		echo "Enter the path of tests :
		"
		read path
		echo "${YELLOW}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		${DEFAULT}"
		for entry in "$path"/*
		do
			if [[ -f $entry ]]
			then
				echo ${GREEN}"$entry"${DEFAULT}
				echo ""
				./ft_nm ${entry} > a
				nm ${entry} > b
				result=$(diff a b)
				echo ${result}
				echo "
---------------------------------------------------------------
"
				rm -rf a b
			fi
		done
	elif [ ${var} == 2 ]
	then
		echo "Enter the path of tests :
		"
		read path
		echo "${YELLOW}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		${DEFAULT}"
		for entry in "$path"/*
		do
			if [[ -f $entry ]]
			then
				echo ${GREEN}"$entry"${DEFAULT}
				echo ""
				./ft_otool ${entry} > a
				otool -t ${entry} > b
				result=$(diff a b)
				echo ${result}
				echo "
---------------------------------------------------------------
"
				rm -rf a b
			fi
		done
	fi
fi
