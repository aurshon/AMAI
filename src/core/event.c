/*================================================================
*   2021 (Aurshon). All rights reserved.
*   
*   文件名称：event.c
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月10日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <string.h>
#include "../../include/common/xy_types.h"
#include "../../include/common/debug.h"
#include "../../include/core/pub.h"


//所有事件列表
Match_xy Entry[] = 
{
    {EVENT1,EventHandingFunc1},
    {EVENT2,EventHandingFunc2}
};

I32_xy EventHandingFunc1(Content_xy)
{
    Xpinfo("自己实现业务EventHandingFunc1:[1]");
}

I32_xy EventHandingFunc2(Content_xy)
{
    Xpinfo("自己实现业务EventHandingFunc2:[2]");
}
 
