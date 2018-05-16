#!/bin/bash
#
#

i=8000

while [ $i -lt 100000 ]
do
    ./main 1 $i $i 1
			
    i=$(($i+100))
done
		       
