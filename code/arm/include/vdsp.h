﻿#ifndef VDSP_H
#define VDSP_H
#include "baseapp.h" ///<用到baseapp类.


/**
* /brief 消息类
*/

class Vdsp : public BaseApp
{

private:
    //以下为syslink层的接口函数
    int ( *fun_write ) ( char *buf , uint32 len );//写数据
    int ( *fun_read ) ( char *buf , uint32* len );//读数据
    int ( *fun_checkmsg ) ( char *buf , uint32 *len );//读消息
    int ( *fun_sendcmd ) ( uint32 cmd, uint32 data );//发送命令
    int ( *fun_recvcmd ) ( void );//接收命令
    int ( *fun_init ) ( void );//初始化
    /**
    *************************************************************************************
    *  @brief 检查dsp发来的消息处理函数.
    *  @author  liht
    *  @param[in]
    *  @param[out]
    *  @return  无
    **************************************************************************************
    */
    void CheckMsg();
    /**
    *************************************************************************************
    *  @brief 检查arm发来的消息处理函数.
    *  @author  liht
    *  @param[in]
    *  @param[out]
    *  @return  无
    **************************************************************************************
    */    
    void GetMsg();
    /**
    *************************************************************************************
    *  @brief  获得Dsp数据，同时设置公共数据区中数据.
    *  @author  liht
    *  @param[in] int16 Num 数量,Item* 数据描述,
    *  @param[out]
    *  @return  成功，返回1，否则返回0。
    **************************************************************************************
    */
    int16 GetData ( int16 Num, Item*item );
    /**
    *************************************************************************************
    *  @brief  从公共数据区中取数据，向dsp设置数据。
    *  @author  liht
    *  @param[in] int16 Num 数量,Item* 数据描述,
    *  @param[out]
    *  @return  成功，返回1，否则返回0。
    **************************************************************************************
    */
    int16 SetData ( int16 Num, Item*item );

public:
    Vdsp();
    ~Vdsp();
    /**
    *************************************************************************************
    *  @brief  初始化本模块。
    *  @author  liht
    *  @param[in]
    *  @param[out]
    *  @return  成功，返回1，否则返回0。
    **************************************************************************************
    */
    int16 Init();
    /**
    *************************************************************************************
    *  @brief  运行模块。
    *  @author  liht
    *  @param[in]
    *  @param[out]
    *  @return  成功，返回1，否则返回0。
    **************************************************************************************
    */
    int16 Run ( void*arg );
    /**
    *************************************************************************************
    *  @brief  处理本模块获得的消息。
    *  @author  liht
    *  @param[in] MessageData message，消息类型定义参见datatype.h
    *  @param[out]
    *  @return  成功，返回1，否则返回0。
    **************************************************************************************
    */
    int16 GetMsg ( MessageData<BaseDataType>message );



};

extern Vdsp vdsp;
/** /brief需要定义一个全局函数Task类处理该类的入口
*/
extern void* vdsp_main ( void* );

#endif