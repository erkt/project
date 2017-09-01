void D_write(unsigned char sa, unsigned char mr, unsigned char dta){
 		start();
		write(sa);
		ack();
		write(mr);
		ack();
		write(dta);
		ack();
		stop();
		DelayMS(10);
}
unsigned char D_read(unsigned char sa, unsigned char mr){
		unsigned char temp;
		start();
		write(sa);
		ack();
		write(mr);
		ack();
		start();
		write(sa|1);
		ack();
		temp = read();
		noack();
		stop();
		return temp;
}