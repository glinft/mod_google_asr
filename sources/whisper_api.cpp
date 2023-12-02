#include "whisper_api.h"
#include "openai.hpp"
#include <string>
#include <exception>

extern "C" {
switch_status_t whisper_transcribe(gasr_ctx_t *asr_ctx, const char *fname, char **script){
    char *result = NULL;
    std::string token=globals.api_key;
    openai::start(token);
    //switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_NOTICE, "token: %s\n", token.c_str());
    try{
        std::string audiofile=fname;
        std::string jreq=R"({"file": ")"+audiofile+R"(", "model": "whisper-1"})";
        switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_NOTICE, "audio: %s\n", jreq.c_str());
        auto jdoc=nlohmann::json::parse(jreq);
        auto transcription=openai::audio().transcribe(jdoc);
        std::string text=transcription["text"];
        switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_NOTICE, "script: %s\n", text.c_str());
        result=strdup(text.c_str());
    }catch(std::exception& e){
        switch_log_printf(SWITCH_CHANNEL_LOG, SWITCH_LOG_NOTICE, "error: %s\n", e.what());
        result=NULL;
    }
    *script = result;
    return (result ? SWITCH_STATUS_SUCCESS : SWITCH_STATUS_FALSE);
}
}
