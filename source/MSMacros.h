//
//  MSMacros.h
//  MediaStreamPlayer
//
//  Created by xiaoming on 2019/1/16.
//  Copyright © 2019 freecoder. All rights reserved.
//

#ifndef MSMacros_h
#define MSMacros_h

#include <cstdio>
#include <cassert>

#define intervale(rate) microseconds(1000000LL / rate)

#define adv_intervale(rate) microseconds((1000000ll << 16) / rate)

#define MaxPixelBufferSize 100

#define MaxSampleBufferSize 40

#if DEBUG

#define ErrorLocationLog(reason) \
printf("\n"\
"-----------------------------ERROR-----------------------------\n"\
"| filepath:    %s\n"\
"| linenumber:  %d\n"\
"| funcname:    %s\n"\
"| reson:       %s\n"\
"---------------------------------------------------------------\n",__FILE__,__LINE__,__func__,reason)

// parse OSStatus meaning
#define OSStatus2Str(status) \
char errStr[5] = {char(status >> 24), char(status >> 16), char(status >> 8), char(status) , 0x00}

#define OSStatusErrorLocationLog(reason,status) \
OSStatus2Str(status); \
printf("\n"\
"-----------------------------ERROR-----------------------------\n"\
"| filepath:    %s\n"\
"| linenumber:  %d\n"\
"| funcname:    %s\n"\
"| reson:       %s\n"\
"| status:      %d --> %s\n"\
"---------------------------------------------------------------\n",__FILE__,__LINE__,__func__,reason,(int)status,errStr)

#else

#define OSStatus2Str(status)
#define ErrorLocationLog(reason)
#define OSStatusErrorLocationLog(reason,status)

#endif

#ifdef __APPLE__

#define MSNullable  _Nullable
#define MSNonnull   _Nonnull

#else

#define MSNullable
#define MSNonnull

#endif

#endif /* MSMacros_h */
