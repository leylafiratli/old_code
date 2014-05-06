#!/bin/bash
echo "Input 1 => Relational Distance and Friend Suggestions - Users Large"
read -p "Press any key to continue"
./social_network users_large.txt < grade_input1
echo "Input 2 => Relational Distance and Friend Suggestions - Users Large2"
read -p "Press any key to continue"
./social_network users_large2.txt < grade_input1
echo "Input 3 => Disjoint Sets - 1 (1 Group)"
read -p "Press any key to continue"
./social_network users_large2.txt < grade_input2
echo "Input 3 => Disjoint Sets - 2 (2 Groups)"
read -p "Press any key to continue"
./social_network users_large_disjoint2.txt < grade_input2
echo "Input 3 => Disjoint Sets - 3 (4 Groups)"
read -p "Press any key to continue"
./social_network users_large_disjoint.txt < grade_input2
#echo "Input 4 => Hubs (Users_Large)"
#read -p "Press any key to continue"
#./social_network users_large.txt < grade_input3
#echo "Input 4 => Hubs (Users_Large2)"
#read -p "Press any key to continue"
#./social_network users_large2.txt < grade_input3
#echo "Input 4 => Hubs (Users_Small)"
#read -p "Press any key to continue"
#./social_network users_small.txt < grade_input3
