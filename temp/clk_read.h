	 // this define in main  unsigned char ss,mi,hh,d,dd,mm,yy,temp;
void clock(){

	hh=D_read(0xD0,0x02);//hour
	   temp=hh;
	   hh&=0x1f;
	ldata(hh/16+48);
	ldata(hh%16+48);
	

	mi=D_read(0xD0,0x01);//minute
	ldata(mi/16+48);
	ldata(mi%16+48);
	
	
	ss=D_read(0xD0,0x00);//second
	ldata(ss/16+48);
	ldata(ss%16+48);
	

	if(temp&0x20)
		string(" PM");
	else
		string(" AM");	

	
	d=D_read(0xD0,0x03);//day
	if(d==0){
	   	string("SUN ");
	}
	else if(d==1){
		string("MON ");
	}
	else if(d==2){
		string("TUE ");
	}
	else if(d==3){
		string("WED ");
	}
	else if(d==4){
		string("THU ");
	}
	else if(d==5){
		string("FRI ");
	}
	else if(d==6){
		string("SAT ");
	}
	
	cmd(0xc0);

	dd=D_read(0xD0,0x04);//date
	ldata(dd/16+48);
	ldata(dd%16+48);
	
	
	mm=D_read(0xD0,0x04);//month
	ldata(mm/16+48);
	ldata(mm%16+48);
	
	
	yy=D_read(0xD0,0x04);//year
	ldata(yy/16+48);
	ldata(yy%16+48);
	
}

