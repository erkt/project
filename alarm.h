void alarm(){
   unsigned char mm,hh,ampm;
   gcmd(PG0+1,2);
   gcmd(ST_ADD,2);
   string("ALARM");
	 if(ALM==1){
			gcmd(PG0+3,2);
			gcmd(ST_ADD,2);
			string("ON");
	 }
	 else if(ALM==0){
			gcmd(PG0+3,2);
			gcmd(ST_ADD,2);
			string("OFF");
	 }
   gcmd(PG0+5,2);
   gcmd(ST_ADD,2);
   mm=D_read(0xA0,0x00);
   hh=D_read(0xA0,0x01);
	 ampm=hh&(1<<5);
		ampm=ampm>>5;
	 hh&=0x1f;
   sdigit(hh/16);
   sdigit(hh%16);
   string(":");
   sdigit(mm/16);
   sdigit(mm%16);
   if(ampm==0)
   string(" AM");
   else
   string(" PM");



}/* hh mm ampm*/
void alarm_set(unsigned char hh,unsigned char mm){
 D_write(0xA0,0x00,mm);
 D_write(0xA0,0x01,hh);
 //D_write(0xA0,0x02,ampm);  //ampm==1 pm	and ampm=0 am
}

void alarm_check(){
		//unsigned char a_mm,a_hh,c_mm,c_hh,ampm,temp,h,m;
		unsigned char a_mm,a_hh,c_mm,c_hh;
		a_mm=D_read(0xA0,0x00);//read alarm min
   	a_hh=D_read(0xA0,0x01);//read alarm hour
		c_mm=D_read(0xD0,0x01);//read clock min
   	c_hh=D_read(0xD0,0x02);//read clock hour

			if(a_hh==c_hh)
				if(a_mm==c_mm){			 
					gcmd(PG0+6,2);
					gcmd(ST_ADD,2);
					
						special();
						LED=0;
						DelayMS(10000);
						ALM=0;
						LED=1;
						clrpage(PG0+6,2);
					}
}	