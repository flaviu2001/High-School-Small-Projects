#!/bin/bash
#cnr - Compile and Run

name=$(basename "$0")
term=".cpp"
things=""
files=( )
position=1
mainfile="./main"
enable_valgrind=false
super_valgrind=false
non_recursive=""
no_remove=false
my_args=""
gcclib=""

if [ "$name" == "cnrc" ]; then
	term=".c"
fi

while [ $# -gt 0 ]; do
    if [ "$1" == "-l" ]; then
	shift 1
	if [ $# -eq 0 ]; then
	    echo "You have not specified any library."
	else
	    gcclib="-l $1"
	fi
    elif [ "$1" == "-a" ]; then
	shift 1
	if [ $# -eq 0 ]; then
	    echo "You have not specified any argument."
	fi
	while [ $# -gt 0 ]; do
	    my_args="$my_args $1"
	    shift 1
	done
	break
    elif [ "$1" == "-vv" ]; then
	super_valgrind=true
    elif [ "$1" == "-v" ]; then
	enable_valgrind=true
    elif [ "$1" == "-r" ]; then
	non_recursive="-maxdepth 1"
    elif [ "$1" == "-k" ]; then
	no_remove=true
    else
	things="$things"$'\n'"$1"
    fi
    shift 1
done

if [ "$things" == "" ]; then
	things=$PWD
fi

bkp=$IFS
IFS=$'\n'
for location in $things; do
    if [ ! -d "$location" ] && [ ! -f "$location" ]; then
	echo "$location is not a valid directory or file."
	continue
    fi
    if [ -f "$location" ] && [ $(echo $location | grep -c "\(${term}$\)\|\(.h$\)") -eq 1 ]; then
	files[$position]="\"$location\""
	position=$(($position+1))
	if [ $(grep -c "int main(" "$location") -eq 1 ];then
	    mainfile="$(echo "$location" | sed "s/${term}$//")"
	fi
    fi

    if [ -d "$location" ]; then
	bkp2=$IFS
	IFS=$'\n'
	for source_file in $(eval "find \"$location\" $non_recursive"); do
	    if [ -f "$source_file" ] && [ $(echo $source_file | grep -c "\(${term}$\)\|\(.h$\)") -eq 1 ]; then
		files[$position]="\"$source_file\""
		position=$(($position+1))
		if [ $(grep -c "int main(" "$source_file") -eq 1 ];then
		    mainfile="$(echo "$source_file" | sed "s/${term}$//")"
		fi
	    fi
	done
	IFS=$bkp2
    fi
done
IFS=$bkp

mainfile=$(readlink -f "$mainfile")

if [ "$name" == "cnrc" ]; then
    if eval "gcc -Wall -O2 -g ${files[@]} -o \"$mainfile\" $gcclib"; then
		if $super_valgrind; then
		    valgrind --leak-check=full "$mainfile"
		elif $enable_valgrind; then
		    valgrind "$mainfile"
		else
		     eval "\"$mainfile\" $my_args"
		fi
		if ! $no_remove; then
		    rm "$mainfile"
		fi
		exit 0
    fi
    exit 1
fi

if [ "$name" == "cnr" ]; then
    if eval "g++ -std=c++14 -Wall -O2 -g ${files[@]} -o \"$mainfile\" $gcclib"; then
		if $super_valgrind; then
		    valgrind --leak-check=full "$mainfile"
		elif $enable_valgrind; then
		    valgrind "$mainfile"
		else
		    eval "\"$mainfile\" $my_args"
		fi
		if ! $no_remove; then
		    rm "$mainfile"
		fi
		exit 0
    fi
    exit 1
fi
