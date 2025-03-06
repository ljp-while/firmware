#include "drivers/buffer.h"





bool init_buffer(CircularBuffer_TypeDef* buffer,uint8_t* buff,uint32_t buff_size) {
    buffer->buffer = buff;
		buffer->is_init = false;
    if (buffer->buffer == NULL) {
        return false; // 内存分配失败
    }
    buffer->size = buff_size;
    buffer->read_index = 0;
    buffer->write_index = 0;
		buffer->is_init = true;
    return true;
}

void destroy_buffer(CircularBuffer_TypeDef* buffer) {
    if (buffer->buffer != NULL) {
        buffer->buffer = NULL;
    }
		buffer->is_init = false;
}

uint32_t write_to_buffer(CircularBuffer_TypeDef* buffer, uint8_t* data, uint32_t num_elements) {
    uint32_t written = 0;
		if(buffer->is_init == false) return 0;
    while (written < num_elements) {
        if ((buffer->write_index + 1) % buffer->size == buffer->read_index) {
            return written; 
        }
        buffer->buffer[buffer->write_index] = data[written];
        buffer->write_index = (buffer->write_index + 1) % buffer->size;
        written++;
    }
    return written; 
}


uint32_t read_from_buffer(CircularBuffer_TypeDef* buffer, uint8_t* destination, uint32_t num_elements) {
    uint32_t read = 0;
		if(buffer->is_init == false) return 0;
    while (read < num_elements) {
        if (buffer->read_index == buffer->write_index) {
            return read; 
        }
        destination[read] = buffer->buffer[buffer->read_index];
        buffer->read_index = (buffer->read_index + 1) % buffer->size;
        read++;
    }
    return read; 
}

