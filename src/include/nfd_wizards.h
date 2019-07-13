/*
  Native file dialog but actually an API usable as a dynamic library.
 */


#ifndef _NFD_WIZARDS_H
#define _NFD_WIZARDS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* denotes UTF-8 char */
typedef char sw_nfdchar_t;

/* opaque data structure -- see NFD_PathSet_* */
typedef struct {
    sw_nfdchar_t *buf;
    size_t *indices; /* byte offsets into buf */
    size_t count;    /* number of indices into buf */
}sw_nfdpathset_t;

typedef enum {
    SW_NFD_ERROR,       /* programmatic error */
    SW_NFD_OKAY,        /* user pressed okay, or successful return */
    SW_NFD_CANCEL       /* user pressed cancel */
}sw_nfdresult_t;
    

/* nfd_<targetplatform>.c */

/* single file open dialog */    
sw_nfdresult_t sw_NFD_OpenDialog( const sw_nfdchar_t *filterList,
                            const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath );

/* multiple file open dialog */    
sw_nfdresult_t sw_NFD_OpenDialogMultiple( const sw_nfdchar_t *filterList,
                                    const sw_nfdchar_t *defaultPath,
                                    sw_nfdpathset_t *outPaths );

/* save dialog */
sw_nfdresult_t sw_NFD_SaveDialog( const sw_nfdchar_t *filterList,
                            const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath );


/* select folder dialog */
sw_nfdresult_t sw_NFD_PickFolder( const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath);

/* nfd_common.c */

/* get last error -- set when sw_nfdresult_t returns SW_NFD_ERROR */
const char *sw_NFD_GetError( void );
/* get the number of entries stored in pathSet */
size_t      sw_NFD_PathSet_GetCount( const sw_nfdpathset_t *pathSet );
/* Get the UTF-8 path at offset index */
sw_nfdchar_t  *sw_NFD_PathSet_GetPath( const sw_nfdpathset_t *pathSet, size_t index );
/* Free the pathSet */    
void        sw_NFD_PathSet_Free( sw_nfdpathset_t *pathSet );

void sw_NFD_Free(void* ptr);

#ifdef __cplusplus
}
#endif

#endif
