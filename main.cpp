/* mbed Example Program
 * Copyright (c) 2006-2014 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
Thread thread;
 
void led2_thread() {
    while (true) {
        led2 = !led2;
        wait(1);
    }
}
 
int main() {
    thread.start(led2_thread);
    
    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}
