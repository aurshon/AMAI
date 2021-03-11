/*================================================================
*   Copyright (C) 2021 Xag(XY) Ltd. All rights reserved.
*   
*   文件名称：sem.c
*   创 建 者：Aurshon(XY)
*   创建日期：2021年03月11日
*   描    述：
*
================================================================*/

#include <sys/types.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "../../include/common/xy_types.h"
#include "../../include/common/debug.h"
#include "../../include/common/sem.h"

/*****************************
 *创建信号量
 *****************************/
I32_xy Xsemget(key_t key)
{
    I32_xy semId = semget(key, 1, 0666|IPC_CREAT);
    if(-1 == semId){
        Xpwarn(获取信号量失败semget函数返回值为:%d,semId);
    } 
    return semId;
}

/***************************
 *初始化信号量
 ***************************/
I32_xy Xseminit(I32_xy semId)
{
    semun semunion;
    semunion.val = 1;
    if (-1 == semctl(semId, 0, SETVAL, semunion))
    {
        perror("初始化信号量失败\n");
    }
    return 0;
}


/***************************
 *删除信号量
 ***************************/
Vd_xy Xsemdel(I32_xy semId)
{
    if (-1 == semctl(semId, 0, IPC_RMID, NULL))
    {
        perror("删除信号量失败\n");
    }
}

/***************************
 *P操作（访问临界区之前使用）
 *对信号量做-1操作
 ***************************/
I32_xy XsemP(I32_xy semId)
{
    I32_xy ret;
    struct sembuf semb;
    semb.sem_num = 0;
    semb.sem_op = -1;
    semb.sem_flg = SEM_UNDO;
    ret = semop(semId, &semb, 1);
    if (-1 == ret)
    {
        perror("信号量P操作失败\n");
    }
    return ret;
}

/***************************
 *V操作（离开临界区之后使用）
 *对信号量做+1操作
 ***************************/
I32_xy XsemV(I32_xy semId)
{
    I32_xy ret;
    struct sembuf semb;
    semb.sem_num = 0;
    semb.sem_op = 1;
    semb.sem_flg = SEM_UNDO;
    ret = semop(semId, &semb, 1);
    if (-1 == ret)
    {
        perror("信号量V操作失败\n");
    }
    return ret;
}
