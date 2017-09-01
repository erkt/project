#include<reg51.h>
#include"delay.h"
unsigned char ss,mi,hh,d,dd,mm,yy,temp;
sfr LCD =0x80;
sbit RS =P3^4;
sbit RW =P3^5;
sbit EN =P3^6;
sbit SCL = P1^1;
sbit SDA = P1^0;
#include"lcd.h"
#include"i2c.h"
#include"i2c_device.h"
#include"clk_set.h"
#include"clk_read.h"
main(){
init();
ldata('k');
clock_set();
ldata('j');
while(1){
clock();
cmd(0x80);
}
}