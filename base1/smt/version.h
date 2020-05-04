/*==========================================================
 *
 *  version.h - version information for SMT
 *
 *  Should be the last file included in parent source program.
 *  Generated by iMatix Boom
 *  
 *  Copyright (c) 1996-2009 iMatix Corporation
 *  All rights reserved.
 *  
 *  This file is licensed under the BSD license as follows:
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of iMatix Corporation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY IMATIX CORPORATION "AS IS" AND ANY
 *  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL IMATIX CORPORATION BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *==========================================================*/

#undef  VERSION         /*  Scrap any previous definitions  */
#undef  PRODUCT
#undef  COPYRIGHT
#undef  BUILDDATE
#undef  BUILDMODEL
#define VERSION         "3.0c2"
#define PRODUCT         "SMT/3.0c2"
#define COPYRIGHT       "Copyright (c) 1991-2009 iMatix Corporation"
#define BUILDDATE       ""
#ifndef SVN_REVISION
#define SVN_REVISION    "12075"
#endif
#if defined (DEBUG)
#   define BUILDMODEL   "Debug release for internal use only"
#else
#   define BUILDMODEL   "Production release"
#endif
#if defined (VERSION_EMBED)
/*  Embed the version information in the resulting binary   */
char *smt_version_start = "VeRsIoNsTaRt:smt";
char *smt_version = VERSION;
char *smt_product = PRODUCT;
char *smt_copyright = COPYRIGHT;
char *smt_buildmodel = BUILDMODEL;
char *smt_svn_revision = SVN_REVISION;
char *smt_version_end = "VeRsIoNeNd:smt";
#endif
