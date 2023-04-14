# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <iostream>

using namespace std;

int main () {

	char str [256] ;
	int fifo_rw1;
		
		while (strcmp (str, "abort") != 0) {
			fifo_rw1 = open ("pipe_one", O_WRONLY);
			cout << "Process 1: Input text: ";
			cin >> str;
			write(fifo_rw1, str, sizeof(str));
			close (fifo_rw1);
			fifo_rw1 = open ("pipe_one", O_RDONLY);
			read (fifo_rw1, str, sizeof(str));
			cout << "Process 2: Output Text: " << str << endl;
			close (fifo_rw1);
		}
		close (fifo_rw1);
	
	
	return 0;
}
