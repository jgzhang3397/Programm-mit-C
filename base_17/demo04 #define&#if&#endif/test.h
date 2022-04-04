#ifdef _TEST_H_
#define _TEST_H_

/*
防止头文件重复包含:
    1:
        #ifdef _TEST_H_
        #define _TEST_H_
            ...
        #endif
    2:
        #pragma once
*/
int Add(int x, int y);

#endif