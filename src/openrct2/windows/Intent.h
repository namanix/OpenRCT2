#ifndef OPENRCT2_INTENT_H
#define OPENRCT2_INTENT_H

#include "../common.h"
#include "../interface/window.h"
#ifdef __cplusplus
#include <map>
#endif // __cplusplus


#ifdef __cplusplus
struct IntentData
{
    enum DATATYPE { DT_INT, DT_STRING, DT_POINTER } type;

    union {
        uint32 unsignedInt;
        sint32 signedInt;
    } intVal;
    utf8string stringVal;
    void * pointerVal;
};

class Intent
{
private:
    rct_windowclass _Class;
    std::map<uint32, IntentData> _Data;
public:
    explicit Intent(rct_windowclass windowclass);
    rct_windowclass GetWindowClass();
    void * GetPointerExtra(uint32 key);
    utf8string GetStringExtra(uint32 key);
    uint32 GetUIntExtra(uint32 key);
    sint32 GetSIntExtra(uint32 key);
    Intent * putExtra(uint32 key, uint32 value);
    Intent * putExtra(uint32 key, void * value);
    Intent * putExtra(uint32 key, sint32 value);
    Intent * putExtra(uint32 key, utf8string value);
};
#else
// Allow C code to use `Intent *`
typedef struct Intent Intent;
#endif


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

    enum
    {
        INTENT_EXTRA_GUEST_LIST_FILTER,
        INTENT_EXTRA_RIDE_ID,
        INTENT_EXTRA_PATH,
        INTENT_EXTRA_PEEP,
        INTENT_EXTRA_LOADSAVE_TYPE,
        INTENT_EXTRA_CALLBACK,
        INTENT_EXTRA_TRACK_DESIGN,
    };

    Intent *intent_create(rct_windowclass clss);
    void intent_release(Intent * intent);
    void intent_set_string(Intent *, uint32 key, utf8string value);
    void intent_set_pointer(Intent *, uint32 key, void * value);
    void intent_set_sint(Intent *, uint32 key, sint32 value);
    void intent_set_uint(Intent *, uint32 key, uint32 value);
#ifdef __cplusplus
}
#endif // __cplusplus

#endif // OPENRCT2_INTENT_H
