/* TA-LIB Copyright (c) 1999-2004, Mario Fortier
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
 *  AC       Angelo Ciceri
 *
 *
 * Change history:
 *
 *  MMDDYY BY   Description
 *  -------------------------------------------------------------------
 *  011505 AC   Creation           
 *
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
/* Generated */ int Core::CDLDRAGONFLYDOJI_Lookback( void )
/* Generated */ 
/* Generated */ #else
/* Generated */ int TA_CDLDRAGONFLYDOJI_Lookback( void )
/* Generated */ 
/* Generated */ #endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/
{
   /* insert lookback code here. */
    return max( TA_CANDLEAVGPERIOD(TA_BodyDoji), TA_CANDLEAVGPERIOD(TA_ShadowVeryShort) );
}

/**** START GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
/*
 * TA_CDLDRAGONFLYDOJI - Dragonfly Doji
 * 
 * Input  = Open, High, Low, Close
 * Output = int
 * 
 */
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ enum class Core::TA_RetCode Core::CDLDRAGONFLYDOJI( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     cli::array<double>^ inOpen,
/* Generated */                                                     cli::array<double>^ inHigh,
/* Generated */                                                     cli::array<double>^ inLow,
/* Generated */                                                     cli::array<double>^ inClose,
/* Generated */                                                     [OutAttribute]int^ outBegIdx,
/* Generated */                                                     [OutAttribute]int^ outNbElement,
/* Generated */                                                     cli::array<int>^  outInteger )
/* Generated */ #else
/* Generated */ TA_RetCode TA_CDLDRAGONFLYDOJI( int    startIdx,
/* Generated */                                 int    endIdx,
/* Generated */                                 const double inOpen[],
/* Generated */                                 const double inHigh[],
/* Generated */                                 const double inLow[],
/* Generated */                                 const double inClose[],
/* Generated */                                 int          *outBegIdx,
/* Generated */                                 int          *outNbElement,
/* Generated */                                 int           outInteger[] )
/* Generated */ #endif
/**** END GENCODE SECTION 2 - DO NOT DELETE THIS LINE ****/
{
   /* Insert local variables here. */
    double BodyDojiPeriodTotal, ShadowVeryShortPeriodTotal;
    int i, outIdx, BodyDojiTrailingIdx, ShadowVeryShortTrailingIdx, lookbackTotal;

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
/* Generated */    /* Verify required price component. */
/* Generated */    if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */    if( !outInteger )
/* Generated */       return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */ 
/* Generated */ #endif /* TA_FUNC_NO_RANGE_CHECK */
/* Generated */ 
/**** END GENCODE SECTION 3 - DO NOT DELETE THIS LINE ****/

   /* Identify the minimum number of price bar needed
    * to calculate at least one output.
    */

   lookbackTotal = TA_CDLDRAGONFLYDOJI_Lookback();

   /* Move up the start index if there is not
    * enough initial data.
    */
   if( startIdx < lookbackTotal )
      startIdx = lookbackTotal;

   /* Make sure there is still something to evaluate. */
   if( startIdx > endIdx )
   {
      VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
      VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
      return NAMESPACE(TA_RetCode)TA_SUCCESS;
   }

   /* Do the calculation using tight loops. */
   /* Add-up the initial period, except for the last value. */
   BodyDojiPeriodTotal = 0;
   BodyDojiTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyDoji);
   ShadowVeryShortPeriodTotal = 0;
   ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
   
   i = BodyDojiTrailingIdx;
   while( i < startIdx ) {
        BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i );
        i++;
   }
   i = ShadowVeryShortTrailingIdx;
   while( i < startIdx ) {
        ShadowVeryShortPeriodTotal += TA_CANDLERANGE( TA_ShadowVeryShort, i );
        i++;
   }

   /* Proceed with the calculation for the requested range.
    *
    * Must have:
    * - doji body
    * - open and close at the high of the day = no or very short upper shadow
    * - lower shadow (to distinguish from other dojis, here lower shadow should not be very short)
    * The meaning of "doji" and "very short" is specified with TA_SetCandleSettings
    * outInteger is always positive (1 to 100) but this does not mean it is bullish: dragonfly doji must be considered
    * relatively to the trend
    */
   outIdx = 0;
   do
   {
        if( TA_REALBODY(i) <= TA_CANDLEAVERAGE( TA_BodyDoji, BodyDojiPeriodTotal, i ) &&
            TA_UPPERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal, i ) &&
            TA_LOWERSHADOW(i) > TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal, i )
          )
            outInteger[outIdx++] = 100;
        else
            outInteger[outIdx++] = 0;
        /* add the current range and subtract the first range: this is done after the pattern recognition 
         * when avgPeriod is not 0, that means "compare with the previous candles" (it excludes the current candle)
         */
        BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i ) - TA_CANDLERANGE( TA_BodyDoji, BodyDojiTrailingIdx );
        ShadowVeryShortPeriodTotal += TA_CANDLERANGE( TA_ShadowVeryShort, i ) 
                                    - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx );
        i++; 
        BodyDojiTrailingIdx++;
        ShadowVeryShortTrailingIdx++;
   } while( i <= endIdx );

   /* All done. Indicate the output limits and return. */
   VALUE_HANDLE_DEREF(outNbElement) = outIdx;
   VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;

   return NAMESPACE(TA_RetCode)TA_SUCCESS;
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
/* Generated */ enum class Core::TA_RetCode Core::CDLDRAGONFLYDOJI( int    startIdx,
/* Generated */                                                     int    endIdx,
/* Generated */                                                     cli::array<float>^ inOpen,
/* Generated */                                                     cli::array<float>^ inHigh,
/* Generated */                                                     cli::array<float>^ inLow,
/* Generated */                                                     cli::array<float>^ inClose,
/* Generated */                                                     [OutAttribute]int^ outBegIdx,
/* Generated */                                                     [OutAttribute]int^ outNbElement,
/* Generated */                                                     cli::array<int>^  outInteger )
/* Generated */ #else
/* Generated */ TA_RetCode TA_S_CDLDRAGONFLYDOJI( int    startIdx,
/* Generated */                                   int    endIdx,
/* Generated */                                   const float  inOpen[],
/* Generated */                                   const float  inHigh[],
/* Generated */                                   const float  inLow[],
/* Generated */                                   const float  inClose[],
/* Generated */                                   int          *outBegIdx,
/* Generated */                                   int          *outNbElement,
/* Generated */                                   int           outInteger[] )
/* Generated */ #endif
/* Generated */ {
/* Generated */     double BodyDojiPeriodTotal, ShadowVeryShortPeriodTotal;
/* Generated */     int i, outIdx, BodyDojiTrailingIdx, ShadowVeryShortTrailingIdx, lookbackTotal;
/* Generated */  #ifndef TA_FUNC_NO_RANGE_CHECK
/* Generated */     if( startIdx < 0 )
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_START_INDEX;
/* Generated */     if( (endIdx < 0) || (endIdx < startIdx))
/* Generated */        return NAMESPACE(TA_RetCode)TA_OUT_OF_RANGE_END_INDEX;
/* Generated */     if(!inOpen||!inHigh||!inLow||!inClose)
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */     if( !outInteger )
/* Generated */        return NAMESPACE(TA_RetCode)TA_BAD_PARAM;
/* Generated */  #endif 
/* Generated */    lookbackTotal = TA_CDLDRAGONFLYDOJI_Lookback();
/* Generated */    if( startIdx < lookbackTotal )
/* Generated */       startIdx = lookbackTotal;
/* Generated */    if( startIdx > endIdx )
/* Generated */    {
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outBegIdx);
/* Generated */       VALUE_HANDLE_DEREF_TO_ZERO(outNbElement);
/* Generated */       return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */    }
/* Generated */    BodyDojiPeriodTotal = 0;
/* Generated */    BodyDojiTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_BodyDoji);
/* Generated */    ShadowVeryShortPeriodTotal = 0;
/* Generated */    ShadowVeryShortTrailingIdx = startIdx - TA_CANDLEAVGPERIOD(TA_ShadowVeryShort);
/* Generated */    i = BodyDojiTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    i = ShadowVeryShortTrailingIdx;
/* Generated */    while( i < startIdx ) {
/* Generated */         ShadowVeryShortPeriodTotal += TA_CANDLERANGE( TA_ShadowVeryShort, i );
/* Generated */         i++;
/* Generated */    }
/* Generated */    outIdx = 0;
/* Generated */    do
/* Generated */    {
/* Generated */         if( TA_REALBODY(i) <= TA_CANDLEAVERAGE( TA_BodyDoji, BodyDojiPeriodTotal, i ) &&
/* Generated */             TA_UPPERSHADOW(i) < TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal, i ) &&
/* Generated */             TA_LOWERSHADOW(i) > TA_CANDLEAVERAGE( TA_ShadowVeryShort, ShadowVeryShortPeriodTotal, i )
/* Generated */           )
/* Generated */             outInteger[outIdx++] = 100;
/* Generated */         else
/* Generated */             outInteger[outIdx++] = 0;
/* Generated */         BodyDojiPeriodTotal += TA_CANDLERANGE( TA_BodyDoji, i ) - TA_CANDLERANGE( TA_BodyDoji, BodyDojiTrailingIdx );
/* Generated */         ShadowVeryShortPeriodTotal += TA_CANDLERANGE( TA_ShadowVeryShort, i ) 
/* Generated */                                     - TA_CANDLERANGE( TA_ShadowVeryShort, ShadowVeryShortTrailingIdx );
/* Generated */         i++; 
/* Generated */         BodyDojiTrailingIdx++;
/* Generated */         ShadowVeryShortTrailingIdx++;
/* Generated */    } while( i <= endIdx );
/* Generated */    VALUE_HANDLE_DEREF(outNbElement) = outIdx;
/* Generated */    VALUE_HANDLE_DEREF(outBegIdx)    = startIdx;
/* Generated */    return NAMESPACE(TA_RetCode)TA_SUCCESS;
/* Generated */ }
/* Generated */ 
/* Generated */ #if defined( _MANAGED )
/* Generated */ }} // Close namespace TA.Lib
/* Generated */ #endif
/**** END GENCODE SECTION 4 - DO NOT DELETE THIS LINE ****/

