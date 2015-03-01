/*
 * Generated from Zimbu file zudocu.zu
 */
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdio.h>
#include <signal.h>
#if defined(__MINGW32__) || defined(_MSC_VER)
# define GC_SIG SIGABRT
# include <excpt.h>
#else
# define GC_SIG SIGUSR2
#endif
#include <sys/time.h>
#include <time.h>

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
#define ZOH_OFF 0
typedef struct ZforString__S Tfs; /* FOR in string */
typedef struct ZforList__S Tfl; /* FOR in list */
typedef struct ZforDict__S Tfd; /* FOR in dict */
typedef struct ZforRange__S Tfr; /* FOR in range */

typedef struct CArray__S Ta; /* array head */

typedef struct CListHead__S Tl; /* list head */

typedef unsigned long Zhashtype;
typedef struct CDictItem__S CDictItem;
typedef struct CDictHead__S Td;

/* including TIMEModule typedefs */
typedef struct Y2KX__S Y2KX; /* MTIMEModule.Values */
/* TIMEModule done */
/* including EModule typedefs */
typedef struct Ytlm__S Ytlm; /* MEModule.Exception */
typedef struct YEro__S YEro; /* MEModule.Exit */
typedef struct YKhn__S YKhn; /* MEModule.OutOfMemory */
typedef struct Y1uN__S Y1uN; /* MEModule.NilAccess */
typedef struct YAxe__S YAxe; /* MEModule.MemoryAccess */
typedef struct YVNj__S YVNj; /* MEModule.Init */
typedef struct YtEE__S YtEE; /* MEModule.Check */
typedef struct Yalz__S Yalz; /* MEModule.BadValue */
typedef struct Yw3O__S Yw3O; /* MEModule.OutOfRange */
typedef struct Y2EX__S Y2EX; /* MEModule.KeyNotFound */
typedef struct YX0i__S YX0i; /* MEModule.KeyExists */
typedef struct YP_P__S YP_P; /* MEModule.IllegalByte */
typedef struct YzSI__S YzSI; /* MEModule.DivideByZero */
typedef struct YXKl__S YXKl; /* MEModule.IOError */
typedef struct YuDC__S YuDC; /* MEModule.WrongType */
typedef struct YrHq__S YrHq; /* MEModule.Internal */
/* EModule done */
/* including ZModule typedefs */
typedef struct YkxB__S YkxB; /* MZModule.Pos */
/* ZModule done */
/* including IOModule typedefs */
typedef struct Yw8L__S Yw8L; /* MIOModule.File */
typedef struct YjUM__S YjUM; /* MIOModule.StringWriter */
typedef struct YPto__S YPto; /* MIOModule.FileInfo */
/* IOModule done */
/* including SETModule typedefs */
typedef struct Yhqr__S Yhqr; /* MSETModule.Set__t1 */
/* SETModule done */
/* including SORTEDLISTModule typedefs */
typedef struct Yo7T__S Yo7T; /* MSORTEDLISTModule.SortedList__t1 */
typedef struct YKQB__S YKQB; /* MSORTEDLISTModule.SortedListIterator__t1 */
/* SORTEDLISTModule done */
/* including BOXModule typedefs */
typedef struct YyHo__S YyHo; /* MBOXModule.ListIterator__t1 */
/* BOXModule done */
/* including ARGModule typedefs */
typedef struct YnU5__S YnU5; /* MARGModule.Status */
typedef struct YuMQ__S YuMQ; /* MARGModule.Usage */
typedef struct Y86c__S Y86c; /* MARGModule.Bool */
typedef struct YJQu__S YJQu; /* MARGModule.Int */
typedef struct YzqH__S YzqH; /* MARGModule.String */
typedef struct Y_SI__S Y_SI; /* MARGModule.StringList */
/* ARGModule done */
/* including zui typedefs */
typedef struct Yol9__S Yol9; /* MZui.Contents */
typedef struct Yknz__S Yknz; /* MZui.SymbolRef */
typedef struct YqKm__S YqKm; /* MZui.Import */
typedef struct YYIi__S YYIi; /* MZui.Declaration */
typedef struct YRBza__S YRBza; /* MZui.Type */
typedef struct YJON__S YJON; /* MZui.Attributes */
typedef struct YftY__S YftY; /* MZui.ClassType */
typedef struct YfQg__S YfQg; /* MZui.BitsType */
typedef struct YFN2__S YFN2; /* MZui.EnumType */
typedef struct Y2wP__S Y2wP; /* MZui.ModuleType */
typedef struct Y7Np__S Y7Np; /* MZui.MethodType */
typedef struct YyfS__S YyfS; /* MZui.ContainerType */
typedef struct YoDF__S YoDF; /* MZui.AliasType */
typedef struct YhZL__S YhZL; /* MZui.CodeBlock */
typedef struct YXCg__S YXCg; /* MZui.Statement */
typedef struct YfBB__S YfBB; /* MZui.Include */
typedef struct Yq22__S Yq22; /* MZui.Assignment */
typedef struct Y5eh__S Y5eh; /* MZui.Condition */
typedef struct Yxh9__S Yxh9; /* MZui.ForStatement */
typedef struct Yy74__S Yy74; /* MZui.TryStatement */
typedef struct Ya9G__S Ya9G; /* MZui.Catch */
typedef struct YLuR__S YLuR; /* MZui.CBlock */
typedef struct YnZD__S YnZD; /* MZui.Expression */
typedef struct Y1p4__S Y1p4; /* MZui.Id */
typedef struct YYKi__S YYKi; /* MZui.ExprPair */
typedef struct YJFN__S YJFN; /* MZui.NameExpr */
typedef struct Y_1n__S Y_1n; /* MZui.MethodCall */
typedef struct Ysbp__S Ysbp; /* MZui.Position */
/* zui done */
/* including Parse typedefs */
/* including Input typedefs */
typedef struct YeYq__S YeYq; /* Input */
/* Input done */
/* including Token typedefs */
typedef struct Yev8__S Yev8; /* Token */
/* Token done */
/* including TokenInput typedefs */
/* including Tokenizer typedefs */
/* including ZuiFile typedefs */
typedef struct YgKE__S YgKE; /* ZuiFile */
/* ZuiFile done */
typedef struct YsZx__S YsZx; /* MTokenizer.Node */
/* Tokenizer done */
typedef struct Y7Sj__S Y7Sj; /* TokenInput */
/* TokenInput done */
typedef struct YL4o__S YL4o; /* MParse.ParseResult */
/* Parse done */
typedef struct YwDJ__S YwDJ; /* Page */
typedef struct YrBF__S YrBF; /* Parent */
typedef struct YT98__S YT98; /* SummaryEntry */
typedef struct YHCf__S YHCf; /* Summary */
typedef struct YaHa__S YaHa; /* DocItems */
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
struct ZforString__S {
 Tc *ptr;
 Ti idx;
 Ti len;
};
struct ZforList__S {
 Tl *l;
 Ti i;
 Ti *keyp;
 void *valp;
};
struct ZforDict__S {
 Td *d;
 CDictItem *di;
 Ti todo;
 void *keyp;
 void *valp;
};
struct ZforRange__S {
 Ti idx;
 Ti step;
 Ti last;
};

void ZthrowObject(Tr *eo);
void ZthrowIobject(Tr eo);

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
extern Tt array__T;
extern Tt list__T;
extern Tt dict__T;
extern Tt cb__T;
extern Tt iobj__T;
typedef struct {
 Yol9 * a0;
 YL4o * a1;
} YjS4;
typedef struct {
 Yev8 * a0;
 Yev8 * a1;
} YU01;
typedef struct {
 Tc * a0;
 Ysbp * a1;
} YLSh;

struct CArray__S {
 void *ptr;
 int dim;
 Ti size[3];
 Tt *itemType;
 int itemSize;
 int tosNr;
};
void ZfreeArray(Ta *head);
Ta *ZnewArray(Tt *itemType, int itemSize, Ti size);
struct CListHead__S {
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
YkxB *MZ__callerPos(void);

Tl *MZ__backtrace(Ti zkip, Ti limit);

YkxB *MZ__posnr2pos(YkxB *t, Ti pos);
typedef struct {
 char text[5];
} Zs5;
/* including TIMEModule structs */
typedef struct {
 char text[3];
} Zs3;
struct Y2KX__S {
 Ti Vusec;
 Ti Vsec;
 Ti Vmin;
 Ti Vhour;
 Ti Vday;
 Ti Vmonth;
 Ti Vyear;
 Ti VweekDay;
 Ti VyearDay;
 Te Vdst;
};
extern Tto Y2KX__T;
typedef struct {
 char text[8];
} Zs8;
/* TIMEModule done */
/* including EModule structs */
typedef struct {
 char text[4];
} Zs4;
typedef struct {
 char text[13];
} Zs13;
typedef struct {
 char text[11];
} Zs11;
typedef struct {
 char text[39];
} Zs39;
typedef struct {
 char text[12];
} Zs12;
struct Ytlm__S {
 Tc *Vmessage;
 YkxB *Vpos;
 Tl *Vbacktrace;
};
extern Tto Ytlm__T;
typedef struct {
 char text[7];
} Zs7;
struct YEro__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
 Ti Vvalue;
};
extern Tto YEro__T;
typedef struct {
 char text[6];
} Zs6;
typedef struct {
 char text[28];
} Zs28;
typedef struct {
 char text[9];
} Zs9;
struct YKhn__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YKhn__T;
struct Y1uN__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y1uN__T;
struct YAxe__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YAxe__T;
typedef struct {
 char text[14];
} Zs14;
struct YVNj__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YVNj__T;
struct YtEE__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YtEE__T;
struct Yalz__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yalz__T;
typedef struct {
 char text[10];
} Zs10;
struct Yw3O__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Yw3O__T;
struct Y2EX__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto Y2EX__T;
typedef struct {
 char text[17];
} Zs17;
typedef struct {
 char text[18];
} Zs18;
struct YX0i__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YX0i__T;
typedef struct {
 char text[22];
} Zs22;
typedef struct {
 char text[23];
} Zs23;
struct YP_P__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YP_P__T;
struct YzSI__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YzSI__T;
struct YXKl__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YXKl__T;
typedef struct {
 char text[15];
} Zs15;
struct YuDC__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YuDC__T;
struct YrHq__S {
Tc *Vmessage;
YkxB *Vpos;
Tl *Vbacktrace;
};
extern Tto YrHq__T;
/* EModule done */
/* including ZModule structs */
typedef struct {
 char text[16];
} Zs16;
struct YkxB__S {
 Tc *Vfilename;
 Ti Vlnum;
 Ti Vcol;
 Tc *Vtext;
};
extern Tto YkxB__T;
/* ZModule done */
/* including IOModule structs */
typedef struct {
 char text[27];
} Zs27;
typedef struct {
 char text[30];
} Zs30;
typedef struct {
 char text[19];
} Zs19;
struct Yw8L__S {
 FILE * Vfd;
 Tc *Vname;
};
extern Tto Yw8L__T;
typedef struct {
 char text[2];
} Zs2;
typedef struct {
 char text[53];
} Zs53;
struct YjUM__S {
 Ti VsLen;
 Ta *Vs;
 Tc *Vx;
};
extern Tto YjUM__T;
struct YPto__S {
 Ts Vstatus;
 Ti Vsize;
 Ti Vtime;
 Tb VisDir;
};
extern Tto YPto__T;
/* IOModule done */
/* including LOGModule structs */
typedef struct {
 char text[45];
} Zs45;
/* LOGModule done */
/* including SETModule structs */
struct Yhqr__S {
 Td *Vdict;
};
extern Tto Yhqr__T;
/* SETModule done */
/* including SORTEDLISTModule structs */
struct Yo7T__S {
 Tl *Vlist;
 Tcb *VsortMethod;
};
extern Tto Yo7T__T;
typedef struct {
 char text[44];
} Zs44;
struct YKQB__S {
Tl *Vitems;
Ti Vpos;
Ti VeditPos;
Ti VinsertPos;
Ti VaddPos;
};
extern Tto YKQB__T;
typedef struct {
 char text[24];
} Zs24;
/* SORTEDLISTModule done */
/* including CHECKModule structs */
typedef struct {
 char text[21];
} Zs21;
/* CHECKModule done */
/* including BOXModule structs */
struct YyHo__S {
 Tl *Vitems;
 Ti Vpos;
 Ti VeditPos;
 Ti VinsertPos;
 Ti VaddPos;
};
extern Tto YyHo__T;
/* BOXModule done */
/* including ARGModule structs */
struct YnU5__S {
};
extern Tto YnU5__T;
typedef struct {
 char text[51];
} Zs51;
typedef struct {
 char text[56];
} Zs56;
typedef struct {
 char text[20];
} Zs20;
typedef struct {
 char text[29];
} Zs29;
typedef struct {
 char text[31];
} Zs31;
typedef struct {
 char text[43];
} Zs43;
struct YuMQ__S {
 Tc *Vtext;
};
extern Tto YuMQ__T;
typedef struct {
 char text[42];
} Zs42;
typedef struct {
 char text[50];
} Zs50;
typedef struct {
 char text[52];
} Zs52;
typedef struct {
 char text[32];
} Zs32;
struct Y86c__S {
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
/* including zui structs */
struct Yol9__S {
 Tl *Vf_import;
 Tl *Vf_statement;
};
extern Tto Yol9__T;
struct Yknz__S {
 Ti Vf_ref;
 Tb Vhas_ref;
 Ti Vf_importNumber;
 Tb Vhas_importNumber;
 Ti Vf_importRef;
 Tb Vhas_importRef;
 Tc *Vf_name;
};
extern Tto Yknz__T;
struct YqKm__S {
 Tc *Vf_fileName;
 Ti Vf_angleQuotes;
 Tc *Vf_plugin;
 Tc *Vf_asName;
 Tc *Vf_options;
 Ysbp *Vf_pos;
 Ti Vf_importNumber;
 Tb Vhas_importNumber;
 Ti Vf_javascript;
};
extern Tto YqKm__T;
struct YYIi__S {
 Tc *Vf_name;
 YnZD *Vf_dotName;
 Ti Vf_dollar;
 Ti Vf_percent;
 Ti Vf_shared;
 Ysbp *Vf_pos;
 Ti Vf_ref;
 Tb Vhas_ref;
 Ti Vf_isUse;
 YRBza *Vf_type;
 YnZD *Vf_init;
 Ti Vf_isArg;
 Ti Vf_threeDots;
 Tc *Vf_commentBefore;
 Tc *Vf_commentAfter;
 Ti Vf_preferCommentAfter;
};
extern Tto YYIi__T;
char *MZui__ETypeEnum[] = {
 (char*)47,
 "unknown",
 "eINT",
 "eBOOL",
 "eSTATUS",
 "eNIL",
 "eANY",
 "eCSTRING",
 "eSTRING",
 "eVARSTRING",
 "eBYTES",
 "eVARBYTES",
 "eARRAY",
 "eTUPLE",
 "eLIST",
 "eDICT",
 "eMULTIDICT",
 "eSET",
 "eMULTISET",
 "eNEW",
 "ePROC",
 "eFUNC",
 "eLAMBDA",
 "ePROCREF",
 "eFUNCREF",
 "eMODULE",
 "eENUM",
 "eENUMVAL",
 "eBITS",
 "eBITSVAL",
 "eCLASS",
 "eOBJECT",
 "eINTERFACE",
 "eIOBJECT",
 "ePIECE",
 "eNAT",
 "eBIGINT",
 "eBIGNAT",
 "eFLOAT",
 "eFLOAT32",
 "eFLOAT80",
 "eFLOAT128",
 "eFIXED",
 "eALIAS",
 "eUSE",
 "eREF",
 "eNAME",
 "eUNKNOWN",
};
char *MZui__ETypeEnum__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)MZui__ETypeEnum[0]) ? "INVALID" : MZui__ETypeEnum[n + 1];
};
struct YRBza__S {
 Te Vf_type;
 Tc *Vf_text;
 Ysbp *Vf_pos;
 YJON *Vf_attr;
 Yknz *Vf_classRef;
 Ti Vf_decimals;
 Tb Vhas_decimals;
 Ti Vf_mask;
 Tb Vhas_mask;
 YftY *Vf_classDecl;
 YfQg *Vf_bitsDecl;
 YFN2 *Vf_enumDecl;
 Y2wP *Vf_moduleDecl;
 Y7Np *Vf_methodDecl;
 YyfS *Vf_container;
 YoDF *Vf_alias;
 YRBza *Vf_ref;
 YnZD *Vf_name;
 Tc *Vf_itemName;
 Ysbp *Vf_itemNamePos;
 Ti Vf_isReturn;
};
extern Tto YRBza__T;
struct YJON__S {
 Ti Vf_abstract;
 Ti Vf_isdefault;
 Ti Vf_final;
 Ti Vf_define;
 Ti Vf_replace;
 Ti Vf_earlyInit;
 Ti Vf_primitive;
 Ti Vf_noBacktrace;
 Ti Vf_wantBacktrace;
 Te Vf_visibility;
 Te Vf_readVisibility;
 Te Vf_itemsVisibility;
 Ti Vf_notOnExit;
 Ti Vf_javascript;
};
extern Tto YJON__T;
struct YftY__S {
 Tc *Vf_name;
 Ti Vf_isInterface;
 Ti Vf_isPiece;
 Tl *Vf_templateTypeName;
 YnZD *Vf_extends;
 Tl *Vf_implements;
 Tl *Vf_member;
 YhZL *Vf_shared;
 YJON *Vf_sharedAttr;
};
extern Tto YftY__T;
struct YfQg__S {
 Tl *Vf_member;
};
extern Tto YfQg__T;
struct YFN2__S {
 Tl *Vf_item;
 Tl *Vf_member;
};
extern Tto YFN2__T;
struct Y2wP__S {
 Tl *Vf_statement;
};
extern Tto Y2wP__T;
struct Y7Np__S {
 Tl *Vf_returnType;
 Tl *Vf_templateTypeName;
 Tl *Vf_argument;
 Tl *Vf_use;
 YhZL *Vf_body;
 YnZD *Vf_expr;
};
extern Tto Y7Np__T;
struct YyfS__S {
 YRBza *Vf_keyType;
 Tl *Vf_itemType;
};
extern Tto YyfS__T;
struct YoDF__S {
 YnZD *Vf_from;
 Tc *Vf_name;
 YXCg *Vf_for;
};
extern Tto YoDF__T;
struct YhZL__S {
 Ysbp *Vf_pos;
 Ysbp *Vf_endPos;
 Tl *Vf_statement;
};
extern Tto YhZL__T;
typedef struct {
 char text[25];
} Zs25;
struct YXCg__S {
 Ysbp *Vf_pos;
 Te Vf_type;
 YYIi *Vf_declaration;
 YfBB *Vf_include;
 Yq22 *Vf_assign;
 Y_1n *Vf_methodCall;
 Y5eh *Vf_condition;
 Yxh9 *Vf_for;
 Yy74 *Vf_try;
 YhZL *Vf_block;
 YnZD *Vf_expr;
 Tl *Vf_arguments;
 Tl *Vf_cblock;
 Ysbp *Vf_proceedPos;
 Ti Vf_blockgc;
 Tl *Vf_statement;
};
extern Tto YXCg__T;
struct YfBB__S {
 Tl *Vf_statement;
};
extern Tto YfBB__T;
struct Yq22__S {
 Te Vf_type;
 YnZD *Vf_lhs;
 YnZD *Vf_rhs;
};
extern Tto Yq22__T;
struct Y5eh__S {
 YnZD *Vf_cond;
 YhZL *Vf_block;
 Tl *Vf_elseif;
 YhZL *Vf_else;
};
extern Tto Y5eh__T;
struct Yxh9__S {
 Tl *Vf_loopVar;
 Tl *Vf_iter;
 YnZD *Vf_to;
 YnZD *Vf_until;
 YnZD *Vf_step;
 YhZL *Vf_body;
};
extern Tto Yxh9__T;
struct Yy74__S {
 YhZL *Vf_body;
 Tl *Vf_catch;
 YhZL *Vf_else;
 YhZL *Vf_finally;
};
extern Tto Yy74__T;
struct Ya9G__S {
 Ysbp *Vf_pos;
 Tl *Vf_type;
 YYIi *Vf_decl;
 YhZL *Vf_body;
};
extern Tto Ya9G__T;
struct YLuR__S {
 Ysbp *Vf_pos;
 Tl *Vf_uses;
 Tc *Vf_text;
 YnZD *Vf_expr;
 Ti Vf_literal;
};
extern Tto YLuR__T;
char *MZui__EExprType[] = {
 (char*)69,
 "unknown",
 "eID",
 "eINT",
 "eNAT",
 "eFLOAT",
 "eSTRING",
 "eNIL",
 "eTRUE",
 "eFALSE",
 "eOK",
 "eFAIL",
 "eTHIS",
 "ePARENT",
 "eLIST",
 "eDICT",
 "eINIT",
 "eCALL",
 "eNEWCALL",
 "eMETHOD",
 "eLAMBDA",
 "eMEMBER",
 "eTYPECAST",
 "eTYPESPEC",
 "eCTYPE",
 "eMINUS",
 "eNOT",
 "eTILDE",
 "eREF",
 "ePRE_INC",
 "ePRE_DEC",
 "ePOST_INC",
 "ePOST_DEC",
 "ePARENS",
 "eSUBSCRIPT",
 "eBITSASSIGN",
 "eEXPRMETHOD",
 "eADD",
 "eSUBTRACT",
 "eMULTIPLY",
 "eDIVIDE",
 "eREMAINDER",
 "eCONCAT",
 "eSHIFT_LEFT",
 "eSHIFT_RIGHT",
 "eBIT_AND",
 "eBIT_OR",
 "eBIT_XOR",
 "eIFNIL",
 "eTERNARY",
 "eEQUAL",
 "eNOTEQUAL",
 "eMATCH",
 "eNOMATCH",
 "eGREATER",
 "eGREATER_EQUAL",
 "eLESS",
 "eLESS_EQUAL",
 "eIS",
 "eISNOT",
 "eISA",
 "eISNOTA",
 "eAND",
 "eOR",
 "eINF",
 "eNINF",
 "eNAN",
 "eASSIGN",
 "eCCODE",
 "eUNKNOWN",
};
char *MZui__EExprType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)MZui__EExprType[0]) ? "INVALID" : MZui__EExprType[n + 1];
};
struct YnZD__S {
 Te Vf_type;
 Ysbp *Vf_pos;
 Y1p4 *Vf_id;
 Ti Vf_number;
 Tb Vhas_number;
 Tf Vf_fnumber;
 Tb Vhas_fnumber;
 Ti Vf_dotNumber;
 Tb Vhas_dotNumber;
 Tc *Vf_stringValue;
 Tl *Vf_listItem;
 Tl *Vf_dictItem;
 Tl *Vf_initItem;
 Ti Vf_orderedDict;
 Y_1n *Vf_methodCall;
 Y7Np *Vf_method;
 YYIi *Vf_decl;
 YRBza *Vf_typecast;
 Tl *Vf_typespec;
 YnZD *Vf_cond;
 YnZD *Vf_left;
 YnZD *Vf_right;
 Ti Vf_dotnil;
 Y_1n *Vf_call;
};
extern Tto YnZD__T;
struct Y1p4__S {
 Ysbp *Vf_pos;
 Tc *Vf_name;
 Ti Vf_dollar;
 Ti Vf_percent;
 Ti Vf_ref;
 Tb Vhas_ref;
};
extern Tto Y1p4__T;
struct YYKi__S {
 YnZD *Vf_key;
 YnZD *Vf_value;
};
extern Tto YYKi__T;
struct YJFN__S {
 Tc *Vf_name;
 YnZD *Vf_value;
};
extern Tto YJFN__T;
struct Y_1n__S {
 Yknz *Vf_method;
 Ysbp *Vf_pos;
 YnZD *Vf_name;
 Tl *Vf_argument;
 YnZD *Vf_vararg;
};
extern Tto Y_1n__T;
struct Ysbp__S {
 Ti Vf_line;
 Tb Vhas_line;
 Ti Vf_column;
 Tb Vhas_column;
 Tc *Vf_filename;
};
extern Tto Ysbp__T;
/* zui done */
/* including Parse structs */
/* including Input structs */
struct YeYq__S {
 Tr Vfd;
 Tc *Vtext;
 Ti VtextIdx;
 YkxB *Vpos;
 Ti VprevLineCol;
 Tl *VcharStack;
 Tc *Vindent;
 Tb VallowTabs;
 YjUM *VrecordWriter;
};
extern Tto YeYq__T;
/* Input done */
/* including Token structs */
char *CToken__EType[] = {
 (char*)143,
 "unknown",
 "eof",
 "sep",
 "line_sep",
 "comment",
 "empty",
 "nil",
 "this",
 "parent",
 "false",
 "true",
 "ok",
 "fail",
 "stringLiteral",
 "stringExprStart",
 "char",
 "any",
 "var",
 "use",
 "get",
 "threeDots",
 "id",
 "import",
 "as",
 "options",
 "alias",
 "type",
 "copy_start",
 "copy_end",
 "module",
 "class",
 "shared",
 "static",
 "interface",
 "piece",
 "enum",
 "bits",
 "func",
 "proc",
 "lambda",
 "extends",
 "implements",
 "include",
 "inf",
 "ninf",
 "nan",
 "return",
 "exit",
 "throw",
 "try",
 "catch",
 "finally",
 "defer",
 "new",
 "ready",
 "c",
 "i",
 "build_if",
 "build_elseif",
 "build_else",
 "generate_if",
 "generate_elseif",
 "generate_else",
 "generate_error",
 "if",
 "elseif",
 "else",
 "ifnil",
 "while",
 "break",
 "continue",
 "proceed",
 "switch",
 "case",
 "default",
 "do",
 "until",
 "for",
 "in",
 "to",
 "upto",
 "step",
 "comma",
 "semicolon",
 "colon",
 "question",
 "colonnil",
 "dotnil",
 "at",
 "dot",
 "p_open",
 "p_close",
 "c_open",
 "c_close",
 "sq_open",
 "sq_o_open",
 "sq_close",
 "dollar",
 "minus",
 "minmin",
 "plus",
 "plusplus",
 "tilde",
 "star",
 "slash",
 "percent",
 "concat",
 "bit_or",
 "bit_xor",
 "amp",
 "rshift",
 "lshift",
 "assign",
 "minassign",
 "plusassign",
 "multassign",
 "divassign",
 "percentassign",
 "tildeassign",
 "andassign",
 "orassign",
 "xorassign",
 "stringassign",
 "lshiftassign",
 "rshiftassign",
 "isis",
 "gives",
 "notequal",
 "match",
 "nomatch",
 "and",
 "or",
 "not",
 "gt",
 "gte",
 "lt",
 "lte",
 "is",
 "isnot",
 "isa",
 "isnota",
 "html",
 "css",
};
char *CToken__EType__name(Te n) {
 return (n < 0 || n >= (Te)(size_t)CToken__EType[0]) ? "INVALID" : CToken__EType[n + 1];
};
struct Yev8__S {
 Te Vtype;
 Tc *Vvalue;
 Tb VhasComment;
 Tb VhasCommentFirst;
 Ysbp *VzuiPos;
};
extern Tto Yev8__T;
/* Token done */
/* including TokenInput structs */
/* including Tokenizer structs */
/* including ZuiFile structs */
struct YgKE__S {
};
extern Tto YgKE__T;
/* ZuiFile done */
typedef struct {
 char text[40];
} Zs40;
typedef struct {
 char text[34];
} Zs34;
struct YsZx__S {
 Ta *Vchildren;
 Tc *Vvalue;
 Te Vtype;
 Tb VisKeyword;
};
extern Tto YsZx__T;
/* Tokenizer done */
struct Y7Sj__S {
 YeYq *Vinput;
 Tl *VtokenStack;
 Yhqr *VusedIdKeywords;
};
extern Tto Y7Sj__T;
/* TokenInput done */
struct YL4o__S {
 Yhqr *VusedIdKeywords;
};
extern Tto YL4o__T;
typedef struct {
 char text[36];
} Zs36;
typedef struct {
 char text[49];
} Zs49;
typedef struct {
 char text[38];
} Zs38;
typedef struct {
 char text[26];
} Zs26;
typedef struct {
 char text[35];
} Zs35;
typedef struct {
 char text[33];
} Zs33;
typedef struct {
 char text[37];
} Zs37;
typedef struct {
 char text[55];
} Zs55;
typedef struct {
 char text[41];
} Zs41;
typedef struct {
 char text[48];
} Zs48;
/* Parse done */
struct YwDJ__S {
 YrBF *Vparent;
 Tl *Vchildren;
 Tc *Vname;
 Tc *VfullName;
 YXCg *Vstmt;
 YJON *Vattr;
 Tc *Vtype;
 Tc *VtypeSpec;
 Tc *Vcomment;
 Tb VnoIndex;
 Tb Vhide;
 YHCf *Vsummary;
 Tc *Vextends;
 Tl *Vimplements;
 Tl *Vincludes;
 Tc *VextendsNoType;
 Tc *Vheader;
 Tc *Vtail;
};
extern Tto YwDJ__T;
struct YrBF__S {
 YrBF *Vparent;
 YwDJ *Vpage;
 Tc *Vname;
 Tc *VfullName;
 YJON *Vattr;
 Tb VisLibModule;
 Tb VisLibClass;
 YaHa *Vitems;
 Yhqr *VtypeNames;
};
extern Tto YrBF__T;
typedef struct {
 char text[65];
} Zs65;
typedef struct {
 char text[54];
} Zs54;
typedef struct {
 char text[66];
} Zs66;
typedef struct {
 char text[62];
} Zs62;
typedef struct {
 char text[67];
} Zs67;
typedef struct {
 char text[64];
} Zs64;
typedef struct {
 char text[70];
} Zs70;
typedef struct {
 char text[58];
} Zs58;
typedef struct {
 char text[74];
} Zs74;
struct YT98__S {
 Tc *VitemName;
 Tc *VtableRow;
};
extern Tto YT98__T;
struct YHCf__S {
 Tl *Ventries;
 Ti Vcount;
};
extern Tto YHCf__T;
struct YaHa__S {
 Tc *Vheader;
 Tc *Vsummary;
 Tc *Vdetails;
 Tl *Vextra;
 Tb Vhide;
 Tb VnoIndex;
};
extern Tto YaHa__T;
typedef struct {
 char text[691];
} Zs691;
typedef struct {
 char text[76];
} Zs76;
struct Tcallback__S {
 void *cfunc;
 int toCount;
};
/*
 * DECLARE FUNCTIONS AND GLOBALS
 */
Zs5 ZNilString = {"\003NIL\000"};
/* including TIMEModule declarations */
Ti Y9Rj(); /* MTIMEModule.current */
Y2KX *YgaY(Y2KX *t); /* MTIMEModule__CValues.NEW */
Y2KX *YgaYb(Y2KX *t, Ti Ausec); /* MTIMEModule__CValues.NEW */
Tc *YYTs(Y2KX *t); /* MTIMEModule__CValues.ToString */
Zs3 YV = {"\001/\000"};
Zs5 Y6O7 = {"\00302d\000"};
Zs3 YG = {"\001 \000"};
Zs3 Y5 = {"\001:\000"};
To ToY2KX[1];
Zs8 YeCO = {"\006Values\000"};
Tt MTIMEModule__EDst__T = {23, 0, 0};
/* TIMEModule done */
/* including EModule declarations */
Ytlm *YRHR(Ytlm *t, Tc *Amsg); /* MEModule__CException.NEW */
void YxaJ(Ytlm *t, Tr Aw); /* MEModule__CException.writeTo */
Zs4 YFDa = {"\002: \000"};
Zs13 YHbP = {"\013Exception: \000"};
Zs11 YDGe = {"\011Exception\000"};
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw); /* MEModule__CException.writeTo */
Zs39 Y62e = {"\045\nStack backtrace (last called first):\000"};
Zs12 Yv6_ = {"\012\n(unknown)\000"};
Zs3 Yk = {"\001\n\000"};
Tc *Ytlm__Ytlm_I_imt[14];
To ToYtlm[4];
void YScq(Ti Apos, Tc *Atext); /* MEModule.throwException */
void YXHSa(YEro *t, Tr Aw); /* MEModule__CExit.writeTo */
Zs7 YxJ1 = {"\005EXIT \000"};
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw); /* MEModule__CExit.writeTo__p1 */
To ToYEro[4];
Zs6 YJMo = {"\004Exit\000"};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit); /* MEModule__COutOfMemory.NEW */
Zs28 YIBz = {"\032Out of memory (allocating \000"};
Zs9 YDSH = {"\007 bytes)\000"};
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw); /* MEModule__COutOfMemory.writeTo__p2 */
Tc *YKhn__Ytlm_I_imt[14];
To ToYKhn[4];
Zs13 Y9Fv = {"\013OutOfMemory\000"};
void Y1KV(Ti Asize); /* MEModule.throwOutOfMemorySize */
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg); /* MEModule__CNilAccess.NEW__p2 */
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw); /* MEModule__CNilAccess.writeTo__p2 */
Tc *Y1uN__Ytlm_I_imt[14];
To ToY1uN[4];
Zs11 Y4wO = {"\011NilAccess\000"};
void YvdV(YkxB *Apos, Tc *Atext); /* MEModule.throwNil */
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg); /* MEModule__CMemoryAccess.NEW__p2 */
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw); /* MEModule__CMemoryAccess.writeTo__p2 */
Tc *YAxe__Ytlm_I_imt[14];
To ToYAxe[4];
Zs14 Y4QW = {"\014MemoryAccess\000"};
void YE93(Ti Anr); /* MEModule.throwDeadly */
Zs13 YkfG = {"\013signal SEGV\000"};
Zs12 YoEx = {"\012signal FPE\000"};
Zs12 YQNH = {"\012signal BUS\000"};
Zs9 YpCZ = {"\007signal \000"};
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg); /* MEModule__CInit.NEW__p2 */
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw); /* MEModule__CInit.writeTo__p2 */
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw); /* MEModule__CInit.writeTo__p2 */
Tc *YVNj__Ytlm_I_imt[14];
To ToYVNj[4];
Zs6 Ysqt = {"\004Init\000"};
void Y3w6(Tc *Atext); /* MEModule.throwInit */
YtEE *YtEE__YwtA__YRHRa(YtEE *t, YkxB *Apos, Tc *Amsg); /* MEModule__CCheck.NEW__p2 */
void YtEE__YwtA__YxaJa(YtEE *t, Tb Averbose, Tr Aw); /* MEModule__CCheck.writeTo__p2 */
void YtEE__YwtA__YxaJ(YtEE *t, Tr Aw); /* MEModule__CCheck.writeTo__p2 */
Tc *YtEE__Ytlm_I_imt[14];
To ToYtEE[4];
Zs7 YvUM = {"\005Check\000"};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg); /* MEModule__CBadValue.NEW__p2 */
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw); /* MEModule__CBadValue.writeTo__p2 */
Tc *Yalz__Ytlm_I_imt[14];
To ToYalz[4];
Zs10 YEZq = {"\010BadValue\000"};
void Yaez(Tc *Atext); /* MEModule.throwBadValue */
Yw3O *Yw3O__Yalz__YwtA__YRHRa(Yw3O *t, YkxB *Apos, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg); /* MEModule__COutOfRange.NEW__p3 */
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw); /* MEModule__COutOfRange.writeTo__p3 */
Tc *Yw3O__Ytlm_I_imt[14];
To ToYw3O[4];
Zs12 YFK2 = {"\012OutOfRange\000"};
void Y6NT(Ti Aindex, Tc *Amsg); /* MEModule.throwOutOfRange */
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg); /* MEModule__CKeyNotFound.NEW__p3 */
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw); /* MEModule__CKeyNotFound.writeTo__p3 */
Tc *Y2EX__Ytlm_I_imt[14];
To ToY2EX[4];
Zs13 YRiW = {"\013KeyNotFound\000"};
void Yxmk(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyNotFound */
Zs17 Ym6C = {"\017Key not found: \000"};
void Y5LT(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyNotFound */
Zs18 YJ3Y = {"\020Key not found: \"\000"};
Zs3 YI = {"\001\"\000"};
YX0i *YX0i__Yalz__YwtA__YRHRa(YX0i *t, YkxB *Apos, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg); /* MEModule__CKeyExists.NEW__p3 */
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw); /* MEModule__CKeyExists.writeTo__p3 */
Tc *YX0i__Ytlm_I_imt[14];
To ToYX0i[4];
Zs11 Y9_h = {"\011KeyExists\000"};
void YL9Z(Ti Akey, Tc *Amsg); /* MEModule.throwIntKeyExists */
Zs22 Y9qa = {"\024Key already exists: \000"};
void YEeX(Tc *Akey, Tc *Amsg); /* MEModule.throwStringKeyExists */
Zs23 YMKM = {"\025Key already exists: \"\000"};
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg); /* MEModule__CIllegalByte.NEW__p3 */
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw); /* MEModule__CIllegalByte.writeTo__p3 */
Tc *YP_P__Ytlm_I_imt[14];
To ToYP_P[4];
Zs13 Ydbm = {"\013IllegalByte\000"};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg); /* MEModule__CDivideByZero.NEW__p3 */
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw); /* MEModule__CDivideByZero.writeTo__p3 */
Tc *YzSI__Ytlm_I_imt[14];
To ToYzSI[4];
Zs14 YxFl = {"\014DivideByZero\000"};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg); /* MEModule__CIOError.NEW__p2 */
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw); /* MEModule__CIOError.writeTo__p2 */
Tc *YXKl__Ytlm_I_imt[14];
To ToYXKl[4];
Zs9 YTj3 = {"\007IOError\000"};
YuDC *YdhH(YuDC *t); /* MEModule__CWrongType.NEW */
Zs15 Ynjz = {"\015Type mismatch\000"};
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw); /* MEModule__CWrongType.writeTo__p2 */
Tc *YuDC__Ytlm_I_imt[14];
To ToYuDC[4];
Zs11 YCoZ = {"\011WrongType\000"};
void YTuG(Ti Apos); /* MEModule.throwWrongType */
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg); /* MEModule__CInternal.NEW__p2 */
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw); /* MEModule__CInternal.writeTo__p2 */
Tc *YrHq__Ytlm_I_imt[14];
To ToYrHq[4];
Zs10 YVki = {"\010Internal\000"};
void YUSH(YkxB *Apos, Tc *Atext); /* MEModule.throwInternal */
void YxIS(Tr Ae); /* MEModule.unhandledException */
void YvL0(Tr Ae); /* MEModule.writeToStderr */
void YQar(Tr A0, Tb A1, Tr A2); /* Ytlm_I__MwriteTo_I__bool__Yw8L_I */
/* EModule done */
/* including ZModule declarations */
YkxB *Ypp_(YkxB *t, Tc *Afilename); /* MZModule__CPos.NEW */
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol); /* MZModule__CPos.NEW */
YkxB *Y83A(YkxB *t); /* MZModule__CPos.copy */
void YnS4(YkxB *t); /* MZModule__CPos.nextLine */
void Y7Yp(YkxB *t, Tc *As); /* MZModule__CPos.advance */
Tc *YpI_(YkxB *t); /* MZModule__CPos.ToString */
Zs16 YKo1 = {"\016[unknown file]\000"};
Zs8 YBpY = {"\006 line \000"};
Zs7 Y8ES = {"\005 col \000"};
To ToYkxB[3];
Zs5 YBCs = {"\003Pos\000"};
/* ZModule done */
/* including IOModule declarations */
Ti Y3QJ__NOT = -1 /* MIOModule.eof */;
Tr Y59X = {NULL}; /* MIOModule.stdin */
Tr Yb0q = {NULL}; /* MIOModule.stdout */
Tr YeNQ = {NULL}; /* MIOModule.stderr */
Tr Yd89(); /* MIOModule.newStdin */
Tr Yvyt(); /* MIOModule.newStdout */
Tr YsM3(); /* MIOModule.newStderr */
Tc **YdXi__imtt[4];
Ti YFeQ(Yw8L *t); /* MIOModule__CFile.readByte */
Zs18 YQe8 = {"\020File is not open\000"};
Ti YAPp(Yw8L *t); /* MIOModule__CFile.readChar */
Zs27 YPHa = {"\031first byte out of range: \000"};
Zs30 YKzT = {"\034found EOF when getting byte \000"};
Zs7 Ymwv = {"\005byte \000"};
Zs15 YPfW = {"\015 out of range\000"};
Zs19 Y8Gn = {"\021overlong sequence\000"};
Ts YwHoa(Yw8L *t, Tc *Atext); /* MIOModule__CFile.write */
Ts YGmp(Yw8L *t); /* MIOModule__CFile.flush */
Ts YrF8(Yw8L *t); /* MIOModule__CFile.close */
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber); /* MIOModule__CFile.write__p1 */
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext); /* MIOModule__CFile.print__p1 */
Ts Yw8L__YRt7g(Yw8L *t); /* MIOModule__CFile.print__p1 */
Tc *Yw8L__Yw8L_I_imt[38];
Tc *Yw8L__YdXi_imt[3];
To ToYw8L[2];
Zs6 YtTU = {"\004File\000"};
Tr YsGz(Tc *AfileName); /* MIOModule.fileReader */
Tr YiBk(Tc *AfileName, Tb Atruncate); /* MIOModule.fileWriter */
Ts Yvcu(Tc *Atext); /* MIOModule.write */
Ts Yl0k(Tc *Atext); /* MIOModule.print */
Ts Ylxt(); /* MIOModule.flush */
Ts YJqza(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.write */
Ts Ye7fa(YjUM *t, Ti Abyte); /* MIOModule__CStringWriter.writeByte */
Ti YKJQ(YjUM *t); /* MIOModule__CStringWriter.Size */
Tc *YbNW(YjUM *t); /* MIOModule__CStringWriter.ToString */
Zs2 Ya = {"\000\000"};
Ti Y6jW(YjUM *t); /* MIOModule__CStringWriter.remove */
void Y3_a(YjUM *t); /* MIOModule__CStringWriter.truncate */
Ts YjUM__YHhZb(YjUM *t, Ti Anumber); /* MIOModule__CStringWriter.write__p1 */
Ts YjUM__Ydti(YjUM *t, Ti Achar); /* MIOModule__CStringWriter.writeChar__p1 */
Zs53 Yv8w = {"\063UTF-8 character must be in range 0 - 0x10ffff, got \000"};
Ts YjUM__YRt7(YjUM *t, Tc *Atext); /* MIOModule__CStringWriter.print__p1 */
Tc *YjUM__YdXi_imt[3];
To ToYjUM[3];
Zs14 YE4c = {"\014StringWriter\000"};
To ToYPto[1];
Zs10 Y68E = {"\010FileInfo\000"};
YPto *YPwr(Tc *Aname); /* MIOModule.fileInfo */
int JIOModule(int round);
/* IOModule done */
/* including LOGModule declarations */
Zs3 YLa = {"\001d\000"};
Zs7 YGwH = {"\005debug\000"};
Zs12 YhpM = {"\012Debug mode\000"};
Y86c *YU8T = 0; /* MLOGModule.debugFlag */
Zs3 Y2a = {"\001v\000"};
Zs9 YUsn = {"\007verbose\000"};
Zs45 YSuP = {"\053Verbose messages, repeat for more verbosity\000"};
Y86c *YlUb = 0; /* MLOGModule.verboseFlag */
Tt MLOGModule__ELevel__T = {23, 0, 0};
Zs7 YuXA = {"\005Flags\000"};
Tt MLOGModule__BFlags__T = {25, ((Tc*)&YuXA), 0};
Td *Ytd2 = NULL; /* MLOGModule.counts */
Ti Yrpn = 0; /* MLOGModule.errorCount */
void YDY4(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.info */
void YDli(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.error */
void Y2oO(Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.internal */
Tc *YmaW = ((Tc*)&Ya) /* MLOGModule.extraLead */;
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags); /* MLOGModule.log */
Zs11 YJ5p = {"\011INTERNAL \000"};
Zs11 Yyq1 = {"\011Warning: \000"};
Zs9 Y27a = {"\007ERROR: \000"};
Zs16 Y3l3 = {"\016SEVERE ERROR: \000"};
Zs15 YmM8 = {"\015FATAL ERROR: \000"};
Zs3 YU = {"\001.\000"};
Zs5 YwV7 = {"\00306d\000"};
void YwlF(Tr Aout); /* MLOGModule.reportStack */
Zs12 YDzC = {"\012Backtrace:\000"};
Ti YvW3 = 0; /* MLOGModule.lastFlush */
Ti YOwl = 300000 /* MLOGModule.flushInterval */;
void Y7LJ(); /* MLOGModule.flush */
Tr Yz2b = {NULL}; /* MLOGModule.logFile */
Tb YiAD = 1 /* MLOGModule.useTimeStamp */;
int JLOGModule(int round);
/* LOGModule done */
/* including SETModule declarations */
int Ypau__r = 0; /* MSETModule__CSet__t1.Ready */
Yhqr *Ypau(Yhqr *t); /* MSETModule__CSet__t1.Init */
Yhqr *Yh95(Yhqr *t); /* MSETModule__CSet__t1.NEW */
Tb YyHa(Yhqr *t, Tc *Akey); /* MSETModule__CSet__t1.has */
Yhqr *YGMT(Yhqr *t, Tc *Akey); /* MSETModule__CSet__t1.add */
Zs23 YLLX = {"\025key already present: \000"};
Yhqr *Y63C(Yhqr *t, Tc *Akey); /* MSETModule__CSet__t1.set */
To ToYhqr[2];
Zs9 Yehz = {"\007Set__t1\000"};
/* SETModule done */
/* including SORTEDLISTModule declarations */
int YaDX__r = 0; /* MSORTEDLISTModule__CSortedList__t1.Ready */
Yo7T *YaDX(Yo7T *t); /* MSORTEDLISTModule__CSortedList__t1.Init */
Yo7T *YFR3(Yo7T *t); /* MSORTEDLISTModule__CSortedList__t1.NEW */
Tr YOv9(Yo7T *t); /* MSORTEDLISTModule__CSortedList__t1.Iterator */
Yo7T *Ygeh(Yo7T *t, YwDJ *Aitem); /* MSORTEDLISTModule__CSortedList__t1.add */
To ToYo7T[3];
Zs16 YMyc = {"\016SortedList__t1\000"};
YKQB *YKQB__YXWx(YKQB *t, Tl *Aitems); /* MSORTEDLISTModule__CSortedListIterator__t1.NEW__p1 */
Tb YKQB__Yd_d(YKQB *t); /* MSORTEDLISTModule__CSortedListIterator__t1.hasNext__p1 */
YwDJ *YKQB__YUEI(YKQB *t); /* MSORTEDLISTModule__CSortedListIterator__t1.next__p1 */
Zs44 YL9D = {"\052Calling next() while there is no next item\000"};
int YKQBa__r = 0; /* Init/1().Ready */
YKQB *YKQBa(YKQB *t); /* MSORTEDLISTModule__CSortedListIterator__t1.Init */
Tc *YKQB__Yzfy_imt[5];
To ToYKQB[2];
Zs24 Y_Qo = {"\026SortedListIterator__t1\000"};
/* SORTEDLISTModule done */
/* including CHECKModule declarations */
void Y8UT(Tb Ab); /* MCHECKModule.true */
Zs21 YG7w = {"\023CHECK.true() failed\000"};
/* CHECKModule done */
/* including BOXModule declarations */
Tb Yd_d(YyHo *t); /* MBOXModule__CListIterator__t1.hasNext */
YwDJ *YUEI(YyHo *t); /* MBOXModule__CListIterator__t1.next */
To ToYyHo[2];
Zs18 YC5w = {"\020ListIterator__t1\000"};
/* BOXModule done */
/* including ARGModule declarations */
Tc *YzvW = NULL; /* MARGModule.rawName */
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
Ti Yd2Z(); /* MARGModule.Size */
Tc *YtgL(Ti Aindex); /* MARGModule.get */
To ToYnU5[1];
Zs8 Yr32 = {"\006Status\000"};
void YY8i(); /* MARGModule.initCheck */
Zs51 YeBP = {"\061Using command line flag before they are available\000"};
void YZH8(); /* MARGModule.init */
Zs56 Y7T_ = {"\066ARG.disable() used but command line flags were defined\000"};
Zs3 YT = {"\001-\000"};
Zs4 Y1ia = {"\002--\000"};
Zs6 YqzQ = {"\004help\000"};
Zs10 Y3via = {"\010morehelp\000"};
Zs10 Yll7 = {"\010helpmore\000"};
Zs4 YhZb = {"\002no\000"};
Zs20 YcW8 = {"\022Invalid argument: \000"};
Zs29 Y2hB = {"\033Unknown command line flag: \000"};
Zs31 YcLH = {"\035Duplicate command line flag: \000"};
Zs5 YjK7 = {"\003yes\000"};
Zs6 YsfP = {"\004true\000"};
Zs7 YvpX = {"\005false\000"};
Zs43 YHSJ = {"\051Expected 'yes', 'no', 'true' or 'false': \000"};
Zs19 Y6QK = {"\021Unexpected = in: \000"};
Zs28 Y_ju = {"\032Missing argument for flag \000"};
Zs29 YjTs = {"\033INTERNAL: unknown flag type\000"};
void YSUO(Tc *Amsg); /* MARGModule.error */
Zs22 YkFE = {"\024To list flags use: '\000"};
Zs10 Y15F = {"\010 --help'\000"};
void Yfj5(Tb Averbose); /* MARGModule.displayHelp */
Zs21 YaBy = {"\023Command line flags:\000"};
Zs13 YwXF = {"\013--morehelp \000"};
Zs24 YEcf = {"\026show more verbose help\000"};
Zs8 Yy2p = {"\006number\000"};
Zs8 YanE = {"\006string\000"};
Zs12 YDci = {"\012string ...\000"};
Zs6 YulU = {"\004 ...\000"};
Zs4 YVZ = {"\002 [\000"};
Zs3 YEa = {"\001]\000"};
Zs4 Yq_ = {"\002 {\000"};
Zs3 Y9a = {"\001}\000"};
Zs5 Y_y2 = {"\003...\000"};
Zs6 Y2yA = {"\004... \000"};
Zs13 Ym4c = {"\013Defined in \000"};
void YTlu(Tc *Alead, Ti AmaxLeadLen); /* MARGModule.writeLead */
Tc *YAMW(YuMQ *t); /* MARGModule__CUsage.get */
Zs5 YMtG = {"\003%0%\000"};
To ToYuMQ[2];
Zs7 Y6qT = {"\005Usage\000"};
Td *Y7be = NULL; /* MARGModule.shortFlags */
Td *YBQy = NULL; /* MARGModule.longFlags */
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc); /* MARGModule__CBool.NEW */
void YEqoa(Y86c *t); /* MARGModule__CBool.setToDefault */
Tb YHoR(Y86c *t); /* MARGModule__CBool.get */
Tb YuOS(Y86c *t); /* MARGModule__CBool.value */
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos); /* MARGModule__CBool.NEW__p1 */
Zs42 Yc_h = {"\050Adding command line flag after using one\000"};
Zs50 Y6pY = {"\060Command line flag must have a short or long name\000"};
Zs52 Y9CP = {"\062short command line flag name must be one character\000"};
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos); /* MARGModule__CBool.throwDuplicate__p1 */
Zs9 YbbH = {"\007unknown\000"};
Zs32 YtzG = {"\036Duplicate command line flag: '\000"};
Zs17 YDyy = {"\017' also used at \000"};
Ti Y86c__Ye9f(Y86c *t); /* MARGModule__CBool.presentCount__p1 */
Tc *Y86c__YuQR_I_imt[19];
To ToY86c[6];
Zs6 YZ1F = {"\004Bool\000"};
void Y49ga(YJQu *t); /* MARGModule__CInt.setToDefault */
To ToYJQu[7];
Zs5 YzBa = {"\003Int\000"};
void YJaza(YzqH *t); /* MARGModule__CString.setToDefault */
To ToYzqH[9];
Zs8 YDAE = {"\006String\000"};
void YSkKa(Y_SI *t); /* MARGModule__CStringList.setToDefault */
To ToY_SI[8];
Zs12 Ygf5 = {"\012StringList\000"};
int JARGModule(int round);
/* ARGModule done */
/* including zui declarations */
Yol9 *YzBD(Yol9 *t); /* MZui__CContents.NEW */
Yol9 *YJpo(Yol9 *t, YqKm *Av); /* MZui__CContents.addImport */
YqKm *YNk6(Yol9 *t); /* MZui__CContents.addNewImport */
Tl *YAaE(Yol9 *t); /* MZui__CContents.getStatementList */
Yol9 *YVAS(Yol9 *t, Tl *Al); /* MZui__CContents.setStatementList */
To ToYol9[3];
Zs10 Yz59 = {"\010Contents\000"};
Yknz *YpBS(Yknz *t); /* MZui__CSymbolRef.NEW */
Yknz *YCOd(Yknz *t, Tb Adeep); /* MZui__CSymbolRef.copy */
To ToYknz[2];
Zs11 YrHi = {"\011SymbolRef\000"};
YqKm *YFYs(YqKm *t); /* MZui__CImport.NEW */
YqKm *Y6Pf(YqKm *t, Tc *Av); /* MZui__CImport.setFileName */
YqKm *YWuz(YqKm *t, Tb Av); /* MZui__CImport.setAngleQuotes */
YqKm *Y0hJ(YqKm *t, Tc *Av); /* MZui__CImport.setPlugin */
YqKm *YYIq(YqKm *t, Tc *Av); /* MZui__CImport.setAsName */
YqKm *YQa2(YqKm *t, Tc *Av); /* MZui__CImport.setOptions */
YqKm *YimL(YqKm *t, Ysbp *Av); /* MZui__CImport.setPos */
YqKm *YQBo(YqKm *t, Ti Av); /* MZui__CImport.setImportNumber */
YqKm *YygQ(YqKm *t, Tb Av); /* MZui__CImport.setJavascript */
To ToYqKm[6];
Zs8 YeYv = {"\006Import\000"};
YYIi *YpQb(YYIi *t); /* MZui__CDeclaration.NEW */
YYIi *YpBC(YYIi *t, Tc *Av); /* MZui__CDeclaration.setName */
Tc *YdHK(YYIi *t); /* MZui__CDeclaration.getName */
YYIi *YTLb(YYIi *t, YnZD *Av); /* MZui__CDeclaration.setDotName */
YYIi *YJ03(YYIi *t, Tb Av); /* MZui__CDeclaration.setDollar */
Tb YGHm(YYIi *t); /* MZui__CDeclaration.getDollar */
YYIi *Y5JX(YYIi *t, Tb Av); /* MZui__CDeclaration.setPercent */
Tb YEkx(YYIi *t); /* MZui__CDeclaration.getPercent */
YYIi *Y1ql(YYIi *t, Tb Av); /* MZui__CDeclaration.setShared */
YYIi *YvRw(YYIi *t, Ysbp *Av); /* MZui__CDeclaration.setPos */
YYIi *Y747(YYIi *t, Tb Av); /* MZui__CDeclaration.setIsUse */
YYIi *YdTj(YYIi *t, YRBza *Av); /* MZui__CDeclaration.setType */
YRBza *YkDm(YYIi *t); /* MZui__CDeclaration.newType */
YRBza *Y1Yr(YYIi *t); /* MZui__CDeclaration.getType */
Zs18 YM0N = {"\020type was not set\000"};
YYIi *YhZx(YYIi *t, YnZD *Av); /* MZui__CDeclaration.setInit */
Tb YoD_(YYIi *t); /* MZui__CDeclaration.hasInit */
YYIi *Y6vX(YYIi *t, Tb Av); /* MZui__CDeclaration.setIsArg */
YYIi *Yv8X(YYIi *t, Tb Av); /* MZui__CDeclaration.setThreeDots */
YYIi *Y4e7(YYIi *t, Tc *Av); /* MZui__CDeclaration.setCommentBefore */
Tc *YWDX(YYIi *t); /* MZui__CDeclaration.getCommentBefore */
Tb YMEi(YYIi *t); /* MZui__CDeclaration.hasCommentBefore */
YYIi *YDJy(YYIi *t, Tc *Av); /* MZui__CDeclaration.setCommentAfter */
Tc *YNOi(YYIi *t); /* MZui__CDeclaration.getCommentAfter */
Tb YqeZ(YYIi *t); /* MZui__CDeclaration.hasCommentAfter */
YYIi *Yxn8(YYIi *t, Tb Av); /* MZui__CDeclaration.setPreferCommentAfter */
Tb YfGL(YYIi *t); /* MZui__CDeclaration.getPreferCommentAfter */
YYIi *YTec(YYIi *t, Tb Adeep); /* MZui__CDeclaration.copy */
To ToYYIi[8];
Zs13 Yy4i = {"\013Declaration\000"};
Tt MZui__ETypeEnum__T = {23, 0, MZui__ETypeEnum__name};
YRBza *Ya_p(YRBza *t); /* MZui__CType.NEW */
YRBza *YLJs(YRBza *t, Te Av); /* MZui__CType.setType */
Te YXDk(YRBza *t); /* MZui__CType.getType */
YRBza *Y2b1(YRBza *t, Ysbp *Av); /* MZui__CType.setPos */
YRBza *YrDX(YRBza *t, YJON *Av); /* MZui__CType.setAttr */
YJON *YDxP(YRBza *t); /* MZui__CType.getAttr */
Zs18 Yzav = {"\020attr was not set\000"};
Tb YkZu(YRBza *t); /* MZui__CType.hasAttr */
YRBza *Y45H(YRBza *t, YftY *Av); /* MZui__CType.setClassDecl */
YftY *YJgu(YRBza *t); /* MZui__CType.getClassDecl */
Zs23 Ydqh = {"\025classDecl was not set\000"};
YRBza *YewF(YRBza *t, YfQg *Av); /* MZui__CType.setBitsDecl */
YfQg *YDOm(YRBza *t); /* MZui__CType.getBitsDecl */
Zs22 Y9pb = {"\024bitsDecl was not set\000"};
YRBza *YEtr(YRBza *t, YFN2 *Av); /* MZui__CType.setEnumDecl */
YFN2 *YdRA(YRBza *t); /* MZui__CType.getEnumDecl */
Zs22 Y_JJ = {"\024enumDecl was not set\000"};
YRBza *YM5q(YRBza *t, Y2wP *Av); /* MZui__CType.setModuleDecl */
Y2wP *Y8Ec(YRBza *t); /* MZui__CType.getModuleDecl */
Zs24 YN1w = {"\026moduleDecl was not set\000"};
YRBza *YHPQ(YRBza *t, Y7Np *Av); /* MZui__CType.setMethodDecl */
Y7Np *Y3nC(YRBza *t); /* MZui__CType.getMethodDecl */
Zs24 YPyV = {"\026methodDecl was not set\000"};
YRBza *YVus(YRBza *t, YoDF *Av); /* MZui__CType.setAlias */
YoDF *Y9au(YRBza *t); /* MZui__CType.getAlias */
Zs19 YKpG = {"\021alias was not set\000"};
YRBza *YE45(YRBza *t, YRBza *Av); /* MZui__CType.setRef */
YRBza *YH95(YRBza *t); /* MZui__CType.getRef */
Zs17 YKdC = {"\017ref was not set\000"};
YRBza *Yz09(YRBza *t, YnZD *Av); /* MZui__CType.setName */
YnZD *YLV1(YRBza *t); /* MZui__CType.getName */
Zs18 Y0L2 = {"\020name was not set\000"};
YRBza *Yk0M(YRBza *t, Tc *Av); /* MZui__CType.setItemName */
YRBza *YPkC(YRBza *t, Ysbp *Av); /* MZui__CType.setItemNamePos */
YRBza *Y3HG(YRBza *t, Tb Av); /* MZui__CType.setIsReturn */
YRBza *YK7D(YRBza *t, Tb Adeep); /* MZui__CType.copy */
To ToYRBza[16];
Zs6 Yokf = {"\004Type\000"};
Tt MZui__EVisibility__T = {23, 0, 0};
YJON *YsCX(YJON *t); /* MZui__CAttributes.NEW */
YJON *Y5IN(YJON *t, Tb Av); /* MZui__CAttributes.setAbstract */
Tb YCKw(YJON *t); /* MZui__CAttributes.getAbstract */
YJON *Y_Uu(YJON *t, Tb Av); /* MZui__CAttributes.setIsdefault */
Tb YHd1(YJON *t); /* MZui__CAttributes.getIsdefault */
YJON *YsDp(YJON *t, Tb Av); /* MZui__CAttributes.setFinal */
Tb YdXn(YJON *t); /* MZui__CAttributes.getFinal */
YJON *YdJG(YJON *t, Tb Av); /* MZui__CAttributes.setDefine */
Tb YapZ(YJON *t); /* MZui__CAttributes.getDefine */
YJON *Y3gm(YJON *t, Tb Av); /* MZui__CAttributes.setReplace */
Tb YJqm(YJON *t); /* MZui__CAttributes.getReplace */
YJON *Y5i_(YJON *t, Tb Av); /* MZui__CAttributes.setEarlyInit */
Tb YBPw(YJON *t); /* MZui__CAttributes.getEarlyInit */
YJON *YOG0(YJON *t, Tb Av); /* MZui__CAttributes.setPrimitive */
Tb YTrv(YJON *t); /* MZui__CAttributes.getPrimitive */
YJON *Y980(YJON *t, Tb Av); /* MZui__CAttributes.setNoBacktrace */
Tb Y929(YJON *t); /* MZui__CAttributes.getNoBacktrace */
YJON *YDDz(YJON *t, Tb Av); /* MZui__CAttributes.setWantBacktrace */
Tb Ynfv(YJON *t); /* MZui__CAttributes.getWantBacktrace */
YJON *Ywbp(YJON *t, Te Av); /* MZui__CAttributes.setVisibility */
Te Y9CD(YJON *t); /* MZui__CAttributes.getVisibility */
Zs24 YRZU = {"\026visibility was not set\000"};
Tb YVd6(YJON *t); /* MZui__CAttributes.hasVisibility */
YJON *YjX9(YJON *t, Te Av); /* MZui__CAttributes.setReadVisibility */
Tb YpeP(YJON *t); /* MZui__CAttributes.hasReadVisibility */
YJON *YUKK(YJON *t, Te Av); /* MZui__CAttributes.setItemsVisibility */
Te Yr4g(YJON *t); /* MZui__CAttributes.getItemsVisibility */
Zs29 Y_Vi = {"\033itemsVisibility was not set\000"};
Tb YVep(YJON *t); /* MZui__CAttributes.hasItemsVisibility */
YJON *YJmK(YJON *t, Tb Av); /* MZui__CAttributes.setNotOnExit */
Tb YYLM(YJON *t); /* MZui__CAttributes.getNotOnExit */
YJON *YFFWa(YJON *t, Tb Av); /* MZui__CAttributes.setJavascript */
Tb YiKB(YJON *t); /* MZui__CAttributes.getJavascript */
YJON *YGuf(YJON *t, Tb Adeep); /* MZui__CAttributes.copy */
To ToYJON[1];
Zs12 YK8n = {"\012Attributes\000"};
YftY *YOMn(YftY *t); /* MZui__CClassType.NEW */
YftY *YHGh(YftY *t, Tb Av); /* MZui__CClassType.setIsInterface */
YftY *YFgR(YftY *t, Tb Av); /* MZui__CClassType.setIsPiece */
Tl *YrvP(YftY *t); /* MZui__CClassType.getTemplateTypeNameList */
YftY *YCdb(YftY *t, Tl *Al); /* MZui__CClassType.setTemplateTypeNameList */
Tb YHI7(YftY *t); /* MZui__CClassType.hasTemplateTypeName */
YftY *YSMx(YftY *t, YnZD *Av); /* MZui__CClassType.setExtends */
YnZD *YVVa(YftY *t); /* MZui__CClassType.getExtends */
Zs21 YAke = {"\023extends was not set\000"};
Tb YCwH(YftY *t); /* MZui__CClassType.hasExtends */
Tl *YVqZ(YftY *t); /* MZui__CClassType.getImplementsList */
YftY *Yq9S(YftY *t, Tl *Al); /* MZui__CClassType.setImplementsList */
Tb YXx6(YftY *t); /* MZui__CClassType.hasImplements */
Tl *YGyt(YftY *t); /* MZui__CClassType.getMemberList */
YftY *Yj_H(YftY *t, Tl *Al); /* MZui__CClassType.setMemberList */
Tb YskK(YftY *t); /* MZui__CClassType.hasMember */
YhZL *YPLV(YftY *t); /* MZui__CClassType.newShared */
YhZL *Ykbi(YftY *t); /* MZui__CClassType.getShared */
Zs20 Y_pz = {"\022shared was not set\000"};
Tb YPer(YftY *t); /* MZui__CClassType.hasShared */
YftY *YjP6(YftY *t, YJON *Av); /* MZui__CClassType.setSharedAttr */
YftY *YOIH(YftY *t, Tb Adeep); /* MZui__CClassType.copy */
To ToYftY[8];
Zs11 YwBU = {"\011ClassType\000"};
YfQg *Y8xU(YfQg *t); /* MZui__CBitsType.NEW */
Tl *Y4e2(YfQg *t); /* MZui__CBitsType.getMemberList */
YfQg *YT9u(YfQg *t, Tl *Al); /* MZui__CBitsType.setMemberList */
Tb YVXf(YfQg *t); /* MZui__CBitsType.hasMember */
YfQg *Y60S(YfQg *t, Tb Adeep); /* MZui__CBitsType.copy */
To ToYfQg[2];
Zs10 YIB2 = {"\010BitsType\000"};
YFN2 *Y5iq(YFN2 *t); /* MZui__CEnumType.NEW */
YFN2 *Ydz4(YFN2 *t, YYIi *Av); /* MZui__CEnumType.addItem */
YYIi *YbCT(YFN2 *t); /* MZui__CEnumType.addNewItem */
Tl *YOZZ(YFN2 *t); /* MZui__CEnumType.getItemList */
Tl *YjCl(YFN2 *t); /* MZui__CEnumType.getMemberList */
Tb YohH(YFN2 *t); /* MZui__CEnumType.hasMember */
YFN2 *Y17e(YFN2 *t, Tb Adeep); /* MZui__CEnumType.copy */
To ToYFN2[3];
Zs10 YiEg = {"\010EnumType\000"};
Y2wP *YwDD(Y2wP *t); /* MZui__CModuleType.NEW */
Tl *YiW9(Y2wP *t); /* MZui__CModuleType.getStatementList */
Y2wP *YDlo(Y2wP *t, Tl *Al); /* MZui__CModuleType.setStatementList */
Tb Y13u(Y2wP *t); /* MZui__CModuleType.hasStatement */
Y2wP *YBUM(Y2wP *t, Tb Adeep); /* MZui__CModuleType.copy */
To ToY2wP[2];
Zs12 Yqqm = {"\012ModuleType\000"};
Y7Np *YWVR(Y7Np *t); /* MZui__CMethodType.NEW */
Y7Np *YEOq(Y7Np *t, YRBza *Av); /* MZui__CMethodType.addReturnType */
YRBza *YQsX(Y7Np *t); /* MZui__CMethodType.addNewReturnType */
Tl *Yv3S(Y7Np *t); /* MZui__CMethodType.getReturnTypeList */
Tb Y5UB(Y7Np *t); /* MZui__CMethodType.hasReturnType */
Tl *YmXD(Y7Np *t); /* MZui__CMethodType.getTemplateTypeNameList */
Y7Np *YxF_(Y7Np *t, Tl *Al); /* MZui__CMethodType.setTemplateTypeNameList */
Tb Yq8G(Y7Np *t); /* MZui__CMethodType.hasTemplateTypeName */
Y7Np *YWsV(Y7Np *t, YYIi *Av); /* MZui__CMethodType.addArgument */
YYIi *YG6V(Y7Np *t); /* MZui__CMethodType.addNewArgument */
Tl *Y8dZ(Y7Np *t); /* MZui__CMethodType.getArgumentList */
Y7Np *YT39(Y7Np *t, YYIi *Av); /* MZui__CMethodType.addUse */
YYIi *YyeO(Y7Np *t); /* MZui__CMethodType.addNewUse */
Y7Np *Y4cF(Y7Np *t, YhZL *Av); /* MZui__CMethodType.setBody */
Y7Np *YI0V(Y7Np *t, YnZD *Av); /* MZui__CMethodType.setExpr */
Y7Np *Yt_q(Y7Np *t, Tb Adeep); /* MZui__CMethodType.copy */
To ToY7Np[7];
Zs12 Yl9L = {"\012MethodType\000"};
YyfS *YvNY(YyfS *t); /* MZui__CContainerType.NEW */
YyfS *YLOM(YyfS *t, Tb Adeep); /* MZui__CContainerType.copy */
To ToYyfS[3];
Zs15 YmBB = {"\015ContainerType\000"};
YoDF *YRGj(YoDF *t); /* MZui__CAliasType.NEW */
YoDF *YpwO(YoDF *t, YnZD *Av); /* MZui__CAliasType.setFrom */
YnZD *YdCW(YoDF *t); /* MZui__CAliasType.getFrom */
Zs18 YObi = {"\020from was not set\000"};
YoDF *Yit4(YoDF *t, Tc *Av); /* MZui__CAliasType.setName */
YoDF *YlIy(YoDF *t, YXCg *Av); /* MZui__CAliasType.setFor */
YXCg *YiDy(YoDF *t); /* MZui__CAliasType.getFor */
Zs17 YsP0 = {"\017for was not set\000"};
Tb YNTP(YoDF *t); /* MZui__CAliasType.hasFor */
YoDF *YL4I(YoDF *t, Tb Adeep); /* MZui__CAliasType.copy */
To ToYoDF[4];
Zs11 Ynrc = {"\011AliasType\000"};
YhZL *YBTx(YhZL *t); /* MZui__CCodeBlock.NEW */
YhZL *YtnA(YhZL *t, Ysbp *Av); /* MZui__CCodeBlock.setPos */
YhZL *YFf4(YhZL *t, Ysbp *Av); /* MZui__CCodeBlock.setEndPos */
YhZL *Y0lJ(YhZL *t, YXCg *Av); /* MZui__CCodeBlock.addStatement */
Tl *Yb8Y(YhZL *t); /* MZui__CCodeBlock.getStatementList */
YhZL *YRIK(YhZL *t, Tl *Al); /* MZui__CCodeBlock.setStatementList */
Tb YJD1(YhZL *t); /* MZui__CCodeBlock.hasStatement */
YhZL *Yzft(YhZL *t, Tb Adeep); /* MZui__CCodeBlock.copy */
To ToYhZL[4];
Zs11 Yu55 = {"\011CodeBlock\000"};
Tt MZui__EStatementType__T = {23, 0, 0};
YXCg *YDNI(YXCg *t); /* MZui__CStatement.NEW */
YXCg *YZqm(YXCg *t, Ysbp *Av); /* MZui__CStatement.setPos */
Ysbp *YWlm(YXCg *t); /* MZui__CStatement.getPos */
Zs17 Y6Oda = {"\017pos was not set\000"};
YXCg *Yiw6(YXCg *t, Te Av); /* MZui__CStatement.setType */
Te YuqZ(YXCg *t); /* MZui__CStatement.getType */
YXCg *Yh4I(YXCg *t, YYIi *Av); /* MZui__CStatement.setDeclaration */
YYIi *YK2t(YXCg *t); /* MZui__CStatement.newDeclaration */
YYIi *YjGb(YXCg *t); /* MZui__CStatement.getDeclaration */
Zs25 YIL3 = {"\027declaration was not set\000"};
Tb YGtH(YXCg *t); /* MZui__CStatement.hasDeclaration */
YXCg *YCIA(YXCg *t, YfBB *Av); /* MZui__CStatement.setInclude */
YfBB *Yaja(YXCg *t); /* MZui__CStatement.getInclude */
Zs21 YtKs = {"\023include was not set\000"};
YXCg *Yw4A(YXCg *t, Yq22 *Av); /* MZui__CStatement.setAssign */
YXCg *YM__(YXCg *t, Y_1n *Av); /* MZui__CStatement.setMethodCall */
YXCg *YYdx(YXCg *t, Y5eh *Av); /* MZui__CStatement.setCondition */
Y5eh *YpRA(YXCg *t); /* MZui__CStatement.newCondition */
Y5eh *YCoj(YXCg *t); /* MZui__CStatement.getCondition */
Zs23 YuH4 = {"\025condition was not set\000"};
YXCg *Yc8L(YXCg *t, Yxh9 *Av); /* MZui__CStatement.setFor */
YXCg *Yo4b(YXCg *t, Yy74 *Av); /* MZui__CStatement.setTry */
YXCg *Yq9q(YXCg *t, YhZL *Av); /* MZui__CStatement.setBlock */
YhZL *YFQs(YXCg *t); /* MZui__CStatement.getBlock */
Zs19 YB3y = {"\021block was not set\000"};
Tb Ycfv(YXCg *t); /* MZui__CStatement.hasBlock */
YXCg *YMTX(YXCg *t, YnZD *Av); /* MZui__CStatement.setExpr */
YXCg *YkEo(YXCg *t, Tl *Al); /* MZui__CStatement.setArgumentsList */
YXCg *YGJp(YXCg *t, YLuR *Av); /* MZui__CStatement.addCblock */
YXCg *YBVz(YXCg *t, Ysbp *Av); /* MZui__CStatement.setProceedPos */
YXCg *YpTx(YXCg *t, Tb Av); /* MZui__CStatement.setBlockgc */
YXCg *YGDU(YXCg *t, YXCg *Av); /* MZui__CStatement.addStatement */
Tl *YM4H(YXCg *t); /* MZui__CStatement.getStatementList */
YXCg *Y9N8(YXCg *t, Tb Adeep); /* MZui__CStatement.copy */
To ToYXCg[15];
Zs11 YPrB = {"\011Statement\000"};
YfBB *Y48I(YfBB *t); /* MZui__CInclude.NEW */
Tl *YXSw(YfBB *t); /* MZui__CInclude.getStatementList */
YfBB *YZnt(YfBB *t, Tl *Al); /* MZui__CInclude.setStatementList */
YfBB *Y8pz(YfBB *t, Tb Adeep); /* MZui__CInclude.copy */
To ToYfBB[2];
Zs9 YghR = {"\007Include\000"};
Yq22 *YZ8B(Yq22 *t); /* MZui__CAssignment.NEW */
Yq22 *YhEN(Yq22 *t, Te Av); /* MZui__CAssignment.setType */
Yq22 *Y2Ep(Yq22 *t, YnZD *Av); /* MZui__CAssignment.setLhs */
Yq22 *Yz4E(Yq22 *t, YnZD *Av); /* MZui__CAssignment.setRhs */
Yq22 *YPgi(Yq22 *t, Tb Adeep); /* MZui__CAssignment.copy */
To ToYq22[3];
Zs12 Y2U7 = {"\012Assignment\000"};
Y5eh *Y4Kn(Y5eh *t); /* MZui__CCondition.NEW */
Y5eh *YpGq(Y5eh *t, YnZD *Av); /* MZui__CCondition.setCond */
Y5eh *YNhk(Y5eh *t, YhZL *Av); /* MZui__CCondition.setBlock */
YhZL *YzLV(Y5eh *t); /* MZui__CCondition.newBlock */
YhZL *Y1Yl(Y5eh *t); /* MZui__CCondition.getBlock */
Tb Yzno(Y5eh *t); /* MZui__CCondition.hasBlock */
Y5eh *Yucl(Y5eh *t, Y5eh *Av); /* MZui__CCondition.addElseif */
Y5eh *YbNt(Y5eh *t); /* MZui__CCondition.addNewElseif */
Tl *YPh5(Y5eh *t); /* MZui__CCondition.getElseifList */
Y5eh *Ya5i(Y5eh *t, YhZL *Av); /* MZui__CCondition.setElse */
YhZL *Ym_a(Y5eh *t); /* MZui__CCondition.getElse */
Zs18 YqLt = {"\020else was not set\000"};
Tb Y3qR(Y5eh *t); /* MZui__CCondition.hasElse */
Y5eh *Y3dy(Y5eh *t, Tb Adeep); /* MZui__CCondition.copy */
To ToY5eh[5];
Zs11 YGPA = {"\011Condition\000"};
Yxh9 *Yx2D(Yxh9 *t); /* MZui__CForStatement.NEW */
Yxh9 *YEk6(Yxh9 *t, YYIi *Av); /* MZui__CForStatement.addLoopVar */
Ti YCdt(Yxh9 *t); /* MZui__CForStatement.sizeLoopVar */
Yxh9 *YMOM(Yxh9 *t, YnZD *Av); /* MZui__CForStatement.addIter */
Yxh9 *YmBG(Yxh9 *t, YnZD *Av); /* MZui__CForStatement.setTo */
Yxh9 *YV_5(Yxh9 *t, YnZD *Av); /* MZui__CForStatement.setUntil */
Yxh9 *YiIU(Yxh9 *t, YnZD *Av); /* MZui__CForStatement.setStep */
YhZL *YCBH(Yxh9 *t); /* MZui__CForStatement.newBody */
Yxh9 *YDH2(Yxh9 *t, Tb Adeep); /* MZui__CForStatement.copy */
To ToYxh9[7];
Zs14 YoLj = {"\014ForStatement\000"};
Yy74 *YNpV(Yy74 *t); /* MZui__CTryStatement.NEW */
Yy74 *YM0M(Yy74 *t, YhZL *Av); /* MZui__CTryStatement.setBody */
YhZL *YA6U(Yy74 *t); /* MZui__CTryStatement.getBody */
Zs18 YBft = {"\020body was not set\000"};
Yy74 *YPVu(Yy74 *t, Ya9G *Av); /* MZui__CTryStatement.addCatch */
Ya9G *YNyp(Yy74 *t); /* MZui__CTryStatement.addNewCatch */
Yy74 *YHr1a(Yy74 *t, YhZL *Av); /* MZui__CTryStatement.setElse */
Yy74 *YFQt(Yy74 *t, YhZL *Av); /* MZui__CTryStatement.setFinally */
Yy74 *YCDC(Yy74 *t, Tb Adeep); /* MZui__CTryStatement.copy */
To ToYy74[5];
Zs14 YdWn = {"\014TryStatement\000"};
Ya9G *Ynwi(Ya9G *t); /* MZui__CCatch.NEW */
Ya9G *YvJl(Ya9G *t, Ysbp *Av); /* MZui__CCatch.setPos */
Ya9G *YpMg(Ya9G *t, Tl *Al); /* MZui__CCatch.setTypeList */
Ya9G *Yu95(Ya9G *t, YYIi *Av); /* MZui__CCatch.setDecl */
Ya9G *YxIg(Ya9G *t, YhZL *Av); /* MZui__CCatch.setBody */
Ya9G *Y3_J(Ya9G *t, Tb Adeep); /* MZui__CCatch.copy */
To ToYa9G[5];
Zs7 Ynly = {"\005Catch\000"};
YLuR *YgFm(YLuR *t); /* MZui__CCBlock.NEW */
YLuR *YapJ(YLuR *t, Ysbp *Av); /* MZui__CCBlock.setPos */
YLuR *YwGh(YLuR *t, Tl *Al); /* MZui__CCBlock.setUsesList */
YLuR *YRpi(YLuR *t, Tc *Av); /* MZui__CCBlock.setText */
YLuR *YZAk(YLuR *t, YnZD *Av); /* MZui__CCBlock.setExpr */
YLuR *YvSw(YLuR *t, Tb Av); /* MZui__CCBlock.setLiteral */
YLuR *YsIm(YLuR *t, Tb Adeep); /* MZui__CCBlock.copy */
To ToYLuR[5];
Zs8 YzI_ = {"\006CBlock\000"};
Tt MZui__EExprType__T = {23, 0, MZui__EExprType__name};
YnZD *Y4GO(YnZD *t); /* MZui__CExpression.NEW */
YnZD *YaZq(YnZD *t, Te Av); /* MZui__CExpression.setType */
Te YmTi(YnZD *t); /* MZui__CExpression.getType */
YnZD *Y4_i(YnZD *t, Ysbp *Av); /* MZui__CExpression.setPos */
Ysbp *Y74i(YnZD *t); /* MZui__CExpression.getPos */
Y1p4 *YRE8(YnZD *t); /* MZui__CExpression.newId */
Y1p4 *YjUS(YnZD *t); /* MZui__CExpression.getId */
Zs16 Y5Te = {"\016id was not set\000"};
YnZD *Ypk4(YnZD *t, Ti Av); /* MZui__CExpression.setNumber */
Ti YsEM(YnZD *t); /* MZui__CExpression.getNumber */
YnZD *Y1BD(YnZD *t, Tf Av); /* MZui__CExpression.setFnumber */
Tf YAcd(YnZD *t); /* MZui__CExpression.getFnumber */
Zs21 YPnZ = {"\023fnumber was not set\000"};
YnZD *YM_T(YnZD *t, Tc *Av); /* MZui__CExpression.setStringValue */
YnZD *YKTm(YnZD *t, Tl *Al); /* MZui__CExpression.setListItemList */
Ti YMHY(YnZD *t); /* MZui__CExpression.sizeListItem */
YnZD *Yw_g(YnZD *t, YYKi *Av); /* MZui__CExpression.addDictItem */
YYKi *YmCP(YnZD *t); /* MZui__CExpression.addNewDictItem */
YnZD *Y51O(YnZD *t, YJFN *Av); /* MZui__CExpression.addInitItem */
YJFN *YNzh(YnZD *t); /* MZui__CExpression.addNewInitItem */
YnZD *Y_Jm(YnZD *t, Tb Av); /* MZui__CExpression.setOrderedDict */
YnZD *YoWy(YnZD *t, Y_1n *Av); /* MZui__CExpression.setMethodCall */
Y_1n *YztZ(YnZD *t); /* MZui__CExpression.getMethodCall */
Zs24 YP7Q = {"\026methodCall was not set\000"};
YnZD *YCI5(YnZD *t, Y7Np *Av); /* MZui__CExpression.setMethod */
YnZD *Y35a(YnZD *t, YYIi *Av); /* MZui__CExpression.setDecl */
YRBza *Ymcl(YnZD *t); /* MZui__CExpression.newTypecast */
Tl *Y6_b(YnZD *t); /* MZui__CExpression.getTypespecList */
YnZD *YbfL(YnZD *t, Tl *Al); /* MZui__CExpression.setTypespecList */
YnZD *YkIT(YnZD *t, YnZD *Av); /* MZui__CExpression.setCond */
YnZD *Yfkd(YnZD *t, YnZD *Av); /* MZui__CExpression.setLeft */
YnZD *Y8za(YnZD *t); /* MZui__CExpression.newLeft */
YnZD *Yre5(YnZD *t); /* MZui__CExpression.getLeft */
Zs18 Yt7m = {"\020left was not set\000"};
Tb Y8FL(YnZD *t); /* MZui__CExpression.hasLeft */
YnZD *YPfx(YnZD *t, YnZD *Av); /* MZui__CExpression.setRight */
YnZD *YBJ7(YnZD *t); /* MZui__CExpression.newRight */
YnZD *Y3Wy(YnZD *t); /* MZui__CExpression.getRight */
Zs19 YC23 = {"\021right was not set\000"};
Tb YBlB(YnZD *t); /* MZui__CExpression.hasRight */
YnZD *YkYI(YnZD *t, Tb Av); /* MZui__CExpression.setDotnil */
YnZD *Ypps(YnZD *t, Tb Adeep); /* MZui__CExpression.copy */
To ToYnZD[16];
Zs12 Y5cf = {"\012Expression\000"};
Y1p4 *YUZH(Y1p4 *t); /* MZui__CId.NEW */
Y1p4 *YxV1(Y1p4 *t, Ysbp *Av); /* MZui__CId.setPos */
Y1p4 *YMou(Y1p4 *t, Tc *Av); /* MZui__CId.setName */
Tc *YYim(Y1p4 *t); /* MZui__CId.getName */
Y1p4 *YLsU(Y1p4 *t, Tb Av); /* MZui__CId.setDollar */
Tb YI8b(Y1p4 *t); /* MZui__CId.getDollar */
Y1p4 *YuRa(Y1p4 *t, Tb Av); /* MZui__CId.setPercent */
Tb YFAa(Y1p4 *t); /* MZui__CId.getPercent */
Y1p4 *Y_4M(Y1p4 *t, Tb Adeep); /* MZui__CId.copy */
To ToY1p4[3];
Zs4 YN1a = {"\002Id\000"};
YYKi *YJyD(YYKi *t); /* MZui__CExprPair.NEW */
YYKi *YdT0(YYKi *t, YnZD *Av); /* MZui__CExprPair.setKey */
YYKi *YsFD(YYKi *t, YnZD *Av); /* MZui__CExprPair.setValue */
YYKi *YqYD(YYKi *t, Tb Adeep); /* MZui__CExprPair.copy */
To ToYYKi[3];
Zs10 Y_G0 = {"\010ExprPair\000"};
YJFN *Ydki(YJFN *t); /* MZui__CNameExpr.NEW */
YJFN *YXqm(YJFN *t, Tc *Av); /* MZui__CNameExpr.setName */
YJFN *YP1z(YJFN *t, YnZD *Av); /* MZui__CNameExpr.setValue */
YJFN *YPAH(YJFN *t, Tb Adeep); /* MZui__CNameExpr.copy */
To ToYJFN[3];
Zs10 YeMw = {"\010NameExpr\000"};
Y_1n *YLx8(Y_1n *t); /* MZui__CMethodCall.NEW */
Y_1n *Y_BE(Y_1n *t, Ysbp *Av); /* MZui__CMethodCall.setPos */
Y_1n *YOo6(Y_1n *t, YnZD *Av); /* MZui__CMethodCall.setName */
Y_1n *YnYS(Y_1n *t, Tl *Al); /* MZui__CMethodCall.setArgumentList */
Y_1n *Y6Kb(Y_1n *t, Tb Adeep); /* MZui__CMethodCall.copy */
To ToY_1n[6];
Zs12 YtVN = {"\012MethodCall\000"};
Ysbp *Y602(Ysbp *t); /* MZui__CPosition.NEW */
Ysbp *YGxQ(Ysbp *t, Ti Av); /* MZui__CPosition.setLine */
Ti YuDY(Ysbp *t); /* MZui__CPosition.getLine */
Ysbp *Y6ET(Ysbp *t, Ti Av); /* MZui__CPosition.setColumn */
Ti Y3kb(Ysbp *t); /* MZui__CPosition.getColumn */
Ysbp *YMCx(Ysbp *t, Tc *Av); /* MZui__CPosition.setFilename */
Tc *Y5Hu(Ysbp *t); /* MZui__CPosition.getFilename */
Ysbp *Yw4M(Ysbp *t, Tb Adeep); /* MZui__CPosition.copy */
To ToYsbp[2];
Zs10 YvfVb = {"\010Position\000"};
/* zui done */
/* including Parse declarations */
/* including Input declarations */
YeYq *YOdr(YeYq *t, Tr Afd, Tc *Afname, Tc *Aindent, Tb Arecord); /* CInput.NEW */
YeYq *YOdra(YeYq *t, Tc *As, YkxB *Astartpos); /* CInput.NEW */
Ti YAit(YeYq *t); /* CInput.get */
Zs21 YrKy = {"\023found NUL character\000"};
Zs21 YemR = {"\023found Tab character\000"};
Zs25 Y3Pw = {"\027found control character\000"};
void YmK2(YeYq *t, Ti Ac); /* CInput.push */
To ToYeYq[7];
Zs7 YVUW = {"\005Input\000"};
/* Input done */
/* including Token declarations */
YkxB *YWLf(Yev8 *t); /* CToken.zcPos */
void YdIu(Yev8 *t, Tc *Amsg); /* CToken.error */
void YREn(Yev8 *t); /* CToken.errorNotAllowed */
Zs3 YN = {"\001'\000"};
Zs20 YScH = {"\022' not allowed here\000"};
Tb YfTZ(Yev8 *t); /* CToken.isSep */
Yev8 *Y77H(Yev8 *t); /* CToken.copy */
Tt CToken__EType__T = {23, 0, CToken__EType__name};
To ToYev8[3];
Zs7 YVrE = {"\005Token\000"};
/* Token done */
/* including TokenInput declarations */
/* including Tokenizer declarations */
/* including ZuiFile declarations */
Ysbp *YK9d(YkxB *Apos); /* CZuiFile__X.createPosition */
void YA4C(YkxB *Apos, Ysbp *Azpos); /* CZuiFile__X.copyPosition */
To ToYgKE[1];
Zs9 YRzA = {"\007ZuiFile\000"};
/* ZuiFile done */
Tb YIA3(Ti Ac); /* MTokenizer.isIdChar */
Zs5 Yez2 = {"\003..=\000"};
Zs5 YzUC = {"\003<<=\000"};
Zs5 YC5H = {"\003>>=\000"};
Zs5 YD5H = {"\003>>>\000"};
Zs5 YyUC = {"\003<<<\000"};
Zs4 Y2_ = {"\002!=\000"};
Zs4 Y40 = {"\002!~\000"};
Zs4 Yhja = {"\002-=\000"};
Zs4 YNfa = {"\002++\000"};
Zs4 Y4fa = {"\002+=\000"};
Zs4 Ytea = {"\002*=\000"};
Zs4 Yuma = {"\002/=\000"};
Zs4 Ys6 = {"\002%=\000"};
Zs4 Y8mc = {"\002~=\000"};
Zs4 Y37 = {"\002&=\000"};
Zs4 YWjc = {"\002|=\000"};
Zs4 YQyb = {"\002^=\000"};
Zs4 YWIa = {"\002==\000"};
Zs4 YXIa = {"\002=>\000"};
Zs4 YYJa = {"\002=~\000"};
Zs4 YjHa = {"\002<<\000"};
Zs4 YyKa = {"\002>>\000"};
Zs4 YkHa = {"\002<=\000"};
Zs4 YxKa = {"\002>=\000"};
Zs4 YH7 = {"\002&&\000"};
Zs4 YWkc = {"\002||\000"};
Zs4 YEka = {"\002..\000"};
Zs4 Y5La = {"\002?:\000"};
Zs4 YULa = {"\002?.\000"};
Zs3 YH = {"\001!\000"};
Zs3 YK = {"\001$\000"};
Zs3 YL = {"\001%\000"};
Zs3 YM = {"\001&\000"};
Zs3 YO = {"\001(\000"};
Zs3 YP = {"\001)\000"};
Zs3 YQ = {"\001*\000"};
Zs3 YR = {"\001+\000"};
Zs3 YS = {"\001,\000"};
Zs3 Y6 = {"\001;\000"};
Zs3 Y7 = {"\001<\000"};
Zs3 Y8 = {"\001=\000"};
Zs3 Y9 = {"\001>\000"};
Zs3 Yba = {"\001@\000"};
Zs4 Ygbb = {"\002O[\000"};
Zs3 YCa = {"\001[\000"};
Zs3 YFa = {"\001^\000"};
Zs3 Y7a = {"\001{\000"};
Zs3 Y8a = {"\001|\000"};
Zs3 Yab = {"\001~\000"};
Zs3 Yaa = {"\001?\000"};
Td Y3rf = {}; /* MTokenizer.nonKeywords */
Zs7 Yu2V = {"\005ALIAS\000"};
Zs5 YBjQ = {"\003ARG\000"};
Zs4 YHPa = {"\002AS\000"};
Zs6 YjG6 = {"\004BITS\000"};
Zs5 YZOS = {"\003BOX\000"};
Zs7 YZzE = {"\005BREAK\000"};
Zs10 YOgo = {"\010BUILD_IF\000"};
Zs14 YwZW = {"\014BUILD_ELSEIF\000"};
Zs12 YCSN = {"\012BUILD_ELSE\000"};
Zs7 Ydl6 = {"\005BYTES\000"};
Zs12 YxBe = {"\012BYTESTRING\000"};
Zs3 Yea = {"\001C\000"};
Zs6 Y6FU = {"\004CASE\000"};
Zs7 YCun = {"\005CATCH\000"};
Zs9 YPQP = {"\007CHEADER\000"};
Zs7 YK2B = {"\005CHECK\000"};
Zs7 YMwW = {"\005CLASS\000"};
Zs10 Yn3A = {"\010CONTINUE\000"};
Zs5 YeuV = {"\003CSS\000"};
Zs9 YUlG = {"\007DEFAULT\000"};
Zs7 Yqcs = {"\005DEFER\000"};
Zs4 YrUa = {"\002DO\000"};
Zs3 Yga = {"\001E\000"};
Zs6 Yc7A = {"\004ELSE\000"};
Zs8 Y9jU = {"\006ELSEIF\000"};
Zs6 YnjG = {"\004ENUM\000"};
Zs6 YsI4 = {"\004EXIT\000"};
Zs9 YDN8 = {"\007EXTENDS\000"};
Zs6 Y8ag = {"\004FAIL\000"};
Zs7 Y2cy = {"\005FALSE\000"};
Zs9 YdbBa = {"\007FINALLY\000"};
Zs5 Yz51 = {"\003FOR\000"};
Zs6 YqI4 = {"\004FUNC\000"};
Zs4 Y3Ya = {"\002GC\000"};
Zs15 Yuso = {"\015GENERATE_ELSE\000"};
Zs17 Ycx0 = {"\017GENERATE_ELSEIF\000"};
Zs16 Yf3i = {"\016GENERATE_ERROR\000"};
Zs13 Y1Ce = {"\013GENERATE_IF\000"};
Zs5 Yup4 = {"\003GET\000"};
Zs6 Yith = {"\004HTTP\000"};
Zs6 Y0hh = {"\004HTML\000"};
Zs3 Yka = {"\001I\000"};
Zs4 Yj1a = {"\002IF\000"};
Zs7 Y4UI = {"\005IFNIL\000"};
Zs12 Y4lO = {"\012IMPLEMENTS\000"};
Zs8 YML6 = {"\006IMPORT\000"};
Zs4 Yr1a = {"\002IN\000"};
Zs9 Ygis = {"\007INCLUDE\000"};
Zs5 YxM9 = {"\003INF\000"};
Zs5 YLM9 = {"\003INT\000"};
Zs11 Y0as = {"\011INTERFACE\000"};
Zs4 Ys1aa = {"\002IO\000"};
Zs4 Yw1a = {"\002IS\000"};
Zs5 YtU9 = {"\003ISA\000"};
Zs7 YCHh = {"\005ISNOT\000"};
Zs8 Y5nR = {"\006ISNOTA\000"};
Zs8 YAcL = {"\006LAMBDA\000"};
Zs5 YVvha = {"\003LOG\000"};
Zs8 YKxe = {"\006MODULE\000"};
Zs5 Yqim = {"\003NAN\000"};
Zs5 YZom = {"\003NEW\000"};
Zs6 Yizy = {"\004NINF\000"};
Zs4 Y0ab = {"\002OK\000"};
Zs9 Y2gz = {"\007OPTIONS\000"};
Zs8 YV4t = {"\006PARENT\000"};
Zs7 YNqR = {"\005PIECE\000"};
Zs6 YsNN = {"\004PIPE\000"};
Zs6 Y6T9 = {"\004PROC\000"};
Zs9 Ysa6 = {"\007PROCEED\000"};
Zs7 YgRl = {"\005PROTO\000"};
Zs8 YGD1 = {"\006RETURN\000"};
Zs5 YZXw = {"\003RPC\000"};
Zs8 YuOB = {"\006SHARED\000"};
Zs8 YuyE = {"\006STATIC\000"};
Zs6 Y4xB = {"\004STEP\000"};
Zs8 Yaof = {"\006STRING\000"};
Zs8 Y0Y5 = {"\006SWITCH\000"};
Zs5 YALz = {"\003SYS\000"};
Zs3 Yva = {"\001T\000"};
Zs6 Ytoe = {"\004THIS\000"};
Zs8 YVLC = {"\006THREAD\000"};
Zs7 YTJV = {"\005THROW\000"};
Zs6 YA3g = {"\004TIME\000"};
Zs5 YNVB = {"\003TIO\000"};
Zs4 Y5ib = {"\002TO\000"};
Zs6 YHoE = {"\004TRUE\000"};
Zs5 Yn9B = {"\003TRY\000"};
Zs6 Y7fW = {"\004TYPE\000"};
Zs7 YexT = {"\005UNTIL\000"};
Zs5 YAKE = {"\003USE\000"};
Zs5 YRRGa = {"\003VAR\000"};
Zs10 YD2V = {"\010VARBYTES\000"};
Zs15 Y_r2 = {"\015VARBYTESTRING\000"};
Zs11 YRA8 = {"\011VARSTRING\000"};
Zs7 YHo2 = {"\005WHILE\000"};
Zs3 YBa = {"\001Z\000"};
Zs5 YDER = {"\003ZUT\000"};
Zs5 YQHR = {"\003ZWT\000"};
Td Y0sf = {}; /* MTokenizer.keywords */
YjUM Yc6N = {}; /* MTokenizer.tokenWriter */
Yev8 *Yx5t(Y7Sj *Ain); /* MTokenizer.get */
Zs22 YD4M = {"\024missing double quote\000"};
Zs27 YjHV = {"\031missing end of ''\" string\000"};
Zs40 YXk7 = {"\046Missing character betwee single quotes\000"};
Zs22 YYrm = {"\024missing single quote\000"};
Zs27 YtNZ = {"\031Unrecognized character: '\000"};
Zs25 Yl7Q = {"\027Unrecognized keyword: '\000"};
Zs34 Y_B2 = {"\040'__' is illegal in identifier: '\000"};
void YxBx(Ti Ac, Y7Sj *Ain, YjUM *Awriter); /* MTokenizer.controlChar */
Zs25 YVwa = {"\027Illegal octal character\000"};
Zs27 Y3ak = {"\031Illegal character after \\\000"};
Ti YHDu(Ti AcharCount, Y7Sj *Ain); /* MTokenizer.getHex */
Zs23 YnRg = {"\025Illegal hex character\000"};
void YfFo(Y7Sj *Ain, YjUM *Awriter); /* MTokenizer.getRawString */
YjUM Yl_6 = {}; /* MTokenizer.whiteWriter */
void YZTP(Y7Sj *Ain, Yev8 *Ares); /* MTokenizer.handleWhite */
Zs12 YWPM = {"\012missing */\000"};
To ToYsZx[3];
Zs6 Y2N6 = {"\004Node\000"};
YsZx YXGF = {}; /* MTokenizer.root */
void Yfh4(Tc *Aname, Te Atype, Tb AisKeyword); /* MTokenizer.addNode */
Zs19 Yqcm = {"\021Duplicate token: \000"};
int YTyo__r = 0; /* MTokenizer.Ready */
Ts YTyo(); /* MTokenizer.Init */
Ts Ybdf(Y7Sj *Ain, Yev8 *Ares); /* MTokenizer.getNew */
Ts YY69(Y7Sj *Ain, YsZx *An, Yev8 *Ares); /* MTokenizer.deeper */
int JTokenizer(int round);
/* Tokenizer done */
Y7Sj *YUwt(Y7Sj *t, YeYq *Ainput); /* CTokenInput.NEW */
Ti YGBv(Y7Sj *t); /* CTokenInput.get */
void YPmF(Y7Sj *t, Ti Ac); /* CTokenInput.push */
Ti YHT_(Y7Sj *t); /* CTokenInput.peek */
Tc *YUrw(Y7Sj *t); /* CTokenInput.getWord */
Tb Y7_i(Y7Sj *t); /* CTokenInput.skipWhite */
Yev8 *Y_PN(Y7Sj *t); /* CTokenInput.getToken */
void YH7I(Y7Sj *t, Yev8 *Atoken); /* CTokenInput.pushToken */
Yev8 *YksM(Y7Sj *t); /* CTokenInput.peekToken */
void YGzQ(Y7Sj *t); /* CTokenInput.emptyStack */
void Y5yp(Y7Sj *t, Tc *Amsg); /* CTokenInput.error */
To ToY7Sj[4];
Zs12 YnOq = {"\012TokenInput\000"};
int JTokenInput(int round);
/* TokenInput done */
/* including Visibility declarations */
Tt EVisibility__T = {23, 0, 0};
/* Visibility done */
To ToYL4o[2];
Zs13 YL2R = {"\013ParseResult\000"};
YjS4 Yl0s(Tc *AfileName, Tc *Aindent, Tbb AblockType); /* MParse.parseFile */
Zs14 Yxtr = {"\014: Parsing...\000"};
void YNYW(Y7Sj *Ain, Yol9 *Acontents); /* MParse.parseImports */
Zs36 YbdI = {"\042IMPORT. must be followed by a name\000"};
Zs49 Y0jB = {"\057IMPORT must be followed by a string in \"\" or <>\000"};
Zs11 YnLg = {"\011Missing >\000"};
Zs14 YXzm = {"\014duplicate AS\000"};
Zs38 YAo4 = {"\044OPTIONS must be followed by a string\000"};
Zs19 YLLV = {"\021duplicate OPTIONS\000"};
Zs12 YE5Z = {"\012javascript\000"};
Yev8 *YABA(Y7Sj *Ain); /* MParse.getAs */
Zs31 YXPH = {"\035AS must be followed by a name\000"};
void Ygty(Y7Sj *Ain, Tbb AblockTypeIn, Yol9 *Acontents); /* MParse.parseInput */
Zs14 YLl7 = {"\014unexpected }\000"};
Zs32 YhQ4 = {"\036Only one toplevel item allowed\000"};
Zs11 Ynu8 = {"\011BlockType\000"};
Tt MParse__BBlockType__T = {25, ((Tc*)&Ynu8), 0};
Tl *YBd7(Y7Sj *Ain, Tbb AblockType); /* MParse.parseBlock */
Zs14 YbEV = {"\014Syntax error\000"};
YXCg YIbB = {}; /* MParse.emptyStatement */
YXCg *YjwQ(Y7Sj *Ain, Tbb AblockType); /* MParse.parseBlockItem */
Zs16 YPTa = {"\016unexpected EOF\000"};
Zs22 YlkF = {"\024unexpected string: '\000"};
Zs19 Yqta = {"\021Unexpected SHARED\000"};
Zs19 YqJ7 = {"\021Unexpected STATIC\000"};
Zs18 Ym_A = {"\020Misplaced LAMBDA\000"};
Zs13 YABa = {"\013Cannot use \000"};
Zs7 Yz33 = {"\005 here\000"};
Zs14 Y7m7 = {"\014unexpected '\000"};
YXCg *YQbp(Yev8 *Atoken, YnZD *AnameExpr); /* MParse.makeIncDecStatement */
YXCg *YH3h(YnZD *AtypeExpr, Yev8 *Aid_token, Tb AcheckForInit, Tb AcheckForEol, Y7Sj *Ain); /* MParse.parseDeclaration */
Zs26 Yxw0 = {"\030name without operation: \000"};
Zs9 YF4i = {"\007private\000"};
Zs11 YPwY = {"\011protected\000"};
Zs8 Ygnv = {"\006public\000"};
Zs7 YDNe = {"\005local\000"};
Zs6 YYFL = {"\004file\000"};
Zs11 YIEZ = {"\011directory\000"};
Zs6 Yr91 = {"\004read\000"};
Zs11 YlOO = {"\011earlyInit\000"};
void YmQW(YnZD *Aexpr, Y7Sj *Ain); /* MParse.typeUsed */
Zs10 YrXn = {"\010varbytes\000"};
Zs15 YHkL = {"\015varByteString\000"};
Zs11 Y7Ft = {"\011varstring\000"};
Zs11 YATt = {"\011varString\000"};
Zs5 Y1Qt = {"\003int\000"};
Zs5 YYgh = {"\003dyn\000"};
Zs6 Y3nJ = {"\004lock\000"};
Zs10 YbJS = {"\010autoLock\000"};
Zs6 YJnE = {"\004cond\000"};
YXCg *Y4h6(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseModule */
Zs35 YFVc = {"\041MODULE must be followed by a name\000"};
Zs7 Yyir = {"\005items\000"};
YXCg *YTWI(Yev8 *AclassToken, Y7Sj *Ain); /* MParse.parseClass */
Zs34 Yoc2 = {"\040CLASS must be followed by a name\000"};
Zs8 YVK0 = {"\006thread\000"};
Zs12 Y6Yl = {"\012evalThread\000"};
Zs39 Ywka = {"\045cannot use IMPLEMENTS on an interface\000"};
Zs10 YrkU = {"\010abstract\000"};
Zs7 YtNZa = {"\005final\000"};
Zs33 YS9i = {"\037No } found that ends this class\000"};
YXCg *YEc4(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseInclude */
Tb Yb8a = 0; /* MParse.hadMain */
YXCg *YGqS(Yev8 *AfirstToken, Y7Sj *Ain, Tbb AblockType); /* MParse.parseMethod */
Zs20 Y9St = {"\022 NEW() not allowed\000"};
Zs6 Ykmq = {"\004Main\000"};
Zs37 YgzP = {"\043Main() not allowed in imported file\000"};
Zs18 YIcs = {"\020Duplicate Main()\000"};
Zs17 YIYT = {"\017Expected a name\000"};
Zs11 Y1Kg = {"\011Missing (\000"};
Zs11 YODD = {"\011backtrace\000"};
Zs9 YpLJ = {"\007default\000"};
Zs8 Ybyf = {"\006define\000"};
Zs9 Yl3I = {"\007replace\000"};
Zs11 YDqN = {"\011primitive\000"};
Zs11 YIK3 = {"\011notOnExit\000"};
YXCg *Ye9W(Yev8 *AbitsToken, Y7Sj *Ain); /* MParse.parseBits */
Zs33 Y06E = {"\037BITS must be followed by a name\000"};
YXCg *Yawn(Yev8 *AenumToken, Y7Sj *Ain); /* MParse.parseEnum */
Zs33 Ybaw = {"\037ENUM must be followed by a name\000"};
Zs35 Y_ih = {"\041unexpected EOF, unterminated ENUM\000"};
Zs26 YMKA = {"\030unexpected token in ENUM\000"};
YXCg *YWYQa(Yev8 *AstartToken, Y7Sj *Ain, Tbb AblockType); /* MParse.parseStatement */
Zs13 YPq4 = {"\013cannot use \000"};
Zs16 YzTy = {"\016 in this scope\000"};
Zs38 Ynnk = {"\044cannot call a function in this scope\000"};
Zs36 YobZ = {"\042cannot do assignment in this scope\000"};
Zs38 YPRH = {"\044cannot do in/decrement in this scope\000"};
Zs32 YpoI = {"\036cannot in/decrement dyn or VAR\000"};
Zs13 YVlJ = {"\013Misplaced $\000"};
Tb YAdu(Te Atype); /* MParse.isAssign */
YXCg *Yyn4(YnZD *Aexpr, Yev8 *Atoken, Y7Sj *Ain); /* MParse.parseAssign */
Zs17 YjOD = {"\017Misplaced comma\000"};
Zs11 Y71i = {"\011Expected \000"};
Zs17 Yppy = {"\017 values, found \000"};
YnZD *Yi5r(YXCg *Astmt); /* MParse.varExprFromDeclStmt */
YXCg *YoGb(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseIf */
YXCg *YHeC(Yev8 *Atoken, Y7Sj *Ain); /* MParse.parseGenerateError */
YXCg *Y34o(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseTry */
Zs35 YW6h = {"\041Expected a name for the exception\000"};
YhZL *YaF_(Yev8 *Atoken, Y7Sj *Ain, Tbb AblockType); /* MParse.getCodeBlock */
YXCg *YOOP(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseWhile */
YXCg *YgOb(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseDo */
Zs15 YwIv = {"\015Missing UNTIL\000"};
YXCg *YS8Y(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseFor */
Zs50 YkPj = {"\060Sorry, only name supported for FOR loop variable\000"};
Zs12 YJji = {"\012Missing IN\000"};
Zs52 Yf98 = {"\062Cannot use TO or UNTIL with more than one variable\000"};
YXCg *YdOB(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseReturnExitThrowDefer */
YXCg *Yhta(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseBreakContinue */
YXCg *YlJY(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseSwitch */
Zs20 Y7Zb = {"\022CASE after DEFAULT\000"};
Zs19 YYge = {"\021Duplicate DEFAULT\000"};
Zs22 YO0F = {"\024DEFAULT follows CASE\000"};
Zs27 YE7Q = {"\031Unexpected item in SWITCH\000"};
YXCg *Ywf0(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseNewStatement */
YXCg *YG4L(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseBlockStatement */
void YQ6k(Y7Np *Amethod, Y7Sj *Ain, Tb AisLambda, Te Aend_token); /* MParse.parseArgDecl */
Zs15 YhTQ = {"\015missing comma\000"};
Zs30 YAe7 = {"\034superfluous comma before USE\000"};
Zs19 YV20 = {"\021superfluous comma\000"};
Zs55 YG1N = {"\065Cannot have another argument after a varargs argument\000"};
Zs22 YjHG = {"\024Missing type or name\000"};
Zs36 YTbL = {"\042Expected argument name; missing )?\000"};
Zs24 Y8XM = {"\026Expected default value\000"};
Zs49 YKXH = {"\057Cannot have both varargs and optional arguments\000"};
void YcHs(YYIi *Ad, YnZD *Aexpr); /* MParse.setPrefixFromExpr */
void Y6sC(YJON *Aza, Tb ArequireSep, Tl *Aaccepted, Y7Sj *Ain); /* MParse.parseAttr */
Zs25 Ymh8 = {"\027Expected attribute name\000"};
Zs38 Ypcv = {"\044missing =no or =yes after @backtrace\000"};
Zs39 YNcJ = {"\045expected =no or =yes after @backtrace\000"};
Zs19 YQK_ = {"\021missing = after @\000"};
Zs21 YThp = {"\023invalid value for @\000"};
Zs38 YDZt = {"\044No value expected for this attribute\000"};
Zs25 YKik = {"\027Unsupported attribute: \000"};
Td *YK6i = NULL; /* MParse.name2visibility */
Td *Yoe0 = NULL; /* MParse.name2zuiVisibility */
void Y5DG(Yev8 *Atoken, Tc *Aname, Tl *Aaccepted); /* MParse.checkAttrAccepted */
Zs31 YH8L = {"\035Attribute not allowed here: @\000"};
void Yo8f(Tb Avalue, Yev8 *Atoken, Tc *Aname); /* MParse.attrUsedTwice */
Zs25 YOzx = {"\027Attribute used twice: @\000"};
void YpNX(Tb AisSet, Yev8 *Atoken, Tc *Aname); /* MParse.visAttrSet */
Zs33 Y2U4 = {"\037Visibility set a second time: @\000"};
YnZD *YUWY(Y7Sj *Ain); /* MParse.parseExpr */
YnZD *Ybvc(Y7Sj *Ain); /* MParse.parseExprIfnil */
YnZD *YDIQ(Y7Sj *Ain); /* MParse.parseExprAlt */
Zs23 YCtv = {"\025Missing ':' after '?'\000"};
YnZD *YMzT(Y7Sj *Ain); /* MParse.parseExprOr */
YnZD *YALQ(Y7Sj *Ain); /* MParse.parseExprAnd */
YnZD *YDun(Y7Sj *Ain); /* MParse.parseExprComp */
YnZD *YF5Y(Y7Sj *Ain); /* MParse.parseExprConcat */
YnZD *Y97P(Y7Sj *Ain); /* MParse.parseExprBitwise */
YnZD *Yxkx(Y7Sj *Ain); /* MParse.parseExprShift */
YnZD *YxCP(Y7Sj *Ain); /* MParse.parseExprPlus */
YnZD *YsLP(Y7Sj *Ain); /* MParse.parseExprMult */
Zs16 YOH4 = {"\016Divide by zero\000"};
Zs25 Y3el = {"\027Cannot use % with float\000"};
YnZD *YV4G(Y7Sj *Ain); /* MParse.parseExprIndecr */
Zs23 Yy5o = {"\025white space before ++\000"};
Zs23 YN8o = {"\025white space before --\000"};
YnZD *YTtO(Y7Sj *Ain); /* MParse.parseExprUnary */
YnZD *YcvY(Y7Sj *Ain); /* MParse.parseExprDot */
YnZD *Y1cv(Y7Sj *Ain); /* MParse.parseExprParen */
Zs20 Y0GX = {"\022missing matching )\000"};
YnZD *Yc4G(Y7Sj *Ain); /* MParse.parseExprBase */
Zs13 YWlJ = {"\013Misplaced %\000"};
Zs18 YZ3P = {"\020Unexpected minus\000"};
Zs11 YnMg = {"\011Missing }\000"};
Zs14 YOm7 = {"\014unexpected ;\000"};
YnZD *YOXc(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseStringExpr */
Zs10 Y318 = {"\010ToString\000"};
YnZD *YblP(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseCurlyExpr */
YnZD *YKtr(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseObjectInitializer */
Zs17 YhDZ = {"\017To match this {\000"};
Zs15 YNoT = {"\015missing colon\000"};
Zs24 Ycz6 = {"\026unexpected white space\000"};
Zs18 Y2hw = {"\020expected a comma\000"};
YnZD *YdwE(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseLambdaExpr */
YnZD *YqGb(Y7Sj *Ain, Yev8 *Atoken); /* MParse.parseId */
Zs22 YJgb = {"\024Missing digit after \000"};
Zs30 Ydlx = {"\034Non-digit after hex number: \000"};
Zs41 YorS = {"\047Invalid character after binary number: \000"};
Zs26 YUOY = {"\030Non-digit after number: \000"};
Zs18 YG2L = {"\020invalid number: \000"};
YnZD *YsQE(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseNew */
Zs28 YA_q = {"\032Expected ), missing comma?\000"};
Zs20 YhYk = {"\022Expected ), found \000"};
YnZD *YZiK(Yev8 *AstartToken, Y7Sj *Ain); /* MParse.parseList */
Zs41 YC09 = {"\047Empty dictionary must be written as [:]\000"};
Zs36 Yigf = {"\042O[ can only be used for dictionary\000"};
Zs20 Y9_n = {"\022Expected ], found \000"};
YnZD *YvpI(Y7Sj *Ain, YnZD *AfirstKey, Tb AisL); /* MParse.parseDict */
Zs28 Y43V = {"\032Missing ':' after dict key\000"};
Tl *Ya1K(Y7Sj *Ain); /* MParse.parseDotNameList */
Zs25 YJzF = {"\027superfluous white space\000"};
YnZD *YTKt(Y7Sj *Ain, Tb AprefixOk, Tbs Awhat); /* MParse.parseDotName */
Zs25 YCCu = {"\027expected ID instead of \000"};
Zs19 YCEd = {"\021 not allowed here\000"};
Zs28 YZDt = {"\032expected type name, found \000"};
Zs25 Yu2L = {"\027unexpected token type: \000"};
Tb Y00A(YnZD *Aexpr); /* MParse.exprHasDollar */
Tb YpO1(YnZD *Aexpr); /* MParse.exprHasPercent */
void Ya8Z(Y7Sj *Ain, Tl *Atypes, Tb AitemNames); /* MParse.parseTypeSpec */
Zs27 Y1BZ = {"\031Missing > after type spec\000"};
void YyoS(Y7Sj *Ain, Tl *Atypes, Tb AitemNames); /* MParse.parseTypeList */
Zs32 Yfdg = {"\036white space required before =>\000"};
Tl *Yyre(Y7Sj *Ain); /* MParse.parseTypeNameList */
Zs12 YjZE = {"\012expected >\000"};
Zs12 YMpU = {"\012CommaFlags\000"};
Tt MParse__BCommaFlags__T = {25, ((Tc*)&YMpU), 0};
Tl *YZnz(Y7Sj *Ain, YnZD *AfirstExpr, Tbs Aflags); /* MParse.parseComma */
Zs48 YYCX = {"\056Argument without name after argument with name\000"};
Zs16 Yjbe = {"\016trailing comma\000"};
Zs12 YUGl = {"\012MemberType\000"};
Tt MParse__BMemberType__T = {25, ((Tc*)&YUGl), 0};
YnZD *Y3lj(YnZD *AstartExpr, Y7Sj *Ain, Tbs Awhat); /* MParse.parseMembers */
Zs11 Y2Kg = {"\011Missing )\000"};
Zs21 YlRP = {"\023expected ID after .\000"};
Zs31 YzHl = {"\035expected ID or number after =\000"};
Zs26 YVJU = {"\030expected number after =-\000"};
Zs27 YoAJ = {"\031Missing ] after subscript\000"};
Zs7 YclO = {"\005tuple\000"};
Zs6 Yknu = {"\004list\000"};
Zs11 YPxi = {"\011multiDict\000"};
Zs6 YdEY = {"\004pipe\000"};
Zs5 YOjT = {"\003set\000"};
Zs12 YCpI = {"\012sortedList\000"};
YXCg *YPL0(Y7Sj *Ain); /* MParse.copyCode */
Zs5 YNjT = {"\003ses\000"};
Zs22 YSrw = {"\024Missing ( after uses\000"};
Zs24 Ympj = {"\026Syntax error in uses()\000"};
Zs34 YFLI = {"\040Unexpected white space in uses()\000"};
Zs33 Y7QZ = {"\037Missing white space after comma\000"};
Zs8 YqCB = {"\006lockgc\000"};
Zs28 YcVF = {"\032Expected comment or uses()\000"};
Zs13 YMiN = {"\013missing <<<\000"};
void YBL_(YLuR *Ablock, Tc *Atext, YkxB *Apos); /* MParse.parseCopyPercent */
YXCg *YBsI(Yev8 *Atoken, Y7Sj *Ain); /* MParse.parseAlias */
Zs36 YLxU = {"\042Must both have a dollar or neither\000"};
Zs37 YKTL = {"\043Must both have a percent or neither\000"};
YXCg *YksO(Y7Sj *Ain); /* MParse.parseCType */
YLSh YljT(Y7Sj *Ain); /* MParse.parseCparens */
YnZD *Y9sl(Y7Sj *Ain); /* MParse.parseCCode */
void YHwp(Tc *Amsg, Y7Sj *Ain); /* MParse.error */
void YHwpa(Tc *Amsg, Ysbp *Apos); /* MParse.error */
void YQuF(Y7Sj *Ain); /* MParse.expectLineSep */
void YE5j(Y7Sj *Ain); /* MParse.expectNewLine */
void YQuFa(Y7Sj *Ain, Tb AallowSemicolon); /* MParse.expectLineSep */
Zs22 Y9h9 = {"\024unexpected semicolon\000"};
Zs36 YyZB = {"\042missing white space before comment\000"};
Zs49 Y5E1 = {"\057semicolon not allowed here, line break required\000"};
Zs20 YmhU = {"\022missing line break\000"};
void YzLT(Y7Sj *Ain); /* MParse.expectSep */
Zs22 YXMB = {"\024white space required\000"};
Yev8 *Y3DE = 0; /* MParse.lastSep */
void YBch(Y7Sj *Ain); /* MParse.skipSep */
void Y5bl(Y7Sj *Ain); /* MParse.skipLineSep */
Yev8 *Y6qU(Y7Sj *Ain); /* MParse.tokenAfterSep */
YU01 YdZD(Y7Sj *Ain); /* MParse.twoTokensAfterSep */
void YuRk(Y7Sj *Ain); /* MParse.checkNoSep */
void YE6J(Y7Sj *Ain); /* MParse.checkNoLineBreak */
Zs23 YwSe = {"\025unexpected line break\000"};
YnZD *YxDV(Te Atype, Ysbp *Apos); /* MParse.newZuiExpr */
int JParse(int round);
/* Parse done */
Zs9 YZVC = {"\007Usage: \000"};
Zs28 Y1c5 = {"\032 filename.zu ... outputDir\000"};
Zs36 Y0k0 = {"\042Last argument is not a directory: \000"};
Zs32 YoaB = {"\036Last argument not accessible: \000"};
YwDJ *YYjF(YwDJ *t, YrBF *Aparent, Tc *Aname, YXCg *Astmt, YJON *Aattr, Tc *Atype, YaHa *Aitems); /* CPage.NEW */
Ti YMst(YwDJ *t, YwDJ *Aother); /* CPage.Compare */
Tc *YoRE(YwDJ *t); /* CPage.parentName */
void YXei(YwDJ *t, Tc *Atext); /* CPage.addHeader */
void YWvO(YwDJ *t, Tc *Atext); /* CPage.addTail */
void YsLl(YwDJ *t, YrBF *Aparent, Tl *Aimplements); /* CPage.addImplements */
Zs4 YW0a = {"\002I.\000"};
To ToYwDJ[17];
Zs6 YW3M = {"\004Page\000"};
YrBF *YSjh(YrBF *t, YJON *Aattr, YrBF *Aparent, YwDJ *Apage, Tc *Aname, YaHa *Aitems); /* CParent.NEW */
void Y7hE(YrBF *t, Tc *Aname); /* CParent.addType */
Tb YXY0(YrBF *t, Tc *Aname); /* CParent.hasType */
To ToYrBF[8];
Zs8 YnhT = {"\006Parent\000"};
Td *Vpages = NULL;
void YSxp(Tc *AinFileName); /* processFile */
Zs5 YYv4 = {"\003.zu\000"};
Zs38 YpAh = {"\044ERROR: file name must end in '.zu': \000"};
Zs13 Yqha = {"\013ARRAY.array\000"};
Zs9 YdXv = {"\007T.array\000"};
Zs11 Yq48 = {"\011BOOL.bool\000"};
Zs8 YoH1 = {"\006T.bool\000"};
Zs23 Yj5A = {"\025BYTESTRING.byteString\000"};
Zs14 YlDi = {"\014T.byteString\000"};
Zs13 Ysz5 = {"\013THREAD.Cond\000"};
Zs8 YEf9 = {"\006T.cond\000"};
Zs11 Yq6m = {"\011DICT.dict\000"};
Zs8 YJ80 = {"\006T.dict\000"};
Zs9 Yk6j = {"\007DYN.dyn\000"};
Zs7 YzOx = {"\005T.dyn\000"};
Zs19 Y8Aj = {"\021THREAD.EvalThread\000"};
Zs14 YAmq = {"\014T.evalThread\000"};
Zs13 Y3um = {"\013FLOAT.float\000"};
Zs9 Ysau = {"\007T.float\000"};
Zs9 YZ7r = {"\007INT.int\000"};
Zs7 YDnK = {"\005T.int\000"};
Zs11 YzYD = {"\011LIST.list\000"};
Zs8 Yff_ = {"\006T.list\000"};
Zs13 YNza = {"\013THREAD.Lock\000"};
Zs8 YZfe = {"\006T.lock\000"};
Zs17 Y8lF = {"\017THREAD.AutoLock\000"};
Zs12 YWm4 = {"\012T.autoLock\000"};
Zs21 Yn4Y = {"\023MULTIDICT.MultiDict\000"};
Zs13 YqZb = {"\013T.multiDict\000"};
Zs19 Y6OI = {"\021MULTISET.MultiSet\000"};
Zs12 YDGg = {"\012T.multiSet\000"};
Zs9 YNmB = {"\007NAT.nat\000"};
Zs7 YoUW = {"\005T.nat\000"};
Zs11 Yplx = {"\011PIPE.Pipe\000"};
Zs8 Y8vt = {"\006T.pipe\000"};
Zs9 YKaX = {"\007SET.Set\000"};
Zs7 YpR8 = {"\005T.set\000"};
Zs23 YuxY = {"\025SORTEDLIST.SortedList\000"};
Zs14 Y80D = {"\014T.sortedList\000"};
Zs15 YrRy = {"\015STATUS.status\000"};
Zs10 YnDK = {"\010T.status\000"};
Zs15 YnNK = {"\015STRING.string\000"};
Zs10 Yz9k = {"\010T.string\000"};
Zs11 YUCs = {"\011TYPE.type\000"};
Zs8 YOZB = {"\006T.type\000"};
Zs15 YasT = {"\015THREAD.Thread\000"};
Zs10 YjxI = {"\010T.thread\000"};
Zs13 YIbo = {"\013TUPLE.Tuple\000"};
Zs9 YboU = {"\007T.tuple\000"};
Zs11 YpQB = {"\011TYPE.Type\000"};
Zs29 Yc08 = {"\033VARBYTESTRING.varByteString\000"};
Zs17 Yrn0 = {"\017T.varByteString\000"};
Zs21 YcK4 = {"\023VARSTRING.varString\000"};
Zs13 YFD0 = {"\013T.varString\000"};
Td *VbuiltinMap = NULL;
Zs7 YeUp = {"\005array\000"};
Zs55 Yaqp = {"\065<A class='typehref' href='ARRAY.array.html'>array</A>\000"};
Zs6 YtPw = {"\004bool\000"};
Zs52 Y_bS = {"\062<A class='typehref' href='BOOL.bool.html'>bool</A>\000"};
Zs12 YP0m = {"\012byteString\000"};
Zs65 YRfw = {"\077<A class='typehref' href='BYTES.byteString.html'>byteString</A>\000"};
Zs54 Ytv8 = {"\064<A class='typehref' href='THREAD.Cond.html'>cond</A>\000"};
Zs6 YOgw = {"\004dict\000"};
Zs52 YG7D = {"\062<A class='typehref' href='DICT.dict.html'>dict</A>\000"};
Zs49 Ye2t = {"\057<A class='typehref' href='DYN.dyn.html'>dyn</A>\000"};
Zs66 YTGY = {"\100<A class='typehref' href='THREAD.EvalThread.html'>evalThread</A>\000"};
Zs7 Yt7n = {"\005float\000"};
Zs55 YcX9 = {"\065<A class='typehref' href='FLOAT.float.html'>float</A>\000"};
Zs49 YDo5 = {"\057<A class='typehref' href='INT.int.html'>int</A>\000"};
Zs52 YREK = {"\062<A class='typehref' href='LIST.list.html'>list</A>\000"};
Zs54 Yq45 = {"\064<A class='typehref' href='THREAD.Lock.html'>lock</A>\000"};
Zs62 Yy0W = {"\074<A class='typehref' href='THREAD.AutoLock.html'>autoLock</A>\000"};
Zs67 Yu1V = {"\101<A class='typehref' href='MULTIDICT.MultiDict.html'>multiDict</A>\000"};
Zs10 YT13 = {"\010multiSet\000"};
Zs64 YlZ5 = {"\076<A class='typehref' href='MULTISET.MultiSet.html'>multiSet</A>\000"};
Zs5 YNmG = {"\003nat\000"};
Zs49 YzJL = {"\057<A class='typehref' href='NAT.nat.html'>nat</A>\000"};
Zs52 YFI7 = {"\062<A class='typehref' href='PIPE.Pipe.html'>pipe</A>\000"};
Zs49 YQJ4 = {"\057<A class='typehref' href='SET.Set.html'>set</A>\000"};
Zs70 YEM6 = {"\104<A class='typehref' href='SORTEDLIST.SortedList.html'>sortedList</A>\000"};
Zs8 YZQ2 = {"\006status\000"};
Zs58 YMs0 = {"\070<A class='typehref' href='STATUS.status.html'>status</A>\000"};
Zs58 YLNy = {"\070<A class='typehref' href='STRING.string.html'>string</A>\000"};
Zs58 YvDQ = {"\070<A class='typehref' href='THREAD.Thread.html'>thread</A>\000"};
Zs6 YT65 = {"\004type\000"};
Zs52 YX_g = {"\062<A class='typehref' href='TYPE.type.html'>type</A>\000"};
Zs55 Ycuk = {"\065<A class='typehref' href='TUPLE.Tuple.html'>tuple</A>\000"};
Zs74 YMrR = {"\110<A class='typehref' href='VARBYTES.varByteString.html'>varByteString</A>\000"};
Zs67 Y8jz = {"\101<A class='typehref' href='VARSTRING.varString.html'>varString</A>\000"};
Td *VknownTypes = NULL;
Tc *YH8U(Tc *Aname); /* builtinTranslate */
Zs10 Yg46 = {"\010@private\000"};
Zs12 Yych = {"\012@protected\000"};
Zs9 YhdP = {"\007@public\000"};
Zs7 Ymmd = {"\005@file\000"};
Zs12 YF4f = {"\012@directory\000"};
Td *VvisName = NULL;
void YEoy(YwDJ *Apage, Tc *AoutDirName); /* writePage */
Zs6 YvWD = {"\004<h1>\000"};
Zs11 YmHE = {"\011@abstract\000"};
Zs12 Y1Vq = {"\012@earlyInit\000"};
Zs7 YwPS = {"\005</h1>\000"};
Zs18 YNG2 = {"\020<h2>summary</h2>\000"};
Zs9 YBWA = {"\007<table>\000"};
Zs10 YADm = {"\010</table>\000"};
void YaYd(YwDJ *Apage, Tr Aout); /* writeImplements */
Zs12 YAtSa = {"\012&nbsp;<br>\000"};
Zs18 YlM6 = {"\020<div>Implements \000"};
Zs8 YP3b = {"\006</div>\000"};
void Ymvz(YwDJ *Apage, Tr Aout); /* writeImplementers */
Zs33 YujZ = {"\037Known implementing classes:<br>\000"};
Zs7 Ydgk = {"\005<div>\000"};
void YpPK(YwDJ *Apage, Tr Aout); /* writeSubClasses */
Zs23 YOOI = {"\025Known subclasses:<br>\000"};
void YO3Z(YwDJ *Apage, Yhqr *Adone, Tr Aout); /* writeInherited */
Zs28 Y3cs = {"\032<tr><td colspan=3>Parent: \000"};
Zs13 YtoW = {"\013</td></tr>\n\000"};
Zs35 YJ6I = {"\041<tr><td colspan=3>Inherited from \000"};
Zs14 YdSD = {"\014:</td></tr>\n\000"};
void YXA6(YwDJ *Apage, Tr Aout); /* writePieces */
Zs34 YV4I = {"\040<tr><td colspan=3>Included from \000"};
void YyrL(Tc *AoutDirName); /* writeIndex */
Zs7 YZ_F = {"\005index\000"};
Zs16 Y2BD = {"\016<h1>index</h1>\000"};
Zs11 Ymmq = {"\011MultiDict\000"};
Zs10 YAxF = {"\010MultiSet\000"};
Zs6 YJR6 = {"\004Pipe\000"};
Zs5 Yl4z = {"\003Set\000"};
Zs12 YBHe = {"\012SortedList\000"};
Zs8 YnY0 = {"\006Thread\000"};
Zs6 YeBN = {"\004Cond\000"};
Zs6 YzBS = {"\004Lock\000"};
Zs10 YTdt = {"\010AutoLock\000"};
Zs6 YIZD = {"\004<h3>\000"};
Zs15 Ydjn = {"\015builtin types\000"};
Zs17 YPHA = {"\017builtin modules\000"};
Zs7 YJSS = {"\005</h3>\000"};
Zs24 YgSX = {"\026<tr><td align='right'>\000"};
Zs32 Y9Qy = {"\036&nbsp;</td><td class='nowrap'>\000"};
Zs17 Yvkb = {"\017&nbsp;</td><td>\000"};
Zs12 YNaw = {"\012</td></tr>\000"};
Zs29 YTSL = {"\033<h3>second level items</h3>\000"};
void Ywyp(YXCg *Astmt, Tl *AlibStatements, YrBF *Aparent); /* handleClass */
Zs7 YpSv = {"\005START\000"};
Zs5 YPu_ = {"\003END\000"};
Zs11 YhgN = {"\011interface\000"};
Zs7 YeJk = {"\005class\000"};
Zs7 YfDf = {"\005piece\000"};
Zs7 Ya4C = {"\005?????\000"};
Zs6 Y89Q = {"\004enum\000"};
Zs6 Y4wh = {"\004bits\000"};
Zs7 YXek = {"\005alias\000"};
Zs20 YKGB = {"\022SortedListIterator\000"};
Zs6 YU_a = {"\004&lt;\000"};
void YFk5(YXCg *Astmt); /* handleModule */
Zs8 YcKD = {"\006Module\000"};
Zs8 YKwD = {"\006module\000"};
Td *Vmethods = NULL;
void Ye4o(YXCg *Astmt, YrBF *Aparent); /* handleAlias */
YT98 *Y5WC(YT98 *t, Tc *Aname, Tc *Arow); /* CSummaryEntry.NEW */
To ToYT98[3];
Zs14 Y0G4 = {"\014SummaryEntry\000"};
YHCf *Yjz5(YHCf *t); /* CSummary.NEW */
Ti YOvr(YHCf *t); /* CSummary.Size */
void YVWi(YHCf *t, Tc *AitemName, Tc *Arow); /* CSummary.add */
void YAEk(YHCf *t); /* CSummary.addSep */
void Y2QV(YHCf *t, Tc *Atext); /* CSummary.addHeader */
Zs20 Yf6C = {"\022<tr><td colspan=3>\000"};
Tc *Ytst(YHCf *t, Yhqr *Adone); /* CSummary.toString */
To ToYHCf[2];
Zs9 Yhsb = {"\007Summary\000"};
YHCf *Yjji(Tl *Astatements, Tl *AsharedStatements, YrBF *Aparent, YrBF *AthisClass, Tc *AitemName); /* summarize */
void Yhld(Tl *Astatements, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary); /* summarizeClasses */
Te YDXu(YJON *Aattr, YrBF *Aparent); /* getVisibility */
void YxMt(YXCg *Astmt, YrBF *Aparent, YHCf *Asummary); /* summarizeClass */
Zs13 YhFLa = {"\013&nbsp;</td>\000"};
Zs21 YbsA = {"\023<td class='nowrap'>\000"};
Zs9 YwxW = {"\007<small>\000"};
Zs10 YveI = {"\010</small>\000"};
Zs4 YJ7b = {"\002td\000"};
Zs8 Yf9s = {"\006</tr>\n\000"};
void YVrF(Tl *Astatements, Tb Amember, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary); /* summarizeVars */
Zs16 YPeR = {"\016</small>&nbsp;\000"};
Zs26 YiKI = {"\030</td><td class='nowrap'>\000"};
Zs11 Yk9v = {"\011<A href='\000"};
Zs8 YidB = {"\006.html#\000"};
Zs7 Y_Et = {"\005'><b>\000"};
Zs10 Y_wz = {"\010</b></A>\000"};
void YjWd(Tl *Astatements, Tb Amember, Tb AdoLibMethod, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary); /* summarizeMethods */
Tc *YXra(Tc *Aname, Tb Amember); /* makeDollarName */
void YaYU(YXCg *Astmt, Tb Amember, Tb AdoLibMethod, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary, Tb Aregister); /* summarizeMethod */
Zs9 YHtZa = {"\007cOMPARE\000"};
Zs9 Yb2I = {"\007Compare\000"};
Zs35 YqnL = {"\041</td><td class='nowrap'><A href='\000"};
Zs10 YilA = {"\010</b></a>\000"};
Zs10 YE9G = {"\010(<small>\000"};
Zs11 YuIo = {"\011</small>)\000"};
Zs10 YP1k = {"\010 <small>\000"};
Zs4 Ydha = {"\002, \000"};
Zs14 YfzN = {"\014&nbsp;</td>\n\000"};
Tc *YZi9(YFN2 *Aenum); /* listEnumValues */
Zs17 Y50q = {"\017<h2>values</h2>\000"};
Zs13 YJWh = {"\013<tr><td><b>\000"};
Zs21 YZ6b = {"\023</b>&nbsp;</td><td>\000"};
Tl *YSvC(Tl *Astatements, YrBF *Aparent, YrBF *AthisClass); /* findIncludes */
Tc *Y20k(Tl *Astatements, Tl *AsharedStatements, YrBF *Aparent, YrBF *AthisClass); /* listMembers */
Zs36 YW43 = {"\042<h2>members (alphabetically)</h2>\n\000"};
Zs35 YajA = {"\041<h2>shared (alphabetically)</h2>\n\000"};
Tc *YdL1(YXCg *Astmt, YrBF *Aparent, YrBF *AthisClass); /* printAlias */
Zs24 YSPB = {"\026<h2>aliased type</h2>\n\000"};
Tc *Yo3K(Td *Amembers); /* sortMembers */
void YWa4(Tl *Astatements, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Avars); /* listVars */
Zs5 YXdE = {"\003<p>\000"};
Zs8 YEZE = {"\006&nbsp;\000"};
Zs11 Y0gF = {"\011<A name='\000"};
Zs6 Y11k = {"\004</p>\000"};
void YB63(Tl *Astatements, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Amembers); /* listMethods */
Tb YfpX(YrBF *Aparent, YXCg *Astmt); /* isTypeMethod */
Zs6 Yefp = {"\004this\000"};
void YSYh(YXCg *Astmt, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Amembers); /* listMethod */
Zs21 Y01g = {"\023<p class='pheader'>\000"};
Zs12 Y_j7 = {"\012 @abstract\000"};
Zs11 YtWp = {"\011 @default\000"};
Zs11 Ypep = {"\011 @replace\000"};
Zs7 Yjdx = {"\005!0NEW\000"};
Zs8 Yw0Y = {"\006!1Init\000"};
Zs8 YkKS = {"\006Finish\000"};
Zs10 Y1U9 = {"\010!2Finish\000"};
Zs11 YkAg = {"\011!3Compare\000"};
Zs7 YHQQ = {"\005Equal\000"};
Zs9 YlKZ = {"\007!4Equal\000"};
Zs12 Y8AK = {"\012FromString\000"};
Zs14 YkRm = {"\014!5FromString\000"};
Zs10 Yju3 = {"\010Iterator\000"};
Zs12 YlQS = {"\012!6Iterator\000"};
Zs12 YGQt = {"\012!7ToString\000"};
Tc *YJgp(YaHa *AitemsArg, YrBF *AparentArg); /* getFooter */
Zs6 Y6XD = {"\004<h2>\000"};
Zs8 YwCp = {"\006</h2>\n\000"};
void YBfF(Tl *Astatements, YrBF *Aparent); /* handleClasses */
void YhbZ(Tl *Astatements, YrBF *Aparent); /* handleLibClasses */
Tc *YcAo(Tc *Atext, Tc *Aitem); /* getSection */
Zs4 Y6Ga = {"\002</\000"};
Zs4 YJJa = {"\002>\n\000"};
Tc *YLwI(Tc *Atext); /* getTextSection */
Zs7 YUHc = {"\005</p>\n\000"};
Tc *Y6Od(YrBF *Aparent, Tc *Atext); /* processComment */
Zs6 Yi9Y = {"\004&gt;\000"};
Zs7 Yycx = {"\005&amp;\000"};
Zs5 YvSD = {"\003<b>\000"};
Zs6 YAGk = {"\004</b>\000"};
Zs28 Yj8D = {"\032<span class='commentcode'>\000"};
Zs9 Ylkh = {"\007</span>\000"};
Zs6 Yo_a = {"\004@ ()\000"};
Zs11 Yf9v = {"\011<A href=\"\000"};
Zs4 YF1 = {"\002\">\000"};
Zs6 YZEk = {"\004</a>\000"};
Tc *Yy61(YrBF *Aparent, Tc *Aname, Tc *Aitem); /* getHref */
Zs7 Y1zY = {"\005.html\000"};
Zs3 YJ = {"\001#\000"};
Tc *Yiyv(Tc *Aname, Tb Abold); /* pageRef */
Tc *Yiyva(Tc *AfullName, Tc *Aname, Tb Abold); /* pageRef */
Zs9 YoT8 = {"\007.html'>\000"};
Zs6 YGQj = {"\004</A>\000"};
Tc *YWaa(YRBza *Atype, YrBF *Aparent, YrBF *AthisClass, Tb Awrap); /* getTypeName */
Tc *YGD4(Tl *AtypeList, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType, Tb AisFunc); /* getTypeList */
Zs9 YRSF = {"\007 =&gt; \000"};
Tc *YGD4a(Tl *AtypeList, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType); /* getTypeList */
Tc *Ydfw(YRBza *Atype, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType); /* getTypeRecurse */
Zs5 YuzG = {"\003nil\000"};
Zs4 Y4Y = {"\002 &\000"};
Zs22 YMW6 = {"\024Type not supported: \000"};
Tc *YJvB(YnZD *Aexpr, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType); /* getTypeFromExpr */
Zs6 Ybzf = {"\004func\000"};
Zs6 YSKk = {"\004proc\000"};
Zs10 Y05v = {"\010callback\000"};
Zs26 Ycbm = {"\030ExprType not supported: \000"};
Tc *YauL(Tl *Atypes, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType, Tb AisFunc); /* getTypeSpecString */
Tc *YauLa(Tl *Atypes, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType); /* getTypeSpecString */
Tc *YiXc(Tc *Aname, Tb Awrap); /* wrapKnownTypes */
Tc *Y40A(Tc *Atype, YrBF *AthisClass, Tb Awrap); /* wrapTypeRef */
Zs4 Y4ka = {"\002.I\000"};
Zs28 YMOA = {"\032<A class='typehref' href='\000"};
Tb YrHb(Tc *As); /* startsWithDotname */
Zs7 Yh3h = {"\005Titem\000"};
Zs6 Yb4F = {"\004Tkey\000"};
Zs9 Yvep = {"\007Tresult\000"};
Tc *Yb3r(Tl *Aarguments); /* getArgumentNames */
Tc *Yqvs(Tl *Aarguments, YrBF *Aparent, YrBF *AthisClass); /* getArgumentTypes */
Tc *Y2Xm(Tl *Aarguments, YrBF *Aparent, YrBF *AthisClass); /* getArguments */
YaHa *Y9vTa(YaHa *t, YrBF *Aparent, YXCg *Astmt, Tb Adummy); /* CDocItems.NEW */
YaHa *Y9vTb(YaHa *t, YrBF *Aparent, YYIi *Adecl); /* CDocItems.NEW */
void YuWe(YaHa *t, YrBF *Aparent, Tc *Acomment, Tb AuseStart); /* CDocItems.create */
Zs9 Y1Fa = {"\007</pre>\n\000"};
Zs23 YLSt = {"\025<pre class='example'>\000"};
To ToYaHa[5];
Zs10 Yu_u = {"\010DocItems\000"};
Tc *Y0ZR(YnZD *Aexpr, YrBF *Aparent); /* getDotName */
Tr YHH0(Tc *AoutDirName, Tc *AfullName, Tc *Atitle, YrBF *Aparent); /* writeHeader */
Zs39 YRJs = {"\045ERROR: Cannot open file for writing: \000"};
Zs10 Y3UZ = {"\010Writing \000"};
Zs9 YuQ3 = {"\007<title>\000"};
Zs32 Y0_7 = {"\036 - Zimbu documentation</title>\000"};
Zs29 YPTh = {"\033<table width='500'><tr><td>\000"};
Zs18 Ynep = {"\020.html'>up:&nbsp;\000"};
Zs11 Yhee = {"\011</td><td>\000"};
Zs20 YTI2 = {"\022&nbsp;&nbsp;&nbsp;\000"};
Zs32 YYIg = {"\036<A href='index.html'>index</A>\000"};
Zs37 YVLi = {"\043</td><td align='right' width='90%'>\000"};
Zs70 YbEl = {"\104<A href='http://www.zimbu.org/documentation'>Zimbu documentation</A>\000"};
Zs20 Yz5Q = {"\022</td></tr></table>\000"};
Zs691 Yn1L = {"\205\060<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n<html><head>\n<style type=\"text/css\">\nbody {\nfont-family: arial,sans-serif;\n}\n.keyword {\n  color: #774400;\n}\n.type {\n  color: #227722;\n}\n.attribute {\n  color: #990077;\n}\n.typehref {\n  color: #227722;\n  text-decoration: underline;\n}\n.example {\n  background-color: #EEFFCC;\n  border-color: #88AA66;\n  border-style: solid none;\n  border-width: 1px medium;\n  padding: 5px;\n}\n.commentcode {\n  font-family: monospace;\n  background-color: #EEFFCC;\n}\n.ptext {\n  margin-top: 3px;\n  margin-bottom: 3px;\n}\n.pheader {\n  margin-bottom: 3px;\n}\nsmall {\n  font-size: 60%;\n}\n.nowrap {\n  white-space: nowrap;\n  vertical-align: top;\n}\n</style>\n\000"};
Tc *VhtmlHeader = ((Tc*)&Yn1L);
Zs15 YnEX = {"\015</head><body>\000"};
Tc *VhtmlMiddle = ((Tc*)&YnEX);
Zs16 YwtH = {"\016</body></html>\000"};
Tc *VhtmlFooter = ((Tc*)&YwtH);
Zs76 YLWK = {"\112<table width=1000><tr><td width=40>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</td><td>\000"};
Tc *VhtmlIndentStart = ((Tc*)&YLWK);
Tc *VhtmlIndentEnd = ((Tc*)&Yz5Q);
Zs21 YgQM = {"\023<span class='type'>\000"};
Tc *VhtmlTypeStart = ((Tc*)&YgQM);
Tc *VhtmlTypeEnd = ((Tc*)&Ylkh);
Zs26 YJc_ = {"\030<span class='attribute'>\000"};
Tc *VhtmlAttrStart = ((Tc*)&YJc_);
Tc *VhtmlAttrEnd = ((Tc*)&Ylkh);
Zs34 YOPy = {"\040<span class='attribute'><small> \000"};
Tc *VhtmlSmallAttrStart = ((Tc*)&YOPy);
Zs17 YExz = {"\017</small></span>\000"};
Tc *VhtmlSmallAttrEnd = ((Tc*)&YExz);
Zs24 YYAK = {"\026<span class='keyword'>\000"};
Tc *VhtmlKeyStart = ((Tc*)&YYAK);
Tc *VhtmlKeyEnd = ((Tc*)&Ylkh);
Zs26 YOH1 = {"\030<tr><td>&nbsp;</td></tr>\000"};
Tc *VhtmlTableSep = ((Tc*)&YOH1);
Zs19 YA12 = {"\021<p class='ptext'>\000"};
Tc *VhtmlTextStart = ((Tc*)&YA12);

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
typedef struct Senv__S {
 int tosNr;
} Tn; /* per-thread environemnt */

Zsf *topFrame = NULL;
int inZa = 0;
int ZaEntered = 0;

Tn Zenv = {0};

void beforeExit() {
}


Tc *Zstr(char *s) {
 return ZnewString((Tc*)s, strlen(s));
}

/* allocate memory */
void *Za(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (Za)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* allocate memory with offset */
#define ZaOff(size) (Za((size) + ZOH_OFF) + ZOH_OFF)
#define ZranOff(ptr, osize, nsize) (Zran((ptr) ? (void*)(ptr) - ZOH_OFF : NULL, (osize) + ZOH_OFF, (nsize) + ZOH_OFF) + ZOH_OFF)

/* allocate memory */
void *ZaNm(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNm)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

void *ZaNmi(size_t size) {
 void *p = NULL;
 if (!inZa) {
  inZa = 1;
  p = calloc(1, size);
  inZa = 0;
 }
 if (p == NULL) {
  if (inZa || ZaEntered) {
   if (16384 - emergencyAllocUsed >= size) {
    p = emergencyAlloc + emergencyAllocUsed;
    emergencyAllocUsed += size;
    return p;
   }
   fputs("Out of memory (ZaNmi)\n", stderr);
   fflush(stderr);
   exit(1);
  }
  ++ZaEntered;
  ZthrowOutOfMemory(size);
 }
 ZaEntered = 0;
 return p;
}

/* reallocate memory */
void *Zran(void *op, size_t osize, size_t nsize) {
 void *p = NULL;
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
    ++ZaEntered;
    ZthrowOutOfMemory(nsize);
  }
  ZaEntered = 0;
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
 if (!inZa && !ZaEntered) {
  inZa = 1;
  p = realloc(op, nsize);
  inZa = 0;
  if (p == NULL) {
   ++ZaEntered;
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
Tc Yzok[]="D:/zimbu/lib/ARGModule.zu";
Tc Yhjo[]="D:/zimbu/lib/BOXModule.zu";
Tc Y_4X[]="D:/zimbu/lib/EModule.zu";
Tc YkTo[]="D:/zimbu/lib/IOModule.zu";
Tc YYTG[]="D:/zimbu/lib/LOGModule.zu";
Tc YHVE[]="D:/zimbu/lib/SETModule.zu";
Tc YuC6[]="D:/zimbu/lib/SORTEDLISTModule.zu";
Tc Ysv0[]="D:/zimbu/lib/TIMEModule.zu";
Tc Ypx4[]="D:/zimbu/lib/ZModule.zu";
Tc Ydmy[]="Input.zu";
Tc YQXZ[]="Parse.zu";
Tc YdPO[]="Token.zu";
Tc Y57c[]="TokenInput.zu";
Tc YqXi[]="Tokenizer.zu";
Tc Yg6g[]="ZUDIR/zui.zu";
Tc Y0CK[]="ZuiFile.zu";
Tc YGbq[]="zudocu.zu";
Tc Yaaa[]="";
Tcpos ZcTbl0[]={
{208,20},
{38,22},
{67,22},
{100,30},
{553,29},
};
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
Tc Y2cg[]="ARG.Bool.value()";
Tcpos ZcTbl61284[]={
{830,11},
{1,15},
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
Tc YZNA[]="ARG.String.setToDefault/1()";
Tcpos ZcTbl86206[]={
{953,11},
{1,16},
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
Tc YMnk[]="ARG.writeLead()";
Tcpos ZcTbl81798[]={
{569,5},
{2,5},
{3,7},
{2,5},
};
Tc YFeP[]="BOX.ListIterator__t1.hasNext()";
Tcpos ZcTbl83606[]={
{141,11},
{1,19},
};
Tc Yx5d[]="BOX.SortedListIterator__t1.NEW__p1/1()";
Tcpos ZcTbl16054[]={
{136,5},
{1,14},
};
Tc Yt30[]="BOX.SortedListIterator__t1.hasNext__p1/1()";
Tcpos ZcTbl18774[]={
{141,11},
{1,19},
};
Tc YDcJ[]="DocItems.NEW/1()";
Tcpos ZcTbl80633[]={
{2209,3},
{1,5},
{2,35},
{3,7},
{4,9},
};
Tc YyML[]="DocItems.NEW/2()";
Tcpos ZcTbl90834[]={
{2220,3},
{8,5},
{9,7},
{12,16},
{13,19},
{14,19},
{15,15},
{16,15},
{18,5},
{19,16},
{20,16},
{21,7},
{22,13},
{23,7},
{24,18},
{26,7},
{27,18},
};
Tc Yn14[]="DocItems.create()";
Tcpos ZcTbl70283[]={
{2256,9},
{1,16},
{9,5},
{10,19},
{11,19},
{12,7},
{15,9},
{18,18},
{19,18},
{20,16},
{21,20},
{22,15},
{23,18},
{25,7},
{28,7},
{29,9},
{37,17},
{40,11},
{42,18},
{43,29},
{45,18},
{46,29},
{47,22},
{49,18},
{52,18},
{55,11},
{57,15},
{58,25},
{59,22},
{60,25},
{62,25},
{64,27},
{66,15},
{67,26},
{68,22},
{69,26},
{71,26},
{73,28},
{75,15},
{76,26},
{78,17},
{79,28},
{81,26},
{83,28},
{84,32},
{86,15},
{87,26},
{88,22},
{89,26},
{91,26},
{93,28},
{94,32},
{96,15},
{97,24},
{98,26},
{100,15},
{101,17},
{102,33},
{103,17},
{104,17},
{106,17},
{108,26},
{110,27},
{111,17},
{113,23},
{114,24},
{115,11},
{116,22},
{117,26},
{118,30},
{120,11},
{121,13},
{122,24},
{126,9},
{9,5},
{128,5},
{129,16},
};
Tc Y5LR[]="E.BadValue.NEW__p2/2()";
Tcpos ZcTbl60593[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc Ya7k[]="E.Check.NEW__p2/3()";
Tcpos ZcTbl31332[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YSxu[]="E.Check.writeTo__p2/4()";
Tcpos ZcTbl35029[]={
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
Tc YN6w[]="E.Check.writeTo__p2/5()";
Tcpos ZcTbl45230[]={
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
Tc YpMw[]="E.Exception.NEW()";
Tcpos ZcTbl83031[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc Y2NH[]="E.IllegalByte.NEW__p3/3()";
Tcpos ZcTbl45209[]={
{60,5},
{1,16},
{2,12},
{4,20},
{4,24},
};
Tc YALK[]="E.IllegalByte.writeTo__p3/6()";
Tcpos ZcTbl9948[]={
{87,11},
{1,7},
{2,9},
{3,9},
{6,7},
{8,9},
{9,9},
{11,9},
};
Tc YFbI[]="E.IllegalByte.writeTo__p3/7()";
Tcpos ZcTbl20149[]={
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
Tc YhC6[]="E.KeyExists.NEW__p3/4()";
Tcpos ZcTbl95201[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc Y4Jj[]="E.OutOfRange.NEW__p3/4()";
Tcpos ZcTbl66582[]={
{69,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc YR5m[]="E.WrongType.NEW/1()";
Tcpos ZcTbl87235[]={
{514,5},
{1,16},
{2,12},
{4,20},
{4,24},
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
Tc Ys1a[]="IO";
Tcpos ZcTbl7452[]={
{26,8},
{3,8},
{6,8},
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
Tc YskO[]="IO.File.flush()";
Tcpos ZcTbl60567[]={
{564,11},
{1,20},
{2,7},
{4,4},
{12,14},
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
Tc Y5P_[]="IO.File.readByte()";
Tcpos ZcTbl16053[]={
{253,11},
{1,7},
{2,9},
{6,4},
{17,14},
};
Tc YHCY[]="IO.File.readChar()";
Tcpos ZcTbl46631[]={
{275,11},
{1,16},
{2,7},
{4,9},
{5,15},
{6,13},
{7,27},
{8,15},
{9,13},
{10,27},
{11,15},
{12,13},
{14,11},
{16,9},
{17,21},
{18,11},
{19,13},
{20,30},
{21,13},
{23,13},
{16,9},
{25,9},
{27,15},
{28,17},
{31,15},
{32,17},
{35,15},
{36,17},
{40,14},
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
Tc Y4qG[]="IO.StringWriter.Size()";
Tcpos ZcTbl34324[]={
{1416,11},
{1,7},
{2,16},
{5,26},
};
Tc YrJP[]="IO.StringWriter.ToString()";
Tcpos ZcTbl64531[]={
{1431,11},
{3,9},
{4,13},
{6,4},
{17,14},
};
Tc YYk7[]="IO.StringWriter.print__p1/8()";
Tcpos ZcTbl26760[]={
{184,11},
{1,7},
{2,16},
{4,14},
};
Tc YSa1[]="IO.StringWriter.remove()";
Tcpos ZcTbl58975[]={
{1453,11},
{1,7},
{2,16},
{6,11},
{7,19},
{8,9},
{9,21},
{10,21},
{11,11},
{12,23},
{13,23},
{14,13},
{16,25},
{17,25},
{18,17},
{22,17},
{26,15},
{36,14},
};
Tc Yijq[]="IO.StringWriter.truncate()";
Tcpos ZcTbl83443[]={
{1507,11},
{1,13},
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
Tc Y35R[]="IO.StringWriter.writeByte/1()";
Tcpos ZcTbl38552[]={
{1388,11},
{2,9},
{3,14},
{4,26},
{6,11},
{8,21},
{9,19},
{19,14},
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
Tc Yd0m[]="IO.fileInfo()";
Tcpos ZcTbl43483[]={
{1651,19},
{2,4},
{18,12},
};
Tc YTE3[]="IO.fileReader()";
Tcpos ZcTbl99838[]={
{926,4},
{5,9},
{6,4},
{16,12},
};
Tc Y5X7[]="IO.fileWriter()";
Tcpos ZcTbl81580[]={
{956,4},
{8,9},
{9,4},
{19,12},
};
Tc YN2v[]="IO.flush()";
Tcpos ZcTbl46761[]={
{1337,4},
{9,12},
};
Tc YNFk[]="IO.print()";
Tcpos ZcTbl1872[]={
{1227,37},
{1,4},
{13,12},
};
Tc Y_pS[]="IO.write()";
Tcpos ZcTbl84870[]={
{1168,4},
{13,12},
};
Tc YOoa[]="Input.NEW()";
Tcpos ZcTbl44401[]={
{32,3},
{1,9},
{2,10},
{3,16},
{4,13},
{5,5},
{6,21},
};
Tc Yjek[]="Input.NEW/1()";
Tcpos ZcTbl90157[]={
{44,3},
{1,11},
{2,14},
{3,10},
{4,16},
{5,13},
};
Tc YHM2[]="Input.get()";
Tcpos ZcTbl19887[]={
{56,9},
{2,5},
{3,9},
{4,15},
{5,16},
{6,7},
{7,11},
{9,11},
{10,9},
{11,17},
{14,7},
{15,11},
{16,17},
{18,9},
{19,11},
{20,13},
{21,15},
{22,20},
{23,13},
{24,15},
{26,15},
{27,28},
{28,13},
{29,15},
{32,7},
{14,7},
{35,5},
{36,20},
{37,7},
{40,5},
{41,7},
{44,12},
};
Tc Yq05[]="Input.push()";
Tcpos ZcTbl34047[]={
{104,9},
{1,5},
{2,7},
{3,7},
{4,18},
{5,18},
{7,17},
{9,7},
{10,9},
};
Tc YVvh[]="LOG";
Tcpos ZcTbl83326[]={
{21,14},
{2,14},
{50,20},
};
Tc YFIR[]="LOG.flush()";
Tcpos ZcTbl56555[]={
{226,5},
{1,5},
{2,7},
{4,15},
};
Tc Y8w5[]="LOG.reportStack()";
Tcpos ZcTbl84899[]={
{213,7},
{1,7},
{2,18},
{2,7},
{2,18},
{3,9},
{2,7},
};
Tc Y9QD[]="Main()";
Tcpos ZcTbl5270[]={
{29,3},
{1,5},
{2,10},
{5,27},
{6,25},
{7,3},
{8,5},
{9,7},
{11,7},
{16,3},
{17,5},
{16,3},
{21,3},
{22,5},
{23,7},
{21,3},
{28,3},
{30,10},
};
Tc YjEW[]="Page.Compare()";
Tcpos ZcTbl21859[]={
{120,9},
{1,28},
};
Tc YiJI[]="Page.NEW()";
Tcpos ZcTbl32878[]={
{89,3},
{3,13},
{4,15},
{5,11},
{6,11},
{7,11},
{8,11},
{9,5},
{10,17},
{12,17},
{14,5},
{16,13},
{17,11},
{18,5},
{19,16},
{21,16},
{23,5},
{24,16},
{25,13},
{27,17},
};
Tc Ysdj[]="Page.addHeader()";
Tcpos ZcTbl42842[]={
{140,9},
{1,13},
};
Tc Y0KY[]="Page.addImplements()";
Tcpos ZcTbl32779[]={
{148,9},
{1,5},
{4,18},
{5,7},
{6,11},
{8,7},
{1,5},
};
Tc Yw6n[]="Page.addTail()";
Tcpos ZcTbl57439[]={
{144,9},
{1,11},
};
Tc YWZE[]="Page.parentName()";
Tcpos ZcTbl16195[]={
{128,9},
{1,5},
{3,46},
{4,7},
{5,16},
{9,13},
};
Tc YqS8[]="Parent.NEW()";
Tcpos ZcTbl63527[]={
{174,3},
{2,11},
{3,13},
{4,11},
{5,11},
{6,5},
{7,17},
{9,17},
{11,12},
};
Tc Y5vg[]="Parent.addType()";
Tcpos ZcTbl81692[]={
{188,9},
{1,5},
{2,18},
{4,5},
};
Tc YYPv[]="Parent.hasType()";
Tcpos ZcTbl74211[]={
{195,9},
{1,5},
{2,7},
{3,16},
{5,22},
{7,12},
};
Tc YipB[]="Parse";
Tcpos ZcTbl45907[]={
{297,18},
{1956,28},
{1963,32},
{4216,9},
};
Tc YzRJ[]="Parse.attrUsedTwice()";
Tcpos ZcTbl7598[]={
{2282,5},
{1,7},
};
Tc YLD5[]="Parse.checkAttrAccepted()";
Tcpos ZcTbl27280[]={
{2271,5},
{1,7},
{2,9},
{0,5},
{5,5},
};
Tc YGSM[]="Parse.checkNoLineBreak()";
Tcpos ZcTbl49482[]={
{4591,21},
{1,5},
{2,7},
};
Tc YEtq[]="Parse.checkNoSep()";
Tcpos ZcTbl89237[]={
{4580,21},
{1,5},
{2,7},
{4,7},
};
Tc YbgE[]="Parse.copyCode()";
Tcpos ZcTbl7028[]={
{4078,30},
{4,10},
{8,5},
{14,5},
{15,37},
{16,9},
{17,7},
{20,7},
{21,17},
{22,14},
{23,9},
{25,13},
{26,11},
{27,13},
{28,21},
{30,22},
{31,13},
{32,32},
{33,15},
{34,17},
{35,25},
{38,15},
{39,17},
{40,15},
{43,15},
{44,17},
{45,19},
{47,19},
{49,25},
{52,15},
{53,17},
{54,25},
{31,13},
{59,25},
{61,11},
{62,18},
{63,11},
{64,19},
{14,5},
{70,30},
{71,23},
{72,5},
{73,9},
{74,7},
{75,9},
{80,7},
{81,9},
{82,9},
{80,7},
{85,7},
{86,18},
{87,28},
{88,9},
{92,18},
{94,7},
{95,9},
{72,5},
{100,5},
{101,9},
{102,7},
{100,5},
{107,26},
{114,22},
{115,26},
{116,5},
{117,22},
{118,7},
{120,25},
{121,17},
{122,9},
{123,9},
{125,23},
{127,9},
{129,11},
{131,19},
{134,19},
{135,21},
{137,11},
{138,11},
{139,13},
{138,11},
{141,11},
{142,13},
{146,11},
{148,13},
{146,11},
{151,9},
{152,11},
{154,21},
{155,13},
{160,18},
{161,13},
{162,15},
{163,24},
{165,13},
{167,15},
{168,13},
{169,13},
{171,21},
{172,20},
};
Tcpos ZcTbl7029[]={
{4251,22},
{2,17},
{5,19},
{6,17},
{10,17},
{-57,5},
{15,5},
{17,12},
{18,7},
{19,9},
{20,18},
{22,7},
{25,12},
};
Tc Yrgp[]="Parse.error()";
Tcpos ZcTbl80808[]={
{4426,5},
};
Tc YNv2[]="Parse.error/1()";
Tcpos ZcTbl42956[]={
{4432,5},
};
Tc YuKH[]="Parse.expectLineSep()";
Tcpos ZcTbl1915[]={
{4440,5},
};
Tc YlOY[]="Parse.expectLineSep/1()";
Tcpos ZcTbl40839[]={
{4451,22},
{2,5},
{3,15},
{4,12},
{5,13},
{7,5},
{8,7},
{10,15},
{11,9},
{12,11},
{14,11},
{15,11},
{17,9},
{19,7},
{20,9},
{24,5},
{25,15},
{27,7},
{28,9},
{29,25},
{30,14},
{31,9},
{32,11},
{34,11},
{35,11},
{36,13},
{40,9},
{41,9},
{42,11},
};
Tc YxBM[]="Parse.expectNewLine()";
Tcpos ZcTbl52917[]={
{4445,5},
};
Tc YYdB[]="Parse.expectSep()";
Tcpos ZcTbl68691[]={
{4502,22},
{1,5},
{2,7},
{3,7},
{4,9},
};
Tc YxVS[]="Parse.exprHasDollar()";
Tcpos ZcTbl7515[]={
{3620,24},
{1,5},
{2,9},
{1,5},
{4,5},
{5,24},
{7,12},
};
Tc YN96[]="Parse.exprHasPercent()";
Tcpos ZcTbl45322[]={
{3632,24},
{1,5},
{2,9},
{1,5},
{4,5},
{5,24},
{7,12},
};
Tc YTEI[]="Parse.getAs()";
Tcpos ZcTbl12654[]={
{193,5},
{1,22},
{2,5},
{3,11},
{4,5},
{5,7},
{7,12},
};
Tc YClq[]="Parse.getCodeBlock()";
Tcpos ZcTbl81956[]={
{1610,27},
{1,33},
{2,5},
{3,7},
{4,7},
{6,7},
{8,5},
{9,12},
};
Tc YBJK[]="Parse.isAssign()";
Tcpos ZcTbl33439[]={
{1354,9},
};
Tc YrSB[]="Parse.makeIncDecStatement()";
Tcpos ZcTbl25475[]={
{523,18},
{2,26},
{3,5},
{7,12},
};
Tc YU1K[]="Parse.newZuiExpr()";
Tcpos ZcTbl84323[]={
{4599,27},
{1,5},
{2,5},
{3,12},
};
Tc YYXN[]="Parse.parseAlias()";
Tcpos ZcTbl7035[]={
{4299,5},
{1,15},
{5,5},
{6,27},
{9,5},
{10,29},
{12,5},
{13,7},
{15,12},
{16,7},
{17,9},
{19,7},
{20,9},
{25,25},
{26,5},
{29,27},
{30,5},
{31,5},
{33,28},
{34,5},
{40,5},
{41,5},
{42,7},
{46,21},
{47,5},
{48,7},
{50,5},
{52,26},
{53,5},
{59,12},
};
Tc YniQ[]="Parse.parseArgDecl()";
Tcpos ZcTbl26683[]={
{1984,5},
{1,5},
{2,24},
{3,7},
{6,7},
{8,18},
{9,9},
{10,34},
{12,9},
{13,9},
{16,9},
{17,11},
{19,9},
{20,9},
{21,11},
{24,7},
{25,9},
{26,15},
{27,9},
{28,17},
{32,7},
{33,9},
{36,27},
{37,23},
{38,7},
{39,7},
{41,9},
{43,15},
{44,9},
{46,11},
{47,11},
{48,20},
{49,11},
{50,16},
{51,11},
{54,37},
{55,11},
{59,17},
{60,11},
{61,13},
{63,11},
{64,11},
{68,13},
{69,7},
{71,22},
{72,9},
{73,15},
{77,7},
{78,9},
{79,15},
{81,9},
{82,11},
{86,15},
{87,16},
{88,11},
{92,7},
{95,9},
{96,35},
{101,14},
{102,9},
{104,15},
{105,9},
{106,17},
{107,11},
{110,9},
{111,11},
{115,36},
{116,9},
{122,9},
{124,11},
{125,11},
{126,11},
{127,11},
{128,24},
{129,16},
{130,11},
{134,7},
{135,9},
{140,13},
{141,7},
{143,9},
{145,7},
{146,9},
{1,5},
};
Tc YEtp[]="Parse.parseAssign()";
Tcpos ZcTbl90238[]={
{1369,26},
{1,5},
{3,12},
{5,12},
{7,12},
{9,12},
{11,12},
{13,5},
{14,26},
{16,5},
{18,42},
{20,7},
{21,9},
{22,31},
{23,9},
{24,11},
{27,9},
{28,9},
{20,7},
{31,11},
{32,7},
{34,7},
{36,9},
{41,5},
{42,5},
{44,26},
{45,5},
{48,12},
};
Tc Ybj5[]="Parse.parseAttr()";
Tcpos ZcTbl80772[]={
{2144,20},
{1,5},
{2,21},
{3,7},
{6,7},
{7,9},
{9,9},
{10,17},
{12,13},
{13,13},
{14,7},
{15,9},
{18,31},
{20,13},
{21,7},
{22,15},
{24,19},
{26,9},
{28,7},
{30,7},
{31,9},
{32,11},
{33,26},
{34,11},
{36,11},
{37,26},
{38,11},
{40,11},
{42,11},
{44,33},
{46,9},
{47,11},
{49,44},
{50,53},
{53,11},
{54,13},
{56,11},
{57,13},
{58,13},
{60,13},
{61,13},
{65,9},
{66,11},
{68,9},
{69,11},
{70,11},
{71,25},
{72,11},
{73,11},
{74,25},
{75,11},
{76,11},
{77,25},
{78,11},
{79,11},
{80,25},
{81,11},
{82,11},
{83,25},
{84,11},
{85,11},
{86,25},
{87,11},
{88,11},
{89,25},
{90,11},
{91,11},
{92,25},
{93,11},
{94,11},
{96,49},
{98,11},
{99,13},
{100,13},
{102,13},
{1,5},
};
Tc Yysl[]="Parse.parseBits()";
Tcpos ZcTbl27063[]={
{1021,25},
{1,26},
{2,5},
{4,5},
{5,15},
{7,5},
{8,22},
{9,5},
{10,7},
{12,5},
{13,33},
{14,5},
{15,7},
{17,5},
{18,33},
{19,5},
{23,5},
{24,5},
{25,7},
{28,12},
};
Tc YYLp[]="Parse.parseBlock()";
Tcpos ZcTbl99036[]={
{269,38},
{2,5},
{3,28},
{4,7},
{7,7},
{8,9},
{9,11},
{11,11},
{2,5},
{15,5},
{16,24},
{17,7},
{18,9},
{20,9},
{24,12},
};
Tc YGfO[]="Parse.parseBlockItem()";
Tcpos ZcTbl12499[]={
{305,22},
{2,5},
{4,9},
{5,16},
{13,17},
{17,9},
{18,16},
{21,9},
{22,17},
{26,16},
{32,30},
{33,16},
{37,16},
{40,16},
{46,16},
{49,16},
{52,9},
{54,11},
{55,18},
{57,9},
{60,9},
{63,30},
{64,30},
{65,9},
{66,11},
{67,18},
{69,9},
{72,9},
{80,24},
{81,20},
{82,16},
{85,9},
{86,17},
{89,16},
{92,16},
{103,16},
{106,16},
{112,9},
{113,16},
{116,16},
{125,5},
{126,7},
{129,5},
{132,16},
{138,9},
{139,16},
{142,16},
{148,9},
{149,16},
{152,16},
{155,16},
{159,9},
{160,16},
{163,16},
{169,16},
{173,16},
{176,16},
{184,9},
{185,16},
{188,16},
{191,16},
{198,9},
{200,35},
{202,9},
{203,11},
{205,9},
{207,16},
{210,9},
{213,13},
};
Tc YG6y[]="Parse.parseBlockStatement()";
Tcpos ZcTbl83593[]={
{1959,5},
{1,27},
{2,26},
{3,5},
{7,12},
};
Tc Yt45[]="Parse.parseBreakContinue()";
Tcpos ZcTbl29319[]={
{1843,36},
{1,5},
{3,26},
{4,5},
{8,12},
};
Tc YK_x[]="Parse.parseCCode()";
Tcpos ZcTbl98191[]={
{4418,20},
{1,28},
{2,5},
{3,12},
};
Tc YCEY[]="Parse.parseCType()";
Tcpos ZcTbl74330[]={
{4365,24},
{2,28},
{3,5},
{5,5},
{6,22},
{8,12},
};
Tc Yo4X[]="Parse.parseClass()";
Tcpos ZcTbl70447[]={
{718,5},
{1,15},
{3,40},
{4,36},
{5,27},
{6,5},
{7,7},
{9,5},
{10,7},
{13,25},
{14,5},
{15,7},
{19,5},
{20,22},
{21,5},
{22,7},
{24,25},
{27,11},
{28,5},
{29,7},
{30,7},
{31,13},
{35,5},
{36,7},
{37,13},
{38,7},
{39,33},
{40,7},
{41,7},
{42,41},
{44,9},
{45,11},
{48,13},
{52,5},
{53,7},
{54,9},
{56,7},
{57,13},
{58,7},
{59,39},
{60,7},
{63,5},
{66,5},
{69,39},
{70,39},
{71,5},
{73,7},
{76,7},
{81,13},
{84,7},
{85,7},
{87,7},
{71,5},
{90,5},
{91,5},
{92,7},
{94,7},
{98,11},
{99,5},
{100,7},
{101,7},
{103,7},
{107,28},
{108,5},
{116,5},
{117,7},
{120,26},
{121,5},
{125,12},
};
Tc YSSX[]="Parse.parseComma()";
Tcpos ZcTbl31338[]={
{3792,5},
{1,12},
{3,12},
{6,37},
{8,5},
{11,7},
{12,9},
{13,11},
{15,16},
{16,15},
{18,28},
{19,9},
{20,9},
{21,9},
{22,14},
{23,14},
{24,9},
{27,7},
{28,9},
{32,16},
{33,11},
{37,16},
{39,9},
{42,7},
{45,7},
{46,24},
{47,7},
{49,12},
{50,7},
{51,9},
{52,11},
{8,5},
{58,12},
};
Tc Yj7N[]="Parse.parseCopyPercent()";
Tcpos ZcTbl58921[]={
{4282,5},
{1,21},
{2,10},
{3,23},
{5,21},
{6,10},
{8,5},
{10,5},
};
Tc YV_n[]="Parse.parseCparens()";
Tcpos ZcTbl91041[]={
{4378,37},
{1,16},
{2,5},
{3,7},
{4,14},
{8,5},
{9,9},
{10,5},
{8,5},
{11,5},
{15,30},
{17,5},
{18,7},
{19,9},
{20,16},
{22,9},
{23,7},
{24,9},
{27,9},
{28,16},
{29,9},
{31,7},
{17,5},
{33,19},
};
Tc Y5mz[]="Parse.parseCurlyExpr()";
Tcpos ZcTbl21339[]={
{3226,22},
{2,5},
{3,10},
{5,10},
{6,13},
{8,24},
{9,5},
{10,5},
{11,7},
{15,5},
{17,14},
{19,12},
};
Tc YZlX[]="Parse.parseDeclaration()";
Tcpos ZcTbl13987[]={
{538,19},
{4,5},
{6,13},
{7,17},
{8,23},
{10,13},
{11,18},
{13,5},
{14,7},
{15,7},
{16,9},
{18,9},
{20,15},
{24,25},
{25,30},
{28,5},
{29,19},
{35,25},
{36,5},
{40,5},
{41,13},
{42,7},
{44,9},
{45,15},
{46,9},
{47,14},
{50,9},
{57,21},
{59,5},
{60,19},
{63,5},
{64,7},
{67,5},
{69,28},
{70,5},
{78,5},
{79,7},
{81,5},
{82,7},
{84,5},
{85,7},
{86,7},
{89,26},
{90,5},
{93,12},
};
Tc YcTl[]="Parse.parseDict()";
Tcpos ZcTbl23149[]={
{3487,5},
{1,7},
{3,22},
{4,31},
{5,5},
{6,7},
{8,5},
{9,35},
{10,7},
{12,9},
{13,23},
{14,15},
{16,15},
{18,9},
{19,15},
{20,9},
{21,11},
{22,11},
{25,11},
{26,13},
{30,9},
{31,32},
{33,9},
{38,9},
{39,11},
{42,11},
{44,9},
{45,15},
{48,9},
{49,11},
{52,9},
{10,7},
{55,5},
{56,11},
{57,5},
{58,7},
{61,12},
};
Tc Y0pQ[]="Parse.parseDo()";
Tcpos ZcTbl35424[]={
{1649,5},
{2,33},
{4,22},
{5,5},
{6,7},
{10,7},
{11,33},
{12,7},
{14,28},
{15,7},
{17,28},
{18,7},
{21,7},
{24,26},
{25,5},
{28,31},
{29,5},
{30,5},
{31,7},
{35,5},
{37,12},
};
Tc YCLx[]="Parse.parseDotName()";
Tcpos ZcTbl89805[]={
{3580,22},
{2,5},
{3,12},
{4,39},
{6,32},
{7,23},
{8,7},
{9,9},
{10,14},
{11,9},
{13,12},
{15,20},
{16,7},
{17,9},
{19,9},
{21,19},
{22,23},
{23,12},
{24,23},
{25,12},
{27,7},
{28,9},
{30,9},
{32,12},
{35,12},
};
Tc Y1BW[]="Parse.parseDotNameList()";
Tcpos ZcTbl41085[]={
{3553,34},
{1,5},
{2,5},
{3,7},
{7,24},
{8,7},
{10,9},
{12,7},
{13,15},
{15,7},
{16,7},
{2,5},
{18,12},
};
Tc YSl9[]="Parse.parseEnum()";
Tcpos ZcTbl99666[]={
{1058,5},
{1,15},
{5,5},
{6,22},
{7,5},
{8,7},
{10,29},
{13,25},
{14,5},
{16,25},
{18,5},
{19,5},
{20,13},
{21,27},
{22,7},
{23,9},
{26,7},
{27,9},
{28,11},
{30,11},
{35,23},
{37,20},
{38,7},
{39,9},
{41,9},
{47,7},
{48,21},
{51,7},
{52,21},
{55,35},
{56,7},
{60,7},
{61,9},
{63,7},
{64,9},
{19,5},
{68,26},
{69,5},
{71,33},
{72,5},
{78,5},
{79,7},
{82,12},
};
Tc YdwV[]="Parse.parseExpr()";
Tcpos ZcTbl3176[]={
{2299,12},
};
Tc YlJ9[]="Parse.parseExprAlt()";
Tcpos ZcTbl72429[]={
{2330,27},
{1,5},
{2,14},
{5,19},
{6,5},
{7,7},
{8,13},
{9,7},
{11,26},
{12,7},
{13,12},
{15,9},
{16,7},
{18,7},
{19,13},
{20,7},
{21,9},
{22,9},
{24,9},
{25,11},
{26,9},
{29,12},
};
Tc Y6Fz[]="Parse.parseExprAnd()";
Tcpos ZcTbl69815[]={
{2394,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{11,13},
{12,7},
{14,26},
{15,7},
{16,12},
{18,9},
{19,7},
{5,5},
{21,12},
};
Tc YiXca[]="Parse.parseExprBase()";
Tcpos ZcTbl10807[]={
{3016,22},
{3,5},
{5,17},
{8,17},
{10,17},
{12,17},
{14,17},
{16,17},
{18,17},
{20,17},
{22,17},
{24,17},
{26,17},
{28,17},
{30,17},
{32,28},
{33,17},
{36,17},
{37,12},
{38,14},
{40,14},
{43,17},
{44,12},
{45,14},
{47,14},
{50,17},
{51,12},
{52,14},
{53,34},
{55,14},
{56,14},
{57,34},
{58,14},
{60,14},
{64,17},
{67,17},
{69,17},
{74,33},
{75,25},
{76,12},
{77,14},
{79,40},
{80,17},
{83,17},
{86,12},
{90,12},
{91,17},
{94,12},
};
Tc YeHq[]="Parse.parseExprBitwise()";
Tcpos ZcTbl5223[]={
{2563,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{12,7},
{13,13},
{14,7},
{16,30},
{18,7},
{24,9},
{25,15},
{26,27},
{27,15},
{29,15},
{31,9},
{33,28},
{34,9},
{35,11},
{36,27},
{37,11},
{39,11},
{41,9},
{42,9},
{43,9},
{44,14},
{5,5},
{47,12},
};
Tc Y9gJ[]="Parse.parseExprComp()";
Tcpos ZcTbl87327[]={
{2422,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{25,24},
{26,7},
{28,18},
{29,15},
{32,9},
{33,9},
{34,15},
{36,7},
{37,9},
{39,9},
{42,32},
{43,26},
{44,7},
{46,13},
{48,13},
{50,13},
{52,13},
{54,13},
{55,15},
{57,15},
{60,13},
{62,13},
{64,13},
{66,13},
{68,13},
{70,13},
{72,13},
{75,7},
{76,7},
{78,7},
{80,9},
{85,11},
{86,17},
{89,32},
{90,9},
{91,9},
{94,11},
{96,9},
{97,11},
{99,16},
{102,14},
{103,11},
{104,9},
{5,5},
{107,12},
};
Tc Y58p[]="Parse.parseExprConcat()";
Tcpos ZcTbl22232[]={
{2536,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{11,13},
{12,7},
{14,26},
{15,7},
{16,12},
{18,7},
{5,5},
{20,12},
};
Tc Yc5i[]="Parse.parseExprDot()";
Tcpos ZcTbl44535[]={
{2938,27},
{1,5},
{2,14},
{6,12},
};
Tc Y85Z[]="Parse.parseExprIfnil()";
Tcpos ZcTbl99618[]={
{2306,27},
{1,5},
{2,14},
{5,5},
{6,7},
{7,24},
{8,7},
{10,26},
{11,7},
{12,12},
{14,9},
{15,7},
{17,12},
};
Tc YPlW[]="Parse.parseExprIndecr()";
Tcpos ZcTbl91829[]={
{2843,22},
{3,5},
{4,7},
{5,17},
{7,17},
{9,7},
{11,7},
{14,27},
{15,5},
{16,14},
{18,5},
{19,7},
{20,12},
{23,11},
{26,5},
{27,23},
{28,7},
{29,9},
{30,15},
{31,24},
{32,9},
{33,15},
{35,9},
{38,5},
{39,33},
{40,7},
{41,9},
{43,9},
{45,7},
{46,7},
{47,12},
{49,7},
{52,12},
};
Tc Y1EK[]="Parse.parseExprMult()";
Tcpos ZcTbl65246[]={
{2741,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{12,7},
{15,21},
{16,9},
{20,7},
{21,13},
{22,7},
{24,30},
{26,7},
{32,9},
{33,15},
{35,11},
{36,13},
{37,17},
{38,29},
{39,17},
{41,17},
{44,9},
{48,10},
{53,9},
{55,16},
{57,16},
{60,9},
{62,16},
{64,16},
{66,9},
{67,16},
{69,11},
{70,13},
{71,29},
{72,18},
{74,13},
{77,9},
{78,9},
{80,28},
{81,9},
{82,11},
{83,27},
{84,11},
{86,11},
{88,9},
{89,9},
{90,9},
{91,14},
{5,5},
{95,12},
};
Tc YxvM[]="Parse.parseExprOr()";
Tcpos ZcTbl41733[]={
{2366,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{11,13},
{12,7},
{14,26},
{15,7},
{16,12},
{18,9},
{19,7},
{5,5},
{21,12},
};
Tc YWPO[]="Parse.parseExprParen()";
Tcpos ZcTbl92122[]={
{2952,22},
{2,5},
{3,7},
{4,30},
{5,7},
{6,16},
{8,7},
{9,29},
{10,7},
{11,9},
{14,7},
{27,14},
{29,14},
{30,9},
{33,7},
{34,12},
{36,12},
};
Tc YDdP[]="Parse.parseExprPlus()";
Tcpos ZcTbl85648[]={
{2665,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{11,13},
{12,7},
{14,30},
{16,7},
{22,9},
{23,15},
{25,15},
{27,9},
{31,10},
{36,9},
{38,16},
{40,16},
{43,9},
{45,16},
{47,16},
{49,9},
{50,16},
{52,16},
{54,9},
{55,9},
{57,28},
{58,9},
{59,11},
{61,11},
{63,9},
{64,9},
{65,9},
{66,14},
{5,5},
{69,12},
};
Tc YowX[]="Parse.parseExprShift()";
Tcpos ZcTbl95330[]={
{2617,27},
{1,5},
{2,14},
{5,5},
{6,21},
{7,7},
{10,7},
{11,13},
{12,7},
{14,30},
{16,7},
{22,9},
{23,15},
{25,15},
{27,9},
{29,28},
{30,9},
{31,11},
{33,11},
{35,9},
{36,9},
{37,9},
{38,14},
{5,5},
{41,12},
};
Tc YElD[]="Parse.parseExprUnary()";
Tcpos ZcTbl30947[]={
{2903,22},
{1,42},
{3,5},
{7,16},
{8,23},
{9,16},
{10,23},
{11,16},
{12,23},
{13,16},
{16,5},
{17,7},
{18,12},
{20,26},
{21,7},
{22,16},
{24,12},
{28,12},
};
Tc Y_9S[]="Parse.parseFile()";
Tcpos ZcTbl43845[]={
{39,25},
{1,5},
{2,14},
{6,19},
{7,21},
{8,5},
{9,22},
{13,5},
{16,29},
{17,5},
{20,5},
{22,23},
{23,5},
{24,12},
};
Tc Yaoa[]="Parse.parseFor()";
Tcpos ZcTbl91840[]={
{1693,28},
{3,5},
{4,33},
{6,7},
{7,24},
{8,7},
{9,9},
{10,9},
{11,9},
{14,33},
{16,7},
{17,14},
{20,9},
{21,14},
{23,7},
{24,7},
{25,7},
{26,7},
{28,7},
{31,7},
{32,7},
{3,5},
{35,5},
{36,22},
{37,5},
{38,7},
{40,5},
{41,27},
{42,5},
{44,11},
{45,5},
{46,7},
{47,9},
{52,7},
{53,7},
{54,7},
{55,31},
{56,7},
{57,9},
{59,9},
{62,13},
{63,7},
{65,9},
{66,9},
{67,9},
{68,35},
{69,9},
{72,7},
{74,9},
{75,9},
{76,9},
{77,14},
{78,9},
{79,15},
{72,7},
{83,5},
{84,33},
{85,5},
{86,7},
{92,26},
{93,5},
{97,12},
};
Tc YnXxa[]="Parse.parseGenerateError()";
Tcpos ZcTbl29910[]={
{1498,26},
{1,5},
{2,5},
{4,5},
{5,5},
{6,27},
{7,5},
{8,5},
{10,12},
};
Tc YdLG[]="Parse.parseId()";
Tcpos ZcTbl74718[]={
{3323,19},
{2,5},
{6,7},
{8,9},
{9,11},
{11,32},
{12,9},
{13,11},
{14,13},
{12,9},
{18,15},
{20,28},
{21,32},
{22,9},
{23,11},
{25,9},
{26,11},
{27,13},
{25,9},
{32,15},
{34,9},
{35,11},
{36,21},
{39,11},
{40,13},
{34,9},
{44,9},
{46,18},
{47,11},
{48,13},
{51,17},
{55,7},
{56,14},
{60,17},
{61,14},
{65,12},
{66,24},
{67,7},
{69,12},
};
Tc YnCB[]="Parse.parseIf()";
Tcpos ZcTbl95120[]={
{1441,21},
{1,18},
{3,26},
{5,5},
{6,7},
{7,7},
{8,33},
{9,7},
{11,5},
{14,5},
{16,26},
{17,5},
{25,5},
{26,13},
{27,7},
{30,7},
{31,7},
{32,35},
{33,7},
{34,39},
{35,7},
{36,7},
{25,5},
{40,5},
{41,7},
{42,7},
{43,13},
{46,5},
{47,7},
{49,7},
{52,12},
};
Tc Y8h6[]="Parse.parseImports()";
Tcpos ZcTbl68275[]={
{75,22},
{2,5},
{3,13},
{4,7},
{5,9},
{10,20},
{11,7},
{13,9},
{14,15},
{15,9},
{16,15},
{17,9},
{18,11},
{20,18},
{24,7},
{25,13},
{26,7},
{27,9},
{28,9},
{30,33},
{31,34},
{33,9},
{34,17},
{35,31},
{36,11},
{37,24},
{38,13},
{39,15},
{42,13},
{45,13},
{36,11},
{47,20},
{54,9},
{55,11},
{57,21},
{58,15},
{59,17},
{61,24},
{66,15},
{67,21},
{68,15},
{69,21},
{70,15},
{71,17},
{72,30},
{73,17},
{75,25},
{80,35},
{81,15},
{82,26},
{54,9},
{88,9},
{90,9},
{91,40},
{92,11},
{93,11},
{94,11},
{95,11},
{96,11},
{97,13},
{99,11},
{100,13},
{102,11},
{103,11},
{2,5},
{111,5},
{112,15},
};
Tc YqCy[]="Parse.parseInclude()";
Tcpos ZcTbl73233[]={
{851,5},
{1,15},
{3,5},
{5,27},
{6,36},
{7,5},
{9,26},
{10,5},
{14,12},
};
Tc Yi0h[]="Parse.parseInput()";
Tcpos ZcTbl51873[]={
{211,27},
{1,23},
{3,38},
{6,5},
{7,13},
{8,7},
{13,7},
{14,9},
{15,11},
{17,11},
{20,20},
{22,7},
{23,28},
{24,7},
{25,15},
{26,9},
{28,27},
{29,11},
{31,11},
{33,19},
{34,9},
{35,11},
{37,11},
{6,5},
{42,5},
};
Tc Y4EA[]="Parse.parseLambdaExpr()";
Tcpos ZcTbl90589[]={
{3294,5},
{3,29},
{4,5},
{7,5},
{8,28},
{9,5},
{14,5},
{15,22},
{16,5},
{17,7},
{18,7},
{22,32},
{24,12},
};
Tc YPxq[]="Parse.parseList()";
Tcpos ZcTbl11973[]={
{3439,32},
{3,19},
{4,5},
{5,13},
{7,7},
{8,15},
{9,15},
{11,13},
{12,7},
{13,9},
{15,14},
{18,5},
{19,32},
{20,11},
{21,5},
{23,14},
{25,5},
{26,7},
{29,37},
{30,5},
{31,11},
{32,5},
{33,7},
{36,31},
{37,5},
{39,12},
};
Tc Yuvy[]="Parse.parseMembers()";
Tcpos ZcTbl1740[]={
{3875,27},
{3,5},
{4,13},
{5,7},
{14,7},
{18,7},
{20,15},
{21,9},
{22,11},
{25,7},
{26,26},
{28,7},
{31,9},
{33,7},
{34,15},
{35,9},
{37,39},
{39,11},
{40,13},
{42,11},
{43,32},
{44,11},
{45,17},
{46,11},
{47,13},
{48,13},
{51,11},
{52,11},
{53,16},
{54,27},
{57,24},
{58,11},
{59,13},
{61,11},
{62,32},
{63,11},
{64,17},
{65,11},
{66,13},
{67,13},
{70,11},
{73,11},
{74,16},
{77,11},
{82,13},
{85,35},
{86,11},
{87,13},
{90,11},
{95,11},
{96,16},
{98,27},
{100,15},
{102,9},
{104,20},
{105,17},
{107,9},
{108,11},
{110,30},
{111,9},
{112,11},
{114,13},
{116,11},
{120,29},
{121,9},
{123,14},
{124,27},
{126,9},
{127,37},
{128,9},
{129,15},
{130,9},
{131,11},
{132,11},
{135,33},
{136,9},
{137,9},
{138,9},
{140,14},
{144,27},
{146,30},
{147,9},
{148,15},
{149,9},
{150,11},
{151,11},
{156,17},
{157,9},
{159,14},
{167,32},
{168,9},
{171,9},
{174,38},
{175,11},
{184,13},
{190,16},
{191,9},
{192,9},
{193,14},
{3,5},
};
Tcpos ZcTbl1741[]={
{4071,12},
};
Tc Y0Nt[]="Parse.parseMethod()";
Tcpos ZcTbl90734[]={
{884,5},
{4,5},
{5,7},
{8,5},
{9,15},
{14,26},
{15,33},
{16,5},
{18,29},
{19,25},
{21,5},
{22,7},
{25,5},
{26,7},
{29,38},
{31,5},
{33,7},
{36,7},
{38,19},
{41,19},
{42,9},
{44,11},
{45,21},
{47,9},
{48,11},
{51,7},
{53,14},
{54,9},
{55,41},
{57,9},
{58,11},
{59,16},
{60,11},
{62,17},
{63,29},
{64,9},
{66,12},
{67,7},
{70,7},
{71,9},
{74,5},
{77,22},
{78,5},
{79,7},
{81,7},
{84,5},
{86,12},
{88,7},
{89,22},
{91,7},
{92,9},
{91,7},
{96,28},
{97,12},
{100,5},
{107,5},
{110,27},
{112,5},
{113,7},
{116,5},
{118,5},
{122,5},
{123,7},
{126,12},
};
Tc Y1La[]="Parse.parseModule()";
Tcpos ZcTbl93239[]={
{660,41},
{2,5},
{3,15},
{7,5},
{8,22},
{9,5},
{10,7},
{12,25},
{15,25},
{16,5},
{18,29},
{19,5},
{20,5},
{22,28},
{23,5},
{29,5},
{30,7},
{33,26},
{34,5},
{38,12},
};
Tc Ye4R[]="Parse.parseNew()";
Tcpos ZcTbl23043[]={
{3397,22},
{2,5},
{4,7},
{6,12},
{7,7},
{10,7},
{11,35},
{12,13},
{13,7},
{16,15},
{17,38},
{19,15},
{21,7},
{22,9},
{23,11},
{25,11},
{29,31},
{30,7},
{33,7},
{34,12},
{35,7},
{37,12},
};
Tc YFK5[]="Parse.parseNewStatement()";
Tcpos ZcTbl54828[]={
{1944,27},
{2,34},
{3,26},
{4,5},
{8,12},
};
Tc Y3_i[]="Parse.parseObjectInitializer()";
Tcpos ZcTbl1873[]={
{3250,5},
{1,31},
{3,22},
{4,5},
{5,7},
{6,9},
{7,9},
{10,7},
{11,9},
{13,7},
{14,24},
{15,7},
{16,9},
{18,7},
{19,28},
{20,36},
{21,7},
{22,7},
{25,13},
{26,7},
{27,9},
{28,15},
{30,7},
{31,9},
{33,37},
{34,9},
{37,13},
{4,5},
{39,12},
};
Tc YEuD[]="Parse.parseReturnExitThrowDefer()";
Tcpos ZcTbl75821[]={
{1798,26},
{1,5},
{3,12},
{5,12},
{7,12},
{9,12},
{11,21},
{12,5},
{13,5},
{15,5},
{16,21},
{17,7},
{18,13},
{19,9},
{21,13},
{24,11},
{26,5},
{31,7},
{34,5},
{35,7},
{37,5},
{39,12},
};
Tc YRz6[]="Parse.parseStatement()";
Tcpos ZcTbl53510[]={
{1145,5},
{1,7},
{4,5},
{10,7},
{12,9},
{15,7},
{16,16},
{18,42},
{19,16},
{22,16},
{23,7},
{29,5},
{33,39},
{34,7},
{35,38},
{36,9},
{37,11},
{43,18},
{44,9},
{45,9},
{46,34},
{48,9},
{49,21},
{50,11},
{52,9},
{53,18},
{54,9},
{56,11},
{34,7},
{61,16},
{62,7},
{67,5},
{69,7},
{70,9},
{72,7},
{74,38},
{75,12},
{76,7},
{80,24},
{81,7},
{83,9},
{85,24},
{86,7},
{87,9},
{88,11},
{90,14},
{91,9},
{93,14},
{95,9},
{96,9},
{97,15},
{98,9},
{99,11},
{101,14},
{103,11},
{105,9},
{107,14},
{110,9},
{111,11},
{113,14},
{115,9},
{121,20},
{122,40},
{123,21},
{124,11},
{126,29},
{127,11},
{137,13},
{139,45},
{140,13},
{141,15},
{142,17},
{143,26},
{144,17},
{145,17},
{146,23},
{147,22},
{150,15},
{151,17},
{154,15},
{158,24},
{159,15},
{160,40},
{162,15},
{165,15},
{166,24},
{167,15},
{170,23},
{173,23},
{140,13},
{180,28},
{181,13},
{182,15},
{183,20},
{184,43},
{185,15},
{181,13},
{192,9},
{196,5},
{197,7},
};
Tcpos ZcTbl53511[]={
{1343,14},
{2,12},
};
Tc YK_T[]="Parse.parseStringExpr()";
Tcpos ZcTbl71675[]={
{3117,19},
{1,5},
{2,7},
{4,52},
{5,9},
{6,18},
{8,30},
{9,11},
{10,11},
{11,18},
{14,7},
{20,27},
{23,7},
{24,20},
{25,9},
{29,9},
{30,9},
{31,11},
{32,13},
{34,11},
{35,11},
{38,16},
{39,16},
{41,25},
{42,20},
{43,37},
{46,20},
{47,57},
{48,11},
{49,13},
{48,11},
{23,7},
{56,29},
{61,12},
{62,7},
{67,31},
{68,7},
{69,7},
{70,9},
{72,7},
{77,13},
{79,7},
{80,16},
{82,28},
{83,9},
{84,9},
{85,16},
{89,7},
{90,13},
{91,7},
{92,9},
{93,9},
{99,7},
{100,13},
{1,5},
{102,12},
};
Tc YGjZ[]="Parse.parseSwitch()";
Tcpos ZcTbl62251[]={
{1861,5},
{1,31},
{2,26},
{3,5},
{5,5},
{7,33},
{11,5},
{12,13},
{13,7},
{15,9},
{16,11},
{18,9},
{19,35},
{20,9},
{22,14},
{23,9},
{26,9},
{27,25},
{29,9},
{30,11},
{32,9},
{33,11},
{35,20},
{36,9},
{38,14},
{39,9},
{41,9},
{44,11},
{47,9},
{48,11},
{50,9},
{51,31},
{52,9},
{53,11},
{56,15},
{57,9},
{58,17},
{59,11},
{60,11},
{61,13},
{64,14},
{11,5},
{67,5},
{68,7},
{73,10},
{74,5},
{78,12},
};
Tc Ydye[]="Parse.parseTry()";
Tcpos ZcTbl99764[]={
{1521,19},
{2,28},
{3,26},
{4,5},
{8,5},
{11,5},
{14,5},
{15,13},
{16,7},
{19,29},
{20,7},
{21,7},
{22,7},
{25,30},
{26,7},
{27,7},
{29,7},
{30,13},
{31,7},
{32,9},
{34,30},
{35,7},
{36,7},
{37,7},
{38,7},
{42,7},
{14,5},
{46,5},
{48,7},
{51,31},
{53,32},
{54,7},
{58,7},
{59,7},
{61,13},
{65,5},
{66,7},
{69,34},
{70,7},
{71,9},
{74,13},
{77,5},
{78,7},
{80,7},
{81,7},
{84,12},
};
Tc Yima[]="Parse.parseTypeList()";
Tcpos ZcTbl36927[]={
{3691,5},
{1,24},
{2,7},
{4,9},
{5,9},
{6,28},
{8,15},
{9,9},
{10,20},
{13,9},
{14,9},
{17,29},
{21,12},
{23,7},
{25,9},
{26,22},
{30,15},
{31,14},
{34,7},
{35,9},
{38,7},
{40,7},
{41,9},
{42,15},
{43,9},
{44,9},
{47,7},
{48,9},
{49,9},
{50,37},
{53,16},
{0,5},
};
Tc YVtG[]="Parse.parseTypeNameList()";
Tcpos ZcTbl11612[]={
{3750,5},
{1,5},
{3,26},
{5,5},
{6,13},
{7,7},
{10,19},
{11,7},
{12,7},
{13,7},
{15,13},
{16,7},
{19,7},
{5,5},
{22,5},
{23,7},
{25,12},
};
Tc YcXq[]="Parse.parseTypeSpec()";
Tcpos ZcTbl65610[]={
{3646,22},
{1,5},
{4,7},
{5,7},
{6,7},
{7,13},
{11,5},
{15,28},
{16,19},
{17,7},
{18,7},
{21,30},
{22,9},
{23,9},
{25,7},
{26,18},
{28,5},
{29,7},
{30,7},
};
Tc Y_hh[]="Parse.parseWhile()";
Tcpos ZcTbl8750[]={
{1626,5},
{1,31},
{2,26},
{3,5},
{5,5},
{6,27},
{7,5},
{8,7},
{11,26},
{12,5},
{16,12},
};
Tc YkKc[]="Parse.setPrefixFromExpr()";
Tcpos ZcTbl22507[]={
{2136,5},
{1,5},
};
Tc Yxd7[]="Parse.skipLineSep()";
Tcpos ZcTbl94113[]={
{4529,22},
{1,5},
{3,15},
{5,7},
{6,9},
{7,25},
{8,9},
{10,9},
};
Tc Y_TK[]="Parse.skipSep()";
Tcpos ZcTbl99225[]={
{4517,22},
{1,5},
{2,15},
{4,7},
};
Tc Yv_x[]="Parse.tokenAfterSep()";
Tcpos ZcTbl60141[]={
{4548,22},
{1,5},
{2,11},
{3,7},
{5,11},
{7,5},
{8,12},
};
Tc YxDM[]="Parse.twoTokensAfterSep()";
Tcpos ZcTbl90674[]={
{4564,22},
{1,5},
{2,11},
{3,12},
{4,7},
{6,11},
{7,12},
{9,5},
{10,12},
};
Tc YDE6[]="Parse.typeUsed()";
Tcpos ZcTbl57441[]={
{638,5},
{1,34},
{3,7},
{10,9},
{11,51},
{12,9},
};
Tc YxHj[]="Parse.varExprFromDeclStmt()";
Tcpos ZcTbl28158[]={
{1422,27},
{1,22},
{2,33},
{3,5},
{4,5},
{5,5},
{6,12},
};
Tc YROM[]="Parse.visAttrSet()";
Tcpos ZcTbl97223[]={
{2290,5},
{1,7},
};
Tc YYkI[]="SET.Set__t1.Init()";
Tcpos ZcTbl89012[]={
{41,13},
};
Tc YjAA[]="SET.Set__t1.NEW()";
Tcpos ZcTbl21378[]={
{45,5},
};
Tc YFAP[]="SET.Set__t1.has()";
Tcpos ZcTbl25860[]={
{88,11},
{1,20},
};
Tc Yrsv[]="SET.Set__t1.set()";
Tcpos ZcTbl21676[]={
{139,11},
{1,7},
{2,9},
{4,14},
};
Tc Ye39[]="SORTEDLIST.SortedListIterator__t1.Init/1()";
Tcpos ZcTbl92784[]={
{131,18},
{1,18},
{2,18},
};
Tc YO53[]="SORTEDLIST.SortedList__t1.Init()";
Tcpos ZcTbl47746[]={
{47,13},
};
Tc YaWp[]="SORTEDLIST.SortedList__t1.Iterator()";
Tcpos ZcTbl14960[]={
{98,11},
{1,40},
};
Tc Y6us[]="SORTEDLIST.SortedList__t1.NEW()";
Tcpos ZcTbl95800[]={
{51,5},
};
Tc Y7EP[]="SORTEDLIST.SortedList__t1.add()";
Tcpos ZcTbl15363[]={
{183,11},
{2,17},
{3,31},
{4,7},
{5,30},
{7,9},
{8,15},
{10,15},
{12,9},
{13,15},
{16,9},
{17,11},
{18,17},
{21,16},
{23,15},
{4,7},
{26,7},
{27,14},
};
Tc YYXD[]="Summary.NEW()";
Tcpos ZcTbl37195[]={
{823,3},
{1,14},
};
Tc YnmB[]="Summary.Size()";
Tcpos ZcTbl16084[]={
{827,9},
{1,13},
};
Tc YXNg[]="Summary.add()";
Tcpos ZcTbl56758[]={
{832,9},
{1,5},
{2,5},
{3,7},
};
Tc YSww[]="Summary.addHeader()";
Tcpos ZcTbl41247[]={
{848,9},
{1,5},
};
Tc Ygck[]="Summary.addSep()";
Tcpos ZcTbl58278[]={
{839,9},
{3,5},
{5,7},
};
Tc YG8D[]="Summary.toString()";
Tcpos ZcTbl76467[]={
{854,9},
{1,18},
{2,5},
{3,7},
{4,9},
{5,11},
{7,9},
{8,15},
{2,5},
{12,12},
};
Tc Yhfb[]="SummaryEntry.NEW()";
Tcpos ZcTbl79365[]={
{813,3},
{1,15},
{2,15},
};
Tc YQE_[]="TIME.Values.NEW()";
Tcpos ZcTbl5342[]={
{50,5},
{1,7},
};
Tc Y0DO[]="TIME.Values.NEW/2()";
Tcpos ZcTbl32939[]={
{64,5},
{2,4},
{23,13},
};
Tc YHWY[]="TIME.Values.ToString()";
Tcpos ZcTbl34818[]={
{111,11},
{1,27},
{2,7},
{3,7},
{4,7},
{5,7},
{6,7},
{7,7},
{8,7},
{9,7},
{10,7},
{11,7},
{12,7},
{13,16},
};
Tc YLwM[]="TIME.current()";
Tcpos ZcTbl50841[]={
{22,4},
{5,12},
};
Tc YOBf[]="Token.copy()";
Tcpos ZcTbl39899[]={
{43,9},
{1,15},
{2,12},
{3,13},
{4,18},
{5,23},
{6,5},
{7,16},
{9,12},
};
Tc Yxgh[]="Token.error()";
Tcpos ZcTbl40374[]={
{28,9},
{1,5},
};
Tc YNC6[]="Token.errorNotAllowed()";
Tcpos ZcTbl20159[]={
{33,9},
{1,5},
};
Tc Ynxa[]="Token.isSep()";
Tcpos ZcTbl47436[]={
{38,9},
{1,56},
};
Tc YYG0[]="Token.zcPos()";
Tcpos ZcTbl52047[]={
{22,9},
{1,18},
};
Tc YwHH[]="TokenInput.NEW()";
Tcpos ZcTbl63886[]={
{27,3},
{1,12},
{2,17},
{3,21},
};
Tc YfrQ[]="TokenInput.emptyStack()";
Tcpos ZcTbl39789[]={
{109,9},
{1,5},
{2,29},
{3,7},
{4,9},
{3,7},
{1,5},
};
Tc YHjE[]="TokenInput.error()";
Tcpos ZcTbl54950[]={
{119,9},
{1,5},
};
Tc Yp4z[]="TokenInput.get()";
Tcpos ZcTbl39372[]={
{37,9},
{1,19},
};
Tc YEF1[]="TokenInput.getToken()";
Tcpos ZcTbl32257[]={
{85,9},
{1,5},
{2,26},
{4,22},
};
Tc YcBB[]="TokenInput.getWord()";
Tcpos ZcTbl67276[]={
{56,9},
{1,26},
{2,5},
{3,16},
{4,7},
{5,9},
{8,7},
{2,5},
{10,15},
};
Tc YozJ[]="TokenInput.peek()";
Tcpos ZcTbl32309[]={
{47,9},
{1,14},
{2,5},
{3,12},
};
Tc YWNo[]="TokenInput.peekToken()";
Tcpos ZcTbl3006[]={
{98,9},
{1,5},
{2,15},
{4,29},
{5,5},
{6,12},
};
Tc YLKU[]="TokenInput.push()";
Tcpos ZcTbl92336[]={
{42,9},
{1,5},
};
Tc YvtJ[]="TokenInput.pushToken()";
Tcpos ZcTbl24917[]={
{93,9},
{1,5},
};
Tc Ykc9[]="TokenInput.skipWhite()";
Tcpos ZcTbl59236[]={
{70,9},
{1,14},
{2,5},
{3,7},
{4,14},
{6,5},
{7,9},
{6,5},
{9,5},
{10,12},
};
Tc YcP2[]="Tokenizer";
Tcpos ZcTbl20555[]={
{27,24},
{61,24},
{165,20},
{438,20},
};
Tc Yuv2[]="Tokenizer.Init()";
Tcpos ZcTbl34882[]={
{571,11},
{1,5},
{2,7},
{1,5},
{4,5},
{5,7},
{4,5},
{8,12},
};
Tc YPve[]="Tokenizer.addNode()";
Tcpos ZcTbl34905[]={
{551,15},
{1,5},
{2,7},
{3,20},
{5,7},
{6,23},
{8,9},
{1,5},
{10,5},
{11,7},
{13,13},
{14,12},
{15,17},
};
Tc YZvS[]="Tokenizer.controlChar()";
Tcpos ZcTbl90889[]={
{372,5},
{2,9},
{4,9},
{6,9},
{8,9},
{10,9},
{12,9},
{14,9},
{16,9},
{18,9},
{20,9},
{26,19},
{27,9},
{28,23},
{29,11},
{30,13},
{31,13},
{32,13},
{35,13},
{27,9},
{37,9},
{40,9},
{43,9},
{46,9},
{48,9},
{49,9},
{50,9},
};
Tc YX0R[]="Tokenizer.deeper()";
Tcpos ZcTbl60003[]={
{611,16},
{1,5},
{2,19},
{3,7},
{4,9},
{5,11},
{6,20},
{9,9},
{11,20},
{12,21},
{13,18},
{17,5},
{18,12},
};
Tc Ysro[]="Tokenizer.get()";
Tcpos ZcTbl6038[]={
{198,18},
{3,16},
{4,5},
{5,5},
{6,14},
{9,5},
{10,5},
{11,7},
{12,9},
{14,14},
{17,16},
{18,5},
{20,7},
{21,7},
{22,16},
{24,7},
{27,20},
{28,11},
{29,15},
{30,13},
{33,13},
{34,15},
{35,15},
{38,13},
{39,17},
{40,15},
{41,17},
{44,15},
{46,26},
{49,15},
{51,15},
{28,11},
{57,13},
{58,11},
{59,15},
{60,13},
{63,24},
{64,15},
{65,29},
{66,19},
{67,17},
{68,21},
{69,19},
{70,23},
{71,21},
{74,21},
{75,23},
{77,19},
{78,21},
{80,17},
{81,19},
{84,17},
{64,15},
{88,15},
{89,17},
{92,20},
{93,11},
{94,13},
{96,13},
{97,15},
{98,15},
{99,17},
{101,13},
{103,13},
{104,11},
{105,13},
{110,11},
{111,13},
{114,13},
{115,22},
{117,13},
{120,15},
{121,29},
{122,17},
{123,17},
{127,15},
{128,17},
{117,13},
{130,13},
{133,38},
{134,21},
{136,27},
{137,27},
{138,35},
{139,11},
{140,15},
{141,13},
{142,24},
{144,13},
{146,24},
{148,13},
{149,32},
{139,11},
{152,11},
{153,13},
{155,11},
{156,13},
{159,20},
{163,5},
{164,17},
};
Tcpos ZcTbl6039[]={
{364,5},
{2,12},
};
Tc YiIo[]="Tokenizer.getHex()";
Tcpos ZcTbl44787[]={
{428,5},
{1,18},
{2,7},
{3,9},
{4,9},
{5,9},
{6,16},
{8,11},
{0,5},
{10,12},
};
Tc YQws[]="Tokenizer.getNew()";
Tcpos ZcTbl96992[]={
{583,17},
{1,5},
{3,16},
{4,14},
{6,5},
{7,22},
{8,7},
{9,9},
{10,11},
{11,20},
{14,9},
{16,20},
{17,21},
{18,18},
{23,5},
{24,12},
};
Tc YXf2[]="Tokenizer.getRawString()";
Tcpos ZcTbl90891[]={
{443,5},
{1,18},
{2,7},
{3,11},
{4,9},
{6,11},
{11,7},
{12,9},
{13,9},
{16,7},
{0,5},
};
Tc YRo0[]="Tokenizer.handleWhite()";
Tcpos ZcTbl38927[]={
{474,16},
{1,5},
{3,13},
{5,5},
{6,7},
{7,7},
{8,22},
{9,16},
{11,9},
{12,31},
{14,24},
{15,22},
{16,9},
{17,13},
{18,11},
{19,9},
{16,9},
{20,16},
{22,9},
{23,9},
{24,31},
{26,24},
{27,9},
{28,13},
{29,11},
{30,13},
{31,13},
{32,15},
{35,11},
{36,9},
{27,9},
{37,9},
{38,11},
{41,9},
{5,5},
{43,5},
{45,5},
{46,7},
{48,18},
{51,18},
{53,16},
{55,16},
{57,16},
{58,7},
{60,15},
{61,5},
};
Tc YLig[]="Tokenizer.isIdChar()";
Tcpos ZcTbl43917[]={
{21,9},
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
Tc YQcV[]="Z.Pos.advance()";
Tcpos ZcTbl86775[]={
{65,11},
{2,7},
{3,19},
{4,9},
{7,14},
{8,9},
{9,13},
{2,7},
{11,12},
};
Tc YPRm[]="Z.Pos.copy()";
Tcpos ZcTbl16020[]={
{42,11},
{1,15},
{2,14},
{3,13},
{4,14},
{5,14},
};
Tc YzF7[]="Z.Pos.nextLine()";
Tcpos ZcTbl46868[]={
{59,11},
{1,12},
{2,12},
};
Tc YRsu[]="Zui.AliasType.NEW()";
Tcpos ZcTbl97527[]={
{5097,5},
};
Tc YPFc[]="Zui.AliasType.copy()";
Tcpos ZcTbl94168[]={
{5223,11},
{1,23},
{2,7},
{3,20},
{5,18},
{6,7},
{7,19},
{9,14},
};
Tc Yu8c[]="Zui.AliasType.getFor()";
Tcpos ZcTbl65952[]={
{5153,9},
};
Tc Yp1W[]="Zui.AliasType.getFrom()";
Tcpos ZcTbl61629[]={
{5113,9},
};
Tc YCkn[]="Zui.Assignment.NEW()";
Tcpos ZcTbl4968[]={
{6644,5},
};
Tc YdRc[]="Zui.Assignment.copy()";
Tcpos ZcTbl23085[]={
{6783,11},
{1,24},
{2,18},
{3,7},
{4,19},
{6,7},
{7,19},
{9,14},
};
Tc YK9t[]="Zui.Attributes.NEW()";
Tcpos ZcTbl75910[]={
{2893,5},
};
Tc Y9ig[]="Zui.Attributes.copy()";
Tcpos ZcTbl98019[]={
{3253,11},
{1,24},
{2,22},
{3,23},
{4,19},
{5,20},
{6,21},
{7,23},
{8,23},
{9,25},
{10,27},
{11,24},
{12,28},
{13,29},
{14,23},
{15,24},
{16,14},
};
Tc YDLv[]="Zui.Attributes.getItemsVisibility()";
Tcpos ZcTbl64594[]={
{3103,9},
};
Tc Y4Wm[]="Zui.Attributes.getVisibility()";
Tcpos ZcTbl4008[]={
{3067,9},
};
Tc YsYS[]="Zui.BitsType.NEW()";
Tcpos ZcTbl67675[]={
{3865,5},
};
Tc Yxe4[]="Zui.BitsType.copy()";
Tcpos ZcTbl20940[]={
{3947,11},
{1,22},
{2,7},
{3,9},
{4,24},
{5,11},
{6,13},
{5,11},
{10,22},
{12,14},
};
Tc Y_VA[]="Zui.CBlock.NEW()";
Tcpos ZcTbl74861[]={
{8140,5},
};
Tc Yrwj[]="Zui.CBlock.copy()";
Tcpos ZcTbl46630[]={
{8345,11},
{1,20},
{2,7},
{3,19},
{5,7},
{6,9},
{7,22},
{8,11},
{9,13},
{8,11},
{13,20},
{15,18},
{16,7},
{17,20},
{19,21},
{20,14},
};
Tc YiO6[]="Zui.Catch.NEW()";
Tcpos ZcTbl8602[]={
{7848,5},
};
Tc Y8xC[]="Zui.Catch.copy()";
Tcpos ZcTbl9319[]={
{8043,11},
{1,19},
{2,7},
{3,19},
{5,7},
{6,9},
{7,22},
{8,11},
{9,13},
{8,11},
{13,20},
{15,7},
{16,20},
{18,7},
{19,20},
{21,14},
};
Tc You8[]="Zui.ClassType.NEW()";
Tcpos ZcTbl17451[]={
{3355,5},
};
Tc Ye5I[]="Zui.ClassType.copy()";
Tcpos ZcTbl67708[]={
{3740,11},
{1,23},
{2,18},
{3,25},
{4,21},
{5,7},
{6,9},
{7,34},
{8,11},
{9,13},
{8,11},
{13,32},
{15,7},
{16,23},
{18,7},
{19,9},
{20,28},
{21,11},
{22,13},
{21,11},
{26,26},
{28,7},
{29,9},
{30,24},
{31,11},
{32,13},
{31,11},
{36,22},
{38,7},
{39,22},
{41,7},
{42,26},
{44,14},
};
Tc Yh7E[]="Zui.ClassType.getExtends()";
Tcpos ZcTbl4256[]={
{3464,9},
};
Tc YbUI[]="Zui.ClassType.getShared()";
Tcpos ZcTbl69092[]={
{3564,9},
};
Tc Y3SI[]="Zui.ClassType.newShared()";
Tcpos ZcTbl630[]={
{3558,11},
{1,17},
{2,15},
};
Tc YR9H[]="Zui.CodeBlock.NEW()";
Tcpos ZcTbl13081[]={
{5309,5},
};
Tc YwJM[]="Zui.CodeBlock.addStatement()";
Tcpos ZcTbl465[]={
{5359,11},
{1,7},
{2,22},
{4,7},
{5,14},
};
Tc Yw57[]="Zui.CodeBlock.copy()";
Tcpos ZcTbl16738[]={
{5471,11},
{1,23},
{2,7},
{3,19},
{5,7},
{6,22},
{8,7},
{9,9},
{10,27},
{11,11},
{12,13},
{11,11},
{16,25},
{18,14},
};
Tc YBwX[]="Zui.Condition.NEW()";
Tcpos ZcTbl6734[]={
{6867,5},
};
Tc Ye66[]="Zui.Condition.addElseif()";
Tcpos ZcTbl26437[]={
{6917,11},
{1,7},
{2,19},
{4,7},
{5,14},
};
Tc YnaG[]="Zui.Condition.addNewElseif()";
Tcpos ZcTbl51475[]={
{6924,11},
{1,21},
{2,7},
{3,14},
};
Tc Yc3M[]="Zui.Condition.copy()";
Tcpos ZcTbl30443[]={
{7062,11},
{1,23},
{2,7},
{3,20},
{5,7},
{6,21},
{8,7},
{9,9},
{10,24},
{11,11},
{12,13},
{11,11},
{16,22},
{18,7},
{19,20},
{21,14},
};
Tc YK7W[]="Zui.Condition.getBlock()";
Tcpos ZcTbl73887[]={
{6905,9},
};
Tc Y53b[]="Zui.Condition.getElse()";
Tcpos ZcTbl86485[]={
{6966,9},
};
Tc YrDo[]="Zui.Condition.newBlock()";
Tcpos ZcTbl32297[]={
{6899,11},
{1,16},
{2,15},
};
Tc YKbA[]="Zui.ContainerType.NEW()";
Tcpos ZcTbl31888[]={
{4879,5},
};
Tc Yx23[]="Zui.ContainerType.copy()";
Tcpos ZcTbl48469[]={
{5008,11},
{1,27},
{2,7},
{3,23},
{5,7},
{6,9},
{7,26},
{8,11},
{9,13},
{8,11},
{13,24},
{15,14},
};
Tc YKr8[]="Zui.Contents.NEW()";
Tcpos ZcTbl28605[]={
{225,5},
};
Tc Yvot[]="Zui.Contents.addImport()";
Tcpos ZcTbl85111[]={
{231,11},
{1,7},
{2,19},
{4,7},
{5,14},
};
Tc YNFL[]="Zui.Contents.addNewImport()";
Tcpos ZcTbl82665[]={
{238,11},
{1,18},
{2,7},
{3,14},
};
Tc YMsF[]="Zui.Declaration.NEW()";
Tcpos ZcTbl77717[]={
{1376,5},
};
Tc Y7IM[]="Zui.Declaration.copy()";
Tcpos ZcTbl9422[]={
{1810,11},
{1,25},
{2,18},
{3,7},
{4,23},
{6,20},
{7,21},
{8,20},
{9,7},
{10,19},
{12,7},
{13,21},
{14,19},
{16,19},
{17,7},
{18,20},
{20,7},
{21,20},
{23,19},
{24,23},
{25,27},
{26,26},
{27,32},
{28,14},
};
Tc Y_fU[]="Zui.Declaration.getType()";
Tcpos ZcTbl37709[]={
{1547,9},
};
Tc YvGg[]="Zui.Declaration.newType()";
Tcpos ZcTbl55119[]={
{1541,11},
{1,15},
{2,15},
};
Tc YEts[]="Zui.EnumType.NEW()";
Tcpos ZcTbl74774[]={
{4032,5},
};
Tc YqdL[]="Zui.EnumType.addItem()";
Tcpos ZcTbl69864[]={
{4038,11},
{1,7},
{2,17},
{4,7},
{5,14},
};
Tc YY2f[]="Zui.EnumType.addNewItem()";
Tcpos ZcTbl33350[]={
{4045,11},
{1,23},
{2,7},
{3,14},
};
Tc YjQE[]="Zui.EnumType.copy()";
Tcpos ZcTbl67123[]={
{4167,11},
{1,22},
{2,7},
{3,9},
{4,22},
{5,11},
{6,13},
{5,11},
{10,20},
{12,7},
{13,9},
{14,24},
{15,11},
{16,13},
{15,11},
{20,22},
{22,14},
};
Tc YTM4[]="Zui.ExprPair.NEW()";
Tcpos ZcTbl87834[]={
{10270,5},
};
Tc YEEk[]="Zui.ExprPair.copy()";
Tcpos ZcTbl14983[]={
{10365,11},
{1,22},
{2,7},
{3,19},
{5,7},
{6,21},
{8,14},
};
Tc YcXM[]="Zui.Expression.NEW()";
Tcpos ZcTbl93663[]={
{9010,5},
};
Tc YP1b[]="Zui.Expression.addDictItem()";
Tcpos ZcTbl23561[]={
{9198,11},
{1,7},
{2,21},
{4,7},
{5,14},
};
Tc YGFh[]="Zui.Expression.addInitItem()";
Tcpos ZcTbl96277[]={
{9237,11},
{1,7},
{2,21},
{4,7},
{5,14},
};
Tc Y1Xb[]="Zui.Expression.addNewDictItem()";
Tcpos ZcTbl8515[]={
{9205,11},
{1,20},
{2,7},
{3,14},
};
Tc YqwF[]="Zui.Expression.addNewInitItem()";
Tcpos ZcTbl81231[]={
{9244,11},
{1,20},
{2,7},
{3,14},
};
Tc Y_ym[]="Zui.Expression.copy()";
Tcpos ZcTbl10176[]={
{9819,11},
{1,24},
{2,18},
{3,7},
{4,19},
{6,7},
{7,18},
{9,7},
{10,24},
{11,22},
{13,7},
{14,25},
{15,23},
{17,7},
{18,27},
{19,25},
{21,25},
{22,7},
{23,9},
{24,26},
{25,11},
{26,13},
{25,11},
{30,24},
{32,7},
{33,9},
{34,26},
{35,11},
{36,13},
{35,11},
{40,24},
{42,7},
{43,9},
{44,26},
{45,11},
{46,13},
{45,11},
{50,24},
{52,25},
{53,7},
{54,26},
{56,7},
{57,22},
{59,7},
{60,20},
{62,7},
{63,24},
{65,7},
{66,9},
{67,26},
{68,11},
{69,13},
{68,11},
{73,24},
{75,7},
{76,20},
{78,7},
{79,20},
{81,7},
{82,21},
{84,20},
{85,7},
{86,20},
{88,14},
};
Tc YOPG[]="Zui.Expression.getFnumber()";
Tcpos ZcTbl32204[]={
{9107,9},
};
Tc YCPu[]="Zui.Expression.getId()";
Tcpos ZcTbl69190[]={
{9066,9},
};
Tc YFBD[]="Zui.Expression.getLeft()";
Tcpos ZcTbl36880[]={
{9453,9},
};
Tc Y19C[]="Zui.Expression.getMethodCall()";
Tcpos ZcTbl68318[]={
{9304,9},
};
Tc YPvG[]="Zui.Expression.getPos()";
Tcpos ZcTbl63883[]={
{9044,9},
};
Tc Y3l3a[]="Zui.Expression.getRight()";
Tcpos ZcTbl8671[]={
{9475,9},
};
Tc Y3uM[]="Zui.Expression.getType()";
Tcpos ZcTbl98903[]={
{9022,9},
};
Tc YjaA[]="Zui.Expression.newId()";
Tcpos ZcTbl4600[]={
{9060,11},
{1,13},
{2,15},
};
Tc Ya1_[]="Zui.Expression.newLeft()";
Tcpos ZcTbl54290[]={
{9447,11},
{1,15},
{2,15},
};
Tc YZrH[]="Zui.Expression.newRight()";
Tcpos ZcTbl15465[]={
{9469,11},
{1,16},
{2,15},
};
Tc Y5tU[]="Zui.Expression.newTypecast()";
Tcpos ZcTbl53988[]={
{9364,11},
{1,19},
{2,15},
};
Tc YEzw[]="Zui.ForStatement.NEW()";
Tcpos ZcTbl56903[]={
{7161,5},
};
Tc YUbH[]="Zui.ForStatement.addIter()";
Tcpos ZcTbl28454[]={
{7206,11},
{1,7},
{2,17},
{4,7},
{5,14},
};
Tc YrT8[]="Zui.ForStatement.addLoopVar()";
Tcpos ZcTbl70521[]={
{7167,11},
{1,7},
{2,20},
{4,7},
{5,14},
};
Tc YNXg[]="Zui.ForStatement.copy()";
Tcpos ZcTbl71848[]={
{7442,11},
{1,26},
{2,7},
{3,9},
{4,25},
{5,11},
{6,13},
{5,11},
{10,23},
{12,7},
{13,9},
{14,22},
{15,11},
{16,13},
{15,11},
{20,20},
{22,7},
{23,18},
{25,7},
{26,21},
{28,7},
{29,20},
{31,7},
{32,20},
{34,14},
};
Tc YHwg[]="Zui.ForStatement.newBody()";
Tcpos ZcTbl86581[]={
{7315,11},
{1,15},
{2,15},
};
Tc YSDH[]="Zui.Id.NEW()";
Tcpos ZcTbl80968[]={
{10000,5},
};
Tc Y8q6[]="Zui.Id.copy()";
Tcpos ZcTbl57165[]={
{10181,11},
{1,16},
{2,7},
{3,19},
{5,18},
{6,20},
{7,21},
{8,7},
{9,21},
{10,19},
{12,14},
};
Tc Y5pP[]="Zui.Import.NEW()";
Tcpos ZcTbl2646[]={
{971,5},
};
Tc Y7J_[]="Zui.Include.NEW()";
Tcpos ZcTbl64067[]={
{6477,5},
};
Tc YfjP[]="Zui.Include.copy()";
Tcpos ZcTbl62900[]={
{6559,11},
{1,21},
{2,7},
{3,9},
{4,27},
{5,11},
{6,13},
{5,11},
{10,25},
{12,14},
};
Tc Ym28[]="Zui.MethodCall.NEW()";
Tcpos ZcTbl17536[]={
{10622,5},
};
Tc Yglh[]="Zui.MethodCall.copy()";
Tcpos ZcTbl50341[]={
{10850,11},
{1,24},
{2,7},
{3,22},
{5,7},
{6,19},
{8,7},
{9,20},
{11,7},
{12,9},
{13,26},
{14,11},
{15,13},
{14,11},
{19,24},
{21,7},
{22,22},
{24,14},
};
Tc Yud3[]="Zui.MethodType.NEW()";
Tcpos ZcTbl29058[]={
{4432,5},
};
Tc YeqT[]="Zui.MethodType.addArgument()";
Tcpos ZcTbl45452[]={
{4516,11},
{1,7},
{2,21},
{4,7},
{5,14},
};
Tc Yz10[]="Zui.MethodType.addNewArgument()";
Tcpos ZcTbl794[]={
{4523,11},
{1,23},
{2,7},
{3,14},
};
Tc Yi5C[]="Zui.MethodType.addNewReturnType()";
Tcpos ZcTbl11693[]={
{4445,11},
{1,16},
{2,7},
{3,14},
};
Tc Y36B[]="Zui.MethodType.addNewUse()";
Tcpos ZcTbl12252[]={
{4562,11},
{1,23},
{2,7},
{3,14},
};
Tc YlHH[]="Zui.MethodType.addReturnType()";
Tcpos ZcTbl16975[]={
{4438,11},
{1,7},
{2,23},
{4,7},
{5,14},
};
Tc Y6a9[]="Zui.MethodType.addUse()";
Tcpos ZcTbl1798[]={
{4555,11},
{1,7},
{2,16},
{4,7},
{5,14},
};
Tc YWpG[]="Zui.MethodType.copy()";
Tcpos ZcTbl10831[]={
{4753,11},
{1,24},
{2,7},
{3,9},
{4,28},
{5,11},
{6,13},
{5,11},
{10,26},
{12,7},
{13,9},
{14,34},
{15,11},
{16,13},
{15,11},
{20,32},
{22,7},
{23,9},
{24,26},
{25,11},
{26,13},
{25,11},
{30,24},
{32,7},
{33,9},
{34,21},
{35,11},
{36,13},
{35,11},
{40,19},
{42,7},
{43,20},
{45,7},
{46,20},
{48,14},
};
Tc YjOa[]="Zui.ModuleType.NEW()";
Tcpos ZcTbl61323[]={
{4263,5},
};
Tc YycE[]="Zui.ModuleType.copy()";
Tcpos ZcTbl63132[]={
{4345,11},
{1,24},
{2,7},
{3,9},
{4,27},
{5,11},
{6,13},
{5,11},
{10,25},
{12,14},
};
Tc YMc3[]="Zui.NameExpr.NEW()";
Tcpos ZcTbl39983[]={
{10447,5},
};
Tc YMMn[]="Zui.NameExpr.copy()";
Tcpos ZcTbl88688[]={
{10540,11},
{1,22},
{2,18},
{3,7},
{4,21},
{6,14},
};
Tc YcEv[]="Zui.Position.NEW()";
Tcpos ZcTbl6724[]={
{10951,5},
};
Tc YDiN[]="Zui.Position.copy()";
Tcpos ZcTbl39225[]={
{11058,11},
{1,22},
{2,7},
{3,22},
{4,20},
{6,7},
{7,24},
{8,22},
{10,22},
{11,14},
};
Tc YLo9[]="Zui.Statement.NEW()";
Tcpos ZcTbl77656[]={
{5682,5},
};
Tc YsdE[]="Zui.Statement.addCblock()";
Tcpos ZcTbl79729[]={
{5965,11},
{1,7},
{2,19},
{4,7},
{5,14},
};
Tc YNAG[]="Zui.Statement.addStatement()";
Tcpos ZcTbl19756[]={
{6044,11},
{1,7},
{2,22},
{4,7},
{5,14},
};
Tc Yn3i[]="Zui.Statement.copy()";
Tcpos ZcTbl35389[]={
{6322,11},
{1,23},
{2,7},
{3,19},
{5,18},
{6,7},
{7,27},
{9,7},
{10,23},
{12,7},
{13,22},
{15,7},
{16,26},
{18,7},
{19,25},
{21,7},
{22,19},
{24,7},
{25,19},
{27,7},
{28,21},
{30,7},
{31,20},
{33,7},
{34,9},
{35,27},
{36,11},
{37,13},
{36,11},
{41,25},
{43,7},
{44,9},
{45,24},
{46,11},
{47,13},
{46,11},
{51,22},
{53,7},
{54,26},
{56,21},
{57,7},
{58,9},
{59,27},
{60,11},
{61,13},
{60,11},
{65,25},
{67,14},
};
Tc Y8pM[]="Zui.Statement.getBlock()";
Tcpos ZcTbl5105[]={
{5892,9},
};
Tc YS5g[]="Zui.Statement.getCondition()";
Tcpos ZcTbl68673[]={
{5826,9},
};
Tc YWul[]="Zui.Statement.getDeclaration()";
Tcpos ZcTbl60480[]={
{5738,9},
};
Tc YRP7[]="Zui.Statement.getInclude()";
Tcpos ZcTbl85022[]={
{5760,9},
};
Tc Y8Wx[]="Zui.Statement.getPos()";
Tcpos ZcTbl15776[]={
{5698,9},
};
Tc YrcZ[]="Zui.Statement.getType()";
Tcpos ZcTbl27168[]={
{5716,9},
};
Tc Y9FU[]="Zui.Statement.newCondition()";
Tcpos ZcTbl11851[]={
{5820,11},
{1,20},
{2,15},
};
Tc Y27Q[]="Zui.Statement.newDeclaration()";
Tcpos ZcTbl94362[]={
{5732,11},
{1,22},
{2,15},
};
Tc Y4Da[]="Zui.SymbolRef.NEW()";
Tcpos ZcTbl38674[]={
{745,5},
};
Tc YvRq[]="Zui.SymbolRef.copy()";
Tcpos ZcTbl30719[]={
{878,11},
{1,23},
{2,7},
{3,21},
{4,19},
{6,7},
{7,30},
{8,28},
{10,7},
{11,27},
{12,25},
{14,18},
{15,14},
};
Tc YnbC[]="Zui.TryStatement.NEW()";
Tcpos ZcTbl42315[]={
{7556,5},
};
Tc Y4A9[]="Zui.TryStatement.addCatch()";
Tcpos ZcTbl57213[]={
{7584,11},
{1,7},
{2,18},
{4,7},
{5,14},
};
Tc YX0k[]="Zui.TryStatement.addNewCatch()";
Tcpos ZcTbl34415[]={
{7591,11},
{1,17},
{2,7},
{3,14},
};
Tc YNhz[]="Zui.TryStatement.copy()";
Tcpos ZcTbl4732[]={
{7751,11},
{1,26},
{2,7},
{3,20},
{5,7},
{6,9},
{7,23},
{8,11},
{9,13},
{8,11},
{13,21},
{15,7},
{16,20},
{18,7},
{19,23},
{21,14},
};
Tc YR7H[]="Zui.TryStatement.getBody()";
Tcpos ZcTbl94199[]={
{7572,9},
};
Tc YOFz[]="Zui.Type.NEW()";
Tcpos ZcTbl3993[]={
{2073,5},
};
Tc YM3X[]="Zui.Type.copy()";
Tcpos ZcTbl2082[]={
{2720,11},
{1,18},
{2,18},
{3,18},
{4,7},
{5,19},
{7,7},
{8,20},
{10,7},
{11,24},
{13,7},
{14,26},
{15,24},
{17,7},
{18,22},
{19,20},
{21,7},
{22,25},
{24,7},
{25,24},
{27,7},
{28,24},
{30,7},
{31,26},
{33,7},
{34,26},
{36,7},
{37,25},
{39,7},
{40,21},
{42,7},
{43,19},
{45,7},
{46,20},
{48,22},
{49,7},
{50,27},
{52,22},
{53,14},
};
Tc YH3x[]="Zui.Type.getAlias()";
Tcpos ZcTbl92453[]={
{2365,9},
};
Tc Ye3c[]="Zui.Type.getAttr()";
Tcpos ZcTbl4902[]={
{2147,9},
};
Tc YKUf[]="Zui.Type.getBitsDecl()";
Tcpos ZcTbl87653[]={
{2255,9},
};
Tc Ygsn[]="Zui.Type.getClassDecl()";
Tcpos ZcTbl3141[]={
{2233,9},
};
Tc YOQN[]="Zui.Type.getEnumDecl()";
Tcpos ZcTbl81456[]={
{2277,9},
};
Tc Youh[]="Zui.Type.getMethodDecl()";
Tcpos ZcTbl6172[]={
{2321,9},
};
Tc YZ3U[]="Zui.Type.getModuleDecl()";
Tcpos ZcTbl65333[]={
{2299,9},
};
Tc YBIb[]="Zui.Type.getName()";
Tcpos ZcTbl19076[]={
{2409,9},
};
Tc YiSI[]="Zui.Type.getRef()";
Tcpos ZcTbl51544[]={
{2387,9},
};
Tc YEZU[]="Zui.Type.getType()";
Tcpos ZcTbl62609[]={
{2085,9},
};
Tc YaaO[]="ZuiFile.copyPosition()";
Tcpos ZcTbl78335[]={
{130,7},
{1,7},
{2,7},
};
Tc Ya7y[]="ZuiFile.createPosition()";
Tcpos ZcTbl6228[]={
{118,7},
{1,16},
{3,27},
{4,7},
{5,7},
{6,7},
{7,14},
};
Tc Y3Q7[]="builtinTranslate()";
Tcpos ZcTbl28962[]={
{305,21},
};
Tc YpEz[]="findIncludes()";
Tcpos ZcTbl45337[]={
{1321,27},
{2,3},
{3,5},
{5,36},
{6,9},
{7,11},
{8,27},
{10,26},
{11,13},
{13,20},
{18,13},
{19,13},
{20,20},
{21,15},
{6,9},
{29,35},
{30,9},
{31,11},
{35,9},
{36,11},
{37,13},
{35,9},
{42,9},
{43,11},
{2,3},
{48,10},
};
Tc YTrD[]="getArgumentNames()";
Tcpos ZcTbl91748[]={
{2150,16},
{1,18},
{2,3},
{3,9},
{4,9},
{5,11},
{2,3},
{7,10},
};
Tc YHMc[]="getArgumentTypes()";
Tcpos ZcTbl88581[]={
{2164,16},
{1,18},
{2,3},
{3,9},
{4,9},
{5,11},
{2,3},
{7,10},
};
Tc YJas[]="getArguments()";
Tcpos ZcTbl4115[]={
{2178,16},
{1,18},
{2,3},
{3,9},
{4,9},
{5,5},
{6,11},
{8,9},
{9,11},
{2,3},
{11,10},
};
Tc Y10A[]="getDotName()";
Tcpos ZcTbl10085[]={
{2392,3},
{2,27},
{5,41},
{8,19},
{11,10},
};
Tc Yn8ia[]="getFooter()";
Tcpos ZcTbl27172[]={
{1672,20},
{1,19},
{2,3},
{3,11},
{4,12},
{2,3},
{7,16},
{8,3},
{9,5},
{10,11},
{11,11},
{12,15},
{13,7},
{14,13},
{15,9},
{13,7},
{17,11},
{9,5},
{20,10},
};
Tc YNiY[]="getHref()";
Tcpos ZcTbl99790[]={
{1903,3},
{1,11},
{3,11},
{4,5},
{5,13},
{8,28},
{9,3},
{10,9},
{12,57},
};
Tc Y4Vy[]="getSection()";
Tcpos ZcTbl9530[]={
{1793,3},
{1,12},
{3,53},
};
Tc Y1Vl[]="getTextSection()";
Tcpos ZcTbl21019[]={
{1802,3},
{1,12},
{3,32},
};
Tc YZCk[]="getTypeFromExpr()";
Tcpos ZcTbl65794[]={
{2014,16},
{1,3},
{2,32},
{3,5},
{5,11},
{6,7},
{11,16},
{14,11},
{16,11},
{18,25},
{19,9},
{20,25},
{21,9},
{22,9},
{23,9},
{24,25},
{25,9},
{26,9},
{27,9},
{28,9},
{30,25},
{34,5},
{35,16},
{36,14},
{37,14},
{39,5},
{40,11},
{44,9},
{45,5},
{46,11},
{49,9},
{52,5},
{53,9},
{55,10},
};
Tc Yp0n[]="getTypeList()";
Tcpos ZcTbl14295[]={
{1958,16},
{1,18},
{2,3},
{3,16},
{4,5},
{5,7},
{6,13},
{8,15},
{11,19},
{12,9},
{13,11},
{2,3},
{15,10},
};
Tc YQXy[]="getTypeList/1()";
Tcpos ZcTbl20323[]={
{1979,16},
{1,18},
{2,3},
{3,9},
{4,11},
{2,3},
{6,10},
};
Tc Y8q1[]="getTypeName()";
Tcpos ZcTbl97268[]={
{1948,14},
{1,3},
{2,31},
{4,10},
};
Tc YNIo[]="getTypeRecurse()";
Tcpos ZcTbl44652[]={
{1991,3},
{1,12},
{4,16},
{5,3},
{6,9},
{8,25},
{9,9},
{12,5},
{13,9},
{16,10},
};
Tc Y3cb[]="getTypeSpecString()";
Tcpos ZcTbl66957[]={
{2075,16},
{1,7},
{2,7},
{3,10},
};
Tc YjHe[]="getTypeSpecString/1()";
Tcpos ZcTbl49897[]={
{2084,16},
{1,7},
{2,7},
{3,10},
};
Tc YUc5[]="getVisibility()";
Tcpos ZcTbl4937[]={
{992,3},
{1,9},
{3,3},
{4,5},
{5,11},
{7,19},
{8,11},
{10,11},
{13,10},
};
Tc Y1PJ[]="handleAlias()";
Tcpos ZcTbl12459[]={
{767,57},
{2,21},
{3,3},
{4,5},
{6,7},
{7,7},
{11,22},
{12,5},
{13,16},
{15,5},
{16,7},
{18,9},
{19,9},
{23,7},
{27,7},
{28,7},
{33,15},
{34,3},
{35,3},
{38,3},
};
Tc YsXT[]="handleClass()";
Tcpos ZcTbl75871[]={
{590,31},
{1,22},
{2,3},
{5,5},
{6,7},
{8,10},
{11,20},
{14,3},
{16,7},
{17,14},
{18,39},
{19,14},
{20,39},
{21,14},
{23,14},
{26,12},
{28,12},
{30,12},
{33,24},
{34,40},
{35,15},
{36,22},
{37,3},
{38,26},
{44,3},
{46,5},
{49,3},
{50,5},
{51,5},
{58,3},
{60,13},
{61,7},
{62,20},
{63,20},
{64,20},
{66,7},
{67,26},
{69,7},
{70,23},
{75,42},
{76,7},
{77,20},
{80,42},
{81,7},
{82,20},
{86,16},
{89,3},
{90,5},
{93,3},
{94,18},
{95,32},
{96,5},
{97,26},
{99,26},
{104,17},
{106,3},
{107,5},
{110,3},
{111,5},
{113,5},
{117,3},
};
Tc Ydzl[]="handleClasses()";
Tcpos ZcTbl82843[]={
{1696,3},
{1,5},
{5,9},
{8,9},
{11,9},
{12,11},
{17,35},
{18,9},
{19,11},
{22,9},
{23,11},
{24,13},
{22,9},
{28,9},
{29,11},
{0,3},
};
Tc Yvdn[]="handleLibClasses()";
Tcpos ZcTbl98386[]={
{1734,3},
{1,26},
{2,5},
{4,37},
{5,9},
{6,39},
{8,48},
{9,11},
{10,19},
{13,11},
{14,11},
{15,39},
{16,13},
{20,13},
{21,13},
{14,11},
{23,11},
{24,13},
{29,9},
{30,11},
{35,35},
{36,9},
{37,11},
{40,9},
{41,11},
{42,13},
{40,9},
{46,9},
{47,11},
{51,5},
{0,3},
};
Tc YBjV[]="handleModule()";
Tcpos ZcTbl34599[]={
{711,31},
{1,42},
{3,20},
{5,22},
{9,3},
{10,17},
{11,10},
{13,40},
{14,15},
{15,19},
{16,22},
{18,3},
{19,5},
{20,5},
{24,3},
{25,16},
{28,3},
{31,5},
{33,5},
{36,7},
{40,16},
{43,3},
{46,3},
};
Tc YRPX[]="isTypeMethod()";
Tcpos ZcTbl60980[]={
{1543,31},
{1,42},
{2,24},
{7,7},
};
Tc Yrfb[]="listEnumValues()";
Tcpos ZcTbl4762[]={
{1293,16},
{3,7},
{4,7},
{5,7},
{7,3},
{8,19},
{9,5},
{10,11},
{11,7},
{12,13},
{13,13},
{15,11},
{7,3},
{19,7},
{20,7},
{22,10},
};
Tc YPpi[]="listMembers()";
Tcpos ZcTbl10632[]={
{1379,16},
{3,7},
{4,7},
{5,3},
{6,33},
{7,5},
{8,9},
{10,36},
{11,5},
{12,9},
{15,3},
{17,9},
{18,9},
{19,9},
{20,33},
{21,5},
{22,9},
{24,36},
{25,5},
{26,9},
{29,14},
};
Tc YQcS[]="listMethod()";
Tcpos ZcTbl30970[]={
{1560,31},
{1,17},
{2,3},
{3,5},
{6,42},
{7,24},
{8,21},
{9,22},
{10,3},
{11,5},
{14,15},
{17,7},
{19,5},
{22,12},
{26,23},
{29,23},
{31,21},
{32,3},
{33,14},
{37,16},
{38,7},
{39,3},
{40,9},
{42,9},
{44,7},
{46,7},
{47,7},
{48,7},
{49,7},
{51,3},
{52,20},
{53,5},
{54,11},
{55,11},
{56,13},
{53,5},
{60,40},
{61,3},
{62,9},
{64,3},
{65,9},
{67,3},
{68,9},
{70,24},
{72,7},
{73,7},
{74,3},
{75,9},
{76,9},
{77,9},
{78,9},
{84,16},
{85,3},
{86,9},
{87,14},
{88,9},
{89,14},
{90,9},
{91,14},
{92,9},
{93,14},
{94,9},
{95,14},
{96,9},
{97,14},
{98,9},
{99,14},
{100,9},
{103,3},
{104,5},
{103,3},
{107,22},
};
Tc YBRF[]="listMethods()";
Tcpos ZcTbl47641[]={
{1504,3},
{1,5},
{3,9},
{10,9},
{11,11},
{17,35},
{18,9},
{19,11},
{23,9},
{24,11},
{25,13},
{23,9},
{30,9},
{31,11},
{0,3},
};
Tc YYDo[]="listVars()";
Tcpos ZcTbl85541[]={
{1442,3},
{1,5},
{3,23},
{4,9},
{5,39},
{6,45},
{7,24},
{8,15},
{9,15},
{10,15},
{11,15},
{12,32},
{15,15},
{16,15},
{18,11},
{19,17},
{20,17},
{21,17},
{22,17},
{24,22},
{28,9},
{29,11},
{35,35},
{36,9},
{37,11},
{41,9},
{42,11},
{43,13},
{41,9},
{48,9},
{49,11},
{0,3},
};
Tc You9[]="makeDollarName()";
Tcpos ZcTbl62638[]={
{1193,34},
};
Tc Y3XY[]="pageRef()";
Tcpos ZcTbl8079[]={
{1921,10},
};
Tc Y4f4[]="pageRef/1()";
Tcpos ZcTbl19259[]={
{1927,40},
{1,3},
{2,9},
{4,7},
{5,3},
{6,9},
{8,14},
};
Tc YYLR[]="printAlias()";
Tcpos ZcTbl35096[]={
{1416,16},
{2,7},
{3,7},
{5,57},
{6,7},
{8,14},
};
Tc YlAL[]="processComment()";
Tcpos ZcTbl10023[]={
{1811,16},
{1,18},
{4,3},
{5,13},
{6,5},
{7,7},
{8,13},
{10,16},
{11,7},
{12,23},
{13,23},
{14,23},
{16,19},
{17,7},
{20,14},
{21,9},
{22,11},
{21,9},
{24,9},
{25,11},
{26,17},
{28,20},
{29,15},
{30,15},
{32,16},
{35,14},
{36,9},
{37,11},
{36,9},
{39,9},
{40,11},
{41,17},
{43,20},
{44,15},
{46,15},
{48,16},
{50,13},
{51,9},
{52,11},
{51,9},
{54,9},
{57,17},
{58,11},
{59,13},
{58,11},
{61,11},
{62,13},
{63,19},
{65,22},
{66,17},
{68,17},
{70,20},
{72,11},
{73,17},
{75,20},
{76,15},
{77,15},
{81,5},
{4,3},
{83,3},
{84,9},
{86,10},
};
Tc YYom[]="processFile()";
Tcpos ZcTbl11080[]={
{213,3},
{1,5},
{2,10},
{8,51},
{14,3},
{16,5},
{17,7},
{21,11},
{24,11},
{27,11},
{16,5},
};
Tc YPvR[]="sortMembers()";
Tcpos ZcTbl43125[]={
{1429,16},
{1,3},
{2,9},
{1,3},
{4,10},
};
Tc Y978[]="startsWithDotname()";
Tcpos ZcTbl90798[]={
{2127,3},
{1,12},
{3,3},
{4,12},
{6,3},
{8,12},
{10,3},
{11,5},
{14,5},
{15,14},
{10,3},
{18,10},
};
Tc YZLK[]="summarize()";
Tcpos ZcTbl29750[]={
{879,21},
{3,19},
{4,3},
{5,3},
{6,5},
{8,3},
{9,5},
{13,5},
{14,3},
{16,3},
{17,5},
{19,3},
{20,7},
{21,5},
{22,5},
{23,7},
{28,5},
{29,3},
{31,3},
{32,5},
{36,3},
{37,7},
{38,5},
{40,5},
{41,7},
{46,3},
{47,7},
{48,5},
{50,5},
{51,7},
{55,10},
};
Tc YXYv[]="summarizeClass()";
Tcpos ZcTbl6020[]={
{1009,31},
{1,22},
{2,3},
{3,5},
{4,12},
{5,17},
{6,7},
{11,3},
{13,7},
{14,14},
{15,39},
{16,14},
{17,39},
{18,14},
{20,14},
{23,12},
{25,12},
{27,12},
{29,17},
{30,3},
{31,5},
{32,5},
{35,3},
{36,5},
{39,54},
{40,9},
{41,5},
{43,11},
{50,45},
{51,26},
{52,9},
{53,9},
{54,5},
{55,11},
{57,9},
{58,5},
};
Tc YsLr[]="summarizeClasses()";
Tcpos ZcTbl79320[]={
{940,3},
{1,5},
{4,63},
{5,9},
{6,43},
{7,11},
{11,13},
{17,35},
{18,9},
{19,11},
{23,9},
{24,11},
{25,13},
{23,9},
{30,9},
{31,11},
{36,9},
{37,11},
{44,9},
{0,3},
};
Tc YzMJ[]="summarizeMethod()";
Tcpos ZcTbl51479[]={
{1204,31},
{1,42},
{2,17},
{3,22},
{5,24},
{6,21},
{7,3},
{8,5},
{11,15},
{14,7},
{16,5},
{19,12},
{23,3},
{25,5},
{26,16},
{27,19},
{28,16},
{30,16},
{32,23},
{34,23},
{37,23},
{39,21},
{40,3},
{41,14},
{46,73},
{47,3},
{48,5},
{49,5},
{51,3},
{52,5},
{54,18},
{55,9},
{57,5},
{58,11},
{60,9},
{61,9},
{62,9},
{64,5},
{65,11},
{66,22},
{67,7},
{68,13},
{69,13},
{70,15},
{67,7},
{72,11},
{75,26},
{77,9},
{78,9},
{79,5},
{80,11},
{82,9},
{83,5},
};
Tc YiYC[]="summarizeMethods()";
Tcpos ZcTbl96426[]={
{1146,3},
{1,5},
{3,9},
{8,63},
{9,9},
{10,44},
{11,11},
{12,13},
{19,35},
{20,9},
{21,11},
{25,9},
{26,11},
{27,13},
{25,9},
{32,9},
{33,11},
{38,9},
{39,11},
{0,3},
};
Tc YLzy[]="summarizeVars()";
Tcpos ZcTbl1642[]={
{1077,3},
{1,5},
{3,23},
{4,9},
{5,11},
{6,11},
{8,37},
{9,28},
{10,9},
{11,11},
{13,24},
{14,55},
{15,15},
{16,15},
{17,15},
{18,15},
{19,15},
{21,32},
{24,15},
{25,15},
{26,11},
{27,17},
{29,15},
{30,11},
{39,35},
{40,9},
{41,11},
{45,9},
{46,11},
{47,13},
{45,9},
{52,9},
{53,11},
{58,9},
{59,11},
{0,3},
};
Tc YGQ4[]="wrapKnownTypes()";
Tcpos ZcTbl65909[]={
{2091,3},
{1,12},
{3,3},
{4,12},
{6,10},
};
Tc YjOp[]="wrapTypeRef()";
Tcpos ZcTbl17750[]={
{2103,3},
{1,12},
{3,3},
{4,12},
{9,3},
{10,12},
{13,3},
{15,10},
{17,10},
{19,68},
};
Tc YKiR[]="writeHeader()";
Tcpos ZcTbl40461[]={
{2411,54},
{1,20},
{2,3},
{3,5},
{4,10},
{6,3},
{8,3},
{9,3},
{10,3},
{12,3},
{13,3},
{14,5},
{18,3},
{19,3},
{20,3},
{21,3},
{22,5},
{25,3},
{26,3},
{27,3},
{29,10},
};
Tc Y0ZRa[]="writeImplementers()";
Tcpos ZcTbl7069[]={
{398,29},
{1,3},
{2,5},
{3,7},
{4,9},
{2,5},
{1,3},
{9,3},
{10,5},
{11,5},
{12,5},
{13,7},
{12,5},
{15,5},
{16,5},
};
Tc YNDG[]="writeImplements()";
Tcpos ZcTbl90766[]={
{385,3},
{1,5},
{3,3},
{4,5},
{3,3},
{6,3},
{7,5},
};
Tc YO8S[]="writeIndex()";
Tcpos ZcTbl2580[]={
{498,17},
{1,3},
{7,32},
{8,33},
{9,3},
{10,17},
{11,5},
{13,7},
{14,45},
{15,9},
{23,19},
{24,16},
{26,24},
{28,9},
{29,11},
{33,13},
{28,9},
{37,7},
{38,9},
{40,9},
{9,3},
{45,3},
{46,5},
{47,5},
{48,5},
{49,5},
{50,5},
{52,5},
{53,26},
{54,7},
{56,14},
{58,7},
{59,7},
{60,7},
{61,7},
{62,7},
{52,5},
{65,5},
{66,5},
{45,3},
{70,3},
{71,3},
{72,3},
{73,3},
{74,17},
{75,5},
{76,7},
{77,7},
{78,7},
{79,7},
{80,7},
{73,3},
{83,3},
{84,3},
{86,3},
};
Tc YR4E[]="writeInherited()";
Tcpos ZcTbl76920[]={
{441,3},
{1,5},
{3,28},
{4,3},
{5,23},
{6,38},
{7,5},
{8,7},
{11,7},
{13,7},
{17,5},
};
Tc Ybsk[]="writePage()";
Tcpos ZcTbl90413[]={
{318,17},
{2,3},
{4,3},
{5,3},
{6,5},
{8,3},
{9,30},
{10,3},
{12,5},
{15,3},
{16,5},
{20,33},
{21,3},
{22,5},
{23,11},
{24,50},
{25,11},
{27,11},
{30,3},
{32,3},
{33,3},
{34,3},
{36,3},
{38,3},
{40,3},
{41,22},
{42,3},
{45,3},
{48,3},
{50,3},
{53,3},
{56,3},
{58,3},
{60,3},
{62,3},
};
Tc YtZ1[]="writePieces()";
Tcpos ZcTbl80277[]={
{465,3},
{1,5},
{2,24},
{3,39},
{4,7},
{5,9},
{7,9},
{0,3},
};
Tc YVox[]="writeSubClasses()";
Tcpos ZcTbl67008[]={
{420,29},
{1,3},
{2,5},
{3,7},
{1,3},
{7,3},
{8,5},
{9,5},
{10,5},
{11,7},
{10,5},
{13,5},
{14,5},
};
Tcode ZcodeTable[]={
{0,YGbq,Yaaa,ZcTbl0},
{412,Y_4X,YxLq,ZcTbl412},
{465,Yg6g,YwJM,ZcTbl465},
{630,Yg6g,Y3SI,ZcTbl630},
{794,Yg6g,Yz10,ZcTbl794},
{1642,YGbq,YLzy,ZcTbl1642},
{1740,YQXZ,Yuvy,ZcTbl1740},
{1741,YQXZ,Yuvy,ZcTbl1741},
{1798,Yg6g,Y6a9,ZcTbl1798},
{1872,YkTo,YNFk,ZcTbl1872},
{1873,YQXZ,Y3_i,ZcTbl1873},
{1915,YQXZ,YuKH,ZcTbl1915},
{2082,Yg6g,YM3X,ZcTbl2082},
{2580,YGbq,YO8S,ZcTbl2580},
{2646,Yg6g,Y5pP,ZcTbl2646},
{3006,Y57c,YWNo,ZcTbl3006},
{3141,Yg6g,Ygsn,ZcTbl3141},
{3176,YQXZ,YdwV,ZcTbl3176},
{3273,Yzok,Y_VO,ZcTbl3273},
{3993,Yg6g,YOFz,ZcTbl3993},
{4008,Yg6g,Y4Wm,ZcTbl4008},
{4115,YGbq,YJas,ZcTbl4115},
{4256,Yg6g,Yh7E,ZcTbl4256},
{4600,Yg6g,YjaA,ZcTbl4600},
{4732,Yg6g,YNhz,ZcTbl4732},
{4762,YGbq,Yrfb,ZcTbl4762},
{4902,Yg6g,Ye3c,ZcTbl4902},
{4937,YGbq,YUc5,ZcTbl4937},
{4968,Yg6g,YCkn,ZcTbl4968},
{5105,Yg6g,Y8pM,ZcTbl5105},
{5223,YQXZ,YeHq,ZcTbl5223},
{5270,YGbq,Y9QD,ZcTbl5270},
{5342,Ysv0,YQE_,ZcTbl5342},
{6020,YGbq,YXYv,ZcTbl6020},
{6038,YqXi,Ysro,ZcTbl6038},
{6039,YqXi,Ysro,ZcTbl6039},
{6172,Yg6g,Youh,ZcTbl6172},
{6228,Y0CK,Ya7y,ZcTbl6228},
{6308,Y_4X,YR5_,ZcTbl6308},
{6724,Yg6g,YcEv,ZcTbl6724},
{6734,Yg6g,YBwX,ZcTbl6734},
{7028,YQXZ,YbgE,ZcTbl7028},
{7029,YQXZ,YbgE,ZcTbl7029},
{7035,YQXZ,YYXN,ZcTbl7035},
{7069,YGbq,Y0ZRa,ZcTbl7069},
{7452,YkTo,Ys1a,ZcTbl7452},
{7515,YQXZ,YxVS,ZcTbl7515},
{7598,YQXZ,YzRJ,ZcTbl7598},
{8079,YGbq,Y3XY,ZcTbl8079},
{8515,Yg6g,Y1Xb,ZcTbl8515},
{8602,Yg6g,YiO6,ZcTbl8602},
{8671,Yg6g,Y3l3a,ZcTbl8671},
{8750,YQXZ,Y_hh,ZcTbl8750},
{9319,Yg6g,Y8xC,ZcTbl9319},
{9422,Yg6g,Y7IM,ZcTbl9422},
{9530,YGbq,Y4Vy,ZcTbl9530},
{9948,Y_4X,YALK,ZcTbl9948},
{10023,YGbq,YlAL,ZcTbl10023},
{10085,YGbq,Y10A,ZcTbl10085},
{10176,Yg6g,Y_ym,ZcTbl10176},
{10613,Y_4X,YCbo,ZcTbl10613},
{10632,YGbq,YPpi,ZcTbl10632},
{10807,YQXZ,YiXca,ZcTbl10807},
{10831,Yg6g,YWpG,ZcTbl10831},
{11080,YGbq,YYom,ZcTbl11080},
{11217,Y_4X,YoZS,ZcTbl11217},
{11612,YQXZ,YVtG,ZcTbl11612},
{11693,Yg6g,Yi5C,ZcTbl11693},
{11851,Yg6g,Y9FU,ZcTbl11851},
{11973,YQXZ,YPxq,ZcTbl11973},
{12252,Yg6g,Y36B,ZcTbl12252},
{12459,YGbq,Y1PJ,ZcTbl12459},
{12499,YQXZ,YGfO,ZcTbl12499},
{12654,YQXZ,YTEI,ZcTbl12654},
{13081,Yg6g,YR9H,ZcTbl13081},
{13987,YQXZ,YZlX,ZcTbl13987},
{14295,YGbq,Yp0n,ZcTbl14295},
{14715,Y_4X,Y4SL,ZcTbl14715},
{14960,YuC6,YaWp,ZcTbl14960},
{14983,Yg6g,YEEk,ZcTbl14983},
{15363,YuC6,Y7EP,ZcTbl15363},
{15465,Yg6g,YZrH,ZcTbl15465},
{15718,Y_4X,YEFs,ZcTbl15718},
{15755,YkTo,YEgn,ZcTbl15755},
{15776,Yg6g,Y8Wx,ZcTbl15776},
{16020,Ypx4,YPRm,ZcTbl16020},
{16053,YkTo,Y5P_,ZcTbl16053},
{16054,Yhjo,Yx5d,ZcTbl16054},
{16084,YGbq,YnmB,ZcTbl16084},
{16195,YGbq,YWZE,ZcTbl16195},
{16350,Yzok,Ygzb,ZcTbl16350},
{16738,Yg6g,Yw57,ZcTbl16738},
{16975,Yg6g,YlHH,ZcTbl16975},
{17451,Yg6g,You8,ZcTbl17451},
{17536,Yg6g,Ym28,ZcTbl17536},
{17750,YGbq,YjOp,ZcTbl17750},
{18187,Ypx4,Ym1t,ZcTbl18187},
{18774,Yhjo,Yt30,ZcTbl18774},
{19076,Yg6g,YBIb,ZcTbl19076},
{19259,YGbq,Y4f4,ZcTbl19259},
{19756,Yg6g,YNAG,ZcTbl19756},
{19887,Ydmy,YHM2,ZcTbl19887},
{20149,Y_4X,YFbI,ZcTbl20149},
{20159,YdPO,YNC6,ZcTbl20159},
{20323,YGbq,YQXy,ZcTbl20323},
{20555,YqXi,YcP2,ZcTbl20555},
{20940,Yg6g,Yxe4,ZcTbl20940},
{21019,YGbq,Y1Vl,ZcTbl21019},
{21339,YQXZ,Y5mz,ZcTbl21339},
{21378,YHVE,YjAA,ZcTbl21378},
{21418,Y_4X,YtpQ,ZcTbl21418},
{21676,YHVE,Yrsv,ZcTbl21676},
{21859,YGbq,YjEW,ZcTbl21859},
{22232,YQXZ,Y58p,ZcTbl22232},
{22507,YQXZ,YkKc,ZcTbl22507},
{23043,YQXZ,Ye4R,ZcTbl23043},
{23085,Yg6g,YdRc,ZcTbl23085},
{23149,YQXZ,YcTl,ZcTbl23149},
{23561,Yg6g,YP1b,ZcTbl23561},
{24916,Y_4X,Y9iJ,ZcTbl24916},
{24917,Y57c,YvtJ,ZcTbl24917},
{25475,YQXZ,YrSB,ZcTbl25475},
{25860,YHVE,YFAP,ZcTbl25860},
{25958,Y_4X,Y4vu,ZcTbl25958},
{26437,Yg6g,Ye66,ZcTbl26437},
{26683,YQXZ,YniQ,ZcTbl26683},
{26760,YkTo,YYk7,ZcTbl26760},
{27063,YQXZ,Yysl,ZcTbl27063},
{27168,Yg6g,YrcZ,ZcTbl27168},
{27172,YGbq,Yn8ia,ZcTbl27172},
{27280,YQXZ,YLD5,ZcTbl27280},
{28158,YQXZ,YxHj,ZcTbl28158},
{28454,Yg6g,YUbH,ZcTbl28454},
{28605,Yg6g,YKr8,ZcTbl28605},
{28962,YGbq,Y3Q7,ZcTbl28962},
{29058,Yg6g,Yud3,ZcTbl29058},
{29319,YQXZ,Yt45,ZcTbl29319},
{29560,Yzok,YzK9,ZcTbl29560},
{29585,Y_4X,YAVe,ZcTbl29585},
{29750,YGbq,YZLK,ZcTbl29750},
{29910,YQXZ,YnXxa,ZcTbl29910},
{30443,Yg6g,Yc3M,ZcTbl30443},
{30719,Yg6g,YvRq,ZcTbl30719},
{30947,YQXZ,YElD,ZcTbl30947},
{30970,YGbq,YQcS,ZcTbl30970},
{31332,Y_4X,Ya7k,ZcTbl31332},
{31338,YQXZ,YSSX,ZcTbl31338},
{31888,Yg6g,YKbA,ZcTbl31888},
{32086,Y_4X,Y1As,ZcTbl32086},
{32204,Yg6g,YOPG,ZcTbl32204},
{32257,Y57c,YEF1,ZcTbl32257},
{32297,Yg6g,YrDo,ZcTbl32297},
{32309,Y57c,YozJ,ZcTbl32309},
{32779,YGbq,Y0KY,ZcTbl32779},
{32878,YGbq,YiJI,ZcTbl32878},
{32939,Ysv0,Y0DO,ZcTbl32939},
{33350,Yg6g,YY2f,ZcTbl33350},
{33439,YQXZ,YBJK,ZcTbl33439},
{34047,Ydmy,Yq05,ZcTbl34047},
{34324,YkTo,Y4qG,ZcTbl34324},
{34415,Yg6g,YX0k,ZcTbl34415},
{34599,YGbq,YBjV,ZcTbl34599},
{34818,Ysv0,YHWY,ZcTbl34818},
{34882,YqXi,Yuv2,ZcTbl34882},
{34905,YqXi,YPve,ZcTbl34905},
{35029,Y_4X,YSxu,ZcTbl35029},
{35088,Y_4X,YcIS,ZcTbl35088},
{35096,YGbq,YYLR,ZcTbl35096},
{35389,Yg6g,Yn3i,ZcTbl35389},
{35424,YQXZ,Y0pQ,ZcTbl35424},
{36159,Y_4X,Y_4w,ZcTbl36159},
{36491,Y_4X,YYT9,ZcTbl36491},
{36880,Yg6g,YFBD,ZcTbl36880},
{36927,YQXZ,Yima,ZcTbl36927},
{37195,YGbq,YYXD,ZcTbl37195},
{37709,Yg6g,Y_fU,ZcTbl37709},
{38552,YkTo,Y35R,ZcTbl38552},
{38674,Yg6g,Y4Da,ZcTbl38674},
{38911,Yzok,YM2k,ZcTbl38911},
{38927,YqXi,YRo0,ZcTbl38927},
{39225,Yg6g,YDiN,ZcTbl39225},
{39372,Y57c,Yp4z,ZcTbl39372},
{39789,Y57c,YfrQ,ZcTbl39789},
{39899,YdPO,YOBf,ZcTbl39899},
{39983,Yg6g,YMc3,ZcTbl39983},
{40374,YdPO,Yxgh,ZcTbl40374},
{40461,YGbq,YKiR,ZcTbl40461},
{40839,YQXZ,YlOY,ZcTbl40839},
{41085,YQXZ,Y1BW,ZcTbl41085},
{41247,YGbq,YSww,ZcTbl41247},
{41733,YQXZ,YxvM,ZcTbl41733},
{42315,Yg6g,YnbC,ZcTbl42315},
{42842,YGbq,Ysdj,ZcTbl42842},
{42956,YQXZ,YNv2,ZcTbl42956},
{42983,Y_4X,Y9aV,ZcTbl42983},
{43000,Yzok,YEFE,ZcTbl43000},
{43124,Y_4X,Ygil,ZcTbl43124},
{43125,YGbq,YPvR,ZcTbl43125},
{43483,YkTo,Yd0m,ZcTbl43483},
{43845,YQXZ,Y_9S,ZcTbl43845},
{43917,YqXi,YLig,ZcTbl43917},
{44130,Y_4X,YG80,ZcTbl44130},
{44401,Ydmy,YOoa,ZcTbl44401},
{44535,YQXZ,Yc5i,ZcTbl44535},
{44652,YGbq,YNIo,ZcTbl44652},
{44787,YqXi,YiIo,ZcTbl44787},
{45209,Y_4X,Y2NH,ZcTbl45209},
{45230,Y_4X,YN6w,ZcTbl45230},
{45289,Y_4X,Y7gV,ZcTbl45289},
{45322,YQXZ,YN96,ZcTbl45322},
{45337,YGbq,YpEz,ZcTbl45337},
{45452,Yg6g,YeqT,ZcTbl45452},
{45907,YQXZ,YipB,ZcTbl45907},
{46171,Y_4X,Y9VX,ZcTbl46171},
{46630,Yg6g,Yrwj,ZcTbl46630},
{46631,YkTo,YHCY,ZcTbl46631},
{46761,YkTo,YN2v,ZcTbl46761},
{46868,Ypx4,YzF7,ZcTbl46868},
{47436,YdPO,Ynxa,ZcTbl47436},
{47641,YGbq,YBRF,ZcTbl47641},
{47746,YuC6,YO53,ZcTbl47746},
{48299,Y_4X,Y9Cv,ZcTbl48299},
{48469,Yg6g,Yx23,ZcTbl48469},
{49183,Y_4X,YgcH,ZcTbl49183},
{49285,YkTo,Y1Ue,ZcTbl49285},
{49482,YQXZ,YGSM,ZcTbl49482},
{49897,YGbq,YjHe,ZcTbl49897},
{50341,Yg6g,Yglh,ZcTbl50341},
{50841,Ysv0,YLwM,ZcTbl50841},
{51475,Yg6g,YnaG,ZcTbl51475},
{51479,YGbq,YzMJ,ZcTbl51479},
{51544,Yg6g,YiSI,ZcTbl51544},
{51873,YQXZ,Yi0h,ZcTbl51873},
{52047,YdPO,YYG0,ZcTbl52047},
{52386,Y_4X,YgcM,ZcTbl52386},
{52608,Y_4X,YqK0,ZcTbl52608},
{52917,YQXZ,YxBM,ZcTbl52917},
{53325,Y_4X,YlJi,ZcTbl53325},
{53377,Y_4X,Yp81,ZcTbl53377},
{53510,YQXZ,YRz6,ZcTbl53510},
{53511,YQXZ,YRz6,ZcTbl53511},
{53988,Yg6g,Y5tU,ZcTbl53988},
{54290,Yg6g,Ya1_,ZcTbl54290},
{54331,Y_4X,YLzZ,ZcTbl54331},
{54828,YQXZ,YFK5,ZcTbl54828},
{54950,Y57c,YHjE,ZcTbl54950},
{55119,Yg6g,YvGg,ZcTbl55119},
{56372,Y_4X,Y4u_,ZcTbl56372},
{56381,Y_4X,Y99g,ZcTbl56381},
{56555,YYTG,YFIR,ZcTbl56555},
{56758,YGbq,YXNg,ZcTbl56758},
{56903,Yg6g,YEzw,ZcTbl56903},
{57165,Yg6g,Y8q6,ZcTbl57165},
{57213,Yg6g,Y4A9,ZcTbl57213},
{57439,YGbq,Yw6n,ZcTbl57439},
{57441,YQXZ,YDE6,ZcTbl57441},
{58278,YGbq,Ygck,ZcTbl58278},
{58921,YQXZ,Yj7N,ZcTbl58921},
{58975,YkTo,YSa1,ZcTbl58975},
{59236,Y57c,Ykc9,ZcTbl59236},
{59819,YkTo,YGQL,ZcTbl59819},
{60003,YqXi,YX0R,ZcTbl60003},
{60141,YQXZ,Yv_x,ZcTbl60141},
{60480,Yg6g,YWul,ZcTbl60480},
{60567,YkTo,YskO,ZcTbl60567},
{60593,Y_4X,Y5LR,ZcTbl60593},
{60980,YGbq,YRPX,ZcTbl60980},
{61284,Yzok,Y2cg,ZcTbl61284},
{61323,Yg6g,YjOa,ZcTbl61323},
{61629,Yg6g,Yp1W,ZcTbl61629},
{62251,YQXZ,YGjZ,ZcTbl62251},
{62609,Yg6g,YEZU,ZcTbl62609},
{62638,YGbq,You9,ZcTbl62638},
{62809,Y_4X,Ylj3,ZcTbl62809},
{62900,Yg6g,YfjP,ZcTbl62900},
{63132,Yg6g,YycE,ZcTbl63132},
{63527,YGbq,YqS8,ZcTbl63527},
{63578,Y_4X,Yuz_,ZcTbl63578},
{63883,Yg6g,YPvG,ZcTbl63883},
{63886,Y57c,YwHH,ZcTbl63886},
{64067,Yg6g,Y7J_,ZcTbl64067},
{64478,Yzok,YRbs,ZcTbl64478},
{64531,YkTo,YrJP,ZcTbl64531},
{64594,Yg6g,YDLv,ZcTbl64594},
{65246,YQXZ,Y1EK,ZcTbl65246},
{65333,Yg6g,YZ3U,ZcTbl65333},
{65610,YQXZ,YcXq,ZcTbl65610},
{65794,YGbq,YZCk,ZcTbl65794},
{65909,YGbq,YGQ4,ZcTbl65909},
{65952,Yg6g,Yu8c,ZcTbl65952},
{66188,YkTo,YJ7z,ZcTbl66188},
{66501,Yzok,YPPv,ZcTbl66501},
{66582,Y_4X,Y4Jj,ZcTbl66582},
{66957,YGbq,Y3cb,ZcTbl66957},
{67008,YGbq,YVox,ZcTbl67008},
{67123,Yg6g,YjQE,ZcTbl67123},
{67276,Y57c,YcBB,ZcTbl67276},
{67675,Yg6g,YsYS,ZcTbl67675},
{67708,Yg6g,Ye5I,ZcTbl67708},
{68275,YQXZ,Y8h6,ZcTbl68275},
{68318,Yg6g,Y19C,ZcTbl68318},
{68673,Yg6g,YS5g,ZcTbl68673},
{68691,YQXZ,YYdB,ZcTbl68691},
{69092,Yg6g,YbUI,ZcTbl69092},
{69190,Yg6g,YCPu,ZcTbl69190},
{69815,YQXZ,Y6Fz,ZcTbl69815},
{69864,Yg6g,YqdL,ZcTbl69864},
{70283,YGbq,Yn14,ZcTbl70283},
{70447,YQXZ,Yo4X,ZcTbl70447},
{70521,Yg6g,YrT8,ZcTbl70521},
{71675,YQXZ,YK_T,ZcTbl71675},
{71848,Yg6g,YNXg,ZcTbl71848},
{72007,YkTo,YzQB,ZcTbl72007},
{72429,YQXZ,YlJ9,ZcTbl72429},
{73233,YQXZ,YqCy,ZcTbl73233},
{73471,Y_4X,Y_Qs,ZcTbl73471},
{73580,Y_4X,YF6S,ZcTbl73580},
{73887,Yg6g,YK7W,ZcTbl73887},
{74211,YGbq,YYPv,ZcTbl74211},
{74330,YQXZ,YCEY,ZcTbl74330},
{74718,YQXZ,YdLG,ZcTbl74718},
{74774,Yg6g,YEts,ZcTbl74774},
{74861,Yg6g,Y_VA,ZcTbl74861},
{75697,Yzok,YgDO,ZcTbl75697},
{75821,YQXZ,YEuD,ZcTbl75821},
{75871,YGbq,YsXT,ZcTbl75871},
{75910,Yg6g,YK9t,ZcTbl75910},
{76467,YGbq,YG8D,ZcTbl76467},
{76644,Yzok,YImf,ZcTbl76644},
{76920,YGbq,YR4E,ZcTbl76920},
{77656,Yg6g,YLo9,ZcTbl77656},
{77717,Yg6g,YMsF,ZcTbl77717},
{78082,Y_4X,YbzA,ZcTbl78082},
{78335,Y0CK,YaaO,ZcTbl78335},
{79320,YGbq,YsLr,ZcTbl79320},
{79365,YGbq,Yhfb,ZcTbl79365},
{79729,Yg6g,YsdE,ZcTbl79729},
{80277,YGbq,YtZ1,ZcTbl80277},
{80633,YGbq,YDcJ,ZcTbl80633},
{80644,Y_4X,YobA,ZcTbl80644},
{80772,YQXZ,Ybj5,ZcTbl80772},
{80808,YQXZ,Yrgp,ZcTbl80808},
{80968,Yg6g,YSDH,ZcTbl80968},
{81231,Yg6g,YqwF,ZcTbl81231},
{81456,Yg6g,YOQN,ZcTbl81456},
{81580,YkTo,Y5X7,ZcTbl81580},
{81692,YGbq,Y5vg,ZcTbl81692},
{81798,Yzok,YMnk,ZcTbl81798},
{81956,YQXZ,YClq,ZcTbl81956},
{82533,Yzok,Yh2v,ZcTbl82533},
{82534,Yzok,Yh2v,ZcTbl82534},
{82618,YkTo,Yxlj,ZcTbl82618},
{82665,Yg6g,YNFL,ZcTbl82665},
{82843,YGbq,Ydzl,ZcTbl82843},
{83031,Y_4X,YpMw,ZcTbl83031},
{83326,YYTG,YVvh,ZcTbl83326},
{83443,YkTo,Yijq,ZcTbl83443},
{83593,YQXZ,YG6y,ZcTbl83593},
{83606,Yhjo,YFeP,ZcTbl83606},
{84323,YQXZ,YU1K,ZcTbl84323},
{84870,YkTo,Y_pS,ZcTbl84870},
{84899,YYTG,Y8w5,ZcTbl84899},
{85000,Y_4X,Ycb9,ZcTbl85000},
{85022,Yg6g,YRP7,ZcTbl85022},
{85111,Yg6g,Yvot,ZcTbl85111},
{85295,Yzok,Yza4,ZcTbl85295},
{85541,YGbq,YYDo,ZcTbl85541},
{85648,YQXZ,YDdP,ZcTbl85648},
{86206,Yzok,YZNA,ZcTbl86206},
{86485,Yg6g,Y53b,ZcTbl86485},
{86581,Yg6g,YHwg,ZcTbl86581},
{86775,Ypx4,YQcV,ZcTbl86775},
{86818,Y_4X,YlgI,ZcTbl86818},
{87235,Y_4X,YR5m,ZcTbl87235},
{87327,YQXZ,Y9gJ,ZcTbl87327},
{87653,Yg6g,YKUf,ZcTbl87653},
{87834,Yg6g,YTM4,ZcTbl87834},
{88581,YGbq,YHMc,ZcTbl88581},
{88688,Yg6g,YMMn,ZcTbl88688},
{89012,YHVE,YYkI,ZcTbl89012},
{89237,YQXZ,YEtq,ZcTbl89237},
{89685,Y_4X,Y59h,ZcTbl89685},
{89805,YQXZ,YCLx,ZcTbl89805},
{89987,YkTo,YCbR,ZcTbl89987},
{90157,Ydmy,Yjek,ZcTbl90157},
{90238,YQXZ,YEtp,ZcTbl90238},
{90413,YGbq,Ybsk,ZcTbl90413},
{90589,YQXZ,Y4EA,ZcTbl90589},
{90674,YQXZ,YxDM,ZcTbl90674},
{90734,YQXZ,Y0Nt,ZcTbl90734},
{90766,YGbq,YNDG,ZcTbl90766},
{90798,YGbq,Y978,ZcTbl90798},
{90834,YGbq,YyML,ZcTbl90834},
{90889,YqXi,YZvS,ZcTbl90889},
{90891,YqXi,YXf2,ZcTbl90891},
{91041,YQXZ,YV_n,ZcTbl91041},
{91748,YGbq,YTrD,ZcTbl91748},
{91829,YQXZ,YPlW,ZcTbl91829},
{91840,YQXZ,Yaoa,ZcTbl91840},
{92122,YQXZ,YWPO,ZcTbl92122},
{92163,Y_4X,YTjU,ZcTbl92163},
{92336,Y57c,YLKU,ZcTbl92336},
{92453,Yg6g,YH3x,ZcTbl92453},
{92784,Yhjo,Ye39,ZcTbl92784},
{93239,YQXZ,Y1La,ZcTbl93239},
{93663,Yg6g,YcXM,ZcTbl93663},
{94113,YQXZ,Yxd7,ZcTbl94113},
{94168,Yg6g,YPFc,ZcTbl94168},
{94199,Yg6g,YR7H,ZcTbl94199},
{94362,Yg6g,Y27Q,ZcTbl94362},
{94823,YkTo,Yj_J,ZcTbl94823},
{95120,YQXZ,YnCB,ZcTbl95120},
{95201,Y_4X,YhC6,ZcTbl95201},
{95330,YQXZ,YowX,ZcTbl95330},
{95800,YuC6,Y6us,ZcTbl95800},
{96107,Y_4X,YMF2,ZcTbl96107},
{96277,Yg6g,YGFh,ZcTbl96277},
{96426,YGbq,YiYC,ZcTbl96426},
{96992,YqXi,YQws,ZcTbl96992},
{97019,Y_4X,YgQK,ZcTbl97019},
{97223,YQXZ,YROM,ZcTbl97223},
{97268,YGbq,Y8q1,ZcTbl97268},
{97527,Yg6g,YRsu,ZcTbl97527},
{98019,Yg6g,Y9ig,ZcTbl98019},
{98191,YQXZ,YK_x,ZcTbl98191},
{98386,YGbq,Yvdn,ZcTbl98386},
{98903,Yg6g,Y3uM,ZcTbl98903},
{99036,YQXZ,YYLp,ZcTbl99036},
{99225,YQXZ,Y_TK,ZcTbl99225},
{99618,YQXZ,Y85Z,ZcTbl99618},
{99666,YQXZ,YSl9,ZcTbl99666},
{99764,YQXZ,Ydye,ZcTbl99764},
{99790,YGbq,YNiY,ZcTbl99790},
{99838,YkTo,YTE3,ZcTbl99838},
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

void ZthrowInternal(Tc *text) {
 YUSH(NULL, text);
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
 beforeExit();
 exit((int)val);
}

void *ZnoAllocClear(size_t len, void *p, void *(*init)(void*)) {
 memset(p, 0, len);
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

Tc *ZintFormat(Tc *fmt, Ti n) {
 char fmtbuf[100];
 char buf[100];
 char *p;
 int len;
 int c;
 Tc *fmtp;
 if (fmt == NULL) ZthrowCstringNil("ToString(): format is NIL");
 if (ZstringSizePtr(fmt, &fmtp) > 90) {
  ZthrowCstringBadValue("ToString(): format too long");
 }
 c = fmtp[strlen((char*)fmtp) - 1];
 if (c != 'd' && c != 'x') {
  ZthrowCstringBadValue("ToString(): format must end in 'd' or 'x'");
 }
 sprintf(fmtbuf, "%%%s", fmtp);
 strcpy(fmtbuf + strlen(fmtbuf) - 1, (c == 'd' ? ZINT_FORMAT : ZINT_XFORMAT) + 1);
 sprintf(buf, fmtbuf, n);
 len = (int)strlen(buf);
 p = Za(ZOH_OFF + len + 2);
 p[ZOH_OFF] = len;
 strcpy(p + ZOH_OFF + 1, buf);
 return (Tc*)p;
}

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

Tf Zstring2float(Tc *ss, Ti *dn) {
 Tc *s;
 char *e;
 Ti len;
 if (ss == NULL) {
  ZthrowCstringNil("using toFloat() on NIL");
 }
 len = ZstringSizePtr(ss, &s);
 Tf r = strtod((char *)s, &e);
 if (dn) *dn = (Tc*)e - s;
 return r;
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

void ZforStringNew(Tc *p, Tfs *s) {
 s->len = p == NULL ? 0 : ZstringSizePtr(p, &(s->ptr));
 s->idx = 0;
}
void ZforStringGetInt(Tfs *s, Ti *p) {
 if (s->idx >= s->len) *p = 0;
 else *p = ZfromChar(s->ptr + s->idx);
}
int ZforStringContInt(Tfs *s) {
return s->idx < s->len;
}
void ZforStringNextInt(Tfs *s, Ti *p) {
 if (s->idx < s->len) {
  ++(s->idx);
  while ((s->ptr[s->idx] & 0xc0) == 0x80) ++(s->idx);
 }
 ZforStringGetInt(s, p);
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

void ZthrowIobject(Tr eo) {
 YxIS(eo);
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

Ti ZstringCompare(Tc *one, Tc *two, int dn) {
 Tc *onep;
 Tc *twop;
 Ti onelen;
 Ti twolen;
 Ti r;
 size_t len;
 if (one == NULL) {
  if (!dn) ZthrowCstringNil("using Compare() on NIL");
  if (two == NULL) r = 0;
  else r = -1;
 } else {
  if (two == NULL) ZthrowCstringNil("using Compare() with NIL argument");
  onelen = ZstringSizePtr(one, &onep);
  twolen = ZstringSizePtr(two, &twop);
  len = onelen < twolen ? onelen : twolen;
  r = memcmp(onep, twop, len);
  if (r == 0) r = onelen - twolen;
  if (r < 0) r = -1;
  else if (r > 0) r = 1;
 }
 return r;
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

Ti ZptrQuotedToInt(Tc *s, int t, Ti def) {
 Ti r = 0;
 Ti m = 1;
 Tc *p = s;
 if (*p == '-') { ++p; m = -1; }
 if (*p < '0' || *p > '9') {
  if (t == 1) ZthrowCstringBadValue("quotedToInt(): argument does not start with a digit or -");
  return def;
 }
 for ( ; *p != 0; ++p) {
  if (*p >= '0' && *p <= '9')
   r = r * 10 + (*p - '0');
  else if (*p != '\'' && *p != '_')
   break;
 }
 return r * m;
}

Ti ZptrQuotedBinToInt(Tc *s, int t, Ti def) {
 Ti r = 0;
 Tc *p;
 if (*s < '0' || *s > '1') {
  if (t == 1) ZthrowCstringBadValue("quotedBinToInt(): argument does not start with 0 or 1");
  return def;
 }
 for (p = s; *p != 0; ++p) {
  if (*p == '0')
   r <<= 1;
  else if (*p == '1')
   r = (r << 1) + 1;
  else if (*p != '\'' && *p != '_')
   break;
 }
 return r;
}

Ti ZptrHexToInt(Tc *s, int t, Ti def) {
 Ti r;
 char *p = (char *)s;
 if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) p += 2;
 if ((*p < '0' || *p > '9') && (*p < 'a' || *p > 'f') && (*p < 'A' || *p > 'F')) {
  if (t == 1) ZthrowCstringBadValue("hexToInt(): argument does not start with a hex digit");
  return def;
 }
 sscanf(p, ZINT_XFORMAT, &r);
 return r;
}

Ti ZptrQuotedHexToInt(Tc *s, int t, Ti def) {
 Ti r = 0;
 Tc *p = s;
 if (p[0] == '0' && (p[1] == 'x' || p[1] == 'X')) p += 2;
 if ((*p < '0' || *p > '9') && (*p < 'a' || *p > 'f') && (*p < 'A' || *p > 'F')) {
  if (t == 1) ZthrowCstringBadValue("hexToInt(): argument does not start with a hex digit");
  return def;
 }
 for (; *p != 0; ++p) {
  if (*p >= '0' && *p <= '9')
   r = r * 16 + (*p - '0');
  else if (*p >= 'a' && *p <= 'f')
   r = r * 16 + (*p - 'a' + 10);
  else if (*p >= 'A' && *p <= 'F')
   r = r * 16 + (*p - 'A' + 10);
  else if (*p != '\'' && *p != '_')
   break;
 }
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

Ti ZstringQuotedToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using quotedToInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrQuotedToInt(s, t, def);
 return r;
}

Ti ZstringQuotedBinToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using quotedBinToInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrQuotedBinToInt(s, t, def);
 return r;
}

Ti ZstringHexToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using hexToInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrHexToInt(s, t, def);
 return r;
}

Ti ZstringQuotedHexToInt(Tc *p, int t, Ti def) {
 Tc *s;
 Ti r;
 if (p == NULL) {
  if (t & 2) return def;
  ZthrowCstringNil("using quotedhexToInt() on NIL");
 }
 (void)ZstringSizePtr(p, &s);
 r = ZptrQuotedHexToInt(s, t, def);
 return r;
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

void *ZarrayPtr(Ta *head, Ti idx) {
 if (head == NULL) ZthrowCstringNil("using [] on NIL array");
 if (idx < 0 || idx >= head->size[0]) ZthrowCstringOutOfRange(idx, "array index out of bounds");
 return head->ptr + idx * head->itemSize;
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

Tl *ZListExtend(Tl *head, Tl *head2) {
 if (head == NULL) ZthrowCstringNil("Attempt to extend NIL list");
 if (head2 == NULL) return head;  /* TODO: throw exception? */
 ZListGrow(head, head2->itemCount);
 ZcopyItems(head->itemType, head->itemSize, head->items, head->empty + head->itemCount, head2->itemType, head2->itemSize, head2->items, head2->empty, head2->itemCount);
 head->itemCount += head2->itemCount;
 return head;
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

Ti ZListRemoveIntItem(Tl *head, Ti idx) {
 Ti r = 0;
 if (head == NULL) ZthrowCstringNil("Invoking remove() on NIL list");
 Ti n = ZListFindIdx(head, idx);
 if (n >= 0) {
  Ti len = head->itemCount - (n - head->empty) - 1;
  switch (head->itemType->nr) {
   case 0:
   case 10:
   case 24:
   case 25:
    r = ((Ti*)head->items)[n]; break;
   case 1:
   case 11:
    r = ((char*)head->items)[n]; break;
   case 12:
   case 2:
    r = ((Ti16*)head->items)[n]; break;
   case 3:
   case 13:
    r = ((Ti32*)head->items)[n]; break;
   case 21:
   case 22:
   case 23:
    r = ((int*)head->items)[n]; break;
  }
  if (len > 0)
   memmove((char*)head->items + n * head->itemSize, (char*)head->items + (n + 1) * head->itemSize, len * head->itemSize);
  head->itemCount--;
  // ZListShrink(head);
 }
 return r;
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

Tl *ZListSlice(Tl *head, Ti i1, Ti i2) {
 Tl *newhead;
 Ti n;
 Ti len;
 Ti ai1;
 Ti ai2;
 if (head == NULL) ZthrowCstringNil("Invoking slice() on NIL list");
 newhead = Za(sizeof(Tl));
 newhead->itemType = head->itemType;
 newhead->itemSize = head->itemSize;
 ai1 = i1 >= 0 ? i1 : head->itemCount + i1;
 ai2 = i2 >= 0 ? i2 : head->itemCount + i2;
 if (ai1 < 0) ai1 = 0;
 if (ai1 < head->itemCount && ai1 <= ai2) {
  if (ai2 >= head->itemCount) ai2 = head->itemCount - 1;
  len = ai2 - ai1 + 1;
  newhead->items = ZaOff(head->itemSize * len);
  newhead->space = len;
  memmove(newhead->items, (char*)head->items + (ai1 + head->empty) * head->itemSize, len * head->itemSize);
  newhead->itemCount = len;
 }
 return newhead;
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

void *ZDictGetPtrDef(Td *d, Tz key, void *def) {
 void *r;
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) r = di->item.ptr;
 else r = def;
 return r;
}

Ti *ZDictGetIntP(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di == NULL) {
  ZDictAdd(1, d, key, (Tz)(Ti)0);
  di = ZDictFind(d, key);
 }
 return &di->item.ival;
}

Ti ZDictGetInt(Td *d, Tz key) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) {
  return di->item.ival;
 }
 if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr(""));
 ZthrowIntKeyNotFound(key, Zstr(""));
 return 0;
}

Ti ZDictGetIntDef(Td *d, Tz key, Ti def) {
 CDictItem *di = ZDictFind(d, key);
 if (di != NULL) return di->item.ival;
 return def;
}

Tb ZDictHas(Td *d, Tz key) {
 return (ZDictFind(d, key) != NULL);
}
Tb ZDictHasIobj(Td *d, Tr key) {
 return (ZDictFind(d, (Tz)(void*)&key) != NULL);
}
void *ZDictRemovePtr(Td *d, Tz key, int remove) {
 CDictItem *di;
 void *r = NULL;
 if (d == NULL) ZthrowCstringNil("Invoking remove() on NIL dict");
 di = ZDictFind(d, key);
 if (di != NULL) {
  r = di->item.ptr;
  di->flags = CDI_FLAG_DEL;
  --d->used;
  ZDictResize(d, 0);
  if (d->type & DTYPE_ORDERED) {
   if (di->lprev) di->lprev->lnext = di->lnext;
   else d->first = di->lnext;
   if (di->lnext) di->lnext->lprev = di->lprev;
   else d->last = di->lprev;
  }
 } else if (remove) {
  if (d->keyType->nr >= 100) ZthrowStringKeyNotFound(key, Zstr("dict.remove(): "));
  ZthrowIntKeyNotFound(key, Zstr("dict.remove(): "));
 }
 if (remove)
   return r;
 return d;
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

void ZforDictGet(Tfd *tfd) {
 Td *d = tfd->d;
 CDictItem *di = tfd->di;
 if (di) {
  if (tfd->keyp) {
   if (d->keyType == &iobj__T)
    *(Tr*)tfd->keyp = di->iokey;
   else if (d->keyType->nr < 80)
    *(Ti*)tfd->keyp = di->key.ival;
   else if (d->keyType->nr < 100)
    *(Tf*)tfd->keyp = di->key.fval;
   else
    *(char**)tfd->keyp = di->key.ptr;
  }
  if (d->itemType == &iobj__T)
   *(Tr*)tfd->valp = di->ioitem;
  else if (d->itemType->nr < 80)
   *(Ti*)tfd->valp = di->item.ival;
  else if (d->itemType->nr < 100)
   *(Tf*)tfd->valp = di->item.fval;
  else
   *(char**)tfd->valp = di->item.ptr;
 }
}

void ZforDictStart(Tfd *tfd) {
 Td *d = tfd->d;
 if (d != NULL && d->used) {
  if (d->type & DTYPE_ORDERED) {
   tfd->di = d->first;
  } else {
   CDictItem *di = d->array;
   while ((di->flags & CDI_FLAG_USED) == 0) ++di;
   tfd->di = di;
   tfd->todo = d->used - 1;
  }
  ZforDictGet(tfd);
 } else {
  tfd->di = NULL;
 }
}

int ZforDictCont(Tfd *tfd) {
 return tfd->di != NULL;
}

void ZforDictNext(Tfd *tfd) {
 Td *d = tfd->d;
 if (d->type & DTYPE_ORDERED) {
  tfd->di = tfd->di->lnext;
 } else if (tfd->todo > 0) {
  CDictItem *di = tfd->di + 1;
  while ((di->flags & CDI_FLAG_USED) == 0) ++di;
  tfd->di = di;
  --tfd->todo;
 } else {
  tfd->di = NULL;
 }
 ZforDictGet(tfd);
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
 Zsf *tf = topFrame;
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
 Zsf *tf = topFrame;
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
/* including TIMEModule bodies */
Ti Y9Rj() {
 Ti Vusec;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vusec = 0;
 sf.pos=5084100;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    Vusec = (Ti)tv.tv_sec * 1000000 + (Ti)tv.tv_usec;
 sf.pos=5084101;
 r = Vusec;
 topFrame = sf.prev;
 return r;
}
Y2KX *YgaY(Y2KX *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=534200; t = Za(sizeof(Y2KX));}
 sf.pos=534201;
 YgaYb(t, Y9Rj());
 topFrame = sf.prev;
 return t;
}
Y2KX *YgaYb(Y2KX *t, Ti Ausec) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3293900; t = Za(sizeof(Y2KX));}
 sf.pos=3293901;
  time_t tt = Ausec / 1000000;
  struct tm tms;
  struct tm *tmsp;
#ifdef __MINGW32__
  tmsp = localtime(&tt);
  if (tmsp) tms = *tmsp;
#else
  localtime_r(&tt, &tms);
#endif
  t->Vsec = tms.tm_sec;
  t->Vmin = tms.tm_min;
  t->Vhour = tms.tm_hour;
  t->Vday = tms.tm_mday;
  t->Vmonth = tms.tm_mon + 1;
  t->Vyear = tms.tm_year + 1900;
  t->VweekDay = tms.tm_wday + 1;
  t->VyearDay = tms.tm_yday + 1;
  if (tms.tm_isdst > 0) t->Vdst = 2;
  else if (tms.tm_isdst == 0) t->Vdst = 1;
 sf.pos=3293902;
 t->Vusec = (Ausec % 1000000);
 topFrame = sf.prev;
 return t;
}
Tc *YYTs(Y2KX *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3481800;
  ZthrowThisNil();
 }
 sf.pos=3481801;
 Vw = Za(sizeof(YjUM));
 sf.pos=3481802;
 YjUM__YHhZb(Vw, t->Vyear);
 sf.pos=3481803;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481804;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmonth));
 sf.pos=3481805;
 YJqza(Vw, ((Tc*)&YV));
 sf.pos=3481806;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vday));
 sf.pos=3481807;
 YJqza(Vw, ((Tc*)&YG));
 sf.pos=3481808;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vhour));
 sf.pos=3481809;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481810;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vmin));
 sf.pos=3481811;
 YJqza(Vw, ((Tc*)&Y5));
 sf.pos=3481812;
 YJqza(Vw, ZintFormat(((Tc*)&Y6O7), t->Vsec));
 sf.pos=3481813;
 r = YbNW(Vw);
 topFrame = sf.prev;
 return r;
}
To ToY2KX[] = {
 {0, 0},
};
Tto Y2KX__T = {390, (Tc*)&YeCO, 0, ToY2KX};
/* TIMEModule done */
/* including EModule bodies */
Ytlm *YRHR(Ytlm *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8303100; t = Za(sizeof(Ytlm));}
 sf.pos=8303101;
 t->Vmessage = Amsg;
 sf.pos=8303102;
 t->Vpos = MZ__callerPos();
 sf.pos=8303103;
 t->Vbacktrace = (sf.pos=8303104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YxaJ(Ytlm *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YxaJa(Ytlm *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *Ytlm__Ytlm_I_imt[] = {
 (Tc*)&Ytlm__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CException.NEW - YRHRa */
 (Tc*)YRHR, /* MEModule__CException.NEW - YRHR */
 (Tc*)0, /* MEModule__CException.ToString - YH0V */
 (Tc*)YxaJa, /* MEModule__CException.writeTo - YxaJa */
 (Tc*)YxaJ, /* MEModule__CException.writeTo - YxaJ */
 (Tc*)0, /* MEModule__CException.toString - Yoww */
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
Tto Ytlm__T = {390, (Tc*)&YDGe, 0, ToYtlm};
void YScq(Ti Apos, Tc *Atext) {
 Tr ex;
 Tr Ve = {NULL};
 Ve = Zao(YRHR(NULL, Atext), Ytlm__Ytlm_I_imt, 0);
 (*(YkxB**)(Ve.ptr + (size_t)Ve.table[2])) = MZ__posnr2pos(NULL, Apos);
 (ex = Ve);
 ZthrowIobject(ex);
}
void YXHSa(YEro *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YEro__YxaJa(YEro *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
To ToYEro[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YEro__T = {390, (Tc*)&YJMo, 0, ToYEro};
YKhn *YDNob(YKhn *t, Ti Asize, Ti Alimit) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8064400; t = Za(sizeof(YKhn));}
 sf.pos=8064401;
 t->Vmessage = ZcS3(((Tc*)&YIBz), Zint2string(Asize), ((Tc*)&YDSH));
 sf.pos=8064402;
 t->Vpos = MZ__callerPos();
 sf.pos=8064403;
 t->Vbacktrace = (sf.pos=8064404, MZ__backtrace(1, Alimit));
 topFrame = sf.prev;
 return t;
}
void YKhn__YwtA__YxaJa(YKhn *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YKhn__YwtA__YxaJ(YKhn *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YKhn__Ytlm_I_imt[] = {
 (Tc*)&YKhn__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHRa */
 (Tc*)0, /* MEModule__COutOfMemory.NEW - YKhn__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfMemory.ToString - YKhn__YwtA__YH0V */
 (Tc*)YKhn__YwtA__YxaJa, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJa */
 (Tc*)YKhn__YwtA__YxaJ, /* MEModule__COutOfMemory.writeTo - YKhn__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfMemory.toString - YKhn__YwtA__Yoww */
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
Tto YKhn__T = {390, (Tc*)&Y9Fv, 0, ToYKhn};
void Y1KV(Ti Asize) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YDNob(NULL, Asize, 30), YKhn__Ytlm_I_imt, 4);
 ZthrowIobject(ex);
}
Y1uN *Y1uN__YwtA__YRHR(Y1uN *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3208600; t = Za(sizeof(Y1uN));}
 sf.pos=3208601;
 t->Vmessage = Amsg;
 sf.pos=3208602;
 t->Vpos = MZ__callerPos();
 sf.pos=3208603;
 t->Vbacktrace = (sf.pos=3208604, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void Y1uN__YwtA__YxaJa(Y1uN *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void Y1uN__YwtA__YxaJ(Y1uN *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *Y1uN__Ytlm_I_imt[] = {
 (Tc*)&Y1uN__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHRa */
 (Tc*)Y1uN__YwtA__YRHR, /* MEModule__CNilAccess.NEW - Y1uN__YwtA__YRHR */
 (Tc*)0, /* MEModule__CNilAccess.ToString - Y1uN__YwtA__YH0V */
 (Tc*)Y1uN__YwtA__YxaJa, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJa */
 (Tc*)Y1uN__YwtA__YxaJ, /* MEModule__CNilAccess.writeTo - Y1uN__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CNilAccess.toString - Y1uN__YwtA__Yoww */
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
Tto Y1uN__T = {390, (Tc*)&Y4wO, 0, ToY1uN};
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
YAxe *YAxe__YwtA__YRHR(YAxe *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7358000; t = Za(sizeof(YAxe));}
 sf.pos=7358001;
 t->Vmessage = Amsg;
 sf.pos=7358002;
 t->Vpos = MZ__callerPos();
 sf.pos=7358003;
 t->Vbacktrace = (sf.pos=7358004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YAxe__YwtA__YxaJa(YAxe *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YAxe__YwtA__YxaJ(YAxe *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YAxe__Ytlm_I_imt[] = {
 (Tc*)&YAxe__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHRa */
 (Tc*)YAxe__YwtA__YRHR, /* MEModule__CMemoryAccess.NEW - YAxe__YwtA__YRHR */
 (Tc*)0, /* MEModule__CMemoryAccess.ToString - YAxe__YwtA__YH0V */
 (Tc*)YAxe__YwtA__YxaJa, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJa */
 (Tc*)YAxe__YwtA__YxaJ, /* MEModule__CMemoryAccess.writeTo - YAxe__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CMemoryAccess.toString - YAxe__YwtA__Yoww */
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
Tto YAxe__T = {390, (Tc*)&Y4QW, 0, ToYAxe};
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
YVNj *YVNj__YwtA__YRHRa(YVNj *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6357800; t = Za(sizeof(YVNj));}
 sf.pos=6357801;
 t->Vmessage = Amsg;
 sf.pos=6357802;
 t->Vpos = Apos;
 sf.pos=6357803;
 t->Vbacktrace = (sf.pos=6357804, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
YVNj *YVNj__YwtA__YRHR(YVNj *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5337700; t = Za(sizeof(YVNj));}
 sf.pos=5337701;
 t->Vmessage = Amsg;
 sf.pos=5337702;
 t->Vpos = MZ__callerPos();
 sf.pos=5337703;
 t->Vbacktrace = (sf.pos=5337704, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YVNj__YwtA__YxaJa(YVNj *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YVNj__YwtA__YxaJ(YVNj *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YVNj__Ytlm_I_imt[] = {
 (Tc*)&YVNj__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YVNj__YwtA__YRHRa, /* MEModule__CInit.NEW - YVNj__YwtA__YRHRa */
 (Tc*)YVNj__YwtA__YRHR, /* MEModule__CInit.NEW - YVNj__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInit.ToString - YVNj__YwtA__YH0V */
 (Tc*)YVNj__YwtA__YxaJa, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJa */
 (Tc*)YVNj__YwtA__YxaJ, /* MEModule__CInit.writeTo - YVNj__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInit.toString - YVNj__YwtA__Yoww */
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
Tto YVNj__T = {390, (Tc*)&Ysqt, 0, ToYVNj};
void Y3w6(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, YVNj__YwtA__YRHR(NULL, Atext), YVNj__Ytlm_I_imt, 7);
 ZthrowIobject(ex);
}
YtEE *YtEE__YwtA__YRHRa(YtEE *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3133200; t = Za(sizeof(YtEE));}
 sf.pos=3133201;
 t->Vmessage = Amsg;
 sf.pos=3133202;
 t->Vpos = Apos;
 sf.pos=3133203;
 t->Vbacktrace = (sf.pos=3133204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YtEE__YwtA__YxaJa(YtEE *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3502900;
  ZthrowThisNil();
 }
 sf.pos=3502901;
 YtEE__YwtA__YxaJ(t, Aw);
 sf.pos=3502902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=3502903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=3502904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3502905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=3502906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=3502907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=3502908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=3502909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=3502910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=3502911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=3502912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
void YtEE__YwtA__YxaJ(YtEE *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4523000;
  ZthrowThisNil();
 }
 sf.pos=4523001;
 if ((t->Vpos != NULL))
 {
  sf.pos=4523002;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=4523003;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=4523004;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=4523005;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=4523006;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=4523007;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
Tc *YtEE__Ytlm_I_imt[] = {
 (Tc*)&YtEE__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YtEE__YwtA__YRHRa, /* MEModule__CCheck.NEW - YtEE__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CCheck.NEW - YtEE__YwtA__YRHR */
 (Tc*)0, /* MEModule__CCheck.ToString - YtEE__YwtA__YH0V */
 (Tc*)YtEE__YwtA__YxaJa, /* MEModule__CCheck.writeTo - YtEE__YwtA__YxaJa */
 (Tc*)YtEE__YwtA__YxaJ, /* MEModule__CCheck.writeTo - YtEE__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CCheck.toString - YtEE__YwtA__Yoww */
 (Tc*)0, /* MEModule__CCheck.getMessage - YtEE__YwtA__YCzX */
 (Tc*)0, /* MEModule__CCheck.getPos - YtEE__YwtA__YvCK */
 (Tc*)0, /* MEModule__CCheck.getBacktrace - YtEE__YwtA__Y4bq */
 (Tc*)0, /* Init - YtEEa */
};
To ToYtEE[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YtEE__T = {390, (Tc*)&YvUM, 0, ToYtEE};
Yalz *Yalz__YwtA__YRHR(Yalz *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6059300; t = Za(sizeof(Yalz));}
 sf.pos=6059301;
 t->Vmessage = Amsg;
 sf.pos=6059302;
 t->Vpos = MZ__callerPos();
 sf.pos=6059303;
 t->Vbacktrace = (sf.pos=6059304, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void Yalz__YwtA__YxaJa(Yalz *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void Yalz__YwtA__YxaJ(Yalz *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *Yalz__Ytlm_I_imt[] = {
 (Tc*)&Yalz__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHRa */
 (Tc*)Yalz__YwtA__YRHR, /* MEModule__CBadValue.NEW - Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CBadValue.ToString - Yalz__YwtA__YH0V */
 (Tc*)Yalz__YwtA__YxaJa, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJa */
 (Tc*)Yalz__YwtA__YxaJ, /* MEModule__CBadValue.writeTo - Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CBadValue.toString - Yalz__YwtA__Yoww */
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
Tto Yalz__T = {390, (Tc*)&YEZq, 0, ToYalz};
void Yaez(Tc *Atext) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yalz__YwtA__YRHR(NULL, Atext), Yalz__Ytlm_I_imt, 10);
 ZthrowIobject(ex);
}
Yw3O *Yw3O__Yalz__YwtA__YRHRa(Yw3O *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6658200; t = Za(sizeof(Yw3O));}
 sf.pos=6658201;
 t->Vmessage = Amsg;
 sf.pos=6658202;
 t->Vpos = Apos;
 sf.pos=6658203;
 t->Vbacktrace = (sf.pos=6658204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
Yw3O *Yw3O__Yalz__YwtA__YRHR(Yw3O *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5638100; t = Za(sizeof(Yw3O));}
 sf.pos=5638101;
 t->Vmessage = Amsg;
 sf.pos=5638102;
 t->Vpos = MZ__callerPos();
 sf.pos=5638103;
 t->Vbacktrace = (sf.pos=5638104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void Yw3O__Yalz__YwtA__YxaJ(Yw3O *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void Yw3O__Yalz__YwtA__YxaJa(Yw3O *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *Yw3O__Ytlm_I_imt[] = {
 (Tc*)&Yw3O__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)Yw3O__Yalz__YwtA__YRHRa, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHRa */
 (Tc*)Yw3O__Yalz__YwtA__YRHR, /* MEModule__COutOfRange.NEW - Yw3O__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__COutOfRange.ToString - Yw3O__Yalz__YwtA__YH0V */
 (Tc*)Yw3O__Yalz__YwtA__YxaJa, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJa */
 (Tc*)Yw3O__Yalz__YwtA__YxaJ, /* MEModule__COutOfRange.writeTo - Yw3O__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__COutOfRange.toString - Yw3O__Yalz__YwtA__Yoww */
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
Tto Yw3O__T = {390, (Tc*)&YFK2, 0, ToYw3O};
void Y6NT(Ti Aindex, Tc *Amsg) {
 Tr ex;
 Tr t0 = {NULL};
 *Znao(&ex, Yw3O__Yalz__YwtA__YRHR(NULL, ZcS3(Amsg, ((Tc*)&YFDa), Zint2string(Aindex))), Yw3O__Ytlm_I_imt, 11);
 ZthrowIobject(ex);
}
Y2EX *Y2EX__Yalz__YwtA__YRHR(Y2EX *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2958500; t = Za(sizeof(Y2EX));}
 sf.pos=2958501;
 t->Vmessage = Amsg;
 sf.pos=2958502;
 t->Vpos = MZ__callerPos();
 sf.pos=2958503;
 t->Vbacktrace = (sf.pos=2958504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void Y2EX__Yalz__YwtA__YxaJ(Y2EX *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void Y2EX__Yalz__YwtA__YxaJa(Y2EX *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *Y2EX__Ytlm_I_imt[] = {
 (Tc*)&Y2EX__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHRa */
 (Tc*)Y2EX__Yalz__YwtA__YRHR, /* MEModule__CKeyNotFound.NEW - Y2EX__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyNotFound.ToString - Y2EX__Yalz__YwtA__YH0V */
 (Tc*)Y2EX__Yalz__YwtA__YxaJa, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJa */
 (Tc*)Y2EX__Yalz__YwtA__YxaJ, /* MEModule__CKeyNotFound.writeTo - Y2EX__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyNotFound.toString - Y2EX__Yalz__YwtA__Yoww */
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
Tto Y2EX__T = {390, (Tc*)&YRiW, 0, ToY2EX};
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
YX0i *YX0i__Yalz__YwtA__YRHRa(YX0i *t, YkxB *Apos, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9520100; t = Za(sizeof(YX0i));}
 sf.pos=9520101;
 t->Vmessage = Amsg;
 sf.pos=9520102;
 t->Vpos = Apos;
 sf.pos=9520103;
 t->Vbacktrace = (sf.pos=9520104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
YX0i *YX0i__Yalz__YwtA__YRHR(YX0i *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8500000; t = Za(sizeof(YX0i));}
 sf.pos=8500001;
 t->Vmessage = Amsg;
 sf.pos=8500002;
 t->Vpos = MZ__callerPos();
 sf.pos=8500003;
 t->Vbacktrace = (sf.pos=8500004, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YX0i__Yalz__YwtA__YxaJ(YX0i *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YX0i__Yalz__YwtA__YxaJa(YX0i *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YX0i__Ytlm_I_imt[] = {
 (Tc*)&YX0i__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)YX0i__Yalz__YwtA__YRHRa, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHRa */
 (Tc*)YX0i__Yalz__YwtA__YRHR, /* MEModule__CKeyExists.NEW - YX0i__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CKeyExists.ToString - YX0i__Yalz__YwtA__YH0V */
 (Tc*)YX0i__Yalz__YwtA__YxaJa, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJa */
 (Tc*)YX0i__Yalz__YwtA__YxaJ, /* MEModule__CKeyExists.writeTo - YX0i__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CKeyExists.toString - YX0i__Yalz__YwtA__Yoww */
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
Tto YX0i__T = {390, (Tc*)&Y9_h, 0, ToYX0i};
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
YP_P *YP_P__Yalz__YwtA__YRHR(YP_P *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4520900; t = Za(sizeof(YP_P));}
 sf.pos=4520901;
 t->Vmessage = Amsg;
 sf.pos=4520902;
 t->Vpos = MZ__callerPos();
 sf.pos=4520903;
 t->Vbacktrace = (sf.pos=4520904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YP_P__Yalz__YwtA__YxaJ(YP_P *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=994800;
  ZthrowThisNil();
 }
 sf.pos=994801;
 if ((t->Vpos != NULL))
 {
  sf.pos=994802;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(t->Vpos));
  sf.pos=994803;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
 }
 sf.pos=994804;
 if (((t->Vmessage != NULL) && (ZbyteStringSize(t->Vmessage) != 0)))
 {
  sf.pos=994805;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YHbP));
  sf.pos=994806;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, t->Vmessage);
 }
 else
 {
  sf.pos=994807;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YDGe));
 }
 topFrame = sf.prev;
 return;
}
void YP_P__Yalz__YwtA__YxaJa(YP_P *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2014900;
  ZthrowThisNil();
 }
 sf.pos=2014901;
 YP_P__Yalz__YwtA__YxaJ(t, Aw);
 sf.pos=2014902;
 if ((Averbose && (t->Vbacktrace != NULL)))
 {
  sf.pos=2014903;
  ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Y62e));
  sf.pos=2014904;
  {
   Tfl Zf2i;
   Zf2 = t->Vbacktrace;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vpos;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=2014905;
   if ((Vpos->Vfilename == NULL))
   {
    sf.pos=2014906;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yv6_));
   }
   else
   {
    sf.pos=2014907;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&Yk));
    sf.pos=2014908;
    ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, YpI_(Vpos));
    sf.pos=2014909;
    if ((Vpos->Vtext != NULL))
    {
     sf.pos=2014910;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, ((Tc*)&YFDa));
     sf.pos=2014911;
     ((Ts (*)(void*, Tc*))(Aw.table[1]))(Aw.ptr, Vpos->Vtext);
    }
   }
   sf.pos=2014912;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YP_P__Ytlm_I_imt[] = {
 (Tc*)&YP_P__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHRa */
 (Tc*)YP_P__Yalz__YwtA__YRHR, /* MEModule__CIllegalByte.NEW - YP_P__Yalz__YwtA__YRHR */
 (Tc*)0, /* MEModule__CIllegalByte.ToString - YP_P__Yalz__YwtA__YH0V */
 (Tc*)YP_P__Yalz__YwtA__YxaJa, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJa */
 (Tc*)YP_P__Yalz__YwtA__YxaJ, /* MEModule__CIllegalByte.writeTo - YP_P__Yalz__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CIllegalByte.toString - YP_P__Yalz__YwtA__Yoww */
 (Tc*)0, /* MEModule__CIllegalByte.getMessage - YP_P__Yalz__YwtA__YCzX */
 (Tc*)0, /* MEModule__CIllegalByte.getPos - YP_P__Yalz__YwtA__YvCK */
 (Tc*)0, /* MEModule__CIllegalByte.getBacktrace - YP_P__Yalz__YwtA__Y4bq */
 (Tc*)0, /* Init - YP_Pa */
};
To ToYP_P[] = {
 {3, 0},
 {0, (Tt*)&string__T}, /* message */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* backtrace */
};
Tto YP_P__T = {390, (Tc*)&Ydbm, 0, ToYP_P};
YzSI *YzSI__Ylz1__YwtA__YRHR(YzSI *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7347100; t = Za(sizeof(YzSI));}
 sf.pos=7347101;
 t->Vmessage = Amsg;
 sf.pos=7347102;
 t->Vpos = MZ__callerPos();
 sf.pos=7347103;
 t->Vbacktrace = (sf.pos=7347104, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YzSI__Ylz1__YwtA__YxaJ(YzSI *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YzSI__Ylz1__YwtA__YxaJa(YzSI *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YzSI__Ytlm_I_imt[] = {
 (Tc*)&YzSI__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHRa */
 (Tc*)YzSI__Ylz1__YwtA__YRHR, /* MEModule__CDivideByZero.NEW - YzSI__Ylz1__YwtA__YRHR */
 (Tc*)0, /* MEModule__CDivideByZero.ToString - YzSI__Ylz1__YwtA__YH0V */
 (Tc*)YzSI__Ylz1__YwtA__YxaJa, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJa */
 (Tc*)YzSI__Ylz1__YwtA__YxaJ, /* MEModule__CDivideByZero.writeTo - YzSI__Ylz1__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CDivideByZero.toString - YzSI__Ylz1__YwtA__Yoww */
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
Tto YzSI__T = {390, (Tc*)&YxFl, 0, ToYzSI};
YXKl *YXKl__YwtA__YRHR(YXKl *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4829900; t = Za(sizeof(YXKl));}
 sf.pos=4829901;
 t->Vmessage = Amsg;
 sf.pos=4829902;
 t->Vpos = MZ__callerPos();
 sf.pos=4829903;
 t->Vbacktrace = (sf.pos=4829904, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YXKl__YwtA__YxaJa(YXKl *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YXKl__YwtA__YxaJ(YXKl *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YXKl__Ytlm_I_imt[] = {
 (Tc*)&YXKl__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHRa */
 (Tc*)YXKl__YwtA__YRHR, /* MEModule__CIOError.NEW - YXKl__YwtA__YRHR */
 (Tc*)0, /* MEModule__CIOError.ToString - YXKl__YwtA__YH0V */
 (Tc*)YXKl__YwtA__YxaJa, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJa */
 (Tc*)YXKl__YwtA__YxaJ, /* MEModule__CIOError.writeTo - YXKl__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CIOError.toString - YXKl__YwtA__Yoww */
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
Tto YXKl__T = {390, (Tc*)&YTj3, 0, ToYXKl};
YuDC *YdhH(YuDC *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8723500; t = Za(sizeof(YuDC));}
 sf.pos=8723501;
 t->Vmessage = ((Tc*)&Ynjz);
 sf.pos=8723502;
 t->Vpos = MZ__callerPos();
 sf.pos=8723503;
 t->Vbacktrace = (sf.pos=8723504, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YuDC__YwtA__YxaJa(YuDC *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YuDC__YwtA__YxaJ(YuDC *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YuDC__Ytlm_I_imt[] = {
 (Tc*)&YuDC__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHRa */
 (Tc*)0, /* MEModule__CWrongType.NEW - YuDC__YwtA__YRHR */
 (Tc*)0, /* MEModule__CWrongType.ToString - YuDC__YwtA__YH0V */
 (Tc*)YuDC__YwtA__YxaJa, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJa */
 (Tc*)YuDC__YwtA__YxaJ, /* MEModule__CWrongType.writeTo - YuDC__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CWrongType.toString - YuDC__YwtA__Yoww */
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
Tto YuDC__T = {390, (Tc*)&YCoZ, 0, ToYuDC};
void YTuG(Ti Apos) {
 Tr ex;
 YuDC *Ve = 0;
 Tr t0 = {NULL};
 Ve = YdhH(NULL);
 Ve->Vpos = MZ__posnr2pos(NULL, Apos);
 *Znao(&ex, Ve, YuDC__Ytlm_I_imt, 24);
 ZthrowIobject(ex);
}
YrHq *YrHq__YwtA__YRHR(YrHq *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7808200; t = Za(sizeof(YrHq));}
 sf.pos=7808201;
 t->Vmessage = Amsg;
 sf.pos=7808202;
 t->Vpos = MZ__callerPos();
 sf.pos=7808203;
 t->Vbacktrace = (sf.pos=7808204, MZ__backtrace(1, -1));
 topFrame = sf.prev;
 return t;
}
void YrHq__YwtA__YxaJa(YrHq *t, Tb Averbose, Tr Aw) {
 Zsf sf;
 Tl *Zf2 = NULL;
 YkxB *Vpos = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
void YrHq__YwtA__YxaJ(YrHq *t, Tr Aw) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YrHq__Ytlm_I_imt[] = {
 (Tc*)&YrHq__T,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0,
 (Tc*)0, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHRa */
 (Tc*)YrHq__YwtA__YRHR, /* MEModule__CInternal.NEW - YrHq__YwtA__YRHR */
 (Tc*)0, /* MEModule__CInternal.ToString - YrHq__YwtA__YH0V */
 (Tc*)YrHq__YwtA__YxaJa, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJa */
 (Tc*)YrHq__YwtA__YxaJ, /* MEModule__CInternal.writeTo - YrHq__YwtA__YxaJ */
 (Tc*)0, /* MEModule__CInternal.toString - YrHq__YwtA__Yoww */
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
Tto YrHq__T = {390, (Tc*)&YVki, 0, ToYrHq};
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
void YvL0(Tr Ae) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5238600;
 Ylxt();
 sf.pos=5238601;
 YQar(Ae, 1, YeNQ);
 sf.pos=5238618;
 ((Ts (*)(void*))(YeNQ.table[18]))(YeNQ.ptr);
 topFrame = sf.prev;
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
   YtEE__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238608)); return;
  case 9:
   return;
  case 10:
   Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238609)); return;
  case 11:
   Yw3O__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238610)); return;
  case 12:
   Y2EX__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238611)); return;
  case 13:
   return;
  case 14:
   YX0i__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238612)); return;
  case 15:
   YP_P__Yalz__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238613)); return;
  case 16:
   return;
  case 17:
   YzSI__Ylz1__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238614)); return;
  case 18:
   return;
  case 19:
   YXKl__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238615)); return;
  case 20:
   return;
  case 21:
   return;
  case 22:
   return;
  case 23:
   return;
  case 24:
   YuDC__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238616)); return;
  case 25:
   return;
  case 26:
   YrHq__YwtA__YxaJa(A0.ptr,A1,ZconvertZioref(A2, YdXi__imtt, 0, 99999, 5238617)); return;
  case 27:
   return;
  case 28:
   return;
  case 29:
   return;
  case 30:
   return;
  case 31:
   return;
 }
 ZthrowCstringBadValue("writeTo: cannot select method to invoke");
 return;
}
/* EModule done */
/* including ZModule bodies */
YkxB *Ypp_(YkxB *t, Tc *Afilename) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = 1;
 t->Vcol = 1;
 return t;
}
YkxB *Ypp_a(YkxB *t, Tc *Afilename, Ti Alnum, Ti Acol) {
 if (t == NULL) {t = Za(sizeof(YkxB));}
 t->Vfilename = Afilename;
 t->Vlnum = Alnum;
 t->Vcol = Acol;
 return t;
}
YkxB *Y83A(YkxB *t) {
 Zsf sf;
 YkxB *r = 0;
 YkxB *Vp = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1602000;
  ZthrowThisNil();
 }
 sf.pos=1602001;
 Vp = Ypp_(NULL, t->Vfilename);
 sf.pos=1602002;
 Vp->Vlnum = t->Vlnum;
 sf.pos=1602003;
 Vp->Vcol = t->Vcol;
 sf.pos=1602004;
 Vp->Vtext = t->Vtext;
 sf.pos=1602005;
 r = Vp;
 topFrame = sf.prev;
 return r;
}
void YnS4(YkxB *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4686800;
  ZthrowThisNil();
 }
 sf.pos=4686801;
 ++(t->Vlnum);
 sf.pos=4686802;
 t->Vcol = 1;
 topFrame = sf.prev;
 return;
}
void Y7Yp(YkxB *t, Tc *As) {
 Ti Vidx;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8677500;
  ZthrowThisNil();
 }
 Vidx = 0;
 sf.pos=8677501;
 while (1)
 {
  Ti Vi;
  sf.pos=8677502;
  Vi = ZstringFindChar2(As, 10, Vidx, 0);
  sf.pos=8677503;
  if ((Vi < 0))
  {
   rt = 2;
   goto YqjL;
  }
  sf.pos=8677504;
  t->Vcol = 1;
  sf.pos=8677505;
  ++(t->Vlnum);
  sf.pos=8677506;
  Vidx = (Vi + 1);
YqjL:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=8677507;
 }
 sf.pos=8677508;
 t->Vcol += ZstringSize(ZstringSlice(As, Vidx, -1, 0));
 topFrame = sf.prev;
 return;
}
Tc *YpI_(YkxB *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vw = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
To ToYkxB[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* filename */
 {0, (Tt*)&string__T}, /* text */
};
Tto YkxB__T = {390, (Tc*)&YBCs, 0, ToYkxB};
/* ZModule done */
/* including IOModule bodies */
Tr Yd89() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdin;
 r = Vfile;
 return r;
}
Tr Yvyt() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = stdout;
 r = Vfile;
 return r;
}
Tr YsM3() {
 Tr r = {NULL};
 Tr Vfile = {NULL};
 Vfile = Zao(Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
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
Ti YFeQ(Yw8L *t) {
 Ti Vb;
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1605300;
  ZthrowThisNil();
 }
 sf.pos=1605301;
 if ((t->Vfd == NULL))
 {
  Tr ex;
  sf.pos=1605302;
  *Znao(&ex, YXKl__YwtA__YRHR(NULL, ((Tc*)&YQe8)), YXKl__Ytlm_I_imt, 19);
  ZthrowIobject(ex);
 }
 Vb = 0;
 sf.pos=1605303;
 Vb = fgetc(t->Vfd);
 sf.pos=1605304;
 r = Vb;
 topFrame = sf.prev;
 return r;
}
Ti YAPp(Yw8L *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4663100;
  ZthrowThisNil();
 }
 sf.pos=4663101;
 Vc = YFeQ(t);
 sf.pos=4663102;
 if (((Vc != Y3QJ) && (Vc >= 128)))
 {
  Ti Vlen;
  Vlen = 0;
  sf.pos=4663103;
  if ((((Vc & 224)) == 192))
  {
   sf.pos=4663104;
   Vlen = 2;
   sf.pos=4663105;
   Vc = (Vc & 31);
  }
  else {
  sf.pos=4663106;
 if ((((Vc & 240)) == 224))
  {
   sf.pos=4663107;
   Vlen = 3;
   sf.pos=4663108;
   Vc = (Vc & 15);
  }
  else {
  sf.pos=4663109;
 if ((((Vc & 248)) == 240))
  {
   sf.pos=4663110;
   Vlen = 4;
   sf.pos=4663111;
   Vc = (Vc & 7);
  }
  else
  {
   Tr ex;
   sf.pos=4663112;
   *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YPHa), Zint2string(Vc))), YP_P__Ytlm_I_imt, 15);
   ZthrowIobject(ex);
  }
  }}
  sf.pos=4663113;
  {
   Ti Vnr;
   Tfr Zf2;
   ZforRangeNew(2, Vlen, 0, 1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vnr); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vnr)) {
   Ti Vc2;
   sf.pos=4663114;
   Vc2 = YFeQ(t);
   sf.pos=4663115;
   if ((Vc2 == Y3QJ))
   {
    Tr ex;
    sf.pos=4663116;
    *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS(((Tc*)&YKzT), Zint2string(Vnr))), YP_P__Ytlm_I_imt, 15);
    ZthrowIobject(ex);
   }
   else {
   sf.pos=4663117;
 if ((((Vc2 & 192)) != 128))
   {
    Tr ex;
    sf.pos=4663118;
    *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ZcS3(((Tc*)&Ymwv), Zint2string(Vnr), ((Tc*)&YPfW))), YP_P__Ytlm_I_imt, 15);
    ZthrowIobject(ex);
   }
   }
   sf.pos=4663119;
   Vc = (((Vc << 6)) + ((Vc2 & 63)));
   sf.pos=4663120;
   }
  }
  sf.pos=4663121;
  switch (Vlen)
  {
  case 2:
   {
    sf.pos=4663122;
    if ((Vc <= 127))
    {
     Tr ex;
     sf.pos=4663123;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  case 3:
   {
    sf.pos=4663124;
    if ((Vc <= 2047))
    {
     Tr ex;
     sf.pos=4663125;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  case 4:
   {
    sf.pos=4663126;
    if ((Vc <= 65535))
    {
     Tr ex;
     sf.pos=4663127;
     *Znao(&ex, YP_P__Yalz__YwtA__YRHR(NULL, ((Tc*)&Y8Gn)), YP_P__Ytlm_I_imt, 15);
     ZthrowIobject(ex);
    }
     break;
   }
  }
 }
 sf.pos=4663128;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
Ts YwHoa(Yw8L *t, Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts YGmp(Yw8L *t) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6056700;
  ZthrowThisNil();
 }
 sf.pos=6056701;
 Vret = 0;
 sf.pos=6056702;
 if ((t->Vfd != NULL))
 {
  sf.pos=6056703;
 if (fflush(t->Vfd) == 0)
  Vret = 1;
 else
  Vret = 0;
 }
 sf.pos=6056704;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YrF8(Yw8L *t) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YHhZb(Yw8L *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5981900;
  ZthrowThisNil();
 }
 sf.pos=5981901;
 r = YwHoa(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7(Yw8L *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts Yw8L__YRt7g(Yw8L *t) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8261800;
  ZthrowThisNil();
 }
 sf.pos=8261801;
 r = YwHoa(t, ((Tc*)&Yk));
 topFrame = sf.prev;
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
 (Tc*)YFeQ, /* MIOModule__CFile.readByte - YFeQ */
 (Tc*)YAPp, /* MIOModule__CFile.readChar - YAPp */
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
 (Tc*)YGmp, /* MIOModule__CFile.flush - YGmp */
 (Tc*)YrF8, /* MIOModule__CFile.close - YrF8 */
 (Tc*)0, /* MIOModule__CFile.Finish - YSo_ */
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
Tto Yw8L__T = {390, (Tc*)&YtTU, 0, ToYw8L};
Tr YsGz(Tc *AfileName) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9983800;
 {
  int fnr = open(ZgetCstring(AfileName), O_RDONLY);
  if (fnr >= 0) {
 sf.pos=9983801;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=9983802;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "r");
  }
 }
 sf.pos=9983803;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Tr YiBk(Tc *AfileName, Tb Atruncate) {
 Zsf sf;
 Tr r = {NULL};
 Tr Vfile = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8158000;
 {
  int flags = O_WRONLY|O_CREAT;
  if (Atruncate) flags |= O_TRUNC;
  int fnr = open(ZgetCstring(AfileName), flags, 0666);
  if (fnr >= 0) {
   if (!Atruncate) lseek(fnr, 0, SEEK_END);
 sf.pos=8158001;
 Vfile = *Znao(&Vfile, Za(sizeof(Yw8L)), Yw8L__Yw8L_I_imt, 0);
 sf.pos=8158002;
   (*(FILE **)(Vfile.ptr + (size_t)Vfile.table[20])) = fdopen(fnr, "w");
  }
 }
 sf.pos=8158003;
 r = Vfile;
 topFrame = sf.prev;
 return r;
}
Ts Yvcu(Tc *Atext) {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts Yl0k(Tc *Atext) {
 Ts Vret;
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts Ylxt() {
 Ts Vret;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vret = 0;
 sf.pos=4676100;
 if (fflush(stdout) == 0)
  Vret = 1;
 else
  Vret = 0;
 sf.pos=4676101;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Ts YJqza(YjUM *t, Tc *Atext) {
 Ti Vlen;
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts Ye7fa(YjUM *t, Ti Abyte) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3855200;
  ZthrowThisNil();
 }
 sf.pos=3855201;
 if ((t->Vs == NULL))
 {
  sf.pos=3855202;
  t->Vs = ZnewArray((Tt*)&byte__T, sizeof(Tc), 30);
 }
 else {
 sf.pos=3855203;
 if (((t->VsLen + 2) >= ZArraySize(t->Vs)))
 {
  sf.pos=3855204;
  ZarrayResize(t->Vs, sizeof(Tc), ((ZArraySize(t->Vs) + (ZArraySize(t->Vs) / 8)) + 50)) ;
 }
 }
 sf.pos=3855205;
 (*(Tc*)ZarrayPtr(t->Vs, (t->VsLen)++)) = Abyte;
 sf.pos=3855206;
 (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
 sf.pos=3855207;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Ti YKJQ(YjUM *t) {
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3432400;
  ZthrowThisNil();
 }
 sf.pos=3432401;
 if ((t->VsLen == 0))
 {
  sf.pos=3432402;
  r = 0;
  rt = 1;
  goto Yx8n;
 }
 sf.pos=3432403;
 r = ZstringSize(YbNW(t));
Yx8n:
 topFrame = sf.prev;
 return r;
}
Tc *YbNW(YjUM *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vr = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ti Y6jW(YjUM *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5897500;
  ZthrowThisNil();
 }
 sf.pos=5897501;
 if ((t->VsLen == 0))
 {
  sf.pos=5897502;
  r = Y3QJ;
  rt = 1;
  goto Ykjg;
 }
 Vc = 0;
 sf.pos=5897503;
 Vc = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
 sf.pos=5897504;
 (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
 sf.pos=5897505;
 if (((((Vc & 192)) == 128) && (t->VsLen > 0)))
 {
  Ti Vc2;
  sf.pos=5897506;
  Vc2 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
  sf.pos=5897507;
  (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
  sf.pos=5897508;
  if (((((Vc2 & 192)) == 128) && (t->VsLen > 0)))
  {
   Ti Vc3;
   sf.pos=5897509;
   Vc3 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
   sf.pos=5897510;
   (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
   sf.pos=5897511;
   if (((((Vc3 & 192)) == 128) && (t->VsLen > 0)))
   {
    Ti Vc4;
    sf.pos=5897512;
    Vc4 = (*(Tc*)ZarrayPtr(t->Vs, --(t->VsLen)));
    sf.pos=5897513;
    (*(Tc*)ZarrayPtr(t->Vs, t->VsLen)) = 0;
    sf.pos=5897514;
    Vc = (((((((Vc4 & 7)) << 18)) + ((((Vc3 & 63)) << 12))) + ((((Vc2 & 63)) << 6))) + ((Vc & 63)));
   }
   else
   {
    sf.pos=5897515;
    Vc = ((((((Vc3 & 15)) << 12)) + ((((Vc2 & 63)) << 6))) + ((Vc & 63)));
   }
  }
  else
  {
   sf.pos=5897516;
   Vc = (((((Vc2 & 31)) << 6)) + ((Vc & 63)));
  }
 }
 sf.pos=5897517;
 r = Vc;
Ykjg:
 topFrame = sf.prev;
 return r;
}
void Y3_a(YjUM *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8344300;
  ZthrowThisNil();
 }
 sf.pos=8344301;
 t->VsLen = 0;
 topFrame = sf.prev;
 return;
}
Ts YjUM__YHhZb(YjUM *t, Ti Anumber) {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7200700;
  ZthrowThisNil();
 }
 sf.pos=7200701;
 r = YJqza(t, Zint2string(Anumber));
 topFrame = sf.prev;
 return r;
}
Ts YjUM__Ydti(YjUM *t, Ti Achar) {
 Zsf sf;
 Ts r = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Ts YjUM__YRt7(YjUM *t, Tc *Atext) {
 Zsf sf;
 Ts r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
Tc *YjUM__YdXi_imt[] = {
 (Tc*)&YjUM__T,
 (Tc*)YJqza, /* MIOModule__CStringWriter.write - YJqza */
 (Tc*)YjUM__YRt7, /* MIOModule__CStringWriter.print - YjUM__YRt7 */
};
To ToYjUM[] = {
 {2, 0},
 {0, (Tt*)&array__T}, /* s */
 {0, (Tt*)&string__T}, /* x */
};
Tto YjUM__T = {390, (Tc*)&YE4c, 0, ToYjUM};
To ToYPto[] = {
 {0, 0},
};
Tto YPto__T = {390, (Tc*)&Y68E, 0, ToYPto};
YPto *YPwr(Tc *Aname) {
 Zsf sf;
 YPto *r = 0;
 YPto *Vst = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4348300;
 Vst = Za(sizeof(YPto));
 sf.pos=4348301;
 {
  struct stat st;
  if (stat(ZgetCstring(Aname), &st) == 0) {
   Vst->Vsize = st.st_size;
   Vst->Vtime = st.st_mtime * 1000000LL;
   Vst->Vstatus = 1;
   Vst->VisDir = S_ISDIR(st.st_mode);
  }
 }
 sf.pos=4348302;
 r = Vst;
 topFrame = sf.prev;
 return r;
}
int JIOModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
   sf.pos=745200;
   Y59X = Yd89();
   sf.pos=745201;
   Yb0q = Yvyt();
   sf.pos=745202;
   YeNQ = YsM3();
  }
  topFrame = sf.prev;
 }
 return done;
}
/* IOModule done */
/* including LOGModule bodies */
void YDY4(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(2, Amsg, Apos, Aflags);
 return;
}
void YDli(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(5, Amsg, Apos, Aflags);
 return;
}
void Y2oO(Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 Ygkj(5, Amsg, Apos, (Aflags + 2));
 return;
}
void Ygkj(Te Alevel, Tc *Amsg, YkxB *Apos, Tbs Aflags) {
 YjUM *Vw = 0;
 Tc *VwholeMsg = NULL;
 Y2KX *Vtv = 0;
 Tr t0 = {NULL};
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 int rt = 0;
 if ((((((Alevel == 0) && !(YuOS(YU8T)))) || (((Alevel == 1) && (Y86c__Ye9f(YlUb) < 2)))) || (((Alevel == 2) && (Y86c__Ye9f(YlUb) < 1)))))
 {
  rt = 1;
  goto YbRZ;
 }
 ++(*ZDictGetIntP(Ytd2, (Tz)(Ti)Alevel));
 Vw = Za(sizeof(YjUM));
 if ((Apos != NULL))
 {
  YJqza(Vw, YpI_(Apos));
  YJqza(Vw, ((Tc*)&YFDa));
 }
 if ((((Aflags) & 2) >> 1))
 {
  YJqza(Vw, ((Tc*)&YJ5p));
 }
 switch (Alevel)
 {
 case 4:
  {
   YJqza(Vw, ((Tc*)&Yyq1));
    break;
  }
 case 5:
  {
   YJqza(Vw, ((Tc*)&Y27a));
    break;
  }
 case 6:
  {
   YJqza(Vw, ((Tc*)&Y3l3));
    break;
  }
 case 7:
  {
   YJqza(Vw, ((Tc*)&YmM8));
    break;
  }
 }
 YJqza(Vw, YmaW);
 YJqza(Vw, Amsg);
 if ((((Aflags) & 1)))
 {
  YwlF(*Znao(&t0, Vw, YjUM__YdXi_imt, 2));
 }
 if (!((((Aflags) & 4) >> 2)))
 {
  YJqza(Vw, ((Tc*)&Yk));
 }
 VwholeMsg = YbNW(Vw);
 Yvcu(VwholeMsg);
 if ((((Yz2b).ptr) != NULL))
 {
  if (YiAD)
  {
   Vtv = YgaY(NULL);
   ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, ZcS5(YYTs(Vtv), ((Tc*)&YU), (t1 = ZintFormat(((Tc*)&YwV7), Vtv->Vusec)), ((Tc*)&YG), (Tc*)1));
  }
  ((Ts (*)(void*, Tc*))(Yz2b.table[1]))(Yz2b.ptr, VwholeMsg);
 }
 if ((Alevel >= 5))
 {
  ++(Yrpn);
  Y7LJ();
 }
 else {
 if (((Y9Rj() - YvW3) > YOwl))
 {
  Y7LJ();
 }
 }
 if ((Alevel == 7))
 {
  Zexit(NULL, 10);
 }
YbRZ:
 return;
}
void YwlF(Tr Aout) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YkxB *Vp = 0;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8489900;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&Ya));
 sf.pos=8489901;
 ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ((Tc*)&YDzC));
 sf.pos=8489903;
 {
  Tfl Zf1i;
  Zf1 = (sf.pos=8489904, MZ__backtrace(0, -1));
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vp;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8489905;
  ((Ts (*)(void*, Tc*))(Aout.table[2]))(Aout.ptr, ZcS3(YpI_(Vp), ((Tc*)&YFDa), (t0 = Vp->Vtext)));
  sf.pos=8489906;
  }
 }
 topFrame = sf.prev;
 return;
}
void Y7LJ() {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5655500;
 Ylxt();
 sf.pos=5655501;
 if ((((Yz2b).ptr) != NULL))
 {
  sf.pos=5655502;
  ((Ts (*)(void*))(Yz2b.table[34]))(Yz2b.ptr);
 }
 sf.pos=5655503;
 YvW3 = Y9Rj();
 topFrame = sf.prev;
 return;
}
int JLOGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 0) {
   sf.pos=8332600;
   YU8T = YttT(NULL, ((Tc*)&YLa), ((Tc*)&YGwH), 0, ((Tc*)&YhpM));
   sf.pos=8332601;
   YlUb = YttT(NULL, ((Tc*)&Y2a), ((Tc*)&YUsn), 0, ((Tc*)&YSuP));
  }
  if (round == 0) {
   sf.pos=8332602;
   Ytd2 = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MLOGModule__ELevel__T, (Tt*)&int__T, 0), (Tz)(Ti)0, (Tz)(Ti)0), (Tz)(Ti)1, (Tz)(Ti)0), (Tz)(Ti)2, (Tz)(Ti)0), (Tz)(Ti)3, (Tz)(Ti)0), (Tz)(Ti)4, (Tz)(Ti)0), (Tz)(Ti)5, (Tz)(Ti)0), (Tz)(Ti)6, (Tz)(Ti)0), (Tz)(Ti)7, (Tz)(Ti)0);
  }
  topFrame = sf.prev;
 }
 return done;
}
/* LOGModule done */
/* including SETModule bodies */
Yhqr *Ypau(Yhqr *t) {
 Zsf sf;
 if (t == NULL) t = Za(sizeof(Yhqr));
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8901200;
 t->Vdict = ZnewDict((Tt*)&string__T, (Tt*)&bool__T, 0);
 topFrame = sf.prev;
 return t;
}
Yhqr *Yh95(Yhqr *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2137800; t = Ypau(NULL);}
 topFrame = sf.prev;
 return t;
}
Tb YyHa(Yhqr *t, Tc *Akey) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2586000;
  ZthrowThisNil();
 }
 sf.pos=2586001;
 r = ZDictHas(t->Vdict, (Tz)(void*)Akey);
 topFrame = sf.prev;
 return r;
}
Yhqr *YGMT(Yhqr *t, Tc *Akey) {
 Yhqr *r = 0;
 YkxB *t0 = 0;
 Tc *t1 = NULL;
 Tr t2 = {NULL};
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (ZDictHas(t->Vdict, (Tz)(void*)Akey))
 {
  Tr ex;
  *Znao(&ex, YX0i__Yalz__YwtA__YRHRa(NULL, (t0 = MZ__callerPos()), (t1 = ZcS(((Tc*)&YLLX), Akey))), YX0i__Ytlm_I_imt, 14);
  ZthrowIobject(ex);
 }
 ZDictAdd(0, t->Vdict, (Tz)(void*)Akey, (Tz)(Ti)1);
 r = t;
 return r;
}
Yhqr *Y63C(Yhqr *t, Tc *Akey) {
 Zsf sf;
 Yhqr *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2167600;
  ZthrowThisNil();
 }
 sf.pos=2167601;
 if (!(ZDictHas(t->Vdict, (Tz)(void*)Akey)))
 {
  sf.pos=2167602;
  ZDictAdd(0, t->Vdict, (Tz)(void*)Akey, (Tz)(Ti)1);
 }
 sf.pos=2167603;
 r = t;
 topFrame = sf.prev;
 return r;
}
To ToYhqr[] = {
 {1, 0},
 {0, (Tt*)&dict__T}, /* dict */
};
Tto Yhqr__T = {390, (Tc*)&Yehz, 0, ToYhqr};
/* SETModule done */
/* including SORTEDLISTModule bodies */
Yo7T *YaDX(Yo7T *t) {
 Zsf sf;
 if (t == NULL) t = Za(sizeof(Yo7T));
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4774600;
 t->Vlist = ZnewList((Tt*)&YwDJ__T, 0);
 topFrame = sf.prev;
 return t;
}
Yo7T *YFR3(Yo7T *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9580000; t = YaDX(NULL);}
 topFrame = sf.prev;
 return t;
}
Tr YOv9(Yo7T *t) {
 Zsf sf;
 Tr r = {NULL};
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1496000;
  ZthrowThisNil();
 }
 sf.pos=1496001;
 r = *Znao(&t0, YKQB__YXWx(NULL, t->Vlist), YKQB__Yzfy_imt, 1);
 topFrame = sf.prev;
 return r;
}
Yo7T *Ygeh(Yo7T *t, YwDJ *Aitem) {
 Ti Vlow;
 Ti Vhigh;
 Zsf sf;
 Yo7T *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1536300;
  ZthrowThisNil();
 }
 sf.pos=1536301;
 Vlow = 0;
 sf.pos=1536302;
 Vhigh = (ZListSize(t->Vlist) - 1);
 sf.pos=1536303;
 while ((Vhigh >= Vlow))
 {
  Ti Vn;
  Ti Vcmp;
  sf.pos=1536304;
  Vn = (((Vlow + Vhigh)) / 2);
  Vcmp = 0;
  sf.pos=1536305;
  if ((t->VsortMethod != NULL))
  {
   sf.pos=1536306;
   Vcmp = ((Ti (*)(Tcb *, YwDJ*, YwDJ*))t->VsortMethod->cfunc)((Tcb*)t->VsortMethod, Aitem, ((YwDJ *)ZListGetPtr(t->Vlist, Vn)));
  }
  else
  {
   sf.pos=1536307;
   Vcmp = YMst(Aitem, ((YwDJ *)ZListGetPtr(t->Vlist, Vn)));
  }
  sf.pos=1536308;
  if ((Vcmp == 0))
  {
   sf.pos=1536309;
   Vlow = Vn;
   rt = 2;
   goto Y_rl;
  }
  sf.pos=1536310;
  if ((Vcmp < 0))
  {
   sf.pos=1536311;
   if ((Vn == 0))
   {
    sf.pos=1536312;
    Vlow = 0;
    rt = 2;
    goto Yui9;
   }
   sf.pos=1536313;
   Vhigh = (Vn - 1);
Yui9:
   if (rt) goto Y_rl;
  }
  else
  {
   sf.pos=1536314;
   Vlow = (Vn + 1);
  }
Y_rl:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=1536315;
 }
 sf.pos=1536316;
 ZListInsert((Tl*)t->Vlist, Vlow, (Tz)(void*)Aitem);
 sf.pos=1536317;
 r = t;
 topFrame = sf.prev;
 return r;
}
To ToYo7T[] = {
 {2, 0},
 {0, (Tt*)&list__T}, /* list */
 {0, (Tt*)&cb__T}, /* sortMethod */
};
Tto Yo7T__T = {390, (Tc*)&YMyc, 0, ToYo7T};
YKQB *YKQB__YXWx(YKQB *t, Tl *Aitems) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1605400; t = YKQBa(NULL);}
 sf.pos=1605401;
 t->Vitems = Aitems;
 topFrame = sf.prev;
 return t;
}
Tb YKQB__Yd_d(YKQB *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1877400;
  ZthrowThisNil();
 }
 sf.pos=1877401;
 r = (t->Vpos < ZListSize(t->Vitems));
 topFrame = sf.prev;
 return r;
}
YwDJ *YKQB__YUEI(YKQB *t) {
 YwDJ *r = 0;
 YwDJ *Vitem = 0;
 Tr t0 = {NULL};
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vpos >= ZListSize(t->Vitems)))
 {
  Tr ex;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YL9D)), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 Vitem = ((YwDJ *)ZListGetPtr(t->Vitems, t->Vpos));
 t->VeditPos = t->Vpos;
 ++(t->Vpos);
 r = Vitem;
 return r;
}
YKQB *YKQBa(YKQB *t) {
 Zsf sf;
 if (t == NULL) t = Za(sizeof(YKQB));
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9278400;
 t->VeditPos = -1;
 sf.pos=9278401;
 t->VinsertPos = 0;
 sf.pos=9278402;
 t->VaddPos = -1;
 topFrame = sf.prev;
 return t;
}
Tc *YKQB__Yzfy_imt[] = {
 (Tc*)&YKQB__T,
 (Tc*)YKQB__Yd_d, /* MSORTEDLISTModule__CSortedListIterator__t1.hasNext - YKQB__Yd_d */
 (Tc*)YKQB__YUEI, /* MSORTEDLISTModule__CSortedListIterator__t1.next - YKQB__YUEI */
 (Tc*)0, /* MSORTEDLISTModule__CSortedListIterator__t1.peekSupported - YKQB__Y0nZ */
 (Tc*)0, /* MSORTEDLISTModule__CSortedListIterator__t1.peek - YKQB__YxYt */
};
To ToYKQB[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* items */
};
Tto YKQB__T = {390, (Tc*)&Y_Qo, 0, ToYKQB};
/* SORTEDLISTModule done */
/* including CHECKModule bodies */
void Y8UT(Tb Ab) {
 Tr t0 = {NULL};
 if (!(Ab))
 {
  Tr ex;
  *Znao(&ex, YtEE__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YG7w)), YtEE__Ytlm_I_imt, 8);
  ZthrowIobject(ex);
 }
 return;
}
/* CHECKModule done */
/* including BOXModule bodies */
Tb Yd_d(YyHo *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8360600;
  ZthrowThisNil();
 }
 sf.pos=8360601;
 r = (t->Vpos < ZListSize(t->Vitems));
 topFrame = sf.prev;
 return r;
}
YwDJ *YUEI(YyHo *t) {
 YwDJ *r = 0;
 YwDJ *Vitem = 0;
 Tr t0 = {NULL};
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vpos >= ZListSize(t->Vitems)))
 {
  Tr ex;
  *Znao(&ex, Yw3O__Yalz__YwtA__YRHRa(NULL, MZ__callerPos(), ((Tc*)&YL9D)), Yw3O__Ytlm_I_imt, 11);
  ZthrowIobject(ex);
 }
 Vitem = ((YwDJ *)ZListGetPtr(t->Vitems, t->Vpos));
 t->VeditPos = t->Vpos;
 ++(t->Vpos);
 r = Vitem;
 return r;
}
To ToYyHo[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* items */
};
Tto YyHo__T = {390, (Tc*)&YC5w, 0, ToYyHo};
/* BOXModule done */
/* including ARGModule bodies */
Ts Ytu_() {
 Zsf sf;
 Ts r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6650100;
 r = (((Y6fX == NULL)) ? (0) : (1));
 topFrame = sf.prev;
 return r;
}
Ti Yd2Z() {
 Ti r = 0;
 YY8i();
 r = ZListSize(Y6fX);
 return r;
}
Tc *YtgL(Ti Aindex) {
 Tc *r = 0;
 int rt = 0;
 YY8i();
 if (((Aindex < 0) || (Aindex >= ZListSize(Y6fX))))
 {
  r = NULL;
  rt = 1;
  goto YJ1M;
 }
 r = ((Tc *)ZListGetPtr(Y6fX, Aindex));
YJ1M:
 return r;
}
To ToYnU5[] = {
 {0, 0},
};
Tto YnU5__T = {390, (Tc*)&Yr32, 0, ToYnU5};
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
void YZH8() {
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
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
      if ((!(YhUP) && ((((ZstringCmp(Vflagname, ((Tc*)&YqzQ)) == 0) || (ZstringCmp(Vflagname, ((Tc*)&Y3via)) == 0)) || (ZstringCmp(Vflagname, ((Tc*)&Yll7)) == 0)))))
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
 topFrame = sf.prev;
 return;
}
void YSUO(Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 Zexit(NULL, 1);
 topFrame = sf.prev;
 return;
}
void Yfj5(Tb Averbose) {
 Ti VmaxLeadLen;
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
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 Zexit(NULL, YMLU);
 topFrame = sf.prev;
 return;
}
void YTlu(Tc *Alead, Ti AmaxLeadLen) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return;
}
Tc *YAMW(YuMQ *t) {
 Ti Vidx;
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return r;
}
To ToYuMQ[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* text */
};
Tto YuMQ__T = {390, (Tc*)&Y6qT, 0, ToYuMQ};
Y86c *YttT(Y86c *t, Tc *AshortName, Tc *AlongName, Tb Adefault, Tc *Adoc) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=327300; t = Za(sizeof(Y86c));}
 sf.pos=327301;
 Y86c__YcLu(t, AshortName, AlongName, Adoc, MZ__callerPos());
 sf.pos=327302;
 t->Vcurrent = Adefault;
 sf.pos=327303;
 t->Vdefault = Adefault;
 sf.pos=327304;
 t->VcanRepeat = 1;
 topFrame = sf.prev;
 return t;
}
void YEqoa(Y86c *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3891100;
  ZthrowThisNil();
 }
 sf.pos=3891101;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
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
Tb YuOS(Y86c *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6128400;
  ZthrowThisNil();
 }
 sf.pos=6128401;
 r = YHoR(t);
 topFrame = sf.prev;
 return r;
}
Y86c *Y86c__YcLu(Y86c *t, Tc *AshortName, Tc *AlongName, Tc *Adoc, YkxB *Apos) {
 Zsf sf;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
 topFrame = sf.prev;
 return t;
}
void Y86c__YofP(Y86c *t, Tc *Aname, Tr Aflag, YkxB *Apos) {
 void *Y_CE = NULL;
 void *p1;
 Tr ex;
 Zsf sf;
 Tc *VonePos = NULL;
 YVNj *Ve = 0;
 Tr t0 = {NULL};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
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
Ti Y86c__Ye9f(Y86c *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 YY8i();
 r = t->VsetCount;
 return r;
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
 (Tc*)Y86c__Ye9f, /* MARGModule__CBool.presentCount - Y86c__Ye9f */
 (Tc*)0, /* MARGModule__CBool.present - Y86c__Y8Dq */
 (Tc*)YEqoa, /* MARGModule__CBool.setToDefault - YEqoa */
 (Tc*)0, /* Init - Y86ca */
};
To ToY86c[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y86c__T = {390, (Tc*)&YZ1F, 0, ToY86c};
void Y49ga(YJQu *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1635000;
  ZthrowThisNil();
 }
 sf.pos=1635001;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYJQu[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YJQu__T = {390, (Tc*)&YzBa, 0, ToYJQu};
void YJaza(YzqH *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8620600;
  ZthrowThisNil();
 }
 sf.pos=8620601;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToYzqH[] = {
 {8, 0},
 {0, (Tt*)&string__T}, /* current */
 {0, (Tt*)&string__T}, /* default */
 {0, (Tt*)&list__T}, /* theValueList */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto YzqH__T = {390, (Tc*)&YDAE, 0, ToYzqH};
void YSkKa(Y_SI *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6447800;
  ZthrowThisNil();
 }
 sf.pos=6447801;
 t->Vcurrent = t->Vdefault;
 topFrame = sf.prev;
 return;
}
To ToY_SI[] = {
 {7, 0},
 {0, (Tt*)&list__T}, /* current */
 {0, (Tt*)&list__T}, /* default */
 {0, (Tt*)&string__T}, /* shortName */
 {0, (Tt*)&string__T}, /* longName */
 {0, (Tt*)&string__T}, /* doc */
 {0, (Tt*)&string__T}, /* argName */
 {0, (Tt*)&YkxB__T}, /* pos */
};
Tto Y_SI__T = {390, (Tc*)&Ygf5, 0, ToY_SI};
int JARGModule(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
  if (round == 0) {
  done = 0;
  } else if (round > 2001) {
    if (Ytu___r == 0) {
      Ytu___r = Ytu_();
      done &= Ytu___r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* ARGModule done */
/* including zui bodies */
Yol9 *YzBD(Yol9 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2860500; t = Za(sizeof(Yol9));}
 topFrame = sf.prev;
 return t;
}
Yol9 *YJpo(Yol9 *t, YqKm *Av) {
 Zsf sf;
 Yol9 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8511100;
  ZthrowThisNil();
 }
 sf.pos=8511101;
 if ((t->Vf_import == NULL))
 {
  sf.pos=8511102;
  t->Vf_import = ZnewList((Tt*)&YqKm__T, 0);
 }
 sf.pos=8511103;
 ZLap((Tl*)t->Vf_import, (Tz)(void*)Av);
 sf.pos=8511104;
 r = t;
 topFrame = sf.prev;
 return r;
}
YqKm *YNk6(Yol9 *t) {
 Zsf sf;
 YqKm *r = 0;
 YqKm *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8266500;
  ZthrowThisNil();
 }
 sf.pos=8266501;
 Vv = YFYs(NULL);
 sf.pos=8266502;
 YJpo(t, Vv);
 sf.pos=8266503;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Tl *YAaE(Yol9 *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_statement;
 return r;
}
Yol9 *YVAS(Yol9 *t, Tl *Al) {
 Yol9 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_statement = Al;
 r = t;
 return r;
}
To ToYol9[] = {
 {2, 0},
 {0, (Tt*)&list__T}, /* f_import */
 {0, (Tt*)&list__T}, /* f_statement */
};
Tto Yol9__T = {390, (Tc*)&Yz59, 0, ToYol9};
Yknz *YpBS(Yknz *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3867400; t = Za(sizeof(Yknz));}
 topFrame = sf.prev;
 return t;
}
Yknz *YCOd(Yknz *t, Tb Adeep) {
 Zsf sf;
 Yknz *r = 0;
 Yknz *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3071900;
  ZthrowThisNil();
 }
 sf.pos=3071901;
 Vret = YpBS(NULL);
 sf.pos=3071902;
 if (t->Vhas_ref)
 {
  sf.pos=3071903;
  Vret->Vhas_ref = 1;
  sf.pos=3071904;
  Vret->Vf_ref = t->Vf_ref;
 }
 sf.pos=3071905;
 if (t->Vhas_importNumber)
 {
  sf.pos=3071906;
  Vret->Vhas_importNumber = 1;
  sf.pos=3071907;
  Vret->Vf_importNumber = t->Vf_importNumber;
 }
 sf.pos=3071908;
 if (t->Vhas_importRef)
 {
  sf.pos=3071909;
  Vret->Vhas_importRef = 1;
  sf.pos=3071910;
  Vret->Vf_importRef = t->Vf_importRef;
 }
 sf.pos=3071911;
 Vret->Vf_name = t->Vf_name;
 sf.pos=3071912;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYknz[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* f_name */
};
Tto Yknz__T = {390, (Tc*)&YrHi, 0, ToYknz};
YqKm *YFYs(YqKm *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=264600; t = Za(sizeof(YqKm));}
 topFrame = sf.prev;
 return t;
}
YqKm *Y6Pf(YqKm *t, Tc *Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_fileName = Av;
 r = t;
 return r;
}
YqKm *YWuz(YqKm *t, Tb Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_angleQuotes = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YqKm *Y0hJ(YqKm *t, Tc *Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_plugin = Av;
 r = t;
 return r;
}
YqKm *YYIq(YqKm *t, Tc *Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_asName = Av;
 r = t;
 return r;
}
YqKm *YQa2(YqKm *t, Tc *Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_options = Av;
 r = t;
 return r;
}
YqKm *YimL(YqKm *t, Ysbp *Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
YqKm *YQBo(YqKm *t, Ti Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_importNumber = Av;
 t->Vhas_importNumber = 1;
 r = t;
 return r;
}
YqKm *YygQ(YqKm *t, Tb Av) {
 YqKm *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_javascript = ((Av) ? (2) : (1));
 r = t;
 return r;
}
To ToYqKm[] = {
 {5, 0},
 {0, (Tt*)&string__T}, /* f_fileName */
 {0, (Tt*)&string__T}, /* f_plugin */
 {0, (Tt*)&string__T}, /* f_asName */
 {0, (Tt*)&string__T}, /* f_options */
 {0, (Tt*)&Ysbp__T}, /* f_pos */
};
Tto YqKm__T = {390, (Tc*)&YeYv, 0, ToYqKm};
YYIi *YpQb(YYIi *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7771700; t = Za(sizeof(YYIi));}
 topFrame = sf.prev;
 return t;
}
YYIi *YpBC(YYIi *t, Tc *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
Tc *YdHK(YYIi *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_name == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto YqrY;
 }
 r = t->Vf_name;
YqrY:
 return r;
}
YYIi *YTLb(YYIi *t, YnZD *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_dotName = Av;
 r = t;
 return r;
}
YYIi *YJ03(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_dollar = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YGHm(YYIi *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_dollar == 0))
 {
  r = 0;
  rt = 1;
  goto YYG9;
 }
 r = (t->Vf_dollar == 2);
YYG9:
 return r;
}
YYIi *Y5JX(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_percent = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YEkx(YYIi *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_percent == 0))
 {
  r = 0;
  rt = 1;
  goto Yo4K;
 }
 r = (t->Vf_percent == 2);
Yo4K:
 return r;
}
YYIi *Y1ql(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_shared = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YYIi *YvRw(YYIi *t, Ysbp *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
YYIi *Y747(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isUse = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YYIi *YdTj(YYIi *t, YRBza *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Av;
 r = t;
 return r;
}
YRBza *YkDm(YYIi *t) {
 Zsf sf;
 YRBza *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5511900;
  ZthrowThisNil();
 }
 sf.pos=5511901;
 t->Vf_type = Ya_p(NULL);
 sf.pos=5511902;
 r = t->Vf_type;
 topFrame = sf.prev;
 return r;
}
YRBza *Y1Yr(YYIi *t) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_type == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YM0N);
  ZthrowPos(3770900, ex);
 }
 r = t->Vf_type;
 return r;
}
YYIi *YhZx(YYIi *t, YnZD *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_init = Av;
 r = t;
 return r;
}
Tb YoD_(YYIi *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_init != NULL);
 return r;
}
YYIi *Y6vX(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isArg = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YYIi *Yv8X(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_threeDots = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YYIi *Y4e7(YYIi *t, Tc *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_commentBefore = Av;
 r = t;
 return r;
}
Tc *YWDX(YYIi *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_commentBefore == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto Y83y;
 }
 r = t->Vf_commentBefore;
Y83y:
 return r;
}
Tb YMEi(YYIi *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_commentBefore != NULL);
 return r;
}
YYIi *YDJy(YYIi *t, Tc *Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_commentAfter = Av;
 r = t;
 return r;
}
Tc *YNOi(YYIi *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_commentAfter == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto YdIr;
 }
 r = t->Vf_commentAfter;
YdIr:
 return r;
}
Tb YqeZ(YYIi *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_commentAfter != NULL);
 return r;
}
YYIi *Yxn8(YYIi *t, Tb Av) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_preferCommentAfter = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YfGL(YYIi *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_preferCommentAfter == 0))
 {
  r = 0;
  rt = 1;
  goto Y97u;
 }
 r = (t->Vf_preferCommentAfter == 2);
Y97u:
 return r;
}
YYIi *YTec(YYIi *t, Tb Adeep) {
 Zsf sf;
 YYIi *r = 0;
 YYIi *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=942200;
  ZthrowThisNil();
 }
 sf.pos=942201;
 Vret = YpQb(NULL);
 sf.pos=942202;
 Vret->Vf_name = t->Vf_name;
 sf.pos=942203;
 if ((t->Vf_dotName != NULL))
 {
  sf.pos=942204;
  Vret->Vf_dotName = ((Adeep) ? (Ypps(t->Vf_dotName, Adeep)) : (t->Vf_dotName));
 }
 sf.pos=942205;
 Vret->Vf_dollar = t->Vf_dollar;
 sf.pos=942206;
 Vret->Vf_percent = t->Vf_percent;
 sf.pos=942207;
 Vret->Vf_shared = t->Vf_shared;
 sf.pos=942208;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=942209;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=942210;
 if (t->Vhas_ref)
 {
  sf.pos=942211;
  Vret->Vhas_ref = 1;
  sf.pos=942212;
  Vret->Vf_ref = t->Vf_ref;
 }
 sf.pos=942213;
 Vret->Vf_isUse = t->Vf_isUse;
 sf.pos=942214;
 if ((t->Vf_type != NULL))
 {
  sf.pos=942215;
  Vret->Vf_type = ((Adeep) ? (YK7D(t->Vf_type, Adeep)) : (t->Vf_type));
 }
 sf.pos=942216;
 if ((t->Vf_init != NULL))
 {
  sf.pos=942217;
  Vret->Vf_init = ((Adeep) ? (Ypps(t->Vf_init, Adeep)) : (t->Vf_init));
 }
 sf.pos=942218;
 Vret->Vf_isArg = t->Vf_isArg;
 sf.pos=942219;
 Vret->Vf_threeDots = t->Vf_threeDots;
 sf.pos=942220;
 Vret->Vf_commentBefore = t->Vf_commentBefore;
 sf.pos=942221;
 Vret->Vf_commentAfter = t->Vf_commentAfter;
 sf.pos=942222;
 Vret->Vf_preferCommentAfter = t->Vf_preferCommentAfter;
 sf.pos=942223;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYYIi[] = {
 {7, 0},
 {0, (Tt*)&string__T}, /* f_name */
 {0, (Tt*)&YnZD__T}, /* f_dotName */
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&YRBza__T}, /* f_type */
 {0, (Tt*)&YnZD__T}, /* f_init */
 {0, (Tt*)&string__T}, /* f_commentBefore */
 {0, (Tt*)&string__T}, /* f_commentAfter */
};
Tto YYIi__T = {390, (Tc*)&Yy4i, 0, ToYYIi};
YRBza *Ya_p(YRBza *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=399300; t = Za(sizeof(YRBza));}
 topFrame = sf.prev;
 return t;
}
YRBza *YLJs(YRBza *t, Te Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Av;
 r = t;
 return r;
}
Te YXDk(YRBza *t) {
 Te r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_type == 0))
 {
  void *ex = NULL;
  ex = ((Tc*)&YM0N);
  ZthrowPos(6260900, ex);
 }
 r = t->Vf_type;
 return r;
}
YRBza *Y2b1(YRBza *t, Ysbp *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
YRBza *YrDX(YRBza *t, YJON *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_attr = Av;
 r = t;
 return r;
}
YJON *YDxP(YRBza *t) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_attr == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Yzav);
  ZthrowPos(490200, ex);
 }
 r = t->Vf_attr;
 return r;
}
Tb YkZu(YRBza *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_attr != NULL);
 return r;
}
YRBza *Y45H(YRBza *t, YftY *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_classDecl = Av;
 r = t;
 return r;
}
YftY *YJgu(YRBza *t) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_classDecl == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Ydqh);
  ZthrowPos(314100, ex);
 }
 r = t->Vf_classDecl;
 return r;
}
YRBza *YewF(YRBza *t, YfQg *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_bitsDecl = Av;
 r = t;
 return r;
}
YfQg *YDOm(YRBza *t) {
 YfQg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_bitsDecl == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y9pb);
  ZthrowPos(8765300, ex);
 }
 r = t->Vf_bitsDecl;
 return r;
}
YRBza *YEtr(YRBza *t, YFN2 *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_enumDecl = Av;
 r = t;
 return r;
}
YFN2 *YdRA(YRBza *t) {
 YFN2 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_enumDecl == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y_JJ);
  ZthrowPos(8145600, ex);
 }
 r = t->Vf_enumDecl;
 return r;
}
YRBza *YM5q(YRBza *t, Y2wP *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_moduleDecl = Av;
 r = t;
 return r;
}
Y2wP *Y8Ec(YRBza *t) {
 Y2wP *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_moduleDecl == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YN1w);
  ZthrowPos(6533300, ex);
 }
 r = t->Vf_moduleDecl;
 return r;
}
YRBza *YHPQ(YRBza *t, Y7Np *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_methodDecl = Av;
 r = t;
 return r;
}
Y7Np *Y3nC(YRBza *t) {
 Y7Np *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_methodDecl == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YPyV);
  ZthrowPos(617200, ex);
 }
 r = t->Vf_methodDecl;
 return r;
}
YRBza *YVus(YRBza *t, YoDF *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_alias = Av;
 r = t;
 return r;
}
YoDF *Y9au(YRBza *t) {
 YoDF *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_alias == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YKpG);
  ZthrowPos(9245300, ex);
 }
 r = t->Vf_alias;
 return r;
}
YRBza *YE45(YRBza *t, YRBza *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_ref = Av;
 r = t;
 return r;
}
YRBza *YH95(YRBza *t) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_ref == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YKdC);
  ZthrowPos(5154400, ex);
 }
 r = t->Vf_ref;
 return r;
}
YRBza *Yz09(YRBza *t, YnZD *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
YnZD *YLV1(YRBza *t) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_name == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y0L2);
  ZthrowPos(1907600, ex);
 }
 r = t->Vf_name;
 return r;
}
YRBza *Yk0M(YRBza *t, Tc *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_itemName = Av;
 r = t;
 return r;
}
YRBza *YPkC(YRBza *t, Ysbp *Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_itemNamePos = Av;
 r = t;
 return r;
}
YRBza *Y3HG(YRBza *t, Tb Av) {
 YRBza *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isReturn = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YRBza *YK7D(YRBza *t, Tb Adeep) {
 Zsf sf;
 YRBza *r = 0;
 YRBza *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=208200;
  ZthrowThisNil();
 }
 sf.pos=208201;
 Vret = Ya_p(NULL);
 sf.pos=208202;
 Vret->Vf_type = t->Vf_type;
 sf.pos=208203;
 Vret->Vf_text = t->Vf_text;
 sf.pos=208204;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=208205;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=208206;
 if ((t->Vf_attr != NULL))
 {
  sf.pos=208207;
  Vret->Vf_attr = ((Adeep) ? (YGuf(t->Vf_attr, Adeep)) : (t->Vf_attr));
 }
 sf.pos=208208;
 if ((t->Vf_classRef != NULL))
 {
  sf.pos=208209;
  Vret->Vf_classRef = ((Adeep) ? (YCOd(t->Vf_classRef, Adeep)) : (t->Vf_classRef));
 }
 sf.pos=208210;
 if (t->Vhas_decimals)
 {
  sf.pos=208211;
  Vret->Vhas_decimals = 1;
  sf.pos=208212;
  Vret->Vf_decimals = t->Vf_decimals;
 }
 sf.pos=208213;
 if (t->Vhas_mask)
 {
  sf.pos=208214;
  Vret->Vhas_mask = 1;
  sf.pos=208215;
  Vret->Vf_mask = t->Vf_mask;
 }
 sf.pos=208216;
 if ((t->Vf_classDecl != NULL))
 {
  sf.pos=208217;
  Vret->Vf_classDecl = ((Adeep) ? (YOIH(t->Vf_classDecl, Adeep)) : (t->Vf_classDecl));
 }
 sf.pos=208218;
 if ((t->Vf_bitsDecl != NULL))
 {
  sf.pos=208219;
  Vret->Vf_bitsDecl = ((Adeep) ? (Y60S(t->Vf_bitsDecl, Adeep)) : (t->Vf_bitsDecl));
 }
 sf.pos=208220;
 if ((t->Vf_enumDecl != NULL))
 {
  sf.pos=208221;
  Vret->Vf_enumDecl = ((Adeep) ? (Y17e(t->Vf_enumDecl, Adeep)) : (t->Vf_enumDecl));
 }
 sf.pos=208222;
 if ((t->Vf_moduleDecl != NULL))
 {
  sf.pos=208223;
  Vret->Vf_moduleDecl = ((Adeep) ? (YBUM(t->Vf_moduleDecl, Adeep)) : (t->Vf_moduleDecl));
 }
 sf.pos=208224;
 if ((t->Vf_methodDecl != NULL))
 {
  sf.pos=208225;
  Vret->Vf_methodDecl = ((Adeep) ? (Yt_q(t->Vf_methodDecl, Adeep)) : (t->Vf_methodDecl));
 }
 sf.pos=208226;
 if ((t->Vf_container != NULL))
 {
  sf.pos=208227;
  Vret->Vf_container = ((Adeep) ? (YLOM(t->Vf_container, Adeep)) : (t->Vf_container));
 }
 sf.pos=208228;
 if ((t->Vf_alias != NULL))
 {
  sf.pos=208229;
  Vret->Vf_alias = ((Adeep) ? (YL4I(t->Vf_alias, Adeep)) : (t->Vf_alias));
 }
 sf.pos=208230;
 if ((t->Vf_ref != NULL))
 {
  sf.pos=208231;
  Vret->Vf_ref = ((Adeep) ? (YK7D(t->Vf_ref, Adeep)) : (t->Vf_ref));
 }
 sf.pos=208232;
 if ((t->Vf_name != NULL))
 {
  sf.pos=208233;
  Vret->Vf_name = ((Adeep) ? (Ypps(t->Vf_name, Adeep)) : (t->Vf_name));
 }
 sf.pos=208234;
 Vret->Vf_itemName = t->Vf_itemName;
 sf.pos=208235;
 if ((t->Vf_itemNamePos != NULL))
 {
  sf.pos=208236;
  Vret->Vf_itemNamePos = ((Adeep) ? (Yw4M(t->Vf_itemNamePos, Adeep)) : (t->Vf_itemNamePos));
 }
 sf.pos=208237;
 Vret->Vf_isReturn = t->Vf_isReturn;
 sf.pos=208238;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYRBza[] = {
 {15, 0},
 {0, (Tt*)&string__T}, /* f_text */
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&YJON__T}, /* f_attr */
 {0, (Tt*)&Yknz__T}, /* f_classRef */
 {0, (Tt*)&YftY__T}, /* f_classDecl */
 {0, (Tt*)&YfQg__T}, /* f_bitsDecl */
 {0, (Tt*)&YFN2__T}, /* f_enumDecl */
 {0, (Tt*)&Y2wP__T}, /* f_moduleDecl */
 {0, (Tt*)&Y7Np__T}, /* f_methodDecl */
 {0, (Tt*)&YyfS__T}, /* f_container */
 {0, (Tt*)&YoDF__T}, /* f_alias */
 {0, (Tt*)&YRBza__T}, /* f_ref */
 {0, (Tt*)&YnZD__T}, /* f_name */
 {0, (Tt*)&string__T}, /* f_itemName */
 {0, (Tt*)&Ysbp__T}, /* f_itemNamePos */
};
Tto YRBza__T = {390, (Tc*)&Yokf, 0, ToYRBza};
YJON *YsCX(YJON *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7591000; t = Za(sizeof(YJON));}
 topFrame = sf.prev;
 return t;
}
YJON *Y5IN(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_abstract = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YCKw(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_abstract == 0))
 {
  r = 0;
  rt = 1;
  goto Y8hz;
 }
 r = (t->Vf_abstract == 2);
Y8hz:
 return r;
}
YJON *Y_Uu(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isdefault = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YHd1(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_isdefault == 0))
 {
  r = 0;
  rt = 1;
  goto YCUT;
 }
 r = (t->Vf_isdefault == 2);
YCUT:
 return r;
}
YJON *YsDp(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_final = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YdXn(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_final == 0))
 {
  r = 0;
  rt = 1;
  goto Ya9w;
 }
 r = (t->Vf_final == 2);
Ya9w:
 return r;
}
YJON *YdJG(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_define = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YapZ(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_define == 0))
 {
  r = 0;
  rt = 1;
  goto YlCI;
 }
 r = (t->Vf_define == 2);
YlCI:
 return r;
}
YJON *Y3gm(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_replace = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YJqm(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_replace == 0))
 {
  r = 0;
  rt = 1;
  goto YNoi;
 }
 r = (t->Vf_replace == 2);
YNoi:
 return r;
}
YJON *Y5i_(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_earlyInit = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YBPw(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_earlyInit == 0))
 {
  r = 0;
  rt = 1;
  goto Yc66;
 }
 r = (t->Vf_earlyInit == 2);
Yc66:
 return r;
}
YJON *YOG0(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_primitive = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YTrv(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_primitive == 0))
 {
  r = 0;
  rt = 1;
  goto YSrD;
 }
 r = (t->Vf_primitive == 2);
YSrD:
 return r;
}
YJON *Y980(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_noBacktrace = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Y929(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_noBacktrace == 0))
 {
  r = 0;
  rt = 1;
  goto YRTh;
 }
 r = (t->Vf_noBacktrace == 2);
YRTh:
 return r;
}
YJON *YDDz(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_wantBacktrace = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb Ynfv(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_wantBacktrace == 0))
 {
  r = 0;
  rt = 1;
  goto YgPN;
 }
 r = (t->Vf_wantBacktrace == 2);
YgPN:
 return r;
}
YJON *Ywbp(YJON *t, Te Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_visibility = Av;
 r = t;
 return r;
}
Te Y9CD(YJON *t) {
 Te r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_visibility == 0))
 {
  void *ex = NULL;
  ex = ((Tc*)&YRZU);
  ZthrowPos(400800, ex);
 }
 r = t->Vf_visibility;
 return r;
}
Tb YVd6(YJON *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_visibility != 0);
 return r;
}
YJON *YjX9(YJON *t, Te Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_readVisibility = Av;
 r = t;
 return r;
}
Tb YpeP(YJON *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_readVisibility != 0);
 return r;
}
YJON *YUKK(YJON *t, Te Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_itemsVisibility = Av;
 r = t;
 return r;
}
Te Yr4g(YJON *t) {
 Te r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_itemsVisibility == 0))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y_Vi);
  ZthrowPos(6459400, ex);
 }
 r = t->Vf_itemsVisibility;
 return r;
}
Tb YVep(YJON *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_itemsVisibility != 0);
 return r;
}
YJON *YJmK(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_notOnExit = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YYLM(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_notOnExit == 0))
 {
  r = 0;
  rt = 1;
  goto YpFZ;
 }
 r = (t->Vf_notOnExit == 2);
YpFZ:
 return r;
}
YJON *YFFWa(YJON *t, Tb Av) {
 YJON *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_javascript = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YiKB(YJON *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_javascript == 0))
 {
  r = 0;
  rt = 1;
  goto YG3Y;
 }
 r = (t->Vf_javascript == 2);
YG3Y:
 return r;
}
YJON *YGuf(YJON *t, Tb Adeep) {
 Zsf sf;
 YJON *r = 0;
 YJON *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9801900;
  ZthrowThisNil();
 }
 sf.pos=9801901;
 Vret = YsCX(NULL);
 sf.pos=9801902;
 Vret->Vf_abstract = t->Vf_abstract;
 sf.pos=9801903;
 Vret->Vf_isdefault = t->Vf_isdefault;
 sf.pos=9801904;
 Vret->Vf_final = t->Vf_final;
 sf.pos=9801905;
 Vret->Vf_define = t->Vf_define;
 sf.pos=9801906;
 Vret->Vf_replace = t->Vf_replace;
 sf.pos=9801907;
 Vret->Vf_earlyInit = t->Vf_earlyInit;
 sf.pos=9801908;
 Vret->Vf_primitive = t->Vf_primitive;
 sf.pos=9801909;
 Vret->Vf_noBacktrace = t->Vf_noBacktrace;
 sf.pos=9801910;
 Vret->Vf_wantBacktrace = t->Vf_wantBacktrace;
 sf.pos=9801911;
 Vret->Vf_visibility = t->Vf_visibility;
 sf.pos=9801912;
 Vret->Vf_readVisibility = t->Vf_readVisibility;
 sf.pos=9801913;
 Vret->Vf_itemsVisibility = t->Vf_itemsVisibility;
 sf.pos=9801914;
 Vret->Vf_notOnExit = t->Vf_notOnExit;
 sf.pos=9801915;
 Vret->Vf_javascript = t->Vf_javascript;
 sf.pos=9801916;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYJON[] = {
 {0, 0},
};
Tto YJON__T = {390, (Tc*)&YK8n, 0, ToYJON};
YftY *YOMn(YftY *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1745100; t = Za(sizeof(YftY));}
 topFrame = sf.prev;
 return t;
}
YftY *YHGh(YftY *t, Tb Av) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isInterface = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YftY *YFgR(YftY *t, Tb Av) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_isPiece = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tl *YrvP(YftY *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_templateTypeName;
 return r;
}
YftY *YCdb(YftY *t, Tl *Al) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_templateTypeName = Al;
 r = t;
 return r;
}
Tb YHI7(YftY *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_templateTypeName != NULL) && (ZListSize(t->Vf_templateTypeName) > 0));
 return r;
}
YftY *YSMx(YftY *t, YnZD *Av) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_extends = Av;
 r = t;
 return r;
}
YnZD *YVVa(YftY *t) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_extends == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YAke);
  ZthrowPos(425600, ex);
 }
 r = t->Vf_extends;
 return r;
}
Tb YCwH(YftY *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_extends != NULL);
 return r;
}
Tl *YVqZ(YftY *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_implements;
 return r;
}
YftY *Yq9S(YftY *t, Tl *Al) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_implements = Al;
 r = t;
 return r;
}
Tb YXx6(YftY *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_implements != NULL) && (ZListSize(t->Vf_implements) > 0));
 return r;
}
Tl *YGyt(YftY *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_member;
 return r;
}
YftY *Yj_H(YftY *t, Tl *Al) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_member = Al;
 r = t;
 return r;
}
Tb YskK(YftY *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_member != NULL) && (ZListSize(t->Vf_member) > 0));
 return r;
}
YhZL *YPLV(YftY *t) {
 Zsf sf;
 YhZL *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=63000;
  ZthrowThisNil();
 }
 sf.pos=63001;
 t->Vf_shared = YBTx(NULL);
 sf.pos=63002;
 r = t->Vf_shared;
 topFrame = sf.prev;
 return r;
}
YhZL *Ykbi(YftY *t) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_shared == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y_pz);
  ZthrowPos(6909200, ex);
 }
 r = t->Vf_shared;
 return r;
}
Tb YPer(YftY *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_shared != NULL);
 return r;
}
YftY *YjP6(YftY *t, YJON *Av) {
 YftY *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_sharedAttr = Av;
 r = t;
 return r;
}
YftY *YOIH(YftY *t, Tb Adeep) {
 Zsf sf;
 YftY *r = 0;
 YftY *Vret = 0;
 Tl *Zf3 = NULL;
 Tl *Zf31 = NULL;
 Tl *Zf32 = NULL;
 Y1p4 *Vi = 0;
 YnZD *Vi1 = 0;
 YXCg *Vi2 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6770800;
  ZthrowThisNil();
 }
 sf.pos=6770801;
 Vret = YOMn(NULL);
 sf.pos=6770802;
 Vret->Vf_name = t->Vf_name;
 sf.pos=6770803;
 Vret->Vf_isInterface = t->Vf_isInterface;
 sf.pos=6770804;
 Vret->Vf_isPiece = t->Vf_isPiece;
 sf.pos=6770805;
 if (Adeep)
 {
  sf.pos=6770806;
  if ((t->Vf_templateTypeName != NULL))
  {
   sf.pos=6770807;
   Vret->Vf_templateTypeName = ZnewList((Tt*)&Y1p4__T, 0);
   sf.pos=6770808;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_templateTypeName;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=6770809;
    ZLap((Tl*)Vret->Vf_templateTypeName, (Tz)(void*)Y_4M(Vi, Adeep));
    sf.pos=6770810;
    }
   }
  }
 }
 else
 {
  sf.pos=6770811;
  Vret->Vf_templateTypeName = t->Vf_templateTypeName;
 }
 sf.pos=6770812;
 if ((t->Vf_extends != NULL))
 {
  sf.pos=6770813;
  Vret->Vf_extends = ((Adeep) ? (Ypps(t->Vf_extends, Adeep)) : (t->Vf_extends));
 }
 sf.pos=6770814;
 if (Adeep)
 {
  sf.pos=6770815;
  if ((t->Vf_implements != NULL))
  {
   sf.pos=6770816;
   Vret->Vf_implements = ZnewList((Tt*)&YnZD__T, 0);
   sf.pos=6770817;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_implements;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi1;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=6770818;
    ZLap((Tl*)Vret->Vf_implements, (Tz)(void*)Ypps(Vi1, Adeep));
    sf.pos=6770819;
    }
   }
  }
 }
 else
 {
  sf.pos=6770820;
  Vret->Vf_implements = t->Vf_implements;
 }
 sf.pos=6770821;
 if (Adeep)
 {
  sf.pos=6770822;
  if ((t->Vf_member != NULL))
  {
   sf.pos=6770823;
   Vret->Vf_member = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=6770824;
   {
    Tfl Zf32i;
    Zf32 = t->Vf_member;
    Zf32i.l = Zf32;
    Zf32i.valp = (void*)&Vi2;
    Zf32i.i = 0;
    for (; ZforListPtrCont(&Zf32i); ) {
    sf.pos=6770825;
    ZLap((Tl*)Vret->Vf_member, (Tz)(void*)Y9N8(Vi2, Adeep));
    sf.pos=6770826;
    }
   }
  }
 }
 else
 {
  sf.pos=6770827;
  Vret->Vf_member = t->Vf_member;
 }
 sf.pos=6770828;
 if ((t->Vf_shared != NULL))
 {
  sf.pos=6770829;
  Vret->Vf_shared = ((Adeep) ? (Yzft(t->Vf_shared, Adeep)) : (t->Vf_shared));
 }
 sf.pos=6770830;
 if ((t->Vf_sharedAttr != NULL))
 {
  sf.pos=6770831;
  Vret->Vf_sharedAttr = ((Adeep) ? (YGuf(t->Vf_sharedAttr, Adeep)) : (t->Vf_sharedAttr));
 }
 sf.pos=6770832;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYftY[] = {
 {7, 0},
 {0, (Tt*)&string__T}, /* f_name */
 {0, (Tt*)&list__T}, /* f_templateTypeName */
 {0, (Tt*)&YnZD__T}, /* f_extends */
 {0, (Tt*)&list__T}, /* f_implements */
 {0, (Tt*)&list__T}, /* f_member */
 {0, (Tt*)&YhZL__T}, /* f_shared */
 {0, (Tt*)&YJON__T}, /* f_sharedAttr */
};
Tto YftY__T = {390, (Tc*)&YwBU, 0, ToYftY};
YfQg *Y8xU(YfQg *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6767500; t = Za(sizeof(YfQg));}
 topFrame = sf.prev;
 return t;
}
Tl *Y4e2(YfQg *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_member;
 return r;
}
YfQg *YT9u(YfQg *t, Tl *Al) {
 YfQg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_member = Al;
 r = t;
 return r;
}
Tb YVXf(YfQg *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_member != NULL) && (ZListSize(t->Vf_member) > 0));
 return r;
}
YfQg *Y60S(YfQg *t, Tb Adeep) {
 Zsf sf;
 YfQg *r = 0;
 YfQg *Vret = 0;
 Tl *Zf3 = NULL;
 YXCg *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2094000;
  ZthrowThisNil();
 }
 sf.pos=2094001;
 Vret = Y8xU(NULL);
 sf.pos=2094002;
 if (Adeep)
 {
  sf.pos=2094003;
  if ((t->Vf_member != NULL))
  {
   sf.pos=2094004;
   Vret->Vf_member = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=2094005;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_member;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=2094006;
    ZLap((Tl*)Vret->Vf_member, (Tz)(void*)Y9N8(Vi, Adeep));
    sf.pos=2094007;
    }
   }
  }
 }
 else
 {
  sf.pos=2094008;
  Vret->Vf_member = t->Vf_member;
 }
 sf.pos=2094009;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYfQg[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* f_member */
};
Tto YfQg__T = {390, (Tc*)&YIB2, 0, ToYfQg};
YFN2 *Y5iq(YFN2 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7477400; t = Za(sizeof(YFN2));}
 topFrame = sf.prev;
 return t;
}
YFN2 *Ydz4(YFN2 *t, YYIi *Av) {
 Zsf sf;
 YFN2 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6986400;
  ZthrowThisNil();
 }
 sf.pos=6986401;
 if ((t->Vf_item == NULL))
 {
  sf.pos=6986402;
  t->Vf_item = ZnewList((Tt*)&YYIi__T, 0);
 }
 sf.pos=6986403;
 ZLap((Tl*)t->Vf_item, (Tz)(void*)Av);
 sf.pos=6986404;
 r = t;
 topFrame = sf.prev;
 return r;
}
YYIi *YbCT(YFN2 *t) {
 Zsf sf;
 YYIi *r = 0;
 YYIi *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3335000;
  ZthrowThisNil();
 }
 sf.pos=3335001;
 Vv = YpQb(NULL);
 sf.pos=3335002;
 Ydz4(t, Vv);
 sf.pos=3335003;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Tl *YOZZ(YFN2 *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_item;
 return r;
}
Tl *YjCl(YFN2 *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_member;
 return r;
}
Tb YohH(YFN2 *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_member != NULL) && (ZListSize(t->Vf_member) > 0));
 return r;
}
YFN2 *Y17e(YFN2 *t, Tb Adeep) {
 Zsf sf;
 YFN2 *r = 0;
 YFN2 *Vret = 0;
 Tl *Zf3 = NULL;
 YYIi *Vi = 0;
 Tl *Zf31 = NULL;
 YXCg *Vi1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6712300;
  ZthrowThisNil();
 }
 sf.pos=6712301;
 Vret = Y5iq(NULL);
 sf.pos=6712302;
 if (Adeep)
 {
  sf.pos=6712303;
  if ((t->Vf_item != NULL))
  {
   sf.pos=6712304;
   Vret->Vf_item = ZnewList((Tt*)&YYIi__T, 0);
   sf.pos=6712305;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_item;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=6712306;
    ZLap((Tl*)Vret->Vf_item, (Tz)(void*)YTec(Vi, Adeep));
    sf.pos=6712307;
    }
   }
  }
 }
 else
 {
  sf.pos=6712308;
  Vret->Vf_item = t->Vf_item;
 }
 sf.pos=6712309;
 if (Adeep)
 {
  sf.pos=6712310;
  if ((t->Vf_member != NULL))
  {
   sf.pos=6712311;
   Vret->Vf_member = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=6712312;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_member;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi1;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=6712313;
    ZLap((Tl*)Vret->Vf_member, (Tz)(void*)Y9N8(Vi1, Adeep));
    sf.pos=6712314;
    }
   }
  }
 }
 else
 {
  sf.pos=6712315;
  Vret->Vf_member = t->Vf_member;
 }
 sf.pos=6712316;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYFN2[] = {
 {2, 0},
 {0, (Tt*)&list__T}, /* f_item */
 {0, (Tt*)&list__T}, /* f_member */
};
Tto YFN2__T = {390, (Tc*)&YiEg, 0, ToYFN2};
Y2wP *YwDD(Y2wP *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6132300; t = Za(sizeof(Y2wP));}
 topFrame = sf.prev;
 return t;
}
Tl *YiW9(Y2wP *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_statement;
 return r;
}
Y2wP *YDlo(Y2wP *t, Tl *Al) {
 Y2wP *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_statement = Al;
 r = t;
 return r;
}
Tb Y13u(Y2wP *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_statement != NULL) && (ZListSize(t->Vf_statement) > 0));
 return r;
}
Y2wP *YBUM(Y2wP *t, Tb Adeep) {
 Zsf sf;
 Y2wP *r = 0;
 Y2wP *Vret = 0;
 Tl *Zf3 = NULL;
 YXCg *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6313200;
  ZthrowThisNil();
 }
 sf.pos=6313201;
 Vret = YwDD(NULL);
 sf.pos=6313202;
 if (Adeep)
 {
  sf.pos=6313203;
  if ((t->Vf_statement != NULL))
  {
   sf.pos=6313204;
   Vret->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=6313205;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_statement;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=6313206;
    ZLap((Tl*)Vret->Vf_statement, (Tz)(void*)Y9N8(Vi, Adeep));
    sf.pos=6313207;
    }
   }
  }
 }
 else
 {
  sf.pos=6313208;
  Vret->Vf_statement = t->Vf_statement;
 }
 sf.pos=6313209;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToY2wP[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* f_statement */
};
Tto Y2wP__T = {390, (Tc*)&Yqqm, 0, ToY2wP};
Y7Np *YWVR(Y7Np *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=2905800; t = Za(sizeof(Y7Np));}
 topFrame = sf.prev;
 return t;
}
Y7Np *YEOq(Y7Np *t, YRBza *Av) {
 Zsf sf;
 Y7Np *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1697500;
  ZthrowThisNil();
 }
 sf.pos=1697501;
 if ((t->Vf_returnType == NULL))
 {
  sf.pos=1697502;
  t->Vf_returnType = ZnewList((Tt*)&YRBza__T, 0);
 }
 sf.pos=1697503;
 ZLap((Tl*)t->Vf_returnType, (Tz)(void*)Av);
 sf.pos=1697504;
 r = t;
 topFrame = sf.prev;
 return r;
}
YRBza *YQsX(Y7Np *t) {
 Zsf sf;
 YRBza *r = 0;
 YRBza *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1169300;
  ZthrowThisNil();
 }
 sf.pos=1169301;
 Vv = Ya_p(NULL);
 sf.pos=1169302;
 YEOq(t, Vv);
 sf.pos=1169303;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Tl *Yv3S(Y7Np *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_returnType;
 return r;
}
Tb Y5UB(Y7Np *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_returnType != NULL) && (ZListSize(t->Vf_returnType) > 0));
 return r;
}
Tl *YmXD(Y7Np *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_templateTypeName;
 return r;
}
Y7Np *YxF_(Y7Np *t, Tl *Al) {
 Y7Np *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_templateTypeName = Al;
 r = t;
 return r;
}
Tb Yq8G(Y7Np *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_templateTypeName != NULL) && (ZListSize(t->Vf_templateTypeName) > 0));
 return r;
}
Y7Np *YWsV(Y7Np *t, YYIi *Av) {
 Zsf sf;
 Y7Np *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4545200;
  ZthrowThisNil();
 }
 sf.pos=4545201;
 if ((t->Vf_argument == NULL))
 {
  sf.pos=4545202;
  t->Vf_argument = ZnewList((Tt*)&YYIi__T, 0);
 }
 sf.pos=4545203;
 ZLap((Tl*)t->Vf_argument, (Tz)(void*)Av);
 sf.pos=4545204;
 r = t;
 topFrame = sf.prev;
 return r;
}
YYIi *YG6V(Y7Np *t) {
 Zsf sf;
 YYIi *r = 0;
 YYIi *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=79400;
  ZthrowThisNil();
 }
 sf.pos=79401;
 Vv = YpQb(NULL);
 sf.pos=79402;
 YWsV(t, Vv);
 sf.pos=79403;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Tl *Y8dZ(Y7Np *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_argument;
 return r;
}
Y7Np *YT39(Y7Np *t, YYIi *Av) {
 Zsf sf;
 Y7Np *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=179800;
  ZthrowThisNil();
 }
 sf.pos=179801;
 if ((t->Vf_use == NULL))
 {
  sf.pos=179802;
  t->Vf_use = ZnewList((Tt*)&YYIi__T, 0);
 }
 sf.pos=179803;
 ZLap((Tl*)t->Vf_use, (Tz)(void*)Av);
 sf.pos=179804;
 r = t;
 topFrame = sf.prev;
 return r;
}
YYIi *YyeO(Y7Np *t) {
 Zsf sf;
 YYIi *r = 0;
 YYIi *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1225200;
  ZthrowThisNil();
 }
 sf.pos=1225201;
 Vv = YpQb(NULL);
 sf.pos=1225202;
 YT39(t, Vv);
 sf.pos=1225203;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Y7Np *Y4cF(Y7Np *t, YhZL *Av) {
 Y7Np *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_body = Av;
 r = t;
 return r;
}
Y7Np *YI0V(Y7Np *t, YnZD *Av) {
 Y7Np *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_expr = Av;
 r = t;
 return r;
}
Y7Np *Yt_q(Y7Np *t, Tb Adeep) {
 Zsf sf;
 Y7Np *r = 0;
 Y7Np *Vret = 0;
 Tl *Zf3 = NULL;
 YRBza *Vi = 0;
 Tl *Zf31 = NULL;
 Tl *Zf32 = NULL;
 YYIi *Vi1 = 0;
 Tl *Zf33 = NULL;
 YYIi *Vi2 = 0;
 Y1p4 *Vi3 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1083100;
  ZthrowThisNil();
 }
 sf.pos=1083101;
 Vret = YWVR(NULL);
 sf.pos=1083102;
 if (Adeep)
 {
  sf.pos=1083103;
  if ((t->Vf_returnType != NULL))
  {
   sf.pos=1083104;
   Vret->Vf_returnType = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=1083105;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_returnType;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=1083106;
    ZLap((Tl*)Vret->Vf_returnType, (Tz)(void*)YK7D(Vi, Adeep));
    sf.pos=1083107;
    }
   }
  }
 }
 else
 {
  sf.pos=1083108;
  Vret->Vf_returnType = t->Vf_returnType;
 }
 sf.pos=1083109;
 if (Adeep)
 {
  sf.pos=1083110;
  if ((t->Vf_templateTypeName != NULL))
  {
   sf.pos=1083111;
   Vret->Vf_templateTypeName = ZnewList((Tt*)&Y1p4__T, 0);
   sf.pos=1083112;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_templateTypeName;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi3;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=1083113;
    ZLap((Tl*)Vret->Vf_templateTypeName, (Tz)(void*)Y_4M(Vi3, Adeep));
    sf.pos=1083114;
    }
   }
  }
 }
 else
 {
  sf.pos=1083115;
  Vret->Vf_templateTypeName = t->Vf_templateTypeName;
 }
 sf.pos=1083116;
 if (Adeep)
 {
  sf.pos=1083117;
  if ((t->Vf_argument != NULL))
  {
   sf.pos=1083118;
   Vret->Vf_argument = ZnewList((Tt*)&YYIi__T, 0);
   sf.pos=1083119;
   {
    Tfl Zf32i;
    Zf32 = t->Vf_argument;
    Zf32i.l = Zf32;
    Zf32i.valp = (void*)&Vi1;
    Zf32i.i = 0;
    for (; ZforListPtrCont(&Zf32i); ) {
    sf.pos=1083120;
    ZLap((Tl*)Vret->Vf_argument, (Tz)(void*)YTec(Vi1, Adeep));
    sf.pos=1083121;
    }
   }
  }
 }
 else
 {
  sf.pos=1083122;
  Vret->Vf_argument = t->Vf_argument;
 }
 sf.pos=1083123;
 if (Adeep)
 {
  sf.pos=1083124;
  if ((t->Vf_use != NULL))
  {
   sf.pos=1083125;
   Vret->Vf_use = ZnewList((Tt*)&YYIi__T, 0);
   sf.pos=1083126;
   {
    Tfl Zf33i;
    Zf33 = t->Vf_use;
    Zf33i.l = Zf33;
    Zf33i.valp = (void*)&Vi2;
    Zf33i.i = 0;
    for (; ZforListPtrCont(&Zf33i); ) {
    sf.pos=1083127;
    ZLap((Tl*)Vret->Vf_use, (Tz)(void*)YTec(Vi2, Adeep));
    sf.pos=1083128;
    }
   }
  }
 }
 else
 {
  sf.pos=1083129;
  Vret->Vf_use = t->Vf_use;
 }
 sf.pos=1083130;
 if ((t->Vf_body != NULL))
 {
  sf.pos=1083131;
  Vret->Vf_body = ((Adeep) ? (Yzft(t->Vf_body, Adeep)) : (t->Vf_body));
 }
 sf.pos=1083132;
 if ((t->Vf_expr != NULL))
 {
  sf.pos=1083133;
  Vret->Vf_expr = ((Adeep) ? (Ypps(t->Vf_expr, Adeep)) : (t->Vf_expr));
 }
 sf.pos=1083134;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToY7Np[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* f_returnType */
 {0, (Tt*)&list__T}, /* f_templateTypeName */
 {0, (Tt*)&list__T}, /* f_argument */
 {0, (Tt*)&list__T}, /* f_use */
 {0, (Tt*)&YhZL__T}, /* f_body */
 {0, (Tt*)&YnZD__T}, /* f_expr */
};
Tto Y7Np__T = {390, (Tc*)&Yl9L, 0, ToY7Np};
YyfS *YvNY(YyfS *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3188800; t = Za(sizeof(YyfS));}
 topFrame = sf.prev;
 return t;
}
YyfS *YLOM(YyfS *t, Tb Adeep) {
 Zsf sf;
 YyfS *r = 0;
 YyfS *Vret = 0;
 Tl *Zf3 = NULL;
 YRBza *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4846900;
  ZthrowThisNil();
 }
 sf.pos=4846901;
 Vret = YvNY(NULL);
 sf.pos=4846902;
 if ((t->Vf_keyType != NULL))
 {
  sf.pos=4846903;
  Vret->Vf_keyType = ((Adeep) ? (YK7D(t->Vf_keyType, Adeep)) : (t->Vf_keyType));
 }
 sf.pos=4846904;
 if (Adeep)
 {
  sf.pos=4846905;
  if ((t->Vf_itemType != NULL))
  {
   sf.pos=4846906;
   Vret->Vf_itemType = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=4846907;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_itemType;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=4846908;
    ZLap((Tl*)Vret->Vf_itemType, (Tz)(void*)YK7D(Vi, Adeep));
    sf.pos=4846909;
    }
   }
  }
 }
 else
 {
  sf.pos=4846910;
  Vret->Vf_itemType = t->Vf_itemType;
 }
 sf.pos=4846911;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYyfS[] = {
 {2, 0},
 {0, (Tt*)&YRBza__T}, /* f_keyType */
 {0, (Tt*)&list__T}, /* f_itemType */
};
Tto YyfS__T = {390, (Tc*)&YmBB, 0, ToYyfS};
YoDF *YRGj(YoDF *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9752700; t = Za(sizeof(YoDF));}
 topFrame = sf.prev;
 return t;
}
YoDF *YpwO(YoDF *t, YnZD *Av) {
 YoDF *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_from = Av;
 r = t;
 return r;
}
YnZD *YdCW(YoDF *t) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_from == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YObi);
  ZthrowPos(6162900, ex);
 }
 r = t->Vf_from;
 return r;
}
YoDF *Yit4(YoDF *t, Tc *Av) {
 YoDF *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
YoDF *YlIy(YoDF *t, YXCg *Av) {
 YoDF *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_for = Av;
 r = t;
 return r;
}
YXCg *YiDy(YoDF *t) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_for == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YsP0);
  ZthrowPos(6595200, ex);
 }
 r = t->Vf_for;
 return r;
}
Tb YNTP(YoDF *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_for != NULL);
 return r;
}
YoDF *YL4I(YoDF *t, Tb Adeep) {
 Zsf sf;
 YoDF *r = 0;
 YoDF *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9416800;
  ZthrowThisNil();
 }
 sf.pos=9416801;
 Vret = YRGj(NULL);
 sf.pos=9416802;
 if ((t->Vf_from != NULL))
 {
  sf.pos=9416803;
  Vret->Vf_from = ((Adeep) ? (Ypps(t->Vf_from, Adeep)) : (t->Vf_from));
 }
 sf.pos=9416804;
 Vret->Vf_name = t->Vf_name;
 sf.pos=9416805;
 if ((t->Vf_for != NULL))
 {
  sf.pos=9416806;
  Vret->Vf_for = ((Adeep) ? (Y9N8(t->Vf_for, Adeep)) : (t->Vf_for));
 }
 sf.pos=9416807;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYoDF[] = {
 {3, 0},
 {0, (Tt*)&YnZD__T}, /* f_from */
 {0, (Tt*)&string__T}, /* f_name */
 {0, (Tt*)&YXCg__T}, /* f_for */
};
Tto YoDF__T = {390, (Tc*)&Ynrc, 0, ToYoDF};
YhZL *YBTx(YhZL *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1308100; t = Za(sizeof(YhZL));}
 topFrame = sf.prev;
 return t;
}
YhZL *YtnA(YhZL *t, Ysbp *Av) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
YhZL *YFf4(YhZL *t, Ysbp *Av) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_endPos = Av;
 r = t;
 return r;
}
YhZL *Y0lJ(YhZL *t, YXCg *Av) {
 Zsf sf;
 YhZL *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=46500;
  ZthrowThisNil();
 }
 sf.pos=46501;
 if ((t->Vf_statement == NULL))
 {
  sf.pos=46502;
  t->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
 }
 sf.pos=46503;
 ZLap((Tl*)t->Vf_statement, (Tz)(void*)Av);
 sf.pos=46504;
 r = t;
 topFrame = sf.prev;
 return r;
}
Tl *Yb8Y(YhZL *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_statement;
 return r;
}
YhZL *YRIK(YhZL *t, Tl *Al) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_statement = Al;
 r = t;
 return r;
}
Tb YJD1(YhZL *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = ((t->Vf_statement != NULL) && (ZListSize(t->Vf_statement) > 0));
 return r;
}
YhZL *Yzft(YhZL *t, Tb Adeep) {
 Zsf sf;
 YhZL *r = 0;
 YhZL *Vret = 0;
 Tl *Zf3 = NULL;
 YXCg *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1673800;
  ZthrowThisNil();
 }
 sf.pos=1673801;
 Vret = YBTx(NULL);
 sf.pos=1673802;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=1673803;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=1673804;
 if ((t->Vf_endPos != NULL))
 {
  sf.pos=1673805;
  Vret->Vf_endPos = ((Adeep) ? (Yw4M(t->Vf_endPos, Adeep)) : (t->Vf_endPos));
 }
 sf.pos=1673806;
 if (Adeep)
 {
  sf.pos=1673807;
  if ((t->Vf_statement != NULL))
  {
   sf.pos=1673808;
   Vret->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=1673809;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_statement;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=1673810;
    ZLap((Tl*)Vret->Vf_statement, (Tz)(void*)Y9N8(Vi, Adeep));
    sf.pos=1673811;
    }
   }
  }
 }
 else
 {
  sf.pos=1673812;
  Vret->Vf_statement = t->Vf_statement;
 }
 sf.pos=1673813;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYhZL[] = {
 {3, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&Ysbp__T}, /* f_endPos */
 {0, (Tt*)&list__T}, /* f_statement */
};
Tto YhZL__T = {390, (Tc*)&Yu55, 0, ToYhZL};
YXCg *YDNI(YXCg *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7765600; t = Za(sizeof(YXCg));}
 topFrame = sf.prev;
 return t;
}
YXCg *YZqm(YXCg *t, Ysbp *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
Ysbp *YWlm(YXCg *t) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_pos == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y6Oda);
  ZthrowPos(1577600, ex);
 }
 r = t->Vf_pos;
 return r;
}
YXCg *Yiw6(YXCg *t, Te Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Av;
 r = t;
 return r;
}
Te YuqZ(YXCg *t) {
 Te r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_type == 0))
 {
  void *ex = NULL;
  ex = ((Tc*)&YM0N);
  ZthrowPos(2716800, ex);
 }
 r = t->Vf_type;
 return r;
}
YXCg *Yh4I(YXCg *t, YYIi *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_declaration = Av;
 r = t;
 return r;
}
YYIi *YK2t(YXCg *t) {
 Zsf sf;
 YYIi *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9436200;
  ZthrowThisNil();
 }
 sf.pos=9436201;
 t->Vf_declaration = YpQb(NULL);
 sf.pos=9436202;
 r = t->Vf_declaration;
 topFrame = sf.prev;
 return r;
}
YYIi *YjGb(YXCg *t) {
 YYIi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_declaration == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YIL3);
  ZthrowPos(6048000, ex);
 }
 r = t->Vf_declaration;
 return r;
}
Tb YGtH(YXCg *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_declaration != NULL);
 return r;
}
YXCg *YCIA(YXCg *t, YfBB *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_include = Av;
 r = t;
 return r;
}
YfBB *Yaja(YXCg *t) {
 YfBB *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_include == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YtKs);
  ZthrowPos(8502200, ex);
 }
 r = t->Vf_include;
 return r;
}
YXCg *Yw4A(YXCg *t, Yq22 *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_assign = Av;
 r = t;
 return r;
}
YXCg *YM__(YXCg *t, Y_1n *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_methodCall = Av;
 r = t;
 return r;
}
YXCg *YYdx(YXCg *t, Y5eh *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_condition = Av;
 r = t;
 return r;
}
Y5eh *YpRA(YXCg *t) {
 Zsf sf;
 Y5eh *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1185100;
  ZthrowThisNil();
 }
 sf.pos=1185101;
 t->Vf_condition = Y4Kn(NULL);
 sf.pos=1185102;
 r = t->Vf_condition;
 topFrame = sf.prev;
 return r;
}
Y5eh *YCoj(YXCg *t) {
 Y5eh *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_condition == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YuH4);
  ZthrowPos(6867300, ex);
 }
 r = t->Vf_condition;
 return r;
}
YXCg *Yc8L(YXCg *t, Yxh9 *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_for = Av;
 r = t;
 return r;
}
YXCg *Yo4b(YXCg *t, Yy74 *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_try = Av;
 r = t;
 return r;
}
YXCg *Yq9q(YXCg *t, YhZL *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_block = Av;
 r = t;
 return r;
}
YhZL *YFQs(YXCg *t) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_block == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YB3y);
  ZthrowPos(510500, ex);
 }
 r = t->Vf_block;
 return r;
}
Tb Ycfv(YXCg *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_block != NULL);
 return r;
}
YXCg *YMTX(YXCg *t, YnZD *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_expr = Av;
 r = t;
 return r;
}
YXCg *YkEo(YXCg *t, Tl *Al) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_arguments = Al;
 r = t;
 return r;
}
YXCg *YGJp(YXCg *t, YLuR *Av) {
 Zsf sf;
 YXCg *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7972900;
  ZthrowThisNil();
 }
 sf.pos=7972901;
 if ((t->Vf_cblock == NULL))
 {
  sf.pos=7972902;
  t->Vf_cblock = ZnewList((Tt*)&YLuR__T, 0);
 }
 sf.pos=7972903;
 ZLap((Tl*)t->Vf_cblock, (Tz)(void*)Av);
 sf.pos=7972904;
 r = t;
 topFrame = sf.prev;
 return r;
}
YXCg *YBVz(YXCg *t, Ysbp *Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_proceedPos = Av;
 r = t;
 return r;
}
YXCg *YpTx(YXCg *t, Tb Av) {
 YXCg *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_blockgc = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YXCg *YGDU(YXCg *t, YXCg *Av) {
 Zsf sf;
 YXCg *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1975600;
  ZthrowThisNil();
 }
 sf.pos=1975601;
 if ((t->Vf_statement == NULL))
 {
  sf.pos=1975602;
  t->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
 }
 sf.pos=1975603;
 ZLap((Tl*)t->Vf_statement, (Tz)(void*)Av);
 sf.pos=1975604;
 r = t;
 topFrame = sf.prev;
 return r;
}
Tl *YM4H(YXCg *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_statement;
 return r;
}
YXCg *Y9N8(YXCg *t, Tb Adeep) {
 Zsf sf;
 YXCg *r = 0;
 YXCg *Vret = 0;
 Tl *Zf3 = NULL;
 Tl *Zf31 = NULL;
 Tl *Zf32 = NULL;
 YXCg *Vi = 0;
 YnZD *Vi1 = 0;
 YLuR *Vi2 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3538900;
  ZthrowThisNil();
 }
 sf.pos=3538901;
 Vret = YDNI(NULL);
 sf.pos=3538902;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=3538903;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=3538904;
 Vret->Vf_type = t->Vf_type;
 sf.pos=3538905;
 if ((t->Vf_declaration != NULL))
 {
  sf.pos=3538906;
  Vret->Vf_declaration = ((Adeep) ? (YTec(t->Vf_declaration, Adeep)) : (t->Vf_declaration));
 }
 sf.pos=3538907;
 if ((t->Vf_include != NULL))
 {
  sf.pos=3538908;
  Vret->Vf_include = ((Adeep) ? (Y8pz(t->Vf_include, Adeep)) : (t->Vf_include));
 }
 sf.pos=3538909;
 if ((t->Vf_assign != NULL))
 {
  sf.pos=3538910;
  Vret->Vf_assign = ((Adeep) ? (YPgi(t->Vf_assign, Adeep)) : (t->Vf_assign));
 }
 sf.pos=3538911;
 if ((t->Vf_methodCall != NULL))
 {
  sf.pos=3538912;
  Vret->Vf_methodCall = ((Adeep) ? (Y6Kb(t->Vf_methodCall, Adeep)) : (t->Vf_methodCall));
 }
 sf.pos=3538913;
 if ((t->Vf_condition != NULL))
 {
  sf.pos=3538914;
  Vret->Vf_condition = ((Adeep) ? (Y3dy(t->Vf_condition, Adeep)) : (t->Vf_condition));
 }
 sf.pos=3538915;
 if ((t->Vf_for != NULL))
 {
  sf.pos=3538916;
  Vret->Vf_for = ((Adeep) ? (YDH2(t->Vf_for, Adeep)) : (t->Vf_for));
 }
 sf.pos=3538917;
 if ((t->Vf_try != NULL))
 {
  sf.pos=3538918;
  Vret->Vf_try = ((Adeep) ? (YCDC(t->Vf_try, Adeep)) : (t->Vf_try));
 }
 sf.pos=3538919;
 if ((t->Vf_block != NULL))
 {
  sf.pos=3538920;
  Vret->Vf_block = ((Adeep) ? (Yzft(t->Vf_block, Adeep)) : (t->Vf_block));
 }
 sf.pos=3538921;
 if ((t->Vf_expr != NULL))
 {
  sf.pos=3538922;
  Vret->Vf_expr = ((Adeep) ? (Ypps(t->Vf_expr, Adeep)) : (t->Vf_expr));
 }
 sf.pos=3538923;
 if (Adeep)
 {
  sf.pos=3538924;
  if ((t->Vf_arguments != NULL))
  {
   sf.pos=3538925;
   Vret->Vf_arguments = ZnewList((Tt*)&YnZD__T, 0);
   sf.pos=3538926;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_arguments;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi1;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=3538927;
    ZLap((Tl*)Vret->Vf_arguments, (Tz)(void*)Ypps(Vi1, Adeep));
    sf.pos=3538928;
    }
   }
  }
 }
 else
 {
  sf.pos=3538929;
  Vret->Vf_arguments = t->Vf_arguments;
 }
 sf.pos=3538930;
 if (Adeep)
 {
  sf.pos=3538931;
  if ((t->Vf_cblock != NULL))
  {
   sf.pos=3538932;
   Vret->Vf_cblock = ZnewList((Tt*)&YLuR__T, 0);
   sf.pos=3538933;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_cblock;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi2;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=3538934;
    ZLap((Tl*)Vret->Vf_cblock, (Tz)(void*)YsIm(Vi2, Adeep));
    sf.pos=3538935;
    }
   }
  }
 }
 else
 {
  sf.pos=3538936;
  Vret->Vf_cblock = t->Vf_cblock;
 }
 sf.pos=3538937;
 if ((t->Vf_proceedPos != NULL))
 {
  sf.pos=3538938;
  Vret->Vf_proceedPos = ((Adeep) ? (Yw4M(t->Vf_proceedPos, Adeep)) : (t->Vf_proceedPos));
 }
 sf.pos=3538939;
 Vret->Vf_blockgc = t->Vf_blockgc;
 sf.pos=3538940;
 if (Adeep)
 {
  sf.pos=3538941;
  if ((t->Vf_statement != NULL))
  {
   sf.pos=3538942;
   Vret->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=3538943;
   {
    Tfl Zf32i;
    Zf32 = t->Vf_statement;
    Zf32i.l = Zf32;
    Zf32i.valp = (void*)&Vi;
    Zf32i.i = 0;
    for (; ZforListPtrCont(&Zf32i); ) {
    sf.pos=3538944;
    ZLap((Tl*)Vret->Vf_statement, (Tz)(void*)Y9N8(Vi, Adeep));
    sf.pos=3538945;
    }
   }
  }
 }
 else
 {
  sf.pos=3538946;
  Vret->Vf_statement = t->Vf_statement;
 }
 sf.pos=3538947;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYXCg[] = {
 {14, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&YYIi__T}, /* f_declaration */
 {0, (Tt*)&YfBB__T}, /* f_include */
 {0, (Tt*)&Yq22__T}, /* f_assign */
 {0, (Tt*)&Y_1n__T}, /* f_methodCall */
 {0, (Tt*)&Y5eh__T}, /* f_condition */
 {0, (Tt*)&Yxh9__T}, /* f_for */
 {0, (Tt*)&Yy74__T}, /* f_try */
 {0, (Tt*)&YhZL__T}, /* f_block */
 {0, (Tt*)&YnZD__T}, /* f_expr */
 {0, (Tt*)&list__T}, /* f_arguments */
 {0, (Tt*)&list__T}, /* f_cblock */
 {0, (Tt*)&Ysbp__T}, /* f_proceedPos */
 {0, (Tt*)&list__T}, /* f_statement */
};
Tto YXCg__T = {390, (Tc*)&YPrB, 0, ToYXCg};
YfBB *Y48I(YfBB *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6406700; t = Za(sizeof(YfBB));}
 topFrame = sf.prev;
 return t;
}
Tl *YXSw(YfBB *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_statement;
 return r;
}
YfBB *YZnt(YfBB *t, Tl *Al) {
 YfBB *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_statement = Al;
 r = t;
 return r;
}
YfBB *Y8pz(YfBB *t, Tb Adeep) {
 Zsf sf;
 YfBB *r = 0;
 YfBB *Vret = 0;
 Tl *Zf3 = NULL;
 YXCg *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6290000;
  ZthrowThisNil();
 }
 sf.pos=6290001;
 Vret = Y48I(NULL);
 sf.pos=6290002;
 if (Adeep)
 {
  sf.pos=6290003;
  if ((t->Vf_statement != NULL))
  {
   sf.pos=6290004;
   Vret->Vf_statement = ZnewList((Tt*)&YXCg__T, 0);
   sf.pos=6290005;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_statement;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=6290006;
    ZLap((Tl*)Vret->Vf_statement, (Tz)(void*)Y9N8(Vi, Adeep));
    sf.pos=6290007;
    }
   }
  }
 }
 else
 {
  sf.pos=6290008;
  Vret->Vf_statement = t->Vf_statement;
 }
 sf.pos=6290009;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYfBB[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* f_statement */
};
Tto YfBB__T = {390, (Tc*)&YghR, 0, ToYfBB};
Yq22 *YZ8B(Yq22 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=496800; t = Za(sizeof(Yq22));}
 topFrame = sf.prev;
 return t;
}
Yq22 *YhEN(Yq22 *t, Te Av) {
 Yq22 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Av;
 r = t;
 return r;
}
Yq22 *Y2Ep(Yq22 *t, YnZD *Av) {
 Yq22 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_lhs = Av;
 r = t;
 return r;
}
Yq22 *Yz4E(Yq22 *t, YnZD *Av) {
 Yq22 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_rhs = Av;
 r = t;
 return r;
}
Yq22 *YPgi(Yq22 *t, Tb Adeep) {
 Zsf sf;
 Yq22 *r = 0;
 Yq22 *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2308500;
  ZthrowThisNil();
 }
 sf.pos=2308501;
 Vret = YZ8B(NULL);
 sf.pos=2308502;
 Vret->Vf_type = t->Vf_type;
 sf.pos=2308503;
 if ((t->Vf_lhs != NULL))
 {
  sf.pos=2308504;
  Vret->Vf_lhs = ((Adeep) ? (Ypps(t->Vf_lhs, Adeep)) : (t->Vf_lhs));
 }
 sf.pos=2308505;
 if ((t->Vf_rhs != NULL))
 {
  sf.pos=2308506;
  Vret->Vf_rhs = ((Adeep) ? (Ypps(t->Vf_rhs, Adeep)) : (t->Vf_rhs));
 }
 sf.pos=2308507;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYq22[] = {
 {2, 0},
 {0, (Tt*)&YnZD__T}, /* f_lhs */
 {0, (Tt*)&YnZD__T}, /* f_rhs */
};
Tto Yq22__T = {390, (Tc*)&Y2U7, 0, ToYq22};
Y5eh *Y4Kn(Y5eh *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=673400; t = Za(sizeof(Y5eh));}
 topFrame = sf.prev;
 return t;
}
Y5eh *YpGq(Y5eh *t, YnZD *Av) {
 Y5eh *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_cond = Av;
 r = t;
 return r;
}
Y5eh *YNhk(Y5eh *t, YhZL *Av) {
 Y5eh *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_block = Av;
 r = t;
 return r;
}
YhZL *YzLV(Y5eh *t) {
 Zsf sf;
 YhZL *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3229700;
  ZthrowThisNil();
 }
 sf.pos=3229701;
 t->Vf_block = YBTx(NULL);
 sf.pos=3229702;
 r = t->Vf_block;
 topFrame = sf.prev;
 return r;
}
YhZL *Y1Yl(Y5eh *t) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_block == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YB3y);
  ZthrowPos(7388700, ex);
 }
 r = t->Vf_block;
 return r;
}
Tb Yzno(Y5eh *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_block != NULL);
 return r;
}
Y5eh *Yucl(Y5eh *t, Y5eh *Av) {
 Zsf sf;
 Y5eh *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2643700;
  ZthrowThisNil();
 }
 sf.pos=2643701;
 if ((t->Vf_elseif == NULL))
 {
  sf.pos=2643702;
  t->Vf_elseif = ZnewList((Tt*)&Y5eh__T, 0);
 }
 sf.pos=2643703;
 ZLap((Tl*)t->Vf_elseif, (Tz)(void*)Av);
 sf.pos=2643704;
 r = t;
 topFrame = sf.prev;
 return r;
}
Y5eh *YbNt(Y5eh *t) {
 Zsf sf;
 Y5eh *r = 0;
 Y5eh *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5147500;
  ZthrowThisNil();
 }
 sf.pos=5147501;
 Vv = Y4Kn(NULL);
 sf.pos=5147502;
 Yucl(t, Vv);
 sf.pos=5147503;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Tl *YPh5(Y5eh *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_elseif;
 return r;
}
Y5eh *Ya5i(Y5eh *t, YhZL *Av) {
 Y5eh *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_else = Av;
 r = t;
 return r;
}
YhZL *Ym_a(Y5eh *t) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_else == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YqLt);
  ZthrowPos(8648500, ex);
 }
 r = t->Vf_else;
 return r;
}
Tb Y3qR(Y5eh *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_else != NULL);
 return r;
}
Y5eh *Y3dy(Y5eh *t, Tb Adeep) {
 Zsf sf;
 Y5eh *r = 0;
 Y5eh *Vret = 0;
 Tl *Zf3 = NULL;
 Y5eh *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3044300;
  ZthrowThisNil();
 }
 sf.pos=3044301;
 Vret = Y4Kn(NULL);
 sf.pos=3044302;
 if ((t->Vf_cond != NULL))
 {
  sf.pos=3044303;
  Vret->Vf_cond = ((Adeep) ? (Ypps(t->Vf_cond, Adeep)) : (t->Vf_cond));
 }
 sf.pos=3044304;
 if ((t->Vf_block != NULL))
 {
  sf.pos=3044305;
  Vret->Vf_block = ((Adeep) ? (Yzft(t->Vf_block, Adeep)) : (t->Vf_block));
 }
 sf.pos=3044306;
 if (Adeep)
 {
  sf.pos=3044307;
  if ((t->Vf_elseif != NULL))
  {
   sf.pos=3044308;
   Vret->Vf_elseif = ZnewList((Tt*)&Y5eh__T, 0);
   sf.pos=3044309;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_elseif;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=3044310;
    ZLap((Tl*)Vret->Vf_elseif, (Tz)(void*)Y3dy(Vi, Adeep));
    sf.pos=3044311;
    }
   }
  }
 }
 else
 {
  sf.pos=3044312;
  Vret->Vf_elseif = t->Vf_elseif;
 }
 sf.pos=3044313;
 if ((t->Vf_else != NULL))
 {
  sf.pos=3044314;
  Vret->Vf_else = ((Adeep) ? (Yzft(t->Vf_else, Adeep)) : (t->Vf_else));
 }
 sf.pos=3044315;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToY5eh[] = {
 {4, 0},
 {0, (Tt*)&YnZD__T}, /* f_cond */
 {0, (Tt*)&YhZL__T}, /* f_block */
 {0, (Tt*)&list__T}, /* f_elseif */
 {0, (Tt*)&YhZL__T}, /* f_else */
};
Tto Y5eh__T = {390, (Tc*)&YGPA, 0, ToY5eh};
Yxh9 *Yx2D(Yxh9 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=5690300; t = Za(sizeof(Yxh9));}
 topFrame = sf.prev;
 return t;
}
Yxh9 *YEk6(Yxh9 *t, YYIi *Av) {
 Zsf sf;
 Yxh9 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7052100;
  ZthrowThisNil();
 }
 sf.pos=7052101;
 if ((t->Vf_loopVar == NULL))
 {
  sf.pos=7052102;
  t->Vf_loopVar = ZnewList((Tt*)&YYIi__T, 0);
 }
 sf.pos=7052103;
 ZLap((Tl*)t->Vf_loopVar, (Tz)(void*)Av);
 sf.pos=7052104;
 r = t;
 topFrame = sf.prev;
 return r;
}
Ti YCdt(Yxh9 *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (((t->Vf_loopVar == NULL)) ? (0) : (ZListSize(t->Vf_loopVar)));
 return r;
}
Yxh9 *YMOM(Yxh9 *t, YnZD *Av) {
 Zsf sf;
 Yxh9 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2845400;
  ZthrowThisNil();
 }
 sf.pos=2845401;
 if ((t->Vf_iter == NULL))
 {
  sf.pos=2845402;
  t->Vf_iter = ZnewList((Tt*)&YnZD__T, 0);
 }
 sf.pos=2845403;
 ZLap((Tl*)t->Vf_iter, (Tz)(void*)Av);
 sf.pos=2845404;
 r = t;
 topFrame = sf.prev;
 return r;
}
Yxh9 *YmBG(Yxh9 *t, YnZD *Av) {
 Yxh9 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_to = Av;
 r = t;
 return r;
}
Yxh9 *YV_5(Yxh9 *t, YnZD *Av) {
 Yxh9 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_until = Av;
 r = t;
 return r;
}
Yxh9 *YiIU(Yxh9 *t, YnZD *Av) {
 Yxh9 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_step = Av;
 r = t;
 return r;
}
YhZL *YCBH(Yxh9 *t) {
 Zsf sf;
 YhZL *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8658100;
  ZthrowThisNil();
 }
 sf.pos=8658101;
 t->Vf_body = YBTx(NULL);
 sf.pos=8658102;
 r = t->Vf_body;
 topFrame = sf.prev;
 return r;
}
Yxh9 *YDH2(Yxh9 *t, Tb Adeep) {
 Zsf sf;
 Yxh9 *r = 0;
 Yxh9 *Vret = 0;
 Tl *Zf3 = NULL;
 YYIi *Vi = 0;
 Tl *Zf31 = NULL;
 YnZD *Vi1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7184800;
  ZthrowThisNil();
 }
 sf.pos=7184801;
 Vret = Yx2D(NULL);
 sf.pos=7184802;
 if (Adeep)
 {
  sf.pos=7184803;
  if ((t->Vf_loopVar != NULL))
  {
   sf.pos=7184804;
   Vret->Vf_loopVar = ZnewList((Tt*)&YYIi__T, 0);
   sf.pos=7184805;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_loopVar;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=7184806;
    ZLap((Tl*)Vret->Vf_loopVar, (Tz)(void*)YTec(Vi, Adeep));
    sf.pos=7184807;
    }
   }
  }
 }
 else
 {
  sf.pos=7184808;
  Vret->Vf_loopVar = t->Vf_loopVar;
 }
 sf.pos=7184809;
 if (Adeep)
 {
  sf.pos=7184810;
  if ((t->Vf_iter != NULL))
  {
   sf.pos=7184811;
   Vret->Vf_iter = ZnewList((Tt*)&YnZD__T, 0);
   sf.pos=7184812;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_iter;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi1;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=7184813;
    ZLap((Tl*)Vret->Vf_iter, (Tz)(void*)Ypps(Vi1, Adeep));
    sf.pos=7184814;
    }
   }
  }
 }
 else
 {
  sf.pos=7184815;
  Vret->Vf_iter = t->Vf_iter;
 }
 sf.pos=7184816;
 if ((t->Vf_to != NULL))
 {
  sf.pos=7184817;
  Vret->Vf_to = ((Adeep) ? (Ypps(t->Vf_to, Adeep)) : (t->Vf_to));
 }
 sf.pos=7184818;
 if ((t->Vf_until != NULL))
 {
  sf.pos=7184819;
  Vret->Vf_until = ((Adeep) ? (Ypps(t->Vf_until, Adeep)) : (t->Vf_until));
 }
 sf.pos=7184820;
 if ((t->Vf_step != NULL))
 {
  sf.pos=7184821;
  Vret->Vf_step = ((Adeep) ? (Ypps(t->Vf_step, Adeep)) : (t->Vf_step));
 }
 sf.pos=7184822;
 if ((t->Vf_body != NULL))
 {
  sf.pos=7184823;
  Vret->Vf_body = ((Adeep) ? (Yzft(t->Vf_body, Adeep)) : (t->Vf_body));
 }
 sf.pos=7184824;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYxh9[] = {
 {6, 0},
 {0, (Tt*)&list__T}, /* f_loopVar */
 {0, (Tt*)&list__T}, /* f_iter */
 {0, (Tt*)&YnZD__T}, /* f_to */
 {0, (Tt*)&YnZD__T}, /* f_until */
 {0, (Tt*)&YnZD__T}, /* f_step */
 {0, (Tt*)&YhZL__T}, /* f_body */
};
Tto Yxh9__T = {390, (Tc*)&YoLj, 0, ToYxh9};
Yy74 *YNpV(Yy74 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4231500; t = Za(sizeof(Yy74));}
 topFrame = sf.prev;
 return t;
}
Yy74 *YM0M(Yy74 *t, YhZL *Av) {
 Yy74 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_body = Av;
 r = t;
 return r;
}
YhZL *YA6U(Yy74 *t) {
 YhZL *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_body == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YBft);
  ZthrowPos(9419900, ex);
 }
 r = t->Vf_body;
 return r;
}
Yy74 *YPVu(Yy74 *t, Ya9G *Av) {
 Zsf sf;
 Yy74 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5721300;
  ZthrowThisNil();
 }
 sf.pos=5721301;
 if ((t->Vf_catch == NULL))
 {
  sf.pos=5721302;
  t->Vf_catch = ZnewList((Tt*)&Ya9G__T, 0);
 }
 sf.pos=5721303;
 ZLap((Tl*)t->Vf_catch, (Tz)(void*)Av);
 sf.pos=5721304;
 r = t;
 topFrame = sf.prev;
 return r;
}
Ya9G *YNyp(Yy74 *t) {
 Zsf sf;
 Ya9G *r = 0;
 Ya9G *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3441500;
  ZthrowThisNil();
 }
 sf.pos=3441501;
 Vv = Ynwi(NULL);
 sf.pos=3441502;
 YPVu(t, Vv);
 sf.pos=3441503;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
Yy74 *YHr1a(Yy74 *t, YhZL *Av) {
 Yy74 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_else = Av;
 r = t;
 return r;
}
Yy74 *YFQt(Yy74 *t, YhZL *Av) {
 Yy74 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_finally = Av;
 r = t;
 return r;
}
Yy74 *YCDC(Yy74 *t, Tb Adeep) {
 Zsf sf;
 Yy74 *r = 0;
 Yy74 *Vret = 0;
 Tl *Zf3 = NULL;
 Ya9G *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=473200;
  ZthrowThisNil();
 }
 sf.pos=473201;
 Vret = YNpV(NULL);
 sf.pos=473202;
 if ((t->Vf_body != NULL))
 {
  sf.pos=473203;
  Vret->Vf_body = ((Adeep) ? (Yzft(t->Vf_body, Adeep)) : (t->Vf_body));
 }
 sf.pos=473204;
 if (Adeep)
 {
  sf.pos=473205;
  if ((t->Vf_catch != NULL))
  {
   sf.pos=473206;
   Vret->Vf_catch = ZnewList((Tt*)&Ya9G__T, 0);
   sf.pos=473207;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_catch;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=473208;
    ZLap((Tl*)Vret->Vf_catch, (Tz)(void*)Y3_J(Vi, Adeep));
    sf.pos=473209;
    }
   }
  }
 }
 else
 {
  sf.pos=473210;
  Vret->Vf_catch = t->Vf_catch;
 }
 sf.pos=473211;
 if ((t->Vf_else != NULL))
 {
  sf.pos=473212;
  Vret->Vf_else = ((Adeep) ? (Yzft(t->Vf_else, Adeep)) : (t->Vf_else));
 }
 sf.pos=473213;
 if ((t->Vf_finally != NULL))
 {
  sf.pos=473214;
  Vret->Vf_finally = ((Adeep) ? (Yzft(t->Vf_finally, Adeep)) : (t->Vf_finally));
 }
 sf.pos=473215;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYy74[] = {
 {4, 0},
 {0, (Tt*)&YhZL__T}, /* f_body */
 {0, (Tt*)&list__T}, /* f_catch */
 {0, (Tt*)&YhZL__T}, /* f_else */
 {0, (Tt*)&YhZL__T}, /* f_finally */
};
Tto Yy74__T = {390, (Tc*)&YdWn, 0, ToYy74};
Ya9G *Ynwi(Ya9G *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=860200; t = Za(sizeof(Ya9G));}
 topFrame = sf.prev;
 return t;
}
Ya9G *YvJl(Ya9G *t, Ysbp *Av) {
 Ya9G *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
Ya9G *YpMg(Ya9G *t, Tl *Al) {
 Ya9G *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Al;
 r = t;
 return r;
}
Ya9G *Yu95(Ya9G *t, YYIi *Av) {
 Ya9G *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_decl = Av;
 r = t;
 return r;
}
Ya9G *YxIg(Ya9G *t, YhZL *Av) {
 Ya9G *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_body = Av;
 r = t;
 return r;
}
Ya9G *Y3_J(Ya9G *t, Tb Adeep) {
 Zsf sf;
 Ya9G *r = 0;
 Ya9G *Vret = 0;
 Tl *Zf3 = NULL;
 YRBza *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=931900;
  ZthrowThisNil();
 }
 sf.pos=931901;
 Vret = Ynwi(NULL);
 sf.pos=931902;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=931903;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=931904;
 if (Adeep)
 {
  sf.pos=931905;
  if ((t->Vf_type != NULL))
  {
   sf.pos=931906;
   Vret->Vf_type = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=931907;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_type;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=931908;
    ZLap((Tl*)Vret->Vf_type, (Tz)(void*)YK7D(Vi, Adeep));
    sf.pos=931909;
    }
   }
  }
 }
 else
 {
  sf.pos=931910;
  Vret->Vf_type = t->Vf_type;
 }
 sf.pos=931911;
 if ((t->Vf_decl != NULL))
 {
  sf.pos=931912;
  Vret->Vf_decl = ((Adeep) ? (YTec(t->Vf_decl, Adeep)) : (t->Vf_decl));
 }
 sf.pos=931913;
 if ((t->Vf_body != NULL))
 {
  sf.pos=931914;
  Vret->Vf_body = ((Adeep) ? (Yzft(t->Vf_body, Adeep)) : (t->Vf_body));
 }
 sf.pos=931915;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYa9G[] = {
 {4, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&list__T}, /* f_type */
 {0, (Tt*)&YYIi__T}, /* f_decl */
 {0, (Tt*)&YhZL__T}, /* f_body */
};
Tto Ya9G__T = {390, (Tc*)&Ynly, 0, ToYa9G};
YLuR *YgFm(YLuR *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7486100; t = Za(sizeof(YLuR));}
 topFrame = sf.prev;
 return t;
}
YLuR *YapJ(YLuR *t, Ysbp *Av) {
 YLuR *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
YLuR *YwGh(YLuR *t, Tl *Al) {
 YLuR *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_uses = Al;
 r = t;
 return r;
}
YLuR *YRpi(YLuR *t, Tc *Av) {
 YLuR *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_text = Av;
 r = t;
 return r;
}
YLuR *YZAk(YLuR *t, YnZD *Av) {
 YLuR *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_expr = Av;
 r = t;
 return r;
}
YLuR *YvSw(YLuR *t, Tb Av) {
 YLuR *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_literal = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YLuR *YsIm(YLuR *t, Tb Adeep) {
 Zsf sf;
 YLuR *r = 0;
 YLuR *Vret = 0;
 Tl *Zf3 = NULL;
 Tc *Vi = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4663000;
  ZthrowThisNil();
 }
 sf.pos=4663001;
 Vret = YgFm(NULL);
 sf.pos=4663002;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=4663003;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=4663004;
 if (Adeep)
 {
  sf.pos=4663005;
  if ((t->Vf_uses != NULL))
  {
   sf.pos=4663006;
   Vret->Vf_uses = ZnewList((Tt*)&string__T, 0);
   sf.pos=4663007;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_uses;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=4663008;
    ZLap((Tl*)Vret->Vf_uses, (Tz)(void*)Vi);
    sf.pos=4663009;
    }
   }
  }
 }
 else
 {
  sf.pos=4663010;
  Vret->Vf_uses = t->Vf_uses;
 }
 sf.pos=4663011;
 Vret->Vf_text = t->Vf_text;
 sf.pos=4663012;
 if ((t->Vf_expr != NULL))
 {
  sf.pos=4663013;
  Vret->Vf_expr = ((Adeep) ? (Ypps(t->Vf_expr, Adeep)) : (t->Vf_expr));
 }
 sf.pos=4663014;
 Vret->Vf_literal = t->Vf_literal;
 sf.pos=4663015;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYLuR[] = {
 {4, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&list__T}, /* f_uses */
 {0, (Tt*)&string__T}, /* f_text */
 {0, (Tt*)&YnZD__T}, /* f_expr */
};
Tto YLuR__T = {390, (Tc*)&YzI_, 0, ToYLuR};
YnZD *Y4GO(YnZD *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9366300; t = Za(sizeof(YnZD));}
 topFrame = sf.prev;
 return t;
}
YnZD *YaZq(YnZD *t, Te Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_type = Av;
 r = t;
 return r;
}
Te YmTi(YnZD *t) {
 Te r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_type == 0))
 {
  void *ex = NULL;
  ex = ((Tc*)&YM0N);
  ZthrowPos(9890300, ex);
 }
 r = t->Vf_type;
 return r;
}
YnZD *Y4_i(YnZD *t, Ysbp *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
Ysbp *Y74i(YnZD *t) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_pos == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y6Oda);
  ZthrowPos(6388300, ex);
 }
 r = t->Vf_pos;
 return r;
}
Y1p4 *YRE8(YnZD *t) {
 Zsf sf;
 Y1p4 *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=460000;
  ZthrowThisNil();
 }
 sf.pos=460001;
 t->Vf_id = YUZH(NULL);
 sf.pos=460002;
 r = t->Vf_id;
 topFrame = sf.prev;
 return r;
}
Y1p4 *YjUS(YnZD *t) {
 Y1p4 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_id == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Y5Te);
  ZthrowPos(6919000, ex);
 }
 r = t->Vf_id;
 return r;
}
YnZD *Ypk4(YnZD *t, Ti Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_number = Av;
 t->Vhas_number = 1;
 r = t;
 return r;
}
Ti YsEM(YnZD *t) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_number))
 {
  r = 0;
  rt = 1;
  goto YK8k;
 }
 r = t->Vf_number;
YK8k:
 return r;
}
YnZD *Y1BD(YnZD *t, Tf Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_fnumber = Av;
 t->Vhas_fnumber = 1;
 r = t;
 return r;
}
Tf YAcd(YnZD *t) {
 Tf r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_fnumber))
 {
  void *ex = NULL;
  ex = ((Tc*)&YPnZ);
  ZthrowPos(3220400, ex);
 }
 r = t->Vf_fnumber;
 return r;
}
YnZD *YM_T(YnZD *t, Tc *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_stringValue = Av;
 r = t;
 return r;
}
YnZD *YKTm(YnZD *t, Tl *Al) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_listItem = Al;
 r = t;
 return r;
}
Ti YMHY(YnZD *t) {
 Ti r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (((t->Vf_listItem == NULL)) ? (0) : (ZListSize(t->Vf_listItem)));
 return r;
}
YnZD *Yw_g(YnZD *t, YYKi *Av) {
 Zsf sf;
 YnZD *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2356100;
  ZthrowThisNil();
 }
 sf.pos=2356101;
 if ((t->Vf_dictItem == NULL))
 {
  sf.pos=2356102;
  t->Vf_dictItem = ZnewList((Tt*)&YYKi__T, 0);
 }
 sf.pos=2356103;
 ZLap((Tl*)t->Vf_dictItem, (Tz)(void*)Av);
 sf.pos=2356104;
 r = t;
 topFrame = sf.prev;
 return r;
}
YYKi *YmCP(YnZD *t) {
 Zsf sf;
 YYKi *r = 0;
 YYKi *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=851500;
  ZthrowThisNil();
 }
 sf.pos=851501;
 Vv = YJyD(NULL);
 sf.pos=851502;
 Yw_g(t, Vv);
 sf.pos=851503;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
YnZD *Y51O(YnZD *t, YJFN *Av) {
 Zsf sf;
 YnZD *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9627700;
  ZthrowThisNil();
 }
 sf.pos=9627701;
 if ((t->Vf_initItem == NULL))
 {
  sf.pos=9627702;
  t->Vf_initItem = ZnewList((Tt*)&YJFN__T, 0);
 }
 sf.pos=9627703;
 ZLap((Tl*)t->Vf_initItem, (Tz)(void*)Av);
 sf.pos=9627704;
 r = t;
 topFrame = sf.prev;
 return r;
}
YJFN *YNzh(YnZD *t) {
 Zsf sf;
 YJFN *r = 0;
 YJFN *Vv = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8123100;
  ZthrowThisNil();
 }
 sf.pos=8123101;
 Vv = Ydki(NULL);
 sf.pos=8123102;
 Y51O(t, Vv);
 sf.pos=8123103;
 r = Vv;
 topFrame = sf.prev;
 return r;
}
YnZD *Y_Jm(YnZD *t, Tb Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_orderedDict = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YnZD *YoWy(YnZD *t, Y_1n *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_methodCall = Av;
 r = t;
 return r;
}
Y_1n *YztZ(YnZD *t) {
 Y_1n *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_methodCall == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YP7Q);
  ZthrowPos(6831800, ex);
 }
 r = t->Vf_methodCall;
 return r;
}
YnZD *YCI5(YnZD *t, Y7Np *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_method = Av;
 r = t;
 return r;
}
YnZD *Y35a(YnZD *t, YYIi *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_decl = Av;
 r = t;
 return r;
}
YRBza *Ymcl(YnZD *t) {
 Zsf sf;
 YRBza *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5398800;
  ZthrowThisNil();
 }
 sf.pos=5398801;
 t->Vf_typecast = Ya_p(NULL);
 sf.pos=5398802;
 r = t->Vf_typecast;
 topFrame = sf.prev;
 return r;
}
Tl *Y6_b(YnZD *t) {
 Tl *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = t->Vf_typespec;
 return r;
}
YnZD *YbfL(YnZD *t, Tl *Al) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_typespec = Al;
 r = t;
 return r;
}
YnZD *YkIT(YnZD *t, YnZD *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_cond = Av;
 r = t;
 return r;
}
YnZD *Yfkd(YnZD *t, YnZD *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_left = Av;
 r = t;
 return r;
}
YnZD *Y8za(YnZD *t) {
 Zsf sf;
 YnZD *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5429000;
  ZthrowThisNil();
 }
 sf.pos=5429001;
 t->Vf_left = Y4GO(NULL);
 sf.pos=5429002;
 r = t->Vf_left;
 topFrame = sf.prev;
 return r;
}
YnZD *Yre5(YnZD *t) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_left == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&Yt7m);
  ZthrowPos(3688000, ex);
 }
 r = t->Vf_left;
 return r;
}
Tb Y8FL(YnZD *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_left != NULL);
 return r;
}
YnZD *YPfx(YnZD *t, YnZD *Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_right = Av;
 r = t;
 return r;
}
YnZD *YBJ7(YnZD *t) {
 Zsf sf;
 YnZD *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1546500;
  ZthrowThisNil();
 }
 sf.pos=1546501;
 t->Vf_right = Y4GO(NULL);
 sf.pos=1546502;
 r = t->Vf_right;
 topFrame = sf.prev;
 return r;
}
YnZD *Y3Wy(YnZD *t) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_right == NULL))
 {
  void *ex = NULL;
  ex = ((Tc*)&YC23);
  ZthrowPos(867100, ex);
 }
 r = t->Vf_right;
 return r;
}
Tb YBlB(YnZD *t) {
 Tb r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 r = (t->Vf_right != NULL);
 return r;
}
YnZD *YkYI(YnZD *t, Tb Av) {
 YnZD *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_dotnil = ((Av) ? (2) : (1));
 r = t;
 return r;
}
YnZD *Ypps(YnZD *t, Tb Adeep) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vret = 0;
 Tl *Zf3 = NULL;
 YnZD *Vi = 0;
 Tl *Zf31 = NULL;
 Tl *Zf32 = NULL;
 Tl *Zf33 = NULL;
 YRBza *Vi1 = 0;
 YYKi *Vi2 = 0;
 YJFN *Vi3 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1017600;
  ZthrowThisNil();
 }
 sf.pos=1017601;
 Vret = Y4GO(NULL);
 sf.pos=1017602;
 Vret->Vf_type = t->Vf_type;
 sf.pos=1017603;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=1017604;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=1017605;
 if ((t->Vf_id != NULL))
 {
  sf.pos=1017606;
  Vret->Vf_id = ((Adeep) ? (Y_4M(t->Vf_id, Adeep)) : (t->Vf_id));
 }
 sf.pos=1017607;
 if (t->Vhas_number)
 {
  sf.pos=1017608;
  Vret->Vhas_number = 1;
  sf.pos=1017609;
  Vret->Vf_number = t->Vf_number;
 }
 sf.pos=1017610;
 if (t->Vhas_fnumber)
 {
  sf.pos=1017611;
  Vret->Vhas_fnumber = 1;
  sf.pos=1017612;
  Vret->Vf_fnumber = t->Vf_fnumber;
 }
 sf.pos=1017613;
 if (t->Vhas_dotNumber)
 {
  sf.pos=1017614;
  Vret->Vhas_dotNumber = 1;
  sf.pos=1017615;
  Vret->Vf_dotNumber = t->Vf_dotNumber;
 }
 sf.pos=1017616;
 Vret->Vf_stringValue = t->Vf_stringValue;
 sf.pos=1017617;
 if (Adeep)
 {
  sf.pos=1017618;
  if ((t->Vf_listItem != NULL))
  {
   sf.pos=1017619;
   Vret->Vf_listItem = ZnewList((Tt*)&YnZD__T, 0);
   sf.pos=1017620;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_listItem;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=1017621;
    ZLap((Tl*)Vret->Vf_listItem, (Tz)(void*)Ypps(Vi, Adeep));
    sf.pos=1017622;
    }
   }
  }
 }
 else
 {
  sf.pos=1017623;
  Vret->Vf_listItem = t->Vf_listItem;
 }
 sf.pos=1017624;
 if (Adeep)
 {
  sf.pos=1017625;
  if ((t->Vf_dictItem != NULL))
  {
   sf.pos=1017626;
   Vret->Vf_dictItem = ZnewList((Tt*)&YYKi__T, 0);
   sf.pos=1017627;
   {
    Tfl Zf31i;
    Zf31 = t->Vf_dictItem;
    Zf31i.l = Zf31;
    Zf31i.valp = (void*)&Vi2;
    Zf31i.i = 0;
    for (; ZforListPtrCont(&Zf31i); ) {
    sf.pos=1017628;
    ZLap((Tl*)Vret->Vf_dictItem, (Tz)(void*)YqYD(Vi2, Adeep));
    sf.pos=1017629;
    }
   }
  }
 }
 else
 {
  sf.pos=1017630;
  Vret->Vf_dictItem = t->Vf_dictItem;
 }
 sf.pos=1017631;
 if (Adeep)
 {
  sf.pos=1017632;
  if ((t->Vf_initItem != NULL))
  {
   sf.pos=1017633;
   Vret->Vf_initItem = ZnewList((Tt*)&YJFN__T, 0);
   sf.pos=1017634;
   {
    Tfl Zf32i;
    Zf32 = t->Vf_initItem;
    Zf32i.l = Zf32;
    Zf32i.valp = (void*)&Vi3;
    Zf32i.i = 0;
    for (; ZforListPtrCont(&Zf32i); ) {
    sf.pos=1017635;
    ZLap((Tl*)Vret->Vf_initItem, (Tz)(void*)YPAH(Vi3, Adeep));
    sf.pos=1017636;
    }
   }
  }
 }
 else
 {
  sf.pos=1017637;
  Vret->Vf_initItem = t->Vf_initItem;
 }
 sf.pos=1017638;
 Vret->Vf_orderedDict = t->Vf_orderedDict;
 sf.pos=1017639;
 if ((t->Vf_methodCall != NULL))
 {
  sf.pos=1017640;
  Vret->Vf_methodCall = ((Adeep) ? (Y6Kb(t->Vf_methodCall, Adeep)) : (t->Vf_methodCall));
 }
 sf.pos=1017641;
 if ((t->Vf_method != NULL))
 {
  sf.pos=1017642;
  Vret->Vf_method = ((Adeep) ? (Yt_q(t->Vf_method, Adeep)) : (t->Vf_method));
 }
 sf.pos=1017643;
 if ((t->Vf_decl != NULL))
 {
  sf.pos=1017644;
  Vret->Vf_decl = ((Adeep) ? (YTec(t->Vf_decl, Adeep)) : (t->Vf_decl));
 }
 sf.pos=1017645;
 if ((t->Vf_typecast != NULL))
 {
  sf.pos=1017646;
  Vret->Vf_typecast = ((Adeep) ? (YK7D(t->Vf_typecast, Adeep)) : (t->Vf_typecast));
 }
 sf.pos=1017647;
 if (Adeep)
 {
  sf.pos=1017648;
  if ((t->Vf_typespec != NULL))
  {
   sf.pos=1017649;
   Vret->Vf_typespec = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=1017650;
   {
    Tfl Zf33i;
    Zf33 = t->Vf_typespec;
    Zf33i.l = Zf33;
    Zf33i.valp = (void*)&Vi1;
    Zf33i.i = 0;
    for (; ZforListPtrCont(&Zf33i); ) {
    sf.pos=1017651;
    ZLap((Tl*)Vret->Vf_typespec, (Tz)(void*)YK7D(Vi1, Adeep));
    sf.pos=1017652;
    }
   }
  }
 }
 else
 {
  sf.pos=1017653;
  Vret->Vf_typespec = t->Vf_typespec;
 }
 sf.pos=1017654;
 if ((t->Vf_cond != NULL))
 {
  sf.pos=1017655;
  Vret->Vf_cond = ((Adeep) ? (Ypps(t->Vf_cond, Adeep)) : (t->Vf_cond));
 }
 sf.pos=1017656;
 if ((t->Vf_left != NULL))
 {
  sf.pos=1017657;
  Vret->Vf_left = ((Adeep) ? (Ypps(t->Vf_left, Adeep)) : (t->Vf_left));
 }
 sf.pos=1017658;
 if ((t->Vf_right != NULL))
 {
  sf.pos=1017659;
  Vret->Vf_right = ((Adeep) ? (Ypps(t->Vf_right, Adeep)) : (t->Vf_right));
 }
 sf.pos=1017660;
 Vret->Vf_dotnil = t->Vf_dotnil;
 sf.pos=1017661;
 if ((t->Vf_call != NULL))
 {
  sf.pos=1017662;
  Vret->Vf_call = ((Adeep) ? (Y6Kb(t->Vf_call, Adeep)) : (t->Vf_call));
 }
 sf.pos=1017663;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYnZD[] = {
 {15, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&Y1p4__T}, /* f_id */
 {0, (Tt*)&string__T}, /* f_stringValue */
 {0, (Tt*)&list__T}, /* f_listItem */
 {0, (Tt*)&list__T}, /* f_dictItem */
 {0, (Tt*)&list__T}, /* f_initItem */
 {0, (Tt*)&Y_1n__T}, /* f_methodCall */
 {0, (Tt*)&Y7Np__T}, /* f_method */
 {0, (Tt*)&YYIi__T}, /* f_decl */
 {0, (Tt*)&YRBza__T}, /* f_typecast */
 {0, (Tt*)&list__T}, /* f_typespec */
 {0, (Tt*)&YnZD__T}, /* f_cond */
 {0, (Tt*)&YnZD__T}, /* f_left */
 {0, (Tt*)&YnZD__T}, /* f_right */
 {0, (Tt*)&Y_1n__T}, /* f_call */
};
Tto YnZD__T = {390, (Tc*)&Y5cf, 0, ToYnZD};
Y1p4 *YUZH(Y1p4 *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8096800; t = Za(sizeof(Y1p4));}
 topFrame = sf.prev;
 return t;
}
Y1p4 *YxV1(Y1p4 *t, Ysbp *Av) {
 Y1p4 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
Y1p4 *YMou(Y1p4 *t, Tc *Av) {
 Y1p4 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
Tc *YYim(Y1p4 *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_name == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto YM65;
 }
 r = t->Vf_name;
YM65:
 return r;
}
Y1p4 *YLsU(Y1p4 *t, Tb Av) {
 Y1p4 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_dollar = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YI8b(Y1p4 *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_dollar == 0))
 {
  r = 0;
  rt = 1;
  goto Ykhv;
 }
 r = (t->Vf_dollar == 2);
Ykhv:
 return r;
}
Y1p4 *YuRa(Y1p4 *t, Tb Av) {
 Y1p4 *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_percent = ((Av) ? (2) : (1));
 r = t;
 return r;
}
Tb YFAa(Y1p4 *t) {
 Tb r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_percent == 0))
 {
  r = 0;
  rt = 1;
  goto YRhJ;
 }
 r = (t->Vf_percent == 2);
YRhJ:
 return r;
}
Y1p4 *Y_4M(Y1p4 *t, Tb Adeep) {
 Zsf sf;
 Y1p4 *r = 0;
 Y1p4 *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5716500;
  ZthrowThisNil();
 }
 sf.pos=5716501;
 Vret = YUZH(NULL);
 sf.pos=5716502;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=5716503;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=5716504;
 Vret->Vf_name = t->Vf_name;
 sf.pos=5716505;
 Vret->Vf_dollar = t->Vf_dollar;
 sf.pos=5716506;
 Vret->Vf_percent = t->Vf_percent;
 sf.pos=5716507;
 if (t->Vhas_ref)
 {
  sf.pos=5716508;
  Vret->Vhas_ref = 1;
  sf.pos=5716509;
  Vret->Vf_ref = t->Vf_ref;
 }
 sf.pos=5716510;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToY1p4[] = {
 {2, 0},
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&string__T}, /* f_name */
};
Tto Y1p4__T = {390, (Tc*)&YN1a, 0, ToY1p4};
YYKi *YJyD(YYKi *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8783400; t = Za(sizeof(YYKi));}
 topFrame = sf.prev;
 return t;
}
YYKi *YdT0(YYKi *t, YnZD *Av) {
 YYKi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_key = Av;
 r = t;
 return r;
}
YYKi *YsFD(YYKi *t, YnZD *Av) {
 YYKi *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_value = Av;
 r = t;
 return r;
}
YYKi *YqYD(YYKi *t, Tb Adeep) {
 Zsf sf;
 YYKi *r = 0;
 YYKi *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1498300;
  ZthrowThisNil();
 }
 sf.pos=1498301;
 Vret = YJyD(NULL);
 sf.pos=1498302;
 if ((t->Vf_key != NULL))
 {
  sf.pos=1498303;
  Vret->Vf_key = ((Adeep) ? (Ypps(t->Vf_key, Adeep)) : (t->Vf_key));
 }
 sf.pos=1498304;
 if ((t->Vf_value != NULL))
 {
  sf.pos=1498305;
  Vret->Vf_value = ((Adeep) ? (Ypps(t->Vf_value, Adeep)) : (t->Vf_value));
 }
 sf.pos=1498306;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYYKi[] = {
 {2, 0},
 {0, (Tt*)&YnZD__T}, /* f_key */
 {0, (Tt*)&YnZD__T}, /* f_value */
};
Tto YYKi__T = {390, (Tc*)&Y_G0, 0, ToYYKi};
YJFN *Ydki(YJFN *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3998300; t = Za(sizeof(YJFN));}
 topFrame = sf.prev;
 return t;
}
YJFN *YXqm(YJFN *t, Tc *Av) {
 YJFN *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
YJFN *YP1z(YJFN *t, YnZD *Av) {
 YJFN *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_value = Av;
 r = t;
 return r;
}
YJFN *YPAH(YJFN *t, Tb Adeep) {
 Zsf sf;
 YJFN *r = 0;
 YJFN *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8868800;
  ZthrowThisNil();
 }
 sf.pos=8868801;
 Vret = Ydki(NULL);
 sf.pos=8868802;
 Vret->Vf_name = t->Vf_name;
 sf.pos=8868803;
 if ((t->Vf_value != NULL))
 {
  sf.pos=8868804;
  Vret->Vf_value = ((Adeep) ? (Ypps(t->Vf_value, Adeep)) : (t->Vf_value));
 }
 sf.pos=8868805;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYJFN[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* f_name */
 {0, (Tt*)&YnZD__T}, /* f_value */
};
Tto YJFN__T = {390, (Tc*)&YeMw, 0, ToYJFN};
Y_1n *YLx8(Y_1n *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=1753600; t = Za(sizeof(Y_1n));}
 topFrame = sf.prev;
 return t;
}
Y_1n *Y_BE(Y_1n *t, Ysbp *Av) {
 Y_1n *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_pos = Av;
 r = t;
 return r;
}
Y_1n *YOo6(Y_1n *t, YnZD *Av) {
 Y_1n *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_name = Av;
 r = t;
 return r;
}
Y_1n *YnYS(Y_1n *t, Tl *Al) {
 Y_1n *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_argument = Al;
 r = t;
 return r;
}
Y_1n *Y6Kb(Y_1n *t, Tb Adeep) {
 Zsf sf;
 Y_1n *r = 0;
 Y_1n *Vret = 0;
 Tl *Zf3 = NULL;
 YnZD *Vi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5034100;
  ZthrowThisNil();
 }
 sf.pos=5034101;
 Vret = YLx8(NULL);
 sf.pos=5034102;
 if ((t->Vf_method != NULL))
 {
  sf.pos=5034103;
  Vret->Vf_method = ((Adeep) ? (YCOd(t->Vf_method, Adeep)) : (t->Vf_method));
 }
 sf.pos=5034104;
 if ((t->Vf_pos != NULL))
 {
  sf.pos=5034105;
  Vret->Vf_pos = ((Adeep) ? (Yw4M(t->Vf_pos, Adeep)) : (t->Vf_pos));
 }
 sf.pos=5034106;
 if ((t->Vf_name != NULL))
 {
  sf.pos=5034107;
  Vret->Vf_name = ((Adeep) ? (Ypps(t->Vf_name, Adeep)) : (t->Vf_name));
 }
 sf.pos=5034108;
 if (Adeep)
 {
  sf.pos=5034109;
  if ((t->Vf_argument != NULL))
  {
   sf.pos=5034110;
   Vret->Vf_argument = ZnewList((Tt*)&YnZD__T, 0);
   sf.pos=5034111;
   {
    Tfl Zf3i;
    Zf3 = t->Vf_argument;
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vi;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=5034112;
    ZLap((Tl*)Vret->Vf_argument, (Tz)(void*)Ypps(Vi, Adeep));
    sf.pos=5034113;
    }
   }
  }
 }
 else
 {
  sf.pos=5034114;
  Vret->Vf_argument = t->Vf_argument;
 }
 sf.pos=5034115;
 if ((t->Vf_vararg != NULL))
 {
  sf.pos=5034116;
  Vret->Vf_vararg = ((Adeep) ? (Ypps(t->Vf_vararg, Adeep)) : (t->Vf_vararg));
 }
 sf.pos=5034117;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToY_1n[] = {
 {5, 0},
 {0, (Tt*)&Yknz__T}, /* f_method */
 {0, (Tt*)&Ysbp__T}, /* f_pos */
 {0, (Tt*)&YnZD__T}, /* f_name */
 {0, (Tt*)&list__T}, /* f_argument */
 {0, (Tt*)&YnZD__T}, /* f_vararg */
};
Tto Y_1n__T = {390, (Tc*)&YtVN, 0, ToY_1n};
Ysbp *Y602(Ysbp *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=672400; t = Za(sizeof(Ysbp));}
 topFrame = sf.prev;
 return t;
}
Ysbp *YGxQ(Ysbp *t, Ti Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_line = Av;
 t->Vhas_line = 1;
 r = t;
 return r;
}
Ti YuDY(Ysbp *t) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_line))
 {
  r = 0;
  rt = 1;
  goto YxeV;
 }
 r = t->Vf_line;
YxeV:
 return r;
}
Ysbp *Y6ET(Ysbp *t, Ti Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_column = Av;
 t->Vhas_column = 1;
 r = t;
 return r;
}
Ti Y3kb(Ysbp *t) {
 Ti r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if (!(t->Vhas_column))
 {
  r = 0;
  rt = 1;
  goto YQm6a;
 }
 r = t->Vf_column;
YQm6a:
 return r;
}
Ysbp *YMCx(Ysbp *t, Tc *Av) {
 Ysbp *r = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 t->Vf_filename = Av;
 r = t;
 return r;
}
Tc *Y5Hu(Ysbp *t) {
 Tc *r = 0;
 int rt = 0;
 if (t == NULL) {
   ZthrowThisNil();
 }
 if ((t->Vf_filename == NULL))
 {
  r = ((Tc*)&Ya);
  rt = 1;
  goto YoMJ;
 }
 r = t->Vf_filename;
YoMJ:
 return r;
}
Ysbp *Yw4M(Ysbp *t, Tb Adeep) {
 Zsf sf;
 Ysbp *r = 0;
 Ysbp *Vret = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3922500;
  ZthrowThisNil();
 }
 sf.pos=3922501;
 Vret = Y602(NULL);
 sf.pos=3922502;
 if (t->Vhas_line)
 {
  sf.pos=3922503;
  Vret->Vhas_line = 1;
  sf.pos=3922504;
  Vret->Vf_line = t->Vf_line;
 }
 sf.pos=3922505;
 if (t->Vhas_column)
 {
  sf.pos=3922506;
  Vret->Vhas_column = 1;
  sf.pos=3922507;
  Vret->Vf_column = t->Vf_column;
 }
 sf.pos=3922508;
 Vret->Vf_filename = t->Vf_filename;
 sf.pos=3922509;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYsbp[] = {
 {1, 0},
 {0, (Tt*)&string__T}, /* f_filename */
};
Tto Ysbp__T = {390, (Tc*)&YvfVb, 0, ToYsbp};
/* zui done */
/* including Parse bodies */
/* including Input bodies */
YeYq *YOdr(YeYq *t, Tr Afd, Tc *Afname, Tc *Aindent, Tb Arecord) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=4440100; t = Za(sizeof(YeYq));}
 sf.pos=4440101;
 t->Vfd = Afd;
 sf.pos=4440102;
 t->Vpos = Ypp_(NULL, Afname);
 sf.pos=4440103;
 t->VcharStack = ZnewList((Tt*)&int__T, 0);
 sf.pos=4440104;
 t->Vindent = Aindent;
 sf.pos=4440105;
 if (Arecord)
 {
  sf.pos=4440106;
  t->VrecordWriter = Za(sizeof(YjUM));
 }
 topFrame = sf.prev;
 return t;
}
YeYq *YOdra(YeYq *t, Tc *As, YkxB *Astartpos) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9015700; t = Za(sizeof(YeYq));}
 sf.pos=9015701;
 t->Vtext = As;
 sf.pos=9015702;
 t->VtextIdx = 0;
 sf.pos=9015703;
 t->Vpos = Y83A(Astartpos);
 sf.pos=9015704;
 t->VcharStack = ZnewList((Tt*)&int__T, 0);
 sf.pos=9015705;
 t->Vindent = ((Tc*)&Ya);
 topFrame = sf.prev;
 return t;
}
Ti YAit(YeYq *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1988700;
  ZthrowThisNil();
 }
 Vc = 0;
 sf.pos=1988701;
 if ((ZListSize(t->VcharStack) > 0))
 {
  sf.pos=1988702;
  Vc = ZListRemoveIntItem((Tl*)t->VcharStack, -1);
  sf.pos=1988703;
  ++(t->Vpos->Vcol);
 }
 else {
 sf.pos=1988704;
 if ((((t->Vfd).ptr) == NULL))
 {
  sf.pos=1988705;
  if ((t->VtextIdx >= ZstringSize(t->Vtext)))
  {
   sf.pos=1988706;
   Vc = Y3QJ;
  }
  else
  {
   sf.pos=1988707;
   Vc = ZstringGetChar(t->Vtext, t->VtextIdx);
   sf.pos=1988708;
   ++(t->VtextIdx);
   sf.pos=1988709;
   ++(t->Vpos->Vcol);
  }
 }
 else
 {
  sf.pos=1988710;
  for (;;)
  {
   sf.pos=1988711;
   Vc = ((Ti (*)(void*))(t->Vfd.table[23]))(t->Vfd.ptr);
   sf.pos=1988712;
   ++(t->Vpos->Vcol);
   sf.pos=1988713;
   if (((((Vc >= 0) && (Vc <= 31))) || (((Vc >= 127) && (Vc <= 160)))))
   {
    sf.pos=1988714;
    if ((Vc == 0))
    {
     sf.pos=1988715;
     YDli(((Tc*)&YrKy), t->Vpos, 0);
     sf.pos=1988716;
     Vc = 32;
    }
    else {
    sf.pos=1988717;
 if ((Vc == 9))
    {
     sf.pos=1988718;
     if (!(t->VallowTabs))
     {
      sf.pos=1988719;
      YDli(((Tc*)&YemR), t->Vpos, 0);
     }
     sf.pos=1988720;
     Vc = 32;
    }
    else {
    sf.pos=1988721;
 if (((Vc != 13) && (Vc != 10)))
    {
     sf.pos=1988722;
     YDli(((Tc*)&Y3Pw), t->Vpos, 0);
     sf.pos=1988723;
     Vc = 32;
    }
    }}
   }
   sf.pos=1988724;
   if (((Vc != 13) && (Vc != 65279))) break;
  sf.pos=1988725;
  }
 }
 }
 sf.pos=1988726;
 if ((Vc == 10))
 {
  sf.pos=1988727;
  t->VprevLineCol = t->Vpos->Vcol;
  sf.pos=1988728;
  YnS4(t->Vpos);
 }
 sf.pos=1988729;
 if (((t->VrecordWriter != NULL) && (Vc != Y3QJ)))
 {
  sf.pos=1988730;
  YjUM__Ydti(t->VrecordWriter, Vc);
 }
 sf.pos=1988731;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
void YmK2(YeYq *t, Ti Ac) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3404700;
  ZthrowThisNil();
 }
 sf.pos=3404701;
 if ((Ac != Y3QJ))
 {
  sf.pos=3404702;
  ZLap((Tl*)t->VcharStack, (Tz)(Ti)Ac);
  sf.pos=3404703;
  if ((Ac == 10))
  {
   sf.pos=3404704;
   t->Vpos->Vcol = t->VprevLineCol;
   sf.pos=3404705;
   --(t->Vpos->Vlnum);
  }
  else
  {
   sf.pos=3404706;
   --(t->Vpos->Vcol);
  }
  sf.pos=3404707;
  if ((t->VrecordWriter != NULL))
  {
   sf.pos=3404708;
   Y6jW(t->VrecordWriter);
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYeYq[] = {
 {6, 0},
 {0, (Tt*)&iobj__T}, /* fd */
 {0, (Tt*)&string__T}, /* text */
 {0, (Tt*)&YkxB__T}, /* pos */
 {0, (Tt*)&list__T}, /* charStack */
 {0, (Tt*)&string__T}, /* indent */
 {0, (Tt*)&YjUM__T}, /* recordWriter */
};
Tto YeYq__T = {390, (Tc*)&YVUW, 0, ToYeYq};
/* Input done */
/* including Token bodies */
YkxB *YWLf(Yev8 *t) {
 Zsf sf;
 YkxB *r = 0;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5204700;
  ZthrowThisNil();
 }
 sf.pos=5204701;
 r = Ypp_a(NULL, (t0 = Y5Hu(t->VzuiPos)), YuDY(t->VzuiPos), Y3kb(t->VzuiPos));
 topFrame = sf.prev;
 return r;
}
void YdIu(Yev8 *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4037400;
  ZthrowThisNil();
 }
 sf.pos=4037401;
 YDli(Amsg, YWLf(t), 0);
 topFrame = sf.prev;
 return;
}
void YREn(Yev8 *t) {
 Zsf sf;
 Tc *t0 = NULL;
 YkxB *t1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2015900;
  ZthrowThisNil();
 }
 sf.pos=2015901;
 YDli((t0 = ZcS3(((Tc*)&YN), t->Vvalue, ((Tc*)&YScH))), (t1 = YWLf(t)), 0);
 topFrame = sf.prev;
 return;
}
Tb YfTZ(Yev8 *t) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4743600;
  ZthrowThisNil();
 }
 sf.pos=4743601;
 r = (((t->Vtype == 2) || (t->Vtype == 3)) || (t->Vtype == 4));
 topFrame = sf.prev;
 return r;
}
Yev8 *Y77H(Yev8 *t) {
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3989900;
  ZthrowThisNil();
 }
 sf.pos=3989901;
 Vt = Za(sizeof(Yev8));
 sf.pos=3989902;
 Vt->Vtype = t->Vtype;
 sf.pos=3989903;
 Vt->Vvalue = t->Vvalue;
 sf.pos=3989904;
 Vt->VhasComment = t->VhasComment;
 sf.pos=3989905;
 Vt->VhasCommentFirst = t->VhasCommentFirst;
 sf.pos=3989906;
 if ((t->VzuiPos != NULL))
 {
  sf.pos=3989907;
  Vt->VzuiPos = Yw4M(t->VzuiPos, 0);
 }
 sf.pos=3989908;
 r = Vt;
 topFrame = sf.prev;
 return r;
}
To ToYev8[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* value */
 {0, (Tt*)&Ysbp__T}, /* zuiPos */
};
Tto Yev8__T = {390, (Tc*)&YVrE, 0, ToYev8};
/* Token done */
/* including TokenInput bodies */
/* including Tokenizer bodies */
/* including ZuiFile bodies */
Ysbp *YK9d(YkxB *Apos) {
 Zsf sf;
 Ysbp *r = 0;
 Ysbp *Vzpos = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=622800;
 if ((Apos == NULL))
 {
  sf.pos=622801;
  r = NULL;
  rt = 1;
  goto YPIH;
 }
 sf.pos=622802;
 Vzpos = Y602(NULL);
 sf.pos=622803;
 YGxQ(Vzpos, Apos->Vlnum);
 sf.pos=622804;
 Y6ET(Vzpos, Apos->Vcol);
 sf.pos=622805;
 YMCx(Vzpos, Apos->Vfilename);
 sf.pos=622806;
 r = Vzpos;
YPIH:
 topFrame = sf.prev;
 return r;
}
void YA4C(YkxB *Apos, Ysbp *Azpos) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7833500;
 YGxQ(Azpos, Apos->Vlnum);
 sf.pos=7833501;
 Y6ET(Azpos, Apos->Vcol);
 sf.pos=7833502;
 YMCx(Azpos, Apos->Vfilename);
 topFrame = sf.prev;
 return;
}
To ToYgKE[] = {
 {0, 0},
};
Tto YgKE__T = {390, (Tc*)&YRzA, 0, ToYgKE};
/* ZuiFile done */
Tb YIA3(Ti Ac) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4391700;
 r = ((((((Ac >= 97) && (Ac <= 122))) || (((Ac >= 65) && (Ac <= 90)))) || (((Ac >= 48) && (Ac <= 57)))) || (Ac == 95));
 topFrame = sf.prev;
 return r;
}
Yev8 *Yx5t(Y7Sj *Ain) {
 Ti Vc;
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vres = 0;
 Tc *Vname = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=603800;
 Vres = Za(sizeof(Yev8));
 sf.pos=603801;
 Vres->VzuiPos = YK9d(Ain->Vinput->Vpos);
 sf.pos=603802;
 YZTP(Ain, Vres);
 sf.pos=603803;
 if ((Vres->Vtype != 5))
 {
  sf.pos=603804;
  r = Vres;
  rt = 1;
  goto YqMK;
 }
 sf.pos=603805;
 YA4C(Ain->Vinput->Vpos, Vres->VzuiPos);
 sf.pos=603806;
 if ((Ybdf(Ain, Vres) == 1))
 {
  sf.pos=603807;
  if (((Vres->Vtype == 21) || (Vres->Vtype == 56)))
  {
   sf.pos=603808;
   Y63C(Ain->VusedIdKeywords, Vres->Vvalue);
  }
  sf.pos=603809;
  r = Vres;
  rt = 1;
  goto YqMK;
 }
 sf.pos=603810;
 Vc = YGBv(Ain);
 sf.pos=603811;
 if (((Vc == 82) && (YHT_(Ain) == 34)))
 {
  sf.pos=603812;
  YGBv(Ain);
  sf.pos=603813;
  YfFo(Ain, (&Yc6N));
  sf.pos=603814;
  Vres->Vtype = 13;
 }
 else
 {
  sf.pos=603815;
  switch (Vc)
  {
  case 34:
   {
    sf.pos=603816;
    Vres->Vtype = 13;
    sf.pos=603817;
    while (1)
    {
     sf.pos=603818;
     Vc = YGBv(Ain);
     sf.pos=603819;
     if ((Vc == 34))
     {
      rt = 2;
      goto YAns;
     }
     sf.pos=603820;
     if (((Vc == 10) || (Vc == Y3QJ)))
     {
      sf.pos=603821;
      YPmF(Ain, Vc);
      sf.pos=603822;
      Y5yp(Ain, ((Tc*)&YD4M));
      rt = 2;
      goto YAns;
     }
     sf.pos=603823;
     if ((Vc == 92))
     {
      sf.pos=603824;
      Vc = YGBv(Ain);
      sf.pos=603825;
      if (((Vc == 10) || (Vc == Y3QJ)))
      {
       sf.pos=603826;
       Y5yp(Ain, ((Tc*)&YD4M));
       rt = 2;
       goto Y3Ye;
      }
      sf.pos=603827;
      if ((Vc == 40))
      {
       sf.pos=603828;
       Vres->Vtype = 14;
       rt = 2;
       goto Y3Ye;
      }
      sf.pos=603829;
      YxBx(Vc, Ain, (&Yc6N));
Y3Ye:
      if (rt) goto YAns;
     }
     else
     {
      sf.pos=603830;
      YjUM__Ydti((&Yc6N), Vc);
     }
YAns:
     if (rt == 2) { rt &= 1; break; }
    sf.pos=603831;
    }
     break;
   }
  case 39:
   {
    sf.pos=603832;
    Vc = YGBv(Ain);
    sf.pos=603833;
    if ((Vc == 39))
    {
     sf.pos=603834;
     Vc = YGBv(Ain);
     sf.pos=603835;
     if (((Vc == 39) || (Vc == 34)))
     {
      sf.pos=603836;
      Vres->Vtype = 13;
      sf.pos=603837;
      while (1)
      {
       Ti Vnc;
       sf.pos=603838;
       Vnc = YGBv(Ain);
       sf.pos=603839;
       Vc = Vnc;
       sf.pos=603840;
       if (((Vc == 39) || (Vc == 34)))
       {
        sf.pos=603841;
        Vc = YGBv(Ain);
        sf.pos=603842;
        if ((Vc == 39))
        {
         sf.pos=603843;
         Vc = YGBv(Ain);
         sf.pos=603844;
         if ((Vc == 39))
         {
          rt = 2;
          goto YCmf;
         }
         sf.pos=603845;
         YPmF(Ain, Vc);
         sf.pos=603846;
         Vc = 39;
YCmf:
         if (rt) goto Ydgn;
        }
        sf.pos=603847;
        YPmF(Ain, Vc);
        sf.pos=603848;
        Vc = Vnc;
Ydgn:
        if (rt) goto YCkF;
       }
       sf.pos=603849;
       if ((Vc == Y3QJ))
       {
        sf.pos=603850;
        Y5yp(Ain, ((Tc*)&YjHV));
        rt = 2;
        goto YCkF;
       }
       sf.pos=603851;
       YjUM__Ydti((&Yc6N), Vc);
YCkF:
       if (rt == 2) { rt &= 1; break; }
      sf.pos=603852;
      }
      rt = 2;
      goto YbmY;
     }
     else
     {
      sf.pos=603853;
      YPmF(Ain, Vc);
      sf.pos=603854;
      Vc = 39;
     }
YbmY:
     if (rt) goto Yduz;
    }
    sf.pos=603855;
    Vres->Vtype = 15;
    sf.pos=603856;
    if ((Vc == 92))
    {
     sf.pos=603857;
     YxBx(YGBv(Ain), Ain, (&Yc6N));
    }
    else
    {
     sf.pos=603858;
     if ((Vc == 39))
     {
      sf.pos=603859;
      YPmF(Ain, Vc);
      sf.pos=603860;
      Y5yp(Ain, ((Tc*)&YXk7));
      sf.pos=603861;
      Vc = 0;
     }
     sf.pos=603862;
     YjUM__Ydti((&Yc6N), Vc);
    }
    sf.pos=603863;
    Vc = YGBv(Ain);
    sf.pos=603864;
    if ((Vc != 39))
    {
     sf.pos=603865;
     Y5yp(Ain, ((Tc*)&YYrm));
    }
Yduz:
    if (rt == 2) { rt &= 1; break; }
     break;
   }
  default:
   {
    Tb VallUpper;
    Tb VnonDigit;
    Tb VdoubleUnderscore;
    sf.pos=603866;
    if (!(YIA3(Vc)))
    {
     sf.pos=603867;
     Y5yp(Ain, ZcS3(((Tc*)&YtNZ), ZintAsString(Vc), ((Tc*)&YN)));
    }
    else
    {
     Tb Vnumber;
     Vnumber = 0;
     sf.pos=603868;
     if (((Vc >= 48) && (Vc <= 57)))
     {
      sf.pos=603869;
      Vnumber = 1;
     }
     sf.pos=603870;
     while ((YIA3(Vc) || ((Vnumber && (((((Vc == 39) || (Vc == 95)) || (Vc == 46)) || (Vc == 45)))))))
     {
      sf.pos=603871;
      if ((Vc == 46))
      {
       Ti Vnc;
       sf.pos=603872;
       Vnc = YGBv(Ain);
       sf.pos=603873;
       YPmF(Ain, Vnc);
       sf.pos=603874;
       if (!(isdigit(Vnc)))
       {
        rt = 2;
        goto YuS9;
       }
YuS9:
       if (rt) goto YfVV;
      }
      sf.pos=603875;
      YjUM__Ydti((&Yc6N), Vc);
      sf.pos=603876;
      Vc = YGBv(Ain);
YfVV:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=603877;
     }
     sf.pos=603878;
     YPmF(Ain, Vc);
    }
    sf.pos=603879;
    Vname = YbNW((&Yc6N));
    sf.pos=603880;
    Vres->Vvalue = Vname;
    sf.pos=603881;
    VallUpper = 1;
    sf.pos=603882;
    VnonDigit = 0;
    sf.pos=603883;
    VdoubleUnderscore = 0;
    sf.pos=603884;
    {
     Ti Vi;
     Tfr Zf4;
     ZforRangeNew(0, ZstringSize(Vname), 1, 1, &Zf4);
     for (ZforRangeGetInt(&Zf4, &Vi); ZforRangeContInt(&Zf4); ZforRangeNextInt(&Zf4, &Vi)) {
     sf.pos=603885;
     Vc = ZstringGetChar(Vname, Vi);
     sf.pos=603886;
     if (!((((((Vc >= 48) && (Vc <= 57)) && (Vc != 39)) && (Vc != 95)))))
     {
      sf.pos=603887;
      VnonDigit = 1;
     }
     sf.pos=603888;
     if (!(((((((Vc >= 65) && (Vc <= 90))) || (Vc == 95)) || (((Vc >= 48) && (Vc <= 57)))))))
     {
      sf.pos=603889;
      VallUpper = 0;
     }
     sf.pos=603890;
     if ((((Vc == 95) && ((Vi + 1) < ZstringSize(Vname))) && (ZstringGetChar(Vname, (Vi + 1)) == 95)))
     {
      sf.pos=603891;
      VdoubleUnderscore = 1;
     }
     sf.pos=603892;
     }
    }
    sf.pos=603893;
    if ((VallUpper && VnonDigit))
    {
     sf.pos=603894;
     YdIu(Vres, ZcS3(((Tc*)&Yl7Q), Vname, ((Tc*)&YN)));
    }
    sf.pos=603895;
    if (VdoubleUnderscore)
    {
     sf.pos=603896;
     YdIu(Vres, ZcS3(((Tc*)&Y_B2), Vname, ((Tc*)&YN)));
    }
    sf.pos=603897;
    Vres->Vtype = 21;
     break;
   }
   if (rt) goto YSTp;
  }
YSTp:
  ;
 }
 sf.pos=603898;
 if ((Vres->Vvalue == NULL))
 {
  sf.pos=603899;
  Vres->Vvalue = YbNW((&Yc6N));
 }
 sf.pos=603900;
 Y3_a((&Yc6N));
 sf.pos=603901;
 r = Vres;
YqMK:
 topFrame = sf.prev;
 return r;
}
void YxBx(Ti Ac, Y7Sj *Ain, YjUM *Awriter) {
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9088900;
 switch (Ac)
 {
 case 92:
  {
   sf.pos=9088901;
   YjUM__Ydti(Awriter, 92);
    break;
  }
 case 39:
  {
   sf.pos=9088902;
   YjUM__Ydti(Awriter, 39);
    break;
  }
 case 34:
  {
   sf.pos=9088903;
   YjUM__Ydti(Awriter, 34);
    break;
  }
 case 97:
  {
   sf.pos=9088904;
   YjUM__Ydti(Awriter, 7);
    break;
  }
 case 98:
  {
   sf.pos=9088905;
   YjUM__Ydti(Awriter, 8);
    break;
  }
 case 102:
  {
   sf.pos=9088906;
   YjUM__Ydti(Awriter, 14);
    break;
  }
 case 110:
  {
   sf.pos=9088907;
   YjUM__Ydti(Awriter, 10);
    break;
  }
 case 114:
  {
   sf.pos=9088908;
   YjUM__Ydti(Awriter, 13);
    break;
  }
 case 116:
  {
   sf.pos=9088909;
   YjUM__Ydti(Awriter, 9);
    break;
  }
 case 118:
  {
   sf.pos=9088910;
   YjUM__Ydti(Awriter, 11);
    break;
  }
 case 48:
 case 49:
 case 50:
 case 51:
  {
   Ti Vn;
   sf.pos=9088911;
   Vn = (Ac - 48);
   sf.pos=9088912;
   {
    Ti Vi;
    Tfr Zf3;
    ZforRangeNew(1, 2, 0, 1, &Zf3);
    for (ZforRangeGetInt(&Zf3, &Vi); ZforRangeContInt(&Zf3); ZforRangeNextInt(&Zf3, &Vi)) {
    Ti Voc;
    sf.pos=9088913;
    Voc = YGBv(Ain);
    sf.pos=9088914;
    if (((Voc < 48) || (Voc > 55)))
    {
     sf.pos=9088915;
     YPmF(Ain, Voc);
     sf.pos=9088916;
     Y5yp(Ain, ((Tc*)&YVwa));
     sf.pos=9088917;
     YGBv(Ain);
     rt = 2;
     goto Yoj7;
    }
    sf.pos=9088918;
    Vn = (((Vn << 3)) + ((Voc - 48)));
Yoj7:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=9088919;
    }
   }
   sf.pos=9088920;
   Ye7fa(Awriter, Vn);
    break;
  }
 case 120:
  {
   sf.pos=9088921;
   Ye7fa(Awriter, YHDu(2, Ain));
    break;
  }
 case 117:
  {
   sf.pos=9088922;
   YjUM__Ydti(Awriter, YHDu(4, Ain));
    break;
  }
 case 85:
  {
   sf.pos=9088923;
   YjUM__Ydti(Awriter, YHDu(8, Ain));
    break;
  }
 default:
  {
   sf.pos=9088924;
   YPmF(Ain, Ac);
   sf.pos=9088925;
   Y5yp(Ain, ((Tc*)&Y3ak));
   sf.pos=9088926;
   YGBv(Ain);
    break;
  }
 }
 topFrame = sf.prev;
 return;
}
Ti YHDu(Ti AcharCount, Y7Sj *Ain) {
 Ti Vres;
 Zsf sf;
 Ti r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vres = 0;
 sf.pos=4478700;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(1, AcharCount, 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  Ti Vc;
  sf.pos=4478701;
  Vc = YGBv(Ain);
  sf.pos=4478702;
  if (!(isxdigit(Vc)))
  {
   sf.pos=4478703;
   YPmF(Ain, Vc);
   sf.pos=4478704;
   Y5yp(Ain, ((Tc*)&YnRg));
   sf.pos=4478705;
   YGBv(Ain);
   sf.pos=4478706;
   r = 0;
   rt = 1;
   goto Yr0H;
  }
  sf.pos=4478707;
  Vres = (((Vres << 4)) + ZstringHexToInt(ZintAsString(Vc), 1, 0));
Yr0H:
  if (rt) goto YriQ;
  sf.pos=4478708;
  }
 }
 sf.pos=4478709;
 r = Vres;
YriQ:
 topFrame = sf.prev;
 return r;
}
void YfFo(Y7Sj *Ain, YjUM *Awriter) {
 Ti Vi;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vi = 0;
 sf.pos=9089100;
 while (1)
 {
  Ti Vc;
  sf.pos=9089101;
  Vc = YGBv(Ain);
  sf.pos=9089102;
  if ((Vc == 34))
  {
   sf.pos=9089103;
   Vc = YGBv(Ain);
   sf.pos=9089104;
   if ((Vc != 34))
   {
    sf.pos=9089105;
    YPmF(Ain, Vc);
    rt = 2;
    goto Y4k2;
   }
Y4k2:
   if (rt) goto YueL;
  }
  sf.pos=9089106;
  if (((Vc == 10) || (Vc == Y3QJ)))
  {
   sf.pos=9089107;
   YPmF(Ain, Vc);
   sf.pos=9089108;
   Y5yp(Ain, ((Tc*)&YD4M));
   rt = 2;
   goto YueL;
  }
  sf.pos=9089109;
  YJqza(Awriter, ZintAsString(Vc));
YueL:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9089110;
 }
 topFrame = sf.prev;
 return;
}
void YZTP(Y7Sj *Ain, Yev8 *Ares) {
 Tb VisSep;
 Tb VhasLineBreak;
 Ti Vc;
 Zsf sf;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VisSep = 0;
 VhasLineBreak = 0;
 sf.pos=3892700;
 Vc = YGBv(Ain);
 sf.pos=3892701;
 if (((Vc == 32) || (Vc == 10)))
 {
  sf.pos=3892702;
  VisSep = 1;
 }
 sf.pos=3892703;
 while (((((Vc == 35) || (((Vc == 47) && (YHT_(Ain) == 42)))) || (Vc == 32)) || (Vc == 10)))
 {
  sf.pos=3892704;
  YjUM__Ydti((&Yl_6), Vc);
  sf.pos=3892705;
  if ((Vc == 10))
  {
   sf.pos=3892706;
   VhasLineBreak = 1;
  }
  else {
  sf.pos=3892707;
 if ((Vc == 35))
  {
   sf.pos=3892708;
   if (!(Ares->VhasComment))
   {
    sf.pos=3892709;
    Ares->VhasCommentFirst = !(VhasLineBreak);
   }
   sf.pos=3892710;
   Ares->VhasComment = 1;
   sf.pos=3892711;
   VhasLineBreak = 1;
   sf.pos=3892712;
   for (;;)
   {
    sf.pos=3892713;
    Vc = YGBv(Ain);
    sf.pos=3892714;
    YjUM__Ydti((&Yl_6), Vc);
    sf.pos=3892715;
    if (((Vc == Y3QJ) || (Vc == 10))) break;
   sf.pos=3892716;
   }
  }
  else {
  sf.pos=3892717;
 if ((Vc == 47))
  {
   sf.pos=3892718;
   YjUM__Ydti((&Yl_6), YGBv(Ain));
   sf.pos=3892719;
   if (!(Ares->VhasComment))
   {
    sf.pos=3892720;
    Ares->VhasCommentFirst = !(VhasLineBreak);
   }
   sf.pos=3892721;
   Ares->VhasComment = 1;
   sf.pos=3892722;
   for (;;)
   {
    sf.pos=3892723;
    Vc = YGBv(Ain);
    sf.pos=3892724;
    if ((Vc == 10))
    {
     sf.pos=3892725;
     YPmF(Ain, Vc);
     sf.pos=3892726;
     Y5yp(Ain, ((Tc*)&YWPM));
     sf.pos=3892727;
     Vc = Y3QJ;
     rt = 2;
     goto YaVe;
    }
    sf.pos=3892728;
    YjUM__Ydti((&Yl_6), Vc);
    sf.pos=3892729;
    if (((Vc == Y3QJ) || (((Vc == 42) && (YHT_(Ain) == 47))))) break;
YaVe:
    if (rt == 2) { rt &= 1; break; }
   sf.pos=3892730;
   }
   sf.pos=3892731;
   if ((Vc != Y3QJ))
   {
    sf.pos=3892732;
    YjUM__Ydti((&Yl_6), YGBv(Ain));
   }
  }
  }}
  sf.pos=3892733;
  Vc = YGBv(Ain);
 sf.pos=3892734;
 }
 sf.pos=3892735;
 YPmF(Ain, Vc);
 sf.pos=3892736;
 if (VisSep)
 {
  sf.pos=3892737;
  if (VhasLineBreak)
  {
   sf.pos=3892738;
   Ares->Vtype = 3;
  }
  else
  {
   sf.pos=3892739;
   Ares->Vtype = 2;
  }
 }
 else {
 sf.pos=3892740;
 if (Ares->VhasComment)
 {
  sf.pos=3892741;
  Ares->Vtype = 4;
 }
 else
 {
  sf.pos=3892742;
  Ares->Vtype = 5;
  sf.pos=3892743;
  rt = 1;
  goto YBbM;
 }
 }
 sf.pos=3892744;
 Ares->Vvalue = YbNW((&Yl_6));
 sf.pos=3892745;
 Y3_a((&Yl_6));
YBbM:
 topFrame = sf.prev;
 return;
}
To ToYsZx[] = {
 {2, 0},
 {0, (Tt*)&array__T}, /* children */
 {0, (Tt*)&string__T}, /* value */
};
Tto YsZx__T = {390, (Tc*)&Y2N6, 0, ToYsZx};
void Yfh4(Tc *Aname, Te Atype, Tb AisKeyword) {
 Zsf sf;
 YsZx *Vn = 0;
 Tc *Zf1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3490500;
 Vn = (&YXGF);
 sf.pos=3490501;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = Aname;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vc); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vc)) {
  sf.pos=3490502;
  if ((Vn->Vchildren == NULL))
  {
   sf.pos=3490503;
   Vn->Vchildren = ZnewArray((Tt*)&YsZx__T, sizeof(YsZx*), 128);
  }
  sf.pos=3490504;
  if (((*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc)) == NULL))
  {
   sf.pos=3490505;
   (*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc)) = Za(sizeof(YsZx));
  }
  sf.pos=3490506;
  Vn = (*(YsZx**)ZarrayPtr(Vn->Vchildren, Vc));
  sf.pos=3490507;
  }
 }
 sf.pos=3490508;
 if ((Vn->Vvalue != NULL))
 {
  sf.pos=3490509;
  Y2oO(ZcS(((Tc*)&Yqcm), Aname), NULL, 0);
 }
 sf.pos=3490510;
 Vn->Vvalue = Aname;
 sf.pos=3490511;
 Vn->Vtype = Atype;
 sf.pos=3490512;
 Vn->VisKeyword = AisKeyword;
 topFrame = sf.prev;
 return;
}
Ts YTyo() {
 Zsf sf;
 Ts r = 0;
 Tl *Zf1 = NULL;
 Tc *Vkey = NULL;
 Tl *Zf11 = NULL;
 Tc *Vkey1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3488200;
 ZnoAllocClear(sizeof(YsZx), &YXGF, NULL);
 sf.pos=3488201;
 {
  Tfl Zf1i;
  Zf1 = ZDictKeys((&Y3rf), 0);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vkey;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=3488202;
  Yfh4(Vkey, ZDictGetInt((&Y3rf), (Tz)(void*)Vkey), 0);
  sf.pos=3488203;
  }
 }
 sf.pos=3488204;
 {
  Tfl Zf11i;
  Zf11 = ZDictKeys((&Y0sf), 0);
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&Vkey1;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=3488205;
  Yfh4(Vkey1, ZDictGetInt((&Y0sf), (Tz)(void*)Vkey1), 1);
  sf.pos=3488206;
  }
 }
 sf.pos=3488207;
 r = 1;
 topFrame = sf.prev;
 return r;
}
Ts Ybdf(Y7Sj *Ain, Yev8 *Ares) {
 Ti Vc1;
 Zsf sf;
 Ts r = 0;
 YsZx *Vn = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9699200;
 Vc1 = YGBv(Ain);
 sf.pos=9699201;
 if ((Vc1 == Y3QJ))
 {
  sf.pos=9699202;
  Ares->Vtype = 1;
  sf.pos=9699203;
  r = 1;
  rt = 1;
  goto Yfhb;
 }
 sf.pos=9699204;
 if ((Vc1 < 128))
 {
  sf.pos=9699205;
  Vn = (*(YsZx**)ZarrayPtr((&YXGF)->Vchildren, Vc1));
  sf.pos=9699206;
  if ((Vn != NULL))
  {
   sf.pos=9699207;
   if ((Vn->Vchildren != NULL))
   {
    sf.pos=9699208;
    if ((YY69(Ain, Vn, Ares) == 1))
    {
     sf.pos=9699209;
     r = 1;
     rt = 1;
     goto YSwi;
    }
YSwi:
    if (rt) goto Yc4Z;
   }
   sf.pos=9699210;
   if (((Vn->Vvalue != NULL) && ((!(Vn->VisKeyword) || !(YIA3(YHT_(Ain)))))))
   {
    sf.pos=9699211;
    Ares->Vtype = Vn->Vtype;
    sf.pos=9699212;
    Ares->Vvalue = Vn->Vvalue;
    sf.pos=9699213;
    r = 1;
    rt = 1;
    goto Yc4Z;
   }
Yc4Z:
   if (rt) goto Ysx1;
  }
Ysx1:
  if (rt) goto Yfhb;
 }
 sf.pos=9699214;
 YPmF(Ain, Vc1);
 sf.pos=9699215;
 r = 0;
Yfhb:
 topFrame = sf.prev;
 return r;
}
Ts YY69(Y7Sj *Ain, YsZx *An, Yev8 *Ares) {
 Ti Vc;
 Zsf sf;
 Ts r = 0;
 YsZx *Vn2 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6000300;
 Vc = YGBv(Ain);
 sf.pos=6000301;
 if (((Vc > 0) && (Vc < 128)))
 {
  sf.pos=6000302;
  Vn2 = (*(YsZx**)ZarrayPtr(An->Vchildren, Vc));
  sf.pos=6000303;
  if ((Vn2 != NULL))
  {
   sf.pos=6000304;
   if ((Vn2->Vchildren != NULL))
   {
    sf.pos=6000305;
    if ((YY69(Ain, Vn2, Ares) == 1))
    {
     sf.pos=6000306;
     r = 1;
     rt = 1;
     goto YeiW;
    }
YeiW:
    if (rt) goto YyJq;
   }
   sf.pos=6000307;
   if (((Vn2->Vvalue != NULL) && ((!(Vn2->VisKeyword) || !(YIA3(YHT_(Ain)))))))
   {
    sf.pos=6000308;
    Ares->Vtype = Vn2->Vtype;
    sf.pos=6000309;
    Ares->Vvalue = Vn2->Vvalue;
    sf.pos=6000310;
    r = 1;
    rt = 1;
    goto YyJq;
   }
YyJq:
   if (rt) goto Yyxk;
  }
Yyxk:
  if (rt) goto Ykt8;
 }
 sf.pos=6000311;
 YPmF(Ain, Vc);
 sf.pos=6000312;
 r = 0;
Ykt8:
 topFrame = sf.prev;
 return r;
}
int JTokenizer(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 if (round == 2001) {
   sf.pos=2055500;
   ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictInit(&Y3rf, (Tt*)&string__T, (Tt*)&CToken__EType__T, 0), (Tz)(void*)((Tc*)&Y_y2), (Tz)(Ti)20), (Tz)(void*)((Tc*)&Yez2), (Tz)(Ti)122), (Tz)(void*)((Tc*)&YzUC), (Tz)(Ti)123), (Tz)(void*)((Tc*)&YC5H), (Tz)(Ti)124), (Tz)(void*)((Tc*)&YD5H), (Tz)(Ti)27), (Tz)(void*)((Tc*)&YyUC), (Tz)(Ti)28), (Tz)(void*)((Tc*)&Y2_), (Tz)(Ti)127), (Tz)(void*)((Tc*)&Y40), (Tz)(Ti)129), (Tz)(void*)((Tc*)&Y1ia), (Tz)(Ti)99), (Tz)(void*)((Tc*)&Yhja), (Tz)(Ti)113), (Tz)(void*)((Tc*)&YNfa), (Tz)(Ti)101), (Tz)(void*)((Tc*)&Y4fa), (Tz)(Ti)114), (Tz)(void*)((Tc*)&Ytea), (Tz)(Ti)115), (Tz)(void*)((Tc*)&Yuma), (Tz)(Ti)116), (Tz)(void*)((Tc*)&Ys6), (Tz)(Ti)117), (Tz)(void*)((Tc*)&Y8mc), (Tz)(Ti)118), (Tz)(void*)((Tc*)&Y37), (Tz)(Ti)119), (Tz)(void*)((Tc*)&YWjc), (Tz)(Ti)120), (Tz)(void*)((Tc*)&YQyb), (Tz)(Ti)121), (Tz)(void*)((Tc*)&YWIa), (Tz)(Ti)125), (Tz)(void*)((Tc*)&YXIa), (Tz)(Ti)126), (Tz)(void*)((Tc*)&YYJa), (Tz)(Ti)128), (Tz)(void*)((Tc*)&YjHa), (Tz)(Ti)111), (Tz)(void*)((Tc*)&YyKa), (Tz)(Ti)110), (Tz)(void*)((Tc*)&YkHa), (Tz)(Ti)136), (Tz)(void*)((Tc*)&YxKa), (Tz)(Ti)134), (Tz)(void*)((Tc*)&YH7), (Tz)(Ti)130), (Tz)(void*)((Tc*)&YWkc), (Tz)(Ti)131), (Tz)(void*)((Tc*)&YEka), (Tz)(Ti)106), (Tz)(void*)((Tc*)&Y5La), (Tz)(Ti)86), (Tz)(void*)((Tc*)&YULa), (Tz)(Ti)87), (Tz)(void*)((Tc*)&YH), (Tz)(Ti)132), (Tz)(void*)((Tc*)&YK), (Tz)(Ti)97), (Tz)(void*)((Tc*)&YL), (Tz)(Ti)105), (Tz)(void*)((Tc*)&YM), (Tz)(Ti)109), (Tz)(void*)((Tc*)&YO), (Tz)(Ti)90), (Tz)(void*)((Tc*)&YP), (Tz)(Ti)91), (Tz)(void*)((Tc*)&YQ), (Tz)(Ti)103), (Tz)(void*)((Tc*)&YR), (Tz)(Ti)100), (Tz)(void*)((Tc*)&YS), (Tz)(Ti)82), (Tz)(void*)((Tc*)&YT), (Tz)(Ti)98), (Tz)(void*)((Tc*)&YU), (Tz)(Ti)89), (Tz)(void*)((Tc*)&YV), (Tz)(Ti)104), (Tz)(void*)((Tc*)&Y5), (Tz)(Ti)84), (Tz)(void*)((Tc*)&Y6), (Tz)(Ti)83), (Tz)(void*)((Tc*)&Y7), (Tz)(Ti)135), (Tz)(void*)((Tc*)&Y8), (Tz)(Ti)112), (Tz)(void*)((Tc*)&Y9), (Tz)(Ti)133), (Tz)(void*)((Tc*)&Yba), (Tz)(Ti)88), (Tz)(void*)((Tc*)&Ygbb), (Tz)(Ti)95), (Tz)(void*)((Tc*)&YCa), (Tz)(Ti)94), (Tz)(void*)((Tc*)&YEa), (Tz)(Ti)96), (Tz)(void*)((Tc*)&YFa), (Tz)(Ti)108), (Tz)(void*)((Tc*)&Y7a), (Tz)(Ti)92), (Tz)(void*)((Tc*)&Y8a), (Tz)(Ti)107), (Tz)(void*)((Tc*)&Y9a), (Tz)(Ti)93), (Tz)(void*)((Tc*)&Yab), (Tz)(Ti)102), (Tz)(void*)((Tc*)&Yaa), (Tz)(Ti)85);
   sf.pos=2055501;
   ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictInit(&Y0sf, (Tt*)&string__T, (Tt*)&CToken__EType__T, 0), (Tz)(void*)((Tc*)&Yu2V), (Tz)(Ti)25), (Tz)(void*)((Tc*)&YBjQ), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YHPa), (Tz)(Ti)23), (Tz)(void*)((Tc*)&YjG6), (Tz)(Ti)36), (Tz)(void*)((Tc*)&YZOS), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YZzE), (Tz)(Ti)69), (Tz)(void*)((Tc*)&YOgo), (Tz)(Ti)57), (Tz)(void*)((Tc*)&YwZW), (Tz)(Ti)58), (Tz)(void*)((Tc*)&YCSN), (Tz)(Ti)59), (Tz)(void*)((Tc*)&Ydl6), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YxBe), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yea), (Tz)(Ti)55), (Tz)(void*)((Tc*)&Y6FU), (Tz)(Ti)73), (Tz)(void*)((Tc*)&YCun), (Tz)(Ti)50), (Tz)(void*)((Tc*)&YPQP), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YK2B), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YMwW), (Tz)(Ti)30), (Tz)(void*)((Tc*)&Yn3A), (Tz)(Ti)70), (Tz)(void*)((Tc*)&YeuV), (Tz)(Ti)142), (Tz)(void*)((Tc*)&YUlG), (Tz)(Ti)74), (Tz)(void*)((Tc*)&Yqcs), (Tz)(Ti)52), (Tz)(void*)((Tc*)&YrUa), (Tz)(Ti)75), (Tz)(void*)((Tc*)&Yga), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yc7A), (Tz)(Ti)66), (Tz)(void*)((Tc*)&Y9jU), (Tz)(Ti)65), (Tz)(void*)((Tc*)&YnjG), (Tz)(Ti)35), (Tz)(void*)((Tc*)&YsI4), (Tz)(Ti)47), (Tz)(void*)((Tc*)&YDN8), (Tz)(Ti)40), (Tz)(void*)((Tc*)&Y8ag), (Tz)(Ti)12), (Tz)(void*)((Tc*)&Y2cy), (Tz)(Ti)9), (Tz)(void*)((Tc*)&YdbBa), (Tz)(Ti)51), (Tz)(void*)((Tc*)&Yz51), (Tz)(Ti)77), (Tz)(void*)((Tc*)&YqI4), (Tz)(Ti)37), (Tz)(void*)((Tc*)&Y3Ya), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yuso), (Tz)(Ti)62), (Tz)(void*)((Tc*)&Ycx0), (Tz)(Ti)61), (Tz)(void*)((Tc*)&Yf3i), (Tz)(Ti)63), (Tz)(void*)((Tc*)&Y1Ce), (Tz)(Ti)60), (Tz)(void*)((Tc*)&Yup4), (Tz)(Ti)19), (Tz)(void*)((Tc*)&Yith), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0hh), (Tz)(Ti)141), (Tz)(void*)((Tc*)&Yka), (Tz)(Ti)56), (Tz)(void*)((Tc*)&Yj1a), (Tz)(Ti)64), (Tz)(void*)((Tc*)&Y4UI), (Tz)(Ti)67), (Tz)(void*)((Tc*)&Y4lO), (Tz)(Ti)41), (Tz)(void*)((Tc*)&YML6), (Tz)(Ti)22), (Tz)(void*)((Tc*)&Yr1a), (Tz)(Ti)78), (Tz)(void*)((Tc*)&Ygis), (Tz)(Ti)42), (Tz)(void*)((Tc*)&YxM9), (Tz)(Ti)43), (Tz)(void*)((Tc*)&YLM9), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0as), (Tz)(Ti)33), (Tz)(void*)((Tc*)&Ys1aa), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yw1a), (Tz)(Ti)137), (Tz)(void*)((Tc*)&YtU9), (Tz)(Ti)139), (Tz)(void*)((Tc*)&YCHh), (Tz)(Ti)138), (Tz)(void*)((Tc*)&Y5nR), (Tz)(Ti)140), (Tz)(void*)((Tc*)&YAcL), (Tz)(Ti)39), (Tz)(void*)((Tc*)&YVvha), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YKxe), (Tz)(Ti)29), (Tz)(void*)((Tc*)&Yqim), (Tz)(Ti)45), (Tz)(void*)((Tc*)&YZom), (Tz)(Ti)53), (Tz)(void*)((Tc*)&ZNilString), (Tz)(Ti)6), (Tz)(void*)((Tc*)&Yizy), (Tz)(Ti)44), (Tz)(void*)((Tc*)&Y0ab), (Tz)(Ti)11), (Tz)(void*)((Tc*)&Y2gz), (Tz)(Ti)24), (Tz)(void*)((Tc*)&YV4t), (Tz)(Ti)8), (Tz)(void*)((Tc*)&YNqR), (Tz)(Ti)34), (Tz)(void*)((Tc*)&YsNN), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y6T9), (Tz)(Ti)38), (Tz)(void*)((Tc*)&Ysa6), (Tz)(Ti)71), (Tz)(void*)((Tc*)&YgRl), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YGD1), (Tz)(Ti)46), (Tz)(void*)((Tc*)&YZXw), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YuOB), (Tz)(Ti)31), (Tz)(void*)((Tc*)&YuyE), (Tz)(Ti)32), (Tz)(void*)((Tc*)&Y4xB), (Tz)(Ti)81), (Tz)(void*)((Tc*)&Yaof), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y0Y5), (Tz)(Ti)72), (Tz)(void*)((Tc*)&YALz), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Yva), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Ytoe), (Tz)(Ti)7), (Tz)(void*)((Tc*)&YVLC), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YTJV), (Tz)(Ti)48), (Tz)(void*)((Tc*)&YA3g), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YNVB), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y5ib), (Tz)(Ti)79), (Tz)(void*)((Tc*)&YHoE), (Tz)(Ti)10), (Tz)(void*)((Tc*)&Yn9B), (Tz)(Ti)49), (Tz)(void*)((Tc*)&Y7fW), (Tz)(Ti)26), (Tz)(void*)((Tc*)&YexT), (Tz)(Ti)76), (Tz)(void*)((Tc*)&YAKE), (Tz)(Ti)18), (Tz)(void*)((Tc*)&YRRGa), (Tz)(Ti)17), (Tz)(void*)((Tc*)&YD2V), (Tz)(Ti)21), (Tz)(void*)((Tc*)&Y_r2), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YRA8), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YHo2), (Tz)(Ti)68), (Tz)(void*)((Tc*)&YBa), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YDER), (Tz)(Ti)21), (Tz)(void*)((Tc*)&YQHR), (Tz)(Ti)21);
   sf.pos=2055502;
   ZnoAllocClear(sizeof(YjUM), &Yc6N, NULL);
   sf.pos=2055503;
   ZnoAllocClear(sizeof(YjUM), &Yl_6, NULL);
  done = 0;
  } else if (round > 2001) {
    if (YTyo__r == 0) {
      YTyo__r = YTyo();
      done &= YTyo__r;
    }
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Tokenizer done */
Y7Sj *YUwt(Y7Sj *t, YeYq *Ainput) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6388600; t = Za(sizeof(Y7Sj));}
 sf.pos=6388601;
 t->Vinput = Ainput;
 sf.pos=6388602;
 t->VtokenStack = ZnewList((Tt*)&Yev8__T, 0);
 sf.pos=6388603;
 t->VusedIdKeywords = Yh95(NULL);
 topFrame = sf.prev;
 return t;
}
Ti YGBv(Y7Sj *t) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3937200;
  ZthrowThisNil();
 }
 sf.pos=3937201;
 r = YAit(t->Vinput);
 topFrame = sf.prev;
 return r;
}
void YPmF(Y7Sj *t, Ti Ac) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=9233600;
  ZthrowThisNil();
 }
 sf.pos=9233601;
 YmK2(t->Vinput, Ac);
 topFrame = sf.prev;
 return;
}
Ti YHT_(Y7Sj *t) {
 Ti Vc;
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3230900;
  ZthrowThisNil();
 }
 sf.pos=3230901;
 Vc = YGBv(t);
 sf.pos=3230902;
 YPmF(t, Vc);
 sf.pos=3230903;
 r = Vc;
 topFrame = sf.prev;
 return r;
}
Tc *YUrw(Y7Sj *t) {
 Zsf sf;
 Tc *r = 0;
 YjUM *Vsw = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=6727600;
  ZthrowThisNil();
 }
 sf.pos=6727601;
 Vsw = Za(sizeof(YjUM));
 sf.pos=6727602;
 while (1)
 {
  Ti Vc;
  sf.pos=6727603;
  Vc = YGBv(t);
  sf.pos=6727604;
  if ((!(isalpha(Vc)) && (Vc != 95)))
  {
   sf.pos=6727605;
   YPmF(t, Vc);
   rt = 2;
   goto Yvki;
  }
  sf.pos=6727606;
  YJqza(Vsw, ZintAsString(Vc));
Yvki:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6727607;
 }
 sf.pos=6727608;
 r = YbNW(Vsw);
 topFrame = sf.prev;
 return r;
}
Tb Y7_i(Y7Sj *t) {
 Ti Vc;
 Zsf sf;
 Tb r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5923600;
  ZthrowThisNil();
 }
 sf.pos=5923601;
 Vc = YGBv(t);
 sf.pos=5923602;
 if ((Vc != 32))
 {
  sf.pos=5923603;
  YPmF(t, Vc);
  sf.pos=5923604;
  r = 0;
  rt = 1;
  goto YuqQ;
 }
 sf.pos=5923605;
 while ((Vc == 32))
 {
  sf.pos=5923606;
  Vc = YGBv(t);
 sf.pos=5923607;
 }
 sf.pos=5923608;
 YPmF(t, Vc);
 sf.pos=5923609;
 r = 1;
YuqQ:
 topFrame = sf.prev;
 return r;
}
Yev8 *Y_PN(Y7Sj *t) {
 Zsf sf;
 Yev8 *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3225700;
  ZthrowThisNil();
 }
 sf.pos=3225701;
 if ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=3225702;
  r = ZListRemovePtrItem((Tl*)t->VtokenStack, -1);
  rt = 1;
  goto YNOF;
 }
 sf.pos=3225703;
 r = Yx5t(t);
YNOF:
 topFrame = sf.prev;
 return r;
}
void YH7I(Y7Sj *t, Yev8 *Atoken) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2491700;
  ZthrowThisNil();
 }
 sf.pos=2491701;
 ZLap((Tl*)t->VtokenStack, (Tz)(void*)Atoken);
 topFrame = sf.prev;
 return;
}
Yev8 *YksM(Y7Sj *t) {
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vtoken = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=300600;
  ZthrowThisNil();
 }
 sf.pos=300601;
 if ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=300602;
  r = ((Yev8 *)ZListGetPtr(t->VtokenStack, (ZListSize(t->VtokenStack) - 1)));
  rt = 1;
  goto YS9s;
 }
 sf.pos=300603;
 Vtoken = Yx5t(t);
 sf.pos=300604;
 ZLap((Tl*)t->VtokenStack, (Tz)(void*)Vtoken);
 sf.pos=300605;
 r = Vtoken;
YS9s:
 topFrame = sf.prev;
 return r;
}
void YGzQ(Y7Sj *t) {
 Zsf sf;
 Yev8 *Vt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3978900;
  ZthrowThisNil();
 }
 sf.pos=3978901;
 while ((ZListSize(t->VtokenStack) > 0))
 {
  sf.pos=3978902;
  Vt = ZListRemovePtrItem((Tl*)t->VtokenStack, -1);
  sf.pos=3978903;
  {
   Ti Vi;
   Tfr Zf2;
   ZforRangeNew((ZstringSize(Vt->Vvalue) - 1), 0, 0, -1, &Zf2);
   for (ZforRangeGetInt(&Zf2, &Vi); ZforRangeContInt(&Zf2); ZforRangeNextInt(&Zf2, &Vi)) {
   sf.pos=3978904;
   YPmF(t, ZstringGetChar(Vt->Vvalue, Vi));
   sf.pos=3978905;
   }
  }
 sf.pos=3978906;
 }
 topFrame = sf.prev;
 return;
}
void Y5yp(Y7Sj *t, Tc *Amsg) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5495000;
  ZthrowThisNil();
 }
 sf.pos=5495001;
 YDli(Amsg, t->Vinput->Vpos, 0);
 topFrame = sf.prev;
 return;
}
To ToY7Sj[] = {
 {3, 0},
 {0, (Tt*)&YeYq__T}, /* input */
 {0, (Tt*)&list__T}, /* tokenStack */
 {0, (Tt*)&Yhqr__T}, /* usedIdKeywords */
};
Tto Y7Sj__T = {390, (Tc*)&YnOq, 0, ToY7Sj};
int JTokenInput(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 done &= JTokenizer(round);
 if (round == 2001) {
  }
  topFrame = sf.prev;
 }
 return done;
}
/* TokenInput done */
To ToYL4o[] = {
 {1, 0},
 {0, (Tt*)&Yhqr__T}, /* usedIdKeywords */
};
Tto YL4o__T = {390, (Tc*)&YL2R, 0, ToYL4o};
YjS4 Yl0s(Tc *AfileName, Tc *Aindent, Tbb AblockType) {
 Zsf sf;
 YjS4 r;
 Tr VinFile = {NULL};
 YeYq *Vinput = 0;
 Y7Sj *Vin = 0;
 YL4o *Vpr = 0;
 Yol9 *Vcontents = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4384500;
 VinFile = YsGz(AfileName);
 sf.pos=4384501;
 if ((((VinFile).ptr) == NULL))
 {
  sf.pos=4384502;
  r.a1 = NULL;
  r.a0 = NULL;
  rt = 1;
  goto Ytfa;
 }
 sf.pos=4384503;
 Vinput = YOdr(NULL, VinFile, AfileName, Aindent, 0);
 sf.pos=4384504;
 Vin = YUwt(NULL, Vinput);
 sf.pos=4384505;
 YDY4(ZcS3((t1 = Aindent), (t0 = AfileName), ((Tc*)&Yxtr)), NULL, 0);
 sf.pos=4384506;
 Vpr = Za(sizeof(YL4o));
 sf.pos=4384507;
 YBch(Vin);
 sf.pos=4384508;
 Vcontents = YzBD(NULL);
 sf.pos=4384509;
 YNYW(Vin, Vcontents);
 sf.pos=4384510;
 Ygty(Vin, AblockType, Vcontents);
 sf.pos=4384511;
 Vpr->VusedIdKeywords = Vin->VusedIdKeywords;
 sf.pos=4384512;
 ((Ts (*)(void*))(VinFile.table[35]))(VinFile.ptr);
 sf.pos=4384513;
 r.a1 = Vpr;
 r.a0 = Vcontents;
Ytfa:
 topFrame = sf.prev;
 return r;
}
void YNYW(Y7Sj *Ain, Yol9 *Acontents) {
 Ti VimportNumber;
 Zsf sf;
 Yev8 *Vtoken = 0;
 Yev8 *VfirstSep = 0;
 Tc *Vplugin = NULL;
 Yev8 *Vnext = 0;
 Tc *VfileName = NULL;
 Ysbp *Vpos = 0;
 YjUM *Vw = 0;
 Tc *VasName = NULL;
 Tc *Voptions = NULL;
 YJON *Vza = 0;
 YqKm *Vimport = 0;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VimportNumber = 0;
 sf.pos=6827500;
 VfirstSep = Y3DE;
 sf.pos=6827501;
 while (1)
 {
  sf.pos=6827502;
  Vtoken = Y_PN(Ain);
  sf.pos=6827503;
  if ((Vtoken->Vtype != 22))
  {
   sf.pos=6827504;
   YH7I(Ain, Vtoken);
   rt = 2;
   goto YPZU;
  }
  Vplugin = NULL;
  sf.pos=6827505;
  Vnext = Y6qU(Ain);
  sf.pos=6827506;
  if ((Vnext->Vtype == 89))
  {
   sf.pos=6827507;
   YuRk(Ain);
   sf.pos=6827508;
   Vtoken = Y_PN(Ain);
   sf.pos=6827509;
   YuRk(Ain);
   sf.pos=6827510;
   Vtoken = Y_PN(Ain);
   sf.pos=6827511;
   if ((Vtoken->Vtype != 21))
   {
    sf.pos=6827512;
    YdIu(Vtoken, ((Tc*)&YbdI));
   }
   else
   {
    sf.pos=6827513;
    Vplugin = Vtoken->Vvalue;
   }
  }
  sf.pos=6827514;
  YzLT(Ain);
  sf.pos=6827515;
  Vtoken = Y_PN(Ain);
  sf.pos=6827516;
  if (((Vtoken->Vtype != 13) && (Vtoken->Vtype != 135)))
  {
   sf.pos=6827517;
   YdIu(Vtoken, ((Tc*)&Y0jB));
   sf.pos=6827518;
   YH7I(Ain, Vtoken);
  }
  else
  {
   Tb Vangle;
   Tb Vjavascript;
   sf.pos=6827519;
   VfileName = Vtoken->Vvalue;
   sf.pos=6827520;
   Vpos = Vtoken->VzuiPos;
   Vangle = 0;
   sf.pos=6827521;
   if ((Vtoken->Vtype == 135))
   {
    sf.pos=6827522;
    Vangle = 1;
    sf.pos=6827523;
    Vw = Za(sizeof(YjUM));
    sf.pos=6827524;
    while (1)
    {
     Ti Vc;
     sf.pos=6827525;
     Vc = YGBv(Ain);
     sf.pos=6827526;
     if (((Vc == Y3QJ) || (Vc == 10)))
     {
      sf.pos=6827527;
      YdIu(Vtoken, ((Tc*)&YnLg));
      rt = 2;
      goto YM1m;
     }
     sf.pos=6827528;
     if ((Vc == 62))
     {
      rt = 2;
      goto YM1m;
     }
     sf.pos=6827529;
     YjUM__Ydti(Vw, Vc);
YM1m:
     if (rt == 2) { rt &= 1; break; }
    sf.pos=6827530;
    }
    sf.pos=6827531;
    VfileName = YbNW(Vw);
   }
   VasName = NULL;
   Voptions = NULL;
   Vjavascript = 0;
   sf.pos=6827532;
   while (1)
   {
    sf.pos=6827533;
    switch (Y6qU(Ain)->Vtype)
    {
    case 23:
     {
      sf.pos=6827534;
      Vtoken = YABA(Ain);
      sf.pos=6827535;
      if ((VasName != NULL))
      {
       sf.pos=6827536;
       YdIu(Vtoken, ((Tc*)&YXzm));
      }
      else
      {
       sf.pos=6827537;
       VasName = Vtoken->Vvalue;
      }
      rt = 4;
      if (rt == 4) { rt &= 1; continue; }
       break;
     }
    case 24:
     {
      sf.pos=6827538;
      YzLT(Ain);
      sf.pos=6827539;
      Vtoken = Y_PN(Ain);
      sf.pos=6827540;
      YzLT(Ain);
      sf.pos=6827541;
      Vtoken = Y_PN(Ain);
      sf.pos=6827542;
      if ((Vtoken->Vtype != 13))
      {
       sf.pos=6827543;
       YdIu(Vtoken, ((Tc*)&YAo4));
      }
      else {
      sf.pos=6827544;
 if ((Voptions != NULL))
      {
       sf.pos=6827545;
       YdIu(Vtoken, ((Tc*)&YLLV));
      }
      else
      {
       sf.pos=6827546;
       Voptions = Vtoken->Vvalue;
      }
      }
      rt = 4;
      if (rt == 4) { rt &= 1; continue; }
       break;
     }
    case 88:
     {
      sf.pos=6827547;
      Vza = YsCX(NULL);
      sf.pos=6827548;
      Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YE5Z))), Ain);
      sf.pos=6827549;
      Vjavascript = YiKB(Vza);
      rt = 4;
      if (rt == 4) { rt &= 1; continue; }
       break;
     }
     if (rt) goto YPJd;
    }
    rt = 2;
YPJd:
    if (rt == 2) { rt &= 1; break; }
    if (rt == 4) { rt &= 1; continue; }
   sf.pos=6827550;
   }
   sf.pos=6827551;
   YE5j(Ain);
   sf.pos=6827552;
   if ((Acontents != NULL))
   {
    sf.pos=6827553;
    Vimport = YNk6(Acontents);
    sf.pos=6827554;
    Y6Pf(Vimport, VfileName);
    sf.pos=6827555;
    Y0hJ(Vimport, Vplugin);
    sf.pos=6827556;
    YQa2(Vimport, Voptions);
    sf.pos=6827557;
    YygQ(Vimport, Vjavascript);
    sf.pos=6827558;
    if ((VasName != NULL))
    {
     sf.pos=6827559;
     YYIq(Vimport, VasName);
    }
    sf.pos=6827560;
    if (Vangle)
    {
     sf.pos=6827561;
     YWuz(Vimport, 1);
    }
    sf.pos=6827562;
    YimL(Vimport, Vpos);
    sf.pos=6827563;
    YQBo(Vimport, ++(VimportNumber));
   }
  }
YPZU:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6827564;
 }
 sf.pos=6827565;
 if (!(Y3DE->VhasComment))
 {
  sf.pos=6827566;
  Y3DE = VfirstSep;
 }
 topFrame = sf.prev;
 return;
}
Yev8 *YABA(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1265400;
 YzLT(Ain);
 sf.pos=1265401;
 Vtoken = Y_PN(Ain);
 sf.pos=1265402;
 YzLT(Ain);
 sf.pos=1265403;
 Vtoken = Y_PN(Ain);
 sf.pos=1265404;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=1265405;
  YdIu(Vtoken, ((Tc*)&YXPH));
 }
 sf.pos=1265406;
 r = Vtoken;
 topFrame = sf.prev;
 return r;
}
void Ygty(Y7Sj *Ain, Tbb AblockTypeIn, Yol9 *Acontents) {
 Tb VhadBlockItem;
 Tbb VblockType;
 Zsf sf;
 Yev8 *Vtoken = 0;
 Tl *Vstatements = NULL;
 YXCg *Vstmt = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VhadBlockItem = 0;
 sf.pos=5187300;
 VblockType = AblockTypeIn;
 sf.pos=5187301;
 VblockType = ((VblockType) & -9) | ((0) << 3);
 sf.pos=5187302;
 Vstatements = ZnewList((Tt*)&YXCg__T, 0);
 sf.pos=5187303;
 while (1)
 {
  sf.pos=5187304;
  Vtoken = Y_PN(Ain);
  sf.pos=5187305;
  if ((Vtoken->Vtype == 1))
  {
   rt = 2;
   goto YH0O;
  }
  sf.pos=5187306;
  if (((!((((VblockType) & 1))) && (((VblockType) & 2) >> 1)) && VhadBlockItem))
  {
   sf.pos=5187307;
   if ((Vtoken->Vtype == 93))
   {
    sf.pos=5187308;
    YdIu(Vtoken, ((Tc*)&YLl7));
   }
   else
   {
    sf.pos=5187309;
    YdIu(Vtoken, ((Tc*)&YhQ4));
   }
  }
  sf.pos=5187310;
  VhadBlockItem = 1;
  sf.pos=5187311;
  YH7I(Ain, Vtoken);
  sf.pos=5187312;
  Vstmt = YjwQ(Ain, VblockType);
  sf.pos=5187313;
  if ((Vstmt == NULL))
  {
   sf.pos=5187314;
   Vtoken = Y_PN(Ain);
   sf.pos=5187315;
   if ((Vtoken->Vtype == 1))
   {
    rt = 2;
    goto YHcG;
   }
   else {
   sf.pos=5187316;
 if ((Vtoken->Vtype == 93))
   {
    sf.pos=5187317;
    YdIu(Vtoken, ((Tc*)&YLl7));
   }
   else
   {
    sf.pos=5187318;
    YREn(Vtoken);
   }
   }
YHcG:
   if (rt) goto YH0O;
  }
  else {
  sf.pos=5187319;
 if ((Vstmt != (&YIbB)))
  {
   sf.pos=5187320;
   if ((YuqZ(Vstmt) == 36))
   {
    sf.pos=5187321;
    ZListExtend((Tl*)Vstatements, YM4H(Vstmt));
   }
   else
   {
    sf.pos=5187322;
    ZLap((Tl*)Vstatements, (Tz)(void*)Vstmt);
   }
  }
  }
YH0O:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=5187323;
 }
 sf.pos=5187324;
 YVAS(Acontents, Vstatements);
 topFrame = sf.prev;
 return;
}
Tl *YBd7(Y7Sj *Ain, Tbb AblockType) {
 Zsf sf;
 Tl *r = 0;
 Tl *Vstatements = NULL;
 YXCg *Vstmt = 0;
 Yev8 *Vtoken = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9903600;
 Vstatements = ZnewList((Tt*)&YXCg__T, 0);
 sf.pos=9903601;
 while (1)
 {
  sf.pos=9903602;
  Vstmt = YjwQ(Ain, AblockType);
  sf.pos=9903603;
  if ((Vstmt == NULL))
  {
   rt = 2;
   goto Ylf1;
  }
  sf.pos=9903604;
  if ((Vstmt != (&YIbB)))
  {
   sf.pos=9903605;
   if ((YuqZ(Vstmt) == 36))
   {
    sf.pos=9903606;
    ZListExtend((Tl*)Vstatements, YM4H(Vstmt));
   }
   else
   {
    sf.pos=9903607;
    ZLap((Tl*)Vstatements, (Tz)(void*)Vstmt);
   }
  }
Ylf1:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9903608;
 }
 sf.pos=9903609;
 if (!((((AblockType) & 8) >> 3)))
 {
  sf.pos=9903610;
  Vtoken = Y_PN(Ain);
  sf.pos=9903611;
  if ((Vtoken->Vtype != 93))
  {
   sf.pos=9903612;
   YdIu(Vtoken, ((Tc*)&YbEV));
  }
  else
  {
   sf.pos=9903613;
   YE5j(Ain);
  }
 }
 sf.pos=9903614;
 r = Vstatements;
 topFrame = sf.prev;
 return r;
}
YXCg *YjwQ(Y7Sj *Ain, Tbb AblockType) {
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vtoken = 0;
 YXCg *Vstmt = 0;
 Yev8 *VnextToken = 0;
 YXCg *Vstmt1 = 0;
 YnZD *VnameExpr = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1249900;
 Vtoken = Y_PN(Ain);
 sf.pos=1249901;
 switch (Vtoken->Vtype)
 {
 case 1:
  {
   sf.pos=1249902;
   YHwp(((Tc*)&YPTa), Ain);
   sf.pos=1249903;
   r = NULL;
   rt = 1;
   goto YLVG;
  }
 case 3:
 case 2:
 case 4:
  {
   sf.pos=1249904;
   r = (&YIbB);
   rt = 1;
   goto YLVG;
  }
 case 93:
  {
   sf.pos=1249905;
   YH7I(Ain, Vtoken);
   sf.pos=1249906;
   r = NULL;
   rt = 1;
   goto YLVG;
  }
 case 13:
  {
   sf.pos=1249907;
   YdIu(Vtoken, ZcS3(((Tc*)&YlkF), Vtoken->Vvalue, ((Tc*)&YN)));
   sf.pos=1249908;
   r = (&YIbB);
   rt = 1;
   goto YLVG;
  }
 case 25:
 case 26:
  {
   sf.pos=1249909;
   r = YBsI(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 27:
  {
   sf.pos=1249910;
   Vstmt = YPL0(Ain);
   sf.pos=1249911;
   r = Vstmt;
   rt = 1;
   goto YLVG;
  }
 case 55:
  {
   sf.pos=1249912;
   r = YksO(Ain);
   rt = 1;
   goto YLVG;
  }
 case 29:
  {
   sf.pos=1249913;
   r = Y4h6(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 30:
 case 33:
 case 34:
  {
   sf.pos=1249914;
   r = YTWI(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 42:
  {
   sf.pos=1249915;
   r = YEc4(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 31:
  {
   sf.pos=1249916;
   if ((((AblockType) & 2) >> 1))
   {
    sf.pos=1249917;
    YH7I(Ain, Vtoken);
    sf.pos=1249918;
    r = NULL;
    rt = 1;
    goto YA9O;
   }
   sf.pos=1249919;
   YdIu(Vtoken, ((Tc*)&Yqta));
YA9O:
   if (rt) goto YLVG;
    break;
  }
 case 32:
  {
   sf.pos=1249920;
   YBch(Ain);
   sf.pos=1249921;
   VnextToken = Y_PN(Ain);
   sf.pos=1249922;
   Vstmt1 = YWYQa(VnextToken, Ain, AblockType);
   sf.pos=1249923;
   if ((YuqZ(Vstmt1) == 1))
   {
    sf.pos=1249924;
    Y1ql(YjGb(Vstmt1), 1);
    sf.pos=1249925;
    r = Vstmt1;
    rt = 1;
    goto YEIv;
   }
   sf.pos=1249926;
   YdIu(Vtoken, ((Tc*)&YqJ7));
YEIv:
   if (rt) goto YLVG;
    break;
  }
 case 53:
  {
   sf.pos=1249927;
   if (!((((AblockType) & 2) >> 1)))
   {
    rt = 2;
    goto YIgc;
   }
YIgc:
   if (rt == 2) { rt &= 1; break; }
  }
 case 38:
 case 37:
  {
   Tbb Vbt;
   sf.pos=1249928;
   Vbt = AblockType;
   sf.pos=1249929;
   Vbt = ((Vbt) & -9) | ((0) << 3);
   sf.pos=1249930;
   r = YGqS(Vtoken, Ain, Vbt);
   rt = 1;
   goto YLVG;
  }
 case 39:
  {
   sf.pos=1249931;
   YdIu(Vtoken, ((Tc*)&Ym_A));
   sf.pos=1249932;
   r = (&YIbB);
   rt = 1;
   goto YLVG;
  }
 case 36:
  {
   sf.pos=1249933;
   r = Ye9W(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 35:
  {
   sf.pos=1249934;
   r = Yawn(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 97:
 case 105:
 case 21:
 case 17:
 case 7:
 case 8:
 case 56:
 case 94:
  {
   sf.pos=1249935;
   r = YWYQa(Vtoken, Ain, AblockType);
   rt = 1;
   goto YLVG;
  }
 case 60:
  {
   sf.pos=1249936;
   r = YoGb(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 case 61:
 case 62:
  {
   sf.pos=1249937;
   YH7I(Ain, Vtoken);
   sf.pos=1249938;
   r = NULL;
   rt = 1;
   goto YLVG;
  }
 case 63:
  {
   sf.pos=1249939;
   r = YHeC(Vtoken, Ain);
   rt = 1;
   goto YLVG;
  }
 default:
  break;
YLVG:
  if (rt) goto YXux;
 }
 sf.pos=1249940;
 if ((((AblockType) & 2) >> 1))
 {
  sf.pos=1249941;
  YREn(Vtoken);
 }
 sf.pos=1249942;
 switch (Vtoken->Vtype)
 {
 case 64:
 case 67:
  {
   sf.pos=1249943;
   r = YoGb(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 65:
 case 66:
  {
   sf.pos=1249944;
   YH7I(Ain, Vtoken);
   sf.pos=1249945;
   r = NULL;
   rt = 1;
   goto YHZ3;
  }
 case 49:
  {
   sf.pos=1249946;
   r = Y34o(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 50:
 case 51:
  {
   sf.pos=1249947;
   YH7I(Ain, Vtoken);
   sf.pos=1249948;
   r = NULL;
   rt = 1;
   goto YHZ3;
  }
 case 68:
  {
   sf.pos=1249949;
   r = YOOP(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 75:
  {
   sf.pos=1249950;
   r = YgOb(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 76:
  {
   sf.pos=1249951;
   YH7I(Ain, Vtoken);
   sf.pos=1249952;
   r = NULL;
   rt = 1;
   goto YHZ3;
  }
 case 77:
  {
   sf.pos=1249953;
   r = YS8Y(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 46:
 case 47:
 case 48:
 case 52:
  {
   sf.pos=1249954;
   r = YdOB(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 69:
 case 70:
  {
   sf.pos=1249955;
   r = Yhta(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 72:
  {
   sf.pos=1249956;
   r = YlJY(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 73:
 case 74:
 case 71:
  {
   sf.pos=1249957;
   YH7I(Ain, Vtoken);
   sf.pos=1249958;
   r = NULL;
   rt = 1;
   goto YHZ3;
  }
 case 53:
  {
   sf.pos=1249959;
   r = Ywf0(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 92:
  {
   sf.pos=1249960;
   r = YG4L(Vtoken, Ain);
   rt = 1;
   goto YHZ3;
  }
 case 101:
 case 99:
  {
   sf.pos=1249961;
   YuRk(Ain);
   sf.pos=1249962;
   VnameExpr = YTKt(Ain, 1, (1 + 2));
   sf.pos=1249963;
   if ((YmTi(VnameExpr) == 16))
   {
    sf.pos=1249964;
    YdIu(Vtoken, ZcS3(((Tc*)&YABa), Vtoken->Vvalue, ((Tc*)&Yz33)));
   }
   sf.pos=1249965;
   YQuF(Ain);
   sf.pos=1249966;
   r = YQbp(Vtoken, VnameExpr);
   rt = 1;
   goto YHZ3;
  }
 default:
  {
   sf.pos=1249967;
   YdIu(Vtoken, ZcS3(((Tc*)&Y7m7), Vtoken->Vvalue, ((Tc*)&YN)));
    break;
  }
YHZ3:
  if (rt) goto YXux;
 }
 sf.pos=1249968;
 r = (&YIbB);
YXux:
 topFrame = sf.prev;
 return r;
}
YXCg *YQbp(Yev8 *Atoken, YnZD *AnameExpr) {
 Tb VisInc;
 Zsf sf;
 YXCg *r = 0;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2547500;
 VisInc = ((Atoken->Vtype == 101));
 sf.pos=2547501;
 Vstmt = YDNI(NULL);
 sf.pos=2547502;
 YMTX(Yiw6(YZqm(Vstmt, Atoken->VzuiPos), ((VisInc) ? (28) : (29))), AnameExpr);
 sf.pos=2547503;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YH3h(YnZD *AtypeExpr, Yev8 *Aid_token, Tb AcheckForInit, Tb AcheckForEol, Y7Sj *Ain) {
 Tb VhasDollar;
 Tb VhasPercent;
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vtoken = 0;
 Tc *Vname = NULL;
 Ysbp *Vpos = 0;
 Yev8 *VprevComment = 0;
 YJON *Vza = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vpeek = 0;
 Yev8 *VnextComment = 0;
 YYIi *Vdecl = 0;
 YXCg *Vstmt = 0;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1398700;
 Vtoken = Aid_token;
 VhasDollar = 0;
 VhasPercent = 0;
 sf.pos=1398701;
 if ((Vtoken->Vtype == 97))
 {
  sf.pos=1398702;
  Vtoken = Y_PN(Ain);
  sf.pos=1398703;
  VhasDollar = 1;
 }
 else {
 sf.pos=1398704;
 if ((Vtoken->Vtype == 105))
 {
  sf.pos=1398705;
  Vtoken = Y_PN(Ain);
  sf.pos=1398706;
  VhasPercent = 1;
 }
 }
 sf.pos=1398707;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=1398708;
  YH7I(Ain, Vtoken);
  sf.pos=1398709;
  if ((YmTi(AtypeExpr) == 1))
  {
   sf.pos=1398710;
   YdIu(Vtoken, ZcS(((Tc*)&Yxw0), YYim(YjUS(AtypeExpr))));
  }
  else
  {
   sf.pos=1398711;
   YdIu(Vtoken, ((Tc*)&YbEV));
  }
  sf.pos=1398712;
  r = (&YIbB);
  rt = 1;
  goto YS_o;
 }
 sf.pos=1398713;
 Vname = Vtoken->Vvalue;
 sf.pos=1398714;
 Vpos = Vtoken->VzuiPos;
 sf.pos=1398715;
 if (Y3DE->VhasComment)
 {
  sf.pos=1398716;
  VprevComment = Y3DE;
 }
 sf.pos=1398717;
 Vza = YsCX(NULL);
 sf.pos=1398718;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 7), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YF4i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YPwY)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDNe)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yr91))), Ain);
 sf.pos=1398719;
 if (AcheckForInit)
 {
  sf.pos=1398720;
  Vtoken = Y6qU(Ain);
  sf.pos=1398721;
  if ((Vtoken->Vtype == 112))
  {
   sf.pos=1398722;
   YzLT(Ain);
   sf.pos=1398723;
   Vtoken = Y_PN(Ain);
   sf.pos=1398724;
   YzLT(Ain);
   sf.pos=1398725;
   Vexpr = YUWY(Ain);
   sf.pos=1398726;
   Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YlOO))), Ain);
  }
 }
 sf.pos=1398727;
 Vpeek = YksM(Ain);
 sf.pos=1398728;
 if (((Vpeek->Vtype == 3) && Vpeek->VhasCommentFirst))
 {
  sf.pos=1398729;
  VnextComment = Vpeek;
 }
 sf.pos=1398730;
 if (AcheckForEol)
 {
  sf.pos=1398731;
  YE5j(Ain);
 }
 sf.pos=1398732;
 YmQW(AtypeExpr, Ain);
 sf.pos=1398733;
 Vdecl = YpQb(NULL);
 sf.pos=1398734;
 YrDX(Yz09(YLJs(YkDm(YvRw(Y5JX(YJ03(YpBC(Vdecl, Vname), VhasDollar), VhasPercent), Vpos)), 45), AtypeExpr), Vza);
 sf.pos=1398735;
 if ((Vexpr != NULL))
 {
  sf.pos=1398736;
  YhZx(Vdecl, Vexpr);
 }
 sf.pos=1398737;
 if ((VprevComment != NULL))
 {
  sf.pos=1398738;
  Y4e7(Vdecl, VprevComment->Vvalue);
 }
 sf.pos=1398739;
 if ((VnextComment != NULL))
 {
  sf.pos=1398740;
  Yxn8(Vdecl, 1);
  sf.pos=1398741;
  YDJy(Vdecl, VnextComment->Vvalue);
 }
 sf.pos=1398742;
 Vstmt = YDNI(NULL);
 sf.pos=1398743;
 Yh4I(Yiw6(YZqm(Vstmt, Vpos), 1), Vdecl);
 sf.pos=1398744;
 r = Vstmt;
YS_o:
 topFrame = sf.prev;
 return r;
}
void YmQW(YnZD *Aexpr, Y7Sj *Ain) {
 Zsf sf;
 Tc *Vname = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5744100;
 if ((YmTi(Aexpr) == 1))
 {
  sf.pos=5744101;
  Vname = YYim(YjUS(Aexpr));
  sf.pos=5744102;
  if ((((((((ZstringCmp(Vname, ((Tc*)&YrXn)) == 0) || (ZstringCmp(Vname, ((Tc*)&YHkL)) == 0)) || (ZstringCmp(Vname, ((Tc*)&Y7Ft)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YATt)) == 0)) || (ZstringCmp(Vname, ((Tc*)&Y1Qt)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YYgh)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YanE)) == 0)))
  {
   sf.pos=5744103;
   Y63C(Ain->VusedIdKeywords, ZstringToUpper(Vname));
  }
  else {
  sf.pos=5744104;
 if ((((ZstringCmp(Vname, ((Tc*)&Y3nJ)) == 0) || (ZstringCmp(Vname, ((Tc*)&YbJS)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YJnE)) == 0)))
  {
   sf.pos=5744105;
   Y63C(Ain->VusedIdKeywords, ((Tc*)&YVLC));
  }
  }
 }
 topFrame = sf.prev;
 return;
}
YXCg *Y4h6(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Ysbp *VmodulePos = 0;
 Yev8 *Vcomment = 0;
 Yev8 *Vtoken = 0;
 Tc *Vname = NULL;
 YJON *Vza = 0;
 Y2wP *Vmodule = 0;
 YYIi *Vdecl = 0;
 YXCg *Vstmt = 0;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9323900;
 VmodulePos = AstartToken->VzuiPos;
 sf.pos=9323901;
 if (Y3DE->VhasComment)
 {
  sf.pos=9323902;
  Vcomment = Y3DE;
 }
 sf.pos=9323903;
 YzLT(Ain);
 sf.pos=9323904;
 Vtoken = Y_PN(Ain);
 sf.pos=9323905;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=9323906;
  YdIu(Vtoken, ((Tc*)&YFVc));
 }
 sf.pos=9323907;
 Vname = Vtoken->Vvalue;
 sf.pos=9323908;
 Vza = YsCX(NULL);
 sf.pos=9323909;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 4), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yyir))), Ain);
 sf.pos=9323910;
 Vmodule = YwDD(NULL);
 sf.pos=9323911;
 YE5j(Ain);
 sf.pos=9323912;
 YDlo(Vmodule, YBd7(Ain, 2));
 sf.pos=9323913;
 Vdecl = YpQb(NULL);
 sf.pos=9323914;
 YrDX(YM5q(YLJs(YkDm(YvRw(YpBC(Vdecl, Vname), VmodulePos)), 24), Vmodule), Vza);
 sf.pos=9323915;
 if ((Vcomment != NULL))
 {
  sf.pos=9323916;
  Y4e7(Vdecl, Vcomment->Vvalue);
 }
 sf.pos=9323917;
 Vstmt = YDNI(NULL);
 sf.pos=9323918;
 Yh4I(Yiw6(YZqm(Vstmt, VmodulePos), 2), Vdecl);
 sf.pos=9323919;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YTWI(Yev8 *AclassToken, Y7Sj *Ain) {
 Tb VisInterface;
 Tb VisPiece;
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vcomment = 0;
 YftY *Vclass = 0;
 YJON *Vza = 0;
 Yev8 *Vtoken = 0;
 Tc *Vname = NULL;
 YnZD *VnameExpr = 0;
 Tc *Vtname = NULL;
 Tl *VnameList = NULL;
 Tl *VmemberStmts = NULL;
 Tl *VsharedStmts = NULL;
 YYIi *Vdecl = 0;
 YXCg *Vstmt = 0;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7044700;
 if (Y3DE->VhasComment)
 {
  sf.pos=7044701;
  Vcomment = Y3DE;
 }
 sf.pos=7044702;
 VisInterface = (AclassToken->Vtype == 33);
 sf.pos=7044703;
 VisPiece = (AclassToken->Vtype == 34);
 sf.pos=7044704;
 Vclass = YOMn(NULL);
 sf.pos=7044705;
 if (VisInterface)
 {
  sf.pos=7044706;
  YHGh(Vclass, 1);
 }
 sf.pos=7044707;
 if (VisPiece)
 {
  sf.pos=7044708;
  YFgR(Vclass, 1);
 }
 sf.pos=7044709;
 Vza = YsCX(NULL);
 sf.pos=7044710;
 if (VisInterface)
 {
  sf.pos=7044711;
  Y5IN(Vza, 1);
 }
 sf.pos=7044712;
 YzLT(Ain);
 sf.pos=7044713;
 Vtoken = Y_PN(Ain);
 sf.pos=7044714;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=7044715;
  YdIu(Vtoken, ((Tc*)&Yoc2));
 }
 sf.pos=7044716;
 Vname = Vtoken->Vvalue;
 sf.pos=7044717;
 Vtoken = Y6qU(Ain);
 sf.pos=7044718;
 if ((Vtoken->Vtype == 135))
 {
  sf.pos=7044719;
  Y5bl(Ain);
  sf.pos=7044720;
  YCdb(Vclass, Yyre(Ain));
  sf.pos=7044721;
  Vtoken = Y6qU(Ain);
 }
 sf.pos=7044722;
 if ((Vtoken->Vtype == 40))
 {
  sf.pos=7044723;
  YzLT(Ain);
  sf.pos=7044724;
  Vtoken = Y_PN(Ain);
  sf.pos=7044725;
  YzLT(Ain);
  sf.pos=7044726;
  VnameExpr = YTKt(Ain, 0, 1);
  sf.pos=7044727;
  YSMx(Vclass, VnameExpr);
  sf.pos=7044728;
  if ((YmTi(VnameExpr) == 1))
  {
   sf.pos=7044729;
   Vtname = YYim(YjUS(VnameExpr));
   sf.pos=7044730;
   if (((ZstringCmp(Vtname, ((Tc*)&YVK0)) == 0) || (ZstringCmp(Vtname, ((Tc*)&Y6Yl)) == 0)))
   {
    sf.pos=7044731;
    Y63C(Ain->VusedIdKeywords, ((Tc*)&YVLC));
   }
  }
  sf.pos=7044732;
  Vtoken = Y6qU(Ain);
 }
 sf.pos=7044733;
 if ((Vtoken->Vtype == 41))
 {
  sf.pos=7044734;
  if (VisInterface)
  {
   sf.pos=7044735;
   YdIu(Vtoken, ((Tc*)&Ywka));
  }
  sf.pos=7044736;
  YzLT(Ain);
  sf.pos=7044737;
  Vtoken = Y_PN(Ain);
  sf.pos=7044738;
  YzLT(Ain);
  sf.pos=7044739;
  VnameList = Ya1K(Ain);
  sf.pos=7044740;
  Yq9S(Vclass, VnameList);
 }
 sf.pos=7044741;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 10), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YrkU)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YtNZa)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YlOO)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YF4i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YPwY)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDNe)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yyir))), Ain);
 sf.pos=7044742;
 YE5j(Ain);
 sf.pos=7044743;
 VmemberStmts = ZnewList((Tt*)&YXCg__T, 0);
 sf.pos=7044744;
 VsharedStmts = ZnewList((Tt*)&YXCg__T, 0);
 sf.pos=7044745;
 while (1)
 {
  sf.pos=7044746;
  ZListExtend((Tl*)VmemberStmts, YBd7(Ain, ((2 + 8) + (((VisInterface) ? (16) : (0))))));
  sf.pos=7044747;
  if ((Y6qU(Ain)->Vtype != 31))
  {
   rt = 2;
   goto YW2F;
  }
  sf.pos=7044748;
  Vtoken = Y_PN(Ain);
  sf.pos=7044749;
  Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yyir))), Ain);
  sf.pos=7044750;
  YE5j(Ain);
  sf.pos=7044751;
  ZListExtend((Tl*)VsharedStmts, YBd7(Ain, 2));
YW2F:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=7044752;
 }
 sf.pos=7044753;
 Yj_H(Vclass, VmemberStmts);
 sf.pos=7044754;
 if ((ZListSize(VsharedStmts) > 0))
 {
  sf.pos=7044755;
  YRIK(YPLV(Vclass), VsharedStmts);
  sf.pos=7044756;
  YjP6(Vclass, YsCX(NULL));
 }
 sf.pos=7044757;
 Vtoken = Y_PN(Ain);
 sf.pos=7044758;
 if ((Vtoken->Vtype != 93))
 {
  sf.pos=7044759;
  YdIu(Vtoken, ((Tc*)&YbEV));
  sf.pos=7044760;
  YdIu(AclassToken, ((Tc*)&YS9i));
 }
 else
 {
  sf.pos=7044761;
  YE5j(Ain);
 }
 sf.pos=7044762;
 Vdecl = YpQb(NULL);
 sf.pos=7044763;
 YrDX(Y45H(YLJs(YkDm(YvRw(YpBC(Vdecl, Vname), AclassToken->VzuiPos)), ((VisInterface) ? (31) : (((VisPiece) ? (33) : (29))))), Vclass), Vza);
 sf.pos=7044764;
 if ((Vcomment != NULL))
 {
  sf.pos=7044765;
  Y4e7(Vdecl, Vcomment->Vvalue);
 }
 sf.pos=7044766;
 Vstmt = YDNI(NULL);
 sf.pos=7044767;
 Yh4I(Yiw6(YZqm(Vstmt, AclassToken->VzuiPos), 3), Vdecl);
 sf.pos=7044768;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YEc4(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vcomment = 0;
 YfBB *Vinclude = 0;
 Tl *VstmtList = NULL;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7323300;
 if (Y3DE->VhasComment)
 {
  sf.pos=7323301;
  Vcomment = Y3DE;
 }
 sf.pos=7323302;
 YQuF(Ain);
 sf.pos=7323303;
 Vinclude = Y48I(NULL);
 sf.pos=7323304;
 VstmtList = YBd7(Ain, 0);
 sf.pos=7323305;
 YZnt(Vinclude, VstmtList);
 sf.pos=7323306;
 Vstmt = YDNI(NULL);
 sf.pos=7323307;
 YCIA(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 32), Vinclude);
 sf.pos=7323308;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YGqS(Yev8 *AfirstToken, Y7Sj *Ain, Tbb AblockType) {
 Te Vtype;
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vcomment = 0;
 YXCg *Vstmt = 0;
 YYIi *Vdecl = 0;
 Y7Np *Vmethod = 0;
 YJON *Vza = 0;
 Tc *Vname = NULL;
 Yev8 *VnameToken = 0;
 Yev8 *Vtoken = 0;
 YhZL *Vblock = 0;
 Tl *Zf2 = NULL;
 YnZD *VretType = 0;
 Tl *VtypeList = NULL;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9073400;
 Y8UT(((((AfirstToken->Vtype == 37) || (AfirstToken->Vtype == 38)) || (AfirstToken->Vtype == 39)) || (AfirstToken->Vtype == 53)));
 sf.pos=9073401;
 if ((((AblockType) & 4) >> 2))
 {
  sf.pos=9073402;
  YREn(AfirstToken);
 }
 sf.pos=9073403;
 if (Y3DE->VhasComment)
 {
  sf.pos=9073404;
  Vcomment = Y3DE;
 }
 sf.pos=9073405;
 Vstmt = YDNI(NULL);
 sf.pos=9073406;
 Vdecl = YK2t(Vstmt);
 sf.pos=9073407;
 YvRw(Vdecl, AfirstToken->VzuiPos);
 sf.pos=9073408;
 Vmethod = YWVR(NULL);
 sf.pos=9073409;
 Vza = YsCX(NULL);
 sf.pos=9073410;
 if ((((AblockType) & 16) >> 4))
 {
  sf.pos=9073411;
  Y5IN(Vza, 1);
 }
 sf.pos=9073412;
 if ((AfirstToken->Vtype != 53))
 {
  sf.pos=9073413;
  YzLT(Ain);
 }
 sf.pos=9073414;
 Vtype = 19;
 sf.pos=9073415;
 if ((((AblockType) & 32) >> 5))
 {
  sf.pos=9073416;
  YvRw(Vdecl, AfirstToken->VzuiPos);
 }
 else
 {
  sf.pos=9073417;
  if ((AfirstToken->Vtype == 53))
  {
   sf.pos=9073418;
   VnameToken = AfirstToken;
  }
  else
  {
   sf.pos=9073419;
   VnameToken = Y_PN(Ain);
   sf.pos=9073420;
   if ((VnameToken->Vtype == 97))
   {
    sf.pos=9073421;
    YJ03(Vdecl, 1);
    sf.pos=9073422;
    VnameToken = Y_PN(Ain);
   }
   sf.pos=9073423;
   if ((VnameToken->Vtype == 53))
   {
    sf.pos=9073424;
    YdIu(VnameToken, ZcS(AfirstToken->Vvalue, ((Tc*)&Y9St)));
   }
  }
  sf.pos=9073425;
  if ((VnameToken->Vtype == 53))
  {
   sf.pos=9073426;
   Vtype = 18;
   sf.pos=9073427;
   YJ03(Vdecl, 1);
  }
  else {
  sf.pos=9073428;
 if (((VnameToken->Vtype == 21) && (ZstringCmp(VnameToken->Vvalue, ((Tc*)&Ykmq)) == 0)))
  {
   sf.pos=9073429;
   if (!((((AblockType) & 1))))
   {
    sf.pos=9073430;
    YdIu(VnameToken, ((Tc*)&YgzP));
   }
   else {
   sf.pos=9073431;
 if (Yb8a)
   {
    sf.pos=9073432;
    YdIu(VnameToken, ((Tc*)&YIcs));
   }
   }
   sf.pos=9073433;
   Yb8a = 1;
  }
  else {
  sf.pos=9073434;
 if ((VnameToken->Vtype != 21))
  {
   sf.pos=9073435;
   YdIu(VnameToken, ((Tc*)&YIYT));
  }
  }}
  sf.pos=9073436;
  Vname = VnameToken->Vvalue;
  sf.pos=9073437;
  YvRw(Vdecl, VnameToken->VzuiPos);
  sf.pos=9073438;
  if ((YksM(Ain)->Vtype == 135))
  {
   sf.pos=9073439;
   YxF_(Vmethod, Yyre(Ain));
  }
 }
 sf.pos=9073440;
 YpBC(Vdecl, Vname);
 sf.pos=9073441;
 Vtoken = Y_PN(Ain);
 sf.pos=9073442;
 if ((Vtoken->Vtype != 90))
 {
  sf.pos=9073443;
  YdIu(Vtoken, ((Tc*)&Y1Kg));
 }
 else
 {
  sf.pos=9073444;
  YQ6k(Vmethod, Ain, (AfirstToken->Vtype == 39), 91);
 }
 sf.pos=9073445;
 if ((AfirstToken->Vtype == 37))
 {
  sf.pos=9073446;
  Vtype = 20;
  sf.pos=9073447;
  YzLT(Ain);
  sf.pos=9073448;
  VtypeList = Ya1K(Ain);
  sf.pos=9073449;
  {
   Tfl Zf2i;
   Zf2 = VtypeList;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&VretType;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=9073450;
   Yz09(YLJs(YQsX(Vmethod), 45), VretType);
   sf.pos=9073451;
   }
  }
 }
 else {
 sf.pos=9073452;
 if ((AfirstToken->Vtype == 39))
 {
  sf.pos=9073453;
  Vtype = 21;
 }
 }
 sf.pos=9073454;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 13), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YODD)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YrkU)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YpLJ)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ybyf)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Yl3I)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YF4i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YPwY)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDNe)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDqN)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIK3))), Ain);
 sf.pos=9073455;
 YQuFa(Ain, (((AblockType) & 32) >> 5));
 sf.pos=9073456;
 Vblock = YaF_(AfirstToken, Ain, (((((AblockType) & 8) >> 3)) ? (8) : (0)));
 sf.pos=9073457;
 if (YJD1(Vblock))
 {
  sf.pos=9073458;
  Y4cF(Vmethod, Vblock);
 }
 sf.pos=9073459;
 Yiw6(YZqm(Vstmt, AfirstToken->VzuiPos), 6);
 sf.pos=9073460;
 YrDX(YHPQ(YLJs(YkDm(Vdecl), Vtype), Vmethod), Vza);
 sf.pos=9073461;
 if ((Vcomment != NULL))
 {
  sf.pos=9073462;
  Y4e7(Vdecl, Vcomment->Vvalue);
 }
 sf.pos=9073463;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *Ye9W(Yev8 *AbitsToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YfQg *Vbits = 0;
 YXCg *Vstmt = 0;
 Yev8 *Vcomment = 0;
 Yev8 *Vtoken = 0;
 Tl *Vstmts = NULL;
 YYIi *Vdecl = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2706300;
 Vbits = Y8xU(NULL);
 sf.pos=2706301;
 Vstmt = YDNI(NULL);
 sf.pos=2706302;
 YZqm(Vstmt, AbitsToken->VzuiPos);
 sf.pos=2706303;
 if (Y3DE->VhasComment)
 {
  sf.pos=2706304;
  Vcomment = Y3DE;
 }
 sf.pos=2706305;
 YzLT(Ain);
 sf.pos=2706306;
 Vtoken = Y_PN(Ain);
 sf.pos=2706307;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=2706308;
  YdIu(Vtoken, ((Tc*)&Y06E));
 }
 sf.pos=2706309;
 YE5j(Ain);
 sf.pos=2706310;
 Vstmts = YBd7(Ain, 2);
 sf.pos=2706311;
 if ((ZListSize(Vstmts) > 0))
 {
  sf.pos=2706312;
  YT9u(Vbits, Vstmts);
 }
 sf.pos=2706313;
 Yiw6(Vstmt, 4);
 sf.pos=2706314;
 Vdecl = YK2t(Vstmt);
 sf.pos=2706315;
 YewF(YLJs(YkDm(YvRw(Vdecl, YWlm(Vstmt))), 27), Vbits);
 sf.pos=2706316;
 YpBC(Vdecl, Vtoken->Vvalue);
 sf.pos=2706317;
 if ((Vcomment != NULL))
 {
  sf.pos=2706318;
  Y4e7(Vdecl, Vcomment->Vvalue);
 }
 sf.pos=2706319;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *Yawn(Yev8 *AenumToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vcomment = 0;
 Yev8 *Vtoken = 0;
 Tc *VenumName = NULL;
 YJON *Vza = 0;
 YFN2 *Venum = 0;
 Yev8 *VsaveLastSep = 0;
 Yev8 *Vpeek = 0;
 Yev8 *Vnext = 0;
 Yev8 *VnextComment = 0;
 Yev8 *VprevComment = 0;
 YYIi *Vdecl = 0;
 YXCg *Vstmt = 0;
 YYIi *Vdecl1 = 0;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9966600;
 if (Y3DE->VhasComment)
 {
  sf.pos=9966601;
  Vcomment = Y3DE;
 }
 sf.pos=9966602;
 YzLT(Ain);
 sf.pos=9966603;
 Vtoken = Y_PN(Ain);
 sf.pos=9966604;
 if ((Vtoken->Vtype != 21))
 {
  sf.pos=9966605;
  YdIu(Vtoken, ((Tc*)&Ybaw));
 }
 sf.pos=9966606;
 VenumName = Vtoken->Vvalue;
 sf.pos=9966607;
 Vza = YsCX(NULL);
 sf.pos=9966608;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 5), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YF4i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YDNe)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ))), Ain);
 sf.pos=9966609;
 Venum = Y5iq(NULL);
 sf.pos=9966610;
 YE5j(Ain);
 sf.pos=9966611;
 while (1)
 {
  sf.pos=9966612;
  Vtoken = Y_PN(Ain);
  sf.pos=9966613;
  VsaveLastSep = Y3DE;
  sf.pos=9966614;
  if ((Vtoken->Vtype == 93))
  {
   sf.pos=9966615;
   YE5j(Ain);
   rt = 2;
   goto YnEh;
  }
  sf.pos=9966616;
  if ((Vtoken->Vtype != 21))
  {
   sf.pos=9966617;
   if ((Vtoken->Vtype == 1))
   {
    sf.pos=9966618;
    YdIu(Vtoken, ((Tc*)&Y_ih));
   }
   else
   {
    sf.pos=9966619;
    YdIu(Vtoken, ((Tc*)&YMKA));
   }
   rt = 2;
   goto YnEh;
  }
  sf.pos=9966620;
  Vpeek = YksM(Ain);
  sf.pos=9966621;
  Vnext = Y6qU(Ain);
  sf.pos=9966622;
  if ((Vnext->Vtype == 93))
  {
   sf.pos=9966623;
   YE5j(Ain);
  }
  else
  {
   sf.pos=9966624;
   YzLT(Ain);
  }
  VnextComment = 0;
  sf.pos=9966625;
  if (((Vpeek->Vtype == 3) && Vpeek->VhasCommentFirst))
  {
   sf.pos=9966626;
   VnextComment = Vpeek;
  }
  VprevComment = 0;
  sf.pos=9966627;
  if (VsaveLastSep->VhasComment)
  {
   sf.pos=9966628;
   VprevComment = Y3DE;
  }
  sf.pos=9966629;
  Vdecl = YbCT(Venum);
  sf.pos=9966630;
  YLJs(YkDm(YpBC(YvRw(Vdecl, Vtoken->VzuiPos), Vtoken->Vvalue)), 26);
  sf.pos=9966631;
  if ((VprevComment != NULL))
  {
   sf.pos=9966632;
   Y4e7(Vdecl, VprevComment->Vvalue);
  }
  sf.pos=9966633;
  if ((VnextComment != NULL))
  {
   sf.pos=9966634;
   YDJy(Vdecl, VnextComment->Vvalue);
  }
YnEh:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9966635;
 }
 sf.pos=9966636;
 Vstmt = YDNI(NULL);
 sf.pos=9966637;
 Yiw6(YZqm(Vstmt, AenumToken->VzuiPos), 5);
 sf.pos=9966638;
 Vdecl1 = YK2t(Vstmt);
 sf.pos=9966639;
 YrDX(YEtr(YLJs(YkDm(YpBC(YvRw(Vdecl1, AenumToken->VzuiPos), VenumName)), 25), Venum), Vza);
 sf.pos=9966640;
 if ((Vcomment != NULL))
 {
  sf.pos=9966641;
  Y4e7(Vdecl1, Vcomment->Vvalue);
 }
 sf.pos=9966642;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YWYQa(Yev8 *AstartToken, Y7Sj *Ain, Tbb AblockType) {
 Zsf sf;
 YXCg *r = 0;
 YnZD *VleadExpr = 0;
 YXCg *VsplitStmt = 0;
 Tl *VitemList = NULL;
 Tl *Vitems = NULL;
 YXCg *VdeclStmt = 0;
 YXCg *Vstmt = 0;
 Y_1n *Vcall = 0;
 Yev8 *VafterSep = 0;
 Yev8 *Vtoken = 0;
 Tl *Vitems1 = NULL;
 Yev8 *VnextToken = 0;
 Tl *VitemList1 = NULL;
 YXCg *VdeclStmt1 = 0;
 Tl *Zf5 = NULL;
 YnZD *Vvar = 0;
 YYIi *Vdecl = 0;
 YXCg *VdeclStmt2 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5351000;
 if ((((AblockType) & 4) >> 2))
 {
  sf.pos=5351001;
  YREn(AstartToken);
 }
 sf.pos=5351002;
 if (((((((AstartToken->Vtype == 21) || (AstartToken->Vtype == 97)) || (AstartToken->Vtype == 105)) || (AstartToken->Vtype == 7)) || (AstartToken->Vtype == 8)) || (AstartToken->Vtype == 56)))
 {
  sf.pos=5351003;
  if (((((AblockType) & 2) >> 1) && (((AstartToken->Vtype == 7) || (AstartToken->Vtype == 8)))))
  {
   sf.pos=5351004;
   YdIu(AstartToken, ZcS3(((Tc*)&YPq4), AstartToken->Vvalue, ((Tc*)&YzTy)));
  }
  sf.pos=5351005;
  YH7I(Ain, AstartToken);
  sf.pos=5351006;
  VleadExpr = YTKt(Ain, 1, (1 + 2));
 }
 else {
 sf.pos=5351007;
 if (((AstartToken->Vtype == 94) || (AstartToken->Vtype == 95)))
 {
  sf.pos=5351008;
  VleadExpr = YZiK(AstartToken, Ain);
 }
 else
 {
  sf.pos=5351009;
  VleadExpr = YxDV(1, AstartToken->VzuiPos);
  sf.pos=5351010;
  YMou(YRE8(VleadExpr), AstartToken->Vvalue);
 }
 }
 sf.pos=5351011;
 if ((Y6qU(Ain)->Vtype == 82))
 {
  sf.pos=5351012;
  VitemList = ZnewList((Tt*)&YnZD__T, 0);
  sf.pos=5351013;
  while (1)
  {
   sf.pos=5351014;
   Vitems = YZnz(Ain, VleadExpr, 0);
   sf.pos=5351015;
   if (YAdu(Y6qU(Ain)->Vtype))
   {
    sf.pos=5351016;
    ZListExtend((Tl*)VitemList, Vitems);
    rt = 2;
    goto YrPC;
   }
   sf.pos=5351017;
   VleadExpr = ZListRemovePtrItem((Tl*)Vitems, -1);
   sf.pos=5351018;
   ZListExtend((Tl*)VitemList, Vitems);
   sf.pos=5351019;
   YzLT(Ain);
   sf.pos=5351020;
   VdeclStmt = YH3h(VleadExpr, Y_PN(Ain), 0, 0, Ain);
   sf.pos=5351021;
   if ((VsplitStmt == NULL))
   {
    sf.pos=5351022;
    VsplitStmt = YDNI(NULL);
    sf.pos=5351023;
    Yiw6(VsplitStmt, 36);
   }
   sf.pos=5351024;
   YGDU(VsplitStmt, VdeclStmt);
   sf.pos=5351025;
   VleadExpr = Yi5r(VdeclStmt);
   sf.pos=5351026;
   if ((Y6qU(Ain)->Vtype != 82))
   {
    sf.pos=5351027;
    ZLap((Tl*)VitemList, (Tz)(void*)VleadExpr);
    rt = 2;
    goto YrPC;
   }
YrPC:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=5351028;
  }
  sf.pos=5351029;
  VleadExpr = YxDV(13, AstartToken->VzuiPos);
  sf.pos=5351030;
  YKTm(VleadExpr, VitemList);
 }
 sf.pos=5351031;
 if ((YmTi(VleadExpr) == 16))
 {
  sf.pos=5351032;
  if ((((AblockType) & 2) >> 1))
  {
   sf.pos=5351033;
   YdIu(AstartToken, ((Tc*)&Ynnk));
  }
  sf.pos=5351034;
  YQuF(Ain);
  sf.pos=5351035;
  Vcall = YztZ(VleadExpr);
  sf.pos=5351036;
  Vstmt = YDNI(NULL);
  sf.pos=5351037;
  YM__(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 10), Vcall);
 }
 else
 {
  sf.pos=5351038;
  VafterSep = Y6qU(Ain);
  sf.pos=5351039;
  if (((VafterSep->Vtype != 101) && (VafterSep->Vtype != 99)))
  {
   sf.pos=5351040;
   YzLT(Ain);
  }
  sf.pos=5351041;
  Vtoken = Y_PN(Ain);
  sf.pos=5351042;
  if (YAdu(Vtoken->Vtype))
  {
   sf.pos=5351043;
   if ((((AblockType) & 2) >> 1))
   {
    sf.pos=5351044;
    YdIu(Vtoken, ((Tc*)&YobZ));
   }
   sf.pos=5351045;
   Vstmt = Yyn4(VleadExpr, Vtoken, Ain);
   sf.pos=5351046;
   YQuF(Ain);
  }
  else {
  sf.pos=5351047;
 if (((VafterSep->Vtype == 101) || (VafterSep->Vtype == 99)))
  {
   sf.pos=5351048;
   YH7I(Ain, Vtoken);
   sf.pos=5351049;
   YuRk(Ain);
   sf.pos=5351050;
   Vtoken = Y_PN(Ain);
   sf.pos=5351051;
   if ((((AblockType) & 2) >> 1))
   {
    sf.pos=5351052;
    YdIu(Vtoken, ((Tc*)&YPRH));
   }
   else {
   sf.pos=5351053;
 if (((YmTi(VleadExpr) == 1) && (((ZstringCmp(YYim(YjUS(VleadExpr)), ((Tc*)&YYgh)) == 0) || (ZstringCmp(YYim(YjUS(VleadExpr)), ((Tc*)&YRRGa)) == 0)))))
   {
    sf.pos=5351054;
    YdIu(Vtoken, ((Tc*)&YpoI));
   }
   }
   sf.pos=5351055;
   YQuF(Ain);
   sf.pos=5351056;
   Vstmt = YQbp(Vtoken, VleadExpr);
  }
  else
  {
   sf.pos=5351057;
   if ((AstartToken->Vtype == 97))
   {
    sf.pos=5351058;
    YdIu(AstartToken, ((Tc*)&YVlJ));
   }
   sf.pos=5351059;
   Vstmt = YH3h(VleadExpr, Vtoken, 1, 0, Ain);
   sf.pos=5351060;
   if ((((Vstmt != (&YIbB)) && !(YoD_(YjGb(Vstmt)))) && (Y6qU(Ain)->Vtype == 82)))
   {
    sf.pos=5351061;
    VleadExpr = Yi5r(Vstmt);
    sf.pos=5351062;
    Vitems1 = YZnz(Ain, VleadExpr, 0);
    sf.pos=5351063;
    VsplitStmt = YDNI(NULL);
    sf.pos=5351064;
    Yiw6(VsplitStmt, 36);
    sf.pos=5351065;
    VnextToken = Y6qU(Ain);
    sf.pos=5351066;
    if ((YAdu(VnextToken->Vtype) || (((VnextToken->Vtype == 21) && (YksM(Ain)->Vtype != 3)))))
    {
     sf.pos=5351067;
     YGDU(VsplitStmt, Vstmt);
     sf.pos=5351068;
     VitemList1 = ZnewList((Tt*)&YnZD__T, 0);
     sf.pos=5351069;
     while (1)
     {
      sf.pos=5351070;
      if (YAdu(Y6qU(Ain)->Vtype))
      {
       sf.pos=5351071;
       ZListExtend((Tl*)VitemList1, Vitems1);
       sf.pos=5351072;
       VleadExpr = YxDV(13, AstartToken->VzuiPos);
       sf.pos=5351073;
       YKTm(VleadExpr, VitemList1);
       sf.pos=5351074;
       YzLT(Ain);
       sf.pos=5351075;
       Vtoken = Y_PN(Ain);
       sf.pos=5351076;
       Vstmt = Yyn4(VleadExpr, Vtoken, Ain);
       rt = 2;
       goto Y10e;
      }
      sf.pos=5351077;
      if ((YksM(Ain)->Vtype == 3))
      {
       sf.pos=5351078;
       YdIu(Vtoken, ((Tc*)&YbEV));
       rt = 2;
       goto Y10e;
      }
      sf.pos=5351079;
      YzLT(Ain);
      sf.pos=5351080;
      VleadExpr = ZListRemovePtrItem((Tl*)Vitems1, -1);
      sf.pos=5351081;
      ZListExtend((Tl*)VitemList1, Vitems1);
      sf.pos=5351082;
      VdeclStmt1 = YH3h(VleadExpr, Y_PN(Ain), 0, 0, Ain);
      sf.pos=5351083;
      if ((VdeclStmt1 == (&YIbB)))
      {
       rt = 2;
       goto Y10e;
      }
      sf.pos=5351084;
      YGDU(VsplitStmt, VdeclStmt1);
      sf.pos=5351085;
      VleadExpr = Yi5r(VdeclStmt1);
      sf.pos=5351086;
      if ((Y6qU(Ain)->Vtype != 82))
      {
       sf.pos=5351087;
       Vitems1 = ZnewList((Tt*)&YnZD__T, 1); ZLap((Tl*)Vitems1, (Tz)(void*)VleadExpr);
      }
      else
      {
       sf.pos=5351088;
       Vitems1 = YZnz(Ain, VleadExpr, 0);
      }
Y10e:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=5351089;
     }
    }
    else
    {
     sf.pos=5351090;
     VdeclStmt2 = Vstmt;
     sf.pos=5351091;
     {
      Tfl Zf5i;
      Zf5 = ZListSlice((Tl*)Vitems1, 1, -1);
      Zf5i.l = Zf5;
      Zf5i.valp = (void*)&Vvar;
      Zf5i.i = 0;
      for (; ZforListPtrCont(&Zf5i); ) {
      sf.pos=5351092;
      YGDU(VsplitStmt, Vstmt);
      sf.pos=5351093;
      Vstmt = Y9N8(VdeclStmt2, 1);
      sf.pos=5351094;
      Vdecl = YjGb(Vstmt);
      sf.pos=5351095;
      YvRw(Y5JX(YJ03(YpBC(Vdecl, YYim(YjUS(Vvar))), YI8b(YjUS(Vvar))), YFAa(YjUS(Vvar))), Y74i(Vvar));
      sf.pos=5351096;
      }
     }
    }
   }
   sf.pos=5351097;
   YE5j(Ain);
  }
  }
 }
 sf.pos=5351098;
 if ((VsplitStmt != NULL))
 {
  sf.pos=5351099;
  YGDU(VsplitStmt, Vstmt);
  sf.pos=5351100;
  r = VsplitStmt;
  rt = 1;
  goto Yjs5;
 }
 sf.pos=5351101;
 r = Vstmt;
Yjs5:
 topFrame = sf.prev;
 return r;
}
Tb YAdu(Te Atype) {
 Zsf sf;
 Tb r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3343900;
 r = ((((((Atype == 112) || (Atype == 113)) || (Atype == 114)) || (Atype == 115)) || (Atype == 116)) || (Atype == 122));
 topFrame = sf.prev;
 return r;
}
YXCg *Yyn4(YnZD *Aexpr, Yev8 *Atoken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yq22 *Vass = 0;
 YnZD *Vrhs = 0;
 Tl *VrhsList = NULL;
 Yev8 *VcommaToken = 0;
 YXCg *Vstmt = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9023800;
 Vass = YZ8B(NULL);
 sf.pos=9023801;
 switch (Atoken->Vtype)
 {
 case 113:
  {
   sf.pos=9023802;
   YhEN(Vass, 37);
    break;
  }
 case 114:
  {
   sf.pos=9023803;
   YhEN(Vass, 36);
    break;
  }
 case 115:
  {
   sf.pos=9023804;
   YhEN(Vass, 38);
    break;
  }
 case 116:
  {
   sf.pos=9023805;
   YhEN(Vass, 39);
    break;
  }
 case 122:
  {
   sf.pos=9023806;
   YhEN(Vass, 41);
    break;
  }
 }
 sf.pos=9023807;
 YzLT(Ain);
 sf.pos=9023808;
 Vrhs = YUWY(Ain);
 sf.pos=9023809;
 if ((Y6qU(Ain)->Vtype == 82))
 {
  sf.pos=9023810;
  VrhsList = ZnewList((Tt*)&YnZD__T, 1); ZLap((Tl*)VrhsList, (Tz)(void*)Vrhs);
  sf.pos=9023811;
  while ((Y6qU(Ain)->Vtype == 82))
  {
   sf.pos=9023812;
   YuRk(Ain);
   sf.pos=9023813;
   VcommaToken = Y_PN(Ain);
   sf.pos=9023814;
   if ((YmTi(Aexpr) != 13))
   {
    sf.pos=9023815;
    YdIu(VcommaToken, ((Tc*)&YjOD));
    rt = 2;
    goto YqXU;
   }
   sf.pos=9023816;
   YzLT(Ain);
   sf.pos=9023817;
   ZLap((Tl*)VrhsList, (Tz)(void*)YUWY(Ain));
YqXU:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=9023818;
  }
  sf.pos=9023819;
  Vrhs = YxDV(13, Atoken->VzuiPos);
  sf.pos=9023820;
  YKTm(Vrhs, VrhsList);
  sf.pos=9023821;
  if (((YmTi(Aexpr) == 13) && (YMHY(Aexpr) != ZListSize(VrhsList))))
  {
   sf.pos=9023822;
   YdIu(Atoken, ZcS5(((Tc*)&Y71i), Zint2string(YMHY(Aexpr)), ((Tc*)&Yppy), (t0 = Zint2string(ZListSize(VrhsList))), (Tc*)1));
  }
 }
 sf.pos=9023823;
 Y2Ep(Vass, Aexpr);
 sf.pos=9023824;
 Yz4E(Vass, Vrhs);
 sf.pos=9023825;
 Vstmt = YDNI(NULL);
 sf.pos=9023826;
 Yw4A(Yiw6(YZqm(Vstmt, Atoken->VzuiPos), 9), Vass);
 sf.pos=9023827;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YnZD *Yi5r(YXCg *Astmt) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Y1p4 *Vid = 0;
 YYIi *Vdecl = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2815800;
 Vexpr = YxDV(1, YWlm(Astmt));
 sf.pos=2815801;
 Vid = YRE8(Vexpr);
 sf.pos=2815802;
 Vdecl = YjGb(Astmt);
 sf.pos=2815803;
 YMou(Vid, YdHK(Vdecl));
 sf.pos=2815804;
 YLsU(Vid, YGHm(Vdecl));
 sf.pos=2815805;
 YuRa(Vid, YEkx(Vdecl));
 sf.pos=2815806;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YXCg *YoGb(Yev8 *AstartToken, Y7Sj *Ain) {
 Tb Vgenerate;
 Tb Vifnil;
 Zsf sf;
 YXCg *r = 0;
 Y5eh *Vcond = 0;
 YnZD *VcondExpr = 0;
 YXCg *Vstmt = 0;
 Yev8 *Vtoken = 0;
 YnZD *VelseifExpr = 0;
 Y5eh *VelseifCond = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9512000;
 Vgenerate = ((AstartToken->Vtype == 60));
 sf.pos=9512001;
 Vifnil = ((AstartToken->Vtype == 67));
 sf.pos=9512002;
 Vcond = Y4Kn(NULL);
 sf.pos=9512003;
 if (!(Vifnil))
 {
  sf.pos=9512004;
  YE6J(Ain);
  sf.pos=9512005;
  YzLT(Ain);
  sf.pos=9512006;
  VcondExpr = YUWY(Ain);
  sf.pos=9512007;
  YpGq(Vcond, VcondExpr);
 }
 sf.pos=9512008;
 YQuF(Ain);
 sf.pos=9512009;
 YNhk(Vcond, YaF_(AstartToken, Ain, 8));
 sf.pos=9512010;
 Vstmt = YDNI(NULL);
 sf.pos=9512011;
 YYdx(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), ((Vgenerate) ? (13) : (((Vifnil) ? (34) : (12))))), Vcond);
 sf.pos=9512012;
 while (1)
 {
  sf.pos=9512013;
  Vtoken = Y_PN(Ain);
  sf.pos=9512014;
  if ((Vtoken->Vtype != (((Vgenerate) ? (61) : (65)))))
  {
   rt = 2;
   goto Yt3e;
  }
  sf.pos=9512015;
  YE6J(Ain);
  sf.pos=9512016;
  YzLT(Ain);
  sf.pos=9512017;
  VelseifExpr = YUWY(Ain);
  sf.pos=9512018;
  YQuF(Ain);
  sf.pos=9512019;
  VelseifCond = YbNt(Vcond);
  sf.pos=9512020;
  YpGq(VelseifCond, VelseifExpr);
  sf.pos=9512021;
  YNhk(VelseifCond, YaF_(Vtoken, Ain, 8));
Yt3e:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9512022;
 }
 sf.pos=9512023;
 if ((Vtoken->Vtype == (((Vgenerate) ? (62) : (66)))))
 {
  sf.pos=9512024;
  YQuF(Ain);
  sf.pos=9512025;
  Ya5i(Vcond, YaF_(Vtoken, Ain, 8));
  sf.pos=9512026;
  Vtoken = Y_PN(Ain);
 }
 sf.pos=9512027;
 if ((Vtoken->Vtype == 93))
 {
  sf.pos=9512028;
  YE5j(Ain);
 }
 else
 {
  sf.pos=9512029;
  YdIu(Vtoken, ((Tc*)&YbEV));
 }
 sf.pos=9512030;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YHeC(Yev8 *Atoken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YXCg *Vstmt = 0;
 YnZD *Vexpr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2991000;
 Vstmt = YDNI(NULL);
 sf.pos=2991001;
 Yiw6(Vstmt, 33);
 sf.pos=2991002;
 YZqm(Vstmt, Atoken->VzuiPos);
 sf.pos=2991003;
 YE6J(Ain);
 sf.pos=2991004;
 YzLT(Ain);
 sf.pos=2991005;
 Vexpr = YUWY(Ain);
 sf.pos=2991006;
 YMTX(Vstmt, Vexpr);
 sf.pos=2991007;
 YQuF(Ain);
 sf.pos=2991008;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *Y34o(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vtoken = 0;
 Yy74 *Vtry = 0;
 YXCg *Vstmt = 0;
 Ya9G *Vcatch = 0;
 Tl *Vtypes = NULL;
 YYIi *Vdecl = 0;
 YhZL *VtryElse = 0;
 YXCg *VelseStmt = 0;
 YhZL *VtryFinally = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9976400;
 Vtoken = AstartToken;
 sf.pos=9976401;
 Vtry = YNpV(NULL);
 sf.pos=9976402;
 Vstmt = YDNI(NULL);
 sf.pos=9976403;
 Yo4b(Yiw6(YZqm(Vstmt, Vtoken->VzuiPos), 18), Vtry);
 sf.pos=9976404;
 YQuF(Ain);
 sf.pos=9976405;
 YM0M(Vtry, YaF_(AstartToken, Ain, 8));
 sf.pos=9976406;
 while (1)
 {
  sf.pos=9976407;
  Vtoken = Y_PN(Ain);
  sf.pos=9976408;
  if ((Vtoken->Vtype != 50))
  {
   rt = 2;
   goto YfJL;
  }
  sf.pos=9976409;
  Vcatch = YNyp(Vtry);
  sf.pos=9976410;
  YvJl(Vcatch, Vtoken->VzuiPos);
  sf.pos=9976411;
  YE6J(Ain);
  sf.pos=9976412;
  YzLT(Ain);
  sf.pos=9976413;
  Vtypes = ZnewList((Tt*)&YRBza__T, 0);
  sf.pos=9976414;
  YyoS(Ain, Vtypes, 0);
  sf.pos=9976415;
  YpMg(Vcatch, Vtypes);
  sf.pos=9976416;
  YzLT(Ain);
  sf.pos=9976417;
  Vtoken = Y_PN(Ain);
  sf.pos=9976418;
  if ((Vtoken->Vtype != 21))
  {
   sf.pos=9976419;
   YdIu(Vtoken, ((Tc*)&YW6h));
  }
  sf.pos=9976420;
  Vdecl = YpQb(NULL);
  sf.pos=9976421;
  YpBC(Vdecl, Vtoken->Vvalue);
  sf.pos=9976422;
  YvRw(Vdecl, Vtoken->VzuiPos);
  sf.pos=9976423;
  Yu95(Vcatch, Vdecl);
  sf.pos=9976424;
  YQuF(Ain);
  sf.pos=9976425;
  YxIg(Vcatch, YaF_(Vtoken, Ain, 8));
YfJL:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9976426;
 }
 sf.pos=9976427;
 if ((Vtoken->Vtype == 66))
 {
  sf.pos=9976428;
  YQuF(Ain);
  sf.pos=9976429;
  VtryElse = YaF_(Vtoken, Ain, 8);
  sf.pos=9976430;
  VelseStmt = YDNI(NULL);
  sf.pos=9976431;
  Yo4b(Yq9q(Yiw6(YZqm(VelseStmt, Vtoken->VzuiPos), 19), VtryElse), Vtry);
  sf.pos=9976432;
  Y0lJ(YA6U(Vtry), VelseStmt);
  sf.pos=9976433;
  YHr1a(Vtry, VtryElse);
  sf.pos=9976434;
  Vtoken = Y_PN(Ain);
 }
 sf.pos=9976435;
 if ((Vtoken->Vtype == 51))
 {
  sf.pos=9976436;
  YQuF(Ain);
  sf.pos=9976437;
  VtryFinally = YaF_(Vtoken, Ain, 8);
  sf.pos=9976438;
  if (YJD1(VtryFinally))
  {
   sf.pos=9976439;
   YFQt(Vtry, VtryFinally);
  }
  sf.pos=9976440;
  Vtoken = Y_PN(Ain);
 }
 sf.pos=9976441;
 if ((Vtoken->Vtype == 93))
 {
  sf.pos=9976442;
  YE5j(Ain);
 }
 else
 {
  sf.pos=9976443;
  YdIu(Vtoken, ((Tc*)&YbEV));
  sf.pos=9976444;
  YH7I(Ain, Vtoken);
 }
 sf.pos=9976445;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YhZL *YaF_(Yev8 *Atoken, Y7Sj *Ain, Tbb AblockType) {
 Zsf sf;
 YhZL *r = 0;
 YhZL *Vblock = 0;
 Tl *Vstmts = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8195600;
 Vblock = YBTx(NULL);
 sf.pos=8195601;
 Vstmts = YBd7(Ain, AblockType);
 sf.pos=8195602;
 if ((ZListSize(Vstmts) > 0))
 {
  sf.pos=8195603;
  YRIK(Vblock, Vstmts);
  sf.pos=8195604;
  YtnA(Vblock, YWlm(((YXCg *)ZListGetPtr(Vstmts, 0))));
 }
 else
 {
  sf.pos=8195605;
  YtnA(Vblock, Atoken->VzuiPos);
 }
 sf.pos=8195606;
 YFf4(Vblock, YksM(Ain)->VzuiPos);
 sf.pos=8195607;
 r = Vblock;
 topFrame = sf.prev;
 return r;
}
YXCg *YOOP(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YnZD *VcondExpr = 0;
 Y5eh *Vcond = 0;
 YhZL *Vblock = 0;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=875000;
 YzLT(Ain);
 sf.pos=875001;
 VcondExpr = YUWY(Ain);
 sf.pos=875002;
 Vcond = Y4Kn(NULL);
 sf.pos=875003;
 YpGq(Vcond, VcondExpr);
 sf.pos=875004;
 YQuF(Ain);
 sf.pos=875005;
 Vblock = YaF_(AstartToken, Ain, 0);
 sf.pos=875006;
 if (YJD1(Vblock))
 {
  sf.pos=875007;
  YNhk(Vcond, Vblock);
 }
 sf.pos=875008;
 Vstmt = YDNI(NULL);
 sf.pos=875009;
 YYdx(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 15), Vcond);
 sf.pos=875010;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YgOb(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Tl *Vstmts = NULL;
 Yev8 *Vtoken = 0;
 YnZD *VcondExpr = 0;
 Y5eh *Vcond = 0;
 YXCg *Vstmt = 0;
 YXCg *Vstmt1 = 0;
 Y5eh *Vcond1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3542400;
 YQuF(Ain);
 sf.pos=3542401;
 Vstmts = YBd7(Ain, 8);
 sf.pos=3542402;
 Vtoken = Y_PN(Ain);
 sf.pos=3542403;
 if ((Vtoken->Vtype != 76))
 {
  sf.pos=3542404;
  YdIu(Vtoken, ((Tc*)&YwIv));
 }
 else
 {
  sf.pos=3542405;
  YzLT(Ain);
  sf.pos=3542406;
  VcondExpr = YUWY(Ain);
  sf.pos=3542407;
  YE5j(Ain);
  sf.pos=3542408;
  Vcond = Y4Kn(NULL);
  sf.pos=3542409;
  YpGq(Vcond, VcondExpr);
  sf.pos=3542410;
  Vstmt = YDNI(NULL);
  sf.pos=3542411;
  YYdx(Yiw6(YZqm(Vstmt, Vtoken->VzuiPos), 17), Vcond);
  sf.pos=3542412;
  ZLap((Tl*)Vstmts, (Tz)(void*)Vstmt);
 }
 sf.pos=3542413;
 Vstmt1 = YDNI(NULL);
 sf.pos=3542414;
 Yiw6(YZqm(Vstmt1, AstartToken->VzuiPos), 16);
 sf.pos=3542415;
 Vcond1 = YpRA(Vstmt1);
 sf.pos=3542416;
 YtnA(YzLV(Vcond1), YWlm(Vstmt1));
 sf.pos=3542417;
 if ((ZListSize(Vstmts) > 0))
 {
  sf.pos=3542418;
  YRIK(YtnA(Y1Yl(Vcond1), YWlm(((YXCg *)ZListGetPtr(Vstmts, 0)))), Vstmts);
 }
 sf.pos=3542419;
 YFf4(Y1Yl(Vcond1), Vtoken->VzuiPos);
 sf.pos=3542420;
 r = Vstmt1;
 topFrame = sf.prev;
 return r;
}
YXCg *YS8Y(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yxh9 *Vfor = 0;
 YYIi *VloopVar = 0;
 Yev8 *Vtoken = 0;
 YnZD *VleftExpr = 0;
 Tc *Vname = NULL;
 Yev8 *Vtoken1 = 0;
 YnZD *Vexpr = 0;
 YnZD *VtoExpr = 0;
 YnZD *VstepExpr = 0;
 Tl *Vstmts = NULL;
 YXCg *Vstmt = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9184000;
 Vfor = Yx2D(NULL);
 sf.pos=9184001;
 while (1)
 {
  sf.pos=9184002;
  VloopVar = YpQb(NULL);
  sf.pos=9184003;
  YzLT(Ain);
  sf.pos=9184004;
  Vtoken = YksM(Ain);
  sf.pos=9184005;
  if ((Vtoken->Vtype == 18))
  {
   sf.pos=9184006;
   Y747(VloopVar, 1);
   sf.pos=9184007;
   Y_PN(Ain);
   sf.pos=9184008;
   YzLT(Ain);
  }
  sf.pos=9184009;
  VleftExpr = YTKt(Ain, 1, 0);
  Vname = NULL;
  sf.pos=9184010;
  if ((YmTi(VleftExpr) == 1))
  {
   sf.pos=9184011;
   Vname = YYim(YjUS(VleftExpr));
  }
  else
  {
   sf.pos=9184012;
   YdIu(Vtoken, ((Tc*)&YkPj));
   sf.pos=9184013;
   Vname = ((Tc*)&YbbH);
  }
  sf.pos=9184014;
  YpBC(VloopVar, Vname);
  sf.pos=9184015;
  YvRw(VloopVar, Y74i(VleftExpr));
  sf.pos=9184016;
  YcHs(VloopVar, VleftExpr);
  sf.pos=9184017;
  YEk6(Vfor, VloopVar);
  sf.pos=9184018;
  if ((Y6qU(Ain)->Vtype != 82))
  {
   rt = 2;
   goto YCc7;
  }
  sf.pos=9184019;
  YuRk(Ain);
  sf.pos=9184020;
  Y_PN(Ain);
YCc7:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9184021;
 }
 sf.pos=9184022;
 YzLT(Ain);
 sf.pos=9184023;
 Vtoken1 = Y_PN(Ain);
 sf.pos=9184024;
 if ((Vtoken1->Vtype != 78))
 {
  sf.pos=9184025;
  YdIu(Vtoken1, ((Tc*)&YJji));
 }
 sf.pos=9184026;
 YzLT(Ain);
 sf.pos=9184027;
 Vexpr = YUWY(Ain);
 sf.pos=9184028;
 YMOM(Vfor, Vexpr);
 sf.pos=9184029;
 Vtoken1 = Y6qU(Ain);
 sf.pos=9184030;
 if (((Vtoken1->Vtype == 79) || (Vtoken1->Vtype == 76)))
 {
  sf.pos=9184031;
  if ((YCdt(Vfor) > 1))
  {
   sf.pos=9184032;
   YdIu(Vtoken1, ((Tc*)&Yf98));
  }
  sf.pos=9184033;
  YzLT(Ain);
  sf.pos=9184034;
  Y_PN(Ain);
  sf.pos=9184035;
  YzLT(Ain);
  sf.pos=9184036;
  VtoExpr = YUWY(Ain);
  sf.pos=9184037;
  if ((Vtoken1->Vtype == 79))
  {
   sf.pos=9184038;
   YmBG(Vfor, VtoExpr);
  }
  else
  {
   sf.pos=9184039;
   YV_5(Vfor, VtoExpr);
  }
  sf.pos=9184040;
  Vtoken1 = Y6qU(Ain);
  sf.pos=9184041;
  if ((Vtoken1->Vtype == 81))
  {
   sf.pos=9184042;
   YzLT(Ain);
   sf.pos=9184043;
   Y_PN(Ain);
   sf.pos=9184044;
   YzLT(Ain);
   sf.pos=9184045;
   VstepExpr = YUWY(Ain);
   sf.pos=9184046;
   YiIU(Vfor, VstepExpr);
  }
 }
 else
 {
  sf.pos=9184047;
  while ((Vtoken1->Vtype == 82))
  {
   sf.pos=9184048;
   YuRk(Ain);
   sf.pos=9184049;
   Y_PN(Ain);
   sf.pos=9184050;
   YzLT(Ain);
   sf.pos=9184051;
   Vexpr = YUWY(Ain);
   sf.pos=9184052;
   YMOM(Vfor, Vexpr);
   sf.pos=9184053;
   Vtoken1 = Y6qU(Ain);
  sf.pos=9184054;
  }
 }
 sf.pos=9184055;
 YQuF(Ain);
 sf.pos=9184056;
 Vstmts = YBd7(Ain, 0);
 sf.pos=9184057;
 if ((ZListSize(Vstmts) > 0))
 {
  sf.pos=9184058;
  YFf4(YRIK(YtnA(YCBH(Vfor), YWlm(((YXCg *)ZListGetPtr(Vstmts, 0)))), Vstmts), YksM(Ain)->VzuiPos);
 }
 sf.pos=9184059;
 Vstmt = YDNI(NULL);
 sf.pos=9184060;
 Yc8L(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 14), Vfor);
 sf.pos=9184061;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YdOB(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YXCg *Vstmt = 0;
 Yev8 *Vnext = 0;
 YnZD *Varg = 0;
 Tl *VargList = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7582100;
 Vstmt = YDNI(NULL);
 sf.pos=7582101;
 switch (AstartToken->Vtype)
 {
 case 46:
  {
   sf.pos=7582102;
   Yiw6(Vstmt, 20);
    break;
  }
 case 47:
  {
   sf.pos=7582103;
   Yiw6(Vstmt, 21);
    break;
  }
 case 48:
  {
   sf.pos=7582104;
   Yiw6(Vstmt, 22);
    break;
  }
 case 52:
  {
   sf.pos=7582105;
   Yiw6(Vstmt, 35);
    break;
  }
 }
 sf.pos=7582106;
 Vnext = Y_PN(Ain);
 sf.pos=7582107;
 YH7I(Ain, Vnext);
 sf.pos=7582108;
 YBch(Ain);
 sf.pos=7582109;
 if ((AstartToken->Vtype == 46))
 {
  sf.pos=7582110;
  VargList = YZnz(Ain, NULL, 0);
  sf.pos=7582111;
  if ((ZListSize(VargList) > 0))
  {
   sf.pos=7582112;
   Varg = ((YnZD *)ZListGetPtr(VargList, 0));
   sf.pos=7582113;
   YkEo(Vstmt, VargList);
  }
  else
  {
   sf.pos=7582114;
   Varg = YxDV(68, AstartToken->VzuiPos);
  }
 }
 else
 {
  sf.pos=7582115;
  Varg = YUWY(Ain);
 }
 sf.pos=7582116;
 if (((YmTi(Varg) != 68) || (Vnext->Vtype != 3)))
 {
  sf.pos=7582117;
  YQuF(Ain);
 }
 sf.pos=7582118;
 if ((YmTi(Varg) != 68))
 {
  sf.pos=7582119;
  YMTX(Vstmt, Varg);
 }
 sf.pos=7582120;
 YZqm(Vstmt, AstartToken->VzuiPos);
 sf.pos=7582121;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *Yhta(Yev8 *AstartToken, Y7Sj *Ain) {
 Tb VisBreak;
 Zsf sf;
 YXCg *r = 0;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2931900;
 VisBreak = (AstartToken->Vtype == 69);
 sf.pos=2931901;
 YQuF(Ain);
 sf.pos=2931902;
 Vstmt = YDNI(NULL);
 sf.pos=2931903;
 Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), ((VisBreak) ? (26) : (27)));
 sf.pos=2931904;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YlJY(Yev8 *AstartToken, Y7Sj *Ain) {
 Tb VhadDefault;
 Zsf sf;
 YXCg *r = 0;
 YnZD *VcondExpr = 0;
 Y5eh *Vcond = 0;
 Tl *Vstmts = NULL;
 YXCg *Vstmt = 0;
 Yev8 *Vtoken = 0;
 YnZD *VcaseExpr = 0;
 YhZL *Vblock = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6225100;
 YBch(Ain);
 sf.pos=6225101;
 VcondExpr = YUWY(Ain);
 sf.pos=6225102;
 Vcond = Y4Kn(NULL);
 sf.pos=6225103;
 YpGq(Vcond, VcondExpr);
 sf.pos=6225104;
 YQuF(Ain);
 sf.pos=6225105;
 Vstmts = ZnewList((Tt*)&YXCg__T, 0);
 VhadDefault = 0;
 sf.pos=6225106;
 while (1)
 {
  sf.pos=6225107;
  Vtoken = Y_PN(Ain);
  sf.pos=6225108;
  if ((Vtoken->Vtype == 73))
  {
   sf.pos=6225109;
   if (VhadDefault)
   {
    sf.pos=6225110;
    YdIu(Vtoken, ((Tc*)&Y7Zb));
   }
   sf.pos=6225111;
   YBch(Ain);
   sf.pos=6225112;
   VcaseExpr = YUWY(Ain);
   sf.pos=6225113;
   YQuF(Ain);
   sf.pos=6225114;
   Vstmt = YDNI(NULL);
   sf.pos=6225115;
   YMTX(Yiw6(YZqm(Vstmt, Vtoken->VzuiPos), 24), VcaseExpr);
   sf.pos=6225116;
   ZLap((Tl*)Vstmts, (Tz)(void*)Vstmt);
  }
  else {
  sf.pos=6225117;
 if ((Vtoken->Vtype == 74))
  {
   sf.pos=6225118;
   if (VhadDefault)
   {
    sf.pos=6225119;
    YdIu(Vtoken, ((Tc*)&YYge));
   }
   sf.pos=6225120;
   if ((Vstmt != NULL))
   {
    sf.pos=6225121;
    YdIu(Vtoken, ((Tc*)&YO0F));
   }
   sf.pos=6225122;
   VhadDefault = 1;
   sf.pos=6225123;
   YQuF(Ain);
   sf.pos=6225124;
   Vstmt = YDNI(NULL);
   sf.pos=6225125;
   Yiw6(YZqm(Vstmt, Vtoken->VzuiPos), 25);
   sf.pos=6225126;
   ZLap((Tl*)Vstmts, (Tz)(void*)Vstmt);
  }
  else {
  sf.pos=6225127;
 if (((Vtoken->Vtype == 93) || (Vtoken->Vtype == 1)))
  {
   rt = 2;
   goto YRpT;
  }
  else
  {
   sf.pos=6225128;
   if ((Vstmt == NULL))
   {
    sf.pos=6225129;
    YdIu(Vtoken, ((Tc*)&YE7Q));
   }
   sf.pos=6225130;
   YH7I(Ain, Vtoken);
   sf.pos=6225131;
   Vblock = YaF_(Vtoken, Ain, 8);
   sf.pos=6225132;
   if ((YJD1(Vblock) && (Vstmt != NULL)))
   {
    sf.pos=6225133;
    Yq9q(Vstmt, Vblock);
   }
   sf.pos=6225134;
   Vtoken = Y6qU(Ain);
   sf.pos=6225135;
   if ((Vtoken->Vtype == 71))
   {
    sf.pos=6225136;
    Vtoken = Y_PN(Ain);
    sf.pos=6225137;
    YQuF(Ain);
    sf.pos=6225138;
    if ((Vstmt != NULL))
    {
     sf.pos=6225139;
     YBVz(Vstmt, Vtoken->VzuiPos);
    }
   }
   sf.pos=6225140;
   Vstmt = NULL;
  }
  }}
YRpT:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6225141;
 }
 sf.pos=6225142;
 if ((ZListSize(Vstmts) > 0))
 {
  sf.pos=6225143;
  YFf4(YRIK(YzLV(Vcond), Vstmts), Vtoken->VzuiPos);
 }
 sf.pos=6225144;
 Vstmt = YDNI(NULL);
 sf.pos=6225145;
 YYdx(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 23), Vcond);
 sf.pos=6225146;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *Ywf0(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YnZD *Vexpr = 0;
 Y_1n *Vmethod = 0;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5482800;
 Vexpr = YsQE(AstartToken, Ain);
 sf.pos=5482801;
 Vmethod = YztZ(Vexpr);
 sf.pos=5482802;
 Vstmt = YDNI(NULL);
 sf.pos=5482803;
 YM__(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 11), Vmethod);
 sf.pos=5482804;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YG4L(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 YhZL *Vblock = 0;
 YXCg *Vstmt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8359300;
 YQuF(Ain);
 sf.pos=8359301;
 Vblock = YaF_(AstartToken, Ain, 0);
 sf.pos=8359302;
 Vstmt = YDNI(NULL);
 sf.pos=8359303;
 Yq9q(Yiw6(YZqm(Vstmt, AstartToken->VzuiPos), 30), Vblock);
 sf.pos=8359304;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
void YQ6k(Y7Np *Amethod, Y7Sj *Ain, Tb AisLambda, Te Aend_token) {
 Tb VdidFirst;
 Tb VfoundUse;
 Tb VfoundDefault;
 Tb VgotThreeDots;
 Zsf sf;
 Yev8 *Vtoken = 0;
 YRBza *Vtype = 0;
 YnZD *VtypeExpr = 0;
 YRBza *Vt = 0;
 YnZD *VnameExpr = 0;
 YYIi *Vd = 0;
 YYIi *Vd1 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VdidFirst = 0;
 VfoundUse = 0;
 VfoundDefault = 0;
 VgotThreeDots = 0;
 sf.pos=2668300;
 Y5bl(Ain);
 sf.pos=2668301;
 while (1)
 {
  Te Vttype;
  sf.pos=2668302;
  Vtoken = Y_PN(Ain);
  sf.pos=2668303;
  if ((Vtoken->Vtype == Aend_token))
  {
   rt = 2;
   goto YM_y;
  }
  sf.pos=2668304;
  if (!(VdidFirst))
  {
   sf.pos=2668305;
   VdidFirst = 1;
   sf.pos=2668306;
   YH7I(Ain, Vtoken);
  }
  else {
  sf.pos=2668307;
 if ((YksM(Ain)->Vtype == 18))
  {
   sf.pos=2668308;
   YH7I(Ain, Vtoken);
   sf.pos=2668309;
   YzLT(Ain);
  }
  else
  {
   sf.pos=2668310;
   if ((Vtoken->Vtype != 82))
   {
    sf.pos=2668311;
    YdIu(Vtoken, ((Tc*)&YhTQ));
   }
   sf.pos=2668312;
   YzLT(Ain);
   sf.pos=2668313;
   if ((YksM(Ain)->Vtype == 18))
   {
    sf.pos=2668314;
    YdIu(Vtoken, ((Tc*)&YAe7));
   }
  }
  }
  sf.pos=2668315;
  if ((Y6qU(Ain)->Vtype == Aend_token))
  {
   sf.pos=2668316;
   YdIu(Vtoken, ((Tc*)&YV20));
   sf.pos=2668317;
   Vtoken = Y_PN(Ain);
   sf.pos=2668318;
   if ((Vtoken->Vtype != Aend_token))
   {
    sf.pos=2668319;
    Vtoken = Y_PN(Ain);
   }
   rt = 2;
   goto YM_y;
  }
  sf.pos=2668320;
  if (VgotThreeDots)
  {
   sf.pos=2668321;
   YdIu(Vtoken, ((Tc*)&YG1N));
  }
  sf.pos=2668322;
  Vttype = 21;
  sf.pos=2668323;
  Vtype = Ya_p(NULL);
  sf.pos=2668324;
  Y2b1(Vtype, Vtoken->VzuiPos);
  sf.pos=2668325;
  if (VfoundUse)
  {
   sf.pos=2668326;
   YLJs(Vtype, 43);
  }
  else
  {
   sf.pos=2668327;
   Vtoken = YksM(Ain);
   sf.pos=2668328;
   if ((Vtoken->Vtype == 18))
   {
    sf.pos=2668329;
    Y_PN(Ain);
    sf.pos=2668330;
    YLJs(Vtype, 43);
    sf.pos=2668331;
    VfoundUse = 1;
    sf.pos=2668332;
    YzLT(Ain);
   }
   else {
   sf.pos=2668333;
 if (AisLambda)
   {
    sf.pos=2668334;
    YLJs(Vtype, 43);
   }
   else
   {
    sf.pos=2668335;
    VtypeExpr = YTKt(Ain, 0, 1);
    sf.pos=2668336;
    Yz09(YLJs(Vtype, 45), VtypeExpr);
    sf.pos=2668337;
    Vtoken = Y_PN(Ain);
    sf.pos=2668338;
    if (((Vtoken->Vtype == Aend_token) || (Vtoken->Vtype == 82)))
    {
     sf.pos=2668339;
     YdIu(Vtoken, ((Tc*)&YjHG));
    }
    sf.pos=2668340;
    YH7I(Ain, Vtoken);
    sf.pos=2668341;
    YzLT(Ain);
   }
   }
  }
  sf.pos=2668342;
  Vtoken = Y_PN(Ain);
  sf.pos=2668343;
  if ((Vtoken->Vtype == 20))
  {
   sf.pos=2668344;
   VgotThreeDots = 1;
   sf.pos=2668345;
   YzLT(Ain);
   sf.pos=2668346;
   Vtoken = Y_PN(Ain);
  }
  sf.pos=2668347;
  if ((Vtoken->Vtype == 109))
  {
   sf.pos=2668348;
   YuRk(Ain);
   sf.pos=2668349;
   Vtoken = Y_PN(Ain);
   sf.pos=2668350;
   if (VfoundUse)
   {
    sf.pos=2668351;
    YLJs(Vtype, 44);
   }
   else
   {
    sf.pos=2668352;
    Vt = YE45(YLJs(Ya_p(NULL), 44), Vtype);
    sf.pos=2668353;
    Vtype = Vt;
    sf.pos=2668354;
    Y2b1(Vtype, Vtoken->VzuiPos);
   }
  }
  sf.pos=2668355;
  if (VfoundUse)
  {
   sf.pos=2668356;
   YH7I(Ain, Vtoken);
   sf.pos=2668357;
   VnameExpr = YTKt(Ain, 1, 0);
   sf.pos=2668358;
   Vd = YdTj(Y6vX(YvRw(YTLb(YyeO(Amethod), VnameExpr), Vtoken->VzuiPos), 1), Vtype);
   sf.pos=2668359;
   YcHs(Vd, VnameExpr);
   sf.pos=2668360;
   Vtoken = Y6qU(Ain);
   sf.pos=2668361;
   if ((Vtoken->Vtype == 23))
   {
    sf.pos=2668362;
    Vtoken = YABA(Ain);
    sf.pos=2668363;
    YpBC(Vd, Vtoken->Vvalue);
   }
  }
  else
  {
   sf.pos=2668364;
   if ((Vtoken->Vtype != 21))
   {
    sf.pos=2668365;
    YdIu(Vtoken, ((Tc*)&YTbL));
    rt = 2;
    goto Yjdp;
   }
   sf.pos=2668366;
   Vd1 = YG6V(Amethod);
   sf.pos=2668367;
   YdTj(Yv8X(Y6vX(YvRw(YpBC(Vd1, Vtoken->Vvalue), Vtoken->VzuiPos), 1), VgotThreeDots), Vtype);
   sf.pos=2668368;
   if ((Y6qU(Ain)->Vtype == 112))
   {
    sf.pos=2668369;
    YzLT(Ain);
    sf.pos=2668370;
    Y_PN(Ain);
    sf.pos=2668371;
    YzLT(Ain);
    sf.pos=2668372;
    YhZx(Vd1, YUWY(Ain));
    sf.pos=2668373;
    VfoundDefault = 1;
   }
   else {
   sf.pos=2668374;
 if (VfoundDefault)
   {
    sf.pos=2668375;
    YHwp(((Tc*)&Y8XM), Ain);
   }
   }
Yjdp:
   if (rt) goto YM_y;
  }
  sf.pos=2668376;
  if ((VfoundDefault && VgotThreeDots))
  {
   sf.pos=2668377;
   YHwp(((Tc*)&YKXH), Ain);
  }
  sf.pos=2668378;
  Vtoken = Y6qU(Ain);
  sf.pos=2668379;
  if ((Vtoken->Vtype == 126))
  {
   sf.pos=2668380;
   YzLT(Ain);
  }
  sf.pos=2668381;
  if (((Vtoken->Vtype != 82) && (Vtoken->Vtype != 18)))
  {
   sf.pos=2668382;
   Y5bl(Ain);
  }
YM_y:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=2668383;
 }
 topFrame = sf.prev;
 return;
}
void YcHs(YYIi *Ad, YnZD *Aexpr) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2250700;
 YJ03(Ad, Y00A(Aexpr));
 sf.pos=2250701;
 Y5JX(Ad, YpO1(Aexpr));
 topFrame = sf.prev;
 return;
}
void Y6sC(YJON *Aza, Tb ArequireSep, Tl *Aaccepted, Y7Sj *Ain) {
 Tb VneedSep;
 Zsf sf;
 Yev8 *Vtoken = 0;
 Tc *VattrName = NULL;
 Tc *VattrValue = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8077200;
 VneedSep = ArequireSep;
 sf.pos=8077201;
 while (1)
 {
  sf.pos=8077202;
  Vtoken = Y6qU(Ain);
  sf.pos=8077203;
  if ((Vtoken->Vtype != 88))
  {
   rt = 2;
   goto YEgz;
  }
  sf.pos=8077204;
  if (VneedSep)
  {
   sf.pos=8077205;
   YzLT(Ain);
  }
  else
  {
   sf.pos=8077206;
   YuRk(Ain);
   sf.pos=8077207;
   VneedSep = 1;
  }
  sf.pos=8077208;
  Vtoken = Y_PN(Ain);
  sf.pos=8077209;
  Vtoken = Y_PN(Ain);
  sf.pos=8077210;
  if ((Vtoken->Vtype != 21))
  {
   sf.pos=8077211;
   YdIu(Vtoken, ((Tc*)&Ymh8));
   rt = 2;
   goto YEgz;
  }
  sf.pos=8077212;
  VattrName = Vtoken->Vvalue;
  VattrValue = NULL;
  sf.pos=8077213;
  Vtoken = Y_PN(Ain);
  sf.pos=8077214;
  if ((Vtoken->Vtype == 112))
  {
   sf.pos=8077215;
   Vtoken = Y_PN(Ain);
   sf.pos=8077216;
   VattrValue = Vtoken->Vvalue;
  }
  else
  {
   sf.pos=8077217;
   YH7I(Ain, Vtoken);
  }
  sf.pos=8077218;
  Y5DG(Vtoken, VattrName, Aaccepted);
  sf.pos=8077219;
  if ((ZstringCmp(VattrName, ((Tc*)&YODD)) == 0))
  {
   sf.pos=8077220;
   if ((VattrValue == NULL))
   {
    sf.pos=8077221;
    YdIu(Vtoken, ((Tc*)&Ypcv));
   }
   else {
   sf.pos=8077222;
 if ((ZstringCmp(VattrValue, ((Tc*)&YhZb)) == 0))
   {
    sf.pos=8077223;
    Yo8f((Y929(Aza) || Ynfv(Aza)), Vtoken, VattrName);
    sf.pos=8077224;
    Y980(Aza, 1);
   }
   else {
   sf.pos=8077225;
 if ((ZstringCmp(VattrValue, ((Tc*)&YjK7)) == 0))
   {
    sf.pos=8077226;
    Yo8f((Y929(Aza) || Ynfv(Aza)), Vtoken, VattrName);
    sf.pos=8077227;
    YDDz(Aza, 1);
   }
   else
   {
    sf.pos=8077228;
    YdIu(Vtoken, ((Tc*)&YNcJ));
   }
   }}
  }
  else {
  sf.pos=8077229;
 if (((ZstringCmp(VattrName, ((Tc*)&Yr91)) == 0) || (ZstringCmp(VattrName, ((Tc*)&Yyir)) == 0)))
  {
   sf.pos=8077230;
   if ((VattrValue == NULL))
   {
    sf.pos=8077231;
    YdIu(Vtoken, ZcS(((Tc*)&YQK_), VattrName));
   }
   else
   {
    Te Vvis;
    Te Vzavis;
    sf.pos=8077232;
    Vvis = ZDictGetIntDef(YK6i, (Tz)(void*)VattrValue, 0);
    sf.pos=8077233;
    Vzavis = ZDictGetIntDef(Yoe0, (Tz)(void*)VattrValue, 1);
    sf.pos=8077234;
    if ((Vvis == 0))
    {
     sf.pos=8077235;
     YdIu(Vtoken, ZcS3(((Tc*)&YThp), VattrName, ((Tc*)&Y8)));
    }
    sf.pos=8077236;
    if ((ZstringCmp(VattrName, ((Tc*)&Yr91)) == 0))
    {
     sf.pos=8077237;
     Yo8f(YpeP(Aza), Vtoken, ((Tc*)&Yr91));
     sf.pos=8077238;
     YjX9(Aza, Vzavis);
    }
    else
    {
     sf.pos=8077239;
     Yo8f(YVep(Aza), Vtoken, ((Tc*)&Yyir));
     sf.pos=8077240;
     YUKK(Aza, Vzavis);
    }
   }
  }
  else
  {
   sf.pos=8077241;
   if ((VattrValue != NULL))
   {
    sf.pos=8077242;
    YdIu(Vtoken, ((Tc*)&YDZt));
   }
   sf.pos=8077243;
   if ((ZstringCmp(VattrName, ((Tc*)&YpLJ)) == 0))
   {
    sf.pos=8077244;
    Yo8f(YHd1(Aza), Vtoken, VattrName);
    sf.pos=8077245;
    Y_Uu(Aza, 1);
   }
   else {
   sf.pos=8077246;
 if ((ZstringCmp(VattrName, ((Tc*)&Yl3I)) == 0))
   {
    sf.pos=8077247;
    Yo8f(YJqm(Aza), Vtoken, VattrName);
    sf.pos=8077248;
    Y3gm(Aza, 1);
   }
   else {
   sf.pos=8077249;
 if ((ZstringCmp(VattrName, ((Tc*)&Ybyf)) == 0))
   {
    sf.pos=8077250;
    Yo8f(YapZ(Aza), Vtoken, VattrName);
    sf.pos=8077251;
    YdJG(Aza, 1);
   }
   else {
   sf.pos=8077252;
 if ((ZstringCmp(VattrName, ((Tc*)&YrkU)) == 0))
   {
    sf.pos=8077253;
    Yo8f(YCKw(Aza), Vtoken, VattrName);
    sf.pos=8077254;
    Y5IN(Aza, 1);
   }
   else {
   sf.pos=8077255;
 if ((ZstringCmp(VattrName, ((Tc*)&YlOO)) == 0))
   {
    sf.pos=8077256;
    Yo8f(YBPw(Aza), Vtoken, VattrName);
    sf.pos=8077257;
    Y5i_(Aza, 1);
   }
   else {
   sf.pos=8077258;
 if ((ZstringCmp(VattrName, ((Tc*)&YDqN)) == 0))
   {
    sf.pos=8077259;
    Yo8f(YTrv(Aza), Vtoken, VattrName);
    sf.pos=8077260;
    YOG0(Aza, 1);
   }
   else {
   sf.pos=8077261;
 if ((ZstringCmp(VattrName, ((Tc*)&YIK3)) == 0))
   {
    sf.pos=8077262;
    Yo8f(YYLM(Aza), Vtoken, VattrName);
    sf.pos=8077263;
    YJmK(Aza, 1);
   }
   else {
   sf.pos=8077264;
 if ((ZstringCmp(VattrName, ((Tc*)&YtNZa)) == 0))
   {
    sf.pos=8077265;
    Yo8f(YdXn(Aza), Vtoken, VattrName);
    sf.pos=8077266;
    YsDp(Aza, 1);
   }
   else {
   sf.pos=8077267;
 if ((ZstringCmp(VattrName, ((Tc*)&YE5Z)) == 0))
   {
    sf.pos=8077268;
    Yo8f(YiKB(Aza), Vtoken, VattrName);
    sf.pos=8077269;
    YFFWa(Aza, 1);
   }
   else
   {
    Te Vv;
    sf.pos=8077270;
    Vv = ZDictGetIntDef(Yoe0, (Tz)(void*)VattrName, 1);
    sf.pos=8077271;
    if ((Vv != 1))
    {
     sf.pos=8077272;
     YpNX(YVd6(Aza), Vtoken, VattrName);
     sf.pos=8077273;
     Ywbp(Aza, Vv);
    }
    else
    {
     sf.pos=8077274;
     YdIu(Vtoken, ZcS(((Tc*)&YKik), VattrName));
    }
   }
   }}}}}}}}
  }
  }
YEgz:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=8077275;
 }
 topFrame = sf.prev;
 return;
}
void Y5DG(Yev8 *Atoken, Tc *Aname, Tl *Aaccepted) {
 Zsf sf;
 Tl *Zf1 = NULL;
 Tc *Vn = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2728000;
 {
  Tfl Zf1i;
  Zf1 = Aaccepted;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vn;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=2728001;
  if ((ZstringCmp(Vn, Aname) == 0))
  {
   sf.pos=2728002;
   rt = 1;
   goto YOrU;
  }
YOrU:
  if (rt) goto YwCE;
  sf.pos=2728003;
  }
 }
 sf.pos=2728004;
 YdIu(Atoken, ZcS(((Tc*)&YH8L), Aname));
YwCE:
 topFrame = sf.prev;
 return;
}
void Yo8f(Tb Avalue, Yev8 *Atoken, Tc *Aname) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=759800;
 if (Avalue)
 {
  sf.pos=759801;
  YdIu(Atoken, ZcS(((Tc*)&YOzx), Aname));
 }
 topFrame = sf.prev;
 return;
}
void YpNX(Tb AisSet, Yev8 *Atoken, Tc *Aname) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9722300;
 if (AisSet)
 {
  sf.pos=9722301;
  YdIu(Atoken, ZcS(((Tc*)&Y2U4), Aname));
 }
 topFrame = sf.prev;
 return;
}
YnZD *YUWY(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=317600;
 r = Ybvc(Ain);
 topFrame = sf.prev;
 return r;
}
YnZD *Ybvc(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9961800;
 Vexpr = YDIQ(Ain);
 sf.pos=9961801;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=9961802;
  r = Vexpr;
  rt = 1;
  goto YvkI;
 }
 sf.pos=9961803;
 if ((Y6qU(Ain)->Vtype == 86))
 {
  sf.pos=9961804;
  YzLT(Ain);
  sf.pos=9961805;
  Vtoken = Y_PN(Ain);
  sf.pos=9961806;
  YzLT(Ain);
  sf.pos=9961807;
  Ve = YxDV(47, Vtoken->VzuiPos);
  sf.pos=9961808;
  Yfkd(Ve, Vexpr);
  sf.pos=9961809;
  Vexpr = Ve;
  sf.pos=9961810;
  Ve = Ybvc(Ain);
  sf.pos=9961811;
  YPfx(Vexpr, Ve);
 }
 sf.pos=9961812;
 r = Vexpr;
YvkI:
 topFrame = sf.prev;
 return r;
}
YnZD *YDIQ(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7242900;
 Vexpr = YMzT(Ain);
 sf.pos=7242901;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=7242902;
  r = Vexpr;
  rt = 1;
  goto Y3M5;
 }
 sf.pos=7242903;
 Vtoken = Y6qU(Ain);
 sf.pos=7242904;
 if ((Vtoken->Vtype == 85))
 {
  sf.pos=7242905;
  YzLT(Ain);
  sf.pos=7242906;
  Vtoken = Y_PN(Ain);
  sf.pos=7242907;
  YzLT(Ain);
  sf.pos=7242908;
  Ve = YxDV(48, Vtoken->VzuiPos);
  sf.pos=7242909;
  YkIT(Ve, Vexpr);
  sf.pos=7242910;
  Vexpr = Ve;
  sf.pos=7242911;
  Ve = YDIQ(Ain);
  sf.pos=7242912;
  Yfkd(Vexpr, Ve);
  sf.pos=7242913;
  YzLT(Ain);
  sf.pos=7242914;
  Vtoken = Y_PN(Ain);
  sf.pos=7242915;
  if ((Vtoken->Vtype != 84))
  {
   sf.pos=7242916;
   YdIu(Vtoken, ((Tc*)&YCtv));
   sf.pos=7242917;
   YH7I(Ain, Vtoken);
  }
  else
  {
   sf.pos=7242918;
   YzLT(Ain);
   sf.pos=7242919;
   Ve = YDIQ(Ain);
   sf.pos=7242920;
   YPfx(Vexpr, Ve);
  }
 }
 sf.pos=7242921;
 r = Vexpr;
Y3M5:
 topFrame = sf.prev;
 return r;
}
YnZD *YMzT(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4173300;
 Vexpr = YALQ(Ain);
 sf.pos=4173301;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=4173302;
  r = Vexpr;
  rt = 1;
  goto Y8XX;
 }
 sf.pos=4173303;
 while (1)
 {
  sf.pos=4173304;
  Vtoken = Y6qU(Ain);
  sf.pos=4173305;
  if ((Vtoken->Vtype != 131))
  {
   rt = 2;
   goto YR7y;
  }
  sf.pos=4173306;
  YzLT(Ain);
  sf.pos=4173307;
  Vtoken = Y_PN(Ain);
  sf.pos=4173308;
  YzLT(Ain);
  sf.pos=4173309;
  Ve = YxDV(62, Vtoken->VzuiPos);
  sf.pos=4173310;
  Yfkd(Ve, Vexpr);
  sf.pos=4173311;
  Vexpr = Ve;
  sf.pos=4173312;
  Ve = YALQ(Ain);
  sf.pos=4173313;
  YPfx(Vexpr, Ve);
YR7y:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=4173314;
 }
 sf.pos=4173315;
 r = Vexpr;
Y8XX:
 topFrame = sf.prev;
 return r;
}
YnZD *YALQ(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6981500;
 Vexpr = YDun(Ain);
 sf.pos=6981501;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=6981502;
  r = Vexpr;
  rt = 1;
  goto YruG;
 }
 sf.pos=6981503;
 while (1)
 {
  sf.pos=6981504;
  Vtoken = Y6qU(Ain);
  sf.pos=6981505;
  if ((Vtoken->Vtype != 130))
  {
   rt = 2;
   goto Ykv4;
  }
  sf.pos=6981506;
  YzLT(Ain);
  sf.pos=6981507;
  Vtoken = Y_PN(Ain);
  sf.pos=6981508;
  YzLT(Ain);
  sf.pos=6981509;
  Ve = YxDV(61, Vtoken->VzuiPos);
  sf.pos=6981510;
  Yfkd(Ve, Vexpr);
  sf.pos=6981511;
  Vexpr = Ve;
  sf.pos=6981512;
  Ve = YDun(Ain);
  sf.pos=6981513;
  YPfx(Vexpr, Ve);
Ykv4:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6981514;
 }
 sf.pos=6981515;
 r = Vexpr;
YruG:
 topFrame = sf.prev;
 return r;
}
YnZD *YDun(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 Yev8 *Vfirst = 0;
 YkxB *Vpos = 0;
 YnZD *Ve = 0;
 Tl *Vtypes = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8732700;
 Vexpr = YF5Y(Ain);
 sf.pos=8732701;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=8732702;
  r = Vexpr;
  rt = 1;
  goto YI5X;
 }
 sf.pos=8732703;
 while (1)
 {
  Tb VtypeSpec;
  sf.pos=8732704;
  Vtoken = Y6qU(Ain);
  sf.pos=8732705;
  if ((Vtoken->Vtype == 112))
  {
   rt = 2;
   goto Y8ZV;
  }
  sf.pos=8732706;
  if (((((((((((((Vtoken->Vtype != 125) && (Vtoken->Vtype != 127)) && (Vtoken->Vtype != 133)) && (Vtoken->Vtype != 134)) && (Vtoken->Vtype != 135)) && (Vtoken->Vtype != 136)) && (Vtoken->Vtype != 137)) && (Vtoken->Vtype != 138)) && (Vtoken->Vtype != 139)) && (Vtoken->Vtype != 140)) && (Vtoken->Vtype != 128)) && (Vtoken->Vtype != 129)))
  {
   rt = 2;
   goto Y8ZV;
  }
  VtypeSpec = 0;
  sf.pos=8732707;
  Vfirst = Y_PN(Ain);
  sf.pos=8732708;
  if ((Vfirst->Vtype == 135))
  {
   sf.pos=8732709;
   VtypeSpec = 1;
   sf.pos=8732710;
   Vtoken = Vfirst;
  }
  else
  {
   sf.pos=8732711;
   YH7I(Ain, Vfirst);
   sf.pos=8732712;
   YzLT(Ain);
   sf.pos=8732713;
   Vtoken = Y_PN(Ain);
  }
  sf.pos=8732714;
  if (VtypeSpec)
  {
   sf.pos=8732715;
   YBch(Ain);
  }
  else
  {
   sf.pos=8732716;
   YzLT(Ain);
  }
  sf.pos=8732717;
  Vpos = Y83A(Ain->Vinput->Vpos);
  sf.pos=8732718;
  Ve = Y4GO(NULL);
  sf.pos=8732719;
  switch (Vtoken->Vtype)
  {
  case 125:
   {
    sf.pos=8732720;
    YaZq(Ve, 49);
     break;
   }
  case 127:
   {
    sf.pos=8732721;
    YaZq(Ve, 50);
     break;
   }
  case 133:
   {
    sf.pos=8732722;
    YaZq(Ve, 53);
     break;
   }
  case 134:
   {
    sf.pos=8732723;
    YaZq(Ve, 54);
     break;
   }
  case 135:
   {
    sf.pos=8732724;
    if (VtypeSpec)
    {
     sf.pos=8732725;
     YaZq(Ve, 22);
    }
    else
    {
     sf.pos=8732726;
     YaZq(Ve, 55);
    }
     break;
   }
  case 136:
   {
    sf.pos=8732727;
    YaZq(Ve, 56);
     break;
   }
  case 137:
   {
    sf.pos=8732728;
    YaZq(Ve, 57);
     break;
   }
  case 138:
   {
    sf.pos=8732729;
    YaZq(Ve, 58);
     break;
   }
  case 139:
   {
    sf.pos=8732730;
    YaZq(Ve, 59);
     break;
   }
  case 140:
   {
    sf.pos=8732731;
    YaZq(Ve, 60);
     break;
   }
  case 128:
   {
    sf.pos=8732732;
    YaZq(Ve, 51);
     break;
   }
  case 129:
   {
    sf.pos=8732733;
    YaZq(Ve, 52);
     break;
   }
  }
  sf.pos=8732734;
  Yfkd(Ve, Vexpr);
  sf.pos=8732735;
  Y4_i(Ve, Vtoken->VzuiPos);
  sf.pos=8732736;
  if (VtypeSpec)
  {
   Tb VhasOp;
   VhasOp = 0;
   sf.pos=8732737;
   if (((((YmTi(Vexpr) != 1) && (YmTi(Vexpr) != 20)) && Y8FL(Vexpr)) && YBlB(Vexpr)))
   {
    sf.pos=8732738;
    Yfkd(Ve, Y3Wy(Vexpr));
    sf.pos=8732739;
    VhasOp = 1;
   }
   sf.pos=8732740;
   Vtypes = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=8732741;
   Ya8Z(Ain, Vtypes, 0);
   sf.pos=8732742;
   YbfL(Ve, Vtypes);
   sf.pos=8732743;
   Ve = Y3lj(Ve, Ain, 2);
   sf.pos=8732744;
   if (VhasOp)
   {
    sf.pos=8732745;
    YPfx(Vexpr, Ve);
   }
   else
   {
    sf.pos=8732746;
    Vexpr = Ve;
   }
  }
  else
  {
   sf.pos=8732747;
   Vexpr = Ve;
   sf.pos=8732748;
   Ve = YF5Y(Ain);
   sf.pos=8732749;
   YPfx(Vexpr, Ve);
  }
Y8ZV:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=8732750;
 }
 sf.pos=8732751;
 r = Vexpr;
YI5X:
 topFrame = sf.prev;
 return r;
}
YnZD *YF5Y(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2223200;
 Vexpr = Y97P(Ain);
 sf.pos=2223201;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=2223202;
  r = Vexpr;
  rt = 1;
  goto Yx5j;
 }
 sf.pos=2223203;
 while (1)
 {
  sf.pos=2223204;
  Vtoken = Y6qU(Ain);
  sf.pos=2223205;
  if ((Vtoken->Vtype != 106))
  {
   rt = 2;
   goto YHvj;
  }
  sf.pos=2223206;
  YzLT(Ain);
  sf.pos=2223207;
  Vtoken = Y_PN(Ain);
  sf.pos=2223208;
  YzLT(Ain);
  sf.pos=2223209;
  Ve = YxDV(41, Vtoken->VzuiPos);
  sf.pos=2223210;
  Yfkd(Ve, Vexpr);
  sf.pos=2223211;
  Vexpr = Ve;
  sf.pos=2223212;
  YPfx(Vexpr, Y97P(Ain));
YHvj:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=2223213;
 }
 sf.pos=2223214;
 r = Vexpr;
Yx5j:
 topFrame = sf.prev;
 return r;
}
YnZD *Y97P(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vright = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=522300;
 Vexpr = Yxkx(Ain);
 sf.pos=522301;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=522302;
  r = Vexpr;
  rt = 1;
  goto YYka;
 }
 sf.pos=522303;
 while (1)
 {
  sf.pos=522304;
  Vtoken = Y6qU(Ain);
  sf.pos=522305;
  if ((((Vtoken->Vtype != 109) && (Vtoken->Vtype != 107)) && (Vtoken->Vtype != 108)))
  {
   rt = 2;
   goto YmhK;
  }
  sf.pos=522306;
  YzLT(Ain);
  sf.pos=522307;
  Vtoken = Y_PN(Ain);
  sf.pos=522308;
  YzLT(Ain);
  sf.pos=522309;
  Vright = Yxkx(Ain);
  sf.pos=522310;
  if (((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3))) && (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))))
  {
   Ti Vval;
   Vval = 0;
   sf.pos=522311;
   if ((Vtoken->Vtype == 109))
   {
    sf.pos=522312;
    Vval = (YsEM(Vexpr) & YsEM(Vright));
   }
   else {
   sf.pos=522313;
 if ((Vtoken->Vtype == 107))
   {
    sf.pos=522314;
    Vval = (YsEM(Vexpr) | YsEM(Vright));
   }
   else
   {
    sf.pos=522315;
    Vval = (YsEM(Vexpr) ^ YsEM(Vright));
   }
   }
   sf.pos=522316;
   Ypk4(Vexpr, Vval);
  }
  else
  {
   sf.pos=522317;
   Ve = Y4GO(NULL);
   sf.pos=522318;
   if ((Vtoken->Vtype == 109))
   {
    sf.pos=522319;
    YaZq(Ve, 44);
   }
   else {
   sf.pos=522320;
 if ((Vtoken->Vtype == 107))
   {
    sf.pos=522321;
    YaZq(Ve, 45);
   }
   else
   {
    sf.pos=522322;
    YaZq(Ve, 46);
   }
   }
   sf.pos=522323;
   Yfkd(Ve, Vexpr);
   sf.pos=522324;
   YPfx(Ve, Vright);
   sf.pos=522325;
   Y4_i(Ve, Vtoken->VzuiPos);
   sf.pos=522326;
   Vexpr = Ve;
  }
YmhK:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=522327;
 }
 sf.pos=522328;
 r = Vexpr;
YYka:
 topFrame = sf.prev;
 return r;
}
YnZD *Yxkx(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vright = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9533000;
 Vexpr = YxCP(Ain);
 sf.pos=9533001;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=9533002;
  r = Vexpr;
  rt = 1;
  goto YtHc;
 }
 sf.pos=9533003;
 while (1)
 {
  sf.pos=9533004;
  Vtoken = Y6qU(Ain);
  sf.pos=9533005;
  if (((Vtoken->Vtype != 111) && (Vtoken->Vtype != 110)))
  {
   rt = 2;
   goto Y9So;
  }
  sf.pos=9533006;
  YzLT(Ain);
  sf.pos=9533007;
  Vtoken = Y_PN(Ain);
  sf.pos=9533008;
  YzLT(Ain);
  sf.pos=9533009;
  Vright = YxCP(Ain);
  sf.pos=9533010;
  if (((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3))) && (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))))
  {
   Ti Vval;
   Vval = 0;
   sf.pos=9533011;
   if ((Vtoken->Vtype == 111))
   {
    sf.pos=9533012;
    Vval = (YsEM(Vexpr) << YsEM(Vright));
   }
   else
   {
    sf.pos=9533013;
    Vval = (YsEM(Vexpr) >> YsEM(Vright));
   }
   sf.pos=9533014;
   Ypk4(Vexpr, Vval);
  }
  else
  {
   sf.pos=9533015;
   Ve = Y4GO(NULL);
   sf.pos=9533016;
   if ((Vtoken->Vtype == 111))
   {
    sf.pos=9533017;
    YaZq(Ve, 42);
   }
   else
   {
    sf.pos=9533018;
    YaZq(Ve, 43);
   }
   sf.pos=9533019;
   Yfkd(Ve, Vexpr);
   sf.pos=9533020;
   YPfx(Ve, Vright);
   sf.pos=9533021;
   Y4_i(Ve, Vtoken->VzuiPos);
   sf.pos=9533022;
   Vexpr = Ve;
  }
Y9So:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=9533023;
 }
 sf.pos=9533024;
 r = Vexpr;
YtHc:
 topFrame = sf.prev;
 return r;
}
YnZD *YxCP(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vright = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8564800;
 Vexpr = YsLP(Ain);
 sf.pos=8564801;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=8564802;
  r = Vexpr;
  rt = 1;
  goto YeLQ;
 }
 sf.pos=8564803;
 while (1)
 {
  sf.pos=8564804;
  Vtoken = Y6qU(Ain);
  sf.pos=8564805;
  if (((Vtoken->Vtype != 100) && (Vtoken->Vtype != 98)))
  {
   rt = 2;
   goto YMcD;
  }
  sf.pos=8564806;
  YzLT(Ain);
  sf.pos=8564807;
  Vtoken = Y_PN(Ain);
  sf.pos=8564808;
  YzLT(Ain);
  sf.pos=8564809;
  Vright = YsLP(Ain);
  sf.pos=8564810;
  if (((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3))) && (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))))
  {
   Ti Vval;
   Vval = 0;
   sf.pos=8564811;
   if ((Vtoken->Vtype == 100))
   {
    sf.pos=8564812;
    Vval = (YsEM(Vexpr) + YsEM(Vright));
   }
   else
   {
    sf.pos=8564813;
    Vval = (YsEM(Vexpr) - YsEM(Vright));
   }
   sf.pos=8564814;
   Ypk4(Vexpr, Vval);
  }
  else {
  sf.pos=8564815;
 if ((((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3)) || (YmTi(Vexpr) == 4))) && ((((YmTi(Vright) == 2) || (YmTi(Vright) == 3)) || (YmTi(Vright) == 4)))))
  {
   Tf Vlval;
   Tf Vrval;
   Vlval = 0;
   sf.pos=8564816;
   if (((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3)))
   {
    sf.pos=8564817;
    Vlval = YsEM(Vexpr);
   }
   else
   {
    sf.pos=8564818;
    Vlval = YAcd(Vexpr);
   }
   Vrval = 0;
   sf.pos=8564819;
   if (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))
   {
    sf.pos=8564820;
    Vrval = YsEM(Vright);
   }
   else
   {
    sf.pos=8564821;
    Vrval = YAcd(Vright);
   }
   sf.pos=8564822;
   if ((Vtoken->Vtype == 100))
   {
    sf.pos=8564823;
    Vlval += Vrval;
   }
   else
   {
    sf.pos=8564824;
    Vlval -= Vrval;
   }
   sf.pos=8564825;
   Y1BD(Vexpr, Vlval);
   sf.pos=8564826;
   YaZq(Vexpr, 4);
  }
  else
  {
   sf.pos=8564827;
   Ve = Y4GO(NULL);
   sf.pos=8564828;
   if ((Vtoken->Vtype == 100))
   {
    sf.pos=8564829;
    YaZq(Ve, 36);
   }
   else
   {
    sf.pos=8564830;
    YaZq(Ve, 37);
   }
   sf.pos=8564831;
   Yfkd(Ve, Vexpr);
   sf.pos=8564832;
   YPfx(Ve, Vright);
   sf.pos=8564833;
   Y4_i(Ve, Vtoken->VzuiPos);
   sf.pos=8564834;
   Vexpr = Ve;
  }
  }
YMcD:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=8564835;
 }
 sf.pos=8564836;
 r = Vexpr;
YeLQ:
 topFrame = sf.prev;
 return r;
}
YnZD *YsLP(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 Yev8 *Vnext = 0;
 YnZD *Vright = 0;
 YnZD *Ve = 0;
 YU01 t0 = {};
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6524600;
 Vexpr = YV4G(Ain);
 sf.pos=6524601;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=6524602;
  r = Vexpr;
  rt = 1;
  goto Yn8i;
 }
 sf.pos=6524603;
 while (1)
 {
  sf.pos=6524604;
  Vtoken = Y6qU(Ain);
  sf.pos=6524605;
  if ((((Vtoken->Vtype != 103) && (Vtoken->Vtype != 104)) && (Vtoken->Vtype != 105)))
  {
   rt = 2;
   goto Y7uQ;
  }
  sf.pos=6524606;
  if ((Vtoken->Vtype == 105))
  {
   Vnext = 0;
   sf.pos=6524607;
   (t0 = YdZD(Ain));
   Vtoken = t0.a0;
   Vnext = t0.a1;
   sf.pos=6524608;
   if (!(YfTZ(Vnext)))
   {
    rt = 2;
    goto YOgP;
   }
YOgP:
   if (rt) goto Y7uQ;
  }
  sf.pos=6524609;
  YzLT(Ain);
  sf.pos=6524610;
  Vtoken = Y_PN(Ain);
  sf.pos=6524611;
  YzLT(Ain);
  sf.pos=6524612;
  Vright = YV4G(Ain);
  sf.pos=6524613;
  if (((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3))) && (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))))
  {
   Ti Vval;
   Vval = 0;
   sf.pos=6524614;
   if ((Vtoken->Vtype == 103))
   {
    sf.pos=6524615;
    Vval = (YsEM(Vexpr) * YsEM(Vright));
   }
   else
   {
    sf.pos=6524616;
    if ((YsEM(Vright) == 0))
    {
     sf.pos=6524617;
     YdIu(Vtoken, ((Tc*)&YOH4));
     sf.pos=6524618;
     Vval = 0;
    }
    else {
    sf.pos=6524619;
 if ((Vtoken->Vtype == 104))
    {
     sf.pos=6524620;
     Vval = (YsEM(Vexpr) / YsEM(Vright));
    }
    else
    {
     sf.pos=6524621;
     Vval = (YsEM(Vexpr) % YsEM(Vright));
    }
    }
   }
   sf.pos=6524622;
   Ypk4(Vexpr, Vval);
  }
  else {
  sf.pos=6524623;
 if ((((((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3)) || (YmTi(Vexpr) == 4))) && ((((YmTi(Vright) == 2) || (YmTi(Vright) == 3)) || (YmTi(Vright) == 4)))))
  {
   Tf Vlval;
   Tf Vrval;
   Vlval = 0;
   sf.pos=6524624;
   if (((YmTi(Vexpr) == 2) || (YmTi(Vexpr) == 3)))
   {
    sf.pos=6524625;
    Vlval = YsEM(Vexpr);
   }
   else
   {
    sf.pos=6524626;
    Vlval = YAcd(Vexpr);
   }
   Vrval = 0;
   sf.pos=6524627;
   if (((YmTi(Vright) == 2) || (YmTi(Vright) == 3)))
   {
    sf.pos=6524628;
    Vrval = YsEM(Vright);
   }
   else
   {
    sf.pos=6524629;
    Vrval = YAcd(Vright);
   }
   sf.pos=6524630;
   if ((Vtoken->Vtype == 103))
   {
    sf.pos=6524631;
    Vlval = (Vlval * Vrval);
   }
   else
   {
    sf.pos=6524632;
    if ((Vrval == 0))
    {
     sf.pos=6524633;
     YdIu(Vtoken, ((Tc*)&YOH4));
    }
    else {
    sf.pos=6524634;
 if ((Vtoken->Vtype == 104))
    {
     sf.pos=6524635;
     Vlval = (Vlval / Vrval);
    }
    else
    {
     sf.pos=6524636;
     YdIu(Vtoken, ((Tc*)&Y3el));
    }
    }
   }
   sf.pos=6524637;
   Y1BD(Vexpr, Vlval);
   sf.pos=6524638;
   YaZq(Vexpr, 4);
  }
  else
  {
   sf.pos=6524639;
   Ve = Y4GO(NULL);
   sf.pos=6524640;
   if ((Vtoken->Vtype == 103))
   {
    sf.pos=6524641;
    YaZq(Ve, 38);
   }
   else {
   sf.pos=6524642;
 if ((Vtoken->Vtype == 104))
   {
    sf.pos=6524643;
    YaZq(Ve, 39);
   }
   else
   {
    sf.pos=6524644;
    YaZq(Ve, 40);
   }
   }
   sf.pos=6524645;
   Yfkd(Ve, Vexpr);
   sf.pos=6524646;
   YPfx(Ve, Vright);
   sf.pos=6524647;
   Y4_i(Ve, Vtoken->VzuiPos);
   sf.pos=6524648;
   Vexpr = Ve;
  }
  }
Y7uQ:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=6524649;
 }
 sf.pos=6524650;
 r = Vexpr;
Yn8i:
 topFrame = sf.prev;
 return r;
}
YnZD *YV4G(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *VpreExpr = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vnext = 0;
 YnZD *VpostExpr = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9182900;
 Vtoken = Y_PN(Ain);
 sf.pos=9182901;
 if (((Vtoken->Vtype == 101) || (Vtoken->Vtype == 99)))
 {
  sf.pos=9182902;
  if ((Vtoken->Vtype == 101))
  {
   sf.pos=9182903;
   VpreExpr = YaZq(Y4GO(NULL), 28);
  }
  else
  {
   sf.pos=9182904;
   VpreExpr = YaZq(Y4GO(NULL), 29);
  }
  sf.pos=9182905;
  Y4_i(VpreExpr, Vtoken->VzuiPos);
 }
 else
 {
  sf.pos=9182906;
  YH7I(Ain, Vtoken);
 }
 sf.pos=9182907;
 Vexpr = YTtO(Ain);
 sf.pos=9182908;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=9182909;
  r = Vexpr;
  rt = 1;
  goto Y4JN;
 }
 sf.pos=9182910;
 if ((VpreExpr != NULL))
 {
  sf.pos=9182911;
  YPfx(VpreExpr, Vexpr);
  sf.pos=9182912;
  Vexpr = VpreExpr;
 }
 sf.pos=9182913;
 Vtoken = Y_PN(Ain);
 sf.pos=9182914;
 if ((Vtoken->Vtype == 2))
 {
  sf.pos=9182915;
  Vnext = Y_PN(Ain);
  sf.pos=9182916;
  if ((Vnext->Vtype == 101))
  {
   sf.pos=9182917;
   YdIu(Vnext, ((Tc*)&Yy5o));
   sf.pos=9182918;
   Vtoken = Vnext;
  }
  else {
  sf.pos=9182919;
 if ((Vnext->Vtype == 99))
  {
   sf.pos=9182920;
   YdIu(Vnext, ((Tc*)&YN8o));
   sf.pos=9182921;
   Vtoken = Vnext;
  }
  else
  {
   sf.pos=9182922;
   YH7I(Ain, Vnext);
  }
  }
 }
 sf.pos=9182923;
 if (((Vtoken->Vtype == 101) || (Vtoken->Vtype == 99)))
 {
  sf.pos=9182924;
  VpostExpr = Y4GO(NULL);
  sf.pos=9182925;
  if ((Vtoken->Vtype == 101))
  {
   sf.pos=9182926;
   YaZq(VpostExpr, 30);
  }
  else
  {
   sf.pos=9182927;
   YaZq(VpostExpr, 31);
  }
  sf.pos=9182928;
  Y4_i(VpostExpr, Vtoken->VzuiPos);
  sf.pos=9182929;
  YPfx(VpostExpr, Vexpr);
  sf.pos=9182930;
  Vexpr = VpostExpr;
 }
 else
 {
  sf.pos=9182931;
  YH7I(Ain, Vtoken);
 }
 sf.pos=9182932;
 r = Vexpr;
Y4JN:
 topFrame = sf.prev;
 return r;
}
YnZD *YTtO(Y7Sj *Ain) {
 Te VexprType;
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3094700;
 Vtoken = Y_PN(Ain);
 sf.pos=3094701;
 VexprType = 68;
 sf.pos=3094702;
 if (((Vtoken->Vtype == 98) && !((((YksM(Ain)->Vtype == 21) && isdigit(ZstringGetChar(YksM(Ain)->Vvalue, 0)))))))
 {
  sf.pos=3094703;
  VexprType = 24;
 }
 else {
 sf.pos=3094704;
 if ((Vtoken->Vtype == 132))
 {
  sf.pos=3094705;
  VexprType = 25;
 }
 else {
 sf.pos=3094706;
 if ((Vtoken->Vtype == 102))
 {
  sf.pos=3094707;
  VexprType = 26;
 }
 else {
 sf.pos=3094708;
 if ((Vtoken->Vtype == 109))
 {
  sf.pos=3094709;
  VexprType = 27;
 }
 }}}
 sf.pos=3094710;
 if ((VexprType == 68))
 {
  sf.pos=3094711;
  YH7I(Ain, Vtoken);
  sf.pos=3094712;
  Vexpr = YcvY(Ain);
 }
 else
 {
  sf.pos=3094713;
  Ve = YcvY(Ain);
  sf.pos=3094714;
  if ((YmTi(Ve) == 68))
  {
   sf.pos=3094715;
   r = Ve;
   rt = 1;
   goto YjH5;
  }
  sf.pos=3094716;
  Vexpr = YPfx(YxDV(VexprType, Vtoken->VzuiPos), Ve);
YjH5:
  if (rt) goto YypN;
 }
 sf.pos=3094717;
 r = Vexpr;
YypN:
 topFrame = sf.prev;
 return r;
}
YnZD *YcvY(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4453500;
 Vexpr = Y1cv(Ain);
 sf.pos=4453501;
 if ((YmTi(Vexpr) == 68))
 {
  sf.pos=4453502;
  r = Vexpr;
  rt = 1;
  goto Y4_8;
 }
 sf.pos=4453503;
 r = Y3lj(Vexpr, Ain, 2);
Y4_8:
 topFrame = sf.prev;
 return r;
}
YnZD *Y1cv(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vright = 0;
 Yev8 *VcloseToken = 0;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9212200;
 Vtoken = Y_PN(Ain);
 sf.pos=9212201;
 if ((Vtoken->Vtype == 90))
 {
  sf.pos=9212202;
  Y5bl(Ain);
  sf.pos=9212203;
  Vright = YUWY(Ain);
  sf.pos=9212204;
  if ((YmTi(Vright) == 68))
  {
   sf.pos=9212205;
   r = Vright;
   rt = 1;
   goto YBwR;
  }
  sf.pos=9212206;
  Y5bl(Ain);
  sf.pos=9212207;
  VcloseToken = Y_PN(Ain);
  sf.pos=9212208;
  if ((VcloseToken->Vtype != 91))
  {
   sf.pos=9212209;
   YdIu(Vtoken, ((Tc*)&Y0GX));
  }
  sf.pos=9212210;
  if ((ZListFind((Tl*)(t0 = ZnewList((Tt*)&MZui__EExprType__T, 12), ZLap((Tl*)t0, (Tz)(Ti)5), ZLap((Tl*)t0, (Tz)(Ti)6), ZLap((Tl*)t0, (Tz)(Ti)11), ZLap((Tl*)t0, (Tz)(Ti)12), ZLap((Tl*)t0, (Tz)(Ti)7), ZLap((Tl*)t0, (Tz)(Ti)8), ZLap((Tl*)t0, (Tz)(Ti)9), ZLap((Tl*)t0, (Tz)(Ti)10), ZLap((Tl*)t0, (Tz)(Ti)2), ZLap((Tl*)t0, (Tz)(Ti)3), ZLap((Tl*)t0, (Tz)(Ti)4), ZLap((Tl*)t0, (Tz)(Ti)1)), (Tz)(Ti)YmTi(Vright))>= 0))
  {
   sf.pos=9212211;
   Vexpr = Vright;
  }
  else
  {
   sf.pos=9212212;
   Vexpr = YxDV(32, Vtoken->VzuiPos);
   sf.pos=9212213;
   YPfx(Vexpr, Vright);
  }
YBwR:
  if (rt) goto YCwv;
 }
 else
 {
  sf.pos=9212214;
  YH7I(Ain, Vtoken);
  sf.pos=9212215;
  Vexpr = Yc4G(Ain);
 }
 sf.pos=9212216;
 r = Vexpr;
YCwv:
 topFrame = sf.prev;
 return r;
}
YnZD *Yc4G(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vexpr = 0;
 YXCg *Vstmt = 0;
 Yev8 *Vt = 0;
 YYIi *Vdecl = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1080700;
 Vtoken = Y_PN(Ain);
 sf.pos=1080701;
 switch (Vtoken->Vtype)
 {
 case 13:
  {
   sf.pos=1080702;
   Vexpr = YM_T(YxDV(5, Vtoken->VzuiPos), Vtoken->Vvalue);
    break;
  }
 case 14:
  {
   sf.pos=1080703;
   Vexpr = YOXc(Vtoken, Ain);
    break;
  }
 case 6:
  {
   sf.pos=1080704;
   Vexpr = YxDV(6, Vtoken->VzuiPos);
    break;
  }
 case 43:
  {
   sf.pos=1080705;
   Vexpr = YxDV(63, Vtoken->VzuiPos);
    break;
  }
 case 44:
  {
   sf.pos=1080706;
   Vexpr = YxDV(64, Vtoken->VzuiPos);
    break;
  }
 case 45:
  {
   sf.pos=1080707;
   Vexpr = YxDV(65, Vtoken->VzuiPos);
    break;
  }
 case 7:
  {
   sf.pos=1080708;
   Vexpr = YxDV(11, Vtoken->VzuiPos);
    break;
  }
 case 8:
  {
   sf.pos=1080709;
   Vexpr = YxDV(12, Vtoken->VzuiPos);
    break;
  }
 case 53:
  {
   sf.pos=1080710;
   Vexpr = YsQE(Vtoken, Ain);
    break;
  }
 case 10:
  {
   sf.pos=1080711;
   Vexpr = YxDV(7, Vtoken->VzuiPos);
    break;
  }
 case 9:
  {
   sf.pos=1080712;
   Vexpr = YxDV(8, Vtoken->VzuiPos);
    break;
  }
 case 11:
  {
   sf.pos=1080713;
   Vexpr = YxDV(9, Vtoken->VzuiPos);
    break;
  }
 case 12:
  {
   sf.pos=1080714;
   Vexpr = YxDV(10, Vtoken->VzuiPos);
    break;
  }
 case 15:
  {
   Ti Vval;
   sf.pos=1080715;
   Vval = ZstringGetChar(Vtoken->Vvalue, 0);
   sf.pos=1080716;
   Vexpr = Ypk4(YxDV(2, Vtoken->VzuiPos), Vval);
    break;
  }
 case 97:
  {
   sf.pos=1080717;
   Vexpr = YqGb(Ain, Y_PN(Ain));
   sf.pos=1080718;
   if ((YmTi(Vexpr) == 1))
   {
    sf.pos=1080719;
    YLsU(YjUS(Vexpr), 1);
   }
   else
   {
    sf.pos=1080720;
    YdIu(Vtoken, ((Tc*)&YVlJ));
   }
    break;
  }
 case 105:
  {
   sf.pos=1080721;
   Vexpr = YqGb(Ain, Y_PN(Ain));
   sf.pos=1080722;
   if ((YmTi(Vexpr) == 1))
   {
    sf.pos=1080723;
    YuRa(YjUS(Vexpr), 1);
   }
   else
   {
    sf.pos=1080724;
    YdIu(Vtoken, ((Tc*)&YWlJ));
   }
    break;
  }
 case 98:
  {
   sf.pos=1080725;
   Vexpr = YqGb(Ain, Y_PN(Ain));
   sf.pos=1080726;
   if ((YmTi(Vexpr) == 2))
   {
    sf.pos=1080727;
    Ypk4(Vexpr, -(YsEM(Vexpr)));
   }
   else {
   sf.pos=1080728;
 if ((YmTi(Vexpr) == 3))
   {
    sf.pos=1080729;
    Ypk4(Vexpr, -(YsEM(Vexpr)));
    sf.pos=1080730;
    YaZq(Vexpr, 2);
   }
   else {
   sf.pos=1080731;
 if ((YmTi(Vexpr) == 4))
   {
    sf.pos=1080732;
    Y1BD(Vexpr, -(YAcd(Vexpr)));
   }
   else
   {
    sf.pos=1080733;
    YdIu(Vtoken, ((Tc*)&YZ3P));
   }
   }}
    break;
  }
 case 21:
 case 56:
  {
   sf.pos=1080734;
   Vexpr = YqGb(Ain, Vtoken);
    break;
  }
 case 94:
 case 95:
  {
   sf.pos=1080735;
   Vexpr = YZiK(Vtoken, Ain);
    break;
  }
 case 92:
  {
   sf.pos=1080736;
   Vexpr = YblP(Vtoken, Ain);
    break;
  }
 case 38:
 case 37:
 case 39:
  {
   sf.pos=1080737;
   Vstmt = YGqS(Vtoken, Ain, (8 + 32));
   sf.pos=1080738;
   Vt = Y_PN(Ain);
   sf.pos=1080739;
   if ((Vt->Vtype != 93))
   {
    sf.pos=1080740;
    YdIu(Vt, ((Tc*)&YnMg));
   }
   sf.pos=1080741;
   Vdecl = YjGb(Vstmt);
   sf.pos=1080742;
   Vexpr = Y35a(YxDV(18, Vtoken->VzuiPos), Vdecl);
    break;
  }
 case 55:
  {
   sf.pos=1080743;
   Vexpr = Y9sl(Ain);
    break;
  }
 case 83:
  {
   sf.pos=1080744;
   YdIu(Vtoken, ((Tc*)&YOm7));
  }
 default:
  {
   sf.pos=1080745;
   YH7I(Ain, Vtoken);
   sf.pos=1080746;
   Vexpr = YxDV(68, Vtoken->VzuiPos);
    break;
  }
 }
 sf.pos=1080747;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YnZD *YOXc(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vresult = 0;
 Yev8 *Vtoken = 0;
 YnZD *VsExpr = 0;
 YnZD *Ve = 0;
 Tl *Vargs = NULL;
 YjUM *Vw = 0;
 YnZD *Varg = 0;
 YnZD *Vexpr = 0;
 YnZD *VmethodName = 0;
 Y_1n *Vmethod = 0;
 YnZD *Vcall = 0;
 YnZD *Ve1 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7167500;
 Vtoken = AstartToken;
 sf.pos=7167501;
 while (1)
 {
  Tb VgotSpace;
  Tb VgotMinus;
  sf.pos=7167502;
  if ((ZbyteStringSize(Vtoken->Vvalue) != 0))
  {
   sf.pos=7167503;
   VsExpr = YM_T(YxDV(5, Vtoken->VzuiPos), Vtoken->Vvalue);
   sf.pos=7167504;
   if ((Vresult == NULL))
   {
    sf.pos=7167505;
    Vresult = VsExpr;
   }
   else
   {
    sf.pos=7167506;
    Ve = YxDV(41, Vtoken->VzuiPos);
    sf.pos=7167507;
    Yfkd(Ve, Vresult);
    sf.pos=7167508;
    YPfx(Ve, VsExpr);
    sf.pos=7167509;
    Vresult = Ve;
   }
  }
  sf.pos=7167510;
  if ((Vtoken->Vtype != 14))
  {
   rt = 2;
   goto Y1BK;
  }
  Vargs = NULL;
  sf.pos=7167511;
  Vw = Za(sizeof(YjUM));
  VgotSpace = 0;
  VgotMinus = 0;
  sf.pos=7167512;
  while (1)
  {
   Ti Vc;
   sf.pos=7167513;
   Vc = YGBv(Ain);
   sf.pos=7167514;
   if (((Vc == 32) && (YKJQ(Vw) == 0)))
   {
    rt = 2;
    goto Y4Zh;
   }
   sf.pos=7167515;
   YjUM__Ydti(Vw, Vc);
   sf.pos=7167516;
   if ((VgotSpace && (((isdigit(Vc) || isalpha(Vc)) || (((Vc != 32) && VgotMinus))))))
   {
    sf.pos=7167517;
    if (VgotMinus)
    {
     sf.pos=7167518;
     YPmF(Ain, Y6jW(Vw));
    }
    sf.pos=7167519;
    YPmF(Ain, Y6jW(Vw));
    sf.pos=7167520;
    Y6jW(Vw);
    sf.pos=7167521;
    Varg = YM_T(YaZq(Y4GO(NULL), 5), YbNW(Vw));
    sf.pos=7167522;
    Vargs = ZnewList((Tt*)&YnZD__T, 1); ZLap((Tl*)Vargs, (Tz)(void*)Varg);
    rt = 2;
    goto Y4Zh;
   }
   else {
   sf.pos=7167523;
 if (((Vc == 32) && !(VgotSpace)))
   {
    sf.pos=7167524;
    VgotSpace = 1;
   }
   else {
   sf.pos=7167525;
 if ((((Vc == 45) && VgotSpace) && !(VgotMinus)))
   {
    sf.pos=7167526;
    VgotMinus = 1;
   }
   else {
   sf.pos=7167527;
 if ((((!(isdigit(Vc)) && !(isalpha(Vc))) && (Vc != 45)) && (Vc != 46)))
   {
    sf.pos=7167528;
    while ((YKJQ(Vw) > 0))
    {
     sf.pos=7167529;
     YPmF(Ain, Y6jW(Vw));
    sf.pos=7167530;
    }
    rt = 2;
    goto Y4Zh;
   }
   }}}
Y4Zh:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=7167531;
  }
  sf.pos=7167532;
  Vexpr = YUWY(Ain);
  sf.pos=7167533;
  VmethodName = Yfkd(Y4_i(YaZq(Y4GO(NULL), 20), Y74i(Vexpr)), Vexpr);
  sf.pos=7167534;
  YMou(YRE8(Y4_i(YaZq(YBJ7(VmethodName), 1), Vtoken->VzuiPos)), ((Tc*)&Y318));
  sf.pos=7167535;
  Vmethod = YLx8(NULL);
  sf.pos=7167536;
  Y_BE(Vmethod, Y74i(Vexpr));
  sf.pos=7167537;
  if ((Vargs != NULL))
  {
   sf.pos=7167538;
   YnYS(Vmethod, Vargs);
  }
  sf.pos=7167539;
  YOo6(Vmethod, VmethodName);
  sf.pos=7167540;
  Vcall = YoWy(Y4_i(YaZq(Y4GO(NULL), 16), Y74i(Vexpr)), Vmethod);
  sf.pos=7167541;
  if ((Vresult == NULL))
  {
   sf.pos=7167542;
   Vresult = Vcall;
  }
  else
  {
   sf.pos=7167543;
   Ve1 = YxDV(41, Vtoken->VzuiPos);
   sf.pos=7167544;
   Yfkd(Ve1, Vresult);
   sf.pos=7167545;
   YPfx(Ve1, Vcall);
   sf.pos=7167546;
   Vresult = Ve1;
  }
  sf.pos=7167547;
  YBch(Ain);
  sf.pos=7167548;
  Vtoken = Y_PN(Ain);
  sf.pos=7167549;
  if ((Vtoken->Vtype != 91))
  {
   sf.pos=7167550;
   YdIu(Vtoken, ((Tc*)&Y0GX));
   sf.pos=7167551;
   if ((Vtoken->Vtype == 13))
   {
    rt = 2;
    goto YIwm;
   }
YIwm:
   if (rt) goto Y1BK;
  }
  sf.pos=7167552;
  YPmF(Ain, 34);
  sf.pos=7167553;
  Vtoken = Y_PN(Ain);
Y1BK:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=7167554;
 }
 sf.pos=7167555;
 r = Vresult;
 topFrame = sf.prev;
 return r;
}
YnZD *YblP(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vfirst = 0;
 Yev8 *Vid = 0;
 Yev8 *VafterId = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2133900;
 Vfirst = Y_PN(Ain);
 sf.pos=2133901;
 if (YfTZ(Vfirst))
 {
  sf.pos=2133902;
  Vid = Y_PN(Ain);
 }
 else
 {
  sf.pos=2133903;
  Vid = Vfirst;
  sf.pos=2133904;
  Vfirst = NULL;
 }
 sf.pos=2133905;
 VafterId = YksM(Ain);
 sf.pos=2133906;
 YH7I(Ain, Vid);
 sf.pos=2133907;
 if ((Vfirst != NULL))
 {
  sf.pos=2133908;
  YH7I(Ain, Vfirst);
 }
 sf.pos=2133909;
 if (((((Vid->Vtype == 21) && (VafterId->Vtype == 84))) || (Vid->Vtype == 93)))
 {
  sf.pos=2133910;
  r = YKtr(AstartToken, Ain);
  rt = 1;
  goto YbOY;
 }
 sf.pos=2133911;
 r = YdwE(AstartToken, Ain);
YbOY:
 topFrame = sf.prev;
 return r;
}
YnZD *YKtr(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *VinitExpr = 0;
 Yev8 *Vtoken = 0;
 Yev8 *Vcolon = 0;
 YnZD *Vval = 0;
 YJFN *Vitem = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=187300;
 Y5bl(Ain);
 sf.pos=187301;
 VinitExpr = YxDV(15, AstartToken->VzuiPos);
 sf.pos=187302;
 Vtoken = Y_PN(Ain);
 sf.pos=187303;
 while ((Vtoken->Vtype != 93))
 {
  sf.pos=187304;
  if ((Vtoken->Vtype == 1))
  {
   sf.pos=187305;
   YdIu(Vtoken, ((Tc*)&YnMg));
   sf.pos=187306;
   YdIu(AstartToken, ((Tc*)&YhDZ));
   rt = 2;
   goto YtQ9;
  }
  sf.pos=187307;
  if ((Vtoken->Vtype != 21))
  {
   sf.pos=187308;
   YdIu(Vtoken, ((Tc*)&YIYT));
  }
  sf.pos=187309;
  YuRk(Ain);
  sf.pos=187310;
  Vcolon = Y_PN(Ain);
  sf.pos=187311;
  if ((Vcolon->Vtype != 84))
  {
   sf.pos=187312;
   YdIu(Vtoken, ((Tc*)&YNoT));
  }
  sf.pos=187313;
  YBch(Ain);
  sf.pos=187314;
  Vval = YUWY(Ain);
  sf.pos=187315;
  Vitem = YNzh(VinitExpr);
  sf.pos=187316;
  YXqm(Vitem, Vtoken->Vvalue);
  sf.pos=187317;
  YP1z(Vitem, Vval);
  sf.pos=187318;
  Vtoken = Y_PN(Ain);
  sf.pos=187319;
  if ((YfTZ(Vtoken) && (YksM(Ain)->Vtype == 82)))
  {
   sf.pos=187320;
   YdIu(Vtoken, ((Tc*)&Ycz6));
   sf.pos=187321;
   Vtoken = Y_PN(Ain);
  }
  sf.pos=187322;
  if ((Vtoken->Vtype == 82))
  {
   sf.pos=187323;
   YBch(Ain);
  }
  else {
  sf.pos=187324;
 if (((Vtoken->Vtype != 93) && (Y6qU(Ain)->Vtype != 93)))
  {
   sf.pos=187325;
   YdIu(Vtoken, ((Tc*)&Y2hw));
  }
  }
  sf.pos=187326;
  Vtoken = Y_PN(Ain);
YtQ9:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=187327;
 }
 sf.pos=187328;
 r = VinitExpr;
 topFrame = sf.prev;
 return r;
}
YnZD *YdwE(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Y7Np *Vmethod = 0;
 YnZD *Vright = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vexpr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9058900;
 YzLT(Ain);
 sf.pos=9058901;
 Vmethod = YWVR(NULL);
 sf.pos=9058902;
 YQ6k(Vmethod, Ain, 1, 126);
 sf.pos=9058903;
 YzLT(Ain);
 sf.pos=9058904;
 Vright = YUWY(Ain);
 sf.pos=9058905;
 YI0V(Vmethod, Vright);
 sf.pos=9058906;
 YzLT(Ain);
 sf.pos=9058907;
 Vtoken = Y_PN(Ain);
 sf.pos=9058908;
 if ((Vtoken->Vtype != 93))
 {
  sf.pos=9058909;
  YdIu(Vtoken, ((Tc*)&YnMg));
  sf.pos=9058910;
  YdIu(AstartToken, ((Tc*)&YhDZ));
 }
 sf.pos=9058911;
 Vexpr = YCI5(YxDV(19, AstartToken->VzuiPos), Vmethod);
 sf.pos=9058912;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YnZD *YqGb(Y7Sj *Ain, Yev8 *Atoken) {
 Ti Vc;
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Tc *Vv = NULL;
 Tc *Zf3 = NULL;
 Tc *Vv1 = NULL;
 Tc *Zf31 = NULL;
 Tc *Zf32 = NULL;
 Y1p4 *Vid = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7471800;
 Vc = ZstringGetChar(Atoken->Vvalue, 0);
 sf.pos=7471801;
 if (((Vc >= 48) && (Vc <= 57)))
 {
  Tu Vvalue;
  Tf Vfvalue;
  Tb VisFloat;
  Vvalue = 0;
  Vfvalue = 0;
  VisFloat = 0;
  sf.pos=7471802;
  if ((((Vc == 48) && (ZstringSize(Atoken->Vvalue) > 1)) && (((ZstringGetChar(Atoken->Vvalue, 1) == 120) || (ZstringGetChar(Atoken->Vvalue, 1) == 88)))))
  {
   sf.pos=7471803;
   if ((ZstringSize(Atoken->Vvalue) == 2))
   {
    sf.pos=7471804;
    YdIu(Atoken, ZcS(((Tc*)&YJgb), Atoken->Vvalue));
   }
   sf.pos=7471805;
   Vv = ZstringSlice(Atoken->Vvalue, 2, -1, 0);
   sf.pos=7471806;
   {
    Ti Vcc;
    Tfs iZf3;
    Zf3 = Vv;
    ZforStringNew(Zf3, &iZf3);
    for (ZforStringGetInt(&iZf3, &Vcc); ZforStringContInt(&iZf3); ZforStringNextInt(&iZf3, &Vcc)) {
    sf.pos=7471807;
    if (((!(isxdigit(Vcc)) && (Vcc != 39)) && (Vcc != 95)))
    {
     sf.pos=7471808;
     YdIu(Atoken, ZcS(((Tc*)&Ydlx), Atoken->Vvalue));
     rt = 2;
     goto Yu35;
    }
Yu35:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=7471809;
    }
   }
   sf.pos=7471810;
   Vvalue = ZstringQuotedHexToInt(Vv, 1, 0);
  }
  else {
  sf.pos=7471811;
 if ((((Vc == 48) && (ZstringSize(Atoken->Vvalue) > 1)) && (((ZstringGetChar(Atoken->Vvalue, 1) == 98) || (ZstringGetChar(Atoken->Vvalue, 1) == 66)))))
  {
   sf.pos=7471812;
   Vv1 = ZstringSlice(Atoken->Vvalue, 2, -1, 0);
   sf.pos=7471813;
   if ((ZstringSize(Atoken->Vvalue) == 2))
   {
    sf.pos=7471814;
    YdIu(Atoken, ZcS(((Tc*)&YJgb), Atoken->Vvalue));
   }
   sf.pos=7471815;
   {
    Ti Vcc;
    Tfs iZf31;
    Zf31 = Vv1;
    ZforStringNew(Zf31, &iZf31);
    for (ZforStringGetInt(&iZf31, &Vcc); ZforStringContInt(&iZf31); ZforStringNextInt(&iZf31, &Vcc)) {
    sf.pos=7471816;
    if (((((Vcc != 48) && (Vcc != 49)) && (Vcc != 39)) && (Vcc != 95)))
    {
     sf.pos=7471817;
     YdIu(Atoken, ZcS(((Tc*)&YorS), Atoken->Vvalue));
     rt = 2;
     goto YzBE;
    }
YzBE:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=7471818;
    }
   }
   sf.pos=7471819;
   Vvalue = ZstringQuotedBinToInt(Vv1, 1, 0);
  }
  else
  {
   sf.pos=7471820;
   {
    Ti Vcc;
    Tfs iZf32;
    Zf32 = Atoken->Vvalue;
    ZforStringNew(Zf32, &iZf32);
    for (ZforStringGetInt(&iZf32, &Vcc); ZforStringContInt(&iZf32); ZforStringNextInt(&iZf32, &Vcc)) {
    sf.pos=7471821;
    if ((((Vcc == 46) || (Vcc == 101)) || (Vcc == 69)))
    {
     sf.pos=7471822;
     VisFloat = 1;
     rt = 2;
     goto YVLT;
    }
    sf.pos=7471823;
    if (((!(isdigit(Vcc)) && (Vcc != 39)) && (Vcc != 95)))
    {
     sf.pos=7471824;
     YdIu(Atoken, ZcS(((Tc*)&YUOY), Atoken->Vvalue));
     rt = 2;
     goto YVLT;
    }
YVLT:
    if (rt == 2) { rt &= 1; break; }
    sf.pos=7471825;
    }
   }
   sf.pos=7471826;
   if (VisFloat)
   {
    Ti Vlen;
    Vlen = 0;
    sf.pos=7471827;
    Vfvalue = Zstring2float(Atoken->Vvalue, &(Vlen));
    sf.pos=7471828;
    if ((Vlen < ZstringSize(Atoken->Vvalue)))
    {
     sf.pos=7471829;
     YdIu(Atoken, ZcS(((Tc*)&YG2L), Atoken->Vvalue));
    }
   }
   else
   {
    sf.pos=7471830;
    Vvalue = ZstringQuotedToInt(Atoken->Vvalue, 1, 0);
   }
  }
  }
  sf.pos=7471831;
  if (VisFloat)
  {
   sf.pos=7471832;
   Vexpr = Y1BD(YxDV(4, Atoken->VzuiPos), Vfvalue);
  }
  else
  {
   Ti Vv;
   sf.pos=7471833;
   Vv = Vvalue;
   sf.pos=7471834;
   Vexpr = Ypk4(YxDV(3, Atoken->VzuiPos), Vv);
  }
 }
 else
 {
  sf.pos=7471835;
  Vexpr = YxDV(1, Atoken->VzuiPos);
  sf.pos=7471836;
  Vid = YRE8(Vexpr);
  sf.pos=7471837;
  YMou(Vid, Atoken->Vvalue);
 }
 sf.pos=7471838;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YnZD *YsQE(Yev8 *AstartToken, Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vexpr = 0;
 Tl *Vargs = NULL;
 Y_1n *Vmethod = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2304300;
 Vtoken = Y_PN(Ain);
 sf.pos=2304301;
 if ((Vtoken->Vtype != 90))
 {
  sf.pos=2304302;
  YH7I(Ain, Vtoken);
  sf.pos=2304303;
  Vexpr = YxDV(1, AstartToken->VzuiPos);
  sf.pos=2304304;
  YMou(YRE8(Vexpr), ((Tc*)&YZom));
 }
 else
 {
  sf.pos=2304305;
  Y5bl(Ain);
  sf.pos=2304306;
  Vargs = YZnz(Ain, NULL, 2);
  sf.pos=2304307;
  Vtoken = Y_PN(Ain);
  sf.pos=2304308;
  if ((Vtoken->Vtype == 3))
  {
   sf.pos=2304309;
   Vtoken = Y_PN(Ain);
  }
  else {
  sf.pos=2304310;
 if (((Vtoken->Vtype == 2) && Vtoken->VhasComment))
  {
   sf.pos=2304311;
   Vtoken = Y_PN(Ain);
  }
  }
  sf.pos=2304312;
  if ((Vtoken->Vtype != 91))
  {
   sf.pos=2304313;
   if ((Vtoken->Vtype == 2))
   {
    sf.pos=2304314;
    YdIu(Vtoken, ((Tc*)&YA_q));
   }
   else
   {
    sf.pos=2304315;
    YdIu(Vtoken, ZcS(((Tc*)&YhYk), Zenum2string(CToken__EType, Vtoken->Vtype)));
   }
  }
  sf.pos=2304316;
  Vmethod = YLx8(NULL);
  sf.pos=2304317;
  Y_BE(Vmethod, AstartToken->VzuiPos);
  sf.pos=2304318;
  YnYS(Vmethod, Vargs);
  sf.pos=2304319;
  Vexpr = YxDV(17, AstartToken->VzuiPos);
  sf.pos=2304320;
  YoWy(Vexpr, Vmethod);
 }
 sf.pos=2304321;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YnZD *YZiK(Yev8 *AstartToken, Y7Sj *Ain) {
 Tb VisL;
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *VfirstExpr = 0;
 Tl *VitemList = NULL;
 YnZD *VlistExpr = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1197300;
 VisL = (AstartToken->Vtype == 95);
 sf.pos=1197301;
 Vtoken = Y6qU(Ain);
 sf.pos=1197302;
 if ((Vtoken->Vtype == 84))
 {
  Tb Vwrong;
  sf.pos=1197303;
  Vtoken = Y_PN(Ain);
  Vwrong = 0;
  sf.pos=1197304;
  if ((Vtoken->Vtype != 84))
  {
   sf.pos=1197305;
   Vwrong = 1;
   sf.pos=1197306;
   Vtoken = Y_PN(Ain);
  }
  sf.pos=1197307;
  Vtoken = YksM(Ain);
  sf.pos=1197308;
  if ((Vwrong || (Vtoken->Vtype != 96)))
  {
   sf.pos=1197309;
   YdIu(Vtoken, ((Tc*)&YC09));
  }
  sf.pos=1197310;
  r = YvpI(Ain, NULL, VisL);
  rt = 1;
  goto YgbV;
 }
 sf.pos=1197311;
 Y5bl(Ain);
 sf.pos=1197312;
 VfirstExpr = YUWY(Ain);
 sf.pos=1197313;
 Vtoken = Y6qU(Ain);
 sf.pos=1197314;
 if ((Vtoken->Vtype == 84))
 {
  sf.pos=1197315;
  r = YvpI(Ain, VfirstExpr, VisL);
  rt = 1;
  goto YgbV;
 }
 sf.pos=1197316;
 if (VisL)
 {
  sf.pos=1197317;
  YdIu(AstartToken, ((Tc*)&Yigf));
 }
 sf.pos=1197318;
 VitemList = YZnz(Ain, VfirstExpr, 1);
 sf.pos=1197319;
 Y5bl(Ain);
 sf.pos=1197320;
 Vtoken = Y_PN(Ain);
 sf.pos=1197321;
 if ((Vtoken->Vtype != 96))
 {
  sf.pos=1197322;
  YdIu(Vtoken, ZcS(((Tc*)&Y9_n), Zenum2string(CToken__EType, Vtoken->Vtype)));
 }
 sf.pos=1197323;
 VlistExpr = YxDV(13, Vtoken->VzuiPos);
 sf.pos=1197324;
 YKTm(VlistExpr, VitemList);
 sf.pos=1197325;
 r = VlistExpr;
YgbV:
 topFrame = sf.prev;
 return r;
}
YnZD *YvpI(Y7Sj *Ain, YnZD *AfirstKey, Tb AisL) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *VdictExpr = 0;
 YnZD *Vkey = 0;
 YnZD *Vvalue = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2314900;
 if ((AfirstKey == NULL))
 {
  sf.pos=2314901;
  Y5bl(Ain);
 }
 sf.pos=2314902;
 Vtoken = YksM(Ain);
 sf.pos=2314903;
 VdictExpr = YxDV(14, Vtoken->VzuiPos);
 sf.pos=2314904;
 if (AisL)
 {
  sf.pos=2314905;
  Y_Jm(VdictExpr, 1);
 }
 sf.pos=2314906;
 if ((Vtoken->Vtype != 96))
 {
  Tb VuseFirstKey;
  sf.pos=2314907;
  VuseFirstKey = (AfirstKey != NULL);
  sf.pos=2314908;
  while (1)
  {
   Vkey = 0;
   sf.pos=2314909;
   if (VuseFirstKey)
   {
    sf.pos=2314910;
    VuseFirstKey = 0;
    sf.pos=2314911;
    Vkey = AfirstKey;
   }
   else
   {
    sf.pos=2314912;
    Vkey = YUWY(Ain);
   }
   sf.pos=2314913;
   Y5bl(Ain);
   sf.pos=2314914;
   Vtoken = Y_PN(Ain);
   sf.pos=2314915;
   if ((Vtoken->Vtype != 84))
   {
    sf.pos=2314916;
    YdIu(Vtoken, ((Tc*)&Y43V));
    sf.pos=2314917;
    if ((Vtoken->Vtype == 1))
    {
     rt = 2;
     goto YClx;
    }
    sf.pos=2314918;
    if ((Vtoken->Vtype == 96))
    {
     sf.pos=2314919;
     YH7I(Ain, Vtoken);
     rt = 2;
     goto YClx;
    }
YClx:
    if (rt) goto YTBf;
   }
   sf.pos=2314920;
   YzLT(Ain);
   sf.pos=2314921;
   Vvalue = YUWY(Ain);
   sf.pos=2314922;
   YsFD(YdT0(YmCP(VdictExpr), Vkey), Vvalue);
   sf.pos=2314923;
   if ((Y6qU(Ain)->Vtype != 82))
   {
    sf.pos=2314924;
    if ((Y6qU(Ain)->Vtype == 96))
    {
     rt = 2;
     goto YzNQ;
    }
    sf.pos=2314925;
    YdIu(Vtoken, ((Tc*)&YhTQ));
YzNQ:
    if (rt) goto YTBf;
   }
   sf.pos=2314926;
   YuRk(Ain);
   sf.pos=2314927;
   Vtoken = Y_PN(Ain);
   sf.pos=2314928;
   if ((Y6qU(Ain)->Vtype == 96))
   {
    sf.pos=2314929;
    YBch(Ain);
    rt = 2;
    goto YTBf;
   }
   sf.pos=2314930;
   YzLT(Ain);
YTBf:
   if (rt == 2) { rt &= 1; break; }
  sf.pos=2314931;
  }
 }
 sf.pos=2314932;
 Y5bl(Ain);
 sf.pos=2314933;
 Vtoken = Y_PN(Ain);
 sf.pos=2314934;
 if ((Vtoken->Vtype != 96))
 {
  sf.pos=2314935;
  YdIu(Vtoken, ZcS(((Tc*)&Y9_n), Zenum2string(CToken__EType, Vtoken->Vtype)));
 }
 sf.pos=2314936;
 r = VdictExpr;
 topFrame = sf.prev;
 return r;
}
Tl *Ya1K(Y7Sj *Ain) {
 Zsf sf;
 Tl *r = 0;
 Tl *Vnames = NULL;
 Yev8 *Vtoken = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4108500;
 Vnames = ZnewList((Tt*)&YnZD__T, 0);
 sf.pos=4108501;
 ZLap((Tl*)Vnames, (Tz)(void*)YTKt(Ain, 0, 1));
 sf.pos=4108502;
 while (1)
 {
  sf.pos=4108503;
  if ((Y6qU(Ain)->Vtype != 82))
  {
   rt = 2;
   goto Ys7f;
  }
  sf.pos=4108504;
  Vtoken = Y_PN(Ain);
  sf.pos=4108505;
  if (((Vtoken->Vtype == 3) || (((Vtoken->Vtype == 2) && !(Vtoken->VhasComment)))))
  {
   sf.pos=4108506;
   YdIu(Vtoken, ((Tc*)&YJzF));
  }
  sf.pos=4108507;
  if ((Vtoken->Vtype != 82))
  {
   sf.pos=4108508;
   Vtoken = Y_PN(Ain);
  }
  sf.pos=4108509;
  YzLT(Ain);
  sf.pos=4108510;
  ZLap((Tl*)Vnames, (Tz)(void*)YTKt(Ain, 0, 1));
Ys7f:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=4108511;
 }
 sf.pos=4108512;
 r = Vnames;
 topFrame = sf.prev;
 return r;
}
YnZD *YTKt(Y7Sj *Ain, Tb AprefixOk, Tbs Awhat) {
 Zsf sf;
 YnZD *r = 0;
 Yev8 *Vtoken = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vnext = 0;
 Y1p4 *Vid = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8980500;
 Vtoken = Y_PN(Ain);
 sf.pos=8980501;
 if (((Vtoken->Vtype == 21) || (Vtoken->Vtype == 56)))
 {
  sf.pos=8980502;
  Vexpr = YqGb(Ain, Vtoken);
 }
 else {
 sf.pos=8980503;
 if (((Vtoken->Vtype == 97) || (Vtoken->Vtype == 105)))
 {
  Tb Vdollar;
  sf.pos=8980504;
  Vdollar = (Vtoken->Vtype == 97);
  sf.pos=8980505;
  Vnext = Y_PN(Ain);
  sf.pos=8980506;
  if ((Vnext->Vtype != 21))
  {
   sf.pos=8980507;
   YdIu(Vtoken, ZcS(((Tc*)&YCCu), Zenum2string(CToken__EType, Vnext->Vtype)));
  }
  else {
  sf.pos=8980508;
 if (!(AprefixOk))
  {
   sf.pos=8980509;
   YdIu(Vtoken, ZcS((((Vdollar) ? (((Tc*)&YK)) : (((Tc*)&YL)))), ((Tc*)&YCEd)));
  }
  }
  sf.pos=8980510;
  Vexpr = YxDV(1, Vtoken->VzuiPos);
  sf.pos=8980511;
  Vid = YMou(YRE8(Vexpr), Vnext->Vvalue);
  sf.pos=8980512;
  if (Vdollar)
  {
   sf.pos=8980513;
   YLsU(Vid, 1);
  }
  else
  {
   sf.pos=8980514;
   YuRa(Vid, 1);
  }
  sf.pos=8980515;
  Vtoken->Vvalue = Vnext->Vvalue;
 }
 else {
 sf.pos=8980516;
 if ((Vtoken->Vtype == 7))
 {
  sf.pos=8980517;
  Vexpr = YxDV(11, Vtoken->VzuiPos);
 }
 else {
 sf.pos=8980518;
 if ((Vtoken->Vtype == 8))
 {
  sf.pos=8980519;
  Vexpr = YxDV(12, Vtoken->VzuiPos);
 }
 else
 {
  sf.pos=8980520;
  if ((((Awhat) & 1)))
  {
   sf.pos=8980521;
   YdIu(Vtoken, ZcS(((Tc*)&YZDt), Vtoken->Vvalue));
  }
  else
  {
   sf.pos=8980522;
   YdIu(Vtoken, ZcS(((Tc*)&Yu2L), Zenum2string(CToken__EType, Vtoken->Vtype)));
  }
  sf.pos=8980523;
  Vexpr = YxDV(68, Vtoken->VzuiPos);
 }
 }}}
 sf.pos=8980524;
 r = Y3lj(Vexpr, Ain, Awhat);
 topFrame = sf.prev;
 return r;
}
Tb Y00A(YnZD *Aexpr) {
 Zsf sf;
 Tb r = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=751500;
 Ve = Aexpr;
 sf.pos=751501;
 while (Y8FL(Ve))
 {
  sf.pos=751502;
  Ve = Yre5(Ve);
 sf.pos=751503;
 }
 sf.pos=751504;
 if ((YmTi(Ve) == 1))
 {
  sf.pos=751505;
  r = YI8b(YjUS(Ve));
  rt = 1;
  goto Y_dH;
 }
 sf.pos=751506;
 r = 0;
Y_dH:
 topFrame = sf.prev;
 return r;
}
Tb YpO1(YnZD *Aexpr) {
 Zsf sf;
 Tb r = 0;
 YnZD *Ve = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4532200;
 Ve = Aexpr;
 sf.pos=4532201;
 while (Y8FL(Ve))
 {
  sf.pos=4532202;
  Ve = Yre5(Ve);
 sf.pos=4532203;
 }
 sf.pos=4532204;
 if ((YmTi(Ve) == 1))
 {
  sf.pos=4532205;
  r = YFAa(YjUS(Ve));
  rt = 1;
  goto Y_2_;
 }
 sf.pos=4532206;
 r = 0;
Y_2_:
 topFrame = sf.prev;
 return r;
}
void Ya8Z(Y7Sj *Ain, Tl *Atypes, Tb AitemNames) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 Yev8 *Vsecond = 0;
 Yev8 *Vthird = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6561000;
 Vtoken = Y_PN(Ain);
 sf.pos=6561001;
 if ((((Vtoken->Vtype != 133) && (Vtoken->Vtype != 110)) && (Vtoken->Vtype != 27)))
 {
  sf.pos=6561002;
  YH7I(Ain, Vtoken);
  sf.pos=6561003;
  YyoS(Ain, Atypes, AitemNames);
  sf.pos=6561004;
  Y5bl(Ain);
  sf.pos=6561005;
  Vtoken = Y_PN(Ain);
 }
 sf.pos=6561006;
 if (((Vtoken->Vtype == 110) || (Vtoken->Vtype == 27)))
 {
  sf.pos=6561007;
  Vsecond = Y77H(Vtoken);
  sf.pos=6561008;
  Vsecond->Vtype = 133;
  sf.pos=6561009;
  Y6ET(Vsecond->VzuiPos, (Y3kb(Vsecond->VzuiPos) + 1));
  sf.pos=6561010;
  if ((Vtoken->Vtype == 27))
  {
   sf.pos=6561011;
   Vthird = Y77H(Vsecond);
   sf.pos=6561012;
   Y6ET(Vthird->VzuiPos, (Y3kb(Vthird->VzuiPos) + 1));
   sf.pos=6561013;
   YH7I(Ain, Vthird);
  }
  sf.pos=6561014;
  YH7I(Ain, Vsecond);
  sf.pos=6561015;
  Vtoken->Vtype = 133;
 }
 sf.pos=6561016;
 if ((Vtoken->Vtype != 133))
 {
  sf.pos=6561017;
  YdIu(Vtoken, ((Tc*)&Y1BZ));
  sf.pos=6561018;
  YH7I(Ain, Vtoken);
 }
 topFrame = sf.prev;
 return;
}
void YyoS(Y7Sj *Ain, Tl *Atypes, Tb AitemNames) {
 Tb VdidFirst;
 Tb VfoundGives;
 Zsf sf;
 Yev8 *Vtoken = 0;
 YnZD *Vexpr = 0;
 YRBza *Vitem = 0;
 Yev8 *Vt = 0;
 YRBza *Vref = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 VdidFirst = 0;
 VfoundGives = 0;
 sf.pos=3692700;
 while (1)
 {
  sf.pos=3692701;
  Vtoken = Y_PN(Ain);
  sf.pos=3692702;
  if ((Vtoken->Vtype == 126))
  {
   sf.pos=3692703;
   YdIu(Vtoken, ((Tc*)&Yfdg));
   sf.pos=3692704;
   YzLT(Ain);
  }
  else {
  sf.pos=3692705;
 if ((YfTZ(Vtoken) && (YksM(Ain)->Vtype == 126)))
  {
   sf.pos=3692706;
   Vtoken = Y_PN(Ain);
   sf.pos=3692707;
   YzLT(Ain);
   sf.pos=3692708;
   VfoundGives = 1;
  }
  else
  {
   sf.pos=3692709;
   YH7I(Ain, Vtoken);
   sf.pos=3692710;
   Y5bl(Ain);
  }
  }
  sf.pos=3692711;
  Vexpr = YTKt(Ain, 0, 1);
  sf.pos=3692712;
  Vitem = Yz09(Y2b1(YLJs(Ya_p(NULL), 45), Y74i(Vexpr)), Vexpr);
  sf.pos=3692713;
  if ((Y6qU(Ain)->Vtype == 109))
  {
   sf.pos=3692714;
   YzLT(Ain);
   sf.pos=3692715;
   Vt = Y_PN(Ain);
   sf.pos=3692716;
   Vref = Y2b1(YE45(YLJs(Ya_p(NULL), 44), Vitem), Vt->VzuiPos);
   sf.pos=3692717;
   Vitem = Vref;
  }
  sf.pos=3692718;
  if (VfoundGives)
  {
   sf.pos=3692719;
   Y3HG(Vitem, 1);
  }
  sf.pos=3692720;
  ZLap((Tl*)Atypes, (Tz)(void*)Vitem);
  sf.pos=3692721;
  if ((AitemNames && (Y6qU(Ain)->Vtype == 21)))
  {
   sf.pos=3692722;
   YzLT(Ain);
   sf.pos=3692723;
   Vtoken = Y_PN(Ain);
   sf.pos=3692724;
   Yk0M(Vitem, Vtoken->Vvalue);
   sf.pos=3692725;
   YPkC(Vitem, Vtoken->VzuiPos);
  }
  sf.pos=3692726;
  if ((YksM(Ain)->Vtype == 82))
  {
   sf.pos=3692727;
   Y_PN(Ain);
   sf.pos=3692728;
   YzLT(Ain);
  }
  else {
  sf.pos=3692729;
 if ((Y6qU(Ain)->Vtype != 126))
  {
   rt = 2;
   goto Y2sj;
  }
  }
  sf.pos=3692730;
  VdidFirst = 1;
Y2sj:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=3692731;
 }
 topFrame = sf.prev;
 return;
}
Tl *Yyre(Y7Sj *Ain) {
 Zsf sf;
 Tl *r = 0;
 Tl *Vnames = NULL;
 Yev8 *Vtoken = 0;
 Y1p4 *Vid = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1161200;
 Y_PN(Ain);
 sf.pos=1161201;
 YuRk(Ain);
 sf.pos=1161202;
 Vnames = ZnewList((Tt*)&Y1p4__T, 0);
 sf.pos=1161203;
 while (1)
 {
  sf.pos=1161204;
  Vtoken = Y_PN(Ain);
  sf.pos=1161205;
  if ((Vtoken->Vtype != 21))
  {
   rt = 2;
   goto Y8nY;
  }
  sf.pos=1161206;
  Vid = YUZH(NULL);
  sf.pos=1161207;
  YxV1(Vid, Vtoken->VzuiPos);
  sf.pos=1161208;
  YMou(Vid, Vtoken->Vvalue);
  sf.pos=1161209;
  ZLap((Tl*)Vnames, (Tz)(void*)Vid);
  sf.pos=1161210;
  Vtoken = Y_PN(Ain);
  sf.pos=1161211;
  if ((Vtoken->Vtype != 82))
  {
   rt = 2;
   goto Y8nY;
  }
  sf.pos=1161212;
  YzLT(Ain);
Y8nY:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=1161213;
 }
 sf.pos=1161214;
 if ((Vtoken->Vtype != 133))
 {
  sf.pos=1161215;
  YdIu(Vtoken, ((Tc*)&YjZE));
 }
 sf.pos=1161216;
 r = Vnames;
 topFrame = sf.prev;
 return r;
}
Tl *YZnz(Y7Sj *Ain, YnZD *AfirstExpr, Tbs Aflags) {
 Tb VfoundNamedArgument;
 Zsf sf;
 Tl *r = 0;
 YnZD *Vexpr = 0;
 Tl *VexprList = NULL;
 Tc *Vname = NULL;
 Ysbp *Vpos = 0;
 YnZD *Vassign = 0;
 Yev8 *Vtoken = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3133800;
 if ((AfirstExpr == NULL))
 {
  sf.pos=3133801;
  Vexpr = YUWY(Ain);
 }
 else
 {
  sf.pos=3133802;
  Vexpr = AfirstExpr;
 }
 sf.pos=3133803;
 VexprList = ZnewList((Tt*)&YnZD__T, 0);
 VfoundNamedArgument = 0;
 sf.pos=3133804;
 while (1)
 {
  Vname = NULL;
  Vpos = 0;
  sf.pos=3133805;
  if (((((Aflags) & 2) >> 1) && (Y6qU(Ain)->Vtype == 112)))
  {
   sf.pos=3133806;
   if ((YmTi(Vexpr) != 1))
   {
    sf.pos=3133807;
    YHwp(((Tc*)&YYCX), Ain);
   }
   else
   {
    sf.pos=3133808;
    Vname = YYim(YjUS(Vexpr));
    sf.pos=3133809;
    Vpos = Y74i(Vexpr);
   }
   sf.pos=3133810;
   VfoundNamedArgument = 1;
   sf.pos=3133811;
   YzLT(Ain);
   sf.pos=3133812;
   Y_PN(Ain);
   sf.pos=3133813;
   YzLT(Ain);
   sf.pos=3133814;
   Vexpr = YUWY(Ain);
  }
  else {
  sf.pos=3133815;
 if (VfoundNamedArgument)
  {
   sf.pos=3133816;
   YHwp(((Tc*)&YYCX), Ain);
  }
  }
  sf.pos=3133817;
  if ((YmTi(Vexpr) != 68))
  {
   sf.pos=3133818;
   if ((Vname != NULL))
   {
    sf.pos=3133819;
    Vassign = YPfx(Y4_i(YaZq(Y4GO(NULL), 66), Vpos), Vexpr);
    sf.pos=3133820;
    Y4_i(YM_T(YaZq(Y8za(Vassign), 5), Vname), Vpos);
    sf.pos=3133821;
    Vexpr = Vassign;
   }
   sf.pos=3133822;
   ZLap((Tl*)VexprList, (Tz)(void*)Vexpr);
  }
  sf.pos=3133823;
  if ((Y6qU(Ain)->Vtype != 82))
  {
   rt = 2;
   goto YpjQ;
  }
  sf.pos=3133824;
  YuRk(Ain);
  sf.pos=3133825;
  Vtoken = Y_PN(Ain);
  sf.pos=3133826;
  YzLT(Ain);
  sf.pos=3133827;
  Vexpr = YUWY(Ain);
  sf.pos=3133828;
  if ((YmTi(Vexpr) == 68))
  {
   sf.pos=3133829;
   if (!((((Aflags) & 1))))
   {
    sf.pos=3133830;
    YdIu(Vtoken, ((Tc*)&Yjbe));
   }
   rt = 2;
   goto YpjQ;
  }
YpjQ:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=3133831;
 }
 sf.pos=3133832;
 r = VexprList;
 topFrame = sf.prev;
 return r;
}
YnZD *Y3lj(YnZD *AstartExpr, Y7Sj *Ain, Tbs Awhat) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 Yev8 *Vtoken = 0;
 Yev8 *VopToken = 0;
 YnZD *VmethodExpr = 0;
 YnZD *Varg = 0;
 YnZD *VtypeExpr = 0;
 YnZD *Varg1 = 0;
 YnZD *Vmember = 0;
 YnZD *Vrhs = 0;
 YnZD *Vassign = 0;
 Tl *Vargs = NULL;
 Y_1n *Vmethod = 0;
 YnZD *Varg2 = 0;
 YnZD *Vsubscript = 0;
 Tl *Vtypes = NULL;
 Tc *Vname = NULL;
 YnZD *Vtypespec = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=174000;
 Vexpr = AstartExpr;
 sf.pos=174001;
 while (1)
 {
  sf.pos=174002;
  Vtoken = Y6qU(Ain);
  sf.pos=174003;
  if (!((((((((Vtoken->Vtype == 89) || (Vtoken->Vtype == 87)) || (((Vtoken->Vtype == 90) && (((Awhat) & 2) >> 1)))) || (Vtoken->Vtype == 94)) || ((((Vtoken->Vtype == 112) && !((((Awhat) & 1)))) && !(YfTZ(YksM(Ain)))))) || (((Vtoken->Vtype == 135) && (((Awhat) & 1))))))))
  {
   rt = 2;
   goto Y1Vr;
  }
  sf.pos=174004;
  if (((Vtoken->Vtype == 94) && (YksM(Ain)->Vtype == 3)))
  {
   rt = 2;
   goto Y1Vr;
  }
  sf.pos=174005;
  if (((Vtoken->Vtype == 89) || (Vtoken->Vtype == 87)))
  {
   sf.pos=174006;
   Vtoken = Y_PN(Ain);
   sf.pos=174007;
   if ((Vtoken->Vtype != 3))
   {
    sf.pos=174008;
    YH7I(Ain, Vtoken);
   }
  }
  sf.pos=174009;
  YuRk(Ain);
  sf.pos=174010;
  VopToken = Y_PN(Ain);
  sf.pos=174011;
  if (((((VopToken->Vtype != 89) && (VopToken->Vtype != 87)) && (VopToken->Vtype != 112)) && (VopToken->Vtype != 135)))
  {
   sf.pos=174012;
   Y5bl(Ain);
  }
  sf.pos=174013;
  if (((VopToken->Vtype == 89) || (VopToken->Vtype == 87)))
  {
   sf.pos=174014;
   Vtoken = Y_PN(Ain);
   sf.pos=174015;
   if ((Vtoken->Vtype == 90))
   {
    sf.pos=174016;
    VmethodExpr = YxDV(35, Vtoken->VzuiPos);
    sf.pos=174017;
    if ((VopToken->Vtype == 87))
    {
     sf.pos=174018;
     YkYI(VmethodExpr, 1);
    }
    sf.pos=174019;
    Y5bl(Ain);
    sf.pos=174020;
    Varg = YUWY(Ain);
    sf.pos=174021;
    Y5bl(Ain);
    sf.pos=174022;
    Vtoken = Y_PN(Ain);
    sf.pos=174023;
    if ((Vtoken->Vtype != 91))
    {
     sf.pos=174024;
     YdIu(Vtoken, ((Tc*)&Y2Kg));
     sf.pos=174025;
     YH7I(Ain, Vtoken);
    }
    sf.pos=174026;
    YPfx(VmethodExpr, Varg);
    sf.pos=174027;
    Yfkd(VmethodExpr, Vexpr);
    sf.pos=174028;
    Vexpr = VmethodExpr;
   }
   else {
   sf.pos=174029;
 if ((Vtoken->Vtype == 135))
   {
    sf.pos=174030;
    VtypeExpr = YxDV(21, Vtoken->VzuiPos);
    sf.pos=174031;
    if ((VopToken->Vtype == 87))
    {
     sf.pos=174032;
     YkYI(VtypeExpr, 1);
    }
    sf.pos=174033;
    Y5bl(Ain);
    sf.pos=174034;
    Varg1 = YTKt(Ain, 1, 1);
    sf.pos=174035;
    Y5bl(Ain);
    sf.pos=174036;
    Vtoken = Y_PN(Ain);
    sf.pos=174037;
    if ((Vtoken->Vtype != 133))
    {
     sf.pos=174038;
     YdIu(Vtoken, ((Tc*)&YnLg));
     sf.pos=174039;
     YH7I(Ain, Vtoken);
    }
    sf.pos=174040;
    Yz09(YLJs(Ymcl(VtypeExpr), 45), Varg1);
    sf.pos=174041;
    Yfkd(VtypeExpr, Vexpr);
    sf.pos=174042;
    Vexpr = VtypeExpr;
   }
   else
   {
    sf.pos=174043;
    if ((((((Vtoken->Vtype != 21) && (Vtoken->Vtype != 53)) && (Vtoken->Vtype != 8)) && (Vtoken->Vtype != 55)) && (Vtoken->Vtype != 56)))
    {
     sf.pos=174044;
     YdIu(Vtoken, ((Tc*)&YlRP));
    }
    sf.pos=174045;
    Vmember = YxDV(20, Vtoken->VzuiPos);
    sf.pos=174046;
    if ((VopToken->Vtype == 87))
    {
     sf.pos=174047;
     YkYI(Vmember, 1);
    }
    sf.pos=174048;
    YMou(YRE8(Y4_i(YaZq(YBJ7(Vmember), 1), Vtoken->VzuiPos)), Vtoken->Vvalue);
    sf.pos=174049;
    Yfkd(Vmember, Vexpr);
    sf.pos=174050;
    Vexpr = Vmember;
   }
   }
  }
  else {
  sf.pos=174051;
 if ((VopToken->Vtype == 112))
  {
   Tb Vnegative;
   sf.pos=174052;
   Vtoken = Y_PN(Ain);
   Vnegative = 0;
   sf.pos=174053;
   if ((Vtoken->Vtype == 98))
   {
    sf.pos=174054;
    Vnegative = 1;
    sf.pos=174055;
    Vtoken = Y_PN(Ain);
   }
   sf.pos=174056;
   if ((Vtoken->Vtype != 21))
   {
    sf.pos=174057;
    YdIu(Vtoken, ((Tc*)&YzHl));
   }
   sf.pos=174058;
   Vrhs = YqGb(Ain, Vtoken);
   sf.pos=174059;
   if (Vnegative)
   {
    sf.pos=174060;
    if (((YmTi(Vrhs) != 2) && (YmTi(Vrhs) != 3)))
    {
     sf.pos=174061;
     YdIu(Vtoken, ((Tc*)&YVJU));
    }
    sf.pos=174062;
    Ypk4(Vrhs, -(YsEM(Vrhs)));
   }
   sf.pos=174063;
   Vassign = YxDV(34, Vtoken->VzuiPos);
   sf.pos=174064;
   Yfkd(YPfx(Vassign, Vrhs), Vexpr);
   sf.pos=174065;
   Vexpr = Vassign;
  }
  else {
  sf.pos=174066;
 if ((VopToken->Vtype == 90))
  {
   sf.pos=174067;
   Y5bl(Ain);
   sf.pos=174068;
   Vargs = YZnz(Ain, NULL, 2);
   sf.pos=174069;
   Y5bl(Ain);
   sf.pos=174070;
   Vtoken = Y_PN(Ain);
   sf.pos=174071;
   if ((Vtoken->Vtype != 91))
   {
    sf.pos=174072;
    YdIu(Vtoken, ((Tc*)&Y2Kg));
    sf.pos=174073;
    YH7I(Ain, Vtoken);
   }
   sf.pos=174074;
   Vmethod = YLx8(NULL);
   sf.pos=174075;
   Y_BE(Vmethod, Y74i(Vexpr));
   sf.pos=174076;
   YnYS(Vmethod, Vargs);
   sf.pos=174077;
   YOo6(Vmethod, Vexpr);
   sf.pos=174078;
   Vexpr = YoWy(Y4_i(YaZq(Y4GO(NULL), 16), Y74i(Vexpr)), Vmethod);
  }
  else {
  sf.pos=174079;
 if ((VopToken->Vtype == 94))
  {
   sf.pos=174080;
   Varg2 = YUWY(Ain);
   sf.pos=174081;
   Y5bl(Ain);
   sf.pos=174082;
   Vtoken = Y_PN(Ain);
   sf.pos=174083;
   if ((Vtoken->Vtype != 96))
   {
    sf.pos=174084;
    YdIu(Vtoken, ((Tc*)&YoAJ));
    sf.pos=174085;
    YH7I(Ain, Vtoken);
   }
   sf.pos=174086;
   Vsubscript = Y4_i(YaZq(Y4GO(NULL), 33), Y74i(Vexpr));
   sf.pos=174087;
   YPfx(Yfkd(Vsubscript, Vexpr), Varg2);
   sf.pos=174088;
   Vexpr = Vsubscript;
  }
  else
  {
   sf.pos=174089;
   Vtypes = ZnewList((Tt*)&YRBza__T, 0);
   sf.pos=174090;
   Ya8Z(Ain, Vtypes, ((YmTi(Vexpr) == 1) && (ZstringCmp(YYim(YjUS(Vexpr)), ((Tc*)&YclO)) == 0)));
   sf.pos=174091;
   if ((YmTi(Vexpr) == 1))
   {
    sf.pos=174092;
    Vname = YYim(YjUS(Vexpr));
    sf.pos=174093;
    if (((((((ZstringCmp(Vname, ((Tc*)&Yknu)) == 0) || (ZstringCmp(Vname, ((Tc*)&YPxi)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YdEY)) == 0)) || (ZstringCmp(Vname, ((Tc*)&Y6Yl)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YOjT)) == 0)) || (ZstringCmp(Vname, ((Tc*)&YCpI)) == 0)))
    {
     sf.pos=174094;
     Y63C(Ain->VusedIdKeywords, ZstringToUpper(Vname));
    }
   }
   sf.pos=174095;
   Vtypespec = Y4_i(YaZq(Y4GO(NULL), 22), Y74i(Vexpr));
   sf.pos=174096;
   YbfL(Vtypespec, Vtypes);
   sf.pos=174097;
   Yfkd(Vtypespec, Vexpr);
   sf.pos=174098;
   Vexpr = Vtypespec;
  }
  }}}
Y1Vr:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=174099;
 }
 sf.pos=174100;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
YXCg *YPL0(Y7Sj *Ain) {
 Tb Vcomment;
 Ti Vc;
 Ti Vgt_count;
 Ti Vstart;
 Zsf sf;
 YXCg *r = 0;
 YkxB *Vpos = 0;
 YXCg *Vstmt = 0;
 Tl *VusesList = NULL;
 YkxB *VstartPos = 0;
 Tc *Vword = NULL;
 YjUM *Vwriter = 0;
 Tc *Vtext = NULL;
 Tc *VtoWrite = NULL;
 YkxB *VstartPos1 = 0;
 Tc *Vs = NULL;
 YLuR *Vblock = 0;
 YLuR *Vblock1 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=702800;
 Vpos = Y83A(Ain->Vinput->Vpos);
 sf.pos=702801;
 Vstmt = Yiw6(YZqm(YDNI(NULL), YK9d(Vpos)), 31);
 sf.pos=702802;
 YGzQ(Ain);
 Vcomment = 0;
 Vc = 0;
 sf.pos=702803;
 while (1)
 {
  sf.pos=702804;
  VstartPos = Y83A(Ain->Vinput->Vpos);
  sf.pos=702805;
  Vc = YGBv(Ain);
  sf.pos=702806;
  if (((Vc == Y3QJ) || (Vc == 10)))
  {
   rt = 2;
   goto Y6z4;
  }
  sf.pos=702807;
  if ((Vc == 35))
  {
   sf.pos=702808;
   Vcomment = 1;
  }
  else {
  sf.pos=702809;
 if (!(Vcomment))
  {
   sf.pos=702810;
   if (((Vc == 117) && (ZstringCmp(YUrw(Ain), ((Tc*)&YNjT)) == 0)))
   {
    sf.pos=702811;
    Vc = YGBv(Ain);
    sf.pos=702812;
    if ((Vc != 40))
    {
     sf.pos=702813;
     YHwp(((Tc*)&YSrw), Ain);
     sf.pos=702814;
     Vcomment = 1;
    }
    else
    {
     sf.pos=702815;
     VusesList = ZnewList((Tt*)&string__T, 0);
     sf.pos=702816;
     while (1)
     {
      sf.pos=702817;
      Vword = YUrw(Ain);
      sf.pos=702818;
      if ((ZbyteStringSize(Vword) == 0))
      {
       sf.pos=702819;
       YHwp(((Tc*)&Ympj), Ain);
       sf.pos=702820;
       Vcomment = 1;
       rt = 2;
       goto YVqs;
      }
      sf.pos=702821;
      ZLap((Tl*)VusesList, (Tz)(void*)Vword);
      sf.pos=702822;
      Vc = YGBv(Ain);
      sf.pos=702823;
      if ((Vc == 41))
      {
       rt = 2;
       goto YVqs;
      }
      sf.pos=702824;
      if ((Vc != 44))
      {
       sf.pos=702825;
       if ((Vc == 32))
       {
        sf.pos=702826;
        YHwp(((Tc*)&YFLI), Ain);
       }
       else
       {
        sf.pos=702827;
        YHwp(((Tc*)&Ympj), Ain);
       }
       sf.pos=702828;
       Vcomment = 1;
       rt = 2;
       goto YVqs;
      }
      sf.pos=702829;
      if (!(Y7_i(Ain)))
      {
       sf.pos=702830;
       YHwp(((Tc*)&Y7QZ), Ain);
       sf.pos=702831;
       Vcomment = 1;
       rt = 2;
       goto YVqs;
      }
YVqs:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=702832;
     }
    }
   }
   else {
   sf.pos=702833;
 if (((Vc == 98) && (ZstringCmp(YUrw(Ain), ((Tc*)&YqCB)) == 0)))
   {
    sf.pos=702834;
    YpTx(Vstmt, 1);
   }
   else {
   sf.pos=702835;
 if ((Vc != 32))
   {
    sf.pos=702836;
    YDli(((Tc*)&YcVF), VstartPos, 0);
    sf.pos=702837;
    Vcomment = 1;
   }
   }}
  }
  }
Y6z4:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=702838;
 }
 sf.pos=702839;
 Vwriter = Za(sizeof(YjUM));
 sf.pos=702840;
 Vgt_count = 0;
 sf.pos=702841;
 while (1)
 {
  sf.pos=702842;
  Vc = YGBv(Ain);
  sf.pos=702843;
  if ((Vc == Y3QJ))
  {
   sf.pos=702844;
   YHwp(((Tc*)&YMiN), Ain);
   rt = 2;
   goto Yw2n;
  }
  sf.pos=702845;
  while (((Vgt_count > 0) && (Vc != 60)))
  {
   sf.pos=702846;
   YjUM__Ydti(Vwriter, 60);
   sf.pos=702847;
   --(Vgt_count);
  sf.pos=702848;
  }
  sf.pos=702849;
  if ((Vc == 10))
  {
   sf.pos=702850;
   Vgt_count = 0;
  }
  else {
  sf.pos=702851;
 if (((Vgt_count >= 0) && (Vc == 60)))
  {
   sf.pos=702852;
   if ((++(Vgt_count) == 3))
   {
    rt = 2;
    goto YcXw;
   }
YcXw:
   if (rt) goto Yw2n;
  }
  else
  {
   sf.pos=702853;
   Vgt_count = -1;
  }
  }
  sf.pos=702854;
  if ((Vgt_count <= 0))
  {
   sf.pos=702855;
   YjUM__Ydti(Vwriter, Vc);
  }
Yw2n:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=702856;
 }
 sf.pos=702857;
 while (1)
 {
  sf.pos=702858;
  Vc = YGBv(Ain);
  sf.pos=702859;
  if (((Vc == Y3QJ) || (Vc == 10)))
  {
   rt = 2;
   goto YxuHa;
  }
YxuHa:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=702860;
 }
 sf.pos=702861;
 Vtext = YbNW(Vwriter);
 Vstart = 0;
 sf.pos=702862;
 VtoWrite = ((Tc*)&Ya);
 sf.pos=702863;
 VstartPos1 = Y83A(Vpos);
 sf.pos=702864;
 while (1)
 {
  Ti Vidx;
  sf.pos=702865;
  Vidx = ZstringFindChar2(Vtext, 37, Vstart, 0);
  sf.pos=702866;
  if ((Vidx >= 0))
  {
   Ti Vend;
   Tb Vliteral;
   sf.pos=702867;
   Vs = ZstringSlice(Vtext, Vstart, (Vidx - 1), 0);
   sf.pos=702868;
   VtoWrite =  ZcS(VtoWrite, Vs);
   sf.pos=702869;
   Y7Yp(Vpos, Vs);
   sf.pos=702870;
   ++(Vpos->Vcol);
   sf.pos=702871;
   Vend = (Vidx + 1);
   Vliteral = 0;
   sf.pos=702872;
   if (((ZstringGetChar(Vtext, Vend) == 123) || (ZstringGetChar(Vtext, Vend) == 91)))
   {
    Ti Vmatch;
    Vmatch = 0;
    sf.pos=702873;
    if ((ZstringGetChar(Vtext, Vend) == 123))
    {
     sf.pos=702874;
     Vmatch = 125;
    }
    else
    {
     sf.pos=702875;
     Vmatch = 93;
     sf.pos=702876;
     Vliteral = 1;
    }
    sf.pos=702877;
    ++(Vend);
    sf.pos=702878;
    while (((ZstringGetChar(Vtext, Vend) != 0) && (((ZstringGetChar(Vtext, Vend) != Vmatch) || (ZstringGetChar(Vtext, (Vend + 1)) != 37)))))
    {
     sf.pos=702879;
     ++(Vend);
    sf.pos=702880;
    }
    sf.pos=702881;
    if ((ZstringGetChar(Vtext, Vend) == Vmatch))
    {
     sf.pos=702882;
     ++(Vend);
    }
   }
   else
   {
    sf.pos=702883;
    while (((((ZstringGetChar(Vtext, Vend) != 37) && (ZstringGetChar(Vtext, Vend) != 0)) && (ZstringGetChar(Vtext, Vend) != 32)) && (ZstringGetChar(Vtext, Vend) != 10)))
    {
     sf.pos=702884;
     ++(Vend);
    sf.pos=702885;
    }
   }
   sf.pos=702886;
   if ((ZstringGetChar(Vtext, Vend) == 37))
   {
    sf.pos=702887;
    if ((Vend == (Vidx + 1)))
    {
     sf.pos=702888;
     VtoWrite =  ZcS(VtoWrite, ((Tc*)&YL));
     sf.pos=702889;
     ++(Vpos->Vcol);
    }
    else
    {
     sf.pos=702890;
     Vblock = YvSw(YRpi(YapJ(YgFm(NULL), YK9d(VstartPos1)), VtoWrite), Vliteral);
     sf.pos=702891;
     if ((VusesList != NULL))
     {
      sf.pos=702892;
      YwGh(Vblock, VusesList);
      sf.pos=702893;
      VusesList = NULL;
     }
     sf.pos=702894;
     YGJp(Vstmt, Vblock);
     sf.pos=702895;
     Vs = ZstringSlice(Vtext, (Vidx + 1), (Vend - 1), 0);
     sf.pos=702896;
     YBL_(Vblock, Vs, Vpos);
     sf.pos=702897;
     Y7Yp(Vpos, Vs);
     sf.pos=702898;
     VtoWrite = ((Tc*)&Ya);
     sf.pos=702899;
     ++(Vpos->Vcol);
     sf.pos=702900;
     VstartPos1 = Y83A(Vpos);
    }
    sf.pos=702901;
    Vstart = (Vend + 1);
   }
   else
   {
    sf.pos=702902;
    VtoWrite =  ZcS(VtoWrite, ((Tc*)&YL));
    sf.pos=702903;
    Vstart = (Vidx + 1);
   }
  }
  else
  {
   sf.pos=702904;
   VtoWrite =  ZcS(VtoWrite, ZstringSlice(Vtext, Vstart, -1, 0));
   rt = 2;
   goto YWX_;
  }
YWX_:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=702905;
 }
 sf.pos=702906;
 if ((ZbyteStringSize(VtoWrite) != 0))
 {
  sf.pos=702907;
  Vblock1 = YRpi(YapJ(YgFm(NULL), YK9d(VstartPos1)), VtoWrite);
  sf.pos=702908;
  if ((VusesList != NULL))
  {
   sf.pos=702909;
   YwGh(Vblock1, VusesList);
   sf.pos=702910;
   VusesList = NULL;
  }
  sf.pos=702911;
  YGJp(Vstmt, Vblock1);
 }
 sf.pos=702912;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
void YBL_(YLuR *Ablock, Tc *Atext, YkxB *Apos) {
 Zsf sf;
 Y7Sj *Vin = 0;
 YeYq *Vinput = 0;
 YeYq *Vinput1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5892100;
 if (((ZstringGetChar(Atext, 0) == 123) || (ZstringGetChar(Atext, 0) == 91)))
 {
  sf.pos=5892101;
  Vinput = YOdra(NULL, ZstringSlice(Atext, 1, -2, 0), Apos);
  sf.pos=5892102;
  Vin = YUwt(NULL, Vinput);
  sf.pos=5892103;
  ++(Vin->Vinput->Vpos->Vcol);
 }
 else
 {
  sf.pos=5892104;
  Vinput1 = YOdra(NULL, Atext, Apos);
  sf.pos=5892105;
  Vin = YUwt(NULL, Vinput1);
 }
 sf.pos=5892106;
 YBch(Vin);
 sf.pos=5892107;
 YZAk(Ablock, YUWY(Vin));
 topFrame = sf.prev;
 return;
}
YXCg *YBsI(Yev8 *Atoken, Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Yev8 *Vcomment = 0;
 YnZD *Vleft = 0;
 YnZD *VidExpr = 0;
 Tc *Vname = NULL;
 YJON *Vza = 0;
 YoDF *Valias = 0;
 YYIi *Vdecl = 0;
 Yev8 *Vpeek = 0;
 YXCg *Vstmt = 0;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=703500;
 if (Y3DE->VhasComment)
 {
  sf.pos=703501;
  Vcomment = Y3DE;
 }
 sf.pos=703502;
 YzLT(Ain);
 sf.pos=703503;
 Vleft = YTKt(Ain, 1, 1);
 sf.pos=703504;
 YzLT(Ain);
 sf.pos=703505;
 VidExpr = YTKt(Ain, 1, 0);
 sf.pos=703506;
 if ((YmTi(VidExpr) != 1))
 {
  sf.pos=703507;
  YdIu(Atoken, ((Tc*)&YIYT));
 }
 else
 {
  sf.pos=703508;
  Vname = YYim(YjUS(VidExpr));
  sf.pos=703509;
  if ((Y00A(VidExpr) != Y00A(Vleft)))
  {
   sf.pos=703510;
   YdIu(Atoken, ((Tc*)&YLxU));
  }
  sf.pos=703511;
  if ((YpO1(VidExpr) != YpO1(Vleft)))
  {
   sf.pos=703512;
   YdIu(Atoken, ((Tc*)&YKTL));
  }
 }
 sf.pos=703513;
 Vza = YsCX(NULL);
 sf.pos=703514;
 Y6sC(Vza, 1, (t0 = ZnewList((Tt*)&string__T, 5), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YF4i)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YPwY)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ygnv)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YYFL)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YIEZ))), Ain);
 sf.pos=703515;
 Valias = YRGj(NULL);
 sf.pos=703516;
 YpwO(Valias, Vleft);
 sf.pos=703517;
 Yit4(Valias, Vname);
 sf.pos=703518;
 Vdecl = YpQb(NULL);
 sf.pos=703519;
 YrDX(YVus(YLJs(YkDm(YvRw(YpBC(Vdecl, Vname), Atoken->VzuiPos)), 42), Valias), Vza);
 sf.pos=703520;
 YcHs(Vdecl, VidExpr);
 sf.pos=703521;
 if ((Vcomment != NULL))
 {
  sf.pos=703522;
  Y4e7(Vdecl, Vcomment->Vvalue);
 }
 sf.pos=703523;
 Vpeek = YksM(Ain);
 sf.pos=703524;
 if (((Vpeek->Vtype == 3) && Vpeek->VhasCommentFirst))
 {
  sf.pos=703525;
  YDJy(Vdecl, Vpeek->Vvalue);
 }
 sf.pos=703526;
 YE5j(Ain);
 sf.pos=703527;
 Vstmt = YDNI(NULL);
 sf.pos=703528;
 Yh4I(Yiw6(YZqm(Vstmt, Atoken->VzuiPos), (((Atoken->Vtype == 25)) ? (7) : (8))), Vdecl);
 sf.pos=703529;
 r = Vstmt;
 topFrame = sf.prev;
 return r;
}
YXCg *YksO(Y7Sj *Ain) {
 Zsf sf;
 YXCg *r = 0;
 Ysbp *VstartPos = 0;
 Tc *VtypeName = NULL;
 YnZD *Vctype = 0;
 Yev8 *Vtoken = 0;
 YLSh t0 = {};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7433000;
 (t0 = YljT(Ain));
 VtypeName = t0.a0;
 VstartPos = t0.a1;
 sf.pos=7433001;
 Vctype = YxDV(23, VstartPos);
 sf.pos=7433002;
 YMou(YRE8(Vctype), VtypeName);
 sf.pos=7433003;
 YzLT(Ain);
 sf.pos=7433004;
 Vtoken = Y_PN(Ain);
 sf.pos=7433005;
 r = YH3h(Vctype, Vtoken, 1, 1, Ain);
 topFrame = sf.prev;
 return r;
}
YLSh YljT(Y7Sj *Ain) {
 Ti Vc;
 Ti Vnesting;
 Zsf sf;
 YLSh r;
 Ysbp *VstartPos = 0;
 YjUM *Vwriter = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9104100;
 VstartPos = YK9d(Ain->Vinput->Vpos);
 sf.pos=9104101;
 Vc = YGBv(Ain);
 sf.pos=9104102;
 if ((Vc != 40))
 {
  sf.pos=9104103;
  YHwp(((Tc*)&Y1Kg), Ain);
  sf.pos=9104104;
  r.a1 = VstartPos;
  r.a0 = ((Tc*)&Ya);
  rt = 1;
  goto YYl1;
 }
 sf.pos=9104105;
 for (;;)
 {
  sf.pos=9104106;
  Vc = YGBv(Ain);
  sf.pos=9104107;
  if ((Vc != 32)) break;
 sf.pos=9104108;
 }
 sf.pos=9104109;
 YPmF(Ain, Vc);
 sf.pos=9104110;
 Vwriter = Za(sizeof(YjUM));
 Vnesting = 0;
 sf.pos=9104111;
 while (1)
 {
  sf.pos=9104112;
  if (((Vc == Y3QJ) || (Vc == 10)))
  {
   sf.pos=9104113;
   YHwpa(((Tc*)&Y2Kg), VstartPos);
   sf.pos=9104114;
   r.a1 = VstartPos;
   r.a0 = ((Tc*)&Ya);
   rt = 1;
   goto YsjU;
  }
  sf.pos=9104115;
  Vc = YGBv(Ain);
  sf.pos=9104116;
  if ((Vc == 41))
  {
   sf.pos=9104117;
   if ((Vnesting == 0))
   {
    rt = 2;
    goto YawY;
   }
   sf.pos=9104118;
   --(Vnesting);
YawY:
   if (rt) goto YsjU;
  }
  else {
  sf.pos=9104119;
 if ((Vc == 40))
  {
   sf.pos=9104120;
   ++(Vnesting);
  }
  }
  sf.pos=9104121;
  YjUM__Ydti(Vwriter, Vc);
YsjU:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YYl1;
 sf.pos=9104122;
 }
 sf.pos=9104123;
 r.a1 = VstartPos;
 r.a0 = YbNW(Vwriter);
YYl1:
 topFrame = sf.prev;
 return r;
}
YnZD *Y9sl(Y7Sj *Ain) {
 Zsf sf;
 YnZD *r = 0;
 Ysbp *VstartPos = 0;
 Tc *Vcode = NULL;
 YnZD *Vccode = 0;
 YLSh t0 = {};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9819100;
 (t0 = YljT(Ain));
 Vcode = t0.a0;
 VstartPos = t0.a1;
 sf.pos=9819101;
 Vccode = YxDV(67, VstartPos);
 sf.pos=9819102;
 YM_T(Vccode, Vcode);
 sf.pos=9819103;
 r = Vccode;
 topFrame = sf.prev;
 return r;
}
void YHwp(Tc *Amsg, Y7Sj *Ain) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8080800;
 YDli(Amsg, Ain->Vinput->Vpos, 0);
 topFrame = sf.prev;
 return;
}
void YHwpa(Tc *Amsg, Ysbp *Apos) {
 Zsf sf;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4295600;
 YDli(Amsg, Ypp_a(NULL, (t0 = Y5Hu(Apos)), YuDY(Apos), Y3kb(Apos)), 0);
 topFrame = sf.prev;
 return;
}
void YQuF(Y7Sj *Ain) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=191500;
 YQuFa(Ain, 1);
 topFrame = sf.prev;
 return;
}
void YE5j(Y7Sj *Ain) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5291700;
 YQuFa(Ain, 0);
 topFrame = sf.prev;
 return;
}
void YQuFa(Y7Sj *Ain, Tb AallowSemicolon) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 Yev8 *Vnext = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4083900;
 Vtoken = Y_PN(Ain);
 sf.pos=4083901;
 if ((Vtoken->Vtype == 2))
 {
  sf.pos=4083902;
  Y3DE = Vtoken;
  sf.pos=4083903;
  Vnext = Y_PN(Ain);
  sf.pos=4083904;
  Vtoken = Vnext;
 }
 sf.pos=4083905;
 if (AallowSemicolon)
 {
  sf.pos=4083906;
  if ((Vtoken->Vtype == 83))
  {
   sf.pos=4083907;
   Vtoken = Y_PN(Ain);
   sf.pos=4083908;
   if ((Vtoken->Vtype == 3))
   {
    sf.pos=4083909;
    YdIu(Vtoken, ((Tc*)&Y9h9));
   }
   else
   {
    sf.pos=4083910;
    YH7I(Ain, Vtoken);
    sf.pos=4083911;
    YzLT(Ain);
   }
   sf.pos=4083912;
   rt = 1;
   goto Y2Ws;
  }
  sf.pos=4083913;
  if ((Vnext != NULL))
  {
   sf.pos=4083914;
   YH7I(Ain, Vnext);
  }
Y2Ws:
  if (rt) goto YshR;
 }
 sf.pos=4083915;
 if ((Vtoken->Vtype == 3))
 {
  sf.pos=4083916;
  Y3DE = Vtoken;
 }
 else
 {
  sf.pos=4083917;
  if ((Vtoken->Vtype == 4))
  {
   sf.pos=4083918;
   YdIu(Vtoken, ((Tc*)&YyZB));
  }
  else {
  sf.pos=4083919;
 if ((Vtoken->Vtype == 83))
  {
   sf.pos=4083920;
   Vnext = Y_PN(Ain);
   sf.pos=4083921;
   if ((Vnext->Vtype == 3))
   {
    sf.pos=4083922;
    YdIu(Vtoken, ((Tc*)&Y9h9));
   }
   else
   {
    sf.pos=4083923;
    YdIu(Vtoken, ((Tc*)&Y5E1));
    sf.pos=4083924;
    if ((Vnext->Vtype != 2))
    {
     sf.pos=4083925;
     YH7I(Ain, Vnext);
    }
   }
  }
  else
  {
   sf.pos=4083926;
   YdIu(Vtoken, ((Tc*)&YmhU));
   sf.pos=4083927;
   if ((Vtoken->Vtype != 2))
   {
    sf.pos=4083928;
    YH7I(Ain, Vtoken);
   }
  }
  }
 }
YshR:
 topFrame = sf.prev;
 return;
}
void YzLT(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6869100;
 Vtoken = Y_PN(Ain);
 sf.pos=6869101;
 if (((Vtoken->Vtype != 2) && (Vtoken->Vtype != 3)))
 {
  sf.pos=6869102;
  YdIu(Vtoken, ((Tc*)&YXMB));
  sf.pos=6869103;
  if ((Vtoken->Vtype != 4))
  {
   sf.pos=6869104;
   YH7I(Ain, Vtoken);
  }
 }
 topFrame = sf.prev;
 return;
}
void YBch(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9922500;
 Vtoken = Y_PN(Ain);
 sf.pos=9922501;
 if (YfTZ(Vtoken))
 {
  sf.pos=9922502;
  Y3DE = Vtoken;
 }
 else
 {
  sf.pos=9922503;
  YH7I(Ain, Vtoken);
 }
 topFrame = sf.prev;
 return;
}
void Y5bl(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9411300;
 Vtoken = Y_PN(Ain);
 sf.pos=9411301;
 if (((Vtoken->Vtype == 3) || (((Vtoken->Vtype == 2) && Vtoken->VhasComment))))
 {
  sf.pos=9411302;
  Y3DE = Vtoken;
 }
 else
 {
  sf.pos=9411303;
  if ((Vtoken->Vtype == 2))
  {
   sf.pos=9411304;
   YdIu(Vtoken, ((Tc*)&YJzF));
  }
  else {
  sf.pos=9411305;
 if ((Vtoken->Vtype == 4))
  {
   sf.pos=9411306;
   YdIu(Vtoken, ((Tc*)&YXMB));
  }
  else
  {
   sf.pos=9411307;
   YH7I(Ain, Vtoken);
  }
  }
 }
 topFrame = sf.prev;
 return;
}
Yev8 *Y6qU(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *r = 0;
 Yev8 *Vres = 0;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6014100;
 Vtoken = Y_PN(Ain);
 sf.pos=6014101;
 if (((Vtoken->Vtype == 2) || (Vtoken->Vtype == 3)))
 {
  sf.pos=6014102;
  Vres = Y_PN(Ain);
  sf.pos=6014103;
  YH7I(Ain, Vres);
 }
 else
 {
  sf.pos=6014104;
  Vres = Vtoken;
 }
 sf.pos=6014105;
 YH7I(Ain, Vtoken);
 sf.pos=6014106;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
YU01 YdZD(Y7Sj *Ain) {
 Zsf sf;
 YU01 r;
 Yev8 *Vres = 0;
 Yev8 *Vnext = 0;
 Yev8 *Vtoken = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9067400;
 Vtoken = Y_PN(Ain);
 sf.pos=9067401;
 if (((Vtoken->Vtype == 2) || (Vtoken->Vtype == 3)))
 {
  sf.pos=9067402;
  Vres = Y_PN(Ain);
  sf.pos=9067403;
  Vnext = YksM(Ain);
  sf.pos=9067404;
  YH7I(Ain, Vres);
 }
 else
 {
  sf.pos=9067405;
  Vres = Vtoken;
  sf.pos=9067406;
  Vnext = YksM(Ain);
 }
 sf.pos=9067407;
 YH7I(Ain, Vtoken);
 sf.pos=9067408;
 r.a1 = Vnext;
 r.a0 = Vres;
 topFrame = sf.prev;
 return r;
}
void YuRk(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *Vnext = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8923700;
 Vnext = Y_PN(Ain);
 sf.pos=8923701;
 if (((Vnext->Vtype == 2) || (Vnext->Vtype == 3)))
 {
  sf.pos=8923702;
  YdIu(Vnext, ((Tc*)&YJzF));
 }
 else
 {
  sf.pos=8923703;
  YH7I(Ain, Vnext);
 }
 topFrame = sf.prev;
 return;
}
void YE6J(Y7Sj *Ain) {
 Zsf sf;
 Yev8 *Vnext = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4948200;
 Vnext = YksM(Ain);
 sf.pos=4948201;
 if ((Vnext->Vtype == 3))
 {
  sf.pos=4948202;
  YdIu(Vnext, ((Tc*)&YwSe));
 }
 topFrame = sf.prev;
 return;
}
YnZD *YxDV(Te Atype, Ysbp *Apos) {
 Zsf sf;
 YnZD *r = 0;
 YnZD *Vexpr = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8432300;
 Vexpr = Y4GO(NULL);
 sf.pos=8432301;
 YaZq(Vexpr, Atype);
 sf.pos=8432302;
 Y4_i(Vexpr, Apos);
 sf.pos=8432303;
 r = Vexpr;
 topFrame = sf.prev;
 return r;
}
int JParse(int round) {
 static int round_done = -1;
 int done = 1;
 if (round_done < round) {
  Zsf sf;
  sf.prev = topFrame;
  sf.pos = 0;
  sf.frof = NULL;
  topFrame = &sf;
  round_done = round;
 done &= JTokenInput(round);
 if (round == 2001) {
   sf.pos=4590700;
   YDNI(ZnoAllocClear(sizeof(YXCg), &YIbB, NULL));
   sf.pos=4590701;
   YK6i = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&EVisibility__T, 0), (Tz)(void*)((Tc*)&YF4i), (Tz)(Ti)1), (Tz)(void*)((Tc*)&YPwY), (Tz)(Ti)2), (Tz)(void*)((Tc*)&Ygnv), (Tz)(Ti)3), (Tz)(void*)((Tc*)&YYFL), (Tz)(Ti)5), (Tz)(void*)((Tc*)&YIEZ), (Tz)(Ti)6);
   sf.pos=4590702;
   Yoe0 = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&MZui__EVisibility__T, 0), (Tz)(void*)((Tc*)&YF4i), (Tz)(Ti)2), (Tz)(void*)((Tc*)&YPwY), (Tz)(Ti)3), (Tz)(void*)((Tc*)&Ygnv), (Tz)(Ti)4), (Tz)(void*)((Tc*)&YDNe), (Tz)(Ti)5), (Tz)(void*)((Tc*)&YYFL), (Tz)(Ti)6), (Tz)(void*)((Tc*)&YIEZ), (Tz)(Ti)7);
   sf.pos=4590703;
   Y3DE = Za(sizeof(Yev8));
  }
  topFrame = sf.prev;
 }
 return done;
}
/* Parse done */
YwDJ *YYjF(YwDJ *t, YrBF *Aparent, Tc *Aname, YXCg *Astmt, YJON *Aattr, Tc *Atype, YaHa *Aitems) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3287800; t = Za(sizeof(YwDJ));}
 sf.pos=3287801;
 t->Vparent = Aparent;
 sf.pos=3287802;
 t->Vchildren = ZnewList((Tt*)&YwDJ__T, 0);
 sf.pos=3287803;
 t->Vname = Aname;
 sf.pos=3287804;
 t->Vstmt = Astmt;
 sf.pos=3287805;
 t->Vattr = Aattr;
 sf.pos=3287806;
 t->Vtype = Atype;
 sf.pos=3287807;
 if ((Aparent == NULL))
 {
  sf.pos=3287808;
  t->VfullName = Aname;
 }
 else
 {
  sf.pos=3287809;
  t->VfullName = ZcS3(t->Vparent->VfullName, ((Tc*)&YU), Aname);
 }
 sf.pos=3287810;
 ZDictAdd(0, Vpages, (Tz)(void*)t->VfullName, (Tz)(void*)t);
 sf.pos=3287811;
 t->Vheader = ((Tc*)&Ya);
 sf.pos=3287812;
 t->Vtail = ((Tc*)&Ya);
 sf.pos=3287813;
 if (((Aitems == NULL) || (Aitems->Vsummary == NULL)))
 {
  sf.pos=3287814;
  t->Vcomment = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=3287815;
  t->Vcomment = Aitems->Vsummary;
 }
 sf.pos=3287816;
 if ((Aitems != NULL))
 {
  sf.pos=3287817;
  t->VnoIndex = Aitems->VnoIndex;
  sf.pos=3287818;
  t->Vhide = Aitems->Vhide;
 }
 sf.pos=3287819;
 t->Vimplements = ZnewList((Tt*)&string__T, 0);
 topFrame = sf.prev;
 return t;
}
Ti YMst(YwDJ *t, YwDJ *Aother) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=2185900;
  ZthrowThisNil();
 }
 sf.pos=2185901;
 r = ZstringCompare(ZstringToLower(t->Vname), ZstringToLower(Aother->Vname), 0);
 topFrame = sf.prev;
 return r;
}
Tc *YoRE(YwDJ *t) {
 Zsf sf;
 Tc *r = 0;
 Tc *VpName = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1619500;
  ZthrowThisNil();
 }
 sf.pos=1619501;
 if ((t->Vparent != NULL))
 {
  sf.pos=1619502;
  VpName = ZcS3(t->Vparent->VfullName, ((Tc*)&YU), t->VextendsNoType);
  sf.pos=1619503;
  if (ZDictHas(Vpages, (Tz)(void*)VpName))
  {
   sf.pos=1619504;
   r = VpName;
   rt = 1;
   goto YZPA;
  }
YZPA:
  if (rt) goto YeS7;
 }
 sf.pos=1619505;
 r = t->VextendsNoType;
YeS7:
 topFrame = sf.prev;
 return r;
}
void YXei(YwDJ *t, Tc *Atext) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4284200;
  ZthrowThisNil();
 }
 sf.pos=4284201;
 t->Vheader =  ZcS(t->Vheader, Atext);
 topFrame = sf.prev;
 return;
}
void YWvO(YwDJ *t, Tc *Atext) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5743900;
  ZthrowThisNil();
 }
 sf.pos=5743901;
 t->Vtail =  ZcS(t->Vtail, Atext);
 topFrame = sf.prev;
 return;
}
void YsLl(YwDJ *t, YrBF *Aparent, Tl *Aimplements) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YnZD *Vimpl = 0;
 Tc *Vs = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=3277900;
  ZthrowThisNil();
 }
 sf.pos=3277901;
 {
  Tfl Zf1i;
  Zf1 = Aimplements;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vimpl;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=3277902;
  Vs = Y0ZR(Vimpl, Aparent);
  sf.pos=3277903;
  if (((Aparent != NULL) && !(ZstringStartsWith(Vs, ((Tc*)&YW0a), 0))))
  {
   sf.pos=3277904;
   Vs = ZcS3(Aparent->VfullName, ((Tc*)&YU), Vs);
  }
  sf.pos=3277905;
  ZLap((Tl*)t->Vimplements, (Tz)(void*)Vs);
  sf.pos=3277906;
  }
 }
 topFrame = sf.prev;
 return;
}
To ToYwDJ[] = {
 {16, 0},
 {0, (Tt*)&YrBF__T}, /* parent */
 {0, (Tt*)&list__T}, /* children */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&string__T}, /* fullName */
 {0, (Tt*)&YXCg__T}, /* stmt */
 {0, (Tt*)&YJON__T}, /* attr */
 {0, (Tt*)&string__T}, /* type */
 {0, (Tt*)&string__T}, /* typeSpec */
 {0, (Tt*)&string__T}, /* comment */
 {0, (Tt*)&YHCf__T}, /* summary */
 {0, (Tt*)&string__T}, /* extends */
 {0, (Tt*)&list__T}, /* implements */
 {0, (Tt*)&list__T}, /* includes */
 {0, (Tt*)&string__T}, /* extendsNoType */
 {0, (Tt*)&string__T}, /* header */
 {0, (Tt*)&string__T}, /* tail */
};
Tto YwDJ__T = {390, (Tc*)&YW3M, 0, ToYwDJ};
YrBF *YSjh(YrBF *t, YJON *Aattr, YrBF *Aparent, YwDJ *Apage, Tc *Aname, YaHa *Aitems) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=6352700; t = Za(sizeof(YrBF));}
 sf.pos=6352701;
 t->Vattr = Aattr;
 sf.pos=6352702;
 t->Vparent = Aparent;
 sf.pos=6352703;
 t->Vpage = Apage;
 sf.pos=6352704;
 t->Vname = Aname;
 sf.pos=6352705;
 if ((Aparent != NULL))
 {
  sf.pos=6352706;
  t->VfullName = ZcS3(Aparent->VfullName, ((Tc*)&YU), Aname);
 }
 else
 {
  sf.pos=6352707;
  t->VfullName = Aname;
 }
 sf.pos=6352708;
 t->Vitems = Aitems;
 topFrame = sf.prev;
 return t;
}
void Y7hE(YrBF *t, Tc *Aname) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=8169200;
  ZthrowThisNil();
 }
 sf.pos=8169201;
 if ((t->VtypeNames == NULL))
 {
  sf.pos=8169202;
  t->VtypeNames = Yh95(NULL);
 }
 sf.pos=8169203;
 Y63C(t->VtypeNames, Aname);
 topFrame = sf.prev;
 return;
}
Tb YXY0(YrBF *t, Tc *Aname) {
 Zsf sf;
 Tb r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7421100;
  ZthrowThisNil();
 }
 sf.pos=7421101;
 if (((t->VtypeNames == NULL) || !(YyHa(t->VtypeNames, Aname))))
 {
  sf.pos=7421102;
  if ((t->Vparent == NULL))
  {
   sf.pos=7421103;
   r = 0;
   rt = 1;
   goto YHVC;
  }
  sf.pos=7421104;
  r = YXY0(t->Vparent, Aname);
YHVC:
  ;
  rt = 1;
  goto YCZX;
 }
 sf.pos=7421105;
 r = 1;
YCZX:
 topFrame = sf.prev;
 return r;
}
To ToYrBF[] = {
 {7, 0},
 {0, (Tt*)&YrBF__T}, /* parent */
 {0, (Tt*)&YwDJ__T}, /* page */
 {0, (Tt*)&string__T}, /* name */
 {0, (Tt*)&string__T}, /* fullName */
 {0, (Tt*)&YJON__T}, /* attr */
 {0, (Tt*)&YaHa__T}, /* items */
 {0, (Tt*)&Yhqr__T}, /* typeNames */
};
Tto YrBF__T = {390, (Tc*)&YnhT, 0, ToYrBF};
void YSxp(Tc *AinFileName) {
 Zsf sf;
 Yol9 *Vcontents = 0;
 YL4o *Vparsed = 0;
 Tl *Zf2 = NULL;
 YXCg *Vstmt = 0;
 YjS4 t0 = {};
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1108000;
 if ((ZstringCmp(ZstringSlice(AinFileName, -3, -1, 0), ((Tc*)&YYv4)) != 0))
 {
  sf.pos=1108001;
  Yl0k(ZcS(((Tc*)&YpAh), AinFileName));
  sf.pos=1108002;
  Zexit(NULL, 1);
 }
 sf.pos=1108003;
 (t0 = Yl0s(AinFileName, ((Tc*)&Ya), (((2 + 1) + 4) + 8)));
 Vcontents = t0.a0;
 Vparsed = t0.a1;
 sf.pos=1108004;
 if ((Yrpn == 0))
 {
  sf.pos=1108005;
  {
   Tfl Zf2i;
   Zf2 = YAaE(Vcontents);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vstmt;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=1108006;
   switch (YuqZ(Vstmt))
   {
   case 3:
   case 5:
   case 4:
    {
     sf.pos=1108007;
     Ywyp(Vstmt, NULL, NULL);
      break;
    }
   case 7:
    {
     sf.pos=1108008;
     Ye4o(Vstmt, NULL);
      break;
    }
   case 2:
    {
     sf.pos=1108009;
     YFk5(Vstmt);
      break;
    }
   }
   sf.pos=1108010;
   }
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YH8U(Tc *Aname) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2896200;
 r = ((Tc *)ZDictGetPtrDef(VbuiltinMap, (Tz)(void*)Aname, Aname));
 topFrame = sf.prev;
 return r;
}
void YEoy(YwDJ *Apage, Tc *AoutDirName) {
 Te Vvis;
 Zsf sf;
 Tr Vout = {NULL};
 YJON *Vattr = 0;
 Yhqr *Vdone = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 YrBF *t2 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9041300;
 Vout = YHH0(AoutDirName, (t1 = Apage->VfullName), ZcS3(Apage->VfullName, ((Tc*)&YG), (t0 = Apage->Vtype)), (t2 = Apage->Vparent));
 sf.pos=9041301;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS5(((Tc*)&YvWD), VhtmlKeyStart, (t0 = ZstringToUpper(Apage->Vtype)), VhtmlKeyEnd, (Tc*)1));
 sf.pos=9041302;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS(((Tc*)&YG), YH8U(Apage->VfullName)));
 sf.pos=9041303;
 if ((Apage->VtypeSpec != NULL))
 {
  sf.pos=9041304;
  ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Apage->VtypeSpec);
 }
 sf.pos=9041305;
 ((Ts (*)(void*))(Vout.table[18]))(Vout.ptr);
 sf.pos=9041306;
 Vattr = Apage->Vattr;
 sf.pos=9041307;
 if ((YCKw(Vattr) && (YXDk(Y1Yr(YjGb(Apage->Vstmt))) == 29)))
 {
  sf.pos=9041308;
  ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(VhtmlSmallAttrStart, ((Tc*)&YmHE), VhtmlSmallAttrEnd));
 }
 sf.pos=9041309;
 if (YBPw(Vattr))
 {
  sf.pos=9041310;
  ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(VhtmlSmallAttrStart, ((Tc*)&Y1Vq), VhtmlSmallAttrEnd));
 }
 sf.pos=9041311;
 Vvis = ((YVd6(Vattr)) ? (Y9CD(Vattr)) : (1));
 sf.pos=9041312;
 if ((Vvis == 1))
 {
  sf.pos=9041313;
  if (((Apage->Vparent == NULL) || !(YVep(Apage->Vparent->Vattr))))
  {
   sf.pos=9041314;
   Vvis = 7;
  }
  else {
  sf.pos=9041315;
 if ((Yr4g(Apage->Vparent->Vattr) != 1))
  {
   sf.pos=9041316;
   Vvis = Yr4g(Apage->Vparent->Vattr);
  }
  else
  {
   sf.pos=9041317;
   Vvis = 6;
  }
  }
 }
 sf.pos=9041318;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(VhtmlSmallAttrStart, ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis)), VhtmlSmallAttrEnd));
 sf.pos=9041319;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YwPS));
 sf.pos=9041320;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YNG2));
 sf.pos=9041321;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentStart);
 sf.pos=9041322;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Apage->Vheader);
 sf.pos=9041323;
 YaYd(Apage, Vout);
 sf.pos=9041324;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&YBWA));
 sf.pos=9041325;
 Vdone = Yh95(NULL);
 sf.pos=9041326;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Ytst(Apage->Vsummary, Vdone));
 sf.pos=9041327;
 YO3Z(Apage, Vdone, Vout);
 sf.pos=9041328;
 YXA6(Apage, Vout);
 sf.pos=9041329;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&YADm));
 sf.pos=9041330;
 Ymvz(Apage, Vout);
 sf.pos=9041331;
 YpPK(Apage, Vout);
 sf.pos=9041332;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentEnd);
 sf.pos=9041333;
 ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Apage->Vtail);
 sf.pos=9041334;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlFooter);
 topFrame = sf.prev;
 return;
}
void YaYd(YwDJ *Apage, Tr Aout) {
 Zsf sf;
 Tl *Zf1 = NULL;
 Tc *Vimpl = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9076600;
 if ((ZListSize(Apage->Vimplements) > 0))
 {
  sf.pos=9076601;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YAtSa));
 }
 sf.pos=9076602;
 {
  Tfl Zf1i;
  Zf1 = Apage->Vimplements;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vimpl;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9076603;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ZcS3(((Tc*)&YlM6), Yiyv(Vimpl, 0), ((Tc*)&YP3b)));
  sf.pos=9076604;
  }
 }
 sf.pos=9076605;
 if ((ZListSize(Apage->Vimplements) > 0))
 {
  sf.pos=9076606;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YAtSa));
 }
 topFrame = sf.prev;
 return;
}
void Ymvz(YwDJ *Apage, Tr Aout) {
 Zsf sf;
 Tl *VclassNames = NULL;
 Td *Zf1 = NULL;
 YwDJ *Vp = 0;
 Tl *Zf2 = NULL;
 Tc *Vimpl = NULL;
 Tl *Zf21 = NULL;
 Tc *Vn = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=706900;
 VclassNames = ZnewList((Tt*)&string__T, 0);
 sf.pos=706901;
 {
  Tfd Zf1i;
  Zf1 = Vpages;
  Zf1i.d = Zf1;
  Zf1i.keyp = NULL;
  Zf1i.valp = (void*)&Vp;
  for (ZforDictStart(&Zf1i); ZforDictCont(&Zf1i); ZforDictNext(&Zf1i)) {
  sf.pos=706902;
  {
   Tfl Zf2i;
   Zf2 = Vp->Vimplements;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vimpl;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=706903;
   if ((ZstringCmp(Vimpl, Apage->VfullName) == 0))
   {
    sf.pos=706904;
    ZLap((Tl*)VclassNames, (Tz)(void*)Vp->VfullName);
   }
   sf.pos=706905;
   }
  }
  sf.pos=706906;
  }
 }
 sf.pos=706907;
 if ((ZListSize(VclassNames) > 0))
 {
  sf.pos=706908;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YujZ));
  sf.pos=706909;
  ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, VhtmlIndentStart);
  sf.pos=706910;
  {
   Tfl Zf21i;
   Zf21 = VclassNames;
   Zf21i.l = Zf21;
   Zf21i.valp = (void*)&Vn;
   Zf21i.i = 0;
   for (; ZforListPtrCont(&Zf21i); ) {
   sf.pos=706911;
   ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ZcS3(((Tc*)&Ydgk), Yiyv(Vn, 0), ((Tc*)&YP3b)));
   sf.pos=706912;
   }
  }
  sf.pos=706913;
  ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, VhtmlIndentEnd);
  sf.pos=706914;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YAtSa));
 }
 topFrame = sf.prev;
 return;
}
void YpPK(YwDJ *Apage, Tr Aout) {
 Zsf sf;
 Tl *VclassNames = NULL;
 Td *Zf1 = NULL;
 YwDJ *Vp = 0;
 Tl *Zf2 = NULL;
 Tc *Vn = NULL;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6700800;
 VclassNames = ZnewList((Tt*)&string__T, 0);
 sf.pos=6700801;
 {
  Tfd Zf1i;
  Zf1 = Vpages;
  Zf1i.d = Zf1;
  Zf1i.keyp = NULL;
  Zf1i.valp = (void*)&Vp;
  for (ZforDictStart(&Zf1i); ZforDictCont(&Zf1i); ZforDictNext(&Zf1i)) {
  sf.pos=6700802;
  if ((((Vp->Vextends != NULL) && (ZstringCmp(YoRE(Vp), (t0 = Apage->VfullName)) == 0)) && !(Vp->Vhide)))
  {
   sf.pos=6700803;
   ZLap((Tl*)VclassNames, (Tz)(void*)Vp->VfullName);
  }
  sf.pos=6700804;
  }
 }
 sf.pos=6700805;
 if ((ZListSize(VclassNames) > 0))
 {
  sf.pos=6700806;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YOOI));
  sf.pos=6700807;
  ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, VhtmlIndentStart);
  sf.pos=6700808;
  {
   Tfl Zf2i;
   Zf2 = ZstringListSort(VclassNames, 1);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vn;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=6700809;
   ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ZcS3(((Tc*)&Ydgk), Yiyv(Vn, 0), ((Tc*)&YP3b)));
   sf.pos=6700810;
   }
  }
  sf.pos=6700811;
  ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, VhtmlIndentEnd);
  sf.pos=6700812;
  ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, ((Tc*)&YAtSa));
 }
 topFrame = sf.prev;
 return;
}
void YO3Z(YwDJ *Apage, Yhqr *Adone, Tr Aout) {
 Zsf sf;
 Tc *VparentName = NULL;
 YwDJ *VparentPage = 0;
 Tc *Vtext = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7692000;
 if ((Apage->Vextends == NULL))
 {
  sf.pos=7692001;
  rt = 1;
  goto YG5l;
 }
 sf.pos=7692002;
 VparentName = YoRE(Apage);
 sf.pos=7692003;
 if (ZDictHas(Vpages, (Tz)(void*)VparentName))
 {
  sf.pos=7692004;
  VparentPage = ((YwDJ *)ZDictGetPtr(Vpages, (Tz)(void*)VparentName));
  sf.pos=7692005;
  Vtext = Ytst(VparentPage->Vsummary, Adone);
  sf.pos=7692006;
  if ((ZbyteStringSize(Vtext) == 0))
  {
   sf.pos=7692007;
   ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, ZcS3(((Tc*)&Y3cs), Yiyv(VparentPage->VfullName, 0), ((Tc*)&YtoW)));
  }
  else
  {
   sf.pos=7692008;
   ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, ZcS3(((Tc*)&YJ6I), Yiyv(VparentPage->VfullName, 0), ((Tc*)&YdSD)));
   sf.pos=7692009;
   ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, Vtext);
  }
  sf.pos=7692010;
  YO3Z(VparentPage, Adone, Aout);
 }
YG5l:
 topFrame = sf.prev;
 return;
}
void YXA6(YwDJ *Apage, Tr Aout) {
 void *p2;
 Zsf sf;
 Tl *Zf1 = NULL;
 Tc *Vpiece = NULL;
 YwDJ *VpiecePage = 0;
 Tc *Vtext = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8027700;
 {
  Tfl Zf1i;
  Zf1 = ((p2 = (Apage->Vincludes)) == NULL ? (ZnewList((Tt*)&string__T, 0)) : p2);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vpiece;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8027701;
  if (ZDictHas(Vpages, (Tz)(void*)Vpiece))
  {
   sf.pos=8027702;
   VpiecePage = ((YwDJ *)ZDictGetPtr(Vpages, (Tz)(void*)Vpiece));
   sf.pos=8027703;
   Vtext = Ytst(VpiecePage->Vsummary, Yh95(NULL));
   sf.pos=8027704;
   if ((ZbyteStringSize(Vtext) != 0))
   {
    sf.pos=8027705;
    ((Ts (*)(void*, Tc*))(Aout.table[11]))(Aout.ptr, ZcS3(((Tc*)&YV4I), Yiyv(VpiecePage->VfullName, 0), ((Tc*)&YdSD)));
    sf.pos=8027706;
    ((Ts (*)(void*, Tc*))(Aout.table[1]))(Aout.ptr, Vtext);
   }
  }
  sf.pos=8027707;
  }
 }
 topFrame = sf.prev;
 return;
}
void YyrL(Tc *AoutDirName) {
 Zsf sf;
 Tr Vout = {NULL};
 Tl *Zf1 = NULL;
 Tc *Vkey = NULL;
 YwDJ *Vpage = 0;
 Tc *VchildName = NULL;
 Tl *Zf4 = NULL;
 YwDJ *Vchild = 0;
 Tl *Zf11 = NULL;
 Tc *Vname = NULL;
 Tl *Zf12 = NULL;
 Tc *Vkey1 = NULL;
 YwDJ *Vpage1 = 0;
 Yo7T *VclassList = 0;
 Yo7T *VmoduleList = 0;
 Yo7T *VpageList = 0;
 Tr Zf2 = {NULL};
 YwDJ *Vpage2 = 0;
 Tl *t0 = NULL;
 Tc *t1 = NULL;
 Tc *t2 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=258000;
 Vout = YHH0(AoutDirName, ((Tc*)&YZ_F), ((Tc*)&YZ_F), NULL);
 sf.pos=258001;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&Y2BD));
 sf.pos=258002;
 VclassList = YFR3(NULL);
 sf.pos=258003;
 VmoduleList = YFR3(NULL);
 sf.pos=258004;
 {
  Tfl Zf1i;
  Zf1 = ZstringListSort(ZDictKeys(Vpages, 0), 1);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vkey;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=258005;
  Vpage = ((YwDJ *)ZDictGetPtr(Vpages, (Tz)(void*)Vkey));
  sf.pos=258006;
  if ((((Vpage->Vparent == NULL) && !(Vpage->VnoIndex)) && !(Vpage->Vhide)))
  {
   Tb VisClass;
   VisClass = 0;
   sf.pos=258007;
   if ((ZListSize(Vpage->Vchildren) == 1))
   {
    sf.pos=258008;
    VchildName = ((YwDJ *)ZListGetPtr(Vpage->Vchildren, 0))->Vname;
    sf.pos=258009;
    if ((((((ZDictHas(VknownTypes, (Tz)(void*)VchildName) || (ZstringCmp(VchildName, ((Tc*)&Ymmq)) == 0)) || (ZstringCmp(VchildName, ((Tc*)&YAxF)) == 0)) || (ZstringCmp(VchildName, ((Tc*)&YJR6)) == 0)) || (ZstringCmp(VchildName, ((Tc*)&Yl4z)) == 0)) || (ZstringCmp(VchildName, ((Tc*)&YBHe)) == 0)))
    {
     sf.pos=258010;
     VisClass = 1;
     sf.pos=258011;
     Vpage = ((YwDJ *)ZListGetPtr(Vpage->Vchildren, 0));
    }
   }
   else {
   sf.pos=258012;
 if ((ZstringCmp(Vpage->Vname, ((Tc*)&YVLC)) == 0))
   {
    sf.pos=258013;
    {
     Tfl Zf4i;
     Zf4 = Vpage->Vchildren;
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Vchild;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=258014;
     if (((((ZstringCmp(Vchild->Vname, ((Tc*)&YnY0)) == 0) || (ZstringCmp(Vchild->Vname, ((Tc*)&YeBN)) == 0)) || (ZstringCmp(Vchild->Vname, ((Tc*)&YzBS)) == 0)) || (ZstringCmp(Vchild->Vname, ((Tc*)&YTdt)) == 0)))
     {
      sf.pos=258015;
      Ygeh(VclassList, Vchild);
     }
     sf.pos=258016;
     }
    }
   }
   }
   sf.pos=258017;
   if (VisClass)
   {
    sf.pos=258018;
    Ygeh(VclassList, Vpage);
   }
   else
   {
    sf.pos=258019;
    Ygeh(VmoduleList, Vpage);
   }
  }
  sf.pos=258020;
  }
 }
 sf.pos=258021;
 {
  Tfl Zf11i;
  Zf11 = (t0 = ZnewList((Tt*)&Yo7T__T, 2), ZLap((Tl*)t0, (Tz)(void*)VclassList), ZLap((Tl*)t0, (Tz)(void*)VmoduleList));
  Zf11i.l = Zf11;
  Zf11i.valp = (void*)&VpageList;
  Zf11i.i = 0;
  for (; ZforListPtrCont(&Zf11i); ) {
  sf.pos=258022;
  ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&YIZD));
  sf.pos=258023;
  ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, (((VpageList == VclassList)) ? (((Tc*)&Ydjn)) : (((Tc*)&YPHA))));
  sf.pos=258024;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YJSS));
  sf.pos=258025;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentStart);
  sf.pos=258026;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YBWA));
  sf.pos=258027;
  {
   Zf2 = YOv9(VpageList);
   for (; ((Tb (*)(void*))(Zf2.table[1]))(Zf2.ptr) && (Vpage2 = ((YwDJ* (*)(void*))(Zf2.table[2]))(Zf2.ptr), 1); ) {
   sf.pos=258028;
   Vname = Vpage2->Vname;
   sf.pos=258029;
   if ((((ZstringSize(Vname) > 1) && isupper(ZstringGetChar(Vname, 0))) && islower(ZstringGetChar(Vname, 1))))
   {
    sf.pos=258030;
    Vname = ZcS((t2 = ZintAsString(tolower(ZstringGetChar(Vname, 0)))), (t1 = ZstringSlice(Vname, 1, -1, 0)));
   }
   sf.pos=258031;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&YgSX));
   sf.pos=258032;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(VhtmlKeyStart, ZstringToUpper(Vpage2->Vtype), VhtmlKeyEnd));
   sf.pos=258033;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&Y9Qy));
   sf.pos=258034;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Yiyva(Vpage2->VfullName, Vname, 1));
   sf.pos=258035;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(((Tc*)&Yvkb), Vpage2->Vcomment, ((Tc*)&YNaw)));
   sf.pos=258036;
   }
  }
  sf.pos=258037;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YADm));
  sf.pos=258038;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentEnd);
  sf.pos=258039;
  }
 }
 sf.pos=258040;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YTSL));
 sf.pos=258041;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentStart);
 sf.pos=258042;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YBWA));
 sf.pos=258043;
 {
  Tfl Zf12i;
  Zf12 = ZstringListSort(ZDictKeys(Vpages, 0), 1);
  Zf12i.l = Zf12;
  Zf12i.valp = (void*)&Vkey1;
  Zf12i.i = 0;
  for (; ZforListPtrCont(&Zf12i); ) {
  sf.pos=258044;
  Vpage1 = ((YwDJ *)ZDictGetPtr(Vpages, (Tz)(void*)Vkey1));
  sf.pos=258045;
  if ((((Vpage1->Vparent != NULL) && !(Vpage1->VnoIndex)) && !(Vpage1->Vhide)))
  {
   sf.pos=258046;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&YgSX));
   sf.pos=258047;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(VhtmlKeyStart, ZstringToUpper(Vpage1->Vtype), VhtmlKeyEnd));
   sf.pos=258048;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ((Tc*)&Y9Qy));
   sf.pos=258049;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, Yiyv(Vpage1->VfullName, 1));
   sf.pos=258050;
   ((Ts (*)(void*, Tc*))(Vout.table[1]))(Vout.ptr, ZcS3(((Tc*)&Yvkb), Vpage1->Vcomment, ((Tc*)&YNaw)));
  }
  sf.pos=258051;
  }
 }
 sf.pos=258052;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YADm));
 sf.pos=258053;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlIndentEnd);
 sf.pos=258054;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlFooter);
 topFrame = sf.prev;
 return;
}
void Ywyp(YXCg *Astmt, Tl *AlibStatements, YrBF *Aparent) {
 Zsf sf;
 YYIi *Vdecl = 0;
 Tc *Vname = NULL;
 Tc *Vwhat = NULL;
 YRBza *Vtype = 0;
 YJON *Vattr = 0;
 YwDJ *Vpage = 0;
 YrBF *VthisClass = 0;
 YftY *Vclass = 0;
 Tl *Vstatements = NULL;
 Tl *VsharedStatements = NULL;
 YFN2 *Venum = 0;
 YfQg *Vbits = 0;
 YaHa *Vitems = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7587100;
 Vdecl = YjGb(Astmt);
 sf.pos=7587101;
 Vname = YdHK(Vdecl);
 sf.pos=7587102;
 if ((((Aparent != NULL) && Aparent->VisLibModule) && ((ZstringStartsWith(Vname, ((Tc*)&YpSv), 0) || ZstringStartsWith(Vname, ((Tc*)&YPu_), 0)))))
 {
  sf.pos=7587103;
  if ((AlibStatements == NULL))
  {
   sf.pos=7587104;
   rt = 1;
   goto YxbH;
  }
  sf.pos=7587105;
  Vname = ZstringSlice(Vname, 5, -1, 0);
YxbH:
  if (rt) goto Y8ok;
 }
 sf.pos=7587106;
 Vitems = Y9vTa(NULL, Aparent, Astmt, 0);
 sf.pos=7587107;
 switch (YuqZ(Astmt))
 {
 case 3:
  {
   sf.pos=7587108;
   if ((YXDk(Y1Yr(Vdecl)) == 31))
   {
    sf.pos=7587109;
    Vwhat = ((Tc*)&YhgN);
   }
   else {
   sf.pos=7587110;
 if ((YXDk(Y1Yr(Vdecl)) == 29))
   {
    sf.pos=7587111;
    Vwhat = ((Tc*)&YeJk);
   }
   else {
   sf.pos=7587112;
 if ((YXDk(Y1Yr(Vdecl)) == 33))
   {
    sf.pos=7587113;
    Vwhat = ((Tc*)&YfDf);
   }
   else
   {
    sf.pos=7587114;
    Vwhat = ((Tc*)&Ya4C);
   }
   }}
    break;
  }
 case 5:
  {
   sf.pos=7587115;
   Vwhat = ((Tc*)&Y89Q);
    break;
  }
 case 4:
  {
   sf.pos=7587116;
   Vwhat = ((Tc*)&Y4wh);
    break;
  }
 case 7:
  {
   sf.pos=7587117;
   Vwhat = ((Tc*)&YXek);
    break;
  }
 }
 sf.pos=7587118;
 Vtype = Y1Yr(Vdecl);
 sf.pos=7587119;
 Vattr = ((YkZu(Vtype)) ? (YDxP(Vtype)) : (YsCX(NULL)));
 sf.pos=7587120;
 Vpage = YYjF(NULL, Aparent, Vname, Astmt, Vattr, Vwhat, Vitems);
 sf.pos=7587121;
 VthisClass = YSjh(NULL, Vattr, Aparent, Vpage, Vname, Vitems);
 sf.pos=7587122;
 if ((AlibStatements != NULL))
 {
  sf.pos=7587123;
  VthisClass->VisLibClass = 1;
 }
 sf.pos=7587124;
 if ((((Aparent != NULL) && (Aparent->Vpage != NULL)) && (ZstringCmp(Vpage->Vname, ((Tc*)&YKGB)) != 0)))
 {
  sf.pos=7587125;
  ZLap((Tl*)Aparent->Vpage->Vchildren, (Tz)(void*)Vpage);
 }
 sf.pos=7587126;
 if ((Vitems != NULL))
 {
  sf.pos=7587127;
  YXei(Vpage, YLwI(Vitems->Vsummary));
  sf.pos=7587128;
  YXei(Vpage, YLwI(Vitems->Vdetails));
 }
 sf.pos=7587129;
 switch (YuqZ(Astmt))
 {
 case 3:
  {
   sf.pos=7587130;
   Vclass = YJgu(Y1Yr(Vdecl));
   sf.pos=7587131;
   if ((AlibStatements != NULL))
   {
    sf.pos=7587132;
    Vstatements = AlibStatements;
   }
   else {
   sf.pos=7587133;
 if (YskK(Vclass))
   {
    sf.pos=7587134;
    Vstatements = YGyt(Vclass);
   }
   }
   sf.pos=7587135;
   if (YPer(Vclass))
   {
    sf.pos=7587136;
    VsharedStatements = Yb8Y(Ykbi(Vclass));
   }
   sf.pos=7587137;
   if (YHI7(Vclass))
   {
    sf.pos=7587138;
    Vpage->VtypeSpec = YauLa(YrvP(Vclass), NULL, VthisClass, 0, 1);
   }
    break;
  }
 case 5:
  {
   sf.pos=7587139;
   Venum = YdRA(Y1Yr(Vdecl));
   sf.pos=7587140;
   if (YohH(Venum))
   {
    sf.pos=7587141;
    Vstatements = YjCl(Venum);
   }
    break;
  }
 case 4:
  {
   sf.pos=7587142;
   Vbits = YDOm(Y1Yr(Vdecl));
   sf.pos=7587143;
   if (YVXf(Vbits))
   {
    sf.pos=7587144;
    Vstatements = Y4e2(Vbits);
   }
    break;
  }
 }
 sf.pos=7587145;
 Vpage->Vsummary = Yjji(Vstatements, VsharedStatements, Aparent, VthisClass, Vpage->VfullName);
 sf.pos=7587146;
 if (((Vclass != NULL) && YXx6(Vclass)))
 {
  sf.pos=7587147;
  YsLl(Vpage, Aparent, YVqZ(Vclass));
 }
 sf.pos=7587148;
 if (((Vclass != NULL) && YCwH(Vclass)))
 {
  Ti VtypeIdx;
  sf.pos=7587149;
  Vpage->Vextends = Y0ZR(YVVa(Vclass), Aparent);
  sf.pos=7587150;
  VtypeIdx = ZstringFind(Vpage->Vextends, ((Tc*)&YU_a), 0);
  sf.pos=7587151;
  if ((VtypeIdx > 0))
  {
   sf.pos=7587152;
   Vpage->VextendsNoType = ZstringSlice(Vpage->Vextends, 0, (VtypeIdx - 1), 0);
  }
  else
  {
   sf.pos=7587153;
   Vpage->VextendsNoType = Vpage->Vextends;
  }
 }
 sf.pos=7587154;
 Vpage->Vincludes = YSvC(Vstatements, Aparent, VthisClass);
 sf.pos=7587155;
 if ((YuqZ(Astmt) == 5))
 {
  sf.pos=7587156;
  YWvO(Vpage, YZi9(YdRA(Y1Yr(Vdecl))));
 }
 sf.pos=7587157;
 if ((YuqZ(Astmt) == 7))
 {
  sf.pos=7587158;
  YWvO(Vpage, YdL1(Astmt, Aparent, VthisClass));
 }
 else
 {
  sf.pos=7587159;
  YWvO(Vpage, Y20k(Vstatements, VsharedStatements, Aparent, VthisClass));
 }
 sf.pos=7587160;
 YWvO(Vpage, YJgp(Vitems, Aparent));
Y8ok:
 topFrame = sf.prev;
 return;
}
void YFk5(YXCg *Astmt) {
 Tb VisLibModule;
 Zsf sf;
 YYIi *Vdecl = 0;
 Y2wP *Vmodule = 0;
 Tc *Vname = NULL;
 Tc *VclassName = NULL;
 YJON *Vattr = 0;
 YwDJ *Vpage = 0;
 YrBF *Vparent = 0;
 Tl *Vstatements = NULL;
 YaHa *Vitems = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3459900;
 Vdecl = YjGb(Astmt);
 sf.pos=3459901;
 Vmodule = Y8Ec(Y1Yr(Vdecl));
 sf.pos=3459902;
 Vitems = Y9vTa(NULL, NULL, Astmt, 0);
 sf.pos=3459903;
 Vname = YdHK(Vdecl);
 VisLibModule = 0;
 sf.pos=3459904;
 if (ZstringEndsWith(Vname, ((Tc*)&YcKD), 0))
 {
  sf.pos=3459905;
  VisLibModule = 1;
  sf.pos=3459906;
  Vname = ZstringSlice(Vname, 0, -7, 0);
 }
 sf.pos=3459907;
 Vattr = YDxP(Y1Yr(Vdecl));
 sf.pos=3459908;
 Vpage = YYjF(NULL, NULL, Vname, Astmt, Vattr, ((Tc*)&YKwD), Vitems);
 sf.pos=3459909;
 Vparent = YSjh(NULL, Vattr, NULL, Vpage, Vname, Vitems);
 sf.pos=3459910;
 Vparent->VisLibModule = VisLibModule;
 sf.pos=3459911;
 if ((Vitems != NULL))
 {
  sf.pos=3459912;
  YXei(Vpage, YLwI(Vitems->Vsummary));
  sf.pos=3459913;
  YXei(Vpage, YLwI(Vitems->Vdetails));
 }
 sf.pos=3459914;
 if (Y13u(Vmodule))
 {
  sf.pos=3459915;
  Vstatements = YiW9(Vmodule);
 }
 sf.pos=3459916;
 if ((Vstatements != NULL))
 {
  sf.pos=3459917;
  YBfF(Vstatements, Vparent);
  sf.pos=3459918;
  if (VisLibModule)
  {
   sf.pos=3459919;
   YhbZ(Vstatements, Vparent);
  }
 }
 sf.pos=3459920;
 Vpage->Vsummary = Yjji(Vstatements, NULL, Vparent, NULL, Vname);
 sf.pos=3459921;
 YWvO(Vpage, Y20k(Vstatements, NULL, Vparent, NULL));
 sf.pos=3459922;
 YWvO(Vpage, YJgp(Vitems, NULL));
 topFrame = sf.prev;
 return;
}
void Ye4o(YXCg *Astmt, YrBF *Aparent) {
 Zsf sf;
 YoDF *Valias = 0;
 Tc *VleftName = NULL;
 YwDJ *Vpage = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1245900;
 Valias = Y9au(Y1Yr(YjGb(Astmt)));
 sf.pos=1245901;
 VleftName = Y0ZR(YdCW(Valias), Aparent);
 sf.pos=1245902;
 if (!(ZDictHas(Vpages, (Tz)(void*)VleftName)))
 {
  Ti Vi;
  sf.pos=1245903;
  if (ZDictHas(Vmethods, (Tz)(void*)VleftName))
  {
   sf.pos=1245904;
   YlIy(Valias, ((YXCg *)ZDictGetPtr(Vmethods, (Tz)(void*)VleftName)));
   sf.pos=1245905;
   rt = 1;
   goto YDZp;
  }
  sf.pos=1245906;
  Vi = ZstringFind(VleftName, ((Tc*)&YcKD), 0);
  sf.pos=1245907;
  if ((Vi > 0))
  {
   sf.pos=1245908;
   VleftName = ZcS((t1 = ZstringSlice(VleftName, 0, (Vi - 1), 0)), (t0 = ZstringSlice(VleftName, (Vi + 6), -1, 0)));
  }
  sf.pos=1245909;
  if (!(ZDictHas(Vpages, (Tz)(void*)VleftName)))
  {
   sf.pos=1245910;
   if (ZDictHas(Vmethods, (Tz)(void*)VleftName))
   {
    sf.pos=1245911;
    YlIy(Valias, ((YXCg *)ZDictGetPtr(Vmethods, (Tz)(void*)VleftName)));
    sf.pos=1245912;
    rt = 1;
    goto YyAr;
   }
   sf.pos=1245913;
   YlIy(Valias, Astmt);
   sf.pos=1245914;
   Ywyp(Astmt, NULL, Aparent);
   sf.pos=1245915;
YyAr:
   ;
   rt = 1;
   goto YDZp;
  }
YDZp:
  if (rt) goto Ypcm;
 }
 sf.pos=1245916;
 Vpage = ((YwDJ *)ZDictGetPtr(Vpages, (Tz)(void*)VleftName));
 sf.pos=1245917;
 ZDictRemovePtr(Vpages, (Tz)(void*)VleftName, 1);
 sf.pos=1245918;
 Ywyp(Vpage->Vstmt, NULL, Aparent);
 sf.pos=1245919;
 YlIy(Y9au(Y1Yr(YjGb(Astmt))), Vpage->Vstmt);
Ypcm:
 topFrame = sf.prev;
 return;
}
YT98 *Y5WC(YT98 *t, Tc *Aname, Tc *Arow) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=7936500; t = Za(sizeof(YT98));}
 sf.pos=7936501;
 t->VitemName = Aname;
 sf.pos=7936502;
 t->VtableRow = Arow;
 topFrame = sf.prev;
 return t;
}
To ToYT98[] = {
 {2, 0},
 {0, (Tt*)&string__T}, /* itemName */
 {0, (Tt*)&string__T}, /* tableRow */
};
Tto YT98__T = {390, (Tc*)&Y0G4, 0, ToYT98};
YHCf *Yjz5(YHCf *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=3719500; t = Za(sizeof(YHCf));}
 sf.pos=3719501;
 t->Ventries = ZnewList((Tt*)&YT98__T, 0);
 topFrame = sf.prev;
 return t;
}
Ti YOvr(YHCf *t) {
 Zsf sf;
 Ti r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=1608400;
  ZthrowThisNil();
 }
 sf.pos=1608401;
 r = t->Vcount;
 topFrame = sf.prev;
 return r;
}
void YVWi(YHCf *t, Tc *AitemName, Tc *Arow) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5675800;
  ZthrowThisNil();
 }
 sf.pos=5675801;
 ZLap((Tl*)t->Ventries, (Tz)(void*)Y5WC(NULL, AitemName, Arow));
 sf.pos=5675802;
 if (((ZbyteStringSize(AitemName) != 0) && (Arow != NULL)))
 {
  sf.pos=5675803;
  ++(t->Vcount);
 }
 topFrame = sf.prev;
 return;
}
void YAEk(YHCf *t) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=5827800;
  ZthrowThisNil();
 }
 sf.pos=5827801;
 if (((ZListSize(t->Ventries) > 0) && (ZstringCmp(((YT98 *)ZListGetPtr(t->Ventries, (ZListSize(t->Ventries) - 1)))->VtableRow, VhtmlTableSep) != 0)))
 {
  sf.pos=5827802;
  ZLap((Tl*)t->Ventries, (Tz)(void*)Y5WC(NULL, ((Tc*)&Ya), VhtmlTableSep));
 }
 topFrame = sf.prev;
 return;
}
void Y2QV(YHCf *t, Tc *Atext) {
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=4124700;
  ZthrowThisNil();
 }
 sf.pos=4124701;
 ZLap((Tl*)t->Ventries, (Tz)(void*)Y5WC(NULL, ((Tc*)&Ya), ZcS3(((Tc*)&Yf6C), Atext, ((Tc*)&YtoW))));
 topFrame = sf.prev;
 return;
}
Tc *Ytst(YHCf *t, Yhqr *Adone) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tl *Zf1 = NULL;
 YT98 *Ve = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7646700;
  ZthrowThisNil();
 }
 sf.pos=7646701;
 Vret = ((Tc*)&Ya);
 sf.pos=7646702;
 {
  Tfl Zf1i;
  Zf1 = t->Ventries;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Ve;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=7646703;
  if (((ZbyteStringSize(Ve->VitemName) == 0) || !(YyHa(Adone, Ve->VitemName))))
  {
   sf.pos=7646704;
   if ((ZbyteStringSize(Ve->VitemName) != 0))
   {
    sf.pos=7646705;
    YGMT(Adone, Ve->VitemName);
   }
   sf.pos=7646706;
   if ((Ve->VtableRow != NULL))
   {
    sf.pos=7646707;
    Vret =  ZcS(Vret, Ve->VtableRow);
   }
  }
  sf.pos=7646708;
  }
 }
 sf.pos=7646709;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
To ToYHCf[] = {
 {1, 0},
 {0, (Tt*)&list__T}, /* entries */
};
Tto YHCf__T = {390, (Tc*)&Yhsb, 0, ToYHCf};
YHCf *Yjji(Tl *Astatements, Tl *AsharedStatements, YrBF *Aparent, YrBF *AthisClass, Tc *AitemName) {
 Ti Vl;
 Zsf sf;
 YHCf *r = 0;
 YHCf *Vsummary = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2975000;
 Vsummary = Yjz5(NULL);
 sf.pos=2975001;
 Vl = YOvr(Vsummary);
 sf.pos=2975002;
 Yhld(Astatements, Aparent, AthisClass, Vsummary);
 sf.pos=2975003;
 if ((AsharedStatements != NULL))
 {
  sf.pos=2975004;
  Yhld(AsharedStatements, Aparent, AthisClass, Vsummary);
 }
 sf.pos=2975005;
 if ((YOvr(Vsummary) > Vl))
 {
  sf.pos=2975006;
  YAEk(Vsummary);
 }
 sf.pos=2975007;
 Vl = YOvr(Vsummary);
 sf.pos=2975008;
 YVrF(Astatements, (AthisClass != NULL), AitemName, Aparent, AthisClass, Vsummary);
 sf.pos=2975009;
 if ((YOvr(Vsummary) > Vl))
 {
  sf.pos=2975010;
  YAEk(Vsummary);
 }
 sf.pos=2975011;
 if ((AsharedStatements != NULL))
 {
  sf.pos=2975012;
  Vl = YOvr(Vsummary);
  sf.pos=2975013;
  YVrF(AsharedStatements, 0, AitemName, Aparent, AthisClass, Vsummary);
  sf.pos=2975014;
  if ((YOvr(Vsummary) > Vl))
  {
   sf.pos=2975015;
   YAEk(Vsummary);
  }
 }
 sf.pos=2975016;
 Vl = YOvr(Vsummary);
 sf.pos=2975017;
 YjWd(Astatements, (AthisClass != NULL), 0, AitemName, Aparent, AthisClass, Vsummary);
 sf.pos=2975018;
 if ((YOvr(Vsummary) > Vl))
 {
  sf.pos=2975019;
  YAEk(Vsummary);
 }
 sf.pos=2975020;
 if (((AthisClass != NULL) && AthisClass->VisLibClass))
 {
  sf.pos=2975021;
  Vl = YOvr(Vsummary);
  sf.pos=2975022;
  YjWd(Astatements, 1, 1, AitemName, Aparent, AthisClass, Vsummary);
  sf.pos=2975023;
  if ((YOvr(Vsummary) > Vl))
  {
   sf.pos=2975024;
   YAEk(Vsummary);
  }
 }
 sf.pos=2975025;
 if ((AsharedStatements != NULL))
 {
  sf.pos=2975026;
  Vl = YOvr(Vsummary);
  sf.pos=2975027;
  YjWd(AsharedStatements, 0, 0, AitemName, Aparent, AthisClass, Vsummary);
  sf.pos=2975028;
  if ((YOvr(Vsummary) > Vl))
  {
   sf.pos=2975029;
   YAEk(Vsummary);
  }
 }
 sf.pos=2975030;
 r = Vsummary;
 topFrame = sf.prev;
 return r;
}
void Yhld(Tl *Astatements, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary) {
 void *p3;
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 YoDF *Valias = 0;
 YXCg *VclassStmt = 0;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=7932000;
 {
  Tfl Zf1i;
  Zf1 = ((p3 = (Astatements)) == NULL ? (ZnewList((Tt*)&YXCg__T, 0)) : p3);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=7932001;
  switch (YuqZ(Vstmt))
  {
  case 7:
   {
    sf.pos=7932002;
    Valias = Y9au(Y1Yr(YjGb(Vstmt)));
    sf.pos=7932003;
    if (YNTP(Valias))
    {
     sf.pos=7932004;
     VclassStmt = YiDy(Valias);
     sf.pos=7932005;
     if (((((YuqZ(VclassStmt) == 3) || (YuqZ(VclassStmt) == 4)) || (YuqZ(VclassStmt) == 5)) || (YuqZ(VclassStmt) == 7)))
     {
      sf.pos=7932006;
      YxMt(VclassStmt, Aparent, Asummary);
     }
    }
     break;
   }
  case 13:
   {
    void *p4;
    sf.pos=7932007;
    Vcond = YCoj(Vstmt);
    sf.pos=7932008;
    if (Yzno(Vcond))
    {
     sf.pos=7932009;
     Yhld(Yb8Y(Y1Yl(Vcond)), Aparent, AthisClass, Asummary);
    }
    sf.pos=7932010;
    {
     Tfl Zf4i;
     Zf4 = ((p4 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p4);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=7932011;
     if (Yzno(Velseif))
     {
      sf.pos=7932012;
      Yhld(Yb8Y(Y1Yl(Velseif)), Aparent, AthisClass, Asummary);
     }
     sf.pos=7932013;
     }
    }
    sf.pos=7932014;
    if (Y3qR(Vcond))
    {
     sf.pos=7932015;
     Yhld(Yb8Y(Ym_a(Vcond)), Aparent, AthisClass, Asummary);
    }
     break;
   }
  case 30:
   {
    sf.pos=7932016;
    if (Ycfv(Vstmt))
    {
     sf.pos=7932017;
     Yhld(Yb8Y(YFQs(Vstmt)), Aparent, AthisClass, Asummary);
    }
     break;
   }
  case 3:
  case 4:
  case 5:
   {
    sf.pos=7932018;
    YxMt(Vstmt, Aparent, Asummary);
     break;
   }
  }
  sf.pos=7932019;
  }
 }
 topFrame = sf.prev;
 return;
}
Te YDXu(YJON *Aattr, YrBF *Aparent) {
 Te Vvis;
 Zsf sf;
 Te r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vvis = 0;
 sf.pos=493700;
 if (YVd6(Aattr))
 {
  sf.pos=493701;
  Vvis = Y9CD(Aattr);
 }
 sf.pos=493702;
 if (((Vvis == 1) || (Vvis == 0)))
 {
  sf.pos=493703;
  if ((Aparent == NULL))
  {
   sf.pos=493704;
   Vvis = 7;
  }
  else {
  sf.pos=493705;
 if ((YVep(Aparent->Vattr) && (Yr4g(Aparent->Vattr) != 1)))
  {
   sf.pos=493706;
   Vvis = Yr4g(Aparent->Vattr);
  }
  else
  {
   sf.pos=493707;
   Vvis = 6;
  }
  }
 }
 sf.pos=493708;
 r = Vvis;
 topFrame = sf.prev;
 return r;
}
void YxMt(YXCg *Astmt, YrBF *Aparent, YHCf *Asummary) {
 Zsf sf;
 YYIi *Vdecl = 0;
 Tc *Vname = NULL;
 Tc *Vwhat = NULL;
 Tc *Vret = NULL;
 YJON *Vattr = 0;
 YaHa *Vdi = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=602000;
 Vdecl = YjGb(Astmt);
 sf.pos=602001;
 Vname = YdHK(Vdecl);
 sf.pos=602002;
 if (Aparent->VisLibModule)
 {
  sf.pos=602003;
  if (ZstringStartsWith(Vname, ((Tc*)&YpSv), 0))
  {
   sf.pos=602004;
   Vname = ZstringSlice(Vname, 5, -1, 0);
  }
  else {
  sf.pos=602005;
 if (ZstringStartsWith(Vname, ((Tc*)&YPu_), 0))
  {
   sf.pos=602006;
   rt = 1;
   goto Y3iX;
  }
  }
Y3iX:
  if (rt) goto YyuX;
 }
 sf.pos=602007;
 switch (YuqZ(Astmt))
 {
 case 3:
  {
   sf.pos=602008;
   if ((YXDk(Y1Yr(Vdecl)) == 31))
   {
    sf.pos=602009;
    Vwhat = ((Tc*)&Y0as);
   }
   else {
   sf.pos=602010;
 if ((YXDk(Y1Yr(Vdecl)) == 29))
   {
    sf.pos=602011;
    Vwhat = ((Tc*)&YMwW);
   }
   else {
   sf.pos=602012;
 if ((YXDk(Y1Yr(Vdecl)) == 33))
   {
    sf.pos=602013;
    Vwhat = ((Tc*)&YNqR);
   }
   else
   {
    sf.pos=602014;
    Vwhat = ((Tc*)&Ya4C);
   }
   }}
    break;
  }
 case 5:
  {
   sf.pos=602015;
   Vwhat = ((Tc*)&YnjG);
    break;
  }
 case 4:
  {
   sf.pos=602016;
   Vwhat = ((Tc*)&YjG6);
    break;
  }
 case 7:
  {
   sf.pos=602017;
   Vwhat = ((Tc*)&Yu2V);
    break;
  }
 }
 sf.pos=602018;
 Vdi = Y9vTb(NULL, Aparent, Vdecl);
 sf.pos=602019;
 if ((Vdi->Vheader != NULL))
 {
  sf.pos=602020;
  YAEk(Asummary);
  sf.pos=602021;
  Y2QV(Asummary, Vdi->Vheader);
 }
 sf.pos=602022;
 if ((Vdi->Vhide || Vdi->VnoIndex))
 {
  sf.pos=602023;
  YVWi(Asummary, Vname, NULL);
 }
 else
 {
  Te Vvis;
  sf.pos=602024;
  Vret = ZcS5(((Tc*)&YgSX), VhtmlKeyStart, Vwhat, VhtmlKeyEnd, ((Tc*)&YhFLa));
  sf.pos=602025;
  Vret =  ZcS(Vret, ZcS(((Tc*)&YbsA), Yy61(Aparent, Vname, NULL)));
  sf.pos=602026;
  if (((YuqZ(Astmt) == 3) && YHI7(YJgu(Y1Yr(Vdecl)))))
  {
   sf.pos=602027;
   Vret =  ZcS(Vret, ZcS3(((Tc*)&YwxW), YauLa(YrvP(YJgu(Y1Yr(Vdecl))), NULL, NULL, 0, 0), ((Tc*)&YveI)));
  }
  sf.pos=602028;
  Vattr = ((YkZu(Y1Yr(Vdecl))) ? (YDxP(Y1Yr(Vdecl))) : (YsCX(NULL)));
  sf.pos=602029;
  Vvis = YDXu(Vattr, Aparent);
  sf.pos=602030;
  Vret =  ZcS(Vret, ZcS3(VhtmlSmallAttrStart, ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis)), VhtmlSmallAttrEnd));
  sf.pos=602031;
  Vret =  ZcS(Vret, ((Tc*)&YhFLa));
  sf.pos=602032;
  if ((Vdi->Vsummary != NULL))
  {
   sf.pos=602033;
   Vret =  ZcS(Vret, YcAo(Vdi->Vsummary, ((Tc*)&YJ7b)));
  }
  sf.pos=602034;
  Vret =  ZcS(Vret, ((Tc*)&Yf9s));
  sf.pos=602035;
  YVWi(Asummary, Vname, Vret);
 }
YyuX:
 topFrame = sf.prev;
 return;
}
void YVrF(Tl *Astatements, Tb Amember, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary) {
 void *p5;
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 YYIi *Vdecl = 0;
 Tc *Vname = NULL;
 Tc *Vret = NULL;
 Tc *VdollarName = NULL;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 YaHa *Vdi = 0;
 YrBF *t0 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=164200;
 {
  Tfl Zf1i;
  Zf1 = ((p5 = (Astatements)) == NULL ? (ZnewList((Tt*)&YXCg__T, 0)) : p5);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=164201;
  switch (YuqZ(Vstmt))
  {
  case 1:
   {
    sf.pos=164202;
    Vdi = Y9vTb(NULL, Aparent, YjGb(Vstmt));
    sf.pos=164203;
    if ((Vdi->Vheader != NULL))
    {
     sf.pos=164204;
     YAEk(Asummary);
     sf.pos=164205;
     Y2QV(Asummary, Vdi->Vheader);
    }
    sf.pos=164206;
    Vdecl = YjGb(Vstmt);
    sf.pos=164207;
    Vname = YdHK(Vdecl);
    sf.pos=164208;
    if (Vdi->Vhide)
    {
     sf.pos=164209;
     YVWi(Asummary, Vname, NULL);
    }
    else
    {
     Te Vvis;
     sf.pos=164210;
     Vret = ((Tc*)&YgSX);
     sf.pos=164211;
     VdollarName = (((Amember && (ZstringCmp(Vname, ((Tc*)&YZom)) != 0))) ? (ZcS(((Tc*)&YK), Vname)) : (Vname));
     sf.pos=164212;
     Vret =  ZcS(Vret, ((Tc*)&YwxW));
     sf.pos=164213;
     Vret =  ZcS(Vret, YWaa(Y1Yr(Vdecl), Aparent, AthisClass, 1));
     sf.pos=164214;
     Vret =  ZcS(Vret, ((Tc*)&YPeR));
     sf.pos=164215;
     Vret =  ZcS(Vret, ((Tc*)&YiKI));
     sf.pos=164216;
     Vret =  ZcS(Vret, ZcS8(((Tc*)&Yk9v), AitemName, ((Tc*)&YidB), VdollarName, ((Tc*)&Y_Et), VdollarName, ((Tc*)&Y_wz), (Tc*)1));
     sf.pos=164217;
     Vvis = YDXu(YDxP(Y1Yr(YjGb(Vstmt))), (t0 = (((AthisClass == NULL)) ? (Aparent) : (AthisClass))));
     sf.pos=164218;
     Vret =  ZcS(Vret, ZcS3(VhtmlSmallAttrStart, ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis)), VhtmlSmallAttrEnd));
     sf.pos=164219;
     Vret =  ZcS(Vret, ((Tc*)&YhFLa));
     sf.pos=164220;
     if ((Vdi->Vsummary != NULL))
     {
      sf.pos=164221;
      Vret =  ZcS(Vret, YcAo(Vdi->Vsummary, ((Tc*)&YJ7b)));
     }
     sf.pos=164222;
     Vret =  ZcS(Vret, ((Tc*)&Yf9s));
     sf.pos=164223;
     YVWi(Asummary, Vname, Vret);
    }
     break;
   }
  case 7:
   {
    rt = 2;
    if (rt == 2) { rt &= 1; break; }
     break;
   }
  case 13:
   {
    void *p6;
    sf.pos=164224;
    Vcond = YCoj(Vstmt);
    sf.pos=164225;
    if (Yzno(Vcond))
    {
     sf.pos=164226;
     YVrF(Yb8Y(Y1Yl(Vcond)), Amember, AitemName, Aparent, AthisClass, Asummary);
    }
    sf.pos=164227;
    {
     Tfl Zf4i;
     Zf4 = ((p6 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p6);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=164228;
     if (Yzno(Velseif))
     {
      sf.pos=164229;
      YVrF(Yb8Y(Y1Yl(Velseif)), Amember, AitemName, Aparent, AthisClass, Asummary);
     }
     sf.pos=164230;
     }
    }
    sf.pos=164231;
    if (Y3qR(Vcond))
    {
     sf.pos=164232;
     YVrF(Yb8Y(Ym_a(Vcond)), Amember, AitemName, Aparent, AthisClass, Asummary);
    }
     break;
   }
  case 30:
   {
    sf.pos=164233;
    if (Ycfv(Vstmt))
    {
     sf.pos=164234;
     YVrF(Yb8Y(YFQs(Vstmt)), Amember, AitemName, Aparent, AthisClass, Asummary);
    }
     break;
   }
   if (rt) goto Yg8F;
  }
Yg8F:
  ;
  sf.pos=164235;
  }
 }
 topFrame = sf.prev;
 return;
}
void YjWd(Tl *Astatements, Tb Amember, Tb AdoLibMethod, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary) {
 void *p7;
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 YoDF *Valias = 0;
 YXCg *VmethodStmt = 0;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9642600;
 {
  Tfl Zf1i;
  Zf1 = ((p7 = (Astatements)) == NULL ? (ZnewList((Tt*)&YXCg__T, 0)) : p7);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9642601;
  switch (YuqZ(Vstmt))
  {
  case 6:
   {
    sf.pos=9642602;
    YaYU(Vstmt, Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary, 1);
     break;
   }
  case 7:
   {
    sf.pos=9642603;
    Valias = Y9au(Y1Yr(YjGb(Vstmt)));
    sf.pos=9642604;
    if (YNTP(Valias))
    {
     sf.pos=9642605;
     VmethodStmt = YiDy(Valias);
     sf.pos=9642606;
     if ((YuqZ(VmethodStmt) == 6))
     {
      sf.pos=9642607;
      YaYU(VmethodStmt, Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary, 0);
     }
    }
     break;
   }
  case 13:
   {
    void *p8;
    sf.pos=9642608;
    Vcond = YCoj(Vstmt);
    sf.pos=9642609;
    if (Yzno(Vcond))
    {
     sf.pos=9642610;
     YjWd(Yb8Y(Y1Yl(Vcond)), Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary);
    }
    sf.pos=9642611;
    {
     Tfl Zf4i;
     Zf4 = ((p8 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p8);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=9642612;
     if (Yzno(Velseif))
     {
      sf.pos=9642613;
      YjWd(Yb8Y(Y1Yl(Velseif)), Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary);
     }
     sf.pos=9642614;
     }
    }
    sf.pos=9642615;
    if (Y3qR(Vcond))
    {
     sf.pos=9642616;
     YjWd(Yb8Y(Ym_a(Vcond)), Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary);
    }
     break;
   }
  case 30:
   {
    sf.pos=9642617;
    if (Ycfv(Vstmt))
    {
     sf.pos=9642618;
     YjWd(Yb8Y(YFQs(Vstmt)), Amember, AdoLibMethod, AitemName, Aparent, AthisClass, Asummary);
    }
     break;
   }
  }
  sf.pos=9642619;
  }
 }
 topFrame = sf.prev;
 return;
}
Tc *YXra(Tc *Aname, Tb Amember) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6263800;
 r = (((Amember && (ZstringCmp(Aname, ((Tc*)&YZom)) != 0))) ? (ZcS(((Tc*)&YK), Aname)) : (Aname));
 topFrame = sf.prev;
 return r;
}
void YaYU(YXCg *Astmt, Tb Amember, Tb AdoLibMethod, Tc *AitemName, YrBF *Aparent, YrBF *AthisClass, YHCf *Asummary, Tb Aregister) {
 Tb VtypeMethod;
 Zsf sf;
 YYIi *Vdecl = 0;
 Y7Np *Vmethod = 0;
 Tc *Vname = NULL;
 Tc *VfullName = NULL;
 Tc *VdollarName = NULL;
 YrBF *VthisMethod = 0;
 Tc *VtypeSpec = NULL;
 Tc *VnameWithArgs = NULL;
 Tc *Vret = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf3 = NULL;
 YRBza *Vt = 0;
 YaHa *Vdi = 0;
 Tl *VargList = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 YrBF *t2 = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=5147900;
 Vdecl = YjGb(Astmt);
 sf.pos=5147901;
 Vmethod = Y3nC(Y1Yr(Vdecl));
 sf.pos=5147902;
 Vdi = Y9vTb(NULL, Aparent, Vdecl);
 sf.pos=5147903;
 Vname = YdHK(Vdecl);
 sf.pos=5147904;
 VargList = Y8dZ(Vmethod);
 sf.pos=5147905;
 VtypeMethod = YfpX(Aparent, Astmt);
 sf.pos=5147906;
 if (VtypeMethod)
 {
  sf.pos=5147907;
  if (Amember)
  {
   sf.pos=5147908;
   VargList = ZListSlice((Tl*)VargList, 1, -1);
  }
  else
  {
   sf.pos=5147909;
   rt = 1;
   goto Ypn7;
  }
  sf.pos=5147910;
  if ((ZstringCmp(Vname, ((Tc*)&YHtZa)) == 0))
  {
   sf.pos=5147911;
   Vname = ((Tc*)&Yb2I);
  }
Ypn7:
  if (rt) goto Y2OX;
 }
 sf.pos=5147912;
 if (Aregister)
 {
  sf.pos=5147913;
  if ((AthisClass != NULL))
  {
   sf.pos=5147914;
   VfullName = ZcS3(AthisClass->VfullName, ((Tc*)&YU), Vname);
  }
  else {
  sf.pos=5147915;
 if ((Aparent != NULL))
  {
   sf.pos=5147916;
   VfullName = ZcS3(Aparent->VfullName, ((Tc*)&YU), Vname);
  }
  else
  {
   sf.pos=5147917;
   VfullName = Vname;
  }
  }
  sf.pos=5147918;
  *((YXCg **)ZDictGetPtrP(Vmethods, (Tz)(void*)VfullName)) = Astmt;
 }
 sf.pos=5147919;
 VdollarName = YXra(Vname, Amember);
 sf.pos=5147920;
 VthisMethod = YSjh(NULL, YDxP(Y1Yr(Vdecl)), AthisClass, NULL, Vname, Vdi);
 sf.pos=5147921;
 VtypeSpec = ((Tc*)&Ya);
 sf.pos=5147922;
 if ((Yq8G(Vmethod) && !(VtypeMethod)))
 {
  sf.pos=5147923;
  VtypeSpec = YauLa(YmXD(Vmethod), NULL, VthisMethod, 0, 1);
 }
 sf.pos=5147924;
 VnameWithArgs = ZcS5(VdollarName, VtypeSpec, ((Tc*)&YO), (t0 = Yqvs(VargList, Aparent, VthisMethod)), ((Tc*)&YP));
 sf.pos=5147925;
 if ((Vdi->Vheader != NULL))
 {
  sf.pos=5147926;
  YAEk(Asummary);
  sf.pos=5147927;
  Y2QV(Asummary, Vdi->Vheader);
 }
 sf.pos=5147928;
 if (Vdi->Vhide)
 {
  sf.pos=5147929;
  YVWi(Asummary, VnameWithArgs, NULL);
 }
 else
 {
  Te Vvis;
  sf.pos=5147930;
  Vret = ((Tc*)&YgSX);
  sf.pos=5147931;
  Vret =  ZcS(Vret, ZcS8(((Tc*)&YqnL), AitemName, ((Tc*)&YidB), VdollarName, ((Tc*)&Y_Et), VdollarName, ((Tc*)&YilA), (Tc*)1));
  sf.pos=5147932;
  if ((ZbyteStringSize(VtypeSpec) != 0))
  {
   sf.pos=5147933;
   Vret =  ZcS(Vret, ZcS3(((Tc*)&YwxW), VtypeSpec, ((Tc*)&YveI)));
  }
  sf.pos=5147934;
  Vret =  ZcS(Vret, ((Tc*)&YE9G));
  sf.pos=5147935;
  Vret =  ZcS(Vret, Yb3r(VargList));
  sf.pos=5147936;
  Vret =  ZcS(Vret, ((Tc*)&YuIo));
  sf.pos=5147937;
  if (Y5UB(Vmethod))
  {
   sf.pos=5147938;
   Vret =  ZcS(Vret, ((Tc*)&YP1k));
   sf.pos=5147939;
   Vcomma = ((Tc*)&Ya);
   sf.pos=5147940;
   {
    Tfl Zf3i;
    Zf3 = Yv3S(Vmethod);
    Zf3i.l = Zf3;
    Zf3i.valp = (void*)&Vt;
    Zf3i.i = 0;
    for (; ZforListPtrCont(&Zf3i); ) {
    sf.pos=5147941;
    Vret =  ZcS(Vret, Vcomma);
    sf.pos=5147942;
    Vret =  ZcS(Vret, YWaa(Vt, Aparent, VthisMethod, 1));
    sf.pos=5147943;
    Vcomma = ((Tc*)&Ydha);
    sf.pos=5147944;
    }
   }
   sf.pos=5147945;
   Vret =  ZcS(Vret, ((Tc*)&YveI));
  }
  sf.pos=5147946;
  Vvis = YDXu(YDxP(Y1Yr(Vdecl)), (t2 = (((AthisClass == NULL)) ? (Aparent) : (AthisClass))));
  sf.pos=5147947;
  Vret =  ZcS(Vret, ZcS3(VhtmlSmallAttrStart, ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis)), VhtmlSmallAttrEnd));
  sf.pos=5147948;
  Vret =  ZcS(Vret, ((Tc*)&YfzN));
  sf.pos=5147949;
  if ((Vdi->Vsummary != NULL))
  {
   sf.pos=5147950;
   Vret =  ZcS(Vret, YcAo(Vdi->Vsummary, ((Tc*)&YJ7b)));
  }
  sf.pos=5147951;
  Vret =  ZcS(Vret, ((Tc*)&Yf9s));
  sf.pos=5147952;
  YVWi(Asummary, VnameWithArgs, Vret);
 }
Y2OX:
 topFrame = sf.prev;
 return;
}
Tc *YZi9(YFN2 *Aenum) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tl *Zf1 = NULL;
 YYIi *Vitem = 0;
 YaHa *Vdi = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=476200;
 Vret = ((Tc*)&Ya);
 sf.pos=476201;
 Vret =  ZcS(Vret, ((Tc*)&Y50q));
 sf.pos=476202;
 Vret =  ZcS(Vret, VhtmlIndentStart);
 sf.pos=476203;
 Vret =  ZcS(Vret, ((Tc*)&YBWA));
 sf.pos=476204;
 {
  Tfl Zf1i;
  Zf1 = YOZZ(Aenum);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vitem;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=476205;
  Vdi = Y9vTb(NULL, NULL, Vitem);
  sf.pos=476206;
  if (!(Vdi->Vhide))
  {
   sf.pos=476207;
   Vret =  ZcS(Vret, ZcS3(((Tc*)&YJWh), YdHK(Vitem), ((Tc*)&YZ6b)));
   sf.pos=476208;
   if (((Vdi->Vsummary != NULL) || (Vdi->Vdetails != NULL)))
   {
    sf.pos=476209;
    Vret =  ZcS(Vret, YLwI(Vdi->Vsummary));
    sf.pos=476210;
    Vret =  ZcS(Vret, YLwI(Vdi->Vdetails));
   }
   sf.pos=476211;
   Vret =  ZcS(Vret, ((Tc*)&YNaw));
  }
  sf.pos=476212;
  }
 }
 sf.pos=476213;
 Vret =  ZcS(Vret, ((Tc*)&YADm));
 sf.pos=476214;
 Vret =  ZcS(Vret, VhtmlIndentEnd);
 sf.pos=476215;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tl *YSvC(Tl *Astatements, YrBF *Aparent, YrBF *AthisClass) {
 void *p9;
 Zsf sf;
 Tl *r = 0;
 Tl *Vincludes = NULL;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 YfBB *Vinclude = 0;
 Tl *Zf4 = NULL;
 YXCg *VincStmt = 0;
 Tc *Vtype = NULL;
 Y5eh *Vcond = 0;
 Tl *Zf41 = NULL;
 Y5eh *Velseif = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4533700;
 Vincludes = ZnewList((Tt*)&string__T, 0);
 sf.pos=4533701;
 {
  Tfl Zf1i;
  Zf1 = ((p9 = (Astatements)) == NULL ? (ZnewList((Tt*)&YXCg__T, 0)) : p9);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4533702;
  switch (YuqZ(Vstmt))
  {
  case 32:
   {
    sf.pos=4533703;
    Vinclude = Yaja(Vstmt);
    sf.pos=4533704;
    {
     Tfl Zf4i;
     Zf4 = YXSw(Vinclude);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&VincStmt;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=4533705;
     if ((YuqZ(VincStmt) == 1))
     {
      Ti Vi;
      sf.pos=4533706;
      Vtype = YWaa(Y1Yr(YjGb(VincStmt)), Aparent, AthisClass, 0);
      sf.pos=4533707;
      Vi = ZstringFind(Vtype, ((Tc*)&YU_a), 0);
      sf.pos=4533708;
      if ((Vi > 0))
      {
       sf.pos=4533709;
       Vtype = ZstringSlice(Vtype, 0, (Vi - 1), 0);
      }
      sf.pos=4533710;
      ZLap((Tl*)Vincludes, (Tz)(void*)Vtype);
      sf.pos=4533711;
      if (((Aparent != NULL) && !(ZstringStartsWith(Vtype, ((Tc*)&YW0a), 0))))
      {
       sf.pos=4533712;
       Vtype = ZcS3(Aparent->VfullName, ((Tc*)&YU), Vtype);
       sf.pos=4533713;
       ZLap((Tl*)Vincludes, (Tz)(void*)Vtype);
      }
     }
     sf.pos=4533714;
     }
    }
     break;
   }
  case 13:
   {
    void *p10;
    sf.pos=4533715;
    Vcond = YCoj(Vstmt);
    sf.pos=4533716;
    if (Yzno(Vcond))
    {
     sf.pos=4533717;
     ZListExtend((Tl*)Vincludes, YSvC(Yb8Y(Y1Yl(Vcond)), Aparent, AthisClass));
    }
    sf.pos=4533718;
    {
     Tfl Zf41i;
     Zf41 = ((p10 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p10);
     Zf41i.l = Zf41;
     Zf41i.valp = (void*)&Velseif;
     Zf41i.i = 0;
     for (; ZforListPtrCont(&Zf41i); ) {
     sf.pos=4533719;
     if (Yzno(Velseif))
     {
      sf.pos=4533720;
      ZListExtend((Tl*)Vincludes, YSvC(Yb8Y(Y1Yl(Velseif)), Aparent, AthisClass));
     }
     sf.pos=4533721;
     }
    }
    sf.pos=4533722;
    if (Y3qR(Vcond))
    {
     sf.pos=4533723;
     ZListExtend((Tl*)Vincludes, YSvC(Yb8Y(Ym_a(Vcond)), Aparent, AthisClass));
    }
     break;
   }
  }
  sf.pos=4533724;
  }
 }
 sf.pos=4533725;
 r = Vincludes;
 topFrame = sf.prev;
 return r;
}
Tc *Y20k(Tl *Astatements, Tl *AsharedStatements, YrBF *Aparent, YrBF *AthisClass) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Td *Vvars = NULL;
 Td *Vmembers = NULL;
 Td *Vvars1 = NULL;
 Td *Vmembers1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1063200;
 Vret = ((Tc*)&Ya);
 sf.pos=1063201;
 Vret =  ZcS(Vret, ((Tc*)&YW43));
 sf.pos=1063202;
 Vret =  ZcS(Vret, VhtmlIndentStart);
 sf.pos=1063203;
 if ((Astatements != NULL))
 {
  sf.pos=1063204;
  Vvars = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
  sf.pos=1063205;
  YWa4(Astatements, (AthisClass != NULL), Aparent, AthisClass, Vvars);
  sf.pos=1063206;
  Vret =  ZcS(Vret, Yo3K(Vvars));
  sf.pos=1063207;
  Vmembers = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
  sf.pos=1063208;
  YB63(Astatements, (AthisClass != NULL), Aparent, AthisClass, Vmembers);
  sf.pos=1063209;
  Vret =  ZcS(Vret, Yo3K(Vmembers));
 }
 sf.pos=1063210;
 if ((AsharedStatements != NULL))
 {
  sf.pos=1063211;
  Vret =  ZcS(Vret, VhtmlIndentEnd);
  sf.pos=1063212;
  Vret =  ZcS(Vret, ((Tc*)&YajA));
  sf.pos=1063213;
  Vret =  ZcS(Vret, VhtmlIndentStart);
  sf.pos=1063214;
  Vvars1 = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
  sf.pos=1063215;
  YWa4(AsharedStatements, 0, Aparent, AthisClass, Vvars1);
  sf.pos=1063216;
  Vret =  ZcS(Vret, Yo3K(Vvars1));
  sf.pos=1063217;
  Vmembers1 = ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0);
  sf.pos=1063218;
  YB63(AsharedStatements, 0, Aparent, AthisClass, Vmembers1);
  sf.pos=1063219;
  Vret =  ZcS(Vret, Yo3K(Vmembers1));
 }
 sf.pos=1063220;
 r = ZcS(Vret, VhtmlIndentEnd);
 topFrame = sf.prev;
 return r;
}
Tc *YdL1(YXCg *Astmt, YrBF *Aparent, YrBF *AthisClass) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 YoDF *Valias = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3509600;
 Vret = ((Tc*)&Ya);
 sf.pos=3509601;
 Vret =  ZcS(Vret, ((Tc*)&YSPB));
 sf.pos=3509602;
 Vret =  ZcS(Vret, VhtmlIndentStart);
 sf.pos=3509603;
 Valias = Y9au(Y1Yr(YjGb(Astmt)));
 sf.pos=3509604;
 Vret =  ZcS(Vret, YJvB(YdCW(Valias), Aparent, AthisClass, 1, 0));
 sf.pos=3509605;
 r = ZcS(Vret, VhtmlIndentEnd);
 topFrame = sf.prev;
 return r;
}
Tc *Yo3K(Td *Amembers) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tl *Zf1 = NULL;
 Tc *Vk = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4312500;
 Vret = ((Tc*)&Ya);
 sf.pos=4312501;
 {
  Tfl Zf1i;
  Zf1 = ZstringListSort(ZDictKeys(Amembers, 0), 1);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vk;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4312502;
  Vret =  ZcS(Vret, ((Tc *)ZDictGetPtr(Amembers, (Tz)(void*)Vk)));
  sf.pos=4312503;
  }
 }
 sf.pos=4312504;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
void YWa4(Tl *Astatements, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Avars) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 YYIi *Vdecl = 0;
 Tc *Vname = NULL;
 Tc *Vret = NULL;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 YaHa *Vdi = 0;
 Tc *t0 = NULL;
 YrBF *t1 = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8554100;
 {
  Tfl Zf1i;
  Zf1 = Astatements;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8554101;
  switch (YuqZ(Vstmt))
  {
  case 1:
   {
    sf.pos=8554102;
    Vdi = Y9vTb(NULL, Aparent, YjGb(Vstmt));
    sf.pos=8554103;
    if (!(Vdi->Vhide))
    {
     Te Vvis;
     sf.pos=8554104;
     Vdecl = YjGb(Vstmt);
     sf.pos=8554105;
     Vname = ZcS((t0 = (((Amember) ? (((Tc*)&YK)) : (((Tc*)&Ya))))), YdHK(Vdecl));
     sf.pos=8554106;
     Vret = ((Tc*)&Ya);
     sf.pos=8554107;
     Vret =  ZcS(Vret, ((Tc*)&YXdE));
     sf.pos=8554108;
     Vret =  ZcS(Vret, YWaa(Y1Yr(Vdecl), Aparent, AthisClass, 1));
     sf.pos=8554109;
     Vret =  ZcS(Vret, ((Tc*)&YEZE));
     sf.pos=8554110;
     Vret =  ZcS(Vret, ZcS5(((Tc*)&Y0gF), Vname, ((Tc*)&Y_Et), Vname, ((Tc*)&Y_wz)));
     sf.pos=8554111;
     Vvis = YDXu(YDxP(Y1Yr(YjGb(Vstmt))), (t1 = (((AthisClass == NULL)) ? (Aparent) : (AthisClass))));
     sf.pos=8554112;
     Vret =  ZcS(Vret, ZcS5(VhtmlAttrStart, ((Tc*)&YG), (t0 = ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis))), VhtmlAttrEnd, (Tc*)1));
     sf.pos=8554113;
     Vret =  ZcS(Vret, ((Tc*)&Y11k));
     sf.pos=8554114;
     if (((Vdi->Vsummary != NULL) || (Vdi->Vdetails != NULL)))
     {
      sf.pos=8554115;
      Vret =  ZcS(Vret, VhtmlIndentStart);
      sf.pos=8554116;
      Vret =  ZcS(Vret, YLwI(Vdi->Vsummary));
      sf.pos=8554117;
      Vret =  ZcS(Vret, YLwI(Vdi->Vdetails));
      sf.pos=8554118;
      Vret =  ZcS(Vret, VhtmlIndentEnd);
     }
     sf.pos=8554119;
     *((Tc **)ZDictGetPtrP(Avars, (Tz)(void*)Vname)) = Vret;
    }
     break;
   }
  case 30:
   {
    sf.pos=8554120;
    if (Ycfv(Vstmt))
    {
     sf.pos=8554121;
     YWa4(Yb8Y(YFQs(Vstmt)), Amember, Aparent, AthisClass, Avars);
    }
     break;
   }
  case 13:
   {
    void *p11;
    sf.pos=8554122;
    Vcond = YCoj(Vstmt);
    sf.pos=8554123;
    if (Yzno(Vcond))
    {
     sf.pos=8554124;
     YWa4(Yb8Y(Y1Yl(Vcond)), Amember, Aparent, AthisClass, Avars);
    }
    sf.pos=8554125;
    {
     Tfl Zf4i;
     Zf4 = ((p11 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p11);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=8554126;
     if (Yzno(Velseif))
     {
      sf.pos=8554127;
      YWa4(Yb8Y(Y1Yl(Velseif)), Amember, Aparent, AthisClass, Avars);
     }
     sf.pos=8554128;
     }
    }
    sf.pos=8554129;
    if (Y3qR(Vcond))
    {
     sf.pos=8554130;
     YWa4(Yb8Y(Ym_a(Vcond)), Amember, Aparent, AthisClass, Avars);
    }
     break;
   }
  }
  sf.pos=8554131;
  }
 }
 topFrame = sf.prev;
 return;
}
void YB63(Tl *Astatements, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Amembers) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4764100;
 {
  Tfl Zf1i;
  Zf1 = Astatements;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=4764101;
  switch (YuqZ(Vstmt))
  {
  case 6:
   {
    sf.pos=4764102;
    YSYh(Vstmt, Amember, Aparent, AthisClass, Amembers);
     break;
   }
  case 7:
  case 30:
   {
    sf.pos=4764103;
    if (Ycfv(Vstmt))
    {
     sf.pos=4764104;
     YB63(Yb8Y(YFQs(Vstmt)), Amember, Aparent, AthisClass, Amembers);
    }
     break;
   }
  case 13:
   {
    void *p12;
    sf.pos=4764105;
    Vcond = YCoj(Vstmt);
    sf.pos=4764106;
    if (Yzno(Vcond))
    {
     sf.pos=4764107;
     YB63(Yb8Y(Y1Yl(Vcond)), Amember, Aparent, AthisClass, Amembers);
    }
    sf.pos=4764108;
    {
     Tfl Zf4i;
     Zf4 = ((p12 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p12);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=4764109;
     if (Yzno(Velseif))
     {
      sf.pos=4764110;
      YB63(Yb8Y(Y1Yl(Velseif)), Amember, Aparent, AthisClass, Amembers);
     }
     sf.pos=4764111;
     }
    }
    sf.pos=4764112;
    if (Y3qR(Vcond))
    {
     sf.pos=4764113;
     YB63(Yb8Y(Ym_a(Vcond)), Amember, Aparent, AthisClass, Amembers);
    }
     break;
   }
  }
  sf.pos=4764114;
  }
 }
 topFrame = sf.prev;
 return;
}
Tb YfpX(YrBF *Aparent, YXCg *Astmt) {
 Zsf sf;
 Tb r = 0;
 YYIi *Vdecl = 0;
 Y7Np *Vmethod = 0;
 Tl *VargList = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6098000;
 Vdecl = YjGb(Astmt);
 sf.pos=6098001;
 Vmethod = Y3nC(Y1Yr(Vdecl));
 sf.pos=6098002;
 VargList = Y8dZ(Vmethod);
 sf.pos=6098003;
 r = (((((Aparent != NULL) && Aparent->VisLibModule) && (VargList != NULL)) && (ZListSize(VargList) > 0)) && (ZstringCmp(YdHK(((YYIi *)ZListGetPtr(VargList, 0))), ((Tc*)&Yefp)) == 0));
 topFrame = sf.prev;
 return r;
}
void YSYh(YXCg *Astmt, Tb Amember, YrBF *Aparent, YrBF *AthisClass, Td *Amembers) {
 Tb VtypeMethod;
 Te Vvis;
 Ti Vnr;
 Zsf sf;
 YYIi *Vdecl = 0;
 Y7Np *Vmethod = 0;
 Tc *Vname = NULL;
 Tc *VmethodName = NULL;
 YrBF *VthisMethod = 0;
 Tc *VtypeSpec = NULL;
 Tc *Vret = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf2 = NULL;
 YRBza *Vt = 0;
 YJON *Vattr = 0;
 Tc *Vkey = NULL;
 YaHa *Vdi = 0;
 Tl *VargList = NULL;
 YrBF *t0 = 0;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=3097000;
 Vdecl = YjGb(Astmt);
 sf.pos=3097001;
 Vdi = Y9vTb(NULL, Aparent, Vdecl);
 sf.pos=3097002;
 if (Vdi->Vhide)
 {
  sf.pos=3097003;
  rt = 1;
  goto YSjD;
 }
 sf.pos=3097004;
 Vmethod = Y3nC(Y1Yr(Vdecl));
 sf.pos=3097005;
 VargList = Y8dZ(Vmethod);
 sf.pos=3097006;
 VtypeMethod = YfpX(Aparent, Astmt);
 sf.pos=3097007;
 Vname = YdHK(Vdecl);
 sf.pos=3097008;
 if (VtypeMethod)
 {
  sf.pos=3097009;
  if (Amember)
  {
   sf.pos=3097010;
   VargList = ZListSlice((Tl*)VargList, 1, -1);
  }
  else
  {
   sf.pos=3097011;
   rt = 1;
   goto Y_qC;
  }
  sf.pos=3097012;
  if ((ZstringCmp(Vname, ((Tc*)&YHtZa)) == 0))
  {
   sf.pos=3097013;
   Vname = ((Tc*)&Yb2I);
  }
Y_qC:
  if (rt) goto YSjD;
 }
 sf.pos=3097014;
 VmethodName = YXra(Vname, Amember);
 sf.pos=3097015;
 VthisMethod = YSjh(NULL, YDxP(Y1Yr(Vdecl)), AthisClass, NULL, VmethodName, Vdi);
 sf.pos=3097016;
 VtypeSpec = ((Tc*)&Ya);
 sf.pos=3097017;
 if ((Yq8G(Vmethod) && !(VtypeMethod)))
 {
  sf.pos=3097018;
  VtypeSpec = YauLa(YmXD(Vmethod), NULL, VthisMethod, 0, 1);
 }
 sf.pos=3097019;
 Vret = ((Tc*)&Ya);
 sf.pos=3097020;
 Vret =  ZcS(Vret, ((Tc*)&Y01g));
 sf.pos=3097021;
 if ((YXDk(Y1Yr(Vdecl)) == 20))
 {
  sf.pos=3097022;
  Vret =  ZcS(Vret, ZcS5(VhtmlKeyStart, ((Tc*)&YqI4), VhtmlKeyEnd, ((Tc*)&YG), (Tc*)1));
 }
 else
 {
  sf.pos=3097023;
  Vret =  ZcS(Vret, ZcS5(VhtmlKeyStart, ((Tc*)&Y6T9), VhtmlKeyEnd, ((Tc*)&YG), (Tc*)1));
 }
 sf.pos=3097024;
 Vret =  ZcS(Vret, ZcS5(((Tc*)&Y0gF), VmethodName, ((Tc*)&Y_Et), VmethodName, ((Tc*)&Y_wz)));
 sf.pos=3097025;
 Vret =  ZcS(Vret, VtypeSpec);
 sf.pos=3097026;
 Vret =  ZcS(Vret, ((Tc*)&YO));
 sf.pos=3097027;
 Vret =  ZcS(Vret, Y2Xm(VargList, Aparent, VthisMethod));
 sf.pos=3097028;
 Vret =  ZcS(Vret, ((Tc*)&YP));
 sf.pos=3097029;
 if ((YXDk(Y1Yr(Vdecl)) == 20))
 {
  sf.pos=3097030;
  Vcomma = ((Tc*)&Ya);
  sf.pos=3097031;
  {
   Tfl Zf2i;
   Zf2 = Yv3S(Vmethod);
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vt;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   sf.pos=3097032;
   Vret =  ZcS(Vret, Vcomma);
   sf.pos=3097033;
   Vret =  ZcS(Vret, ZcS(((Tc*)&YG), YWaa(Vt, Aparent, VthisMethod, 1)));
   sf.pos=3097034;
   Vcomma = ((Tc*)&Ydha);
   sf.pos=3097035;
   }
  }
 }
 sf.pos=3097036;
 Vattr = YDxP(Y1Yr(Vdecl));
 sf.pos=3097037;
 if (YCKw(Vattr))
 {
  sf.pos=3097038;
  Vret =  ZcS(Vret, ZcS3(VhtmlAttrStart, ((Tc*)&Y_j7), VhtmlAttrEnd));
 }
 sf.pos=3097039;
 if (YHd1(Vattr))
 {
  sf.pos=3097040;
  Vret =  ZcS(Vret, ZcS3(VhtmlAttrStart, ((Tc*)&YtWp), VhtmlAttrEnd));
 }
 sf.pos=3097041;
 if (YJqm(Vattr))
 {
  sf.pos=3097042;
  Vret =  ZcS(Vret, ZcS3(VhtmlAttrStart, ((Tc*)&Ypep), VhtmlAttrEnd));
 }
 sf.pos=3097043;
 Vvis = YDXu(YDxP(Y1Yr(Vdecl)), (t0 = (((AthisClass == NULL)) ? (Aparent) : (AthisClass))));
 sf.pos=3097044;
 Vret =  ZcS(Vret, ZcS5(VhtmlAttrStart, ((Tc*)&YG), (t1 = ((Tc *)ZDictGetPtr(VvisName, (Tz)(Ti)Vvis))), VhtmlAttrEnd, (Tc*)1));
 sf.pos=3097045;
 Vret =  ZcS(Vret, ((Tc*)&Y11k));
 sf.pos=3097046;
 if (((Vdi->Vsummary != NULL) || (Vdi->Vdetails != NULL)))
 {
  sf.pos=3097047;
  Vret =  ZcS(Vret, VhtmlIndentStart);
  sf.pos=3097048;
  Vret =  ZcS(Vret, YLwI(Vdi->Vsummary));
  sf.pos=3097049;
  Vret =  ZcS(Vret, YLwI(Vdi->Vdetails));
  sf.pos=3097050;
  Vret =  ZcS(Vret, VhtmlIndentEnd);
 }
 sf.pos=3097051;
 Vkey = VmethodName;
 sf.pos=3097052;
 if ((ZstringCmp(Vkey, ((Tc*)&YZom)) == 0))
 {
  sf.pos=3097053;
  Vkey = ((Tc*)&Yjdx);
 }
 else {
 sf.pos=3097054;
 if ((ZstringCmp(Vkey, ((Tc*)&Ysqt)) == 0))
 {
  sf.pos=3097055;
  Vkey = ((Tc*)&Yw0Y);
 }
 else {
 sf.pos=3097056;
 if ((ZstringCmp(Vkey, ((Tc*)&YkKS)) == 0))
 {
  sf.pos=3097057;
  Vkey = ((Tc*)&Y1U9);
 }
 else {
 sf.pos=3097058;
 if ((ZstringCmp(Vkey, ((Tc*)&Yb2I)) == 0))
 {
  sf.pos=3097059;
  Vkey = ((Tc*)&YkAg);
 }
 else {
 sf.pos=3097060;
 if ((ZstringCmp(Vkey, ((Tc*)&YHQQ)) == 0))
 {
  sf.pos=3097061;
  Vkey = ((Tc*)&YlKZ);
 }
 else {
 sf.pos=3097062;
 if ((ZstringCmp(Vkey, ((Tc*)&Y8AK)) == 0))
 {
  sf.pos=3097063;
  Vkey = ((Tc*)&YkRm);
 }
 else {
 sf.pos=3097064;
 if ((ZstringCmp(Vkey, ((Tc*)&Yju3)) == 0))
 {
  sf.pos=3097065;
  Vkey = ((Tc*)&YlQS);
 }
 else {
 sf.pos=3097066;
 if ((ZstringCmp(Vkey, ((Tc*)&Y318)) == 0))
 {
  sf.pos=3097067;
  Vkey = ((Tc*)&YGQt);
 }
 }}}}}}}
 Vnr = 0;
 sf.pos=3097068;
 while (ZDictHas(Amembers, (Tz)(void*)ZcS(Vkey, Zint2string(Vnr))))
 {
  sf.pos=3097069;
  ++(Vnr);
 sf.pos=3097070;
 }
 sf.pos=3097071;
 *((Tc **)ZDictGetPtrP(Amembers, (Tz)(void*)ZcS(Vkey, Zint2string(Vnr)))) = Vret;
YSjD:
 topFrame = sf.prev;
 return;
}
Tc *YJgp(YaHa *AitemsArg, YrBF *AparentArg) {
 Zsf sf;
 Tc *r = 0;
 YrBF *Vparent = 0;
 Tc *Vret = NULL;
 YaHa *Vitems = 0;
 Tl *Zf2 = NULL;
 Tl *Vsection = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2717200;
 Vitems = AitemsArg;
 sf.pos=2717201;
 Vparent = AparentArg;
 sf.pos=2717202;
 while (((Vitems->Vextra == NULL) && (Vparent != NULL)))
 {
  sf.pos=2717203;
  Vitems = Vparent->Vitems;
  sf.pos=2717204;
  Vparent = Vparent->Vparent;
 sf.pos=2717205;
 }
 sf.pos=2717206;
 Vret = ((Tc*)&Ya);
 sf.pos=2717207;
 if ((Vitems->Vextra != NULL))
 {
  sf.pos=2717208;
  {
   Tfl Zf2i;
   Zf2 = Vitems->Vextra;
   Zf2i.l = Zf2;
   Zf2i.valp = (void*)&Vsection;
   Zf2i.i = 0;
   for (; ZforListPtrCont(&Zf2i); ) {
   Ti Vi;
   sf.pos=2717209;
   Vret =  ZcS(Vret, ZcS3(((Tc*)&Y6XD), ((Tc *)ZListGetPtr(Vsection, 0)), ((Tc*)&YwCp)));
   sf.pos=2717210;
   Vret =  ZcS(Vret, VhtmlIndentStart);
   sf.pos=2717211;
   Vi = 1;
   sf.pos=2717212;
   while ((Vi < ZListSize(Vsection)))
   {
    sf.pos=2717213;
    Vret =  ZcS(Vret, ((Tc *)ZListGetPtr(Vsection, Vi)));
    sf.pos=2717214;
    ++(Vi);
   sf.pos=2717215;
   }
   sf.pos=2717216;
   Vret =  ZcS(Vret, VhtmlIndentEnd);
   sf.pos=2717217;
   }
  }
 }
 sf.pos=2717218;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
void YBfF(Tl *Astatements, YrBF *Aparent) {
 Zsf sf;
 Tl *Zf1 = NULL;
 YXCg *Vstmt = 0;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8284300;
 {
  Tfl Zf1i;
  Zf1 = Astatements;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vstmt;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8284301;
  switch (YuqZ(Vstmt))
  {
  case 3:
  case 5:
  case 4:
   {
    sf.pos=8284302;
    Ywyp(Vstmt, NULL, Aparent);
     break;
   }
  case 7:
   {
    sf.pos=8284303;
    Ye4o(Vstmt, Aparent);
     break;
   }
  case 30:
   {
    sf.pos=8284304;
    if (Ycfv(Vstmt))
    {
     sf.pos=8284305;
     YBfF(Yb8Y(YFQs(Vstmt)), Aparent);
    }
     break;
   }
  case 13:
   {
    void *p13;
    sf.pos=8284306;
    Vcond = YCoj(Vstmt);
    sf.pos=8284307;
    if (Yzno(Vcond))
    {
     sf.pos=8284308;
     YBfF(Yb8Y(Y1Yl(Vcond)), Aparent);
    }
    sf.pos=8284309;
    {
     Tfl Zf4i;
     Zf4 = ((p13 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p13);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=8284310;
     if (Yzno(Velseif))
     {
      sf.pos=8284311;
      YBfF(Yb8Y(Y1Yl(Velseif)), Aparent);
     }
     sf.pos=8284312;
     }
    }
    sf.pos=8284313;
    if (Y3qR(Vcond))
    {
     sf.pos=8284314;
     YBfF(Yb8Y(Ym_a(Vcond)), Aparent);
    }
     break;
   }
  }
  sf.pos=8284315;
  }
 }
 topFrame = sf.prev;
 return;
}
void YhbZ(Tl *Astatements, YrBF *Aparent) {
 Ti Vi;
 Zsf sf;
 YXCg *Vstmt = 0;
 YYIi *Vdecl = 0;
 Tl *Vstmts = NULL;
 YftY *Vclass = 0;
 YXCg *VclassStmt = 0;
 Y5eh *Vcond = 0;
 Tl *Zf4 = NULL;
 Y5eh *Velseif = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 Vi = 0;
 sf.pos=9838600;
 while ((Vi < ZListSize(Astatements)))
 {
  sf.pos=9838601;
  Vstmt = ((YXCg *)ZListGetPtr(Astatements, Vi));
  sf.pos=9838602;
  switch (YuqZ(Vstmt))
  {
  case 3:
   {
    sf.pos=9838603;
    Vdecl = YjGb(Vstmt);
    sf.pos=9838604;
    if (ZstringStartsWith(YdHK(Vdecl), ((Tc*)&YpSv), 0))
    {
     sf.pos=9838605;
     Vstmts = ZnewList((Tt*)&YXCg__T, 0);
     sf.pos=9838606;
     Vclass = YJgu(Y1Yr(Vdecl));
     sf.pos=9838607;
     if (YskK(Vclass))
     {
      sf.pos=9838608;
      Vstmts = YGyt(Vclass);
     }
     sf.pos=9838609;
     ++(Vi);
     sf.pos=9838610;
     while ((Vi < ZListSize(Astatements)))
     {
      sf.pos=9838611;
      VclassStmt = ((YXCg *)ZListGetPtr(Astatements, Vi));
      sf.pos=9838612;
      if (((YuqZ(VclassStmt) == 3) && ZstringStartsWith(YdHK(YjGb(VclassStmt)), ((Tc*)&YPu_), 0)))
      {
       rt = 2;
       goto YBSu;
      }
      sf.pos=9838613;
      ZLap((Tl*)Vstmts, (Tz)(void*)VclassStmt);
      sf.pos=9838614;
      ++(Vi);
YBSu:
      if (rt == 2) { rt &= 1; break; }
     sf.pos=9838615;
     }
     sf.pos=9838616;
     if ((ZListSize(Vstmts) > 0))
     {
      sf.pos=9838617;
      Ywyp(Vstmt, Vstmts, Aparent);
     }
    }
     break;
   }
  case 30:
   {
    sf.pos=9838618;
    if (Ycfv(Vstmt))
    {
     sf.pos=9838619;
     YhbZ(Yb8Y(YFQs(Vstmt)), Aparent);
    }
     break;
   }
  case 13:
   {
    void *p14;
    sf.pos=9838620;
    Vcond = YCoj(Vstmt);
    sf.pos=9838621;
    if (Yzno(Vcond))
    {
     sf.pos=9838622;
     YhbZ(Yb8Y(Y1Yl(Vcond)), Aparent);
    }
    sf.pos=9838623;
    {
     Tfl Zf4i;
     Zf4 = ((p14 = (YPh5(Vcond))) == NULL ? (ZnewList((Tt*)&Y5eh__T, 0)) : p14);
     Zf4i.l = Zf4;
     Zf4i.valp = (void*)&Velseif;
     Zf4i.i = 0;
     for (; ZforListPtrCont(&Zf4i); ) {
     sf.pos=9838624;
     if (Yzno(Velseif))
     {
      sf.pos=9838625;
      YhbZ(Yb8Y(Y1Yl(Velseif)), Aparent);
     }
     sf.pos=9838626;
     }
    }
    sf.pos=9838627;
    if (Y3qR(Vcond))
    {
     sf.pos=9838628;
     YhbZ(Yb8Y(Ym_a(Vcond)), Aparent);
    }
     break;
   }
  }
  sf.pos=9838629;
  ++(Vi);
 sf.pos=9838630;
 }
 topFrame = sf.prev;
 return;
}
Tc *YcAo(Tc *Atext, Tc *Aitem) {
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=953000;
 if ((Atext == NULL))
 {
  sf.pos=953001;
  r = ((Tc*)&Ya);
  rt = 1;
  goto YS71;
 }
 sf.pos=953002;
 r = ZcS8(((Tc*)&Y7), Aitem, ((Tc*)&Y9), Atext, ((Tc*)&Y6Ga), Aitem, ((Tc*)&YJJa), (Tc*)1);
YS71:
 topFrame = sf.prev;
 return r;
}
Tc *YLwI(Tc *Atext) {
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2101900;
 if ((Atext == NULL))
 {
  sf.pos=2101901;
  r = ((Tc*)&Ya);
  rt = 1;
  goto Yhm3;
 }
 sf.pos=2101902;
 r = ZcS3(VhtmlTextStart, Atext, ((Tc*)&YUHc));
Yhm3:
 topFrame = sf.prev;
 return r;
}
Tc *Y6Od(YrBF *Aparent, Tc *Atext) {
 Ti Vlen;
 Ti Vidx;
 Ti VstartIdx;
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1002300;
 Vret = ((Tc*)&Ya);
 sf.pos=1002301;
 Vlen = ZstringSize(Atext);
 Vidx = 0;
 VstartIdx = 0;
 sf.pos=1002302;
 while ((Vidx < Vlen))
 {
  Ti Vc;
  sf.pos=1002303;
  Vc = ZstringGetChar(Atext, Vidx);
  sf.pos=1002304;
  if ((((Vc == 60) || (Vc == 62)) || (Vc == 38)))
  {
   sf.pos=1002305;
   if ((Vidx > VstartIdx))
   {
    sf.pos=1002306;
    Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
   }
   sf.pos=1002307;
   VstartIdx = (Vidx + 1);
   sf.pos=1002308;
   switch (Vc)
   {
   case 60:
    {
     sf.pos=1002309;
     Vret =  ZcS(Vret, ((Tc*)&YU_a));
      break;
    }
   case 62:
    {
     sf.pos=1002310;
     Vret =  ZcS(Vret, ((Tc*)&Yi9Y));
      break;
    }
   case 38:
    {
     sf.pos=1002311;
     Vret =  ZcS(Vret, ((Tc*)&Yycx));
      break;
    }
   }
  }
  else {
  sf.pos=1002312;
 if ((Aparent != NULL))
  {
   sf.pos=1002313;
   if ((Vc == 124))
   {
    Ti Vbar2;
    Vbar2 = 0;
    sf.pos=1002314;
    Vbar2 = (Vidx + 1);
    sf.pos=1002315;
    while ((((Vbar2 < Vlen) && (ZstringGetChar(Atext, Vbar2) != 124)) && (ZstringGetChar(Atext, Vbar2) != 32)))
    {
     sf.pos=1002316;
     ++(Vbar2);
    sf.pos=1002317;
    }
    sf.pos=1002318;
    if ((ZstringGetChar(Atext, Vbar2) == 124))
    {
     sf.pos=1002319;
     if ((Vidx > VstartIdx))
     {
      sf.pos=1002320;
      Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
     }
     sf.pos=1002321;
     VstartIdx = (Vbar2 + 1);
     sf.pos=1002322;
     Vret =  ZcS(Vret, ZcS3(((Tc*)&YvSD), ZstringSlice(Atext, (Vidx + 1), (Vbar2 - 1), 0), ((Tc*)&YAGk)));
     sf.pos=1002323;
     Vidx = VstartIdx;
    }
   }
   else {
   sf.pos=1002324;
 if ((Vc == 96))
   {
    Ti Vbar2;
    Vbar2 = 0;
    sf.pos=1002325;
    Vbar2 = (Vidx + 1);
    sf.pos=1002326;
    while (((Vbar2 < Vlen) && (ZstringGetChar(Atext, Vbar2) != 96)))
    {
     sf.pos=1002327;
     ++(Vbar2);
    sf.pos=1002328;
    }
    sf.pos=1002329;
    if ((ZstringGetChar(Atext, Vbar2) == 96))
    {
     sf.pos=1002330;
     if ((Vidx > VstartIdx))
     {
      sf.pos=1002331;
      Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
     }
     sf.pos=1002332;
     VstartIdx = (Vbar2 + 1);
     sf.pos=1002333;
     Vret =  ZcS(Vret, ZcS3(((Tc*)&Yj8D), ZstringSlice(Atext, (Vidx + 1), (Vbar2 - 1), 0), ((Tc*)&Ylkh)));
     sf.pos=1002334;
     Vidx = VstartIdx;
    }
   }
   else {
   sf.pos=1002335;
 if ((Vc == 64))
   {
    Ti Vend;
    Vend = 0;
    sf.pos=1002336;
    Vend = (Vidx + 1);
    sf.pos=1002337;
    while (((Vend < Vlen) && (ZstringFindChar(((Tc*)&Yo_a), ZstringGetChar(Atext, Vend), 0) < 0)))
    {
     sf.pos=1002338;
     ++(Vend);
    sf.pos=1002339;
    }
    sf.pos=1002340;
    if (((Vend < Vlen) && (ZstringGetChar(Atext, Vend) == 64)))
    {
     Ti Vthird;
     Vthird = 0;
     sf.pos=1002341;
     Vthird = (Vend + 1);
     sf.pos=1002342;
     while (((Vthird < Vlen) && (ZstringGetChar(Atext, Vthird) != 64)))
     {
      sf.pos=1002343;
      ++(Vthird);
     sf.pos=1002344;
     }
     sf.pos=1002345;
     if ((ZstringGetChar(Atext, Vthird) == 64))
     {
      sf.pos=1002346;
      if ((Vidx > VstartIdx))
      {
       sf.pos=1002347;
       Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
      }
      sf.pos=1002348;
      VstartIdx = (Vthird + 1);
      sf.pos=1002349;
      Vret =  ZcS(Vret, ZcS5(((Tc*)&Yf9v), ZstringSlice(Atext, (Vidx + 1), (Vend - 1), 0), ((Tc*)&YF1), (t0 = ZstringSlice(Atext, (Vend + 1), (Vthird - 1), 0)), ((Tc*)&YZEk)));
      sf.pos=1002350;
      Vidx = VstartIdx;
     }
    }
    else {
    sf.pos=1002351;
 if ((Vend > (Vidx + 1)))
    {
     sf.pos=1002352;
     if ((Vidx > VstartIdx))
     {
      sf.pos=1002353;
      Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
     }
     sf.pos=1002354;
     VstartIdx = Vend;
     sf.pos=1002355;
     Vret =  ZcS(Vret, Yy61(Aparent, ZstringSlice(Atext, (Vidx + 1), (Vend - 1), 0), NULL));
     sf.pos=1002356;
     Vidx = VstartIdx;
    }
    }
   }
   }}
  }
  }
  sf.pos=1002357;
  ++(Vidx);
 sf.pos=1002358;
 }
 sf.pos=1002359;
 if ((Vidx > VstartIdx))
 {
  sf.pos=1002360;
  Vret =  ZcS(Vret, ZstringSlice(Atext, VstartIdx, (Vidx - 1), 0));
 }
 sf.pos=1002361;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *Yy61(YrBF *Aparent, Tc *Aname, Tc *Aitem) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vfname = NULL;
 Tc *Vret = NULL;
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9979000;
 if ((Aname == NULL))
 {
  sf.pos=9979001;
  Vfname = ((Tc*)&Ya);
 }
 else
 {
  sf.pos=9979002;
  Vfname = ZcS(Aname, ((Tc*)&Y1zY));
  sf.pos=9979003;
  if ((Aparent != NULL))
  {
   sf.pos=9979004;
   Vfname = ZcS3(Aparent->VfullName, ((Tc*)&YU), Vfname);
  }
 }
 sf.pos=9979005;
 Vret = ZcS(((Tc*)&Yk9v), Vfname);
 sf.pos=9979006;
 if ((Aitem != NULL))
 {
  sf.pos=9979007;
  Vret =  ZcS(Vret, ZcS(((Tc*)&YJ), Aitem));
 }
 sf.pos=9979008;
 r = ZcS5(Vret, ((Tc*)&Y_Et), (t0 = ((((Aname == NULL)) ? (Aitem) : (Aname)))), ((Tc*)&Y_wz), (Tc*)1);
 topFrame = sf.prev;
 return r;
}
Tc *Yiyv(Tc *Aname, Tb Abold) {
 Zsf sf;
 Tc *r = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=807900;
 r = Yiyva(Aname, Aname, Abold);
 topFrame = sf.prev;
 return r;
}
Tc *Yiyva(Tc *AfullName, Tc *Aname, Tb Abold) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1925900;
 Vret = ZcS3(((Tc*)&Yk9v), AfullName, ((Tc*)&YoT8));
 sf.pos=1925901;
 if (Abold)
 {
  sf.pos=1925902;
  Vret =  ZcS(Vret, ((Tc*)&YvSD));
 }
 sf.pos=1925903;
 Vret =  ZcS(Vret, Aname);
 sf.pos=1925904;
 if (Abold)
 {
  sf.pos=1925905;
  Vret =  ZcS(Vret, ((Tc*)&YAGk));
 }
 sf.pos=1925906;
 r = ZcS(Vret, ((Tc*)&YGQj));
 topFrame = sf.prev;
 return r;
}
Tc *YWaa(YRBza *Atype, YrBF *Aparent, YrBF *AthisClass, Tb Awrap) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vs = NULL;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9726800;
 Vs = YGD4((t0 = ZnewList((Tt*)&YRBza__T, 1), ZLap((Tl*)t0, (Tz)(void*)Atype)), Aparent, AthisClass, Awrap, 0, 0);
 sf.pos=9726801;
 if (Awrap)
 {
  sf.pos=9726802;
  r = ZcS3(VhtmlTypeStart, Vs, VhtmlTypeEnd);
  rt = 1;
  goto Yb3j;
 }
 sf.pos=9726803;
 r = Vs;
Yb3j:
 topFrame = sf.prev;
 return r;
}
Tc *YGD4(Tl *AtypeList, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType, Tb AisFunc) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 Tc *Vcomma = NULL;
 Tc *Vitem = NULL;
 YRBza *Vtype = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1429500;
 Vres = ((Tc*)&Ya);
 sf.pos=1429501;
 Vcomma = ((Tc*)&Ya);
 sf.pos=1429502;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(0, ZListSize(AtypeList), 1, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=1429503;
  Vtype = ((YRBza *)ZListGetPtr(AtypeList, Vi));
  sf.pos=1429504;
  if ((AisFunc && (Vi == (ZListSize(AtypeList) - 1))))
  {
   sf.pos=1429505;
   if ((ZbyteStringSize(Vcomma) == 0))
   {
    sf.pos=1429506;
    Vres =  ZcS(Vres, ((Tc*)&YRSF));
   }
   else
   {
    sf.pos=1429507;
    Vcomma = ((Tc*)&YRSF);
   }
  }
  sf.pos=1429508;
  Vitem = Ydfw(Vtype, Aparent, AthisClass, Awrap, AaddType);
  sf.pos=1429509;
  Vres =  ZcS(Vres, ZcS(Vcomma, Y40A(Vitem, AthisClass, Awrap)));
  sf.pos=1429510;
  Vcomma = ((Tc*)&Ydha);
  sf.pos=1429511;
  }
 }
 sf.pos=1429512;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
Tc *YGD4a(Tl *AtypeList, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vres = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf1 = NULL;
 Y1p4 *Vid = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=2032300;
 Vres = ((Tc*)&Ya);
 sf.pos=2032301;
 Vcomma = ((Tc*)&Ya);
 sf.pos=2032302;
 {
  Tfl Zf1i;
  Zf1 = AtypeList;
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Vid;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=2032303;
  Vres =  ZcS(Vres, ZcS(Vcomma, Y40A(YYim(Vid), AthisClass, Awrap)));
  sf.pos=2032304;
  Vcomma = ((Tc*)&Ydha);
  sf.pos=2032305;
  }
 }
 sf.pos=2032306;
 r = Vres;
 topFrame = sf.prev;
 return r;
}
Tc *Ydfw(YRBza *Atype, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4465200;
 if ((Atype == NULL))
 {
  sf.pos=4465201;
  r = ((Tc*)&YuzG);
  rt = 1;
  goto YkUN;
 }
 sf.pos=4465202;
 Vret = ((Tc*)&Ya);
 sf.pos=4465203;
 if ((YXDk(Atype) == 45))
 {
  sf.pos=4465204;
  Vret =  ZcS(Vret, YJvB(YLV1(Atype), Aparent, AthisClass, Awrap, AaddType));
 }
 else {
 sf.pos=4465205;
 if ((YXDk(Atype) == 44))
 {
  sf.pos=4465206;
  Vret =  ZcS(Vret, ZcS(Ydfw(YH95(Atype), Aparent, AthisClass, Awrap, AaddType), ((Tc*)&Y4Y)));
 }
 else
 {
  sf.pos=4465207;
  Yl0k(ZcS(((Tc*)&YMW6), Zenum2string(MZui__ETypeEnum, YXDk(Atype))));
  sf.pos=4465208;
  Vret =  ZcS(Vret, ((Tc*)&YbbH));
 }
 }
 sf.pos=4465209;
 r = Vret;
YkUN:
 topFrame = sf.prev;
 return r;
}
Tc *YJvB(YnZD *Aexpr, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tc *Vname = NULL;
 Tc *VspecName = NULL;
 Tl *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6579400;
 Vret = ((Tc*)&Ya);
 sf.pos=6579401;
 if ((YmTi(Aexpr) == 1))
 {
  sf.pos=6579402;
  Vname = YYim(YjUS(Aexpr));
  sf.pos=6579403;
  if (AaddType)
  {
   sf.pos=6579404;
   Vret =  ZcS(Vret, Vname);
   sf.pos=6579405;
   Y7hE(AthisClass, Vname);
  }
  else {
  sf.pos=6579406;
 if ((((((((Aparent != NULL) && (ZstringSize(Vname) >= 2)) && (ZstringGetChar(Vname, 0) >= 65)) && (ZstringGetChar(Vname, 0) <= 90)) && (ZstringGetChar(Vname, 0) != 84)) && (((ZstringGetChar(Vname, 1) < 65) || (ZstringGetChar(Vname, 1) > 90)))) && (((AthisClass == NULL) || !(YXY0(AthisClass, Vname))))))
  {
   sf.pos=6579407;
   Vret =  ZcS(Vret, ZcS3(Aparent->VfullName, ((Tc*)&YU), Vname));
  }
  else
  {
   sf.pos=6579408;
   Vret =  ZcS(Vret, YiXc(Vname, Awrap));
  }
  }
 }
 else {
 sf.pos=6579409;
 if ((YmTi(Aexpr) == 11))
 {
  sf.pos=6579410;
  Vret =  ZcS(Vret, ((Tc*)&Ytoe));
 }
 else {
 sf.pos=6579411;
 if ((YmTi(Aexpr) == 20))
 {
  sf.pos=6579412;
  Vret =  ZcS(Vret, YJvB(Yre5(Aexpr), Aparent, AthisClass, Awrap, AaddType));
  sf.pos=6579413;
  Vret =  ZcS(Vret, ((Tc*)&YU));
  sf.pos=6579414;
  Vret =  ZcS(Vret, YJvB(Y3Wy(Aexpr), NULL, AthisClass, Awrap, AaddType));
 }
 else {
 sf.pos=6579415;
 if ((YmTi(Aexpr) == 33))
 {
  sf.pos=6579416;
  Vret =  ZcS(Vret, YJvB(Yre5(Aexpr), Aparent, AthisClass, Awrap, AaddType));
  sf.pos=6579417;
  Vret =  ZcS(Vret, ((Tc*)&YCa));
  sf.pos=6579418;
  Vret =  ZcS(Vret, YJvB(Y3Wy(Aexpr), Aparent, AthisClass, Awrap, AaddType));
  sf.pos=6579419;
  Vret =  ZcS(Vret, ((Tc*)&YEa));
 }
 else {
 sf.pos=6579420;
 if ((YmTi(Aexpr) == 22))
 {
  Tb VisType;
  Tb VisFunc;
  VisType = 0;
  VisFunc = 0;
  sf.pos=6579421;
  if ((YmTi(Yre5(Aexpr)) == 1))
  {
   sf.pos=6579422;
   VspecName = YYim(YjUS(Yre5(Aexpr)));
   sf.pos=6579423;
   VisType = (ZListFind((Tl*)(t0 = ZnewList((Tt*)&string__T, 3), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Ybzf)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&YSKk)), ZLap((Tl*)t0, (Tz)(void*)((Tc*)&Y05v))), (Tz)(void*)VspecName)>= 0);
   sf.pos=6579424;
   VisFunc = (ZstringCmp(VspecName, ((Tc*)&Ybzf)) == 0);
  }
  sf.pos=6579425;
  if (VisType)
  {
   sf.pos=6579426;
   Vret =  ZcS(Vret, VhtmlTypeStart);
  }
  sf.pos=6579427;
  Vret =  ZcS(Vret, YJvB(Yre5(Aexpr), NULL, AthisClass, Awrap, AaddType));
  sf.pos=6579428;
  if (VisType)
  {
   sf.pos=6579429;
   Vret =  ZcS(Vret, VhtmlTypeEnd);
  }
  sf.pos=6579430;
  Vret =  ZcS(Vret, YauL(Y6_b(Aexpr), Aparent, AthisClass, Awrap, AaddType, (ZstringCmp(VspecName, ((Tc*)&Ybzf)) == 0)));
 }
 else
 {
  sf.pos=6579431;
  Yl0k(ZcS(((Tc*)&Ycbm), Zenum2string(MZui__EExprType, YmTi(Aexpr))));
  sf.pos=6579432;
  Vret =  ZcS(Vret, ((Tc*)&YbbH));
 }
 }}}}
 sf.pos=6579433;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *YauL(Tl *Atypes, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType, Tb AisFunc) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6695700;
 Vret = ((Tc*)&YU_a);
 sf.pos=6695701;
 Vret =  ZcS(Vret, YGD4(Atypes, Aparent, AthisClass, Awrap, AaddType, AisFunc));
 sf.pos=6695702;
 Vret =  ZcS(Vret, ((Tc*)&Yi9Y));
 sf.pos=6695703;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *YauLa(Tl *Atypes, YrBF *Aparent, YrBF *AthisClass, Tb Awrap, Tb AaddType) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4989700;
 Vret = ((Tc*)&YU_a);
 sf.pos=4989701;
 Vret =  ZcS(Vret, YGD4a(Atypes, Aparent, AthisClass, Awrap, AaddType));
 sf.pos=4989702;
 Vret =  ZcS(Vret, ((Tc*)&Yi9Y));
 sf.pos=4989703;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *YiXc(Tc *Aname, Tb Awrap) {
 Zsf sf;
 Tc *r = 0;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=6590900;
 if (!(Awrap))
 {
  sf.pos=6590901;
  r = Aname;
  rt = 1;
  goto Y3EN;
 }
 sf.pos=6590902;
 if (ZDictHas(VknownTypes, (Tz)(void*)Aname))
 {
  sf.pos=6590903;
  r = ((Tc *)ZDictGetPtr(VknownTypes, (Tz)(void*)Aname));
  rt = 1;
  goto Y3EN;
 }
 sf.pos=6590904;
 r = Aname;
Y3EN:
 topFrame = sf.prev;
 return r;
}
Tc *Y40A(Tc *Atype, YrBF *AthisClass, Tb Awrap) {
 Zsf sf;
 Tc *r = 0;
 Tc *Vlead = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1775000;
 if (!(Awrap))
 {
  sf.pos=1775001;
  r = Atype;
  rt = 1;
  goto YCnn;
 }
 sf.pos=1775002;
 if (((AthisClass != NULL) && YXY0(AthisClass, Atype)))
 {
  sf.pos=1775003;
  r = Atype;
  rt = 1;
  goto YCnn;
 }
 sf.pos=1775004;
 if (!(YrHb(Atype)))
 {
  sf.pos=1775005;
  r = Atype;
  rt = 1;
  goto YCnn;
 }
 sf.pos=1775006;
 if (ZstringEndsWith(Atype, ((Tc*)&Y4ka), 0))
 {
  sf.pos=1775007;
  Vlead = ZstringSlice(Atype, 0, -3, 0);
 }
 else
 {
  sf.pos=1775008;
  Vlead = Atype;
 }
 sf.pos=1775009;
 r = ZcS5(((Tc*)&YMOA), Vlead, ((Tc*)&YoT8), Atype, ((Tc*)&YGQj));
YCnn:
 topFrame = sf.prev;
 return r;
}
Tb YrHb(Tc *As) {
 Zsf sf;
 Tb r = 0;
 Tc *Zf1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9079800;
 if (((ZstringGetChar(As, 0) < 65) || (ZstringGetChar(As, 0) > 90)))
 {
  sf.pos=9079801;
  r = 0;
  rt = 1;
  goto YTyh;
 }
 sf.pos=9079802;
 if ((ZstringCmp(As, ((Tc*)&Ytoe)) == 0))
 {
  sf.pos=9079803;
  r = 0;
  rt = 1;
  goto YTyh;
 }
 sf.pos=9079804;
 if ((((ZstringCmp(As, ((Tc*)&Yh3h)) == 0) || (ZstringCmp(As, ((Tc*)&Yb4F)) == 0)) || (ZstringCmp(As, ((Tc*)&Yvep)) == 0)))
 {
  sf.pos=9079805;
  r = 0;
  rt = 1;
  goto YTyh;
 }
 sf.pos=9079806;
 {
  Ti Vc;
  Tfs iZf1;
  Zf1 = As;
  ZforStringNew(Zf1, &iZf1);
  for (ZforStringGetInt(&iZf1, &Vc); ZforStringContInt(&iZf1); ZforStringNextInt(&iZf1, &Vc)) {
  sf.pos=9079807;
  if ((Vc == 46))
  {
   rt = 2;
   goto YC_g;
  }
  sf.pos=9079808;
  if (!((((((Vc >= 65) && (Vc <= 90))) || (((Vc >= 97) && (Vc <= 122)))))))
  {
   sf.pos=9079809;
   r = 0;
   rt = 1;
   goto YC_g;
  }
YC_g:
  if (rt == 2) { rt &= 1; break; }
  if (rt) goto YTyh;
  sf.pos=9079810;
  }
 }
 sf.pos=9079811;
 r = 1;
YTyh:
 topFrame = sf.prev;
 return r;
}
Tc *Yb3r(Tl *Aarguments) {
 void *p15;
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf1 = NULL;
 YYIi *Varg = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=9174800;
 Vret = ((Tc*)&Ya);
 sf.pos=9174801;
 Vcomma = ((Tc*)&Ya);
 sf.pos=9174802;
 {
  Tfl Zf1i;
  Zf1 = ((p15 = (Aarguments)) == NULL ? (ZnewList((Tt*)&YYIi__T, 0)) : p15);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Varg;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=9174803;
  Vret =  ZcS(Vret, Vcomma);
  sf.pos=9174804;
  Vret =  ZcS(Vret, YdHK(Varg));
  sf.pos=9174805;
  Vcomma = ((Tc*)&Ydha);
  sf.pos=9174806;
  }
 }
 sf.pos=9174807;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *Yqvs(Tl *Aarguments, YrBF *Aparent, YrBF *AthisClass) {
 void *p16;
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf1 = NULL;
 YYIi *Varg = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=8858100;
 Vret = ((Tc*)&Ya);
 sf.pos=8858101;
 Vcomma = ((Tc*)&Ya);
 sf.pos=8858102;
 {
  Tfl Zf1i;
  Zf1 = ((p16 = (Aarguments)) == NULL ? (ZnewList((Tt*)&YYIi__T, 0)) : p16);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Varg;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=8858103;
  Vret =  ZcS(Vret, Vcomma);
  sf.pos=8858104;
  Vret =  ZcS(Vret, YWaa(Y1Yr(Varg), Aparent, AthisClass, 0));
  sf.pos=8858105;
  Vcomma = ((Tc*)&YS);
  sf.pos=8858106;
  }
 }
 sf.pos=8858107;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
Tc *Y2Xm(Tl *Aarguments, YrBF *Aparent, YrBF *AthisClass) {
 void *p17;
 Zsf sf;
 Tc *r = 0;
 Tc *Vret = NULL;
 Tc *Vcomma = NULL;
 Tl *Zf1 = NULL;
 YYIi *Varg = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=411500;
 Vret = ((Tc*)&Ya);
 sf.pos=411501;
 Vcomma = ((Tc*)&Ya);
 sf.pos=411502;
 {
  Tfl Zf1i;
  Zf1 = ((p17 = (Aarguments)) == NULL ? (ZnewList((Tt*)&YYIi__T, 0)) : p17);
  Zf1i.l = Zf1;
  Zf1i.valp = (void*)&Varg;
  Zf1i.i = 0;
  for (; ZforListPtrCont(&Zf1i); ) {
  sf.pos=411503;
  Vret =  ZcS(Vret, Vcomma);
  sf.pos=411504;
  Vret =  ZcS(Vret, YWaa(Y1Yr(Varg), Aparent, AthisClass, 1));
  sf.pos=411505;
  if ((YXDk(Y1Yr(Varg)) != 44))
  {
   sf.pos=411506;
   Vret =  ZcS(Vret, ((Tc*)&YG));
  }
  sf.pos=411507;
  Vret =  ZcS(Vret, YdHK(Varg));
  sf.pos=411508;
  Vcomma = ((Tc*)&Ydha);
  sf.pos=411509;
  }
 }
 sf.pos=411510;
 r = Vret;
 topFrame = sf.prev;
 return r;
}
YaHa *Y9vTa(YaHa *t, YrBF *Aparent, YXCg *Astmt, Tb Adummy) {
 Zsf sf;
 YYIi *Vdecl = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=8063300; t = Za(sizeof(YaHa));}
 sf.pos=8063301;
 if (YGtH(Astmt))
 {
  sf.pos=8063302;
  Vdecl = YjGb(Astmt);
  sf.pos=8063303;
  if (YMEi(Vdecl))
  {
   sf.pos=8063304;
   YuWe(t, Aparent, YWDX(Vdecl), 0);
  }
 }
 topFrame = sf.prev;
 return t;
}
YaHa *Y9vTb(YaHa *t, YrBF *Aparent, YYIi *Adecl) {
 Tb VnextHide;
 Tb VhasNext;
 Zsf sf;
 Tc *VnextSummary = NULL;
 Tc *VnextDetails = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {sf.pos=9083400; t = Za(sizeof(YaHa));}
 VnextHide = 0;
 VhasNext = 0;
 sf.pos=9083401;
 if (YqeZ(Adecl))
 {
  sf.pos=9083402;
  YuWe(t, Aparent, YNOi(Adecl), 1);
  sf.pos=9083403;
  VnextHide = t->Vhide;
  sf.pos=9083404;
  VnextSummary = t->Vsummary;
  sf.pos=9083405;
  VnextDetails = t->Vdetails;
  sf.pos=9083406;
  VhasNext = ((VnextSummary != NULL) || (VnextDetails != NULL));
  sf.pos=9083407;
  t->Vheader = NULL;
 }
 sf.pos=9083408;
 if (YMEi(Adecl))
 {
  sf.pos=9083409;
  t->Vsummary = NULL;
  sf.pos=9083410;
  t->Vdetails = NULL;
  sf.pos=9083411;
  YuWe(t, Aparent, YWDX(Adecl), 0);
  sf.pos=9083412;
  t->Vhide = (t->Vhide || VnextHide);
  sf.pos=9083413;
  if (((t->Vsummary == NULL) || ((YfGL(Adecl) && VhasNext))))
  {
   sf.pos=9083414;
   t->Vsummary = VnextSummary;
  }
  sf.pos=9083415;
  if (((t->Vdetails == NULL) || ((YfGL(Adecl) && VhasNext))))
  {
   sf.pos=9083416;
   t->Vdetails = VnextDetails;
  }
 }
 topFrame = sf.prev;
 return t;
}
void YuWe(YaHa *t, YrBF *Aparent, Tc *Acomment, Tb AuseStart) {
 Tb VheaderBreak;
 Tb VsummaryBreak;
 Tb VdetailsInExample;
 Ti VextraIdx;
 Zsf sf;
 Tc *Vs = NULL;
 Tc *VdetailsBreak = NULL;
 Tc *VextraBreak = NULL;
 Tc *Vtext = NULL;
 Tl *t0 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 if (t == NULL) {
  sf.pos=7028300;
  ZthrowThisNil();
 }
 sf.pos=7028301;
 Vs = Acomment;
 VheaderBreak = 0;
 VsummaryBreak = 0;
 VdetailsInExample = 0;
 VextraIdx = 0;
 sf.pos=7028302;
 while (1)
 {
  Ti Vidx;
  Ti Vend;
  sf.pos=7028303;
  Vidx = ZstringFindChar(Vs, 35, 0);
  sf.pos=7028304;
  Vend = ZstringFindChar(Vs, 10, 0);
  sf.pos=7028305;
  if (((Vend >= 0) && (((Vend < Vidx) || (Vidx < 0)))))
  {
   sf.pos=7028306;
   if (AuseStart)
   {
    rt = 2;
    goto YAmH;
   }
   sf.pos=7028307;
   t->Vsummary = NULL;
   sf.pos=7028308;
   t->Vdetails = NULL;
   sf.pos=7028309;
   t->Vextra = NULL;
   sf.pos=7028310;
   VextraBreak = NULL;
   sf.pos=7028311;
   t->Vhide = 0;
   sf.pos=7028312;
   t->VnoIndex = 0;
YAmH:
   if (rt) goto YXbO;
  }
  sf.pos=7028313;
  if ((Vidx < 0))
  {
   rt = 2;
   goto YXbO;
  }
  sf.pos=7028314;
  if ((Vend >= Vidx))
  {
   sf.pos=7028315;
   if ((((((ZstringGetChar(Vs, (Vidx + 1)) == 58) || (ZstringGetChar(Vs, (Vidx + 1)) == 61)) || (ZstringGetChar(Vs, (Vidx + 1)) == 42)) || (ZstringGetChar(Vs, (Vidx + 1)) == 45)) || (ZstringGetChar(Vs, (Vidx + 1)) == 37)))
   {
    sf.pos=7028316;
    t->Vhide = 0;
    Vtext = NULL;
    sf.pos=7028317;
    if ((ZstringGetChar(Vs, (Vidx + 2)) == 62))
    {
     sf.pos=7028318;
     Vtext = ZstringSlice(Vs, (Vidx + 3), Vend, 0);
    }
    else {
    sf.pos=7028319;
 if ((ZstringGetChar(Vs, (Vidx + 1)) == 37))
    {
     sf.pos=7028320;
     Vtext = Y6Od(NULL, ZstringSlice(Vs, (Vidx + 2), Vend, 0));
    }
    else {
    sf.pos=7028321;
 if ((ZstringGetChar(Vs, (Vidx + 2)) == 63))
    {
     sf.pos=7028322;
     t->VnoIndex = 1;
     sf.pos=7028323;
     Vtext = Y6Od(Aparent, ZstringSlice(Vs, (Vidx + 3), Vend, 0));
    }
    else
    {
     sf.pos=7028324;
     Vtext = Y6Od(Aparent, ZstringSlice(Vs, (Vidx + 2), Vend, 0));
    }
    }}
    sf.pos=7028325;
    switch (ZstringGetChar(Vs, (Vidx + 1)))
    {
    case 58:
     {
      sf.pos=7028326;
      if ((t->Vheader == NULL))
      {
       sf.pos=7028327;
       t->Vheader = Vtext;
      }
      else {
      sf.pos=7028328;
 if (VheaderBreak)
      {
       sf.pos=7028329;
       t->Vheader =  ZcS(t->Vheader, ZcS(VhtmlTextStart, Vtext));
      }
      else
      {
       sf.pos=7028330;
       t->Vheader =  ZcS(t->Vheader, Vtext);
      }
      }
      sf.pos=7028331;
      VheaderBreak = 0;
       break;
     }
    case 61:
     {
      sf.pos=7028332;
      if ((t->Vsummary == NULL))
      {
       sf.pos=7028333;
       t->Vsummary = Vtext;
      }
      else {
      sf.pos=7028334;
 if (VsummaryBreak)
      {
       sf.pos=7028335;
       t->Vsummary =  ZcS(t->Vsummary, ZcS(VhtmlTextStart, Vtext));
      }
      else
      {
       sf.pos=7028336;
       t->Vsummary =  ZcS(t->Vsummary, Vtext);
      }
      }
      sf.pos=7028337;
      VsummaryBreak = 0;
       break;
     }
    case 45:
     {
      sf.pos=7028338;
      if ((t->Vdetails == NULL))
      {
       sf.pos=7028339;
       t->Vdetails = Vtext;
      }
      else
      {
       sf.pos=7028340;
       if (VdetailsInExample)
       {
        sf.pos=7028341;
        t->Vdetails =  ZcS(t->Vdetails, ((Tc*)&Y1Fa));
       }
       sf.pos=7028342;
       t->Vdetails =  ZcS(t->Vdetails, Vtext);
      }
      sf.pos=7028343;
      VdetailsBreak = VhtmlTextStart;
      sf.pos=7028344;
      VdetailsInExample = 0;
       break;
     }
    case 37:
     {
      sf.pos=7028345;
      if ((t->Vdetails == NULL))
      {
       sf.pos=7028346;
       t->Vdetails = ZcS(((Tc*)&YLSt), Vtext);
      }
      else {
      sf.pos=7028347;
 if (!(VdetailsInExample))
      {
       sf.pos=7028348;
       t->Vdetails =  ZcS(t->Vdetails, ZcS(((Tc*)&YLSt), Vtext));
      }
      else
      {
       sf.pos=7028349;
       t->Vdetails =  ZcS(t->Vdetails, Vtext);
      }
      }
      sf.pos=7028350;
      VdetailsBreak = ZcS3(((Tc*)&Y1Fa), VhtmlTextStart, ((Tc*)&Yk));
      sf.pos=7028351;
      VdetailsInExample = 1;
       break;
     }
    case 42:
     {
      sf.pos=7028352;
      if ((t->Vextra == NULL))
      {
       sf.pos=7028353;
       t->Vextra = ZnewList((Tt*)&list__T, 0);
       sf.pos=7028354;
       VextraIdx = 0;
      }
      sf.pos=7028355;
      if ((ZListSize(t->Vextra) <= VextraIdx))
      {
       sf.pos=7028356;
       ZLap((Tl*)t->Vextra, (Tz)(void*)(t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)Vtext)));
      }
      else {
      sf.pos=7028357;
 if ((ZstringGetChar(Vs, (Vidx + 2)) != 32))
      {
       sf.pos=7028358;
       ZLap((Tl*)t->Vextra, (Tz)(void*)(t0 = ZnewList((Tt*)&string__T, 1), ZLap((Tl*)t0, (Tz)(void*)Vtext)));
       sf.pos=7028359;
       ++(VextraIdx);
      }
      else
      {
       sf.pos=7028360;
       ZLap((Tl*)((Tl *)ZListGetPtr(t->Vextra, VextraIdx)), (Tz)(void*)Vtext);
      }
      }
      sf.pos=7028361;
      VextraBreak = VhtmlTextStart;
       break;
     }
    }
   }
   else {
   sf.pos=7028362;
 if ((ZstringGetChar(Vs, (Vidx + 1)) == 33))
   {
    sf.pos=7028363;
    t->Vhide = 1;
   }
   else
   {
    sf.pos=7028364;
    VheaderBreak = 1;
    sf.pos=7028365;
    VsummaryBreak = 1;
    sf.pos=7028366;
    if ((VdetailsBreak != NULL))
    {
     sf.pos=7028367;
     t->Vdetails =  ZcS(t->Vdetails, VdetailsBreak);
     sf.pos=7028368;
     VdetailsBreak = NULL;
     sf.pos=7028369;
     VdetailsInExample = 0;
    }
    sf.pos=7028370;
    if ((VextraBreak != NULL))
    {
     sf.pos=7028371;
     ZLap((Tl*)((Tl *)ZListGetPtr(t->Vextra, VextraIdx)), (Tz)(void*)VextraBreak);
     sf.pos=7028372;
     VextraBreak = NULL;
    }
   }
   }
  }
  sf.pos=7028373;
  Vs = ZstringSlice(Vs, (Vend + 1), -1, 0);
YXbO:
  if (rt == 2) { rt &= 1; break; }
 sf.pos=7028374;
 }
 sf.pos=7028375;
 if ((VdetailsInExample && (VdetailsBreak != NULL)))
 {
  sf.pos=7028376;
  t->Vdetails =  ZcS(t->Vdetails, VdetailsBreak);
 }
 topFrame = sf.prev;
 return;
}
To ToYaHa[] = {
 {4, 0},
 {0, (Tt*)&string__T}, /* header */
 {0, (Tt*)&string__T}, /* summary */
 {0, (Tt*)&string__T}, /* details */
 {0, (Tt*)&list__T}, /* extra */
};
Tto YaHa__T = {390, (Tc*)&Yu_u, 0, ToYaHa};
Tc *Y0ZR(YnZD *Aexpr, YrBF *Aparent) {
 Zsf sf;
 Tc *r = 0;
 Tc *t0 = NULL;
 Tc *t1 = NULL;
 int rt = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=1008500;
 switch (YmTi(Aexpr))
 {
 case 1:
  {
   sf.pos=1008501;
   r = YYim(YjUS(Aexpr));
   rt = 1;
   goto Yf95;
  }
 case 20:
  {
   sf.pos=1008502;
   r = ZcS3(Y0ZR(Yre5(Aexpr), Aparent), ((Tc*)&YU), (t0 = Y0ZR(Y3Wy(Aexpr), Aparent)));
   rt = 1;
   goto Yf95;
  }
 case 22:
  {
   sf.pos=1008503;
   r = ZcS((t1 = Y0ZR(Yre5(Aexpr), Aparent)), (t0 = YauL(Y6_b(Aexpr), Aparent, NULL, 0, 0, 0)));
   rt = 1;
   goto Yf95;
  }
Yf95:
  if (rt) goto YDrH;
 }
 sf.pos=1008504;
 r = ((Tc*)&YbbH);
YDrH:
 topFrame = sf.prev;
 return r;
}
Tr YHH0(Tc *AoutDirName, Tc *AfullName, Tc *Atitle, YrBF *Aparent) {
 Zsf sf;
 Tr r = {NULL};
 Tc *VoutFileName = NULL;
 Tr Vout = {NULL};
 Tc *t0 = NULL;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 sf.pos=4046100;
 VoutFileName = ZcS5(AoutDirName, ((Tc*)&YV), AfullName, ((Tc*)&Y1zY), (Tc*)1);
 sf.pos=4046101;
 Vout = YiBk(VoutFileName, 1);
 sf.pos=4046102;
 if ((((Vout).ptr) == NULL))
 {
  sf.pos=4046103;
  Yl0k(ZcS(((Tc*)&YRJs), VoutFileName));
  sf.pos=4046104;
  Zexit(NULL, 1);
  return trZero;
 }
 sf.pos=4046105;
 Yl0k(ZcS(((Tc*)&Y3UZ), VoutFileName));
 sf.pos=4046106;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlHeader);
 sf.pos=4046107;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ZcS3(((Tc*)&YuQ3), Atitle, ((Tc*)&Y0_7)));
 sf.pos=4046108;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, VhtmlMiddle);
 sf.pos=4046109;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YPTh));
 sf.pos=4046110;
 if ((Aparent != NULL))
 {
  sf.pos=4046111;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ZcS5(((Tc*)&Yk9v), Aparent->VfullName, ((Tc*)&Ynep), (t0 = Aparent->VfullName), ((Tc*)&YGQj)));
 }
 sf.pos=4046112;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&Yhee));
 sf.pos=4046113;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YTI2));
 sf.pos=4046114;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&Yhee));
 sf.pos=4046115;
 if ((ZstringCmp(AfullName, ((Tc*)&YZ_F)) != 0))
 {
  sf.pos=4046116;
  ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YYIg));
 }
 sf.pos=4046117;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YVLi));
 sf.pos=4046118;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&YbEl));
 sf.pos=4046119;
 ((Ts (*)(void*, Tc*))(Vout.table[11]))(Vout.ptr, ((Tc*)&Yz5Q));
 sf.pos=4046120;
 r = Vout;
 topFrame = sf.prev;
 return r;
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
  ToYEro[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYEro[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYEro[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YtEE *p = 0;
  YtEE__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YtEE__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YtEE__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYtEE[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYtEE[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYtEE[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YP_P *p = 0;
  YP_P__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YP_P__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YP_P__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYP_P[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYP_P[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYP_P[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
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
  YrHq *p = 0;
  YrHq__Ytlm_I_imt[1] = (Tc*)((Tc*)&p->Vmessage - (Tc*)p);
  YrHq__Ytlm_I_imt[2] = (Tc*)((Tc*)&p->Vpos - (Tc*)p);
  YrHq__Ytlm_I_imt[3] = (Tc*)((Tc*)&p->Vbacktrace - (Tc*)p);
  ToYrHq[1].off = (int)((Tc*)&p->Vmessage - (Tc*)p);
  ToYrHq[2].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYrHq[3].off = (int)((Tc*)&p->Vbacktrace - (Tc*)p);
 }
 {
  YkxB *p = 0;
  ToYkxB[1].off = (int)((Tc*)&p->Vfilename - (Tc*)p);
  ToYkxB[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
 }
 {
  Yw8L *p = 0;
  Yw8L__Yw8L_I_imt[20] = (Tc*)((Tc*)&p->Vfd - (Tc*)p);
  Yw8L__Yw8L_I_imt[21] = (Tc*)((Tc*)&p->Vname - (Tc*)p);
  ToYw8L[1].off = (int)((Tc*)&p->Vname - (Tc*)p);
 }
 {
  YjUM *p = 0;
  ToYjUM[1].off = (int)((Tc*)&p->Vs - (Tc*)p);
  ToYjUM[2].off = (int)((Tc*)&p->Vx - (Tc*)p);
 }
 {
  Yhqr *p = 0;
  ToYhqr[1].off = (int)((Tc*)&p->Vdict - (Tc*)p);
 }
 {
  Yo7T *p = 0;
  ToYo7T[1].off = (int)((Tc*)&p->Vlist - (Tc*)p);
  ToYo7T[2].off = (int)((Tc*)&p->VsortMethod - (Tc*)p);
 }
 {
  YKQB *p = 0;
  ToYKQB[1].off = (int)((Tc*)&p->Vitems - (Tc*)p);
 }
 {
  YyHo *p = 0;
  ToYyHo[1].off = (int)((Tc*)&p->Vitems - (Tc*)p);
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
  ToY86c[1].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY86c[2].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY86c[3].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY86c[4].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY86c[5].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YJQu *p = 0;
  ToYJQu[1].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYJQu[2].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYJQu[3].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYJQu[4].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYJQu[5].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYJQu[6].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  YzqH *p = 0;
  ToYzqH[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToYzqH[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToYzqH[3].off = (int)((Tc*)&p->VtheValueList - (Tc*)p);
  ToYzqH[4].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToYzqH[5].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToYzqH[6].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToYzqH[7].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToYzqH[8].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Y_SI *p = 0;
  ToY_SI[1].off = (int)((Tc*)&p->Vcurrent - (Tc*)p);
  ToY_SI[2].off = (int)((Tc*)&p->Vdefault - (Tc*)p);
  ToY_SI[3].off = (int)((Tc*)&p->VshortName - (Tc*)p);
  ToY_SI[4].off = (int)((Tc*)&p->VlongName - (Tc*)p);
  ToY_SI[5].off = (int)((Tc*)&p->Vdoc - (Tc*)p);
  ToY_SI[6].off = (int)((Tc*)&p->VargName - (Tc*)p);
  ToY_SI[7].off = (int)((Tc*)&p->Vpos - (Tc*)p);
 }
 {
  Yol9 *p = 0;
  ToYol9[1].off = (int)((Tc*)&p->Vf_import - (Tc*)p);
  ToYol9[2].off = (int)((Tc*)&p->Vf_statement - (Tc*)p);
 }
 {
  Yknz *p = 0;
  ToYknz[1].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
 }
 {
  YqKm *p = 0;
  ToYqKm[1].off = (int)((Tc*)&p->Vf_fileName - (Tc*)p);
  ToYqKm[2].off = (int)((Tc*)&p->Vf_plugin - (Tc*)p);
  ToYqKm[3].off = (int)((Tc*)&p->Vf_asName - (Tc*)p);
  ToYqKm[4].off = (int)((Tc*)&p->Vf_options - (Tc*)p);
  ToYqKm[5].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
 }
 {
  YYIi *p = 0;
  ToYYIi[1].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToYYIi[2].off = (int)((Tc*)&p->Vf_dotName - (Tc*)p);
  ToYYIi[3].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYYIi[4].off = (int)((Tc*)&p->Vf_type - (Tc*)p);
  ToYYIi[5].off = (int)((Tc*)&p->Vf_init - (Tc*)p);
  ToYYIi[6].off = (int)((Tc*)&p->Vf_commentBefore - (Tc*)p);
  ToYYIi[7].off = (int)((Tc*)&p->Vf_commentAfter - (Tc*)p);
 }
 {
  YRBza *p = 0;
  ToYRBza[1].off = (int)((Tc*)&p->Vf_text - (Tc*)p);
  ToYRBza[2].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYRBza[3].off = (int)((Tc*)&p->Vf_attr - (Tc*)p);
  ToYRBza[4].off = (int)((Tc*)&p->Vf_classRef - (Tc*)p);
  ToYRBza[5].off = (int)((Tc*)&p->Vf_classDecl - (Tc*)p);
  ToYRBza[6].off = (int)((Tc*)&p->Vf_bitsDecl - (Tc*)p);
  ToYRBza[7].off = (int)((Tc*)&p->Vf_enumDecl - (Tc*)p);
  ToYRBza[8].off = (int)((Tc*)&p->Vf_moduleDecl - (Tc*)p);
  ToYRBza[9].off = (int)((Tc*)&p->Vf_methodDecl - (Tc*)p);
  ToYRBza[10].off = (int)((Tc*)&p->Vf_container - (Tc*)p);
  ToYRBza[11].off = (int)((Tc*)&p->Vf_alias - (Tc*)p);
  ToYRBza[12].off = (int)((Tc*)&p->Vf_ref - (Tc*)p);
  ToYRBza[13].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToYRBza[14].off = (int)((Tc*)&p->Vf_itemName - (Tc*)p);
  ToYRBza[15].off = (int)((Tc*)&p->Vf_itemNamePos - (Tc*)p);
 }
 {
  YftY *p = 0;
  ToYftY[1].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToYftY[2].off = (int)((Tc*)&p->Vf_templateTypeName - (Tc*)p);
  ToYftY[3].off = (int)((Tc*)&p->Vf_extends - (Tc*)p);
  ToYftY[4].off = (int)((Tc*)&p->Vf_implements - (Tc*)p);
  ToYftY[5].off = (int)((Tc*)&p->Vf_member - (Tc*)p);
  ToYftY[6].off = (int)((Tc*)&p->Vf_shared - (Tc*)p);
  ToYftY[7].off = (int)((Tc*)&p->Vf_sharedAttr - (Tc*)p);
 }
 {
  YfQg *p = 0;
  ToYfQg[1].off = (int)((Tc*)&p->Vf_member - (Tc*)p);
 }
 {
  YFN2 *p = 0;
  ToYFN2[1].off = (int)((Tc*)&p->Vf_item - (Tc*)p);
  ToYFN2[2].off = (int)((Tc*)&p->Vf_member - (Tc*)p);
 }
 {
  Y2wP *p = 0;
  ToY2wP[1].off = (int)((Tc*)&p->Vf_statement - (Tc*)p);
 }
 {
  Y7Np *p = 0;
  ToY7Np[1].off = (int)((Tc*)&p->Vf_returnType - (Tc*)p);
  ToY7Np[2].off = (int)((Tc*)&p->Vf_templateTypeName - (Tc*)p);
  ToY7Np[3].off = (int)((Tc*)&p->Vf_argument - (Tc*)p);
  ToY7Np[4].off = (int)((Tc*)&p->Vf_use - (Tc*)p);
  ToY7Np[5].off = (int)((Tc*)&p->Vf_body - (Tc*)p);
  ToY7Np[6].off = (int)((Tc*)&p->Vf_expr - (Tc*)p);
 }
 {
  YyfS *p = 0;
  ToYyfS[1].off = (int)((Tc*)&p->Vf_keyType - (Tc*)p);
  ToYyfS[2].off = (int)((Tc*)&p->Vf_itemType - (Tc*)p);
 }
 {
  YoDF *p = 0;
  ToYoDF[1].off = (int)((Tc*)&p->Vf_from - (Tc*)p);
  ToYoDF[2].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToYoDF[3].off = (int)((Tc*)&p->Vf_for - (Tc*)p);
 }
 {
  YhZL *p = 0;
  ToYhZL[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYhZL[2].off = (int)((Tc*)&p->Vf_endPos - (Tc*)p);
  ToYhZL[3].off = (int)((Tc*)&p->Vf_statement - (Tc*)p);
 }
 {
  YXCg *p = 0;
  ToYXCg[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYXCg[2].off = (int)((Tc*)&p->Vf_declaration - (Tc*)p);
  ToYXCg[3].off = (int)((Tc*)&p->Vf_include - (Tc*)p);
  ToYXCg[4].off = (int)((Tc*)&p->Vf_assign - (Tc*)p);
  ToYXCg[5].off = (int)((Tc*)&p->Vf_methodCall - (Tc*)p);
  ToYXCg[6].off = (int)((Tc*)&p->Vf_condition - (Tc*)p);
  ToYXCg[7].off = (int)((Tc*)&p->Vf_for - (Tc*)p);
  ToYXCg[8].off = (int)((Tc*)&p->Vf_try - (Tc*)p);
  ToYXCg[9].off = (int)((Tc*)&p->Vf_block - (Tc*)p);
  ToYXCg[10].off = (int)((Tc*)&p->Vf_expr - (Tc*)p);
  ToYXCg[11].off = (int)((Tc*)&p->Vf_arguments - (Tc*)p);
  ToYXCg[12].off = (int)((Tc*)&p->Vf_cblock - (Tc*)p);
  ToYXCg[13].off = (int)((Tc*)&p->Vf_proceedPos - (Tc*)p);
  ToYXCg[14].off = (int)((Tc*)&p->Vf_statement - (Tc*)p);
 }
 {
  YfBB *p = 0;
  ToYfBB[1].off = (int)((Tc*)&p->Vf_statement - (Tc*)p);
 }
 {
  Yq22 *p = 0;
  ToYq22[1].off = (int)((Tc*)&p->Vf_lhs - (Tc*)p);
  ToYq22[2].off = (int)((Tc*)&p->Vf_rhs - (Tc*)p);
 }
 {
  Y5eh *p = 0;
  ToY5eh[1].off = (int)((Tc*)&p->Vf_cond - (Tc*)p);
  ToY5eh[2].off = (int)((Tc*)&p->Vf_block - (Tc*)p);
  ToY5eh[3].off = (int)((Tc*)&p->Vf_elseif - (Tc*)p);
  ToY5eh[4].off = (int)((Tc*)&p->Vf_else - (Tc*)p);
 }
 {
  Yxh9 *p = 0;
  ToYxh9[1].off = (int)((Tc*)&p->Vf_loopVar - (Tc*)p);
  ToYxh9[2].off = (int)((Tc*)&p->Vf_iter - (Tc*)p);
  ToYxh9[3].off = (int)((Tc*)&p->Vf_to - (Tc*)p);
  ToYxh9[4].off = (int)((Tc*)&p->Vf_until - (Tc*)p);
  ToYxh9[5].off = (int)((Tc*)&p->Vf_step - (Tc*)p);
  ToYxh9[6].off = (int)((Tc*)&p->Vf_body - (Tc*)p);
 }
 {
  Yy74 *p = 0;
  ToYy74[1].off = (int)((Tc*)&p->Vf_body - (Tc*)p);
  ToYy74[2].off = (int)((Tc*)&p->Vf_catch - (Tc*)p);
  ToYy74[3].off = (int)((Tc*)&p->Vf_else - (Tc*)p);
  ToYy74[4].off = (int)((Tc*)&p->Vf_finally - (Tc*)p);
 }
 {
  Ya9G *p = 0;
  ToYa9G[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYa9G[2].off = (int)((Tc*)&p->Vf_type - (Tc*)p);
  ToYa9G[3].off = (int)((Tc*)&p->Vf_decl - (Tc*)p);
  ToYa9G[4].off = (int)((Tc*)&p->Vf_body - (Tc*)p);
 }
 {
  YLuR *p = 0;
  ToYLuR[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYLuR[2].off = (int)((Tc*)&p->Vf_uses - (Tc*)p);
  ToYLuR[3].off = (int)((Tc*)&p->Vf_text - (Tc*)p);
  ToYLuR[4].off = (int)((Tc*)&p->Vf_expr - (Tc*)p);
 }
 {
  YnZD *p = 0;
  ToYnZD[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToYnZD[2].off = (int)((Tc*)&p->Vf_id - (Tc*)p);
  ToYnZD[3].off = (int)((Tc*)&p->Vf_stringValue - (Tc*)p);
  ToYnZD[4].off = (int)((Tc*)&p->Vf_listItem - (Tc*)p);
  ToYnZD[5].off = (int)((Tc*)&p->Vf_dictItem - (Tc*)p);
  ToYnZD[6].off = (int)((Tc*)&p->Vf_initItem - (Tc*)p);
  ToYnZD[7].off = (int)((Tc*)&p->Vf_methodCall - (Tc*)p);
  ToYnZD[8].off = (int)((Tc*)&p->Vf_method - (Tc*)p);
  ToYnZD[9].off = (int)((Tc*)&p->Vf_decl - (Tc*)p);
  ToYnZD[10].off = (int)((Tc*)&p->Vf_typecast - (Tc*)p);
  ToYnZD[11].off = (int)((Tc*)&p->Vf_typespec - (Tc*)p);
  ToYnZD[12].off = (int)((Tc*)&p->Vf_cond - (Tc*)p);
  ToYnZD[13].off = (int)((Tc*)&p->Vf_left - (Tc*)p);
  ToYnZD[14].off = (int)((Tc*)&p->Vf_right - (Tc*)p);
  ToYnZD[15].off = (int)((Tc*)&p->Vf_call - (Tc*)p);
 }
 {
  Y1p4 *p = 0;
  ToY1p4[1].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToY1p4[2].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
 }
 {
  YYKi *p = 0;
  ToYYKi[1].off = (int)((Tc*)&p->Vf_key - (Tc*)p);
  ToYYKi[2].off = (int)((Tc*)&p->Vf_value - (Tc*)p);
 }
 {
  YJFN *p = 0;
  ToYJFN[1].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToYJFN[2].off = (int)((Tc*)&p->Vf_value - (Tc*)p);
 }
 {
  Y_1n *p = 0;
  ToY_1n[1].off = (int)((Tc*)&p->Vf_method - (Tc*)p);
  ToY_1n[2].off = (int)((Tc*)&p->Vf_pos - (Tc*)p);
  ToY_1n[3].off = (int)((Tc*)&p->Vf_name - (Tc*)p);
  ToY_1n[4].off = (int)((Tc*)&p->Vf_argument - (Tc*)p);
  ToY_1n[5].off = (int)((Tc*)&p->Vf_vararg - (Tc*)p);
 }
 {
  Ysbp *p = 0;
  ToYsbp[1].off = (int)((Tc*)&p->Vf_filename - (Tc*)p);
 }
 {
  YeYq *p = 0;
  ToYeYq[1].off = (int)((Tc*)&p->Vfd - (Tc*)p);
  ToYeYq[2].off = (int)((Tc*)&p->Vtext - (Tc*)p);
  ToYeYq[3].off = (int)((Tc*)&p->Vpos - (Tc*)p);
  ToYeYq[4].off = (int)((Tc*)&p->VcharStack - (Tc*)p);
  ToYeYq[5].off = (int)((Tc*)&p->Vindent - (Tc*)p);
  ToYeYq[6].off = (int)((Tc*)&p->VrecordWriter - (Tc*)p);
 }
 {
  Yev8 *p = 0;
  ToYev8[1].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
  ToYev8[2].off = (int)((Tc*)&p->VzuiPos - (Tc*)p);
 }
 {
  YsZx *p = 0;
  ToYsZx[1].off = (int)((Tc*)&p->Vchildren - (Tc*)p);
  ToYsZx[2].off = (int)((Tc*)&p->Vvalue - (Tc*)p);
 }
 {
  Y7Sj *p = 0;
  ToY7Sj[1].off = (int)((Tc*)&p->Vinput - (Tc*)p);
  ToY7Sj[2].off = (int)((Tc*)&p->VtokenStack - (Tc*)p);
  ToY7Sj[3].off = (int)((Tc*)&p->VusedIdKeywords - (Tc*)p);
 }
 {
  YL4o *p = 0;
  ToYL4o[1].off = (int)((Tc*)&p->VusedIdKeywords - (Tc*)p);
 }
 {
  YwDJ *p = 0;
  ToYwDJ[1].off = (int)((Tc*)&p->Vparent - (Tc*)p);
  ToYwDJ[2].off = (int)((Tc*)&p->Vchildren - (Tc*)p);
  ToYwDJ[3].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYwDJ[4].off = (int)((Tc*)&p->VfullName - (Tc*)p);
  ToYwDJ[5].off = (int)((Tc*)&p->Vstmt - (Tc*)p);
  ToYwDJ[6].off = (int)((Tc*)&p->Vattr - (Tc*)p);
  ToYwDJ[7].off = (int)((Tc*)&p->Vtype - (Tc*)p);
  ToYwDJ[8].off = (int)((Tc*)&p->VtypeSpec - (Tc*)p);
  ToYwDJ[9].off = (int)((Tc*)&p->Vcomment - (Tc*)p);
  ToYwDJ[10].off = (int)((Tc*)&p->Vsummary - (Tc*)p);
  ToYwDJ[11].off = (int)((Tc*)&p->Vextends - (Tc*)p);
  ToYwDJ[12].off = (int)((Tc*)&p->Vimplements - (Tc*)p);
  ToYwDJ[13].off = (int)((Tc*)&p->Vincludes - (Tc*)p);
  ToYwDJ[14].off = (int)((Tc*)&p->VextendsNoType - (Tc*)p);
  ToYwDJ[15].off = (int)((Tc*)&p->Vheader - (Tc*)p);
  ToYwDJ[16].off = (int)((Tc*)&p->Vtail - (Tc*)p);
 }
 {
  YrBF *p = 0;
  ToYrBF[1].off = (int)((Tc*)&p->Vparent - (Tc*)p);
  ToYrBF[2].off = (int)((Tc*)&p->Vpage - (Tc*)p);
  ToYrBF[3].off = (int)((Tc*)&p->Vname - (Tc*)p);
  ToYrBF[4].off = (int)((Tc*)&p->VfullName - (Tc*)p);
  ToYrBF[5].off = (int)((Tc*)&p->Vattr - (Tc*)p);
  ToYrBF[6].off = (int)((Tc*)&p->Vitems - (Tc*)p);
  ToYrBF[7].off = (int)((Tc*)&p->VtypeNames - (Tc*)p);
 }
 {
  YT98 *p = 0;
  ToYT98[1].off = (int)((Tc*)&p->VitemName - (Tc*)p);
  ToYT98[2].off = (int)((Tc*)&p->VtableRow - (Tc*)p);
 }
 {
  YHCf *p = 0;
  ToYHCf[1].off = (int)((Tc*)&p->Ventries - (Tc*)p);
 }
 {
  YaHa *p = 0;
  ToYaHa[1].off = (int)((Tc*)&p->Vheader - (Tc*)p);
  ToYaHa[2].off = (int)((Tc*)&p->Vsummary - (Tc*)p);
  ToYaHa[3].off = (int)((Tc*)&p->Vdetails - (Tc*)p);
  ToYaHa[4].off = (int)((Tc*)&p->Vextra - (Tc*)p);
 }
}

/*
 * INIT GLOBALS
 */
int ZglobInit(int round) {
 int done = 1;
 Zsf sf;
 sf.prev = topFrame;
 sf.pos = 0;
 sf.frof = NULL;
 topFrame = &sf;
 done &= JIOModule(round);
 done &= JLOGModule(round);
 done &= JARGModule(round);
 done &= JParse(round);
 if (round == 2001) {
   sf.pos=0;
   Vpages = ZnewDict((Tt*)&string__T, (Tt*)&YwDJ__T, 0);
   sf.pos=1;
   VbuiltinMap = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0), (Tz)(void*)((Tc*)&Yqha), (Tz)(void*)((Tc*)&YdXv)), (Tz)(void*)((Tc*)&Yq48), (Tz)(void*)((Tc*)&YoH1)), (Tz)(void*)((Tc*)&Yj5A), (Tz)(void*)((Tc*)&YlDi)), (Tz)(void*)((Tc*)&Ysz5), (Tz)(void*)((Tc*)&YEf9)), (Tz)(void*)((Tc*)&Yq6m), (Tz)(void*)((Tc*)&YJ80)), (Tz)(void*)((Tc*)&Yk6j), (Tz)(void*)((Tc*)&YzOx)), (Tz)(void*)((Tc*)&Y8Aj), (Tz)(void*)((Tc*)&YAmq)), (Tz)(void*)((Tc*)&Y3um), (Tz)(void*)((Tc*)&Ysau)), (Tz)(void*)((Tc*)&YZ7r), (Tz)(void*)((Tc*)&YDnK)), (Tz)(void*)((Tc*)&YzYD), (Tz)(void*)((Tc*)&Yff_)), (Tz)(void*)((Tc*)&YNza), (Tz)(void*)((Tc*)&YZfe)), (Tz)(void*)((Tc*)&Y8lF), (Tz)(void*)((Tc*)&YWm4)), (Tz)(void*)((Tc*)&Yn4Y), (Tz)(void*)((Tc*)&YqZb)), (Tz)(void*)((Tc*)&Y6OI), (Tz)(void*)((Tc*)&YDGg)), (Tz)(void*)((Tc*)&YNmB), (Tz)(void*)((Tc*)&YoUW)), (Tz)(void*)((Tc*)&Yplx), (Tz)(void*)((Tc*)&Y8vt)), (Tz)(void*)((Tc*)&YKaX), (Tz)(void*)((Tc*)&YpR8)), (Tz)(void*)((Tc*)&YuxY), (Tz)(void*)((Tc*)&Y80D)), (Tz)(void*)((Tc*)&YrRy), (Tz)(void*)((Tc*)&YnDK)), (Tz)(void*)((Tc*)&YnNK), (Tz)(void*)((Tc*)&Yz9k)), (Tz)(void*)((Tc*)&YUCs), (Tz)(void*)((Tc*)&YOZB)), (Tz)(void*)((Tc*)&YasT), (Tz)(void*)((Tc*)&YjxI)), (Tz)(void*)((Tc*)&YIbo), (Tz)(void*)((Tc*)&YboU)), (Tz)(void*)((Tc*)&YpQB), (Tz)(void*)((Tc*)&YOZB)), (Tz)(void*)((Tc*)&Yc08), (Tz)(void*)((Tc*)&Yrn0)), (Tz)(void*)((Tc*)&YcK4), (Tz)(void*)((Tc*)&YFD0));
   sf.pos=2;
   VknownTypes = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&string__T, (Tt*)&string__T, 0), (Tz)(void*)((Tc*)&YeUp), (Tz)(void*)((Tc*)&Yaqp)), (Tz)(void*)((Tc*)&YtPw), (Tz)(void*)((Tc*)&Y_bS)), (Tz)(void*)((Tc*)&YP0m), (Tz)(void*)((Tc*)&YRfw)), (Tz)(void*)((Tc*)&YJnE), (Tz)(void*)((Tc*)&Ytv8)), (Tz)(void*)((Tc*)&YOgw), (Tz)(void*)((Tc*)&YG7D)), (Tz)(void*)((Tc*)&YYgh), (Tz)(void*)((Tc*)&Ye2t)), (Tz)(void*)((Tc*)&Y6Yl), (Tz)(void*)((Tc*)&YTGY)), (Tz)(void*)((Tc*)&Yt7n), (Tz)(void*)((Tc*)&YcX9)), (Tz)(void*)((Tc*)&Y1Qt), (Tz)(void*)((Tc*)&YDo5)), (Tz)(void*)((Tc*)&Yknu), (Tz)(void*)((Tc*)&YREK)), (Tz)(void*)((Tc*)&Y3nJ), (Tz)(void*)((Tc*)&Yq45)), (Tz)(void*)((Tc*)&YbJS), (Tz)(void*)((Tc*)&Yy0W)), (Tz)(void*)((Tc*)&YPxi), (Tz)(void*)((Tc*)&Yu1V)), (Tz)(void*)((Tc*)&YT13), (Tz)(void*)((Tc*)&YlZ5)), (Tz)(void*)((Tc*)&YNmG), (Tz)(void*)((Tc*)&YzJL)), (Tz)(void*)((Tc*)&YdEY), (Tz)(void*)((Tc*)&YFI7)), (Tz)(void*)((Tc*)&YOjT), (Tz)(void*)((Tc*)&YQJ4)), (Tz)(void*)((Tc*)&YCpI), (Tz)(void*)((Tc*)&YEM6)), (Tz)(void*)((Tc*)&YZQ2), (Tz)(void*)((Tc*)&YMs0)), (Tz)(void*)((Tc*)&YanE), (Tz)(void*)((Tc*)&YLNy)), (Tz)(void*)((Tc*)&YVK0), (Tz)(void*)((Tc*)&YvDQ)), (Tz)(void*)((Tc*)&YT65), (Tz)(void*)((Tc*)&YX_g)), (Tz)(void*)((Tc*)&YclO), (Tz)(void*)((Tc*)&Ycuk)), (Tz)(void*)((Tc*)&YHkL), (Tz)(void*)((Tc*)&YMrR)), (Tz)(void*)((Tc*)&YATt), (Tz)(void*)((Tc*)&Y8jz));
   sf.pos=3;
   VvisName = ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZDictAdd(0, ZnewDict((Tt*)&MZui__EVisibility__T, (Tt*)&string__T, 0), (Tz)(Ti)2, (Tz)(void*)((Tc*)&Yg46)), (Tz)(Ti)3, (Tz)(void*)((Tc*)&Yych)), (Tz)(Ti)4, (Tz)(void*)((Tc*)&YhdP)), (Tz)(Ti)6, (Tz)(void*)((Tc*)&Ymmd)), (Tz)(Ti)7, (Tz)(void*)((Tc*)&YF4f));
   sf.pos=4;
   Vmethods = ZnewDict((Tt*)&string__T, (Tt*)&YXCg__T, 0);
 }
 topFrame = sf.prev;
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
 emergencyAlloc = malloc(16384);
 ZimtInit();
 ZglobInit(round++);
 YzvW = Zstr(argv[0]);
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
 if (topFrame != NULL) fprintf(stderr, "INTERNAL: topFrame not NULL\n");
 return r;
}


int Fmain(void) {
 Zsf sf;
 Ti r = 0;
 Tc *VoutDirName = NULL;
 YPto *Vinfo = 0;
 Td *Zf1 = NULL;
 YwDJ *Vpage = 0;
 sf.prev = topFrame;
 sf.pos = 0;
 topFrame = &sf;
 r = 0;
 sf.pos=527000;
 if ((Yd2Z() < 1))
 {
  sf.pos=527001;
  Yl0k(ZcS3(((Tc*)&YZVC), YzvW, ((Tc*)&Y1c5)));
  sf.pos=527002;
  Zexit(NULL, 1);
  return 0;
 }
 sf.pos=527003;
 VoutDirName = YtgL((Yd2Z() - 1));
 sf.pos=527004;
 Vinfo = YPwr(VoutDirName);
 sf.pos=527005;
 if (!(Vinfo->VisDir))
 {
  sf.pos=527006;
  if ((Vinfo->Vstatus == 1))
  {
   sf.pos=527007;
   Yl0k(ZcS(((Tc*)&Y0k0), VoutDirName));
  }
  else
  {
   sf.pos=527008;
   Yl0k(ZcS(((Tc*)&YoaB), VoutDirName));
  }
 }
 sf.pos=527009;
 {
  Ti Vi;
  Tfr Zf1;
  ZforRangeNew(0, (Yd2Z() - 2), 0, 1, &Zf1);
  for (ZforRangeGetInt(&Zf1, &Vi); ZforRangeContInt(&Zf1); ZforRangeNextInt(&Zf1, &Vi)) {
  sf.pos=527010;
  YSxp(YtgL(Vi));
  sf.pos=527011;
  }
 }
 sf.pos=527012;
 {
  Tfd Zf1i;
  Zf1 = Vpages;
  Zf1i.d = Zf1;
  Zf1i.keyp = NULL;
  Zf1i.valp = (void*)&Vpage;
  for (ZforDictStart(&Zf1i); ZforDictCont(&Zf1i); ZforDictNext(&Zf1i)) {
  sf.pos=527013;
  if (!(Vpage->Vhide))
  {
   sf.pos=527014;
   YEoy(Vpage, VoutDirName);
  }
  sf.pos=527015;
  }
 }
 sf.pos=527016;
 YyrL(VoutDirName);
 sf.pos=527017;
 r = 0;
 topFrame = sf.prev;
 return r;
}
