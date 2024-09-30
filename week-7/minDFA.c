#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_STATES 100
#define MAX_INPUT 20

int transition[MAX_STATES][MAX_INPUT];
bool isFinalState[MAX_STATES];
bool marked[MAX_STATES][MAX_STATES];
int finalState[MAX_STATES];
int inputSymbols[MAX_INPUT];
int noOfState,noOfInput,noOfFinalState;

void initialSetUp(){
    for(int i=0;i<MAX_STATES;i++){
        for(int j=0;j<noOfInput;j++){
            transition[i][j]=-1;
        }
        isFinalState[i]=false;
    }
}
void displayInitialDFA(){
    printf("TRANSITION TABLE:\n");
    printf("STATES ");
    for(int i=0;i<noOfInput;i++){
        printf("%d ",inputSymbols[i]);
    }
    printf("\n");
    for(int i=0;i<noOfState;i++){
        printf("%d      ",i);
        for(int j=0;j<noOfInput;j++){
            if(transition[i][j]!=-1){
                printf("%d ",transition[i][j]);
            }
            else{
                printf(". ");
            }
        }
        printf("\n");
    }
}
void markFinalState(){
    for(int i=0;i<noOfFinalState;i++){
        isFinalState[finalState[i]]=true;
    }
}
void markUndistinguishable(){
    for(int i=0;i<noOfState;i++){
        for(int j=0;j<noOfFinalState;j++){
            if(finalState[i]!=finalState[j]){
                marked[i][j]=marked[j][i]=true;//cannot be merged by DFA!!(final and non-final state!!)
            }
        }
    }
}
void minimiseDFA(){
    markUndistinguishable();
    printf("Executing table filling algorithm...............\n");
    bool change=true;
    while(change){
        change=false;
        for(int i=0;i<noOfState;i++){
            for(int j=0;j<noOfState;j++){
                if(!marked[i][j]){
                    for(int k=0;k<noOfInput;k++){
                        int t1=transition[i][k];
                        int t2=transition[j][k];
                        if((t1!=-1 && t2!=-1 && marked[t1][t2])||(t1==-1 && t2!=-1)||(t2==-1 && t1!=-1)){
                            marked[i][j]=marked[j][i]=true;
                            change=true;
                            break;
                        }
                    }
                }
            }
        }
    }
}
void displayMinimisedDFA(){
    printf("Minimised DFA after completeing table filling algorithm!!\n");
    printf("STATES ");
    for(int i=0;i<noOfInput;i++){
        printf("%d ",inputSymbols[i]);
    }
    printf("\n");
    for(int i=0;i<noOfState;i++){
        bool unique=true;
        for(int j=0;j<i;j++){
            if(!marked[i][j]){
                unique=false;
                break;
            }
        }
        if(unique){
            printf("%d      ",i);
            for(int k=0;k<noOfInput;k++){
                if(transition[i][k]!=-1){
                    printf("%d ",transition[i][k]);
                }
                else{
                    printf(". ");
                }
            }
            printf("\n");
        }
    }
}
int main(){
    initialSetUp();
    printf("Enter no of states:");
    scanf("%d",&noOfState);
    printf("Enter the no of inputs:");
    scanf("%d",&noOfInput);
    printf("Enter input symbols:\n");

    for(int i=0;i<noOfInput;i++){
        printf("%d input element:",i+1);
        scanf("%d",&inputSymbols[i]);
    }
    /*for(int i=0;i<noOfInput;i++){
        printf("%d\n",inputSymbols[i]);
    }*/
   printf("NOTE:Mark transition -1 if theres is no tansition\n");
   printf("Build transition table:\n");
   for(int i=0;i<noOfState;i++){
    for(int j=0;j<noOfInput;j++){
        printf("From %d On %d To:",i,inputSymbols[j]);
        scanf("%d",&transition[i][j]);
    }
   }

   printf("Enter the no of final state:");
   scanf("%d",&noOfFinalState);

   printf("Enter the final state:\n");
   for(int i=0;i<noOfFinalState;i++){
    printf("%d final state:",i+1);
    scanf("%d",&finalState[i]);
   }
   /*for(int i=0;i<noOfFinalState;i++){
    printf("%d\n",finalState[i]);
   }*/
  displayInitialDFA();
  markFinalState();
  minimiseDFA();
  displayMinimisedDFA();

}