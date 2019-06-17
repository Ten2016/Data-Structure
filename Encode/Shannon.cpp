#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAXKLEN 15 
#define CNUM 26 

typedef struct{
    char c;
    int cnt;
    float p; 
    float sump;
    float logp;
    int enl;
    char enc[MAXKLEN];
}Shn;

void QuickSort(Shn *shn,int *shni,int l,int h);
int Init1(Shn *shn,int *shni);
void Init2(Shn *shn,int *shni,int sum);
void Encode(Shn *shn);

int main(){
    Shn shn[CNUM];
    int shni[CNUM];
    int sum;
    sum=Init1(shn,shni);
    QuickSort(shn,shni,0,25);
    Init2(shn,shni,sum);
    //Encode
    Encode(shn);
    //print
    printf("sum:%d\n\n",sum);
    printf("c\tcnt\tp\t\tsump\t\t-logp\t\ttkl\tk\n\n");
    for(int j=0;j<CNUM;j++){
        int i=shni[j];
    	printf("%c\t%d\t%.3f\t\t%.3f\t\t%.3f\t\t%d\t%s\n",shn[i].c,shn[i].cnt,
                    shn[i].p,shn[i].sump,shn[i].logp,shn[i].enl,shn[i].enc);
    }
    return 0;
}


void QuickSort(Shn *shn,int *shni,int l,int h){
    if(l<h){
        int a=l,b=h;                //  
        int tmp=shn[shni[a]].cnt;   //selset the first num
        int tmpi=shni[a];
        while(a<b){
            while(a<b && shn[shni[b]].cnt<=tmp)  b--;
            shni[a]=shni[b];
            while(a<b && shn[shni[a]].cnt>=tmp)  a++;
            shni[b]=shni[a];
        }
        shni[a]=tmpi;
        //partation end
        QuickSort(shn,shni,l,a-1);
        QuickSort(shn,shni,a+1,h);
    }
}
int Init1(Shn *shn,int *shni){
    srand((unsigned)time(NULL));
    int sum=0;
    for(int i=0;i<CNUM;i++){
        shni[i]=i;
        shn[i].c=i+97;
        shn[i].cnt=rand()%97;
        sum+=shn[i].cnt;
    }
    return sum;
}
void Init2(Shn *shn,int *shni,int sum){
    float sump=0;
    for(int j=0;j<CNUM;j++){
        int i=shni[j];
        shn[i].p=shn[i].cnt*1.0/sum;
        shn[i].sump=sump;
        sump+=shn[i].p;
        if(shn[i].p>1e-5)
            shn[i].logp=(-1*(log(shn[i].p)/log(2)));
        else
            shn[i].logp=0;
        shn[i].enl=int(shn[i].logp+0.999);
	}
}

void Encode(Shn *shn){
    for(int i=0;i<CNUM;i++){
    	float t=shn[i].sump;
    	for(int j=0;j<shn[i].enl;j++){
    		t*=2;
    		if(t>=1){
    			shn[i].enc[j]='1';
    			t-=1;
				}
				else
					shn[i].enc[j]='0';	
			}
      shn[i].enc[shn[i].enl]='\0';
    }
}
