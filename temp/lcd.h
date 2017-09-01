void cmd(unsigned char cmd){
	LCD = cmd;
	RS=RW=0;EN=1;
	DelayMS(2);
	EN=0;
}
void ldata(unsigned char dta){
	LCD = dta;
	RS=1;RW=0;EN=1;
	DelayMS(2);
	EN=0;
}
void init(){
	cmd(0x01);
	cmd(0x02);
	cmd(0x06);
	cmd(0x0c);
	cmd(0x38);
	cmd(0x80);
}
void string(char *s){
	while(*s)
		ldata(*s++);
}