#ifndef __BUFFER_H__
#define	__BUFFER_H__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/*
环形缓冲区模块

2023-08-02:
初版
*/


typedef struct {
    uint8_t* buffer;
    uint32_t size;
    uint32_t read_index;
    uint32_t write_index;
	bool			is_init;
} CircularBuffer_TypeDef;

/*!
* @brief     初始化环形缓冲区.
 *
 * @param     buffer：环形缓冲区句柄
 * @param     buff：	分配的内存首地址
 * @param     buff_size：	分配的内存大小
 *
 * @retval    返回true：成功  false：失败
 *
 * @note      无.
 */
bool init_buffer(CircularBuffer_TypeDef* buffer,uint8_t* buff,uint32_t buff_size);

/*!
* @brief     销毁环形缓冲区.
 *
 * @param     buffer：环形缓冲区句柄
 *
 * @retval    无.
 *
 * @note      无.
 */
void destroy_buffer(CircularBuffer_TypeDef* buffer);

/*!
* @brief      写入数据到缓冲区.
 *
 * @param     buffer：环形缓冲区句柄
 * @param     data：	写入数据的首地址
 * @param     num_elements：	写入数据大小
 *
 * @retval    写入数量.
 *
 * @note      无.
 */
uint32_t write_to_buffer(CircularBuffer_TypeDef* buffer, uint8_t* data, uint32_t num_elements);


/*!
* @brief      从缓冲区读取数据.
 *
 * @param     buffer：环形缓冲区句柄
 * @param     destination：	读取数据的首地址
 * @param     num_elements：	读取数据大小
 *
 * @retval    读取数量.
 *
 * @note      无.
 */
uint32_t read_from_buffer(CircularBuffer_TypeDef* buffer, uint8_t* destination, uint32_t num_elements);

#endif




