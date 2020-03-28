#include"mbed.h"
DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn sw2(SW2);
InterruptIn sw3(SW3);
EventQueue queue(32 * EVENTS_EVENT_SIZE);
Thread t;
void led1_info(){
    printf("led1 is triggered! \r\n");
}
void Trig_led1(){
    led1 = !led1;
    queue.call(led1_info);
}
void Trig_led2(){
    led2 = !led2;
    printf("led2 is triggered! \r\n");
}
int main(){
    t.start(callback(&queue,&EventQueue::dispatch_forever));
    sw2.rise(Trig_led1);
    sw3.rise(queue.event(Trig_led2));
}
