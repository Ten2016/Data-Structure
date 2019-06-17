#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXKLEN 20 
#define CNUM 128

typedef struct{
    int  cnt;
    double p; 
    double sump;
    double logp;
    int  enl;
    char enc[MAXKLEN];
}Shannon;

//Vir
Shannon shn[CNUM];
int shni[CNUM];
int sum=0;
int cnt=0;

//Func
void Init(FILE *fp);     //return: char sum
void Print(void);       //print shn
void QuickSort(int l,int h);
void Complete(void);
void Encode(void);
void Save(FILE *fp,FILE *fs);

int main(){
    FILE *fp,*fs;
    int i;
    fp=fopen("test.txt","r");
    if(fp==NULL){
        perror("fp open error");
        exit(1);
    }
    for(i=0;i<CNUM;++i){
        shni[i]=i;
        shn[i].cnt=0;
    }
    Init(fp);
    

    QuickSort(0,CNUM);
    Complete();
    printf("char sum: %d\n",sum);
    printf("char cnt: %d\n\n",cnt);
    Encode();
    Print();
    rewind(fp);
    fs=fopen("save.txt","w");
    if(fs==NULL){
        perror("fs open error");
        exit(1);
    }
    Save(fp,fs);

    //Decode();
    //Compare();
    fclose(fp);
    fclose(fs);
    return 0;
}



void Init(FILE *fp){
    int c;
	while(!feof(fp)){
        c=fgetc(fp);
        shn[c].cnt++;
        sum++;
    }
}
void QuickSort(int l,int h){
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
        QuickSort(l,a-1);
        QuickSort(a+1,h);
    }
}
void Complete(void){
    double sump=0;
    int i,j=0;
    for(;j<CNUM;j++){
        i=shni[j];
        if(shn[i].cnt==0){
            cnt=i;
            break;
        }
        shn[i].p=shn[i].cnt*1.0/sum;
        shn[i].sump=sump;
        sump+=shn[i].p;
        shn[i].logp=(-1*(log(shn[i].p)/log(2)));
        shn[i].enl=ceil(shn[i].logp);
	}
}
void Encode(void){
    int i,j;
    double t;
    for(i=0;i<CNUM;i++){
        if(shn[i].cnt==0)
            continue;
    	t=shn[i].sump;
    	for(j=0;j<shn[i].enl;j++){
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
void Print(void){
    printf("c\tcnt\tp\t\t\tsump\t\t\t-logp\t\t\tkl\tk\n\n");
    int i,j=0;
    while(j<cnt){
        i=shni[j];
    	printf("%c\t%d\t%.6f\t\t%.6f\t\t%.6f\t\t%2d\t%s\n",i,shn[i].cnt,
                    shn[i].p,shn[i].sump,shn[i].logp,shn[i].enl,shn[i].enc);
        j++;
    }
}

void Save(FILE *fp,FILE *fs){
    int c;
    while(!feof(fp)){
        c=fgetc(fp);
        fwrite(shn[c].enc,1,shn[c].enl,fs);
    }
}
