#ifndef __WISPER_API_H
#define __WISPER_API_H

#include <switch.h>
#include <mod_sfwhisper.h>

#ifdef __cplusplus
extern "C"
{
#endif

switch_status_t whisper_transcribe(gasr_ctx_t *asr_ctx, const char *fname, char **script);

#ifdef __cplusplus
}
#endif

#endif
