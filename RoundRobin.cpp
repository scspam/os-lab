#include<iostream>
using namespace std;

int main(){
    int p_count;
    cout<<"Enter Total number of processes"<<endl;
    cin>>p_count;
    int y=p_count;
    int i,bt[20],at[20],temp[20];
    for(i=0;i<p_count;i++){
        cout<<"Enter burst time of processor : "<<i+1<<endl;
        cin>>bt[i];
        temp[i]=bt[i];
        cout<<"Enter arrival time of processor : "<<i+1<<endl;
        cin>>at[i];
    }
    int quant;
    cout<<"Enter Time Quantum"<<endl;
    cin>>quant;
    cout<<"\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time\n"; 
    int count,sum,tat[20],wt[20],avg_wt=0,avg_tat=0;
    for(i = 0,sum=0;y!=0; )  
    {
        if(temp[i] <= quant && temp[i] > 0)   
        {  
            sum = sum + temp[i];  
            temp[i] = 0;  
            count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  

        if(temp[i]==0 && count==1)  
        {  
            y--;  
            cout<<"Process No["<<i+1<<"] \t\t "<<bt[i]<<"\t\t\t\t"<<sum-at[i]<<"\t\t\t"<<sum-at[i]-bt[i]<<endl;  
            wt[i] = sum-at[i]-bt[i];  
            tat[i] = sum-at[i];  
            count =0;     
        } 

        if(i==p_count-1)  
        {
            i=0;  
        } 
        else if(at[i+1]<=sum)  
        {
            i++;  
        }
        else
        {
            i=0;  
        }
    }

    for(i=0;i<p_count;i++){
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= p_count;
    avg_tat /= p_count;

    cout<<"\n Average Turn Around Time: \t"<<avg_wt<<endl;  
    cout<<"\n Average Waiting Time: \t"<<avg_tat<<endl; 
}  
