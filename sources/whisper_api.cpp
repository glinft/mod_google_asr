#include "whisper_api.h"
#include "openai.hpp"
#include <string>
#include <exception>

switch_status_t whisper_transcribe(gasr_ctx_t *asr_ctx, const char *fname, char *result){
    std::string token=globals.api_key;
    openai::start(token);
    try{
        std::string audiofile=fname;
        std::string jreq=R"({"file": ")"+audiofile+R"(", "model": "whisper-1"})";
        auto jdoc=nlohmann::json::parse(jreq);
        auto transcription=openai::audio().transcribe(jdoc);
        std::string txt=transcription["text"];
        result=strdup(txt.c_str());
    }catch(std::exception& e){
        //std::cout<<"XX "<<e.what()<<std::endl;
        result=NULL;
    }
    return (result ? SWITCH_STATUS_SUCCESS : SWITCH_STATUS_FALSE);
}
