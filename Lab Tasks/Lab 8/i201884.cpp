#include <iostream>
using namespace std;


void Queue_Update(int queue[],int timer,int arrival_time[],int num, int max_Proccess_Index){
	int firstindex;
	for(int i = 0; i < num; i++){
		if(queue[i] == 0){
			firstindex = i;
			break;
		}
	}
	queue[firstindex] = max_Proccess_Index + 1;
}



void Queue_Maintain(int queue[], int num){
	for(int i = 0; (i < num-1) && (queue[i+1] != 0) ; i++){
		int temp = queue[i];
		queue[i] = queue[i+1];
		queue[i+1] = temp;
	}
}



void New_Arrival_Time(int timer, int arrival_time[], int num, int max_Proccess_Index,int queue[]){
	if(timer <= arrival_time[num-1]){
	bool new_Arrival = false;
	for(int j = (max_Proccess_Index+1); j < num; j++){
			if(arrival_time[j] <= timer){
			if(max_Proccess_Index < j){
				max_Proccess_Index = j;
				new_Arrival = true;
			}
		}
	}
	if(new_Arrival)
		Queue_Update(queue,timer,arrival_time,num, max_Proccess_Index);
	}
}



int main()
{
	int num,time_quantum, timer = 0, max_Proccess_Index = 0;
	float avg_wait = 0, avg_TurnAroundTime = 0;
	cout << "Enter the time quantum : ";
	cin>>time_quantum;
	cout << "Enter the number of processes : ";
	cin>>num;
	int arrival_time[num], burst_time[num], wait_time[num], turnaround_time[num], queue[num], temp_burst[num];
	bool complete_time[num];

	cout<<endl;
	for(int i = 0; i < num; i++){
		cout << "Enter the arrival time of the process "<<i+1<<" : ";
		cin>>arrival_time[i];
	}
	cout<<endl;
	for(int i = 0; i < num; i++){
		cout << "Enter the burst time of the process "<<i+1<<" : ";
		cin>>burst_time[i];
		temp_burst[i] = burst_time[i];
	}

	for(int i = 0; i < num; i++){ 
		complete_time[i] = false;
		queue[i] = 0;
	}
	while(timer < arrival_time[0]) 
		timer++;
	queue[0] = 1;
	
	while(true){
		bool check = true;
		for(int i = 0; i < num; i++){
			if(temp_burst[i] != 0){
				check = false;
				break;
			}
		}
		if(check)
			break;

		for(int i = 0; (i < num) && (queue[i] != 0); i++){
			int count = 0;
			while((count < time_quantum) && (temp_burst[queue[0]-1] > 0)){
				temp_burst[queue[0]-1] -= 1;
				timer += 1;
				count++;
				New_Arrival_Time(timer, arrival_time, num, max_Proccess_Index, queue);
			}
			if((temp_burst[queue[0]-1] == 0) && (complete_time[queue[0]-1] == false)){
				turnaround_time[queue[0]-1] = timer;	
				complete_time[queue[0]-1] = true;
			}
			bool flag = true;
			if(queue[num-1] == 0){
				for(int i = 0; i < num && queue[i] != 0; i++){
					if(complete_time[queue[i]-1] == false){
						flag = false;
					}
				}
			}
			else
				flag = false;

			if(flag){
				timer++;
				New_Arrival_Time(timer, arrival_time, num, max_Proccess_Index, queue);
			}
			Queue_Maintain(queue,num);
		}
	}

	for(int i = 0; i < num; i++){
		turnaround_time[i] = turnaround_time[i] - arrival_time[i];
		wait_time[i] = turnaround_time[i] - burst_time[i];
	}
	cout<<endl;
	cout << "Program No.		Arrival Time		Burst Time		Wait Time		TurnAround Time"
		<< endl;
	for(int i = 0; i < num; i++){
		cout<<i+1<<"		"<<arrival_time[i]<<"		"<<burst_time[i]<<"		"<<wait_time[i]<<"		"<<turnaround_time[i]<<endl;
	}
	for(int i =0; i< num; i++){
		avg_wait += wait_time[i];
		avg_TurnAroundTime += turnaround_time[i];
	}
	cout<<endl;
	cout<<"Average wait_time time : "<<(avg_wait/num)<<endl;
	cout<<"Average Turn Around Time : "<<(avg_TurnAroundTime/num);

	return 0;
	
}
