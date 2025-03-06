#ifndef __BUFFER_H__
#define	__BUFFER_H__

#include <stdint.h>
#include <string.h>
#include <stdbool.h>

/*
���λ�����ģ��

2023-08-02:
����
*/


typedef struct {
    uint8_t* buffer;
    uint32_t size;
    uint32_t read_index;
    uint32_t write_index;
	bool			is_init;
} CircularBuffer_TypeDef;

/*!
* @brief     ��ʼ�����λ�����.
 *
 * @param     buffer�����λ��������
 * @param     buff��	������ڴ��׵�ַ
 * @param     buff_size��	������ڴ��С
 *
 * @retval    ����true���ɹ�  false��ʧ��
 *
 * @note      ��.
 */
bool init_buffer(CircularBuffer_TypeDef* buffer,uint8_t* buff,uint32_t buff_size);

/*!
* @brief     ���ٻ��λ�����.
 *
 * @param     buffer�����λ��������
 *
 * @retval    ��.
 *
 * @note      ��.
 */
void destroy_buffer(CircularBuffer_TypeDef* buffer);

/*!
* @brief      д�����ݵ�������.
 *
 * @param     buffer�����λ��������
 * @param     data��	д�����ݵ��׵�ַ
 * @param     num_elements��	д�����ݴ�С
 *
 * @retval    д������.
 *
 * @note      ��.
 */
uint32_t write_to_buffer(CircularBuffer_TypeDef* buffer, uint8_t* data, uint32_t num_elements);


/*!
* @brief      �ӻ�������ȡ����.
 *
 * @param     buffer�����λ��������
 * @param     destination��	��ȡ���ݵ��׵�ַ
 * @param     num_elements��	��ȡ���ݴ�С
 *
 * @retval    ��ȡ����.
 *
 * @note      ��.
 */
uint32_t read_from_buffer(CircularBuffer_TypeDef* buffer, uint8_t* destination, uint32_t num_elements);

#endif




