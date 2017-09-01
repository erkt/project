void start(){
	SCL = 1 ;
	SDA = 1;
	SDA =0;
}
void stop(){
	SCL = 0;
	SDA = 0;
	SCL = 1;
	SDA = 1;
}
void write(unsigned char dta){
	char i;
	for(i=7;i>=0;i--){
		SCL = 0;
		SDA = (dta & (1<<i))?1:0;
		SCL = 1;
	}
}
unsigned char read(){
	unsigned char temp=0;
	char i;
	for(i=7;i>=0;i--){
		SCL = 1;
	 	if(SDA==1)
	 		temp = temp | (1<<i);
	 	SCL = 0;
	}
	return temp;
}
void ack(){
	SCL = 0;
	SDA = 1;
	SCL = 1;
	while(SDA == 1);
	SCL = 0;
}
void noack(){
	SCL = 0;
	SDA = 1;
	SCL = 1;
}