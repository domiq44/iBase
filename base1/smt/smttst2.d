/*---------------------------------------------------------------------------*
 *  smttst2.d - LIBERO dialog data definitions for smttst2.c.                *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:32.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define error_event                     0
#define ok_event                        1
#define shutdown_event                  2
#define switch_off_event                3
#define switch_on_event                 4
#define _LR_STATE_after_init            0
#define _LR_STATE_getting_event         1
#define _LR_STATE_defaults              2
#define _LR_defaults_state              2


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE send_time_slot_specifiers    (THREAD *thread);
MODULE send_time_switched_off       (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE signal_switched_on           (THREAD *thread);
MODULE signal_switched_off          (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [3][5] =
{
    { 0,1,0,0,0 },
    { 0,0,0,1,1 },
    { 0,0,2,0,0 }
};

static word _LR_action [3][5] =
{
    { 2,1,0,0,0 },
    { 0,0,0,4,3 },
    { 0,0,2,0,0 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [5];
static long _LR_time  [5];
static word _LR_flow  [3][5];
#endif

static word _LR_offset [] =
{
    0,
    0,
    3,
    5,
    7
};

static word _LR_vector [] =
{
    0,1,_LR_STOP,
    2,_LR_STOP,
    3,_LR_STOP,
    4,_LR_STOP
};

static HOOK *_LR_module [5] = {
    send_time_slot_specifiers,
    send_time_switched_off,
    terminate_the_thread,
    signal_switched_on,
    signal_switched_off
};

static char *_LR_mname [5] =
{
     "Send-Time-Slot-Specifiers",
     "Send-Time-Switched-Off",
     "Terminate-The-Thread",
     "Signal-Switched-On",
     "Signal-Switched-Off"
};

static char *_LR_sname [3] =
{
     "After-Init",
     "Getting-Event",
     "Defaults"
};

static char *_LR_ename [5] =
{
     "Error-Event",
     "Ok-Event",
     "Shutdown-Event",
     "Switch-Off-Event",
     "Switch-On-Event"
};
