#include "mbed.h"
int main(){
    EventQueue queue;
    queue.call(printf,"called immediately\r\n");
    queue.call_in(2000,printf,"called in 2 seconds \r\n");
    queue.call_every(1000,printf,"called every 1 second\r\n");
    queue.dispatch();
}