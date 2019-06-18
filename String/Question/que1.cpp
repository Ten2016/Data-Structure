#include <iostream>

/*
描述:
    删除字符串str中所有值为c的字符
    返回该字符串
 */

void Delete(char *str,char c){
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=c)
            str[j++]=str[i];
    }
    str[j]='\0';
}

int main(){
    char str[]="afdfgtdsfssffe";
    char c='f';
    std::cout<<str<<std::endl<<c<<std::endl;
    Delete(str,c);
    std::cout<<str<<std::endl;
    return 0;
}
