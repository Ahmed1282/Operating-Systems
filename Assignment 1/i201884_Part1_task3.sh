#Ahmed Baig
#20i-1884
#Part 1
#Task 3

echo "Enter directory you want to move to: "

read directory_name

c=0


for dir in *
do
if [ -d "$dir" ] && [ "$dir" = $directory_name ]; then
    c=1
fi
done

while [ $c -ne 1 ]
do
echo -e "Directory '$directory_name' is not present.\nPlease enter directory currently present in current directory."
read directory_name
for dir in *
do
    if [ -d "$dir" ] && [ "$dir" = $directory_name ]; then
        c=1
    fi
done
done

cd $directory_name
while [ true ]
do

echo -e "For forward action, Enter forward and for backward action, Enter backward, To exit, enter exit.\n"
read action

    while [ "$action" != "forward" ] && [ "$action" != "Forward" ] && [ "$action" != "backward" ] && [ "$action" != "Backward" ] && [ "$action" != "exit" ] && [ "$action" != "Exit" ]; 
    do
        echo "Please only enter the provided options."
        echo -e "For forward action, Enter forward and for backward action, Enter backward, To exit, enter exit.\n"
        read action
    done

case $action in

forward|Forward)

    mkdir txt

    mkdir cc

    mkdir java

    mkdir cpp
    mkdir others

    
    for directory in *
    do
        
        if [ -d "$directory" ] && [ "$directory" != "java" ] && [ "$directory" != "others" ] && [ "$directory" != "cpp" ] && [ "$directory" != "cc" ] && [ "$directory" != "txt" ]; then
            cd $directory
            for filename in *
            
            do
                
            if [ -f "$filename" ]; then
            newname=$filename
            newname="-${newname}"
            newname=$directory$newname
            mv $filename $newname
            fi

            done
                
            mv *.java ../java
            mv *.txt ../txt
            mv *.cpp ../cpp
            mv *.cc ../cc
            mv * ../others
            cd ..
            rm -rf $directory
        fi

    done
;;

backward|Backward)  
    for directory in *
    do
        if [ -d "$directory" ] && ( [ "$directory" = "java" ] || [ "$directory" = "cpp" ] || [ "$directory" = "cc" ] || [ "$directory" = "others" ] || [ "$directory" = "txt" ] ); then
            echo "dir: "$directory
            cd $directory
            for filename in *
            do
                if [ -f "$filename" ]; then
                Dirname=$(echo $filename | cut -d'-' -f 1)
                newname=$(echo $filename | cut -d'-' -f 2)
                mv $filename $newname
                cd ..
                mkdir $Dirname
                cd $directory
                mv $newname ../$Dirname
                fi
            done
            cd ..
            rm -rf $directory
        fi
    done

;;
exit|Exit)
    echo "Exiting Program"
    exit
;;

esac
done
exit
Footer
