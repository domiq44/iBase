/*---------------------------------------------------------------------------*
 *  smtoper.d - LIBERO dialog data definitions for smtoper.c.                *
 *  Generated by LIBERO 2.4 on  6 Oct, 2010, 19:32.                          *
 *  Schema file used: smtschm.c.                                             *
 *---------------------------------------------------------------------------*/

/*- Symbolic constants and event numbers ------------------------------------*/

#define _LR_STOP                        0xFFFFL
#define _LR_NULL_EVENT                  -2
#define _LR_NULL_STATE                  -1
#define terminate_event                 -1
#define disable_event                   0
#define enable_event                    1
#define error_event                     2
#define exception_event                 3
#define info_event                      4
#define log_event                       5
#define ok_event                        6
#define shutdown_event                  7
#define warning_event                   8
#define _LR_STATE_after_init            0
#define _LR_STATE_expect_event          1
#define _LR_STATE_defaults              2
#define _LR_defaults_state              2


/*- Function prototypes and macros ------------------------------------------*/

#ifndef MODULE
#define MODULE  static void             /*  Libero dialog modules            */
#endif

MODULE initialise_the_thread        (THREAD *thread);
MODULE enable_console_messages      (THREAD *thread);
MODULE terminate_the_thread         (THREAD *thread);
MODULE use_specified_log_queue      (THREAD *thread);
MODULE signal_error_message         (THREAD *thread);
MODULE signal_warning_message       (THREAD *thread);
MODULE signal_info_message          (THREAD *thread);
MODULE disable_console_messages     (THREAD *thread);
MODULE signal_shutdown_in_progress  (THREAD *thread);

#define the_next_event              _the_next_event
#define the_exception_event         _the_exception_event
#define the_external_event          _the_external_event
#define exception_raised            _exception_raised
#define io_completed                _io_completed


/*- Static areas shared by all threads --------------------------------------*/

static word _LR_nextst [3][9] =
{
    { 0,0,0,0,0,0,1,0,0 },
    { 1,1,1,0,1,1,0,0,1 },
    { 2,2,2,2,2,2,2,2,2 }
};

static word _LR_action [3][9] =
{
    { 0,0,2,0,0,0,1,0,0 },
    { 7,1,4,0,6,3,0,0,5 },
    { 9,9,9,2,9,9,9,8,9 }
};

#if (defined (SMT_PROFILE))
static word _LR_count [8];
static long _LR_time  [8];
static word _LR_flow  [3][9];
#endif

static word _LR_offset [] =
{
    0,
    0,
    2,
    4,
    6,
    8,
    10,
    12,
    14,
    16
};

static word _LR_vector [] =
{
    0,_LR_STOP,
    1,_LR_STOP,
    2,_LR_STOP,
    3,_LR_STOP,
    4,_LR_STOP,
    5,_LR_STOP,
    6,_LR_STOP,
    7,_LR_STOP,
    _LR_STOP
};

static HOOK *_LR_module [8] = {
    enable_console_messages,
    terminate_the_thread,
    use_specified_log_queue,
    signal_error_message,
    signal_warning_message,
    signal_info_message,
    disable_console_messages,
    signal_shutdown_in_progress
};

#if (defined (DEBUG))
static char *_LR_mname [8] =
{
     "Enable-Console-Messages",
     "Terminate-The-Thread",
     "Use-Specified-Log-Queue",
     "Signal-Error-Message",
     "Signal-Warning-Message",
     "Signal-Info-Message",
     "Disable-Console-Messages",
     "Signal-Shutdown-In-Progress"
};

static char *_LR_sname [3] =
{
     "After-Init",
     "Expect-Event",
     "Defaults"
};

static char *_LR_ename [9] =
{
     "Disable-Event",
     "Enable-Event",
     "Error-Event",
     "Exception-Event",
     "Info-Event",
     "Log-Event",
     "Ok-Event",
     "Shutdown-Event",
     "Warning-Event"
};
#else
static char *_LR_mname [8] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7"
};

static char *_LR_sname [3] =
{
     "0",
     "1",
     "2"
};

static char *_LR_ename [9] =
{
     "0",
     "1",
     "2",
     "3",
     "4",
     "5",
     "6",
     "7",
     "8"
};
#endif
