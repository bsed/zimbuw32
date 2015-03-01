/*
 * Generated from Zimbu file testmore.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <setjmp.h>
#include <sys/time.h>
#include <time.h>
#ifdef __MINGW32__
# include <windows.h>
# undef THIS
# undef small
#endif

#ifdef WIN32
# include <winsock.h>
# include <winsock2.h>
# undef THIS
# undef small
  typedef int socklen_t;
# if defined _WIN32 || defined __WIN32__
#  define setsockopt(a,b,c,d,e) setsockopt(a,b,c,(const void*)(d),e)
# endif
# define sckt_read(a, b, c) recv(a, b, c, 0)
# define sckt_write(a, b, c) send(a, b, c, 0)
# define sckt_close(a) closesocket(a)
#else
# define sckt_read(a, b, c) read(a, b, c)
# define sckt_write(a, b, c) write(a, b, c)
# define sckt_close(a) close(a)
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
#endif

/*
 * TYPEDEFS
 */
#define ZINT_FORMAT "%I64d"
#define ZNAT_FORMAT "%I64u"
#define ZINT_XFORMAT "%I64x"
#define ZFLOAT_FORMAT "%g"
typedef long long Ti; /* int */
typedef short Ti16; /* int16 */
typedef int Ti32; /* int32 */
typedef unsigned long long Tu; /* nat */
typedef unsigned char Tc; /* byte */
typedef unsigned short Tu16; /* nat16 */
typedef unsigned int Tu32; /* nat32 */
typedef double Tf; /* float */
typedef float Tf32; /* float32 */
typedef __INTPTR_TYPE__ Tip; /* int for pointer */
typedef long long Tbb; /* big BITS */

typedef int Tbs; /* small BITS */
typedef int Tb; /* bool */
typedef int Ts; /* status */
typedef int Te; /* enum */
typedef struct Zref__S Tr; /* object ref */
typedef struct Zobj__S To; /* object description */
typedef union {
 Ti ival;
 Tf fval;
 void *ptr;
} Tz; /* dyn value */
typedef struct Ztype__S Tt; /* type */
typedef struct Ztypeo__S Tto; /* type with To pointer */
typedef struct Zoh__S Zoh; /* allocated memory header */
struct Zoh__S {
 Zoh *np;
};
#define ZOH_OFF sizeof(Zoh)
Zoh Zstatic;
Zoh Znoalloc;
Zoh Zlast;
#define ZOHF_LAST (Zohf*)&Zlast
typedef struct {
 void *var;
 Tt   *type;
} Zop;
#define GC_BLOCK_SIZE 1022
typedef struct Zgcb__S Zgcb;
struct Zgcb__S {
 Zgcb *next;
 int used;
 Zop items[GC_BLOCK_SIZE];
};
typedef struct {
 Zgcb *todo;
 Zgcb *empty;
} Zgcs;
typedef struct Zohf__S Zohf;
struct Zohf__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
};
#define FOK_OK 1
#define FOK_NOX 2
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforRange__S Tfr; /* FOR in range */
typedef struct ZforEnum__S Tfe; /* FOR in enum */
typedef struct garray__S Tg; /* grow array */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
typedef struct YzSI__S YzSI; /* MEModule.DivideByZero */
typedef struct YXKl__S YXKl; /* MEModule.IOError */
typedef struct YuDC__S YuDC; /* MEModule.WrongType */
typedef struct YqzO__S YqzO; /* MEModule.Thread */
typedef struct YrHq__S YrHq; /* MEModule.Internal */
/* EModule done */
/* including PIPEModule typedefs */
typedef struct YK7s__S YK7s; /* MPIPEModule.Pipe__t1 */
typedef struct YJ7s__S YJ7s; /* MPIPEModule.Pipe__t2 */
/* PIPEModule done */
/* including HTTPModule typedefs */
typedef struct YSM1__S YSM1; /* MHTTPModule.Request */
typedef struct YKeB__S YKeB; /* MHTTPModule.Response */
typedef struct YtzZ__S YtzZ; /* MHTTPModule.Context */
typedef struct YX8j__S YX8j; /* MHTTPModule.FileServlet */
typedef struct YIgO__S YIgO; /* MHTTPModule.StringServlet */
typedef struct YzRH__S YzRH; /* MHTTPModule.FunctionServlet */
typedef struct Y1QG__S Y1QG; /* MHTTPModule.Server */
/* HTTPModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
/* IOModule done */
/* including GCModule typedefs */
typedef struct YXAF__S YXAF; /* MGCModule.Info */
/* GCModule done */
/* including THREADModule typedefs */
typedef struct YgC4__S YgC4; /* MTHREADModule.E_Thread */
typedef struct YTgs__S YTgs; /* MTHREADModule.Thread */
typedef struct YRg3__S YRg3; /* MTHREADModule.EvalThread__t1 */
typedef struct YlXt__S YlXt; /* MTHREADModule.Lock */
typedef struct YTJ0__S YTJ0; /* MTHREADModule.AutoLock */
typedef struct Y0Wo__S Y0Wo; /* MTHREADModule.Cond */
/* THREADModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including PipeTest typedefs */
typedef struct YG3z__S YG3z;
typedef struct YRKg__S YRKg;
/* PipeTest done */
/* including ThreadTest typedefs */
/* including Ticker typedefs */
typedef struct Yeip__S Yeip; /* Ticker */
typedef struct YXJh__S YXJh; /* CTicker.Reader */
/* Ticker done */
typedef struct YjmP__S YjmP; /* MThreadTest.Server */
/* ThreadTest done */
typedef struct Tcallback__S Tcb;
/*
 * STRUCTS
 */
/* IO.eof */
#define Y3QJ EOF


typedef struct {
 int line;
 int col;
} Tcpos;
typedef struct {
 Ti offset;
 Tc *fileName;
 Tc *methodName;
 Tcpos *table;
} Tcode;

void *Za(size_t size);
void *ZaNm(size_t size);
void *ZaNmi(size_t size);
void *Zran(void *op, size_t osize, size_t nsize);
void *ZranNm(void *op, size_t osize, size_t nsize);
void ZthrowOutOfMemory(Ti size);
char *emergencyAlloc = NULL;
size_t emergencyAllocUsed = 0;
void ZthrowDeadly(int nr);
Tc *ZnewString(Tc *p, Ti len);
void ZthrowCstringNil(char *text);
void ZthrowCstringBadValue(char *msg);
void ZthrowInternal(Tc *t);
Tc *Zenum2string(char **names, Te n);

char *ZgetCstring(Tc *s);
struct ZforList__S {
 Zoh *np;
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

struct ZforEnum__S {
 int count;
 int idx;
};
void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);
struct garray__S {
 Tc *data;
 int used;
 int len;
};

struct Zref__S {
 void *ptr;
 Tc **table;
 int  type;
};
Tr trZero = {NULL,NULL,0};
struct Zobj__S {
 int off;
 Tt *type;
};

struct Ztype__S {
 int nr;
 Tc *name;
 void *ToString;
};
struct Ztypeo__S {
 int nr;
 Tc *name;
 void *ToString;
 char **names;
 void *Size;
 void *Finish;
 void *Equal;
 void *Compare;
 To *to;
};
extern Tt bool__T;
extern Tt byte__T;
extern Tt byteString__T;
extern Tt float128__T;
extern Tt float32__T;
extern Tt float80__T;
extern Tt float__T;
extern Tt int16__T;
extern Tt int32__T;
extern Tt int8__T;
extern Tt int__T;
extern Tt nat16__T;
extern Tt nat32__T;
extern Tt nat__T;
extern Tt status__T;
extern Tt string__T;
extern Tt type__T;
extern Tt thread__T;
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt cb__T;
extern Tt iobj__T;
typedef struct Tstring__S Tstring; /* string */
struct Tstring__S {
 Zoh *np;
 Tc *Vm;
};
To ToTstring[] = {
 {1, 0},
 {ZOH_OFF, &string__T},
};

struct CArray__S {
 Zoh *np;
 void *ptr;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
void ZfreeArray(Ta *head);
void ZArrayToStringGa(Ta *head, int useq, Tg *ga);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);
struct CListHead__S {
 Zoh *np;
 Tt *itemType;
 void **items;
 Ti empty;
 Ti space;
 Ti itemCount;
 int itemSize;
 int tosNr;
};
Tl *ZLa(Tl *head, Ti after, Tz val);
Tl *ZnewList(Tt *itemType, Ti size);
Tl *ZLap(Tl *head, Tz val);
void *ZListGetPtr(Tl *head, Ti idx);
void *ZListRemovePtrItem(Tl *head, Ti idx);
Ti ZListFind(Tl *head, Tz val);
void ZListToStringGa(Tl *head, int useq, Tg *ga);
#define HT_INIT_SIZE 16
#define PERTURB_SHIFT 5

#define DTYPE_ORDERED 1 /* dict with list to keep order of items */

#define CDI_FLAG_USED 1
#define CDI_FLAG_DEL 2
struct CDictItem__S {
 Zhashtype hash;
 union {
  Tz key;
  Tr iokey;
 };
 union {
  Tz item;
  Tr ioitem;
 };
 CDictItem *lnext;
 CDictItem *lprev;
 int flags;
};

struct CDictHead__S {
 Zoh *np;

 Zhashtype mask;
 Zhashtype used;
 Zhashtype extra;
 Zhashtype filled;
 int tosNr;
 int type;
 CDictItem *array;
 CDictItem smallArray[HT_INIT_SIZE];
 Tt *keyType;
 Tt *itemType;
 int (*eqfunc)(void *i, Tz *v);
 CDictItem *first;
 CDictItem *last;
};
void ZDictToStringGa(Td *d, int keyUseq, int itemUseq, Tg *ga);
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 Zoh *np;
 char text[5];
} Zs5;
/* including SYSModule structs */
typedef struct {
 Zoh *np;
 char text[9];
} Zs9;
/* SYSModule done */
/* including EModule structs */
typedef struct {
 Zoh *np;
 char text[4];
} Zs4;
typedef struct {
 Zoh *np;
 char text[13];
} Zs13;
typedef struct {
 Zoh *np;
 char text[11];
} Zs11;
typedef struct {
 Zoh *np;
 char text[39];
} Zs39;
typedef struct {
 Zoh *np;
 char text[12];
} Zs12;
typedef struct {
 Zoh *np;
 char text[3];
} Zs3;
struct Ytlm__S {
 Zoh *np;
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 Zoh *np;
 char text[7];
} Zs7;
struct YEro__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 Zoh *np;
 char text[6];
} Zs6;
typedef struct {
 Zoh *np;
 char text[28];
} Zs28;
struct YKhn__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 Zoh *np;
 char text[14];
} Zs14;
struct YVNj__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct Yalz__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 Zoh *np;
 char text[10];
} Zs10;
struct Yw3O__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 Zoh *np;
 char text[17];
} Zs17;
typedef struct {
 Zoh *np;
 char text[18];
} Zs18;
struct YX0i__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 Zoh *np;
 char text[22];
} Zs22;
typedef struct {
 Zoh *np;
 char text[23];
} Zs23;
struct YzSI__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 Zoh *np;
 char text[15];
} Zs15;
struct YuDC__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YqzO__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YqzO__T;
typedef struct {
 Zoh *np;
 char text[8];
} Zs8;
struct YrHq__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including PIPEModule structs */
struct YK7s__S {
 Zoh *np;
 Tb VisOpen;
 Ti VbufferSize;
 Tl *VitemList;
 YlXt *Vlock;
 Y0Wo *VreadCond;
 Y0Wo *VwriteCond;
};
extern Tto YK7s__T;
struct YJ7s__S {
 Zoh *np;
 Tb VisOpen;
 Ti VbufferSize;
 Tl *VitemList;
 YlXt *Vlock;
 Y0Wo *VreadCond;
 Y0Wo *VwriteCond;
};
extern Tto YJ7s__T;
/* PIPEModule done */
/* including HTTPModule structs */
char *MHTTPModule__ERequestType[] = {
 (char*)9,
 "unknown",
 "options",
 "get",
 "head",
 "post",
 "put",
 "delete",
 "trace",
 "connect",
};
char *MHTTPModule__ERequestType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)MHTTPModule__ERequestType[0]) ? "INVALID" : MHTTPModule__ERequestType[n + 1];
};
typedef struct {
 Zoh *np;
 char text[16];
} Zs16;
struct YSM1__S {
 Zoh *np;
 Te Vtype;
 Tc *Vpath;
 Tc *Vparams;
 Tc *VhttpVersion;
 Td *VheaderItems;
 Tc *Vbody;
};
extern Tto YSM1__T;
typedef struct {
 Zoh *np;
 char text[26];
} Zs26;
typedef struct {
 Zoh *np;
 char text[2];
} Zs2;
struct YKeB__S {
 Zoh *np;
 Ti Vcode;
 Tc *Vmsg;
 Td *VheaderItems;
 Tc *Vbody;
};
extern Tto YKeB__T;
struct YtzZ__S {
 Zoh *np;
 Y1QG *Vserver;
 YSM1 *Vrequest;
 YKeB *Vresponse;
};
extern Tto YtzZ__T;
struct YX8j__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tc *VfileName;
};
extern Tto YX8j__T;
struct YIgO__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tc *Vbody;
};
extern Tto YIgO__T;
struct YzRH__S {
 Zoh *np;
Tc *Vname;
Tl *Vpaths;
Tc *VmimeType;
 Tcb *VserveFunc;
};
extern Tto YzRH__T;
typedef struct {
 Zoh *np;
 char text[24];
} Zs24;
typedef struct {
 Zoh *np;
 char text[19];
} Zs19;
typedef struct {
 Zoh *np;
 char text[33];
} Zs33;
typedef struct {
 Zoh *np;
 char text[37];
} Zs37;
struct Y1QG__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Tcb *Vproc;
Tc *Vname;
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
 Ti Vport;
 Ti VlistenQueueLen;
 Tl *Vservlets;
 Tc *VfileRoot;
 Tc *Vbase;
 Te Vverbosity;
 YK7s *VquitPipe;
 Tb VdidQuit;
 Tb Vbusy;
};
extern Tto Y1QG__T;
/* HTTPModule done */
/* including ZModule structs */
struct YkxB__S {
 Zoh *np;
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
struct Yw8L__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
typedef struct {
 Zoh *np;
 char text[29];
} Zs29;
typedef struct {
 Zoh *np;
 char text[31];
} Zs31;
typedef struct {
 Zoh *np;
 char text[32];
} Zs32;
typedef struct {
 Zoh *np;
 char text[30];
} Zs30;
typedef struct {
 Zoh *np;
 char text[53];
} Zs53;
struct YjUM__S {
 Zoh *np;
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
/* IOModule done */
/* including GCModule structs */
struct YXAF__S {
 Zoh *np;
 Ti VstwTime;
 Ti VmarkTime;
 Ti VfreeTime;
 Ti VtotalTime;
 Ti VuseCount;
 Ti VfreeCount;
};
extern Tto YXAF__T;
/* GCModule done */
/* including THREADModule structs */
/* including Config structs */
typedef struct {
 Zoh *np;
 char text[36];
} Zs36;
typedef struct {
 Zoh *np;
 char text[47];
} Zs47;
typedef struct {
 Zoh *np;
 char text[46];
} Zs46;
typedef struct {
 Zoh *np;
 char text[44];
} Zs44;
/* Config done */
struct YgC4__S {
 Zoh *np;
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YgC4__T;
struct YTgs__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Tc *Vname;
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
 Tcb *Vproc;
};
extern Tto YTgs__T;
typedef struct {
 Zoh *np;
 char text[43];
} Zs43;
struct YRg3__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Tc *Vname;
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
 Tcb *VevalFunc;
 YJ7s *VresultPipe;
};
extern Tto YRg3__T;
struct YlXt__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
 pthread_mutex_t Vmutex;
};
extern Tto YlXt__T;
struct YTJ0__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
 YlXt *Vlock;
 Tb VdidEnd;
};
extern Tto YTJ0__T;
struct Y0Wo__S {
 Zoh *np;
 pthread_cond_t Vcond;
};
extern Tto Y0Wo__T;
/* THREADModule done */
/* including ARGModule structs */
struct YnU5__S {
 Zoh *np;
};
extern Tto YnU5__T;
typedef struct {
 Zoh *np;
 char text[51];
} Zs51;
typedef struct {
 Zoh *np;
 char text[58];
} Zs58;
typedef struct {
 Zoh *np;
 char text[56];
} Zs56;
typedef struct {
 Zoh *np;
 char text[20];
} Zs20;
typedef struct {
 Zoh *np;
 char text[27];
} Zs27;
typedef struct {
 Zoh *np;
 char text[21];
} Zs21;
struct YuMQ__S {
 Zoh *np;
 Tc *Vtext;
};
extern Tto YuMQ__T;
typedef struct {
 Zoh *np;
 char text[42];
} Zs42;
typedef struct {
 Zoh *np;
 char text[50];
} Zs50;
typedef struct {
 Zoh *np;
 char text[52];
} Zs52;
struct Y86c__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tb Vcurrent;
 Tb Vdefault;
};
extern Tto Y86c__T;
struct YJQu__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Ti Vcurrent;
 Ti Vdefault;
 Tl *VtheValueList;
};
extern Tto YJQu__T;
struct YzqH__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tc *Vcurrent;
 Tc *Vdefault;
 Tl *VtheValueList;
};
extern Tto YzqH__T;
struct Y_SI__S {
 Zoh *np;
Tc *VshortName;
Tc *VlongName;
Tc *Vdoc;
Tc *VargName;
Ti VsetCount;
Tb VcanRepeat;
Tb VnoCompactVal;
Tb VargOpt;
YkxB *Vpos;
 Tl *Vcurrent;
 Tl *Vdefault;
};
extern Tto Y_SI__T;
/* ARGModule done */
/* including PipeTest structs */
struct YG3z__S {
 Zoh *np;
 void *cfunc;
 int toCount;
 Tcb *cb;
 To to[2];
 void *t;
 Tc * arg1;
};
struct YRKg__S {
 Zoh *np;
 void *cfunc;
 int toCount;
 Tcb *cb;
 To to[2];
 void *t;
 Tstring * arg1;
};
/* PipeTest done */
/* including ThreadTest structs */
/* including Ticker structs */
struct YXJh__S {
 Zoh *np;
 Ti Vindex;
 Yeip *Vticker;
};
extern Tto YXJh__T;
struct Yeip__S {
 Zoh *np;
 Ti VcurrentTick;
 Tl *VreaderTicks;
 Ti VreaderIndex;
 YlXt *VtickLock;
};
extern Tto Yeip__T;
/* Ticker done */
struct YjmP__S {
 Zoh *np;
 int fok;
 To* to;
 Ts (*ff)(void *, Te);
Tcb *Vproc;
Tc *Vname;
Te Vstate;
pthread_t Vthread_id;
Tl *Vstack;
};
extern Tto YjmP__T;
typedef struct {
 Zoh *np;
 char text[25];
} Zs25;
/* ThreadTest done */
struct Tcallback__S {
 Zoh *np;
 void *cfunc;
 int toCount;
};
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {&Zstatic, "\003NIL\000"};
/* including SYSModule declarations */
Tc *Yhy5(Tc *Aname); /* MSYSModule.getEnv */
Zs9 YVbO = {&Zstatic, "\007IOFlags\000"};
Tt MSYSModule__BIOFlags__T = {25, ((Tc*)&YVbO), 0};
/* SYSModule done */
/* including EModule declarations */
Ytlm *YRHR(Ytlm *t, Tc *Amsg); /* MEModule__CException.NEW */
Tc *YH0V(Ytlm *t); /* MEModule__CException.ToString */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {&Zstatic, "\002: \000"};
Zs13 YHbP = {&Zstatic, "\013Exception: \000"};
Zs11 YDGe = {&Zstatic, "\011Exception\000"};
Tc *Yoww(Ytlm *t, Tb Averbose); /* MEModule__CException.toString */
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {&Zstatic, "\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {&Zstatic, "\012\n(unknown)\000"};
Zs3 Yk = {&Zstatic, "\001\n\000"};
Tc *Ytlm__Ytlm_I_imt[14];
To ToYtlm[4];
char *StrYtlm[];
void YScq(Ti Apos, Tc *Atext); /* MEModule.throwException */
YEro *YE2c(YEro *t, Ti Avalue); /* MEModule__CExit.NEW */
Zs7 YxJ1 = {&Zstatic, "\005EXIT \000"};
Tc *Ydtua(YEro *t); /* MEModule__CExit.ToString */
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Tc *YEro__Yoww(YEro *t, Tb Averbose); /* MEModule__CExit.toString__p1 */
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
Tc *YEro__Ytlm_I_imt[14];
To ToYEro[5];
char *StrYEro[];
Zs6 YJMo = {&Zstatic, "\004Exit\000"};
void YNab(YkxB *Apos, Ti Aval); /* MEModule.throwExit */
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {&Zstatic, "\032Out of memory (allocating \000"};
Zs9 YDSH = {&Zstatic, "\007 bytes)\000"};
Tc *YKhn__YwtA__YH0V(YKhn *t); /* MEModule__COutOfMemory.ToString__p2 */
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose); /* MEModule__COutOfMemory.toString__p2 */
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
char *StrYKhn[];
Zs13 Y9Fv = {&Zstatic, "\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
Tc *Y1uN__YwtA__YH0V(Y1uN *t); /* MEModule__CNilAccess.ToString__p2 */
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose); /* MEModule__CNilAccess.toString__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
char *StrY1uN[];
Zs11 Y4wO = {&Zstatic, "\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
Tc *YAxe__YwtA__YH0V(YAxe *t); /* MEModule__CMemoryAccess.ToString__p2 */
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose); /* MEModule__CMemoryAccess.toString__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
char *StrYAxe[];
Zs14 Y4QW = {&Zstatic, "\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {&Zstatic, "\013signal SEGV\000"};
Zs12 YoEx = {&Zstatic, "\012signal FPE\000"};
Zs12 YQNH = {&Zstatic, "\012signal BUS\000"};
Zs9 YpCZ = {&Zstatic, "\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
Tc *YVNj__YwtA__YH0V(YVNj *t); /* MEModule__CInit.ToString__p2 */
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose); /* MEModule__CInit.toString__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
char *StrYVNj[];
Zs6 Ysqt = {&Zstatic, "\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
Tc *Yalz__YwtA__YH0V(Yalz *t); /* MEModule__CBadValue.ToString__p2 */
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose); /* MEModule__CBadValue.toString__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
char *StrYalz[];
Zs10 YEZq = {&Zstatic, "\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t); /* MEModule__COutOfRange.ToString__p3 */
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose); /* MEModule__COutOfRange.toString__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
char *StrYw3O[];
Zs12 YFK2 = {&Zstatic, "\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t); /* MEModule__CKeyNotFound.ToString__p3 */
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose); /* MEModule__CKeyNotFound.toString__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
char *StrY2EX[];
Zs13 YRiW = {&Zstatic, "\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {&Zstatic, "\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {&Zstatic, "\020Key not found: \"\000"};
Zs3 YI = {&Zstatic, "\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t); /* MEModule__CKeyExists.ToString__p3 */
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose); /* MEModule__CKeyExists.toString__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
char *StrYX0i[];
Zs11 Y9_h = {&Zstatic, "\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {&Zstatic, "\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {&Zstatic, "\025Key already exists: \"\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t); /* MEModule__CDivideByZero.ToString__p3 */
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose); /* MEModule__CDivideByZero.toString__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
char *StrYzSI[];
Zs14 YxFl = {&Zstatic, "\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
Tc *YXKl__YwtA__YH0V(YXKl *t); /* MEModule__CIOError.ToString__p2 */
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose); /* MEModule__CIOError.toString__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
char *StrYXKl[];
Zs9 YTj3 = {&Zstatic, "\007IOError\000"};
void YkuV(Tc *Amsg); /* MEModule.throwIOError */
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {&Zstatic, "\015Type mismatch\000"};
Tc *YuDC__YwtA__YH0V(YuDC *t); /* MEModule__CWrongType.ToString__p2 */
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose); /* MEModule__CWrongType.toString__p2 */
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
char *StrYuDC[];
Zs11 YCoZ = {&Zstatic, "\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YqzO *Y4iXa(YqzO *t, Tc *Amsg); /* MEModule__CThread.NEW */
Tc *YqzO__YwtA__YH0V(YqzO *t); /* MEModule__CThread.ToString__p2 */
Tc *YqzO__YwtA__Yoww(YqzO *t, Tb Averbose); /* MEModule__CThread.toString__p2 */
void YqzO__YwtA__YxaJa(YqzO *t, Tb Averbose, Tr Aw); /* MEModule__CThread.writeTo__p2 */
void YqzO__YwtA__YxaJ(YqzO *t, Tr Aw); /* MEModule__CThread.writeTo__p2 */
Tc *YqzO__Ytlm_I_imt[14];
To ToYqzO[4];
char *StrYqzO[];
Zs8 YnY0 = {&Zstatic, "\006Thread\000"};
void YNbE(YkxB *Apos, Tc *Atext); /* MEModule.throwThread */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
Tc *YrHq__YwtA__YH0V(YrHq *t); /* MEModule__CInternal.ToString__p2 */
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose); /* MEModule__CInternal.toString__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
char *StrYrHq[];
Zs10 YVki = {&Zstatic, "\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including PIPEModule declarations */
YK7s *YPsV(YK7s *t); /* MPIPEModule__CPipe__t1.NEW */
Ts YWty(YK7s *t, Tb Aitem); /* MPIPEModule__CPipe__t1.write */
To ToYK7s[7];
char *StrYK7s[];
Zs10 YLJT = {&Zstatic, "\010Pipe__t1\000"};
YJ7s *YqaL(YJ7s *t); /* MPIPEModule__CPipe__t2.NEW */
void YQCO(YJ7s *t); /* MPIPEModule__CPipe__t2.close */
Ts YVE3(YJ7s *t, Tc *Aitem); /* MPIPEModule__CPipe__t2.write */
Tc *YNqf(YJ7s *t, Ts *Rst); /* MPIPEModule__CPipe__t2.read */
Tc *YNqfa(YJ7s *t); /* MPIPEModule__CPipe__t2.read */
To ToYJ7s[7];
char *StrYJ7s[];
Zs10 YMJT = {&Zstatic, "\010Pipe__t2\000"};
/* PIPEModule done */
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
void YQzL(Ti Ausec); /* MTIMEModule.sleep */
/* TIMEModule done */
/* including HTTPModule declarations */
Tt MHTTPModule__ERequestType__T = {23, 0, MHTTPModule__ERequestType__name};
YSM1 *YF0N(YSM1 *t); /* MHTTPModule__CRequest.NEW */
Tc *YuPP(YSM1 *t); /* MHTTPModule__CRequest.ToString */
Zs8 Y5wx = {&Zstatic, "\006type: \000"};
Zs8 YXBd = {&Zstatic, "\006path: \000"};
Zs10 YrAc = {&Zstatic, "\010params: \000"};
Zs16 Y1xf = {&Zstatic, "\016HTTP version: \000"};
Zs15 YiH8 = {&Zstatic, "\015HEADER ITEMS:\000"};
Zs8 YLih = {&Zstatic, "\006Body: \000"};
To ToYSM1[7];
char *StrYSM1[];
Zs9 YFUt = {&Zstatic, "\007Request\000"};
YKeB *YikN(YKeB *t); /* MHTTPModule__CResponse.NEW */
Zs4 Y0ab = {&Zstatic, "\002OK\000"};
Zs26 Ylqg = {&Zstatic, "\030text/html; charset=UTF-8\000"};
Zs8 YBMI = {&Zstatic, "\006empty\n\000"};
void YjIQ(YKeB *t, Ti Alength); /* MHTTPModule__CResponse.setLength */
Zs16 Y95C = {&Zstatic, "\016Content-Length\000"};
Zs2 Ya = {&Zstatic, "\000\000"};
void YDSB(YKeB *t, Tc *Atype); /* MHTTPModule__CResponse.setType */
Zs14 YPoL = {&Zstatic, "\014Content-Type\000"};
To ToYKeB[5];
char *StrYKeB[];
Zs10 YhQB = {&Zstatic, "\010Response\000"};
YtzZ *Y89Z(YtzZ *t, Y1QG *Aserver, YSM1 *Arequest, YKeB *Aresponse); /* MHTTPModule__CContext.NEW */
To ToYtzZ[4];
char *StrYtzZ[];
Zs9 Y36w = {&Zstatic, "\007Context\000"};
YX8j *Yb5K(YX8j *t, Tc *AfileName); /* MHTTPModule__CFileServlet.NEW */
Zs13 YAkv = {&Zstatic, "\013FileServlet\000"};
void YkIq(YX8j *t, Tc *AfileName); /* MHTTPModule__CFileServlet.setFile */
Tb Y3hma(YX8j *t, YtzZ *Acontext); /* MHTTPModule__CFileServlet.serve */
Zs10 Y95j = {&Zstatic, "\010reading \000"};
Zs3 YV = {&Zstatic, "\001/\000"};
void YX8j__Y3fn(YX8j *t, Tc *Apath); /* MHTTPModule__CFileServlet.addPath__p1 */
Tb YX8j__YU_W(YX8j *t, YtzZ *Acontext); /* MHTTPModule__CFileServlet.handle__p1 */
void YX8j__YuzN(YX8j *t, Tc *Atype); /* MHTTPModule__CFileServlet.setMimeType__p1 */
Tc *YX8j__YtrZ_I_imt[9];
To ToYX8j[5];
char *StrYX8j[];
YIgO *Y543(YIgO *t, Tc *Abody); /* MHTTPModule__CStringServlet.NEW */
Zs15 Y2iZ = {&Zstatic, "\015StringServlet\000"};
void Y6ye(YIgO *t, Tc *Abody); /* MHTTPModule__CStringServlet.setBody */
Tb YqXRa(YIgO *t, YtzZ *Acontext); /* MHTTPModule__CStringServlet.serve */
void YIgO__Y3fn(YIgO *t, Tc *Apath); /* MHTTPModule__CStringServlet.addPath__p1 */
Tb YIgO__YU_W(YIgO *t, YtzZ *Acontext); /* MHTTPModule__CStringServlet.handle__p1 */
Tc *YIgO__YtrZ_I_imt[9];
To ToYIgO[5];
char *StrYIgO[];
YzRH *YDye(YzRH *t, Tcb *Afunc); /* MHTTPModule__CFunctionServlet.NEW */
Zs17 YEgW = {&Zstatic, "\017FunctionServlet\000"};
Tb Y9y4a(YzRH *t, YtzZ *Acontext); /* MHTTPModule__CFunctionServlet.serve */
void YzRH__Y3fn(YzRH *t, Tc *Apath); /* MHTTPModule__CFunctionServlet.addPath__p1 */
Tb YzRH__YU_W(YzRH *t, YtzZ *Acontext); /* MHTTPModule__CFunctionServlet.handle__p1 */
Tc *YzRH__YtrZ_I_imt[9];
To ToYzRH[5];
char *StrYzRH[];
Tt MHTTPModule__EVerbosity__T = {23, 0, 0};
Y1QG *YAvl(Y1QG *t, Ti Aport); /* MHTTPModule__CServer.NEW */
Zs3 Y5 = {&Zstatic, "\001:\000"};
Zs8 Ycao = {&Zstatic, "\006/ZUDIR\000"};
void Yj9O(Y1QG *t, Tc *Aroot); /* MHTTPModule__CServer.setFileRoot */
void Yb8i(Y1QG *t, Tr Aservlet); /* MHTTPModule__CServer.addServlet */
void YVBU(Y1QG *t); /* MHTTPModule__CServer.body */
Zs12 Yj86 = {&Zstatic, "\012 params: '\000"};
Zs3 YN = {&Zstatic, "\001'\000"};
Zs10 Ye88 = {&Zstatic, "\010HTTP/1.1\000"};
Zs13 YmUM = {&Zstatic, "\013 version: '\000"};
Zs24 YpFn = {&Zstatic, "\026Received HTTP request \000"};
Zs4 Y5Y = {&Zstatic, "\002 '\000"};
Zs19 YUqj = {&Zstatic, "\021Request so far: '\000"};
Zs33 Yetr = {&Zstatic, "\037Warning: Request header too big\000"};
Zs3 YG = {&Zstatic, "\001 \000"};
Zs4 Ydha = {&Zstatic, "\002, \000"};
Zs17 Y5UY = {&Zstatic, "\017Header fields: \000"};
Zs16 YSBt = {&Zstatic, "\016content-length\000"};
Zs14 Y6Ov = {&Zstatic, "\014Body size = \000"};
Zs14 YLqJ = {&Zstatic, "\014Reading more\000"};
Zs13 Ylp1 = {&Zstatic, "\013Read size: \000"};
Zs11 YrD_ = {&Zstatic, "\011 bytes: '\000"};
Zs7 YKUO = {&Zstatic, "\005 ... \000"};
Zs18 Y_P0 = {&Zstatic, "\020Servlet failed: \000"};
Zs17 Yytr = {&Zstatic, "\017Page not found.\000"};
Zs37 YaLI = {&Zstatic, "\043Sorry, this page is not available.\n\000"};
Zs11 Y5E7 = {&Zstatic, "\011HTTP/1.1 \000"};
Zs4 Yau = {&Zstatic, "\002\r\n\000"};
Zs24 YkHK = {&Zstatic, "\026Sending HTTP response \000"};
Zs9 Y6wd = {&Zstatic, "\007Body: '\000"};
void Y1QG__YTgs__Y7C8(Y1QG *t); /* MHTTPModule__CServer.startBody__p2 */
void Y1QG__YTgs__YSuw(Y1QG *t); /* MHTTPModule__CServer.start__p2 */
Zs14 YgzQ = {&Zstatic, "\014Thread start\000"};
void Y1QG__YTgs__YSfi(Y1QG *t); /* MHTTPModule__CServer.wait__p2 */
void Y1QG__YTgs__YDFp(Y1QG *t); /* MHTTPModule__CServer.kill__p2 */
Ts Y1QG__YTgs__Y2Cz(Y1QG *t, Te _fr); /* MHTTPModule__CServer.Finish__p2 */
void Y1QG__YcCua(Y1QG *t); /* MHTTPModule__CServer.body__p1 */
void Y1QG__YqOJ(Y1QG *t, Tcb *Aproc); /* MHTTPModule__CServer.setProc__p1 */
int Y1QGa__r = 0; /* Init/1().Ready */
Y1QG *Y1QGa(Y1QG *t); /* MHTTPModule__CServer.Init */
Zs18 YoWK = {&Zstatic, "\020http://localhost\000"};
To ToY1QG[14];
char *StrY1QG[];
Zs8 YooJ = {&Zstatic, "\006Server\000"};
Tb Y2jx(Ti Ac); /* MHTTPModule.isWhite */
/* HTTPModule done */
/* including ZModule declarations */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {&Zstatic, "\016[unknown file]\000"};
Zs8 YBpY = {&Zstatic, "\006 line \000"};
Zs7 Y8ES = {&Zstatic, "\005 col \000"};
To ToYkxB[5];
char *StrYkxB[];
Zs5 YBCs = {&Zstatic, "\003Pos\000"};
/* ZModule done */
/* including STRINGModule declarations */
Tc *YO0w(Tc *Athis); /* MSTRINGModule.reverse */
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato); /* MSTRINGModule.replaceAll */
/* STRINGModule done */
/* including IOModule declarations */
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Zs18 YQe8 = {&Zstatic, "\020File is not open\000"};
Ts YrF8(Yw8L *t); /* MIOModule__CFile.close */
Ts YSo_(Yw8L *t, Te _fr); /* MIOModule__CFile.Finish */
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
char *StrYw8L[];
Zs6 YtTU = {&Zstatic, "\004File\000"};
Ts Yhx8(); /* MIOModule.initSockets */
Tc *YDJh(Tc *AfileName); /* MIOModule.readFile */
Zs29 YroP = {&Zstatic, "\033IO.readFile(): Cannot open \000"};
Zs31 Y47X = {&Zstatic, "\035IO.readFile(): Seek error in \000"};
Zs32 Y9TS = {&Zstatic, "\036IO.readFile() Rewind error in \000"};
Zs30 YLjK = {&Zstatic, "\034IO.readFile() Read error in \000"};
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Ti Yd3R(YjUM *t); /* MIOModule__CStringWriter.byteSize */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {&Zstatic, "\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__YdXi_imt[3];
To ToYjUM[4];
char *StrYjUM[];
Zs14 YE4c = {&Zstatic, "\014StringWriter\000"};
Tb Y_3K(Tc *Aname); /* MIOModule.isExecutable */
Tc *Ycmi(Tc *AexeName); /* MIOModule.findExe */
Zs4 YFka = {&Zstatic, "\002./\000"};
Zs5 Y0y2 = {&Zstatic, "\003../\000"};
Zs6 Yykt = {&Zstatic, "\004PATH\000"};
Zs3 Y6 = {&Zstatic, "\001;\000"};
Zs6 YpPR = {&Zstatic, "\004.exe\000"};
Tc *YDop(Tc *AexeName, Tl *Adirs); /* MIOModule.findExeInDirList */
Tc *Yq8a(Tc *Afirst, Tc *Asecond); /* MIOModule.concatPath */
Tc *YPjH(Tc *Afname); /* MIOModule.resolve */
Ti Yr30(Tc *Afname); /* MIOModule.tailIndex */
Ti YN1T(Tc *Afname); /* MIOModule.tailSepIndex */
Ti YEpA(Tc *Afname); /* MIOModule.pastHeadIndex */
Tb Yhu2(Ti Ac); /* MIOModule.isPathSep */
Ti Y26N(Tc *Afname, Ti Aidx); /* MIOModule.nextPartIndex */
int JIOModule(int round);
/* IOModule done */
/* including GCModule declarations */
void YnFG(); /* MGCModule.run */
Tl *YJzU = NULL; /* MGCModule.runInfo */
Tc *YmwF(YXAF *t); /* MGCModule__CInfo.ToString */
Zs14 YQ_s = {&Zstatic, "\014GC run time \000"};
Zs13 Yjxt = {&Zstatic, "\013 usec, STW \000"};
Zs14 Y6De = {&Zstatic, "\014 usec, mark \000"};
Zs14 Yt0B = {&Zstatic, "\014 usec, free \000"};
Zs9 Ye7i = {&Zstatic, "\007 usec; \000"};
Zs18 YPtb = {&Zstatic, "\020 objects freed, \000"};
Zs15 Y0tw = {&Zstatic, "\015 still in use\000"};
To ToYXAF[7];
char *StrYXAF[];
Zs6 Yzlt = {&Zstatic, "\004Info\000"};
int JGCModule(int round);
/* GCModule done */
/* including THREADModule declarations */
/* including Config declarations */
Zs3 YYa = {&Zstatic, "\001q\000"};
Zs7 Yef1 = {&Zstatic, "\005quick\000"};
Zs36 YtSW = {&Zstatic, "\042Quick execution, disable backtrace\000"};
Y86c *Y4fD = 0; /* MConfig.quick */
Tb YEPH = 0; /* MConfig.noBacktrace */
Zs4 YsHb = {&Zstatic, "\002cc\000"};
Zs19 YhxU = {&Zstatic, "\021C compiler to use\000"};
Zs10 YeLO = {&Zstatic, "\010compiler\000"};
YzqH *Y6Gp = 0; /* MConfig.compiler */
Zs7 YApf = {&Zstatic, "\005ccarg\000"};
Zs4 YXja = {&Zstatic, "\002-g\000"};
Zs47 Yl1G = {&Zstatic, "\055C compiler arguments (before other arguments)\000"};
YzqH *YJ5o = 0; /* MConfig.ccarg */
Zs10 Yerz = {&Zstatic, "\010ccendarg\000"};
Zs46 YTzz = {&Zstatic, "\054C compiler arguments (after other arguments)\000"};
YzqH *Y6ma = 0; /* MConfig.ccendarg */
Zs10 Y_e2 = {&Zstatic, "\010portable\000"};
Zs44 Yslo = {&Zstatic, "\052Produce portable C code, not using threads\000"};
Y86c *YMSZ = 0; /* MConfig.portableFlag */
Tb YSaE = 0; /* MConfig.portable */
int JConfig(int round);
/* Config done */
Tt MTHREADModule__EState__T = {23, 0, 0};
YgC4 *YgC4__YwtA__YRHR(YgC4 *t, Tc *Amsg); /* MTHREADModule__CE_Thread.NEW__p2 */
Tc *YgC4__YwtA__YH0V(YgC4 *t); /* MTHREADModule__CE_Thread.ToString__p2 */
Tc *YgC4__YwtA__Yoww(YgC4 *t, Tb Averbose); /* MTHREADModule__CE_Thread.toString__p2 */
void YgC4__YwtA__YxaJa(YgC4 *t, Tb Averbose, Tr Aw); /* MTHREADModule__CE_Thread.writeTo__p2 */
void YgC4__YwtA__YxaJ(YgC4 *t, Tr Aw); /* MTHREADModule__CE_Thread.writeTo__p2 */
Tc *YgC4__Ytlm_I_imt[14];
To ToYgC4[4];
char *StrYgC4[];
Zs10 Yvlp = {&Zstatic, "\010E_Thread\000"};
YTgs *Yydu(YTgs *t, Tcb *Aproc); /* MTHREADModule__CThread.NEW */
YTgs *Yydua(YTgs *t, Tcb *Afunc); /* MTHREADModule__CThread.NEW */
void YcCua(YTgs *t); /* MTHREADModule__CThread.body */
void YqOJ(YTgs *t, Tcb *Aproc); /* MTHREADModule__CThread.setProc */
YTgs *YTgs__YCVY(YTgs *t); /* MTHREADModule__CThread.NEW__p1 */
void YTgs__Y7C8(YTgs *t); /* MTHREADModule__CThread.startBody__p1 */
void YTgs__YSuw(YTgs *t); /* MTHREADModule__CThread.start__p1 */
void YTgs__YSfi(YTgs *t); /* MTHREADModule__CThread.wait__p1 */
void YTgs__YDFp(YTgs *t); /* MTHREADModule__CThread.kill__p1 */
Ts YTgs__Y2Cz(YTgs *t, Te _fr); /* MTHREADModule__CThread.Finish__p1 */
Tc *YTgs__YTgs_I_imt[20];
To ToYTgs[5];
char *StrYTgs[];
YJ7s *YFiE(YRg3 *t, Tcb *Af); /* MTHREADModule__CEvalThread__t1.eval */
void YhD_a(YRg3 *t); /* MTHREADModule__CEvalThread__t1.body */
Zs43 YWvT = {&Zstatic, "\051Started evalThread without calling eval()\000"};
YJ7s *Y21D(Tcb *Af); /* MTHREADModule__CEvalThread__t1__X.eval */
YRg3 *YRg3__YCVY(YRg3 *t); /* MTHREADModule__CEvalThread__t1.NEW__p1 */
void YRg3__Y7C8(YRg3 *t); /* MTHREADModule__CEvalThread__t1.startBody__p1 */
void YRg3__YSuw(YRg3 *t); /* MTHREADModule__CEvalThread__t1.start__p1 */
Ts YRg3__Y2Cz(YRg3 *t, Te _fr); /* MTHREADModule__CEvalThread__t1.Finish__p1 */
To ToYRg3[6];
char *StrYRg3[];
Zs16 YtxE = {&Zstatic, "\016EvalThread__t1\000"};
YJ7s *YaWJ(Tcb *Af); /* MTHREADModule.eval__t1 */
YlXt *YCyl(YlXt *t); /* MTHREADModule__CLock.NEW */
void YHl9(YlXt *t); /* MTHREADModule__CLock.begin */
void Yvoo(YlXt *t); /* MTHREADModule__CLock.end */
Ts YMFu(YlXt *t, Te _fr); /* MTHREADModule__CLock.Finish */
To ToYlXt[1];
char *StrYlXt[];
Zs6 YzBS = {&Zstatic, "\004Lock\000"};
YTJ0 *YDpw(YTJ0 *t, YlXt *Alock); /* MTHREADModule__CAutoLock.NEW */
Ts YKWW(YTJ0 *t, Te _fr); /* MTHREADModule__CAutoLock.Finish */
To ToYTJ0[3];
char *StrYTJ0[];
Zs10 YTdt = {&Zstatic, "\010AutoLock\000"};
Y0Wo *YXGL(Y0Wo *t); /* MTHREADModule__CCond.NEW */
void YjFj(Y0Wo *t, Tb Aall); /* MTHREADModule__CCond.wakeup */
void YN6a(Y0Wo *t, YlXt *Alock); /* MTHREADModule__CCond.wait */
To ToY0Wo[1];
char *StrY0Wo[];
Zs6 YeBN = {&Zstatic, "\004Cond\000"};
int JTHREADModule(int round);
/* THREADModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
Tc *Y2R7 = NULL; /* MARGModule.exeName */
Tl *Y1p3 = NULL; /* MARGModule.rawArgs */
Tl *Y6fX = NULL; /* MARGModule.cleanArgs */
Tb YQpY = 0; /* MARGModule.stopFlag */
Tb YUBd = 0; /* MARGModule.disabled */
Tb YhUP = 0; /* MARGModule.disableGiveHelp */
Tb Y_kI = 0; /* MARGModule.disableCompactVal */
Ti YMLU = 1 /* MARGModule.exitVal */;
YuMQ *Yun4 = 0; /* MARGModule.theUsage */
int Ytu___r = 0; /* MARGModule.Ready */
Ts Ytu_(); /* MARGModule.Init */
To ToYnU5[1];
char *StrYnU5[];
Zs8 Yr32 = {&Zstatic, "\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {&Zstatic, "\061Using command line flag before they are available\000"};
void YS39(); /* MARGModule.notInitCheck */
Zs58 YY2Q = {&Zstatic, "\070Changing command line flag behavior after initialization\000"};
void YQtK(); /* MARGModule.initExeName */
Tc *YzHL(); /* MARGModule.getExeDir */
Zs3 YU = {&Zstatic, "\001.\000"};
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {&Zstatic, "\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {&Zstatic, "\001-\000"};
Zs4 Y1ia = {&Zstatic, "\002--\000"};
Zs6 YqzQ = {&Zstatic, "\004help\000"};
Zs10 Y3vi = {&Zstatic, "\010morehelp\000"};
Zs10 Yll7 = {&Zstatic, "\010helpmore\000"};
Zs4 YhZb = {&Zstatic, "\002no\000"};
Zs20 YcW8 = {&Zstatic, "\022Invalid argument: \000"};
Zs29 Y2hB = {&Zstatic, "\033Unknown command line flag: \000"};
Zs31 YcLH = {&Zstatic, "\035Duplicate command line flag: \000"};
Zs5 YjK7 = {&Zstatic, "\003yes\000"};
Zs6 YsfP = {&Zstatic, "\004true\000"};
Zs7 YvpX = {&Zstatic, "\005false\000"};
Zs43 YHSJ = {&Zstatic, "\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {&Zstatic, "\021Unexpected = in: \000"};
Zs28 Y_ju = {&Zstatic, "\032Missing argument for flag \000"};
Zs29 YjTs = {&Zstatic, "\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {&Zstatic, "\024To list flags use: '\000"};
Zs10 Y15F = {&Zstatic, "\010 --help'\000"};
Zs27 Yzoka = {&Zstatic, "\031D:/zimbu/lib/ARGModule.zu\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {&Zstatic, "\023Command line flags:\000"};
Zs13 YwXF = {&Zstatic, "\013--morehelp \000"};
Zs24 YEcf = {&Zstatic, "\026show more verbose help\000"};
Zs8 Yy2p = {&Zstatic, "\006number\000"};
Zs8 YanE = {&Zstatic, "\006string\000"};
Zs12 YDci = {&Zstatic, "\012string ...\000"};
Zs6 YulU = {&Zstatic, "\004 ...\000"};
Zs4 YVZ = {&Zstatic, "\002 [\000"};
Zs3 YEa = {&Zstatic, "\001]\000"};
Zs4 Yq_ = {&Zstatic, "\002 {\000"};
Zs3 Y9a = {&Zstatic, "\001}\000"};
Zs5 Y_y2 = {&Zstatic, "\003...\000"};
Zs6 Y2yA = {&Zstatic, "\004... \000"};
Zs13 Ym4c = {&Zstatic, "\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {&Zstatic, "\003%0%\000"};
To ToYuMQ[2];
char *StrYuMQ[];
Zs7 Y6qT = {&Zstatic, "\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {&Zstatic, "\050Adding command line flag after using one\000"};
Zs50 Y6pY = {&Zstatic, "\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {&Zstatic, "\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {&Zstatic, "\007unknown\000"};
Zs32 YtzG = {&Zstatic, "\036Duplicate command line flag: '\000"};
Zs17 YDyy = {&Zstatic, "\017' also used at \000"};
Tc *Y86c__YuQR_I_imt[19];
To ToY86c[12];
char *StrY86c[];
Zs6 YZ1F = {&Zstatic, "\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
To ToYJQu[13];
char *StrYJQu[];
Zs5 YzBa = {&Zstatic, "\003Int\000"};
YzqH *YBtk(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adefault, Tc *Adoc); /* MARGModule__CString.NEW */
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
YzqH *YzqH__YcLu(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CString.NEW__p1 */
void YzqH__YofP(YzqH *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CString.throwDuplicate__p1 */
Tr YzqH__Y836(YzqH *t, Tc *AargName); /* MARGModule__CString.setArgName__p1 */
Tc *YzqH__YuQR_I_imt[19];
To ToYzqH[13];
char *StrYzqH[];
Zs8 YDAE = {&Zstatic, "\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[12];
char *StrY_SI[];
Zs12 Ygf5 = {&Zstatic, "\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
/* including INTModule declarations */
Tc *YrLY(Ti Athis); /* MINTModule.toQuotedString */
Zs3 YW = {&Zstatic, "\0010\000"};
Ti Y64n = 9223372036854775807UL /* MINTModule.max */;
/* INTModule done */
/* including GarbageThread declarations */
void Y70b(); /* MGarbageThread.test */
Zs26 Y64ea = {&Zstatic, "\030testdir/GarbageThread.zu\000"};
void Y7To(); /* MGarbageThread.testDictLoop */
Tb YTHZ = 0; /* MGarbageThread.startedFilling */
void Y3Zw(); /* MGarbageThread.loopOverDict */
Zs18 YtAM = {&Zstatic, "\020Filling the dict\000"};
Zs3 Y2a = {&Zstatic, "\001v\000"};
Zs9 YgYB = {&Zstatic, "\007Looped \000"};
Zs8 Yace = {&Zstatic, "\006 times\000"};
void YEVk(); /* MGarbageThread.runGc */
Zs33 YvOX = {&Zstatic, "\037Starting to collect the garbage\000"};
Zs21 YQNE = {&Zstatic, "\023Ran the GC 40 times\000"};
/* GarbageThread done */
/* including HttpTest declarations */
void YqeF(); /* MHttpTest.test */
Zs21 YSp9a = {&Zstatic, "\023testdir/HttpTest.zu\000"};
void Y7aq(); /* MHttpTest.test1 */
Zs7 YE7m = {&Zstatic, "\005pages\000"};
Zs12 YyGk = {&Zstatic, "\012index.html\000"};
Zs11 Y7lu = {&Zstatic, "\011index.htm\000"};
Zs11 Y7pn = {&Zstatic, "\011zimbu.png\000"};
Zs11 YJVW = {&Zstatic, "\011image/png\000"};
Zs7 YaaL = {&Zstatic, "\005hello\000"};
Zs12 YvoF = {&Zstatic, "\012hello.html\000"};
Tc *Yz8u(YtzZ *Acontext); /* Y7aq.varz */
Zs11 YMUL = {&Zstatic, "\011something\000"};
Zs6 YiFm = {&Zstatic, "\004varz\000"};
Zs14 YatH = {&Zstatic, "\014hello there!\000"};
/* HttpTest done */
/* including PipeTest declarations */
void YyHq(); /* MPipeTest.test */
Zs21 Yzipa = {&Zstatic, "\023testdir/PipeTest.zu\000"};
YJ7s *YZxe = 0; /* MPipeTest.p */
void YvfC(); /* MPipeTest.print */
void YXS6(); /* MPipeTest.test1 */
Zs5 YLUk = {&Zstatic, "\003Mon\000"};
Zs5 YG2C = {&Zstatic, "\003Tue\000"};
Zs5 YMlK = {&Zstatic, "\003Wed\000"};
Zs5 Y5IC = {&Zstatic, "\003Thu\000"};
Zs5 Y2Z2 = {&Zstatic, "\003Fri\000"};
void YWS6(); /* MPipeTest.test2 */
Tc *Lambda6(); /* YWS6.Lambda6 */
Zs15 Y2d1 = {&Zstatic, "\015hello thread!\000"};
Zs15 Y6Tz = {&Zstatic, "\015from thread: \000"};
Tc *Lambda8(); /* YWS6.Lambda8 */
Zs26 YjYu = {&Zstatic, "\030hello from THREAD.eval()\000"};
Zs7 YhhK = {&Zstatic, "\005also \000"};
Tc *Y2BS(); /* YWS6.Nameless9 */
Zs23 Y0Oa = {&Zstatic, "\025hello from the thread\000"};
Zs24 Ygt4 = {&Zstatic, "\026hello through the pipe\000"};
Zs13 YNM5 = {&Zstatic, "\013from FUNC: \000"};
void YVS6(); /* MPipeTest.test3 */
Zs7 YjQE = {&Zstatic, "\005world\000"};
Tc *Lambda11(Tc *A0); /* YVS6.Lambda11 */
Zs8 YGL5 = {&Zstatic, "\006hello \000"};
YG3z *ZaYG3z(YG3z *p, void *t, Tt *tt, Tcb *cb, Tc * arg1);
Tc* ZcbYG3z(YG3z *cb);
Tcb *YNml(); /* MPipeTest.getFunc */
Zs7 YUAN = {&Zstatic, "\005there\000"};
Tc *Lambda1(Tc* *R0); /* YNml.Lambda1 */
YRKg *ZaYRKg(YRKg *p, void *t, Tt *tt, Tcb *cb, Tstring * arg1);
Tc* ZcbYRKg(YRKg *cb);
/* PipeTest done */
/* including ThreadTest declarations */
/* including Ticker declarations */
Yeip *YIZf(Yeip *t, Ti Areaders); /* CTicker.NEW */
YXJh *Ye8W(Yeip *t); /* CTicker.getTickReader */
Zs42 YWaW = {&Zstatic, "\050ERROR: more tick readers than available.\000"};
void YJxc(Yeip *t, Ti Aticks); /* CTicker.produceTicks */
YXJh *Y4GK(YXJh *t, Ti Aindex, Yeip *Aticker); /* CTicker__CReader.NEW */
void YCaR(YXJh *t, Ti Atick); /* CTicker__CReader.waitForTick */
void Y1Fl(YXJh *t); /* CTicker__CReader.done */
To ToYXJh[3];
char *StrYXJh[];
Zs8 Y0Er = {&Zstatic, "\006Reader\000"};
int Yeipa__r = 0; /* Init/1().Ready */
Yeip *Yeipa(Yeip *t); /* CTicker.Init */
To ToYeip[5];
char *StrYeip[];
Zs8 YaZC = {&Zstatic, "\006Ticker\000"};
/* Ticker done */
void YW3f(); /* MThreadTest.test */
Zs23 Y9pua = {&Zstatic, "\025testdir/ThreadTest.zu\000"};
Yeip *YIHB = 0; /* MThreadTest.testTicker */
void YzIq(); /* MThreadTest.threadOneFunc */
Zs18 YYNZ = {&Zstatic, "\020threadOneFunc(0)\000"};
Zs18 YmMZ = {&Zstatic, "\020threadOneFunc(1)\000"};
Zs18 YLKZ = {&Zstatic, "\020threadOneFunc(2)\000"};
void YOdR(); /* MThreadTest.threadTwoFunc */
Zs18 YCc8 = {&Zstatic, "\020threadTwoFunc(0)\000"};
Zs18 Yde8 = {&Zstatic, "\020threadTwoFunc(1)\000"};
void YJqh(); /* MThreadTest.test1 */
Zs5 YR0p = {&Zstatic, "\003One\000"};
Zs5 Y25C = {&Zstatic, "\003Two\000"};
void Y_r7(); /* MThreadTest.simpleFunc */
Zs14 YCHu = {&Zstatic, "\014simpleFunc()\000"};
void YIqh(); /* MThreadTest.test2 */
Zs22 YSzJ = {&Zstatic, "\024started simpleFunc()\000"};
void YPz8a(YjmP *t); /* MThreadTest__CServer.body */
Zs14 YFOE = {&Zstatic, "\014still alive \000"};
YjmP *YjmP__YTgs__YCVY(YjmP *t); /* MThreadTest__CServer.NEW__p2 */
void YjmP__YTgs__Y7C8(YjmP *t); /* MThreadTest__CServer.startBody__p2 */
void YjmP__YTgs__YSuw(YjmP *t); /* MThreadTest__CServer.start__p2 */
void YjmP__YTgs__YSfi(YjmP *t); /* MThreadTest__CServer.wait__p2 */
void YjmP__YTgs__YDFp(YjmP *t); /* MThreadTest__CServer.kill__p2 */
Ts YjmP__YTgs__Y2Cz(YjmP *t, Te _fr); /* MThreadTest__CServer.Finish__p2 */
void YjmP__YqOJ(YjmP *t, Tcb *Aproc); /* MThreadTest__CServer.setProc__p1 */
To ToYjmP[5];
char *StrYjmP[];
void YHqh(); /* MThreadTest.test3 */
Zs9 Yyxf = {&Zstatic, "\007test3()\000"};
Zs6 Yp8I = {&Zstatic, "\004nice\000"};
void YGqh(); /* MThreadTest.test4 */
Ts Lambda3(); /* YGqh.Lambda3 */
Zs21 Yobe = {&Zstatic, "\023in the test4 thread\000"};
void YFvG(); /* YGqh.Nameless4 */
Zs19 Y8pV = {&Zstatic, "\021from test4 thread\000"};
void YqfF(); /* MThreadTest.testAutoLock */
Zs14 YJhU = {&Zstatic, "\014got the lock\000"};
Zs19 Ybkv = {&Zstatic, "\021released the lock\000"};
Zs20 YMAI = {&Zstatic, "\022got the lock again\000"};
Zs25 YLdK = {&Zstatic, "\027released the lock again\000"};
/* ThreadTest done */
/*** callbacks for methods invoked directly ***/
Tc* ZcbLambda1(Tcb *cb, Tc* *arg0);
Tcb ZCB_Lambda1 = {0, ZcbLambda1, -1};
Tc* ZcbLambda11(Tcb *cb, Tc *arg0);
Tcb ZCB_Lambda11 = {0, ZcbLambda11, -1};
Ts ZcbLambda3(Tcb *cb);
Tcb ZCB_Lambda3 = {0, ZcbLambda3, -1};
Tc* ZcbLambda6(Tcb *cb);
Tcb ZCB_Lambda6 = {0, ZcbLambda6, -1};
Tc* ZcbLambda8(Tcb *cb);
Tcb ZCB_Lambda8 = {0, ZcbLambda8, -1};
Tc* ZcbY2BS(Tcb *cb);
Tcb ZCB_Y2BS = {0, ZcbY2BS, -1};
void ZcbY3Zw(Tcb *cb);
Tcb ZCB_Y3Zw = {0, ZcbY3Zw, -1};
void ZcbYEVk(Tcb *cb);
Tcb ZCB_YEVk = {0, ZcbYEVk, -1};
void ZcbYFvG(Tcb *cb);
Tcb ZCB_YFvG = {0, ZcbYFvG, -1};
void ZcbYOdR(Tcb *cb);
Tcb ZCB_YOdR = {0, ZcbYOdR, -1};
void ZcbY_r7(Tcb *cb);
Tcb ZCB_Y_r7 = {0, ZcbY_r7, -1};
void ZcbYvfC(Tcb *cb);
Tcb ZCB_YvfC = {0, ZcbYvfC, -1};
Tc* ZcbYz8u(Tcb *cb, YtzZ *arg0);
Tcb ZCB_Yz8u = {0, ZcbYz8u, -1};
void ZcbYzIq(Tcb *cb);
Tcb ZCB_YzIq = {0, ZcbYzIq, -1};
Tto Tstring__T = {390, (Tc*)&YanE, 0, 0, 0, 0, 0, 0, ToTstring};

Tt bool__T  = {21, 0, 0};
Tt byte__T  = {11, 0, 0};
Tt byteString__T = {201, 0, 0};
Tt float128__T  = {83, 0, 0};
Tt float32__T  = {81, 0, 0};
Tt float80__T  = {82, 0, 0};
Tt float__T  = {80, 0, 0};
Tt int16__T  = {2, 0, 0};
Tt int32__T  = {3, 0, 0};
Tt int8__T  = {1, 0, 0};
Tt int__T  = {0, 0, 0};
Tt nat16__T  = {12, 0, 0};
Tt nat32__T  = {13, 0, 0};
Tt nat__T  = {10, 0, 0};
Tt status__T  = {22, 0, 0};
Tt string__T = {200, 0, 0};
Tt type__T  = {101, 0, 0};
Tt thread__T = {250, 0, 0};
Tt array__T = {300, 0, 0};
Tt list__T = {301, 0, 0};
Tt dict__T = {302, 0, 0};
Tt cb__T  = {330, 0, 0};
Tt iobj__T = {391, 0, 0};
int ZglobInit(int round);

typedef struct Zfo__S {
 int off;
 Tt  *type;
} Zfo;
typedef struct Zsf__S {
 volatile int pos;
 struct Zsf__S *prev;
 Zfo *frof;
} Zsf;
#define POS_MASK 0x3fffffff
typedef struct StryCtx__S {
 jmp_buf jmpBuf;
 Zsf *sf;
} Ttc;
typedef struct Senv__S {
 Ttc  *tryCtx;
 int  tryCtxSize;
 int  tryCtxUsed;
 Tr   *thrown;
 int  thrownSize;
 int  thrownUsed;
 pthread_t tid;
 int finished;
 int found;
 int timedOut;
 int inZa;
 int ZaEntered;
 Zsf *startFrames;
 Zsf *topFrame;
 Zohf *firstUsedF;
 int tosNr;
} Tn; /* per-thread environemnt */

typedef struct Zohpf__S Zohpf;
struct Zohpf__S {
 Zohpf *next;
 Zohf  *firstUsedF;
};
Zohpf *usedListF = NULL;
Zohf *toFinish = ZOHF_LAST;
pthread_mutex_t threadsMutex;
Tl *threads;

static pthread_key_t ZenvKey;
void ZenvFree(void *ptr) {
 Tn *e = (Tn *)ptr;
 if (e->startFrames) free(e->startFrames);
 pthread_mutex_lock(&threadsMutex);
 ZListRemovePtrItem(threads, ZListFind(threads, (Tz)(void*)e));
 pthread_mutex_unlock(&threadsMutex);
 free(ptr);
}
Tn *ZgetEnv() {
 Tn *e = pthread_getspecific(ZenvKey);
 if (e == NULL) {
  e = ZaNmi(sizeof(Tn));
  e->tid = pthread_self();
  pthread_setspecific(ZenvKey, e);
 }
 return e;
}
void ZenvInit() {
 (void)pthread_key_create(&ZenvKey, ZenvFree);
 pthread_setspecific(ZenvKey, NULL);
 pthread_mutex_init(&threadsMutex, NULL);
 threads = ZnewList(&thread__T, 0);
 ZLa(threads, -1, (Tz)(void*)ZgetEnv());
}

void ZgcFinishAll(int rsn);
void ZgcRun();
void beforeExit() {
 {
  int i;
  Tn *e = ZgetEnv();
  for (i = 0; i < threads->itemCount; ++i) {
   Tn *ie = ZListGetPtr(threads, i);
   if (ie != e && !ie->finished) {
    pthread_cancel(ie->tid);
    ie->finished = 1;
   }
  }
 }
 ZgcFinishAll(1);
}

Ti ZgcUseCount = 0;
Ti ZgcStwTime = 0;
Ti ZgcMarkTime = 0;
Ti ZgcFinishTime = 0;
Ti ZgcFreeTime = 0;
Ti ZgcFreeCount = 0;


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 return p;
}

/* allocate memory */
void *ZaF(size_t size, To *to, Ts (*ff)(void *, Te), int nox) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaF)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 ((Zoh *)p)->np = (Zoh*)e->firstUsedF;
 e->firstUsedF = p;
 ((Zohf *)p)->to = to;
 ((Zohf *)p)->ff = ff;
 if (nox) ((Zohf *)p)->fok = FOK_NOX;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa) {
  e->inZa = 1;
  p = calloc(1, size);
  e->inZa = 0;
 }
 if (p == NULL) {
  if (e->inZa || e->ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++e->ZaEntered;
  ZthrowOutOfMemory(size);
 }
 e->ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 p = calloc(1, size);
 if (p == NULL) {
  {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ZthrowOutOfMemory(size);
 }
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa && !e->ZaEntered) {
  e->inZa = 1;
  p = realloc(op, nsize);
  e->inZa = 0;
  if (p == NULL) {
    ++e->ZaEntered;
    ZthrowOutOfMemory(nsize);
  }
  e->ZaEntered = 0;
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = Za(nsize);
 if (op)
  memmove(p + ZOH_OFF, op + ZOH_OFF, nsize > osize ? osize - ZOH_OFF : nsize - ZOH_OFF);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void *ZranNm(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 Tn *e = ZgetEnv();
 if (!e->inZa && !e->ZaEntered) {
  e->inZa = 1;
  p = realloc(op, nsize);
  e->inZa = 0;
  if (p == NULL) {
   ++e->ZaEntered;
   ZthrowOutOfMemory(nsize);
  }
  if (nsize > osize) memset(p + osize, 0, nsize - osize);
  return p;
 }
 p = ZaNm(nsize);
 if (op) memmove(p, op, nsize > osize ? osize : nsize);
 if (nsize > osize) memset(p + osize, 0, nsize - osize);
 return p;
}

void Zfree(void *p) {
 if (p) free(p);
}

void ZtryDeeper(Tn *e, Zsf *sf);

void ZcallFinish(Zohf *p, Te rsn) {
 if ((p->fok & FOK_OK) == 0 && (rsn != 1 || (p->fok & FOK_NOX) == 0)) {
  Tn *e = ZgetEnv();
  int try_index = e->tryCtxUsed;
  Zsf *tf = e->topFrame;
  ZtryDeeper(e, e->topFrame);
  if (setjmp(e->tryCtx[try_index].jmpBuf) == 0) {
   p->ff(p, rsn);
  } else {
   e->topFrame = tf;
   YvL0(e->thrown[--e->thrownUsed]);
   p->fok |= FOK_OK;
  }
  e->tryCtxUsed = try_index;
 }
}
void ZFinishIobj(Tr *tr, Te rsn) {
 if (tr->ptr != NULL) {
  if (((Tto*)tr->table[0])->Finish != NULL)
   ZcallFinish(tr->ptr, rsn);
   tr->ptr = NULL;
 }
}
void ZgcCallFinish(Te rsn) {
 Zohf *p = toFinish;
 Zohf *np;
 toFinish = ZOHF_LAST;
 while (p != ZOHF_LAST) {
  np = (Zohf*)((Tip)(p->np) & ~3);
  ZcallFinish(p, rsn);
  if (usedListF == NULL) {
   usedListF = ZaNmi(sizeof(Zohpf));
   usedListF->firstUsedF = ZOHF_LAST;
  }
  p->np = (Zoh*)usedListF->firstUsedF;
  usedListF->firstUsedF = p;
  p = np;
 }
}

void ZgcFinishAll(int rsn) {
 Zohpf *up;
 Zohpf *np;
 for (up = usedListF; up; up = np) {
  if (toFinish == ZOHF_LAST) {
   toFinish = up->firstUsedF;
  } else {
   Zohf *p = toFinish;
   while ((Zohf*)((Tip)p->np & ~3) != ZOHF_LAST) p = (Zohf*)((Tip)p->np & ~3);
   p->np = (Zoh*)up->firstUsedF;
  }
  np = up->next;
  free(up);
 }
 usedListF = NULL;
 ZgcCallFinish(rsn);
}

Tc *ZnewStringInit(Ti len, Tc **pp) {
 Ti rlen = len;
 int i;
 int n = ZOH_OFF;
 Tc buf[20];
 Tc *res;
 buf[0] = (rlen & 127);
 rlen >>= 7;
 for (i = 1; rlen > 0; ++i)
 {
  buf[i] = (rlen & 127) + 128;
  rlen >>= 7;
 }
 res = Za(ZOH_OFF + len + i + 1);
 while (i > 0) res[n++] = buf[--i];
 *pp = res + n;
 return res;
}

Tc *ZnewString(Tc *p, Ti len) {
 Tc *pp;
 Tc *res = ZnewStringInit(len, &pp);
 memmove(pp, p, len);
 return res;
}
Tc YXwB[]="D:/zimbu/Config.zu";
Tc Yzok[]="D:/zimbu/lib/ARGModule.zu";
Tc Y_4X[]="D:/zimbu/lib/EModule.zu";
Tc Y1XW[]="D:/zimbu/lib/GCModule.zu";
Tc Y_VG[]="D:/zimbu/lib/HTTPModule.zu";
Tc YAdQ[]="D:/zimbu/lib/INTModule.zu";
Tc YkTo[]="D:/zimbu/lib/IOModule.zu";
Tc YSsV[]="D:/zimbu/lib/PIPEModule.zu";
Tc YlLp[]="D:/zimbu/lib/STRINGModule.zu";
Tc YaR1[]="D:/zimbu/lib/SYSModule.zu";
Tc Ynl5[]="D:/zimbu/lib/THREADModule.zu";
Tc Ysv0[]="D:/zimbu/lib/TIMEModule.zu";
Tc Ypx4[]="D:/zimbu/lib/ZModule.zu";
Tc Y64e[]="testdir/GarbageThread.zu";
Tc YSp9[]="testdir/HttpTest.zu";
Tc Yzip[]="testdir/PipeTest.zu";
Tc Y9pu[]="testdir/ThreadTest.zu";
Tc Y94F[]="testdir/Ticker.zu";
Tc YYSG[]="testmore.zu";
Tc Y_VO[]="ARG.Bool.NEW/1()";
Tcpos ZcTbl3273[]={
{791,5},
{2,7},
{3,16},
{4,16},
{5,18},
};
Tc YImf[]="ARG.Bool.NEW__p1/1()";
Tcpos ZcTbl76644[]={
{637,5},
{1,7},
{2,9},
{4,7},
{6,9},
{8,7},
{9,20},
{11,7},
{12,19},
{14,12},
{18,7},
{19,20},
{20,19},
{23,7},
{24,9},
{25,11},
{27,9},
{29,7},
{30,9},
{31,11},
{33,9},
{34,11},
{36,9},
{38,12},
};
Tc YM2k[]="ARG.Bool.setToDefault/1()";
Tcpos ZcTbl38911[]={
{800,11},
{1,16},
};
Tc YgDO[]="ARG.Bool.throwDuplicate__p1/1()";
Tcpos ZcTbl75697[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc YPPv[]="ARG.Init()";
Tcpos ZcTbl66501[]={
{78,29},
};
Tc Ygzb[]="ARG.Int.setToDefault/1()";
Tcpos ZcTbl16350[]={
{865,11},
{1,16},
};
Tc YAAq[]="ARG.String.NEW/1()";
Tcpos ZcTbl80636[]={
{945,5},
{1,7},
{2,16},
{3,16},
{4,21},
};
Tc YGq4[]="ARG.String.NEW__p1/1()";
Tcpos ZcTbl4839[]={
{637,5},
{1,7},
{2,9},
{4,7},
{6,9},
{8,7},
{9,20},
{11,7},
{12,19},
{14,12},
{18,7},
{19,20},
{20,19},
{23,7},
{24,9},
{25,11},
{27,9},
{29,7},
{30,9},
{31,11},
{33,9},
{34,11},
{36,9},
{38,12},
};
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
};
Tc YF9k[]="ARG.String.throwDuplicate__p1/1()";
Tcpos ZcTbl52648[]={
{679,11},
{1,44},
{2,18},
{4,7},
};
Tc YRbs[]="ARG.StringList.setToDefault/1()";
Tcpos ZcTbl64478[]={
{1046,11},
{1,16},
};
Tc YEFE[]="ARG.Usage.get()";
Tcpos ZcTbl43000[]={
{600,11},
{1,23},
{2,7},
{3,17},
{5,49},
};
Tc YzK9[]="ARG.displayHelp()";
Tcpos ZcTbl29560[]={
{461,5},
{1,7},
{3,5},
{6,35},
{7,5},
{8,19},
{9,7},
{10,33},
{7,5},
{17,5},
{18,7},
{19,9},
{20,9},
{23,7},
{24,21},
{26,26},
{28,9},
{29,11},
{30,21},
{32,21},
{34,15},
{35,21},
{36,11},
{37,21},
{39,21},
{41,15},
{42,21},
{43,11},
{44,21},
{46,21},
{48,15},
{50,9},
{51,11},
{52,21},
{54,21},
{58,23},
{59,9},
{60,16},
{62,9},
{63,11},
{65,13},
{66,15},
{67,22},
{69,15},
{71,18},
{73,16},
{76,9},
{77,16},
{80,9},
{81,11},
{82,13},
{83,13},
{85,13},
{87,11},
{88,13},
{89,13},
{92,11},
{93,24},
{95,11},
{96,24},
{23,7},
{17,5},
{103,10},
};
Tc Yza4[]="ARG.error()";
Tcpos ZcTbl85295[]={
{449,5},
{1,5},
{2,7},
{4,5},
{5,7},
{7,10},
};
Tc YBSz[]="ARG.getExeDir()";
Tcpos ZcTbl32618[]={
{248,24},
{1,5},
{3,14},
{5,20},
};
Tc Yh2v[]="ARG.init()";
Tcpos ZcTbl82533[]={
{259,5},
{1,7},
{3,20},
{4,19},
{6,7},
{7,9},
{9,7},
{10,9},
{9,7},
{12,7},
{13,9},
{12,7},
{16,17},
{17,22},
{19,7},
{20,9},
{22,16},
{26,22},
{27,9},
{28,11},
{29,11},
{30,21},
{33,11},
{34,21},
{39,13},
{40,37},
{41,15},
{44,17},
{48,34},
{49,15},
{50,23},
{51,26},
{54,20},
{57,15},
{58,22},
{59,17},
{60,19},
{62,30},
{63,27},
{66,26},
{72,37},
{75,34},
{76,15},
{77,23},
{78,26},
{80,17},
{82,24},
{83,19},
{86,21},
{88,23},
{89,36},
{89,36},
{90,37},
{91,32},
{92,28},
{93,33},
{96,47},
{98,29},
{99,32},
{80,17},
{105,15},
{106,17},
{107,27},
{108,22},
{111,13},
{112,15},
{113,17},
{116,15},
{117,17},
{119,15},
{120,15},
{121,30},
{121,30},
{122,17},
{123,19},
{124,35},
{125,40},
{126,35},
{128,21},
{131,33},
{133,27},
{134,17},
{135,19},
{137,36},
{137,36},
{138,31},
{139,17},
{140,19},
{139,17},
{144,17},
{146,24},
{147,19},
{148,21},
{150,25},
{152,17},
{153,31},
{153,31},
{154,19},
{156,35},
{157,21},
};
Tcpos ZcTbl82534[]={
{422,40},
{1,35},
{2,21},
{4,29},
{5,34},
{5,34},
{6,19},
{8,35},
{9,21},
{11,35},
{12,21},
{15,19},
{-144,7},
};
Tc YTJ0b[]="ARG.initExeName()";
Tcpos ZcTbl77164[]={
{238,13},
};
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc YF2d[]="Config";
Tcpos ZcTbl22398[]={
{57,12},
{2,12},
{6,29},
{5,14},
{7,14},
{9,14},
{12,12},
{14,12},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0hW[]="E.BadValue.ToString__p2/2()";
Tcpos ZcTbl52701[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YO_6[]="E.BadValue.toString__p2/2()";
Tcpos ZcTbl56573[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y9VX[]="E.BadValue.writeTo__p2/4()";
Tcpos ZcTbl46171[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y4u_[]="E.BadValue.writeTo__p2/5()";
Tcpos ZcTbl56372[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y_Qs[]="E.DivideByZero.NEW__p3/3()";
Tcpos ZcTbl73471[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yk5m[]="E.DivideByZero.ToString__p3/3()";
Tcpos ZcTbl17179[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YNLE[]="E.DivideByZero.toString__p3/3()";
Tcpos ZcTbl69435[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YG80[]="E.DivideByZero.writeTo__p3/6()";
Tcpos ZcTbl44130[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YLzZ[]="E.DivideByZero.writeTo__p3/7()";
Tcpos ZcTbl54331[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YVQQ[]="E.E_Thread.NEW__p2/2()";
Tcpos ZcTbl97985[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YZd2[]="E.E_Thread.ToString__p2/2()";
Tcpos ZcTbl33805[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y8CZ[]="E.E_Thread.toString__p2/2()";
Tcpos ZcTbl86061[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y8Ap[]="E.E_Thread.writeTo__p2/4()";
Tcpos ZcTbl7051[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y39r[]="E.E_Thread.writeTo__p2/5()";
Tcpos ZcTbl17252[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YpMw[]="E.Exception.NEW()";
Tcpos ZcTbl83031[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y2Qj[]="E.Exception.ToString()";
Tcpos ZcTbl51535[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y3yN[]="E.Exception.toString()";
Tcpos ZcTbl97135[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YgcH[]="E.Exception.writeTo()";
Tcpos ZcTbl49183[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YYT9[]="E.Exception.writeTo/1()";
Tcpos ZcTbl36491[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YwZj[]="E.Exit.NEW/1()";
Tcpos ZcTbl31890[]={
{171,5},
{1,14},
{2,16},
{4,20},
{4,24},
};
Tc Y0TG[]="E.Exit.ToString/1()";
Tcpos ZcTbl18934[]={
{182,11},
{1,27},
{2,7},
{3,16},
};
Tc Ywpu[]="E.Exit.toString__p1/1()";
Tcpos ZcTbl94689[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YTjU[]="E.Exit.writeTo/2()";
Tcpos ZcTbl92163[]={
{191,11},
{1,7},
{2,9},
{3,9},
{5,7},
{6,7},
{7,7},
{8,9},
{9,9},
};
Tc Y9aV[]="E.Exit.writeTo__p1/3()";
Tcpos ZcTbl42983[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y9Cv[]="E.IOError.NEW__p2/2()";
Tcpos ZcTbl48299[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YVJp[]="E.IOError.ToString__p2/2()";
Tcpos ZcTbl79935[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Yc7B[]="E.IOError.toString__p2/2()";
Tcpos ZcTbl32191[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y59h[]="E.IOError.writeTo__p2/4()";
Tcpos ZcTbl89685[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y0Jk[]="E.IOError.writeTo__p2/5()";
Tcpos ZcTbl99886[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Yp81[]="E.Init.NEW__p2/2()";
Tcpos ZcTbl53377[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yuz_[]="E.Init.NEW__p2/3()";
Tcpos ZcTbl63578[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YAwk[]="E.Init.ToString__p2/2()";
Tcpos ZcTbl89581[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YeMI[]="E.Init.toString__p2/2()";
Tcpos ZcTbl93453[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YMF2[]="E.Init.writeTo__p2/4()";
Tcpos ZcTbl96107[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YR5_[]="E.Init.writeTo__p2/5()";
Tcpos ZcTbl6308[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YbzA[]="E.Internal.NEW__p2/2()";
Tcpos ZcTbl78082[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y8mE[]="E.Internal.ToString__p2/2()";
Tcpos ZcTbl27618[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YFnU[]="E.Internal.toString__p2/2()";
Tcpos ZcTbl79874[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YxLq[]="E.Internal.writeTo__p2/4()";
Tcpos ZcTbl412[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YCbo[]="E.Internal.writeTo__p2/5()";
Tcpos ZcTbl10613[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ycb9[]="E.KeyExists.NEW__p3/3()";
Tcpos ZcTbl85000[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Yoiq[]="E.KeyExists.ToString__p3/3()";
Tcpos ZcTbl52728[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YJyB[]="E.KeyExists.toString__p3/3()";
Tcpos ZcTbl4984[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4SL[]="E.KeyExists.writeTo__p3/6()";
Tcpos ZcTbl14715[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y9iJ[]="E.KeyExists.writeTo__p3/7()";
Tcpos ZcTbl24916[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YAVe[]="E.KeyNotFound.NEW__p3/3()";
Tcpos ZcTbl29585[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YMB8[]="E.KeyNotFound.ToString__p3/3()";
Tcpos ZcTbl15669[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YlfT[]="E.KeyNotFound.toString__p3/3()";
Tcpos ZcTbl67925[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Ygil[]="E.KeyNotFound.writeTo__p3/6()";
Tcpos ZcTbl43124[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YlJi[]="E.KeyNotFound.writeTo__p3/7()";
Tcpos ZcTbl53325[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YF6S[]="E.MemoryAccess.NEW__p2/2()";
Tcpos ZcTbl73580[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YQJA[]="E.MemoryAccess.ToString__p2/2()";
Tcpos ZcTbl66036[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Yh7q[]="E.MemoryAccess.toString__p2/2()";
Tcpos ZcTbl18292[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc Y4vu[]="E.MemoryAccess.writeTo__p2/4()";
Tcpos ZcTbl25958[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y_4w[]="E.MemoryAccess.writeTo__p2/5()";
Tcpos ZcTbl36159[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y1As[]="E.NilAccess.NEW__p2/2()";
Tcpos ZcTbl32086[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YN54[]="E.NilAccess.ToString__p2/2()";
Tcpos ZcTbl26854[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YkLW[]="E.NilAccess.toString__p2/2()";
Tcpos ZcTbl79110[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YcIS[]="E.NilAccess.writeTo__p2/4()";
Tcpos ZcTbl35088[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Y7gV[]="E.NilAccess.writeTo__p2/5()";
Tcpos ZcTbl45289[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YobA[]="E.OutOfMemory.NEW/3()";
Tcpos ZcTbl80644[]={
{262,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Ym8y[]="E.OutOfMemory.ToString__p2/2()";
Tcpos ZcTbl86699[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Ys9t[]="E.OutOfMemory.toString__p2/2()";
Tcpos ZcTbl90571[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YoZS[]="E.OutOfMemory.writeTo__p2/4()";
Tcpos ZcTbl11217[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YtpQ[]="E.OutOfMemory.writeTo__p2/5()";
Tcpos ZcTbl21418[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Y99g[]="E.OutOfRange.NEW__p3/3()";
Tcpos ZcTbl56381[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0DD[]="E.OutOfRange.ToString__p3/3()";
Tcpos ZcTbl31729[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y6co[]="E.OutOfRange.toString__p3/3()";
Tcpos ZcTbl83985[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YqK0[]="E.OutOfRange.writeTo__p3/6()";
Tcpos ZcTbl52608[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc Ylj3[]="E.OutOfRange.writeTo__p3/7()";
Tcpos ZcTbl62809[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc Yq0C[]="E.Thread.NEW/1()";
Tcpos ZcTbl61772[]={
{569,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YYc1[]="E.Thread.ToString__p2/2()";
Tcpos ZcTbl44333[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc Y9D_[]="E.Thread.toString__p2/2()";
Tcpos ZcTbl96589[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YwJf[]="E.Thread.writeTo__p2/4()";
Tcpos ZcTbl45067[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YB9c[]="E.Thread.writeTo__p2/5()";
Tcpos ZcTbl55268[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc Y0Td[]="E.WrongType.ToString__p2/2()";
Tcpos ZcTbl12896[]={
{79,11},
{1,27},
{2,7},
{3,16},
};
Tc YOoP[]="E.WrongType.toString__p2/2()";
Tcpos ZcTbl16768[]={
{105,11},
{1,27},
{2,7},
{3,16},
};
Tc YlgI[]="E.WrongType.writeTo__p2/4()";
Tcpos ZcTbl86818[]={
{114,11},
{1,7},
{3,9},
{4,12},
{5,12},
{6,14},
{7,16},
{9,16},
{10,16},
{11,16},
{12,18},
{13,18},
{5,12},
};
Tc YgQK[]="E.WrongType.writeTo__p2/5()";
Tcpos ZcTbl97019[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YEFs[]="E.unhandledException()";
Tcpos ZcTbl15718[]={
{609,23},
{0,23},
{0,23},
};
Tc YgcM[]="E.writeToStderr()";
Tcpos ZcTbl52386[]={
{629,5},
{1,5},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{1,7},
{2,5},
};
Tc Y3Ya[]="GC";
Tcpos ZcTbl7238[]={
{40,14},
};
Tc YUXK[]="GC.Info.ToString()";
Tcpos ZcTbl71057[]={
{51,11},
{7,41},
};
Tc Y8BT[]="GC.run()";
Tcpos ZcTbl30206[]={
{21,24},
{1,4},
{4,19},
{5,4},
{12,22},
{13,7},
};
Tc Y_2n[]="GarbageThread.loopOverDict()";
Tcpos ZcTbl16490[]={
{34,5},
{1,20},
{2,27},
{3,5},
{4,7},
{3,5},
{8,5},
{9,7},
{10,9},
{9,7},
{8,5},
{13,5},
};
Tc Y7Vi[]="GarbageThread.runGc()";
Tcpos ZcTbl57803[]={
{52,5},
{1,7},
{0,5},
{4,5},
{5,5},
{6,7},
{7,7},
{5,5},
{9,5},
};
Tc YITr[]="GarbageThread.test()";
Tcpos ZcTbl91844[]={
{14,5},
{1,5},
};
Tc YBpN[]="GarbageThread.testDictLoop()";
Tcpos ZcTbl58522[]={
{21,26},
{1,5},
{3,27},
{4,5},
{6,5},
{7,5},
};
Tc YGWN[]="HTTP.Context.NEW()";
Tcpos ZcTbl91620[]={
{150,5},
{1,15},
{2,16},
{3,17},
};
Tc Yd9V[]="HTTP.FileServlet.NEW()";
Tcpos ZcTbl94336[]={
{239,5},
{1,13},
{2,17},
};
Tc Y5GQ[]="HTTP.FileServlet.addPath__p1/1()";
Tcpos ZcTbl53063[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc YXHL[]="HTTP.FileServlet.handle__p1/1()";
Tcpos ZcTbl38545[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc Ykap[]="HTTP.FileServlet.serve/1()";
Tcpos ZcTbl53863[]={
{251,11},
{2,7},
{3,29},
{7,14},
};
Tc YCzi[]="HTTP.FileServlet.setFile()";
Tcpos ZcTbl51434[]={
{245,11},
{1,17},
};
Tc YRZz[]="HTTP.FileServlet.setMimeType__p1/1()";
Tcpos ZcTbl11603[]={
{191,11},
{1,17},
};
Tc YSio[]="HTTP.FunctionServlet.NEW()";
Tcpos ZcTbl88986[]={
{293,5},
{1,13},
{2,18},
};
Tc YBlz[]="HTTP.FunctionServlet.addPath__p1/1()";
Tcpos ZcTbl35537[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc Y4b2[]="HTTP.FunctionServlet.handle__p1/1()";
Tcpos ZcTbl14099[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc Y7n9[]="HTTP.FunctionServlet.serve/1()";
Tcpos ZcTbl37281[]={
{305,11},
{1,29},
{2,14},
};
Tc YFGh[]="HTTP.Request.NEW()";
Tcpos ZcTbl46640[]={
{52,5},
{1,20},
};
Tc YLdV[]="HTTP.Request.ToString()";
Tcpos ZcTbl84668[]={
{89,11},
{1,27},
{2,7},
{3,7},
{4,7},
{5,7},
{6,7},
{7,7},
{8,9},
{7,7},
{10,7},
{11,9},
{14,16},
};
Tc YfxG[]="HTTP.Response.NEW()";
Tcpos ZcTbl34822[]={
{124,5},
{1,13},
{2,12},
{3,20},
{4,7},
{5,13},
};
Tc Yxl5[]="HTTP.Response.setLength()";
Tcpos ZcTbl14874[]={
{133,11},
{1,38},
};
Tc Ys1T[]="HTTP.Response.setType()";
Tcpos ZcTbl84506[]={
{138,11},
{1,36},
};
Tc YGL9[]="HTTP.Server.Init/1()";
Tcpos ZcTbl32864[]={
{391,22},
{1,22},
{3,22},
{4,22},
{7,22},
};
Tc Y32H[]="HTTP.Server.NEW()";
Tcpos ZcTbl96330[]={
{403,5},
{1,13},
{2,7},
{3,15},
{8,17},
};
Tc YXL6[]="HTTP.Server.addServlet()";
Tcpos ZcTbl98650[]={
{431,11},
{1,7},
};
Tc Y7FCa[]="HTTP.Server.body()";
Tcpos ZcTbl99366[]={
{465,11},
{2,24},
{3,7},
{4,4},
{58,4},
{72,4},
{76,23},
{80,28},
{81,9},
{82,4},
{86,52},
{87,9},
{88,11},
{89,22},
{87,9},
{95,9},
{96,13},
{95,9},
{100,18},
{101,9},
{102,13},
{101,9},
{104,18},
{105,27},
{106,9},
{108,22},
{109,20},
{113,9},
{114,13},
{113,9},
{120,29},
{122,9},
{123,15},
{124,15},
{126,15},
{127,11},
{128,11},
{129,13},
{132,25},
{134,9},
{135,27},
{136,11},
{137,20},
{139,25},
{140,11},
{142,18},
{144,11},
{148,11},
{149,13},
{155,9},
{156,15},
{157,11},
{159,13},
{160,17},
{163,11},
{165,17},
{170,33},
{171,11},
{172,64},
{173,33},
{174,36},
{175,13},
{176,34},
{177,15},
{178,17},
{181,15},
{182,17},
{181,15},
{185,15},
{186,17},
{185,15},
{188,26},
{189,15},
{193,19},
{194,19},
{195,15},
{199,26},
{200,26},
{175,13},
{202,13},
{205,26},
{207,40},
{210,15},
{155,9},
{212,9},
{213,11},
{217,24},
{218,9},
{219,20},
{220,11},
{221,13},
{224,9},
{227,36},
{228,11},
{232,11},
{234,13},
{235,15},
{237,4},
{242,4},
{246,13},
};
Tcpos ZcTbl99367[]={
{712,15},
{2,13},
{5,13},
{-15,11},
{7,20},
{8,11},
{9,13},
{10,13},
{11,15},
{12,15},
{13,15},
{15,15},
{17,13},
{20,20},
{23,15},
{26,25},
{28,27},
{29,9},
{29,9},
{30,11},
{31,13},
{32,20},
{30,11},
{37,11},
{38,13},
{40,13},
{43,9},
{44,21},
{45,20},
{46,21},
{48,9},
{53,70},
{55,9},
{56,22},
{55,9},
{58,17},
{60,9},
{61,11},
{62,11},
{63,13},
{64,13},
{65,13},
{66,15},
{67,15},
{68,15},
{70,15},
{72,13},
{75,4},
{79,4},
{82,4},
{89,11},
{90,24},
{91,21},
{92,4},
{98,4},
{101,4},
{109,4},
{114,15},
{115,9},
{116,11},
{118,4},
};
Tc YZ7U[]="HTTP.Server.setFileRoot()";
Tcpos ZcTbl30564[]={
{425,11},
{1,17},
};
Tc Ytbi[]="HTTP.StringServlet.NEW()";
Tcpos ZcTbl72151[]={
{267,5},
{1,13},
{2,13},
};
Tc YEI9[]="HTTP.StringServlet.addPath__p1/1()";
Tcpos ZcTbl76262[]={
{164,11},
{1,7},
{2,16},
{4,7},
};
Tc YAxR[]="HTTP.StringServlet.handle__p1/1()";
Tcpos ZcTbl31780[]={
{174,11},
{1,7},
{2,9},
{3,11},
{4,13},
{5,15},
{7,13},
{8,22},
{2,9},
{13,14},
};
Tc YPt0[]="HTTP.StringServlet.serve/1()";
Tcpos ZcTbl76846[]={
{278,11},
{1,29},
{2,14},
};
Tc Y8yX[]="HTTP.StringServlet.setBody()";
Tcpos ZcTbl96431[]={
{273,11},
{1,13},
};
Tc YHiL[]="HTTP.isWhite()";
Tcpos ZcTbl74200[]={
{863,21},
};
Tc YmMC[]="HttpTest.test()";
Tcpos ZcTbl183[]={
{12,5},
{1,5},
};
Tc YYCt[]="HttpTest.test1()";
Tcpos ZcTbl77816[]={
{20,26},
{1,22},
{2,5},
{4,27},
{5,5},
{6,5},
{7,5},
{8,5},
{10,8},
{11,5},
{12,5},
{13,5},
{15,20},
{16,29},
{17,5},
{18,5},
{23,31},
{24,5},
{25,5},
{27,5},
{29,5},
};
Tc YZNT[]="HttpTest.test1().varz()";
Tcpos ZcTbl69626[]={
{41,14},
};
Tc Yfv3[]="INT.toQuotedString()";
Tcpos ZcTbl4706[]={
{99,5},
{1,14},
{4,25},
{5,22},
{6,23},
{7,5},
{8,7},
{9,9},
{10,21},
{12,17},
{13,7},
{14,9},
{15,7},
{7,5},
{17,5},
{18,7},
{20,25},
};
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
};
Tc YIxT[]="IO.File.Finish()";
Tcpos ZcTbl49822[]={
{601,11},
{1,7},
{5,14},
};
Tc YEgn[]="IO.File.close()";
Tcpos ZcTbl15755[]={
{582,11},
{1,20},
{2,7},
{6,4},
{9,4},
{12,15},
{15,14},
};
Tc Yxlj[]="IO.File.print__p1/15()";
Tcpos ZcTbl82618[]={
{230,11},
{1,15},
};
Tc YJ7z[]="IO.File.print__p1/8()";
Tcpos ZcTbl66188[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc Yj_J[]="IO.File.write/8()";
Tcpos ZcTbl94823[]={
{483,11},
{3,9},
{4,11},
{6,4},
{31,14},
};
Tc YGQL[]="IO.File.write__p1/9()";
Tcpos ZcTbl59819[]={
{129,11},
{1,15},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc Ylob[]="IO.StringWriter.byteSize()";
Tcpos ZcTbl95336[]={
{1411,11},
{1,15},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc YCbR[]="IO.StringWriter.write/8()";
Tcpos ZcTbl89987[]={
{1359,11},
{1,37},
{3,9},
{4,14},
{5,11},
{6,17},
{8,11},
{10,13},
{12,11},
{13,17},
{24,14},
};
Tc Y1Ue[]="IO.StringWriter.writeChar__p1/1()";
Tcpos ZcTbl49285[]={
{175,11},
{1,7},
{2,9},
{4,15},
};
Tc YzQB[]="IO.StringWriter.write__p1/9()";
Tcpos ZcTbl72007[]={
{129,11},
{1,15},
};
Tc Y0Nw[]="IO.concatPath()";
Tcpos ZcTbl68304[]={
{2077,5},
{1,7},
{2,22},
{4,20},
{6,5},
{7,20},
{9,25},
};
Tc YrlY[]="IO.findExe()";
Tcpos ZcTbl64970[]={
{1982,28},
{2,7},
{5,15},
{8,27},
{9,9},
{10,4},
{13,23},
{14,4},
{17,23},
{18,4},
{22,15},
{23,4},
{26,9},
{27,17},
{29,4},
{32,9},
{33,17},
{34,4},
{37,11},
{38,19},
{40,4},
{44,17},
{47,14},
};
Tc Y60W[]="IO.findExeInDirList()";
Tcpos ZcTbl86176[]={
{2038,5},
{1,22},
{2,7},
{3,16},
{0,5},
{6,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc Y85R[]="IO.initSockets()";
Tcpos ZcTbl37363[]={
{1054,18},
{1,4},
{16,12},
};
Tc Yuq9[]="IO.isExecutable()";
Tcpos ZcTbl73877[]={
{1729,4},
{8,14},
};
Tc Yofe[]="IO.isPathSep()";
Tcpos ZcTbl79136[]={
{2475,14},
};
Tc YaL5[]="IO.nextPartIndex()";
Tcpos ZcTbl36277[]={
{2481,5},
{1,7},
{2,18},
{0,5},
{5,13},
};
Tc YSYC[]="IO.pastHeadIndex()";
Tcpos ZcTbl11017[]={
{2456,4},
{3,7},
{4,11},
{6,4},
{10,5},
{11,7},
{10,5},
{13,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc Y4pE[]="IO.readFile()";
Tcpos ZcTbl7451[]={
{1106,18},
{2,4},
{9,4},
{10,4},
{16,4},
{17,4},
{22,4},
{23,4},
{26,4},
{34,5},
{35,4},
{43,7},
{44,4},
{54,12},
};
Tc YlPR[]="IO.resolve()";
Tcpos ZcTbl45331[]={
{2248,4},
{3,12},
{4,4},
{7,23},
{10,39},
{13,33},
{15,13},
{16,5},
{20,14},
{21,14},
{24,14},
{27,5},
{28,7},
{29,4},
{37,11},
{38,4},
{42,9},
{43,18},
{48,9},
{49,16},
{54,11},
{55,9},
{56,11},
{57,20},
{59,20},
{61,16},
{64,17},
{65,9},
{67,18},
{68,13},
{70,9},
{72,18},
{75,18},
{28,7},
{79,7},
{85,9},
{86,7},
{87,16},
{88,16},
{90,16},
{91,16},
{27,5},
{97,5},
{98,7},
{107,16},
{108,14},
{110,11},
{111,9},
{112,13},
{111,9},
{114,9},
{115,18},
{122,5},
{123,15},
{124,7},
{125,16},
{124,7},
{129,4},
{133,12},
};
Tc YU58[]="IO.tailIndex()";
Tcpos ZcTbl62213[]={
{2391,19},
{1,4},
{4,19},
{5,5},
{6,9},
{8,4},
{11,5},
{12,14},
{14,14},
};
Tc Y1GP[]="IO.tailSepIndex()";
Tcpos ZcTbl76601[]={
{2436,19},
{1,5},
{2,14},
{4,13},
{5,5},
{6,9},
{8,7},
{9,9},
{8,7},
{12,12},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1168,4},
{13,12},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{11,3},
{3,3},
{6,3},
{9,3},
{11,10},
};
Tc YV0a[]="PIPE.Pipe__t1.NEW()";
Tcpos ZcTbl64622[]={
{41,5},
{1,17},
{2,13},
{3,17},
{4,18},
{5,19},
{6,15},
};
Tc Ysl1[]="PIPE.Pipe__t1.write()";
Tcpos ZcTbl82363[]={
{126,11},
{2,7},
{3,9},
{4,11},
{5,13},
{6,20},
{8,11},
{9,13},
{12,11},
{3,9},
{15,7},
{18,7},
{19,14},
};
Tc YWQF[]="PIPE.Pipe__t2.NEW()";
Tcpos ZcTbl15223[]={
{41,5},
{1,17},
{2,13},
{3,17},
{4,18},
{5,19},
{6,15},
};
Tc YWcE[]="PIPE.Pipe__t2.close()";
Tcpos ZcTbl80243[]={
{79,11},
{2,7},
{3,17},
{5,7},
{9,7},
{10,7},
};
Tc Y5qq[]="PIPE.Pipe__t2.read()";
Tcpos ZcTbl32393[]={
{152,11},
{2,7},
{3,9},
{4,11},
{5,16},
{6,33},
{7,13},
{10,13},
{11,20},
{13,11},
{14,16},
{17,11},
{3,9},
{20,7},
{22,14},
};
Tc Y1CV[]="PIPE.Pipe__t2.read/1()";
Tcpos ZcTbl4645[]={
{181,11},
{2,15},
};
Tc YxUI[]="PIPE.Pipe__t2.write()";
Tcpos ZcTbl63164[]={
{126,11},
{2,7},
{3,9},
{4,11},
{5,13},
{6,20},
{8,11},
{9,13},
{12,11},
{3,9},
{15,7},
{18,7},
{19,14},
};
Tc Yuy1[]="PipeTest.getFunc()";
Tcpos ZcTbl40705[]={
{82,16},
{0,12},
{1,12},
};
Tc Y53b[]="PipeTest.print()";
Tcpos ZcTbl66606[]={
{25,5},
{2,20},
{3,7},
{6,7},
{0,5},
};
Tc YUHL[]="PipeTest.test()";
Tcpos ZcTbl84789[]={
{15,5},
{1,5},
{2,5},
{3,5},
};
Tc Yjch[]="PipeTest.test1()";
Tcpos ZcTbl64846[]={
{38,7},
{1,16},
{2,5},
{3,5},
{4,7},
{3,5},
{6,5},
{7,5},
};
Tc YeMj[]="PipeTest.test2()";
Tcpos ZcTbl75047[]={
{50,28},
{1,25},
{2,5},
{3,19},
{4,5},
{5,9},
{7,5},
{9,22},
{10,5},
{12,44},
{17,5},
};
Tc Yt1E[]="PipeTest.test2().Nameless9()";
Tcpos ZcTbl73727[]={
{64,11},
{1,18},
};
Tc Y9km[]="PipeTest.test3()";
Tcpos ZcTbl85248[]={
{71,16},
{2,47},
{3,5},
{5,26},
{6,8},
{7,5},
};
Tc YuIh[]="STRING.replaceAll()";
Tcpos ZcTbl12035[]={
{669,5},
{1,14},
{3,18},
{4,5},
{6,27},
{7,7},
{8,9},
{9,11},
{11,9},
{12,18},
{13,11},
{7,7},
{15,7},
{16,16},
{18,12},
};
Tc Yiyv[]="STRING.reverse()";
Tcpos ZcTbl42834[]={
{635,5},
{1,14},
{3,25},
{4,5},
{6,7},
{4,5},
{8,14},
};
Tc YQ54[]="SYS.getEnv()";
Tcpos ZcTbl42323[]={
{56,4},
{4,12},
};
Tc YOtj[]="THREAD.AutoLock.Finish()";
Tcpos ZcTbl79248[]={
{438,11},
{1,7},
{2,17},
{3,9},
{5,14},
};
Tc Yo8T[]="THREAD.AutoLock.NEW()";
Tcpos ZcTbl38761[]={
{431,5},
{1,7},
{2,13},
};
Tc YCe5[]="THREAD.Cond.NEW()";
Tcpos ZcTbl68823[]={
{455,5},
{1,4},
};
Tc YL2R[]="THREAD.Cond.wait()";
Tcpos ZcTbl73734[]={
{475,11},
{1,4},
};
Tc YGy0[]="THREAD.Cond.wakeup()";
Tcpos ZcTbl1082[]={
{463,11},
{1,4},
};
Tc YkGR[]="THREAD.EvalThread__t1.Finish__p1/1()";
Tcpos ZcTbl28548[]={
{193,11},
{1,4},
{4,14},
};
Tc YCPV[]="THREAD.EvalThread__t1.NEW__p1/1()";
Tcpos ZcTbl93865[]={
{50,5},
};
Tc YDGea[]="THREAD.EvalThread__t1.body/1()";
Tcpos ZcTbl55066[]={
{309,9},
};
Tc YBws[]="THREAD.EvalThread__t1.eval()";
Tcpos ZcTbl70432[]={
{293,11},
{1,17},
{2,19},
{3,7},
{4,15},
};
Tc Y6_a[]="THREAD.EvalThread__t1.eval/1()";
Tcpos ZcTbl54660[]={
{321,40},
};
Tc YZ20[]="THREAD.EvalThread__t1.startBody__p1/1()";
Tcpos ZcTbl58143[]={
{64,11},
{2,4},
{9,9},
{10,4},
{9,9},
{17,4},
{44,4},
{53,4},
};
Tc Yrl2[]="THREAD.EvalThread__t1.start__p1/1()";
Tcpos ZcTbl46385[]={
{134,11},
{4,4},
{7,16},
{8,9},
{10,4},
{15,11},
{8,9},
{18,4},
{21,9},
{22,11},
{24,4},
{31,14},
};
Tc YOJ5[]="THREAD.Lock.Finish()";
Tcpos ZcTbl80111[]={
{407,11},
{1,4},
{4,14},
};
Tc YEgk[]="THREAD.Lock.NEW()";
Tcpos ZcTbl53428[]={
{363,5},
{1,4},
};
Tc YIVA[]="THREAD.Lock.begin()";
Tcpos ZcTbl7651[]={
{375,11},
{1,4},
};
Tc Yc45[]="THREAD.Lock.end()";
Tcpos ZcTbl17605[]={
{400,11},
{1,4},
};
Tc Yz4h[]="THREAD.Server.Finish__p2/2()";
Tcpos ZcTbl96282[]={
{193,11},
{1,4},
{4,14},
{0,11},
{1,4},
{4,14},
};
Tc YXjG[]="THREAD.Server.NEW__p2/2()";
Tcpos ZcTbl95407[]={
{50,5},
};
Tc YNNP[]="THREAD.Server.kill__p2/2()";
Tcpos ZcTbl4133[]={
{181,11},
{1,4},
{4,4},
{0,11},
{1,4},
{4,4},
};
Tc Ykoq[]="THREAD.Server.setProc__p1/1()";
Tcpos ZcTbl13167[]={
{262,11},
{1,13},
{0,11},
{1,13},
};
Tc Ys_j[]="THREAD.Server.startBody__p2/2()";
Tcpos ZcTbl39877[]={
{64,11},
{2,4},
{9,9},
{10,4},
{9,9},
{17,4},
{44,4},
{53,4},
{0,11},
{2,4},
{9,9},
{10,4},
{9,9},
{17,4},
{44,4},
{53,4},
};
Tc YEiU[]="THREAD.Server.start__p2/2()";
Tcpos ZcTbl22103[]={
{134,11},
{4,4},
{7,16},
{8,9},
{10,4},
{15,11},
{8,9},
{18,4},
{21,9},
{22,11},
{24,4},
{31,14},
{0,11},
{4,4},
{7,16},
{8,9},
{10,4},
{15,11},
{8,9},
{18,4},
{21,9},
{22,11},
{24,4},
{31,14},
};
Tc YT99[]="THREAD.Server.wait__p2/2()";
Tcpos ZcTbl21682[]={
{169,11},
{1,4},
{4,4},
{8,14},
{0,11},
{1,4},
{4,4},
{8,14},
};
Tc Y7wT[]="THREAD.Thread.Finish__p1/1()";
Tcpos ZcTbl84521[]={
{193,11},
{1,4},
{4,14},
};
Tc Y_81[]="THREAD.Thread.NEW/1()";
Tcpos ZcTbl70007[]={
{236,5},
{1,13},
};
Tc YVI4[]="THREAD.Thread.NEW/2()";
Tcpos ZcTbl80208[]={
{242,5},
{2,4},
};
Tc YKzP[]="THREAD.Thread.NEW__p1/1()";
Tcpos ZcTbl54226[]={
{50,5},
};
Tc Yq1b[]="THREAD.Thread.kill__p1/1()";
Tcpos ZcTbl8476[]={
{181,11},
{1,4},
{4,4},
};
Tc YFj1[]="THREAD.Thread.setProc()";
Tcpos ZcTbl70197[]={
{262,11},
{1,13},
};
Tc YPKA[]="THREAD.Thread.startBody__p1/1()";
Tcpos ZcTbl39472[]={
{64,11},
{2,4},
{9,9},
{10,4},
{9,9},
{17,4},
{44,4},
{53,4},
};
Tc Ydy6[]="THREAD.Thread.start__p1/1()";
Tcpos ZcTbl85586[]={
{134,11},
{4,4},
{7,16},
{8,9},
{10,4},
{15,11},
{8,9},
{18,4},
{21,9},
{22,11},
{24,4},
{31,14},
};
Tc YQ9S[]="THREAD.Thread.wait__p1/1()";
Tcpos ZcTbl77641[]={
{169,11},
{1,4},
{4,4},
{8,14},
};
Tc YcKY[]="THREAD.eval__t1()";
Tcpos ZcTbl55402[]={
{333,28},
{1,15},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc Y0oq[]="TIME.sleep()";
Tcpos ZcTbl91247[]={
{248,4},
};
Tc YLyP[]="ThreadTest.Server.body/1()";
Tcpos ZcTbl80762[]={
{80,11},
{1,18},
{2,37},
{3,7},
{4,14},
{5,9},
{6,9},
{3,7},
};
Tc YArQ[]="ThreadTest.simpleFunc()";
Tcpos ZcTbl50581[]={
{64,35},
{1,5},
{2,5},
{3,5},
};
Tc Y3P0[]="ThreadTest.test()";
Tcpos ZcTbl7155[]={
{16,5},
{1,5},
{2,5},
{3,5},
{4,5},
{5,5},
};
Tc YIA9[]="ThreadTest.test1()";
Tcpos ZcTbl65828[]={
{47,16},
{1,17},
{2,13},
{3,5},
{4,17},
{5,13},
{6,5},
{7,5},
{8,5},
{9,5},
{11,5},
};
Tc YN06[]="ThreadTest.test2()";
Tcpos ZcTbl76029[]={
{71,16},
{1,5},
{2,5},
{3,5},
};
Tc YSr4[]="ThreadTest.test3()";
Tcpos ZcTbl86230[]={
{92,5},
{1,16},
{2,16},
{3,12},
{4,5},
{5,5},
{6,5},
};
Tc YXS1[]="ThreadTest.test4()";
Tcpos ZcTbl96432[]={
{105,25},
{1,5},
{2,5},
{4,26},
{5,5},
{6,5},
};
Tc YCsD[]="ThreadTest.test4().Nameless4()";
Tcpos ZcTbl29674[]={
{109,39},
};
Tc Ys1o[]="ThreadTest.testAutoLock()";
Tcpos ZcTbl61661[]={
{117,20},
{2,22},
{3,7},
{3,7},
{5,5},
{7,22},
{8,7},
{8,7},
{10,5},
};
Tc YBNM[]="ThreadTest.threadOneFunc()";
Tcpos ZcTbl5369[]={
{29,35},
{1,5},
{2,5},
{3,5},
{4,5},
{5,5},
};
Tc YpOz[]="ThreadTest.threadTwoFunc()";
Tcpos ZcTbl11693[]={
{38,35},
{1,5},
{2,5},
{3,5},
{4,5},
{5,5},
};
Tc YX0q[]="Ticker.Init/1()";
Tcpos ZcTbl56121[]={
{16,14},
};
Tc YW1p[]="Ticker.NEW()";
Tcpos ZcTbl64663[]={
{20,3},
{1,18},
{2,18},
{3,5},
{4,7},
{3,5},
};
Tc YikS[]="Ticker.Reader.NEW()";
Tcpos ZcTbl7600[]={
{65,5},
{1,14},
{2,15},
};
Tc YzGP[]="Ticker.Reader.done()";
Tcpos ZcTbl44092[]={
{81,11},
{1,35},
};
Tc YbGu[]="Ticker.Reader.waitForTick()";
Tcpos ZcTbl69613[]={
{71,11},
{1,7},
{3,37},
{4,9},
{1,7},
};
Tc Yu1q[]="Ticker.getTickReader()";
Tcpos ZcTbl51191[]={
{29,9},
{1,5},
{2,5},
{3,7},
{5,16},
{6,5},
{7,12},
};
Tc YZcM[]="Ticker.produceTicks()";
Tcpos ZcTbl67709[]={
{40,9},
{1,5},
{3,7},
{4,21},
{5,9},
{6,11},
{8,18},
{5,9},
{12,9},
{15,9},
{3,7},
{17,7},
{1,5},
};
Tc Ym1t[]="Z.Pos.ToString()";
Tcpos ZcTbl18187[]={
{83,11},
{1,27},
{2,7},
{3,9},
{5,9},
{7,7},
{8,7},
{9,7},
{10,7},
{11,16},
};
Tcode ZcodeTable[]={
{183,YSp9,YmMC,ZcTbl183},
{412,Y_4X,YxLq,ZcTbl412},
{1082,Ynl5,YGy0,ZcTbl1082},
{1872,YkTo,YNFk,ZcTbl1872},
{3273,Yzok,Y_VO,ZcTbl3273},
{4133,Ynl5,YNNP,ZcTbl4133},
{4645,YSsV,Y1CV,ZcTbl4645},
{4706,YAdQ,Yfv3,ZcTbl4706},
{4839,Yzok,YGq4,ZcTbl4839},
{4984,Y_4X,YJyB,ZcTbl4984},
{5270,YYSG,Y9QD,ZcTbl5270},
{5369,Y9pu,YBNM,ZcTbl5369},
{6308,Y_4X,YR5_,ZcTbl6308},
{7051,Y_4X,Y8Ap,ZcTbl7051},
{7155,Y9pu,Y3P0,ZcTbl7155},
{7238,Y1XW,Y3Ya,ZcTbl7238},
{7451,YkTo,Y4pE,ZcTbl7451},
{7452,YkTo,Ys1a,ZcTbl7452},
{7600,Y94F,YikS,ZcTbl7600},
{7651,Ynl5,YIVA,ZcTbl7651},
{8476,Ynl5,Yq1b,ZcTbl8476},
{10613,Y_4X,YCbo,ZcTbl10613},
{11017,YkTo,YSYC,ZcTbl11017},
{11217,Y_4X,YoZS,ZcTbl11217},
{11603,Y_VG,YRZz,ZcTbl11603},
{11693,Y9pu,YpOz,ZcTbl11693},
{12035,YlLp,YuIh,ZcTbl12035},
{12896,Y_4X,Y0Td,ZcTbl12896},
{13167,Ynl5,Ykoq,ZcTbl13167},
{14099,Y_VG,Y4b2,ZcTbl14099},
{14715,Y_4X,Y4SL,ZcTbl14715},
{14874,Y_VG,Yxl5,ZcTbl14874},
{15223,YSsV,YWQF,ZcTbl15223},
{15669,Y_4X,YMB8,ZcTbl15669},
{15718,Y_4X,YEFs,ZcTbl15718},
{15755,YkTo,YEgn,ZcTbl15755},
{16350,Yzok,Ygzb,ZcTbl16350},
{16490,Y64e,Y_2n,ZcTbl16490},
{16768,Y_4X,YOoP,ZcTbl16768},
{17179,Y_4X,Yk5m,ZcTbl17179},
{17252,Y_4X,Y39r,ZcTbl17252},
{17605,Ynl5,Yc45,ZcTbl17605},
{18187,Ypx4,Ym1t,ZcTbl18187},
{18292,Y_4X,Yh7q,ZcTbl18292},
{18934,Y_4X,Y0TG,ZcTbl18934},
{21418,Y_4X,YtpQ,ZcTbl21418},
{21682,Ynl5,YT99,ZcTbl21682},
{22103,Ynl5,YEiU,ZcTbl22103},
{22398,YXwB,YF2d,ZcTbl22398},
{24916,Y_4X,Y9iJ,ZcTbl24916},
{25958,Y_4X,Y4vu,ZcTbl25958},
{26760,YkTo,YYk7,ZcTbl26760},
{26854,Y_4X,YN54,ZcTbl26854},
{27618,Y_4X,Y8mE,ZcTbl27618},
{28548,Ynl5,YkGR,ZcTbl28548},
{29560,Yzok,YzK9,ZcTbl29560},
{29585,Y_4X,YAVe,ZcTbl29585},
{29674,Y9pu,YCsD,ZcTbl29674},
{30206,Y1XW,Y8BT,ZcTbl30206},
{30564,Y_VG,YZ7U,ZcTbl30564},
{31729,Y_4X,Y0DD,ZcTbl31729},
{31780,Y_VG,YAxR,ZcTbl31780},
{31890,Y_4X,YwZj,ZcTbl31890},
{32086,Y_4X,Y1As,ZcTbl32086},
{32191,Y_4X,Yc7B,ZcTbl32191},
{32393,YSsV,Y5qq,ZcTbl32393},
{32618,Yzok,YBSz,ZcTbl32618},
{32864,Y_VG,YGL9,ZcTbl32864},
{33805,Y_4X,YZd2,ZcTbl33805},
{34822,Y_VG,YfxG,ZcTbl34822},
{35088,Y_4X,YcIS,ZcTbl35088},
{35537,Y_VG,YBlz,ZcTbl35537},
{36159,Y_4X,Y_4w,ZcTbl36159},
{36277,YkTo,YaL5,ZcTbl36277},
{36491,Y_4X,YYT9,ZcTbl36491},
{37281,Y_VG,Y7n9,ZcTbl37281},
{37363,YkTo,Y85R,ZcTbl37363},
{38545,Y_VG,YXHL,ZcTbl38545},
{38761,Ynl5,Yo8T,ZcTbl38761},
{38911,Yzok,YM2k,ZcTbl38911},
{39472,Ynl5,YPKA,ZcTbl39472},
{39877,Ynl5,Ys_j,ZcTbl39877},
{40705,Yzip,Yuy1,ZcTbl40705},
{42323,YaR1,YQ54,ZcTbl42323},
{42834,YlLp,Yiyv,ZcTbl42834},
{42983,Y_4X,Y9aV,ZcTbl42983},
{43000,Yzok,YEFE,ZcTbl43000},
{43124,Y_4X,Ygil,ZcTbl43124},
{44092,Y94F,YzGP,ZcTbl44092},
{44130,Y_4X,YG80,ZcTbl44130},
{44333,Y_4X,YYc1,ZcTbl44333},
{45067,Y_4X,YwJf,ZcTbl45067},
{45289,Y_4X,Y7gV,ZcTbl45289},
{45331,YkTo,YlPR,ZcTbl45331},
{46171,Y_4X,Y9VX,ZcTbl46171},
{46385,Ynl5,Yrl2,ZcTbl46385},
{46640,Y_VG,YFGh,ZcTbl46640},
{46761,YkTo,YN2v,ZcTbl46761},
{48299,Y_4X,Y9Cv,ZcTbl48299},
{49183,Y_4X,YgcH,ZcTbl49183},
{49285,YkTo,Y1Ue,ZcTbl49285},
{49822,YkTo,YIxT,ZcTbl49822},
{50581,Y9pu,YArQ,ZcTbl50581},
{50841,Ysv0,YLwM,ZcTbl50841},
{51191,Y94F,Yu1q,ZcTbl51191},
{51434,Y_VG,YCzi,ZcTbl51434},
{51535,Y_4X,Y2Qj,ZcTbl51535},
{52386,Y_4X,YgcM,ZcTbl52386},
{52608,Y_4X,YqK0,ZcTbl52608},
{52648,Yzok,YF9k,ZcTbl52648},
{52701,Y_4X,Y0hW,ZcTbl52701},
{52728,Y_4X,Yoiq,ZcTbl52728},
{53063,Y_VG,Y5GQ,ZcTbl53063},
{53325,Y_4X,YlJi,ZcTbl53325},
{53377,Y_4X,Yp81,ZcTbl53377},
{53428,Ynl5,YEgk,ZcTbl53428},
{53863,Y_VG,Ykap,ZcTbl53863},
{54226,Ynl5,YKzP,ZcTbl54226},
{54331,Y_4X,YLzZ,ZcTbl54331},
{54660,Ynl5,Y6_a,ZcTbl54660},
{55066,Ynl5,YDGea,ZcTbl55066},
{55268,Y_4X,YB9c,ZcTbl55268},
{55402,Ynl5,YcKY,ZcTbl55402},
{56121,Y94F,YX0q,ZcTbl56121},
{56372,Y_4X,Y4u_,ZcTbl56372},
{56381,Y_4X,Y99g,ZcTbl56381},
{56573,Y_4X,YO_6,ZcTbl56573},
{57803,Y64e,Y7Vi,ZcTbl57803},
{58143,Ynl5,YZ20,ZcTbl58143},
{58522,Y64e,YBpN,ZcTbl58522},
{59819,YkTo,YGQL,ZcTbl59819},
{60593,Y_4X,Y5LR,ZcTbl60593},
{61661,Y9pu,Ys1o,ZcTbl61661},
{61772,Y_4X,Yq0C,ZcTbl61772},
{62213,YkTo,YU58,ZcTbl62213},
{62809,Y_4X,Ylj3,ZcTbl62809},
{63164,YSsV,YxUI,ZcTbl63164},
{63578,Y_4X,Yuz_,ZcTbl63578},
{64478,Yzok,YRbs,ZcTbl64478},
{64531,YkTo,YrJP,ZcTbl64531},
{64622,YSsV,YV0a,ZcTbl64622},
{64663,Y94F,YW1p,ZcTbl64663},
{64846,Yzip,Yjch,ZcTbl64846},
{64970,YkTo,YrlY,ZcTbl64970},
{65828,Y9pu,YIA9,ZcTbl65828},
{66036,Y_4X,YQJA,ZcTbl66036},
{66188,YkTo,YJ7z,ZcTbl66188},
{66501,Yzok,YPPv,ZcTbl66501},
{66606,Yzip,Y53b,ZcTbl66606},
{67709,Y94F,YZcM,ZcTbl67709},
{67925,Y_4X,YlfT,ZcTbl67925},
{68304,YkTo,Y0Nw,ZcTbl68304},
{68823,Ynl5,YCe5,ZcTbl68823},
{69435,Y_4X,YNLE,ZcTbl69435},
{69613,Y94F,YbGu,ZcTbl69613},
{69626,YSp9,YZNT,ZcTbl69626},
{70007,Ynl5,Y_81,ZcTbl70007},
{70197,Ynl5,YFj1,ZcTbl70197},
{70432,Ynl5,YBws,ZcTbl70432},
{71057,Y1XW,YUXK,ZcTbl71057},
{72007,YkTo,YzQB,ZcTbl72007},
{72151,Y_VG,Ytbi,ZcTbl72151},
{73471,Y_4X,Y_Qs,ZcTbl73471},
{73580,Y_4X,YF6S,ZcTbl73580},
{73727,Yzip,Yt1E,ZcTbl73727},
{73734,Ynl5,YL2R,ZcTbl73734},
{73877,YkTo,Yuq9,ZcTbl73877},
{74200,Y_VG,YHiL,ZcTbl74200},
{75047,Yzip,YeMj,ZcTbl75047},
{75697,Yzok,YgDO,ZcTbl75697},
{76029,Y9pu,YN06,ZcTbl76029},
{76262,Y_VG,YEI9,ZcTbl76262},
{76601,YkTo,Y1GP,ZcTbl76601},
{76644,Yzok,YImf,ZcTbl76644},
{76846,Y_VG,YPt0,ZcTbl76846},
{77164,Yzok,YTJ0b,ZcTbl77164},
{77641,Ynl5,YQ9S,ZcTbl77641},
{77816,YSp9,YYCt,ZcTbl77816},
{78082,Y_4X,YbzA,ZcTbl78082},
{79110,Y_4X,YkLW,ZcTbl79110},
{79136,YkTo,Yofe,ZcTbl79136},
{79248,Ynl5,YOtj,ZcTbl79248},
{79874,Y_4X,YFnU,ZcTbl79874},
{79935,Y_4X,YVJp,ZcTbl79935},
{80111,Ynl5,YOJ5,ZcTbl80111},
{80208,Ynl5,YVI4,ZcTbl80208},
{80243,YSsV,YWcE,ZcTbl80243},
{80636,Yzok,YAAq,ZcTbl80636},
{80644,Y_4X,YobA,ZcTbl80644},
{80762,Y9pu,YLyP,ZcTbl80762},
{81798,Yzok,YMnk,ZcTbl81798},
{82363,YSsV,Ysl1,ZcTbl82363},
{82533,Yzok,Yh2v,ZcTbl82533},
{82534,Yzok,Yh2v,ZcTbl82534},
{82618,YkTo,Yxlj,ZcTbl82618},
{83031,Y_4X,YpMw,ZcTbl83031},
{83985,Y_4X,Y6co,ZcTbl83985},
{84506,Y_VG,Ys1T,ZcTbl84506},
{84521,Ynl5,Y7wT,ZcTbl84521},
{84668,Y_VG,YLdV,ZcTbl84668},
{84789,Yzip,YUHL,ZcTbl84789},
{84870,YkTo,Y_pS,ZcTbl84870},
{85000,Y_4X,Ycb9,ZcTbl85000},
{85248,Yzip,Y9km,ZcTbl85248},
{85295,Yzok,Yza4,ZcTbl85295},
{85586,Ynl5,Ydy6,ZcTbl85586},
{86061,Y_4X,Y8CZ,ZcTbl86061},
{86176,YkTo,Y60W,ZcTbl86176},
{86206,Yzok,YZNA,ZcTbl86206},
{86230,Y9pu,YSr4,ZcTbl86230},
{86699,Y_4X,Ym8y,ZcTbl86699},
{86818,Y_4X,YlgI,ZcTbl86818},
{87235,Y_4X,YR5m,ZcTbl87235},
{88986,Y_VG,YSio,ZcTbl88986},
{89581,Y_4X,YAwk,ZcTbl89581},
{89685,Y_4X,Y59h,ZcTbl89685},
{89987,YkTo,YCbR,ZcTbl89987},
{90571,Y_4X,Ys9t,ZcTbl90571},
{91247,Ysv0,Y0oq,ZcTbl91247},
{91620,Y_VG,YGWN,ZcTbl91620},
{91844,Y64e,YITr,ZcTbl91844},
{92163,Y_4X,YTjU,ZcTbl92163},
{93453,Y_4X,YeMI,ZcTbl93453},
{93865,Ynl5,YCPV,ZcTbl93865},
{94336,Y_VG,Yd9V,ZcTbl94336},
{94689,Y_4X,Ywpu,ZcTbl94689},
{94823,YkTo,Yj_J,ZcTbl94823},
{95336,YkTo,Ylob,ZcTbl95336},
{95407,Ynl5,YXjG,ZcTbl95407},
{96107,Y_4X,YMF2,ZcTbl96107},
{96282,Ynl5,Yz4h,ZcTbl96282},
{96330,Y_VG,Y32H,ZcTbl96330},
{96431,Y_VG,Y8yX,ZcTbl96431},
{96432,Y9pu,YXS1,ZcTbl96432},
{96589,Y_4X,Y9D_,ZcTbl96589},
{97019,Y_4X,YgQK,ZcTbl97019},
{97135,Y_4X,Y3yN,ZcTbl97135},
{97985,Y_4X,YVQQ,ZcTbl97985},
{98650,Y_VG,YXL6,ZcTbl98650},
{99366,Y_VG,Y7FCa,ZcTbl99366},
{99367,Y_VG,Y7FCa,ZcTbl99367},
{99886,Y_4X,Y0Jk,ZcTbl99886},
};

#ifdef SIGSEGV
void Zdeadly(int nr) {
 ZthrowDeadly(nr);
}
#endif

void ZthreadGC() {
}
Ti ZstringSizePtr(Tc *s, Tc **dp) {
 Tc *p;
 Ti len;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {  /* be quick for short string */
  *dp = p + 1;
  return *p;
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 *dp = p + 1;
 return (len << 7) + *p;
}

void ZgcRun() {
}

void ZthrowPos(Ti pos, Tc *text) {
 YScq(pos, text);
}

void ZthrowCstringNil(char *text) {
 YvdV(NULL, Zstr(text));
}

void ZthrowThisNil() {
 YvdV(NULL, Zstr("THIS is NIL"));
}

void ZthrowCstringInit(char *text) {
 Y3w6(Zstr(text));
}

void ZthrowOutOfMemory(Ti size) {
 Y1KV(size);
}

void ZthrowCstringOutOfRange(Ti i, char *text) {
 Y6NT(i, Zstr(text));
}

void ZthrowCstringBadValue(char *msg) {
 Yaez(Zstr(msg));
}

void ZthrowDeadly(int nr) {
 YE93((Ti)nr);
}

void ZthrowThread(Tc *text) {
 YNbE(NULL, text);
}

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
}

int ZTypeInRange(int type, int low, int high) {
 return type >= low && type <= high;
}

Tc *ZintAsString(Ti n) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  Tc *p = Za(ZOH_OFF + 3);
  p[ZOH_OFF] = 1;
  p[ZOH_OFF + 1] = n;
  p[ZOH_OFF + 2] = 0;
  return p;
 }
 if (n <= 0x7ff) {
  Tc *p = Za(ZOH_OFF + 4);
  p[ZOH_OFF] = 2;
  p[ZOH_OFF + 1] = 0xc0 + ((unsigned)n >> 6);
  p[ZOH_OFF + 2] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 3] = 0;
  return p;
 }
 if (n <= 0xffff) {
  Tc *p = Za(ZOH_OFF + 5);
  p[ZOH_OFF] = 3;
  p[ZOH_OFF + 1] = 0xe0 + ((unsigned)n >> 12);
  p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  p[ZOH_OFF + 3] = 0x80 + (n & 0x3f);
  p[ZOH_OFF + 4] = 0;
  return p;
 }
 Tc *p = Za(ZOH_OFF + 6);
 p[ZOH_OFF] = 4;
 p[ZOH_OFF + 1] = 0xf0 + ((unsigned)n >> 18);
 p[ZOH_OFF + 2] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 p[ZOH_OFF + 3] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 p[ZOH_OFF + 4] = 0x80 + (n & 0xef);
 p[ZOH_OFF + 5] = 0;
 return p;
}

int Zchar2stringBuf(Ti n, Tc *buf) {
 if (n < 0 || n > 0x10fffff)
  ZthrowCstringBadValue("asString(): Character must be in range 0 - 0x10ffff");
 if (n <= 0x7f) {
  buf[0] = n;
  buf[1] = 0;
  return 1;
 }
 if (n <= 0x7ff) {
  buf[0] = 0xc0 + ((unsigned)n >> 6);
  buf[1] = 0x80 + (n & 0x3f);
  buf[2] = 0;
  return 2;
 }
 if (n <= 0xffff) {
  buf[0] = 0xe0 + ((unsigned)n >> 12);
  buf[1] = 0x80 + (((unsigned)n >> 6) & 0x3f);
  buf[2] = 0x80 + (n & 0x3f);
  buf[3] = 0;
  return 3;
 }
 buf[0] = 0xf0 + ((unsigned)n >> 18);
 buf[1] = 0x80 + (((unsigned)n >> 12) & 0x3f);
 buf[2] = 0x80 + (((unsigned)n >> 6) & 0x3f);
 buf[3] = 0x80 + (n & 0xef);
 buf[4] = 0;
 return 4;
}

Tc *ZbyteStringCheckUtf8(Tc *p) {
 /* TODO */
 return p;
}

/* concat string */
Tc *ZcS(Tc *l, Tc *ri) {
 Tc *l_p;
 Ti l_len;
 Tc *r_p;
 Ti r_len;
 Ti len;
 Tc *pp;
 Tc *r;
 if (l == NULL) {l_len = 3; l_p = (Tc*)"NIL";}
 else l_len = ZstringSizePtr(l, &l_p);
 if (ri == NULL) {r_len = 3; r_p = (Tc*)"NIL";}
 else r_len = ZstringSizePtr(ri, &r_p);
 len = l_len + r_len;
 r = ZnewStringInit(len, &pp);
 memmove(pp, l_p, l_len);
 memmove(pp + l_len, r_p, r_len);
 return r;
}

/* concat string */
Tc *ZcS3(Tc *s1, Tc *s2, Tc *s3) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 len = len1 + len2 + len3;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 return r;
}

/* concat string */
Tc *ZcS5(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5) {
 Tc *p1;
 Ti len1;
 Tc *p2;
 Ti len2;
 Tc *p3;
 Ti len3;
 Tc *p4;
 Ti len4;
 Tc *p5;
 Ti len5;
 Ti len;
 Tc *pp;
 Tc *r;
 if (s1 == NULL) {len1 = 3; p1 = (Tc*)"NIL";}
 else len1 = ZstringSizePtr(s1, &p1);
 if (s2 == NULL) {len2 = 3; p2 = (Tc*)"NIL";}
 else len2 = ZstringSizePtr(s2, &p2);
 if (s3 == NULL) {len3 = 3; p3 = (Tc*)"NIL";}
 else len3 = ZstringSizePtr(s3, &p3);
 if (s4 == NULL) {len4 = 3; p4 = (Tc*)"NIL";}
 else len4 = ZstringSizePtr(s4, &p4);
 if (s5 == (Tc*)1) len5 = 0;
 else if (s5 == NULL) {len5 = 3; p5 = (Tc*)"NIL";}
 else len5 = ZstringSizePtr(s5, &p5);
 len = len1 + len2 + len3 + len4 + len5;
 r = ZnewStringInit(len, &pp);
 memmove(pp, p1, len1);
 memmove(pp + len1, p2, len2);
 memmove(pp + len1 + len2, p3, len3);
 memmove(pp + len1 + len2 + len3, p4, len4);
 if (s5 != (Tc*)1) memmove(pp + len1 + len2 + len3 + len4, p5, len5);
 return r;
}

/* concat string */
Tc *ZcS8(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8) {
 Tc *p[8];
 Ti len[8];
 Ti totlen = 0;
 Tc *pp;
 Tc *r;
 int i;
 if (s1 == NULL) {len[0] = 3; p[0] = (Tc*)"NIL";}
 else len[0] = ZstringSizePtr(s1, &p[0]);
 if (s2 == NULL) {len[1] = 3; p[1] = (Tc*)"NIL";}
 else len[1] = ZstringSizePtr(s2, &p[1]);
 if (s3 == NULL) {len[2] = 3; p[2] = (Tc*)"NIL";}
 else len[2] = ZstringSizePtr(s3, &p[2]);
 if (s4 == NULL) {len[3] = 3; p[3] = (Tc*)"NIL";}
 else len[3] = ZstringSizePtr(s4, &p[3]);
 if (s5 == NULL) {len[4] = 3; p[4] = (Tc*)"NIL";}
 else len[4] = ZstringSizePtr(s5, &p[4]);
 if (s6 == NULL) {len[5] = 3; p[5] = (Tc*)"NIL";}
 else len[5] = ZstringSizePtr(s6, &p[5]);
 if (s7 == (Tc*)1) len[6] = 0;
 else if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == (Tc*)1) len[7] = 0;
 else if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 for (i = 0; i < 8; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 8; ++i) {
  memmove(pp + totlen, p[i], len[i]);
  totlen += len[i];
 }
 return r;
}

/* concat string */
Tc *ZcS12(Tc *s1, Tc *s2, Tc *s3, Tc *s4, Tc *s5, Tc *s6, Tc *s7, Tc *s8, Tc *s9, Tc *s10, Tc *s11, Tc *s12) {
 Tc *p[12];
 Ti len[12];
 Ti totlen = 0;
 Tc *pp;
 Tc *r;
 int i;
 if (s1 == NULL) {len[0] = 3; p[0] = (Tc*)"NIL";}
 else len[0] = ZstringSizePtr(s1, &p[0]);
 if (s2 == NULL) {len[1] = 3; p[1] = (Tc*)"NIL";}
 else len[1] = ZstringSizePtr(s2, &p[1]);
 if (s3 == NULL) {len[2] = 3; p[2] = (Tc*)"NIL";}
 else len[2] = ZstringSizePtr(s3, &p[2]);
 if (s4 == NULL) {len[3] = 3; p[3] = (Tc*)"NIL";}
 else len[3] = ZstringSizePtr(s4, &p[3]);
 if (s5 == NULL) {len[4] = 3; p[4] = (Tc*)"NIL";}
 else len[4] = ZstringSizePtr(s5, &p[4]);
 if (s6 == NULL) {len[5] = 3; p[5] = (Tc*)"NIL";}
 else len[5] = ZstringSizePtr(s6, &p[5]);
 if (s7 == NULL) {len[6] = 3; p[6] = (Tc*)"NIL";}
 else len[6] = ZstringSizePtr(s7, &p[6]);
 if (s8 == NULL) {len[7] = 3; p[7] = (Tc*)"NIL";}
 else len[7] = ZstringSizePtr(s8, &p[7]);
 if (s9 == NULL) {len[8] = 3; p[8] = (Tc*)"NIL";}
 else len[8] = ZstringSizePtr(s9, &p[8]);
 if (s10 == (Tc*)1) len[9] = 0;
 else if (s10 == NULL) {len[9] = 3; p[9] = (Tc*)"NIL";}
 else len[9] = ZstringSizePtr(s10, &p[9]);
 if (s11 == (Tc*)1) len[10] = 0;
 else if (s11 == NULL) {len[10] = 3; p[10] = (Tc*)"NIL";}
 else len[10] = ZstringSizePtr(s11, &p[10]);
 if (s12 == (Tc*)1) len[11] = 0;
 else if (s12 == NULL) {len[11] = 3; p[11] = (Tc*)"NIL";}
 else len[11] = ZstringSizePtr(s12, &p[11]);
 for (i = 0; i < 12; ++i) totlen += len[i];
 r = ZnewStringInit(totlen, &pp);
 totlen = 0;
 for (i = 0; i < 12; ++i) {
  memmove(pp + totlen, p[i], len[i]);
  totlen += len[i];
 }
 return r;
}

Tr Zao(void *ptr, Tc **table, Ti type) {
 Tr tr;
 tr.ptr = ptr;
 tr.table = table;
 tr.type = type;
 return tr;
}

/* fill not-allocated object reference */
Tr *Znao(Tr *p, void *ptr, Tc **table, Ti type) {
 p->ptr = ptr;
 p->table = table;
 p->type = type;
 return p;
}

Tr ZconvertZioref(Tr orig, Tc ***table, int type, int maxType, Ti pos) {
 Tr p;
 if (orig.ptr == NULL) p.ptr = NULL;
 else {
  if (orig.type < type || orig.type >= maxType) YTuG(pos);
  p.ptr = orig.ptr;
  p.type = orig.type - type;
  p.table = table[p.type];
 }
 return p;
}

void *Zio(int type, Ti pos, Tr *p) {
 void *r;
 if (p == NULL || p->ptr == NULL) r = NULL;
 else {
  if (p->type != type) YTuG(pos);
  r = p->ptr;
 }
 return r;
}

void *Znio(int type, Ti pos, Tr tr) {
 void *r;
 if (tr.ptr == NULL) r = NULL;
 else {
  if (tr.type != type) YTuG(pos);
  r = tr.ptr;
 }
 return r;
}

void Zexit(YkxB *pos, Ti val) {
 YNab(pos, val);
}

Tt *ZiobjType(Tr *p) {
 if (p == NULL) ZthrowCstringNil("using Type() on NIL");
 return (Tt *)(p->table[0]);
}

void *ZnoAllocClear(size_t len, void *p, Ts (*finish)(void*, Te), void *(*init)(void*)) {
 if (finish && ((Zoh*)p)->np != NULL) ZcallFinish(p, 3);
 memset(p, 0, len);
 ((Zoh*)p)->np = &Znoalloc;
 if (finish) ((Zohf*)p)->ff = finish;
 if (init) init(p);
 return p;
}

Ti ZChar2ByteIdx(Tc *p, Ti len, Ti charIdx) {
 Ti idx = 0;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == len) break;
  ++idx;
  if ((p[idx - 1] & 0x80) != 0) {
    while ((p[idx] & 0xc0) == 0x80)
      ++idx;
  }
  ++count;
 }
 return idx;
}

Ti ZfromChar(Tc *p) {
 if (*p <= 0x7f)
  return *p;
 if ((*p & 0xe0) == 0xc0)
  return ((p[0] & 0x1f) << 6) + (p[1] & 0x3f);
 if  ((*p & 0xf0) == 0xe0)
  return ((p[0] & 0x0f) << 12) + ((p[1] & 0x3f) << 6) + (p[2] & 0x3f);
 return ((p[0] & 0x07) << 18) + ((p[1] & 0x3f) << 12) + ((p[2] & 0x3f) << 6) + (p[3] & 0x3f);
}

Ti ZstringGetChar(Tc *sv, Ti idx) {
 Ti i;
 Tc *p;
 Ti len;
 Ti r;
 if (sv == NULL) ZthrowCstringNil("using [] on NIL");
 if (idx < 0) ZthrowCstringOutOfRange(idx, "using negative index");
 len = ZstringSizePtr(sv, &p);
 i = ZChar2ByteIdx(p, len, idx);
 if (i >= len) ZthrowCstringOutOfRange(idx, "index too big");
 r = ZfromChar(p + i);
 return r;
}

Ti Zutf8size(Tc *sp, Ti len) {
 Tc *p = (Tc*)sp;
 Tc *pend = p + len;
 Ti clen = 0;
 while (p < pend) {
  if ((*p & 0xc0) != 0x80) ++clen;
  ++p;
 }
 return clen;
}

Ti ZstringSize(Tc *s) {
 Tc *p;
 Ti r;
 Ti len;
 if (s == NULL) return 0;
 len = ZstringSizePtr(s, &p);
 r = Zutf8size(p, len);
 return r;
}

Ti ZbyteStringSize(Tc *s) {
 Tc *p;
 Ti len;
 if (s == NULL) return 0;
 p = s + ZOH_OFF;
 if ((*p & 0x80) == 0) {
  return *p;  /* be quick for short string */
 }
 len = *p & 0x7f;
 ++p;
 while ((*p & 0x80) != 0) {
  len = (len << 7) + (*p & 0x7f);
  ++p;
 }
 return (len << 7) + *p;
}

Tc *Zint2string(Ti n) {
 char buf[30];
 char *p;
 int len;
 sprintf(buf, ZINT_FORMAT, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

#ifdef __MINGW32__
void ZcorrFloatStr(char *buf, char *fmt) {
 size_t len = strlen(buf);
 if (len > 5 && buf[len - 3] == '0' && (buf[len - 5] == 'e' || buf[len - 5] == 'E')) {
  if (fmt != NULL && isdigit(fmt[1]) && strchr(fmt, '.') > 0 && atoi(fmt + 1) >= strlen(buf)) {
   memcpy(buf + 1, buf, len - 2);
   buf[0] = ' ';
  } else {
   buf[len - 3] = buf[len - 2];
   buf[len - 2] = buf[len - 1];
   buf[len - 1] = 0;
  }
 } else if (strcmp(buf, "1.#INF") == 0) {
  strcpy(buf, "inf");
 } else if (strcmp(buf, "-1.#INF") == 0) {
  strcpy(buf, "-inf");
 } else if (strcmp(buf, "1.#QNAN") == 0) {
  strcpy(buf, "nan");
 }
}
#endif

Tc *Zenum2string(char **names, Te n) {
 return Zstr((n < 0 || n >= (Te)(size_t)names[0]) ? "INVALID" : names[n + 1]);
}

char *ZgetCstring(Tc *s) {
 Tc *p;
 if (s == NULL) return NULL;
 p = s + ZOH_OFF;
 while ((*p & 0x80) != 0) ++p;
 return (char *)p + 1;
}

Tc *ZstringToLowerAscii(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0)
  *d++ = tolower(*s++);
 *d = 0;
 return (Tc*)r;
}

Tc *ZstringToLower(Tc *ss) {
 return ZstringToLowerAscii(ss);
}

Tc *ZstringToUpperAscii(Tc *ss) {
 Tc *r;
 Tc *d;
 Tc *s;
 Ti len;
 if (ss == NULL) return NULL;
 len = ZstringSizePtr(ss, &s);
 r = ZnewString(s, len);
 d = r + (s - (Tc*)ss);
 while (*s != 0)
  *d++ = toupper(*s++);
 *d = 0;
 return (Tc*)r;
}

Tc *ZstringToUpper(Tc *ss) {
 return ZstringToUpperAscii(ss);
}

void ZforRangeNew(Ti start, Ti last, int until, Ti step, Tfr *s) {
 s->idx = start;
 if (until)
  s->last = last - (step > 0 ? 1 : -1);
 else
  s->last = last;
 s->step = step;
}
void ZforRangeGetInt(Tfr *s, Ti *p) {
 *p = s->idx;
}
int ZforRangeContInt(Tfr *s) {
 return s->step > 0 ? (s->idx <= s->last) : (s->idx >= s->last);
}
void ZforRangeNextInt(Tfr *s, Ti *p) {
 s->idx += s->step;
 ZforRangeGetInt(s, p);
}

void ZforEnumGetEnum(Tfe *fe, Te *p) {
 *p = fe->idx;
}
int ZforEnumContEnum(Tfe *fe) {
 return fe->idx < fe->count;
}
void ZforEnumNextEnum(Tfe *fe, Te *p) {
 if (fe->idx < fe->count)
  ++(fe->idx);
 *p = fe->idx;
}

void ZtryDeeper(Tn *e, Zsf *sf) {
 if (e->tryCtx == NULL) {
  e->tryCtxSize = 20;
  e->tryCtx = ZaNm(sizeof(Ttc) * e->tryCtxSize);
  e->tryCtxUsed = 1;
 } else if (++e->tryCtxUsed > e->tryCtxSize) {
  e->tryCtxSize += 20;
  e->tryCtx = ZranNm(e->tryCtx, sizeof(Ttc) * (e->tryCtxSize - 20), sizeof(Ttc) * e->tryCtxSize);
 }
 e->tryCtx[e->tryCtxUsed - 1].sf = sf;
}
void Zrethrow() {
 Tn *e = ZgetEnv();
   ZthrowIobject(e->thrown[--e->thrownUsed]);
}

void ZthrowIobject(Tr eo) {
 Tn *e = ZgetEnv();
 Ttc *ctx = &e->tryCtx[e->tryCtxUsed - 1];
 int i;
 Zsf *stop = NULL;
 if (e->tryCtxUsed > 0) stop = ctx->sf;
 while (e->topFrame != stop) {
  Zfo *fo = e->topFrame->frof;
  if (fo != NULL) {
   for (i = 0; fo[i].off != 0; ++i) {
    Tto *tto = (Tto*)fo[i].type;
    if (tto->nr == 390 && tto->Finish != NULL && (fo[i].off & 1)) {
     Zohf *p = (Zohf*)((char *)e->topFrame - (fo[i].off - 1));
     if (p->np != NULL) {
      ZcallFinish(p, 2);
      p->np = NULL;
     }
    } else if (tto->nr == 391 && (fo[i].off & 1)) {
     ZFinishIobj((Tr*)((char *)e->topFrame - (fo[i].off - 1)), 2);
    }
   }
  }
  if (e->topFrame->prev == NULL) break;
  e->topFrame = e->topFrame->prev;
 }
 if (e->tryCtxUsed > 0) {
  if (e->thrown == NULL) {
   e->thrownSize = 10;
   e->thrown = ZaNmi(sizeof(Tr) * e->thrownSize);
   e->thrownUsed = 1;
  } else if (++e->thrownUsed > e->thrownSize) {
   e->thrownSize += 20;
   e->thrown = ZranNm(e->thrown, sizeof(Tr) * (e->thrownSize - 20), sizeof(Tr *) * e->thrownSize);
  }
  e->thrown[e->thrownUsed - 1] = eo;
  longjmp(ctx->jmpBuf, 42);
 } else
 YxIS(eo);
}
void ga_append(Tg *ga, char *str) {
 int len = (int)strlen(str);
 if (ga->data == NULL || ga->used + len >= ga->len) {
  int newLen = ga->used + len + 200;
  Tc *newData = ZaOff(newLen);
  if (ga->data != NULL) {
    memmove(newData, ga->data, ga->used);
    Zfree(ga->data - ZOH_OFF);
  }
  ga->data = newData;
  ga->len = newLen;
 }
 strcpy((char *)ga->data + ga->used, str);
 ga->used += len;
}

int ZstringCmp(Tc *s1, Tc *s2) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 int r;
 if (s1 == NULL || s2 == NULL) {
  if (s1 == NULL && s2 == NULL) r = 0;
  else r = 1;
  goto end;
 }
 if (s1[ZOH_OFF] != s2[ZOH_OFF]) {
  r = 1;
  goto end;
 }
 len1 = ZstringSizePtr(s1, &p1);
 len2 = ZstringSizePtr(s2, &p2);
 if (len1 == len2) {
  r = memcmp(p1, p2, len1);
  goto end;
 }
 r = 1;
end:
 return r;
}

Ti ZChar2ByteIdxEnd(Tc *p, Ti len, Ti charIdx) {
 Ti idx = len;
 Ti count = 0;
 while (count < charIdx) {
  if (idx == 0) return -1;
  --idx;
  while (idx > 0 && (p[idx] & 0xc0) == 0x80)
    --idx;
  ++count;
 }
 return idx;
}

Ti ZstringFindLen(Tc *big, Ti biglen, Tc *small, Ti smalllen) {
 Ti i;
 Ti ci = 0;
 for (i = 0; i <= biglen - smalllen; ++ci) {
  if (memcmp(big + i, small, smalllen) == 0)
   return ci;
  ++i;
  while ((big[i] & 0xc0) == 0x80 && i < biglen)
   ++i;
 }
 return -1;
}

Ti ZstringFind(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Ti r;
 if (big == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  if (small == NULL) ZthrowCstringNil("using find() with NIL argument");
  biglen = ZstringSizePtr(big, &bigp);
  smalllen = ZstringSizePtr(small, &smallp);
  r = ZstringFindLen(bigp, biglen, smallp, smalllen);
 }
 return r;
}

Ti ZptrFindChar2(Tc *s, Ti slen, Ti c, Ti low) {
 Tc *p = s;
 Ti idx = 0;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0 && idx >= low) {
   return idx;
  }
  p += charlen;
  ++idx;
 }
 return -1;
}

Ti ZstringFindChar2(Tc *s, Ti c, Ti low, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using find() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindChar2(p, len, c, low);
 }
 return r;
}

Ti ZstringFindChar(Tc *s, Ti c, int dn) {
 return ZstringFindChar2(s, c, 0, dn);
}

Tb ZstringStartsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using startsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using startsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp, smallp, smalllen) == 0;
end:
 return r;
}

Tb ZstringEndsWith(Tc *big, Tc *small, int dn) {
 Tc *bigp;
 Tc *smallp;
 Ti biglen;
 Ti smalllen;
 Tb r = 0;
 if (big == NULL) {
  if (dn) goto end;
  ZthrowCstringNil("using endsWith() on NIL");
 }
 if (small == NULL) ZthrowCstringNil("using endsWith() with NIL argument");
 biglen = ZstringSizePtr(big, &bigp);
 smalllen = ZstringSizePtr(small, &smallp);
 if (smalllen <= biglen) r = memcmp(bigp + biglen - smalllen, smallp, smalllen) == 0;
end:
 return r;
}

Ti ZptrFindLastChar2(Tc *s, Ti slen, Ti c, Ti high) {
 Tc *p = s;
 Ti idx = 0;
 Ti best = -1;
 Ti len;
 Tc buf[5];
 int charlen;
 int clen = Zchar2stringBuf(c, buf);
 for (len = slen; len > 0 && idx <= high; len -= charlen) {
  for (charlen = 1; (p[charlen] & 0xc0) == 0x80; ++charlen)
   ;
  if (charlen == clen && memcmp(buf, p, charlen) == 0)
   best = idx;
  p += charlen;
  ++idx;
 }
 return best;
}

Ti ZstringFindLastChar(Tc *s, Ti c, int dn) {
 Tc *p;
 int len;
 Ti r;
 if (s == NULL) {
  if (!dn) ZthrowCstringNil("using findLast() on NIL");
  r = -1;
 } else {
  len = ZstringSizePtr(s, &p);
  r = ZptrFindLastChar2(p, len, c, len);
 }
 return r;
}

Tl *ZstringSplitLen(Tc *pss, Ti len, Tc *m) {
 Tl *head = ZnewList(&string__T, 0);
 if (len > 0) {
  Tc *mp;
  Ti mlen = ZstringSizePtr(m, &mp);
  Tc *ps;
  Tc *pe;

  for (ps = pss; ; ps = pe + mlen) {
   int nlen;
   /* TODO: handle NULL byteString */
   pe = (Tc*)strstr((char *)ps, (char *)mp);
   if (pe == NULL) {
    nlen = len - (ps - pss);
   } else {
    nlen = pe - ps;
   }
   ZLa(head, -1, (Tz)(void*)ZnewString(ps, nlen));
   if (pe == NULL) break;
  }
 }
 return head;
}

Tl *ZstringSplit(Tc *b, Tc *m, int dn) {
 Tc *p;
 Ti len;
 Tl *r;
 if (b == NULL) {
  if (!dn) ZthrowCstringNil("using split() on NIL");
  r = NULL;
 } else {
  if (m == NULL) ZthrowCstringNil("split() argument is NIL");
  len = ZstringSizePtr(b, &p);
  r = ZstringSplitLen(p, len, m);
 }
 return r;
}

Tc *ZstringSlice(Tc *sv, Ti start, Ti end, int dn) {
 Ti is;
 Ti ie;
 Tc *p;
 Ti len;
 Tc *r;
 if (sv == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("using slice() on NIL");
 }
 len = ZstringSizePtr(sv, &p);
 is = start < 0 ? ZChar2ByteIdxEnd(p, len, -start) : ZChar2ByteIdx(p, len, start);
 ie = end < 0 ? ZChar2ByteIdxEnd(p, len, -end - 1) - 1 : ZChar2ByteIdx(p, len, end + 1) - 1;
 if (is < 0)
  is = 0;
 if (ie < 0 || ie < is) r = ZnewString((Tc*)"", 0);
 else r = ZnewString(p + is,  ie - is + 1);
 return r;
}

Ti ZptrToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char*)s;
 if ((*p < '0' || *p > '9') && *p != '-') {
  if (t == 1) ZthrowCstringBadValue("toInt(): argument does not start with a digit or -");
  return def;
 }
 sscanf(p, ZINT_FORMAT, &r);
 return r;
}

Ti ZstringToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using toInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrToInt(s, t, def);
 return r;
}

void ZitemToString(Tt *type, int useq, Tz val, Tg *ga);

void ZobjectToString(Tto *typearg, void *ptrarg, Tg *ga) {
 Tto *type = typearg;
 void *ptr = ptrarg;
 To *to;
 int cnt;
 if (type == NULL && ptr != NULL) {
  type = ((Tto*)ZiobjType(ptr));
  ptr = ((Tr*)ptr)->ptr;
 }
 if (ptr == NULL ) {
  ga_append(ga, "{NIL}");
 } else {
  int i;
  int first = 1;
  if (type->ToString != NULL) {
   Tc *p = ((Tc * (*)(void *))type->ToString)(ptr);
   ga_append(ga, ZgetCstring(p));
   return;
  }
  to = type->to;
  ga_append(ga, "{");
  cnt = to[0].off;
  for (i = 1; i <= cnt; ++i) {
   Tz val;
   void *vptr = ptr + to[i].off;

   if (!first) ga_append(ga, ", ");
   first = 0;
   ga_append(ga, type->names[i - 1]);
   ga_append(ga, ": ");
   switch (to[i].type->nr) {
    case 0:
    case 24:
    case 25:
     val = (Tz)*((Ti*)vptr); break;
    case 10:
     val = (Tz)(Ti)*((Tu*)vptr); break;
    case 1:
     val = (Tz)(Ti)*((char*)vptr); break;
    case 11:
     val = (Tz)(Ti)*((Tc*)vptr); break;
    case 2:
     val = (Tz)(Ti)*((Ti16*)vptr); break;
    case 12:
     val = (Tz)(Ti)*((Tu16*)vptr); break;
    case 3:
     val = (Tz)(Ti)*((Ti32*)vptr); break;
    case 13:
     val = (Tz)(Ti)*((Tu32*)vptr); break;
    case 21:
    case 22:
    case 23:
     val = (Tz)(Ti)*((int*)vptr); break;
    case 80:
    case 82:
    case 83:
     val = (Tz)*((Tf*)vptr); break;
    case 81:
     val = (Tz)(Tf)*((Tf32*)vptr); break;
    default:
     val = (Tz)*(((void**)vptr)); break;
   }
   ZitemToString(to[i].type, 1, val, ga);
  }
  ga_append(ga, "}");
 }
}

Tc *ZobjectToStringval(Tto *type, void *ptr) {
 Tg ga;
 Tc *r;
 ga.data = NULL;
 ga.used = 0;
 ++ZgetEnv()->tosNr;
 ZobjectToString(type, ptr, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}
Tc *ZiobjectToStringval(Tr tr) {
 Tg ga;
 Tc *r;
 ga.data = NULL;
 ga.used = 0;
 ++ZgetEnv()->tosNr;
 ZobjectToString((Tto*)tr.table[0], tr.ptr, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

void ZitemToString(Tt *type, int useq, Tz val, Tg *ga) {
 char buf[30];
 if (type->nr < 100) {
  switch (type->nr) {
   case 0:
   case 1:
   case 2:
   case 3:
   case 25:
    sprintf(buf, ZINT_FORMAT, val.ival);
    ga_append(ga, buf);
    break;
   case 10:
    sprintf(buf, ZNAT_FORMAT, (Tu)val.ival);
    ga_append(ga, buf);
    break;
   case 11:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tc)val.ival);
    ga_append(ga, buf);
    break;
   case 12:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tu16)val.ival);
    ga_append(ga, buf);
    break;
   case 13:
    sprintf(buf, ZNAT_FORMAT, (Tu)(Tu32)val.ival);
    ga_append(ga, buf);
    break;
   case 21: ga_append(ga, val.ival ? "TRUE" : "FALSE"); break;
   case 22: ga_append(ga, val.ival ? "OK" : "FAIL"); break;
   case 23:
    if (type->ToString == NULL) {
     ga_append(ga, "-enum");
     if (type->name) {
      ga_append(ga, " ");
      ga_append(ga, ZgetCstring(type->name));
     }
     ga_append(ga, "-");
    } else {
     ga_append(ga, ((char * (*)(Te))type->ToString)(val.ival));
    }
    break;
   case 80:
   case 81:
   case 82:
   case 83:
    sprintf(buf, ZFLOAT_FORMAT, val.fval);
#ifdef __MINGW32__
    ZcorrFloatStr(buf, NULL);
#endif
    ga_append(ga, buf);
    break;
  }
 } else {
  void *ptr = val.ptr;
  if (ptr == NULL) ga_append(ga, "NIL");
  else switch (type->nr) {
   case 200:
   case 201: {
     Tc *p;
     (void)ZstringSizePtr(ptr, &p);
     if (useq) ga_append(ga, "\"");
     ga_append(ga, (char *)p);
     if (useq) ga_append(ga, "\"");
    }
    break;
   case 300:
    ZArrayToStringGa((Ta *)ptr, 1, ga);
    break;
   case 301:
    ZListToStringGa((Tl *)ptr, 1, ga);
    break;
   case 302:
    ZDictToStringGa((Td *)ptr, 1, 1, ga);
    break;
   case 310:
    ga_append(ga, "-varString-");
    break;
   case 311:
    ga_append(ga, "-varByteString-");
    break;
   case 320:
    if (type->ToString == NULL) ga_append(ga, "-tuple-");
    else {
     Tc *p = ((Tc * (*)(void *))type->ToString)(ptr);
     ga_append(ga, ZgetCstring(p));
    }
    break;
   case 330:
    ga_append(ga, "-proc/func-");
    break;
   case 390:
    ZobjectToString(((Tto*)type), ptr, ga);
    break;
   case 391:
    ZobjectToString((Tto*)((Tr*)ptr)->table[0], ((Tr*)ptr)->ptr, ga);
    break;
  }
 }
}

int ZcopyItems(Tt *toType, int toSize, void *toPtr, Ti toOff, Tt *fromType, int fromSize, void *fromPtr, Ti fromOff, Ti len) {
 Ti i;
 if (toType == fromType || (toType->nr >= 100 && fromType->nr >= 100)) {
  memmove((char*)toPtr + toOff * toSize, (char*)fromPtr + fromOff * fromSize, len * toSize);
  return 1;
 }
 if (fromType->nr >= 100 || toType->nr >= 100) return 0;
 for (i = 0; i < len; ++i) {
  Ti iv;
  Tf fv;
  switch (fromType->nr) {
   case 0:
   case 24:
   case 25:
    iv = ((Ti*)fromPtr)[fromOff + i]; fv = iv; break;
   case 1:
    iv = ((char*)fromPtr)[fromOff + i]; fv = iv; break;
   case 2:
    iv = ((Ti16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 3:
    iv = ((Ti32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 10:
    iv = ((Tu*)fromPtr)[fromOff + i]; fv = iv; break;
   case 11:
    iv = ((Tc*)fromPtr)[fromOff + i]; fv = iv; break;
   case 12:
    iv = ((Tu16*)fromPtr)[fromOff + i]; fv = iv; break;
   case 13:
    iv = ((Tu32*)fromPtr)[fromOff + i]; fv = iv; break;
   case 21:
   case 22:
   case 23:
    iv = ((int*)fromPtr)[fromOff + i]; fv = iv; break;
   case 80:
   case 82:
   case 83:
    fv = ((Tf*)fromPtr)[fromOff + i]; iv = fv; break;
   case 81:
    fv = ((Tf32*)fromPtr)[fromOff + i]; iv = fv; break;
  }
  switch (toType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    ((Ti*)toPtr)[toOff + i] = iv; break;
   case 1:
   case 11:
    ((char*)toPtr)[toOff + i] = iv; break;
   case 2:
   case 12:
    ((Ti16*)toPtr)[toOff + i] = iv; break;
   case 3:
   case 13:
    ((Ti32*)toPtr)[toOff + i] = iv; break;
   case 21:
   case 22:
   case 23:
    ((int*)toPtr)[toOff + i] = iv; break;
   case 80:
   case 82:
   case 83:
    ((Tf*)toPtr)[toOff + i] = fv; break;
   case 81:
    ((Tf32*)toPtr)[toOff + i] = fv; break;
  }
 }
 return 1;
}
void ZfreeArray(Ta *head) {
 Ti i;
 Ti d;
 if (head == NULL) return;
 if (head->ptr && head->ptr != head + 1) {
  Zfree(head->ptr - ZOH_OFF);
 }
 Zfree(head);
}

Ta *ZArrayInit(Ta *head, Tt *itemType, int itemSize, Ti size) {
 head->ptr = ZaOff(itemSize * size);
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ta *ZnewArray(Tt *itemType, int itemSize, Ti size) {
 Ta *head;
 size_t extra = size * itemSize;
 if (extra > 100) extra = 0;
 head = Za(sizeof(Ta) + extra);
 if (extra == 0) {
  head->ptr = ZaOff(itemSize * size);
 } else head->ptr = head + 1;
 head->dim = 1;
 head->size[0] = size;
 head->itemType = itemType;
 head->itemSize = itemSize;
 return head;
}

Ti ZArraySize(Ta *head) {
 Ti r;
 if (head == NULL) r = 0;
 else r = head->size[0];
 return r;
}

Ta *Zas(Ta *head, void *vals, int type, Ti offset) {
 int len;
 int i;
 if (head == NULL) ZthrowCstringNil("Invoking set() on NIL array");
 if (type == 0) {
  /* vals is a byteString */
  Tc *p;
  len = ZstringSizePtr(vals, &p);
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  if (head->itemSize == 1) {
   memmove(((Tc*)head->ptr) + offset, p, len);
  } else if (head->itemSize == sizeof(Te)) {
   for (i = 0; i < len; ++i) ((Te*)head->ptr)[i + offset] = p[i];
  } else {
   for (i = 0; i < len; ++i) ((Ti*)head->ptr)[i + offset] = p[i];
  }
 } else if (type == 1) {
  /* vals is an array */
  Ta *from = vals;
  len = from->size[0];
  if (len > head->size[0] - offset) len = head->size[0] - offset;
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->ptr, 0, len);

 } else {
  /* vals is a list */
  Tl *from = (Tl*)vals;
  Ti count = from->itemCount;
  if (count > offset + head->size[0]) count = offset + head->size[0];
  ZcopyItems(head->itemType, head->itemSize, head->ptr, offset, from->itemType, from->itemSize, from->items, from->empty, count);
 }
 return head;
}

Ta *ZarrayResize(Ta *head, int bytes, Ti size) {
 if (head == NULL) ZthrowCstringNil("Invoking resize() on NIL array");
 if (head->ptr == head + 1) {
  head->ptr = ZaOff(bytes * size);
  memmove(head->ptr, head + 1, size > head->size[0] ? bytes * head->size[0] : bytes * size);
 } else head->ptr = ZranOff(head->ptr, bytes * head->size[0], bytes * size);
 head->size[0] = size;
 return head;
}

void ZArrayToStringGa(Ta *head, int useq, Tg *ga) {
 int i;
 Tn *e = ZgetEnv();
 ga_append(ga, "[");
 if (head->tosNr == e->tosNr) {
  ga_append(ga, "recursive-array");
 } else {
  head->tosNr = e->tosNr;
  for (i = 0; i < head->size[0]; ++i) {
   Tz v;
   if (i > 0) ga_append(ga, ", ");
   if (head->itemType == &iobj__T) {
    Tr *tr = (Tr*)head->ptr + i;
    if (tr->ptr == NULL) ZobjectToString(NULL, NULL, ga);
    else ZitemToString((Tt*)(tr->table[0]), useq, (Tz)tr->ptr, ga);
   } else {
    if (head->itemSize == 1) {
     v.ival = ((Tc*)head->ptr)[i];
    } else if (head->itemType->nr >= 100) {
     v.ptr = ((char**)head->ptr)[i];
    } else if (head->itemSize == sizeof(Te)) {
     v.ival = ((Te*)head->ptr)[i];
    } else {
     v.ival = ((Ti*)head->ptr)[i];
    }
    ZitemToString(head->itemType, useq, v, ga);
   }
  }
  head->tosNr = 0;
 }
 ga_append(ga, "]");
}

Tc *ZarrayToString(Ta *head, int useq) {
 Tg ga;
 Tc *r;
 if (head == NULL) return (Tc*)&ZNilString;
 ++ZgetEnv()->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZArrayToStringGa(head, useq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

Ti ZListFindIdx(Tl *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("Accessing NIL list");
 if (idx < 0) {
  Ti n = head->itemCount + idx;
  if (n < 0) return n;
  return n + head->empty;
 }
 if (idx >= head->itemCount) return -1;
 return idx + head->empty;
}

void ZListSetType(Tl* head, Tt *itemType) {
 head->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating list without type");
 switch (itemType->nr) {
  case 0:
  case 10:
  case 80:
  case 82:
  case 83:
  case 24:
  case 25:
   head->itemSize = 8; break;
  case 1:
  case 11:
   head->itemSize = 1; break;
  case 12:
  case 2:
   head->itemSize = 2; break;
  case 3:
  case 13:
  case 81:
   head->itemSize = 4; break;
  case 21:
  case 22:
  case 23:
   head->itemSize = sizeof(int); break;
  case 391:
   head->itemSize = sizeof(Tr); break;
  default:
   head->itemSize = sizeof(void*); break;
 }
}

Tl *ZnewList(Tt *itemType, Ti size) {
 int alloc = size > ((itemType->nr == 1 || itemType->nr == 11) ? 64 : 8);
 int extraSize = itemType != NULL && itemType->nr == 391 ? 8 * sizeof(Tr) : 64;
 Tl *head = Za(sizeof(Tl) + (alloc ? 0 : extraSize));
 ZListSetType(head, itemType);
 if (alloc) {
  head->items = ZaOff(head->itemSize * size);
  head->space = size;
 } else {
  head->items = (void**)(head + 1);
  head->space = extraSize / head->itemSize;
 }
 return head;
}
void ZListitemToString(Tl *head, int useq, Ti n, Tg *ga) {
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   ZitemToString(head->itemType, useq, (Tz)((Ti*)head->items)[n], ga);
   break;
  case 1:
  case 11:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((char*)head->items)[n], ga);
   break;
  case 12:
  case 2:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((Ti16*)head->items)[n], ga);
   break;
  case 3:
  case 13:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((Ti32*)head->items)[n], ga);
   break;
  case 21:
  case 22:
  case 23:
   ZitemToString(head->itemType, useq, (Tz)(Ti)((int*)head->items)[n], ga);
   break;
  case 80:
  case 82:
  case 83:
   ZitemToString(head->itemType, useq, (Tz)((Tf*)head->items)[n], ga);
   break;
  case 81:
   ZitemToString(head->itemType, useq, (Tz)(Tf)((Tf32*)head->items)[n], ga);
   break;
  case 391:
   {
    Tr *tr = (Tr*)head->items + n;
    ZitemToString((Tt*)(tr->table[0]), useq, (Tz)tr->ptr, ga);
    break;
   }
  default:
   ZitemToString(head->itemType, useq, (Tz)head->items[n], ga);
   break;
 }
}

void ZListToStringGa(Tl *head, int useq, Tg *ga) {
 Ti n = head->empty;
 Ti tot = head->empty + head->itemCount;
 int itemType = head->itemType->nr;
 Tn *e = ZgetEnv();
 ga_append(ga, "[");
 if (head->itemCount) {
  if (head->tosNr == e->tosNr) {
   ga_append(ga, "recursive-list");
  } else {
   head->tosNr = e->tosNr;
   for (;;) {
    ZListitemToString(head, useq, n, ga);
    if (++n == tot) break;
    ga_append(ga, ", ");
   }
   head->tosNr = 0;
  }
 }
 ga_append(ga, "]");
}

Tc *ZListToString(Tl *head, int useq) {
 Tg ga;
 Tc *r;
 if (head == NULL) return (Tc*)&ZNilString;
 ++ZgetEnv()->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZListToStringGa(head, useq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree(ga.data - ZOH_OFF);
 return r;
}

void ZListGrow(Tl *head, Ti count) {
 Ti newsize = head->empty + head->itemCount + count;
 if (newsize <= head->space) return;
 if (newsize < 100) {
  newsize += (newsize >> 2) + 7;
 } else {
  newsize += newsize >> 3;
 }
 if (head->items == (void**)(head + 1)) {
  head->items = ZaOff(head->itemSize * newsize);
  memmove(head->items, head + 1, head->itemSize * head->itemCount);
 } else {
  head->items = ZranOff(head->items, head->itemSize * head->space, head->itemSize * newsize);
 }
 head->space = newsize;
}

Tl *ZLa(Tl *head, Ti after, Tz val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 switch (head->itemType->nr) {
  case 0:
  case 10:
  case 24:
  case 25:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti*)head->items) + idx + 1, ((Ti*)head->items) + idx, head->itemSize * len);
   ((Ti*)head->items)[idx] = val.ival;
   break;
  case 1:
  case 11:
   if (len > 0 && idx >= head->empty)
    memmove(((char*)head->items) + idx + 1, ((char*)head->items) + idx, head->itemSize * len);
   ((char*)head->items)[idx] = val.ival;
   break;
  case 12:
  case 2:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti16*)head->items) + idx + 1, ((Ti16*)head->items) + idx, head->itemSize * len);
   ((Ti16*)head->items)[idx] = val.ival;
   break;
  case 3:
  case 13:
   if (len > 0 && idx >= head->empty)
    memmove(((Ti32*)head->items) + idx + 1, ((Ti32*)head->items) + idx, head->itemSize * len);
   ((Ti32*)head->items)[idx] = val.ival;
   break;
  case 21:
  case 22:
  case 23:
   if (len > 0 && idx >= head->empty)
    memmove(((int*)head->items) + idx + 1, ((int*)head->items) + idx, head->itemSize * len);
   ((int*)head->items)[idx] = val.ival;
   break;
  case 80:
  case 82:
  case 83:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf*)head->items) + idx + 1, ((Tf*)head->items) + idx, head->itemSize * len);
   ((Tf*)head->items)[idx] = val.fval;
   break;
  case 81:
   if (len > 0 && idx >= head->empty)
    memmove(((Tf32*)head->items) + idx + 1, ((Tf32*)head->items) + idx, head->itemSize * len);
   ((Tf32*)head->items)[idx] = val.fval;
   break;
  default:
   if (len > 0 && idx >= head->empty)
    memmove(head->items + idx + 1, head->items + idx, head->itemSize * len);
   head->items[idx] = val.ptr;
   break;
 }
 ++head->itemCount;
 return head;
}
Tl *ZLap(Tl *head, Tz val) {
 return ZLa(head, -1, val);
}

Tl *ZLaIobj(Tl *head, Ti after, Tr val) {
 Ti nAfter;
 Ti idx;
 Ti len;
 if (head == NULL) ZthrowCstringNil("Attempt to append to NIL list");
 ZListGrow(head, 1);
 if (after < 0) {
  nAfter = head->itemCount + after;
  if (nAfter < 0) nAfter = -1;
 } else {
  nAfter = after;
  if (nAfter >= head->itemCount) nAfter = head->itemCount - 1;
 }
 idx = nAfter + head->empty + 1;
 len = head->itemCount - nAfter - 1;
 if (len > 0 && idx >= head->empty)
  memmove((Tr*)head->items + idx + 1, (Tr*)head->items + idx, head->itemSize * len);
 ((Tr*)head->items)[idx] = val;
 ++head->itemCount;
 return head;
}
Tl *ZLapIobj(Tl *head, Tr val) {
 return ZLaIobj(head, -1, val);
}
Tl *ZListInsert(Tl *head, Ti before, Tz val) {
 Ti nBefore;
 Ti idx;
 if (head == NULL) ZthrowCstringNil("Invoking insert() on NIL list");
 if (head->itemCount == 0 || before >= head->itemCount) return ZLa(head, -1, val);
 if (before < 0) {
  nBefore = head->itemCount + before;
 } else {
  nBefore = before;
 }
 if (nBefore <= 0) nBefore = -head->itemCount;
 return ZLa(head, nBefore - 1, val);
}

Ti ZListSize(Tl *head) {
 if (head == NULL) return 0;
 return head->itemCount;
}

Ti ZListGetInt(Tl *head, Ti idx) {
 Ti r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 10:
    r = (Ti)((Tu*)head->items)[n]; break;
   case 1:
    r = ((char*)head->items)[n]; break;
   case 11:
    r = (Ti)((Tc*)head->items)[n]; break;
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 12:
    r = (Ti)((Tu16*)head->items)[n]; break;
   case 3:
    r = ((Ti32*)head->items)[n]; break;
   case 13:
    r = (Ti)((Tu32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetIntP(Tl *head, Ti idx) {
 Ti *r;
 Ti n = ZListFindIdx(head, idx);
 if (n < 0) ZthrowCstringOutOfRange(idx, "index out of range");
 return (void*)head->items + n * head->itemSize;
}

Tf ZListGetFloat(Tl *head, Ti idx) {
 Tf r;
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  switch (head->itemType->nr) {
   case 80:
   case 82:
   case 83:
    r = ((Tf*)head->items)[n]; break;
   case 81:
    r = (Tf)((Tf32*)head->items)[n]; break;
  }
 } else r = 0;
 return r;
}

void *ZListGetPtr(Tl *head, Ti idx) {
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) return head->items[n];
 return NULL;
}

Ti ZListFind(Tl *head, Tz val) {
 Ti n;
 Ti tot;
 if (head == NULL) ZthrowCstringNil("Attempt to find in NIL list");
 n = head->empty;
 tot = n + head->itemCount;
 for ( ; n < tot ; ++n)
  switch (head->itemType->nr) {
   case 0:
   case 24:
   case 25:
    if (((Ti*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 10:
    if ((Ti)((Tu*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 1:
    if (((char*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 11:
    if ((Ti)((Tc*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 2:
    if (((Ti16*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 12:
    if ((Ti)((Tu16*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 3:
   case 13:
    if (((Ti32*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 21:
   case 22:
   case 23:
    if (((int*)head->items)[n] == val.ival) return n - head->empty;
    break;
   case 80:
   case 82:
   case 83:
    if (((Tf*)head->items)[n] == val.fval) return n - head->empty;
    break;
   case 81:
    if (((Tf32*)head->items)[n] == (Tf32)val.fval) return n - head->empty;
    break;
   case 200:
   case 201:
    if (ZstringCmp(head->items[n], val.ptr) == 0) return n - head->empty;
    break;
   case 391:
    ZthrowCstringNil("Invoking find() on iobject list");
    break;
   default:
    if (head->items[n] == val.ptr) return n - head->empty;
    break;
  }
 return -1;
}

void *ZListRemovePtrItem(Tl *head, Ti idx) {
 void *r = NULL;
 if (head == NULL) ZthrowCstringNil("Invoking remove() on NIL list");
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  Ti len = head->itemCount - (n - head->empty) - 1;
  r = head->items[n];
  if (len > 0)
   memmove(head->items + n, head->items + n + 1, len * sizeof(void*));
  head->itemCount--;
  // ZListShrink(head);
 }
 return r;
}

static int stringCmp(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p1p, p2p, len);
 if (r == 0) return len1 - len2;
 return r;
}
static int stringCmpR(const void *p1, const void *p2) {
 Tc *p1p;
 Tc *p2p;
 Ti len1 = ZstringSizePtr(*(Tc **)p1, &p1p);
 Ti len2 = ZstringSizePtr(*(Tc **)p2, &p2p);
 size_t len = len1 < len2 ? len1 : len2;
 int r = memcmp(p2p, p1p, len);
 if (r == 0) return len2 - len1;
 return r;
}
Tl *ZstringListSort(Tl *head, int asc) {
 int i = 0;
 if (head == NULL) ZthrowCstringNil("Invoking sort() on NIL list");
 qsort(head->items + head->empty, head->itemCount, sizeof(Tc*), asc ? stringCmp : stringCmpR);
 return head;
}

int ZforListIobjCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Tr*)tfl->valp = ((Tr*)l->items)[i + l->empty];
 ++tfl->i;
 return 1;
}

int ZforListIntCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(Ti*)tfl->valp = ZListGetInt(l, i);
 ++tfl->i;
 return 1;
}

int ZforListPtrCont(Tfl *tfl) {
 Tl *l = tfl->l;
 Ti i = tfl->i;
 if (l == NULL || i >= l->itemCount) return 0;
 *(char**)tfl->valp = l->items[i + l->empty];
 ++tfl->i;
 return 1;
}

int ZDeqNr(Tz *l, Tz *r) {
 return l->ival == r->ival;
}
int ZDeqFloat(Tz *l, Tz *r) {
 return l->fval == r->fval;
}
int ZDeqStr(Tz *l, Tz *r) {
 Tc *p1;
 Tc *p2;
 Ti len1;
 Ti len2;
 if (r->ptr != NULL) {
  len1 = ZstringSizePtr(l->ptr, &p1);
  len2 = ZstringSizePtr(r->ptr, &p2);
  if (len1 == len2) return memcmp(p1, p2, len1) == 0;
 }
 return 0;
}
int ZDeqRef(Tz *l, Tz *r) {
 return l->ptr == r->ptr;
}
int ZDeqIobj(Tr *l, Tz *r) {
 return l->ptr == ((Tr*)r->ptr)->ptr;
}

Td *ZDictHead(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 d->array = d->smallArray;
 d->mask = HT_INIT_SIZE - 1;
 d->keyType = keyType;
 d->itemType = itemType;
 if (itemType == NULL) ZthrowCstringNil("Creating dict without item type");
 if (keyType == NULL) ZthrowCstringNil("Creating dict without key type");
 if (ordered) d->type = DTYPE_ORDERED;
 if (keyType->nr < 80) d->eqfunc = (int (*)(void*, Tz*))ZDeqNr;
 else if (keyType->nr < 100) d->eqfunc = (int (*)(void*, Tz*))ZDeqFloat;
 else if (keyType == &iobj__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqIobj;
 else if (keyType == &string__T || keyType == &byteString__T) d->eqfunc = (int (*)(void*, Tz*))ZDeqStr;
 else d->eqfunc = (int (*)(void*, Tz*))ZDeqRef;
 return d;
}
Td *ZDictInit(Td *d, Tt *keyType, Tt *itemType, Tb ordered) {
 memset(d, 0, sizeof(Td));
 d->np = &Znoalloc;
 ZDictHead(d, keyType, itemType, ordered);
 return d;
}
Td *ZnewDict(Tt *keyType, Tt *itemType, Tb ordered) {
 return ZDictHead(Za(sizeof(Td)), keyType, itemType, ordered);
}

Zhashtype ZDictHash(Tt *keyType, Tz key) {
 Zhashtype hash;
 void *ptr;
 if (keyType->nr < 80) return (Zhashtype)key.ival;
 if (keyType->nr < 100) return (Zhashtype)key.fval;
 if (keyType == &iobj__T) {
  ptr = ((Tr*)key.ptr)->ptr;
 } else {
  ptr = key.ptr;
 }
 if (ptr == NULL) ZthrowCstringNil("dict key is NIL");
 if (keyType == &string__T || keyType == &byteString__T) {
  Tc *p;
  int l = ZstringSizePtr(key.ptr, &p);
  if (l == 0) {
   hash = 0;
  } else {
   hash = *p;
   while (--l > 0) {
    hash = hash * 101 + *++p;
   }
  }
 } else {
  Tip k = (Tip)ptr;
  int l = sizeof(Tc*);
  hash = k & 0xff;
  while (--l > 0) {
   k >>= 8;
   hash = hash * 101 + (k & 0xff);
  }
 }
 return hash;
}

void ZthrowIntKeyNotFound(Tz key, Tc *msg) {
  Yxmk(key.ival, msg);
}

void ZthrowStringKeyNotFound(Tz key, Tc *msg) {
  Y5LT(key.ptr, msg);
}

void ZthrowIntKeyExists(Tz key, Tc *msg) {
  YL9Z(key.ival, msg);
}
void ZthrowStringKeyExists(Tz key, Tc *msg) {
  YEeX(key.ptr, msg);
}

/* #define DICT_DEBUG 1 */

CDictItem *ZDictLookup(Td *d, Tz key, Zhashtype hash)
{
 Zhashtype  perturb;
 CDictItem  *freeitem;
 int        idx = (int)(hash & d->mask);
 CDictItem  *di = &d->array[idx];
 if (di->flags == 0) return di;
 if (di->flags == CDI_FLAG_DEL) freeitem = di;
 else if (di->hash == hash && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) {
  return di;
 } else {
  freeitem = NULL;
 }

 for (perturb = hash; ; perturb >>= PERTURB_SHIFT)
 {
  idx = (int)((idx << 2) + idx + perturb + 1);
  di = &d->array[idx & d->mask];
  if (di->flags == 0) return freeitem == NULL ? di : freeitem;
  if (di->hash == hash && di->flags != CDI_FLAG_DEL && d->keyType == &iobj__T ? d->eqfunc(&di->iokey, &key) : d->eqfunc(&di->key, &key)) return di;
  if (di->flags == CDI_FLAG_DEL && freeitem == NULL) freeitem = di;
 }
}

void ZDictResize(Td *d, int minitems) {
 CDictItem temparray[HT_INIT_SIZE];
 CDictItem *oldarray, *newarray;
 CDictItem *olditem, *newitem, *nextitem;
 int newi;
 int todo;
 Zhashtype oldsize, newsize;
 Zhashtype minsize;
 Zhashtype newmask;
 Zhashtype perturb;

#ifdef DICT_DEBUG
 printf("size: %lu, filled: %lu, used: %lu\n",
           d->mask + 1, d->filled, d->used);
#endif

 if (minitems == 0) {
  if (d->filled < HT_INIT_SIZE - 1 && d->array == d->smallArray) {
#ifdef DICT_DEBUG
   printf("small array not full\n");
#endif
   return;
  }
  oldsize = d->mask + 1;
  if (d->filled * 3 < oldsize * 2 && d->used > oldsize / 5) {
#ifdef DICT_DEBUG
   printf("size OK\n");
#endif
   return;
  }
  if (d->used > 1000) minsize = d->used * 2;
  else minsize = d->used * 4;
 } else {
  if ((Zhashtype)minitems < d->used) minitems = (int)d->used;
  minsize = minitems * 3 / 2;
 }

 newsize = HT_INIT_SIZE;
 while (newsize < minsize) {
  newsize <<= 1;
  if (newsize == 0) {
   ZthrowInternal(Zstr("ZDictResize"));
   return;
  }
 }

#ifdef DICT_DEBUG
 printf("resizing from %lu to %lu\n", d->mask + 1, newsize);
#endif

 if (newsize == HT_INIT_SIZE) {
  newarray = d->smallArray;
  if (d->array == newarray) {
   memmove(temparray, newarray, sizeof(temparray));
   oldarray = temparray;
  } else
   oldarray = d->array;
  memset(newarray, 0, (size_t)(sizeof(CDictItem) * newsize));
 } else {
  newarray = (CDictItem *)ZaOff((sizeof(CDictItem) * newsize));
  oldarray = d->array;
 }

 newmask = newsize - 1;
 todo = (int)d->used;
 for (olditem = oldarray; todo > 0; ++olditem)
  if (olditem->flags & CDI_FLAG_USED) {
   newi = (int)(olditem->hash & newmask);
   newitem = &newarray[newi];
   if (newitem->flags != 0)
    for (perturb = olditem->hash; ; perturb >>= PERTURB_SHIFT) {
     newi = (int)((newi << 2) + newi + perturb + 1);
     newitem = &newarray[newi & newmask];
     if (newitem->flags == 0) break;
    }
   *newitem = *olditem;
   if (d->type & DTYPE_ORDERED) {
    olditem->lprev = newitem;
   }
   --todo;
  }
 if ((d->type & DTYPE_ORDERED) && d->first) {
  olditem = d->first;
  newitem = olditem->lprev;
  newitem->lprev = NULL;
  d->first = newitem;
  while (olditem->lnext) {
   olditem = olditem->lnext;
   nextitem = olditem->lprev;
   newitem->lnext = nextitem;
   newitem->lnext->lprev = newitem;
   newitem = nextitem;
  }
  newitem->lnext = NULL;
  d->last = newitem;
 }

 if (d->array != d->smallArray) Zfree((void*)d->array - ZOH_OFF);
 d->array = newarray;
 d->mask = newmask;
 d->filled = d->used;
}

/* "ow" is the overwrite flag.  When zero it's not allowed to overwrite an
 * existing entry. */
Td *ZDictAdd(int ow, Td *d, Tz key, Tz value) {
 Zhashtype hash = ZDictHash(d->keyType, key);
 CDictItem *di = ZDictLookup(d, key, hash);
#ifdef DICT_DEBUG
 if (d->keyType->nr >= 100)
   printf("Adding item %s\n", (Tc*)key.ptr);
 else
   printf("Adding item %lld\n", key.ival);
 if (key.ptr != NULL
     && (strcmp(key.ptr, "ENUM") == 0
         || strcmp(key.ptr, "Equal") == 0
         || strcmp(key.ptr, "EXIT") == 0))
   dumpdict(d);
#endif
 if (di->flags == 0 || di->flags == CDI_FLAG_DEL || ow) {
  if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
   ++d->used;
   if (di->flags == 0)
    ++d->filled;
  }
  di->hash = hash;
  if (d->keyType->nr == 391) {
   di->iokey = *(Tr*)key.ptr;
  } else if (d->keyType->nr >= 100) {
   if (di->flags == 0 || di->flags == CDI_FLAG_DEL) {
    di->key = key;
   }
  } else di->key = key;
  if (d->itemType->nr == 391)
   di->ioitem = *(Tr*)value.ptr;
  else
   di->item = value;
  di->flags = CDI_FLAG_USED;
  if (d->type & DTYPE_ORDERED) {
   di->lprev = d->last;
   if (d->last) d->last->lnext = di;
   else d->first = di;
   d->last = di;
   di->lnext = NULL;
  }

  ZDictResize(d, 0);
 } else {
  if (d->keyType->nr >= 100) ZthrowStringKeyExists(key, Zstr("dict.add(): "));
  ZthrowIntKeyExists(key, Zstr("dict.add(): "));
 }
 return d;
}
Td *ZDictAddIobjTz(int ow, Td *d, Tr key, Tz value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, value);
}
Td *ZDictAddTzIobj(int ow, Td *d, Tz key, Tr value) {
 return ZDictAdd(ow, d, key, (Tz)(void*)&value);
}
Td *ZDictAddIobjIobj(int ow, Td *d, Tr key, Tr value) {
 return ZDictAdd(ow, d, (Tz)(void*)&key, (Tz)(void*)&value);
}

#ifdef DICT_DEBUG
dumpdict(Td *d)
{
 int        todo = (int)d->used;
 CDictItem  *item;
 int        idx = 0;

 for (item = d->array; todo > 0; ++item) {
  if (item->flags & CDI_FLAG_USED) {
   printf("%2d: %s\n", idx, (Tc*)item->key.ptr);
   --todo;
  } else if (item->flags == 0) {
   printf("%2d: unused\n", idx);
  } else if (item->flags == CDI_FLAG_DEL) {
   printf("%2d: deleted\n", idx);
  } else {
   printf("%2d: invalid flags: %d\n", idx, item->flags);
  }
  ++idx;
 }
}
#endif


CDictItem *ZDictFind(Td *d, Tz key) {
 Zhashtype  hash = ZDictHash(d->keyType, key);
 CDictItem  *di = ZDictLookup(d, key, hash);
 if (di->flags & CDI_FLAG_USED) return di;
 return NULL;
}

Tr *ZDictGetIobjP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  static Tr dummy = {0, 0, 0};
  ZDictAdd(1, d, key, (Tz)(void*)&dummy);
  di = ZDictFind(d, key);
 }
 return &di->ioitem;
}

Tr ZDictGetIobj(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->ioitem;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return trZero;
}

Tr ZDictGetIobjDef(Td *d, Tz key, Tr def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->ioitem;
 return def;
}

void *ZDictGetPtrP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  ZDictAdd(1, d, key, (Tz)(void*)0);
  di = ZDictFind(d, key);
 }
 return &di->item.ptr;
}

void *ZDictGetPtr(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ptr;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return NULL;
}

Tb ZDictHas(Td *d, Tz key) {
 return (ZDictFind(d, key) != NULL);
}
Tb ZDictHasIobj(Td *d, Tr key) {
 return (ZDictFind(d, (Tz)(void*)&key) != NULL);
}
void ZDiToString(Td *d, int keyUseq, int itemUseq, CDictItem *di, Tg *ga) {
 if (d->keyType == &iobj__T)
  ZitemToString((Tt*)(di->iokey.table[0]), keyUseq, (Tz)di->iokey.ptr, ga);
 else
  ZitemToString(d->keyType, keyUseq, di->key, ga);
 ga_append(ga, ": ");
 if (d->itemType == &iobj__T)
  ZitemToString((Tt*)(di->ioitem.table[0]), keyUseq, (Tz)di->ioitem.ptr, ga);
 else
  ZitemToString(d->itemType, itemUseq, di->item, ga);
}

void ZDictToStringGa(Td *d, int keyUseq, int itemUseq, Tg *ga) {
 int first = 1;
 int todo = d->used;
 Tn *e = ZgetEnv();
 CDictItem *di;
 ga_append(ga, "[");
 if (todo == 0) {
  ga_append(ga, ":");  /* empty dictionary: [:] */
 } else if (e->tosNr == d->tosNr) {
  ga_append(ga, "recursive-dict");
 } else {
  d->tosNr = e->tosNr;
  if (d->type & DTYPE_ORDERED) {
   for (di = d->first; di; di = di->lnext) {
    if (first == 0) ga_append(ga, ", "); else first = 0;
    ZDiToString(d, keyUseq, itemUseq, di, ga);
   }
  } else {
   for (di = d->array; todo > 0; ++di) {
    if (di->flags & CDI_FLAG_USED) {
     --todo;
     if (first == 0) ga_append(ga, ", "); else first = 0;
     ZDiToString(d, keyUseq, itemUseq,di, ga);
    }
   }
  }
  d->tosNr = 0;
 }
 ga_append(ga, "]");
}

Tc *ZDictToString(Td *d, int keyUseq, int itemUseq) {
 Tg ga;
 Tc *r;
 if (d == NULL) return (Tc*)&ZNilString;
 ++ZgetEnv()->tosNr;
 ga.data = NULL;
 ga.used = 0;
 ZDictToStringGa(d, keyUseq, itemUseq, &ga);
 r = ZnewString(ga.data, ga.used);
 Zfree((void*)ga.data - ZOH_OFF);
 return r;
}

Tl *ZDictKeys(Td *d, int dn) {
 Tl *l;
 int todo;
 CDictItem *di;
 if (d == NULL) {
  if (dn) return NULL;
  ZthrowCstringNil("Invoking keys() on NIL dict");
 }
 l = ZnewList(d->keyType, d->used);
 if (d->type & DTYPE_ORDERED) {
  if (d->keyType == &iobj__T)
   for (di = d->first; di; di = di->lnext) {
    ZLaIobj(l, -1, di->iokey);
   }
  else
   for (di = d->first; di; di = di->lnext) {
    ZLa(l, -1, di->key);
   }
 } else {
  todo = d->used;
  for (di = d->array; todo > 0; ++di) {
   if (di->flags & CDI_FLAG_USED) {
    --todo;
    if (d->keyType == &iobj__T)
     ZLaIobj(l, -1, di->iokey);
    else
     ZLa(l, -1, di->key);
   }
  }
 }
 return l;
}

Ti ZDictSize(Td *d) {
 if (d == NULL) return 0;
 return d->used;
}

Tcode *ZtableIndex(Ti pos100) {
 Ti pos = pos100 / 100;
 int l = 0;
 int h = sizeof(ZcodeTable)/sizeof(Tcode) - 1;
 int m;
 while (l <= h) {
  m = (l + h) / 2;
  if (ZcodeTable[m].offset == pos) break;
  if (ZcodeTable[m].offset < pos) l = m + 1;
  else h = m - 1;
 }
 return &ZcodeTable[m];
}
YkxB *MZ__callerPos(void) {
 Tcode *p;
 Zsf *tf = ZgetEnv()->topFrame;
 if (tf == NULL) return NULL;
 tf = tf->prev == NULL ? tf : tf->prev;
 while (1) {
  if (tf == NULL) return NULL;
  if (tf->pos & POS_MASK) {
   p = ZtableIndex(tf->pos & POS_MASK);
   if (p->fileName) {
    return MZ__posnr2pos(NULL, tf->pos & POS_MASK);
   }
  }
  tf = tf->prev;
 }
}

Tl *MZ__backtrace(Ti skip, Ti limit) {
 Tl *head = ZnewList((Tt*)&YkxB__T, 0);
 int done = 0;
 Zsf *tf = ZgetEnv()->topFrame;
 if (skip > 0) {
  int i;
  for (i = 0; i < skip && tf != NULL; ++i) tf = tf->prev;
 }
 while (tf != NULL) {
  if (tf->pos & POS_MASK) {
   YkxB *item = Za(sizeof(YkxB));
   if (limit >= 0 && done >= limit) {
    item->Vfilename = Zstr("truncated");
    ZLa(head, -1, (Tz)(void*)item);
    break;
   }
   MZ__posnr2pos(item, tf->pos & POS_MASK);
   ZLa(head, -1, (Tz)(void*)item);
   ++done;
  }
  tf = tf->prev;
 }
 return head;
}

YkxB *MZ__posnr2pos(YkxB *t, Ti pos) {
 int i;
 Tcode *p;
 Tcpos *pp;
 if (t == NULL) t = Za(sizeof(YkxB));
 p = ZtableIndex(pos);
 i = pos - p->offset * 100;
 pp = &p->table[i];
 t->Vfilename = Zstr((char*)p->fileName);
 t->Vtext = Zstr((char*)p->methodName);
 t->Vlnum = pp->line;
 if (i) t->Vlnum += p->table[0].line;
 t->Vcol = pp->col;
 return t;
}
/*
 * FUNCTION BODIES
 */
/* including SYSModule bodies */
Zfo Yhy5fo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yhy5(Tc *Aname) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yhy5fo[0].off = (void*)&sf - (void*)&Aname;
  Yhy5fo[1].off = (void*)&sf - (void*)&Vres;
 }
 sf.frof = Yhy5fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4232300;
 Vres = (Tc*)getenv(ZgetCstring(Aname));
 if (Vres != NULL) Vres = Zstr((char*)Vres);
 sf.pos=4232301;
 r = Vres;
 e->topFrame = sf.prev;
 return r;
}
/* SYSModule done */
/* including EModule bodies */
Zfo YRHRfo[3] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&string__T},{0,0}};
Ytlm *YRHR(Ytlm *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRHRfo[0].off = (void*)&sf - (void*)&t;
  YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8303100; t = Za(sizeof(Ytlm));}
 sf.pos=8303101;
 t->Vmessage = Amsg;
 sf.pos=8303102;
 t->Vpos = MZ__callerPos();
 sf.pos=8303103;
 t->Vbacktrace = (sf.pos=8303104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YH0Vfo[4] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YH0V(Ytlm *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5153500;
  ZthrowThisNil();
 }
 sf.pos=5153501;
 Vw = Za(sizeof(YjUM));
 sf.pos=5153502;
 YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5153503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YxaJfo[3] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&iobj__T},{0,0}};
void YxaJ(Ytlm *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJfo[0].off = (void*)&sf - (void*)&t;
  YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4918300;
  ZthrowThisNil();
 }
 sf.pos=4918301;
 if ((t->Vpos != NULL))
 {
  sf.pos=4918302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4918303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4918304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4918305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4918306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4918307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Yowwfo[4] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yoww(Ytlm *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9713500;
  ZthrowThisNil();
 }
 sf.pos=9713501;
 Vw = Za(sizeof(YjUM));
 sf.pos=9713502;
 YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9713503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YxaJafo[5] = {{0,(Tt*)&Ytlm__T},{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,0}};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YxaJafo[0].off = (void*)&sf - (void*)&t;
  YxaJafo[1].off = (void*)&sf - (void*)&Zf2;
  YxaJafo[2].off = (void*)&sf - (void*)&Aw;
  YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3649100;
  ZthrowThisNil();
 }
 sf.pos=3649101;
 YxaJ(t, Aw);
 sf.pos=3649102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3649103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3649104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3649105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3649106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3649107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3649108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3649109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3649110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3649111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3649112;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Ytlm__Ytlm_I_imt[] = {
 (Tc*)&Ytlm__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CException.NEW - YRHRa */
 (Tc*)YRHR, /* MEModule__CException.NEW - YRHR */
 (Tc*)YH0V, /* MEModule__CException.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CException.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CException.writeTo - YxaJ */
 (Tc*)Yoww, /* MEModule__CException.toString - Yoww */
 (Tc*)0, /* MEModule__CException.getMessage - YCzX */
 (Tc*)0, /* MEModule__CException.getPos - YvCK */
 (Tc*)0, /* MEModule__CException.getBacktrace - Y4bq */
 (Tc*)0, /* Init - Ytlma */
};
To ToYtlm[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYtlm[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Ytlm__T = {390, (Tc*)&YDGe, YH0V, StrYtlm, 0, 0, 0, 0, ToYtlm};
void YScq(Ti Apos, Tc *Atext) {
 Tr ex;
 Tr Ve = {NULL};
 Ve = Zao(YRHR(NULL, Atext), Ytlm__Ytlm_I_imt, 0);
 (*(YkxB**)(Ve.ptr + (size_t)Ve.table[2])) = MZ__posnr2pos(NULL, Apos);
 (ex = Ve);
 ZthrowIobject(ex);
}
Zfo YE2cfo[2] = {{0,(Tt*)&YEro__T},{0,0}};
YEro *YE2c(YEro *t, Ti Avalue) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YE2cfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YE2cfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3189000; t = Za(sizeof(YEro));}
 sf.pos=3189001;
 t->Vvalue = Avalue;
 sf.pos=3189002;
 t->Vmessage = ZcS(((Tc*)&YxJ1), Zint2string(Avalue));
 sf.pos=3189003;
 t->Vbacktrace = (sf.pos=3189004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Ydtuafo[4] = {{0,(Tt*)&YEro__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Ydtua(YEro *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ydtuafo[0].off = (void*)&sf - (void*)&t;
  Ydtuafo[1].off = (void*)&sf - (void*)&Vw;
  Ydtuafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Ydtuafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1893400;
  ZthrowThisNil();
 }
 sf.pos=1893401;
 Vw = Za(sizeof(YjUM));
 sf.pos=1893402;
 YXHSa(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1893403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YXHSafo[3] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,0}};
void YXHSa(YEro *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXHSafo[0].off = (void*)&sf - (void*)&t;
  YXHSafo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXHSafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9216300;
  ZthrowThisNil();
 }
 sf.pos=9216301;
 if ((t->Vpos != NULL))
 {
  sf.pos=9216302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9216303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9216304;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YxJ1));
 sf.pos=9216305;
 ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Zint2string(t->Vvalue));
 sf.pos=9216306;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9216307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
  sf.pos=9216308;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YEro__Yowwfo[4] = {{0,(Tt*)&YEro__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YEro__Yoww(YEro *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEro__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YEro__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YEro__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YEro__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9468900;
  ZthrowThisNil();
 }
 sf.pos=9468901;
 Vw = Za(sizeof(YjUM));
 sf.pos=9468902;
 YEro__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9468903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YEro__YxaJafo[5] = {{0,(Tt*)&YEro__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEro__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YEro__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YEro__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YEro__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YEro__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4298300;
  ZthrowThisNil();
 }
 sf.pos=4298301;
 YXHSa(t, Aw);
 sf.pos=4298302;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4298303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4298304;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4298305;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4298306;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4298307;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4298308;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4298309;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4298310;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4298311;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4298312;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YEro__Ytlm_I_imt[] = {
 (Tc*)&YEro__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHRa */
 (Tc*)0, /* MEModule__CExit.NEW - YEro__YRHR */
 (Tc*)Ydtua, /* MEModule__CExit.ToString - Ydtua */
 (Tc*)YEro__YxaJa, /* MEModule__CExit.writeTo - YEro__YxaJa */
 (Tc*)YXHSa, /* MEModule__CExit.writeTo - YXHSa */
 (Tc*)YEro__Yoww, /* MEModule__CExit.toString - YEro__Yoww */
 (Tc*)0, /* MEModule__CExit.getMessage - YEro__YCzX */
 (Tc*)0, /* MEModule__CExit.getPos - YEro__YvCK */
 (Tc*)0, /* MEModule__CExit.getBacktrace - YEro__Y4bq */
 (Tc*)0, /* Init - YEroa */
};
To ToYEro[] = {
 {4, 0},
 {0, (Tt*)&int__T}, /* value */
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYEro[] = {
 "value",
 "message",
 "pos",
 "backtrace",
};
Tto YEro__T = {390, (Tc*)&YJMo, Ydtua, StrYEro, 0, 0, 0, 0, ToYEro};
void YNab(YkxB *Apos, Ti Aval) {
 Tr ex;
 YEro *Ve = 0;
 Tr t0 = {NULL};
 Ve = YE2c(NULL, Aval);
 Ve->Vpos = Apos;
 *Znao(&ex, Ve, YEro__Ytlm_I_imt, 1);
 ZthrowIobject(ex);
}
Zfo YDNobfo[2] = {{0,(Tt*)&YKhn__T},{0,0}};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDNobfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YDNobfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Za(sizeof(YKhn));}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 e->topFrame = sf.prev;
 return t;
}
Zfo YKhn__YwtA__YH0Vfo[4] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YKhn__YwtA__YH0V(YKhn *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YKhn__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YKhn__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8669900;
  ZthrowThisNil();
 }
 sf.pos=8669901;
 Vw = Za(sizeof(YjUM));
 sf.pos=8669902;
 YKhn__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8669903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YKhn__YwtA__Yowwfo[4] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YKhn__YwtA__Yoww(YKhn *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YKhn__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YKhn__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9057100;
  ZthrowThisNil();
 }
 sf.pos=9057101;
 Vw = Za(sizeof(YjUM));
 sf.pos=9057102;
 YKhn__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9057103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YKhn__YwtA__YxaJafo[5] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YKhn__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YKhn__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YKhn__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1121700;
  ZthrowThisNil();
 }
 sf.pos=1121701;
 YKhn__YwtA__YxaJ(t, Aw);
 sf.pos=1121702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=1121703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=1121704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1121705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=1121706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=1121707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=1121708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=1121709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=1121710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=1121711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=1121712;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YKhn__YwtA__YxaJfo[3] = {{0,(Tt*)&YKhn__T},{0,(Tt*)&iobj__T},{0,0}};
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKhn__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YKhn__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YKhn__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2141800;
  ZthrowThisNil();
 }
 sf.pos=2141801;
 if ((t->Vpos != NULL))
 {
  sf.pos=2141802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=2141803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=2141804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=2141805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=2141806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=2141807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YKhn__Ytlm_I_imt[] = {
 (Tc*)&YKhn__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHRa */
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHR */
 (Tc*)YKhn__YwtA__YH0V, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
 (Tc*)YKhn__YwtA__YxaJa, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJa */
 (Tc*)YKhn__YwtA__YxaJ, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJ */
 (Tc*)YKhn__YwtA__Yoww, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfMemory.getMessage - YKhn__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfMemory.getPos - YKhn__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfMemory.getBacktrace - YKhn__YwtA__Y4bq */
 (Tc*)0, /* Init - YKhna */
};
To ToYKhn[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYKhn[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YKhn__T = {390, (Tc*)&Y9Fv, YKhn__YwtA__YH0V, StrYKhn, 0, 0, 0, 0, ToYKhn};
void Y1KV(Ti Asize) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Zfo Y1uN__YwtA__YRHRfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&string__T},{0,0}};
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y1uN__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Y1uN__YwtA__YH0Vfo[4] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y1uN__YwtA__YH0V(Y1uN *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Y1uN__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1uN__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2685400;
  ZthrowThisNil();
 }
 sf.pos=2685401;
 Vw = Za(sizeof(YjUM));
 sf.pos=2685402;
 Y1uN__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2685403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y1uN__YwtA__Yowwfo[4] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y1uN__YwtA__Yoww(Y1uN *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Y1uN__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1uN__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7911000;
  ZthrowThisNil();
 }
 sf.pos=7911001;
 Vw = Za(sizeof(YjUM));
 sf.pos=7911002;
 Y1uN__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7911003;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y1uN__YwtA__YxaJafo[5] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y1uN__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y1uN__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y1uN__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3508800;
  ZthrowThisNil();
 }
 sf.pos=3508801;
 Y1uN__YwtA__YxaJ(t, Aw);
 sf.pos=3508802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3508803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3508804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3508805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3508806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3508807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3508808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3508809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3508810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3508811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3508812;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y1uN__YwtA__YxaJfo[3] = {{0,(Tt*)&Y1uN__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1uN__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y1uN__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y1uN__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4528900;
  ZthrowThisNil();
 }
 sf.pos=4528901;
 if ((t->Vpos != NULL))
 {
  sf.pos=4528902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4528903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4528904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4528905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4528906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4528907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Y1uN__Ytlm_I_imt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHRa */
 (Tc*)Y1uN__YwtA__YRHR, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHR */
 (Tc*)Y1uN__YwtA__YH0V, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
 (Tc*)Y1uN__YwtA__YxaJa, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJa */
 (Tc*)Y1uN__YwtA__YxaJ, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJ */
 (Tc*)Y1uN__YwtA__Yoww, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
 (Tc*)0, /* MEModule__CNilAccess.getMessage - Y1uN__YwtA__YCzX */
 (Tc*)0, /* MEModule__CNilAccess.getPos - Y1uN__YwtA__YvCK */
 (Tc*)0, /* MEModule__CNilAccess.getBacktrace - Y1uN__YwtA__Y4bq */
 (Tc*)0, /* Init - Y1uNa */
};
To ToY1uN[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrY1uN[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Y1uN__T = {390, (Tc*)&Y4wO, Y1uN__YwtA__YH0V, StrY1uN, 0, 0, 0, 0, ToY1uN};
void YvdV(YkxB *Apos, Tc *Atext) {
 Tr ex;
 Y1uN *Ve = 0;
 Tr t0 = {NULL};
 Ve = Y1uN__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, Y1uN__Ytlm_I_imt, 5);
 ZthrowIobject(ex);
}
Zfo YAxe__YwtA__YRHRfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&string__T},{0,0}};
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YAxe__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YAxe__YwtA__YH0Vfo[4] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YAxe__YwtA__YH0V(YAxe *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YAxe__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YAxe__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6603600;
  ZthrowThisNil();
 }
 sf.pos=6603601;
 Vw = Za(sizeof(YjUM));
 sf.pos=6603602;
 YAxe__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6603603;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YAxe__YwtA__Yowwfo[4] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YAxe__YwtA__Yoww(YAxe *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YAxe__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YAxe__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1829200;
  ZthrowThisNil();
 }
 sf.pos=1829201;
 Vw = Za(sizeof(YjUM));
 sf.pos=1829202;
 YAxe__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1829203;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YAxe__YwtA__YxaJafo[5] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YAxe__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YAxe__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YAxe__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2595800;
  ZthrowThisNil();
 }
 sf.pos=2595801;
 YAxe__YwtA__YxaJ(t, Aw);
 sf.pos=2595802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2595803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2595804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2595805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2595806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2595807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2595808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2595809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2595810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2595811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2595812;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YAxe__YwtA__YxaJfo[3] = {{0,(Tt*)&YAxe__T},{0,(Tt*)&iobj__T},{0,0}};
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAxe__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YAxe__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YAxe__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3615900;
  ZthrowThisNil();
 }
 sf.pos=3615901;
 if ((t->Vpos != NULL))
 {
  sf.pos=3615902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=3615903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=3615904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=3615905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=3615906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=3615907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YAxe__Ytlm_I_imt[] = {
 (Tc*)&YAxe__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHRa */
 (Tc*)YAxe__YwtA__YRHR, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHR */
 (Tc*)YAxe__YwtA__YH0V, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
 (Tc*)YAxe__YwtA__YxaJa, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJa */
 (Tc*)YAxe__YwtA__YxaJ, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJ */
 (Tc*)YAxe__YwtA__Yoww, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
 (Tc*)0, /* MEModule__CMemoryAccess.getMessage - YAxe__YwtA__YCzX */
 (Tc*)0, /* MEModule__CMemoryAccess.getPos - YAxe__YwtA__YvCK */
 (Tc*)0, /* MEModule__CMemoryAccess.getBacktrace - YAxe__YwtA__Y4bq */
 (Tc*)0, /* Init - YAxea */
};
To ToYAxe[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYAxe[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YAxe__T = {390, (Tc*)&Y4QW, YAxe__YwtA__YH0V, StrYAxe, 0, 0, 0, 0, ToYAxe};
void YE93(Ti Anr) {
 Tr ex;
 Tr t0 = {NULL};
 if ((Anr == 11))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YkfG)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 if ((Anr == 8))
 {
  Tr ex;
  *Znao(&ex, YzSI__Ylz1__YwtA__YRHR(NULL, ((Tc*)&YoEx)), YzSI__Ytlm_I_imt, 17);
  ZthrowIobject(ex);
 }
 if ((Anr == 7))
 {
  Tr ex;
  *Znao(&ex, YAxe__YwtA__YRHR(NULL, ((Tc*)&YQNH)), YAxe__Ytlm_I_imt, 6);
  ZthrowIobject(ex);
 }
 *Znao(&ex, YAxe__YwtA__YRHR(NULL, ZcS(((Tc*)&YpCZ), Zint2string(Anr))), YAxe__Ytlm_I_imt, 6);
 ZthrowIobject(ex);
}
Zfo YVNj__YwtA__YRHRafo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,0}};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YRHRafo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YRHRafo[1].off = (void*)&sf - (void*)&Amsg;
  YVNj__YwtA__YRHRafo[2].off = (void*)&sf - (void*)&Apos;
 }
 sf.frof = YVNj__YwtA__YRHRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Za(sizeof(YVNj));}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YVNj__YwtA__YRHRfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&string__T},{0,0}};
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YVNj__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YVNj__YwtA__YH0Vfo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YVNj__YwtA__YH0V(YVNj *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YVNj__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YVNj__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8958100;
  ZthrowThisNil();
 }
 sf.pos=8958101;
 Vw = Za(sizeof(YjUM));
 sf.pos=8958102;
 YVNj__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8958103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YVNj__YwtA__Yowwfo[4] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YVNj__YwtA__Yoww(YVNj *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YVNj__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YVNj__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9345300;
  ZthrowThisNil();
 }
 sf.pos=9345301;
 Vw = Za(sizeof(YjUM));
 sf.pos=9345302;
 YVNj__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9345303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YVNj__YwtA__YxaJafo[5] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YVNj__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YVNj__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YVNj__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9610700;
  ZthrowThisNil();
 }
 sf.pos=9610701;
 YVNj__YwtA__YxaJ(t, Aw);
 sf.pos=9610702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=9610703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=9610704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=9610705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=9610706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=9610707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=9610708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=9610709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=9610710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=9610711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=9610712;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YVNj__YwtA__YxaJfo[3] = {{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVNj__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YVNj__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YVNj__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=630800;
  ZthrowThisNil();
 }
 sf.pos=630801;
 if ((t->Vpos != NULL))
 {
  sf.pos=630802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=630803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=630804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=630805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=630806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=630807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YVNj__Ytlm_I_imt[] = {
 (Tc*)&YVNj__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YVNj__YwtA__YRHRa, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)YVNj__YwtA__YH0V, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
 (Tc*)YVNj__YwtA__YxaJa, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJa */
 (Tc*)YVNj__YwtA__YxaJ, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJ */
 (Tc*)YVNj__YwtA__Yoww, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInit.getMessage - YVNj__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInit.getPos - YVNj__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInit.getBacktrace - YVNj__YwtA__Y4bq */
 (Tc*)0, /* Init - YVNja */
};
To ToYVNj[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYVNj[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YVNj__T = {390, (Tc*)&Ysqt, YVNj__YwtA__YH0V, StrYVNj, 0, 0, 0, 0, ToYVNj};
void Y3w6(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Zfo Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&string__T},{0,0}};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yalz__YwtA__YH0V(Yalz *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5270100;
  ZthrowThisNil();
 }
 sf.pos=5270101;
 Vw = Za(sizeof(YjUM));
 sf.pos=5270102;
 Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5270103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yalz__YwtA__Yoww(Yalz *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5657300;
  ZthrowThisNil();
 }
 sf.pos=5657301;
 Vw = Za(sizeof(YjUM));
 sf.pos=5657302;
 Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5657303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4617100;
  ZthrowThisNil();
 }
 sf.pos=4617101;
 Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=4617102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4617103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4617104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4617105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4617106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4617107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4617108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4617109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4617110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4617111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4617112;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yalz__T},{0,(Tt*)&iobj__T},{0,0}};
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5637200;
  ZthrowThisNil();
 }
 sf.pos=5637201;
 if ((t->Vpos != NULL))
 {
  sf.pos=5637202;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5637203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5637204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5637205;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5637206;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5637207;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Yalz__Ytlm_I_imt[] = {
 (Tc*)&Yalz__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHRa */
 (Tc*)Yalz__YwtA__YRHR, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHR */
 (Tc*)Yalz__YwtA__YH0V, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
 (Tc*)Yalz__YwtA__YxaJa, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJa */
 (Tc*)Yalz__YwtA__YxaJ, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJ */
 (Tc*)Yalz__YwtA__Yoww, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CBadValue.getMessage - Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CBadValue.getPos - Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CBadValue.getBacktrace - Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yalza */
};
To ToYalz[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYalz[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Yalz__T = {390, (Tc*)&YEZq, Yalz__YwtA__YH0V, StrYalz, 0, 0, 0, 0, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Zfo Yw3O__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&string__T},{0,0}};
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Yw3O__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yw3O__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yw3O__Yalz__YwtA__YH0V(Yw3O *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Yw3O__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yw3O__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3172900;
  ZthrowThisNil();
 }
 sf.pos=3172901;
 Vw = Za(sizeof(YjUM));
 sf.pos=3172902;
 Yw3O__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3172903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw3O__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Yw3O__Yalz__YwtA__Yoww(Yw3O *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Yw3O__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yw3O__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8398500;
  ZthrowThisNil();
 }
 sf.pos=8398501;
 Vw = Za(sizeof(YjUM));
 sf.pos=8398502;
 Yw3O__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8398503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw3O__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5260800;
  ZthrowThisNil();
 }
 sf.pos=5260801;
 if ((t->Vpos != NULL))
 {
  sf.pos=5260802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5260803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5260804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5260805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5260806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5260807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Yw3O__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Yw3O__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw3O__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Yw3O__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Yw3O__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Yw3O__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Yw3O__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6280900;
  ZthrowThisNil();
 }
 sf.pos=6280901;
 Yw3O__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=6280902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=6280903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=6280904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6280905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=6280906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=6280907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=6280908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=6280909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=6280910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=6280911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=6280912;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Yw3O__Ytlm_I_imt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHRa */
 (Tc*)Yw3O__Yalz__YwtA__YRHR, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHR */
 (Tc*)Yw3O__Yalz__YwtA__YH0V, /* MEModule__COutOfRange.ToString - Yw3O__Yalz__YwtA__YH0V */
 (Tc*)Yw3O__Yalz__YwtA__YxaJa, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJa */
 (Tc*)Yw3O__Yalz__YwtA__YxaJ, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJ */
 (Tc*)Yw3O__Yalz__YwtA__Yoww, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__COutOfRange.getMessage - Yw3O__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__COutOfRange.getPos - Yw3O__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__COutOfRange.getBacktrace - Yw3O__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Yw3Oa */
};
To ToYw3O[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYw3O[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Yw3O__T = {390, (Tc*)&YFK2, Yw3O__Yalz__YwtA__YH0V, StrYw3O, 0, 0, 0, 0, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Zfo Y2EX__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&string__T},{0,0}};
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y2EX__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo Y2EX__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2EX__Yalz__YwtA__YH0V(Y2EX *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  Y2EX__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2EX__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1566900;
  ZthrowThisNil();
 }
 sf.pos=1566901;
 Vw = Za(sizeof(YjUM));
 sf.pos=1566902;
 Y2EX__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1566903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2EX__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *Y2EX__Yalz__YwtA__Yoww(Y2EX *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  Y2EX__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y2EX__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6792500;
  ZthrowThisNil();
 }
 sf.pos=6792501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6792502;
 Y2EX__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6792503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y2EX__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4312400;
  ZthrowThisNil();
 }
 sf.pos=4312401;
 if ((t->Vpos != NULL))
 {
  sf.pos=4312402;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4312403;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4312404;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4312405;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4312406;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4312407;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y2EX__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&Y2EX__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y2EX__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  Y2EX__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  Y2EX__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  Y2EX__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = Y2EX__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5332500;
  ZthrowThisNil();
 }
 sf.pos=5332501;
 Y2EX__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=5332502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5332503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5332504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5332505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5332506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5332507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5332508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5332509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5332510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5332511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5332512;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *Y2EX__Ytlm_I_imt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHRa */
 (Tc*)Y2EX__Yalz__YwtA__YRHR, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHR */
 (Tc*)Y2EX__Yalz__YwtA__YH0V, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
 (Tc*)Y2EX__Yalz__YwtA__YxaJa, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJa */
 (Tc*)Y2EX__Yalz__YwtA__YxaJ, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJ */
 (Tc*)Y2EX__Yalz__YwtA__Yoww, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyNotFound.getMessage - Y2EX__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyNotFound.getPos - Y2EX__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyNotFound.getBacktrace - Y2EX__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - Y2EXa */
};
To ToY2EX[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrY2EX[] = {
 "message",
 "pos",
 "backtrace",
};
Tto Y2EX__T = {390, (Tc*)&YRiW, Y2EX__Yalz__YwtA__YH0V, StrY2EX, 0, 0, 0, 0, ToY2EX};
void Yxmk(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Ym6C), Zint2string(Akey))), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
void Y5LT(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Y2EX__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YJ3Y), Akey, ((Tc*)&YI), (Tc*)1)), Y2EX__Ytlm_I_imt, 12);
 ZthrowIobject(ex);
}
Zfo YX0i__Yalz__YwtA__YRHRfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&string__T},{0,0}};
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YX0i__Yalz__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YX0i__Yalz__YwtA__YH0Vfo[4] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YX0i__Yalz__YwtA__YH0V(YX0i *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YX0i__Yalz__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YX0i__Yalz__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5272800;
  ZthrowThisNil();
 }
 sf.pos=5272801;
 Vw = Za(sizeof(YjUM));
 sf.pos=5272802;
 YX0i__Yalz__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=5272803;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YX0i__Yalz__YwtA__Yowwfo[4] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YX0i__Yalz__YwtA__Yoww(YX0i *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YX0i__Yalz__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YX0i__Yalz__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=498400;
  ZthrowThisNil();
 }
 sf.pos=498401;
 Vw = Za(sizeof(YjUM));
 sf.pos=498402;
 YX0i__Yalz__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=498403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YX0i__Yalz__YwtA__YxaJfo[3] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1471500;
  ZthrowThisNil();
 }
 sf.pos=1471501;
 if ((t->Vpos != NULL))
 {
  sf.pos=1471502;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1471503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1471504;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1471505;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1471506;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1471507;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YX0i__Yalz__YwtA__YxaJafo[5] = {{0,(Tt*)&YX0i__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX0i__Yalz__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YX0i__Yalz__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YX0i__Yalz__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YX0i__Yalz__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YX0i__Yalz__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2491600;
  ZthrowThisNil();
 }
 sf.pos=2491601;
 YX0i__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2491602;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2491603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2491604;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2491605;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2491606;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2491607;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2491608;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2491609;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2491610;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2491611;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2491612;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YX0i__Ytlm_I_imt[] = {
 (Tc*)&YX0i__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHRa */
 (Tc*)YX0i__Yalz__YwtA__YRHR, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHR */
 (Tc*)YX0i__Yalz__YwtA__YH0V, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
 (Tc*)YX0i__Yalz__YwtA__YxaJa, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJa */
 (Tc*)YX0i__Yalz__YwtA__YxaJ, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJ */
 (Tc*)YX0i__Yalz__YwtA__Yoww, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CKeyExists.getMessage - YX0i__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CKeyExists.getPos - YX0i__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CKeyExists.getBacktrace - YX0i__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YX0ia */
};
To ToYX0i[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYX0i[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YX0i__T = {390, (Tc*)&Y9_h, YX0i__Yalz__YwtA__YH0V, StrYX0i, 0, 0, 0, 0, ToYX0i};
void YL9Z(Ti Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&Y9qa), Zint2string(Akey))), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
void YEeX(Tc *Akey, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YX0i__Yalz__YwtA__YRHR(NULL, ZcS5(Amsg, ((Tc*)&YMKM), Akey, ((Tc*)&YI), (Tc*)1)), YX0i__Ytlm_I_imt, 14);
 ZthrowIobject(ex);
}
Zfo YzSI__Ylz1__YwtA__YRHRfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&string__T},{0,0}};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YzSI__Ylz1__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YzSI__Ylz1__YwtA__YH0Vfo[4] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YzSI__Ylz1__YwtA__YH0V(YzSI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YzSI__Ylz1__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzSI__Ylz1__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1717900;
  ZthrowThisNil();
 }
 sf.pos=1717901;
 Vw = Za(sizeof(YjUM));
 sf.pos=1717902;
 YzSI__Ylz1__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1717903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YzSI__Ylz1__YwtA__Yowwfo[4] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YzSI__Ylz1__YwtA__Yoww(YzSI *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YzSI__Ylz1__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzSI__Ylz1__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6943500;
  ZthrowThisNil();
 }
 sf.pos=6943501;
 Vw = Za(sizeof(YjUM));
 sf.pos=6943502;
 YzSI__Ylz1__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=6943503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YzSI__Ylz1__YwtA__YxaJfo[3] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4413000;
  ZthrowThisNil();
 }
 sf.pos=4413001;
 if ((t->Vpos != NULL))
 {
  sf.pos=4413002;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4413003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4413004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4413005;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4413006;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4413007;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YzSI__Ylz1__YwtA__YxaJafo[5] = {{0,(Tt*)&YzSI__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzSI__Ylz1__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YzSI__Ylz1__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YzSI__Ylz1__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YzSI__Ylz1__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YzSI__Ylz1__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5433100;
  ZthrowThisNil();
 }
 sf.pos=5433101;
 YzSI__Ylz1__YwtA__YxaJ(t, Aw);
 sf.pos=5433102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=5433103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=5433104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=5433105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=5433106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=5433107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=5433108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=5433109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=5433110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=5433111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=5433112;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YzSI__Ytlm_I_imt[] = {
 (Tc*)&YzSI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHRa */
 (Tc*)YzSI__Ylz1__YwtA__YRHR, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHR */
 (Tc*)YzSI__Ylz1__YwtA__YH0V, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
 (Tc*)YzSI__Ylz1__YwtA__YxaJa, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJa */
 (Tc*)YzSI__Ylz1__YwtA__YxaJ, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJ */
 (Tc*)YzSI__Ylz1__YwtA__Yoww, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
 (Tc*)0, /* MEModule__CDivideByZero.getMessage - YzSI__Ylz1__YwtA__YCzX */
 (Tc*)0, /* MEModule__CDivideByZero.getPos - YzSI__Ylz1__YwtA__YvCK */
 (Tc*)0, /* MEModule__CDivideByZero.getBacktrace - YzSI__Ylz1__YwtA__Y4bq */
 (Tc*)0, /* Init - YzSIa */
};
To ToYzSI[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYzSI[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YzSI__T = {390, (Tc*)&YxFl, YzSI__Ylz1__YwtA__YH0V, StrYzSI, 0, 0, 0, 0, ToYzSI};
Zfo YXKl__YwtA__YRHRfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&string__T},{0,0}};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YXKl__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YXKl__YwtA__YH0Vfo[4] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YXKl__YwtA__YH0V(YXKl *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YXKl__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YXKl__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7993500;
  ZthrowThisNil();
 }
 sf.pos=7993501;
 Vw = Za(sizeof(YjUM));
 sf.pos=7993502;
 YXKl__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7993503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YXKl__YwtA__Yowwfo[4] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YXKl__YwtA__Yoww(YXKl *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YXKl__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YXKl__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3219100;
  ZthrowThisNil();
 }
 sf.pos=3219101;
 Vw = Za(sizeof(YjUM));
 sf.pos=3219102;
 YXKl__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3219103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YXKl__YwtA__YxaJafo[5] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YXKl__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YXKl__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YXKl__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8968500;
  ZthrowThisNil();
 }
 sf.pos=8968501;
 YXKl__YwtA__YxaJ(t, Aw);
 sf.pos=8968502;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8968503;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8968504;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8968505;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8968506;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8968507;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8968508;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8968509;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8968510;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8968511;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8968512;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YXKl__YwtA__YxaJfo[3] = {{0,(Tt*)&YXKl__T},{0,(Tt*)&iobj__T},{0,0}};
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXKl__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YXKl__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YXKl__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9988600;
  ZthrowThisNil();
 }
 sf.pos=9988601;
 if ((t->Vpos != NULL))
 {
  sf.pos=9988602;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9988603;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9988604;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9988605;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9988606;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9988607;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YXKl__Ytlm_I_imt[] = {
 (Tc*)&YXKl__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHRa */
 (Tc*)YXKl__YwtA__YRHR, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHR */
 (Tc*)YXKl__YwtA__YH0V, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
 (Tc*)YXKl__YwtA__YxaJa, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJa */
 (Tc*)YXKl__YwtA__YxaJ, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJ */
 (Tc*)YXKl__YwtA__Yoww, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIOError.getMessage - YXKl__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIOError.getPos - YXKl__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIOError.getBacktrace - YXKl__YwtA__Y4bq */
 (Tc*)0, /* Init - YXKla */
};
To ToYXKl[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYXKl[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YXKl__T = {390, (Tc*)&YTj3, YXKl__YwtA__YH0V, StrYXKl, 0, 0, 0, 0, ToYXKl};
void YkuV(Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YXKl__YwtA__YRHR(NULL, Amsg), YXKl__Ytlm_I_imt, 19);
 ZthrowIobject(ex);
}
Zfo YdhHfo[2] = {{0,(Tt*)&YuDC__T},{0,0}};
YuDC *YdhH(YuDC *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YdhHfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YdhHfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YuDC__YwtA__YH0Vfo[4] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YuDC__YwtA__YH0V(YuDC *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YuDC__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuDC__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1289600;
  ZthrowThisNil();
 }
 sf.pos=1289601;
 Vw = Za(sizeof(YjUM));
 sf.pos=1289602;
 YuDC__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1289603;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YuDC__YwtA__Yowwfo[4] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YuDC__YwtA__Yoww(YuDC *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YuDC__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuDC__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1676800;
  ZthrowThisNil();
 }
 sf.pos=1676801;
 Vw = Za(sizeof(YjUM));
 sf.pos=1676802;
 YuDC__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=1676803;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YuDC__YwtA__YxaJafo[5] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YuDC__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YuDC__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YuDC__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8681800;
  ZthrowThisNil();
 }
 sf.pos=8681801;
 YuDC__YwtA__YxaJ(t, Aw);
 sf.pos=8681802;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=8681803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=8681804;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=8681805;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=8681806;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=8681807;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=8681808;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=8681809;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=8681810;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=8681811;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=8681812;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YuDC__YwtA__YxaJfo[3] = {{0,(Tt*)&YuDC__T},{0,(Tt*)&iobj__T},{0,0}};
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuDC__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YuDC__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YuDC__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9701900;
  ZthrowThisNil();
 }
 sf.pos=9701901;
 if ((t->Vpos != NULL))
 {
  sf.pos=9701902;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=9701903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=9701904;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=9701905;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=9701906;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=9701907;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YuDC__Ytlm_I_imt[] = {
 (Tc*)&YuDC__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHR */
 (Tc*)YuDC__YwtA__YH0V, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
 (Tc*)YuDC__YwtA__YxaJa, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJa */
 (Tc*)YuDC__YwtA__YxaJ, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJ */
 (Tc*)YuDC__YwtA__Yoww, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
 (Tc*)0, /* MEModule__CWrongType.getMessage - YuDC__YwtA__YCzX */
 (Tc*)0, /* MEModule__CWrongType.getPos - YuDC__YwtA__YvCK */
 (Tc*)0, /* MEModule__CWrongType.getBacktrace - YuDC__YwtA__Y4bq */
 (Tc*)0, /* Init - YuDCa */
};
To ToYuDC[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYuDC[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YuDC__T = {390, (Tc*)&YCoZ, YuDC__YwtA__YH0V, StrYuDC, 0, 0, 0, 0, ToYuDC};
void YTuG(Ti Apos) {
 Tr ex;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
Zfo Y4iXafo[3] = {{0,(Tt*)&YqzO__T},{0,(Tt*)&string__T},{0,0}};
YqzO *Y4iXa(YqzO *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y4iXafo[0].off = (void*)&sf - (void*)&t;
  Y4iXafo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = Y4iXafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6177200; t = Za(sizeof(YqzO));}
 sf.pos=6177201;
 t->Vmessage = Amsg;
 sf.pos=6177202;
 t->Vpos = MZ__callerPos();
 sf.pos=6177203;
 t->Vbacktrace = (sf.pos=6177204, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YqzO__YwtA__YH0Vfo[4] = {{0,(Tt*)&YqzO__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YqzO__YwtA__YH0V(YqzO *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqzO__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YqzO__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YqzO__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YqzO__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4433300;
  ZthrowThisNil();
 }
 sf.pos=4433301;
 Vw = Za(sizeof(YjUM));
 sf.pos=4433302;
 YqzO__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=4433303;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YqzO__YwtA__Yowwfo[4] = {{0,(Tt*)&YqzO__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YqzO__YwtA__Yoww(YqzO *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqzO__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YqzO__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YqzO__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YqzO__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9658900;
  ZthrowThisNil();
 }
 sf.pos=9658901;
 Vw = Za(sizeof(YjUM));
 sf.pos=9658902;
 YqzO__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=9658903;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YqzO__YwtA__YxaJafo[5] = {{0,(Tt*)&YqzO__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YqzO__YwtA__YxaJa(YqzO *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqzO__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YqzO__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YqzO__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YqzO__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YqzO__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4506700;
  ZthrowThisNil();
 }
 sf.pos=4506701;
 YqzO__YwtA__YxaJ(t, Aw);
 sf.pos=4506702;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=4506703;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=4506704;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=4506705;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=4506706;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=4506707;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=4506708;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=4506709;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=4506710;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=4506711;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=4506712;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YqzO__YwtA__YxaJfo[3] = {{0,(Tt*)&YqzO__T},{0,(Tt*)&iobj__T},{0,0}};
void YqzO__YwtA__YxaJ(YqzO *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqzO__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YqzO__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YqzO__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5526800;
  ZthrowThisNil();
 }
 sf.pos=5526801;
 if ((t->Vpos != NULL))
 {
  sf.pos=5526802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=5526803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=5526804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=5526805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=5526806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=5526807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YqzO__Ytlm_I_imt[] = {
 (Tc*)&YqzO__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CThread.NEW - YqzO__YwtA__YRHRa */
 (Tc*)Y4iXa, /* MEModule__CThread.NEW - Y4iXa */
 (Tc*)YqzO__YwtA__YH0V, /* MEModule__CThread.ToString - YqzO__YwtA__YH0V */
 (Tc*)YqzO__YwtA__YxaJa, /* MEModule__CThread.writeTo - YqzO__YwtA__YxaJa */
 (Tc*)YqzO__YwtA__YxaJ, /* MEModule__CThread.writeTo - YqzO__YwtA__YxaJ */
 (Tc*)YqzO__YwtA__Yoww, /* MEModule__CThread.toString - YqzO__YwtA__Yoww */
 (Tc*)0, /* MEModule__CThread.getMessage - YqzO__YwtA__YCzX */
 (Tc*)0, /* MEModule__CThread.getPos - YqzO__YwtA__YvCK */
 (Tc*)0, /* MEModule__CThread.getBacktrace - YqzO__YwtA__Y4bq */
 (Tc*)0, /* Init - YqzOa */
};
To ToYqzO[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYqzO[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YqzO__T = {390, (Tc*)&YnY0, YqzO__YwtA__YH0V, StrYqzO, 0, 0, 0, 0, ToYqzO};
void YNbE(YkxB *Apos, Tc *Atext) {
 Tr ex;
 YqzO *Ve = 0;
 Tr t0 = {NULL};
 Ve = Y4iXa(NULL, Atext);
 Ve->Vpos = Apos;
 *Znao(&ex, Ve, YqzO__Ytlm_I_imt, 25);
 ZthrowIobject(ex);
}
Zfo YrHq__YwtA__YRHRfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&string__T},{0,0}};
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YrHq__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YrHq__YwtA__YH0Vfo[4] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YrHq__YwtA__YH0V(YrHq *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YrHq__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YrHq__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2761800;
  ZthrowThisNil();
 }
 sf.pos=2761801;
 Vw = Za(sizeof(YjUM));
 sf.pos=2761802;
 YrHq__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=2761803;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YrHq__YwtA__Yowwfo[4] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YrHq__YwtA__Yoww(YrHq *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YrHq__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YrHq__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7987400;
  ZthrowThisNil();
 }
 sf.pos=7987401;
 Vw = Za(sizeof(YjUM));
 sf.pos=7987402;
 YrHq__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=7987403;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YrHq__YwtA__YxaJafo[5] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YrHq__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YrHq__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YrHq__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=41200;
  ZthrowThisNil();
 }
 sf.pos=41201;
 YrHq__YwtA__YxaJ(t, Aw);
 sf.pos=41202;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=41203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=41204;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=41205;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=41206;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=41207;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=41208;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=41209;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=41210;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=41211;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=41212;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YrHq__YwtA__YxaJfo[3] = {{0,(Tt*)&YrHq__T},{0,(Tt*)&iobj__T},{0,0}};
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrHq__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YrHq__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YrHq__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1061300;
  ZthrowThisNil();
 }
 sf.pos=1061301;
 if ((t->Vpos != NULL))
 {
  sf.pos=1061302;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1061303;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1061304;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1061305;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1061306;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1061307;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YrHq__Ytlm_I_imt[] = {
 (Tc*)&YrHq__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHRa */
 (Tc*)YrHq__YwtA__YRHR, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHR */
 (Tc*)YrHq__YwtA__YH0V, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
 (Tc*)YrHq__YwtA__YxaJa, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJa */
 (Tc*)YrHq__YwtA__YxaJ, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJ */
 (Tc*)YrHq__YwtA__Yoww, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
 (Tc*)0, /* MEModule__CInternal.getMessage - YrHq__YwtA__YCzX */
 (Tc*)0, /* MEModule__CInternal.getPos - YrHq__YwtA__YvCK */
 (Tc*)0, /* MEModule__CInternal.getBacktrace - YrHq__YwtA__Y4bq */
 (Tc*)0, /* Init - YrHqa */
};
To ToYrHq[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYrHq[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YrHq__T = {390, (Tc*)&YVki, YrHq__YwtA__YH0V, StrYrHq, 0, 0, 0, 0, ToYrHq};
void YUSH(YkxB *Apos, Tc *Atext) {
 Tr ex;
 YrHq *Ve = 0;
 Tr t0 = {NULL};
 Ve = YrHq__YwtA__YRHR(NULL, Atext);
 if ((Apos != NULL))
 {
  Ve->Vpos = Apos;
 }
 *Znao(&ex, Ve, YrHq__Ytlm_I_imt, 26);
 ZthrowIobject(ex);
}
void YxIS(Tr Ae) {
      static int entered = 0;
      int didEnter = entered;
      entered = 1;
 if ((Ae).type == 1)
 {
  Ti VexitVal;
  VexitVal = ((YEro *)Znio(1, 1571802, (Ae)))->Vvalue;
  if (!didEnter) beforeExit();
  exit(VexitVal);
 }
 else
 {
  YvL0(Ae);
  if (!didEnter) beforeExit();
  exit(1);
 }
 return;
}
Zfo YvL0fo[2] = {{0,(Tt*)&iobj__T},{0,0}};
void YvL0(Tr Ae) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YvL0fo[0].off = (void*)&sf - (void*)&Ae;
 }
 sf.frof = YvL0fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238618;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 e->topFrame = sf.prev;
 return;
}
void YQar(Tr A0, Tb A1, Tr A2) {
 if (A0.ptr == NULL) ZthrowCstringNil("writeTo: object is NIL, cannot select method to invoke");
 if (A2.ptr == NULL) ZthrowCstringNil("writeTo: argument 2 is NIL, cannot select method to invoke");
 switch (A0.type) {
  case 0:
   YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238602)); return;
  case 1:
   YEro__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238603)); return;
  case 2:
   return;
  case 3:
   return;
  case 4:
   YKhn__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238604)); return;
  case 5:
   Y1uN__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238605)); return;
  case 6:
   YAxe__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238606)); return;
  case 7:
   YVNj__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238607)); return;
  case 8:
   return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 15:
   return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 25:
   YqzO__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 27:
   return;
  case 28:
   return;
  case 29:
   return;
  case 30:
   YgC4__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238617)); return;
  case 31:
   return;
  case 32:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including PIPEModule bodies */
Zfo YPsVfo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
YK7s *YPsV(YK7s *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YPsVfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YPsVfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6462200; t = Za(sizeof(YK7s));}
 sf.pos=6462201;
 t->VitemList = ZnewList((Tt*)&bool__T, 0);
 sf.pos=6462202;
 t->Vlock = YCyl(NULL);
 sf.pos=6462203;
 t->VreadCond = YXGL(NULL);
 sf.pos=6462204;
 t->VwriteCond = YXGL(NULL);
 sf.pos=6462205;
 t->VbufferSize = 1;
 sf.pos=6462206;
 t->VisOpen = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YWtyfo[2] = {{0,(Tt*)&YK7s__T},{0,0}};
Ts YWty(YK7s *t, Tb Aitem) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YWtyfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YWtyfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8236300;
  ZthrowThisNil();
 }
 sf.pos=8236301;
 YHl9(t->Vlock);
 sf.pos=8236302;
 while (1)
 {
  sf.pos=8236303;
  if (!(t->VisOpen))
  {
   sf.pos=8236304;
   Yvoo(t->Vlock);
   sf.pos=8236305;
   r = 0;
   rt = 1;
   goto YFdj;
  }
  sf.pos=8236306;
  if ((ZListSize(t->VitemList) < t->VbufferSize))
  {
   sf.pos=8236307;
   ZListInsert((Tl*)t->VitemList, 0, (Tz)(Ti)Aitem);
   rt = 2;
   goto YFdj;
  }
  sf.pos=8236308;
  YN6a(t->VwriteCond, t->Vlock);
YFdj:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto Ytc1;
 sf.pos=8236309;
 }
 sf.pos=8236310;
 Yvoo(t->Vlock);
 sf.pos=8236311;
 YjFj(t->VreadCond, 1);
 sf.pos=8236312;
 r = 1;
Ytc1:
 e->topFrame = sf.prev;
 return r;
}
To ToYK7s[] = {
 {6, 0},
 {0, (Tt*)&bool__T}, /* isOpen */
 {0, (Tt*)&int__T}, /* bufferSize */
 {0, (Tt*)&list__T}, /* itemList */
 {0, (Tt*)&YlXt__T}, /* lock */
 {0, (Tt*)&Y0Wo__T}, /* readCond */
 {0, (Tt*)&Y0Wo__T}, /* writeCond */
};
char *StrYK7s[] = {
 "isOpen",
 "bufferSize",
 "itemList",
 "lock",
 "readCond",
 "writeCond",
};
Tto YK7s__T = {390, (Tc*)&YLJT, 0, StrYK7s, 0, 0, 0, 0, ToYK7s};
Zfo YqaLfo[2] = {{0,(Tt*)&YJ7s__T},{0,0}};
YJ7s *YqaL(YJ7s *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqaLfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YqaLfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=1522300; t = Za(sizeof(YJ7s));}
 sf.pos=1522301;
 t->VitemList = ZnewList((Tt*)&string__T, 0);
 sf.pos=1522302;
 t->Vlock = YCyl(NULL);
 sf.pos=1522303;
 t->VreadCond = YXGL(NULL);
 sf.pos=1522304;
 t->VwriteCond = YXGL(NULL);
 sf.pos=1522305;
 t->VbufferSize = 1;
 sf.pos=1522306;
 t->VisOpen = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YQCOfo[2] = {{0,(Tt*)&YJ7s__T},{0,0}};
void YQCO(YJ7s *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YQCOfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YQCOfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8024300;
  ZthrowThisNil();
 }
 sf.pos=8024301;
 YHl9(t->Vlock);
 sf.pos=8024302;
 t->VisOpen = 0;
 sf.pos=8024303;
 Yvoo(t->Vlock);
 sf.pos=8024304;
 YjFj(t->VreadCond, 1);
 sf.pos=8024305;
 YjFj(t->VwriteCond, 1);
 e->topFrame = sf.prev;
 return;
}
Zfo YVE3fo[3] = {{0,(Tt*)&YJ7s__T},{0,(Tt*)&string__T},{0,0}};
Ts YVE3(YJ7s *t, Tc *Aitem) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YVE3fo[0].off = (void*)&sf - (void*)&t;
  YVE3fo[1].off = (void*)&sf - (void*)&Aitem;
 }
 sf.frof = YVE3fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6316400;
  ZthrowThisNil();
 }
 sf.pos=6316401;
 YHl9(t->Vlock);
 sf.pos=6316402;
 while (1)
 {
  sf.pos=6316403;
  if (!(t->VisOpen))
  {
   sf.pos=6316404;
   Yvoo(t->Vlock);
   sf.pos=6316405;
   r = 0;
   rt = 1;
   goto YEe7;
  }
  sf.pos=6316406;
  if ((ZListSize(t->VitemList) < t->VbufferSize))
  {
   sf.pos=6316407;
   ZListInsert((Tl*)t->VitemList, 0, (Tz)(void*)Aitem);
   rt = 2;
   goto YEe7;
  }
  sf.pos=6316408;
  YN6a(t->VwriteCond, t->Vlock);
YEe7:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YFEu;
 sf.pos=6316409;
 }
 sf.pos=6316410;
 Yvoo(t->Vlock);
 sf.pos=6316411;
 YjFj(t->VreadCond, 1);
 sf.pos=6316412;
 r = 1;
YFEu:
 e->topFrame = sf.prev;
 return r;
}
Zfo YNqffo[4] = {{0,(Tt*)&YJ7s__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YNqf(YJ7s *t, Ts *Rst) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vs = NULL;
 Tc *Vret = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YNqffo[0].off = (void*)&sf - (void*)&t;
  YNqffo[1].off = (void*)&sf - (void*)&Vs;
  YNqffo[2].off = (void*)&sf - (void*)&Vret;
 }
 sf.frof = YNqffo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3239300;
  ZthrowThisNil();
 }
 sf.pos=3239301;
 YHl9(t->Vlock);
 sf.pos=3239302;
 while (1)
 {
  sf.pos=3239303;
  if ((ZListSize(t->VitemList) > 0))
  {
   sf.pos=3239304;
   (*Rst) = 1;
   sf.pos=3239305;
   Vs = ZListRemovePtrItem((Tl*)t->VitemList, -1);
   sf.pos=3239306;
   Yvoo(t->Vlock);
   sf.pos=3239307;
   YjFj(t->VwriteCond, 0);
   sf.pos=3239308;
   r = Vs;
   rt = 1;
   goto Y6vt;
  }
  sf.pos=3239309;
  if (!(t->VisOpen))
  {
   sf.pos=3239310;
   (*Rst) = 0;
   rt = 2;
   goto Y6vt;
  }
  sf.pos=3239311;
  YN6a(t->VreadCond, t->Vlock);
Y6vt:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YSiV;
 sf.pos=3239312;
 }
 sf.pos=3239313;
 Yvoo(t->Vlock);
 sf.pos=3239314;
 r = Vret;
YSiV:
 e->topFrame = sf.prev;
 return r;
}
Zfo YNqfafo[2] = {{0,(Tt*)&YJ7s__T},{0,0}};
Tc *YNqfa(YJ7s *t) {
 Ts Vst;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YNqfafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YNqfafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=464500;
  ZthrowThisNil();
 }
 Vst = 0;
 sf.pos=464501;
 r = YNqf(t, &(Vst));
 e->topFrame = sf.prev;
 return r;
}
To ToYJ7s[] = {
 {6, 0},
 {0, (Tt*)&bool__T}, /* isOpen */
 {0, (Tt*)&int__T}, /* bufferSize */
 {0, (Tt*)&list__T}, /* itemList */
 {0, (Tt*)&YlXt__T}, /* lock */
 {0, (Tt*)&Y0Wo__T}, /* readCond */
 {0, (Tt*)&Y0Wo__T}, /* writeCond */
};
char *StrYJ7s[] = {
 "isOpen",
 "bufferSize",
 "itemList",
 "lock",
 "readCond",
 "writeCond",
};
Tto YJ7s__T = {390, (Tc*)&YMJT, 0, StrYJ7s, 0, 0, 0, 0, ToYJ7s};
/* PIPEModule done */
/* including TIMEModule bodies */
Ti Y9Rj() {
 Ti Vusec;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 e->topFrame = sf.prev;
 return r;
}
void YQzL(Ti Ausec) {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=9124700;
#ifdef __MINGW32__
    Sleep((int)((Ausec + 999) / 1000));
#else
    struct timespec tm;
    tm.tv_sec = Ausec / 1000000;
    tm.tv_nsec = (Ausec % 1000000) * 1000;
    nanosleep(&tm, NULL);
#endif
 e->topFrame = sf.prev;
 return;
}
/* TIMEModule done */
/* including HTTPModule bodies */
Zfo YF0Nfo[2] = {{0,(Tt*)&YSM1__T},{0,0}};
YSM1 *YF0N(YSM1 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YF0Nfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YF0Nfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=4664000; t = Za(sizeof(YSM1));}
 sf.pos=4664001;
 t->VheaderItems = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo YuPPfo[6] = {{0,(Tt*)&YSM1__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Tc *YuPP(YSM1 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vi = NULL;
 YjUM *Vw = 0;
 Tc *t0 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YuPPfo[0].off = (void*)&sf - (void*)&t;
  YuPPfo[1].off = (void*)&sf - (void*)&Zf1;
  YuPPfo[2].off = (void*)&sf - (void*)&Vi;
  YuPPfo[3].off = (void*)&sf - (void*)&Vw;
  YuPPfo[4].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YuPPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8466800;
  ZthrowThisNil();
 }
 sf.pos=8466801;
 Vw = Za(sizeof(YjUM));
 sf.pos=8466802;
 YjUM__YRt7(Vw, ZcS(((Tc*)&Y5wx), Zenum2string(MHTTPModule__ERequestType, t->Vtype)));
 sf.pos=8466803;
 YjUM__YRt7(Vw, ZcS(((Tc*)&YXBd), t->Vpath));
 sf.pos=8466804;
 YjUM__YRt7(Vw, ZcS(((Tc*)&YrAc), t->Vparams));
 sf.pos=8466805;
 YjUM__YRt7(Vw, ZcS(((Tc*)&Y1xf), t->VhttpVersion));
 sf.pos=8466806;
 YjUM__YRt7(Vw, ((Tc*)&YiH8));
 sf.pos=8466807;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys(t->VheaderItems, 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vi;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8466808;
  YjUM__YRt7(Vw, ZcS3(Vi, ((Tc*)&YFDa), (t0 = ((Tc *)ZDictGetPtr(t->VheaderItems, (Tz)(void*)Vi)))));
  sf.pos=8466809;
  }
 }
 sf.pos=8466810;
 if ((t->Vbody != NULL))
 {
  sf.pos=8466811;
  YjUM__YRt7(Vw, ZcS(((Tc*)&YLih), ZbyteStringCheckUtf8(t->Vbody)));
 }
 sf.pos=8466812;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
To ToYSM1[] = {
 {6, 0},
 {0, (Tt*)&MHTTPModule__ERequestType__T}, /* type */
 {0, (Tt*)&string__T}, /* path */
 {0, (Tt*)&string__T}, /* params */
 {0, (Tt*)&string__T}, /* httpVersion */
 {0, (Tt*)&dict__T}, /* headerItems */
 {0, (Tt*)&byteString__T}, /* body */
};
char *StrYSM1[] = {
 "type",
 "path",
 "params",
 "httpVersion",
 "headerItems",
 "body",
};
Tto YSM1__T = {390, (Tc*)&YFUt, YuPP, StrYSM1, 0, 0, 0, 0, ToYSM1};
Zfo YikNfo[2] = {{0,(Tt*)&YKeB__T},{0,0}};
YKeB *YikN(YKeB *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YikNfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YikNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3482200; t = Za(sizeof(YKeB));}
 sf.pos=3482201;
 t->Vcode = 200;
 sf.pos=3482202;
 t->Vmsg = ((Tc*)&Y0ab);
 sf.pos=3482203;
 t->VheaderItems = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
 sf.pos=3482204;
 YDSB(t, ((Tc*)&Ylqg));
 sf.pos=3482205;
 t->Vbody = ((Tc*)&YBMI);
 e->topFrame = sf.prev;
 return t;
}
Zfo YjIQfo[2] = {{0,(Tt*)&YKeB__T},{0,0}};
void YjIQ(YKeB *t, Ti Alength) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjIQfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjIQfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1487400;
  ZthrowThisNil();
 }
 sf.pos=1487401;
 *((Tc **)ZDictGetPtrP(t->VheaderItems, (Tz)(void*)((Tc*)&Y95C))) = ZcS(Zint2string(Alength), ((Tc*)&Ya));
 e->topFrame = sf.prev;
 return;
}
Zfo YDSBfo[3] = {{0,(Tt*)&YKeB__T},{0,(Tt*)&string__T},{0,0}};
void YDSB(YKeB *t, Tc *Atype) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDSBfo[0].off = (void*)&sf - (void*)&t;
  YDSBfo[1].off = (void*)&sf - (void*)&Atype;
 }
 sf.frof = YDSBfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8450600;
  ZthrowThisNil();
 }
 sf.pos=8450601;
 *((Tc **)ZDictGetPtrP(t->VheaderItems, (Tz)(void*)((Tc*)&YPoL))) = Atype;
 e->topFrame = sf.prev;
 return;
}
To ToYKeB[] = {
 {4, 0},
 {0, (Tt*)&int__T}, /* code */
 {0, (Tt*)&string__T}, /* msg */
 {0, (Tt*)&dict__T}, /* headerItems */
 {0, (Tt*)&string__T}, /* body */
};
char *StrYKeB[] = {
 "code",
 "msg",
 "headerItems",
 "body",
};
Tto YKeB__T = {390, (Tc*)&YhQB, 0, StrYKeB, 0, 0, 0, 0, ToYKeB};
Zfo Y89Zfo[5] = {{0,(Tt*)&YtzZ__T},{0,(Tt*)&YKeB__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&Y1QG__T},{0,0}};
YtzZ *Y89Z(YtzZ *t, Y1QG *Aserver, YSM1 *Arequest, YKeB *Aresponse) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y89Zfo[0].off = (void*)&sf - (void*)&t;
  Y89Zfo[1].off = (void*)&sf - (void*)&Aresponse;
  Y89Zfo[2].off = (void*)&sf - (void*)&Arequest;
  Y89Zfo[3].off = (void*)&sf - (void*)&Aserver;
 }
 sf.frof = Y89Zfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9162000; t = Za(sizeof(YtzZ));}
 sf.pos=9162001;
 t->Vserver = Aserver;
 sf.pos=9162002;
 t->Vrequest = Arequest;
 sf.pos=9162003;
 t->Vresponse = Aresponse;
 e->topFrame = sf.prev;
 return t;
}
To ToYtzZ[] = {
 {3, 0},
 {0, (Tt*)&Y1QG__T}, /* server */
 {0, (Tt*)&YSM1__T}, /* request */
 {0, (Tt*)&YKeB__T}, /* response */
};
char *StrYtzZ[] = {
 "server",
 "request",
 "response",
};
Tto YtzZ__T = {390, (Tc*)&Y36w, 0, StrYtzZ, 0, 0, 0, 0, ToYtzZ};
Zfo Yb5Kfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
YX8j *Yb5K(YX8j *t, Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yb5Kfo[0].off = (void*)&sf - (void*)&t;
  Yb5Kfo[1].off = (void*)&sf - (void*)&AfileName;
 }
 sf.frof = Yb5Kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9433600; t = Za(sizeof(YX8j));}
 sf.pos=9433601;
 t->Vname = ((Tc*)&YAkv);
 sf.pos=9433602;
 t->VfileName = AfileName;
 e->topFrame = sf.prev;
 return t;
}
Zfo YkIqfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
void YkIq(YX8j *t, Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YkIqfo[0].off = (void*)&sf - (void*)&t;
  YkIqfo[1].off = (void*)&sf - (void*)&AfileName;
 }
 sf.frof = YkIqfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5143400;
  ZthrowThisNil();
 }
 sf.pos=5143401;
 t->VfileName = AfileName;
 e->topFrame = sf.prev;
 return;
}
Zfo Y3hmafo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&YtzZ__T},{0,0}};
Tb Y3hma(YX8j *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y3hmafo[0].off = (void*)&sf - (void*)&t;
  Y3hmafo[1].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = Y3hmafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5386300;
  ZthrowThisNil();
 }
 sf.pos=5386301;
 Yl0k(ZcS5(((Tc*)&Y95j), Acontext->Vserver->VfileRoot, ((Tc*)&YV), t->VfileName, (Tc*)1));
 sf.pos=5386302;
 Acontext->Vresponse->Vbody = YDJh(ZcS3(Acontext->Vserver->VfileRoot, ((Tc*)&YV), t->VfileName));
 sf.pos=5386303;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YX8j__Y3fnfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
void YX8j__Y3fn(YX8j *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX8j__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YX8j__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YX8j__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5306300;
  ZthrowThisNil();
 }
 sf.pos=5306301;
 if ((t->Vpaths == NULL))
 {
  sf.pos=5306302;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=5306303;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YX8j__YU_Wfo[5] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YX8j__YU_W(YX8j *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YX8j__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YX8j__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YX8j__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YX8j__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YX8j__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3854500;
  ZthrowThisNil();
 }
 sf.pos=3854501;
 if ((t->Vpaths != NULL))
 {
  sf.pos=3854502;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3854503;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=3854504;
    if ((t->VmimeType != NULL))
    {
     sf.pos=3854505;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=3854506;
    if (Y3hma(t, Acontext))
    {
     sf.pos=3854507;
     r = 1;
     rt = 1;
     goto YzW5;
    }
YzW5:
    if (rt) goto YCxc;
   }
YCxc:
   if (rt) goto YIo4;
   sf.pos=3854508;
   }
  }
YIo4:
  if (rt) goto YENa;
 }
 sf.pos=3854509;
 r = 0;
YENa:
 e->topFrame = sf.prev;
 return r;
}
Zfo YX8j__YuzNfo[3] = {{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,0}};
void YX8j__YuzN(YX8j *t, Tc *Atype) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YX8j__YuzNfo[0].off = (void*)&sf - (void*)&t;
  YX8j__YuzNfo[1].off = (void*)&sf - (void*)&Atype;
 }
 sf.frof = YX8j__YuzNfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1160300;
  ZthrowThisNil();
 }
 sf.pos=1160301;
 t->VmimeType = Atype;
 e->topFrame = sf.prev;
 return;
}
Tc *YX8j__YtrZ_I_imt[] = {
 (Tc*)&YX8j__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YX8j__Y3fn, /* MHTTPModule__CFileServlet.addPath - YX8j__Y3fn */
 (Tc*)YX8j__YU_W, /* MHTTPModule__CFileServlet.handle - YX8j__YU_W */
 (Tc*)YX8j__YuzN, /* MHTTPModule__CFileServlet.setMimeType - YX8j__YuzN */
 (Tc*)Y3hma, /* MHTTPModule__CFileServlet.serve - Y3hma */
 (Tc*)0, /* Init - YX8ja */
};
To ToYX8j[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* fileName */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYX8j[] = {
 "fileName",
 "name",
 "paths",
 "mimeType",
};
Tto YX8j__T = {390, (Tc*)&YAkv, 0, StrYX8j, 0, 0, 0, 0, ToYX8j};
Zfo Y543fo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&string__T},{0,0}};
YIgO *Y543(YIgO *t, Tc *Abody) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y543fo[0].off = (void*)&sf - (void*)&t;
  Y543fo[1].off = (void*)&sf - (void*)&Abody;
 }
 sf.frof = Y543fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7215100; t = Za(sizeof(YIgO));}
 sf.pos=7215101;
 t->Vname = ((Tc*)&Y2iZ);
 sf.pos=7215102;
 t->Vbody = Abody;
 e->topFrame = sf.prev;
 return t;
}
Zfo Y6yefo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&string__T},{0,0}};
void Y6ye(YIgO *t, Tc *Abody) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y6yefo[0].off = (void*)&sf - (void*)&t;
  Y6yefo[1].off = (void*)&sf - (void*)&Abody;
 }
 sf.frof = Y6yefo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9643100;
  ZthrowThisNil();
 }
 sf.pos=9643101;
 t->Vbody = Abody;
 e->topFrame = sf.prev;
 return;
}
Zfo YqXRafo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&YtzZ__T},{0,0}};
Tb YqXRa(YIgO *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqXRafo[0].off = (void*)&sf - (void*)&t;
  YqXRafo[1].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = YqXRafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7684600;
  ZthrowThisNil();
 }
 sf.pos=7684601;
 Acontext->Vresponse->Vbody = t->Vbody;
 sf.pos=7684602;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YIgO__Y3fnfo[3] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&string__T},{0,0}};
void YIgO__Y3fn(YIgO *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YIgO__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YIgO__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YIgO__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7626200;
  ZthrowThisNil();
 }
 sf.pos=7626201;
 if ((t->Vpaths == NULL))
 {
  sf.pos=7626202;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=7626203;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YIgO__YU_Wfo[5] = {{0,(Tt*)&YIgO__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YIgO__YU_W(YIgO *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YIgO__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YIgO__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YIgO__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YIgO__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YIgO__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3178000;
  ZthrowThisNil();
 }
 sf.pos=3178001;
 if ((t->Vpaths != NULL))
 {
  sf.pos=3178002;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3178003;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=3178004;
    if ((t->VmimeType != NULL))
    {
     sf.pos=3178005;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=3178006;
    if (YqXRa(t, Acontext))
    {
     sf.pos=3178007;
     r = 1;
     rt = 1;
     goto YekN;
    }
YekN:
    if (rt) goto YzCH;
   }
YzCH:
   if (rt) goto YJ0k;
   sf.pos=3178008;
   }
  }
YJ0k:
  if (rt) goto Y6QF;
 }
 sf.pos=3178009;
 r = 0;
Y6QF:
 e->topFrame = sf.prev;
 return r;
}
Tc *YIgO__YtrZ_I_imt[] = {
 (Tc*)&YIgO__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YIgO__Y3fn, /* MHTTPModule__CStringServlet.addPath - YIgO__Y3fn */
 (Tc*)YIgO__YU_W, /* MHTTPModule__CStringServlet.handle - YIgO__YU_W */
 (Tc*)0, /* MHTTPModule__CStringServlet.setMimeType - YIgO__YuzN */
 (Tc*)YqXRa, /* MHTTPModule__CStringServlet.serve - YqXRa */
 (Tc*)0, /* Init - YIgOa */
};
To ToYIgO[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* body */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYIgO[] = {
 "body",
 "name",
 "paths",
 "mimeType",
};
Tto YIgO__T = {390, (Tc*)&Y2iZ, 0, StrYIgO, 0, 0, 0, 0, ToYIgO};
Zfo YDyefo[3] = {{0,(Tt*)&YzRH__T},{0,(Tt*)&cb__T},{0,0}};
YzRH *YDye(YzRH *t, Tcb *Afunc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDyefo[0].off = (void*)&sf - (void*)&t;
  YDyefo[1].off = (void*)&sf - (void*)&Afunc;
 }
 sf.frof = YDyefo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8898600; t = Za(sizeof(YzRH));}
 sf.pos=8898601;
 t->Vname = ((Tc*)&YEgW);
 sf.pos=8898602;
 t->VserveFunc = Afunc;
 e->topFrame = sf.prev;
 return t;
}
Zfo Y9y4afo[3] = {{0,(Tt*)&YzRH__T},{0,(Tt*)&YtzZ__T},{0,0}};
Tb Y9y4a(YzRH *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y9y4afo[0].off = (void*)&sf - (void*)&t;
  Y9y4afo[1].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = Y9y4afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3728100;
  ZthrowThisNil();
 }
 sf.pos=3728101;
 Acontext->Vresponse->Vbody = ((Tc* (*)(Tcb *, YtzZ*))t->VserveFunc->cfunc)((Tcb*)t->VserveFunc, Acontext);
 sf.pos=3728102;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YzRH__Y3fnfo[3] = {{0,(Tt*)&YzRH__T},{0,(Tt*)&string__T},{0,0}};
void YzRH__Y3fn(YzRH *t, Tc *Apath) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzRH__Y3fnfo[0].off = (void*)&sf - (void*)&t;
  YzRH__Y3fnfo[1].off = (void*)&sf - (void*)&Apath;
 }
 sf.frof = YzRH__Y3fnfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3553700;
  ZthrowThisNil();
 }
 sf.pos=3553701;
 if ((t->Vpaths == NULL))
 {
  sf.pos=3553702;
  t->Vpaths = ZnewList((Tt*)&string__T, 0);
 }
 sf.pos=3553703;
 ZLap((Tl*)t->Vpaths, (Tz)(void*)Apath);
 e->topFrame = sf.prev;
 return;
}
Zfo YzRH__YU_Wfo[5] = {{0,(Tt*)&YzRH__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tb YzRH__YU_W(YzRH *t, YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 Tl *Zf2 = NULL;
 Tc *Vp = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YzRH__YU_Wfo[0].off = (void*)&sf - (void*)&t;
  YzRH__YU_Wfo[1].off = (void*)&sf - (void*)&Acontext;
  YzRH__YU_Wfo[2].off = (void*)&sf - (void*)&Zf2;
  YzRH__YU_Wfo[3].off = (void*)&sf - (void*)&Vp;
 }
 sf.frof = YzRH__YU_Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1409900;
  ZthrowThisNil();
 }
 sf.pos=1409901;
 if ((t->Vpaths != NULL))
 {
  sf.pos=1409902;
  {
   Tfl Zf2i;
   Zf2 = t->Vpaths;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vp;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1409903;
   if ((ZstringCmp(Vp, Acontext->Vrequest->Vpath) == 0))
   {
    sf.pos=1409904;
    if ((t->VmimeType != NULL))
    {
     sf.pos=1409905;
     YDSB(Acontext->Vresponse, t->VmimeType);
    }
    sf.pos=1409906;
    if (Y9y4a(t, Acontext))
    {
     sf.pos=1409907;
     r = 1;
     rt = 1;
     goto YMWq;
    }
YMWq:
    if (rt) goto YFPB;
   }
YFPB:
   if (rt) goto YHWo;
   sf.pos=1409908;
   }
  }
YHWo:
  if (rt) goto YWRD;
 }
 sf.pos=1409909;
 r = 0;
YWRD:
 e->topFrame = sf.prev;
 return r;
}
Tc *YzRH__YtrZ_I_imt[] = {
 (Tc*)&YzRH__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YzRH__Y3fn, /* MHTTPModule__CFunctionServlet.addPath - YzRH__Y3fn */
 (Tc*)YzRH__YU_W, /* MHTTPModule__CFunctionServlet.handle - YzRH__YU_W */
 (Tc*)0, /* MHTTPModule__CFunctionServlet.setMimeType - YzRH__YuzN */
 (Tc*)Y9y4a, /* MHTTPModule__CFunctionServlet.serve - Y9y4a */
 (Tc*)0, /* Init - YzRHa */
};
To ToYzRH[] = {
 {4, 0},
 {0, (Tt*)&cb__T}, /* serveFunc */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&list__T}, /* paths */
 {0, (Tt*)&string__T}, /* mimeType */
};
char *StrYzRH[] = {
 "serveFunc",
 "name",
 "paths",
 "mimeType",
};
Tto YzRH__T = {390, (Tc*)&YEgW, 0, StrYzRH, 0, 0, 0, 0, ToYzRH};
Zfo YAvlfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Y1QG *YAvl(Y1QG *t, Ti Aport) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YAvlfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YAvlfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9633000; t = Y1QGa(NULL);}
 sf.pos=9633001;
 t->Vport = Aport;
 sf.pos=9633002;
 if ((t->Vport != 80))
 {
  sf.pos=9633003;
  t->Vbase =  ZcS(t->Vbase, ZcS(((Tc*)&Y5), Zint2string(t->Vport)));
 }
 sf.pos=9633004;
 t->VfileRoot = ZcS(YzHL(), ((Tc*)&Ycao));
 e->topFrame = sf.prev;
 return t;
}
Zfo Yj9Ofo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,0}};
void Yj9O(Y1QG *t, Tc *Aroot) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yj9Ofo[0].off = (void*)&sf - (void*)&t;
  Yj9Ofo[1].off = (void*)&sf - (void*)&Aroot;
 }
 sf.frof = Yj9Ofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3056400;
  ZthrowThisNil();
 }
 sf.pos=3056401;
 t->VfileRoot = Aroot;
 e->topFrame = sf.prev;
 return;
}
Zfo Yb8ifo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&iobj__T},{0,0}};
void Yb8i(Y1QG *t, Tr Aservlet) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yb8ifo[0].off = (void*)&sf - (void*)&t;
  Yb8ifo[1].off = (void*)&sf - (void*)&Aservlet;
 }
 sf.frof = Yb8ifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9865000;
  ZthrowThisNil();
 }
 sf.pos=9865001;
 ZLapIobj((Tl*)t->Vservlets, Aservlet);
 e->topFrame = sf.prev;
 return;
}
Zfo YVBUfo[20] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&YSM1__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YKeB__T},{0,(Tt*)&YtzZ__T},{0,(Tt*)&list__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
void YVBU(Y1QG *t) {
 Ti VlistenArg;
 Ti Vsi;
 Ti Vei;
 Ti Vqi;
 Ti Veol;
 Ti Vbol;
 Ti VbodySize;
 volatile Tb Vdone;
 Ti VrespLen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VreqString = NULL;
 YSM1 *Vreq = 0;
 Tc *Vmethod = NULL;
 Tc *Vparams = NULL;
 Tc *Vvers = NULL;
 Tc *VfieldName = NULL;
 Tc *VfieldValue = NULL;
 YKeB *Vresp = 0;
 volatile YtzZ *Vcontext = 0;
 Tl *Zf3 = NULL;
 volatile Tr Vservlet = {NULL};
 volatile Tr Ve = {NULL};
 Tc *VrespString = NULL;
 Tl *Zf1 = NULL;
 Tc *Vkey = NULL;
 YjUM *Vwriter = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YVBUfo[0].off = (void*)&sf - (void*)&t;
  YVBUfo[1].off = (void*)&sf - (void*)&VreqString;
  YVBUfo[2].off = (void*)&sf - (void*)&Vreq;
  YVBUfo[3].off = (void*)&sf - (void*)&Vmethod;
  YVBUfo[4].off = (void*)&sf - (void*)&Vparams;
  YVBUfo[5].off = (void*)&sf - (void*)&Vvers;
  YVBUfo[6].off = (void*)&sf - (void*)&VfieldName;
  YVBUfo[7].off = (void*)&sf - (void*)&VfieldValue;
  YVBUfo[8].off = (void*)&sf - (void*)&Vresp;
  YVBUfo[9].off = (void*)&sf - (void*)&Vcontext;
  YVBUfo[10].off = (void*)&sf - (void*)&Zf3;
  YVBUfo[11].off = (void*)&sf - (void*)&Vservlet;
  YVBUfo[12].off = (void*)&sf - (void*)&Ve;
  YVBUfo[13].off = (void*)&sf - (void*)&VrespString;
  YVBUfo[14].off = (void*)&sf - (void*)&Zf1;
  YVBUfo[15].off = (void*)&sf - (void*)&Vkey;
  YVBUfo[16].off = (void*)&sf - (void*)&Vwriter;
  YVBUfo[17].off = (void*)&sf - (void*)&t0;
  YVBUfo[18].off = (void*)&sf - (void*)&t1;
 }
 sf.frof = YVBUfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9936600;
  ZthrowThisNil();
 }
 sf.pos=9936601;
 VlistenArg = t->VlistenQueueLen;
 sf.pos=9936602;
 Yhx8();
 sf.pos=9936603;
#if defined(__MINGW32__) || defined(_MSC_VER)
      {
        static int did_init = 0;
        if (did_init == 0) {
          WSADATA wsadata;
          did_init = 1;
          if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
            fprintf(stderr, "Error in WSAStartup()\n");
            return;
          }
        }
      }
#endif
      int serv_fd;
      serv_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (serv_fd == -1) {
        perror("HTTP.Server socket()");
        return;
      }
      {
        int on = 1;
        if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR,
                                                     &on, sizeof(on)) == -1) {
          perror("HTTP.Server setsockopt()");
          return;
        }
      }
      {
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(struct sockaddr_in));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons((int)t->Vport);
        if (bind(serv_fd, (struct sockaddr *)&serv_addr,
                                                   sizeof(serv_addr)) == -1) {
          perror("HTTP.Server bind()");
          return;
        }
      }

      if (listen(serv_fd, VlistenArg) == -1) {
        perror("HTTP.Server listen()");
        return;
      }
      while (!t->VdidQuit) {
        struct sockaddr_in client_addr;
        int fd;
#define MAX_HEADER_SIZE 9100
        char req_string[MAX_HEADER_SIZE];
        socklen_t addr_len = sizeof(client_addr);
        int len;
 sf.pos=9936604;

        fd = accept(serv_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (fd == -1) {
          if (errno != EINTR) perror("HTTP.Server accept()");
          if (errno == EBADF || errno == EFAULT || errno == EINVAL) break;
          continue;
        }
        len = sckt_read(fd, req_string, MAX_HEADER_SIZE - 1);
        if (len <= 0) {
          if (len < 0) perror("HTTP.Server read header");
          continue;
        }
 sf.pos=9936605;
        req_string[len] = 0;
        VreqString = Zstr(req_string);
 sf.pos=9936606;
 Vreq = YF0N(NULL);
 sf.pos=9936607;
 Vsi = ZstringFindChar(VreqString, 32, 0);
 sf.pos=9936608;
 if ((Vsi < 0))
 {
  sf.pos=9936609;
          continue;
 }
 sf.pos=9936610;
 Vmethod = ZstringToLower(ZstringSlice(VreqString, 0, (Vsi - 1), 0));
 sf.pos=9936611;
 {
  Te Vt;
  Tfe Zf1;
  Zf1.count = 9;
  Zf1.idx = 0;
  for (ZforEnumGetEnum(&Zf1, &Vt); ZforEnumContEnum(&Zf1); ZforEnumNextEnum(&Zf1, &Vt)) {
  sf.pos=9936612;
  if ((ZstringCmp(Zenum2string(MHTTPModule__ERequestType, Vt), Vmethod) == 0))
  {
   sf.pos=9936613;
   Vreq->Vtype = Vt;
   rt = 2;
   goto Yj3e;
  }
Yj3e:
  if (rt == 2) { rt &= 1; break; }
  sf.pos=9936614;
  }
 }
 sf.pos=9936615;
 while ((ZstringGetChar(VreqString, Vsi) == 32))
 {
  sf.pos=9936616;
  ++(Vsi);
 sf.pos=9936617;
 }
 sf.pos=9936618;
 Vei = Vsi;
 sf.pos=9936619;
 while (((ZstringGetChar(VreqString, Vei) != 32) && (ZstringGetChar(VreqString, Vei) != 0)))
 {
  sf.pos=9936620;
  ++(Vei);
 sf.pos=9936621;
 }
 sf.pos=9936622;
 Vreq->Vpath = ZstringSlice(VreqString, Vsi, (Vei - 1), 0);
 sf.pos=9936623;
 Vqi = ZstringFindChar(Vreq->Vpath, 63, 0);
 sf.pos=9936624;
 if ((Vqi >= 0))
 {
  sf.pos=9936625;
  Vreq->Vparams = ZstringSlice(Vreq->Vpath, (Vqi + 1), -1, 0);
  sf.pos=9936626;
  Vreq->Vpath = ZstringSlice(Vreq->Vpath, 0, (Vqi - 1), 0);
 }
 sf.pos=9936627;
 while ((ZstringGetChar(VreqString, Vei) == 32))
 {
  sf.pos=9936628;
  ++(Vei);
 sf.pos=9936629;
 }
 sf.pos=9936630;
 Veol = ZstringFindChar2(VreqString, 10, Vei, 0);
 Vbol = 0;
 sf.pos=9936631;
 if ((Veol < 0))
 {
  sf.pos=9936632;
  Veol = (ZstringSize(VreqString) - 1);
  sf.pos=9936633;
  Vbol = Veol;
 }
 else
 {
  sf.pos=9936634;
  Vbol = (Veol + 1);
  sf.pos=9936635;
  --(Veol);
  sf.pos=9936636;
  if ((ZstringGetChar(VreqString, Veol) == 13))
  {
   sf.pos=9936637;
   --(Veol);
  }
 }
 sf.pos=9936638;
 Vreq->VhttpVersion = ZstringSlice(VreqString, Vei, Veol, 0);
 sf.pos=9936639;
 if ((t->Vverbosity != 0))
 {
  sf.pos=9936640;
  Vparams = ((Tc*)&Ya);
  sf.pos=9936641;
  if ((Vreq->Vparams != NULL))
  {
   sf.pos=9936642;
   Vparams = ZcS3(((Tc*)&Yj86), Vreq->Vparams, ((Tc*)&YN));
  }
  sf.pos=9936643;
  Vvers = ((Tc*)&Ya);
  sf.pos=9936644;
  if ((ZstringCmp(Vreq->VhttpVersion, ((Tc*)&Ye88)) != 0))
  {
   sf.pos=9936645;
   Vvers = ZcS3(((Tc*)&YmUM), Vreq->VhttpVersion, ((Tc*)&YN));
  }
  sf.pos=9936646;
  Yl0k(ZcS8(((Tc*)&YpFn), ZstringToUpper(Zenum2string(MHTTPModule__ERequestType, Vreq->Vtype)), ((Tc*)&Y5Y), (t0 = Vreq->Vpath), ((Tc*)&YN), Vparams, Vvers, (Tc*)1));
  sf.pos=9936647;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936648;
   Yl0k(ZcS3(((Tc*)&YUqj), VreqString, ((Tc*)&YN)));
  }
 }
 sf.pos=9936649;
 while (1)
 {
  Ti Vcolon;
  sf.pos=9936650;
  Veol = ZstringFindChar2(VreqString, 10, Vbol, 0);
  sf.pos=9936651;
  if ((Veol < 0))
  {
   sf.pos=9936652;
   Yl0k(((Tc*)&Yetr));
   sf.pos=9936653;
   Vbol = ZstringSize(VreqString);
   rt = 2;
   goto Yaoy;
  }
  sf.pos=9936654;
  if (((Veol == Vbol) || (((Veol == (Vbol + 1)) && (ZstringGetChar(VreqString, Vbol) == 13)))))
  {
   sf.pos=9936655;
   Vbol = (Veol + 1);
   rt = 2;
   goto Yaoy;
  }
  sf.pos=9936656;
  Vcolon = ZstringFindChar2(VreqString, 58, Vbol, 0);
  sf.pos=9936657;
  if ((Vcolon > 0))
  {
   Ti VfieldStart;
   sf.pos=9936658;
   VfieldName = ZstringToLower(ZstringSlice(VreqString, Vbol, (Vcolon - 1), 0));
   sf.pos=9936659;
   VfieldValue = ((Tc*)&Ya);
   sf.pos=9936660;
   VfieldStart = (Vcolon + 1);
   sf.pos=9936661;
   while (1)
   {
    Ti VfieldEnd;
    sf.pos=9936662;
    VfieldEnd = (Veol - 1);
    sf.pos=9936663;
    if ((ZstringGetChar(VreqString, VfieldEnd) == 13))
    {
     sf.pos=9936664;
     --(VfieldEnd);
    }
    sf.pos=9936665;
    while ((Y2jx(ZstringGetChar(VreqString, VfieldStart)) && (VfieldStart <= VfieldEnd)))
    {
     sf.pos=9936666;
     ++(VfieldStart);
    sf.pos=9936667;
    }
    sf.pos=9936668;
    while ((Y2jx(ZstringGetChar(VreqString, VfieldEnd)) && (VfieldEnd >= VfieldStart)))
    {
     sf.pos=9936669;
     --(VfieldEnd);
    sf.pos=9936670;
    }
    sf.pos=9936671;
    VfieldValue =  ZcS(VfieldValue, ZstringSlice(VreqString, VfieldStart, VfieldEnd, 0));
    sf.pos=9936672;
    if (!(Y2jx(ZstringGetChar(VreqString, (Veol + 1)))))
    {
     rt = 2;
     goto YU1X;
    }
    sf.pos=9936673;
    Vbol = (Veol + 1);
    sf.pos=9936674;
    Veol = ZstringFindChar2(VreqString, 10, Vbol, 0);
    sf.pos=9936675;
    if ((Veol < 0))
    {
     rt = 2;
     goto YU1X;
    }
    sf.pos=9936676;
    VfieldStart = (Vbol + 1);
    sf.pos=9936677;
    VfieldValue =  ZcS(VfieldValue, ((Tc*)&YG));
YU1X:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=9936678;
   }
   sf.pos=9936679;
   if (ZDictHas(Vreq->VheaderItems, (Tz)(void*)VfieldName))
   {
    sf.pos=9936680;
    VfieldValue = ZcS3(((Tc *)ZDictGetPtr(Vreq->VheaderItems, (Tz)(void*)VfieldName)), ((Tc*)&Ydha), VfieldValue);
   }
   sf.pos=9936681;
   *((Tc **)ZDictGetPtrP(Vreq->VheaderItems, (Tz)(void*)VfieldName)) = VfieldValue;
  }
  sf.pos=9936682;
  Vbol = (Veol + 1);
Yaoy:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9936683;
 }
 sf.pos=9936684;
 if ((t->Vverbosity == 2))
 {
  sf.pos=9936685;
  Yl0k(ZcS(((Tc*)&Y5UY), ZDictToString(Vreq->VheaderItems, 1, 1)));
 }
 sf.pos=9936686;
 VbodySize = 0;
 sf.pos=9936687;
 if (ZDictHas(Vreq->VheaderItems, (Tz)(void*)((Tc*)&YSBt)))
 {
  sf.pos=9936688;
  VbodySize = ZstringToInt(((Tc *)ZDictGetPtr(Vreq->VheaderItems, (Tz)(void*)((Tc*)&YSBt))), 1, 0);
  sf.pos=9936689;
  if ((t->Vverbosity != 0))
  {
   sf.pos=9936690;
   Yl0k(ZcS(((Tc*)&Y6Ov), Zint2string(VbodySize)));
  }
 }
 sf.pos=9936691;
 if ((VbodySize > 0))
 {
  sf.pos=9936692;
  Vwriter = Za(sizeof(YjUM));
  sf.pos=9936693;
  YJqza(Vwriter, ZstringSlice(VreqString, Vbol, -1, 0));
  sf.pos=9936694;
  while ((Yd3R(Vwriter) < VbodySize))
  {
   Ti Vlen;
   Vlen = 0;
   sf.pos=9936695;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936696;
    Yl0k(((Tc*)&YLqJ));
   }
   sf.pos=9936697;
            Vlen = sckt_read(fd, req_string, MAX_HEADER_SIZE - 1);
            if (Vlen > 0) {
              req_string[Vlen] = 0;
   sf.pos=9936698;
              VreqString = Zstr(req_string);
            }
   sf.pos=9936699;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936700;
    Yl0k(ZcS(((Tc*)&Ylp1), Zint2string(Vlen)));
   }
   sf.pos=9936701;
   if ((Vlen <= 0))
   {
    rt = 2;
    goto YAno;
   }
   sf.pos=9936702;
   YJqza(Vwriter, VreqString);
YAno:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=9936703;
  }
  sf.pos=9936704;
  Vreq->Vbody = YbNW(Vwriter);
  sf.pos=9936705;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936706;
   Yvcu(ZcS3(((Tc*)&YLih), Zint2string(ZbyteStringSize(Vreq->Vbody)), ((Tc*)&YrD_)));
   sf.pos=9936707;
   if ((ZbyteStringSize(Vreq->Vbody) > 1000))
   {
    sf.pos=9936708;
    Yl0k(ZstringSlice(ZbyteStringCheckUtf8(Vreq->Vbody), 0, 500, 0));
    sf.pos=9936709;
    Yl0k(((Tc*)&YKUO));
    sf.pos=9936710;
    Yvcu(ZstringSlice(ZbyteStringCheckUtf8(Vreq->Vbody), -500, -1, 0));
   }
   else
   {
    sf.pos=9936711;
    Yvcu(ZbyteStringCheckUtf8(Vreq->Vbody));
   }
   sf.pos=9936712;
   Yl0k(((Tc*)&YN));
  }
 }
 else
 {
  sf.pos=9936713;
  Vreq->Vbody = ((Tc*)&Ya);
 }
 sf.pos=9936714;
 t->Vbusy = 1;
 sf.pos=9936715;
 Vresp = YikN(NULL);
 Vdone = 0;
 sf.pos=9936716;
 Vcontext = Y89Z(NULL, t, Vreq, Vresp);
 sf.pos=9936717;
 {
  volatile int caught = 0;
  Tn *te = ZgetEnv();
  int try_index = te->tryCtxUsed;
  volatile int did_jump = 0;
  sf.pos=9936718;
  ZtryDeeper(te, &sf);
  if (setjmp(te->tryCtx[try_index].jmpBuf) != 0) {
   ++did_jump;
   e->topFrame = &sf;
  }
  if (did_jump == 0) /* TRY */
  {
   sf.pos=9936719;
   {
    Tfl Zf3i;
    Zf3 = t->Vservlets;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vservlet;
    Zf3i.i = 0;
    for (; ZforListIobjCont(&Zf3i); ) {
    sf.pos=9936720;
    if (((Tb (*)(void*, YtzZ*))(((Tr)Vservlet).table[5]))(((Tr)Vservlet).ptr, ((YtzZ*)Vcontext)))
    {
     sf.pos=9936721;
     Vdone = 1;
     rt = 2;
     goto YouY;
    }
YouY:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=9936722;
    }
   }
  }
  te->tryCtxUsed = try_index;
  if (did_jump == 1 && !caught && (ZTypeInRange((te->thrown[te->thrownUsed - 1]).type, 0, 32))) /* CATCH */
  {
   Ve = te->thrown[--te->thrownUsed];
   caught = 1;
   sf.pos=9936723;
   if ((t->Vverbosity == 2))
   {
    sf.pos=9936724;
    Yl0k(ZcS(((Tc*)&Y_P0), ((Tc* (*)(void*, Tb))(((Tr)Ve).table[9]))(((Tr)Ve).ptr, 1)));
   }
   else
   {
    sf.pos=9936725;
    Yl0k(ZcS(((Tc*)&Y_P0), ((Tc* (*)(void*))(((Tr)Ve).table[6]))(((Tr)Ve).ptr)));
   }
  }
  if ((did_jump == 1 && !caught) || did_jump > 1) Zrethrow();
 }
 sf.pos=9936726;
 if (!(Vdone))
 {
  sf.pos=9936727;
  Vresp->Vcode = 404;
  sf.pos=9936728;
  Vresp->Vmsg = ((Tc*)&Yytr);
  sf.pos=9936729;
  Vresp->Vbody = ((Tc*)&YaLI);
 }
 sf.pos=9936730;
 YjIQ(Vresp, ZstringSize(Vresp->Vbody));
 sf.pos=9936731;
 VrespString = ZcS5(((Tc*)&Y5E7), Zint2string(Vresp->Vcode), ((Tc*)&YG), (t0 = Vresp->Vmsg), ((Tc*)&Yau));
 VrespLen = 0;
 sf.pos=9936732;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys(Vresp->VheaderItems, 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vkey;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9936733;
  VrespString =  ZcS(VrespString, ZcS5(Vkey, ((Tc*)&YFDa), (t0 = ((Tc *)ZDictGetPtr(Vresp->VheaderItems, (Tz)(void*)Vkey))), ((Tc*)&Yau), (Tc*)1));
  sf.pos=9936734;
  }
 }
 sf.pos=9936735;
 VrespLen = ZstringSize(VrespString);
 sf.pos=9936736;
 if ((t->Vverbosity != 0))
 {
  sf.pos=9936737;
  Yl0k(ZcS(((Tc*)&YkHK), Zint2string(Vresp->Vcode)));
  sf.pos=9936738;
  if ((t->Vverbosity == 2))
  {
   sf.pos=9936739;
   Yl0k(ZcS(((Tc*)&Y5UY), ZDictToString(Vresp->VheaderItems, 1, 1)));
   sf.pos=9936740;
   Yvcu(((Tc*)&Y6wd));
   sf.pos=9936741;
   if ((ZstringSize(Vresp->Vbody) > 1000))
   {
    sf.pos=9936742;
    Yl0k(ZstringSlice(Vresp->Vbody, 0, 500, 0));
    sf.pos=9936743;
    Yl0k(((Tc*)&YKUO));
    sf.pos=9936744;
    Yvcu(ZstringSlice(Vresp->Vbody, -500, -1, 0));
   }
   else
   {
    sf.pos=9936745;
    Yvcu(Vresp->Vbody);
   }
   sf.pos=9936746;
   Yl0k(((Tc*)&YN));
  }
 }
 sf.pos=9936747;
        /* dummy loop so that we can use "break" to get to sckt_close() */
        for (;;) {
 sf.pos=9936748;
          char *s = ZgetCstring(VrespString);
 sf.pos=9936749;
          if (sckt_write(fd, s, (size_t)VrespLen) <= 0)
          {
            perror("HTTP.Server write header");
            break;
          }
 sf.pos=9936750;
 if ((Vreq->Vtype != 3))
 {
  sf.pos=9936751;
  VrespString = Vresp->Vbody;
  sf.pos=9936752;
  VrespLen = ZstringSize(VrespString);
  sf.pos=9936753;
            if (sckt_write(fd, "\r\n", 2) != 2) {
              perror("HTTP.Server write separator");
              break;
            }
  sf.pos=9936754;
            char *s = ZgetCstring(VrespString);
  sf.pos=9936755;
            if (VrespLen > 0 && sckt_write(fd, s, (size_t)VrespLen) <= 0)
            {
              perror("HTTP.Server write body");
              break;
            }
 }
 sf.pos=9936756;
          break;
        }
        sckt_close(fd);
 sf.pos=9936757;
 t->Vbusy = 0;
 sf.pos=9936758;
 if (t->VdidQuit)
 {
  sf.pos=9936759;
  YWty(t->VquitPipe, 1);
 }
 sf.pos=9936760;
     }  /* while */
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__Y7C8fo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&list__T},{0,0}};
void Y1QG__YTgs__Y7C8(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__Y7C8fo[0].off = (void*)&sf - (void*)&t;
  Y1QG__YTgs__Y7C8fo[1].off = (void*)&sf - (void*)&Zf1;
 }
 sf.frof = Y1QG__YTgs__Y7C8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3987700;
  ZthrowThisNil();
 }
 sf.pos=3987701;
 int i = 0;
 Zsf *prev = NULL;
 e->startFrames = calloc(1, ZListSize(t->Vstack) * sizeof(Zsf));
 sf.pos=3987702;
 {
  Ti Vpos;
  Tfl Zf1i;
  Zf1 = t->Vstack;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpos;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=3987703;
 e->startFrames[i].pos = Vpos;
 e->startFrames[i].prev = prev;
 prev = &e->startFrames[i];
 ++i;
  sf.pos=3987704;
  }
 }
 sf.pos=3987705;
 sf.prev = prev;
 sf.pos=3987706;
 pthread_mutex_lock(&threadsMutex);
 ZLa(threads, -1, (Tz)(void*)e);
 pthread_mutex_unlock(&threadsMutex);
 sf.pos=3987707;
 YVBU(t);

 e->finished = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__YSuwfo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&iobj__T},{0,0}};
void Y1QG__YTgs__YSuw(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__YSuwfo[0].off = (void*)&sf - (void*)&t;
  Y1QG__YTgs__YSuwfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y1QG__YTgs__YSuwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2210300;
  ZthrowThisNil();
 }
 sf.pos=2210301;
 Zsf *top = e->topFrame;
 sf.pos=2210302;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 sf.pos=2210303;
 while ((ZListSize(t->Vstack) < 30))
 {
  Ti Ventry;
  Ventry = 0;
  sf.pos=2210304;
  if (top == NULL) break;
  Ventry = top->pos;
  top = top->prev;
  sf.pos=2210305;
  ZListInsert((Tl*)t->Vstack, 0, (Tz)(Ti)Ventry);
 sf.pos=2210306;
 }
 sf.pos=2210307;
 if (pthread_create(&t->Vthread_id, NULL, (void *(*)(void *))Y1QG__YTgs__Y7C8, t) != 0) {
 sf.pos=2210308;
 if (1)
 {
  Tr ex;
  sf.pos=2210309;
  *Znao(&ex, YgC4__YwtA__YRHR(NULL, ((Tc*)&YgzQ)), YgC4__Ytlm_I_imt, 30);
  ZthrowIobject(ex);
 }
 sf.pos=2210310;
 }
 {
  int oldstate;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
 }
 sf.pos=2210311;
 t->Vstate = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__YSfifo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
void Y1QG__YTgs__YSfi(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__YSfifo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QG__YTgs__YSfifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2168200;
  ZthrowThisNil();
 }
 sf.pos=2168201;
 if (pthread_join(t->Vthread_id, NULL) != 0) {
 sf.pos=2168202;
  ZthrowThread(Zstr("wait()"));
 }
 sf.pos=2168203;
 t->Vstate = 2;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__YDFpfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
void Y1QG__YTgs__YDFp(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__YDFpfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QG__YTgs__YDFpfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=413300;
  ZthrowThisNil();
 }
 sf.pos=413301;
 if (pthread_cancel(t->Vthread_id) != 0) {
 sf.pos=413302;
  ZthrowThread(Zstr("kill()"));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QG__YTgs__Y2Czfo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Ts Y1QG__YTgs__Y2Cz(Y1QG *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YTgs__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QG__YTgs__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9628200;
  ZthrowThisNil();
 }
 sf.pos=9628201;
 pthread_detach(t->Vthread_id);
 sf.pos=9628202;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
void Y1QG__YcCua(Y1QG *t) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vproc != NULL))
 {
  ((void (*)(Tcb *))t->Vproc->cfunc)((Tcb*)t->Vproc);
 }
 return;
}
Zfo Y1QG__YqOJfo[3] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&cb__T},{0,0}};
void Y1QG__YqOJ(Y1QG *t, Tcb *Aproc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1QG__YqOJfo[0].off = (void*)&sf - (void*)&t;
  Y1QG__YqOJfo[1].off = (void*)&sf - (void*)&Aproc;
 }
 sf.frof = Y1QG__YqOJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1316700;
  ZthrowThisNil();
 }
 sf.pos=1316701;
 t->Vproc = Aproc;
 e->topFrame = sf.prev;
 return;
}
Zfo Y1QGafo[2] = {{0,(Tt*)&Y1QG__T},{0,0}};
Y1QG *Y1QGa(Y1QG *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (t == NULL) t = Za(sizeof(Y1QG));
 if (!sfF) {
  sfF = 1;
  Y1QGafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1QGafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3286400;
 t->VlistenQueueLen = 50;
 sf.pos=3286401;
 t->Vservlets = ZnewList((Tt*)&iobj__T, 0);
 sf.pos=3286402;
 t->Vbase = ((Tc*)&YoWK);
 sf.pos=3286403;
 t->Vverbosity = 1;
 sf.pos=3286404;
 t->VquitPipe = YPsV(NULL);
 e->topFrame = sf.prev;
 return t;
}
To ToY1QG[] = {
 {13, 0},
 {0, (Tt*)&int__T}, /* port */
 {0, (Tt*)&int__T}, /* listenQueueLen */
 {0, (Tt*)&list__T}, /* servlets */
 {0, (Tt*)&string__T}, /* fileRoot */
 {0, (Tt*)&string__T}, /* base */
 {0, (Tt*)&MHTTPModule__EVerbosity__T}, /* verbosity */
 {0, (Tt*)&YK7s__T}, /* quitPipe */
 {0, (Tt*)&bool__T}, /* didQuit */
 {0, (Tt*)&bool__T}, /* busy */
 {0, (Tt*)&cb__T}, /* proc */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrY1QG[] = {
 "port",
 "listenQueueLen",
 "servlets",
 "fileRoot",
 "base",
 "verbosity",
 "quitPipe",
 "didQuit",
 "busy",
 "proc",
 "name",
 "state",
 "stack",
};
Tto Y1QG__T = {390, (Tc*)&YooJ, 0, StrY1QG, 0, Y1QG__YTgs__Y2Cz, 0, 0, ToY1QG};
Tb Y2jx(Ti Ac) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7420000;
 r = ((Ac == 32) || (Ac == 9));
 e->topFrame = sf.prev;
 return r;
}
/* HTTPModule done */
/* including ZModule bodies */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
Zfo YpI_fo[3] = {{0,(Tt*)&YkxB__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YpI_(YkxB *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YpI_fo[0].off = (void*)&sf - (void*)&t;
  YpI_fo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YpI_fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1818700;
  ZthrowThisNil();
 }
 sf.pos=1818701;
 Vw = Za(sizeof(YjUM));
 sf.pos=1818702;
 if ((t->Vfilename == NULL))
 {
  sf.pos=1818703;
  YJqza(Vw, ((Tc*)&YKo1));
 }
 else
 {
  sf.pos=1818704;
  YJqza(Vw, t->Vfilename);
 }
 sf.pos=1818705;
 YJqza(Vw, ((Tc*)&YBpY));
 sf.pos=1818706;
 YjUM__YHhZb(Vw, t->Vlnum);
 sf.pos=1818707;
 YJqza(Vw, ((Tc*)&Y8ES));
 sf.pos=1818708;
 YjUM__YHhZb(Vw, t->Vcol);
 sf.pos=1818709;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
To ToYkxB[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&int__T}, /* lnum */
 {0, (Tt*)&int__T}, /* col */
 {0, (Tt*)&string__T}, /* text */
};
char *StrYkxB[] = {
 "filename",
 "lnum",
 "col",
 "text",
};
Tto YkxB__T = {390, (Tc*)&YBCs, YpI_, StrYkxB, 0, 0, 0, 0, ToYkxB};
/* ZModule done */
/* including STRINGModule bodies */
Zfo YO0wfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *YO0w(Tc *Athis) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YO0wfo[0].off = (void*)&sf - (void*)&Athis;
  YO0wfo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YO0wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4283400;
 if (Athis == NULL)
 {
  sf.pos=4283401;
  r = NULL;
  rt = 1;
  goto YX91;
 }
 sf.pos=4283402;
 Vw = Za(sizeof(YjUM));
 sf.pos=4283403;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew((ZstringSize(Athis) - 1), 0, 0, -1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=4283404;
  YjUM__Ydti(Vw, ZstringGetChar(Athis, Vi));
  sf.pos=4283405;
  }
 }
 sf.pos=4283406;
 r = YbNW(Vw);
YX91:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yvnffo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&YjUM__T},{0,0}};
Tc *Yvnf(Tc *Athis, Ti Afrom, Ti Ato) {
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yvnffo[0].off = (void*)&sf - (void*)&Athis;
  Yvnffo[1].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = Yvnffo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=1203500;
 if (Athis == NULL)
 {
  sf.pos=1203501;
  r = NULL;
  rt = 1;
  goto YIVu;
 }
 sf.pos=1203502;
 Vi = ZstringFindChar(Athis, Afrom, 0);
 sf.pos=1203503;
 if ((Vi >= 0))
 {
  Ti VnextChar;
  VnextChar = 0;
  sf.pos=1203504;
  Vw = Za(sizeof(YjUM));
  sf.pos=1203505;
  while ((Vi >= 0))
  {
   sf.pos=1203506;
   if ((Vi > VnextChar))
   {
    sf.pos=1203507;
    YJqza(Vw, ZstringSlice(Athis, VnextChar, (Vi - 1), 0));
   }
   sf.pos=1203508;
   YjUM__Ydti(Vw, Ato);
   sf.pos=1203509;
   VnextChar = (Vi + 1);
   sf.pos=1203510;
   Vi = ZstringFindChar2(Athis, Afrom, VnextChar, 0);
  sf.pos=1203511;
  }
  sf.pos=1203512;
  YJqza(Vw, ZstringSlice(Athis, VnextChar, -1, 0));
  sf.pos=1203513;
  r = YbNW(Vw);
  rt = 1;
  goto YIVu;
 }
 sf.pos=1203514;
 r = Athis;
YIVu:
 e->topFrame = sf.prev;
 return r;
}
/* STRINGModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(ZaF(sizeof(Yw8L), ToYw8L, (Ts (*)(void*, Te))YSo_, 1), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stderr;
 r = Vfile;
 return r;
}
Tc **YdXi__imtt[] = {
  Yw8L__YdXi_imt,
    0,
  YjUM__YdXi_imt,
    0,
};
Zfo YwHoafo[4] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YwHoafo[0].off = (void*)&sf - (void*)&t;
  YwHoafo[1].off = (void*)&sf - (void*)&Atext;
  YwHoafo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YwHoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9482300;
  ZthrowThisNil();
 }
 Vret = 0;
 sf.pos=9482301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=9482302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 sf.pos=9482303;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, t->Vfd) == 1)
   Vret = 1;
  else
   Vret = 0;
  }
 sf.pos=9482304;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YrF8fo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts YrF8(Yw8L *t) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YrF8fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YrF8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1575500;
  ZthrowThisNil();
 }
 sf.pos=1575501;
 Vret = 0;
 sf.pos=1575502;
 if ((t->Vfd != NULL))
 {
  sf.pos=1575503;
 if (fflush(t->Vfd) != 0) Vret = 0;
  sf.pos=1575504;
 if (fclose(t->Vfd) != 0) Vret = 0;
  sf.pos=1575505;
  t->Vfd = NULL;
 }
 sf.pos=1575506;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YSo_fo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts YSo_(Yw8L *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSo_fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YSo_fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4982200;
  ZthrowThisNil();
 }
 sf.pos=4982201;
 YrF8(t);
 sf.pos=4982202;
 r = 1;
 if (r) t->fok |= FOK_OK;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YHhZbfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YHhZbfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5981900;
  ZthrowThisNil();
 }
 sf.pos=5981901;
 r = YwHoa(t, Zint2string(Anumber));
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7fo[3] = {{0,(Tt*)&Yw8L__T},{0,(Tt*)&string__T},{0,0}};
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7fo[0].off = (void*)&sf - (void*)&t;
  Yw8L__YRt7fo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yw8L__YRt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6618800;
  ZthrowThisNil();
 }
 sf.pos=6618801;
 if (((YwHoa(t, Atext) == 1) && (YwHoa(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=6618802;
  r = 1;
  rt = 1;
  goto Y7Vd;
 }
 sf.pos=6618803;
 r = 0;
Y7Vd:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yw8L__YRt7gfo[2] = {{0,(Tt*)&Yw8L__T},{0,0}};
Ts Yw8L__YRt7g(Yw8L *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yw8L__YRt7gfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yw8L__YRt7gfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8261800;
  ZthrowThisNil();
 }
 sf.pos=8261801;
 r = YwHoa(t, ((Tc*)&Yk));
 e->topFrame = sf.prev;
 return r;
}
Tc *Yw8L__Yw8L_I_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZa */
 (Tc*)Yw8L__YHhZb, /* MIOModule__CFile.write - Yw8L__YHhZb */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZc */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZd */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZe */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZf */
 (Tc*)0, /* MIOModule__CFile.write - Yw8L__YHhZg */
 (Tc*)0, /* MIOModule__CFile.writeByte - YvfVa */
 (Tc*)0, /* MIOModule__CFile.writeChar - Yw8L__Ydti */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7a */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7b */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7c */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7d */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7e */
 (Tc*)0, /* MIOModule__CFile.print - Yw8L__YRt7f */
 (Tc*)Yw8L__YRt7g, /* MIOModule__CFile.print - Yw8L__YRt7g */
 (Tc*)0, /* MIOModule__CFile.format - Yw8L__YTPv */
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)0, /* MIOModule__CFile.readChar - YAPp */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyuma */
 (Tc*)0, /* MIOModule__CFile.readAll - Yyum */
 (Tc*)0, /* MIOModule__CFile.readAllBytes - YVfz */
 (Tc*)0, /* MIOModule__CFile.readLine - YaEh */
 (Tc*)0, /* MIOModule__CFile.readLineRaw - Yn2l */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1a */
 (Tc*)0, /* MIOModule__CFile.readAllLines - YCm1 */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWFa */
 (Tc*)0, /* MIOModule__CFile.readAllLinesRaw - YWWF */
 (Tc*)0, /* MIOModule__CFile.writeAllLines - YZFx */
 (Tc*)0, /* MIOModule__CFile.flush - YGmp */
 (Tc*)YrF8, /* MIOModule__CFile.close - YrF8 */
 (Tc*)YSo_, /* MIOModule__CFile.Finish - YSo_ */
 (Tc*)0, /* Init - Yw8La */
};
Tc *Yw8L__YdXi_imt[] = {
 (Tc*)&Yw8L__T,
 (Tc*)YwHoa, /* MIOModule__CFile.write - YwHoa */
 (Tc*)Yw8L__YRt7, /* MIOModule__CFile.print - Yw8L__YRt7 */
};
To ToYw8L[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* name */
};
char *StrYw8L[] = {
 "name",
};
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, StrYw8L, 0, YSo_, 0, 0, ToYw8L};
Ts Yhx8() {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3736300;
 Vret = 1;
 sf.pos=3736301;
#if defined(__MINGW32__) || defined(_MSC_VER)
      {
        static int did_init = 0;
        if (did_init == 0) {
          WSADATA wsadata;
          did_init = 1;
          if (WSAStartup(MAKEWORD(1,1), &wsadata) == SOCKET_ERROR) {
            fprintf(stderr, "Error in WSAStartup()\n");
            Vret = 0;
          }
        }
      }
#endif
 sf.pos=3736302;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YDJhfo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YDJh(Tc *AfileName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDJhfo[0].off = (void*)&sf - (void*)&AfileName;
  YDJhfo[1].off = (void*)&sf - (void*)&Vres;
 }
 sf.frof = YDJhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=745100;
 Vres = ((Tc*)&Ya);
 sf.pos=745101;
 {
  off_t len, rlen, off;
  int fd = open(ZgetCstring(AfileName), O_RDONLY, 0);
  Tc *resp;
  if (fd < 0) {
 sf.pos=745102;
 YkuV(ZcS(((Tc*)&YroP), AfileName));
 sf.pos=745103;
  }
  len = lseek(fd, 0, SEEK_END);
  if (len < 0) {
   close(fd);
 sf.pos=745104;
 YkuV(ZcS(((Tc*)&Y47X), AfileName));
 sf.pos=745105;
  }
  if (lseek(fd, 0, SEEK_SET) < 0) {
   close(fd);
 sf.pos=745106;
 YkuV(ZcS(((Tc*)&Y9TS), AfileName));
 sf.pos=745107;
  }
 sf.pos=745108;
  resp = ZaNm(len + 1);
  off = 0;
  while (len > 0) {
   rlen = read(fd, (char *)resp + off, len);
   if (rlen <= 0) {
    close(fd);
 sf.pos=745109;
 YkuV(ZcS(((Tc*)&YLjK), AfileName));
 sf.pos=745110;
   }
   len -= rlen;
   off += rlen;
  }
  resp[off] = 0;
  close(fd);
 sf.pos=745111;
 Vres = NULL;
 sf.pos=745112;
  Vres = ZnewString(resp, (Ti)off);
  free(resp);
 }
 sf.pos=745113;
 r = Vres;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yvcufo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yvcufo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yvcufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=8487000;
 {
  Tc *p;
  Ti len = ZstringSizePtr(Atext, &p);
  if (len == 0 || fwrite(p, (size_t)len, (size_t)1, stdout) == 1)
   Vret = 1;
  else
   Vret = 0;
 }
 sf.pos=8487001;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yl0kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yl0kfo[0].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = Yl0kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=187200;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=187201;
 if ((Vlen == 0 || fwrite(ZgetCstring(Atext), (size_t)Vlen, 1, stdout) == 1) && fputc('\n', stdout) >= 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=187202;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=4676101;
 r = Vret;
 e->topFrame = sf.prev;
 return r;
}
Zfo YJqzafo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJqzafo[0].off = (void*)&sf - (void*)&t;
  YJqzafo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = YJqzafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8998700;
  ZthrowThisNil();
 }
 sf.pos=8998701;
 Vlen = ZbyteStringSize(Atext);
 sf.pos=8998702;
 if ((t->Vs == NULL))
 {
  sf.pos=8998703;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), (Vlen + 30));
  sf.pos=8998704;
  Zas(t->Vs, Atext, 0, 0);
  sf.pos=8998705;
  t->VsLen = Vlen;
 }
 else
 {
  sf.pos=8998706;
  if ((((t->VsLen + Vlen) + 1) >= ZArraySize(t->Vs)))
  {
   sf.pos=8998707;
   ZarrayResize(t->Vs, sizeof(Tc), (((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + Vlen) + 50)) ;
  }
  sf.pos=8998708;
  Zas(t->Vs, Atext, 0, t->VsLen);
  sf.pos=8998709;
  t->VsLen += Vlen;
 }
 sf.pos=8998710;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo Yd3Rfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ti Yd3R(YjUM *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yd3Rfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yd3Rfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9533600;
  ZthrowThisNil();
 }
 sf.pos=9533601;
 r = t->VsLen;
 e->topFrame = sf.prev;
 return r;
}
Zfo YbNWfo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Tc *YbNW(YjUM *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YbNWfo[0].off = (void*)&sf - (void*)&t;
  YbNWfo[1].off = (void*)&sf - (void*)&Vr;
 }
 sf.frof = YbNWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6453100;
  ZthrowThisNil();
 }
 sf.pos=6453101;
 if ((t->Vs == NULL))
 {
  sf.pos=6453102;
  Vr = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=6453103;
  Vr = ZnewString(t->Vs->ptr, t->VsLen);
 }
 sf.pos=6453104;
 r = Vr;
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__YHhZbfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__YHhZbfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjUM__YHhZbfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7200700;
  ZthrowThisNil();
 }
 sf.pos=7200701;
 r = YJqza(t, Zint2string(Anumber));
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__Ydtifo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Ts YjUM__Ydti(YjUM *t, Ti Achar) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__Ydtifo[0].off = (void*)&sf - (void*)&t;
  YjUM__Ydtifo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YjUM__Ydtifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4928500;
  ZthrowThisNil();
 }
 sf.pos=4928501;
 if (((Achar < 0) || (Achar > 1114111)))
 {
  Tr ex;
  sf.pos=4928502;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&Yv8w), Zint2string(Achar))), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 sf.pos=4928503;
 r = YJqza(t, ZintAsString(Achar));
 e->topFrame = sf.prev;
 return r;
}
Zfo YjUM__YRt7fo[3] = {{0,(Tt*)&YjUM__T},{0,(Tt*)&string__T},{0,0}};
Ts YjUM__YRt7(YjUM *t, Tc *Atext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YjUM__YRt7fo[0].off = (void*)&sf - (void*)&t;
  YjUM__YRt7fo[1].off = (void*)&sf - (void*)&Atext;
 }
 sf.frof = YjUM__YRt7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2676000;
  ZthrowThisNil();
 }
 sf.pos=2676001;
 if (((YJqza(t, Atext) == 1) && (YJqza(t, ((Tc*)&Yk)) == 1)))
 {
  sf.pos=2676002;
  r = 1;
  rt = 1;
  goto Yvkn;
 }
 sf.pos=2676003;
 r = 0;
Yvkn:
 e->topFrame = sf.prev;
 return r;
}
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {3, 0},
 {0, (Tt*)&int__T}, /* sLen */
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
char *StrYjUM[] = {
 "sLen",
 "s",
 "x",
};
Tto YjUM__T = {390, (Tc*)&YE4c, YbNW, StrYjUM, 0, 0, 0, 0, ToYjUM};
Zfo Y_3Kfo[2] = {{0,(Tt*)&string__T},{0,0}};
Tb Y_3K(Tc *Aname) {
 Ti Vv;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y_3Kfo[0].off = (void*)&sf - (void*)&Aname;
 }
 sf.frof = Y_3Kfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vv = 0;
 sf.pos=7387700;
 Vv = access(ZgetCstring(Aname), X_OK);
 sf.pos=7387701;
 r = (Vv == 0);
 e->topFrame = sf.prev;
 return r;
}
Zfo Ycmifo[6] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,0}};
Tc *Ycmi(Tc *AexeName) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vexe = NULL;
 Tc *Vfname = NULL;
 Tl *Vdirectories = NULL;
 Tc *Vpath = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ycmifo[0].off = (void*)&sf - (void*)&AexeName;
  Ycmifo[1].off = (void*)&sf - (void*)&Vexe;
  Ycmifo[2].off = (void*)&sf - (void*)&Vfname;
  Ycmifo[3].off = (void*)&sf - (void*)&Vdirectories;
  Ycmifo[4].off = (void*)&sf - (void*)&Vpath;
 }
 sf.frof = Ycmifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6497000;
 Vexe = Yvnf(AexeName, 92, 47);
 sf.pos=6497001;
 if (((ZstringStartsWith(Vexe, ((Tc*)&YV), 0) || ZstringStartsWith(Vexe, ((Tc*)&YFka), 0)) || ZstringStartsWith(Vexe, ((Tc*)&Y0y2), 0)))
 {
  sf.pos=6497002;
  Vfname = Vexe;
 }
 else
 {
  sf.pos=6497003;
  Vpath = Yhy5(((Tc*)&Yykt));
  sf.pos=6497004;
  if ((Vpath != NULL))
  {
   sf.pos=6497005;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=6497006;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y6), 0);
   sf.pos=6497007;
#else
   sf.pos=6497008;
   Vdirectories = ZstringSplit(Vpath, ((Tc*)&Y5), 0);
   sf.pos=6497009;
#endif
  }
  sf.pos=6497010;
  Vfname = YDop(AexeName, Vdirectories);
  sf.pos=6497011;
#if defined(__MINGW32__) || defined(_MSC_VER)
  sf.pos=6497012;
  if (((Vfname == NULL) && !(ZstringEndsWith(ZstringToLower(AexeName), ((Tc*)&YpPR), 0))))
  {
   sf.pos=6497013;
   Vfname = YDop(ZcS(AexeName, ((Tc*)&YpPR)), Vdirectories);
  }
  sf.pos=6497014;
#endif
  sf.pos=6497015;
  if ((Vfname == NULL))
  {
   sf.pos=6497016;
   Vfname = Vexe;
   sf.pos=6497017;
#if defined(__MINGW32__) || defined(_MSC_VER)
   sf.pos=6497018;
   if ((!(Y_3K(Vfname)) && Y_3K(ZcS(Vfname, ((Tc*)&YpPR)))))
   {
    sf.pos=6497019;
    Vfname =  ZcS(Vfname, ((Tc*)&YpPR));
   }
   sf.pos=6497020;
#endif
  }
  else
  {
   sf.pos=6497021;
   Vfname = Yvnf(Vfname, 92, 47);
  }
 }
 sf.pos=6497022;
 r = YPjH(Vfname);
 e->topFrame = sf.prev;
 return r;
}
Zfo YDopfo[6] = {{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YDop(Tc *AexeName, Tl *Adirs) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tl *Zf1 = NULL;
 Tc *Vdir = NULL;
 Tc *Vfname = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YDopfo[0].off = (void*)&sf - (void*)&Adirs;
  YDopfo[1].off = (void*)&sf - (void*)&AexeName;
  YDopfo[2].off = (void*)&sf - (void*)&Zf1;
  YDopfo[3].off = (void*)&sf - (void*)&Vdir;
  YDopfo[4].off = (void*)&sf - (void*)&Vfname;
 }
 sf.frof = YDopfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8617600;
 {
  Tfl Zf1i;
  Zf1 = Adirs;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdir;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8617601;
  Vfname = Yq8a(Vdir, AexeName);
  sf.pos=8617602;
  if (Y_3K(Vfname))
  {
   sf.pos=8617603;
   r = Vfname;
   rt = 1;
   goto Ycsu;
  }
Ycsu:
  if (rt) goto YsLr;
  sf.pos=8617604;
  }
 }
 sf.pos=8617605;
 r = NULL;
YsLr:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yq8afo[3] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *Yq8a(Tc *Afirst, Tc *Asecond) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yq8afo[0].off = (void*)&sf - (void*)&Afirst;
  Yq8afo[1].off = (void*)&sf - (void*)&Asecond;
 }
 sf.frof = Yq8afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6830400;
 if (ZstringEndsWith(Afirst, ((Tc*)&YV), 0))
 {
  sf.pos=6830401;
  if (ZstringStartsWith(Asecond, ((Tc*)&YV), 0))
  {
   sf.pos=6830402;
   r = ZcS(Afirst, ZstringSlice(Asecond, 1, -1, 0));
   rt = 1;
   goto YV1Y;
  }
  sf.pos=6830403;
  r = ZcS(Afirst, Asecond);
YV1Y:
  ;
  rt = 1;
  goto YSGC;
 }
 sf.pos=6830404;
 if (((ZbyteStringSize(Afirst) == 0) || ZstringStartsWith(Asecond, ((Tc*)&YV), 0)))
 {
  sf.pos=6830405;
  r = ZcS(Afirst, Asecond);
  rt = 1;
  goto YSGC;
 }
 sf.pos=6830406;
 r = ZcS3(Afirst, ((Tc*)&YV), Asecond);
YSGC:
 e->topFrame = sf.prev;
 return r;
}
Zfo YPjHfo[5] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YPjH(Tc *Afname) {
 Ti Vlimit;
 Tb VisRelative;
 Tb VhasTrailingSep;
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *Vresult = NULL;
 Tc *Vlink = NULL;
 Tc *Vremain = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YPjHfo[0].off = (void*)&sf - (void*)&Afname;
  YPjHfo[1].off = (void*)&sf - (void*)&Vresult;
  YPjHfo[2].off = (void*)&sf - (void*)&Vlink;
  YPjHfo[3].off = (void*)&sf - (void*)&Vremain;
 }
 sf.frof = YPjHfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4533100;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=4533101;
 Vresult = Afname;
 sf.pos=4533102;
#else
 sf.pos=4533103;
 Vlimit = 100;
 sf.pos=4533104;
 VisRelative = ((ZstringGetChar(Afname, 0) == 46) && ((Yhu2(ZstringGetChar(Afname, 1)) || (((ZstringGetChar(Afname, 1) == 46) && Yhu2(ZstringGetChar(Afname, 2)))))));
 sf.pos=4533105;
 VhasTrailingSep = ZstringEndsWith(Afname, ((Tc*)&YV), 0);
 sf.pos=4533106;
 Vi = Y26N(Afname, YEpA(Afname));
 sf.pos=4533107;
 if ((Vi > 1))
 {
  sf.pos=4533108;
  Vresult = ZstringSlice(Afname, 0, (Vi - 2), 0);
  sf.pos=4533109;
  Vremain = ZstringSlice(Afname, (Vi - 1), -1, 0);
 }
 else
 {
  sf.pos=4533110;
  Vresult = Afname;
 }
 sf.pos=4533111;
 while (1)
 {
  sf.pos=4533112;
  while (1)
  {
   Ti Vt;
   sf.pos=4533113;
   {
    int   len;
    char  buf[PATH_MAX + 1];
    len = readlink(ZgetCstring(Vresult), (char *)buf, PATH_MAX);
    if (len <= 0) break;  /* can't read, use as-is */
    buf[len] = 0;
   sf.pos=4533114;
   Vlink = NULL;
   sf.pos=4533115;
    Vlink = Zstr(buf);
   }
   sf.pos=4533116;
   if (((Vlimit)-- == 0))
   {
    sf.pos=4533117;
    r = Afname;
    rt = 1;
    goto Yu7Z;
   }
   sf.pos=4533118;
   if (((Vremain == NULL) && VhasTrailingSep))
   {
    sf.pos=4533119;
    Vlink =  ZcS(Vlink, ((Tc*)&YV));
   }
   sf.pos=4533120;
   Vi = Y26N(Vlink, YEpA(Vlink));
   sf.pos=4533121;
   if ((Vi > 1))
   {
    sf.pos=4533122;
    if ((Vremain == NULL))
    {
     sf.pos=4533123;
     Vremain = ZstringSlice(Vlink, (Vi - 1), -1, 0);
    }
    else
    {
     sf.pos=4533124;
     Vremain = ZcS(ZstringSlice(Vlink, (Vi - 1), -1, 0), Vremain);
    }
    sf.pos=4533125;
    Vlink = ZstringSlice(Vlink, 0, (Vi - 2), 0);
   }
   sf.pos=4533126;
   Vt = Yr30(Vresult);
   sf.pos=4533127;
   if (((Vt > 0) && (Vt == ZstringSize(Vresult))))
   {
    sf.pos=4533128;
    Vresult = ZstringSlice(Vresult, 0, -2, 0);
    sf.pos=4533129;
    Vt = Yr30(Vresult);
   }
   sf.pos=4533130;
   if (((Vt > 0) && (YEpA(Vlink) == 0)))
   {
    sf.pos=4533131;
    Vresult = ZcS(ZstringSlice(Vresult, 0, (Vt - 1), 0), Vlink);
   }
   else
   {
    sf.pos=4533132;
    Vresult = ZcS(Vlink, ((Tc*)&Ya));
   }
Yu7Z:
   if (rt) goto YqPr;
  sf.pos=4533133;
  }
  sf.pos=4533134;
  if ((Vremain == NULL))
  {
   rt = 2;
   goto YqPr;
  }
  sf.pos=4533135;
  Vi = Y26N(Vremain, 1);
  sf.pos=4533136;
  if ((Vi > 1))
  {
   sf.pos=4533137;
   Vresult =  ZcS(Vresult, ZstringSlice(Vremain, 0, (Vi - 2), 0));
   sf.pos=4533138;
   Vremain = ZstringSlice(Vremain, (Vi - 1), -1, 0);
  }
  else
  {
   sf.pos=4533139;
   Vresult =  ZcS(Vresult, Vremain);
   sf.pos=4533140;
   Vremain = NULL;
  }
YqPr:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YQMx;
 sf.pos=4533141;
 }
 sf.pos=4533142;
 if (Yhu2(ZstringGetChar(Vresult, 0)))
 {
  sf.pos=4533143;
  if (((VisRelative && (ZstringSize(Vresult) > 0)) && !((((ZstringGetChar(Vresult, 0) == 46) && ((((ZstringSize(Vresult) == 1) || Yhu2(ZstringGetChar(Vresult, 1))) || (((ZstringGetChar(Vresult, 1) == 46) && (((ZstringSize(Vresult) == 2) || Yhu2(ZstringGetChar(Vresult, 2)))))))))))))
  {
   sf.pos=4533144;
   Vresult = ZcS(((Tc*)&YFka), Vresult);
  }
  else {
  sf.pos=4533145;
 if (!(VisRelative))
  {
   sf.pos=4533146;
   Vi = 0;
   sf.pos=4533147;
   while (((ZstringGetChar(Vresult, Vi) == 46) && Yhu2(ZstringGetChar(Vresult, (Vi + 1)))))
   {
    sf.pos=4533148;
    Vi += 2;
   sf.pos=4533149;
   }
   sf.pos=4533150;
   if ((Vi > 0))
   {
    sf.pos=4533151;
    Vresult = ZstringSlice(Vresult, Vi, -1, 0);
   }
  }
  }
 }
 sf.pos=4533152;
 if (!(VhasTrailingSep))
 {
  Ti Vm;
  sf.pos=4533153;
  Vm = YEpA(Vresult);
  sf.pos=4533154;
  while ((ZstringEndsWith(Vresult, ((Tc*)&YV), 0) && (ZstringSize(Vresult) > Vm)))
  {
   sf.pos=4533155;
   Vresult = ZstringSlice(Vresult, 0, -2, 0);
  sf.pos=4533156;
  }
 }
 sf.pos=4533157;
#endif
 sf.pos=4533158;
 r = Vresult;
YQMx:
 e->topFrame = sf.prev;
 return r;
}
Zfo Yr30fo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Yr30(Tc *Afname) {
 Ti Vi;
 Ti Vj;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yr30fo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Yr30fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6221300;
 Vi = ZstringFindLastChar(Afname, 47, 0);
 sf.pos=6221301;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=6221302;
 Vj = ZstringFindLastChar(Afname, 92, 0);
 sf.pos=6221303;
 if ((Vj > Vi))
 {
  sf.pos=6221304;
  Vi = Vj;
 }
 sf.pos=6221305;
#endif
 sf.pos=6221306;
 if ((Vi < 0))
 {
  sf.pos=6221307;
  r = 0;
  rt = 1;
  goto YnSW;
 }
 sf.pos=6221308;
 r = (Vi + 1);
YnSW:
 e->topFrame = sf.prev;
 return r;
}
Zfo YN1Tfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti YN1T(Tc *Afname) {
 Ti Vi;
 Ti Vj;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YN1Tfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = YN1Tfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7660100;
 Vi = ZstringFindLastChar(Afname, 47, 0);
 sf.pos=7660101;
 if ((Vi < 0))
 {
  sf.pos=7660102;
  r = 0;
  rt = 1;
  goto Yn5a;
 }
 sf.pos=7660103;
 Vj = YEpA(Afname);
 sf.pos=7660104;
 if ((Vi < Vj))
 {
  sf.pos=7660105;
  Vi = Vj;
 }
 else
 {
  sf.pos=7660106;
  while (((Vi > Vj) && Yhu2(ZstringGetChar(Afname, (Vi - 1)))))
  {
   sf.pos=7660107;
   --(Vi);
  sf.pos=7660108;
  }
 }
 sf.pos=7660109;
 r = Vi;
Yn5a:
 e->topFrame = sf.prev;
 return r;
}
Zfo YEpAfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti YEpA(Tc *Afname) {
 Ti Vi;
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEpAfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = YEpAfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 Vi = 0;
 sf.pos=1101700;
#if defined(__MINGW32__) || defined(_MSC_VER)
 sf.pos=1101701;
 if ((isalpha(ZstringGetChar(Afname, 0)) && (ZstringGetChar(Afname, 1) == 58)))
 {
  sf.pos=1101702;
  Vi = 2;
 }
 sf.pos=1101703;
#endif
 sf.pos=1101704;
 while (((Vi < ZstringSize(Afname)) && Yhu2(ZstringGetChar(Afname, Vi))))
 {
  sf.pos=1101705;
  ++(Vi);
 sf.pos=1101706;
 }
 sf.pos=1101707;
 r = Vi;
 e->topFrame = sf.prev;
 return r;
}
Tb Yhu2(Ti Ac) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tb r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7913600;
 r = (Ac == 47);
 e->topFrame = sf.prev;
 return r;
}
Zfo Y26Nfo[2] = {{0,(Tt*)&string__T},{0,0}};
Ti Y26N(Tc *Afname, Ti Aidx) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Y26Nfo[0].off = (void*)&sf - (void*)&Afname;
 }
 sf.frof = Y26Nfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3627700;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(Aidx, (ZstringSize(Afname) - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=3627701;
  if (Yhu2(ZstringGetChar(Afname, Vi)))
  {
   sf.pos=3627702;
   r = (Vi + 1);
   rt = 1;
   goto Ydy4;
  }
Ydy4:
  if (rt) goto Y3wQ;
  sf.pos=3627703;
  }
 }
 sf.pos=3627704;
 r = -1;
Y3wQ:
 e->topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=745200;
   Y59X = Yd89();
   sf.pos=745201;
   Yb0q = Yvyt();
   sf.pos=745202;
   YeNQ = YsM3();
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including GCModule bodies */
Zfo YnFGfo[2] = {{0,(Tt*)&YXAF__T},{0,0}};
void YnFG() {
 Ti Vstart;
 Tn *e = ZgetEnv();
 Zsf sf;
 YXAF *Vinfo = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YnFGfo[0].off = (void*)&sf - (void*)&Vinfo;
 }
 sf.frof = YnFGfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3020600;
 Vstart = Y9Rj();
 sf.pos=3020601;
 ZgcRun();
 sf.pos=3020602;
 Vinfo = Za(sizeof(YXAF));
 sf.pos=3020603;
 Vinfo->VstwTime = ZgcStwTime;
 Vinfo->VmarkTime = ZgcMarkTime;
 Vinfo->VfreeTime = ZgcFreeTime;
 Vinfo->VuseCount = ZgcUseCount;
 Vinfo->VfreeCount = ZgcFreeCount;
 sf.pos=3020604;
 Vinfo->VtotalTime = (Y9Rj() - Vstart);
 sf.pos=3020605;
 ZLap((Tl*)YJzU, (Tz)(void*)Vinfo);
 e->topFrame = sf.prev;
 return;
}
Zfo YmwFfo[12] = {{0,(Tt*)&YXAF__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YmwF(YXAF *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 Tc *t3 = NULL;
 Tc *t4 = NULL;
 Tc *t5 = NULL;
 Tc *t6 = NULL;
 Tc *t7 = NULL;
 Tc *t8 = NULL;
 Tc *t9 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YmwFfo[0].off = (void*)&sf - (void*)&t;
  YmwFfo[1].off = (void*)&sf - (void*)&t0;
  YmwFfo[2].off = (void*)&sf - (void*)&t1;
  YmwFfo[3].off = (void*)&sf - (void*)&t2;
  YmwFfo[4].off = (void*)&sf - (void*)&t3;
  YmwFfo[5].off = (void*)&sf - (void*)&t4;
  YmwFfo[6].off = (void*)&sf - (void*)&t5;
  YmwFfo[7].off = (void*)&sf - (void*)&t6;
  YmwFfo[8].off = (void*)&sf - (void*)&t7;
  YmwFfo[9].off = (void*)&sf - (void*)&t8;
  YmwFfo[10].off = (void*)&sf - (void*)&t9;
 }
 sf.frof = YmwFfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7105700;
  ZthrowThisNil();
 }
 sf.pos=7105701;
 r = ZcS12(ZcS3(((Tc*)&YQ_s), YrLY(t->VtotalTime), ((Tc*)&Yjxt)), (t0 = YrLY(t->VstwTime)), ((Tc*)&Y6De), (t2 = YrLY(t->VmarkTime)), ((Tc*)&Yt0B), (t4 = YrLY(t->VfreeTime)), ((Tc*)&Ye7i), (t6 = YrLY(t->VfreeCount)), ((Tc*)&YPtb), (t8 = YrLY(t->VuseCount)), ((Tc*)&Y0tw), (Tc*)1);
 e->topFrame = sf.prev;
 return r;
}
To ToYXAF[] = {
 {6, 0},
 {0, (Tt*)&int__T}, /* stwTime */
 {0, (Tt*)&int__T}, /* markTime */
 {0, (Tt*)&int__T}, /* freeTime */
 {0, (Tt*)&int__T}, /* totalTime */
 {0, (Tt*)&int__T}, /* useCount */
 {0, (Tt*)&int__T}, /* freeCount */
};
char *StrYXAF[] = {
 "stwTime",
 "markTime",
 "freeTime",
 "totalTime",
 "useCount",
 "freeCount",
};
Tto YXAF__T = {390, (Tc*)&Yzlt, YmwF, StrYXAF, 0, 0, 0, 0, ToYXAF};
int JGCModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=723800;
   YJzU = ZnewList((Tt*)&YXAF__T, 0);
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* GCModule done */
/* including THREADModule bodies */
/* including Config bodies */
int JConfig(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 if (round == 1) {
   sf.pos=2239800;
   Y4fD = YttT(NULL, ((Tc*)&YYa), ((Tc*)&Yef1), 0, ((Tc*)&YtSW));
   sf.pos=2239803;
   Y6Gp = ((YzqH *)Znio(2, 2239802, (YzqH__Y836(YBtk(NULL, NULL, ((Tc*)&YsHb), ((Tc*)&YsHb), ((Tc*)&YhxU)), ((Tc*)&YeLO)))));
   sf.pos=2239804;
   YJ5o = YBtk(NULL, NULL, ((Tc*)&YApf), ((Tc*)&YXja), ((Tc*)&Yl1G));
   sf.pos=2239805;
   Y6ma = YBtk(NULL, NULL, ((Tc*)&Yerz), ((Tc*)&Ya), ((Tc*)&YTzz));
   sf.pos=2239806;
   YMSZ = YttT(NULL, NULL, ((Tc*)&Y_e2), 0, ((Tc*)&Yslo));
  }
 if (round == 2001) {
   sf.pos=2239801;
   YEPH = YHoR(Y4fD);
   sf.pos=2239807;
   YSaE = YHoR(YMSZ);
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* Config done */
Zfo YgC4__YwtA__YRHRfo[3] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&string__T},{0,0}};
YgC4 *YgC4__YwtA__YRHR(YgC4 *t, Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YRHRfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YRHRfo[1].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YgC4__YwtA__YRHRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9798500; t = Za(sizeof(YgC4));}
 sf.pos=9798501;
 t->Vmessage = Amsg;
 sf.pos=9798502;
 t->Vpos = MZ__callerPos();
 sf.pos=9798503;
 t->Vbacktrace = (sf.pos=9798504, MZ__backtrace(1, -1));
 e->topFrame = sf.prev;
 return t;
}
Zfo YgC4__YwtA__YH0Vfo[4] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YgC4__YwtA__YH0V(YgC4 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YH0Vfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YH0Vfo[1].off = (void*)&sf - (void*)&Vw;
  YgC4__YwtA__YH0Vfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YgC4__YwtA__YH0Vfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3380500;
  ZthrowThisNil();
 }
 sf.pos=3380501;
 Vw = Za(sizeof(YjUM));
 sf.pos=3380502;
 YgC4__YwtA__YxaJ(t, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=3380503;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YgC4__YwtA__Yowwfo[4] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&YjUM__T},{0,(Tt*)&iobj__T},{0,0}};
Tc *YgC4__YwtA__Yoww(YgC4 *t, Tb Averbose) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__Yowwfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__Yowwfo[1].off = (void*)&sf - (void*)&Vw;
  YgC4__YwtA__Yowwfo[2].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YgC4__YwtA__Yowwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8606100;
  ZthrowThisNil();
 }
 sf.pos=8606101;
 Vw = Za(sizeof(YjUM));
 sf.pos=8606102;
 YgC4__YwtA__YxaJa(t, Averbose, *Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 sf.pos=8606103;
 r = YbNW(Vw);
 e->topFrame = sf.prev;
 return r;
}
Zfo YgC4__YwtA__YxaJafo[5] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&YkxB__T},{0,0}};
void YgC4__YwtA__YxaJa(YgC4 *t, Tb Averbose, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YxaJafo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YxaJafo[1].off = (void*)&sf - (void*)&Aw;
  YgC4__YwtA__YxaJafo[2].off = (void*)&sf - (void*)&Zf2;
  YgC4__YwtA__YxaJafo[3].off = (void*)&sf - (void*)&Vpos;
 }
 sf.frof = YgC4__YwtA__YxaJafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=705100;
  ZthrowThisNil();
 }
 sf.pos=705101;
 YgC4__YwtA__YxaJ(t, Aw);
 sf.pos=705102;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=705103;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=705104;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=705105;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=705106;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=705107;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=705108;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=705109;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=705110;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=705111;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=705112;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YgC4__YwtA__YxaJfo[3] = {{0,(Tt*)&YgC4__T},{0,(Tt*)&iobj__T},{0,0}};
void YgC4__YwtA__YxaJ(YgC4 *t, Tr Aw) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YgC4__YwtA__YxaJfo[0].off = (void*)&sf - (void*)&t;
  YgC4__YwtA__YxaJfo[1].off = (void*)&sf - (void*)&Aw;
 }
 sf.frof = YgC4__YwtA__YxaJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1725200;
  ZthrowThisNil();
 }
 sf.pos=1725201;
 if ((t->Vpos != NULL))
 {
  sf.pos=1725202;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=1725203;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=1725204;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=1725205;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=1725206;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=1725207;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 e->topFrame = sf.prev;
 return;
}
Tc *YgC4__Ytlm_I_imt[] = {
 (Tc*)&YgC4__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MTHREADModule__CE_Thread.NEW - YgC4__YwtA__YRHRa */
 (Tc*)YgC4__YwtA__YRHR, /* MTHREADModule__CE_Thread.NEW - YgC4__YwtA__YRHR */
 (Tc*)YgC4__YwtA__YH0V, /* MTHREADModule__CE_Thread.ToString - YgC4__YwtA__YH0V */
 (Tc*)YgC4__YwtA__YxaJa, /* MTHREADModule__CE_Thread.writeTo - YgC4__YwtA__YxaJa */
 (Tc*)YgC4__YwtA__YxaJ, /* MTHREADModule__CE_Thread.writeTo - YgC4__YwtA__YxaJ */
 (Tc*)YgC4__YwtA__Yoww, /* MTHREADModule__CE_Thread.toString - YgC4__YwtA__Yoww */
 (Tc*)0, /* MTHREADModule__CE_Thread.getMessage - YgC4__YwtA__YCzX */
 (Tc*)0, /* MTHREADModule__CE_Thread.getPos - YgC4__YwtA__YvCK */
 (Tc*)0, /* MTHREADModule__CE_Thread.getBacktrace - YgC4__YwtA__Y4bq */
 (Tc*)0, /* Init - YgC4a */
};
To ToYgC4[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
char *StrYgC4[] = {
 "message",
 "pos",
 "backtrace",
};
Tto YgC4__T = {390, (Tc*)&Yvlp, YgC4__YwtA__YH0V, StrYgC4, 0, 0, 0, 0, ToYgC4};
Zfo Yydufo[3] = {{0,(Tt*)&YTgs__T},{0,(Tt*)&cb__T},{0,0}};
YTgs *Yydu(YTgs *t, Tcb *Aproc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yydufo[0].off = (void*)&sf - (void*)&t;
  Yydufo[1].off = (void*)&sf - (void*)&Aproc;
 }
 sf.frof = Yydufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7000700; t = ZaF(sizeof(YTgs), ToYTgs, (Ts (*)(void*, Te))YTgs__Y2Cz, 0);}
 sf.pos=7000701;
 t->Vproc = Aproc;
 e->topFrame = sf.prev;
 return t;
}
Zfo Yyduafo[3] = {{0,(Tt*)&YTgs__T},{0,(Tt*)&cb__T},{0,0}};
YTgs *Yydua(YTgs *t, Tcb *Afunc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yyduafo[0].off = (void*)&sf - (void*)&t;
  Yyduafo[1].off = (void*)&sf - (void*)&Afunc;
 }
 sf.frof = Yyduafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8020800; t = ZaF(sizeof(YTgs), ToYTgs, (Ts (*)(void*, Te))YTgs__Y2Cz, 0);}
 sf.pos=8020801;
 t->Vproc = Afunc;
 e->topFrame = sf.prev;
 return t;
}
void YcCua(YTgs *t) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vproc != NULL))
 {
  ((void (*)(Tcb *))t->Vproc->cfunc)((Tcb*)t->Vproc);
 }
 return;
}
Zfo YqOJfo[3] = {{0,(Tt*)&YTgs__T},{0,(Tt*)&cb__T},{0,0}};
void YqOJ(YTgs *t, Tcb *Aproc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqOJfo[0].off = (void*)&sf - (void*)&t;
  YqOJfo[1].off = (void*)&sf - (void*)&Aproc;
 }
 sf.frof = YqOJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7019700;
  ZthrowThisNil();
 }
 sf.pos=7019701;
 t->Vproc = Aproc;
 e->topFrame = sf.prev;
 return;
}
Zfo YTgs__YCVYfo[2] = {{0,(Tt*)&YTgs__T},{0,0}};
YTgs *YTgs__YCVY(YTgs *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__YCVYfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YTgs__YCVYfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5422600; t = ZaF(sizeof(YTgs), ToYTgs, (Ts (*)(void*, Te))YTgs__Y2Cz, 0);}
 e->topFrame = sf.prev;
 return t;
}
Zfo YTgs__Y7C8fo[3] = {{0,(Tt*)&YTgs__T},{0,(Tt*)&list__T},{0,0}};
void YTgs__Y7C8(YTgs *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__Y7C8fo[0].off = (void*)&sf - (void*)&t;
  YTgs__Y7C8fo[1].off = (void*)&sf - (void*)&Zf1;
 }
 sf.frof = YTgs__Y7C8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3947200;
  ZthrowThisNil();
 }
 sf.pos=3947201;
 int i = 0;
 Zsf *prev = NULL;
 e->startFrames = calloc(1, ZListSize(t->Vstack) * sizeof(Zsf));
 sf.pos=3947202;
 {
  Ti Vpos;
  Tfl Zf1i;
  Zf1 = t->Vstack;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpos;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=3947203;
 e->startFrames[i].pos = Vpos;
 e->startFrames[i].prev = prev;
 prev = &e->startFrames[i];
 ++i;
  sf.pos=3947204;
  }
 }
 sf.pos=3947205;
 sf.prev = prev;
 sf.pos=3947206;
 pthread_mutex_lock(&threadsMutex);
 ZLa(threads, -1, (Tz)(void*)e);
 pthread_mutex_unlock(&threadsMutex);
 sf.pos=3947207;
 YcCua(t);

 e->finished = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YTgs__YSuwfo[3] = {{0,(Tt*)&YTgs__T},{0,(Tt*)&iobj__T},{0,0}};
void YTgs__YSuw(YTgs *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__YSuwfo[0].off = (void*)&sf - (void*)&t;
  YTgs__YSuwfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YTgs__YSuwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8558600;
  ZthrowThisNil();
 }
 sf.pos=8558601;
 Zsf *top = e->topFrame;
 sf.pos=8558602;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 sf.pos=8558603;
 while ((ZListSize(t->Vstack) < 30))
 {
  Ti Ventry;
  Ventry = 0;
  sf.pos=8558604;
  if (top == NULL) break;
  Ventry = top->pos;
  top = top->prev;
  sf.pos=8558605;
  ZListInsert((Tl*)t->Vstack, 0, (Tz)(Ti)Ventry);
 sf.pos=8558606;
 }
 sf.pos=8558607;
 if (pthread_create(&t->Vthread_id, NULL, (void *(*)(void *))YTgs__Y7C8, t) != 0) {
 sf.pos=8558608;
 if (1)
 {
  Tr ex;
  sf.pos=8558609;
  *Znao(&ex, YgC4__YwtA__YRHR(NULL, ((Tc*)&YgzQ)), YgC4__Ytlm_I_imt, 30);
  ZthrowIobject(ex);
 }
 sf.pos=8558610;
 }
 {
  int oldstate;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
 }
 sf.pos=8558611;
 t->Vstate = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YTgs__YSfifo[2] = {{0,(Tt*)&YTgs__T},{0,0}};
void YTgs__YSfi(YTgs *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__YSfifo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YTgs__YSfifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7764100;
  ZthrowThisNil();
 }
 sf.pos=7764101;
 if (pthread_join(t->Vthread_id, NULL) != 0) {
 sf.pos=7764102;
  ZthrowThread(Zstr("wait()"));
 }
 sf.pos=7764103;
 t->Vstate = 2;
 e->topFrame = sf.prev;
 return;
}
Zfo YTgs__YDFpfo[2] = {{0,(Tt*)&YTgs__T},{0,0}};
void YTgs__YDFp(YTgs *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__YDFpfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YTgs__YDFpfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=847600;
  ZthrowThisNil();
 }
 sf.pos=847601;
 if (pthread_cancel(t->Vthread_id) != 0) {
 sf.pos=847602;
  ZthrowThread(Zstr("kill()"));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YTgs__Y2Czfo[2] = {{0,(Tt*)&YTgs__T},{0,0}};
Ts YTgs__Y2Cz(YTgs *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTgs__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YTgs__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8452100;
  ZthrowThisNil();
 }
 sf.pos=8452101;
 pthread_detach(t->Vthread_id);
 sf.pos=8452102;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Tc *YTgs__YTgs_I_imt[] = {
 (Tc*)&YTgs__T,
 (Tc*)Yydua, /* MTHREADModule__CThread.NEW - Yydua */
 (Tc*)Yydu, /* MTHREADModule__CThread.NEW - Yydu */
 (Tc*)YTgs__YCVY, /* MTHREADModule__CThread.NEW - YTgs__YCVY */
 (Tc*)0, /* MTHREADModule__CThread.setName - YTgs__Yjgi */
 (Tc*)YTgs__Y7C8, /* MTHREADModule__CThread.startBody - YTgs__Y7C8 */
 (Tc*)YTgs__YSuw, /* MTHREADModule__CThread.start - YTgs__YSuw */
 (Tc*)YTgs__YSfi, /* MTHREADModule__CThread.wait - YTgs__YSfi */
 (Tc*)YTgs__YDFp, /* MTHREADModule__CThread.kill - YTgs__YDFp */
 (Tc*)0, /* MTHREADModule__CThread.Finish - YTgs__Y2Cz */
 (Tc*)0, /* MTHREADModule__CThread.remove - YTgs__YQa6 */
 (Tc*)0,
 (Tc*)YcCua, /* MTHREADModule__CThread.body - YcCua */
 (Tc*)YqOJ, /* MTHREADModule__CThread.setProc - YqOJ */
 (Tc*)0, /* Init - YTgsa */
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
};
To ToYTgs[] = {
 {4, 0},
 {0, (Tt*)&cb__T}, /* proc */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrYTgs[] = {
 "proc",
 "name",
 "state",
 "stack",
};
Tto YTgs__T = {390, (Tc*)&YnY0, 0, StrYTgs, 0, YTgs__Y2Cz, 0, 0, ToYTgs};
Zfo YFiEfo[3] = {{0,(Tt*)&YRg3__T},{0,(Tt*)&cb__T},{0,0}};
YJ7s *YFiE(YRg3 *t, Tcb *Af) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YJ7s *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YFiEfo[0].off = (void*)&sf - (void*)&t;
  YFiEfo[1].off = (void*)&sf - (void*)&Af;
 }
 sf.frof = YFiEfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7043200;
  ZthrowThisNil();
 }
 sf.pos=7043201;
 t->VevalFunc = Af;
 sf.pos=7043202;
 t->VresultPipe = YqaL(NULL);
 sf.pos=7043203;
 YRg3__YSuw(t);
 sf.pos=7043204;
 r = t->VresultPipe;
 e->topFrame = sf.prev;
 return r;
}
void YhD_a(YRg3 *t) {
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->VevalFunc == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YWvT);
  ZthrowPos(5506600, ex);
 }
 else
 {
  YVE3(t->VresultPipe, ((Tc* (*)(Tcb *))t->VevalFunc->cfunc)((Tcb*)t->VevalFunc));
  YQCO(t->VresultPipe);
 }
 return;
}
Zfo Y21Dfo[2] = {{0,(Tt*)&cb__T},{0,0}};
YJ7s *Y21D(Tcb *Af) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YJ7s *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y21Dfo[0].off = (void*)&sf - (void*)&Af;
 }
 sf.frof = Y21Dfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5466000;
 r = YFiE(YRg3__YCVY(NULL), Af);
 e->topFrame = sf.prev;
 return r;
}
Zfo YRg3__YCVYfo[2] = {{0,(Tt*)&YRg3__T},{0,0}};
YRg3 *YRg3__YCVY(YRg3 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRg3__YCVYfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YRg3__YCVYfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9386500; t = ZaF(sizeof(YRg3), ToYRg3, (Ts (*)(void*, Te))YRg3__Y2Cz, 0);}
 e->topFrame = sf.prev;
 return t;
}
Zfo YRg3__Y7C8fo[3] = {{0,(Tt*)&YRg3__T},{0,(Tt*)&list__T},{0,0}};
void YRg3__Y7C8(YRg3 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRg3__Y7C8fo[0].off = (void*)&sf - (void*)&t;
  YRg3__Y7C8fo[1].off = (void*)&sf - (void*)&Zf1;
 }
 sf.frof = YRg3__Y7C8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5814300;
  ZthrowThisNil();
 }
 sf.pos=5814301;
 int i = 0;
 Zsf *prev = NULL;
 e->startFrames = calloc(1, ZListSize(t->Vstack) * sizeof(Zsf));
 sf.pos=5814302;
 {
  Ti Vpos;
  Tfl Zf1i;
  Zf1 = t->Vstack;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpos;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=5814303;
 e->startFrames[i].pos = Vpos;
 e->startFrames[i].prev = prev;
 prev = &e->startFrames[i];
 ++i;
  sf.pos=5814304;
  }
 }
 sf.pos=5814305;
 sf.prev = prev;
 sf.pos=5814306;
 pthread_mutex_lock(&threadsMutex);
 ZLa(threads, -1, (Tz)(void*)e);
 pthread_mutex_unlock(&threadsMutex);
 sf.pos=5814307;
 YhD_a(t);

 e->finished = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YRg3__YSuwfo[3] = {{0,(Tt*)&YRg3__T},{0,(Tt*)&iobj__T},{0,0}};
void YRg3__YSuw(YRg3 *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRg3__YSuwfo[0].off = (void*)&sf - (void*)&t;
  YRg3__YSuwfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YRg3__YSuwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4638500;
  ZthrowThisNil();
 }
 sf.pos=4638501;
 Zsf *top = e->topFrame;
 sf.pos=4638502;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 sf.pos=4638503;
 while ((ZListSize(t->Vstack) < 30))
 {
  Ti Ventry;
  Ventry = 0;
  sf.pos=4638504;
  if (top == NULL) break;
  Ventry = top->pos;
  top = top->prev;
  sf.pos=4638505;
  ZListInsert((Tl*)t->Vstack, 0, (Tz)(Ti)Ventry);
 sf.pos=4638506;
 }
 sf.pos=4638507;
 if (pthread_create(&t->Vthread_id, NULL, (void *(*)(void *))YRg3__Y7C8, t) != 0) {
 sf.pos=4638508;
 if (1)
 {
  Tr ex;
  sf.pos=4638509;
  *Znao(&ex, YgC4__YwtA__YRHR(NULL, ((Tc*)&YgzQ)), YgC4__Ytlm_I_imt, 30);
  ZthrowIobject(ex);
 }
 sf.pos=4638510;
 }
 {
  int oldstate;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
 }
 sf.pos=4638511;
 t->Vstate = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YRg3__Y2Czfo[2] = {{0,(Tt*)&YRg3__T},{0,0}};
Ts YRg3__Y2Cz(YRg3 *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YRg3__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YRg3__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2854800;
  ZthrowThisNil();
 }
 sf.pos=2854801;
 pthread_detach(t->Vthread_id);
 sf.pos=2854802;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
To ToYRg3[] = {
 {5, 0},
 {0, (Tt*)&cb__T}, /* evalFunc */
 {0, (Tt*)&YJ7s__T}, /* resultPipe */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrYRg3[] = {
 "evalFunc",
 "resultPipe",
 "name",
 "state",
 "stack",
};
Tto YRg3__T = {390, (Tc*)&YtxE, 0, StrYRg3, 0, YRg3__Y2Cz, 0, 0, ToYRg3};
Zfo YaWJfo[3] = {{0,(Tt*)&cb__T},{0,(Tt*)&YRg3__T},{0,0}};
YJ7s *YaWJ(Tcb *Af) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YJ7s *r = 0;
 YRg3 *Vet = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YaWJfo[0].off = (void*)&sf - (void*)&Af;
  YaWJfo[1].off = (void*)&sf - (void*)&Vet;
 }
 sf.frof = YaWJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5540200;
 Vet = YRg3__YCVY(NULL);
 sf.pos=5540201;
 r = YFiE(Vet, Af);
 e->topFrame = sf.prev;
 return r;
}
Zfo YCylfo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
YlXt *YCyl(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YCylfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YCylfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=5342800; t = ZaF(sizeof(YlXt), ToYlXt, (Ts (*)(void*, Te))YMFu, 0);}
 sf.pos=5342801;
 pthread_mutex_init(&t->Vmutex, NULL);
 e->topFrame = sf.prev;
 return t;
}
Zfo YHl9fo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
void YHl9(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YHl9fo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YHl9fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=765100;
  ZthrowThisNil();
 }
 sf.pos=765101;
 pthread_mutex_lock(&t->Vmutex);
 e->topFrame = sf.prev;
 return;
}
Zfo Yvoofo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
void Yvoo(YlXt *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yvoofo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yvoofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1760500;
  ZthrowThisNil();
 }
 sf.pos=1760501;
 pthread_mutex_unlock(&t->Vmutex);
 e->topFrame = sf.prev;
 return;
}
Zfo YMFufo[2] = {{0,(Tt*)&YlXt__T},{0,0}};
Ts YMFu(YlXt *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YMFufo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YMFufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8011100;
  ZthrowThisNil();
 }
 sf.pos=8011101;
 pthread_mutex_destroy(&t->Vmutex);
 sf.pos=8011102;
 r = 1;
 if (r) t->fok |= FOK_OK;
 e->topFrame = sf.prev;
 return r;
}
To ToYlXt[] = {
 {0, 0},
};
char *StrYlXt[] = {
};
Tto YlXt__T = {390, (Tc*)&YzBS, 0, StrYlXt, 0, YMFu, 0, 0, ToYlXt};
Zfo YDpwfo[3] = {{0,(Tt*)&YTJ0__T},{0,(Tt*)&YlXt__T},{0,0}};
YTJ0 *YDpw(YTJ0 *t, YlXt *Alock) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YDpwfo[0].off = (void*)&sf - (void*)&t;
  YDpwfo[1].off = (void*)&sf - (void*)&Alock;
 }
 sf.frof = YDpwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=3876100; t = ZaF(sizeof(YTJ0), ToYTJ0, (Ts (*)(void*, Te))YKWW, 0);}
 sf.pos=3876101;
 YHl9(Alock);
 sf.pos=3876102;
 t->Vlock = Alock;
 e->topFrame = sf.prev;
 return t;
}
Zfo YKWWfo[2] = {{0,(Tt*)&YTJ0__T},{0,0}};
Ts YKWW(YTJ0 *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YKWWfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YKWWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7924800;
  ZthrowThisNil();
 }
 sf.pos=7924801;
 if (!(t->VdidEnd))
 {
  sf.pos=7924802;
  t->VdidEnd = 1;
  sf.pos=7924803;
  Yvoo(t->Vlock);
 }
 sf.pos=7924804;
 r = 1;
 if (r) t->fok |= FOK_OK;
 e->topFrame = sf.prev;
 return r;
}
To ToYTJ0[] = {
 {2, 0},
 {0, (Tt*)&YlXt__T}, /* lock */
 {0, (Tt*)&bool__T}, /* didEnd */
};
char *StrYTJ0[] = {
 "lock",
 "didEnd",
};
Tto YTJ0__T = {390, (Tc*)&YTdt, 0, StrYTJ0, 0, YKWW, 0, 0, ToYTJ0};
Zfo YXGLfo[2] = {{0,(Tt*)&Y0Wo__T},{0,0}};
Y0Wo *YXGL(Y0Wo *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXGLfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YXGLfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6882300; t = Za(sizeof(Y0Wo));}
 sf.pos=6882301;
 pthread_cond_init(&t->Vcond, NULL);
 e->topFrame = sf.prev;
 return t;
}
Zfo YjFjfo[2] = {{0,(Tt*)&Y0Wo__T},{0,0}};
void YjFj(Y0Wo *t, Tb Aall) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjFjfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjFjfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=108200;
  ZthrowThisNil();
 }
 sf.pos=108201;
 if (Aall)
  pthread_cond_broadcast(&t->Vcond);
 else
  pthread_cond_signal(&t->Vcond);
 e->topFrame = sf.prev;
 return;
}
Zfo YN6afo[3] = {{0,(Tt*)&Y0Wo__T},{0,(Tt*)&YlXt__T},{0,0}};
void YN6a(Y0Wo *t, YlXt *Alock) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YN6afo[0].off = (void*)&sf - (void*)&t;
  YN6afo[1].off = (void*)&sf - (void*)&Alock;
 }
 sf.frof = YN6afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7373400;
  ZthrowThisNil();
 }
 sf.pos=7373401;
 pthread_cond_wait(&t->Vcond, &Alock->Vmutex);
 e->topFrame = sf.prev;
 return;
}
To ToY0Wo[] = {
 {0, 0},
};
char *StrY0Wo[] = {
};
Tto Y0Wo__T = {390, (Tc*)&YeBN, 0, StrY0Wo, 0, 0, 0, 0, ToY0Wo};
int JTHREADModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
 done &= JConfig(round);
  if (round == 0) {
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* THREADModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 e->topFrame = sf.prev;
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
char *StrYnU5[] = {
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, StrYnU5, 0, 0, 0, 0, ToYnU5};
void YY8i() {
 Tr t0 = {NULL};
 if ((Y6fX == NULL))
 {
  Tr ex;
  *Znao(&ex, YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YeBP)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 return;
}
void YS39() {
 Tr t0 = {NULL};
 if ((Y6fX != NULL))
 {
  Tr ex;
  *Znao(&ex, YVNj__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YY2Q)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 return;
}
void YQtK() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7716400;
 Y2R7 = Ycmi(YzvW);
 e->topFrame = sf.prev;
 return;
}
Tc *YzHL() {
 Ti VtailIndex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=3261800;
 VtailIndex = Yr30(Y2R7);
 sf.pos=3261801;
 if ((VtailIndex <= 0))
 {
  sf.pos=3261802;
  r = ((Tc*)&YU);
  rt = 1;
  goto Yt70;
 }
 sf.pos=3261803;
 r = ZstringSlice(Y2R7, 0, (VtailIndex - 2), 0);
Yt70:
 e->topFrame = sf.prev;
 return r;
}
Zfo YZH8fo[16] = {{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y86c__T},{0,(Tt*)&Y_SI__T},{0,(Tt*)&YJQu__T},{0,(Tt*)&YzqH__T},{0,(Tt*)&iobj__T},{0,0}};
void YZH8() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Varg = NULL;
 Tc *Vvalue = NULL;
 Tc *Vflagname = NULL;
 Tc *Vflagname1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vk = NULL;
 Tl *Zf21 = NULL;
 Tc *Vk1 = NULL;
 Tr Vflag = {NULL};
 Y86c *Vbflag = 0;
 Y86c *Vbflag1 = 0;
 Y_SI *Vsflag = 0;
 YJQu *Viflag = 0;
 YzqH *Vsflag1 = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YZH8fo[0].off = (void*)&sf - (void*)&Varg;
  YZH8fo[1].off = (void*)&sf - (void*)&Vvalue;
  YZH8fo[2].off = (void*)&sf - (void*)&Vflagname;
  YZH8fo[3].off = (void*)&sf - (void*)&Vflagname1;
  YZH8fo[4].off = (void*)&sf - (void*)&Zf2;
  YZH8fo[5].off = (void*)&sf - (void*)&Vk;
  YZH8fo[6].off = (void*)&sf - (void*)&Zf21;
  YZH8fo[7].off = (void*)&sf - (void*)&Vk1;
  YZH8fo[8].off = (void*)&sf - (void*)&Vflag;
  YZH8fo[9].off = (void*)&sf - (void*)&Vbflag;
  YZH8fo[10].off = (void*)&sf - (void*)&Vbflag1;
  YZH8fo[11].off = (void*)&sf - (void*)&Vsflag;
  YZH8fo[12].off = (void*)&sf - (void*)&Viflag;
  YZH8fo[13].off = (void*)&sf - (void*)&Vsflag1;
  YZH8fo[14].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YZH8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8253300;
 if ((Y6fX == NULL))
 {
  Tb VdoFlags;
  Tb Vskip;
  sf.pos=8253301;
  if ((Y7be == NULL))
  {
   sf.pos=8253302;
   Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
   sf.pos=8253303;
   YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  }
  sf.pos=8253304;
  if ((YUBd && (((ZDictSize(Y7be) > 0) || (ZDictSize(YBQy) > 0)))))
  {
   Tr ex;
   sf.pos=8253305;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y7T_)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=8253306;
  {
   Tfl Zf2i;
   Zf2 = ZDictKeys(Y7be, 0);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vk;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tr YXyJ = {NULL};
   sf.pos=8253307;
   (YXyJ = ZDictGetIobj(Y7be, (Tz)(void*)Vk), ((void (*)(void*))(YXyJ.table[17]))(YXyJ.ptr));
   sf.pos=8253308;
   }
  }
  sf.pos=8253309;
  {
   Tfl Zf21i;
   Zf21 = ZDictKeys(YBQy, 0);
   Zf21i.l = Zf21;
   Zf21i.valp = (void*)&Vk1;
   Zf21i.i = 0;
   for (; ZforListPtrCont(&Zf21i); ) {
   Tr YWyJ = {NULL};
   sf.pos=8253310;
   (YWyJ = ZDictGetIobj(YBQy, (Tz)(void*)Vk1), ((void (*)(void*))(YWyJ.table[17]))(YWyJ.ptr));
   sf.pos=8253311;
   }
  }
  sf.pos=8253312;
  Y6fX = ZnewList((Tt*)&string__T, 0);
  sf.pos=8253313;
  VdoFlags = !(YUBd);
  Vskip = 0;
  sf.pos=8253314;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew(0, (ZListSize(Y1p3) - 1), 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=8253315;
   if (Vskip)
   {
    sf.pos=8253316;
    Vskip = 0;
    rt = 4;
    if (rt) goto YgsM;
   }
   sf.pos=8253317;
   Varg = ((Tc *)ZListGetPtr(Y1p3, Vi));
   sf.pos=8253318;
   if (((!(VdoFlags) || (ZstringGetChar(Varg, 0) != 45)) || (ZstringCmp(Varg, ((Tc*)&YT)) == 0)))
   {
    sf.pos=8253319;
    ZLap((Tl*)Y6fX, (Tz)(void*)Varg);
    sf.pos=8253320;
    if (YQpY)
    {
     sf.pos=8253321;
     VdoFlags = 0;
    }
   }
   else
   {
    sf.pos=8253322;
    if ((ZstringCmp(Varg, ((Tc*)&Y1ia)) == 0))
    {
     sf.pos=8253323;
     VdoFlags = 0;
    }
    else
    {
     Vflag.ptr = NULL;
     Vvalue = NULL;
     sf.pos=8253324;
     if ((ZstringCmp(ZstringSlice(Varg, 0, 1, 0), ((Tc*)&Y1ia)) == 0))
     {
      Ti Vidx;
      sf.pos=8253325;
      Vflagname = ZstringSlice(Varg, 2, -1, 0);
      sf.pos=8253326;
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3vi)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
      {
       sf.pos=8253327;
       Yfj5((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) != 0));
      }
      sf.pos=8253328;
      Vidx = ZstringFindChar(Vflagname, 61, 0);
      sf.pos=8253329;
      if ((Vidx > 0))
      {
       sf.pos=8253330;
       Vvalue = ZstringSlice(Vflagname, (Vidx + 1), -1, 0);
       sf.pos=8253331;
       Vflagname = ZstringSlice(Vflagname, 0, (Vidx - 1), 0);
      }
      sf.pos=8253332;
      Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)Vflagname, trZero);
      sf.pos=8253333;
      if (((((Vflag).ptr) == NULL) && (ZstringCmp(ZstringSlice(Vflagname, 0, 1, 0), ((Tc*)&YhZb)) == 0)))
      {
       sf.pos=8253334;
       Vflag = ZDictGetIobjDef(YBQy, (Tz)(void*)ZstringSlice(Vflagname, 2, -1, 0), trZero);
       sf.pos=8253335;
       if ((((Vflag).ptr) != NULL))
       {
        sf.pos=8253336;
        if ((Vflag).type == 0)
        {
         sf.pos=8253337;
         Vflagname = ZstringSlice(Vflagname, 2, -1, 0);
         sf.pos=8253338;
         Vvalue = ((Tc*)&YhZb);
        }
        else
        {
         sf.pos=8253339;
         Vflag = trZero;
        }
       }
      }
     }
     else
     {
      Ti Vidx;
      sf.pos=8253340;
      Vflagname1 = ZstringSlice(Varg, 1, -1, 0);
      sf.pos=8253341;
      Vidx = ZstringFindChar(Vflagname1, 61, 0);
      sf.pos=8253342;
      if ((Vidx > 0))
      {
       sf.pos=8253343;
       Vvalue = ZstringSlice(Vflagname1, (Vidx + 1), -1, 0);
       sf.pos=8253344;
       Vflagname1 = ZstringSlice(Vflagname1, 0, (Vidx - 1), 0);
      }
      else
      {
       sf.pos=8253345;
       while ((ZstringSize(Vflagname1) > 1))
       {
        sf.pos=8253346;
        Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)ZstringSlice(Vflagname1, 0, 0, 0), trZero);
        sf.pos=8253347;
        if ((((Vflag).ptr) == NULL))
        {
         rt = 2;
         goto Yy70;
        }
        else
        {
         sf.pos=8253348;
         if ((Vflag).type == 0)
         {
          sf.pos=8253349;
          ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
          sf.pos=8253351;
          Vbflag = ((Y86c *)Znio(0, 8253350, (Vflag)));
          sf.pos=8253352;
          Vbflag->Vcurrent = !(Vbflag->Vdefault);
          sf.pos=8253353;
          Vflagname1 = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253354;
          Vflag = trZero;
         }
         else {
         sf.pos=8253355;
 if ((Vflag).type == 3)
         {
          rt = 2;
          goto YuBh;
         }
         else {
         sf.pos=8253356;
 if ((!(Y_kI) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[7])))))
         {
          sf.pos=8253357;
          Vvalue = ZstringSlice(Vflagname1, 1, -1, 0);
          sf.pos=8253358;
          Vflagname1 = ZstringSlice(Vflagname1, 0, 0, 0);
         }
         }}
YuBh:
         if (rt) goto Yy70;
        }
Yy70:
        if (rt == 2) { rt &= 1; break; }
       sf.pos=8253359;
       }
      }
      sf.pos=8253360;
      if ((ZstringSize(Vflagname1) != 1))
      {
       sf.pos=8253361;
       YSUO(ZcS(((Tc*)&YcW8), Varg));
      }
      else {
      sf.pos=8253362;
 if ((((Vflag).ptr) == NULL))
      {
       sf.pos=8253363;
       Vflag = ZDictGetIobjDef(Y7be, (Tz)(void*)Vflagname1, trZero);
      }
      }
     }
     sf.pos=8253364;
     if ((((Vflag).ptr) == NULL))
     {
      sf.pos=8253365;
      if (!(YUBd))
      {
       sf.pos=8253366;
       YSUO(ZcS(((Tc*)&Y2hB), Varg));
      }
     }
     else
     {
      sf.pos=8253367;
      if ((((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])) > 0) && !((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[6])))))
      {
       sf.pos=8253368;
       YSUO(ZcS(((Tc*)&YcLH), Varg));
      }
      sf.pos=8253369;
      ++((*(Ti*)(Vflag.ptr + (size_t)Vflag.table[5])));
      sf.pos=8253370;
      if ((Vflag).type == 0)
      {
       sf.pos=8253372;
       Vbflag1 = ((Y86c *)Znio(0, 8253371, (Vflag)));
       sf.pos=8253373;
       if ((Vvalue != NULL))
       {
        sf.pos=8253374;
        if (((ZstringCmp(Vvalue, ((Tc*)&YjK7)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YsfP)) == 0)))
        {
         sf.pos=8253375;
         Vbflag1->Vcurrent = 1;
        }
        else {
        sf.pos=8253376;
 if (((ZstringCmp(Vvalue, ((Tc*)&YhZb)) == 0) || (ZstringCmp(Vvalue, ((Tc*)&YvpX)) == 0)))
        {
         sf.pos=8253377;
         Vbflag1->Vcurrent = 0;
        }
        else
        {
         sf.pos=8253378;
         YSUO(ZcS(((Tc*)&YHSJ), Varg));
        }
        }
       }
       else
       {
        sf.pos=8253379;
        Vbflag1->Vcurrent = !(Vbflag1->Vdefault);
       }
      }
      else {
      sf.pos=8253380;
 if ((Vflag).type == 3)
      {
       sf.pos=8253381;
       if ((Vvalue != NULL))
       {
        sf.pos=8253382;
        YSUO(ZcS(((Tc*)&Y6QK), Varg));
       }
       sf.pos=8253384;
       Vsflag = ((Y_SI *)Znio(3, 8253383, (Vflag)));
       sf.pos=8253385;
       Vsflag->Vcurrent = ZnewList((Tt*)&string__T, 0);
       sf.pos=8253386;
       {
        Ti Vj;
        Tfr Zf7;
        ZforRangeNew((Vi + 1), (ZListSize(Y1p3) - 1), 0, 1, &Zf7);
        for (ZforRangeGetInt(&Zf7, &Vj); ZforRangeContInt(&Zf7); ZforRangeNextInt(&Zf7, &Vj)) {
        sf.pos=8253387;
        ZLap((Tl*)Vsflag->Vcurrent, (Tz)(void*)((Tc *)ZListGetPtr(Y1p3, Vj)));
        sf.pos=8253388;
        }
       }
       rt = 2;
       goto YxuQ;
      }
      else
      {
       sf.pos=8253389;
       if ((!((*(Tb*)(Vflag.ptr + (size_t)Vflag.table[8]))) && (Vvalue == NULL)))
       {
        sf.pos=8253390;
        Vskip = 1;
        sf.pos=8253391;
        if ((Vi == (ZListSize(Y1p3) - 1)))
        {
         sf.pos=8253392;
         YSUO(ZcS(((Tc*)&Y_ju), Varg));
        }
        sf.pos=8253393;
        Vvalue = ((Tc *)ZListGetPtr(Y1p3, (Vi + 1)));
       }
       sf.pos=8253394;
       if ((Vflag).type == 1)
       {
        sf.pos=8253396;
        Viflag = ((YJQu *)Znio(1, 8253395, (Vflag)));
        sf.pos=8253397;
        if ((Vvalue == NULL))
        {
         sf.pos=8253398;
         Viflag->Vcurrent = Viflag->Vdefault;
         sf.pos=8253399;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)Viflag->Vdefault);
        }
        else
        {
         Ti VintVal;
         sf.pos=8253400;
         VintVal = ZstringToInt(Vvalue, 1, 0);
         sf.pos=8253401;
         Viflag->Vcurrent = VintVal;
         sf.pos=8253402;
         ZLap((Tl*)Viflag->VtheValueList, (Tz)(Ti)VintVal);
        }
       }
       else {
       sf.pos=8253403;
 if ((Vflag).type == 2)
       {
        sf.pos=8253405;
        Vsflag1 = ((YzqH *)Znio(2, 8253404, (Vflag)));
        sf.pos=8253406;
        if ((Vvalue == NULL))
        {
         sf.pos=8253407;
         Vsflag1->Vcurrent = Vsflag1->Vdefault;
         sf.pos=8253408;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vsflag1->Vdefault);
        }
        else
        {
         sf.pos=8253409;
         Vsflag1->Vcurrent = Vvalue;
         sf.pos=8253410;
         ZLap((Tl*)Vsflag1->VtheValueList, (Tz)(void*)Vvalue);
        }
       }
       else
       {
        Tr ex;
        sf.pos=8253411;
        *Znao(&ex, YrHq__YwtA__YRHR(NULL, ((Tc*)&YjTs)), YrHq__Ytlm_I_imt, 26);
        ZthrowIobject(ex);
       }
       }
      }
      }
YxuQ:
      if (rt) goto YdgD;
     }
YdgD:
     if (rt) goto YOd6;
    }
YOd6:
    if (rt) goto YgsM;
   }
YgsM:
   if (rt == 2) { rt &= 1; break; }
   if (rt == 4) { rt &= 1; continue; }
   sf.pos=8253412;
   }
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YSUOfo[2] = {{0,(Tt*)&string__T},{0,0}};
void YSUO(Tc *Amsg) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSUOfo[0].off = (void*)&sf - (void*)&Amsg;
 }
 sf.frof = YSUOfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8529500;
 ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, Amsg);
 sf.pos=8529501;
 if ((Yun4 != NULL))
 {
  sf.pos=8529502;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=8529503;
 if (!(YhUP))
 {
  sf.pos=8529504;
  ((Ts (*)(void*, Tc*))(YeNQ.table[11]))(YeNQ.ptr, ZcS3(((Tc*)&YkFE), YzvW, ((Tc*)&Y15F)));
 }
 sf.pos=8529505;
 Zexit(Ypp_a(NULL, ((Tc*)&Yzoka), 456, 5), 1);
 e->topFrame = sf.prev;
 return;
}
Zfo Yfj5fo[12] = {{0,(Tt*)&dict__T},{0,(Tt*)&list__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,0}};
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
 Tn *e = ZgetEnv();
 Zsf sf;
 Td *VallFlags = NULL;
 Tl *Zf1 = NULL;
 Tl *Zf2 = NULL;
 Tc *Vkey = NULL;
 Tc *VargText = NULL;
 Tc *Vlead = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 Tr Vflag = {NULL};
 Tr Vflag1 = {NULL};
 Tl *t0 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  Yfj5fo[0].off = (void*)&sf - (void*)&VallFlags;
  Yfj5fo[1].off = (void*)&sf - (void*)&Zf1;
  Yfj5fo[2].off = (void*)&sf - (void*)&Zf2;
  Yfj5fo[3].off = (void*)&sf - (void*)&Vkey;
  Yfj5fo[4].off = (void*)&sf - (void*)&VargText;
  Yfj5fo[5].off = (void*)&sf - (void*)&Vlead;
  Yfj5fo[6].off = (void*)&sf - (void*)&Zf11;
  Yfj5fo[7].off = (void*)&sf - (void*)&Vkey1;
  Yfj5fo[8].off = (void*)&sf - (void*)&Vflag;
  Yfj5fo[9].off = (void*)&sf - (void*)&Vflag1;
  Yfj5fo[10].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Yfj5fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=2956000;
 if ((Yun4 != NULL))
 {
  sf.pos=2956001;
  Yl0k(YAMW(Yun4));
 }
 sf.pos=2956002;
 Yl0k(((Tc*)&YaBy));
 sf.pos=2956003;
 VallFlags = Y7be;
 sf.pos=2956004;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys(YBQy, 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=2956005;
  Vflag = ZDictGetIobj(YBQy, (Tz)(void*)Vkey1);
  sf.pos=2956006;
  if (((*(Tc**)(Vflag.ptr + (size_t)Vflag.table[1])) == NULL))
  {
   sf.pos=2956007;
   *ZDictGetIobjP(VallFlags, (Tz)(void*)(*(Tc**)(Vflag.ptr + (size_t)Vflag.table[2]))) = Vflag;
  }
  sf.pos=2956008;
  }
 }
 VmaxLeadLen = 0;
 sf.pos=2956009;
 {
  Ti Vdisplay;
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&bool__T, 2), ZLap((Tl*)t0, (Tz)(Ti)0), ZLap((Tl*)t0, (Tz)(Ti)1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vdisplay;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=2956010;
  if (Vdisplay)
  {
   sf.pos=2956011;
   YTlu(((Tc*)&YwXF), VmaxLeadLen);
   sf.pos=2956012;
   Yl0k(((Tc*)&YEcf));
  }
  sf.pos=2956013;
  {
   Tfl Zf2i;
   Zf2 = ZstringListSort(ZDictKeys(VallFlags, 0), 1);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vkey;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Tb Vopt;
   sf.pos=2956014;
   Vflag1 = ZDictGetIobj(VallFlags, (Tz)(void*)Vkey);
   sf.pos=2956015;
   VargText = ((Tc*)&Ya);
   Vopt = 0;
   sf.pos=2956016;
   if ((Vflag1).type == 1)
   {
    sf.pos=2956017;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956018;
     VargText = ((Tc*)&Yy2p);
    }
    else
    {
     sf.pos=2956019;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956020;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956021;
 if ((Vflag1).type == 2)
   {
    sf.pos=2956022;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956023;
     VargText = ((Tc*)&YanE);
    }
    else
    {
     sf.pos=2956024;
     VargText = (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4]));
    }
    sf.pos=2956025;
    Vopt = (*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[8]));
   }
   else {
   sf.pos=2956026;
 if ((Vflag1).type == 3)
   {
    sf.pos=2956027;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])) == NULL))
    {
     sf.pos=2956028;
     VargText = ((Tc*)&YDci);
    }
    else
    {
     sf.pos=2956029;
     VargText = ZcS((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[4])), ((Tc*)&YulU));
    }
    sf.pos=2956030;
    Vopt = 1;
   }
   }}
   sf.pos=2956031;
   if ((ZbyteStringSize(VargText) != 0))
   {
    sf.pos=2956032;
    if (Vopt)
    {
     sf.pos=2956033;
     VargText = ZcS3(((Tc*)&YVZ), VargText, ((Tc*)&YEa));
    }
    else
    {
     sf.pos=2956034;
     VargText = ZcS3(((Tc*)&Yq_), VargText, ((Tc*)&Y9a));
    }
   }
   sf.pos=2956035;
   Vlead = ((Tc*)&Ya);
   sf.pos=2956036;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])) != NULL))
   {
    sf.pos=2956037;
    Vlead = ZcS5(((Tc*)&YT), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[1])), VargText, ((Tc*)&YG), (Tc*)1);
   }
   sf.pos=2956038;
   if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])) != NULL))
   {
    sf.pos=2956039;
    if (((ZbyteStringSize(Vlead) != 0) && (ZbyteStringSize(VargText) != 0)))
    {
     sf.pos=2956040;
     if (Vdisplay)
     {
      sf.pos=2956041;
      if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
      {
       sf.pos=2956042;
       Vlead =  ZcS(Vlead, ((Tc*)&Y_y2));
      }
      sf.pos=2956043;
      Yl0k(Vlead);
     }
     sf.pos=2956044;
     Vlead = ((Tc*)&Ya);
    }
    sf.pos=2956045;
    Vlead =  ZcS(Vlead, ZcS5(((Tc*)&Y1ia), (*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[2])), VargText, ((Tc*)&YG), (Tc*)1));
   }
   sf.pos=2956046;
   if ((*(Tb*)(Vflag1.ptr + (size_t)Vflag1.table[6])))
   {
    sf.pos=2956047;
    Vlead =  ZcS(Vlead, ((Tc*)&Y2yA));
   }
   sf.pos=2956048;
   if (Vdisplay)
   {
    sf.pos=2956049;
    if (((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])) != NULL))
    {
     sf.pos=2956050;
     YTlu(Vlead, VmaxLeadLen);
     sf.pos=2956051;
     Yl0k((*(Tc**)(Vflag1.ptr + (size_t)Vflag1.table[3])));
    }
    else
    {
     sf.pos=2956052;
     Yl0k(Vlead);
    }
    sf.pos=2956053;
    if (Averbose)
    {
     sf.pos=2956054;
     YTlu(((Tc*)&Ya), VmaxLeadLen);
     sf.pos=2956055;
     Yl0k(ZcS(((Tc*)&Ym4c), YpI_((*(YkxB**)(Vflag1.ptr + (size_t)Vflag1.table[9])))));
    }
   }
   else
   {
    sf.pos=2956056;
    if ((VmaxLeadLen < ZstringSize(Vlead)))
    {
     sf.pos=2956057;
     VmaxLeadLen = ZstringSize(Vlead);
    }
    sf.pos=2956058;
    if ((VmaxLeadLen > 30))
    {
     sf.pos=2956059;
     VmaxLeadLen = 30;
     rt = 2;
     goto YAEw;
    }
YAEw:
    if (rt) goto Yfan;
   }
Yfan:
   if (rt == 2) { rt &= 1; break; }
   sf.pos=2956060;
   }
  }
  sf.pos=2956061;
  }
 }
 sf.pos=2956062;
 Zexit(Ypp_a(NULL, ((Tc*)&Yzoka), 564, 5), YMLU);
 e->topFrame = sf.prev;
 return;
}
Zfo YTlufo[2] = {{0,(Tt*)&string__T},{0,0}};
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YTlufo[0].off = (void*)&sf - (void*)&Alead;
 }
 sf.frof = YTlufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8179800;
 Yvcu(Alead);
 sf.pos=8179801;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(ZstringSize(Alead), AmaxLeadLen, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=8179802;
  Yvcu(((Tc*)&YG));
  sf.pos=8179803;
  }
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YAMWfo[4] = {{0,(Tt*)&YuMQ__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YAMWfo[0].off = (void*)&sf - (void*)&t;
  YAMWfo[1].off = (void*)&sf - (void*)&t0;
  YAMWfo[2].off = (void*)&sf - (void*)&t1;
 }
 sf.frof = YAMWfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4300000;
  ZthrowThisNil();
 }
 sf.pos=4300001;
 Vidx = ZstringFind(t->Vtext, ((Tc*)&YMtG), 0);
 sf.pos=4300002;
 if ((Vidx < 0))
 {
  sf.pos=4300003;
  r = t->Vtext;
  rt = 1;
  goto YZtK;
 }
 sf.pos=4300004;
 r = ZcS3(ZstringSlice(t->Vtext, 0, (Vidx - 1), 0), YzvW, (t0 = ZstringSlice(t->Vtext, (Vidx + 3), -1, 0)));
YZtK:
 e->topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
char *StrYuMQ[] = {
 "text",
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, StrYuMQ, 0, 0, 0, 0, ToYuMQ};
Zfo YttTfo[5] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YttTfo[0].off = (void*)&sf - (void*)&t;
  YttTfo[1].off = (void*)&sf - (void*)&Adoc;
  YttTfo[2].off = (void*)&sf - (void*)&AshortName;
  YttTfo[3].off = (void*)&sf - (void*)&AlongName;
 }
 sf.frof = YttTfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Za(sizeof(Y86c));}
 sf.pos=327301;
 Y86c__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=327302;
 t->Vcurrent = Adefault;
 sf.pos=327303;
 t->Vdefault = Adefault;
 sf.pos=327304;
 t->VcanRepeat = 1;
 e->topFrame = sf.prev;
 return t;
}
Zfo YEqoafo[2] = {{0,(Tt*)&Y86c__T},{0,0}};
void YEqoa(Y86c *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YEqoafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YEqoafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3891100;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
Tb YHoR(Y86c *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->Vcurrent;
 return r;
}
Zfo Y86c__YcLufo[7] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y86c__YcLufo[0].off = (void*)&sf - (void*)&t;
  Y86c__YcLufo[1].off = (void*)&sf - (void*)&Adoc;
  Y86c__YcLufo[2].off = (void*)&sf - (void*)&AshortName;
  Y86c__YcLufo[3].off = (void*)&sf - (void*)&Apos;
  Y86c__YcLufo[4].off = (void*)&sf - (void*)&AlongName;
  Y86c__YcLufo[5].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y86c__YcLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=7664400; t = Za(sizeof(Y86c));}
 sf.pos=7664401;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=7664402;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664403;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=7664404;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=7664405;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=7664406;
  t->VshortName = AshortName;
 }
 sf.pos=7664407;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=7664408;
  t->VlongName = AlongName;
 }
 sf.pos=7664409;
 t->Vdoc = Adoc;
 sf.pos=7664410;
 if ((Y7be == NULL))
 {
  sf.pos=7664411;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=7664412;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=7664413;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=7664414;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=7664415;
   Y86c__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=7664416;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664417;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=7664418;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=7664419;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=7664420;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=7664421;
   Y86c__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=7664422;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, Y86c__YuQR_I_imt, 0));
 }
 sf.pos=7664423;
 t->Vpos = Apos;
 e->topFrame = sf.prev;
 return t;
}
Zfo Y86c__YofPfo[8] = {{0,(Tt*)&Y86c__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y_CE = NULL;
 void *p1;
 Tr ex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y86c__YofPfo[0].off = (void*)&sf - (void*)&t;
  Y86c__YofPfo[1].off = (void*)&sf - (void*)&Aname;
  Y86c__YofPfo[2].off = (void*)&sf - (void*)&Aflag;
  Y86c__YofPfo[3].off = (void*)&sf - (void*)&Apos;
  Y86c__YofPfo[4].off = (void*)&sf - (void*)&VonePos;
  Y86c__YofPfo[5].off = (void*)&sf - (void*)&Ve;
  Y86c__YofPfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y86c__YofPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=7569700;
  ZthrowThisNil();
 }
 sf.pos=7569701;
 VonePos = ((p1 = ((Y_CE = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), Y_CE == NULL ? NULL : YpI_(Y_CE)))) == NULL ? (((Tc*)&YbbH)) : p1);
 sf.pos=7569702;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=7569703;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Tc *Y86c__YuQR_I_imt[] = {
 (Tc*)&Y86c__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)Y86c__YcLu, /* MARGModule__CBool.NEW - Y86c__YcLu */
 (Tc*)Y86c__YofP, /* MARGModule__CBool.throwDuplicate - Y86c__YofP */
 (Tc*)0, /* MARGModule__CBool.setArgName - Y86c__Y836 */
 (Tc*)0, /* MARGModule__CBool.disableCompact - Y86c__YJbb */
 (Tc*)0, /* MARGModule__CBool.optionalArg - Y86c__YxuH */
 (Tc*)0, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
};
To ToY86c[] = {
 {11, 0},
 {0, (Tt*)&bool__T}, /* current */
 {0, (Tt*)&bool__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrY86c[] = {
 "current",
 "default",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, StrY86c, 0, 0, 0, 0, ToY86c};
Zfo Y49gafo[2] = {{0,(Tt*)&YJQu__T},{0,0}};
void Y49ga(YJQu *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y49gafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y49gafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1635000;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
To ToYJQu[] = {
 {12, 0},
 {0, (Tt*)&int__T}, /* current */
 {0, (Tt*)&int__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrYJQu[] = {
 "current",
 "default",
 "theValueList",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, StrYJQu, 0, 0, 0, 0, ToYJQu};
Zfo YBtkfo[6] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,0}};
YzqH *YBtk(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adefault, Tc *Adoc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YBtkfo[0].off = (void*)&sf - (void*)&t;
  YBtkfo[1].off = (void*)&sf - (void*)&Adoc;
  YBtkfo[2].off = (void*)&sf - (void*)&AshortName;
  YBtkfo[3].off = (void*)&sf - (void*)&Adefault;
  YBtkfo[4].off = (void*)&sf - (void*)&AlongName;
 }
 sf.frof = YBtkfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=8063600; t = Za(sizeof(YzqH));}
 sf.pos=8063601;
 YzqH__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=8063602;
 t->Vcurrent = Adefault;
 sf.pos=8063603;
 t->Vdefault = Adefault;
 sf.pos=8063604;
 t->VtheValueList = ZnewList((Tt*)&string__T, 0);
 e->topFrame = sf.prev;
 return t;
}
Zfo YJazafo[2] = {{0,(Tt*)&YzqH__T},{0,0}};
void YJaza(YzqH *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJazafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YJazafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8620600;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
Zfo YzqH__YcLufo[7] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&string__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,0}};
YzqH *YzqH__YcLu(YzqH *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzqH__YcLufo[0].off = (void*)&sf - (void*)&t;
  YzqH__YcLufo[1].off = (void*)&sf - (void*)&Adoc;
  YzqH__YcLufo[2].off = (void*)&sf - (void*)&AshortName;
  YzqH__YcLufo[3].off = (void*)&sf - (void*)&Apos;
  YzqH__YcLufo[4].off = (void*)&sf - (void*)&AlongName;
  YzqH__YcLufo[5].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzqH__YcLufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=483900; t = Za(sizeof(YzqH));}
 sf.pos=483901;
 if ((Y6fX != NULL))
 {
  Tr ex;
  sf.pos=483902;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Yc_h)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=483903;
 if (((((AshortName == NULL) || (ZbyteStringSize(AshortName) == 0))) && (((AlongName == NULL) || (ZbyteStringSize(AlongName) == 0)))))
 {
  Tr ex;
  sf.pos=483904;
  *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y6pY)), YVNj__Ytlm_I_imt, 7);
  ZthrowIobject(ex);
 }
 sf.pos=483905;
 if ((ZbyteStringSize(AshortName) != 0))
 {
  sf.pos=483906;
  t->VshortName = AshortName;
 }
 sf.pos=483907;
 if ((ZbyteStringSize(AlongName) != 0))
 {
  sf.pos=483908;
  t->VlongName = AlongName;
 }
 sf.pos=483909;
 t->Vdoc = Adoc;
 sf.pos=483910;
 if ((Y7be == NULL))
 {
  sf.pos=483911;
  Y7be = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
  sf.pos=483912;
  YBQy = ZnewDict((Tt*)&string__T, (Tt*)&iobj__T, 0);
 }
 sf.pos=483913;
 if (((AlongName != NULL) && (ZbyteStringSize(AlongName) != 0)))
 {
  sf.pos=483914;
  if (ZDictHas(YBQy, (Tz)(void*)AlongName))
  {
   sf.pos=483915;
   YzqH__YofP(t, AlongName, ZDictGetIobj(YBQy, (Tz)(void*)AlongName), Apos);
  }
  sf.pos=483916;
  ZDictAddTzIobj(0, YBQy, (Tz)(void*)AlongName, *Znao(&t0, t, YzqH__YuQR_I_imt, 2));
 }
 sf.pos=483917;
 if (((AshortName != NULL) && (ZbyteStringSize(AshortName) != 0)))
 {
  sf.pos=483918;
  if ((ZstringSize(AshortName) > 1))
  {
   Tr ex;
   sf.pos=483919;
   *Znao(&ex, YVNj__YwtA__YRHR(NULL, ((Tc*)&Y9CP)), YVNj__Ytlm_I_imt, 7);
   ZthrowIobject(ex);
  }
  sf.pos=483920;
  if (ZDictHas(Y7be, (Tz)(void*)AshortName))
  {
   sf.pos=483921;
   YzqH__YofP(t, AshortName, ZDictGetIobj(Y7be, (Tz)(void*)AshortName), Apos);
  }
  sf.pos=483922;
  ZDictAddTzIobj(0, Y7be, (Tz)(void*)AshortName, *Znao(&t0, t, YzqH__YuQR_I_imt, 2));
 }
 sf.pos=483923;
 t->Vpos = Apos;
 e->topFrame = sf.prev;
 return t;
}
Zfo YzqH__YofPfo[8] = {{0,(Tt*)&YzqH__T},{0,(Tt*)&string__T},{0,(Tt*)&iobj__T},{0,(Tt*)&YkxB__T},{0,(Tt*)&string__T},{0,(Tt*)&YVNj__T},{0,(Tt*)&iobj__T},{0,0}};
void YzqH__YofP(YzqH *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *YVCw = NULL;
 void *p2;
 Tr ex;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzqH__YofPfo[0].off = (void*)&sf - (void*)&t;
  YzqH__YofPfo[1].off = (void*)&sf - (void*)&Aname;
  YzqH__YofPfo[2].off = (void*)&sf - (void*)&Aflag;
  YzqH__YofPfo[3].off = (void*)&sf - (void*)&Apos;
  YzqH__YofPfo[4].off = (void*)&sf - (void*)&VonePos;
  YzqH__YofPfo[5].off = (void*)&sf - (void*)&Ve;
  YzqH__YofPfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YzqH__YofPfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5264800;
  ZthrowThisNil();
 }
 sf.pos=5264801;
 VonePos = ((p2 = ((YVCw = (*(YkxB**)(Aflag.ptr + (size_t)Aflag.table[9])), YVCw == NULL ? NULL : YpI_(YVCw)))) == NULL ? (((Tc*)&YbbH)) : p2);
 sf.pos=5264802;
 Ve = YVNj__YwtA__YRHRa(NULL, Apos, ZcS5(((Tc*)&YtzG), Aname, ((Tc*)&YDyy), VonePos, (Tc*)1));
 sf.pos=5264803;
 *Znao(&ex, Ve, YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
Tr YzqH__Y836(YzqH *t, Tc *AargName) {
 Tr r = {NULL};
 Tr t0 = {NULL};
 if (t == NULL) {
   ZthrowThisNil();
 }
 YS39();
 t->VargName = AargName;
 r = *Znao(&t0, t, YzqH__YuQR_I_imt, 2);
 return r;
}
Tc *YzqH__YuQR_I_imt[] = {
 (Tc*)&YzqH__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YzqH__YcLu, /* MARGModule__CString.NEW - YzqH__YcLu */
 (Tc*)YzqH__YofP, /* MARGModule__CString.throwDuplicate - YzqH__YofP */
 (Tc*)YzqH__Y836, /* MARGModule__CString.setArgName - YzqH__Y836 */
 (Tc*)0, /* MARGModule__CString.disableCompact - YzqH__YJbb */
 (Tc*)0, /* MARGModule__CString.optionalArg - YzqH__YxuH */
 (Tc*)0, /* MARGModule__CString.presentCount - YzqH__Ye9f */
 (Tc*)0, /* MARGModule__CString.present - YzqH__Y8Dq */
 (Tc*)YJaza, /* MARGModule__CString.setToDefault - YJaza */
 (Tc*)0, /* Init - YzqHa */
};
To ToYzqH[] = {
 {12, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrYzqH[] = {
 "current",
 "default",
 "theValueList",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, StrYzqH, 0, 0, 0, 0, ToYzqH};
Zfo YSkKafo[2] = {{0,(Tt*)&Y_SI__T},{0,0}};
void YSkKa(Y_SI *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YSkKafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YSkKafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6447800;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 e->topFrame = sf.prev;
 return;
}
To ToY_SI[] = {
 {11, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&int__T}, /* setCount */
 {0, (Tt*)&bool__T}, /* canRepeat */
 {0, (Tt*)&bool__T}, /* noCompactVal */
 {0, (Tt*)&bool__T}, /* argOpt */
 {0, (Tt*)&YkxB__T}, /* pos */
};
char *StrY_SI[] = {
 "current",
 "default",
 "shortName",
 "longName",
 "doc",
 "argName",
 "setCount",
 "canRepeat",
 "noCompactVal",
 "argOpt",
 "pos",
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, StrY_SI, 0, 0, 0, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Tn *e = ZgetEnv();
  Zsf sf;
  sf.prev = e->topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  e->topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  e->topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
/* including INTModule bodies */
Zfo YrLYfo[2] = {{0,(Tt*)&YjUM__T},{0,0}};
Tc *YrLY(Ti Athis) {
 Ti Vr;
 Ti VbeforeQuote;
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YrLYfo[0].off = (void*)&sf - (void*)&Vw;
 }
 sf.frof = YrLYfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=470600;
 if ((Athis == 0))
 {
  sf.pos=470601;
  r = ((Tc*)&YW);
  rt = 1;
  goto Y4ed;
 }
 sf.pos=470602;
 Vw = Za(sizeof(YjUM));
 sf.pos=470603;
 Vr = (((Athis > 0)) ? (Athis) : (-(Athis)));
 sf.pos=470604;
 VbeforeQuote = 3;
 sf.pos=470605;
 while ((Vr > 0))
 {
  Ti Vn;
  sf.pos=470606;
  if ((VbeforeQuote == 0))
  {
   sf.pos=470607;
   YjUM__Ydti(Vw, 39);
   sf.pos=470608;
   VbeforeQuote = 3;
  }
  sf.pos=470609;
  Vn = (Vr % 10);
  sf.pos=470610;
  YJqza(Vw, Zint2string(Vn));
  sf.pos=470611;
  Vr = (Vr / 10);
  sf.pos=470612;
  --(VbeforeQuote);
 sf.pos=470613;
 }
 sf.pos=470614;
 if ((Athis < 0))
 {
  sf.pos=470615;
  YjUM__Ydti(Vw, 45);
 }
 sf.pos=470616;
 r = YO0w(YbNW(Vw));
Y4ed:
 e->topFrame = sf.prev;
 return r;
}
/* INTModule done */
/* including GarbageThread bodies */
void Y70b() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=9184400;
 Yl0k(((Tc*)&Y64ea));
 sf.pos=9184401;
 Y7To();
 e->topFrame = sf.prev;
 return;
}
Zfo Y7Tofo[3] = {{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
void Y7To() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vtd = {NULL};
 Tr Vtgc = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y7Tofo[0].off = (void*)&sf - (void*)&Vtd;
  Y7Tofo[1].off = (void*)&sf - (void*)&Vtgc;
 }
 sf.frof = Y7Tofo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5852200;
 Vtd = Zao(Yydu(NULL, (&ZCB_Y3Zw)), YTgs__YTgs_I_imt, 0);
 sf.pos=5852201;
 ((void (*)(void*))(Vtd.table[6]))(Vtd.ptr);
 sf.pos=5852202;
 Vtgc = Zao(Yydu(NULL, (&ZCB_YEVk)), YTgs__YTgs_I_imt, 0);
 sf.pos=5852203;
 ((void (*)(void*))(Vtgc.table[6]))(Vtgc.ptr);
 sf.pos=5852204;
 ((void (*)(void*))(Vtd.table[7]))(Vtd.ptr);
 sf.pos=5852205;
 ((void (*)(void*))(Vtgc.table[7]))(Vtgc.ptr);
 e->topFrame = sf.prev;
 return;
}
Zfo Y3Zwfo[3] = {{0,(Tt*)&dict__T},{0,(Tt*)&list__T},{0,0}};
void Y3Zw() {
 Ti Vr;
 Tn *e = ZgetEnv();
 Zsf sf;
 Td *Vd = NULL;
 Tl *Zf2 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y3Zwfo[0].off = (void*)&sf - (void*)&Vd;
  Y3Zwfo[1].off = (void*)&sf - (void*)&Zf2;
 }
 sf.frof = Y3Zwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=1649000;
 Yl0k(((Tc*)&YtAM));
 sf.pos=1649001;
 YTHZ = 1;
 sf.pos=1649002;
 Vd = ZnewDict((Tt*)&int__T, (Tt*)&string__T, 0);
 sf.pos=1649003;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(0, 1000, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=1649004;
  ZDictAdd(0, Vd, (Tz)(Ti)Vi, (Tz)(void*)ZcS(((Tc*)&Y2a), Zint2string(Vi)));
  sf.pos=1649005;
  }
 }
 Vr = 0;
 sf.pos=1649006;
 {
  Ti Vl;
  Tfr Zf1;
  ZforRangeNew(1, 100, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vl); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vl)) {
  sf.pos=1649007;
  {
   Ti Vkey;
   Tfl Zf2i;
   Zf2 = ZDictKeys(Vd, 0);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vkey;
   Zf2i.i = 0;
   for (; ZforListIntCont(&Zf2i); ) {
   sf.pos=1649008;
   ++(Vr);
   sf.pos=1649009;
   }
  }
  sf.pos=1649010;
  }
 }
 sf.pos=1649011;
 Yl0k(ZcS3(((Tc*)&YgYB), Zint2string(Vr), ((Tc*)&Yace)));
 e->topFrame = sf.prev;
 return;
}
void YEVk() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5780300;
 while (!(YTHZ))
 {
  sf.pos=5780301;
  YQzL(100);
 sf.pos=5780302;
 }
 sf.pos=5780303;
 Yl0k(((Tc*)&YvOX));
 sf.pos=5780304;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(0, 40, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=5780305;
  YnFG();
  sf.pos=5780306;
  YQzL(2000);
  sf.pos=5780307;
  }
 }
 sf.pos=5780308;
 Yl0k(((Tc*)&YQNE));
 e->topFrame = sf.prev;
 return;
}
/* GarbageThread done */
/* including HttpTest bodies */
void YqeF() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=18300;
 Yl0k(((Tc*)&YSp9a));
 sf.pos=18301;
 Y7aq();
 e->topFrame = sf.prev;
 return;
}
Zfo Y7aqfo[8] = {{0,(Tt*)&Y1QG__T},{0,(Tt*)&string__T},{0,(Tt*)&YX8j__T},{0,(Tt*)&string__T},{0,(Tt*)&YIgO__T},{0,(Tt*)&YzRH__T},{0,(Tt*)&iobj__T},{0,0}};
Zfo Yz8ufo[2] = {{0,(Tt*)&YtzZ__T},{0,0}};
Tc *Yz8u(YtzZ *Acontext) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Yz8ufo[0].off = (void*)&sf - (void*)&Acontext;
 }
 sf.frof = Yz8ufo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6962600;
 r = ((Tc*)&YMUL);
 e->topFrame = sf.prev;
 return r;
}
void Y7aq() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Y1QG *Vserver = 0;
 Tc *Vexe = NULL;
 YX8j *Vfs = 0;
 Tc *Vhello = NULL;
 YIgO *Vss = 0;
 YzRH *Vps = 0;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y7aqfo[0].off = (void*)&sf - (void*)&Vserver;
  Y7aqfo[1].off = (void*)&sf - (void*)&Vexe;
  Y7aqfo[2].off = (void*)&sf - (void*)&Vfs;
  Y7aqfo[3].off = (void*)&sf - (void*)&Vhello;
  Y7aqfo[4].off = (void*)&sf - (void*)&Vss;
  Y7aqfo[5].off = (void*)&sf - (void*)&Vps;
  Y7aqfo[6].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = Y7aqfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7781600;
 Vserver = YAvl(NULL, 8888);
 sf.pos=7781601;
 Vexe = Y2R7;
 sf.pos=7781602;
 Yj9O(Vserver, ZcS(ZstringSlice(Vexe, 0, YN1T(Vexe), 0), ((Tc*)&YE7m)));
 sf.pos=7781603;
 Vfs = Yb5K(NULL, ((Tc*)&YyGk));
 sf.pos=7781604;
 YX8j__Y3fn(Vfs, ((Tc*)&YyGk));
 sf.pos=7781605;
 YX8j__Y3fn(Vfs, ((Tc*)&Y7lu));
 sf.pos=7781606;
 YkIq(Vfs, ((Tc*)&YyGk));
 sf.pos=7781607;
 Yb8i(Vserver, *Znao(&t0, Vfs, YX8j__YtrZ_I_imt, 1));
 sf.pos=7781608;
 Vfs = Yb5K(NULL, ((Tc*)&Y7pn));
 sf.pos=7781609;
 YX8j__Y3fn(Vfs, ((Tc*)&Y7pn));
 sf.pos=7781610;
 YX8j__YuzN(Vfs, ((Tc*)&YJVW));
 sf.pos=7781611;
 Yb8i(Vserver, *Znao(&t0, Vfs, YX8j__YtrZ_I_imt, 1));
 sf.pos=7781612;
 Vhello = ((Tc*)&YaaL);
 sf.pos=7781613;
 Vss = Y543(NULL, Vhello);
 sf.pos=7781614;
 YIgO__Y3fn(Vss, ((Tc*)&YvoF));
 sf.pos=7781615;
 Yb8i(Vserver, *Znao(&t0, Vss, YIgO__YtrZ_I_imt, 2));
 sf.pos=7781616;
 Vps = YDye(NULL, (&ZCB_Yz8u));
 sf.pos=7781617;
 YzRH__Y3fn(Vps, ((Tc*)&YiFm));
 sf.pos=7781618;
 Yb8i(Vserver, *Znao(&t0, Vps, YzRH__YtrZ_I_imt, 3));
 sf.pos=7781619;
 Y1QG__YTgs__YSuw(Vserver);
 sf.pos=7781620;
 Y6ye(Vss, ((Tc*)&YatH));
 e->topFrame = sf.prev;
 return;
}
/* HttpTest done */
/* including PipeTest bodies */
void YyHq() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8478900;
 Yl0k(((Tc*)&Yzipa));
 sf.pos=8478901;
 YXS6();
 sf.pos=8478902;
 YWS6();
 sf.pos=8478903;
 YVS6();
 e->topFrame = sf.prev;
 return;
}
Zfo YvfCfo[2] = {{0,(Tt*)&string__T},{0,0}};
void YvfC() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Vs = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YvfCfo[0].off = (void*)&sf - (void*)&Vs;
 }
 sf.frof = YvfCfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6660600;
 while (1)
 {
  Ts Vst;
  Vst = 0;
  sf.pos=6660601;
  Vs = YNqf(YZxe, &(Vst));
  sf.pos=6660602;
  if ((Vst == 0))
  {
   rt = 2;
   goto Ynzd;
  }
  sf.pos=6660603;
  Yl0k(Vs);
Ynzd:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6660604;
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YXS6fo[5] = {{0,(Tt*)&iobj__T},{0,(Tt*)&list__T},{0,(Tt*)&string__T},{0,(Tt*)&list__T},{0,0}};
void YXS6() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vt = {NULL};
 Tl *Zf1 = NULL;
 Tc *Vday = NULL;
 Tl *t0 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YXS6fo[0].off = (void*)&sf - (void*)&Vt;
  YXS6fo[1].off = (void*)&sf - (void*)&Zf1;
  YXS6fo[2].off = (void*)&sf - (void*)&Vday;
  YXS6fo[3].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YXS6fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6484600;
 YZxe = YqaL(NULL);
 sf.pos=6484601;
 Vt = Zao(Yydu(NULL, (&ZCB_YvfC)), YTgs__YTgs_I_imt, 0);
 sf.pos=6484602;
 ((void (*)(void*))(Vt.table[6]))(Vt.ptr);
 sf.pos=6484603;
 {
  Tfl Zf1i;
  Zf1 = (t0 = ZnewList((Tt*)&string__T, 5), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YLUk)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YG2C)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YMlK)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y5IC)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y2Z2)));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vday;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=6484604;
  YVE3(YZxe, Vday);
  sf.pos=6484605;
  }
 }
 sf.pos=6484606;
 YQCO(YZxe);
 sf.pos=6484607;
 ((void (*)(void*))(Vt.table[7]))(Vt.ptr);
 e->topFrame = sf.prev;
 return;
}
Zfo YWS6fo[6] = {{0,(Tt*)&string__T},{0,(Tt*)&YRg3__T},{0,(Tt*)&YJ7s__T},{0,(Tt*)&YJ7s__T},{0,(Tt*)&YJ7s__T},{0,0}};
Tc *Lambda6() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = ((Tc*)&Y2d1);
 e->topFrame = sf.prev;
 return r;
}
Tc *Lambda8() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = ((Tc*)&YjYu);
 e->topFrame = sf.prev;
 return r;
}
Tc *Y2BS() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7372700;
 Yl0k(((Tc*)&Y0Oa));
 sf.pos=7372701;
 r = ((Tc*)&Ygt4);
 e->topFrame = sf.prev;
 return r;
}
void YWS6() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Vs = NULL;
 YRg3 *Vt = 0;
 YJ7s *Vtp = 0;
 YJ7s *Vps = 0;
 YJ7s *Vtp2 = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YWS6fo[0].off = (void*)&sf - (void*)&Vs;
  YWS6fo[1].off = (void*)&sf - (void*)&Vt;
  YWS6fo[2].off = (void*)&sf - (void*)&Vtp;
  YWS6fo[3].off = (void*)&sf - (void*)&Vps;
  YWS6fo[4].off = (void*)&sf - (void*)&Vtp2;
 }
 sf.frof = YWS6fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7504700;
 Vt = YRg3__YCVY(NULL);
 sf.pos=7504701;
 Vtp = YFiE(Vt, (&ZCB_Lambda6));
 sf.pos=7504702;
 Yl0k(ZcS(((Tc*)&Y6Tz), YNqfa(Vtp)));
 sf.pos=7504703;
 Vs = YNqfa(Vtp);
 sf.pos=7504704;
 if ((Vs == NULL))
 {
  sf.pos=7504705;
  Vs = ((Tc*)&ZNilString);
 }
 sf.pos=7504706;
 Yl0k(ZcS(((Tc*)&Y6Tz), Vs));
 sf.pos=7504707;
 Vtp2 = YaWJ((&ZCB_Lambda8));
 sf.pos=7504708;
 Yl0k(ZcS(((Tc*)&YhhK), YNqfa(Vtp2)));
 sf.pos=7504709;
 Vps = Y21D((&ZCB_Y2BS));
 sf.pos=7504710;
 Yl0k(ZcS(((Tc*)&YNM5), YNqfa(Vps)));
 e->topFrame = sf.prev;
 return;
}
Zfo YVS6fo[4] = {{0,(Tt*)&string__T},{0,(Tt*)&cb__T},{0,(Tt*)&YJ7s__T},{0,0}};
Zfo Lambda11fo[2] = {{0,(Tt*)&string__T},{0,0}};
Tc *Lambda11(Tc *A0) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Lambda11fo[0].off = (void*)&sf - (void*)&A0;
 }
 sf.frof = Lambda11fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = ZcS(((Tc*)&YGL5), A0);
 e->topFrame = sf.prev;
 return r;
}
YG3z *ZaYG3z(YG3z *p, void *t, Tt *tt, Tcb *cb, Tc * arg1) {
 YG3z *r = p == NULL ? Za(sizeof(YG3z)) : p;
 r->cfunc = ZcbYG3z;
 r->toCount = 2;
 r->t = t;
 r->cb = cb;
 r->arg1 = arg1;
 r->to[0].off = (void*)(&r->arg1) - (void*)r;
 r->to[0].type = (Tt*)&string__T;
 r->to[1].off = (void*)(&r->t) - (void*)r;
 r->to[1].type = tt;
 return r;
}
Tc* ZcbYG3z(YG3z *cb) {
 if (cb->t) return ((Tc* (*)(Tcb *, void *, Tc*))cb->cb->cfunc)(cb->cb, cb->t, cb->arg1);
 else return ((Tc* (*)(Tcb *, Tc*))cb->cb->cfunc)(cb->cb, cb->arg1);
}
void YVS6() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *Vm = NULL;
 Tcb *Vf = 0;
 YJ7s *Vsp = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YVS6fo[0].off = (void*)&sf - (void*)&Vm;
  YVS6fo[1].off = (void*)&sf - (void*)&Vf;
  YVS6fo[2].off = (void*)&sf - (void*)&Vsp;
 }
 sf.frof = YVS6fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8524800;
 Vm = ((Tc*)&YjQE);
 sf.pos=8524801;
 Vsp = YFiE(YRg3__YCVY(NULL), (Tcb*)ZaYG3z(NULL, NULL, NULL, (&ZCB_Lambda11), Vm));
 sf.pos=8524802;
 Yl0k(YNqfa(Vsp));
 sf.pos=8524803;
 Vf = YNml();
 sf.pos=8524804;
 Vsp = YFiE(YRg3__YCVY(NULL), Vf);
 sf.pos=8524805;
 Yl0k(YNqfa(Vsp));
 e->topFrame = sf.prev;
 return;
}
Zfo YNmlfo[2] = {{0,(Tt*)&Tstring__T},{0,0}};
Tc *Lambda1(Tc* *R0) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tc *r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = ZcS(((Tc*)&YGL5), (*R0));
 e->topFrame = sf.prev;
 return r;
}
YRKg *ZaYRKg(YRKg *p, void *t, Tt *tt, Tcb *cb, Tstring * arg1) {
 YRKg *r = p == NULL ? Za(sizeof(YRKg)) : p;
 r->cfunc = ZcbYRKg;
 r->toCount = 2;
 r->t = t;
 r->cb = cb;
 r->arg1 = arg1;
 r->to[0].off = (void*)(&r->arg1) - (void*)r;
 r->to[0].type = (Tt*)&Tstring__T;
 r->to[1].off = (void*)(&r->t) - (void*)r;
 r->to[1].type = tt;
 return r;
}
Tc* ZcbYRKg(YRKg *cb) {
 if (cb->t) return ((Tc* (*)(Tcb *, void *, Tc**))cb->cb->cfunc)(cb->cb, cb->t, &cb->arg1->Vm);
 else return ((Tc* (*)(Tcb *, Tc**))cb->cb->cfunc)(cb->cb, &cb->arg1->Vm);
}
Tcb *YNml() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tcb *r = 0;
 Tstring *Vm = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YNmlfo[0].off = (void*)&sf - (void*)&Vm;
 }
 sf.frof = YNmlfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=4070500;
 sf.pos=4070501;
 Vm = Za(sizeof(Tstring));
 Vm->Vm = ((Tc*)&YUAN);
 sf.pos=4070502;
 r = (Tcb*)ZaYRKg(NULL, NULL, NULL, (&ZCB_Lambda1), Vm);
 e->topFrame = sf.prev;
 return r;
}
/* PipeTest done */
/* including ThreadTest bodies */
/* including Ticker bodies */
Zfo YIZffo[2] = {{0,(Tt*)&Yeip__T},{0,0}};
Yeip *YIZf(Yeip *t, Ti Areaders) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YIZffo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YIZffo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=6466300; t = Yeipa(NULL);}
 sf.pos=6466301;
 t->VcurrentTick = 1;
 sf.pos=6466302;
 t->VreaderTicks = ZnewList((Tt*)&int__T, 0);
 sf.pos=6466303;
 {
  Ti Vidx;
  Tfr Zf1;
  ZforRangeNew(0, (Areaders - 1), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vidx); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vidx)) {
  sf.pos=6466304;
  ZLap((Tl*)t->VreaderTicks, (Tz)(Ti)0);
  sf.pos=6466305;
  }
 }
 e->topFrame = sf.prev;
 return t;
}
Zfo Ye8Wfo[3] = {{0,(Tt*)&Yeip__T},{0,(Tt*)&YXJh__T},{0,0}};
YXJh *Ye8W(Yeip *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 YXJh *r = 0;
 YXJh *Vr = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Ye8Wfo[0].off = (void*)&sf - (void*)&t;
  Ye8Wfo[1].off = (void*)&sf - (void*)&Vr;
 }
 sf.frof = Ye8Wfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=5119100;
  ZthrowThisNil();
 }
 sf.pos=5119101;
 YHl9(t->VtickLock);
 sf.pos=5119102;
 if ((t->VreaderIndex >= ZListSize(t->VreaderTicks)))
 {
  sf.pos=5119103;
  Yl0k(((Tc*)&YWaW));
 }
 sf.pos=5119104;
 Vr = Y4GK(NULL, (t->VreaderIndex)++, t);
 sf.pos=5119105;
 Yvoo(t->VtickLock);
 sf.pos=5119106;
 r = Vr;
 e->topFrame = sf.prev;
 return r;
}
Zfo YJxcfo[3] = {{0,(Tt*)&Yeip__T},{0,(Tt*)&list__T},{0,0}};
void YJxc(Yeip *t, Ti Aticks) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf3 = NULL;
 static int sfF = 0;
 int rt = 0;
 if (!sfF) {
  sfF = 1;
  YJxcfo[0].off = (void*)&sf - (void*)&t;
  YJxcfo[1].off = (void*)&sf - (void*)&Zf3;
 }
 sf.frof = YJxcfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6770900;
  ZthrowThisNil();
 }
 sf.pos=6770901;
 while ((t->VcurrentTick < Aticks))
 {
  sf.pos=6770902;
  while (1)
  {
   Tb Vdone;
   sf.pos=6770903;
   Vdone = 1;
   sf.pos=6770904;
   {
    Ti Vr;
    Tfl Zf3i;
    Zf3 = t->VreaderTicks;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vr;
    Zf3i.i = 0;
    for (; ZforListIntCont(&Zf3i); ) {
    sf.pos=6770905;
    if ((Vr < t->VcurrentTick))
    {
     sf.pos=6770906;
     Vdone = 0;
     rt = 2;
     goto YzCq;
    }
YzCq:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=6770907;
    }
   }
   sf.pos=6770908;
   if (Vdone)
   {
    rt = 2;
    goto YUCC;
   }
   sf.pos=6770909;
   YQzL(222);
YUCC:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=6770910;
  }
  sf.pos=6770911;
  ++(t->VcurrentTick);
 sf.pos=6770912;
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y4GKfo[3] = {{0,(Tt*)&YXJh__T},{0,(Tt*)&Yeip__T},{0,0}};
YXJh *Y4GK(YXJh *t, Ti Aindex, Yeip *Aticker) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y4GKfo[0].off = (void*)&sf - (void*)&t;
  Y4GKfo[1].off = (void*)&sf - (void*)&Aticker;
 }
 sf.frof = Y4GKfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=760000; t = Za(sizeof(YXJh));}
 sf.pos=760001;
 t->Vindex = Aindex;
 sf.pos=760002;
 t->Vticker = Aticker;
 e->topFrame = sf.prev;
 return t;
}
Zfo YCaRfo[2] = {{0,(Tt*)&YXJh__T},{0,0}};
void YCaR(YXJh *t, Ti Atick) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YCaRfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YCaRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=6961300;
  ZthrowThisNil();
 }
 sf.pos=6961301;
 while ((t->Vticker->VcurrentTick < Atick))
 {
  sf.pos=6961302;
  *(Ti*)ZListGetIntP(t->Vticker->VreaderTicks, t->Vindex) = t->Vticker->VcurrentTick;
  sf.pos=6961303;
  YQzL(200);
 sf.pos=6961304;
 }
 e->topFrame = sf.prev;
 return;
}
Zfo Y1Flfo[2] = {{0,(Tt*)&YXJh__T},{0,0}};
void Y1Fl(YXJh *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y1Flfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Y1Flfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=4409200;
  ZthrowThisNil();
 }
 sf.pos=4409201;
 *(Ti*)ZListGetIntP(t->Vticker->VreaderTicks, t->Vindex) = Y64n;
 e->topFrame = sf.prev;
 return;
}
To ToYXJh[] = {
 {2, 0},
 {0, (Tt*)&int__T}, /* index */
 {0, (Tt*)&Yeip__T}, /* ticker */
};
char *StrYXJh[] = {
 "index",
 "ticker",
};
Tto YXJh__T = {390, (Tc*)&Y0Er, 0, StrYXJh, 0, 0, 0, 0, ToYXJh};
Zfo Yeipafo[2] = {{0,(Tt*)&Yeip__T},{0,0}};
Yeip *Yeipa(Yeip *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (t == NULL) t = Za(sizeof(Yeip));
 if (!sfF) {
  sfF = 1;
  Yeipafo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = Yeipafo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5612100;
 t->VtickLock = YCyl(NULL);
 e->topFrame = sf.prev;
 return t;
}
To ToYeip[] = {
 {4, 0},
 {0, (Tt*)&int__T}, /* currentTick */
 {0, (Tt*)&list__T}, /* readerTicks */
 {0, (Tt*)&int__T}, /* readerIndex */
 {0, (Tt*)&YlXt__T}, /* tickLock */
};
char *StrYeip[] = {
 "currentTick",
 "readerTicks",
 "readerIndex",
 "tickLock",
};
Tto Yeip__T = {390, (Tc*)&YaZC, 0, StrYeip, 0, 0, 0, 0, ToYeip};
/* Ticker done */
void YW3f() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=715500;
 Yl0k(((Tc*)&Y9pua));
 sf.pos=715501;
 YJqh();
 sf.pos=715502;
 YIqh();
 sf.pos=715503;
 YHqh();
 sf.pos=715504;
 YGqh();
 sf.pos=715505;
 YqfF();
 e->topFrame = sf.prev;
 return;
}
Zfo YzIqfo[2] = {{0,(Tt*)&YXJh__T},{0,0}};
void YzIq() {
 Tn *e = ZgetEnv();
 Zsf sf;
 YXJh *Vtr = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YzIqfo[0].off = (void*)&sf - (void*)&Vtr;
 }
 sf.frof = YzIqfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=536900;
 Vtr = Ye8W(YIHB);
 sf.pos=536901;
 Yl0k(((Tc*)&YYNZ));
 sf.pos=536902;
 YCaR(Vtr, 5);
 sf.pos=536903;
 Yl0k(((Tc*)&YmMZ));
 sf.pos=536904;
 YCaR(Vtr, 10);
 sf.pos=536905;
 Yl0k(((Tc*)&YLKZ));
 e->topFrame = sf.prev;
 return;
}
Zfo YOdRfo[2] = {{0,(Tt*)&YXJh__T},{0,0}};
void YOdR() {
 Tn *e = ZgetEnv();
 Zsf sf;
 YXJh *Vtr = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YOdRfo[0].off = (void*)&sf - (void*)&Vtr;
 }
 sf.frof = YOdRfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=1169300;
 Vtr = Ye8W(YIHB);
 sf.pos=1169301;
 YCaR(Vtr, 3);
 sf.pos=1169302;
 Yl0k(((Tc*)&YCc8));
 sf.pos=1169303;
 YCaR(Vtr, 7);
 sf.pos=1169304;
 Yl0k(((Tc*)&Yde8));
 sf.pos=1169305;
 Y1Fl(Vtr);
 e->topFrame = sf.prev;
 return;
}
Zfo YJqhfo[3] = {{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
void YJqh() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vt1 = {NULL};
 Tr Vt2 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YJqhfo[0].off = (void*)&sf - (void*)&Vt1;
  YJqhfo[1].off = (void*)&sf - (void*)&Vt2;
 }
 sf.frof = YJqhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6582800;
 YIHB = YIZf(NULL, 2);
 sf.pos=6582801;
 Vt1 = Zao(Yydu(NULL, (&ZCB_YzIq)), YTgs__YTgs_I_imt, 0);
 sf.pos=6582802;
 (*(Tc**)(Vt1.ptr + (size_t)Vt1.table[15])) = ((Tc*)&YR0p);
 sf.pos=6582803;
 ((void (*)(void*))(Vt1.table[6]))(Vt1.ptr);
 sf.pos=6582804;
 Vt2 = Zao(YTgs__YCVY(NULL), YTgs__YTgs_I_imt, 0);
 sf.pos=6582805;
 (*(Tc**)(Vt2.ptr + (size_t)Vt2.table[15])) = ((Tc*)&Y25C);
 sf.pos=6582806;
 ((void (*)(void*, Tcb*))(Vt2.table[13]))(Vt2.ptr, (&ZCB_YOdR));
 sf.pos=6582807;
 ((void (*)(void*))(Vt2.table[6]))(Vt2.ptr);
 sf.pos=6582808;
 YJxc(YIHB, 8);
 sf.pos=6582809;
 ((void (*)(void*))(Vt1.table[8]))(Vt1.ptr);
 sf.pos=6582810;
 ((void (*)(void*))(Vt2.table[7]))(Vt2.ptr);
 e->topFrame = sf.prev;
 return;
}
Zfo Y_r7fo[2] = {{0,(Tt*)&YXJh__T},{0,0}};
void Y_r7() {
 Tn *e = ZgetEnv();
 Zsf sf;
 YXJh *Vtr = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  Y_r7fo[0].off = (void*)&sf - (void*)&Vtr;
 }
 sf.frof = Y_r7fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=5058100;
 Vtr = Ye8W(YIHB);
 sf.pos=5058101;
 YCaR(Vtr, 2);
 sf.pos=5058102;
 Yl0k(((Tc*)&YCHu));
 sf.pos=5058103;
 Y1Fl(Vtr);
 e->topFrame = sf.prev;
 return;
}
void YIqh() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=7602900;
 YIHB = YIZf(NULL, 1);
 sf.pos=7602901;
 YTgs__YSuw(Yydu(NULL, (&ZCB_Y_r7)));
 sf.pos=7602902;
 Yl0k(((Tc*)&YSzJ));
 sf.pos=7602903;
 YJxc(YIHB, 4);
 e->topFrame = sf.prev;
 return;
}
Zfo YPz8afo[3] = {{0,(Tt*)&YjmP__T},{0,(Tt*)&YXJh__T},{0,0}};
void YPz8a(YjmP *t) {
 Ti Vtick;
 Tn *e = ZgetEnv();
 Zsf sf;
 YXJh *Vtr = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YPz8afo[0].off = (void*)&sf - (void*)&t;
  YPz8afo[1].off = (void*)&sf - (void*)&Vtr;
 }
 sf.frof = YPz8afo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=8076200;
  ZthrowThisNil();
 }
 sf.pos=8076201;
 Vtick = 0;
 sf.pos=8076202;
 Vtr = Ye8W(YIHB);
 sf.pos=8076203;
 while (1)
 {
  sf.pos=8076204;
  Vtick += 3;
  sf.pos=8076205;
  YCaR(Vtr, Vtick);
  sf.pos=8076206;
  Yl0k(ZcS(((Tc*)&YFOE), Zint2string(Vtick)));
 sf.pos=8076207;
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YjmP__YTgs__YCVYfo[2] = {{0,(Tt*)&YjmP__T},{0,0}};
YjmP *YjmP__YTgs__YCVY(YjmP *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__YCVYfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjmP__YTgs__YCVYfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {sf.pos=9540700; t = ZaF(sizeof(YjmP), ToYjmP, (Ts (*)(void*, Te))YjmP__YTgs__Y2Cz, 0);}
 e->topFrame = sf.prev;
 return t;
}
Zfo YjmP__YTgs__Y7C8fo[3] = {{0,(Tt*)&YjmP__T},{0,(Tt*)&list__T},{0,0}};
void YjmP__YTgs__Y7C8(YjmP *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tl *Zf1 = NULL;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__Y7C8fo[0].off = (void*)&sf - (void*)&t;
  YjmP__YTgs__Y7C8fo[1].off = (void*)&sf - (void*)&Zf1;
 }
 sf.frof = YjmP__YTgs__Y7C8fo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=3987708;
  ZthrowThisNil();
 }
 sf.pos=3987709;
 int i = 0;
 Zsf *prev = NULL;
 e->startFrames = calloc(1, ZListSize(t->Vstack) * sizeof(Zsf));
 sf.pos=3987710;
 {
  Ti Vpos;
  Tfl Zf1i;
  Zf1 = t->Vstack;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpos;
  Zf1i.i = 0;
  for (; ZforListIntCont(&Zf1i); ) {
  sf.pos=3987711;
 e->startFrames[i].pos = Vpos;
 e->startFrames[i].prev = prev;
 prev = &e->startFrames[i];
 ++i;
  sf.pos=3987712;
  }
 }
 sf.pos=3987713;
 sf.prev = prev;
 sf.pos=3987714;
 pthread_mutex_lock(&threadsMutex);
 ZLa(threads, -1, (Tz)(void*)e);
 pthread_mutex_unlock(&threadsMutex);
 sf.pos=3987715;
 YPz8a(t);

 e->finished = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YjmP__YTgs__YSuwfo[3] = {{0,(Tt*)&YjmP__T},{0,(Tt*)&iobj__T},{0,0}};
void YjmP__YTgs__YSuw(YjmP *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr t0 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__YSuwfo[0].off = (void*)&sf - (void*)&t;
  YjmP__YTgs__YSuwfo[1].off = (void*)&sf - (void*)&t0;
 }
 sf.frof = YjmP__YTgs__YSuwfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2210312;
  ZthrowThisNil();
 }
 sf.pos=2210313;
 Zsf *top = e->topFrame;
 sf.pos=2210314;
 t->Vstack = ZnewList((Tt*)&int__T, 0);
 sf.pos=2210315;
 while ((ZListSize(t->Vstack) < 30))
 {
  Ti Ventry;
  Ventry = 0;
  sf.pos=2210316;
  if (top == NULL) break;
  Ventry = top->pos;
  top = top->prev;
  sf.pos=2210317;
  ZListInsert((Tl*)t->Vstack, 0, (Tz)(Ti)Ventry);
 sf.pos=2210318;
 }
 sf.pos=2210319;
 if (pthread_create(&t->Vthread_id, NULL, (void *(*)(void *))YjmP__YTgs__Y7C8, t) != 0) {
 sf.pos=2210320;
 if (1)
 {
  Tr ex;
  sf.pos=2210321;
  *Znao(&ex, YgC4__YwtA__YRHR(NULL, ((Tc*)&YgzQ)), YgC4__Ytlm_I_imt, 30);
  ZthrowIobject(ex);
 }
 sf.pos=2210322;
 }
 {
  int oldstate;
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, &oldstate);
 }
 sf.pos=2210323;
 t->Vstate = 1;
 e->topFrame = sf.prev;
 return;
}
Zfo YjmP__YTgs__YSfifo[2] = {{0,(Tt*)&YjmP__T},{0,0}};
void YjmP__YTgs__YSfi(YjmP *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__YSfifo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjmP__YTgs__YSfifo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=2168204;
  ZthrowThisNil();
 }
 sf.pos=2168205;
 if (pthread_join(t->Vthread_id, NULL) != 0) {
 sf.pos=2168206;
  ZthrowThread(Zstr("wait()"));
 }
 sf.pos=2168207;
 t->Vstate = 2;
 e->topFrame = sf.prev;
 return;
}
Zfo YjmP__YTgs__YDFpfo[2] = {{0,(Tt*)&YjmP__T},{0,0}};
void YjmP__YTgs__YDFp(YjmP *t) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__YDFpfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjmP__YTgs__YDFpfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=413303;
  ZthrowThisNil();
 }
 sf.pos=413304;
 if (pthread_cancel(t->Vthread_id) != 0) {
 sf.pos=413305;
  ZthrowThread(Zstr("kill()"));
 }
 e->topFrame = sf.prev;
 return;
}
Zfo YjmP__YTgs__Y2Czfo[2] = {{0,(Tt*)&YjmP__T},{0,0}};
Ts YjmP__YTgs__Y2Cz(YjmP *t, Te _fr) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YTgs__Y2Czfo[0].off = (void*)&sf - (void*)&t;
 }
 sf.frof = YjmP__YTgs__Y2Czfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=9628203;
  ZthrowThisNil();
 }
 sf.pos=9628204;
 pthread_detach(t->Vthread_id);
 sf.pos=9628205;
 r = 1;
 e->topFrame = sf.prev;
 return r;
}
Zfo YjmP__YqOJfo[3] = {{0,(Tt*)&YjmP__T},{0,(Tt*)&cb__T},{0,0}};
void YjmP__YqOJ(YjmP *t, Tcb *Aproc) {
 Tn *e = ZgetEnv();
 Zsf sf;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YjmP__YqOJfo[0].off = (void*)&sf - (void*)&t;
  YjmP__YqOJfo[1].off = (void*)&sf - (void*)&Aproc;
 }
 sf.frof = YjmP__YqOJfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 if (t == NULL) {
  sf.pos=1316702;
  ZthrowThisNil();
 }
 sf.pos=1316703;
 t->Vproc = Aproc;
 e->topFrame = sf.prev;
 return;
}
To ToYjmP[] = {
 {4, 0},
 {0, (Tt*)&cb__T}, /* proc */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&MTHREADModule__EState__T}, /* state */
 {0, (Tt*)&list__T}, /* stack */
};
char *StrYjmP[] = {
 "proc",
 "name",
 "state",
 "stack",
};
Tto YjmP__T = {390, (Tc*)&YooJ, 0, StrYjmP, 0, YjmP__YTgs__Y2Cz, 0, 0, ToYjmP};
Zfo YHqhfo[2] = {{0,(Tt*)&YjmP__T},{0,0}};
void YHqh() {
 Tn *e = ZgetEnv();
 Zsf sf;
 YjmP *Vt = 0;
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YHqhfo[0].off = (void*)&sf - (void*)&Vt;
 }
 sf.frof = YHqhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=8623000;
 Yl0k(((Tc*)&Yyxf));
 sf.pos=8623001;
 YIHB = YIZf(NULL, 1);
 sf.pos=8623002;
 Vt = YjmP__YTgs__YCVY(NULL);
 sf.pos=8623003;
 Vt->Vname = ((Tc*)&Yp8I);
 sf.pos=8623004;
 YjmP__YTgs__YSuw(Vt);
 sf.pos=8623005;
 YJxc(YIHB, 7);
 sf.pos=8623006;
 YjmP__YTgs__YDFp(Vt);
 e->topFrame = sf.prev;
 return;
}
Zfo YGqhfo[3] = {{0,(Tt*)&iobj__T},{0,(Tt*)&iobj__T},{0,0}};
Ts Lambda3() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ts r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = Yl0k(((Tc*)&Yobe));
 e->topFrame = sf.prev;
 return r;
}
void YFvG() {
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=2967400;
 Yl0k(((Tc*)&Y8pV));
 e->topFrame = sf.prev;
 return;
}
void YGqh() {
 Tn *e = ZgetEnv();
 Zsf sf;
 Tr Vt = {NULL};
 Tr Vtt = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YGqhfo[0].off = (void*)&sf - (void*)&Vt;
  YGqhfo[1].off = (void*)&sf - (void*)&Vtt;
 }
 sf.frof = YGqhfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=9643200;
 Vt = Zao(Yydua(NULL, (&ZCB_Lambda3)), YTgs__YTgs_I_imt, 0);
 sf.pos=9643201;
 ((void (*)(void*))(Vt.table[6]))(Vt.ptr);
 sf.pos=9643202;
 ((void (*)(void*))(Vt.table[7]))(Vt.ptr);
 sf.pos=9643203;
 Vtt = Zao(Yydu(NULL, (&ZCB_YFvG)), YTgs__YTgs_I_imt, 0);
 sf.pos=9643204;
 ((void (*)(void*))(Vtt.table[6]))(Vtt.ptr);
 sf.pos=9643205;
 ((void (*)(void*))(Vtt.table[7]))(Vtt.ptr);
 e->topFrame = sf.prev;
 return;
}
Zfo YqfFfo[4] = {{0,(Tt*)&YlXt__T},{0,(Tt*)&YTJ0__T},{0,(Tt*)&YTJ0__T},{0,0}};
void YqfF() {
 Tn *e = ZgetEnv();
 Zsf sf;
 YlXt *VtheLock = 0;
 YTJ0 Val = {NULL};
 YTJ0 Val1 = {NULL};
 static int sfF = 0;
 if (!sfF) {
  sfF = 1;
  YqfFfo[0].off = (void*)&sf - (void*)&VtheLock;
  YqfFfo[1].off = 1 + (int)((void*)&sf - (void*)&Val);
  YqfFfo[2].off = 1 + (int)((void*)&sf - (void*)&Val1);
 }
 sf.frof = YqfFfo;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 sf.pos=6166100;
 VtheLock = YCyl(NULL);
 {
  sf.pos=6166101;
  YDpw(ZnoAllocClear(sizeof(YTJ0), &Val, (Ts (*)(void*, Te))YKWW, NULL), VtheLock);
  sf.pos=6166102;
  Yl0k(((Tc*)&YJhU));
   sf.pos=6166103;
  if (Val.np != NULL) {YKWW(&Val, 2); Val.np = NULL;}
 }
 sf.pos=6166104;
 Yl0k(((Tc*)&Ybkv));
 {
  sf.pos=6166105;
  YDpw(ZnoAllocClear(sizeof(YTJ0), &Val1, (Ts (*)(void*, Te))YKWW, NULL), VtheLock);
  sf.pos=6166106;
  Yl0k(((Tc*)&YMAI));
   sf.pos=6166107;
  if (Val1.np != NULL) {YKWW(&Val1, 2); Val1.np = NULL;}
 }
 sf.pos=6166108;
 Yl0k(((Tc*)&YLdK));
 e->topFrame = sf.prev;
 return;
}
/* ThreadTest done */
Tc* ZcbLambda1(Tcb *cb, Tc* *arg0) {
return Lambda1(arg0);
}
Tc* ZcbLambda11(Tcb *cb, Tc *arg0) {
return Lambda11(arg0);
}
Ts ZcbLambda3(Tcb *cb) {
return Lambda3();
}
Tc* ZcbLambda6(Tcb *cb) {
return Lambda6();
}
Tc* ZcbLambda8(Tcb *cb) {
return Lambda8();
}
Tc* ZcbY2BS(Tcb *cb) {
return Y2BS();
}
void ZcbY3Zw(Tcb *cb) {
Y3Zw();
}
void ZcbYEVk(Tcb *cb) {
YEVk();
}
void ZcbYFvG(Tcb *cb) {
YFvG();
}
void ZcbYOdR(Tcb *cb) {
YOdR();
}
void ZcbY_r7(Tcb *cb) {
Y_r7();
}
void ZcbYvfC(Tcb *cb) {
YvfC();
}
Tc* ZcbYz8u(Tcb *cb, YtzZ *arg0) {
return Yz8u(arg0);
}
void ZcbYzIq(Tcb *cb) {
YzIq();
}
/*
 * INIT IMT
 */
void ZimtInit(void) {
 {
  Ytlm *p = 0;
  Ytlm__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Ytlm__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Ytlm__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYtlm[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtlm[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtlm[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YEro *p = 0;
  YEro__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YEro__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YEro__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYEro[1].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[4].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YKhn *p = 0;
  YKhn__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YKhn__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YKhn__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYKhn[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYKhn[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYKhn[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y1uN *p = 0;
  Y1uN__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y1uN__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y1uN__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY1uN[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY1uN[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY1uN[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YAxe *p = 0;
  YAxe__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YAxe__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YAxe__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYAxe[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYAxe[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYAxe[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YVNj *p = 0;
  YVNj__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YVNj__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YVNj__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYVNj[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYVNj[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYVNj[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yalz *p = 0;
  Yalz__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yalz__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yalz__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYalz[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYalz[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYalz[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Yw3O *p = 0;
  Yw3O__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Yw3O__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Yw3O__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYw3O[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYw3O[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYw3O[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  Y2EX *p = 0;
  Y2EX__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  Y2EX__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  Y2EX__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToY2EX[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToY2EX[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToY2EX[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YX0i *p = 0;
  YX0i__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YX0i__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YX0i__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYX0i[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYX0i[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYX0i[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YzSI *p = 0;
  YzSI__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YzSI__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YzSI__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYzSI[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYzSI[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYzSI[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YXKl *p = 0;
  YXKl__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YXKl__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YXKl__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYXKl[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYXKl[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYXKl[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YuDC *p = 0;
  YuDC__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YuDC__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YuDC__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYuDC[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYuDC[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYuDC[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YqzO *p = 0;
  YqzO__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YqzO__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YqzO__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYqzO[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYqzO[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYqzO[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YrHq *p = 0;
  YrHq__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYrHq[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYrHq[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYrHq[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YK7s *p = 0;
  ToYK7s[1].off = (int)((Tc*)&p->VisOpen - (Tc*)p);
  ToYK7s[2].off = (int)((Tc*)&p->VbufferSize - (Tc*)p);
  ToYK7s[3].off = (int)((Tc*)&p->VitemList - (Tc*)p);
  ToYK7s[4].off = (int)((Tc*)&p->Vlock - (Tc*)p);
  ToYK7s[5].off = (int)((Tc*)&p->VreadCond - (Tc*)p);
  ToYK7s[6].off = (int)((Tc*)&p->VwriteCond - (Tc*)p);
 }
 {
  YJ7s *p = 0;
  ToYJ7s[1].off = (int)((Tc*)&p->VisOpen - (Tc*)p);
  ToYJ7s[2].off = (int)((Tc*)&p->VbufferSize - (Tc*)p);
  ToYJ7s[3].off = (int)((Tc*)&p->VitemList - (Tc*)p);
  ToYJ7s[4].off = (int)((Tc*)&p->Vlock - (Tc*)p);
  ToYJ7s[5].off = (int)((Tc*)&p->VreadCond - (Tc*)p);
  ToYJ7s[6].off = (int)((Tc*)&p->VwriteCond - (Tc*)p);
 }
 {
  YSM1 *p = 0;
  ToYSM1[1].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYSM1[2].off = (int)((Tc*)&p->Vpath - (Tc*)p);
  ToYSM1[3].off = (int)((Tc*)&p->Vparams - (Tc*)p);
  ToYSM1[4].off = (int)((Tc*)&p->VhttpVersion - (Tc*)p);
  ToYSM1[5].off = (int)((Tc*)&p->VheaderItems - (Tc*)p);
  ToYSM1[6].off = (int)((Tc*)&p->Vbody - (Tc*)p);
 }
 {
  YKeB *p = 0;
  ToYKeB[1].off = (int)((Tc*)&p->Vcode - (Tc*)p);
  ToYKeB[2].off = (int)((Tc*)&p->Vmsg - (Tc*)p);
  ToYKeB[3].off = (int)((Tc*)&p->VheaderItems - (Tc*)p);
  ToYKeB[4].off = (int)((Tc*)&p->Vbody - (Tc*)p);
 }
 {
  YtzZ *p = 0;
  ToYtzZ[1].off = (int)((Tc*)&p->Vserver - (Tc*)p);
  ToYtzZ[2].off = (int)((Tc*)&p->Vrequest - (Tc*)p);
  ToYtzZ[3].off = (int)((Tc*)&p->Vresponse - (Tc*)p);
 }
 {
  YX8j *p = 0;
  YX8j__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YX8j__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YX8j__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYX8j[1].off = (int)((Tc*)&p->VfileName - (Tc*)p);
  ToYX8j[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYX8j[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYX8j[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  YIgO *p = 0;
  YIgO__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YIgO__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YIgO__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYIgO[1].off = (int)((Tc*)&p->Vbody - (Tc*)p);
  ToYIgO[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYIgO[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYIgO[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  YzRH *p = 0;
  YzRH__YtrZ_I_imt[1] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YzRH__YtrZ_I_imt[2] = (Tc*)((Tc*)&p->Vpaths - (Tc*)p);
  YzRH__YtrZ_I_imt[3] = (Tc*)((Tc*)&p->VmimeType - (Tc*)p);
  ToYzRH[1].off = (int)((Tc*)&p->VserveFunc - (Tc*)p);
  ToYzRH[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYzRH[3].off = (int)((Tc*)&p->Vpaths - (Tc*)p);
  ToYzRH[4].off = (int)((Tc*)&p->VmimeType - (Tc*)p);
 }
 {
  Y1QG *p = 0;
  ToY1QG[1].off = (int)((Tc*)&p->Vport - (Tc*)p);
  ToY1QG[2].off = (int)((Tc*)&p->VlistenQueueLen - (Tc*)p);
  ToY1QG[3].off = (int)((Tc*)&p->Vservlets - (Tc*)p);
  ToY1QG[4].off = (int)((Tc*)&p->VfileRoot - (Tc*)p);
  ToY1QG[5].off = (int)((Tc*)&p->Vbase - (Tc*)p);
  ToY1QG[6].off = (int)((Tc*)&p->Vverbosity - (Tc*)p);
  ToY1QG[7].off = (int)((Tc*)&p->VquitPipe - (Tc*)p);
  ToY1QG[8].off = (int)((Tc*)&p->VdidQuit - (Tc*)p);
  ToY1QG[9].off = (int)((Tc*)&p->Vbusy - (Tc*)p);
  ToY1QG[10].off = (int)((Tc*)&p->Vproc - (Tc*)p);
  ToY1QG[11].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToY1QG[12].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToY1QG[13].off = (int)((Tc*)&p->Vstack - (Tc*)p);
 }
 {
  YkxB *p = 0;
  ToYkxB[1].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYkxB[2].off = (int)((Tc*)&p->Vlnum - (Tc*)p);
  ToYkxB[3].off = (int)((Tc*)&p->Vcol - (Tc*)p);
  ToYkxB[4].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->VsLen - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[3].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  YXAF *p = 0;
  ToYXAF[1].off = (int)((Tc*)&p->VstwTime - (Tc*)p);
  ToYXAF[2].off = (int)((Tc*)&p->VmarkTime - (Tc*)p);
  ToYXAF[3].off = (int)((Tc*)&p->VfreeTime - (Tc*)p);
  ToYXAF[4].off = (int)((Tc*)&p->VtotalTime - (Tc*)p);
  ToYXAF[5].off = (int)((Tc*)&p->VuseCount - (Tc*)p);
  ToYXAF[6].off = (int)((Tc*)&p->VfreeCount - (Tc*)p);
 }
 {
  YgC4 *p = 0;
  YgC4__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YgC4__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YgC4__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYgC4[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYgC4[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYgC4[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YTgs *p = 0;
  YTgs__YTgs_I_imt[11] = (Tc*)((Tc*)&p->Vproc - (Tc*)p);
  YTgs__YTgs_I_imt[15] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  YTgs__YTgs_I_imt[16] = (Tc*)((Tc*)&p->Vstate - (Tc*)p);
  YTgs__YTgs_I_imt[18] = (Tc*)((Tc*)&p->Vthread_id - (Tc*)p);
  YTgs__YTgs_I_imt[19] = (Tc*)((Tc*)&p->Vstack - (Tc*)p);
  ToYTgs[1].off = (int)((Tc*)&p->Vproc - (Tc*)p);
  ToYTgs[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYTgs[3].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToYTgs[4].off = (int)((Tc*)&p->Vstack - (Tc*)p);
 }
 {
  YRg3 *p = 0;
  ToYRg3[1].off = (int)((Tc*)&p->VevalFunc - (Tc*)p);
  ToYRg3[2].off = (int)((Tc*)&p->VresultPipe - (Tc*)p);
  ToYRg3[3].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYRg3[4].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToYRg3[5].off = (int)((Tc*)&p->Vstack - (Tc*)p);
 }
 {
  YTJ0 *p = 0;
  ToYTJ0[1].off = (int)((Tc*)&p->Vlock - (Tc*)p);
  ToYTJ0[2].off = (int)((Tc*)&p->VdidEnd - (Tc*)p);
 }
 {
  YuMQ *p = 0;
  ToYuMQ[1].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Y86c *p = 0;
  Y86c__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  Y86c__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  Y86c__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  Y86c__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  Y86c__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  Y86c__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  Y86c__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  Y86c__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  Y86c__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  ToY86c[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[7].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToY86c[8].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToY86c[9].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToY86c[10].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToY86c[11].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  ToYJQu[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[8].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToYJQu[9].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToYJQu[10].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToYJQu[11].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToYJQu[12].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  YzqH__YuQR_I_imt[1] = (Tc*)((Tc*)&p->VshortName - (Tc*)p);
  YzqH__YuQR_I_imt[2] = (Tc*)((Tc*)&p->VlongName - (Tc*)p);
  YzqH__YuQR_I_imt[3] = (Tc*)((Tc*)&p->Vdoc - (Tc*)p);
  YzqH__YuQR_I_imt[4] = (Tc*)((Tc*)&p->VargName - (Tc*)p);
  YzqH__YuQR_I_imt[5] = (Tc*)((Tc*)&p->VsetCount - (Tc*)p);
  YzqH__YuQR_I_imt[6] = (Tc*)((Tc*)&p->VcanRepeat - (Tc*)p);
  YzqH__YuQR_I_imt[7] = (Tc*)((Tc*)&p->VnoCompactVal - (Tc*)p);
  YzqH__YuQR_I_imt[8] = (Tc*)((Tc*)&p->VargOpt - (Tc*)p);
  YzqH__YuQR_I_imt[9] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToYzqH[9].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToYzqH[10].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToYzqH[11].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToYzqH[12].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->VsetCount - (Tc*)p);
  ToY_SI[8].off = (int)((Tc*)&p->VcanRepeat - (Tc*)p);
  ToY_SI[9].off = (int)((Tc*)&p->VnoCompactVal - (Tc*)p);
  ToY_SI[10].off = (int)((Tc*)&p->VargOpt - (Tc*)p);
  ToY_SI[11].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YXJh *p = 0;
  ToYXJh[1].off = (int)((Tc*)&p->Vindex - (Tc*)p);
  ToYXJh[2].off = (int)((Tc*)&p->Vticker - (Tc*)p);
 }
 {
  Yeip *p = 0;
  ToYeip[1].off = (int)((Tc*)&p->VcurrentTick - (Tc*)p);
  ToYeip[2].off = (int)((Tc*)&p->VreaderTicks - (Tc*)p);
  ToYeip[3].off = (int)((Tc*)&p->VreaderIndex - (Tc*)p);
  ToYeip[4].off = (int)((Tc*)&p->VtickLock - (Tc*)p);
 }
 {
  YjmP *p = 0;
  ToYjmP[1].off = (int)((Tc*)&p->Vproc - (Tc*)p);
  ToYjmP[2].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYjmP[3].off = (int)((Tc*)&p->Vstate - (Tc*)p);
  ToYjmP[4].off = (int)((Tc*)&p->Vstack - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Tn *e = ZgetEnv();
 Zsf sf;
 sf.prev = e->topFrame;
 sf.pos = 0;
 sf.frof = NULL;
 e->topFrame = &sf;
 done &= JIOModule(round);
 done &= JGCModule(round);
 done &= JTHREADModule(round);
 done &= JARGModule(round);
 if (round == 2001) {
 }
 e->topFrame = sf.prev;
 return done;
}

/*
 * MAIN
 */

#if defined(__MINGW32__) || defined(_MSC_VER)
# define CATCH_SIG(sig, func) signal(sig, func)
  typedef struct SEH_EXCEPTION_REGISTRATION_S SEH_EXCEPTION_REGISTRATION;
  struct SEH_EXCEPTION_REGISTRATION_S
  {
    SEH_EXCEPTION_REGISTRATION *prev;
    PEXCEPTION_HANDLER handler;
  };
  static EXCEPTION_DISPOSITION exception_handler(PEXCEPTION_RECORD pRecord, SEH_EXCEPTION_REGISTRATION *pReg, PCONTEXT pContext, PEXCEPTION_RECORD pRecord2) {
   Zdeadly(11);
   return ExceptionContinueSearch;
  }
#else
# define CATCH_SIG(sig, func) catch_sig(sig, func)
void catch_sig(int sig, void *func) {
 struct sigaction act;
 act.sa_handler = func;
 sigemptyset(&act.sa_mask);
 act.sa_flags = SA_NODEFER;
 sigaction(sig, &act, NULL);
}
#endif

int Fmain(void);
int main(int argc, char **argv) {
 int r = 0;
 int round = 0;
#if defined(__MINGW32__) || defined(_MSC_VER)
 SEH_EXCEPTION_REGISTRATION seh_er;
 seh_er.handler = (PEXCEPTION_HANDLER)(exception_handler);
 asm volatile ("movl %%fs:0, %0" : "=r" (seh_er.prev));
 asm volatile ("movl %0, %%fs:0" : : "r" (&seh_er));
#else
# ifdef SIGSEGV
 CATCH_SIG(SIGSEGV, Zdeadly);
# endif
# ifdef SIGBUS
 CATCH_SIG(SIGBUS, Zdeadly);
# endif
# ifdef SIGFPE
 CATCH_SIG(SIGFPE, Zdeadly);
# endif
#endif
#if defined(__MINGW32__) || defined(_MSC_VER)
# ifdef __MINGW32__
 _fmode = _O_BINARY;
# else
 _set_fmode(_O_BINARY);
# endif
 _setmode(_fileno(stdin), _O_BINARY);
 _setmode(_fileno(stdout), _O_BINARY);
 _setmode(_fileno(stderr), _O_BINARY);
#endif
 ZenvInit();
 emergencyAlloc = malloc(16384);
 ZimtInit();
 ZglobInit(round++);
 YzvW = Zstr(argv[0]);
 YQtK();
 Y1p3 = ZnewList(&string__T, 0);
 {
  int i;
  for (i = 1; i < argc; ++i) {
   ZLa(Y1p3, -1, (Tz)(void*)Zstr(argv[i]));
  }
 }

 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 1002) ZthrowCstringInit("Early initialization not done within 1000 rounds");
 }
 YZH8();

 round = 2001;
 ZglobInit(round++);
 while (!ZglobInit(round++)) {
  if (round == 3002) ZthrowCstringInit("Initialization not done within 1000 rounds");
 }
 r = Fmain();
 beforeExit();
 if (ZgetEnv()->topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}


int Fmain(void) {
 Tn *e = ZgetEnv();
 Zsf sf;
 Ti r = 0;
 sf.frof = NULL;
 sf.prev = e->topFrame;
 sf.pos = 0;
 e->topFrame = &sf;
 r = 0;
 sf.pos=527000;
 YW3f();
 sf.pos=527001;
 YyHq();
 sf.pos=527002;
 YqeF();
 sf.pos=527003;
 Y70b();
 sf.pos=527004;
 r = 0;
 e->topFrame = sf.prev;
 return r;
}
