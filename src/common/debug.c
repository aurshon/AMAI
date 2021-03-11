/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：debug.c
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月11日
*   描    述：
*
================================================================*/


#include "../../include/common/debug.h"
#include <stdio.h>
#include <syslog.h>  
/*暂时用宏打印，将来需要远程日志同步可以完善下面代码
int Xprintf(C8_xy *s, fmt..)
{
    openlog();
    syslog();
    closelog();
    return 0;
}
*/
