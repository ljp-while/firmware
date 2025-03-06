#ifndef  __RINGBUFFER_H
#define  __RINGBUFFER_H

typedef unsigned char ring_u8;
typedef unsigned int ring_u16;

typedef enum{
    RING_ERR = -1,
    RING_SUC,
}RingBufferState_Enum;

typedef struct{
    ring_u16 in;        //缓存区写入计数
    ring_u16 out;       //缓存区读出计数
    ring_u16 size;      //缓存区大小
    ring_u8 *buff;      //缓存区数据存放处
}RingBufferInfo_Typedef;

//**********************************************
//!
//! @brief 创建环形缓存区
//!
//! @param  ring_buffer 定义参考 "RingBufferInfo_Typedef"结构体
//! @param  buff        缓存区数据存放处
//! @param  size        缓存区大小
//!
//! @return 返回创建缓存区状态
//!
//! @note size参数为2次幂！！！！
//**********************************************
RingBufferState_Enum create_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size);

//**********************************************
//!
//! @brief 创建环形缓存区
//!
//! @param  ring_buffer “create_ring_buffer”函数创建的ring_buffer变量
//! @param  buff        写入的数据区
//! @param  size        写入数据区的大小
//!
//! @return 返回实际写入的大小
//!
//**********************************************
ring_u16 write_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size);

//**********************************************
//!
//! @brief 创建环形缓存区
//!
//! @param  ring_buffer “create_ring_buffer”函数创建的ring_buffer变量
//! @param  buff        读取数据区的存放处
//! @param  size        读取数据区的大小
//!
//! @return 返回实际读取的大小
//!
//**********************************************
ring_u16 read_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size);

#endif  /*__RINGBUFFER_H*/

