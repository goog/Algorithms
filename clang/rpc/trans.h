/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _TRANS_H_RPCGEN
#define _TRANS_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXLENGTH 1024
#define MAXNAME 20

#define FILETRANSPROG 99
#define FILETRANSVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define READFILE 1
extern  char ** readfile_1(char **, CLIENT *);
extern  char ** readfile_1_svc(char **, struct svc_req *);
extern int filetransprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define READFILE 1
extern  char ** readfile_1();
extern  char ** readfile_1_svc();
extern int filetransprog_1_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_TRANS_H_RPCGEN */
