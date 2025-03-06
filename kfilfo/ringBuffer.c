#include "ringBuffer.h"
#include <string.h>

#define RING_MIN(a, b)                (((a) < (b)) ? (a) : (b))

RingBufferState_Enum create_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size)
{
    if((size & (size - 1)) != 0)    
        return RING_ERR;
    ring_buffer->buff = buff;
    ring_buffer->in = 0;
    ring_buffer->out = 0;
    ring_buffer->size = size;
    return RING_SUC;
}


ring_u16 write_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size)
{
    ring_u16 len = 0;
    size = RING_MIN(size , ring_buffer->size - ring_buffer->in + ring_buffer->out);
    len = RING_MIN(size, ring_buffer->size - (ring_buffer->in & (ring_buffer->size - 1)));
    memcpy(ring_buffer->buff + (ring_buffer->in & (ring_buffer->size - 1)), buff, len); 
    memcpy(ring_buffer->buff, buff + len, size - len);
    ring_buffer->in += size; 
    return size; 
}

ring_u16 read_ring_buffer(RingBufferInfo_Typedef *ring_buffer, ring_u8 *buff, ring_u16 size)
{
    ring_u16 len = 0;
    size = RING_MIN(size , ring_buffer->in - ring_buffer->out);
    len = RING_MIN(size, ring_buffer->size - (ring_buffer->out & (ring_buffer->size - 1)));  
    memcpy(buff, ring_buffer->buff + (ring_buffer->out & (ring_buffer->size - 1)), len); 
    memcpy(buff + len, ring_buffer->buff, size - len);  
    ring_buffer->out += size;
    return size;
}


