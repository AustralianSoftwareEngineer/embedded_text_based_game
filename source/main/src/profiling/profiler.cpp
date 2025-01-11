#include "profiler.hpp"

//There is an over-head because of the system calls that could be optimised out and instead raw profiling in-line in the function could be done.


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