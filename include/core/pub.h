/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：pub.h
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月10日
*   描    述：
*
================================================================*/


#ifndef __PUB__H__
#define __PUB__H__
#include "../common/xy_types.h"


//自定义模块之间的协议
typedef struct X{
    Uc8_xy head;     //head为0x2A
    Uc8_xy from;
    Uc8_xy to;
    Uc8_xy cmd;
}__attribute__((packed))Content_xy;

//模块与center的协议
typedef struct Aurshon{                             
    Uc8_xy head;     //head为0x1A                            
    Uc8_xy from;                                    
    Uc8_xy to;   //to的值和EventCmd_xy里的值匹配                                  
    Content_xy data;                                  
}__attribute__((packed))Aurshon_protocol;           
                                                    

//用来处理事件的匹配信令
typedef enum
{
    EVENT1 = 0x01, //和to匹配
    EVENT2 = 0x02,
}EventCmd_xy;


typedef I32_xy (*PtrEventHanding_xy)(Content_xy);

typedef struct Match                                
{                                                   
    I32_xy cmd;                                     
    PtrEventHanding_xy func;        //事件处理函数  
}Match_xy;                                          

//事件处理函数1
I32_xy EventHandingFunc1(Content_xy);

//事件处理函数2
I32_xy EventHandingFunc2(Content_xy);

#endif //__PUB__H__
