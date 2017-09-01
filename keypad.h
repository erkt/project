unsigned char lut[][4]={1,2,3,'N',4,5,6,'A',7,8,9,'F','E',0,'D','C'}; 
//n=next ,A=AM/PM,F=alarm mode,E=exit,C=CLock mode,D=done
unsigned char keysearch(){
	unsigned char row,col;
	R0=R1=R2=R3=0;
	C0=C1=C2=C3=1;
	while(C0&C1&C2&C3);
	DelayMS(100);
	R0=0;R1=R2=R3=1;
	if(!(C0&C1&C2&C3)){
		row=0;
		goto check;
	}
	R1=0;R0=R2=R3=1;	
	if(!(C0&C1&C2&C3)){
		row=1;
		goto check;
	}
	R2=0;R0=R1=R3=1;	
	if(!(C0&C1&C2&C3)){
		row=2;
		goto check;
	}
	R3=0;R0=R1=R2=1;	
	if(!(C0&C1&C2&C3)){
		row=3;
		goto check;
	}	
check:
	if(C0==0)
		col=0;
	else if(C1==0)
		col=1;
	else if(C2==0)
		col=2;
	else if(C3==0)
		col=3;

	DelayMS(100);
	while(!(C0&C1&C2&C3));
	return lut[row][col];
}