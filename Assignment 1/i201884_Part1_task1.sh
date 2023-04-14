#Ahmed Baig
#20i-1884
#Part 1
#Task 1

((pattern = $1))
((rows = $2))

echo
case $1 in

	left)
	#left
	for((i=1; i<=rows; i++))
	do
		for((j=1; j<=i; j++))
		do
			echo -n "*"
		done
	echo
	done
	for((i=rows-1; i>=1; i--))
	do
		for((j=1; j<=i; j++))
		do
			echo -n "*"
		done
	echo
	done
	
	;;
	
	right)
	#right
	((r=rows-1))
	((r1=rows-1))
	for((i=1; i<=rows; i++))
	do
		for((j=1; j<=r; j++))
		do
			echo -n " "
		done
		((r--))
		for((k=1; k<=i; k++))
		do
			echo -n "*"
		done
		echo
	done

	for((i=1; i<=rows; i++))
	do
		for((j=1; j<=i; j++))
		do
			echo -n " "
		done
		for((k=1; k<=r1; k++))
		do
			echo -n "*"
		done
		((r1--))
		echo
		
	done



	;;
	
	full)
	
	#full
	((r=rows-1))
	for((i=1; i<=rows; i++))
	do
        for((j=1; j<=r; j++))
        do
			echo -n " "
		done
        ((r--))
        for((k=1; k<=(2*i-1); k++))
        do
			echo -n "*"
		done
        echo
    done
    
   ((r = 1));
    for((i=1; i<=rows-1; i++))
    do
        for((j=1; j<=r; j++))
        do
			echo -n " "
		done
        ((r++))
        for((k=1; k<=(2*(rows-i)-1); k++))
        do
			echo -n "*"
		done
        echo
    done

	echo

	;;

	*)
	echo -n "Invalid Input. Program terminated."
	;;
	esac
	
	echo

