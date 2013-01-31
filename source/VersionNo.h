
#define FILEVER_1        2
#define FILEVER_2        2
#define FILEVER_3        0
#define FILEVER_4        0


#define FILEVER        FILEVER_1,FILEVER_2,FILEVER_3,FILEVER_4

#define PPCAT_NX(A, B) A. ## B
#define PPCAT(A, B) PPCAT_NX(A, B)
#define STRINGIZE_NX(A) #A
#define STRINGIZE(A) STRINGIZE_NX(A)

#if FILEVER_4 > 0
	#define STRFILEVER     STRINGIZE( PPCAT(FILEVER_1, PPCAT(FILEVER_2,PPCAT(FILEVER_3,FILEVER_4))) )
#elif FILEVER_3 > 0
	#define STRFILEVER     STRINGIZE( PPCAT(FILEVER_1, PPCAT(FILEVER_2,FILEVER_3)) )
#else
	#define STRFILEVER    STRINGIZE( PPCAT(FILEVER_1,FILEVER_2) )
#endif


