/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：debug.h
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月11日
*   描    述：
*
================================================================*/


#ifndef __DEBUG__H__
#define __DEBUG__H__
#include <stdio.h>

#define Xpinfo(fmt, args...) do{\
                                printf("\033[;32m[%s:%d]\033[0m \033[;35mINFO\033[0m \033[;m"#fmt"\033[0m\r\n", __func__, __LINE__, ##args);    \
                                }while(0)
#define Xperror(fmt, args...) do{\
                                printf("\033[;32m[%s:%d]\033[0m \033[;35mERROR\033[0m \033[;31m"#fmt"\033[0m\r\n", __func__, __LINE__, ##args);    \
                                }while(0)
#define Xpwarn(fmt, args...) do{\
                                printf("\033[;32m[%s:%d]\033[0m \033[;35mWARN\033[0m \033[;33m"#fmt"\033[0m\r\n", __func__, __LINE__, ##args);    \
                                }while(0)
#define Xpdebug(fmt, args...) do{\
                                printf("\033[;32m[%s:%d]\033[0m \033[;35mDEBUG\033[0m \033[;m"#fmt"\033[0m\r\n", __func__, __LINE__, ##args);    \
                                }while(0)

#endif //__DEBUG__H__
