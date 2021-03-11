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

/*
 *维护一个接收消息的双向链表，有消息就把消息加入链表，然后逐个去匹配相应的处理函数
 */


