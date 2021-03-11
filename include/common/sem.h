/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：sem.h
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月11日
*   描    述：
*
================================================================*/


#ifndef __SEM__H__
#define __SEM__H__
union semun { 
    int              val;    /* Value for SETVAL */
    //struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    //unsigned short  *array;  /* Array for GETALL, SETALL */
    //struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */ 
};

#endif //__SEM__H__
