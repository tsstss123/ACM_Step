//不用任何括号的HelloWorld
/*
#include <bits/stdc++.h>
char code[] = 

    "\xe9\x1e\x00\x00\x00"  //          jmp    8048083 <MESSAGE>
    "\xb8\x04\x00\x00\x00"  //          mov    $0x4,%eax
    "\xbb\x01\x00\x00\x00"  //          mov    $0x1,%ebx
    "\x59"                  //          pop    %ecx
    "\xba\x0f\x00\x00\x00"  //          mov    $0xf,%edx
    "\xcd\x80"              //          int    $0x80
    "\xb8\x01\x00\x00\x00"  //          mov    $0x1,%eax
    "\xbb\x00\x00\x00\x00"  //          mov    $0x0,%ebx
    "\xcd\x80"              //          int    $0x80
    "\xe8\xdd\xff\xff\xff"  //          call   8048065 <GOBACK>
    "Hello wolrd!\r\n";     // OR       "\x48\x65\x6c\x6c\x6f\x2c\x20\x57"
                            //          "\x6f\x72\x6c\x64\x21\x0d\x0a"

int main(int argc, char **argv)
{
    for(int i=0;code[i]!='\n';++i)printf("main%d=0x%02X,",i,(unsigned char)code[i]);

    return 0;
}
*/

const char main=0xeb;
const char main1=0x19,main2=0x31,main3=0xc0,main4=0x31,main5=0xdb,main6=0x31,main7=0xc9,main8=0x31,main9=0xd2,main10=0xb0,
main11=0x04,main12=0xb2,main13=0x0e,main14=0x59,main15=0xb3,main16=0x01,main17=0xcd,main18=0x80,main19=0x31,main20=0xc0,
main21=0xb0,main22=0x01,main23=0x31,main24=0xdb,main25=0xcd,main26=0x80,main27=0xe8,main28=0xe2,main29=0xff,main30=0xff,
main31=0xff,main32=0x48,main33=0x65,main34=0x6c,main35=0x6c,main36=0x6f,main37=0x2c,main38=0x20,main39=0x57,main40=0x6f,
main41=0x72,main42=0x6c,main43=0x64,main44=0x21,main45=0x0a;

//本机RE交上去AC，不是很懂你们凝聚
//https://oj.cnssuestc.org/record.html#e1da9de520bc4890bfcd44a7a0ea9d55
