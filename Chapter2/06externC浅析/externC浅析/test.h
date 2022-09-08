#pragma once    //防止重复编译

#ifdef __cplusplus  //两个_下划线
extern "C" {
#endif   //!__cplusplus


#include <stdio.h>      //c语言的输入输出流



void show();

#ifdef __cplusplus
}
#endif
