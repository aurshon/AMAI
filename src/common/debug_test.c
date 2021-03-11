/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月11日
*   描    述：
*
================================================================*/


#include "../../include/common/debug.h"
#include <stdio.h>
int main(int argc, char* argv[])
{
    for(int i = 0; i<5000;i++){
        for(int a=0; a<10;a++){
            Xpinfo("I的值是:%d", i);
        }
        for(int b=0; b<10;b++){
            Xpdebug("正在调试:%d", i);
        }
        for(int c=0; c<10;c++){
            Xperror("出错啦:%d", i);
        }
        for(int d=0; d<10;d++){
            Xpwarn("我只是个警告:%d", i);
        }
    }
    return 0;
}
