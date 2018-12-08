// www.smartelc.ir
// M3R

#define DDR DDRD
#define PORT PORTD
#define PIN PIND
#define Data PD7
#define Clock PD6

unsigned long read_hx711 (void)
{
	DDR=0;
	DDR|=(1<<Data);
	unsigned long count;
	unsigned char i;
	PORT|=(1<<Clock);
	PORT&=~(1<<Data);
	count=0;
	while ( (PIN&(1<<Clock)) );
	for (i=0;i<24;i++)
	{
		PORT|=(1<<Data);
		count=count<<1;
		PORT&=~(1<<Data);
		if ( (PIN&(1<<Clock)) ) count++;
	}
	PORTD|=(1<<Data);
	count=count^0b110000000000000000000000;
	count&=0b111111111111110000000000;
	PORTD&=~(1<<Data);
	return count;	
}
