//
// Created by Cristiano on 2022/6/21.
//
#include <iostream>
#ifndef RISC_V_SIMULATOR_UTILITY_HPP
#define RISC_V_SIMULATOR_UTILITY_HPP
namespace Cristiano{
    std::string reverse(const std::string &str){
        int l=str.length();
        char ans[l+1];
        for(int i=l-1;i>=0;i--)ans[l-1-i]=str[i];
        ans[l]='\0';
        return( std::string )(ans);
    }
    int btoi(const std::string str){
        int l=str.length();int ans=0;
        for(int i=0;i<l;i++){
            ans=ans*2+str[i]-'0';
        }
        return ans;
    }
    int xtoi(const std::string str){
        int l=str.length();int ans=0;
        for(int i=0;i<l;i++){
            char i1=str[i];int in1=0;
            if (i1 >= 'A' && i1 <= 'F')in1 = i1 - 'A' + 10;
            else in1 = i1 - '0';
            ans=ans*16+in1;
        }
        return ans;
    }

    inline unsigned int sext(const unsigned int &x, const int &r){
        bool c=((unsigned)1<<r)&x;
        if(!c)return x;
        return x|((-1)<<(r+1));
    }
    int fix(int x,int h){
        if ((x >> h) & 1) {
            for (int j = h + 1; j < 32; j++) {
                x += 1 << j;
            }
        }
        return x;
    }
    std::string decToBin(unsigned int u){
        std::string str;
        while(u>0){
            int a=u&1;u=u>>1;char ch='0';
            if(a)ch='0'+a;
            str=ch+str;
        }
        int l=str.length();
        for(int i=0;i<32-l;i++)str='0'+str;
        return str;
    }
    std::string decToHex(int u){
        std::string str;
        while(u>0){
            int a=u%16;u=u/16;char ch;
            if (a >= 10 && a <= 15)ch = a - 10  +'A';
            else ch ='0'+a;
            str=ch+str;
        }
        return reverse(str);
    }
    inline unsigned int ask(const unsigned int &x,const int &l,const int &r){
        return (x&( ((-1)>>(31-r+l))<<l ))>>l;
    }
     int hexStringToDec(std::string str){
        int ret = 0;
        for (int i = 0; i < str.length(); ++i) ret = (ret << 4) + ((str[i]>='A'&&str[i]<='F') ? (str[i] - 'A' + 10) : (str[i] - '0'));
        return ret;
    }
//    int*& toIntArray(const std::string str){
//        int l=str.length();int* ans=new int[32];
//        for(int i=0;i<l;i++){
 //           ans[i]=str[l-1-i];
 //       }
 //       return ans;
//    }
}
#endif //RISC_V_SIMULATOR_UTILITY_HPP
