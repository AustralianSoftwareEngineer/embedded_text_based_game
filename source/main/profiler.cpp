#include "profiler.h"
//Due to the way arduino time libraries work, time chararistics have limited usability.
//There is over-head in the form of function calls happening here, I'm happy to ignore that extra cost based on use case.


long start_function_time_us = 0;
long end_function_time_us = 0;
uint8_t profiling_result = 0;

void profileThisStart()
{
    start_function_time_us = micros();
}


void profileThisEnd()
{
    end_function_time_us = micros();

    profiling_result++;
    Serial.print("Profiling result: ");
    Serial.println(profiling_result);
    Serial.println(end_function_time_us - start_function_time_us);
}