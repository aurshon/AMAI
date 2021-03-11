/*================================================================
*   2021 (Aurshon). All rights reserved.
*   
*   文件名称：pub.c
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月10日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <string.h>

#define CMDSIZE 100
typedef int (*ptrFun)(int num);
typedef struct Command_t
{
    const char *cmd;    //出发事件的条件，或信令
    ptrFun func;        //事件处理函数
}Command;
 
int test1(int num)
{
    printf("test1,%d\n",num);
}//事件1处理函数
int test2(int num)
{
    printf("test2,%d\n",num);
}//事件2处理函数
 
Command Entry[] = 
{
    {"Event1",test1},
    {"Event2",test2}
}; //所有事件列表
 
int main(int argc, char* argv[])
{
/*
Event1为事件的触发条件，这里只是简单的用变量赋值，在项目中这个值可以根据实际需要来获取值，比如在socket通信中，客户端发来消息，服务
端接收消息，并解析来得到该信令的值，然后用该值在事件集合中匹配，并执行对应的事件。
例如：
            如下结构体是我们定义的项目中用来接收信令(可以理解为事件的出发条件)的结构体，cmd是信令，parm1,parm2为接收的参数。这两个参数可
            以作为事件函数的入参。这时候事件函数的指针应该定义为：typedef int (*ptrFun)(void *parm1,void *parm2);
            typedef struct CMD_T
            {
                const char* cmd;
                void *parm1;
                void *parm2;
            }CMD;
            CMD client_cmd;
            到时候在事件集合中的代码我们可以这样实现：
             if(strcmp(client_cmd.cmd,Entry[i].cmd) == 0)
            {
                Entry[i].func(parm1,parm2);
            }
    */
    int i = 0;
    const char *parm = "Event1";

    printf("%ld,%ld\n",sizeof(Entry)/sizeof(Entry[0]),sizeof(Entry));
    for(i;i<sizeof(Entry)/sizeof(Command);i++)
    {
        if(strcmp(parm,Entry[i].cmd) == 0)
        {
            Entry[i].func(i);
            break;  //为了提高检索速度
        }
    }
    return 0;
}
