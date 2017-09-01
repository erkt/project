					void set_clock(void){
	unsigned char dt[7],temp,d_co=7,al[2],i=1,SET=0,AM=1,AM_AL=1;
//unsigned char lut[][4]={1,2,3,'N',4,5,6,'A',7,8,9,'F','E',0,'C','D'}; 	
	char *p="ENTER THE ";
	char *p1[]={"TIME.","SECOND:","MINTUES:","HOURS:","DAY:","DATE:","MONTH:","YEAR:","ALARM."};
	FLAG=0;
	clrscreen();	

	if((temp=keysearch())=='N'){
		gcmd(PG0,1);
		gcmd(ST_ADD,1);
		string(p);
		gcmd(PG0,2);
		gcmd(ST_ADD,2);
		string(p1[0]);
		/* sec min hour day date month year */
	
		while(d_co){
			gcmd(PG0+2,1);
			gcmd(ST_ADD,1);
			string(p);
			gcmd(PG0+2,2);
			gcmd(ST_ADD,2);
			string(p1[i]);

					her:temp=keysearch();
					if(temp=='N'){
						i++;
						d_co--;
						clrpage(PG0+2,3);		
					}
					else if(temp>=0 && temp<=9){
						dt[i-1]=dt[i-1]*10+temp;
						sdigit(temp);
						goto her;
					}
					else if(temp=='A'){
						AM=0;
					}
							
		}
		gcmd(PG0+2,1);	
		gcmd(ST_ADD,1);
		string("SET ALM PRES F");
		temp=keysearch();
		if(temp=='F'){
			SET=1;
			goto HERE;
		}
			/* sec min hour day date month year */
		clock_set(dt[0],dt[1],dt[2],dt[3],dt[4],dt[5],dt[6]);
	}
	else if(temp=='F'){
HERE:		clrpage(2,1);
			gcmd(PG0,1);
			gcmd(ST_ADD,1);
			string(p);
			gcmd(PG0,2);
			gcmd(ST_ADD,2);
			string(p1[8]);
		
			gcmd(PG0+2,1);
			gcmd(ST_ADD,1);
			string(p);
			gcmd(PG0+2,2);
			gcmd(ST_ADD,2);
			string(p1[3]);
			while(!((temp=keysearch())=='N')){
			if(temp>=0 && temp<=9){
				al[0]=al[0]*10+temp;
				sdigit(temp);
				}
			}
			clrpage(2,3);
			gcmd(PG0+2,1);
			gcmd(ST_ADD,1);
			string(p);
			gcmd(PG0+2,2);
			gcmd(ST_ADD,2);
			string(p1[2]);
			while(!((temp=keysearch())=='N')){
				if(temp>=0 && temp<=9){
					al[1]=al[1]*10+temp;
					sdigit(temp);
				}
			}
			if((temp=keysearch())=='A')
				AM_AL=0;//am

			ALM=1;
			alarm_set(al[0],al[1],AM_AL);
	}
	for(i=PG0;i<PG6;i++)
		clrpage(i,3);	
	
	clrscreen();	
}