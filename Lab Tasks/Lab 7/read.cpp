# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <iostream>
using namespace std;
int main () {

	char str [256];
	int fifo_rw2;
	
		while (strcmp (str, "abort") != 0) {
			
			fifo_rw2 = open("pipe_one", O_RDONLY);
			read(fifo_rw2, str, sizeof(str));
			cout << "Process 1: Output Text: " << str << endl;
			close (fifo_rw2);
			fifo_rw2 = open("pipe_one", O_WRONLY);
			cout << "Process 2: Input text: ";
			cin >> str;
			write(fifo_rw2, str, sizeof(str));
			close (fifo_rw2);
		}
		close (fifo_rw2);
		
	return 0;
}
