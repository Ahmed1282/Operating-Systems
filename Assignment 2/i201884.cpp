//Ahmed Baig
//20i-1884
//Assignment 2

#include<iostream>
using namespace std;

void findWaitingTime(int num, int bt[], int wt[], int at[])
{
	int temp[num];
	temp[0] = at[0];
	wt[0] = 0;

	for (int i = 1; i<num; i++){
		temp[i] = bt[i-1] + temp[i-1];
		wt[i] = temp[i] - at[i];
        if (wt[i] < 0){
			wt[i] = 0;
        }
	}
}

void findTurnAroundTime(int num, int bt[],int wt[], int tat[])
{
	for (int i = 0; i<num; i++){
		tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int num, int bt[], int at[])
{
	int wt[num];
    int tat[num];
	findWaitingTime(num, bt, wt, at);
	findTurnAroundTime(num, bt, wt, tat);

	cout <<"Processes\t" << "Burst Time\t"<< "Arrival Time\t"<< "Waiting Time\t" << "Turn-Around Time\t"<< "Completion Time \n";
	int twt = 0, ttat = 0;
	for (int i = 0 ; i < num ; i++)
	{
		twt += wt[i];
		ttat += tat[i];
		int ct = 0;
        ct = tat[i] + at[i];
		cout << i+1 << "        \t" << bt[i] << "         \t" << at[i] << "           \t" << wt[i] << "           \t" << tat[i] << "               \t" << ct << endl;
	}

    double avgwt = twt / (double)num;
    double avgtat = ttat / (double)num;
	cout << "\nAverage waiting time = " << avgwt<<endl;
	cout << "\nAverage turn around time = " << avgtat;
}

void SJF(int processes[], int num, int bt[], int at[], int temp[])
{
    int i, min, count = 0, time;
    double wt = 0, tat = 0, end;
    float avgwt, avgtat;
    bt[9] = 9999;
    cout<<endl;
    cout<<"Process:   ";
    for(int i=0; i<num; i++){
        cout<<"\t"<<processes[i];
    }
    cout<<endl;
    cout<<"Arrival Time: ";
    for(int i=0; i<num; i++){
        cout<<"\t"<<at[i];
    }
    cout<<endl; 
    cout<<"Burst Time: ";
    for(int i=0; i<num; i++){
        cout<<"\t"<<bt[i];
    }
    cout<<endl;
    cout<<"Waiting Time:";   
    for(time = 0; count != num; time++){
          min = 9;
          for(i = 0; i < num; i++){
                if(at[i] <= time && bt[i] < bt[min] && bt[i] > 0){
                      min = i;
                }
          }
          bt[min]--;
          if(bt[min] == 0){
                count++;
                end = time + 1;
                wt = wt + end - at[min] - temp[min];
                tat = tat + end - at[min];
                cout<<"\t"<<wt;
          }
    }
    avgwt = wt / num; 
    avgtat = tat / num;
    cout<<endl;
    cout << "\nAverage waiting time = " << avgwt<<endl;
	cout << "\nAverage turn around time = " << avgtat;
}

int main()
{
    int num;

    cout<<"Enter the number of Processes: ";
    cin>>num;

	int process[num];
    int bt[10];
    int at[10]; 
    int temp[10];

    for(int i=0; i<num; i++){
        process[i] = i+1;
    }

    cout<<endl;
    for(int i=0; i<num; i++){
        cout<<"Enter Arrival time of Process "<<i+1<<" : ";
        cin>>at[i];    
    }

    cout<<endl;
    for(int i=0; i<num; i++){
        cout<<"Enter Burst time of Process "<<i+1<<" : ";
        cin>>bt[i];
        temp[i] = bt[i];    
    }
    
    int sch;
    cout<<"\nScheduling you want to perform: "<<endl;
    cout<<"1.FCFS"<<endl;
    cout<<"2.SJF"<<endl;
    cin>>sch;

    if(sch == 1)
    {
        cout<<endl;
	    findavgTime(process, num, bt, at);
    }
    else if(sch == 2)
    {
        SJF(process, num, bt, at, temp);
    }
    else
    {
        cout<<"Wrong Input";
    }

	return 0;
}
