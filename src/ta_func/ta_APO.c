/* TA-LIB Copyright (c) 1999-2005, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* List of contributors:
 *
 *  Initial  Name/description
 *  -------------------------------------------------------------------
 *  MF       Mario Fortier
 *  AA       Andrew Atkinson
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  112400 MF   Template creation.
 *  052603 MF   Adapt code to compile with .NET Managed C++
 *  062804 MF   Resolve div by zero bug on limit case.
 *  020605 AA   Fix #1117666 Lookback & out-of-bound bug.
 */

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
/* All code within this section is automatically
 * generated by gen_code. Any modification will be lost
 * next time gen_code is run.
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */    #include "TA-Lib-Core.h"
/* Generated */    #define TA_INTERNAL_ERROR(Id) (NAMESPACE(TA_RetCode)TA_INTERNAL_ERROR)
/* Generated */    namespace TA { namespace Lib {
/* Generated */ #else
/* Generated */    #include <string.h>
/* Generated */    #include <math.h>
/* Generated */    #include "ta_func.h"
/* Generated */    #include "ta_trace.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_UTILITY_H
/* Generated */    #include "ta_utility.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #ifndef TA_MEMORY_H
/* Generated */    #include "ta_memory.h"
/* Generated */ #endif
/* Generated */ 
/* Generated */ #define TA_PREFIX(x) TA_##x
/* Generated */ #define INPUT_TYPE   double
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ int Core::APO_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                       int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                       TA_MAType     optInMAType ) /* Generated */ 
/* Generated */ #else
/* Generated */ int TA_APO_Lookback( int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                    int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                    TA_MAType     optInMAType ) /* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */

   /* The slow MA is the key factor determining the lookback period. */
   return TA_MA_Lookback( max(optInSlowPeriod,optInFastPeriod), optInMAType );
}


/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_APO - Absolute Price Oscillator
 * 
 * Input  = double
 * Output = double
 * 
 * Optional Parameters
 * -------------------
 * optInFastPeriod:(From 2 to 100000)
 *    Number of period for the fast MA
 * 
 * optInSlowPeriod:(From 2 to 100000)
 *    Number of period for the slow MA
 * 
 * optInMAType:
 *    Type of Moving Average
 * 
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::APO( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<double>^ inReal,
/* Generated */                                        int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                        TA_MAType     optInMAType,
/* Generated */                                        [OutAttribute]int^ outBegIdx,
/* Generated */                                        [OutAttribute]int^ outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #else
/* Generated */ TA_RetCode TA_APO( int    startIdx,
/* Generated */                    int    endIdx,
/* Generated */                    const double inReal[],
/* Generated */                    int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                    int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                    TA_MAType     optInMAType,
/* Generated */                    int          *outBegIdx,
/* Generated */                    int          *outNbElement,
/* Generated */                    double        outReal[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
   ARRAY_REF(tempBuffer);
   TA_RetCode retCode;

/**** START GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */ 
/* Generated */    /* Validate the requested output range. */
/* Generated */    if( startIdx < 0 )
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */    if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */       return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */ 
/* Generated */    /* Validate the parameters. */
/* Generated */    if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */    /* min/max are checked for optInFastPeriod. */
/* Generated */    if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInFastPeriod = 12;
/* Generated */    else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    /* min/max are checked for optInSlowPeriod. */
/* Generated */    if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */       optInSlowPeriod = 26;
/* Generated */    else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #if !defined(_MANAGED)
/* Generated */    if( (int)optInMAType == TA_INTEGER_DEFAULT )
/* Generated */       optInMAType = 0;
/* Generated */    else if( ((int)optInMAType < 0) || ((int)optInMAType > 8) )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    #endif /* !defined(_MANAGED) */
/* Generated */    if( !outReal )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Insert TA function code here. */

   /* Allocate an intermediate buffer. */
   ARRAY_ALLOC(tempBuffer, (endIdx-startIdx+1) );
   if( !tempBuffer )
      return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;

   retCode = TA_PREFIX(INT_PO)( startIdx, endIdx,                        
                              inReal,
                              optInFastPeriod, /* From 1 to 200 */
                              optInSlowPeriod, /* From 1 to 200 */
                              optInMAType,
                              outBegIdx,
                              outNbElement,
                              outReal,
                              tempBuffer,
                              0 /* No percentage. */ );

   ARRAY_FREE( tempBuffer );

   return retCode;
}

/* Internal price oscillator function.
 *
 * A buffer must be provided for intermediate processing.
 */
#if defined( _MANAGED )
 enum class Core::TA_RetCode Core::TA_INT_PO( int    startIdx,
                                              int    endIdx,
											  cli::array<INPUT_TYPE>^ inReal,
                                              int    optInFastPeriod, /* From 1 to 200 */
                                              int    optInSlowPeriod, /* From 1 to 200 */
                                              TA_MAType    optInMethod_2,
                                              [OutAttribute]int^ outBegIdx,
                                              [OutAttribute]int^ outNbElement,
											  cli::array<double>^ outReal,
                                              cli::array<double>^ tempBuffer,
                                              unsigned int  doPercentageOutput )
#else
TA_RetCode TA_PREFIX(INT_PO)( int    startIdx,
                              int    endIdx,
                              const INPUT_TYPE *inReal,
                              int    optInFastPeriod, /* From 1 to 200 */
                              int    optInSlowPeriod, /* From 1 to 200 */
                              TA_MAType optInMethod_2,
                              int   VALUE_HANDLE_DEREF(outBegIdx),
                              int   VALUE_HANDLE_DEREF(outNbElement),
                              double      *outReal,
                              double      *tempBuffer,
                              unsigned int  doPercentageOutput )
#endif
{
   TA_RetCode retCode;

   double tempReal;
   int tempInteger;
   VALUE_HANDLE(int,outBegIdx1);
   VALUE_HANDLE(int,outNbElement1);
   VALUE_HANDLE(int,outBegIdx2);
   VALUE_HANDLE(int,outNbElement2);

   int i, j;

   /* Make sure slow is really slower than
    * the fast period! if not, swap...
    */
   if( optInSlowPeriod < optInFastPeriod )
   {
       /* swap */
       tempInteger     = optInSlowPeriod;
       optInSlowPeriod = optInFastPeriod;
       optInFastPeriod = tempInteger;
   }

   /* Calculate the fast MA into the tempBuffer. */
   retCode = TA_PREFIX(MA)( startIdx, endIdx,
                            inReal,
                            optInFastPeriod, /* From 1 to 200 */
                            optInMethod_2,                    
                            VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2),
							tempBuffer );

   if( retCode == NAMESPACE(TA_RetCode)TA_SUCCESS )
   {
      /* Calculate the slow MA into the output. */
      retCode = TA_PREFIX(MA)( startIdx, endIdx,                       
                               inReal,
                               optInSlowPeriod, /* From 1 to 200 */
                               optInMethod_2,
                               VALUE_HANDLE_OUT(outBegIdx1), VALUE_HANDLE_OUT(outNbElement1),
							   outReal );

      if( retCode == NAMESPACE(TA_RetCode)TA_SUCCESS )
      {
         tempInteger = (int)outBegIdx1 - (int)outBegIdx2;
         if( doPercentageOutput )
         {
            /* Calculate ((fast MA)-(slow MA))/(slow MA) in the output. */   
            for( i=0,j=tempInteger; i < (int)outNbElement1; i++, j++ )
            {
               tempReal = outReal[i];
               if( !TA_IS_ZERO(tempReal) )
                  outReal[i] = ((tempBuffer[j]-tempReal)/tempReal)*100.0;
               else
                  outReal[i] = 0.0;
            }
         }
         else
         {
            /* Calculate (fast MA)-(slow MA) in the output. */   
            for( i=0,j=tempInteger; i < (int)outNbElement1; i++, j++ )
               outReal[i] = tempBuffer[j]-outReal[i];
         }

         VALUE_HANDLE_DEREF(outBegIdx)     = (int)outBegIdx1;
         VALUE_HANDLE_DEREF(outNbElement)  = (int)outNbElement1;
      }
   }

   if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
   }

   return retCode;
}

/**** START GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/
/* Generated */ 
/* Generated */ #define  USE_SINGLE_PRECISION_INPUT
/* Generated */ #if !defined( _MANAGED )
/* Generated */    #undef   TA_PREFIX
/* Generated */    #define  TA_PREFIX(x) TA_S_##x
/* Generated */ #endif
/* Generated */ #undef   INPUT_TYPE
/* Generated */ #define  INPUT_TYPE float
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::APO( int    startIdx,
/* Generated */                                        int    endIdx,
/* Generated */                                        cli::array<float>^ inReal,
/* Generated */                                        int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                                        int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                                        TA_MAType     optInMAType,
/* Generated */                                        [OutAttribute]int^ outBegIdx,
/* Generated */                                        [OutAttribute]int^ outNbElement,
/* Generated */                                        cli::array<double>^  outReal )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_APO( int    startIdx,
/* Generated */                      int    endIdx,
/* Generated */                      const float  inReal[],
/* Generated */                      int           optInFastPeriod, /* From 2 to 100000 */
/* Generated */                      int           optInSlowPeriod, /* From 2 to 100000 */
/* Generated */                      TA_MAType     optInMAType,
/* Generated */                      int          *outBegIdx,
/* Generated */                      int          *outNbElement,
/* Generated */                      double        outReal[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */    ARRAY_REF(tempBuffer);
/* Generated */    TA_RetCode retCode;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if( !inReal ) return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( (int)optInFastPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInFastPeriod = 12;
/* Generated */     else if( ((int)optInFastPeriod < 2) || ((int)optInFastPeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( (int)optInSlowPeriod == TA_INTEGER_DEFAULT )
/* Generated */        optInSlowPeriod = 26;
/* Generated */     else if( ((int)optInSlowPeriod < 2) || ((int)optInSlowPeriod > 100000) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #if !defined(_MANAGED)
/* Generated */     if( (int)optInMAType == TA_INTEGER_DEFAULT )
/* Generated */        optInMAType = 0;
/* Generated */     else if( ((int)optInMAType < 0) || ((int)optInMAType > 8) )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     #endif 
/* Generated */     if( !outReal )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    ARRAY_ALLOC(tempBuffer, (endIdx-startIdx+1) );
/* Generated */    if( !tempBuffer )
/* Generated */       return NAMESPACE(TA_RetCode)TA_ALLOC_ERR;
/* Generated */    retCode = TA_PREFIX(INT_PO)( startIdx, endIdx,                        
/* Generated */                               inReal,
/* Generated */                               optInFastPeriod, 
/* Generated */                               optInSlowPeriod, 
/* Generated */                               optInMAType,
/* Generated */                               outBegIdx,
/* Generated */                               outNbElement,
/* Generated */                               outReal,
/* Generated */                               tempBuffer,
/* Generated */                               0  );
/* Generated */    ARRAY_FREE( tempBuffer );
/* Generated */    return retCode;
/* Generated */ }
/* Generated */ #if defined( _MANAGED )
/* Generated */  enum class Core::TA_RetCode Core::TA_INT_PO( int    startIdx,
/* Generated */                                               int    endIdx,
/* Generated */ 											  cli::array<INPUT_TYPE>^ inReal,
/* Generated */                                               int    optInFastPeriod, 
/* Generated */                                               int    optInSlowPeriod, 
/* Generated */                                               TA_MAType    optInMethod_2,
/* Generated */                                               [OutAttribute]int^ outBegIdx,
/* Generated */                                               [OutAttribute]int^ outNbElement,
/* Generated */ 											  cli::array<double>^ outReal,
/* Generated */                                               cli::array<double>^ tempBuffer,
/* Generated */                                               unsigned int  doPercentageOutput )
/* Generated */ #else
/* Generated */ TA_RetCode TA_PREFIX(INT_PO)( int    startIdx,
/* Generated */                               int    endIdx,
/* Generated */                               const INPUT_TYPE *inReal,
/* Generated */                               int    optInFastPeriod, 
/* Generated */                               int    optInSlowPeriod, 
/* Generated */                               TA_MAType optInMethod_2,
/* Generated */                               int   VALUE_HANDLE_DEREF(outBegIdx),
/* Generated */                               int   VALUE_HANDLE_DEREF(outNbElement),
/* Generated */                               double      *outReal,
/* Generated */                               double      *tempBuffer,
/* Generated */                               unsigned int  doPercentageOutput )
/* Generated */ #endif
/* Generated */ {
/* Generated */    TA_RetCode retCode;
/* Generated */    double tempReal;
/* Generated */    int tempInteger;
/* Generated */    VALUE_HANDLE(int,outBegIdx1);
/* Generated */    VALUE_HANDLE(int,outNbElement1);
/* Generated */    VALUE_HANDLE(int,outBegIdx2);
/* Generated */    VALUE_HANDLE(int,outNbElement2);
/* Generated */    int i, j;
/* Generated */    if( optInSlowPeriod < optInFastPeriod )
/* Generated */    {
/* Generated */        tempInteger     = optInSlowPeriod;
/* Generated */        optInSlowPeriod = optInFastPeriod;
/* Generated */        optInFastPeriod = tempInteger;
/* Generated */    }
/* Generated */    retCode = TA_PREFIX(MA)( startIdx, endIdx,
/* Generated */                             inReal,
/* Generated */                             optInFastPeriod, 
/* Generated */                             optInMethod_2,                    
/* Generated */                             VALUE_HANDLE_OUT(outBegIdx2), VALUE_HANDLE_OUT(outNbElement2),
/* Generated */ 							tempBuffer );
/* Generated */    if( retCode == NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */    {
/* Generated */       retCode = TA_PREFIX(MA)( startIdx, endIdx,                       
/* Generated */                                inReal,
/* Generated */                                optInSlowPeriod, 
/* Generated */                                optInMethod_2,
/* Generated */                                VALUE_HANDLE_OUT(outBegIdx1), VALUE_HANDLE_OUT(outNbElement1),
/* Generated */ 							   outReal );
/* Generated */       if( retCode == NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */       {
/* Generated */          tempInteger = (int)outBegIdx1 - (int)outBegIdx2;
/* Generated */          if( doPercentageOutput )
/* Generated */          {
/* Generated */             for( i=0,j=tempInteger; i < (int)outNbElement1; i++, j++ )
/* Generated */             {
/* Generated */                tempReal = outReal[i];
/* Generated */                if( !TA_IS_ZERO(tempReal) )
/* Generated */                   outReal[i] = ((tempBuffer[j]-tempReal)/tempReal)*100.0;
/* Generated */                else
/* Generated */                   outReal[i] = 0.0;
/* Generated */             }
/* Generated */          }
/* Generated */          else
/* Generated */          {
/* Generated */             for( i=0,j=tempInteger; i < (int)outNbElement1; i++, j++ )
/* Generated */                outReal[i] = tempBuffer[j]-outReal[i];
/* Generated */          }
/* Generated */          VALUE_HANDLE_DEREF(outBegIdx)     = (int)outBegIdx1;
/* Generated */          VALUE_HANDLE_DEREF(outNbElement)  = (int)outNbElement1;
/* Generated */       }
/* Generated */    }
/* Generated */    if( retCode != NAMESPACE(TA_RetCode)TA_SUCCESS )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */    }
/* Generated */    return retCode;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

