
















 


















 



 


















 


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 

    typedef          int    int16_t;
    typedef unsigned int   uint16_t;
    typedef          long   int32_t;
    typedef unsigned long  uint32_t;


    typedef          long long  int64_t;
    typedef unsigned long long uint64_t;

 

    typedef  int16_t  int_least8_t;
    typedef uint16_t uint_least8_t;

    typedef  int16_t  int_least16_t;
    typedef uint16_t uint_least16_t;
    typedef  int32_t  int_least32_t;
    typedef uint32_t uint_least32_t;


    typedef  int64_t  int_least64_t;
    typedef uint64_t uint_least64_t;

 

    typedef  int16_t  int_fast8_t;
    typedef uint16_t uint_fast8_t;
    typedef  int16_t  int_fast16_t;
    typedef uint16_t uint_fast16_t;

    typedef  int32_t  int_fast32_t;
    typedef uint32_t uint_fast32_t;


    typedef  int64_t  int_fast64_t;
    typedef uint64_t uint_fast64_t;

 
    typedef          long intptr_t;
    typedef unsigned long uintptr_t;

 
    typedef          long long intmax_t;
    typedef unsigned long long uintmax_t;





 

 
















 







 







 




 































 





 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 



#pragma diag_push
#pragma CHECK_MISRA("-6.3")  
#pragma CHECK_MISRA("-8.5")  
#pragma CHECK_MISRA("-19.1")  
#pragma CHECK_MISRA("-19.7")  
#pragma CHECK_MISRA("-20.1")  
#pragma CHECK_MISRA("-20.2")  

 
 
 



#pragma diag_push
#pragma CHECK_MISRA("-5.7")  

typedef struct { int quot, rem; } div_t;

typedef struct { long quot, rem; } ldiv_t;

typedef struct { long long quot, rem; } lldiv_t;

#pragma diag_pop



typedef unsigned long size_t;

typedef unsigned int wchar_t;



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


#pragma diag_push
#pragma CHECK_MISRA("-19.4")  

 


 
 
 

 
 
 

 
 
 

#pragma diag_pop


 
 
 
 
 
 
 
#pragma diag_push
#pragma CHECK_MISRA("-16.4")  
      int       abs(int _val); 
      long      labs(long _val);
      long long llabs(long long _val);
#pragma diag_pop

     int       atoi(const char *_st);
     long      atol(const char *_st);
     long long atoll(const char *_st);
     int       ltoa(long val, char *buffer);
          static __inline double    atof(const char *_st);

     long      strtol(const char *_st, char **_endptr, int _base);
     unsigned long strtoul(const char *_st, char **_endptr,
    					  int _base);
     long long strtoll(const char *_st, char **_endptr, int _base);
     unsigned long long strtoull(const char *_st, char **_endptr,
					     int _base);
     float     strtof(const char * _st, 
                                  char ** _endptr);
     double    strtod(const char * _st, 
                                  char ** _endptr);
     long double strtold(const char * _st, 
                                     char ** _endptr);
    
     int    rand(void);
     void   srand(unsigned _seed);
    
     void  *calloc(size_t _num, size_t _size)
               __attribute__((malloc));
     void  *malloc(size_t _size)
               __attribute__((malloc));
     void  *realloc(void *_ptr, size_t _size)
               __attribute__((malloc));
     void   free(void *_ptr);
     void  *memalign(size_t _aln, size_t _size)
               __attribute__((malloc));
    
     void   abort(void); 

    typedef void (*__TI_atexit_fn)(void);
     int    atexit(__TI_atexit_fn _func);

    typedef int (*__TI_compar_fn)(const void *_a,const void *_b);
     void  *bsearch(const void *_key, const void *_base,
                                size_t _nmemb, size_t _size, 
                                __TI_compar_fn compar);
     void   qsort(void *_base, size_t _nmemb, size_t _size, 
                              __TI_compar_fn compar);

     void   exit(int _status);
    
     div_t  div(int _numer, int _denom);
     ldiv_t ldiv(long _numer, long _denom);
     lldiv_t lldiv(long long _numer, long long _denom);

     char  *getenv(const char *_string);
     int    system(const char *_name);

     int    mblen(const char *_s, size_t _n);
     size_t mbstowcs(wchar_t *_dest, const char *_src, size_t _n);
     int    mbtowc(wchar_t *_dest, const char *_src, size_t _n);

     size_t wcstombs(char *_dest, const wchar_t *_src, size_t _n);
     int    wctomb(char *_s, wchar_t _wc);





static __inline double atof(const char *_st) 
{
  return strtod(_st, (char **)0); 
}




#pragma diag_pop


#pragma diag_push


 
 
#pragma CHECK_MISRA("-19.15")


#pragma diag_pop

#pragma diag_push

 
#pragma CHECK_MISRA("-19.1")
#pragma CHECK_MISRA("-19.15")

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#pragma diag_push
#pragma CHECK_MISRA("-6.3")

 long          far_strtol (const char *st,
                                       char **endptr, 
				       int base);
 unsigned long far_strtoul(const char *st,
                                       char **endptr, 
				       int base);
 double        far_strtod (const char *st,
                                       char **endptr);
 long double   far_strtold (const char *st,
                                        char **endptr);
 long long     far_strtoll(const char *st,
                                       char **endptr, 
		 		       int base);
 unsigned long long far_strtoull(const char *st, 
                                                   char **endptr,
                                                   int base);
 int           far_atoi(const char *st);
 long          far_atol(const char *st);
static __inline       double        far_atof(const char *st);
 long long     far_atoll(const char *st);

 void     *far_calloc  (unsigned long num, unsigned long size);
 void     *far_malloc  (unsigned long size);
 void     *far_realloc (void *ptr, unsigned long size);
 void          far_free    (void *ptr);

 void     *far_bsearch(const void *key, 
                                       const void *base, 
			               size_t nmemb, size_t size, 
			               int (*compar)(const void *a,
                                                     const void *b));
 void          far_qsort  (void *base, 
                                       size_t nmemb, size_t size,
			               int (*compar)(const void *a, 
                                                     const void *b));

 int	   free_memory(void);
 int           max_free(void);
 void         *chkheap(void);

#pragma diag_push
#pragma CHECK_MISRA("-8.5")  
static __inline double far_atof(const char *st) 
{ 
   return far_strtod(st, (char **)0);
}
#pragma diag_pop


#pragma diag_pop


#pragma diag_push


 
 
#pragma CHECK_MISRA("-19.15")


#pragma diag_pop

#pragma diag_pop



































extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int IER;









typedef int             	int16;
typedef long            	int32;
typedef long long			int64;
typedef unsigned long long	Uint64;
typedef float           	float32;
typedef long double     	float64;










 

typedef int             Int;
typedef unsigned        Uns;
typedef char            Char;
typedef char            *String;
typedef void            *Ptr;
typedef unsigned short	Bool;

typedef unsigned long   Uint32;
typedef unsigned int    Uint16;
typedef unsigned char   Uint8;

typedef long            Int32;
typedef int             Int16;
typedef char            Int8;

























struct ADCCTL1_BITS {     
	Uint16	TEMPCONV:1;				
	Uint16	VREFLOCONV:1;			
	Uint16	INTPULSEPOS :1;			
	Uint16	ADCREFSEL:1;			
	Uint16	rsvd1:1;				
	Uint16	ADCREFPWD:1;			
	Uint16	ADCBGPWD:1;				
	Uint16	ADCPWDN:1;				
	Uint16	ADCBSYCHN:5;			
	Uint16	ADCBSY:1;				
	Uint16	ADCENABLE:1;			
	Uint16	RESET:1;				
};

union ADCCTL1_REG {
	Uint16 all;
	struct ADCCTL1_BITS	bit;
};

struct ADCCTL2_BITS {     
	Uint16	CLKDIV2EN:1;		
	Uint16	ADCNONOVERLAP:1;	
	Uint16	CLKDIV4EN:1;		
	Uint16	rsvd1:13;			
};

union ADCCTL2_REG {
	Uint16 all;
	struct ADCCTL2_BITS	bit;
};

struct ADCSAMPLEMODE_BITS {     
	Uint16	SIMULEN0:1;			
	Uint16	SIMULEN2:1;			
	Uint16	SIMULEN4:1;			
	Uint16	SIMULEN6:1;			
	Uint16	SIMULEN8:1;			
	Uint16	SIMULEN10:1;		
	Uint16	SIMULEN12:1;		
	Uint16	SIMULEN14:1;		
	Uint16	rsvd1:8;			
};

union ADCSAMPLEMODE_REG {
	Uint16 all;
	struct ADCSAMPLEMODE_BITS	bit;
};

struct SOCPRICTL_BITS {     
	Uint16	SOCPRIORITY:5;		
	Uint16	RRPOINTER:6;		
	Uint16	rsvd1:4;			
	Uint16	ONESHOT:1;			
};

union SOCPRICTL_REG {
	Uint16 all;
	struct SOCPRICTL_BITS	bit;
};

struct ADCSOC_BITS {     
	Uint16	SOC0:1;			
	Uint16	SOC1:1;			
	Uint16	SOC2:1;			
	Uint16	SOC3:1;			
	Uint16	SOC4:1;			
	Uint16	SOC5:1;			
	Uint16	SOC6:1;			
	Uint16	SOC7:1;			
	Uint16	SOC8:1;			
	Uint16	SOC9:1;			
	Uint16	SOC10:1;		
	Uint16	SOC11:1;		
	Uint16	SOC12:1;		
	Uint16	SOC13:1;		
	Uint16	SOC14:1;		
	Uint16	SOC15:1;		
};

union ADCSOC_REG {
	Uint16 all;
	struct ADCSOC_BITS	bit;
};

struct INTSEL1N2_BITS {     
	Uint16	INT1SEL:5;			
	Uint16	INT1E:1;			
	Uint16	INT1CONT:1;			
	Uint16	rsvd1:1;			
	Uint16	INT2SEL:5;			
	Uint16	INT2E:1;			
	Uint16	INT2CONT:1;			
	Uint16	rsvd2:1;			
};

union INTSEL1N2_REG {
	Uint16 all;
	struct INTSEL1N2_BITS	bit;
};

struct INTSEL3N4_BITS {     
	Uint16	INT3SEL:5;			
	Uint16	INT3E:1;			
	Uint16	INT3CONT:1;			
	Uint16	rsvd1:1;			
	Uint16	INT4SEL:5;			
	Uint16	INT4E:1;			
	Uint16	INT4CONT:1;			
	Uint16	rsvd2:1;			
};

union INTSEL3N4_REG {
	Uint16 all;
	struct INTSEL3N4_BITS	bit;
};

struct INTSEL5N6_BITS {     
	Uint16	INT5SEL:5;			
	Uint16	INT5E:1;			
	Uint16	INT5CONT:1;			
	Uint16	rsvd1:1;			
	Uint16	INT6SEL:5;			
	Uint16	INT6E:1;			
	Uint16	INT6CONT:1;			
	Uint16	rsvd2:1;			
};

union INTSEL5N6_REG {
	Uint16 all;
	struct INTSEL5N6_BITS	bit;
};

struct INTSEL7N8_BITS {     
	Uint16	INT7SEL:5;			
	Uint16	INT7E:1;			
	Uint16	INT7CONT:1;			
	Uint16	rsvd1:1;			
	Uint16	INT8SEL:5;			
	Uint16	INT8E:1;			
	Uint16	INT8CONT:1;			
	Uint16	rsvd2:1;			
};

union INTSEL7N8_REG {
	Uint16 all;
	struct INTSEL7N8_BITS	bit;
};

struct INTSEL9N10_BITS {     
	Uint16	INT9SEL:5;			
	Uint16	INT9E:1;			
	Uint16	INT9CONT:1;			
	Uint16	rsvd1:1;			
	Uint16	INT10SEL:5;			
	Uint16	INT10E:1;			
	Uint16	INT10CONT:1;		
	Uint16	rsvd2:1;			
};

union INTSEL9N10_REG {
	Uint16 all;
	struct INTSEL9N10_BITS	bit;
};

struct ADCINT_BITS {     
	Uint16	ADCINT1:1;			
	Uint16	ADCINT2:1;			
	Uint16	ADCINT3:1;			
	Uint16	ADCINT4:1;			
	Uint16	ADCINT5:1;			
	Uint16	ADCINT6:1;			
	Uint16	ADCINT7:1;			
	Uint16	ADCINT8:1;			
	Uint16	ADCINT9:1;			
	Uint16	rsvd1:7;			
};

union ADCINT_REG {
	Uint16 all;
	struct ADCINT_BITS	bit;
};

struct ADCINTSOCSEL1_BITS {     
	Uint16	SOC0:2;			
	Uint16	SOC1:2;			
	Uint16	SOC2:2;			
	Uint16	SOC3:2;			
	Uint16	SOC4:2;			
	Uint16	SOC5:2;			
	Uint16	SOC6:2;			
	Uint16	SOC7:2;			
};

union ADCINTSOCSEL1_REG {
	Uint16 all;
	struct ADCINTSOCSEL1_BITS	bit;
};

struct ADCINTSOCSEL2_BITS {     
	Uint16	SOC8:2;				
	Uint16	SOC9:2;				
	Uint16	SOC10:2;			
	Uint16	SOC11:2;			
	Uint16	SOC12:2;			
	Uint16	SOC13:2;			
	Uint16	SOC14:2;			
	Uint16	SOC15:2;			
};

union ADCINTSOCSEL2_REG {
	Uint16 all;
	struct ADCINTSOCSEL2_BITS	bit;
};

struct ADCSOCxCTL_BITS {     
	Uint16	ACQPS:6;			
	Uint16	CHSEL:4;			
	Uint16	rsvd1:1;			
	Uint16	TRIGSEL:5;			
};

union ADCSOCxCTL_REG {
	Uint16 all;
	struct ADCSOCxCTL_BITS	bit;
};

struct ADCREFTRIM_BITS {     
	Uint16	BG_FINE_TRIM:5;			
	Uint16	BG_COARSE_TRIM:4;		
	Uint16	EXTREF_FINE_TRIM:5;		
	Uint16	rsvd1:2;				
};

union ADCREFTRIM_REG {
	Uint16 all;
	struct ADCREFTRIM_BITS	bit;
};

struct ADCOFFTRIM_BITS {     
	int16	OFFTRIM:9;			
	Uint16	rsvd1:7;			
};

union ADCOFFTRIM_REG {
	Uint16 all;
	struct ADCOFFTRIM_BITS	bit;
};

struct COMPHYSTCTL_BITS{                
    Uint16  rsvd1:1;             	   
    Uint16  COMP1_HYST_DISABLE:1;      
    Uint16  rsvd2:4;                   
    Uint16  COMP2_HYST_DISABLE:1;      
    Uint16  rsvd3:4;                   
    Uint16  COMP3_HYST_DISABLE:1;      
    Uint16  rsvd4:4;                   
};

union COMPHYSTCTL_REG{
    Uint16      all;
    struct COMPHYSTCTL_BITS bit;
};

struct ADC_REGS {
	union	ADCCTL1_REG			ADCCTL1;		
	union	ADCCTL2_REG			ADCCTL2;		
	Uint16						rsvd1;			
	Uint16						rsvd2;			
	union	ADCINT_REG			ADCINTFLG;		
	union	ADCINT_REG			ADCINTFLGCLR;	
	union	ADCINT_REG			ADCINTOVF;		
	union	ADCINT_REG			ADCINTOVFCLR;	
	union	INTSEL1N2_REG		INTSEL1N2;		
	union	INTSEL3N4_REG		INTSEL3N4;		
	union	INTSEL5N6_REG		INTSEL5N6;		
	union	INTSEL7N8_REG		INTSEL7N8;		
	union	INTSEL9N10_REG		INTSEL9N10;		
	Uint16						rsvd3;			
	Uint16						rsvd4;			
	Uint16						rsvd5;			
	union	SOCPRICTL_REG		SOCPRICTL;		
	Uint16						rsvd6;			
	union	ADCSAMPLEMODE_REG	ADCSAMPLEMODE;	
	Uint16						rsvd7;			
	union	ADCINTSOCSEL1_REG	ADCINTSOCSEL1;	
	union	ADCINTSOCSEL2_REG	ADCINTSOCSEL2;	
	Uint16						rsvd8;			
	Uint16						rsvd9;			
	union	ADCSOC_REG			ADCSOCFLG1;		
	Uint16						rsvd10;			
	union	ADCSOC_REG			ADCSOCFRC1;		
	Uint16						rsvd11;			
	union	ADCSOC_REG			ADCSOCOVF1;		
	Uint16						rsvd12;			
	union	ADCSOC_REG			ADCSOCOVFCLR1;	
	Uint16						rsvd13;			
	union	ADCSOCxCTL_REG		ADCSOC0CTL;		
	union	ADCSOCxCTL_REG		ADCSOC1CTL;		
	union	ADCSOCxCTL_REG		ADCSOC2CTL;		
	union	ADCSOCxCTL_REG		ADCSOC3CTL;		
	union	ADCSOCxCTL_REG		ADCSOC4CTL;		
	union	ADCSOCxCTL_REG		ADCSOC5CTL;		
	union	ADCSOCxCTL_REG		ADCSOC6CTL;		
	union	ADCSOCxCTL_REG		ADCSOC7CTL;		
	union	ADCSOCxCTL_REG		ADCSOC8CTL;		
	union	ADCSOCxCTL_REG		ADCSOC9CTL;		
	union	ADCSOCxCTL_REG		ADCSOC10CTL;	
	union	ADCSOCxCTL_REG		ADCSOC11CTL;	
	union	ADCSOCxCTL_REG		ADCSOC12CTL;	
	union	ADCSOCxCTL_REG		ADCSOC13CTL;	
	union	ADCSOCxCTL_REG		ADCSOC14CTL;	
	union	ADCSOCxCTL_REG		ADCSOC15CTL;	
	Uint16						rsvd14[16];		
	union	ADCREFTRIM_REG		ADCREFTRIM;		
	union	ADCOFFTRIM_REG		ADCOFFTRIM;		
	Uint16                      rsvd15 [10];    
	union   COMPHYSTCTL_REG     COMPHYSTCTL;    
	Uint16                      rsvd16 [3];     
};

struct ADC_RESULT_REGS {
	Uint16		ADCRESULT0;		
	Uint16		ADCRESULT1;		
	Uint16		ADCRESULT2;		
	Uint16		ADCRESULT3;		
	Uint16		ADCRESULT4;		
	Uint16		ADCRESULT5;		
	Uint16		ADCRESULT6;		
	Uint16		ADCRESULT7;		
	Uint16		ADCRESULT8;		
	Uint16		ADCRESULT9;		
	Uint16		ADCRESULT10;	
	Uint16		ADCRESULT11;	
	Uint16		ADCRESULT12;	
	Uint16		ADCRESULT13;	
	Uint16		ADCRESULT14;	
	Uint16		ADCRESULT15;	
};




extern volatile struct ADC_REGS AdcRegs;
extern volatile struct ADC_RESULT_REGS AdcResult;


























extern Uint16 EmuKey;
extern Uint16 EmuBMode;
extern Uint32 Flash_CPUScaleFactor;
extern void (*Flash_CallbackPtr) (void);
























struct MCTL_BITS {     
	Uint16	HARDRESET:1;		
	Uint16	SOFTRESET:1;		
	Uint16	IACKE:1;			
	Uint16	rsvd1:13;			
};

union MCTL_REG {
	Uint16 all;
	struct MCTL_BITS	bit;
};

struct MMEMCFG_BITS {     
	Uint16	PROGE:1;			
	Uint16	rsvd1:3;			
	Uint16	RAM0E:1;			
	Uint16	RAM1E:1;			
	Uint16  RAM2E:1;			
	Uint16	rsvd2:1;			
	Uint16	RAM0CPUE:1;			
	Uint16	RAM1CPUE:1;			
	Uint16	RAM2CPUE:1;			
	Uint16	rsvd3:5;			
};

union MMEMCFG_REG {
	Uint16 all;
	struct MMEMCFG_BITS	bit;
};

struct MPISRCSEL1_BITS {     
	Uint16	PERINT1SEL:4;			
	Uint16	PERINT2SEL:4;			
	Uint16	PERINT3SEL:4;			
	Uint16	PERINT4SEL:4;			
	Uint16	PERINT5SEL:4;			
	Uint16	PERINT6SEL:4;			
	Uint16	PERINT7SEL:4;			
	Uint16	PERINT8SEL:4;			
};

union MPISRCSEL1_REG {
	Uint32 all;
	struct MPISRCSEL1_BITS	bit;
};

struct MIFR_BITS {     
	Uint16	INT1:1;			
	Uint16	INT2:1;			
	Uint16	INT3:1;			
	Uint16	INT4:1;			
	Uint16	INT5:1;			
	Uint16	INT6:1;			
	Uint16	INT7:1;			
	Uint16	INT8:1;			
	Uint16	rsvd1:8;		
};

union MIFR_REG {
	Uint16 all;
	struct MIFR_BITS	bit;
};

union MIOVF_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIFRC_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MICLR_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MICLROVF_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIER_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

union MIRUN_REG {
   Uint16              all;
   struct MIFR_BITS    bit;
};

struct MSTF_BITS {     
	Uint16	LVF:1;			
	Uint16	LUF:1;			
	Uint16	NF:1;			
	Uint16	ZF:1;			
	Uint16	rsvd1:2;		
	Uint16	TF:1;			
	Uint16	rsvd2:2;		
	Uint16	RNDF32:1;		
	Uint16	rsvd3:1;		
	Uint16	MEALLOW:1;		
	Uint16	RPCL:4;			
	Uint16	RPCH:8;			
	Uint16	rsvd4:8;		
};

union MSTF_REG {
	Uint32 all;
	struct MSTF_BITS	bit;
};

union MR_REG {
	Uint32				i32;
	float				f32;
};

struct CLA_REGS {
	Uint16					MVECT1;		
	Uint16					MVECT2;		
	Uint16					MVECT3;		
	Uint16					MVECT4;		
	Uint16					MVECT5;		
	Uint16					MVECT6;		
	Uint16					MVECT7;		
	Uint16					MVECT8;		
	Uint16					rsvd1[8];	
	union	MCTL_REG		MCTL;		
	union	MMEMCFG_REG		MMEMCFG;	
	Uint16					rsvd2[2];	
	union	MPISRCSEL1_REG	MPISRCSEL1;	
	Uint16					rsvd3[10];	
	union	MIFR_REG		MIFR;		
	union	MIOVF_REG		MIOVF;		
	union	MIFRC_REG		MIFRC;		
	union	MICLR_REG		MICLR;		
	union	MICLROVF_REG	MICLROVF;	
	union	MIER_REG		MIER;		
	union	MIRUN_REG		MIRUN;		
	Uint16					rsvd4;		
	Uint16					_MPC;		
	Uint16					rsvd5;		
	Uint16					_MAR0;		
	Uint16					_MAR1;		
	Uint16					rsvd6[2];	
	union	MSTF_REG		_MSTF;		
	union	MR_REG			_MR0;		
	Uint32					rsvd7;		
	union	MR_REG			_MR1;		
	Uint32					rsvd8;		
	union	MR_REG			_MR2;		
	Uint32					rsvd9;		
	union	MR_REG			_MR3;		
	Uint32					rsvd10;		
};




extern volatile struct CLA_REGS Cla1Regs;























struct COMPCTL_BITS {     
	Uint16	COMPDACEN:1;		
	Uint16	COMPSOURCE:1;		
	Uint16	CMPINV:1;			
	Uint16	QUALSEL:5;			
	Uint16	SYNCSEL:1;			
	Uint16	rsvd1:7;			
};

union COMPCTL_REG {
	Uint16 all;
	struct COMPCTL_BITS	bit;
};

struct COMPSTS_BITS {     
	Uint16	COMPSTS:1;			
	Uint16	rsvd1:15;			
};

union COMPSTS_REG {
	Uint16 all;
	struct COMPSTS_BITS	bit;
};

struct DACCTL_BITS {            
    Uint16   DACSOURCE:1;        
    Uint16   RAMPSOURCE:4;       
    Uint16   rsvd1:9;            
    Uint16   FREE_SOFT:2;        
};

union DACCTL_REG  {
    Uint16                         all;
    struct DACCTL_BITS             bit;
};

struct DACVAL_BITS {     
	Uint16	DACVAL:10;			
	Uint16	rsvd1:6;			
};

union DACVAL_REG {
	Uint16 all;
	struct DACVAL_BITS	bit;
};




struct COMP_REGS {
	union	COMPCTL_REG	COMPCTL;			
	Uint16				rsvd1;				
	union	COMPSTS_REG	COMPSTS;			
    Uint16                     rsvd2;
    union  DACCTL_REG          DACCTL;
    Uint16                     rsvd3;
    union  DACVAL_REG          DACVAL;
    Uint16                     rsvd4;
    Uint16                     RAMPMAXREF_ACTIVE;
    Uint16                     rsvd5;
    Uint16                     RAMPMAXREF_SHDW;
    Uint16                     rsvd6;
    Uint16                     RAMPDECVAL_ACTIVE;
    Uint16                     rsvd7;
    Uint16                     RAMPDECVAL_SHDW;
    Uint16                     rsvd8;
    Uint16                     RAMPSTS;
    Uint16                     rsvd9[3];
};




extern volatile struct COMP_REGS Comp1Regs;
extern volatile struct COMP_REGS Comp2Regs;
extern volatile struct COMP_REGS Comp3Regs;























struct TCR_BITS {     
	Uint16	rsvd1:4;		
	Uint16	TSS:1;			
	Uint16	TRB:1;			
	Uint16	rsvd2:4;		
	Uint16	SOFT:1;			
	Uint16	FREE:1;			
	Uint16	rsvd3:2;		
	Uint16	TIE:1;			
	Uint16	TIF:1;			
};

union TCR_REG {
	Uint16 all;
	struct TCR_BITS	bit;
};

struct TPR_BITS {     
	Uint16	TDDR:8;			
	Uint16	PSC:8;			
};

union TPR_REG {
	Uint16 all;
	struct TPR_BITS	bit;
};

struct TPRH_BITS {     
	Uint16	TDDRH:8;		
	Uint16	PSCH:8;			
};

union TPRH_REG {
	Uint16 all;
	struct TPRH_BITS	bit;
};


struct TIM_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union TIM_GROUP {
   Uint32          all;
   struct TIM_REG  half;
};


struct PRD_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union PRD_GROUP {
   Uint32          all;
   struct PRD_REG  half;
};

struct CPUTIMER_REGS {
	union TIM_GROUP 	TIM;   		
   	union PRD_GROUP 	PRD;   		
	union	TCR_REG		TCR;		
	Uint16				rsvd1;		
	union	TPR_REG		TPR;		
	union	TPRH_REG	TPRH;		
};







struct CPUTIMER_VARS {
   volatile struct  CPUTIMER_REGS  *RegsAddr;
   Uint32    InterruptCount;
   float   CPUFreqInMHz;
   float   PeriodInUSec;
};




void InitCpuTimers(void);
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period);

extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern struct CPUTIMER_VARS CpuTimer0;

extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;













































struct DEVICECNF_BITS {     
	Uint16	rsvd1:3;			
	Uint16	VMAPS:1;			
	Uint16	rsvd2:1;			
	Uint16	XRSn:1;				
	Uint16	rsvd3:10;			
	Uint16  rsvd4:3;			
	Uint16	ENPROT:1;			
	Uint16	rsvd5:7;			
	Uint16	TRSTn:1;			
	Uint16	rsvd6:2;			
	Uint16	SYSCLK2DIV2DIS:1;	
	Uint16	rsvd8:1;			
};

union DEVICECNF_REG {
	Uint32 all;
	struct DEVICECNF_BITS	bit;
};


struct CLASSID_BITS   {  
   Uint16 CLASSNO:8;     
   Uint16 PARTTYPE:8;    
};

union CLASSID_REG {
   Uint16               all;
   struct CLASSID_BITS  bit;
};


struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  
   union CLASSID_REG   CLASSID;    
   Uint16              REVID;      
};


struct PARTID_BITS   {  
   Uint16 PARTNO:8;     
   Uint16 PARTTYPE:8;   
};

union PARTID_REG {
   Uint16               all;
   struct PARTID_BITS   bit;
};

struct PARTID_REGS {
   union PARTID_REG PARTID; 
};




extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;























struct MODE_BITS {     
	Uint16	PERINTSEL:5;		
	Uint16	rsvd1:2;			
	Uint16	OVRINTE:1;			
	Uint16	PERINTE:1;			
	Uint16	CHINTMODE:1;		
	Uint16	ONESHOT:1;			
	Uint16	CONTINUOUS:1;		
	Uint16	SYNCE:1;			
	Uint16	SYNCSEL:1;			
	Uint16	DATASIZE:1;			
	Uint16	CHINTE:1;			
};

union MODE_REG {
	Uint16 all;
	struct MODE_BITS	bit;
};

struct CONTROL_BITS {     
	Uint16	RUN:1;			
	Uint16	HALT:1;			
	Uint16	SOFTRESET:1;	
	Uint16	PERINTFRC:1;	
	Uint16	PERINTCLR:1;	
	Uint16	SYNCFRC:1;		
	Uint16	SYNCCLR:1;		
	Uint16	ERRCLR:1;		
	Uint16	PERINTFLG:1;	
	Uint16	SYNCFLG:1;		
	Uint16	SYNCERR:1;		
	Uint16	TRANSFERSTS:1;	
	Uint16	BURSTSTS:1;		
	Uint16	RUNSTS:1;		
	Uint16	OVRFLG:1;		
	Uint16	rsvd1:1;		
};

union CONTROL_REG {
	Uint16 all;
	struct CONTROL_BITS	bit;
};

struct DMACTRL_BITS {     
	Uint16	HARDRESET:1;			
	Uint16	PRIORITYRESET:1;		
	Uint16	rsvd1:14;				
};

union DMACTRL_REG {
	Uint16 all;
	struct DMACTRL_BITS	bit;
};

struct DEBUGCTRL_BITS {     
	Uint16	rsvd1:15;		
	Uint16	FREE:1;			
};

union DEBUGCTRL_REG {
	Uint16 all;
	struct DEBUGCTRL_BITS	bit;
};

struct PRIORITYCTRL1_BITS {     
	Uint16	CH1PRIORITY:1;		
	Uint16	rsvd1:15;			
};

union PRIORITYCTRL1_REG {
	Uint16 all;
	struct PRIORITYCTRL1_BITS	bit;
};

struct PRIORITYSTAT_BITS {     
	Uint16	ACTIVESTS:3;		
	Uint16	rsvd1:1;			
	Uint16	ACTIVESTS_SHADOW:3;	
	Uint16	rsvd2:9;			
};

union PRIORITYSTAT_REG {
	Uint16 all;
	struct PRIORITYSTAT_BITS	bit;
};

struct BURST_SIZE_BITS {     
	Uint16	BURSTSIZE:5;		
	Uint16	rsvd1:11;			
};

union BURST_SIZE_REG {
	Uint16 all;
	struct BURST_SIZE_BITS	bit;
};

struct BURST_COUNT_BITS {     
	Uint16	BURSTCOUNT:5;		
	Uint16	rsvd1:11;			
};

union BURST_COUNT_REG {
	Uint16 all;
	struct BURST_COUNT_BITS	bit;
};

struct CH_REGS {
	union	MODE_REG		MODE;					
	union	CONTROL_REG		CONTROL;				
	union	BURST_SIZE_REG	BURST_SIZE;				
	union	BURST_COUNT_REG	BURST_COUNT;			
	int16					SRC_BURST_STEP;			
	int16					DST_BURST_STEP;			
	Uint16					TRANSFER_SIZE;			
	Uint16					TRANSFER_COUNT;			
	int16					SRC_TRANSFER_STEP;		
	int16					DST_TRANSFER_STEP;		
	Uint16					SRC_WRAP_SIZE;			
	Uint16					SRC_WRAP_COUNT;			
	int16					SRC_WRAP_STEP;			
	Uint16					DST_WRAP_SIZE;			
	Uint16					DST_WRAP_COUNT;			
	int16					DST_WRAP_STEP;			
	Uint32					SRC_BEG_ADDR_SHADOW;	
	Uint32					SRC_ADDR_SHADOW;		
	Uint32					SRC_BEG_ADDR_ACTIVE;	
	Uint32					SRC_ADDR_ACTIVE;		
	Uint32					DST_BEG_ADDR_SHADOW;	
	Uint32					DST_ADDR_SHADOW;		
	Uint32					DST_BEG_ADDR_ACTIVE;		
	Uint32					DST_ADDR_ACTIVE;		
};

struct DMA_REGS {
	union	DMACTRL_REG			DMACTRL;		
	union	DEBUGCTRL_REG		DEBUGCTRL;		
	Uint16						rsvd0;			
	Uint16						rsvd1;			
	union	PRIORITYCTRL1_REG	PRIORITYCTRL1;	
	Uint16						rsvd2;			
	union	PRIORITYSTAT_REG	PRIORITYSTAT;	
	Uint16						rsvd3[25];		
	struct CH_REGS             	CH1;            
	struct CH_REGS             	CH2;            
	struct CH_REGS             	CH3;            
	struct CH_REGS             	CH4;            
	struct CH_REGS             	CH5;            
	struct CH_REGS             	CH6;            
};




extern volatile struct DMA_REGS DmaRegs;





















 
 
 

 
struct  CANME_BITS {      
   Uint16      ME0:1;     
   Uint16      ME1:1;     
   Uint16      ME2:1;     
   Uint16      ME3:1;     
   Uint16      ME4:1;     
   Uint16      ME5:1;     
   Uint16      ME6:1;     
   Uint16      ME7:1;     
   Uint16      ME8:1;     
   Uint16      ME9:1;     
   Uint16      ME10:1;    
   Uint16      ME11:1;    
   Uint16      ME12:1;    
   Uint16      ME13:1;    
   Uint16      ME14:1;    
   Uint16      ME15:1;    
   Uint16      ME16:1;    
   Uint16      ME17:1;    
   Uint16      ME18:1;    
   Uint16      ME19:1;    
   Uint16      ME20:1;    
   Uint16      ME21:1;    
   Uint16      ME22:1;    
   Uint16      ME23:1;    
   Uint16      ME24:1;    
   Uint16      ME25:1;    
   Uint16      ME26:1;    
   Uint16      ME27:1;    
   Uint16      ME28:1;    
   Uint16      ME29:1;    
   Uint16      ME30:1;    
   Uint16      ME31:1;    

};

 
union CANME_REG {
   Uint32             all;
   struct CANME_BITS  bit;
};

 
struct  CANMD_BITS {      
   Uint16      MD0:1;     
   Uint16      MD1:1;     
   Uint16      MD2:1;     
   Uint16      MD3:1;     
   Uint16      MD4:1;     
   Uint16      MD5:1;     
   Uint16      MD6:1;     
   Uint16      MD7:1;     
   Uint16      MD8:1;     
   Uint16      MD9:1;     
   Uint16      MD10:1;    
   Uint16      MD11:1;    
   Uint16      MD12:1;    
   Uint16      MD13:1;    
   Uint16      MD14:1;    
   Uint16      MD15:1;    
   Uint16      MD16:1;    
   Uint16      MD17:1;    
   Uint16      MD18:1;    
   Uint16      MD19:1;    
   Uint16      MD20:1;    
   Uint16      MD21:1;    
   Uint16      MD22:1;    
   Uint16      MD23:1;    
   Uint16      MD24:1;    
   Uint16      MD25:1;    
   Uint16      MD26:1;    
   Uint16      MD27:1;    
   Uint16      MD28:1;    
   Uint16      MD29:1;    
   Uint16      MD30:1;    
   Uint16      MD31:1;    

};

 
union CANMD_REG {
   Uint32             all;
   struct CANMD_BITS  bit;
};

 
struct  CANTRS_BITS {      
   Uint16      TRS0:1;     
   Uint16      TRS1:1;     
   Uint16      TRS2:1;     
   Uint16      TRS3:1;     
   Uint16      TRS4:1;     
   Uint16      TRS5:1;     
   Uint16      TRS6:1;     
   Uint16      TRS7:1;     
   Uint16      TRS8:1;     
   Uint16      TRS9:1;     
   Uint16      TRS10:1;    
   Uint16      TRS11:1;    
   Uint16      TRS12:1;    
   Uint16      TRS13:1;    
   Uint16      TRS14:1;    
   Uint16      TRS15:1;    
   Uint16      TRS16:1;    
   Uint16      TRS17:1;    
   Uint16      TRS18:1;    
   Uint16      TRS19:1;    
   Uint16      TRS20:1;    
   Uint16      TRS21:1;    
   Uint16      TRS22:1;    
   Uint16      TRS23:1;    
   Uint16      TRS24:1;    
   Uint16      TRS25:1;    
   Uint16      TRS26:1;    
   Uint16      TRS27:1;    
   Uint16      TRS28:1;    
   Uint16      TRS29:1;    
   Uint16      TRS30:1;    
   Uint16      TRS31:1;    

};

 
union CANTRS_REG {
   Uint32              all;
   struct CANTRS_BITS  bit;
};

 
struct  CANTRR_BITS {      
   Uint16      TRR0:1;     
   Uint16      TRR1:1;     
   Uint16      TRR2:1;     
   Uint16      TRR3:1;     
   Uint16      TRR4:1;     
   Uint16      TRR5:1;     
   Uint16      TRR6:1;     
   Uint16      TRR7:1;     
   Uint16      TRR8:1;     
   Uint16      TRR9:1;     
   Uint16      TRR10:1;    
   Uint16      TRR11:1;    
   Uint16      TRR12:1;    
   Uint16      TRR13:1;    
   Uint16      TRR14:1;    
   Uint16      TRR15:1;    
   Uint16      TRR16:1;    
   Uint16      TRR17:1;    
   Uint16      TRR18:1;    
   Uint16      TRR19:1;    
   Uint16      TRR20:1;    
   Uint16      TRR21:1;    
   Uint16      TRR22:1;    
   Uint16      TRR23:1;    
   Uint16      TRR24:1;    
   Uint16      TRR25:1;    
   Uint16      TRR26:1;    
   Uint16      TRR27:1;    
   Uint16      TRR28:1;    
   Uint16      TRR29:1;    
   Uint16      TRR30:1;    
   Uint16      TRR31:1;    

};

 
union CANTRR_REG {
   Uint32              all;
   struct CANTRR_BITS  bit;
};

 
struct  CANTA_BITS {      
   Uint16      TA0:1;     
   Uint16      TA1:1;     
   Uint16      TA2:1;     
   Uint16      TA3:1;     
   Uint16      TA4:1;     
   Uint16      TA5:1;     
   Uint16      TA6:1;     
   Uint16      TA7:1;     
   Uint16      TA8:1;     
   Uint16      TA9:1;     
   Uint16      TA10:1;    
   Uint16      TA11:1;    
   Uint16      TA12:1;    
   Uint16      TA13:1;    
   Uint16      TA14:1;    
   Uint16      TA15:1;    
   Uint16      TA16:1;    
   Uint16      TA17:1;    
   Uint16      TA18:1;    
   Uint16      TA19:1;    
   Uint16      TA20:1;    
   Uint16      TA21:1;    
   Uint16      TA22:1;    
   Uint16      TA23:1;    
   Uint16      TA24:1;    
   Uint16      TA25:1;    
   Uint16      TA26:1;    
   Uint16      TA27:1;    
   Uint16      TA28:1;    
   Uint16      TA29:1;    
   Uint16      TA30:1;    
   Uint16      TA31:1;    

};

 
union CANTA_REG {
   Uint32             all;
   struct CANTA_BITS  bit;
};

 
struct  CANAA_BITS {      
   Uint16      AA0:1;     
   Uint16      AA1:1;     
   Uint16      AA2:1;     
   Uint16      AA3:1;     
   Uint16      AA4:1;     
   Uint16      AA5:1;     
   Uint16      AA6:1;     
   Uint16      AA7:1;     
   Uint16      AA8:1;     
   Uint16      AA9:1;     
   Uint16      AA10:1;    
   Uint16      AA11:1;    
   Uint16      AA12:1;    
   Uint16      AA13:1;    
   Uint16      AA14:1;    
   Uint16      AA15:1;    
   Uint16      AA16:1;    
   Uint16      AA17:1;    
   Uint16      AA18:1;    
   Uint16      AA19:1;    
   Uint16      AA20:1;    
   Uint16      AA21:1;    
   Uint16      AA22:1;    
   Uint16      AA23:1;    
   Uint16      AA24:1;    
   Uint16      AA25:1;    
   Uint16      AA26:1;    
   Uint16      AA27:1;    
   Uint16      AA28:1;    
   Uint16      AA29:1;    
   Uint16      AA30:1;    
   Uint16      AA31:1;    

};

 
union CANAA_REG {
   Uint32             all;
   struct CANAA_BITS  bit;
};

 
struct  CANRMP_BITS {      
   Uint16      RMP0:1;     
   Uint16      RMP1:1;     
   Uint16      RMP2:1;     
   Uint16      RMP3:1;     
   Uint16      RMP4:1;     
   Uint16      RMP5:1;     
   Uint16      RMP6:1;     
   Uint16      RMP7:1;     
   Uint16      RMP8:1;     
   Uint16      RMP9:1;     
   Uint16      RMP10:1;    
   Uint16      RMP11:1;    
   Uint16      RMP12:1;    
   Uint16      RMP13:1;    
   Uint16      RMP14:1;    
   Uint16      RMP15:1;    
   Uint16      RMP16:1;    
   Uint16      RMP17:1;    
   Uint16      RMP18:1;    
   Uint16      RMP19:1;    
   Uint16      RMP20:1;    
   Uint16      RMP21:1;    
   Uint16      RMP22:1;    
   Uint16      RMP23:1;    
   Uint16      RMP24:1;    
   Uint16      RMP25:1;    
   Uint16      RMP26:1;    
   Uint16      RMP27:1;    
   Uint16      RMP28:1;    
   Uint16      RMP29:1;    
   Uint16      RMP30:1;    
   Uint16      RMP31:1;    

};

 
union CANRMP_REG {
   Uint32              all;
   struct CANRMP_BITS  bit;
};

 
struct  CANRML_BITS {      
   Uint16      RML0:1;     
   Uint16      RML1:1;     
   Uint16      RML2:1;     
   Uint16      RML3:1;     
   Uint16      RML4:1;     
   Uint16      RML5:1;     
   Uint16      RML6:1;     
   Uint16      RML7:1;     
   Uint16      RML8:1;     
   Uint16      RML9:1;     
   Uint16      RML10:1;    
   Uint16      RML11:1;    
   Uint16      RML12:1;    
   Uint16      RML13:1;    
   Uint16      RML14:1;    
   Uint16      RML15:1;    
   Uint16      RML16:1;    
   Uint16      RML17:1;    
   Uint16      RML18:1;    
   Uint16      RML19:1;    
   Uint16      RML20:1;    
   Uint16      RML21:1;    
   Uint16      RML22:1;    
   Uint16      RML23:1;    
   Uint16      RML24:1;    
   Uint16      RML25:1;    
   Uint16      RML26:1;    
   Uint16      RML27:1;    
   Uint16      RML28:1;    
   Uint16      RML29:1;    
   Uint16      RML30:1;    
   Uint16      RML31:1;    

};

 
union CANRML_REG {
   Uint32              all;
   struct CANRML_BITS  bit;
};

 
struct  CANRFP_BITS {      
   Uint16      RFP0:1;     
   Uint16      RFP1:1;     
   Uint16      RFP2:1;     
   Uint16      RFP3:1;     
   Uint16      RFP4:1;     
   Uint16      RFP5:1;     
   Uint16      RFP6:1;     
   Uint16      RFP7:1;     
   Uint16      RFP8:1;     
   Uint16      RFP9:1;     
   Uint16      RFP10:1;    
   Uint16      RFP11:1;    
   Uint16      RFP12:1;    
   Uint16      RFP13:1;    
   Uint16      RFP14:1;    
   Uint16      RFP15:1;    
   Uint16      RFP16:1;    
   Uint16      RFP17:1;    
   Uint16      RFP18:1;    
   Uint16      RFP19:1;    
   Uint16      RFP20:1;    
   Uint16      RFP21:1;    
   Uint16      RFP22:1;    
   Uint16      RFP23:1;    
   Uint16      RFP24:1;    
   Uint16      RFP25:1;    
   Uint16      RFP26:1;    
   Uint16      RFP27:1;    
   Uint16      RFP28:1;    
   Uint16      RFP29:1;    
   Uint16      RFP30:1;    
   Uint16      RFP31:1;    

};

 
union CANRFP_REG {
   Uint32              all;
   struct CANRFP_BITS  bit;
};

 
struct  CANGAM_BITS {   
   Uint16 GAM150:16;    
   Uint16 GAM2816:13;   
   Uint16 rsvd:2;       
   Uint16 AMI:1;        
};

 
union CANGAM_REG {
   Uint32              all;
   struct CANGAM_BITS  bit;
};


 
struct  CANMC_BITS {       
   Uint16      MBNR:5;     
   Uint16      SRES:1;     
   Uint16      STM:1;      
   Uint16      ABO:1;      
   Uint16      CDR:1;      
   Uint16      WUBA:1;     
   Uint16      DBO:1;      
   Uint16      PDR:1;      
   Uint16      CCR:1;      
   Uint16      SCB:1;      
   Uint16      TCC:1;      
   Uint16      MBCC:1;     
   Uint16      SUSP:1;     
   Uint16      rsvd:15;    
};

 
union CANMC_REG {
   Uint32             all;
   struct CANMC_BITS  bit;
};

 
struct  CANBTC_BITS {  
   Uint16  TSEG2REG:3; 
   Uint16  TSEG1REG:4; 
   Uint16  SAM:1;      
   Uint16  SJWREG:2;   
   Uint16  rsvd1:6;    
   Uint16  BRPREG:8;   
   Uint16  rsvd2:8;    
};

 
union CANBTC_REG {
   Uint32              all;
   struct CANBTC_BITS  bit;
};

 
struct  CANES_BITS {    
   Uint16   TM:1;       
   Uint16   RM:1;       
   Uint16   rsvd1:1;    
   Uint16   PDA:1;      
   Uint16   CCE:1;      
   Uint16   SMA:1;      
   Uint16   rsvd2:10;   
   Uint16   EW:1;       
   Uint16   EP:1;       
   Uint16   BO:1;       
   Uint16   ACKE:1;     
   Uint16   SE:1;       
   Uint16   CRCE:1;     
   Uint16   SA1:1;      
   Uint16   BE:1;       
   Uint16   FE:1;       
   Uint16   rsvd3:7;    
};

 
union CANES_REG {
   Uint32             all;
   struct CANES_BITS  bit;
};


 
struct  CANTEC_BITS {  
   Uint16 TEC:8;       
   Uint16 rsvd1:8;     
   Uint16 rsvd2:16;    
};

 
union CANTEC_REG {
   Uint32              all;
   struct CANTEC_BITS  bit;
};

 
struct  CANREC_BITS {  
   Uint16 REC:8;       
   Uint16 rsvd1:8;     
   Uint16 rsvd2:16;    
};

 
union CANREC_REG {
   Uint32              all;
   struct CANREC_BITS  bit;
};

 
struct  CANGIF0_BITS {  
   Uint16   MIV0:5;     
   Uint16   rsvd1:3;    
   Uint16   WLIF0:1;    
   Uint16   EPIF0:1;    
   Uint16   BOIF0:1;    
   Uint16   RMLIF0:1;   
   Uint16   WUIF0:1;    
   Uint16   WDIF0:1;    
   Uint16   AAIF0:1;    
   Uint16   GMIF0:1;    
   Uint16   TCOF0:1;    
   Uint16   MTOF0:1;    
   Uint16   rsvd2:14;   
};

 
union CANGIF0_REG {
   Uint32               all;
   struct CANGIF0_BITS  bit;
};

 
struct  CANGIM_BITS { 
   Uint16  I0EN:1;    
   Uint16  I1EN:1;    
   Uint16  GIL:1;     
   Uint16  rsvd1:5;   
   Uint16  WLIM:1;    
   Uint16  EPIM:1;    
   Uint16  BOIM:1;    
   Uint16  RMLIM:1;   
   Uint16  WUIM:1;    
   Uint16  WDIM:1;    
   Uint16  AAIM:1;    
   Uint16  rsvd2:1;   
   Uint16  TCOM:1;    
   Uint16  MTOM:1;    
   Uint16  rsvd3:14;  
};

 
union CANGIM_REG {
   Uint32              all;
   struct CANGIM_BITS  bit;
};


 
struct  CANGIF1_BITS {     
   Uint16      MIV1:5;     
   Uint16      rsvd1:3;    
   Uint16      WLIF1:1;    
   Uint16      EPIF1:1;    
   Uint16      BOIF1:1;    
   Uint16      RMLIF1:1;   
   Uint16      WUIF1:1;    
   Uint16      WDIF1:1;    
   Uint16      AAIF1:1;    
   Uint16      GMIF1:1;    
   Uint16      TCOF1:1;    
   Uint16      MTOF1:1;    
   Uint16      rsvd2:14;   
};

 
union CANGIF1_REG {
   Uint32               all;
   struct CANGIF1_BITS  bit;
};


 
struct  CANMIM_BITS {      
   Uint16      MIM0:1;     
   Uint16      MIM1:1;     
   Uint16      MIM2:1;     
   Uint16      MIM3:1;     
   Uint16      MIM4:1;     
   Uint16      MIM5:1;     
   Uint16      MIM6:1;     
   Uint16      MIM7:1;     
   Uint16      MIM8:1;     
   Uint16      MIM9:1;     
   Uint16      MIM10:1;    
   Uint16      MIM11:1;    
   Uint16      MIM12:1;    
   Uint16      MIM13:1;    
   Uint16      MIM14:1;    
   Uint16      MIM15:1;    
   Uint16      MIM16:1;    
   Uint16      MIM17:1;    
   Uint16      MIM18:1;    
   Uint16      MIM19:1;    
   Uint16      MIM20:1;    
   Uint16      MIM21:1;    
   Uint16      MIM22:1;    
   Uint16      MIM23:1;    
   Uint16      MIM24:1;    
   Uint16      MIM25:1;    
   Uint16      MIM26:1;    
   Uint16      MIM27:1;    
   Uint16      MIM28:1;    
   Uint16      MIM29:1;    
   Uint16      MIM30:1;    
   Uint16      MIM31:1;    

};

 
union CANMIM_REG {
   Uint32              all;
   struct CANMIM_BITS  bit;
};

 
struct  CANMIL_BITS {      
   Uint16      MIL0:1;     
   Uint16      MIL1:1;     
   Uint16      MIL2:1;     
   Uint16      MIL3:1;     
   Uint16      MIL4:1;     
   Uint16      MIL5:1;     
   Uint16      MIL6:1;     
   Uint16      MIL7:1;     
   Uint16      MIL8:1;     
   Uint16      MIL9:1;     
   Uint16      MIL10:1;    
   Uint16      MIL11:1;    
   Uint16      MIL12:1;    
   Uint16      MIL13:1;    
   Uint16      MIL14:1;    
   Uint16      MIL15:1;    
   Uint16      MIL16:1;    
   Uint16      MIL17:1;    
   Uint16      MIL18:1;    
   Uint16      MIL19:1;    
   Uint16      MIL20:1;    
   Uint16      MIL21:1;    
   Uint16      MIL22:1;    
   Uint16      MIL23:1;    
   Uint16      MIL24:1;    
   Uint16      MIL25:1;    
   Uint16      MIL26:1;    
   Uint16      MIL27:1;    
   Uint16      MIL28:1;    
   Uint16      MIL29:1;    
   Uint16      MIL30:1;    
   Uint16      MIL31:1;    

};

 
union CANMIL_REG {
   Uint32              all;
   struct CANMIL_BITS  bit;
};


 
struct  CANOPC_BITS {      
   Uint16      OPC0:1;     
   Uint16      OPC1:1;     
   Uint16      OPC2:1;     
   Uint16      OPC3:1;     
   Uint16      OPC4:1;     
   Uint16      OPC5:1;     
   Uint16      OPC6:1;     
   Uint16      OPC7:1;     
   Uint16      OPC8:1;     
   Uint16      OPC9:1;     
   Uint16      OPC10:1;    
   Uint16      OPC11:1;    
   Uint16      OPC12:1;    
   Uint16      OPC13:1;    
   Uint16      OPC14:1;    
   Uint16      OPC15:1;    
   Uint16      OPC16:1;    
   Uint16      OPC17:1;    
   Uint16      OPC18:1;    
   Uint16      OPC19:1;    
   Uint16      OPC20:1;    
   Uint16      OPC21:1;    
   Uint16      OPC22:1;    
   Uint16      OPC23:1;    
   Uint16      OPC24:1;    
   Uint16      OPC25:1;    
   Uint16      OPC26:1;    
   Uint16      OPC27:1;    
   Uint16      OPC28:1;    
   Uint16      OPC29:1;    
   Uint16      OPC30:1;    
   Uint16      OPC31:1;    

};

 
union CANOPC_REG {
   Uint32              all;
   struct CANOPC_BITS  bit;
};


 
struct  CANTIOC_BITS { 
   Uint16  rsvd1:3;    
   Uint16  TXFUNC:1;   
   Uint16  rsvd2:12;   
   Uint16  rsvd3:16;   
};

 
union CANTIOC_REG {
   Uint32               all;
   struct CANTIOC_BITS  bit;
};

 
struct  CANRIOC_BITS { 
   Uint16  rsvd1:3;    
   Uint16  RXFUNC:1;   
   Uint16  rsvd2:12;   
   Uint16  rsvd3:16;   
};

 
union CANRIOC_REG {
   Uint32               all;
   struct CANRIOC_BITS  bit;
};


 
struct  CANTOC_BITS {      
   Uint16      TOC0:1;     
   Uint16      TOC1:1;     
   Uint16      TOC2:1;     
   Uint16      TOC3:1;     
   Uint16      TOC4:1;     
   Uint16      TOC5:1;     
   Uint16      TOC6:1;     
   Uint16      TOC7:1;     
   Uint16      TOC8:1;     
   Uint16      TOC9:1;     
   Uint16      TOC10:1;    
   Uint16      TOC11:1;    
   Uint16      TOC12:1;    
   Uint16      TOC13:1;    
   Uint16      TOC14:1;    
   Uint16      TOC15:1;    
   Uint16      TOC16:1;    
   Uint16      TOC17:1;    
   Uint16      TOC18:1;    
   Uint16      TOC19:1;    
   Uint16      TOC20:1;    
   Uint16      TOC21:1;    
   Uint16      TOC22:1;    
   Uint16      TOC23:1;    
   Uint16      TOC24:1;    
   Uint16      TOC25:1;    
   Uint16      TOC26:1;    
   Uint16      TOC27:1;    
   Uint16      TOC28:1;    
   Uint16      TOC29:1;    
   Uint16      TOC30:1;    
   Uint16      TOC31:1;    

};

 
union CANTOC_REG {
   Uint32              all;
   struct CANTOC_BITS  bit;
};


 
struct  CANTOS_BITS {            
   Uint16      TOS0:1;     
   Uint16      TOS1:1;     
   Uint16      TOS2:1;     
   Uint16      TOS3:1;     
   Uint16      TOS4:1;     
   Uint16      TOS5:1;     
   Uint16      TOS6:1;     
   Uint16      TOS7:1;     
   Uint16      TOS8:1;     
   Uint16      TOS9:1;     
   Uint16      TOS10:1;    
   Uint16      TOS11:1;    
   Uint16      TOS12:1;    
   Uint16      TOS13:1;    
   Uint16      TOS14:1;    
   Uint16      TOS15:1;    
   Uint16      TOS16:1;    
   Uint16      TOS17:1;    
   Uint16      TOS18:1;    
   Uint16      TOS19:1;    
   Uint16      TOS20:1;    
   Uint16      TOS21:1;    
   Uint16      TOS22:1;    
   Uint16      TOS23:1;    
   Uint16      TOS24:1;    
   Uint16      TOS25:1;    
   Uint16      TOS26:1;    
   Uint16      TOS27:1;    
   Uint16      TOS28:1;    
   Uint16      TOS29:1;    
   Uint16      TOS30:1;    
   Uint16      TOS31:1;    

};

 
union CANTOS_REG {
   Uint32              all;
   struct CANTOS_BITS  bit;
};

 
 
 

struct ECAN_REGS {
   union CANME_REG   CANME;          
   union CANMD_REG   CANMD;          
   union CANTRS_REG  CANTRS;         
   union CANTRR_REG  CANTRR;         
   union CANTA_REG   CANTA;          
   union CANAA_REG   CANAA;          
   union CANRMP_REG  CANRMP;         
   union CANRML_REG  CANRML;         
   union CANRFP_REG  CANRFP;         
   union CANGAM_REG  CANGAM;         
   union CANMC_REG   CANMC;          
   union CANBTC_REG  CANBTC;         
   union CANES_REG   CANES;          
   union CANTEC_REG  CANTEC;         
   union CANREC_REG  CANREC;         
   union CANGIF0_REG CANGIF0;        
   union CANGIM_REG  CANGIM;         
   union CANGIF1_REG CANGIF1;        
   union CANMIM_REG  CANMIM;         
   union CANMIL_REG  CANMIL;         
   union CANOPC_REG  CANOPC;         
   union CANTIOC_REG CANTIOC;        
   union CANRIOC_REG CANRIOC;        
   Uint32            CANTSC;         
   union CANTOC_REG  CANTOC;         
   union CANTOS_REG  CANTOS;         

};

 
 
 

 
struct  CANMSGID_BITS {        
   Uint16      EXTMSGID_L:16;  
   Uint16      EXTMSGID_H:2;   
   Uint16      STDMSGID:11;    
   Uint16      AAM:1;          
   Uint16      AME:1;          
   Uint16      IDE:1;          

};

 
union CANMSGID_REG {
   Uint32                all;
   struct CANMSGID_BITS  bit;
};

 
struct  CANMSGCTRL_BITS {     
   Uint16 DLC:4;          
   Uint16 RTR:1;          
   Uint16 rsvd1:3;        
   Uint16 TPL:5;          
   Uint16 rsvd2:3;        
   Uint16 rsvd3:16;       
};

 
union CANMSGCTRL_REG {
   Uint32                  all;
   struct CANMSGCTRL_BITS  bit;
};

 
struct  CANMDL_WORDS {      
   Uint16      LOW_WORD:16; 
   Uint16      HI_WORD:16;  
};

 
struct  CANMDL_BYTES {      
   Uint16      BYTE3:8;     
   Uint16      BYTE2:8;     
   Uint16      BYTE1:8;     
   Uint16      BYTE0:8;     
};


 

union CANMDL_REG {
   Uint32                all;
   struct CANMDL_WORDS   word;
   struct CANMDL_BYTES   byte;
};



 
struct  CANMDH_WORDS {         
   Uint16      LOW_WORD:16;    
   Uint16      HI_WORD:16;     
};

 
struct  CANMDH_BYTES {      
   Uint16      BYTE7:8;     
   Uint16      BYTE6:8;     
   Uint16      BYTE5:8;     
   Uint16      BYTE4:8;     
};

 
union CANMDH_REG {
   Uint32                  all;
   struct CANMDH_WORDS     word;
   struct CANMDH_BYTES     byte;
};


struct MBOX {
   union CANMSGID_REG     MSGID;
   union CANMSGCTRL_REG   MSGCTRL;
   union CANMDL_REG       MDL;
   union CANMDH_REG       MDH;
};

 
 
 

struct ECAN_MBOXES {
   struct MBOX MBOX0;
   struct MBOX MBOX1;
   struct MBOX MBOX2;
   struct MBOX MBOX3;
   struct MBOX MBOX4;
   struct MBOX MBOX5;
   struct MBOX MBOX6;
   struct MBOX MBOX7;
   struct MBOX MBOX8;
   struct MBOX MBOX9;
   struct MBOX MBOX10;
   struct MBOX MBOX11;
   struct MBOX MBOX12;
   struct MBOX MBOX13;
   struct MBOX MBOX14;
   struct MBOX MBOX15;
   struct MBOX MBOX16;
   struct MBOX MBOX17;
   struct MBOX MBOX18;
   struct MBOX MBOX19;
   struct MBOX MBOX20;
   struct MBOX MBOX21;
   struct MBOX MBOX22;
   struct MBOX MBOX23;
   struct MBOX MBOX24;
   struct MBOX MBOX25;
   struct MBOX MBOX26;
   struct MBOX MBOX27;
   struct MBOX MBOX28;
   struct MBOX MBOX29;
   struct MBOX MBOX30;
   struct MBOX MBOX31;
};

 
struct  CANLAM_BITS {                
   Uint16      LAM_L:16;     
   Uint16      LAM_H:13;     
   Uint16 rsvd1:2;           
   Uint16      LAMI:1;       
};

 
union CANLAM_REG {
   Uint32        all;
   struct CANLAM_BITS  bit;
};


 
 
 

 
struct LAM_REGS {
   union CANLAM_REG LAM0;
   union CANLAM_REG LAM1;
   union CANLAM_REG LAM2;
   union CANLAM_REG LAM3;
   union CANLAM_REG LAM4;
   union CANLAM_REG LAM5;
   union CANLAM_REG LAM6;
   union CANLAM_REG LAM7;
   union CANLAM_REG LAM8;
   union CANLAM_REG LAM9;
   union CANLAM_REG LAM10;
   union CANLAM_REG LAM11;
   union CANLAM_REG LAM12;
   union CANLAM_REG LAM13;
   union CANLAM_REG LAM14;
   union CANLAM_REG LAM15;
   union CANLAM_REG LAM16;
   union CANLAM_REG LAM17;
   union CANLAM_REG LAM18;
   union CANLAM_REG LAM19;
   union CANLAM_REG LAM20;
   union CANLAM_REG LAM21;
   union CANLAM_REG LAM22;
   union CANLAM_REG LAM23;
   union CANLAM_REG LAM24;
   union CANLAM_REG LAM25;
   union CANLAM_REG LAM26;
   union CANLAM_REG LAM27;
   union CANLAM_REG LAM28;
   union CANLAM_REG LAM29;
   union CANLAM_REG LAM30;
   union CANLAM_REG LAM31;
};

 

struct MOTS_REGS {
   Uint32 MOTS0;
   Uint32 MOTS1;
   Uint32 MOTS2;
   Uint32 MOTS3;
   Uint32 MOTS4;
   Uint32 MOTS5;
   Uint32 MOTS6;
   Uint32 MOTS7;
   Uint32 MOTS8;
   Uint32 MOTS9;
   Uint32 MOTS10;
   Uint32 MOTS11;
   Uint32 MOTS12;
   Uint32 MOTS13;
   Uint32 MOTS14;
   Uint32 MOTS15;
   Uint32 MOTS16;
   Uint32 MOTS17;
   Uint32 MOTS18;
   Uint32 MOTS19;
   Uint32 MOTS20;
   Uint32 MOTS21;
   Uint32 MOTS22;
   Uint32 MOTS23;
   Uint32 MOTS24;
   Uint32 MOTS25;
   Uint32 MOTS26;
   Uint32 MOTS27;
   Uint32 MOTS28;
   Uint32 MOTS29;
   Uint32 MOTS30;
   Uint32 MOTS31;
};

 

struct MOTO_REGS {
   Uint32 MOTO0;
   Uint32 MOTO1;
   Uint32 MOTO2;
   Uint32 MOTO3;
   Uint32 MOTO4;
   Uint32 MOTO5;
   Uint32 MOTO6;
   Uint32 MOTO7;
   Uint32 MOTO8;
   Uint32 MOTO9;
   Uint32 MOTO10;
   Uint32 MOTO11;
   Uint32 MOTO12;
   Uint32 MOTO13;
   Uint32 MOTO14;
   Uint32 MOTO15;
   Uint32 MOTO16;
   Uint32 MOTO17;
   Uint32 MOTO18;
   Uint32 MOTO19;
   Uint32 MOTO20;
   Uint32 MOTO21;
   Uint32 MOTO22;
   Uint32 MOTO23;
   Uint32 MOTO24;
   Uint32 MOTO25;
   Uint32 MOTO26;
   Uint32 MOTO27;
   Uint32 MOTO28;
   Uint32 MOTO29;
   Uint32 MOTO30;
   Uint32 MOTO31;
};





extern volatile struct ECAN_REGS ECanaRegs;
extern volatile struct ECAN_MBOXES ECanaMboxes;
extern volatile struct LAM_REGS ECanaLAMRegs;
extern volatile struct MOTO_REGS ECanaMOTORegs;
extern volatile struct MOTS_REGS ECanaMOTSRegs;























struct ECCTL1_BITS {     
	Uint16	CAP1POL:1;			
	Uint16	CTRRST1:1;			
	Uint16	CAP2POL:1;			
	Uint16	CTRRST2:1;			
	Uint16	CAP3POL:1;			
	Uint16	CTRRST3:1;			
	Uint16	CAP4POL:1;			
	Uint16	CTRRST4:1;			
	Uint16	CAPLDEN:1;			
	Uint16	PRESCALE:5;			
	Uint16	FREE_SOFT:2;		
};

union ECCTL1_REG {
	Uint16 all;
	struct ECCTL1_BITS	bit;
};

struct ECCTL2_BITS {     
	Uint16	CONT_ONESHT:1;		
	Uint16	STOP_WRAP:2;		
	Uint16	REARM:1;			
	Uint16	TSCTRSTOP:1;		
	Uint16	SYNCI_EN:1;			
	Uint16	SYNCO_SEL:2;		
	Uint16	SWSYNC:1;			
	Uint16	CAP_APWM:1;			
	Uint16	APWMPOL:1;			
	Uint16	rsvd1:5;			
};

union ECCTL2_REG {
	Uint16 all;
	struct ECCTL2_BITS	bit;
};

struct ECEINT_BITS {     
	Uint16	rsvd1:1;			
	Uint16	CEVT1:1;			
	Uint16	CEVT2:1;			
	Uint16	CEVT3:1;			
	Uint16	CEVT4:1;			
	Uint16	CTROVF:1;			
	Uint16	CTR_EQ_PRD:1;		
	Uint16	CTR_EQ_CMP:1;		
	Uint16	rsvd2:8;			
};

union ECEINT_REG {
	Uint16 all;
	struct ECEINT_BITS	bit;
};


struct ECFLG_BITS {     
	Uint16	INT:1;				
	Uint16	CEVT1:1;			
	Uint16	CEVT2:1;			
	Uint16	CEVT3:1;			
	Uint16	CEVT4:1;			
	Uint16	CTROVF:1;			
	Uint16	CTR_EQ_PRD:1;		
	Uint16	CTR_EQ_CMP:1;		
	Uint16	rsvd1:8;			
};

union ECFLG_REG {
	Uint16 all;
	struct ECFLG_BITS	bit;
};

struct ECAP_REGS {
	Uint32				TSCTR;		
	Uint32				CTRPHS;		
	Uint32				CAP1;		
	Uint32				CAP2;		
	Uint32				CAP3;		
	Uint32				CAP4;		
	Uint16				rsvd1[8];	
	union	ECCTL1_REG	ECCTL1;		
	union	ECCTL2_REG	ECCTL2;		
	union	ECEINT_REG	ECEINT;		
	union	ECFLG_REG	ECFLG;		
	union	ECFLG_REG	ECCLR;		
	union	ECEINT_REG	ECFRC;		
	Uint16				rsvd2[6];	
};




extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;























struct TBCTL_BITS {     
	Uint16	CTRMODE:2;			
	Uint16	PHSEN:1;			
	Uint16	PRDLD:1;			
	Uint16	SYNCOSEL:2;			
	Uint16	SWFSYNC:1;			
	Uint16	HSPCLKDIV:3;		
	Uint16	CLKDIV:3;			
	Uint16	PHSDIR:1;			
	Uint16	FREE_SOFT:2;		
};

union TBCTL_REG {
	Uint16 all;
	struct TBCTL_BITS	bit;
};

struct TBSTS_BITS {     
	Uint16	CTRDIR:1;			
	Uint16	SYNCI:1;			
	Uint16	CTRMAX:1;			
	Uint16	rsvd1:13;			
};

union TBSTS_REG {
	Uint16 all;
	struct TBSTS_BITS	bit;
};

struct CMPCTL_BITS {     
	Uint16	LOADAMODE:2;		
	Uint16	LOADBMODE:2;		
	Uint16	SHDWAMODE:1;		
	Uint16	rsvd1:1;			
	Uint16	SHDWBMODE:1;		
	Uint16	rsvd2:1;			
	Uint16	SHDWAFULL:1;		
	Uint16	SHDWBFULL:1;		
    Uint16 rsvd3:6;            
};

union CMPCTL_REG {
	Uint16 all;
	struct CMPCTL_BITS	bit;
};

struct AQCTL_BITS {     
	Uint16	ZRO:2;			
	Uint16	PRD:2;			
	Uint16	CAU:2;			
	Uint16	CAD:2;			
	Uint16	CBU:2;			
	Uint16	CBD:2;			
	Uint16	rsvd1:4;		
};

union AQCTL_REG {
	Uint16 all;
	struct AQCTL_BITS	bit;
};

struct AQSFRC_BITS {     
	Uint16	ACTSFA:2;			
	Uint16	OTSFA:1;			
	Uint16	ACTSFB:2;			
	Uint16	OTSFB:1;			
	Uint16	RLDCSF:2;			
	Uint16	rsvd1:8;			
};

union AQSFRC_REG {
	Uint16 all;
	struct AQSFRC_BITS	bit;
};

struct AQCSFRC_BITS {     
	Uint16	CSFA:2;			
	Uint16	CSFB:2;			
	Uint16	rsvd1:12;		
};

union AQCSFRC_REG {
	Uint16 all;
	struct AQCSFRC_BITS	bit;
};

struct DBCTL_BITS {     
	Uint16	OUT_MODE:2;			
	Uint16	POLSEL:2;			
	Uint16	IN_MODE:2;			
	Uint16	rsvd1:9;			
	Uint16	HALFCYCLE:1;		
};

union DBCTL_REG {
	Uint16 all;
	struct DBCTL_BITS	bit;
};

struct TZSEL_BITS {     
	Uint16	CBC1:1;			
	Uint16	CBC2:1;			
	Uint16	CBC3:1;			
	Uint16	CBC4:1;			
	Uint16	CBC5:1;			
	Uint16	CBC6:1;			
	Uint16	DCAEVT2:1;		
	Uint16	DCBEVT2:1;		
	Uint16	OSHT1:1;		
	Uint16	OSHT2:1;		
	Uint16	OSHT3:1;		
	Uint16	OSHT4:1;		
	Uint16	OSHT5:1;		
	Uint16	OSHT6:1;		
	Uint16	DCAEVT1:1;		
	Uint16	DCBEVT1:1;		
};

union TZSEL_REG {
	Uint16 all;
	struct TZSEL_BITS	bit;
};

struct TZDCSEL_BITS {     
	Uint16	DCAEVT1:3;			
	Uint16	DCAEVT2:3;			
	Uint16	DCBEVT1:3;			
	Uint16	DCBEVT2:3;			
	Uint16	rsvd1:4;			
};

union TZDCSEL_REG {
	Uint16 all;
	struct TZDCSEL_BITS	bit;
};

struct TZCTL_BITS {     
	Uint16	TZA:2;			
	Uint16	TZB:2;			
	Uint16	DCAEVT1:2;		
	Uint16	DCAEVT2:2;		
	Uint16	DCBEVT1:2;		
	Uint16	DCBEVT2:2;		
	Uint16	rsvd1:4;		
};

union TZCTL_REG {
	Uint16 all;
	struct TZCTL_BITS	bit;
};

struct TZEINT_BITS {     
	Uint16	rsvd1:1;		
	Uint16	CBC:1;			
	Uint16	OST:1;			
	Uint16	DCAEVT1:1;		
	Uint16	DCAEVT2:1;		
	Uint16	DCBEVT1:1;		
	Uint16	DCBEVT2:1;		
	Uint16	rsvd2:9;		
};

union TZEINT_REG {
	Uint16 all;
	struct TZEINT_BITS	bit;
};

struct TZFLG_BITS {     
	Uint16	INT:1;			
	Uint16	CBC:1;			
	Uint16	OST:1;			
	Uint16	DCAEVT1:1;		
	Uint16	DCAEVT2:1;		
	Uint16	DCBEVT1:1;		
	Uint16	DCBEVT2:1;		
	Uint16	rsvd1:9;		
};

union TZFLG_REG {
	Uint16 all;
	struct TZFLG_BITS	bit;
};

struct TZCLR_BITS {     
	Uint16	INT:1;			
	Uint16	CBC:1;			
	Uint16	OST:1;			
	Uint16	DCAEVT1:1;		
	Uint16	DCAEVT2:1;		
	Uint16	DCBEVT1:1;		
	Uint16	DCBEVT2:1;		
	Uint16	rsvd1:9;		
};

union TZCLR_REG {
	Uint16 all;
	struct TZCLR_BITS	bit;
};

struct TZFRC_BITS {     
	Uint16	rsvd1:1;		
	Uint16	CBC:1;			
	Uint16	OST:1;			
	Uint16	DCAEVT1:1;		
	Uint16	DCAEVT2:1;		
	Uint16	DCBEVT1:1;		
	Uint16	DCBEVT2:1;		
	Uint16	rsvd2:9;		
};

union TZFRC_REG {
	Uint16 all;
	struct TZFRC_BITS	bit;
};

struct ETSEL_BITS {     
	Uint16	INTSEL:3;			
	Uint16	INTEN:1;			
	Uint16	rsvd1:4;			
	Uint16	SOCASEL:3;			
	Uint16	SOCAEN:1;			
	Uint16	SOCBSEL:3;			
	Uint16	SOCBEN:1;			
};

union ETSEL_REG {
	Uint16 all;
	struct ETSEL_BITS	bit;
};

struct ETPS_BITS {     
	Uint16	INTPRD:2;			
	Uint16	INTCNT:2;			
	Uint16	rsvd1:4;			
	Uint16	SOCAPRD:2;			
	Uint16	SOCACNT:2;			
	Uint16	SOCBPRD:2;			
	Uint16	SOCBCNT:2;			
};

union ETPS_REG {
	Uint16 all;
	struct ETPS_BITS	bit;
};

struct ETFLG_BITS {     
	Uint16	INT:1;			
	Uint16	rsvd1:1;		
	Uint16	SOCA:1;			
	Uint16	SOCB:1;			
	Uint16	rsvd2:12;		
};

union ETFLG_REG {
	Uint16 all;
	struct ETFLG_BITS	bit;
};

struct ETCLR_BITS {     
	Uint16	INT:1;			
	Uint16	rsvd1:1;		
	Uint16	SOCA:1;			
	Uint16	SOCB:1;			
	Uint16	rsvd2:12;		
};

union ETCLR_REG {
	Uint16 all;
	struct ETCLR_BITS	bit;
};

struct ETFRC_BITS {     
	Uint16	INT:1;			
	Uint16	rsvd1:1;		
	Uint16	SOCA:1;			
	Uint16	SOCB:1;			
	Uint16	rsvd2:12;		
};

union ETFRC_REG {
	Uint16 all;
	struct ETFRC_BITS	bit;
};

struct PCCTL_BITS {     
	Uint16	CHPEN:1;			
	Uint16	OSHTWTH:4;			
	Uint16	CHPFREQ:3;			
	Uint16	CHPDUTY:3;			
	Uint16	rsvd1:5;			
};

union PCCTL_REG {
	Uint16 all;
	struct PCCTL_BITS	bit;
};

struct HRCNFG_BITS {     
	Uint16	EDGMODE:2;			
	Uint16	CTLMODE:1;			
	Uint16	HRLOAD:2;			
	Uint16	SELOUTB:1;			
	Uint16	AUTOCONV:1;			
	Uint16	SWAPAB:1;			
	Uint16	rsvd1:8;			
};

union HRCNFG_REG {
	Uint16 all;
	struct HRCNFG_BITS	bit;
};

struct HRPCTL_BITS {     
	Uint16	HRPE:1;				
	Uint16	rsvd1:1;			
	Uint16	TBPHSHRLOADE:1;		
	Uint16	rsvd2:13;			
};

union HRPCTL_REG {
	Uint16 all;
	struct HRPCTL_BITS	bit;
};

struct DCTRIPSEL_BITS {     
	Uint16	DCAHCOMPSEL:4;			
	Uint16	DCALCOMPSEL:4;			
	Uint16	DCBHCOMPSEL:4;			
	Uint16	DCBLCOMPSEL:4;			
};

union DCTRIPSEL_REG {
	Uint16 all;
	struct DCTRIPSEL_BITS	bit;
};

struct DCCTL_BITS {     
	Uint16	EVT1SRCSEL:1;			
	Uint16	EVT1FRCSYNCSEL:1;		
	Uint16	EVT1SOCE:1;				
	Uint16	EVT1SYNCE:1;			
	Uint16	rsvd1:4;				
	Uint16	EVT2SRCSEL:1;			
	Uint16	EVT2FRCSYNCSEL:1;		
	Uint16	rsvd2:6;				
};

union DCCTL_REG {
	Uint16 all;
	struct DCCTL_BITS	bit;
};

struct DCFCTL_BITS {     
	Uint16	SRCSEL:2;			
	Uint16	BLANKE:1;			
	Uint16	BLANKINV:1;			
	Uint16	PULSESEL:2;			
	Uint16	rsvd1:10;			
};

union DCFCTL_REG {
	Uint16 all;
	struct DCFCTL_BITS	bit;
};

struct DCCAPCTL_BITS {     
	Uint16	CAPE:1;				
	Uint16	SHDWMODE:1;			
	Uint16	rsvd1:14;			
};

union DCCAPCTL_REG {
	Uint16 all;
	struct DCCAPCTL_BITS	bit;
};

struct TBPHS_HRPWM_REG {   	
   Uint16  TBPHSHR;     	
   Uint16  TBPHS;           
};

union TBPHS_HRPWM_GROUP {
   Uint32                  all;
   struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG {   	
   Uint16  CMPAHR;     	    
   Uint16  CMPA;            
};

union CMPA_HRPWM_GROUP {
   Uint32                 all;
   struct CMPA_HRPWM_REG  half;
};

struct TBPRD_HRPWM_REG {   	
   Uint16  TBPRDHR;     	
   Uint16  TBPRD;           
};

union TBPRD_HRPWM_GROUP {
   Uint32                  all;
   struct TBPRD_HRPWM_REG  half;
};

struct EPWM_REGS {
	union	TBCTL_REG			TBCTL;			
	union	TBSTS_REG			TBSTS;			
	union	TBPHS_HRPWM_GROUP   TBPHS;			
	Uint16						TBCTR;			
	Uint16						TBPRD;			
	Uint16						TBPRDHR;		
	union	CMPCTL_REG			CMPCTL;			
	union	CMPA_HRPWM_GROUP 	CMPA;			
	Uint16						CMPB;			
	union	AQCTL_REG			AQCTLA;			
	union	AQCTL_REG			AQCTLB;			
	union	AQSFRC_REG			AQSFRC;			
	union	AQCSFRC_REG			AQCSFRC;		
	union	DBCTL_REG			DBCTL;			
	Uint16						DBRED;			
	Uint16						DBFED;			
	union	TZSEL_REG			TZSEL;			
	union	TZDCSEL_REG			TZDCSEL;		
	union	TZCTL_REG			TZCTL;			
	union	TZEINT_REG			TZEINT;			
	union	TZFLG_REG			TZFLG;			
	union	TZCLR_REG			TZCLR;			
	union	TZFRC_REG			TZFRC;			
	union	ETSEL_REG			ETSEL;			
	union	ETPS_REG			ETPS;			
	union	ETFLG_REG			ETFLG;			
	union	ETCLR_REG			ETCLR;			
	union	ETFRC_REG			ETFRC;			
	union	PCCTL_REG			PCCTL;			
	Uint16						rsvd1;			
	union	HRCNFG_REG			HRCNFG;			
	Uint16						rsvd2;			
	Uint16						rsvd3;			
	Uint16						rsvd4;			
	Uint16						rsvd5;			
	Uint16						rsvd6;			
	Uint16						HRMSTEP;		
	Uint16						rsvd7;			
	union	HRPCTL_REG			HRPCTL;			
	Uint16						rsvd8;			
	union   TBPRD_HRPWM_GROUP   TBPRDM;     	
    union   CMPA_HRPWM_GROUP    CMPAM;      	
	Uint16						rsvd9[2];		
	union	DCTRIPSEL_REG		DCTRIPSEL;		
	union	DCCTL_REG			DCACTL;			
	union	DCCTL_REG			DCBCTL;			
	union	DCFCTL_REG			DCFCTL;			
	union	DCCAPCTL_REG		DCCAPCTL;		
	Uint16						DCFOFFSET;		
	Uint16						DCFOFFSETCNT;	
	Uint16						DCFWINDOW;		
	Uint16						DCFWINDOWCNT;	
	Uint16						DCCAP;			
	Uint16                      rsvd10[6];
};




extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;
extern volatile struct EPWM_REGS EPwm7Regs;
extern volatile struct EPWM_REGS EPwm8Regs;























struct QDECCTL_BITS {     
	Uint16	rsvd1:5;		
	Uint16	QSP:1;			
	Uint16	QIP:1;			
	Uint16	QBP:1;			
	Uint16	QAP:1;			
	Uint16	IGATE:1;		
	Uint16	SWAP:1;			
	Uint16	XCR:1;			
	Uint16	SPSEL:1;		
	Uint16	SOEN:1;			
	Uint16	QSRC:2;			
};

union QDECCTL_REG {
	Uint16 all;
	struct QDECCTL_BITS	bit;
};

struct QEPCTL_BITS {     
	Uint16	WDE:1;			
	Uint16	UTE:1;			
	Uint16	QCLM:1;			
	Uint16	QPEN:1;			
	Uint16	IEL:2;			
	Uint16	SEL:1;			
	Uint16	SWI:1;			
	Uint16	IEI:2;			
	Uint16	SEI:2;			
	Uint16	PCRM:2;			
	Uint16	FREE_SOFT:2;	
};

union QEPCTL_REG {
	Uint16 all;
	struct QEPCTL_BITS	bit;
};

struct QCAPCTL_BITS {     
	Uint16	UPPS:4;			
	Uint16	CCPS:3;			
	Uint16	rsvd1:8;		
	Uint16	CEN:1;			
};

union QCAPCTL_REG {
	Uint16 all;
	struct QCAPCTL_BITS	bit;
};

struct QPOSCTL_BITS {     
	Uint16	PCSPW:12;		
	Uint16	PCE:1;			
	Uint16	PCPOL:1;		
	Uint16	PCLOAD:1;		
	Uint16	PCSHDW:1;		
};

union QPOSCTL_REG {
	Uint16 all;
	struct QPOSCTL_BITS	bit;
};

struct QEINT_BITS {     
	Uint16	rsvd1:1;		
	Uint16	PCE:1;			
	Uint16	QPE:1;			
	Uint16	QDC:1;			
	Uint16	WTO:1;			
	Uint16	PCU:1;			
	Uint16	PCO:1;			
	Uint16	PCR:1;			
	Uint16	PCM:1;			
	Uint16	SEL:1;			
	Uint16	IEL:1;			
	Uint16	UTO:1;			
	Uint16	rsvd2:4;		
};

union QEINT_REG {
	Uint16 all;
	struct QEINT_BITS	bit;
};

struct QFLG_BITS {     
	Uint16	INT:1;			
	Uint16	PCE:1;			
	Uint16	PHE:1;			
	Uint16	QDC:1;			
	Uint16	WTO:1;			
	Uint16	PCU:1;			
	Uint16	PCO:1;			
	Uint16	PCR:1;			
	Uint16	PCM:1;			
	Uint16	SEL:1;			
	Uint16	IEL:1;			
	Uint16	UTO:1;			
	Uint16	rsvd1:4;		
};

union QFLG_REG {
	Uint16 all;
	struct QFLG_BITS	bit;
};

struct QFRC_BITS {     
	Uint16	rsvd1:1;		
	Uint16	PCE:1;			
	Uint16	PHE:1;			
	Uint16	QDC:1;			
	Uint16	WTO:1;			
	Uint16	PCU:1;			
	Uint16	PCO:1;			
	Uint16	PCR:1;			
	Uint16	PCM:1;			
	Uint16	SEL:1;			
	Uint16	IEL:1;			
	Uint16	UTO:1;			
	Uint16	rsvd2:4;		
};

union QFRC_REG {
	Uint16 all;
	struct QFRC_BITS	bit;
};

struct QEPSTS_BITS {     
	Uint16	PCEF:1;			
	Uint16	FIMF:1;			
	Uint16	CDEF:1;			
	Uint16	COEF:1;			
	Uint16	QDLF:1;			
	Uint16	QDF:1;			
	Uint16	FIDF:1;			
	Uint16	UPEVNT:1;		
	Uint16	rsvd1:8;		
};

union QEPSTS_REG {
	Uint16 all;
	struct QEPSTS_BITS	bit;
};

struct EQEP_REGS {
	Uint32				QPOSCNT;	
	Uint32				QPOSINIT;	
	Uint32				QPOSMAX;	
	Uint32				QPOSCMP;	
	Uint32				QPOSILAT;	
	Uint32				QPOSSLAT;	
	Uint32				QPOSLAT;	
	Uint32				QUTMR;		
	Uint32				QUPRD;		
	Uint16				QWDTMR;		
	Uint16				QWDPRD;		
	union	QDECCTL_REG	QDECCTL;	
	union	QEPCTL_REG	QEPCTL;		
	union	QCAPCTL_REG	QCAPCTL;	
	union	QPOSCTL_REG	QPOSCTL;	
	union	QEINT_REG	QEINT;		
	union	QFLG_REG	QFLG;		
	union	QFLG_REG	QCLR;		
	union	QFRC_REG	QFRC;		
	union	QEPSTS_REG	QEPSTS;		
	Uint16				QCTMR;		
	Uint16				QCPRD;		
	Uint16				QCTMRLAT;	
	Uint16				QCPRDLAT;	
	Uint16				rsvd1;		
};




extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;























struct GPACTRL_BITS {     
	Uint16	QUALPRD0:8;			
	Uint16	QUALPRD1:8;			
	Uint16	QUALPRD2:8;			
	Uint16	QUALPRD3:8;			
};

union GPACTRL_REG {
	Uint32 all;
	struct GPACTRL_BITS	bit;
};

struct GPACTRL2_BITS {	
	Uint16	USB0IOEN:1;		
	Uint16	rsvd1:15;		
};

union GPACTRL2_REG {
	Uint16	all;
	struct GPACTRL2_BITS	bit;
};

struct GPBCTRL_BITS {     
	Uint16	QUALPRD0:8;			
	Uint16	QUALPRD1:8;			
	Uint16	QUALPRD2:8;			
	Uint16	QUALPRD3:8;			
};

union GPBCTRL_REG {
	Uint32 all;
	struct GPBCTRL_BITS	bit;
};

struct GPA1_BITS {     
	Uint16	GPIO0:2;			
	Uint16	GPIO1:2;			
	Uint16	GPIO2:2;			
	Uint16	GPIO3:2;			
	Uint16	GPIO4:2;			
	Uint16	GPIO5:2;			
	Uint16	GPIO6:2;			
	Uint16	GPIO7:2;			
	Uint16	GPIO8:2;			
	Uint16	GPIO9:2;			
	Uint16	GPIO10:2;			
	Uint16	GPIO11:2;			
	Uint16	GPIO12:2;			
	Uint16	GPIO13:2;			
	Uint16	GPIO14:2;			
	Uint16	GPIO15:2;			
};

union GPA1_REG {
	Uint32 all;
	struct GPA1_BITS	bit;
};

struct GPA2_BITS {     
	Uint16	GPIO16:2;			
	Uint16	GPIO17:2;			
	Uint16	GPIO18:2;			
	Uint16	GPIO19:2;			
	Uint16	GPIO20:2;			
	Uint16	GPIO21:2;			
	Uint16	GPIO22:2;			
	Uint16	GPIO23:2;			
	Uint16	GPIO24:2;			
	Uint16	GPIO25:2;			
	Uint16	GPIO26:2;			
	Uint16	GPIO27:2;			
	Uint16	GPIO28:2;			
	Uint16	GPIO29:2;			
	Uint16	GPIO30:2;			
	Uint16	GPIO31:2;			
};

union GPA2_REG {
	Uint32 all;
	struct GPA2_BITS	bit;
};

struct GPB1_BITS {     
	Uint16	GPIO32:2;			
	Uint16	GPIO33:2;			
	Uint16	GPIO34:2;			
	Uint16	GPIO35:2;			
	Uint16	GPIO36:2;			
	Uint16	GPIO37:2;			
	Uint16	GPIO38:2;			
	Uint16	GPIO39:2;			
	Uint16	GPIO40:2;			
	Uint16	GPIO41:2;			
	Uint16	GPIO42:2;			
	Uint16	GPIO43:2;			
	Uint16	GPIO44:2;			
	Uint16	rsvd1:6;			
};

union GPB1_REG {
	Uint32 all;
	struct GPB1_BITS	bit;
};

struct GPB2_BITS {     
	Uint16	rsvd1:4;			
	Uint16	GPIO50:2;			
	Uint16	GPIO51:2;			
	Uint16	GPIO52:2;			
	Uint16	GPIO53:2;			
	Uint16	GPIO54:2;			
	Uint16	GPIO55:2;			
	Uint16	GPIO56:2;			
	Uint16	GPIO57:2;			
	Uint16	GPIO58:2;			
	Uint16	rsvd2:10;			
};

union GPB2_REG {
	Uint32 all;
	struct GPB2_BITS	bit;
};

struct AIO_BITS {     
	Uint16	rsvd1:2;			
	Uint16	rsvd2:2;			
	Uint16	AIO2:2;				
	Uint16	rsvd3:2;			
	Uint16	AIO4:2;				
	Uint16	rsvd4:2;			
	Uint16	AIO6:2;				
	Uint16	rsvd5:2;			
	Uint16	rsvd6:2;			
	Uint16	rsvd7:2;			
	Uint16	AIO10:2;			
	Uint16	rsvd8:2;			
	Uint16	AIO12:2;			
	Uint16	rsvd9:2;			
	Uint16	AIO14:2;			
	Uint16	rsvd10:2;			
};

union AIO_REG {
	Uint32 all;
	struct AIO_BITS	bit;
};

struct GPADAT_BITS {     
	Uint16	GPIO0:1;			
	Uint16	GPIO1:1;			
	Uint16	GPIO2:1;			
	Uint16	GPIO3:1;			
	Uint16	GPIO4:1;			
	Uint16	GPIO5:1;			
	Uint16	GPIO6:1;			
	Uint16	GPIO7:1;			
	Uint16	GPIO8:1;			
	Uint16	GPIO9:1;			
	Uint16	GPIO10:1;			
	Uint16	GPIO11:1;			
	Uint16	GPIO12:1;			
	Uint16	GPIO13:1;			
	Uint16	GPIO14:1;			
	Uint16	GPIO15:1;			
	Uint16	GPIO16:1;			
	Uint16	GPIO17:1;			
	Uint16	GPIO18:1;			
	Uint16	GPIO19:1;			
	Uint16	GPIO20:1;			
	Uint16	GPIO21:1;			
	Uint16	GPIO22:1;			
	Uint16	GPIO23:1;			
	Uint16	GPIO24:1;			
	Uint16	GPIO25:1;			
	Uint16	GPIO26:1;			
	Uint16	GPIO27:1;			
	Uint16	GPIO28:1;			
	Uint16	GPIO29:1;			
	Uint16	GPIO30:1;			
	Uint16	GPIO31:1;			
};

union GPADAT_REG {
	Uint32 all;
	struct GPADAT_BITS	bit;
};

struct GPBDAT_BITS {     
	Uint16	GPIO32:1;			
	Uint16	GPIO33:1;			
	Uint16	GPIO34:1;			
	Uint16	GPIO35:1;			
	Uint16	GPIO36:1;			
	Uint16	GPIO37:1;			
	Uint16	GPIO38:1;			
	Uint16	GPIO39:1;			
	Uint16	GPIO40:1;			
	Uint16	GPIO41:1;			
	Uint16	GPIO42:1;			
	Uint16	GPIO43:1;			
	Uint16	GPIO44:1;			
	Uint16	rsvd1:3;			
	Uint16	rsvd2:2;			
	Uint16	GPIO50:1;			
	Uint16	GPIO51:1;			
	Uint16	GPIO52:1;			
	Uint16	GPIO53:1;			
	Uint16	GPIO54:1;			
	Uint16	GPIO55:1;			
	Uint16	GPIO56:1;			
	Uint16	GPIO57:1;			
	Uint16	GPIO58:1;			
	Uint16	rsvd3:5;			
};

union GPBDAT_REG {
	Uint32 all;
	struct GPBDAT_BITS	bit;
};

struct AIODAT_BITS {     
	Uint16	rsvd1:1;			
	Uint16	rsvd2:1;			
	Uint16	AIO2:1;				
	Uint16	rsvd3:1;			
	Uint16	AIO4:1;				
	Uint16	rsvd4:1;			
	Uint16	AIO6:1;				
	Uint16	rsvd5:1;			
	Uint16	rsvd6:1;			
	Uint16	rsvd7:1;			
	Uint16	AIO10:1;			
	Uint16	rsvd8:1;			
	Uint16	AIO12:1;			
	Uint16	rsvd9:1;			
	Uint16	AIO14:1;			
	Uint16	rsvd10:1;			
	Uint16	rsvd11:16;			
};

union AIODAT_REG {
	Uint32 all;
	struct AIODAT_BITS	bit;
};

struct GPIOXINT_BITS {     
	Uint16	GPIOSEL:5;			
	Uint16	rsvd1:11;			
};

union GPIOXINT_REG {
	Uint16 all;
	struct GPIOXINT_BITS	bit;
};

struct GPIO_CTRL_REGS {
	union	GPACTRL_REG		GPACTRL;	
	union	GPA1_REG		GPAQSEL1;	
	union	GPA2_REG		GPAQSEL2;	
	union	GPA1_REG		GPAMUX1;	
	union	GPA2_REG		GPAMUX2;	
	union	GPADAT_REG		GPADIR;		
	union	GPADAT_REG		GPAPUD;		
	union	GPACTRL2_REG	GPACTRL2;	
	Uint16					rsvd1;		
	union	GPBCTRL_REG		GPBCTRL;	
	union	GPB1_REG		GPBQSEL1;	
	union	GPB2_REG		GPBQSEL2;	
	union	GPB1_REG		GPBMUX1;	
	union	GPB2_REG		GPBMUX2;	
	union	GPBDAT_REG		GPBDIR;		
	union	GPBDAT_REG		GPBPUD;		
	Uint16					rsvd2[24];	
	union	AIO_REG			AIOMUX1;	
	Uint16					rsvd3[2];	
	union	AIODAT_REG		AIODIR;		
	Uint16					rsvd4[4];	
};

struct GPIO_DATA_REGS {
	union	GPADAT_REG		GPADAT;		
	union	GPADAT_REG		GPASET;		
	union	GPADAT_REG		GPACLEAR;	
	union	GPADAT_REG		GPATOGGLE;	
	union	GPBDAT_REG		GPBDAT;		
	union	GPBDAT_REG		GPBSET;		
	union	GPBDAT_REG		GPBCLEAR;	
	union	GPBDAT_REG		GPBTOGGLE;	
	Uint16					rsvd1[8];	
	union	AIODAT_REG		AIODAT;		
	union	AIODAT_REG		AIOSET;		
	union	AIODAT_REG		AIOCLEAR;	
	union	AIODAT_REG		AIOTOGGLE;	
};

struct GPIO_INT_REGS {
	union	GPIOXINT_REG	GPIOXINT1SEL;	
	union	GPIOXINT_REG	GPIOXINT2SEL;	
	union	GPIOXINT_REG	GPIOXINT3SEL;	
	Uint16					rsvd1[5];		
	union	GPADAT_REG		GPIOLPMSEL;		
	Uint16					rsvd2[22];		
};




extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS  GpioIntRegs;

























struct HCCTL_BITS {     
	Uint16	SOFTRESET:1;			
	Uint16	RISEINTE:1;				
	Uint16	FALLINTE:1;				
	Uint16	OVFINTE:1;				
	Uint16	rsvd1:4;				
	Uint16	HCCAPCLKSEL:1;			
	Uint16	rsvd2:7;				
};

union HCCTL_REG {
	Uint16 all;
	struct HCCTL_BITS	bit;
};

struct HCIFR_BITS {     
	Uint16	INT:1;				
	Uint16	RISE:1;				
	Uint16	FALL:1;				
	Uint16	COUNTEROVF:1;		
	Uint16	RISEOVF:1;			
	Uint16	rsvd1:11;			
};

union HCIFR_REG {
	Uint16 all;
	struct HCIFR_BITS	bit;
};

struct HCICLR_BITS {     
	Uint16	INT:1;				
	Uint16	RISE:1;				
	Uint16	FALL:1;				
	Uint16	COUNTEROVF:1;		
	Uint16	RISEOVF:1;			
	Uint16	rsvd1:11;			
};

union HCICLR_REG {
	Uint16 all;
	struct HCICLR_BITS	bit;
};

struct HCIFRC_BITS {     
	Uint16	rsvd1:1;			
	Uint16	RISE:1;				
	Uint16	FALL:1;				
	Uint16	COUNTEROVF:1;		
	Uint16	RISEOVF:1;			
	Uint16	rsvd2:11;			
};

union HCIFRC_REG {
	Uint16 all;
	struct HCIFRC_BITS	bit;
};

struct HRCAP_REGS {
	union	HCCTL_REG			HCCTL;			
	union	HCIFR_REG			HCIFR;			
	union	HCICLR_REG			HCICLR;			
	union	HCIFRC_REG			HCIFRC;			
	Uint16						HCCOUNTER;		
	Uint16						rsvd1[11];		
	Uint16						HCCAPCNTRISE0;	
	Uint16						rsvd2;			
	Uint16						HCCAPCNTFALL0;	
	Uint16						rsvd3;			
	Uint16						rsvd4;			
	Uint16						rsvd5;			
	Uint16						rsvd6[2];		
	Uint16						HCCAPCNTRISE1;	
	Uint16						rsvd7;			
	Uint16						HCCAPCNTFALL1;	
	Uint16						rsvd8;			
	Uint16						rsvd9;			
	Uint16						rsvd10;			
	Uint16						rsvd11;			
    Uint16						rsvd12;			
};




extern volatile struct HRCAP_REGS HRCap1Regs;
extern volatile struct HRCAP_REGS HRCap2Regs;
extern volatile struct HRCAP_REGS HRCap3Regs;
extern volatile struct HRCAP_REGS HRCap4Regs;























struct I2CMDR_BITS {     
	Uint16	BC:3;			
	Uint16	FDF:1;			
	Uint16	STB:1;			
	Uint16	IRS:1;			
	Uint16	DLB:1;			
	Uint16	RM:1;			
	Uint16	XA:1;			
	Uint16	TRX:1;			
	Uint16	MST:1;			
	Uint16	STP:1;			
	Uint16	rsvd1:1;		
	Uint16	STT:1;			
	Uint16	FREE:1;			
	Uint16	NACKMOD:1;		
};

union I2CMDR_REG {
	Uint16 all;
	struct I2CMDR_BITS	bit;
};

struct I2CEMDR_BITS {     
	Uint16	BC:1;			
	Uint16	rsvd1:15;		
};

union I2CEMDR_REG {
	Uint16 all;
	struct I2CEMDR_BITS	bit;
};

struct I2CIER_BITS {     
	Uint16	ARBL:1;			
	Uint16	NACK:1;			
	Uint16	ARDY:1;			
	Uint16	RRDY:1;			
	Uint16	XRDY:1;			
	Uint16	SCD:1;			
	Uint16	AAS:1;			
	Uint16	rsvd1:9;		
};

union I2CIER_REG {
	Uint16 all;
	struct I2CIER_BITS	bit;
};

struct I2CSTR_BITS {     
	Uint16	ARBL:1;			
	Uint16	NACK:1;			
	Uint16	ARDY:1;			
	Uint16	RRDY:1;			
	Uint16	XRDY:1;			
	Uint16	SCD:1;			
	Uint16	rsvd1:2;		
	Uint16	AD0:1;			
	Uint16	AAS:1;			
	Uint16	XSMT:1;			
	Uint16	RSFULL:1;		
	Uint16	BB:1;			
	Uint16	NACKSNT:1;		
	Uint16	SDIR:1;			
	Uint16	rsvd2:1;		
};

union I2CSTR_REG {
	Uint16 all;
	struct I2CSTR_BITS	bit;
};

struct I2CISRC_BITS {     
	Uint16	INTCODE:3;			
	Uint16	rsvd1:5;			
	Uint16	rsvd2:4;			
	Uint16	rsvd3:4;			
};

union I2CISRC_REG {
	Uint16 all;
	struct I2CISRC_BITS	bit;
};

struct I2CPSC_BITS {     
	Uint16	IPSC:8;			
	Uint16	rsvd1:8;		
};

union I2CPSC_REG {
	Uint16 all;
	struct I2CPSC_BITS	bit;
};

struct I2CFFTX_BITS {     
	Uint16	TXFFIL:5;			
	Uint16	TXFFIENA:1;			
	Uint16	TXFFINTCLR:1;		
	Uint16	TXFFINT:1;			
	Uint16	TXFFST:5;			
	Uint16	TXFFRST:1;			
	Uint16	I2CFFEN:1;			
	Uint16	rsvd1:1;			
};

union I2CFFTX_REG {
	Uint16 all;
	struct I2CFFTX_BITS	bit;
};

struct I2CFFRX_BITS {     
	Uint16	RXFFIL:5;			
	Uint16	RXFFIENA:1;			
	Uint16	RXFFINTCLR:1;		
	Uint16	RXFFINT:1;			
	Uint16	RXFFST:5;			
	Uint16	RXFFRST:1;			
	Uint16	rsvd1:2;			
};

union I2CFFRX_REG {
	Uint16 all;
	struct I2CFFRX_BITS	bit;
};

struct I2C_REGS {
	Uint16				I2COAR;		
	union	I2CIER_REG	I2CIER;		
	union	I2CSTR_REG	I2CSTR;		
	Uint16				I2CCLKL;	
	Uint16				I2CCLKH;	
	Uint16				I2CCNT;		
	Uint16				I2CDRR;		
	Uint16				I2CSAR;		
	Uint16				I2CDXR;		
	union	I2CMDR_REG	I2CMDR;		
	union	I2CISRC_REG	I2CISRC;	
	union	I2CEMDR_REG	I2CEMDR;	
	union	I2CPSC_REG	I2CPSC;		
	Uint16				rsvd1[19];	
	union	I2CFFTX_REG	I2CFFTX;	
	union	I2CFFRX_REG	I2CFFRX;	
};




extern volatile struct I2C_REGS I2caRegs;























struct DRR2_BITS {     
	Uint16	HWLB:8;			
	Uint16	HWHB:8;			
};

union DRR2_REG {
	Uint16 all;
	struct DRR2_BITS	bit;
};

struct DRR1_BITS {     
	Uint16	LWLB:8;			
	Uint16	LWHB:8;			
};

union DRR1_REG {
	Uint16 all;
	struct DRR1_BITS	bit;
};

struct DXR2_BITS {     
	Uint16	HWLB:8;			
	Uint16	HWHB:8;			
};

union DXR2_REG {
	Uint16 all;
	struct DXR2_BITS	bit;
};

struct DXR1_BITS {     
	Uint16	LWLB:8;			
	Uint16	LWHB:8;			
};

union DXR1_REG {
	Uint16 all;
	struct DXR1_BITS	bit;
};

struct SPCR2_BITS {     
	Uint16	XRST:1;			
	Uint16	XRDY:1;			
	Uint16	XEMPTY:1;		
	Uint16	XSYNCERR:1;		
	Uint16	XINTM:2;		
	Uint16	GRST:1;			
	Uint16	FRST:1;			
	Uint16	SOFT:1;			
	Uint16	FREE:1;			
	Uint16	rsvd1:6;		
};

union SPCR2_REG {
	Uint16 all;
	struct SPCR2_BITS	bit;
};

struct SPCR1_BITS {     
	Uint16	RRST:1;			
	Uint16	RRDY:1;			
	Uint16	RFULL:1;		
	Uint16	RSYNCERR:1;		
	Uint16	RINTM:2;		
	Uint16	ABIS:1;			
	Uint16	DXENA:1;		
	Uint16	rsvd1:3;		
	Uint16	CLKSTP:2;		
	Uint16	RJUST:2;		
	Uint16	DLB:1;			
};

union SPCR1_REG {
	Uint16 all;
	struct SPCR1_BITS	bit;
};

struct RCR2_BITS {     
	Uint16	RDATDLY:2;			
	Uint16	RFIG:1;				
	Uint16	RCOMPAND:2;			
	Uint16	RWDLEN2:3;			
	Uint16	RFRLEN2:7;			
	Uint16	RPHASE:1;			
};

union RCR2_REG {
	Uint16 all;
	struct RCR2_BITS	bit;
};

struct RCR1_BITS {     
	Uint16	rsvd1:5;			
	Uint16	RWDLEN1:3;			
	Uint16	RFRLEN1:7;			
	Uint16	rsvd2:1;			
};

union RCR1_REG {
	Uint16 all;
	struct RCR1_BITS	bit;
};

struct XCR2_BITS {     
	Uint16	XDATDLY:2;			
	Uint16	XFIG:1;				
	Uint16	XCOMPAND:2;			
	Uint16	XWDLEN2:3;			
	Uint16	XFRLEN2:7;			
	Uint16	XPHASE:1;			
};

union XCR2_REG {
	Uint16 all;
	struct XCR2_BITS	bit;
};

struct XCR1_BITS {     
	Uint16	rsvd1:5;			
	Uint16	XWDLEN1:3;			
	Uint16	XFRLEN1:7;			
	Uint16	rsvd2:1;			
};

union XCR1_REG {
	Uint16 all;
	struct XCR1_BITS	bit;
};

struct SRGR2_BITS {     
	Uint16	FPER:12;			
	Uint16	FSGM:1;				
	Uint16	CLKSM:1;			
	Uint16	rsvd1:1;			
	Uint16	GSYNC:1;			
};

union SRGR2_REG {
	Uint16 all;
	struct SRGR2_BITS	bit;
};

struct SRGR1_BITS {     
	Uint16	CLKGDV:8;		
	Uint16	FWID:8;			
};

union SRGR1_REG {
	Uint16 all;
	struct SRGR1_BITS	bit;
};

struct MCR2_BITS {     
	Uint16	XMCM:2;				
	Uint16	XCBLK:3;			
	Uint16	XPABLK:2;			
	Uint16	XPBBLK:2;			
	Uint16	XMCME:1;			
	Uint16	rsvd1:6;			
};

union MCR2_REG {
	Uint16 all;
	struct MCR2_BITS	bit;
};

struct MCR1_BITS {     
	Uint16	RMCM:1;				
	Uint16	rsvd1:1;			
	Uint16	RCBLK:3;			
	Uint16	RPABLK:2;			
	Uint16	RPBBLK:2;			
	Uint16	RMCME:1;			
	Uint16	rsvd2:6;			
};

union MCR1_REG {
	Uint16 all;
	struct MCR1_BITS	bit;
};

struct RCERA_BITS {     
	Uint16	RCEA0:1;			
	Uint16	RCEA1:1;			
	Uint16	RCEA2:1;			
	Uint16	RCEA3:1;			
	Uint16	RCEA4:1;			
	Uint16	RCEA5:1;			
	Uint16	RCEA6:1;			
	Uint16	RCEA7:1;			
	Uint16	RCEA8:1;			
	Uint16	RCEA9:1;			
	Uint16	RCEA10:1;			
	Uint16	RCEA11:1;			
	Uint16	RCEA12:1;			
	Uint16	RCEA13:1;			
	Uint16	RCEA14:1;			
	Uint16	RCEA15:1;			
};

union RCERA_REG {
	Uint16 all;
	struct RCERA_BITS	bit;
};

struct RCERB_BITS {     
	Uint16	RCEB0:1;			
	Uint16	RCEB1:1;			
	Uint16	RCEB2:1;			
	Uint16	RCEB3:1;			
	Uint16	RCEB4:1;			
	Uint16	RCEB5:1;			
	Uint16	RCEB6:1;			
	Uint16	RCEB7:1;			
	Uint16	RCEB8:1;			
	Uint16	RCEB9:1;			
	Uint16	RCEB10:1;			
	Uint16	RCEB11:1;			
	Uint16	RCEB12:1;			
	Uint16	RCEB13:1;			
	Uint16	RCEB14:1;			
	Uint16	RCEB15:1;			
};

union RCERB_REG {
	Uint16 all;
	struct RCERB_BITS	bit;
};

struct XCERA_BITS {     
	Uint16	XCERA0:1;			
	Uint16	XCERA1:1;			
	Uint16	XCERA2:1;			
	Uint16	XCERA3:1;			
	Uint16	XCERA4:1;			
	Uint16	XCERA5:1;			
	Uint16	XCERA6:1;			
	Uint16	XCERA7:1;			
	Uint16	XCERA8:1;			
	Uint16	XCERA9:1;			
	Uint16	XCERA10:1;			
	Uint16	XCERA11:1;			
	Uint16	XCERA12:1;			
	Uint16	XCERA13:1;			
	Uint16	XCERA14:1;			
	Uint16	XCERA15:1;			
};

union XCERA_REG {
	Uint16 all;
	struct XCERA_BITS	bit;
};

struct XCERB_BITS {     
	Uint16	XCERB0:1;			
	Uint16	XCERB1:1;			
	Uint16	XCERB2:1;			
	Uint16	XCERB3:1;			
	Uint16	XCERB4:1;			
	Uint16	XCERB5:1;			
	Uint16	XCERB6:1;			
	Uint16	XCERB7:1;			
	Uint16	XCERB8:1;			
	Uint16	XCERB9:1;			
	Uint16	XCERB10:1;			
	Uint16	XCERB11:1;			
	Uint16	XCERB12:1;			
	Uint16	XCERB13:1;			
	Uint16	XCERB14:1;			
	Uint16	XCERB15:1;			
};

union XCERB_REG {
	Uint16 all;
	struct XCERB_BITS	bit;
};

struct PCR_BITS {     
	Uint16	CLKRP:1;			
	Uint16	CLKXP:1;			
	Uint16	FSRP:1;				
	Uint16	FSXP:1;				
	Uint16	rsvd1:1;			
	Uint16	rsvd2:1;			
	Uint16	rsvd3:1;			
	Uint16	SCLKME:1;			
	Uint16	CLKRM:1;			
	Uint16	CLKXM:1;			
	Uint16	FSRM:1;				
	Uint16	FSXM:1;				
	Uint16	rsvd4:4;			
};

union PCR_REG {
	Uint16 all;
	struct PCR_BITS	bit;
};

struct RCERC_BITS {     
	Uint16	RCEC0:1;			
	Uint16	RCEC1:1;			
	Uint16	RCEC2:1;			
	Uint16	RCEC3:1;			
	Uint16	RCEC4:1;			
	Uint16	RCEC5:1;			
	Uint16	RCEC6:1;			
	Uint16	RCEC7:1;			
	Uint16	RCEC8:1;			
	Uint16	RCEC9:1;			
	Uint16	RCEC10:1;			
	Uint16	RCEC11:1;			
	Uint16	RCEC12:1;			
	Uint16	RCEC13:1;			
	Uint16	RCEC14:1;			
	Uint16	RCEC15:1;			
};

union RCERC_REG {
	Uint16 all;
	struct RCERC_BITS	bit;
};

struct RCERD_BITS {     
	Uint16	RCED0:1;			
	Uint16	RCED1:1;			
	Uint16	RCED2:1;			
	Uint16	RCED3:1;			
	Uint16	RCED4:1;			
	Uint16	RCED5:1;			
	Uint16	RCED6:1;			
	Uint16	RCED7:1;			
	Uint16	RCED8:1;			
	Uint16	RCED9:1;			
	Uint16	RCED10:1;			
	Uint16	RCED11:1;			
	Uint16	RCED12:1;			
	Uint16	RCED13:1;			
	Uint16	RCED14:1;			
	Uint16	RCED15:1;			
};

union RCERD_REG {
	Uint16 all;
	struct RCERD_BITS	bit;
};

struct XCERC_BITS {     
	Uint16	XCERC0:1;			
	Uint16	XCERC1:1;			
	Uint16	XCERC2:1;			
	Uint16	XCERC3:1;			
	Uint16	XCERC4:1;			
	Uint16	XCERC5:1;			
	Uint16	XCERC6:1;			
	Uint16	XCERC7:1;			
	Uint16	XCERC8:1;			
	Uint16	XCERC9:1;			
	Uint16	XCERC10:1;			
	Uint16	XCERC11:1;			
	Uint16	XCERC12:1;			
	Uint16	XCERC13:1;			
	Uint16	XCERC14:1;			
	Uint16	XCERC15:1;			
};

union XCERC_REG {
	Uint16 all;
	struct XCERC_BITS	bit;
};

struct XCERD_BITS {     
	Uint16	XCERD0:1;			
	Uint16	XCERD1:1;			
	Uint16	XCERD2:1;			
	Uint16	XCERD3:1;			
	Uint16	XCERD4:1;			
	Uint16	XCERD5:1;			
	Uint16	XCERD6:1;			
	Uint16	XCERD7:1;			
	Uint16	XCERD8:1;			
	Uint16	XCERD9:1;			
	Uint16	XCERD10:1;			
	Uint16	XCERD11:1;			
	Uint16	XCERD12:1;			
	Uint16	XCERD13:1;			
	Uint16	XCERD14:1;			
	Uint16	XCERD15:1;			
};

union XCERD_REG {
	Uint16 all;
	struct XCERD_BITS	bit;
};

struct RCERE_BITS {     
	Uint16	RCEE0:1;			
	Uint16	RCEE1:1;			
	Uint16	RCEE2:1;			
	Uint16	RCEE3:1;			
	Uint16	RCEE4:1;			
	Uint16	RCEE5:1;			
	Uint16	RCEE6:1;			
	Uint16	RCEE7:1;			
	Uint16	RCEE8:1;			
	Uint16	RCEE9:1;			
	Uint16	RCEE10:1;			
	Uint16	RCEE11:1;			
	Uint16	RCEE12:1;			
	Uint16	RCEE13:1;			
	Uint16	RCEE14:1;			
	Uint16	RCEE15:1;			
};

union RCERE_REG {
	Uint16 all;
	struct RCERE_BITS	bit;
};

struct RCERF_BITS {     
	Uint16	RCEF0:1;			
	Uint16	RCEF1:1;			
	Uint16	RCEF2:1;			
	Uint16	RCEF3:1;			
	Uint16	RCEF4:1;			
	Uint16	RCEF5:1;			
	Uint16	RCEF6:1;			
	Uint16	RCEF7:1;			
	Uint16	RCEF8:1;			
	Uint16	RCEF9:1;			
	Uint16	RCEF10:1;			
	Uint16	RCEF11:1;			
	Uint16	RCEF12:1;			
	Uint16	RCEF13:1;			
	Uint16	RCEF14:1;			
	Uint16	RCEF15:1;			
};

union RCERF_REG {
	Uint16 all;
	struct RCERF_BITS	bit;
};

struct XCERE_BITS {     
	Uint16	XCERE0:1;			
	Uint16	XCERE1:1;			
	Uint16	XCERE2:1;			
	Uint16	XCERE3:1;			
	Uint16	XCERE4:1;			
	Uint16	XCERE5:1;			
	Uint16	XCERE6:1;			
	Uint16	XCERE7:1;			
	Uint16	XCERE8:1;			
	Uint16	XCERE9:1;			
	Uint16	XCERE10:1;			
	Uint16	XCERE11:1;			
	Uint16	XCERE12:1;			
	Uint16	XCERE13:1;			
	Uint16	XCERE14:1;			
	Uint16	XCERE15:1;			
};

union XCERE_REG {
	Uint16 all;
	struct XCERE_BITS	bit;
};

struct XCERF_BITS {     
	Uint16	XCERF0:1;			
	Uint16	XCERF1:1;			
	Uint16	XCERF2:1;			
	Uint16	XCERF3:1;			
	Uint16	XCERF4:1;			
	Uint16	XCERF5:1;			
	Uint16	XCERF6:1;			
	Uint16	XCERF7:1;			
	Uint16	XCERF8:1;			
	Uint16	XCERF9:1;			
	Uint16	XCERF10:1;			
	Uint16	XCERF11:1;			
	Uint16	XCERF12:1;			
	Uint16	XCERF13:1;			
	Uint16	XCERF14:1;			
	Uint16	XCERF15:1;			
};

union XCERF_REG {
	Uint16 all;
	struct XCERF_BITS	bit;
};

struct RCERG_BITS {     
	Uint16	RCEG0:1;			
	Uint16	RCEG1:1;			
	Uint16	RCEG2:1;			
	Uint16	RCEG3:1;			
	Uint16	RCEG4:1;			
	Uint16	RCEG5:1;			
	Uint16	RCEG6:1;			
	Uint16	RCEG7:1;			
	Uint16	RCEG8:1;			
	Uint16	RCEG9:1;			
	Uint16	RCEG10:1;			
	Uint16	RCEG11:1;			
	Uint16	RCEG12:1;			
	Uint16	RCEG13:1;			
	Uint16	RCEG14:1;			
	Uint16	RCEG15:1;			
};

union RCERG_REG {
	Uint16 all;
	struct RCERG_BITS	bit;
};

struct RCERH_BITS {     
	Uint16	RCEH0:1;			
	Uint16	RCEH1:1;			
	Uint16	RCEH2:1;			
	Uint16	RCEH3:1;			
	Uint16	RCEH4:1;			
	Uint16	RCEH5:1;			
	Uint16	RCEH6:1;			
	Uint16	RCEH7:1;			
	Uint16	RCEH8:1;			
	Uint16	RCEH9:1;			
	Uint16	RCEH10:1;			
	Uint16	RCEH11:1;			
	Uint16	RCEH12:1;			
	Uint16	RCEH13:1;			
	Uint16	RCEH14:1;			
	Uint16	RCEH15:1;			
};

union RCERH_REG {
	Uint16 all;
	struct RCERH_BITS	bit;
};

struct XCERG_BITS {     
	Uint16	XCERG0:1;			
	Uint16	XCERG1:1;			
	Uint16	XCERG2:1;			
	Uint16	XCERG3:1;			
	Uint16	XCERG4:1;			
	Uint16	XCERG5:1;			
	Uint16	XCERG6:1;			
	Uint16	XCERG7:1;			
	Uint16	XCERG8:1;			
	Uint16	XCERG9:1;			
	Uint16	XCERG10:1;			
	Uint16	XCERG11:1;			
	Uint16	XCERG12:1;			
	Uint16	XCERG13:1;			
	Uint16	XCERG14:1;			
	Uint16	XCERG15:1;			
};

union XCERG_REG {
	Uint16 all;
	struct XCERG_BITS	bit;
};

struct XCERH_BITS {     
	Uint16	XCERH0:1;			
	Uint16	XCERH1:1;			
	Uint16	XCERH2:1;			
	Uint16	XCERH3:1;			
	Uint16	XCERH4:1;			
	Uint16	XCERH5:1;			
	Uint16	XCERH6:1;			
	Uint16	XCERH7:1;			
	Uint16	XCERH8:1;			
	Uint16	XCERH9:1;			
	Uint16	XCERH10:1;			
	Uint16	XCERH11:1;			
	Uint16	XCERH12:1;			
	Uint16	XCERH13:1;			
	Uint16	XCERH14:1;			
	Uint16	XCERH15:1;			
};

union XCERH_REG {
	Uint16 all;
	struct XCERH_BITS	bit;
};

struct MFFINT_BITS {     
	Uint16	XINT:1;			
	Uint16	rsvd1:1;		
	Uint16	RINT:1;			
	Uint16	rsvd2:13;		
};

union MFFINT_REG {
	Uint16 all;
	struct MFFINT_BITS	bit;
};

struct McBSP_REGS {
	union	DRR2_REG	DRR2;		
	union	DRR1_REG	DRR1;		
	union	DXR2_REG	DXR2;		
	union	DXR1_REG	DXR1;		
	union	SPCR2_REG	SPCR2;		
	union	SPCR1_REG	SPCR1;		
	union	RCR2_REG	RCR2;		
	union	RCR1_REG	RCR1;		
	union	XCR2_REG	XCR2;		
	union	XCR1_REG	XCR1;		
	union	SRGR2_REG	SRGR2;		
	union	SRGR1_REG	SRGR1;		
	union	MCR2_REG	MCR2;		
	union	MCR1_REG	MCR1;		
	union	RCERA_REG	RCERA;		
	union	RCERB_REG	RCERB;		
	union	XCERA_REG	XCERA;		
	union	XCERB_REG	XCERB;		
	union	PCR_REG		PCR;		
	union	RCERC_REG	RCERC;		
	union	RCERD_REG	RCERD;		
	union	XCERC_REG	XCERC;		
	union	XCERD_REG	XCERD;		
	union	RCERE_REG	RCERE;		
	union	RCERF_REG	RCERF;		
	union	XCERE_REG	XCERE;		
	union	XCERF_REG	XCERF;		
	union	RCERG_REG	RCERG;		
	union	RCERH_REG	RCERH;		
	union	XCERG_REG	XCERG;		
	union	XCERH_REG	XCERH;		
	Uint16				rsvd1[4];	
	union	MFFINT_REG	MFFINT;		
};




extern volatile struct McBSP_REGS McbspaRegs;























struct NMICFG_BITS {             
    Uint16   rsvd1:1;            
    Uint16   CLOCKFAIL:1;        
    Uint16   rsvd2:14;           
};

union NMICFG_REG  {
    Uint16                         all;
    struct NMICFG_BITS             bit;
};

struct NMIFLG_BITS {             
    Uint16   NMIINT:1;           
    Uint16   CLOCKFAIL:1;        
    Uint16   rsvd1:14;           
};

union NMIFLG_REG  {
    Uint16                         all;
    struct NMIFLG_BITS             bit;
};

struct NMIFLGCLR_BITS {          
    Uint16   NMIINT:1;           
    Uint16   CLOCKFAIL:1;        
    Uint16   rsvd1:14;           
};

union NMIFLGCLR_REG  {
    Uint16                         all;
    struct NMIFLGCLR_BITS          bit;
};

struct NMIFLGFRC_BITS {          
    Uint16   rsvd1:1;            
    Uint16   CLOCKFAIL:1;        
    Uint16   rsvd2:14;           
};

union NMIFLGFRC_REG  {
    Uint16                         all;
    struct NMIFLGFRC_BITS          bit;
};





struct NMIINTRUPT_REGS {
    union  NMICFG_REG          NMICFG;
    union  NMIFLG_REG          NMIFLG;
    union  NMIFLGCLR_REG       NMIFLGCLR;
    union  NMIFLGFRC_REG       NMIFLGFRC;
    Uint16                     NMIWDCNT;
    Uint16                     NMIWDPRD;
    Uint16                     rsvd1[10];
};





extern volatile struct NMIINTRUPT_REGS NmiIntruptRegs;























struct PIECTRL_BITS {     
	Uint16	ENPIE:1;			
	Uint16	PIEVECT:15;			
};

union PIECTRL_REG {
	Uint16 all;
	struct PIECTRL_BITS	bit;
};

struct PIEIER_BITS {     
	Uint16	INTx1:1;			
	Uint16	INTx2:1;			
	Uint16	INTx3:1;			
	Uint16	INTx4:1;			
	Uint16	INTx5:1;			
	Uint16	INTx6:1;			
	Uint16	INTx7:1;			
	Uint16	INTx8:1;			
	Uint16	rsvd1:8;			
};

union PIEIER_REG {
	Uint16 all;
	struct PIEIER_BITS	bit;
};

struct PIEIFR_BITS {     
	Uint16	INTx1:1;			
	Uint16	INTx2:1;			
	Uint16	INTx3:1;			
	Uint16	INTx4:1;			
	Uint16	INTx5:1;			
	Uint16	INTx6:1;			
	Uint16	INTx7:1;			
	Uint16	INTx8:1;			
	Uint16	rsvd1:8;			
};

union PIEIFR_REG {
	Uint16 all;
	struct PIEIFR_BITS	bit;
};

struct PIEACK_BITS {     
	Uint16	ACK1:1;			
	Uint16	ACK2:1;			
	Uint16	ACK3:1;			
	Uint16	ACK4:1;			
	Uint16	ACK5:1;			
	Uint16	ACK6:1;			
	Uint16	ACK7:1;			
	Uint16	ACK8:1;			
	Uint16	ACK9:1;			
	Uint16	ACK10:1;		
	Uint16	ACK11:1;		
	Uint16	ACK12:1;		
	Uint16	rsvd1:4;		
};

union PIEACK_REG {
	Uint16 all;
	struct PIEACK_BITS	bit;
};

struct PIE_CTRL_REGS {
	union	PIECTRL_REG	PIECTRL;	
	union	PIEACK_REG	PIEACK;		
	union	PIEIER_REG	PIEIER1;	
	union	PIEIFR_REG	PIEIFR1;	
	union	PIEIER_REG	PIEIER2;	
	union	PIEIFR_REG	PIEIFR2;	
	union	PIEIER_REG	PIEIER3;	
	union	PIEIFR_REG	PIEIFR3;	
	union	PIEIER_REG	PIEIER4;	
	union	PIEIFR_REG	PIEIFR4;	
	union	PIEIER_REG	PIEIER5;	
	union	PIEIFR_REG	PIEIFR5;	
	union	PIEIER_REG	PIEIER6;	
	union	PIEIFR_REG	PIEIFR6;	
	union	PIEIER_REG	PIEIER7;	
	union	PIEIFR_REG	PIEIFR7;	
	union	PIEIER_REG	PIEIER8;	
	union	PIEIFR_REG	PIEIFR8;	
	union	PIEIER_REG	PIEIER9;	
	union	PIEIFR_REG	PIEIFR9;	
	union	PIEIER_REG	PIEIER10;	
	union	PIEIFR_REG	PIEIFR10;	
	union	PIEIER_REG	PIEIER11;	
	union	PIEIFR_REG	PIEIFR11;	
	union	PIEIER_REG	PIEIER12;	
	union	PIEIFR_REG	PIEIFR12;	
};





extern volatile struct PIE_CTRL_REGS PieCtrlRegs;
























typedef interrupt void(*PINT)(void);


struct PIE_VECT_TABLE {





      PINT     PIE1_RESERVED;
      PINT     PIE2_RESERVED;
      PINT     PIE3_RESERVED;
      PINT     PIE4_RESERVED;
      PINT     PIE5_RESERVED;
      PINT     PIE6_RESERVED;
      PINT     PIE7_RESERVED;
      PINT     PIE8_RESERVED;
      PINT     PIE9_RESERVED;
      PINT     PIE10_RESERVED;
      PINT     PIE11_RESERVED;
      PINT     PIE12_RESERVED;
      PINT     PIE13_RESERVED;


      PINT     TINT1;     
      PINT     TINT2;     
      PINT     DATALOG;   
      PINT     RTOSINT;   
      PINT     EMUINT;    
      PINT     NMI;       
      PINT     ILLEGAL;   
      PINT     USER1;     
      PINT     USER2;     
      PINT     USER3;     
      PINT     USER4;     
      PINT     USER5;     
      PINT     USER6;     
      PINT     USER7;     
      PINT     USER8;     
      PINT     USER9;     
      PINT     USER10;    
      PINT     USER11;    
      PINT     USER12;    


      PINT     ADCINT1;   
      PINT     ADCINT2;   
      PINT     rsvd1_3;
      PINT     XINT1;	  
      PINT     XINT2;     
      PINT     ADCINT9;   
      PINT     TINT0;     
      PINT     WAKEINT;   


      PINT     EPWM1_TZINT; 
      PINT     EPWM2_TZINT; 
      PINT     EPWM3_TZINT; 
      PINT     EPWM4_TZINT; 
      PINT     EPWM5_TZINT; 
      PINT     EPWM6_TZINT; 
      PINT     EPWM7_TZINT; 
      PINT     EPWM8_TZINT;	


      PINT     EPWM1_INT;  
      PINT     EPWM2_INT;  
      PINT     EPWM3_INT;  
      PINT     EPWM4_INT;  
      PINT     EPWM5_INT;  
      PINT     EPWM6_INT;  
      PINT     EPWM7_INT;  
      PINT     EPWM8_INT;  


      PINT     ECAP1_INT;  
      PINT     ECAP2_INT;  
      PINT     ECAP3_INT;  
      PINT     rsvd4_4;
      PINT     rsvd4_5;
      PINT     rsvd4_6;
      PINT     HRCAP1_INT; 
      PINT     HRCAP2_INT; 


      PINT     EQEP1_INT;  
      PINT     EQEP2_INT;  
      PINT     rsvd5_3;
      PINT     HRCAP3_INT; 
      PINT     HRCAP4_INT; 
      PINT     rsvd5_6;
      PINT     rsvd5_7;
      PINT     USB0_INT;   


      PINT     SPIRXINTA; 
      PINT     SPITXINTA; 
      PINT     SPIRXINTB; 
      PINT     SPITXINTB; 
      PINT     MRINTA;	  
      PINT     MXINTA;    
      PINT     rsvd6_7;
      PINT     rsvd6_8;


      PINT     DINTCH1;	
      PINT     DINTCH2;	
      PINT     DINTCH3;	
      PINT     DINTCH4;	
      PINT     DINTCH5;	
      PINT     DINTCH6;	
      PINT     rsvd7_7;
      PINT     rsvd7_8;


      PINT     I2CINT1A;  
      PINT     I2CINT2A;  
      PINT     rsvd8_3;
      PINT     rsvd8_4;
      PINT     rsvd8_5;
      PINT     rsvd8_6;
      PINT     rsvd8_7;
      PINT     rsvd8_8;



      PINT     SCIRXINTA;  
      PINT     SCITXINTA;  
      PINT     SCIRXINTB;  
      PINT     SCITXINTB;  
      PINT     ECAN0INTA;  
      PINT     ECAN1INTA;  
      PINT     rsvd9_7;
      PINT     rsvd9_8;


      PINT     rsvd10_1; 
      PINT     rsvd10_2; 
      PINT     ADCINT3;  
      PINT     ADCINT4;  
      PINT     ADCINT5;  
      PINT     ADCINT6;  
      PINT     ADCINT7;  
      PINT     ADCINT8;  



      PINT     CLA1_INT1;  
      PINT     CLA1_INT2;  
      PINT     CLA1_INT3;  
      PINT     CLA1_INT4;  
      PINT     CLA1_INT5;  
      PINT     CLA1_INT6;  
      PINT     CLA1_INT7;  
      PINT     CLA1_INT8;  


      PINT     XINT3;
      PINT     rsvd12_2;
      PINT     rsvd12_3;
      PINT     rsvd12_4;
      PINT     rsvd12_5;
      PINT     rsvd12_6;
      PINT     LVF;        
      PINT     LUF;        
};




extern struct PIE_VECT_TABLE PieVectTable;
























struct SPICCR_BITS {     
	Uint16	SPICHAR:4;			
	Uint16	SPILBK:1;			
	Uint16	rsvd1:1;			
	Uint16	CLKPOLARITY:1;		
	Uint16	SPISWRESET:1;		
	Uint16	rsvd2:8;			
};

union SPICCR_REG {
	Uint16 all;
	struct SPICCR_BITS	bit;
};

struct SPICTL_BITS {     
	Uint16	SPIINTENA:1;		
	Uint16	TALK:1;				
	Uint16	MASTER_SLAVE:1;		
	Uint16	CLK_PHASE:1;		
	Uint16	OVERRUNINTENA:1;	
	Uint16	rsvd1:11;			
};

union SPICTL_REG {
	Uint16 all;
	struct SPICTL_BITS	bit;
};

struct SPISTS_BITS {     
	Uint16	rsvd1:5;			
	Uint16	BUFFULL_FLAG:1;		
	Uint16	INT_FLAG:1;			
	Uint16	OVERRUN_FLAG:1;		
	Uint16	rsvd2:8;			
};

union SPISTS_REG {
	Uint16 all;
	struct SPISTS_BITS	bit;
};

struct SPIFFTX_BITS {     
	Uint16	TXFFIL:5;			
	Uint16	TXFFIENA:1;			
	Uint16	TXFFINTCLR:1;		
	Uint16	TXFFINT:1;			
	Uint16	TXFFST:5;			
	Uint16	TXFIFO:1;			
	Uint16	SPIFFENA:1;			
	Uint16	SPIRST:1;			
};

union SPIFFTX_REG {
	Uint16 all;
	struct SPIFFTX_BITS	bit;
};

struct SPIFFRX_BITS {     
	Uint16	RXFFIL:5;			
	Uint16	RXFFIENA:1;			
	Uint16	RXFFINTCLR:1;		
	Uint16	RXFFINT:1;			
	Uint16	RXFFST:5;			
	Uint16	RXFIFORESET:1;		
	Uint16	RXFFOVFCLR:1;		
	Uint16	RXFFOVF:1;			
};

union SPIFFRX_REG {
	Uint16 all;
	struct SPIFFRX_BITS	bit;
};

struct SPIFFCT_BITS {     
	Uint16	TXDLY:8;			
	Uint16	rsvd1:8;			
};

union SPIFFCT_REG {
	Uint16 all;
	struct SPIFFCT_BITS	bit;
};

struct SPIPRI_BITS {     
   Uint16 TRIWIRE:1;         
   Uint16 STEINV:1;          
   Uint16 rsvd1:2;           
   Uint16 FREE:1;            
   Uint16 SOFT:1;            
   Uint16 PRIORITY:1;        
   Uint16 rsvd2:9;           
};

union SPIPRI_REG {
	Uint16 all;
	struct SPIPRI_BITS	bit;
};

struct SPI_REGS {
	union	SPICCR_REG	SPICCR;		
	union	SPICTL_REG	SPICTL;		
	union	SPISTS_REG	SPISTS;		
	Uint16				rsvd1;		
	Uint16				SPIBRR;		
	Uint16				rsvd2;		
	Uint16				SPIRXEMU;	
	Uint16				SPIRXBUF;	
	Uint16				SPITXBUF;	
	Uint16				SPIDAT;		
	union	SPIFFTX_REG	SPIFFTX;	
	union	SPIFFRX_REG	SPIFFRX;	
	union	SPIFFCT_REG	SPIFFCT;	
	Uint16				rsvd3[2];	
	union	SPIPRI_REG	SPIPRI;		
};




extern volatile struct SPI_REGS SpiaRegs;
extern volatile struct SPI_REGS SpibRegs;























struct SCICCR_BITS {     
	Uint16	SCICHAR:3;			
	Uint16	ADDRIDLE_MODE:1;	
	Uint16	LOOPBKENA:1;		
	Uint16	PARITYENA:1;		
	Uint16	PARITY:1;			
	Uint16	STOPBITS:1;			
	Uint16	rsvd1:8;			
};

union SCICCR_REG {
	Uint16 all;
	struct SCICCR_BITS	bit;
};

struct SCICTL1_BITS {     
	Uint16	RXENA:1;			
	Uint16	TXENA:1;			
	Uint16	SLEEP:1;			
	Uint16	TXWAKE:1;			
	Uint16	rsvd1:1;			
	Uint16	SWRESET:1;			
	Uint16	RXERRINTENA:1;		
	Uint16	rsvd2:9;			
};

union SCICTL1_REG {
	Uint16 all;
	struct SCICTL1_BITS	bit;
};

struct SCICTL2_BITS {     
	Uint16	TXINTENA:1;			
	Uint16	RXBKINTENA:1;		
	Uint16	rsvd1:4;			
	Uint16	TXEMPTY:1;			
	Uint16	TXRDY:1;			
	Uint16	rsvd2:8;			
};

union SCICTL2_REG {
	Uint16 all;
	struct SCICTL2_BITS	bit;
};

struct SCIRXST_BITS {     
	Uint16	rsvd1:1;		
	Uint16	RXWAKE:1;		
	Uint16	PE:1;			
	Uint16	OE:1;			
	Uint16	FE:1;			
	Uint16	BRKDT:1;		
	Uint16	RXRDY:1;		
	Uint16	RXERROR:1;		
	Uint16	rsvd2:8;		
};

union SCIRXST_REG {
	Uint16 all;
	struct SCIRXST_BITS	bit;
};

struct SCIRXBUF_BITS {     
	Uint16	RXDT:8;			
	Uint16	rsvd1:6;		
	Uint16	SCIFFPE:1;		
	Uint16	SCIFFFE:1;		
};

union SCIRXBUF_REG {
	Uint16 all;
	struct SCIRXBUF_BITS	bit;
};

struct SCIFFTX_BITS {     
	Uint16	TXFFIL:5;			
	Uint16	TXFFIENA:1;			
	Uint16	TXFFINTCLR:1;		
	Uint16	TXFFINT:1;			
	Uint16	TXFFST:5;			
	Uint16	TXFIFOXRESET:1;		
	Uint16	SCIFFENA:1;			
	Uint16	SCIRST:1;			
};

union SCIFFTX_REG {
	Uint16 all;
	struct SCIFFTX_BITS	bit;
};

struct SCIFFRX_BITS {     
	Uint16	RXFFIL:5;			
	Uint16	RXFFIENA:1;			
	Uint16	RXFFINTCLR:1;		
	Uint16	RXFFINT:1;			
	Uint16	RXFFST:5;			
	Uint16	RXFIFORESET:1;		
	Uint16	RXFFOVRCLR:1;		
	Uint16	RXFFOVF:1;			
};

union SCIFFRX_REG {
	Uint16 all;
	struct SCIFFRX_BITS	bit;
};

struct SCIFFCT_BITS {     
	Uint16	FFTXDLY:8;		
	Uint16	rsvd1:5;		
	Uint16	CDC:1;			
	Uint16	ABDCLR:1;		
	Uint16	ABD:1;			
};

union SCIFFCT_REG {
	Uint16 all;
	struct SCIFFCT_BITS	bit;
};

struct SCIPRI_BITS {     
	Uint16	rsvd1:3;		
	Uint16	FREE:1;			
	Uint16	SOFT:1;			
	Uint16	rsvd2:3;		
	Uint16	rsvd3:8;		
};

union SCIPRI_REG {
	Uint16 all;
	struct SCIPRI_BITS	bit;
};

struct SCI_REGS {
	union	SCICCR_REG		SCICCR;		
	union	SCICTL1_REG		SCICTL1;	
	Uint16	SCIHBAUD;					
	Uint16	SCILBAUD;					
	union	SCICTL2_REG		SCICTL2;	
	union	SCIRXST_REG		SCIRXST;	
	Uint16					SCIRXEMU;	
	union	SCIRXBUF_REG	SCIRXBUF;	
	Uint16					rsvd1;		
	Uint16					SCITXBUF;	
	union	SCIFFTX_REG		SCIFFTX;	
	union	SCIFFRX_REG		SCIFFRX;	
	union	SCIFFCT_REG		SCIFFCT;	
	Uint16					rsvd2;		
	Uint16					rsvd3;		
	union	SCIPRI_REG		SCIPRI;		
};




extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;
























struct XCLK_BITS {     
	Uint16	XCLKOUTDIV:2;			
	Uint16	rsvd1:4;				
	Uint16	XCLKINSEL:1;			
	Uint16	rsvd2:9;				
};

union XCLK_REG {
	Uint16 all;
	struct XCLK_BITS	bit;
};

struct PLLSTS_BITS {     
	Uint16	PLLLOCKS:1;			
	Uint16	rsvd1:1;			
	Uint16	PLLOFF:1;			
	Uint16	MCLKSTS:1;			
	Uint16	MCLKCLR:1;			
	Uint16	OSCOFF:1;			
	Uint16	MCLKOFF:1;			
	Uint16	DIVSEL:2;			
	Uint16	rsvd2:6;			
	Uint16	NORMRDYE:1;			
};

union PLLSTS_REG {
	Uint16 all;
	struct PLLSTS_BITS	bit;
};

struct CLKCTL_BITS {     
	Uint16	OSCCLKSRCSEL:1;			
	Uint16	OSCCLKSRC2SEL:1;		
	Uint16	WDCLKSRCSEL:1;			
	Uint16	TMR2CLKSRCSEL:2;		
	Uint16	TMR2CLKPRESCALE:3;		
	Uint16	INTOSC1OFF:1;			
	Uint16	INTOSC1HALTI:1;			
	Uint16	INTOSC2OFF:1;			
	Uint16	INTOSC2HALTI:1;			
	Uint16	WDHALTI:1;				
	Uint16	XCLKINOFF:1;			
	Uint16	XTALOSCOFF:1;			
	Uint16	NMIRESETSEL:1;			
};

union CLKCTL_REG {
	Uint16 all;
	struct CLKCTL_BITS	bit;
};

struct INTOSC1TRIM_BITS {     
	Uint16	COARSETRIM:8;		
	Uint16	rsvd1:1;			
	Uint16	FINETRIM:6;			
	Uint16	rsvd2:1;			
};

union INTOSC1TRIM_REG {
	Uint16 all;
	struct INTOSC1TRIM_BITS	bit;
};

struct INTOSC2TRIM_BITS {     
	Uint16	COARSETRIM:8;		
	Uint16	rsvd1:1;			
	Uint16	FINETRIM:6;			
	Uint16	rsvd2:1;			
};

union INTOSC2TRIM_REG {
	Uint16 all;
	struct INTOSC2TRIM_BITS	bit;
};

struct PCLKCR2_BITS {	
	Uint16	rsvd1:8;			
	Uint16	HRCAP1ENCLK:1;		
	Uint16	HRCAP2ENCLK:1;		
	Uint16	HRCAP3ENCLK:1;		
	Uint16	HRCAP4ENCLK:1;		
	Uint16	rsvd2:4;			
};

union PCLKCR2_REG {
	Uint16 all;
	struct PCLKCR2_BITS	bit;
};

struct LOSPCP_BITS {     
	Uint16	LSPCLK:3;			
	Uint16	rsvd1:13;			
};

union LOSPCP_REG {
	Uint16 all;
	struct LOSPCP_BITS	bit;
};

struct PCLKCR0_BITS {     
	Uint16	HRPWMENCLK:1;		
	Uint16	rsvd1:1;			
	Uint16	TBCLKSYNC:1;		
	Uint16	ADCENCLK:1;			
	Uint16	I2CAENCLK:1;		
	Uint16	rsvd2:1;			
	Uint16	rsvd3:2;			
	Uint16	SPIAENCLK:1;		
	Uint16	SPIBENCLK:1;		
	Uint16	SCIAENCLK:1;		
	Uint16	SCIBENCLK:1;		
	Uint16	MCBSPAENCLK:1;		
	Uint16	rsvd4:1;			
	Uint16	ECANAENCLK:1;		
	Uint16	rsvd5:1;			
};

union PCLKCR0_REG {
	Uint16 all;
	struct PCLKCR0_BITS	bit;
};

struct PCLKCR1_BITS {     
	Uint16	EPWM1ENCLK:1;			
	Uint16	EPWM2ENCLK:1;			
	Uint16	EPWM3ENCLK:1;			
	Uint16	EPWM4ENCLK:1;			
	Uint16	EPWM5ENCLK:1;			
	Uint16	EPWM6ENCLK:1;			
	Uint16	EPWM7ENCLK:1;			
	Uint16	EPWM8ENCLK:1;			
	Uint16	ECAP1ENCLK:1;			
	Uint16	ECAP2ENCLK:1;			
	Uint16	ECAP3ENCLK:1;			
	Uint16	rsvd1:3;				
	Uint16	EQEP1ENCLK:1;			
	Uint16	EQEP2ENCLK:1;			
};

union PCLKCR1_REG {
	Uint16 all;
	struct PCLKCR1_BITS	bit;
};

struct PCLKCR3_BITS {     
	Uint16	COMP1ENCLK:1;			
	Uint16	COMP2ENCLK:1;			
	Uint16	COMP3ENCLK:1;			
	Uint16	rsvd1:5;				
	Uint16	CPUTIMER0ENCLK:1;		
	Uint16	CPUTIMER1ENCLK:1;		
	Uint16	CPUTIMER2ENCLK:1;		
	Uint16	DMAENCLK:1;				
	Uint16	rsvd2:1;				
	Uint16	rsvd3:1;				
	Uint16	CLA1ENCLK:1;			
	Uint16	USB0ENCLK:1;			
};

union PCLKCR3_REG {
	Uint16 all;
	struct PCLKCR3_BITS	bit;
};

struct PLLCR_BITS {     
	Uint16	DIV:5;				
	Uint16	rsvd1:11;			
};

union PLLCR_REG {
	Uint16 all;
	struct PLLCR_BITS	bit;
};

struct JTAGDEBUG_BITS {	
	Uint16	JTAGDIS:1;		
	Uint16	rsvd1:15;		
};

union JTAGDEBUG_REG {
	Uint16	all;
	struct	JTAGDEBUG_BITS	bit;
};

struct LPMCR0_BITS {     
	Uint16	LPM:2;				
	Uint16	QUALSTDBY:6;		
	Uint16	rsvd1:7;			
	Uint16	WDINTE:1;			
};

union LPMCR0_REG {
	Uint16 all;
	struct LPMCR0_BITS	bit;
};

struct PLL2CTL_BITS {	
	Uint16	PLL2CLKSRCSEL:2;	
	Uint16	PLL2EN:1;			
	Uint16	rsvd1:13;			
};

union PLL2CTL_REG {
	Uint16 all;
	struct PLL2CTL_BITS	bit;
};

struct PLL2MULT_BITS {	
	Uint16	PLL2MULT:4;		
	Uint16	rsvd1:12;		
};

union PLL2MULT_REG {
	Uint16 all;
	struct PLL2MULT_BITS	bit;
};

struct PLL2STS_BITS {	
	Uint16	PLL2LOCKS:1;	
	Uint16	rsvd1:15;		
};

union PLL2STS_REG {
	Uint16 all;
	struct PLL2STS_BITS	bit;
};

struct EPWMCFG_BITS {     
	Uint16	CONFIG:1;			
	Uint16	rsvd1:15;			
};

union EPWMCFG_REG {
	Uint16 all;
	struct EPWMCFG_BITS	bit;
};

 


struct BORCFG_BITS {     
   Uint16 BORENZ:1;      
   Uint16 rsvd1:15;      
};

union BORCFG_REG {
   Uint16              all;
   struct BORCFG_BITS  bit;
};

struct SYS_PWR_CTRL_REGS {
    union    BORCFG_REG   BORCFG;       
    Uint16   rsvd1[2];                  
};

 
struct  CSMSCR_BITS {      
   Uint16     SECURE:1;    
   Uint16     rsvd1:14;    
   Uint16     FORCESEC:1;  
};

 
union CSMSCR_REG {
   Uint16             all;
   struct CSMSCR_BITS bit;
};

 
struct  CSM_REGS {
   Uint16           KEY0;    
   Uint16           KEY1;    
   Uint16           KEY2;    
   Uint16           KEY3;    
   Uint16           KEY4;    
   Uint16           KEY5;    
   Uint16           KEY6;    
   Uint16           KEY7;    
   Uint16           rsvd1;   
   Uint16           rsvd2;   
   Uint16           rsvd3;   
   Uint16           rsvd4;   
   Uint16           rsvd5;   
   Uint16           rsvd6;   
   Uint16           rsvd7;   
   union CSMSCR_REG CSMSCR;  
};

 
struct  CSM_PWL {
   Uint16   PSWD0;  
   Uint16   PSWD1;  
   Uint16   PSWD2;  
   Uint16   PSWD3;  
   Uint16   PSWD4;  
   Uint16   PSWD5;  
   Uint16   PSWD6;  
   Uint16   PSWD7;  
};



struct FOPT_BITS {     
	Uint16	ENPIPE:1;			
	Uint16	rsvd1:15;			
};

union FOPT_REG {
	Uint16 all;
	struct FOPT_BITS	bit;
};

struct FPWR_BITS {     
	Uint16	PWR:2;				
	Uint16	rsvd1:14;			
};

union FPWR_REG {
	Uint16 all;
	struct FPWR_BITS	bit;
};

struct FSTATUS_BITS {     
	Uint16	PWRS:2;				
	Uint16	STDBYWAITS:1;		
	Uint16	ACTIVEWAITS:1;		
	Uint16	rsvd1:4;			
	Uint16	V3STAT:1;			
	Uint16	rsvd2:7;			
};

union FSTATUS_REG {
	Uint16 all;
	struct FSTATUS_BITS	bit;
};

struct FSTDBYWAIT_BITS {     
	Uint16	STDBYWAIT:9;		
	Uint16	rsvd1:7;			
};

union FSTDBYWAIT_REG {
	Uint16 all;
	struct FSTDBYWAIT_BITS	bit;
};

struct FACTIVEWAIT_BITS {     
	Uint16	ACTIVEWAIT:9;		
	Uint16	rsvd1:7;			
};

union FACTIVEWAIT_REG {
	Uint16 all;
	struct FACTIVEWAIT_BITS	bit;
};

struct FBANKWAIT_BITS {     
	Uint16	RANDWAIT:4;			
	Uint16	rsvd1:4;			
	Uint16	PAGEWAIT:4;			
	Uint16	rsvd2:4;			
};

union FBANKWAIT_REG {
	Uint16 all;
	struct FBANKWAIT_BITS	bit;
};

struct FOTPWAIT_BITS {     
	Uint16	OTPWAIT:5;			
	Uint16	rsvd1:11;			
};

union FOTPWAIT_REG {
	Uint16 all;
	struct FOTPWAIT_BITS	bit;
};

struct SYS_CTRL_REGS {
	union	XCLK_REG		XCLK;			
	union	PLLSTS_REG		PLLSTS;			
	union	CLKCTL_REG		CLKCTL;			
	Uint16					PLLLOCKPRD;		
	union	INTOSC1TRIM_REG	INTOSC1TRIM;	
	Uint16					rsvd1;			
	union	INTOSC2TRIM_REG	INTOSC2TRIM;	
	Uint16					rsvd2[2];		
	union	PCLKCR2_REG		PCLKCR2;		
	Uint16					rsvd3;			
	union	LOSPCP_REG		LOSPCP;			
	union	PCLKCR0_REG		PCLKCR0;		
	union	PCLKCR1_REG		PCLKCR1;		
	union	LPMCR0_REG		LPMCR0;			
	Uint16					rsvd4;			
	union	PCLKCR3_REG		PCLKCR3;		
	union	PLLCR_REG		PLLCR;			
	Uint16					SCSR;			
	Uint16					WDCNTR;			
	Uint16					rsvd5;			
	Uint16					WDKEY;			
	Uint16					rsvd6[3];		
	Uint16					WDCR;			
	union	JTAGDEBUG_REG	JTAGDEBUG;		
	Uint16					rsvd7[5];		
	union	PLL2CTL_REG		PLL2CTL;		
	Uint16					rsvd8;			
	union	PLL2MULT_REG	PLL2MULT;		
	Uint16					rsvd9;			
	union	PLL2STS_REG		PLL2STS;		
	Uint16					rsvd10;			
	Uint16					SYSCLK2CNTR;	
	Uint16					rsvd11[3];		
	union	EPWMCFG_REG		EPWMCFG;		
	Uint16					rsvd12[5];		
};

struct FLASH_REGS {
	union	FOPT_REG		FOPT;			
	Uint16					rsvd1;			
	union	FPWR_REG		FPWR;			
	union	FSTATUS_REG		FSTATUS;		
	union	FSTDBYWAIT_REG	FSTDBYWAIT;		
	union	FACTIVEWAIT_REG	FACTIVEWAIT;	
	union	FBANKWAIT_REG	FBANKWAIT;		
	union	FOTPWAIT_REG	FOTPWAIT;		
};




extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct SYS_PWR_CTRL_REGS SysPwrCtrlRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct FLASH_REGS FlashRegs;






















struct USBFADDR_BITS {     
	Uint16	FUNCADDR:7;			
	Uint16	rsvd1:1;			
};

union USBFADDR_REG {
	Uint16 all;
	struct USBFADDR_BITS	bit;
};

struct USBPOWER_BITS {     
	Uint16	PWRDNPHY:1;			
	Uint16	SUSPEND:1;			
	Uint16	RESUME:1;			
	Uint16	RESET:1;			
	Uint16	rsvd1:2;			
	Uint16	SOFT_CONN:1;		
	Uint16	ISOUP:1;			
};

union USBPOWER_REG {
	Uint16 all;
	struct USBPOWER_BITS	bit;
};

struct USBTXIS_BITS {     
	Uint16	EP0:1;			
	Uint16	EP1:1;			
	Uint16	EP2:1;			
	Uint16	EP3:1;			
	Uint16	rsvd1:12;		
};

union USBTXIS_REG {
	Uint32 all;
	struct USBTXIS_BITS	bit;
};

struct USBRXIS_BITS {     
	Uint16	rsvd1:1;		
	Uint16	EP1:1;			
	Uint16	EP2:1;			
	Uint16	EP3:1;			
	Uint16	rsvd2:12;		
};

union USBRXIS_REG {
	Uint32 all;
	struct USBRXIS_BITS	bit;
};

struct USBTXIE_BITS {     
	Uint16	EP0:1;			
	Uint16	EP1:1;			
	Uint16	EP2:1;			
	Uint16	EP3:1;			
	Uint16	rsvd2:12;		
};

union USBTXIE_REG {
	Uint32 all;
	struct USBTXIE_BITS	bit;
};

struct USBRXIE_BITS {     
	Uint16	rsvd1:1;		
	Uint16	EP1:1;			
	Uint16	EP2:1;			
	Uint16	EP3:1;			
	Uint16	rsvd2:12;		
};

union USBRXIE_REG {
	Uint32 all;
	struct USBRXIE_BITS	bit;
};

struct USBIS_BITS {     
	Uint16	SUSPEND:1;			
	Uint16	RESUME:1;			
	Uint16	RESET:1;			
	Uint16	SOF:1;				
	Uint16	rsvd1:1;			
	Uint16	DISCON:1;			
	Uint16	rsvd2:2;			
};

union USBIS_REG {
	Uint16 all;
	struct USBIS_BITS	bit;
};

struct USBIE_BITS {     
	Uint16	SUSPEND:1;			
	Uint16	RESUME:1;			
	Uint16	RESET:1;			
	Uint16	SOF:1;				
	Uint16	rsvd1:1;			
	Uint16	DISCON:1;			
	Uint16	rsvd2:2;			
};

union USBIE_REG {
	Uint16 all;
	struct USBIE_BITS	bit;
};

struct USBFRAME_BITS {     
	Uint16	FRAME:11;			
	Uint16	rsvd1:5;			
};

union USBFRAME_REG {
	Uint32 all;
	struct USBFRAME_BITS	bit;
};

struct USBEPIDX_BITS {     
	Uint16	EPIDX:4;			
	Uint16	rsvd1:4;			
};

union USBEPIDX_REG {
	Uint16 all;
	struct USBEPIDX_BITS	bit;
};

struct USBTEST_BITS {     
	Uint16	rsvd1:5;			
	Uint16	FORCEFS:1;			
	Uint16	FIFOACC:1;			
	Uint16	FORCEH:1;			
};

union USBTEST_REG {
	Uint16 all;
	struct USBTEST_BITS	bit;
};

struct USBDEVCTL_BITS {     
	Uint16	SESSION:1;			
	Uint16	HOSTREQ:1;			
	Uint16	HOST:1;				
	Uint16	VBUS:2;				
	Uint16	LSDEV:1;			
	Uint16	FSDEV:1;			
	Uint16	DEV:1;				
};

union USBDEVCTL_REG {
	Uint16	all;
	struct USBDEVCTL_BITS	bit;
};

struct USBTXFIFOSZ_BITS {     
	Uint16	SIZE:4;				
	Uint16	DPB:1;				
	Uint16	rsvd1:3;			
};

union USBTXFIFOSZ_REG {
	Uint16 	all;
	struct USBTXFIFOSZ_BITS	bit;
};

struct USBRXFIFOSZ_BITS {     
	Uint16	SIZE:4;				
	Uint16	DPB:1;				
	Uint16	rsvd1:3;			
};

union USBRXFIFOSZ_REG {
	Uint16 	all;
	struct USBRXFIFOSZ_BITS	bit;
};

struct USBTXFIFOADD_BITS {     
	Uint16	ADDR:9;				
	Uint16	rsvd1:7;			
};

union USBTXFIFOADD_REG {
	Uint32 all;
	struct USBTXFIFOADD_BITS	bit;
};

struct USBRXFIFOADD_BITS {     
	Uint16	ADDR:9;				
	Uint16	rsvd1:7;			
};

union USBRXFIFOADD_REG {
	Uint32 all;
	struct USBRXFIFOADD_BITS	bit;
};

struct USBCONTIM_BITS {     
	Uint16	WTID:4;				
	Uint16	WTCON:4;			
};

union USBCONTIM_REG {
	Uint16 	all;
	struct USBCONTIM_BITS	bit;
};

struct USBTXFUNCADDR0_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBTXFUNCADDR0_REG {
	Uint16	all;
	struct USBTXFUNCADDR0_BITS	bit;
};

struct USBTXHUBADDR0_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBTXHUBADDR0_REG {
	Uint16 	all;
	struct USBTXHUBADDR0_BITS	bit;
};

struct USBTXHUBPORT0_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBTXHUBPORT0_REG {
	Uint16 	all;
	struct USBTXHUBPORT0_BITS	bit;
};

struct USBTXFUNCADDR1_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBTXFUNCADDR1_REG {
	Uint16 	all;
	struct USBTXFUNCADDR1_BITS	bit;
};

struct USBTXHUBADDR1_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBTXHUBADDR1_REG {
	Uint16 	all;
	struct USBTXHUBADDR1_BITS	bit;
};

struct USBTXHUBPORT1_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBTXHUBPORT1_REG {
	Uint16 	all;
	struct USBTXHUBPORT1_BITS	bit;
};

struct USBRXFUNCADDR1_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBRXFUNCADDR1_REG {
	Uint16 	all;
	struct USBRXFUNCADDR1_BITS	bit;
};

struct USBRXHUBADDR1_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBRXHUBADDR1_REG {
	Uint16 	all;
	struct USBRXHUBADDR1_BITS	bit;
};

struct USBRXHUBPORT1_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBRXHUBPORT1_REG {
	Uint16 	all;
	struct USBRXHUBPORT1_BITS	bit;
};

struct USBTXFUNCADDR2_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBTXFUNCADDR2_REG {
	Uint16 	all;
	struct USBTXFUNCADDR2_BITS	bit;
};

struct USBTXHUBADDR2_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBTXHUBADDR2_REG {
	Uint16 	all;
	struct USBTXHUBADDR2_BITS	bit;
};

struct USBTXHUBPORT2_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBTXHUBPORT2_REG {
	Uint16 	all;
	struct USBTXHUBPORT2_BITS	bit;
};

struct USBRXFUNCADDR2_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBRXFUNCADDR2_REG {
	Uint16	all;
	struct USBRXFUNCADDR2_BITS	bit;
};

struct USBRXHUBADDR2_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBRXHUBADDR2_REG {
	Uint16 	all;
	struct USBRXHUBADDR2_BITS	bit;
};

struct USBRXHUBPORT2_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBRXHUBPORT2_REG {
	Uint16 	all;
	struct USBRXHUBPORT2_BITS	bit;
};

struct USBTXFUNCADDR3_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBTXFUNCADDR3_REG {
	Uint16 	all;
	struct USBTXFUNCADDR3_BITS	bit;
};

struct USBTXHUBADDR3_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBTXHUBADDR3_REG {
	Uint16 	all;
	struct USBTXHUBADDR3_BITS	bit;
};

struct USBTXHUBPORT3_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBTXHUBPORT3_REG {
	Uint16 	all;
	struct USBTXHUBPORT3_BITS	bit;
};

struct USBRXFUNCADDR3_BITS {     
	Uint16	ADDR:7;				
	Uint16	rsvd1:1;			
};

union USBRXFUNCADDR3_REG {
	Uint16	all;
	struct USBRXFUNCADDR3_BITS	bit;
};

struct USBRXHUBADDR3_BITS {     
	Uint16	ADDR:7;				
	Uint16	MULTTRAN:1;			
};

union USBRXHUBADDR3_REG {
	Uint16 	all;
	struct USBRXHUBADDR3_BITS	bit;
};

struct USBRXHUBPORT3_BITS {     
	Uint16	PORT:7;				
	Uint16	rsvd1:1;			
};

union USBRXHUBPORT3_REG {
	Uint16 	all;
	struct USBRXHUBPORT3_BITS	bit;
};

struct USBCSRL0_BITS {     
	Uint16	RXRDY:1;				
	Uint16	TXRDY:1;				
	Uint16	STALLED:1;				
	Uint16	DATAEND_SETUP:1;		
	Uint16	SETEND_ERROR:1;			
	Uint16	STALL_RQPKT:1;			
	Uint16	RXRDYC_STATUS:1;		
	Uint16	SETENDC_NAKTO:1;		
};

union USBCSRL0_REG {
	Uint16 	all;
	struct USBCSRL0_BITS	bit;
};

struct USBCSRH0_BITS {     
	Uint16	FLUSH:1;			
	Uint16	DT:1;				
	Uint16	DTWE:1;				
	Uint16	rsvd1:5;			
};

union USBCSRH0_REG {
	Uint16 	all;
	struct USBCSRH0_BITS	bit;
};

struct USBCOUNT0_BITS {     
	Uint16	COUNT:7;			
	Uint16	rsvd1:1;			
};

union USBCOUNT0_REG {
	Uint16 	all;
	struct USBCOUNT0_BITS	bit;
};

struct USBTYPE0_BITS {     
	Uint16	rsvd1:6;			
	Uint16	SPEED:2;			
};

union USBTYPE0_REG {
	Uint16 	all;
	struct USBTYPE0_BITS	bit;
};

struct USBNAKLMT_BITS {     
	Uint16	NAKLMT:5;			
	Uint16	rsvd1:3;			
};

union USBNAKLMT_REG {
	Uint16 	all;
	struct USBNAKLMT_BITS	bit;
};

struct USBTXMAXP1_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBTXMAXP1_REG {
	Uint32 all;
	struct USBTXMAXP1_BITS	bit;
};

struct USBTXCSRL1_BITS {     
	Uint16	TXRDY:1;			
	Uint16	FIFONE:1;			
	Uint16	UNDRN_ERROR1:1;		
	Uint16	FLUSH:1;			
	Uint16	STALL_SETUP:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
	Uint16	NAKTO:1;			
};

union USBTXCSRL1_REG {
	Uint16 	all;
	struct USBTXCSRL1_BITS	bit;
};

struct USBTXCSRH1_BITS {     
	Uint16	DT:1;			
	Uint16	DTWE:1;			
	Uint16	DMAMOD:1;		
	Uint16	FDT:1;			
	Uint16	DMAEN:1;		
	Uint16	MODE:1;			
	Uint16	ISO:1;			
	Uint16	AUTOSET:1;		
};

union USBTXCSRH1_REG {
	Uint16 	all;
	struct USBTXCSRH1_BITS	bit;
};

struct USBRXMAXP1_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBRXMAXP1_REG {
	Uint32 all;
	struct USBRXMAXP1_BITS	bit;
};

struct USBRXCSRL1_BITS {     
	Uint16	RXRDY:1;			
	Uint16	FULL:1;				
	Uint16	OVERERROR1:1;		
	Uint16	DATAERRNAKTO:1;	
	Uint16	FLUSH:1;			
	Uint16	STALLREQPKT:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
};

union USBRXCSRL1_REG {
	Uint16 	all;
	struct USBRXCSRL1_BITS	bit;
};

struct USBRXCSRH1_BITS {     
	Uint16	rsvd1:1;			
	Uint16	DT:1;				
	Uint16	DTWE:1;				
	Uint16	DMAMOD:1;			
	Uint16	DISNYETPIDERR:1;	
	Uint16	DMAEN:1;			
	Uint16	ISOAUTORQ:1;		
	Uint16	AUTOCL:1;			
};

union USBRXCSRH1_REG {
	Uint16 	all;
	struct USBRXCSRH1_BITS	bit;
};

struct USBRXCOUNT1_BITS {     
	Uint16	COUNT:13;			
	Uint16	rsvd1:3;			
};

union USBRXCOUNT1_REG {
	Uint32 	all;
	struct USBRXCOUNT1_BITS	bit;
};

struct USBTXTYPE1_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBTXTYPE1_REG {
	Uint16 	all;
	struct USBTXTYPE1_BITS	bit;
};

struct USBRXTYPE1_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBRXTYPE1_REG {
	Uint16 	all;
	struct USBRXTYPE1_BITS	bit;
};

struct USBTXMAXP2_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBTXMAXP2_REG {
	Uint32 all;
	struct USBTXMAXP2_BITS	bit;
};

struct USBTXCSRL2_BITS {     
	Uint16	TXRDY:1;			
	Uint16	FIFONE:1;			
	Uint16	UNDRNERROR2:1;		
	Uint16	FLUSH:1;			
	Uint16	STALLSETUP:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
	Uint16	NAKTO:1;			
};

union USBTXCSRL2_REG {
	Uint16 	all;
	struct USBTXCSRL2_BITS	bit;
};

struct USBTXCSRH2_BITS {     
	Uint16	DT:1;			
	Uint16	DTWE:1;			
	Uint16	DMAMOD:1;		
	Uint16	FDT:1;			
	Uint16	DMAEN:1;		
	Uint16	MODE:1;			
	Uint16	ISO:1;			
	Uint16	AUTOSET:1;		
};

union USBTXCSRH2_REG {
	Uint16 	all;
	struct USBTXCSRH2_BITS	bit;
};

struct USBRXMAXP2_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBRXMAXP2_REG {
	Uint32 all;
	struct USBRXMAXP2_BITS	bit;
};

struct USBRXCSRL2_BITS {     
	Uint16	RXRDY:1;			
	Uint16	FULL:1;				
	Uint16	OVERERROR2:1;		
	Uint16	DATAERRNAKTO:1;	
	Uint16	FLUSH:1;			
	Uint16	STALLREQPKT:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
};

union USBRXCSRL2_REG {
	Uint16 all;
	struct USBRXCSRL2_BITS	bit;
};

struct USBRXCSRH2_BITS {     
	Uint16	rsvd1:1;			
	Uint16	DT:1;				
	Uint16	DTWE:1;				
	Uint16	DMAMOD:1;			
	Uint16	DISNYETPIDERR:1;	
	Uint16	DMAEN:1;			
	Uint16	ISOAUTORQ:1;		
	Uint16	AUTOCL:1;			
};

union USBRXCSRH2_REG {
	Uint16 all;
	struct USBRXCSRH2_BITS	bit;
};

struct USBRXCOUNT2_BITS {     
	Uint16	COUNT:13;			
	Uint16	rsvd1:3;			
};

union USBRXCOUNT2_REG {
	Uint32 all;
	struct USBRXCOUNT2_BITS	bit;
};

struct USBTXTYPE2_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBTXTYPE2_REG {
	Uint16 	all;
	struct USBTXTYPE2_BITS	bit;
};

struct USBRXTYPE2_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBRXTYPE2_REG {
	Uint16 	all;
	struct USBRXTYPE2_BITS	bit;
};

struct USBTXMAXP3_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBTXMAXP3_REG {
	Uint32 all;
	struct USBTXMAXP3_BITS	bit;
};

struct USBTXCSRL3_BITS {     
	Uint16	TXRDY:1;			
	Uint16	FIFONE:1;			
	Uint16	UNDRNERROR3:1;		
	Uint16	FLUSH:1;			
	Uint16	STALLSETUP:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
	Uint16	NAKTO:1;			
};

union USBTXCSRL3_REG {
	Uint16 	all;
	struct USBTXCSRL3_BITS	bit;
};

struct USBTXCSRH3_BITS {     
	Uint16	DT:1;			
	Uint16	DTWE:1;			
	Uint16	DMAMOD:1;		
	Uint16	FDT:1;			
	Uint16	DMAEN:1;		
	Uint16	MODE:1;			
	Uint16	ISO:1;			
	Uint16	AUTOSET:1;		
};

union USBTXCSRH3_REG {
	Uint16 	all;
	struct USBTXCSRH3_BITS	bit;
};

struct USBRXMAXP3_BITS {     
	Uint16	MAXLOAD:11;			
	Uint16	rsvd1:5;			
};

union USBRXMAXP3_REG {
	Uint32 all;
	struct USBRXMAXP3_BITS	bit;
};

struct USBRXCSRL3_BITS {     
	Uint16	RXRDY:1;			
	Uint16	FULL:1;				
	Uint16	OVERERROR3:1;		
	Uint16	DATAERRNAKTO:1;	
	Uint16	FLUSH:1;			
	Uint16	STALLREQPKT:1;		
	Uint16	STALLED:1;			
	Uint16	CLRDT:1;			
};

union USBRXCSRL3_REG {
	Uint16 	all;
	struct USBRXCSRL3_BITS	bit;
};

struct USBRXCSRH3_BITS {     
	Uint16	rsvd1:1;			
	Uint16	DT:1;				
	Uint16	DTWE:1;				
	Uint16	DMAMOD:1;			
	Uint16	DISNYETPIDERR:1;	
	Uint16	DMAEN:1;			
	Uint16	ISOAUTORQ:1;		
	Uint16	AUTOCL:1;			
};

union USBRXCSRH3_REG {
	Uint16 	all;
	struct USBRXCSRH3_BITS	bit;
};

struct USBRXCOUNT3_BITS {     
	Uint16	COUNT:13;			
	Uint16	rsvd1:3;			
};

union USBRXCOUNT3_REG {
	Uint32 all;
	struct USBRXCOUNT3_BITS	bit;
};

struct USBTXTYPE3_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBTXTYPE3_REG {
	Uint16 	all;
	struct USBTXTYPE3_BITS	bit;
};

struct USBRXTYPE3_BITS {     
	Uint16	TEP:4;				
	Uint16	PROTO:2;			
	Uint16	SPEED:2;			
};

union USBRXTYPE3_REG {
	Uint16 	all;
	struct USBRXTYPE3_BITS	bit;
};

struct USBRXDPKTBUFDIS_BITS {     
	Uint16	rsvd1:1;			
	Uint16	EP1:1;				
	Uint16	EP2:1;				
	Uint16	EP3:1;				
	Uint16	rsvd2:12;			
};

union USBRXDPKTBUFDIS_REG {
	Uint32 all;
	struct USBRXDPKTBUFDIS_BITS	bit;
};

struct USBTXDPKTBUFDIS_BITS {     
	Uint16	rsvd1:1;			
	Uint16	EP1:1;				
	Uint16	EP2:1;				
	Uint16	EP3:1;				
	Uint16	rsvd2:12;			
};

union USBTXDPKTBUFDIS_REG {
	Uint32 all;
	struct USBTXDPKTBUFDIS_BITS	bit;
};

struct USBEPC_BITS {     
	Uint16	EPEN:2;				
	Uint16	EPENDE:1;			
	Uint16	rsvd1:1;			
	Uint16	PFLTEN:1;			
	Uint16	PFLTSEN:1;			
	Uint16	PFLTAEN:1;			
	Uint16	rsvd2:1;			
	Uint16	PFLTACT:2;			
	Uint16	rsvd3:6;			
	Uint16	rsvd4:16;			
};

union USBEPC_REG {
	Uint64 all;
	struct USBEPC_BITS	bit;
};

struct USBEPCRIS_BITS {     
	Uint16	PF:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBEPCRIS_REG {
	Uint64 all;
	struct USBEPCRIS_BITS	bit;
};

struct USBEPCIM_BITS {     
	Uint16	PF:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBEPCIM_REG {
	Uint64 all;
	struct USBEPCIM_BITS	bit;
};

struct USBEPCISC_BITS {     
	Uint16	PF:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBEPCISC_REG {
	Uint64 all;
	struct USBEPCISC_BITS	bit;
};

struct USBDRRIS_BITS {     
	Uint16	RESUME:1;			
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBDRRIS_REG {
	Uint64 all;
	struct USBDRRIS_BITS	bit;
};

struct USBDRIM_BITS {     
	Uint16	RESUME:1;			
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBDRIM_REG {
	Uint64 all;
	struct USBDRIM_BITS	bit;
};

struct USBDRISC_BITS {     
	Uint16	RESUME:1;			
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBDRISC_REG {
	Uint64 all;
	struct USBDRISC_BITS	bit;
};

struct USBGPCS_BITS {     
	Uint16	DEVMOD:1;			
	Uint16	DEVMODOTG:1;		
	Uint16	rsvd1:14;			
	Uint16	rsvd2:16;			
};

union USBGPCS_REG {
	Uint64 all;
	struct USBGPCS_BITS	bit;
};

struct USBVDC_BITS {     
	Uint16	VBDEN:1;			
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBVDC_REG {
	Uint64 all;
	struct USBVDC_BITS	bit;
};

struct USBVDCRIS_BITS {     
	Uint16	VD:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBVDCRIS_REG {
	Uint64 all;
	struct USBVDCRIS_BITS	bit;
};

struct USBVDCIM_BITS {     
	Uint16	VD:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBVDCIM_REG {
	Uint64 all;
	struct USBVDCIM_BITS	bit;
};

struct USBVDCISC_BITS {     
	Uint16	VD:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBVDCISC_REG {
	Uint64 all;
	struct USBVDCISC_BITS	bit;
};

struct USBIDVRIS_BITS {     
	Uint16	ID:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBIDVRIS_REG {
	Uint64 all;
	struct USBIDVRIS_BITS	bit;
};

struct USBIDVIM_BITS {     
	Uint16	ID:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBIDVIM_REG {
	Uint64 all;
	struct USBIDVIM_BITS	bit;
};

struct USBIDVISC_BITS {     
	Uint16	ID:1;				
	Uint16	rsvd1:15;			
	Uint16	rsvd2:16;			
};

union USBIDVISC_REG {
	Uint64 all;
	struct USBIDVISC_BITS	bit;
};

struct USBDMASEL_BITS {     
	Uint16	DMAARX:4;			
	Uint16	DMAATX:4;			
	Uint16	DMABRX:4;			
	Uint16	DMABTX:4;			
	Uint16	DMACRX:4;			
	Uint16	DMACTX:4;			
	Uint16	rsvd1:8;			
};

union USBDMASEL_REG {
	Uint64 all;
	struct USBDMASEL_BITS	bit;
};

struct USB_REGS {
	union	USBFADDR_REG		USBFADDR;			
	union	USBPOWER_REG		USBPOWER;			
	union	USBTXIS_REG			USBTXIS;			
	union	USBRXIS_REG			USBRXIS;			
	union	USBTXIE_REG			USBTXIE;			
	union	USBRXIE_REG			USBRXIE;			
	union	USBIS_REG			USBIS;				
	union	USBIE_REG			USBIE;				
	union	USBFRAME_REG		USBFRAME;			
	union	USBEPIDX_REG		USBEPIDX;			
	union	USBTEST_REG			USBTEST;			
	Uint32						rsvd1[8];			
	Uint64						USBFIFO0;			
	Uint64						USBFIFO1;			
	Uint64						USBFIFO2;			
	Uint64						USBFIFO3;			
	Uint32						rsvd2[24];				
	union	USBDEVCTL_REG		USBDEVCTL;			
	union	USBTXFIFOSZ_REG		USBTXFIFOSZ;		
	union	USBRXFIFOSZ_REG		USBRXFIFOSZ;		
	union	USBTXFIFOADD_REG	USBTXFIFOADD;		
	union	USBRXFIFOADD_REG	USBRXFIFOADD;		
	Uint32						rsvd3[9];			
	union	USBCONTIM_REG		USBCONTIM;			
	Uint16						USBVPLEN;			
	Uint16						rsvd4[1];			
	Uint16						USBFSEOF;			
	Uint16						USBLSEOF;			
	Uint16						rsvd5[1];			
	union	USBTXFUNCADDR0_REG	USBTXFUNCADDR0;		
	Uint16						rsvd6[1];			
	union	USBTXHUBADDR0_REG	USBTXHUBADDR0;		
	union	USBTXHUBPORT0_REG	USBTXHUBPORT0;		
	Uint32						rsvd7[2];			
	union	USBTXFUNCADDR1_REG	USBTXFUNCADDR1;		
	Uint16						rsvd8[1];			
	union	USBTXHUBADDR1_REG	USBTXHUBADDR1;		
	union	USBTXHUBPORT1_REG	USBTXHUBPORT1;		
	union	USBRXFUNCADDR1_REG	USBRXFUNCADDR1;		
	Uint16						rsvd9[1];			
	union	USBRXHUBADDR1_REG	USBRXHUBADDR1;		
	union	USBRXHUBPORT1_REG	USBRXHUBPORT1;		
	union	USBTXFUNCADDR2_REG	USBTXFUNCADDR2;		
	Uint16						rsvd10[1];			
	union	USBTXHUBADDR2_REG	USBTXHUBADDR2;		
	union	USBTXHUBPORT2_REG	USBTXHUBPORT2;		
	union	USBRXFUNCADDR2_REG	USBRXFUNCADDR2;		
	Uint16						rsvd11[1];			
	union	USBRXHUBADDR2_REG	USBRXHUBADDR2;		
	union	USBRXHUBPORT2_REG	USBRXHUBPORT2;		
	union	USBTXFUNCADDR3_REG	USBTXFUNCADDR3;		
	Uint16						rsvd12[1];			
	union	USBTXHUBADDR3_REG	USBTXHUBADDR3;		
	union	USBTXHUBPORT3_REG	USBTXHUBPORT3;		
	union	USBRXFUNCADDR3_REG	USBRXFUNCADDR3;		
	Uint16						rsvd13[1];			
	union	USBRXHUBADDR3_REG	USBRXHUBADDR3;		
	union	USBRXHUBPORT3_REG	USBRXHUBPORT3;		
	Uint32						rsvd14[49];			
	union	USBCSRL0_REG		USBCSRL0;			
	union	USBCSRH0_REG		USBCSRH0;			
	Uint32						rsvd15[2];			
	union	USBCOUNT0_REG		USBCOUNT0;			
	Uint16						rsvd16[1];			
	union	USBTYPE0_REG		USBTYPE0;			
	union	USBNAKLMT_REG		USBNAKLMT;			
	Uint32						rsvd17[2];			
	union	USBTXMAXP1_REG		USBTXMAXP1;			
	union	USBTXCSRL1_REG		USBTXCSRL1;			
	union	USBTXCSRH1_REG		USBTXCSRH1;			
	union	USBRXMAXP1_REG		USBRXMAXP1;			
	union	USBRXCSRL1_REG		USBRXCSRL1;			
	union	USBRXCSRH1_REG		USBRXCSRH1;			
	union	USBRXCOUNT1_REG		USBRXCOUNT1;		
	union	USBTXTYPE1_REG		USBTXTYPE1;			
	Uint16						USBTXINTERVAL1;		
	union	USBRXTYPE1_REG		USBRXTYPE1;			
	Uint16						USBRXINTERVAL1;		
	Uint32						rsvd18;				
	union	USBTXMAXP2_REG		USBTXMAXP2;			
	union	USBTXCSRL2_REG		USBTXCSRL2;			
	union	USBTXCSRH2_REG		USBTXCSRH2;			
	union	USBRXMAXP2_REG		USBRXMAXP2;			
	union	USBRXCSRL2_REG		USBRXCSRL2;			
	union	USBRXCSRH2_REG		USBRXCSRH2;			
	union	USBRXCOUNT2_REG		USBRXCOUNT2;		
	union	USBTXTYPE2_REG		USBTXTYPE2;			
	Uint16						USBTXINTERVAL2;		
	union	USBRXTYPE2_REG		USBRXTYPE2;			
	Uint16						USBRXINTERVAL2;		
	Uint32						rsvd19;				
	union	USBTXMAXP3_REG		USBTXMAXP3;			
	union	USBTXCSRL3_REG		USBTXCSRL3;			
	union	USBTXCSRH3_REG		USBTXCSRH3;			
	union	USBRXMAXP3_REG		USBRXMAXP3;			
	union	USBRXCSRL3_REG		USBRXCSRL3;			
	union	USBRXCSRH3_REG		USBRXCSRH3;			
	union	USBRXCOUNT3_REG		USBRXCOUNT3;		
	union	USBTXTYPE3_REG		USBTXTYPE3;			
	Uint16						USBTXINTERVAL3;		
	union	USBRXTYPE3_REG		USBRXTYPE3;			
	Uint16						USBRXINTERVAL3;		
	Uint32						rsvd20[227];		
	Uint32						USBRQPKTCOUNT1;		
	Uint32						rsvd21;				
	Uint32						USBRQPKTCOUNT2;		
	Uint32						rsvd22;				
	Uint32						USBRQPKTCOUNT3;		
	Uint32						rsvd23[25];			
	union	USBRXDPKTBUFDIS_REG	USBRXDPKTBUFDIS;	
	union	USBTXDPKTBUFDIS_REG	USBTXDPKTBUFDIS;	
	Uint32						rsvd24[94];			
	union	USBEPC_REG			USBEPC;				
	union	USBEPCRIS_REG		USBEPCRIS;			
	union	USBEPCIM_REG		USBEPCIM;			
	union	USBEPCISC_REG		USBEPCISC;			
	union	USBDRRIS_REG		USBDRRIS;			
	union	USBDRIM_REG			USBDRIM;			
	union	USBDRISC_REG		USBDRISC;			
	union	USBGPCS_REG			USBGPCS;			
	Uint32						rsvd25[8];			
	union	USBVDC_REG			USBVDC;				
	union	USBVDCRIS_REG		USBVDCRIS;			
	union	USBVDCIM_REG		USBVDCIM;			
	union	USBVDCISC_REG		USBVDCISC;			
	Uint32						rsvd26[2];			
	union	USBIDVRIS_REG		USBIDVRIS;			
	union	USBIDVIM_REG		USBIDVIM;			
	union	USBIDVISC_REG		USBIDVISC;			
	union	USBDMASEL_REG		USBDMASEL;			
};




extern volatile struct	USB_REGS	Usb0Regs;





















struct XINTCR_BITS {
    Uint16   ENABLE:1;    
    Uint16   rsvd1:1;     
    Uint16   POLARITY:2;  
    Uint16   rsvd2:12;    
};

union XINTCR_REG {
   Uint16               all;
   struct XINTCR_BITS   bit;
};




struct XINTRUPT_REGS {
   union XINTCR_REG XINT1CR;
   union XINTCR_REG XINT2CR;
   union XINTCR_REG XINT3CR;
   Uint16           rsvd1[5];
   Uint16           XINT1CTR;
   Uint16           XINT2CTR;
   Uint16           XINT3CTR;
   Uint16           rsvd2[5];
};




extern volatile struct XINTRUPT_REGS XIntruptRegs;


































































































































 






 


 
typedef double Controller_FloatType;

 
extern const char * const Controller_checksum;

 
extern const char * Controller_errorStatus;


 
extern const double Controller_sampleTime;



 
typedef struct
{
   _Bool Delay1;                      
} Controller_ModelStates;
extern Controller_ModelStates Controller_X;


 
typedef struct
{
   _Bool Delay1;                      
   _Bool LogicalOperator1;            
} Controller_BlockOutputs;
extern Controller_BlockOutputs Controller_B;

 
void Controller_initialize(double time);
void Controller_step(void);
void Controller_terminate(void);




































 








 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


#pragma diag_push


 
 
#pragma CHECK_MISRA("-19.15")


#pragma diag_pop

#pragma diag_push

 
#pragma CHECK_MISRA("-19.1")
#pragma CHECK_MISRA("-19.15")

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

#pragma diag_push


 
 
#pragma CHECK_MISRA("-19.15")


#pragma diag_pop

#pragma diag_pop



 




 



 



 



 





 




 
typedef enum
{
   PIL_CLBK_LEAVE_NORMAL_OPERATION_REQ, 
   PIL_CLBK_ENTER_NORMAL_OPERATION_REQ, 
   PIL_CLBK_PREINIT_SIMULATION,      	
   PIL_CLBK_INITIALIZE_SIMULATION,      
   PIL_CLBK_TERMINATE_SIMULATION,       
   PIL_CLBK_STOP_TIMERS,                
   PIL_CLBK_START_TIMERS                
} PIL_CtrlCallbackReq_t;





 
extern void PilInitOverrideProbes(void);







 
extern void PilInitCalibrations(void);




 
typedef void(*PIL_CtrlCallbackPtr_t)(PIL_CtrlCallbackReq_t);





 
typedef void(*PIL_CommCallbackPtr_t)();




 
extern void PIL_init(void);







 
extern void PIL_setLinkParams(const unsigned char* aGuid, PIL_CommCallbackPtr_t aCommPtr);






 
extern void PIL_setNodeAddress(unsigned char aNode);






 
extern void PIL_setCtrlCallback(PIL_CtrlCallbackPtr_t aCtrlPtr);






 
extern void PIL_setBackgroundCommCallback(PIL_CommCallbackPtr_t aBackgroundCommPtr);







 
extern void PIL_allowPilSimulation(void);







 
extern void PIL_inhibitPilSimulation(void);






 
void PIL_requestNormalMode(void);






 
void PIL_requestReadyMode(void);





 
extern _Bool PIL_simulationActive(void);








 
extern void PIL_RA_serialIn(int16_t aChar);









 
extern _Bool PIL_RA_serialOut(int16_t* aChar);




 
extern _Bool PIL_RA_serialOutIsSynchronized(void);




 
extern void PIL_beginInterruptCall(void);



 
extern void PIL_backgroundCall(void);













 
extern void PIL_RA_parallelIn(uint16_t *aBuf, uint16_t aLen);
















 
extern void PIL_RA_parallelOut(uint16_t *aBuf, uint16_t *aLen);



 



 



 
extern const unsigned char PIL_D_Guid[];



 



 



 
typedef struct
{
   int q;       
   float ref;   
   char *unit;  
} pil_var;



 
typedef struct
{
   float min;	
   float max;	
   float dval;	
   int level;	
} pil_var_wa;



 



 



 



 




















 


typedef enum PWM_UNIT {
	PWM_EPWM_NONE=0,
	PWM_EPWM1,
	PWM_EPWM2,
	PWM_EPWM3,
	PWM_EPWM4,
	PWM_EPWM5,
	PWM_EPWM6,
	PWM_EPWM7,
	PWM_EPWM8
} PWM_Unit_t;

typedef struct PWM_CMP_READ_PROBES {
	PIL_READ_PROBE(uint16_t, CMP1, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP2, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP3, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP4, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP5, 0, 1.0, "");
	PIL_READ_PROBE(uint16_t, CMP6, 0, 1.0, "");
} PWM_CmpReadProbes_t;

typedef struct PWM_PARAMS {
	Uint16 TBPRD;
	union TBPHS_HRPWM_GROUP TBPHS;
	union TBCTL_REG TBCTL;
	union CMPCTL_REG CMPCTL;
	union AQCTL_REG AQCTLA;
	union DBCTL_REG DBCTL;
	Uint16 DBFED;
	Uint16 DBRED;
	union TZCTL_REG TZCTL;
	union ETSEL_REG ETSEL;
} PWM_Params_t;

typedef struct PWM_SOBJ
{
	PWM_CmpReadProbes_t cmp;
} PWM_SObj_t;

typedef struct PWM_OBJ
{
	uint16_t *cmprProbe;
	volatile struct EPWM_REGS *pwm;
} PWM_Obj_t;

typedef PWM_Obj_t *PWM_Handle_t;

extern void PWM_getRegisterBase(PWM_Unit_t aPwmChannel, volatile struct EPWM_REGS** aReg);

inline uint32_t PWM_getPeriod(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBPRD;
}

inline uint32_t PWM_getCounter(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBCTR;
}

inline _Bool PWM_getCountDirection(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	return obj->pwm->TBSTS.bit.CTRDIR;
}

inline void PWM_enableOut(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	__asm(" EALLOW");
	obj->pwm->TZCLR.bit.OST=1;
	__asm(" EDIS");
}

inline void PWM_disableOut(PWM_Handle_t aHandle)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;
	__asm(" EALLOW");
	obj->pwm->TZFRC.bit.OST=1;
	__asm(" EDIS");
}


extern void PWM_sinit();

extern PWM_Handle_t PWM_init(void *aMemory, const size_t aNumBytes);

extern void PWM_setDefaultParams(PWM_Params_t *aParams);

extern void PWM_configure(PWM_Handle_t aHandle, uint16_t aModulator, const PWM_Params_t *aParams);

extern void PWM_setCompare(PWM_Handle_t aHandle, uint16_t aCompare);

extern uint32_t PWM_getPeriod(PWM_Handle_t aHandle);

extern uint32_t PWM_getCounter(PWM_Handle_t aHandle);

extern _Bool PWM_getCountDirection(PWM_Handle_t aHandle);

extern void PWM_enableOut(PWM_Handle_t aHandle);

extern void PWM_disableOut(PWM_Handle_t aHandle);


#pragma diag_suppress 112 

PWM_SObj_t PWM_SObj;

void PWM_sinit()
{
	__asm(" EALLOW");
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1; 
	SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK = 1; 
	SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK = 1; 
	SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK = 1; 
	SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK = 1;	
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;	

	EPwm1Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	EPwm2Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	EPwm3Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	EPwm4Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	EPwm5Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	EPwm6Regs.TBCTL.bit.SYNCOSEL = 0x0; 
	__asm(" EDIS");
}

void PWM_getRegisterBase(PWM_Unit_t aPwmChannel, volatile struct EPWM_REGS** aReg){
	switch(aPwmChannel)
	{
		default:
			do { if(!(0)){ asm("        ESTOP0"); for(;;); }} while(0);
			break;
		case PWM_EPWM1:
			*aReg = &EPwm1Regs;
			break;
		case PWM_EPWM2:
			*aReg = &EPwm2Regs;
			break;
		case PWM_EPWM3:
			*aReg = &EPwm3Regs;
			break;
		case PWM_EPWM4:
			*aReg = &EPwm4Regs;
			break;
		case PWM_EPWM5:
			*aReg = &EPwm5Regs;
			break;
		case PWM_EPWM6:
			*aReg = &EPwm6Regs;
			break;
		case PWM_EPWM7:
			*aReg = &EPwm7Regs;
			break;
		case PWM_EPWM8:
			*aReg = &EPwm8Regs;
			break;
	}
}

void PWM_setDefaultParams(PWM_Params_t *aParams)
{
	aParams->TBPRD = 0;
	aParams->DBFED = 0;
	aParams->DBRED = 0;
	aParams->TBCTL.bit.SYNCOSEL = 0x0;

	aParams->TBPHS.half.TBPHS = 0; 
	aParams->TBCTL.bit.CTRMODE = 0x2; 
	aParams->TBCTL.bit.PHSEN = 0x0; 
	aParams->TBCTL.bit.PRDLD = 0x0;
	aParams->CMPCTL.bit.SHDWAMODE = 0x0;
	aParams->CMPCTL.bit.SHDWBMODE = 0x0;
	aParams->CMPCTL.bit.LOADAMODE = 0x0; 
	aParams->CMPCTL.bit.LOADBMODE = 0x0; 
	aParams->AQCTLA.bit.CAU = 0x2; 
	aParams->AQCTLA.bit.CAD = 0x1;
	aParams->DBCTL.bit.OUT_MODE = 0x3; 
	aParams->DBCTL.bit.POLSEL = 0x2; 
	aParams->TZCTL.bit.TZA = 0x2;
	aParams->TZCTL.bit.TZB = 0x2;

	aParams->ETSEL.bit.SOCASEL = 0x1;
	aParams->ETSEL.bit.INTSEL = 0x1;
}

PWM_Handle_t PWM_init(void *aMemory, const size_t aNumBytes)
{
	PWM_Handle_t handle;

	if(aNumBytes < sizeof(PWM_Obj_t))
		return((PWM_Handle_t)0);

	
	handle = (PWM_Handle_t)aMemory;

	return handle;
}

void PWM_configure(PWM_Handle_t aHandle, uint16_t aModulator, const PWM_Params_t *aParams)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;

	do { if(!(aModulator >= 1)){ asm("        ESTOP0"); for(;;); }} while(0);
	do { if(!(aModulator <= 6)){ asm("        ESTOP0"); for(;;); }} while(0);

	obj->cmprProbe = (uint16_t *)&PWM_SObj.cmp + sizeof(uint16_t)*(aModulator-1);

	
	switch(aModulator)
	{
		default:
		case 1:
			obj->pwm = &EPwm1Regs;
			break;
		case 2:
			obj->pwm = &EPwm2Regs;
			break;
		case 3:
			obj->pwm = &EPwm3Regs;
			break;
		case 4:
			obj->pwm = &EPwm4Regs;
			break;
		case 5:
			obj->pwm = &EPwm5Regs;
			break;
		case 6:
			obj->pwm = &EPwm6Regs;
			break;
	}

	__asm(" EALLOW");

	obj->pwm->TBPRD = aParams->TBPRD;
	obj->pwm->DBFED = aParams->DBFED;
	obj->pwm->DBRED = aParams->DBRED;
	obj->pwm->TBCTL.bit.SYNCOSEL = aParams->TBCTL.bit.SYNCOSEL;

	obj->pwm->TBPHS.half.TBPHS = aParams->TBPHS.half.TBPHS;
	obj->pwm->TBCTL.bit.CTRMODE = aParams->TBCTL.bit.CTRMODE;
	obj->pwm->TBCTL.bit.PHSEN = aParams->TBCTL.bit.PHSEN;
	obj->pwm->TBCTL.bit.PRDLD = aParams->TBCTL.bit.PRDLD;
	obj->pwm->CMPCTL.bit.SHDWAMODE = aParams->CMPCTL.bit.SHDWAMODE;
	obj->pwm->CMPCTL.bit.SHDWBMODE = aParams->CMPCTL.bit.SHDWBMODE;
	obj->pwm->CMPCTL.bit.LOADAMODE = aParams->CMPCTL.bit.SHDWAMODE;
	obj->pwm->CMPCTL.bit.LOADBMODE = aParams->CMPCTL.bit.SHDWBMODE;
	obj->pwm->AQCTLA.bit.CAU = aParams->AQCTLA.bit.CAU;
	obj->pwm->AQCTLA.bit.CAD = aParams->AQCTLA.bit.CAD;
	obj->pwm->DBCTL.bit.OUT_MODE = aParams->DBCTL.bit.OUT_MODE;
	obj->pwm->DBCTL.bit.POLSEL = aParams->DBCTL.bit.POLSEL;
	obj->pwm->TZCTL.bit.TZA = aParams->TZCTL.bit.TZA;
	obj->pwm->TZCTL.bit.TZB = aParams->TZCTL.bit.TZB;

	obj->pwm->ETSEL.bit.SOCASEL = aParams->ETSEL.bit.SOCASEL;
	obj->pwm->ETSEL.bit.INTSEL = aParams->ETSEL.bit.INTSEL;

	
	obj->pwm->TZFRC.bit.OST=1;

	switch(aModulator)
	{
		default:
		case 1:
			GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;
			break;
		case 2:
			GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;
			break;
		case 3:
			GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;
			break;
		case 4:
			GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;
			break;
		case 5:
			GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;
			break;
		case 6:
			GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;
			GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;
			break;
	}

	__asm(" EDIS");
}

void PWM_setCompare(PWM_Handle_t aHandle, uint16_t aCompare)
{
	PWM_Obj_t *obj = (PWM_Obj_t *)aHandle;

	*(obj->cmprProbe) = aCompare;
	obj->pwm->CMPA.half.CMPA = aCompare;
}