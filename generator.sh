#!/bin/bash

# AUTHOR: Daniel Robinson 2021 
# Takes two arguments as such
# generator [FSTRING] [optional: START] [END] [optional: STEP]

#check there is 2-4 args
if [ -z "$2" ] || [ -n "$5" ]; then
	echo USAGE: generator [FSTRING] [optional: START] [END] [optional: STEP]
	exit 1
fi

#set start and end
if [ -n "$3" ]; then
	fstart="$2"; fend="$3"
else
	fstart=0; fend="$2"
fi

#set step
if [ -n "$4" ]; then
	fstep="$4"
else
	fstep=1
fi

fstring="$1" #set string

#check numerical args are actually numerical
num='^[0-9]+$'
if ! [[ "$fstart" =~ $num ]]; then
	echo "Invalid Start"; exit 1;
elif ! [[ "$fstep" =~ $num ]]; then
	echo "Invalid Step"; exit 1;
elif ! [[ "$fend" =~ $num ]]; then
	echo "Invalid End"; exit 1;
fi

#replace all ? with number (except for \?)
for i in `seq $fstart $fstep $fend`
do
	fout=$fout$(echo "$fstring" | sed "s/\\\?/\\\temp/g" |  sed "s/?/$i/g" | sed "s/\\\temp/?/g")\\n
done

fout=$(echo -e "$fout" | sed '$d') #remove excess \n on last line
echo -e "$fout" #print to terminal
echo -e "$fout" | xclip -selection c #copy to clipboard

exit 0
