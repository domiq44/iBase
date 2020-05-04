/*---------------------------------------------------------------------------
    http_driver_module.h - http_driver_module component

    This class enables the creation of plug-in modules that handle specific
    URI paths for the server.  The plug-in accepts HTTP methods and an
    http_request object and returns a http_response object.
    Generated from http_driver_module.icl by icl_gen using GSL/4.
    
    Copyright (c) 1996-2009 iMatix Corporation
    All rights reserved.
    
    This file is licensed under the BSD license as follows:
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of iMatix Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
    
    THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    These header files use macros to implement a split inclusion in which all
    safe definitions (those that do not depend on the presence of other
    definitions) are done first, and all unsafe definitions are done in a
    second pass through the same headers.

    The first header file included from the main C program defines itself as
    the "root" and thus controls the inclusion of the safe/unsafe pieces of
    the other headers.
 *---------------------------------------------------------------------------*/

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 1)
# ifndef INCLUDE_HTTP_DRIVER_MODULE_SAFE
#   define INCLUDE_HTTP_DRIVER_MODULE_SAFE
#   define INCLUDE_HTTP_DRIVER_MODULE_ACTIVE
#   if !defined (ICL_IMPORT_HEADERS)
#       define ICL_IMPORT_HTTP_DRIVER_MODULE_ROOT
#       define ICL_IMPORT_HEADERS 1
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif

//  Our own class typedef

typedef struct _http_driver_module_t http_driver_module_t;
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
#    define HTTP_DRIVER_MODULE_HISTORY_LENGTH 32
#endif

#define HTTP_DRIVER_MODULE_ALIVE        0xFABB
#define HTTP_DRIVER_MODULE_DEAD         0xDEAD

#define HTTP_DRIVER_MODULE_ASSERT_SANE(self)\
{\
    if (!self) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "Attempting to work with a NULL http_driver_module\n");\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
    if (self->object_tag != HTTP_DRIVER_MODULE_ALIVE) {\
        icl_system_panic ("", "FATAL ERROR at %s:%u, in %s\n", __FILE__, __LINE__, ICL_ASSERT_SANE_FUNCTION);\
        icl_system_panic ("", "http_driver_module at %p expected object_tag=0x%x, actual object_tag=0x%x\n", self, HTTP_DRIVER_MODULE_ALIVE, self->object_tag);\
        http_driver_module_show (self, ICL_CALLBACK_DUMP, stderr);\
        icl_system_panic ("", "Please report this to openamq-dev@lists.openamq.org\n");\
        abort ();\
    }\
}
#ifndef IPR_UNTYPED_LINK
#define IPR_UNTYPED_LINK
    typedef void * (untyped_link_fn) (void *object);
    typedef void (untyped_unlink_fn) (void *object_p);
#endif
#   ifdef __cplusplus
}
#   endif

#   include "http.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"
#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_MODULE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_MODULE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 2
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 2)
# ifndef INCLUDE_HTTP_DRIVER_MODULE_UNSAFE
#   define INCLUDE_HTTP_DRIVER_MODULE_UNSAFE
#   define INCLUDE_HTTP_DRIVER_MODULE_ACTIVE

#   include "http.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif
//  Global variables

extern Bool
    http_driver_module_animating;

//  Structure of the http_driver_module object

struct _http_driver_module_t {
#if (defined (BASE_THREADSAFE))
    icl_rwlock_t *
        rwlock;
#endif
    volatile int
        links;                          //  Number of links to the item
    volatile qbyte
        zombie;                         //  Object destroyed but not freed
#if defined (DEBUG) || defined (BASE_HISTORY) || defined (BASE_HISTORY_HTTP_DRIVER_MODULE)
    //  Possession history, for tracing
    volatile qbyte
        history_last;
    char
        *history_file [HTTP_DRIVER_MODULE_HISTORY_LENGTH];
    int
        history_line  [HTTP_DRIVER_MODULE_HISTORY_LENGTH];
    char
        *history_type [HTTP_DRIVER_MODULE_HISTORY_LENGTH];
    int
        history_links [HTTP_DRIVER_MODULE_HISTORY_LENGTH];
#endif
    dbyte
        object_tag;                     //  Object validity marker
Bool
    bound,                          //  Has portal been bound?
    stopped;                        //  Has portal been stopped?

//  Server-side state glue
void
    *server_object;                 //  If null, is a factory
ipr_looseref_t
    *server_looseref;               //  Where server holds portal reference
//  Server virtual methods
void (*server_unlink)
    (void *server);
void (*server_unbind)
    (void *server, http_driver_module_t *portal);

//  Client-side state glue
void
    *client_object;                 //  Client object reference
ipr_looseref_t
    *client_looseref;               //  Where client holds portal reference
void (*client_unbind)
    (void *client, http_driver_module_t *portal);
icl_shortstr_t
    path;                           //  Plugin path specification

//  add file name pattern
//  add mime type pattern
http_driver_module_t *(*server_new)
    (void *_server, char * path);
int (*request_announce)
    (void *_server, http_driver_module_t *portal, smt_log_t * log);
int (*request_get)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_head)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_post)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_put)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_delete)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_move)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
int (*request_copy)
    (void *_server, http_driver_module_t *portal, http_driver_context_t * context);
};

#   ifdef __cplusplus
}
#   endif
#   ifdef __cplusplus
extern "C" {
#   endif
//  Method prototypes
#define http_driver_module_new(server_object,server_link,server_unlink,path)  http_driver_module_new_ (__FILE__, __LINE__, server_object, server_link, server_unlink, path)
http_driver_module_t *
    http_driver_module_new_ (
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink,      //  Not documented
char * path                             //  Not documented
);

http_driver_module_t *
    http_driver_module_factory (
http_driver_module_t * self,            //  Portal factory
char * path                             //  Not documented
);

int
    http_driver_module_request_announce (
http_driver_module_t * self,            //  Not documented
smt_log_t * log                         //  Not documented
);

int
    http_driver_module_request_get (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_head (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_post (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_put (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_delete (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_move (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_request_copy (
http_driver_module_t * self,            //  Not documented
http_driver_context_t * context         //  Not documented
);

int
    http_driver_module_ready (
http_driver_module_t * self             //  Reference to object
);

void
    http_driver_module_selftest (
void);

void
    http_driver_module_terminate (
void);

#define http_driver_module_show(item,opcode,trace_file)  http_driver_module_show_ (item, opcode, trace_file, __FILE__, __LINE__)
void
    http_driver_module_show_ (
void * item,                            //  The opaque pointer
int opcode,                             //  The callback opcode
FILE * trace_file,                      //  File to print to
char * file,                            //  Source file
size_t line                             //  Line number
);

#define http_driver_module_destroy(self)  http_driver_module_destroy_ (self, __FILE__, __LINE__)
void
    http_driver_module_destroy_ (
http_driver_module_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source fileSource file
size_t line                             //  Line numberLine number
);

int
    http_driver_module_read_lock (
http_driver_module_t * self             //  Reference to object
);

int
    http_driver_module_write_lock (
http_driver_module_t * self             //  Reference to object
);

int
    http_driver_module_unlock (
http_driver_module_t * self             //  Reference to object
);

#define http_driver_module_link(self)   http_driver_module_link_ (self, __FILE__, __LINE__)
http_driver_module_t *
    http_driver_module_link_ (
http_driver_module_t * self,            //  Not documented
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

#define http_driver_module_unlink(self)  http_driver_module_unlink_ (self, __FILE__, __LINE__)
void
    http_driver_module_unlink_ (
http_driver_module_t * ( * self_p ),    //  Reference to object reference
char * file,                            //  Source file for call
size_t line                             //  Line number for call
);

void
    http_driver_module_show_animation (
Bool enabled                            //  Are we enabling or disabling animation?
);

#define http_driver_module_new_in_scope(self_p,_scope,server_object,server_link,server_unlink,path)  http_driver_module_new_in_scope_ (self_p, _scope, __FILE__, __LINE__, server_object, server_link, server_unlink, path)
void
    http_driver_module_new_in_scope_ (
http_driver_module_t * * self_p,        //  Not documented
icl_scope_t * _scope,                   //  Not documented
char * file,                            //  Source file for call
size_t line,                            //  Line number for call
void * server_object,                   //  Not documented
untyped_link_fn * server_link,          //  Not documented
untyped_unlink_fn * server_unlink,      //  Not documented
char * path                             //  Not documented
);


#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_MODULE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_MODULE_ROOT)
#       undef  ICL_IMPORT_HEADERS
#       define ICL_IMPORT_HEADERS 3
#   endif
# endif
#endif

#if !defined (ICL_IMPORT_HEADERS) || (ICL_IMPORT_HEADERS == 3)
# if !defined (INCLUDE_HTTP_DRIVER_MODULE_INLINE)
#   define INCLUDE_HTTP_DRIVER_MODULE_INLINE
#   define INCLUDE_HTTP_DRIVER_MODULE_ACTIVE

#   include "http.h"
#   include "ipr_looseref.h"
#   include "icl_mem.h"
#   include "icl_system.h"

#   ifdef __cplusplus
extern "C" {
#   endif

#   ifdef __cplusplus
}
#   endif
#   undef INCLUDE_HTTP_DRIVER_MODULE_ACTIVE
#   if defined (ICL_IMPORT_HTTP_DRIVER_MODULE_ROOT)
#       undef ICL_IMPORT_HEADERS
#       undef ICL_IMPORT_HTTP_DRIVER_MODULE_ROOT
#   endif
# endif
#endif
