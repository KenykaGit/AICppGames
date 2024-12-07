// lib from https://github.com/keenigithub/SimpleCppDelay

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void delayms(int msec)
{
    this_thread::sleep_for(chrono::milliseconds(msec));
}

void delaysc(int sec)
{
    this_thread::sleep_for(chrono::seconds(sec));
}

void delaymn(int min)
{
    this_thread::sleep_for(chrono::minutes(min));
}

void delayhr(int hour)
{
    this_thread::sleep_for(chrono::hours(hour));
}