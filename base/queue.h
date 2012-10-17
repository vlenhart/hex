/*
 * HEX Programming Language
 * Copyright (C) 2012  Yanzheng Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Queue - FIFO storage container. */

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stddef.h>


typedef struct HexQueue_s *Queue;


Queue create_queue();

size_t queue_size(Queue queue);

void* queue_front(Queue queue);

void* queue_back(Queue queue);

int queue_push(Queue queue, void *val, size_t size);

void* queue_pop(Queue queue);


#endif /* _QUEUE_H_ */