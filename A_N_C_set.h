void set_clock(void){
//unsigned char lut[][4]={1,2,3,'N',4,5,6,'A',7,8,9,'F','E',0,'D','C'}; 
//n=next ,A=AM/PM,F=alarm mode,E=exit,C=CLock mode,D=done
	unsigned char tm[8]={0,0,0,0,0,0,0,0};
	unsigned char i,temp,j,k,TIME=0,PM=0,tmp=0,kk,ll;
	unsigned char *p[4]={"CLK SET:C","ALM SET:F","CLOCK SET","ALM SET"};
	unsigned char *t[7]={"SECOND:","MINUTES:","HOURS:","DAY:","DATE:","MONTH:","YEAR:"};
c_back:	for(i=PG0;i<=PG7;i++)
		clrpage(i,3);
		clrscreen();
	
	for(i=0;i<2;i++){
		gcmd(PG0+i,1);
		gcmd(ST_ADD,1);
		string(p[i]);
	}
	
	temp=keysearch();
	for(i=PG0;i<=PG7;i++)
		clrpage(i,3);
		clrscreen();	
	
	if(temp=='C'){
		j=0;k=7;TIME=1;
		gcmd(PG0,1);
		gcmd(ST_ADD,1);
		string(p[2]);
	}
	else if(temp=='F'){
		j=1;k=3;ALM=1;
		gcmd(PG0,1);
		gcmd(ST_ADD,1);
		string(p[3]);
	}		
	else
	goto c_back;
	for(i=j;i<k;i++){
			gcmd(PG0+i+1,1);
			gcmd(ST_ADD,1);
			string(t[i]);
	here:	temp=keysearch ();		
				if(temp>=0&&temp<=9){
					tm[i]=tm[i]*10+temp;
					sdigit(temp);
					goto here;
			}
			else if(temp=='A'){PM=1; goto here; }
			else if(temp=='E'){ return; }
			else if(temp=='N'){	continue; }
			else if(temp=='D'){ break; }	
	}
		
		for(i=j;i<k;i++){
				kk=tm[i]%10;
				ll=tm[i]/10;
				ll=(ll<<4);
				tm[i]=(ll&0xf0)|(kk&0x0f);
					   
		}
	 if(PM==1){ tm[2]|=0x60; }
	 else { tm[2]|=0x40; }
	 if(TIME){	/* ss mi hh d dd mm yy */
		 clock_set(tm[0],tm[1],tm[2],tm[3],tm[4],tm[5],tm[6]);
	 } 
	 if(ALM&&(TIME==0)){/* hh mm ampm*/
		alarm_set(tm[2],tm[1]);
	 }
	DelayMS(200);
	return;	
}