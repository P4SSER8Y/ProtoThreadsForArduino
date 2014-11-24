/*
 * Copyright (c) 2014, Huazhong University of Science and Technology
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Author: Troy Cheung <TroyC.public@gmail.com>
 *
 */

#ifndef __PT_TIMER__
#define __PT_TIMER__

typedef unsigned long pt_timer;

/**
 * \name Delay for milliseconds
 * @{
 */

/**
 * Delay for specific milliseconds
 */
#define PT_TIMER_DELAY(pt,time) 				\
		do {															\
			(pt)->t = millis();								\
			PT_WAIT_UNTIL((pt),((pt_timer)(millis()-(pt)->t)>=(time)));\
		}while(0)

/**
 * \name Delay for microseconds
 * @{
 */

/**
 * Delay for specific microseconds
 */
#define PT_TIMER_MICRODELAY(pt,time)\
		do {															\
			(pt)->t = micros();								\
			PT_WAIT_UNTIL((pt),((pt_timer)(micros()-(pt)->t)>=(time)));\
		}while(0)

/**
 * \name Wait for some condition or timeout
 * @{
 */

/**
 * Wait for condition's becoming true or timeout
 */
#define PT_TIMER_WAIT_TIMEOUT(pt,condition,t)		\
	do {												\
		(pt)->t = millis();								\
		PT_WAIT_UNTIL((pt),(condition)||((pt_timer)(millis()-(pt)->t)>=(t)));\
	}while(0)

#endif

