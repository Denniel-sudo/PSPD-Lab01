/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _RPC_H_RPCGEN
#define _RPC_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


#define PROG 12121212
#define VERSAO 100

#if defined(__STDC__) || defined(__cplusplus)
#define WORDS_FREQ 1
extern  char ** words_freq_100(char **, CLIENT *);
extern  char ** words_freq_100_svc(char **, struct svc_req *);
#define WORDS_LENGTH 2
extern  char ** words_length_100(char **, CLIENT *);
extern  char ** words_length_100_svc(char **, struct svc_req *);
extern int prog_100_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define WORDS_FREQ 1
extern  char ** words_freq_100();
extern  char ** words_freq_100_svc();
#define WORDS_LENGTH 2
extern  char ** words_length_100();
extern  char ** words_length_100_svc();
extern int prog_100_freeresult ();
#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_RPC_H_RPCGEN */
