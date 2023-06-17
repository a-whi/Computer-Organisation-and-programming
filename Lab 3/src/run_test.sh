#!/bin/bash
make

# Code Cracking test cases
# Original
python3 run_tests.py "code_cracking" "../data/encrypted.txt" "$(../outputs/code_cracking ../data/encrypted.txt)" "6 3 42 5 548 72 57 1 12 9" "1"

# My own
python3 run_tests.py "code_cracking" "../data/test_codecracking.txt" "$(../outputs/code_cracking "../data/test_codecracking.txt")" "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16" "2"

########################################################################################################
# Code for Music Analysis
# Original
python3 run_tests.py "music_analysis" "../data/music_info.txt" "$(../outputs/music_analysis ../data/music_info.txt)" "Everybody_Wants_To_Rule_The_World - Tears_For_Fears, Songs_From_The_Big_Chair (1985 - 989363525)
You_Get_What_You_Give - New_Radicals, Maybe_You've_Been_Brainwashed_Too (1998 - 336115780)
Tick_Tick_Boom - The_Hives, The_Black_and_White_Album (2007 - 81016902)
Welcome_to_the_Machine - Pink_Floyd, Wish_You_Were_Here (1975 - 74901584)
Future_Starts_Slow - The_Kills, Blood_Pressures (2011 - 51912174)" "3"
# My own
python3 run_tests.py "music_analysis" "../data/music_info_two.txt" "$(../outputs/music_analysis ../data/music_info_two.txt)" "The_Day_The_World_Went_Away - Nine_Inch_Nails, The_Fragile (1999 - 120)
CIA - New_Politics, Lost_In_Translation (2017 - 76)
Welcome_to_the_Machine - Pink_Floyd, Wish_You_Were_Here (1975 - 52)
West_End_Kids - New_Politics, Vikings (2015 - 45)
Im_Afraid_Of_Americans - David_Bowie, Earthling (1997 - 43)" "4"