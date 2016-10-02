#ifndef __MYEVIC_H__
#define __MYEVIC_H__

#include "M451Series.h"
#include "dtmacros.h"

//=========================================================================

#define __myevic__ __attribute__ ((section (".myevic")))

//-------------------------------------------------------------------------

#define CPU_FREQ		72000000
#define PLL_FREQ		(CPU_FREQ<<1)

#define BBC_PWM_FREQ	150000

//-------------------------------------------------------------------------

#define	ISMODETC(m) ((m)<=3)
#define ISMODEVW(m) (((m)==4)||((m)==6))
#define ISMODEBY(m) ((m)==5)

//-------------------------------------------------------------------------

#define FWVERSION	330

#define __BUILD1	( __DAY__ + __MONTH__ * 100 + ( __YEAR__ % 100 ) * 10000 )

#define __BUILD2	(	__DAY__ % 10 + __DAY__ / 10 << 4 \
					+	__MONTH__ % 10 << 8 + __MONTH__ / 10 << 12 \
					+	__YEAR__ % 10 << 16 + __YEAR__ / 10 % 10 << 20 )

//-------------------------------------------------------------------------

#define PID_VTCMINI		(*(uint32_t*)"E052")
#define PID_VTWOMINI	(*(uint32_t*)"E115")
#define PID_VTWO		(*(uint32_t*)"E043")
#define PID_PRESA75W	(*(uint32_t*)"W007")
#define PID_EVICAIO		(*(uint32_t*)"E092")
#define PID_EGRIPII		(*(uint32_t*)"E083")
#define PID_CUBOMINI	(*(uint32_t*)"E056")
#define PID_EVICBASIC	(*(uint32_t*)"E150")

#define ISVTCMINI	(!gFlags.is_vtwo && gFlags.is_mini)
#define ISVTWOMINI	(gFlags.is_vtwo && gFlags.is_mini)
#define ISVTWO		(gFlags.is_vtwo && !gFlags.is_mini)
#define ISPRESA75W	(gFlags.is_presa && gFlags.is_mini)
#define ISEVICAIO	(gFlags.is_evicaio)
#define ISEGRIPII	(gFlags.is_egrip2)
#define ISCUBOMINI	(gFlags.is_cuboid && gFlags.is_mini)
#define ISEVICBASIC	(gFlags.is_evicbasic)


//=========================================================================
// Global flags bitfield
//-------------------------------------------------------------------------

typedef struct
{
/* 00000001 */	int	tick_5khz:1;
/* 00000002 */	int	tick_1khz:1;
/* 00000004 */	int	tick_us:1;
/* 00000008 */	int	tick_100hz:1;
/* 00000010 */	int	tick_10hz:1;
/* 00000020 */	int	tick_5hz:1;
/* 00000040 */	int	tick_2hz:1;
/* 00000080 */	int read_battery:1;

/* 00000100 */	int firing:1;
/* 00000200 */	int low_battery:1;
/* 00000400 */	int usb_attached:1;
/* 00000800 */	int refresh_battery:1;
/* 00001000 */	int battery_charging:1;
/* 00002000 */	int probing_ato:1;
/* 00004000 */	int user_idle:1;
/* 00008000 */	int sample_vbat:1;

/* 00010000 */	int sample_btemp:1;
/* 00020000 */	int refresh_display:1;
/* 00040000 */	int draw_edited_item:1;
/* 00080000 */	int battery_10pc:1;
/* 00100000 */	int draw_battery:1;
/* 00200000 */	int draw_battery_charging:1;
/* 00400000 */	int decrease_voltage:1;
/* 00800000 */	int check_mode:1;

/* 01000000 */	int unused1:1;
/* 02000000 */	int unused2:1;
/* 04000000 */	int limit_ato_temp:1;
/* 08000000 */	int check_rez_ti:1;
/* 10000000 */	int check_rez_ni:1;
/* 20000000 */	int limit_power:1;
/* 40000000 */	int unused3:1;
/* 80000000 */	int check_rez_ss:1;

/* 00000001 */	int edit_value:1;
/* 00000002 */	int check_rez_tcr:1;
/* 00000004 */	int unused4:1;
/* 00000008 */	int unused5:1;
/* 00000010 */	int edit_capture_evt:1;
/* 00000020 */	int osc_1hz:1;
/* 00000040 */	int unused7:1;
/* 00000080 */	int unused8:1;

/* 00000100 */	int	tick_1hz:1;
/* 00000200 */	int	playing_fb:1;
/* 00000400 */	int has_x32:1;
/* 00000800 */	int is_mini:1;
/* 00001000 */	int is_vtwo:1;
/* 00002000 */	int is_presa:1;
/* 00004000 */	int is_evicaio:1;
/* 00008000 */	int is_egrip2:1;

/* 00010000 */	int is_cuboid:1;
/* 00020000 */	int is_evicbasic:1;
/* 00040000 */	int debug:1;
/* 00080000 */	int noclock:1;
/* 00100000 */	int read_bir:1;
/* 00200000 */	int pwm_pll:1;
}
gFlags_t;

extern volatile gFlags_t gFlags;

//=========================================================================
// Functions from assembly language part
//-------------------------------------------------------------------------

extern void MemCpy( void*, const void*, const uint32_t );
extern void MemCpy2( const void*, void*, const uint32_t );
extern void MemClear( void*, const uint32_t );
extern void MemClear2( void*, void*, const uint32_t );
extern void MemSet( void*, const uint32_t, const char );

extern void DrawHexDigit( int x, int y, int v );
extern void DrawHexLong( int x, int y, int v, int font );

//-------------------------------------------------------------------------

extern uint32_t sqrtul( uint32_t v );
extern uint32_t GetFirmwareSize();

//=========================================================================
#endif /* __MYEVIC_H__ */
