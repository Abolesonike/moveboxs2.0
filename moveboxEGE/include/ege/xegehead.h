#ifdef NAMESPACE_DEF
    #ifdef USENAMESPACE
        #define NAMESPACE_BEG namespace xege {
        #define NAMESPACE_END }
    #else
        #define NAMESPACE_BEG
        #define NAMESPACE_END
    #endif
    #ifdef __cplusplus
        #define  EGEEXTERNC extern "C" {
        #define  EGEEXTERNED }
    #else
        #define  EGEEXTERNC
        #define  EGEEXTERNED
    #endif
#elif !defined(_XEGEHEAD_H_)
    #define _XEGEHEAD_H_
    #define XEGE_TITLE "Xege App V0.1.1 alpha"
#endif

