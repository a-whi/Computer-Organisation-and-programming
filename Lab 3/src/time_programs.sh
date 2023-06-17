#!/bin/bash
####################################################

# For music analysis
startTime=$(date +%s.%N)

for i in {1..100}
do
    # Original
    ../outputs/music_analysis ../data/music_info.txt > /dev/null
done

endTime=$(date +%s.%N)
timeDifference=$(echo "$endTime-$startTime" | bc)
echo 'Music analysis: ' 
echo $timeDifference

####################################################

# For code cracker
startTime=$(date +%s.%N)

for i in {1..100}
do
    ../outputs/code_cracking ../data/encrypted.txt > /dev/null
done

endTime=$(date +%s.%N)
timeDifference=$(echo "$endTime-$startTime" | bc)
echo 'Code cracking: ' 
echo $timeDifference