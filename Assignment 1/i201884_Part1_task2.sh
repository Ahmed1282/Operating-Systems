#Ahmed Baig
#20i-1884
#Part 1
#Task 2
	
	echo Select your option 
	echo 1. Change permissions of random file
	echo 2. Search a string in a file
	echo 3. Copy contents of the current directory in a new file
	echo 4. Change modified date for old files
	echo Enter exit to exit the program
	
	read choice
	
	
	case $choice in

	1)
	echo Enter your file name. Please make sure that the file already exists in the current directory
	read flname

	echo Permission for the file $flname is,
	ls -l $flname
	
	((tempsize = $(stat -c %a rand.sh)))

	fdigit="${tempsize:0:1}"


	sdigit="${tempsize:1:1}"

	tdigit="${tempsize:2:1}"

	if [ -x "$flname" ]; then
		((fdigit--))
	else
		((fdigit++))
	fi
	
	if [ -w "$flname" ]; then
		((temp=fdigit-2))
		((fdigit=temp))
	else
		((temp=fdigit+2))
		((fdigit=temp))
	fi

	if [ -r "$flname" ]; then
		((temp=fdigit-4))
		((fdigit=temp))
	else
		((temp=fdigit+4))
		((fdigit=temp))
	fi

	((temp = 7-sdigit))
	((sdigit = temp))
	
	((temp = 7-tdigit))
	((tdigit = temp))
	
	((temp=fdigit*100))
	((fdigit=temp))
	
	((temp=sdigit*10))
	((sdigit=temp))
	
	((newnum = fdigit + sdigit + tdigit))
	echo Permissions after inversing are, 
	chmod $newnum $flname

	ls -l $flname
    	;;

	2)
	echo Enter your file name. Please make sure that the file already exists in the current directory
	read flname
	
	echo Enter your string
	read strng
	
	
	if grep -R "$strng" $flname
	then
	    echo It exists
	else
	    echo doesnt exist
	fi

	;;

	3)

	echo Enter the value of n
	read n
	
	touch dummy.txt
	echo dummy.txt created successfully and data has been moved
	
	;;
	
	4)
	echo Enter your file name. Please make sure that the file already exists in the current directory
	read flname
	
	if [ $(find /path -mtime -1 -type f -name $flname 2>/dev/null) ];then
		echo File was last modified within 24 hours
	else
		echo File was last modified before 24 hours
		touch -d "2 hours ago" $flname
		echo New modified time has been updated
	fi
	;;
	
	exit)
	echo -n "exit"
	;;

	*)
	echo -n "error"
	;;
	esac
	
	
	