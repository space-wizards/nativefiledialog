#include "nfd.h"
#include "nfd_wizards.h"

#include <stdlib.h>

sw_nfdresult_t sw_NFD_OpenDialog( const sw_nfdchar_t *filterList,
                            const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath ) {
    return NFD_OpenDialog(filterList, defaultPath, outPath);
}

sw_nfdresult_t sw_NFD_OpenDialogMultiple( const sw_nfdchar_t *filterList,
                                    const sw_nfdchar_t *defaultPath,
                                    sw_nfdpathset_t *outPaths ) {
    return NFD_OpenDialogMultiple(filterList, defaultPath, (nfdpathset_t*) outPaths);
}

sw_nfdresult_t sw_NFD_SaveDialog( const sw_nfdchar_t *filterList,
                            const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath ) {
    return NFD_SaveDialog(filterList, defaultPath, outPath);
}

sw_nfdresult_t sw_NFD_PickFolder( const sw_nfdchar_t *defaultPath,
                            sw_nfdchar_t **outPath) {
    return NFD_PickFolder(defaultPath, outPath);
}

const char *sw_NFD_GetError( void ) {
    return NFD_GetError();
}

size_t sw_NFD_PathSet_GetCount( const sw_nfdpathset_t *pathSet ) {
    return NFD_PathSet_GetCount((nfdpathset_t*) pathSet);
}

sw_nfdchar_t *sw_NFD_PathSet_GetPath( const sw_nfdpathset_t *pathSet, size_t index ) {
    return NFD_PathSet_GetPath((nfdpathset_t*) pathSet, index);
}

void sw_NFD_PathSet_Free( sw_nfdpathset_t *pathSet ) {
    NFD_PathSet_Free((nfdpathset_t*) pathSet);
}

void sw_NFD_Free(void* ptr) {
    free(ptr);
}