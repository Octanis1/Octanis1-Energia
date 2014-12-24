#ifndef usci_isr_handler_h
#define usci_isr_handler_h




#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_B0__) \
 || defined(__MSP430_HAS_USCI_B1__)
#ifndef USE_USCI_B1
#define UCBxCTLW0     UCB0CTLW0 
#define UCBxCTL0      UCB0CTL0
#define UCBxCTL1      UCB0CTL1
#define UCBxCTL0      UCB0CTL0
#define UCBxBRW       UCB0BRW
#define UCBxBR0       UCB0BR0
#define UCBxBR1       UCB0BR1
#define UCBxMCTL      UCB0MCTL
#define UCBxMCTLW     UCB0MCTLW
#define UCBxSTAT      UCB0STAT
#define UCBxRXBUF     UCB0RXBUF
#define UCBxTXBUF     UCB0TXBUF
#define UCBxABCTL     UCB0ABCTL
#define UCBxIRCTL     UCB0IRCTL
#define UCBxIRTCTL    UCB0IRTCTL
#define UCBxIRRCTL    UCB0IRRCTL
#define UCBxICTL      UCB0ICTL
#define UCBxIE        UCB0IE
#define UCBxIFG       UCB0IFG
#define UCBxIV        UCB0IV
#define UCBxI2COA     UCB0I2COA
#define UCBxI2COA0    UCB0I2COA0
#define UCBxI2CIE     UCB0I2CIE
#define UCBxI2CSA     UCB0I2CSA
#define UCBxRXIFG     UCB0RXIFG
#define UCBxRXIE      UCB0RXIE
#define UCBxTXIE      UCB0TXIE
#define UCBxCTLW1     UCB0CTLW1
#define UCBxTXIFG     UCB0TXIFG
 
#else
#define UCBxCTLW0     UCB1CTLW0
#define UCBxCTL0      UCB1CTL0
#define UCBxCTL1      UCB1CTL1
#define UCBxCTL0      UCB1CTL0
#define UCBxBRW       UCB1BRW
#define UCBxBR0       UCB1BR0
#define UCBxBR1       UCB1BR1
#define UCBxMCTL      UCB1MCTL
#define UCBxMCTLW     UCB1MCTLW
#define UCBxSTAT      UCB1STAT
#define UCBxRXBUF     UCB1RXBUF
#define UCBxTXBUF     UCB1TXBUF
#define UCBxABCTL     UCB1ABCTL
#define UCBxIRCTL     UCB1IRCTL
#define UCBxIRTCTL    UCB1IRTCTL
#define UCBxIRRCTL    UCB1IRRCTL
#define UCBxICTL      UCB1ICTL
#define UCBxIE        UCB1IE
#define UCBxIFG       UCB1IFG
#define UCBxIV        UCB1IV
#define UCBxI2COA     UCB1I2COA
#define UCBxI2COA0    UCB1I2COA0
#define UCBxI2CIE     UCB1I2CIE
#define UCBxI2CSA     UCB1I2CSA
#define UCBxRXIFG     UCB1RXIFG
#define UCBxRXIE      UCB1RXIE
#define UCBxTXIE      UCB1TXIE
#define UCBxCTLW1     UCB1CTLW1
#define UCBxTXIFG     UCB1TXIFG

#endif
#endif


#if defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__) \
 || defined(__MSP430_HAS_EUSCI_A0__)|| defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) 

typedef void CHardwareSerial;
#ifdef __cplusplus
extern "C" {
#endif
void uart_tx_isr(uint8_t offset);
void uart_rx_isr(uint8_t offset);
void i2c_txrx_isr(void);
void i2c_state_isr(void);
void usci_isr_install(void);
#ifdef __cplusplus
}
#endif
#endif /* __MSP430_HAS_USCI__ */
#endif /* usci_isr_handler_h */
