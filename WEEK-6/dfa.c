#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX 100
int isValid(int x,int *inputArray,int len){
    int flag=0;
    for(int i=0;i<len;i++){
        if(x==inputArray[i]){
            flag=1;
            break;
        }
    }
    return flag;
}
int isInFinalState(int * finalStates,int noOfFinalStates,int currState){
    int flag=0;
    for(int i=0;i<noOfFinalStates;i++){
        if(currState==finalStates[i]){
            flag=1;
            break;
        }
    }
    return flag;
}
int main(){
    int noOfStates;
    printf("Enter the no of states:");
    scanf("%d",&noOfStates);

    int nofInputs;
    printf("Enter the number of inuput elemnts you are going to enter:");
    scanf("%d",&nofInputs);

    int inputArray[nofInputs];
    for(int i=0;i<nofInputs;i++){
        printf("Enter the %d element:",i+1);
        scanf("%d",&inputArray[i]);
    }
    int noOfFinalStates;
    printf("enter the no of final states:");
    scanf("%d",&noOfFinalStates);

    int finalStates[noOfFinalStates];
    for(int i=0;i<noOfFinalStates;i++){
        printf("Enter the %d th state:",i+1);
        scanf("%d",&finalStates[i]);
    }

    int inputSize;
    printf("Enter your size of Input:");
    scanf("%d",&inputSize);
    
    int inputString[inputSize];
    printf("Remeber what you are going to enter should be from ur input else it's going to be error!\n");
    for(int i=0;i<inputSize;i++){
        printf("enter your %d INPUT:",i+1);
        scanf("%d",&inputString[i]);
        if(isValid(inputString[i],inputArray,nofInputs)==0){
            printf("INVALID INOUT");
            exit(0);
        }
    }
    int adjMatrix[MAX][MAX];
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adjMatrix[i][j]=-1;
        }
    }
    printf("Enter -1 when there is not transition!! for the DFA\nLET'S CONSTRUCT OUR DFA!\n");
    for(int i=0;i<noOfStates;i++){
        for(int j=0;j<nofInputs;j++){
            printf("FROM %d ON INPUT %d TO:",i,inputArray[j]);
            int temp;
            scanf("%d",&temp);
            adjMatrix[i][inputArray[j]]=temp;
        }
    }
    printf("Processsing......\n");
    int currState=0;
    for(int i=0;i<inputSize;i++){
        currState=adjMatrix[currState][inputString[i]];
        if(currState==-1){
            printf("Reached invalid state");
        }
    }
    if(isInFinalState(finalStates,noOfFinalStates,currState)){
        printf("Reached final state!!!\nDFA recognises given string!!");
    }
    else{
        printf("The current states in not in fial state.\n Henc not recognised by the constructed DFA");
    }
}