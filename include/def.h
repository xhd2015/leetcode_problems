/*
 * def.h
 *
 *  Created on: 2017年4月6日
 *      Author: 13774
 */

#ifndef INCLUDE_DEF_H_
#define INCLUDE_DEF_H_

#include <cstddef>

//===========数学宏
#define arrsizeof(arr) (sizeof(arr)/sizeof((arr)[0]))


//extern inline 宏
//除非特别短的函数 或者必须作为宏来实现的函数
//否则这样做会增加代码长度
#define AS_MACRO inline __attribute__((always_inline))
#define DEPRECATED __attribute__((deprecated))
#define NORETURN __attribute__((noreturn))




#endif /* INCLUDE_DEF_H_ */
